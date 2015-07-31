/** Copyright © 2009, 2014 IBM Corporation. */

package net.sf.crsx.generic.sort;

import java.util.IdentityHashMap;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.Constructor;
import net.sf.crsx.CRS;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericRule;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.generic.PropertiesConstraintsWrapper;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.Util;

/**
 * Various static utility functions related to sorts
 * 
 * @author villardl
 */
public class SortUtil
{

	/**
	 * Gets sort of given term. 
	 * @param factory for getting sorts
	 * @param rule for getting sorts for meta and fresh/free variable
	 * @param term to get the sort of
	 * @return a sort
	 */
	public static GenericTerm sortOf(GenericFactory factory, GenericRule rule, Term term)
	{
		switch (term.kind())
		{
			case CONSTRUCTION :
				return (GenericTerm) factory.sortOf(term.constructor().symbol());
			case META_APPLICATION :
				return (GenericTerm) rule.getMetaVariableSort(term.metaVariable());
			case VARIABLE_USE :
			default :
				Term sort = rule.getVariableSort(term.variable());
				if (sort == null)
					sort = rule.getFresh(term.variable());
				return (GenericTerm) sort;
		}
	}

	/**
	 * Gets properties sort for given term
	 * 
	 * @param factory
	 * @param evaluator  
	 * @param term
	 * @return
	 */
	public static Map<String, Term> sortSetOf(GenericFactory factory, GenericRule rule, PropertiesConstraintsWrapper properties, boolean evaluator)
	{
		String symbol = Util.symbol(properties);

		Map<String, Term> sortSet = null;
//		if (evaluator)
//		{
//			// Try the first arg
//			if (properties.term().arity() >= 1)
//				symbol = Util.symbol(properties.term().sub(0));
//		}
//		else
		{
			// For meta-application, the sort set is on the meta variable sort
			// which can be either data or function.
			if (properties.term().kind() == Kind.META_APPLICATION)
				symbol = Util.symbol(rule.getMetaVariableSort(symbol));
		}
		
		// If the symbol is data, then get it from the factory
		if (factory.isData(symbol))
		{
			// The property sort is on the data symbol sort
			symbol = Util.symbol(factory.sortOf(symbol));
			
		}
		sortSet = factory.sortsetFor(symbol);
		
		if (sortSet == null)
		{
			// Look up the sort set on the function/data sort
			Set<Pair<Term, Term>> formsOf = factory.formsOf(symbol);
		
			if (formsOf != null && formsOf.size() == 1)
			{
				Pair<Term, Term> formOf = formsOf.iterator().next();
				
				if (evaluator)
				{
					// Try on the first tail argument
					symbol = Util.symbol(formOf.tail().sub(0));
					sortSet = factory.sortsetFor(symbol);
				}
				else
				{
				PropertiesHolder ph = Util.propertiesHolder(formOf.head());
				if (ph == null || !ph.propertyNames().iterator().hasNext())
					ph = Util.propertiesHolder(formOf.tail());

				if (ph != null)
					sortSet = Util.namedProperties(ph, factory);
				}
			}
		}

		return sortSet;
	}

	/** 
	 * Compute sort of term as can be derived from a top-down investigation. 
	 * @param factory for checking sorts
	 * @param term to guess the sort of
	 */
	public static GenericTerm sortOf(GenericFactory factory, Term term)
	{
		if (term == null || term.kind() != Kind.CONSTRUCTION)
			return null;
		String literalSort = term.constructor().literalSort();
		if (literalSort != null)
			return factory.constant(factory.makeLiteral(literalSort, CRS.STRING_SORT));
		Set<Pair<Term, Term>> sortforms = factory.formsOf(Util.symbol(term));
		if (sortforms == null || sortforms.isEmpty())
			return null;
		// Search for a form that can be used to retrieve sort!
		for (Pair<Term, Term> sortform : sortforms)
		{
			Term form = sortform.tail();
			if (form.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(form)))
				form = form.sub(0);
			if (form.arity() != term.arity())
				continue;
			// We found a form that fits.
			Map<Variable, Term> variableSorts = SortUtil.impliedVariableSorts(factory, term, form);
			GenericTerm sort = (GenericTerm) sortform.head();
			// TODO: Sort variables...not just variable sorts!!!
			if (sort.kind() == Kind.VARIABLE_USE && variableSorts.containsKey(sort.variable()))
			{
				// Sort is variable that we could resolve.
				return (GenericTerm) variableSorts.get(sort.variable());
			}
			else if (sort.arity() == 0)
			{
				// Got a sort with no sort variables so we are done.
				return sort;
			}
			else
			{
				// Got a polymorphic sort that we shall instantiate as much as possible.
				GenericTerm[] argumentSorts = new GenericTerm[sort.arity()];
				for (int i = 0; i < argumentSorts.length; ++i)
					if (sort.sub(i).kind() == Kind.VARIABLE_USE && variableSorts.containsKey(sort.sub(i).variable()))
						argumentSorts[i] = (GenericTerm) variableSorts.get(sort.sub(i).variable());
					else
						argumentSorts[i] = sort.sub(i); // alas
				return factory.newForm(Util.symbol(sort), argumentSorts);
			}
		}
		return null; // failed to find sort
	}

	/** Return the array of variable parameters of the sort term. */
	public static Variable[] sortParams(Term sortTerm)
	{
		final Variable[] params = new Variable[sortTerm.arity()];
		for (int i = 0; i < params.length; ++i)
			params[i] = sortTerm.sub(i).variable();
		return params;
	}

	/**
	 * Compute any sort variable bindings implied by relationship between term and form.
	 * @param factory for term creation and sort lookups
	 * @param term to extract information from
	 * @param form of the term
	 * @return map from variables to sorts that are implied by the term having the sort
	 */
	public static Map<Variable, Term> impliedVariableSorts(GenericFactory factory, Term term, Term form)
	{
		assert term.kind() == Kind.CONSTRUCTION && form.kind() == Kind.CONSTRUCTION;
		assert Util.symbol(term).equals(Util.symbol(form));
		assert term.arity() == form.arity();
		Map<Variable, Term> impliedVariableSorts = new IdentityHashMap<Variable, Term>();
		for (int i = 0; i < term.arity(); ++i)
		{
			Term formSub = form.sub(i);
			// TODO: also extract form *binder sorts* to add constraints.
			if (formSub.kind() == Kind.VARIABLE_USE)
			{
				Term sub = term.sub(i);
				Term subSort = sortOf(factory, sub);
				if (subSort != null)
					impliedVariableSorts.put(formSub.variable(), subSort);
			}
		}
		return impliedVariableSorts;
	}

	/** Whether this is a special sort...it starts with '$'. */
	public static boolean isBuiltinSort(String sort)
	{
		return sort != null && sort.startsWith("$") && !sort.startsWith("$Text");
	}

	/** Whether this is a literal sort. */
	public static boolean isLiteralSort(String sort)
	{
		return sort != null && (CRS.STRING_SORT.equals(sort) || CRS.BOOLEAN_SORT.equals(sort) || CRS.NUMERIC_SORT.equals(sort));
	}


	/**
	 * Whether the constructor is a data constructor.
	 * @param factory with sorts
	 * @param constructor to check
	 */
	public static boolean isData(GenericFactory factory, Constructor constructor)
    {
		boolean result = (constructor != null && factory.isData(constructor.symbol())); 
		//System.out.println("IS_DATA("+constructor.symbol()+") = "+result);
		return result;
    }
}
