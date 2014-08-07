/* Copyright (c) 2014 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.Map;
import java.util.Map.Entry;

import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.SimpleVariableSet;

/**
 * Optimization delaying meta-closure.
 * 
 * <p>
 * A meta closure is a contraction on the form: 
 * 
 * <pre>  b<sub>1</sub>....b<sub>n</sub>....#[a<sub>1</sub> ... a<sub>n</sub>]</pre>
 * 
 * where the arguments contains the bound variables <code>b<sub>1..n</sub></code>.
 * <p>
 * It is rewriting as a delayed closure:
 * 
 * <pre>  b<sub>1</sub>....b<sub>n</sub>.Delay<i>I</i>[a<sub>1</sub> ... a<sub>n</sub>, a<sub>1</sub> ... a<sub>n</sub>.#[a<sub>1</sub> ... a<sub>n</sub>]]</pre>
 * 
 * @author villardl
 */
public class DelayMetaClosure
{

	// 
	private GenericFactory factory;
	private GenericCRS crs;

	
	public DelayMetaClosure(GenericCRS crs)
	{
		super();

		this.crs = crs;
		this.factory = crs.factory;
	}

	/**
	 * Implements $DelayMetaClosure
	 * 
	 * @throws CRSException 
	 */
	public void optimize(Map<String, GenericRule> ruleByName) throws CRSException
	{
		BooleanHolder changed = new BooleanHolder(); // Whether optimize did changed the contractum
		for (Entry<String, GenericRule> entry : ruleByName.entrySet())
		{
			final GenericRule rule = entry.getValue();

			changed.bool = false;
			GenericTerm newContractum = optimize(rule, (GenericTerm) rule.getContractum(), SimpleVariableSet.EMPTY, changed);
			
			if (changed.bool)
			{
				GenericRule newRule = new GenericRule(crs, rule.name, rule.pattern, newContractum, rule.options);
				entry.setValue(newRule);
			}
		}
	}

	private GenericTerm optimize(GenericRule rule, GenericTerm term, ExtensibleSet<Variable> bound, BooleanHolder changed)
	{
		if (term instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper props = (PropertiesConstraintsWrapper) term;
			props.term = optimize(rule, props.term, bound, changed);
			return props;
		}
		else
		{
		switch (term.kind())
		{
			case CONSTRUCTION :
				return optimize(rule, (GenericConstruction) term, bound, changed);
			case META_APPLICATION :
				return optimize(rule, (GenericMetaApplication) term, bound, changed);
			case VARIABLE_USE :
				return term;
			default :
				assert false : "Invalid term kind:" + term.kind();
				return null;

		}
		}
	}

	private GenericTerm optimize(GenericRule rule, GenericConstruction term, ExtensibleSet<Variable> bound, BooleanHolder changed)
	{
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			ExtensibleSet<Variable> subbound = bound.extend(term.binders(i));
			GenericTerm newsub = optimize(rule, term.sub(i), subbound, changed);
			term.replaceSub(i, term.binders(i), newsub);
		}
		return term;
	}

	private GenericTerm optimize(GenericRule rule, GenericMetaApplication term, ExtensibleSet<Variable> bound, BooleanHolder changed)
	{
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			ExtensibleSet<Variable> subbound = bound.extend(term.binders(i));
			GenericTerm newsub = optimize(rule, term.sub(i), subbound, changed);
			term.replaceSub(i, term.binders(i), newsub);
		}

		if (rule.metaClosure(term, bound))
		{
			// Replace meta by Delay 
			Constructor delay = factory.makeConstructor("Delay" + term.arity());
			
			Variable[][] allbinders = new Variable[term.arity() + 1][];
			GenericTerm[] subs = new GenericTerm[term.arity() + 1];

			// Make binders.
			Variable[] binders = new Variable[term.arity()];
			GenericTerm[] args = new GenericTerm[term.arity()];
			for (int i = term.arity() - 1; i >= 0; i--)
			{
				binders[i] = factory.makeVariable("a", true);
				args[i] = factory.newVariableUse(binders[i]);
				
				allbinders[i] = GenericTerm.NO_BIND;
			}
			allbinders[term.arity()] = binders;
			
			// Make subs
			System.arraycopy(term.allSubs(), 0, subs, 0, term.allSubs().length);
			subs[term.arity()] = factory.newMetaApplication(term.metaVariable, args);
					
			// Finally make Delay
			changed.bool = true;
			return factory.newConstruction(delay, allbinders, subs);
		}

		return term;
	}
	
	private static class BooleanHolder
	{
		boolean bool;
	}

}
