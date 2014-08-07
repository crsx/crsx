/* Copyright © 2012 IBM Corporation. */

package net.sf.crsx.generic.completer;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Kind;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.analysis.Unifier;
import net.sf.crsx.generic.Completer;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.util.Util;

/**
 * Information used during completion and "dispatchification"  
 */
final public class Environment
{
	// State

	/** Term factory */
	final public GenericFactory factory;

	/** The rule standardizer */
	final public Standardizer standardizer;
	
	/** Map positional variable names to the single global variable used to represent each...*/
	final private Map<String, Variable> variables;
	

	/** Map symbol name to integer*/
	final private Map<String,Integer> nextNewSymbol = new HashMap<String, Integer>();

	/**
	 * We keep track, internally, of the sorts of all terms which appear in
	 * the rules, using the variable subtermSorts; the keys are the actual
	 * subterms, and also free and bound variables (which may not appear as a subterm).
	 * Since many of the keys are terms, it should be used with some care,
	 * as it prevents the garbage collector from cleaning up these terms;
	 * thus, subtermSorts is rarely used directly, but only using the
	 * functions below.  This helps to guarantee that only terms which really
	 * (still) appear in our own rules are saved in subtermSorts.
	 */
	public Map<Object,Term> subtermSorts;

	/**
	 * Map the new names of overloaded symbol to their original sort / form
	 */
	public Map<String,String> overloadedSymbolsByForm;

	// Constructor

	public Environment(GenericFactory factory)
	{
		this.factory = factory;
		this.variables = new HashMap<String, Variable>();
		this.standardizer = new Standardizer(this);
		
		this.subtermSorts = new IdentityHashMap<Object,Term>();
		this.overloadedSymbolsByForm = new HashMap<String,String>();
	}

	// Methods

	/**
	 * Returns {@link Variable} for the given name.
	 * @param name
	 * @param promiscuous
	 * @return
	 */
	public Variable makeVariable(String name, boolean promiscuous)
	{
		Variable v = variables.get(name);
		if (v == null || v.promiscuous() != promiscuous)
		{
			v = factory.makeVariable(name, promiscuous);
			variables.put(name, v);
		}
		return v;
	}
	
	/** Generate unique symbol name for given constructor */
	public Constructor internalSymbol(Constructor c)
	{
		String base = c.symbol();
		if (base.contains("$"))
			base = base.substring(0, base.indexOf('$'));
		Integer number = nextNewSymbol.get(base);
		Constructor newc;
		if (number == null)
		{
			nextNewSymbol.put(base, 2);
			newc = factory.makeConstructor(base + "$1"); 
		}
		else
		{
			nextNewSymbol.put(base, number+1);
			newc = factory.makeConstructor(base + "$" + number); 
		}
//		if (newc.symbol().contains("Form-let4$7"))
//			factory.message("karma");
		return newc;
	}

	// ========== keeping track of sorts ========== //

