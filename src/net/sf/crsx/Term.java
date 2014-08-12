/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

import java.io.IOException;
import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;

import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;

/**
 * Full CRS term model that allows access to subterms.
 * The methods names of this interface all start with "crs" to allow for easier
 * integration with existing object models.
 *
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Term.java,v 3.6 2013/12/09 05:48:40 krisrose Exp $
 */
public interface Term extends Stub
{
	/**
	 * The variables bound by the constructor for the i'th subterm, in order.
	 * Behaviour is <b>undefined</b> if index out of range.
	 * @param index which subterm (0-based, less than {@link #arity()})
	 * @return read-only array of variables (modifying the array members may have unpredictable results)
	 */
	Variable[] binders(int index);

	/**
	 * Retrieve i'th subterm of the term, <em>under</em> any binders.
	 * Behaviour is <b>undefined</b> if i out of range.
	 * @param index index of subterm (0-based, less than {@link #arity()})
     * @throws IndexOutOfBoundsException if the index is not possible
	 */
	Term sub(int index);

	/**
	 * Open sink that will accept replacement subterm.
	 * Behavior is <b>undefined</b> if index out of range.
	 * The returned sink should be ready to accept the following {@link Sink} sequence of operations:
	 * <ul>
	 * <li>For construction subterms, an <em>Abstraction</em>.
	 * <li>For meta-aplication subterms: a <em>Term</em>.
	 * </ul>
	 * @param index index of subterm (0-based, less than {@link #arity()})
     * @throws IndexOutOfBoundsException if the index is not possible
	 */
	Sink replaceSubSink(int index);
	
	/**
	 * Set the variable used by a variable occurrence term.
	 */
	void setVariable(Variable variable);

	/**
	 * Return whether the free variables in this (sub)term obey specific restrictions.
	 * @param forbidden variables that are not allowed (not mutated)
	 * @param once variables that are allowed exactly once (not mutated)
	 * @param onceSeen variables from once that have been seen so are now forbidden (mutated if once not empty)
	 * @param promiscuous whether the term needs to be duplicateable (so no non-promiscuous variables)
	 * @param bound bound variables
	 */
	boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound);

	/**
	 * Add all free variables in this term to the set, except those that are bound.
	 * @param set where free variables will be inserted (using the destructive {@link Set#add(Object)}) 
	 * @param bound variables (that should not be considered free)
	 * @param includemetaapps whether free variables in metaapplications should be added
	 * @param base limit the set to a subset of this set (or use null to not have a limit)
	 */
	void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base);
	
	/**
	 * Add all meta-variables with their occurrence count in this term to the set.
	 * @param counts where meta-variable names and their occurrence counts will be inserted
	 */
	void addMetaCounts(Map<String, Integer> counts);

	/**
	 * Analyzes meta variables usage in contractum 
	 * 
	 * <p>This method first computes each meta variable number of uses and then aggregate the results in <code>counts</code>
	 *  
	 * @param counts where meta-variable names and their occurrence counts will be inserted
	 * @param subAnalyzers TODO
	 */
	void analyzeMetaUseContractum(Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers);
	
	/**
	 * Analyzes meta variables usage in pattern. 
	 *  
	 * @param counts the meta variables use count. Computed by {@link #analyzeMetaUseContractum(Map, Map)}
	 */
	void analyzeMetaUsePattern(Map<String, Integer> uses);
	
	
	/**
	 * Whether this and that term are equal except for specific variables in this being renamed to variables in that.
	 * @param that other term to compare to
	 * @param renamings of variables in this to variables in that
	 */
	boolean equalsModulo(Term second, ExtensibleMap<Variable, Variable>renamings);

	/**
	 * Copy this term as part of subterms inserted by substitution.
	 * (Invoked from {@link Contractum#contract(Sink, Valuation, ExtensibleMap)} when inserting a fragment of the matched redex,
	 * as well as recursively, thus this term is part of the redex.)
	 * @param sink to copy to
	 * @param valuation of original match (passed to nested contractions resulting from substituted variables)
	 * @param renamings in effect for contraction (passed to nested contractions resulting from substituted variables)
	 * @param substitution maps the variables in the pattern to the corresponding fragments of the contractum (passed to nested contractions)
	 * @param bound variables locally in the matched term (renames in the redex)
	 * @param possible variables that can still occur in redex needing substitution
	 */
	Sink subsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable,Variable> bound, Set<Variable> possible);

    /**
     * Visit all subterms of term.
     * @param visitor to use
     * @param bound variables in context
     * @throws CRSException if the visitor does
     */
    void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException;

    /**
	 * Write term as text.
	 * The term can be reread with {@link Parser#parse(Sink, String, java.io.Reader, String, int, int, java.util.Map)}
	 * of the {@link Stub#maker()}.
     * @param used updated with map from all encountered variables to the used name (with the null index map convention)
     * @param depth of term to print -- negative means that there is no limit
     * @param full TODO
     * @param namedProps whether properties are included
     * @param variableProps TODO
     * @param omitProps variable properties that correspond to binder sort declarations (and should be omitted) 
     * @param w to append the text to
     * @throws IOException if an i/o error occurs
	 */
	void appendTo(Appendable w, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException;

	/**
	 * Send term representing this term using the sorts of reify.crs.
	 * @param sink to send to
	 * @param metaArgSort map every meta-variable argument to the required sort
	 * @param freeSort map every free variable to the required sort
	 * @return sink after it has received reified term
	 */
	Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers);
	
	/**
	 * Provide all possible paths provided by this subterm
	 * @param base path to this term
	 * @return paths to all the subterms of this term
	 */
	SortedSet<Path> paths(Path base);
}
