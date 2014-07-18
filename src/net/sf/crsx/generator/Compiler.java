/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Kind;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.generic.GenericRule;
import net.sf.crsx.util.LinkedExtensibleSet;

/**
 * Compiler for simplified subset of CRSX systems.
 * <p>
 * Handles CRS systems obeying the following restrictions:
 * <ul>
 * 
 * <li><p>Simplified rules (with one exception below) have the form
 * 		<blockquote>
 * 			<em>F</em>[<var>p</var><sub>1</sub>, ..., <var>p</var><sub>n</sub>] &rarr; <var>c</var>
 * 		</blockquote>
 * 		<p>where
 * 		<ol>
 * 		<li><p>the <em>F</em> constructor does not appear in any other pattern,
 * 		<li><p>all pattern arguments <var>p</var><sub>i</sub> are either:
 *          <ul>
 *          <li> "abstracted meta-applications" of the form
 *			<var>v</var><sub>1</sub>...<var>v</var><sub>n</sub>&nbsp;<b>.</b>&nbsp;#[<var>v</var><sub>1</sub>,...,<var>v</var><sub>n</sub>],
 *			where n&ge;0,
 *         <li>or just a single variable or the form <var>x</var>
 *          </ul>
 *		
 *		<li><p>the contraction <var>c</var> consists of
 *			<ul>
 *			<li>constructions with binders on subterms (that must recursively be of the same form)
 *				where uses of function and dispatch constructors must be consistent with their rules;
 *			<li>uses of bound and fresh variables; and
 *			<li>"explicit meta-applications" of the form #[<var>v</var><sub>1</sub>,...,<var>v</var><sub>n</sub>].
 *			</ul>
 *		</ol>
 *
 * <li><p>Special "dispatch" rule pairs are allowed on the forms
 * 		<ol>
 * 		<li><em>D</em>[<var>v</var>, <var>p</var><sub>1</sub>, ..., <var>p</var><sub>n</sub>] &rarr; <var>c</var>
 * 		<li><em>D</em>[$[C, #c, #args], <var>p</var><sub>1</sub>, ..., <var>p</var><sub>n</sub>] &rarr; $[C,$[:,<em>D</em>,'-',#c], <var>p</var><sub>1</sub>, ..., <var>p</var><sub>n</sub>, #args]
 * 		</ol>
 * 		<p>where
 * 		<ol>
 * 		<li><em>D</em> is a special dispatch constructor not used in any other patterns,
 * 		<li><var>v</var> (in the first rule) is a free variable (and must be declared so),
 * 		<li><var>c</var> is a contraction as above, and
 * 		<li>n&ge;0 and the <var>p</var><sub>i</sub> are abstracted meta-applications as above
 * 			(not necessarily the same in the two rules).
 * 		</ol>
 * 
 * </ul>
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class Compiler
{
    // Constructor

    /** Make one! */
    public Compiler()
    {}

    // Methods

    /**
     * Compiles the given set of rules
     * @param rules
     * @param sink output  
     * @throws CRSException 
     */
    public Sink compile(Map<Constructor, ArrayList<GenericRule>> rules, Sink sink, Class<AbstractGenerator> generatorClass, String srcRoot, String packageName, boolean standalone)
            throws CRSException
    {
        System.out.println("Check rules....");

        // First pass: check whether the rule system belongs to the simplified subset as defined above.
        boolean checked = true;
        for (Constructor cons : rules.keySet())
        {
            Collection<GenericRule> rulesPerCons = rules.get(cons);
 
            // Check "one rule per construction" rule.
            boolean simplifiedRuleSeen = false;
            for (Iterator<GenericRule> iterator = rulesPerCons.iterator(); iterator.hasNext();)
            {
                final GenericRule rule = iterator.next();

                if (!isDispatchRule(rule))
                {
                    // Check only 1 rule per constructor
                    if (simplifiedRuleSeen)
                    {
                        System.out.println("Error: more than one rule is defined for the construction: " + cons.symbol());
                        checked = false;
                    }
                    else
                    	simplifiedRuleSeen = true;
                }
            }
        }

        if (checked)
        {
            System.out.println("Build indexes....");

            // Second pass: build an index of all constructors, metavariables and variables defined in rules
            Map<SymbolArity, ConstructorEntry> constructors = new HashMap<SymbolArity, ConstructorEntry>();

            constructors.put(new SymbolArity("$Cons", 2), new ConstructorEntry(0, "$Cons", 2));
            constructors.put(new SymbolArity("$Nil", 0), new ConstructorEntry(1, "$Nil", 0));
            constructors.put(new SymbolArity("@", 2), new ConstructorEntry(2, "@", 2));

            for (Constructor cons : rules.keySet())
            {
                Collection<GenericRule> rulesPerCons = rules.get(cons);
                for (Iterator<GenericRule> iterator = rulesPerCons.iterator(); iterator.hasNext();)
                {
                    final GenericRule rule = iterator.next();

                    rule.getPattern().visit(new IndexBuilderVisitor(constructors), new LinkedExtensibleSet<Variable>());
                    rule.getContractum().visit(new IndexBuilderVisitor(constructors), new LinkedExtensibleSet<Variable>());

                    // Gets the top-level constructor and mark it as a being a function construction
                    if (rule.getPattern().kind() == Kind.CONSTRUCTION)
                    {
                        final ConstructorEntry leader = constructors.get(new SymbolArity(rule.getPattern().constructor().symbol(),
                                rule.getPattern().arity()));
                        leader.setDataConstruction(false);
                    }
                }
            }

            // Thirs pass: code generation  

            System.out.println("Generate code....");
            AbstractGenerator generator;
            try
            {
                generator = generatorClass.newInstance();
            }
            catch (Exception e)
            {
                throw new RuntimeException(e);
            } 

            generator.setConstructor(constructors);
            generator.setPackageName(packageName);
            generator.setSrcRoot(srcRoot);
            generator.setStandalone(standalone);
            generator.start();

            for (Constructor cons : rules.keySet())
            {
                Collection<GenericRule> rulesPerCons = rules.get(cons);

                // Separate the dispatch rules from the other ones.
                GenericRule rule = null;
                ArrayList<GenericRule> dispatchRule = new ArrayList<GenericRule>();
                for (Iterator<GenericRule> iterator = rulesPerCons.iterator(); iterator.hasNext();)
                {
                    final GenericRule r = iterator.next();
                    if (r.name().contains("Dispatch"))
                    {
                        dispatchRule.add(r);
                    }
                    else
                    {
                        rule = r;
                    }
                }

                if (rule != null)
                    generator.generateRule(rule);

                if (!dispatchRule.isEmpty())
                    generator.generateDispatchRules(dispatchRule);

            }

            generator.end();

            System.out.println("Done.");
            return sink;
        }
        throw new CRSException("Compiler fails. See console printouts for more details.");
    }

    // Helpers

    /** Whether or not the given rule is a dispatch rule */
    protected boolean isDispatchRule(GenericRule rule)
    {
        return rule.name().contains("Dispatch");
    }

    // Inner classes

    /**
     * Builds an index of constructors occuring in simplified and dispatch rules.  
     */
    protected class IndexBuilderVisitor extends Visitor
    {
        // State

        final protected Map<SymbolArity, ConstructorEntry> constructors;

        // Constructors

        protected IndexBuilderVisitor(Map<SymbolArity, ConstructorEntry> constructors)
        {
            this.constructors = constructors;
        }

        // Overrides

        @Override
        public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
        {
            super.visitConstruction(construction, start, bound);

            if (start)
            {
                final String symbol = construction.constructor().symbol();
                final int arity = construction.arity();
                final SymbolArity key = new SymbolArity(symbol, arity);
                if (constructors.get(key) == null)
                    constructors.put(key, new ConstructorEntry(constructors.size(), symbol, arity));
            }
        }

    }
}