	/**
	 * Given a mapping which contains sorts for a given term and all its
	 * subterms, save these sorts into subtermSorts.
	 * @param term a recursively generic term, as appears in either side of our
	 *   own rules (so keys in property sets are always strings)
	 * @param sort to use (or null if unknown)
	 * @param sorts a mapping which contains sorts for term and all its
	 *   subterms and bound variables; this mapping may also contain other stuff,
	 *   which should not be saved
	 */
	public void saveSortsRecursively(Term term, String sort, Map<Object,Term> sorts)
	{
		if (term == null) return; //defensive
		Term termSort = sortGet(sorts, term);
		sortPut(subtermSorts, term, termSort);

		if (sort == null)
			sort = (termSort == null || termSort.kind() != Kind.CONSTRUCTION ? null : Util.symbol(termSort));
//		if (sort != null && !sort.equals(Util.symbol(termSort)))
//			factory.warning("bad karma: inconsistent sorts ("+sort+" vs "+termSort+") for "+term);
		//TODO: unify termSort with actual sort term with parameters?
		Term 	form = factory.formOf(sort, Util.symbol(term));
		// Correct missing binder types from form.
		for (int i = 0; i < term.arity(); i++)
		{
			String subSort = null;
			if (form != null)
			{
				subSort = Util.symbol(Unifier.subSort(form, i));
				final Variable[] bs = term.binders(i);
				for (int j = 0; j < bs.length; ++j)
				{
					Term varsort = sortGet(sorts, bs[j]);
					if (varsort == null)
					{
						// Get binder sort from form.
						varsort = Util.getProperty(form.sub(i), form.binders(i)[j]);
						sortPut(sorts, bs[j], varsort);
					}
				}
			}
			// Recurse.
			saveSortsRecursively(term.sub(i), subSort,  sorts);
			for (int j = 0; j < term.binders(i).length; j++)
				sortPut(subtermSorts, term.binders(i)[j], sortGet(sorts, term.binders(i)[j]));
		}
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null) for (String key : A.propertyNames())
		{
			GenericTerm value = (GenericTerm) A.getProperty(key);
			String keySort = null;
			if (key.equals(Completer.STANDARDIZED))
			{
				// Ignore marker.
			}
			else if (key.equals(Completer.REFERENCE))
			{
				// No action for reference...TODO?
			}
			else if (key.startsWith("%"))
			{
				// Named property.
				keySort = CRS.STRING_SORT;
			}
			else if (key.startsWith("x") || key.startsWith("y") || key.startsWith("z"))
			{
				// Variable property
				keySort = Util.symbol(sortGet(sorts, factory.makeVariable(key, true) )); // HACK: relies on name-based lookup in sortGet...
			}
			else if (key.startsWith("#"))
			{
				// Meta property ignored.
			}
			String valueSort = (keySort == null ? null : Util.symbol(Util.getProperty(form, keySort.substring(1))));
			saveSortsRecursively(value, valueSort, sorts);
		}
	}
	
	/**
	 * Given a term whose sort has been saved recursively, add this sort and
	 * the sorts of its subterms and binders to the given mapping, and remove
	 * them from subtermSorts.
	 * @param term a term whose sort has been saved, as well as the sorts of
	 *   all its subterms and binders(for instance with saveSortsRecursively);
	 *   this sort is part of one of our rules, and follows the required
	 *   conventions.
	 * @param sorts a mapping which will, at the end of the routine, assign to
	 *   all subterms of term their sort; at the start of the function this may
	 *   already contain some values, which are ignored
	 */
	final public void removeSorts(Term term, Map<Object,Term> sorts)
	{
		if (term == null) return;
		Term unsorted = sortRemove(subtermSorts, term);
		if (unsorted != null)
			sortPut(sorts, term, unsorted);
		for (int i = 0; i < term.arity(); i++)
		{
			removeSorts(term.sub(i), sorts);
			for (int j = 0; j < term.binders(i).length; j++)
				sortPut(sorts, term.binders(i)[j], sortGet(subtermSorts, term.binders(i)[j]));
					// we do NOT remove binders from subtermSorts!
					// this is because binders are often reused between different rules
					// and are rarely actually removed
		}
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null) for (String key : A.propertyNames())
			removeSorts((GenericTerm) A.getProperty(key), sorts);
	}
	
	/** Helper for safe saving of sorts. */
	final public void sortPut(Map<Object,Term> sorts, Object key, Term sort)
	{
//		if (key == null)
//			warning("bad karma: null key");
		if (sort != null && sort instanceof GenericTerm)
			sort = ((GenericTerm) sort).stripProperties();
		sorts.put(key, sort);
	}

	/** Helper for safe retrieval of sorts. */
	final public Term sortGet(Map<Object,Term> sorts, Object key)
	{
		Term sort = sorts.get(key);
		if (sort == null)
		{
			// Defensive repair of missing sorts...
			if (key instanceof Term)
			{
				// Try to improve the sort of a term using current information.
				Term term = (Term) key;
				Term keysort = Util.sortOf(factory, term);
				if (keysort != null)
				{
					sort = keysort;
					sorts.put(term, sort);
				}
			}
			else if (key instanceof Variable)
			{
				Variable vkey = (Variable) key;
				for (Object o : sorts.keySet())
				{
					if (o instanceof Variable)
					{
						Variable okey = (Variable) o;
						if (vkey.name().equals(okey.name()))
						{
//							warning("bad karma: had to look up variable "+o+" by name!");
							Term t = sorts.get(o);
							sorts.put(okey, t);
							return t;
						}
					}
				}
			}
		}
		return sort;
	}

	/** Helper for safe saving of sorts. */
	public static Term sortRemove(Map<Object,Term> sorts, Object key)
	{
		return sorts.remove(key);
	}

	/** Helper for safe saving of sorts. */
	public static boolean sortContains(Map<Object,Term> sorts, Object key)
	{
		return sorts.containsKey(key);
	}
	

	/**
	 * Compute options based on current pattern and contraction
	 * <p>
	 * The computed options are: Discard and Copy.
	 */
	public void computeOptions(StandardizedRule rule)
	{
		List<Term> discards = new ArrayList<Term>(2);
		List<Term> copies = new ArrayList<Term>(2);
		// List<Term> weak = new ArrayList<Term>(2);

		Map<String, Integer> patternMetavars = Util.metaVars(rule.getPattern());
		if (patternMetavars != null)
		{
			Map<String, Integer> contractMetavars = Util.metaVars(rule.getContractum());
			for (Entry<String, Integer> e : patternMetavars.entrySet())
			{
				if (!contractMetavars.containsKey(e.getKey()))
				{
					discards.add(factory.newMetaApplication(e.getKey(), GenericTerm.NO_TERMS));
				}
				else
				{
					final int count = contractMetavars.get(e.getKey());
					if (count > 1)
					{
						// For now always copy. Generating Share requires more analysis
						copies.add(factory.newMetaApplication(e.getKey(), GenericTerm.NO_TERMS));
					}
				}
			}
		}

		rule.setOption(Builder.DISCARD_OPTION_SYMBOL, discards);
		rule.setOption(Builder.COPY_OPTION_SYMBOL, copies);
	}

	
	// ========== error handling ========== //

	/**
	 * Give a warning to the user (but don't abort).
	 * @param txt the warning to be given
	 */
	public void warning(String txt)
	{
		factory.warning(txt, "Completer warning: ");
	}

	/**
	 * Give an error message to the user, which is collected and not shown
	 * until factory.errorCheck is called.
	 * @param txt the error to be displayed
	 * @throws CRSException if the error handler (the calling CRS) is set
	 * to be strict about errors 
	 */
	public void error(String txt) throws CRSException
	{
		factory.error(txt, "Completer error: ");
	}

	/** Throw a fatal error */
	public void fatal(String txt) throws CRSException
	{
		factory.fatal(txt, "Completer panic: ");
	}
}
