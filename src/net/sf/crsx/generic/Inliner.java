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
	 * @param rulesByFunction updated with all rules (overridden by {@link #lastDispatchify}) indexed by function symbol
	 * @throws CRSException 
	 */
	public void inline(Set<String> constructors, SortedMultiMap<String, Term> dataForms, SortedMultiMap<String, Pair<Term, Term>> functionForms, Map<String, Term> fullSort, SortedMultiMap<String, GenericRule> rulesByFunction)
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
	 * Partially evaluate the contraction of the given rule.
	 * 
	 * @throws CRSException
	 */
	private void inline(GenericRule rule) throws CRSException
	{
		String function = Util.symbol(rule.contractum); // Name of the function to partially evaluate
		
		// Get all possible candidate rules
		Set<GenericRule> rules = rulesByFunction.multiGet(function);
		assert rules != null;
		
		if (rules.size() == 1)
		{
			// Get rule to evaluate.
			GenericRule inlinedRule = rules.iterator().next(); 
			
			// Use dynamic match for computing valuation (conservative)
			// Does not work well on redex with properties and meta-variables.
			// For instance Redex=F[#1], Pattern=F[W[#2]] produces no valuation (which is normal).
			// TODO: staticMatch.
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
						
					// Override existing rule with new contractum.
					
					GenericRule newRule = new GenericRule(crs, rule.name, rule.pattern, newcontractum, rule.options);
					
					String ruleSymbol = Util.symbol(rule.pattern);
					rulesByFunction.multiRemove(ruleSymbol, rule);
					rulesByFunction.multiAdd(ruleSymbol, newRule);
					
					if (print)
						System.out.println("------ \nafter:\n" + newRule);
					
				} else
					excludes.add(rule);
			}
			else
				excludes.add(rule);
		}
		else
		{
			// Can't inline function with multiple rules as it requires something like $[Dispatch
			// TODO: could do it if only one rule statically match.
			excludes.add(rule);
		}
	}

	/**
	 * Compute the list of rules that should be considered for inlining their contractum 
	 * @return A list of rules
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

	/** 
	 * Determines whether the given rules should be inlined 
	 * @param rule the rule's contractum to considered
	 * @param candidates the rules matching the rule's top-level contractum symbol */
	private boolean inline(GenericRule rule, Set<GenericRule> candidates)
	{
		if (excludes.contains(rule))
			return false;

		// For now only single rule can be inlined.
		if (candidates.size() != 1)
			return false;

		GenericRule r = candidates.iterator().next();
			
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
