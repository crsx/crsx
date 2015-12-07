/* Copyright © 2015 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.CRSException;
import net.sf.crsx.Contractum;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SortedMultiMap;
import net.sf.crsx.util.Util;

/**
 * Rule inliner
 * 
 * Runs after the dispatchifier
 * 
 * @author villardl
 */
public class Inliner
{

	final GenericCRS crs;
	
	/** All rules */
	private SortedMultiMap<String, GenericRule> rulesByFunction;

	/** Rules not to inline */
	private HashSet<GenericRule> excludes;
	
	// 
	public Inliner(GenericCRS crs)
	{
		super();
		this.crs = crs;
	}

	/**
	 * Implements $Inline
	 * 
	 * @param constructors must be set to all constructor symbols before call (not updated)
	 * @param dataForms updated with all data forms indexed by symbol
	 * @param functionForms updated with all function forms from {@link Factory#formsOf(String)} for all sorted symbols, indexed by symbol
	 * @param fullSort updated with the full form of every sort, by sort name
	 * @param rulesByFunction updated with all non-shuffle rules (overridden by {@link #lastDispatchify}) indexed by function symbol
	 * @param shuffleRulesByFunction updated with shuffle rules
	 * @throws CRSException 
	 */
	public void inline(Set<String> constructors, SortedMultiMap<String, Term> dataForms, SortedMultiMap<String, Pair<Term, Term>> functionForms, Map<String, Term> fullSort, SortedMultiMap<String, GenericRule> rulesByFunction, SortedMultiMap<String, GenericRule> shuffleRulesByFunction)
			throws CRSException
	{
		this.rulesByFunction = rulesByFunction; 
		this.excludes = new HashSet<GenericRule>();

		// Iterate until nothing to do.
		List<GenericRule> toInline;
		do
		{
			toInline = toInline();
			if (toInline.isEmpty())
				break;

			for (GenericRule r : toInline)
				inline(r);
		}
		while (true);
	}

	/**
	 * Performs inlining on given rule 
	 * @throws CRSException
	 */
	private void inline(GenericRule rule) throws CRSException
	{
		// Get the rule.
		String function = rule.contractum.constructor().symbol();
		Set<GenericRule> rules = rulesByFunction.multiGet(function);

		assert rules != null;

		if (rules.size() == 1)
		{
			GenericRule inlinedRule = rules.iterator().next();
			
			// Use dynamic match for computing valuation (conservative)
			// Does not work well on redex with properties and meta-variables.
			// For instance Redex=F[#1], Pattern=F[W[#2]] produces no valuation (which is normal).
			Valuation valuation = inlinedRule.match(rule.contractum);
			if (valuation != null)
			{
				Buffer b = new Buffer(rule.contractum.maker());
				valuation.staticContract(b.sink());
				Contractum newcontractum =  (Contractum) b.term(true);
				
				if (newcontractum != null)
				{
					boolean print = false;
					if (print)
					{
						System.out.println("\n\n=============================== START INLINE:\n" + rule);
						System.out.println("\n----- inlined rule:\n" + inlinedRule);
					}
						
					GenericRule newRule = new GenericRule(crs, rule.name, rule.pattern, newcontractum, rule.options);
					
					rulesByFunction.multiRemove(rule.pattern.constructor().symbol(), rule);
					rulesByFunction.multiAdd(rule.pattern.constructor().symbol(), newRule);
					
					if (print)
						System.out.println("------ \nafter:\n" + newRule);
					
				} else
				
					excludes.add(rule);
			}
			else
			{
				// Couldn't statically contract rules. Record.
				excludes.add(rule);
			}
		}
		else
		{
			// Can't inline function with multiple rules as it requiress something like $[Dispatch
			excludes.add(rule);
		}
	}

	/**
	 * Get the list of rules to perform inlining on.
	 */
	private List<GenericRule> toInline()
	{
		ArrayList<GenericRule> rules = new ArrayList<GenericRule>(64);
		for (String function : rulesByFunction.multiKeySet())
		{
			for (GenericRule r : rulesByFunction.multiGet(function))
			{
				boolean candidate = false;

				if (r.getContractum().kind() == Kind.CONSTRUCTION)
				{
					String symbol1 = r.getContractum().constructor().symbol();

					// for now don't inline recursive rules
					if (!r.pattern.constructor().symbol().equals(symbol1))
					{
						Set<GenericRule> rules1 = rulesByFunction.multiGet(symbol1);
					
						candidate = inline(r, rules1);
					}
				}

				if (candidate)
					rules.add(r);
			}
		}
		return rules;
	}

	/** whether the given rules should be inlined */
	private boolean inline(GenericRule rule, Set<GenericRule> rules)
	{
		if (excludes.contains(rule))
			return false;

		// For now only single rule can be inlined.
		if (rules.size() != 1)
			return false;

		GenericRule r = rules.iterator().next();
			
		final String function = Util.symbol(rule.getContractum());
		
		// Not inlinable if recursive
		if (r.contractum.kind() == Kind.CONSTRUCTION && Util.symbol(r.contractum).equals(function))
			return false;
			
		if (r.inline())
			return true;
		
		// By default: don't inline
		return false;
	}
	
	
	
}
