/* Copyright © 2015 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.Builder;
import net.sf.crsx.CRSException;
import net.sf.crsx.Factory;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SortedMultiMap;
import net.sf.crsx.util.Util;

/**
 * Eliminate unused rules.
 * 
 * @author villardl
 */
public class DeadRulesRemover
{

	final GenericCRS crs;

	// 
	public DeadRulesRemover(GenericCRS crs)
	{
		super();
		this.crs = crs;
	}

	/**
	 * Remove dead rules 
	 * 
	 * @param constructors must be set to all constructor symbols before call (not updated)
	 * @param dataForms updated with all data forms indexed by symbol
	 * @param functionForms updated with all function forms from {@link Factory#formsOf(String)} for all sorted symbols, indexed by symbol
	 * @param fullSort updated with the full form of every sort, by sort name
	 * @param rulesByFunction updated with all non-shuffle rules (overridden by {@link #lastDispatchify}) indexed by function symbol
	 * @param shuffleRulesByFunction 
	 * @throws CRSException 
	 */
	public void removeDeadRules(Set<String> constructors, SortedMultiMap<String, Term> dataForms, SortedMultiMap<String, Pair<Term, Term>> functionForms, Map<String, Term> fullSort, SortedMultiMap<String, GenericRule> rulesByFunction, SortedMultiMap<String, GenericRule> shuffleRulesByFunction)
			throws CRSException
	{
		// Fix point algorithm: iterates until no more unused rules are found.
		Set<String> unsusedSymbols;
		do
		{
			// 1. Collect used symbols

			final CollectUsedFunctionsVisitor usedSymbolsVisitor = new CollectUsedFunctionsVisitor();

			for (Set<GenericRule> rules : rulesByFunction.values())
			{
				for (Iterator<GenericRule> iter = rules.iterator(); iter.hasNext();)
				{
					GenericRule rule = (GenericRule) iter.next();
						
					if (rule.getOptions().containsKey(Builder.MAIN_OPTION_SYMBOL))
						usedSymbolsVisitor.usedSymbols.add(Util.symbol(rule.getPattern()));

					rule.getContractum().visit(usedSymbolsVisitor, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
				}
			}

			for (Set<GenericRule> rules : shuffleRulesByFunction.values())
			{
				for (Iterator<GenericRule> iter = rules.iterator(); iter.hasNext();)
				{
					GenericRule rule = (GenericRule) iter.next();
						
					if (rule.getOptions().containsKey(Builder.MAIN_OPTION_SYMBOL))
						usedSymbolsVisitor.usedSymbols.add(Util.symbol(rule.getPattern()));

					rule.getContractum().visit(usedSymbolsVisitor, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
				}
			}

			// 2. Removed unused rules
			unsusedSymbols = new HashSet<String>(rulesByFunction.multiKeySet());
			unsusedSymbols.removeAll(usedSymbolsVisitor.usedSymbols);

			// Ignore Shuffle rules as they are eliminated by the reifier.
			
			for (String key : unsusedSymbols)
			{
	//			System.out.println("Not used: " + key);
				rulesByFunction.remove(key);
				functionForms.remove(key); 
			}

		}
		while (!unsusedSymbols.isEmpty());
	}

	private static class CollectUsedFunctionsVisitor extends Visitor
	{

		// Collect used function symbols
		final HashSet<String> usedSymbols = new HashSet<String>();

		public CollectUsedFunctionsVisitor()
		{}

		@Override
		public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
		{
			if (start)
				usedSymbols.add(Util.symbol(construction));
		}

	}
}
