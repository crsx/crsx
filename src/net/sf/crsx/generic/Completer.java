/* Copyright © 2011, 2012 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sorting;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.analysis.Unifier;
import net.sf.crsx.generic.completer.Environment;
import net.sf.crsx.generic.completer.StandardizedRule;
import net.sf.crsx.generic.completer.Standardizer;
import net.sf.crsx.generic.sort.SortUtil;
import net.sf.crsx.util.HashMultiMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.MultiMap;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.Quad;
import net.sf.crsx.util.Util;

/**
 * This class turns a set of left-linear rules into an orthogonal and complete
 * set of rules which has roughly the same meaning.  That is, given overlapping
 * rules one is chosen (the one which appears first), and data rules are made a
 * part of the functional rules (overriding the behavior of the functional
 * rules they may overlap with).
 * <p>
 * The result follows very strict guidelines: all meta-variables and variables
 * are named in such a way as to represent their location in the rule,
 * reference meta-variables take variables, and all meta-variables can take a
 * variable of the form !x, which indicates that x MUST occur in whatever is
 * substituted for the meta-variable (and complements the normal syntax of
 * omitting x from the argument list); all argument lists have the variables
 * in the order in which they were defined.
 * <p>
 * Moreover, in order to be complete, the rules follow very strict guidelines
 * as to typing: if a term has a subterm of sort ι, then at that position
 * either there is a rule for all the different data constructors of sort ι,
 * or a meta-variable.  If ι is a sort variable, this subterm can only be a
 * meta-variable.  As an example, suppose we have a function constructor for
 * identity:
 * <p align=center>	 &forall; a.I[a] :: a
 * <p>
 * Then this function constructor can only have a pattern of the form I[#x]
 * (which has sort a); it is not, for instance, allowed to have a rule
 * I[O] &rarr; O where O is a data constructor, because you cannot consider data
 * instantiations of a sort constructor.
 * <p>
 * As first the functional rules, and later the data rules, are added into the
 * system, these properties are always preserved in the internal set of rules
 * the Completer keeps track of.
 * 
 * <h4>Notes</h4>
 * The output of this system does not necessarily translate back to a set of
 * rules: in the result, reference meta-variables are replaced by terms
 * (meta-variable applications which may take bound arguments), and to deal
 * with non-fully-extended meta-variables the rules use a syntax to indicate
 * that a certain bound variable MUST be present (note that this is not a
 * stable property).
 * <p>
 * Rather than giving an output, therefore, "dispatchify" functionality was
 * built into the system.  This functionality creates rules of a very simple
 * style which can be fed straight into the compiler (these rules will still
 * have the illegal features).
 * <p>
 * TODO: In addition, there is currently NO SUPPORT for non-promiscuous variables
 * or shared meta-variables.  These properties are completely ignored.
 * Since they are kind of important for optimizations, this should probably
 * be changed in the future. :)
 */
public class Completer
{
	// Some local constants
	
	final public static String REFERENCE = "$$REFERENCE";
	final public static String STANDARDIZED = "$$STANDARDIZED";
	final public static String PRESENT = "$Present";
	
	/** Used for looking up sort information */
	private final GenericFactory factory;
	
	/** Various information for performing completion and dispatchification */
	private volatile Environment env;
	
	/**
	 * this keeps track of our own rules; the keys are declarations
	 * of function constructors (so as to deal with overloaded symbols
	 * more easily), the values "rules", where the right-hand side may
	 * be null (and the string is the rule name this rule is an
	 * instantiation of);
	 * the rules in this list are defined to always be complete (a
	 * term without free semantic variables is either in
	 * constructor-normal form, or matches one of the rules here), and
	 * orthogonal, as well as fully extended
	 */
	private Map<String,List<StandardizedRule>> ruleQuadsByConstructor;
	
	/**
	 * We store textual representations of all sorts for function constructors.
	 * This is used to quickly check whether a rule satisfies sort-minimality.
	 */
	private Set<String> declarations;
	
	/** Whether overlaps are quietly permitted. */
	final private boolean allowOverlaps;
	
	/**
	 * Overloaded symbols are mightily inconvenient, so we will get rid of
	 * them: for each different form of an overloaded instance we create a
	 * new name, and map them across.  Since we work with an internal term
	 * structure anyway (which involves copying all terms), we can normally
	 * work with terms without overloaded symbols.
	 */
	private Map<String,Pair<Term,Term>> overloadedSymbolsByName;
		
	/** Result of the dispatchification. */
	private final List<StandardizedRule> dispatchifyResult = new ArrayList<StandardizedRule>();
	
	/** Whether we omit warnings about missing cases. */
	final private boolean allowMissingCases;
	
	/** Whether to run parallel jobs */
	final private boolean parallel;
	
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
	private void saveSortsRecursively(Term term, String sort, Map<Object,Term> sorts)
	{
		env.saveSortsRecursively(term, sort, sorts);
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
	private void removeSorts(Term term, Map<Object,Term> sorts)
	{
		env.removeSorts(term, sorts);
	}
	/** Helper for safe saving of sorts. */
	private void sortPut(Map<Object,Term> sorts, Object key, Term sort)
	{
		env.sortPut(sorts, key, sort);
	}

	/** Helper for safe retrieval of sorts. */
	private Term sortGet(Map<Object,Term> sorts, Object key)
	{
		return env.sortGet(sorts, key);
	}

	/** Helper for safe saving of sorts. */
	private Term sortRemove(Map<Object,Term> sorts, Object key)
	{
		return Environment.sortRemove(sorts, key);
	}

	/** Helper for safe saving of sorts. */
	private boolean sortContains(Map<Object,Term> sorts, Object key)
	{
		return Environment.sortContains(sorts, key);
	}
		
	// ========== using the standard naming conventions ========== //
	
	/**
	 * Create a construction F of the given form (from
	 * a sort declaration); the result will have the given sort, and be saved as
	 * such in the global variable subtermSorts.  This construction will match
	 * all terms of the form {A} F[s1,...,sn] possibly containing the given
	 * bound variables, and uses a standard naming for variables and
	 * meta-variables.
	 * @param form a form (as used in constructor declarations)
	 * @param sort a sort (any kind, polymorphic or not)
	 * @param constructor the string to be used as a constructor
	 * 	 (may be different from the constructor used in the given form)
	 * @param pos the current position in a larger term, used for naming
	 * @param bound a list of variables bound in a larger term, should be used
	 *   as parameters in meta-variables
	 * @param sorts the sorts for the newly created form and all its subterms
	 *   are saved in the mapping "sorts" (sorts may contain some values to
	 *   start with; these are just ignored); the sorts for the variables in
	 * @param omitPropertySet if set to true, the resulting term should not
	 *   come with a property set, even if its sort dictates 
	 *   bound is already saved in sorts.
	 */
	private GenericTerm generalStandardizedPattern(Term form, Term sort, String constructor,
									String pos,	List<Variable> bound,
									Map<Object,Term> sorts,
									boolean omitPropertySet) throws CRSException
	{
		return env.standardizer.generalStandardizedPattern(form, sort, constructor, pos, bound, sorts, omitPropertySet);
	}

	/** Create meta-application in "standardized" form. */
	private PropertiesConstraintsWrapper standardPatternMetaApplication(String metaVariable, GenericTerm[] mvarargs)
    {
	  return env.standardizer.standardPatternMetaApplication(metaVariable, mvarargs);
    }

	// ========== making copies which follow the standard conventions ========== //
	
	/**
	 * Create a copy of an arbitrary term following the conventions, while
	 * making sure to save the sorts of the new term; any subterms given in
	 * the mapping "replacements" should be replaced by their respective
	 * values.
	 * @param term a term following the conventions from our self-created
	 *   rules (most importantly, that property set keys are always strings)
	 * @param replacements a mapping from subterms of term to generic terms
	 *   which follow all the usual conventions, and which that particular
	 *   subterm should be replaced with
	 * @param sorts a mapping which assigns to all subterms of term a sort,
	 *   and which should be extended with a sort denotation for all subterms
	 *   in the newly created sort
	 */
	private GenericTerm copyAndReplace(Term term, Map<Object,Term> sorts, Map<Term,GenericTerm> replacements)
	{
		 return env.standardizer.copyAndReplace(term, sorts, replacements);
	}
	
	/**
	 * Create a copy of an arbitrary term following the conventions, while
	 * making sure to save the sorts of the new term.
	 * @param term a term following the conventions from our self-created
	 *   rules (most importantly, that property set keys are always strings)
	 * @param sorts a mapping which assigns to all subterms of term a sort,
	 *   and which should be extended with a sort denotation for all subterms
	 *   in the newly created sort
	 */
	private GenericTerm createCopy(Term term, Map<Object,Term> sorts)
	{
		return env.standardizer.createCopy(term, sorts);
	}
	
	/**
	 * Create "copies" of the pattern and contractum of the given rule which
	 * satisfy the standard conventions, and with all relevant sorts saved in
	 * the parameter "sorts".
	 * @param rule a rule, with pattern and contractum and all sort information
	 *   of both these terms saved
	 * @param sorts an initially empty mapping, used to save the sorts of the
	 *   result terms
	 * @param keysorts an initially empty mapping, used to save the sorts for
	 *   keys in meta-property sets (which are not subterms, so not covered by
	 *   sorts)
	 * @return a quad &lt;pattern,contractum,name,options&gt; satisfying our conventions
	 * @throws CRSException possible result of an error being thrown if the
	 *   terms of the rule cannot be standardized, for example because of
	 *   recursive property set use { x : y ; y : x }.
	 */
	private StandardizedRule standardizeRule(GenericRule rule,
				Map<Object,Term> sorts, Map<String,Term> keysorts) throws CRSException
	{
		return env.standardizer.standardizeRule(rule, sorts, keysorts);
	}
	
	/** Return copy of term where standardization has been reversed. */
	private GenericTerm unstandardize(GenericTerm term)
	{
		return env.standardizer.unstandardize(term);
	}
	
	// ========== initialization ========== //
	
	/**
	 * Basic constructor for completing a rule system into "dispatchified" form.
	 * Dispatchifying means to transform the system into a set of rules where
	 * pattern matching is only ever done on the first element, and then only
	 * in a very trivial way (checking the top symbol, or otherwise checking
	 * presence of a given bound variable).
	 * 
	 * @param fac a factory needs to be supplied for sort information
	 * @param overlaps whether we accept overlaps without warnings
	 * @param ruleByName to complete
	 * @throws CRSException if things go wrong
	 */
	public Completer(GenericFactory fac, boolean overlaps, Map<String,GenericRule> ruleByName) throws CRSException
	{
		factory = fac;
		env = new Environment(fac); 
		allowOverlaps = overlaps;
		parallel = factory.defined(Factory.PARALLEL_OPTION);

		ruleQuadsByConstructor = new HashMap<String,List<StandardizedRule>>();
		overloadedSymbolsByName = new HashMap<String,Pair<Term,Term>>();
		
		declarations = new HashSet<String>();

		allowMissingCases = (Util.getInteger(factory, Factory.ALLOW_MISSING_CASES_OPTION, 0) > 0);

		// For each function sort, generates a catch-all rule with no contractum.
		Set<String> constructors = factory.getSortedConstructors();
		for (String constructor : constructors)
		{
			if (!factory.isFunction(constructor)) continue;
			
			Set<Pair<Term,Term>> forms = factory.formsOf(constructor);
			int k = 0;
			for (Pair<Term,Term> pair : forms)
			{
				Term sort = pair.head();
				Term form = pair.tail();
	        	if (form.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(form)))
	        		form = form.sub(0);
				String description = printDeclarationModuloVariables(sort, form);
				declarations.add(description);

				// Compute unique name for each form.
				String name = constructor;
				if (forms.size() > 1)
				{
					while (constructors.contains(constructor + k)) k++;
					name = constructor + k;
					k++;
					overloadedSymbolsByName.put(name, new Pair<Term,Term>(sort, form));
					env.overloadedSymbolsByForm.put(description, name);
				}
				
				GenericTerm basicform = generalStandardizedPattern(form, sort, name, "", new LinkedList<Variable>(), env.subtermSorts, false);
				StandardizedRule r = new StandardizedRule(factory, basicform, null, factory.makeConstructor("⟨undefined⟩"), null);
				List<StandardizedRule> rulelist = ruleQuadsByConstructor.get(name);
				if (rulelist == null)
				{
					rulelist = new ArrayList<StandardizedRule>();
					ruleQuadsByConstructor.put(name, rulelist);
				}
				rulelist.add(r);
			}
		}

        if (factory.verbosity() > 1)
        	factory.message(("// - function catch-all rules generated..."));


		// deal with overloading for data constructors, too
		for (String constructor : constructors)
		{
			if (!factory.isData(constructor)) continue;
			
			Set<Pair<Term,Term>> forms = factory.formsOf(constructor);
			if (forms.size() <= 1) continue;
			int k = 0;
			for (Pair<Term,Term> pair : forms)
			{
				Term sort = pair.head();
				Term form = pair.tail();
				while (constructors.contains(constructor + k)) k++;
				String name = constructor+k;
				k++;
				String description = printDeclarationModuloVariables(sort, form);
				overloadedSymbolsByName.put(name, new Pair<Term,Term>(sort, form));
				env.overloadedSymbolsByForm.put(description, name);
			}
		}

        if (factory.verbosity() > 1)
        	factory.message(("// - data catch-all rules generated..."));

		// Now run the completer
		run(ruleByName);
	}

	/**
	 * Return "dispatchified" version of the rules loaded into the Completer instance.
	 * The returned list of quadruples contain the following components:
	 * <ol>
	 * <li>Pattern term.
	 * <li>Contraction term (shares free variables with pattern).
	 * <li>Name of rule.
	 * <li>Options of rule, including the special CompileType option with value "Dispatch", "Contract"  (shares free variables with pattern)
	 * </ol>
	 */
	public List<Quad<GenericTerm,GenericTerm,Constructor,Map<String,List<Term>>>> dispatchify() throws CRSException
	{
		List<Quad<GenericTerm,GenericTerm,Constructor,Map<String,List<Term>>>> rules = new ArrayList<Quad<GenericTerm,GenericTerm,Constructor,Map<String,List<Term>>>>();
		for (StandardizedRule q : dispatchifyResult)
		{
			Constructor name = q.three();
			//if (name.symbol().contains("Code-lift-13"))
			//	System.out.println("Had rule");
			GenericTerm pattern = unstandardize(q.one());
			GenericTerm contraction = unstandardize(q.two());
			Map<String,List<Term>> options = new HashMap<String, List<Term>>();
			if (q.four() != null)
				for (Map.Entry<String,List<Term>> e : q.four().entrySet())
				{
					String key = e.getKey();
					List<Term> optionTerms = new ArrayList<Term>();
					for (Term option : e.getValue())
						optionTerms.add(unstandardize((GenericTerm) option));
					options.put(key, optionTerms);
				}
			options.put(Builder.LAX_OPTION_SYMBOL, new ArrayList<Term>()); // so rule creation repairs the options.
			//factory.message("UNSTANDARDIZE "+q+"\n⇒ "+name+options+" : "+pattern+" → "+contraction, 2);
			rules.add(new Quad<GenericTerm, GenericTerm, Constructor, Map<String,List<Term>>>(pattern, contraction, name, options));
		}
		return rules;
	}
	
	// ========== main body of the Completer ========== //
	
	/** Hacky messy function for getting things started... */
	@SuppressWarnings("unchecked")
    private void run(Map<String,GenericRule> ruleByName) throws CRSException
	{
		Set<Object[]> dataRules = new HashSet<Object[]>();
			// item 0: left-hand side (now following our conventions)
			// item 1: right-hand side (now following our conventions)
			// item 2: sorts for all subterms of left and right
			// item 3: sorts for all keys of left and right
			// item 4: rule name
			// item 5: options
		
		respectFunctionRules(ruleByName, dataRules);

        if (factory.verbosity() > 1)
        	factory.message(("// - function rules respected..."));
		
		// deal with the data rules
		/** TODO - enable this if/when trivialCriticalPair is written **
		boolean changed = true;
		for (int i = 0; i < 5 && changed; i++)
		{
			changed = false;
			for (Object[] drule : dataRules)
				changed |= respectDataRule((GenericTerm) drule[0], (GenericTerm) drule[1],
										   (String) drule[4], (Map<GenericTerm,Term>) drule[2],
										   (Map<String,Term>) drule[3]
										  );
		}
		if (changed)
			warning("Encountered apparent loop while adding data rules; are you sure they are confluent?");
		*/
		for (int i = 0; i < 5; i++)
			for (Object[] info : dataRules)
				respectDataRule((GenericTerm) info[0], (GenericTerm) info[1], (Map<String,List<Term>>) info[5],
						   		(Constructor) info[4], (Map<Object,Term>) info[2], (Map<String,Term>) info[3]);

		// give warnings if the system is incomplete! (and remove rules leading to no contractum)
		checkCompleteness();
		
		// Now build the dispatchify list.
		dispatchifyEntries();

        if (factory.verbosity() > 1)
        	factory.message(("// - dispatchify entries generated..."));
		
		ruleQuadsByConstructor = null; //done!
	}

	/**
	 * @param ret
	 * @throws CRSException
	 */
    private void dispatchifyEntries() throws CRSException
    {
		ExecutorService pool = null;
		if (parallel)
			pool = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

	    for (final Entry<String,List<StandardizedRule>> e : ruleQuadsByConstructor.entrySet())
		{
			if (parallel)
			{
				pool.execute(new Runnable()
					{
						public void run()
						{
							try
							{
					            dispatchifyEntry(e);
							}
							catch (CRSException e)
							{
								throw new RuntimeException(e);
							}
						}
					});
			}
			else
			{
	            dispatchifyEntry(e);
			}
		}
		
		if (parallel)
		{
			pool.shutdown();
			try
            {
	            pool.awaitTermination(10, TimeUnit.MINUTES);
            }
            catch (InterruptedException e1)
            {
	            throw new CRSException(e1);
            }
		}
    }

	/**
	 * Dispatchify a single entry and return the dispatchified rules.
	 * @param ret
	 * @param e
	 * @throws CRSException
	 */
    private void dispatchifyEntry(final Entry<String, List<StandardizedRule>> e) throws CRSException
    {
	    final Set<StandardizedRule> relevantRules = new HashSet<StandardizedRule>(8);  
	    final Map<Object,Term> sorts = new HashMap<Object,Term>();

	    for (StandardizedRule q : e.getValue())
	    {
	    	final GenericTerm l = q.getPattern();
	    	final GenericTerm r = q.getContractum();
	    	//Constructor n = q.three();
	    	//Map<String,List<Term>> os = q.four();
	    	removeSorts(l, sorts);
	    	removeSorts(r, sorts);

	    	// hmm why new standardized rule here?
	    	//relevantRules.add(new StandardizedRule(l, r, n, os));
	    	relevantRules.add(q);
	    }
	    
	    if (!relevantRules.isEmpty())
	    {
	    	final List<StandardizedRule> rs = dispatchify(relevantRules, sorts);

	    	synchronized (dispatchifyResult)
	    	{
		    	if (factory.verbosity() > 6)
		        	for (StandardizedRule r : rs)
		            	factory.message("ADD "+r);
	    		dispatchifyResult.addAll(rs);
	    	}
	    }
    }

	/**
	 * @param ruleByName
	 * @param dataRules
	 * @throws CRSException
	 */
    protected void respectFunctionRules(Map<String, GenericRule> ruleByName, Set<Object[]> dataRules) throws CRSException
	{
		// deal with the normal rules, and save the data rules
		for (Entry<String, GenericRule> e : ruleByName.entrySet())
		{
			// TODO!! We assume that rule is left-linear - there should probably be a check to that extent. :)
			if (!factory.isData(Util.symbol(e.getValue().getPattern())))
			{
				final GenericRule rule = e.getValue();
				respectFunctionRule(rule);
			}
			else
			{
				Object[] info = new Object[6];
				Map<Object, Term> ruleSorts = new HashMap<Object, Term>();
				Map<String, Term> keySorts = new HashMap<String, Term>();
				StandardizedRule neatrule = standardizeRule(e.getValue(), ruleSorts, keySorts);
				info[0] = neatrule.one();
				info[1] = neatrule.two();
				info[2] = ruleSorts;
				info[3] = keySorts;
				info[4] = e.getValue().getName();
				info[5] = neatrule.four();
				dataRules.add(info);
			}
		}
	}

	/**
	 * This method tries to add the given rule (which is not a data rule) to
	 * {@link #ruleQuadsByConstructor}. If this fails (for example because the rule overlaps
	 * with existing rules), an error is given.
	 * @param rule The name of the rule we should take into account; this must
	 *   be a functional rule.
	 * @throws CRSException giving an error might in some cases cause an
	 *   exception to be thrown
	 */
	private void respectFunctionRule(final GenericRule rule) throws CRSException
	{
		final Constructor rulename = rule.getName();
		
		// check whether sort and form of the pattern are as expected (minimal)
		final Pair<Term,Term> declaration = rule.getConstructorDeclaration(rule.getPattern());
		if (declaration == null) fatal("Missing sort for rule " + rule.name());
		
		/*
		String description = printDeclarationModuloVariables(declaration.head(), declaration.tail());
		
		if (!declarations.contains(description))
		{
				  " which is less general than the declared format.");
			error("rule " + rulename + " has a <form,sort> " + description +
			return;
		}
		*/
		
		// turn the rule into a pair of generic terms in our own style
		final Map<Object,Term> ruleSorts = new HashMap<Object,Term>();
		final Map<String,Term> keySorts = new HashMap<String,Term>();
		final StandardizedRule neatrule = standardizeRule(rule, ruleSorts, keySorts);
		
		final GenericTerm pattern = neatrule.getPattern();
		final GenericTerm contractum = neatrule.getContractum();
		final Map<String,List<Term>> options = neatrule.getOptions();
		
		// now test each of the rules for overlap; 
		// if there is overlap with a rule which does not yet have a right-hand side (good case), add rules until the new pattern
		// instantiates exactly one left-hand side, and then replace the right-hand side if it was null before
		final List<StandardizedRule> relevantRules = ruleQuadsByConstructor.get(Util.symbol(pattern));
		if (relevantRules != null)
		{
			final ListIterator<StandardizedRule> iterator = relevantRules.listIterator();
			
			while (iterator.hasNext())
			{
				StandardizedRule q = iterator.next();
				GenericTerm l = q.getPattern();
				GenericTerm r = q.getContractum();
				
				if (!overlaps(l, pattern)) continue;
				
				if (r != null)
				{
					if (!allowOverlaps) warning("rule " + rulename + " overlaps with instance of " + q.three() + ".");
					continue;
				}
				
				// We have overlap! Save the sort for l, since the rule is probably going to change.
				Map<Object,Term> sortsSave = new HashMap<Object,Term>();
				removeSorts(l, sortsSave);
				for (Entry<Object,Term> e : ruleSorts.entrySet())
					sortPut(sortsSave, e.getKey(), e.getValue());
				
				// find the list of instantiations of l such that some instantiate pattern and the rest is disjunct
				List<Pair<GenericTerm,Boolean>> replacement = prepareInstantiations(l, pattern, "", 0, sortsSave, keySorts, rulename);
				if (replacement == null) continue;
				
				iterator.remove();
				for (Pair<GenericTerm,Boolean> pair : replacement)
				{
					GenericTerm p = pair.head();
					saveSortsRecursively(p, null, sortsSave);
					
					// instantiations of l which do not match the pattern are saved with an empty right-hand side (as the rule had before)
					if (!pair.tail().booleanValue())
						iterator.add(new StandardizedRule(factory, p, null, factory.makeConstructor("⟨undefined⟩"), null));
					// if p is an instantiation of l which also instantiates pattern, determine the instantiation of the contractum
					else
					{
						// determine a substitution γ such that the left-hand side of this "rule" is pattern γ
						Map<Variable,Variable> varSubstitution = new HashMap<Variable,Variable>();
						Map<String,Pair<Variable[],GenericTerm>> metaSubstitution = new HashMap<String,Pair<Variable[],GenericTerm>>();
						determineInstantiatingSubstitution(p, pattern, varSubstitution, metaSubstitution);
	
						// map the fresh variables in the new right-hand side to themselves
						Set<Variable> FV = new HashSet<Variable>();
						contractum.addFree(FV, new LinkedExtensibleSet<Variable>(), true, null);
						for (Variable v : FV)
							if (!varSubstitution.containsKey(v)) varSubstitution.put(v, v);
						
						// and apply the substitution
						GenericTerm result = substitute(contractum, varSubstitution, metaSubstitution, sortsSave, "", false);
						saveSortsRecursively(result, null, sortsSave);
						checkKeyPresence(p, result, null, rulename);
						
						iterator.add(new StandardizedRule(factory, p, result, rulename, options));
					}
				}
			}
		}
	}

	/**
	 * This method tries to add the given data rule (with information as given
	 * by standardizeRule) into our own rules list.  Since our rules list is a
	 * proper constructor system, the rule can only be added below the function
	 * constructions of the existing rules, and will only be added where a
	 * conflict with an existing pattern arises (the existing pattern may have
	 * an empty contractum; if it is non-empty, the data rule overrides it).
	 * @param pattern
	 * @param contractum
	 * @param options 
	 * @param rulename
	 * @param ruleSorts
	 * @param keySorts
	 * @param options
	 * @return true if anything was changed, false if not
	 * @throws CRSException possible result of giving an error message
	 */
	private boolean respectDataRule(GenericTerm pattern, GenericTerm contractum, Map<String, List<Term>> options, Constructor rulename,
									Map<Object,Term> ruleSorts, Map<String,Term> keySorts) throws CRSException
	{
		boolean anythingChanged = false;
		
		for (Entry<String,List<StandardizedRule>> e : ruleQuadsByConstructor.entrySet())
		{
			ListIterator<StandardizedRule> iterator = e.getValue().listIterator();
			while (iterator.hasNext())
			{
				StandardizedRule rulepair = iterator.next();
				GenericTerm l = rulepair.one();
				GenericTerm r = rulepair.two();
				Constructor ruleInstanceName = rulepair.three();
				Map<String,List<Term>> os = rulepair.four();

				// find overlaps between the data rule and the given functional rule
				LinkedList<Pair<Pair<GenericTerm,GenericTerm>,Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>>>> overlapPositions =
						new LinkedList<Pair<Pair<GenericTerm,GenericTerm>,Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>>>>();
				getOverlapPositions(overlapPositions, l, pattern, contractum, "", new LinkedList<Integer>(), env.subtermSorts, ruleSorts);
				
				if (overlapPositions.isEmpty()) continue;
				
				// We have overlap! Save the sorts for l and r, since the rule is probably going to change.
				Map<Object,Term> sortsSave = new HashMap<Object,Term>();
				removeSorts(l, sortsSave);
				removeSorts(r, sortsSave);

				// save the pair into a list, which will be altered for each of overlap positions
				List<StandardizedRule> lst = new LinkedList<StandardizedRule>();
				lst.add(new StandardizedRule(factory, l, r, ruleInstanceName, os)); // TODO: check options?
				
				// try using the data rule at each of the overlap positions; every attempt might create
				// a number of changed rules, and the other positions should be changed iteratively for
				// each of these new rules
				for (Pair<Pair<GenericTerm,GenericTerm>,Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>>> overlap : overlapPositions)
				{
					GenericTerm instantiatedPattern = overlap.head().head();
					GenericTerm instantiatedContractum = overlap.head().tail();
					List<Integer> sub = overlap.tail().head().head();
					String subPosition = overlap.tail().head().tail();
					Map<Object,Term> overlapSorts = overlap.tail().tail().head();
					Map<Variable,Term> theta = overlap.tail().tail().tail();
					
					// save the substituted sorts for the pattern and contractum, so the resulting pattern *actually* matches
					Map<String,Term> substitutedKeySorts = new HashMap<String,Term>();
					for (Entry<Object,Term> en : overlapSorts.entrySet())
						sortPut(sortsSave, en.getKey(), Unifier.apply(en.getValue(), theta, factory));
					for (Entry<String,Term> en : keySorts.entrySet())
						substitutedKeySorts.put(en.getKey(), Unifier.apply(en.getValue(), theta, factory));

					// and run the given data rule on all items of the list
					anythingChanged |= handleDataRule(instantiatedPattern, instantiatedContractum, rulename,
													  lst, sortsSave, substitutedKeySorts, sub, subPosition);
				}
				
				// this generated potentially a whole lot of rules; put them all back!
				iterator.remove();
				for (StandardizedRule q : lst)
				{
					saveSortsRecursively(q.one(), null, sortsSave);
					saveSortsRecursively(q.two(), null, sortsSave);
					iterator.add(q);
				}
			}
		}
		return anythingChanged;
	}
	
	/**
	 * Helping function for respectDataRule; given a data rule, a list of existing
	 * rules and a position we should try, this tests for each of the existing
	 * rules whether it matches with the given data rule at the given position, and
	 * if so, removes the rule and adds the instantiations relevant for this data
	 * rule.  All given terms / rules are made with the usual conventions.
	 * @param pattern The left-hand side of a data rule.
	 * @param contractum The right-hand side of a data rule.
	 * @param rulename The name of the given data rule.
	 * @param relRules A list of rules, part of our rulesByConstructor structure,
	 *   which this function should modify to respect the given data rule.
	 * @param sortsSave The sorts of all terms and subterms in relRules, pattern
	 * 	 and contractum.
	 * @param keySorts The sorts used for all the keys in the given pattern and
	 *   contractum.
	 * @param overlap The position where the given pattern and the patterns of each
	 *   of the given rules might overlap.  It is not guaranteed that there actually
	 *   is an overlap, only that the root symbol at that position overlaps with the
	 *   root symbol of the pattern.
	 * @param overlapPos A string representation of the overlapping position.
	 * @return True if anything was changed in relRules, false if not.
	 */
	boolean handleDataRule(GenericTerm pattern, GenericTerm contractum, Constructor rulename,
						   List<StandardizedRule> relRules,
						   Map<Object,Term> sortsSave, Map<String,Term> keySorts,
						   List<Integer> overlap, String overlapPos) throws CRSException
	{
		boolean anythingChanged = false;
		
		ListIterator<StandardizedRule> iterator = relRules.listIterator();
		while (iterator.hasNext())
		{
			StandardizedRule q = iterator.next();
			GenericTerm l = q.one();
			GenericTerm r = q.two();
			Constructor originalRuleName = q.three();
			Map<String,List<Term>> os = q.four();
			GenericTerm sub = subterm(l, overlap);

			if (!overlaps(sub, pattern)) continue;
			GenericTerm lcopy = createCopy(l, sortsSave);
			GenericTerm rcopy = createCopy(r, sortsSave);

			// find the list of instantiations of the subterm of l such that some instantiate pattern and the rest is disjunct
			List<Pair<GenericTerm,Boolean>> replacement =
					prepareInstantiations(sub, pattern, overlapPos, 0, sortsSave, keySorts, rulename);
			if (replacement == null) continue;
					
			// determine what the replacement would be for this rule / position
			Map<Term,GenericTerm> changes = new HashMap<Term,GenericTerm>();
			changes.put(sub, pattern);
			GenericTerm fullPattern = copyAndReplace(l, sortsSave, changes);
			changes.put(sub, contractum);
			GenericTerm fullContractum = copyAndReplace(l, sortsSave, changes);

			// go through the suggested replacements one by one, and save the results in a separate list (not the main list yet)
			boolean nonTrivialOverlap = false;
				// will be set to true if any of the instantiations of sub causes new information
			List<StandardizedRule> newrules = new LinkedList<StandardizedRule>();
				// will be updated with the instances of rules with patterns in replacement
					
			for (Pair<GenericTerm,Boolean> rep : replacement)
			{
				changes.put(sub, rep.head());
				GenericTerm p = copyAndReplace(l, sortsSave, changes);
					// p is an instantiation of l and either instantiates fullPattern
					// (which has pattern as a subterm) or does not overlap with it
						
				// l has been instantiated to p, find out what the similar instantiation does to r
				GenericTerm rModified = null;
				if (r != null)
				{
					Map<Variable,Variable> varSubstitution = new HashMap<Variable,Variable>();
					Map<String,Pair<Variable[],GenericTerm>> metaSubstitution = new HashMap<String,Pair<Variable[],GenericTerm>>();
					determineInstantiatingSubstitution(p, lcopy, varSubstitution, metaSubstitution);
					rModified = substitute(r, varSubstitution, metaSubstitution, sortsSave, "", false);
				}

				// instantiations of l which do not match the new pattern are saved with their original right-hand side (but instantiated)
				if (!rep.tail().booleanValue())
					newrules.add(new StandardizedRule(factory, p, rModified, originalRuleName, os)); // TODO: check options
						
				// if p = fullPattern γ, we should add a rule p → result = fullContractum γ
				else
				{
					// determine γ
					Map<Variable,Variable> varSubstitution = new HashMap<Variable,Variable>();
					Map<String,Pair<Variable[],GenericTerm>> metaSubstitution = new HashMap<String,Pair<Variable[],GenericTerm>>();
					determineInstantiatingSubstitution(p, fullPattern, varSubstitution, metaSubstitution);
						
					// map the free variables in the new right-hand side to themselves
					Set<Variable> FV = new HashSet<Variable>();
					fullContractum.addFree(FV, new LinkedExtensibleSet<Variable>(), true, null);
					for (Variable v : FV) varSubstitution.put(v, v);
						
					// apply the substitution, and save the result!
					GenericTerm result = substitute(fullContractum, varSubstitution, metaSubstitution, sortsSave, "", false);
					newrules.add(new StandardizedRule(factory, p, result, rulename, os)); // TODO: check options
					checkKeyPresence(p, result, null, rulename);
							
					// if result reduces with only existing rules to something which rModified reduces
					// to with any rules, this is considered as a trivial critical pair, and not
					// registered as a proper change
					if (rModified == null || trivialCriticalPair(result, rModified, p)) nonTrivialOverlap = true;
				}
			}
			
			iterator.remove();
			
			// if none of the replacements caused a relevant change, just keep the old pair!
			if (!nonTrivialOverlap)
			{
				saveSortsRecursively(lcopy, null, sortsSave);
				saveSortsRecursively(rcopy, null, sortsSave);
				iterator.add(new StandardizedRule(factory, lcopy, rcopy, originalRuleName, os)); // TODO: check options
			}
			// if something important did change, replace the old pair by the new ones
			else
			{
				for (StandardizedRule info : newrules)
				{
					saveSortsRecursively(info.one(), null, sortsSave);
					saveSortsRecursively(info.two(), null, sortsSave);
					iterator.add(info);
				}
				anythingChanged = true;
			}
		}
		
		return anythingChanged;
	}

	// ========== searching for overlaps ========== //

	/**
	 * Returns whether the two given meta-term patterns can be instantiated with the
	 * same terms.  These patterns should both be in our own standard form.
	 * @param p1 A pattern defined by us, with the usual position-based naming
	 *   scheme for variables and (reference) meta-variables, and property sets
	 *   using only string keys.  This is one of the standard patterns in our
	 *   own rules, so may not contain $[NotMatch,...] entries, but may have
	 *   !x binders in meta-variable applications.
	 * @param p2 A pattern defined by us, with the usual position-based naming
	 *   scheme for variables and (reference) meta-variables, and property sets
	 *   using only string keys.  This is a translation of a user-given pattern,
	 *   so reference meta-variables always bind all variables in their
	 *   environment and $[NotMatch,...] might occur.
	 * @return true if a shared instantiation is possible, false if not
	 */
	private boolean overlaps(Term p1, Term p2) throws CRSException
	{
		boolean p1properties = Standardizer.hasPropertySet(p1);
		boolean p2properties = Standardizer.hasPropertySet(p2);
		
		// to start, check whether sort sets correspond
		if (p1properties && p2properties)
			if (!testOverlappingPropertySets(Util.propertiesHolder(p1), Util.propertiesHolder(p2)))
				return false;
		
		// deal with $[NotMatch,a,b]
		if (p2.kind() == Kind.CONSTRUCTION && Util.symbol(p2).equals(CRS.EVAL_SYMBOL))
		{
			String subsymb = Util.symbol(p2.sub(0));
			if (subsymb.equals(Primitive.NOT_MATCH.symbol))
				return overlaps(p1, p2.sub(2)) && !instantiates(p1, p2.sub(1));

			if (subsymb.equals(Primitive.MATCH.symbol))
				return overlaps(p1, p2.sub(2));
				
			// we're not prepared to do other $-constructions for now
			warning("Currently, $-constructions in patterns are not supported (except NotMatch).");
			return false;
		}
		
		// if either is a meta-variable application, check whether variable presence is as required
		if (p1.kind() == Kind.META_APPLICATION || p2.kind() == Kind.META_APPLICATION)
		{
			boolean ignorePS = p1properties && p2properties;
			Set<String> certainBound1 = new HashSet<String>();
			Set<String> possibleBound1 = new HashSet<String>();
			getBoundOccurrences(p1, certainBound1, possibleBound1, ignorePS);
			Set<String> certainBound2 = new HashSet<String>();
			Set<String> possibleBound2 = new HashSet<String>();
			getBoundOccurrences(p2, certainBound2, possibleBound2, ignorePS);
			for (String k : certainBound1)
				if (!possibleBound2.contains(k)) return false;
			for (String k : certainBound2)
				if (!possibleBound1.contains(k)) return false;
			
			// a meta-variable with property set does not match a variable
			if (p1.kind() == Kind.META_APPLICATION && p2.kind() == Kind.VARIABLE_USE && p1properties) return false;
			if (p2.kind() == Kind.META_APPLICATION && p1.kind() == Kind.VARIABLE_USE && p2properties) return false;
			return true;
		}
		
		// a variable can only overlap with another variable, and then only if
		// either both are free, or both are the same bound variable
		if (p1.kind() == Kind.VARIABLE_USE)
		{
			if (p2.kind() != Kind.VARIABLE_USE) return false;
			return p1.variable().name().equals(p2.variable().name());
		}
		
		// the only remaining case: both are constructors, and with the same symbol and subterms
		if (p1.kind() != Kind.CONSTRUCTION || p2.kind() != Kind.CONSTRUCTION) return false;
		if (!Util.symbol(p1).equals(Util.symbol(p2))) return false;
		if (p1.arity() != p2.arity()) return false;
		
		for (int i = 0; i < p1.arity(); i++)
			if (!overlaps(p1.sub(i), p2.sub(i))) return false;
		
		return true;
	}

	/**
	 * helping function for overlaps; checks whether the requirements in the
	 * two given property sets are not contradicting each other.
	 */
	private boolean testOverlappingPropertySets(PropertiesHolder A1, PropertiesHolder A2) throws CRSException
	{
		// get the entries in a somewhat easier format to manage
		Map<String,Term> props1 = new HashMap<String,Term>();
		for (String k : A1.propertyNames()) props1.put(k, A1.getProperty(k));
		Map<String,Term> props2 = new HashMap<String,Term>();
		for (String k : A2.propertyNames()) props2.put(k, A2.getProperty(k));

		// test whether any entry that occurs in both sets corresponds
		for (String k : props1.keySet())
		{
			if (k.equals(REFERENCE) || k.equals(STANDARDIZED)) continue;
			if (!props2.containsKey(k)) continue;
			if (props1.get(k) == null && props2.get(k) != null) return false;
			if (props1.get(k) != null && props2.get(k) == null) return false;
			if (props1.get(k) != null && props2.get(k) != null)
			if (!overlaps(props1.get(k), props2.get(k))) return false;
		}
		
		// no testing needs to be done for the references, since the one in A2
		// will always have the form #Γ[x1,...,xn] where {x1,...,xn} consists
		// of all variables bound in the environment
		
		return true;
	}

	/**
	 * Returns whether the first given meta-term patterns is an instance of the second.
	 * @param p1 A pattern defined by us, with the usual position-based naming
	 *   scheme for variables and (reference) meta-variables, and property sets
	 *   using only string keys.  This is one of the standard patterns in our
	 *   own rules, so may not contain $[NotMatch,...] entries, but may have
	 *   !x binders in meta-variable applications.
	 * @param p2 A pattern defined by us, with the usual position-based naming
	 *   scheme for variables and (reference) meta-variables, and property sets
	 *   using only string keys.  This is a translation of a user-given pattern,
	 *   so reference meta-variables always bind all variables in their
	 *   environment and $[NotMatch,...] might occur.
	 * @return true if p1 is an instantiation of p2, false if not
	 */
	private boolean instantiates(Term p1, Term p2) throws CRSException
	{
		// to start, check whether sort sets correspond
		if (Standardizer.hasPropertySet(p1) && Standardizer.hasPropertySet(p2))
			if (!testInstantiatingPropertySets(Util.propertiesHolder(p1), Util.propertiesHolder(p2)))
				return false;
		
		// we're not doing $-constructions here; p2 is part of the left-hand side of a $[NotMatch]!
		if (p2.kind() == Kind.CONSTRUCTION && Util.symbol(p2).equals(CRS.EVAL_SYMBOL))
		{
			error("Encountered $-construction in the left-hand side of a $[NotMatch,...].");
			return false;
		}
		
		// a variable can only be instantiated with another variable, and then
		// only if either both are free, or both are the same bound variable
		if (p2.kind() == Kind.VARIABLE_USE)
		{
			if (p1.kind() != Kind.VARIABLE_USE) return false;
			return p1.variable().name().equals(p2.variable().name());
		}
		
		// if p2 is a meta-variable application, it is fine as long as p1
		// contains only those bound variables occurring as arguments to p2
		if (p2.kind() == Kind.META_APPLICATION)
		{
			Set<String> certainBound = new HashSet<String>();
			Set<String> possibleBound = new HashSet<String>();
			getBoundOccurrences(p1, certainBound, possibleBound, false);
			for (int i = 0; i < p2.arity(); i++)
			{
				if (p2.sub(i).kind() == Kind.VARIABLE_USE)
					possibleBound.remove(p2.sub(i).variable().name());
				else
					possibleBound.remove(p2.sub(i).sub(0).variable().name());
			}
			return possibleBound.isEmpty();
		}
		
		// the only remaining case: both are constructors, and with the same symbol,
		// and the subterms of p1 instantiate the corresponding subterms of p2
		if (p1.kind() != Kind.CONSTRUCTION || p2.kind() != Kind.CONSTRUCTION) return false;
		if (!Util.symbol(p1).equals(Util.symbol(p2))) return false;
		if (p1.arity() != p2.arity()) return false;
		
		for (int i = 0; i < p1.arity(); i++)
			if (!instantiates(p1.sub(i), p2.sub(i))) return false;
		
		return true;
	}

	/**
	 * helping function for instantiates; checks whether the requirements in
	 * the second property set are all present in the first as well.
	 */
	private boolean testInstantiatingPropertySets(PropertiesHolder A1, PropertiesHolder A2) throws CRSException
	{
		// get the entries in a somewhat easier format to manage
		Map<String,Term> props1 = new HashMap<String,Term>();
		for (String k : A1.propertyNames()) props1.put(k, A1.getProperty(k));
		Map<String,Term> props2 = new HashMap<String,Term>();
		for (String k : A2.propertyNames()) props2.put(k, A2.getProperty(k));
		
		// test whether any entry that occurs in the second set corresponds
		// with a property in the first
		for (String k : props2.keySet())
		{
			if (k.equals(REFERENCE) || k.equals(STANDARDIZED)) continue;
			if (!props1.containsKey(k)) return false;
			if (props1.get(k) == null && props2.get(k) != null) return false;
			if (props1.get(k) != null && props2.get(k) == null) return false;
			if (props1.get(k) != null && props2.get(k) != null &&
				!instantiates(props1.get(k), props2.get(k))) return false;
		}
		
		// check whether the references have the same variables (that is,
		// whether the variables in p1 are unmodified)
		Term ref1 = A1.getProperty(REFERENCE);
		Term ref2 = A2.getProperty(REFERENCE);
		if (ref1.arity() != ref2.arity()) return false;
		for (int i = 0; i < ref1.arity(); i++)
			if (ref1.sub(i).kind() != Kind.CONSTRUCTION) return false;
		
		return true;
	}
	
	/**
	 * Checks for occurrences of bound variables in a term which satisfies all
	 * the usual naming conventions.
	 * @param term A recursively generic pattern we built using the standard
	 *   conventions.  Most importantly, all bound variables have a name
	 *   starting with x, which uniquely indicates the position of their
	 *   binder.
	 * @param certain Part of the return value, contains the names of those
	 *   variables whose name starts with x which definitely occur in the
	 *   given pattern.
	 * @param possible Part of the return value, contains the name of those
	 *   variables whose name starts with x which might occur in the given
	 *   pattern (depending on meta-variable instantiation).
	 * @param ignoreProperties If true, the function should not consider
	 *   variables which occur in the topmost property set.  If false, still
	 *   only the _values_ inside this property set are considered, not the
	 *   keys.
	 */
	private void getBoundOccurrences(Term term, Set<String> certain, Set<String> possible, boolean ignoreProperties)
	{
		if (term.kind() == Kind.VARIABLE_USE)
		{
			String name = term.variable().name();
			if (name.charAt(0) == 'x')
				certain.add(term.variable().name());
		}
		
		if (term.kind() == Kind.CONSTRUCTION)
		{
			for (int i = 0; i < term.arity(); i++)
			{
				getBoundOccurrences(term.sub(i), certain, possible, false);
				for (int j = 0; j < term.binders(i).length; j++)
				{
					certain.remove(term.binders(i)[j].name());
					possible.remove(term.binders(i)[j].name());
				}
			}
		}
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			for (int i = 0; i < term.arity(); i++)
			{
				if (term.sub(i).kind() == Kind.VARIABLE_USE)
					possible.add(term.sub(i).variable().name());
				else	// only other option given that term is a pattern: PRESENT[x]
				{
					String var = term.sub(i).sub(0).variable().name();
					possible.add(var);
					certain.add(var);
				}
			}
		}
		
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null && !ignoreProperties && A.getProperty(REFERENCE) != null)
			getBoundOccurrences(A.getProperty(REFERENCE), certain, possible, false);
	}
	
	/**
	 * Finds the positions of all subterms of p1 which have root-overlap with
	 * some sort instantiation of p2, and adds the result to the given set
	 * @param ret Essentially the result, recursively added to.  Contains groups
	 * of five items:
	 *   1. p2 with positions renamed to correspond with a position of p1 (see 3)
	 *   2. c2 with positions renamed to correspond with a position of p1 (see 3)
	 *   3. subterm of p1 which p2 overlaps with
	 *   4. sorts for all the subterms of the renamed p2 and c2, corresponding
	 *   	exactly with the sorts for the subterms of p1
	 *   5. a sort substitution which should be applied on p2 to *actually* match
	 *      with p1.  Note that sort variables in p1 itself will never be
	 *      instantiated
	 * @param p1 The pattern of one of our own rules (or part thereof).
	 * @param p2 The standardized pattern of a data rule added by the user.
	 * @param c2 The standardized contractum of a data rule added by the user.
	 * @param currentPosition Position of p1 in the larger pattern it comes from.
	 * @param start Position of p1 in the larger pattern it comes from, in a
	 *   perhaps more usable form.
	 * @param p1Sorts Sorts of p1 and all its subterms
	 * @param p2Sorts Sorts of p2 and all its subterms (it may need to be
	 *   instantiated to be able to match - sort variables in p1 may not be
	 *   instantiated)
	 * @throws CRSException possible result of giving an error in the overlap
	 * 	 function
	 */
	private void getOverlapPositions(LinkedList<Pair<Pair<GenericTerm,GenericTerm>,Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>>>> ret,
									 Term p1, Term p2, Term c2, String currentPosition,
									 List<Integer> start, Map<Object,Term> p1Sorts,
									 Map<Object,Term> p2Sorts) throws CRSException
	{
		if (p1.kind() != Kind.CONSTRUCTION) return;
			
		for (int i = 0; i < p1.arity(); i++)
		{
			start.add(i);
			getOverlapPositions(ret, p1.sub(i), p2, c2, currentPosition + Standardizer.subPosition(i, p1.arity()), start, p1Sorts, p2Sorts);
			start.remove(start.size()-1);
		}
		
		if (!Util.symbol(p1).equals(Util.symbol(p2))) return;
		Map<Variable,Term> theta = new HashMap<Variable,Term>();
		if (!Unifier.instantiates(p1Sorts.get(p1), p2Sorts.get(p2), theta, factory)) return;

		Map<Object,Term> sortsSave = new HashMap<Object,Term>();
		GenericTerm p2pos = changePosition(p2, currentPosition, new HashMap<Variable,Variable>(), new HashMap<String, Variable>(), sortsSave, p2Sorts);
		GenericTerm c2pos = changePosition(c2, currentPosition, new HashMap<Variable,Variable>(), new HashMap<String, Variable>(), sortsSave, p2Sorts);

		if (overlaps(p1, p2pos))
		{
			List<Integer> positionCopy = new LinkedList<Integer>();
			for (Integer a : start) positionCopy.add(a);
			
			Pair<GenericTerm,GenericTerm> rule = new Pair<GenericTerm,GenericTerm>(p2pos, c2pos);
			Pair<List<Integer>,String> subs = new Pair<List<Integer>,String>(positionCopy, currentPosition);
			Pair<Map<Object,Term>,Map<Variable,Term>> sorts = new Pair<Map<Object,Term>,Map<Variable,Term>>(sortsSave, theta);
			Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>> combi =
					new Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>>(subs, sorts);
			ret.addFirst(new Pair<Pair<GenericTerm,GenericTerm>,Pair<Pair<List<Integer>,String>,Pair<Map<Object,Term>,Map<Variable,Term>>>>(rule, combi));
		}
	}
	
	/**
	 * Returns a copy of the given term, where all position-indicating names are changed to indicate a sub-position.
	 * @param term the term to copy
	 * @param position a string to be placed in front of all position-denoting names
	 * @param varChange used for saving variables, may be empty initially
	 * @param varName recordings names of all variables
	 * @param retSorts used to save the sorts for (all subterms and binders of) the return value
	 * @param originalSorts contains sorts for (all subterms of) term
	 */
	GenericTerm changePosition(Term term, String position, Map<Variable,Variable> varChange, Map<String,Variable> varName,
							   Map<Object,Term> retSorts, Map<Object,Term> originalSorts) throws CRSException
	{
		GenericTerm ret = null;
		switch (term.kind())
		{
			case VARIABLE_USE :
				{
					Variable x = changeVariablePosition(term.variable(), position, varChange, varName);
					ret = factory.newVariableUse(x);
				}
				break;
			
			case META_APPLICATION :
				{
					String name = term.metaVariable();
					GenericTerm[] args = new GenericTerm[term.arity()];
					for (int i = 0; i < args.length; i++)
						args[i] = changePosition(term.sub(i), position, varChange, varName, retSorts, originalSorts);
					if (name.charAt(1) == '\u0393')
						ret = standardPatternMetaApplication("#Γ" + position + name.substring(2), args);
					else
						ret = standardPatternMetaApplication("#" + position + name.substring(1), args);
				}
				break;
			
			case CONSTRUCTION :
				{
					GenericTerm[] args = new GenericTerm[term.arity()];
					Variable[][] binds = new Variable[term.arity()][];
					for (int i = 0; i < args.length; i++)
					{
						binds[i] = new Variable[term.binders(i).length];
						for (int j = 0; j < term.binders(i).length; j++)
						{
							Variable x = term.binders(i)[j];
							binds[i][j] = env.makeVariable(x.name().substring(0,1) + position + x.name().substring(1), x.promiscuous(), x.blocking(), x.shallow());
							varChange.put(term.binders(i)[j], binds[i][j]);
							varName.put(term.binders(i)[j].name(), term.binders(i)[j]);
							varName.put(binds[i][j].name(), binds[i][j]);
							retSorts.put(binds[i][j], originalSorts.get(term.binders(i)[j]));
						}
						args[i] = changePosition(term.sub(i), position+"-"+i, varChange, varName, retSorts, originalSorts);
						for (int j = 0; j < term.binders(i).length; j++)
							varChange.remove(term.binders(i)[j]);
					}
					ret = factory.newConstruction(factory.makeConstructor(term.constructor()), binds, args);
				}
				break;
		}
		
		if (Standardizer.hasPropertySet(term))
		{
			PropertiesHolder ph = Util.propertiesHolder(term);
			// Compute new named properties.
			Map<String,Term> propertyNames = new HashMap<String,Term>();
			for (String name : ph.propertyNames())
			{
				char c = name.charAt(0);
				String aname = name;
				if (c != '%' && c != 'R')
				{
					if (varName.containsKey(name))
					{
						Variable av = varName.get(name);
						aname = varChange.get(av).name();
					}
					else
					{
						aname = name.substring(0,1) + position + name.substring(1);
					}
					propertyNames.put(aname, changePosition(ph.getProperty(name), position, varChange,  varName, retSorts, originalSorts));
				}
			}
			// Compute new variable properties (empty for standardized terms)..
			Map<Variable, Term> propertyVariables = new HashMap<Variable, Term>();
			for (Variable variable : ph.propertyVariables())
			{
				Variable avariable = changeVariablePosition(variable, position, varChange, varName);
				propertyVariables.put(avariable, changePosition(ph.getProperty(variable), position, varChange,  varName, retSorts, originalSorts));
			}
			// Compute new meta-properties, if any
			Map<String, Term> metaProperties = null;
			if (ph instanceof PropertiesConstraintsWrapper)
			{
				metaProperties = new HashMap<String, Term>();
				PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
				for (String mv : pcw.propertyMetaVariables())
				{
					metaProperties.put(mv, changePosition(pcw.getMetaProperty(mv), position, varChange,  varName, retSorts, originalSorts));
				}
			}
			// Done...
			ret = Util.makePropertiesConstraintsWrapper(ret, null, propertyNames, propertyVariables, metaProperties);
		}
		
		retSorts.put(ret, originalSorts.get(term));
		return ret;
	}
	
	/**
	 * Rename actual variable according to position.
	 * @param variable to rename
	 * @param position a string to be placed in front of all position-denoting names
	 * @param varChange used for saving variables, may be empty initially; updated
	 * @param varNameChange recording map from old names to new variables 
	 * @return
	 */
	private Variable changeVariablePosition(Variable variable, String position, Map<Variable, Variable> varChange, Map<String,Variable> varName)
    {
		Variable x;
		if (varChange.containsKey(variable))
			x = varChange.get(variable);
		else
		{
			String name = variable.name();
			x = env.makeVariable(name.substring(0, 1) + position + name.substring(1), variable.promiscuous(), variable.blocking(), variable.shallow());
			varChange.put(variable, x);
			varName.put(name, variable);
			varName.put(x.name(), x);
		}
	    return x;
    }


	// ========== finding instantiations corresponding with two patterns ========== //

	/**
	 * Given two patterns which overlap, determine a list of instantiations of the
	 * first which is complete, that is, if a meta-variable Z[x1,...,xn] is
	 * instantiated, there is a case for every instantiation of the form
	 * F[Z1[x1,...,xn],...,Zm[x1,...,xn]] where F is a data constructor of the
	 * right sort.  The end result is a list of instantiations of p1, one of which
	 * instantiates p2, and the rest of which does not overlap.  This list might
	 * be empty, if it turns out that actually p1 cannot be instantiated with
	 * data constructors / present variables, or null in the same case if an
	 * error has already been given.
	 * This also saves the sorts of all (subterms of) the terms in the returned
	 * list, in the given sort mapping.
	 * @param p1 The pattern to use as the basis for the list (part of our own
	 *   rules list, and thus created in the normal way).
	 * @param p2 A pattern which overlaps with p1 (a convention-following copy
	 *   of a user-supplied rule).
	 * @param position the position of this subterm in the topmost term; this is
	 *   needed for naming newly created variables and meta-variables
	 * @param startat if p1 has the form F[s1,...,sn] and p2 has the form F[t1,
	 *   ...,tn], then if startat = i we already know that s1=t1, ...,
	 *   s_{i-1}=t_{i-1}; if p1 and p2 do not have this form, then either startat
	 *   = 0 (nothing has been checked yet), or 1 (all but the property set have
	 *   been checked)
	 * @param sortsSave Contains an entry for all subterms of p1, and is modified
	 *   by prepareInstantiations to also contain entries for all terms in the
	 *   result list. Might well be given sorts for terms which later become
	 *   redundant.
	 * @param keySorts Maps all property set keys in p2 to their sorts.
	 * @param rule used to derive sorts used in p2 where necessary
	 * @return a list of pairs with: (1) a generic term instantiating p1, and
	 *   following the conventions for a left-hand side; (2) a boolean,
	 *   indicating whether the result term also instantiates p2 (if
	 *   $[NotMatch,...] is not used, this will be true for exactly one entry in
	 *   the list).
	 * @throws CRSException possible result of giving an error, which happens if
	 *   p2 has data constructors at a position where a variable sort is
	 *   expected, or if a sort has no constructors where something is expected;
	 *   in this case, null will be returned
	 */
	private List<Pair<GenericTerm,Boolean>> prepareInstantiations(GenericTerm p1,
			Term p2, String position, int startat,	Map<Object,Term> sortsSave,
			Map<String,Term> keySorts, Constructor rulename) throws CRSException
	{
		// check for the cases where we are done with the main term, and should either
		// return [<p1,true>] without further checks or proceed to checking the
		// property set
		
//        for (Map.Entry<String,Integer> p : Util.metaVars(p1).entrySet())
//        	if (p.getValue().intValue() != 1)
//        		factory.warning("bad karma: repeated pattern meta-variable "+p1);
         
		boolean ok = false;
		if (p2.kind() != Kind.CONSTRUCTION && startat > 0)
			ok = true;
		if (p1.kind() == Kind.CONSTRUCTION && startat >= p1.arity())
			ok = true;
		if (p1.kind() == Kind.VARIABLE_USE && p2.kind() == Kind.VARIABLE_USE)
			ok = true;
		if (ok)
		{
			if (Standardizer.hasPropertySet(p2))
			{
				Term sort = sortGet(sortsSave, p1);
				Map<String, Term> sortSet = factory.sortsetFor(Util.symbol(sort));
				//if (sort.kind() == Kind.VARIABLE_USE)
				//{
				//	// Ignore property set with no sort -- it must be reference!
				//	warning("property set given with something of unbound sort " + sort + " - Sorter module should have caught this (rule "+rulename+").");
				//}
				if (sortSet == null && p1.kind() == Kind.CONSTRUCTION)
				{
					// sort does not have sort set so check if symbol form unique and with form property sort set.
					boolean functionSortSet = false;
					Set<Pair<Term,Term>> forms = factory.formsOf(Util.symbol(p1));
					if (forms != null && forms.size() == 1)
					{
						Term form = forms.iterator().next().tail();
						if (Util.hasNonVariableProperties(form))
						{
							// Add property set reference to p1...
							GenericTerm[] args = new GenericTerm[0];
							GenericTerm reference = standardPatternMetaApplication("#Γ" + position, args);
							Map<String,Term> propertyNames = new HashMap<String,Term>();
							propertyNames.put(REFERENCE, reference);
							p1 = Util.makePropertiesConstraintsWrapper(p1, null, propertyNames, null, null);
							sortPut(sortsSave, p1, sort);
							functionSortSet = true;
							// Create fake sortSet with the form sort set.
							sortSet = new HashMap<String, Term>();
							for (Pair<Term,Term> p : Util.allProperties(Util.propertiesHolder(form), factory))
								sortSet.put(Util.symbol(p.head()), p.tail());
						}
					}
					if (!functionSortSet)
						warning("property set given with something of " + (sort != null && sort.kind() == Kind.VARIABLE_USE ? "polymorphic" : sort) + " sort: cannot be checked yet (rule "+rulename+").");
				}
				if (!Standardizer.hasPropertySet(p1) && p1.kind() == Kind.META_APPLICATION)
				{
					// add a property set to p1
					GenericTerm[] args = new GenericTerm[p1.arity()];
					for (int i = 0; i < p1.arity(); i++)
						args[i] = createCopy(p1.sub(i), sortsSave);
					GenericTerm reference = standardPatternMetaApplication("#Γ" + position, args);
					Map<String,Term> propertyNames = new HashMap<String,Term>();
					propertyNames.put(REFERENCE, reference);
					propertyNames.put(STANDARDIZED, factory.nil());
					p1 = Util.makePropertiesConstraintsWrapper(p1, null, propertyNames, null, null);
					sortPut(sortsSave, p1, sort);
				}
				return preparePropertyInstantiations(p1, p2, position, new HashSet<String>(), sortsSave, keySorts, rulename, sortSet);
			}
			List<Pair<GenericTerm,Boolean>> lst = new LinkedList<Pair<GenericTerm,Boolean>>();
			lst.add(new Pair<GenericTerm,Boolean>(p1,Boolean.TRUE));
			return lst;
		}

		Term sort = sortGet(sortsSave, p2);
		if (sort == null)
			sort = sortGet(sortsSave, p1);

		// if p1 is a meta-application without a property set, but of a sort which *should*
		// come with a property set, and p2 is not a meta-application without a property set,
		// we should consider instantiations of p1: either with the bound variables, or with
		// a meta-variable application with property set
		if (p1.kind() == Kind.META_APPLICATION &&
			factory.sortsetFor(Util.symbol(sort)) != null &&
			Standardizer.hasPropertySet(p2))
		{
			LinkedList<Pair<GenericTerm,Boolean>> ret = new LinkedList<Pair<GenericTerm,Boolean>>();
			
			// first consider that p1 might be instantiated with a bound variable, or a free one
			for (int i = -1; i < p1.arity(); i++)
			{
				if (i == -1 && !factory.sortAllowsVariables(Util.symbol(sort))) continue;
				Variable x;
				if (i == -1) x = env.makeVariable("z" + position, true);
				else if (p1.sub(i).kind() == Kind.VARIABLE_USE) x = p1.sub(i).variable();
				else x = p1.sub(i).sub(0).variable();
				if (i == -1 || Unifier.equalSorts(factory, sortGet(sortsSave, p1.sub(i)), sort))
				{
					GenericTerm xUse = factory.newVariableUse(x);
					sortPut(sortsSave, xUse, sort);
					if (p2.kind() == Kind.VARIABLE_USE && p2.variable().name().equals(x.name()))
						ret.addLast(new Pair<GenericTerm,Boolean>(xUse, Boolean.TRUE));
					else
						ret.addLast(new Pair<GenericTerm,Boolean>(xUse, Boolean.FALSE));
				}
				else if (Unifier.unifiable(sortGet(sortsSave, p1.sub(i)), sort, factory))
					warning("unsure how to deal with bound variable " + p1.sub(i) + " in " + p1 + " in rule " + rulename +
							": its sort unifies with expected sort for " + p1 + " but is not equal.  " +
							"It is not clear whether a case should be added for matching on this variable.");
			}
			
			// alternative instantiations have the form {#Γ[x1,...,xn]} #Z[x1,...,xn], possibly with some variables compulsary
			// figure out which variables must be present, and make a basic replacement for p1 (without presence requirements)
			GenericTerm[] refargs = new GenericTerm[p1.arity()];
			Set<String> presentVars = new HashSet<String>();
			for (int i = 0; i < p1.arity(); i++)
			{
				if (p1.sub(i).kind() == Kind.CONSTRUCTION)
				{
					presentVars.add(p1.sub(i).sub(0).variable().name());
					refargs[i] = createCopy(p1.sub(i).sub(0), sortsSave);
					p1.replaceSub(i, p1.binders(i), p1.sub(i).sub(0));
				}
				else refargs[i] = createCopy(p1.sub(i), sortsSave);
			}
//			GenericTerm reference = standardPatternMetaApplication("#Γ" + position, refargs);
//			Map<String,Term> propertyNames = new HashMap<String,Term>();
//			propertyNames.put(REFERENCE, reference);
//			p1 = Util.makePropertiesConstraintsWrapper(p1, null, propertyNames, null, null);
			sortPut(sortsSave, p1, sort);

			// if there are no compulsary variables, just go on with the modified p1 as is
			if (presentVars.isEmpty())
			{
				if (p2.kind() == Kind.VARIABLE_USE)
				{
					ret.addLast(new Pair<GenericTerm,Boolean>(p1, Boolean.FALSE));
					return ret;
				}
			}
			else
			{
				// if there are compulsary variables, consider all possible ways for these variables to be forced
				List<GenericTerm> possibilities = new LinkedList<GenericTerm>();
				possibilities.add(p1);
				for (String bindername : presentVars)
				{
					List<GenericTerm> update = new LinkedList<GenericTerm>();
					for (GenericTerm pattern : possibilities)
						append(update, forceBound(pattern, bindername, sortsSave, 0, true));
					possibilities = update;
				}

				// and add instantiations of all the results to the return value!
				for (GenericTerm p : possibilities)
				{
					if (!overlaps(p, p2))
						ret.addLast(new Pair<GenericTerm,Boolean>(p, Boolean.FALSE));
					else
					{
						List<Pair<GenericTerm,Boolean>> remainder =
								prepareInstantiations(p, p2, position, startat, sortsSave, keySorts, rulename);
						if (remainder == null) return null;
						append(ret, remainder);
					}
				}
				return ret;
			}
		}
		
		// if p2 is a meta-variable-application, consider which bound variables
		// it contains, and whether we need to split p1 on either having those
		// variables or not; note that p2 can only have the form #Z[x1,...,xn],
		// there are no arguments !xi, and note that if p2 has a property set,
		// so does p1
		if (p2.kind() == Kind.META_APPLICATION)
		{
			boolean p2HasProperties = Standardizer.hasPropertySet(p2);
			List<Pair<GenericTerm,Boolean>> ret = new ArrayList<Pair<GenericTerm,Boolean>>();
			Set<String> certain = new HashSet<String>();
			Set<String> possible = new HashSet<String>();
			getBoundOccurrences(p1, certain, possible, p2HasProperties);
			for (int i = 0; i < p2.arity(); i++)
				possible.remove(p2.sub(i).variable().name());
			if (possible.isEmpty())
				return prepareInstantiations(p1, p2, position, 1, sortsSave, keySorts, rulename);
			String first = possible.iterator().next();
			List<GenericTerm> withBinder = forceBound(p1, first, sortsSave, 0, !p2HasProperties);
			GenericTerm withoutBinder = removeBinder(p1, first, sortsSave, false, !p2HasProperties);
			for (GenericTerm wb : withBinder)
				ret.add(new Pair<GenericTerm,Boolean>(wb, Boolean.FALSE));
			List<Pair<GenericTerm,Boolean>> remainder =
					prepareInstantiations(withoutBinder, p2, position, 0, sortsSave, keySorts, rulename);
			if (remainder == null) return null;
			append(ret, remainder);
			return ret;
		}
		
		// if it's a $[NotMatch,a,b], then if the current term does not overlap with a,
		// just go on with b; otherwise find instantiations for a, and then match b on
		// the ones which are disjunct from a
		if (p2.kind() == Kind.CONSTRUCTION && Util.symbol(p2).equals(CRS.EVAL_SYMBOL) &&
			Util.symbol(p2.sub(0)).equals(Primitive.NOT_MATCH.symbol))
		{
			Term a = p2.sub(1);
			Term b = p2.sub(2);
			if (!overlaps(p1, a))
				return prepareInstantiations(p1, b, position, 0, sortsSave, keySorts, rulename);
			List<Pair<GenericTerm,Boolean>> lst = prepareInstantiations(p1, a, position, 0, sortsSave, keySorts, rulename);
			if (lst == null) return null;
			if (lst.isEmpty())
			{
				warning("Unneccesary NotMatch " + p2 + " in rule " + rulename + ": " +
						a + " cannot be instantiated.");
				return prepareInstantiations(p1, b, position, 0, sortsSave, keySorts, rulename);
			}
			List<Pair<GenericTerm,Boolean>> ret = new LinkedList<Pair<GenericTerm,Boolean>>();
			for (Pair<GenericTerm,Boolean> pair : lst)
			{
				if (pair.tail().booleanValue())
					ret.add(new Pair<GenericTerm,Boolean>(pair.head(), Boolean.FALSE));
				else
				{
					List<Pair<GenericTerm,Boolean>> remainder = 
							prepareInstantiations(pair.head(), b, position, 0, sortsSave, keySorts, rulename);
					if (remainder == null) return null;
					append(ret, remainder);
				}
			}
			return ret;
		}

		// if it's a $[Match,a,b], then find instantiations with just the second!
		if (p2.kind() == Kind.CONSTRUCTION && Util.symbol(p2).equals(CRS.EVAL_SYMBOL) &&
			Util.symbol(p2.sub(0)).equals(Primitive.MATCH.symbol))
		{
			return prepareInstantiations(p1, p2.sub(2), position, 0, sortsSave, keySorts, rulename);
		}
		
		// if both p1 and p2 are normal constructions, we deal with subterm startat first, and then move on to the rest
		if (p1.kind() == Kind.CONSTRUCTION)
		{
			List<Pair<GenericTerm,Boolean>> sublst =
				prepareInstantiations((GenericTerm) p1.sub(startat), p2.sub(startat),
									  position + Standardizer.subPosition(startat, p1.arity()), 0,
									  sortsSave, keySorts, rulename);
			
			if (sublst == null) return null;
			LinkedList<Pair<GenericTerm,Boolean>> ret =	new LinkedList<Pair<GenericTerm,Boolean>>();
			boolean reused = false;
			//p1.replaceSub(startat, p1.binders(startat), (GenericTerm) p1.sub(startat));
			for (Pair<GenericTerm,Boolean> pair : sublst)
			{
				GenericTerm pclone;
				if (reused)
				{
					Map<Term,GenericTerm> replacement = new HashMap<Term,GenericTerm>();
					replacement.put(p1.sub(startat), pair.head());
					pclone = copyAndReplace(p1, sortsSave, replacement);
				}
				else
				{
					pclone = createCopy(p1, sortsSave) ; //p1.copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
					pclone.replaceSub(startat, p1.binders(startat), pair.head());
				}
				reused = true;
				if (pair.tail().booleanValue())
				{
					List<Pair<GenericTerm,Boolean>> remainder =
						prepareInstantiations(pclone, p2, position, startat+1, sortsSave, keySorts, rulename);
					if (remainder == null) return null;
					append(ret, remainder);
				}
				else ret.addLast(new Pair<GenericTerm,Boolean>(pclone, Boolean.FALSE));
			}
			return ret;
		}
		
		// Case where p1 is a meta-variable and p2 a literal 
		if (Util.isLiteral(p2))
		{
			// Match all literals. Might want to check at runtime for proper literal.
			GenericTerm metaLiteral = standardPatternMetaApplication(position, null);
			List<Pair<GenericTerm,Boolean>> ret = new LinkedList<Pair<GenericTerm,Boolean>>();
			ret.add(new Pair<GenericTerm,Boolean>(metaLiteral, true));
			return ret;
		}
		
		// the only remaining case: p1 is a meta-variable application, and p2 is not
		// (but p1 has a property set if and only if p2 does!)
		// check all possible instantiations of the current sort, and continue with
		// the one that matches p2
		Set<String> certainBinders = new HashSet<String>();
		LinkedList<Variable> possibleBinders = new LinkedList<Variable>();
		for (int i = 0; i < p1.arity(); i++)
		{
			Variable x;
			if (p1.sub(i).kind() == Kind.VARIABLE_USE)
				x = p1.sub(i).variable();
			else
			{
				x = p1.sub(i).sub(0).variable();
				certainBinders.add(x.name());
			}
			possibleBinders.addLast(x);
		}
		boolean hasProperties = Standardizer.hasPropertySet(p1);
		List<GenericTerm> directInstantiations = getDataForms(sort, possibleBinders, position, sortsSave, rulename, hasProperties);
		if (directInstantiations == null)
		{
			return null;
		}
		
		// directInstantiations has no PRESENT-force on any of the bound variables;
		// restore it for those variables which must be there
		for (String bindername : certainBinders)
		{
			LinkedList<GenericTerm> update = new LinkedList<GenericTerm>();
			for (GenericTerm pattern : directInstantiations)
			{
				Set<String> certain = new HashSet<String>();
				Set<String> possible = new HashSet<String>();
				getBoundOccurrences(pattern, certain, possible, false);
				if (certain.contains(bindername))
				{
					update.addLast(pattern);
					continue;
				}
				if (!possible.contains(pattern))
					continue;
				append(update, forceBound(pattern, bindername, sortsSave, 0, !hasProperties));
			}
			directInstantiations = update;
		}
		
		// given the list of immediate instantiations, create the result term,
		// which continues prepareInstantiations recursively over those
		// immediate instantiations which match with p2
		PropertiesHolder A = null;
		if (hasProperties) A = Util.propertiesHolder(p1);
		List<Pair<GenericTerm,Boolean>> ret = new LinkedList<Pair<GenericTerm,Boolean>>();
		
		for (GenericTerm t : directInstantiations)
		{
			if (A != null)  // in this case, copy the properties along as well
			{
				Map<String,Term> propertyNames = new HashMap<String,Term>();
				for (String name : A.propertyNames())
				{
					Term v = A.getProperty(name);
					if (v == null) propertyNames.put(name, v);
					else propertyNames.put(name, createCopy(v, sortsSave));
				}
				t = Util.makePropertiesConstraintsWrapper(t, null, propertyNames, null, null);
				sortPut(sortsSave, t, sort);
			}
			if (overlaps(t, p2))
			{
				List<Pair<GenericTerm,Boolean>> lst = prepareInstantiations(t, p2, position, 0, sortsSave, keySorts, rulename);
				append(ret, lst);
			}
			else
				ret.add(new Pair<GenericTerm,Boolean>(t, Boolean.FALSE));
		}
		
		return ret;
	}

	/** @see prepareInstantiations, does the property set part once the rest has been done */
	private LinkedList<Pair<GenericTerm,Boolean>> preparePropertyInstantiations(
				GenericTerm p1, Term p2, String position,
				Set<String> ignoreKeys, Map<Object,Term> sortsSave,
				Map<String,Term> keySorts, Constructor rulename,
				Map<String,Term> sortSet) throws CRSException
	{
		PropertiesHolder A1 = Util.propertiesHolder(p1);
		PropertiesHolder A2 = Util.propertiesHolder(p2);

		// put the property sets in a more manageable form
		Map<String,Term> props1 = new HashMap<String,Term>();
		for (String k : A1.propertyNames())	props1.put(k, A1.getProperty(k));
		Map<String,Term> props2 = new HashMap<String,Term>();
		for (String k : A2.propertyNames())	props2.put(k, A2.getProperty(k));

		// each of the keys in A2 must be in A1 as well, and with a matching
		// value; if not, make it so!
		for (Entry<String,Term> e : props2.entrySet())
		{
			String k = e.getKey();
			Term v = e.getValue();
			
//			if (k == null)
//				factory.warning("bad karma: null key sort?!?");
			
			if (k.equals(REFERENCE) || k.equals(STANDARDIZED)) continue;
				// we don't do anything with the reference, since by assumption
				// in p2 any reference must be fully extended
			
			if (ignoreKeys.contains(k)) continue;
				// we already handled this key
			
			ignoreKeys.add(k);

			if (props1.containsKey(k) && v == null) continue;
				// the terms overlap, so if A1 contains ¬k, then A2 cannot contain k:v;

			String pos = position + "o" + (k.charAt(0) == '#' ? "M" + k.substring(1) : k) + "c";
			//String pos = position + "o" + k + "c";
			
			if (props1.containsKey(k) && v != null)
				// k:v' ∈ A1 and k:v ∈ A2: make sure v' instantiates v!
			{
				List<Pair<GenericTerm,Boolean>> vlst =
					prepareInstantiations((GenericTerm) props1.get(k), v, pos, 0, sortsSave, keySorts, rulename);
				LinkedList<Pair<GenericTerm,Boolean>> ret =	new LinkedList<Pair<GenericTerm,Boolean>>();
				
				boolean reused = false;
				A1.setProperty(k, null);
				for (Pair<GenericTerm,Boolean> pair : vlst)
				{
					GenericTerm pclone = (reused ? createCopy(p1, sortsSave) : p1);
					reused = true;
					Util.propertiesHolder(pclone).setProperty(k, pair.head());
					if (pair.tail().booleanValue())
					{
						List<Pair<GenericTerm,Boolean>> lst =
							preparePropertyInstantiations(pclone, p2, position, ignoreKeys, sortsSave, keySorts, rulename, sortSet);
						if (lst == null) return null;
						append(ret, lst);
					}
					else
						ret.addLast(new Pair<GenericTerm,Boolean>(pclone, Boolean.FALSE));
				}
				return ret;
			}
			
			if (!props1.containsKey(k))
				// k is a key in A2 but not in A1: add it
			{
				GenericTerm pclone = createCopy(p1, sortsSave);
				Util.propertiesHolder(p1).setProperty(k, null);
				// create a value #pos[x1,...,xn], where the x1 are all variables bound
				// by the reference
				Term reference = props1.get(REFERENCE);
				GenericTerm[] args = new GenericTerm[reference == null ? 0 : reference.arity()];
				if (reference != null)
				{
					for (int i = 0; i < args.length; i++)
					{
						if (reference.sub(i).kind() == Kind.VARIABLE_USE)
							args[i] = createCopy(reference.sub(i), sortsSave);
						else args[i] = createCopy(reference.sub(i).sub(0), sortsSave);
						sortPut(sortsSave, args[i], sortGet(sortsSave, reference.sub(i)));
					}
				}
//				else
//					factory.warning("bad karma - null reference");
				GenericTerm vv = standardPatternMetaApplication("#" + pos, args);
				
				Term keysort = keySorts.get(k);
				if (sortSet != null)
					sortPut(sortsSave, vv, sortSet.get("{}"+Util.symbol(keysort))); //hack
				Util.propertiesHolder(pclone).setProperty(k, vv);
				LinkedList<Pair<GenericTerm,Boolean>> ret;
				if (props2.get(k) == null)
				{
					ret = preparePropertyInstantiations(p1, p2, position, ignoreKeys, sortsSave, keySorts, rulename, sortSet);
					ret.addFirst(new Pair<GenericTerm,Boolean>(pclone, Boolean.FALSE));
				}
				else
				{
					ignoreKeys.remove(k);
					ret = preparePropertyInstantiations(pclone, p2, position, ignoreKeys, sortsSave, keySorts, rulename, sortSet);
					ret.addLast(new Pair<GenericTerm,Boolean>(p1, Boolean.FALSE));
				}
				return ret;
			}
		}

		// all properties have been handled - return the list of just this one term!
		LinkedList<Pair<GenericTerm,Boolean>> lst =	new LinkedList<Pair<GenericTerm,Boolean>>();
		lst.add(new Pair<GenericTerm,Boolean>(p1,Boolean.TRUE));
		return lst;
	}

	/**
	 * Returns a copy of the given term, where all instances of the given
	 * variable have been removed.
	 * @param term A pattern following the conventions for our own rules.
	 * @param bindername The name of the binder that should be removed.
	 * @param sortsSave Contains the sorts for term, and is added to to also
	 *   contain the sorts of the result term.
	 * @param ignorePS If true, any property set is not copied along.
	 * @param includePS If false, and ignorePS is false, the property set
	 *   is copied along but will not have binders removed.
	 * @return The required "copy".
	 * @throws CRSException A fatal error is given if the variable occurs at
	 *   an unremovable position.
	 */
	GenericTerm removeBinder(Term term, String bindername, Map<Object,Term> sortsSave,
							 boolean ignorePS, boolean includePS) throws CRSException
	{
		if (term == null) return null;
		GenericTerm ret = null;
		
		if (term.kind() == Kind.VARIABLE_USE)
		{
			Variable x = term.variable();
			if (x.name().equals(bindername))
				fatal("Calling removeBinder(" + bindername + ") on a term which contains this binder for certain; should not happen.");
			ret = factory.newVariableUse(x);
		}
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			int Nargs = term.arity();
			for (int i = 0; i < term.arity(); i++)
			{
				if (term.sub(i).kind() == Kind.CONSTRUCTION && term.sub(i).sub(0).variable().name().equals(bindername))
					fatal("Calling removeBinder(" + bindername + ") on a term which contains this binder for certain; should not happen.");
				if (term.sub(i).kind() == Kind.VARIABLE_USE && term.sub(i).variable().name().equals(bindername))
					Nargs--;
			}
			GenericTerm[] args = new GenericTerm[Nargs];
			int pos = 0;
			for (int i = 0; i < term.arity(); i++)
			{
				if (term.sub(i).kind() == Kind.VARIABLE_USE)
					if (!term.sub(i).variable().name().equals(bindername))
					{
						args[pos] = factory.newVariableUse(term.sub(i).variable());
						sortPut(sortsSave, args[pos], sortGet(sortsSave, term.sub(i)));
						pos++;
					}
				if (term.sub(i).kind() == Kind.CONSTRUCTION)
				{
					args[pos] = createCopy(term.sub(i), sortsSave);
					pos++;
				}
			}
			ret = factory.newMetaApplication(term.metaVariable(), args);
		}
		
		if (term.kind() == Kind.CONSTRUCTION)
		{
			GenericTerm[] args = new GenericTerm[term.arity()];
			Variable[][] binds = new Variable[term.arity()][];
			for (int i = 0; i < args.length; i++)
			{
				binds[i] = term.binders(i);
				args[i] = removeBinder(term.sub(i), bindername, sortsSave, false, true);
			}
			ret = factory.newConstruction(factory.makeConstructor(term.constructor()), binds, args);
		}
			
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null && !ignorePS)
		{
			Map<String,Term> namedPropertiesConstraints = new HashMap<String,Term>();
			for (String name : A.propertyNames())
			{
				Term value;
				if (includePS) value = removeBinder(A.getProperty(name), bindername, sortsSave, false, true);
				else value = createCopy(A.getProperty(name), sortsSave);
				namedPropertiesConstraints.put(name, value);
					// this is also done for the reference, which is dealt with as a meta-application
			}
			
			if (!namedPropertiesConstraints.isEmpty())
				ret = Util.makePropertiesConstraintsWrapper(ret, null, namedPropertiesConstraints, null, null);
		}
		
		if (sortContains(sortsSave, term)) sortPut(sortsSave, ret, sortGet(sortsSave, term));
		return ret;
	}
	
	/**
	 * Returns a list with copies of the given term, where the given bound
	 * variable is forced to be present in some way.
	 * @param term A pattern following the conventions for our own rules; we
	 *   assume that it is not already the case that term contains the given
	 *   binder.
	 * @param bindername The name of the binder that should be removed.
	 * @param sortsSave Contains the sorts for term, and is added to to also
	 *   contain the sorts of the result term.
	 * @param startat Used for recursive calls; should be 0 initially.
	 * @param includePS If set to false, the function will not attempt to
	 *   force variables inside property set references.
	 * @return A list of the required "copies"; if the term does not contain
	 *   the given variable, null is returned.
	 * @throws CRSException A fatal error is given if the variable occurs at
	 *   an unremovable position.
	 */
	LinkedList<GenericTerm> forceBound(Term term, String bindername, Map<Object,Term> sortsSave,
									   int startat, boolean includePS) throws CRSException
	{
		if (term.kind() == Kind.VARIABLE_USE)
		{
			Variable x = term.variable();
			if (x.name().equals(bindername))
				fatal("Calling forceBound(" + bindername + ") on a term which already contains this binder for certain; should not happen.");
			// term does not contain this variable - return the empty list
			return null;
		}
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			int xloc = -1;
			for (int i = 0; i < term.arity(); i++)
			{
				Term sub = term.sub(i);
				Variable x;
				
				if (sub.kind() == Kind.VARIABLE_USE) x = sub.variable();
				else x = sub.sub(0).variable();
				if (x.name().equals(bindername))
				{
					if (sub.kind() == Kind.CONSTRUCTION)
						fatal("Calling forceBound(" + bindername + ") on a term which already contains this binder for certain; should not happen.");
					else xloc = i;
				}
			}
			
			GenericTerm forced = null;
			LinkedList<GenericTerm> rets = new LinkedList<GenericTerm>();

			// if one of the parameters is the required xi, create a copy with
			// that xi forced to true, and add it into the return list
			if (xloc != -1)
			{
				forced = createCopy(term, sortsSave);
				GenericTerm[] subs = new GenericTerm[1];
				subs[0] = factory.newVariableUse(term.sub(xloc).variable());
				sortPut(sortsSave, subs[0], sortGet(sortsSave, term.sub(xloc)));
				GenericTerm arg = factory.newConstruction(factory.makeConstructor(PRESENT), null, subs);
				sortPut(sortsSave, arg, sortGet(sortsSave, term.sub(xloc)));
				forced.replaceSub(xloc, null, arg);
				rets.add(forced);
			}

			// if there's no property set, we continue either the copy, or nothing
			if (!Standardizer.hasPropertySet(term) || !includePS)
			{
				if (xloc == -1) return null;
				else return rets;
			}

			// if there is a property set, it must have a reference; see whether this
			// reference can have the variable forced
			Term reference = Util.propertiesHolder(term).getProperty(REFERENCE);
			LinkedList<GenericTerm> refs = forceBound(reference, bindername, sortsSave, 0, true);
			
			// neither the term itself nor its property set contains the given variable
			if (refs == null && xloc == -1) return null;
			
			// only the term itself contains the given variable
			if (refs == null) return rets;
			
			// the property set contains the given variable; add to rets the term
			// where the variable is forced in the property set, and removed in
			// meta-variable
			GenericTerm base = removeBinder(term, bindername, sortsSave, true, false);
			Map<String,Term> propertyNames = new HashMap<String,Term>();
			propertyNames.put(REFERENCE, refs.getFirst());
			for (String name : Util.propertiesHolder(term).propertyNames())
				if (!name.equals(REFERENCE) && !name.equals(STANDARDIZED))
					propertyNames.put(name, createCopy(Util.propertiesHolder(term).getProperty(name), sortsSave));
			base = Util.makePropertiesConstraintsWrapper(base, null, propertyNames, null, null);
			sortPut(sortsSave, base, sortGet(sortsSave, term));
			rets.add(base);
			return rets;
		}
		
		// constructions
		if (startat < term.arity())
		{
			List<GenericTerm> subs = forceBound(term.sub(startat), bindername, sortsSave, 0, true);
			if (subs == null) return forceBound(term, bindername, sortsSave, startat+1, true);
			LinkedList<GenericTerm> rets = new LinkedList<GenericTerm>();
			GenericTerm original = (GenericTerm) term.sub(startat);
			for (GenericTerm sub : subs)
			{
				Map<Term,GenericTerm> replacement = new HashMap<Term,GenericTerm>();
				replacement.put(original, sub);
				GenericTerm termcopy = copyAndReplace(term, sortsSave, replacement);
				rets.add(termcopy);
			}
			GenericTerm tt = (GenericTerm) term;
			tt.replaceSub(startat, term.binders(startat), removeBinder(original, bindername, sortsSave, false, true));
			List<GenericTerm> remainder = forceBound(tt, bindername, sortsSave, startat+1, true);
			if (remainder != null) append(rets, remainder);
			tt.replaceSub(startat, tt.binders(startat), original);
			return rets;
		}
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A == null || A.getProperty(REFERENCE) == null || !includePS) return null;
		LinkedList<GenericTerm> refs = forceBound(A.getProperty(REFERENCE), bindername, sortsSave, 0, true);
		if (refs == null) return null;
		GenericTerm ret = createCopy(term, sortsSave);
		Util.propertiesHolder(ret).setProperty(REFERENCE, refs.getFirst());
		LinkedList<GenericTerm> rets = new LinkedList<GenericTerm>();
		rets.add(ret);
		return rets;
	}

	/**
	 * Get all the forms F[#Z1[x1,...,xn],...,#Zm[x1,...,xn]] where F is a data
	 * constructor of the given sort, the #Zi are meta-variables and the xj bound
	 * variables; also add the forms x where either x is one of the bound
	 * variables which has the correct sort, or a free variable if the given
	 * sort has syntactic variables
	 * @param sort a sort; could be any kind (so $List[α], BinTree[Nat] or just $Nat)
	 * @param bounds a list of all bound variables we should consider, in the order
	 *   they should occur in meta-variable applications
	 * @param pos the current position in the term, used for naming conventions
	 * @param sortsSave used to save the sorts for the newly created terms,
	 *   and also contains the sorts of all variables in bounds
	 * @param rulename used for error messages
	 * @param omitProperties if set to true, do not include a possible property
	 *   set of the result, and also do not include variables
	 * @return a list of all the suitable forms, or null if an error is encountered
	 * @throws CRSException an error is given if the given sort has no forms at all,
	 *   or it is just a sort variable
	 */
	List<GenericTerm> getDataForms(Term sort, List<Variable> bounds,
										 String pos, Map<Object,Term> sortsSave,
										 Constructor rulename, boolean omitProperties) throws CRSException
	{
		if (sort ==  null)
		{
			error("completing rule " + rulename + " fails: at position " + pos +
				  " sort-wise anything might occur.  Therefore only a meta-variable " +
				  "can be used here.");
			return null;
		}
		
		if (sort.kind() == Kind.VARIABLE_USE || Util.symbol(sort).equals(CRS.NUMERIC_SORT) || Util.symbol(sort).equals(CRS.STRING_SORT))
		{
			//error("completing rule " + rulename + " fails: at position " + pos + " matching is done on an int or string, of which there are infinitely many; could not obtain an orthogonal system.");
			return null;
			// TODO: the above is not usually an error, and actually, with NotMatch, you can; it is perhaps worth investigating
			// the possibility to include NotMatch in our own rules after all, but in a special way that only applies to ints and strings?
		}

		String sortcons = Util.symbol(sort);

		// grab all the various data forms, and save them in "constructorList"
		Set<String> datas = factory.sortDataSymbols(sortcons);
		LinkedList<Pair<String,Term>> constructorList = new LinkedList<Pair<String,Term>>();

		for (String s : datas)
		{
			Term form = formOf(sort, s);
			if (form != null)
				constructorList.addLast(new Pair<String,Term>(s, form));
		}

		// sort the list alphabetically
		Collections.sort(constructorList, new Comparator<Pair<String,Term>>()
			{
				public int compare(Pair<String,Term> o1, Pair<String,Term> o2)
				{
					return o1.head().compareTo(o2.head());
				}
			});

		// for all data constructor forms, make a term with that form
		LinkedList<GenericTerm> lst = new LinkedList<GenericTerm>();
		for (Pair<String,Term> info : constructorList)
			lst.addLast(generalStandardizedPattern(info.tail(), sort, info.head(), pos, bounds, sortsSave, omitProperties));
		
		// for all bound variables with the given sort, add them too
		if (!omitProperties)
		{
			for (Variable x : bounds)
			{
				if (Unifier.equalSorts(factory, sortGet(sortsSave, x), sort))
					lst.addLast(factory.newVariableUse(x));
				else
				{
					Term xsort = sortGet(sortsSave, x);
					if (Unifier.unifiable(xsort, sort, factory))
						warning("unsure how to deal with bound variable " + x + " in rule " + rulename +
								": its sort unifies with expected sort " + sort + " for meta-variable but is not equal.  " +
						 		"It is not clear whether a case should be added for matching on this variable.");
				}
			}
		}
	
		// if the sort has syntactic variables, add one of those, too
		if (!omitProperties && factory.sortAllowsVariables(sortcons))
			lst.addLast(factory.newVariableUse(env.makeVariable("z" + pos, true)));

		return lst;
	}

	// ========== finding and using substitutions ========== //
	
	/**
	 * Given that l instantiates the given pattern, determine a substitution
	 * gamma such that pattern gamma = l.  This substitution consists of two
	 * parts: a variable replacement (changing only the free variables) and
	 * a meta-variable substitution.
	 * @param l a recursively generic term, which is the left-hand side of a
	 * 	 rule as created by us, so satisfies the usual naming conventions and
	 *   has sorts which can be looked up in subtermSorts
	 * @param pattern a recursively generic term also following our conventions,
	 *   which might either be the left-hand side of a rule as created by us,
	 *   or the copy of a left-hand side of a user-generated rule; pattern is
	 *   such that anything that instantiates l also instantiates pattern
	 * @param varSub filled in by this function, maps variables occurring
	 *   freely in pattern to the corresponding variable in l (there always
	 *   is one, since an instantiation can only rename free variables);
	 *   this is also used in recursive calls to rename bound variables,
	 *   but these are removed afterwards
	 * @param metaSub filled in by this function, maps meta-variables
	 *   occurring in the pattern to the corresponding term [x1,...,xn].q
	 *   in l (the xi are variables which probably occur in q)
	 */
	private void determineInstantiatingSubstitution(GenericTerm l, GenericTerm pattern, Map<Variable,Variable> varSub,
													Map<String,Pair<Variable[],GenericTerm>> metaSub)
	{
		if (Standardizer.hasPropertySet(pattern))
		{
			PropertiesHolder A = Util.propertiesHolder(l);
			PropertiesHolder B = Util.propertiesHolder(pattern);
			for (String k : B.propertyNames())
			{
				GenericTerm Ak = (GenericTerm) A.getProperty(k);
				GenericTerm Bk = (GenericTerm) B.getProperty(k);
				if (Ak != null)
					determineInstantiatingSubstitution(Ak, Bk, varSub, metaSub);
				// this deliberately includes the reference
			}
		}
		
		if (pattern.kind() == Kind.VARIABLE_USE)
			varSub.put(pattern.variable(), l.variable());
		
		else if (pattern.kind() == Kind.CONSTRUCTION)
		{
			if (Util.symbol(pattern).equals(CRS.EVAL_SYMBOL))
			{
				String which = Util.symbol(pattern.sub(0));
				if (which.equals(Primitive.NOT_MATCH.symbol))
				{
					determineInstantiatingSubstitution((GenericTerm) l, (GenericTerm) pattern.sub(2), varSub, metaSub);
					return;
				}
				if (which.equals(Primitive.MATCH.symbol))
				{
					determineInstantiatingSubstitution((GenericTerm) l, (GenericTerm) pattern.sub(1), varSub, metaSub);
					determineInstantiatingSubstitution((GenericTerm) l, (GenericTerm) pattern.sub(2), varSub, metaSub);
					return;
				}
			}
			else
			{

				for (int i = 0; i < pattern.arity(); i++)
				{
					for (int j = 0; j < pattern.binders(i).length; j++)
						varSub.put(pattern.binders(i)[j], l.binders(i)[j]);
					determineInstantiatingSubstitution((GenericTerm) l.sub(i), (GenericTerm) pattern.sub(i), varSub, metaSub);
					for (int j = 0; j < pattern.binders(i).length; j++)
						varSub.remove(pattern.binders(i)[j]);
				}
			}
		}
		
		else if (pattern.kind() == Kind.META_APPLICATION)
		{
			Variable[] bound = new Variable[pattern.arity()];
			for (int i = 0; i < bound.length; i++)
			{
				Variable x;
				if (pattern.sub(i).kind() == Kind.VARIABLE_USE) x = pattern.sub(i).variable();
				else x = pattern.sub(i).sub(0).variable();
				bound[i] = varSub.get(x);
			}
			metaSub.put(pattern.metaVariable(), new Pair<Variable[],GenericTerm>(bound,l));
		}
	}
	
	/**
	 * This function applies a meta-substitution on a term, that is, a substitution
	 * consisting of two parts: free variables are mapped to other free variables
	 * (all free variables in the term are assumed to be in the substitution's
	 * domain) and meta-variables, including reference meta-variables, are mapped
	 * to constructions of the form [x1,...,xn]s where s is another (meta-)term.
	 * Note: this is only used to create the right-hand-side of a rule, and the
	 * given term is already a contractum; either the contractum of a
	 * convention-following user-given rule, or of one we defined ourselves.
	 * @param term A recursively generic term, whose sorts (both for the term
	 *   itself and for subterms) are given by the parameter sorts.
	 * @param varSub Indicates which variables are mapped to other variables.
	 *   All free variables in the term are required to be in this mapping.
	 * @param metaSub Indicates the substitution for the meta-variables; this
	 *   should contain all meta-variables used in term, including references.
	 *   The terms in this substitution are all part of a left-hand side we
	 *   have defined ourselves, and their sorts are also given in sorts.
	 * @param sorts Gives a sort denotation for all terms occurring in the
	 *   range of the substitution (including subterms) and the term itself,
	 *   and is used to save the sorts for the result.
	 * @param contextPos The current position in the given term, used for
	 *   naming bound variables.
	 * @param excludePS Set to true if a potential property set of the given
	 *   term should not be copied along.
	 * @return a generic term, which is the expected substituted term; all its
	 *   subterm sorts have been saved in the sorts parameter
	 * @throws CRSException an error is given if there are problems with the
	 *   substitution, which may cause an exception to be thrown
	 */
	private GenericTerm substitute(Term term, Map<Variable,Variable> varSub,
				Map<String,Pair<Variable[],GenericTerm>> metaSub,
				Map<Object,Term> sorts, String contextPos,
				boolean excludePS) throws CRSException
	{
		GenericTerm ret = null;
		switch (term.kind())
		{
			case VARIABLE_USE : {
				Variable x = term.variable();
				ret = factory.newVariableUse(varSub.get(x));
				break;
			}

			case CONSTRUCTION :
				if (Util.isLiteral(term))
				{
					ret = factory.newConstruction(factory.makeLiteral(term.constructor().object(), term.constructor().literalSort()), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
				}
				else
				{
					Variable[][] binders = new Variable[term.arity()][];
					GenericTerm[] subterms = new GenericTerm[term.arity()];
					for (int i = 0; i < term.arity(); i++)
					{
						binders[i] = new Variable[term.binders(i).length];
						for (int j = 0; j < term.binders(i).length; j++)
						{
							Variable b = term.binders(i)[j];
							binders[i][j] = env.makeVariable(b.name(), b.promiscuous(), b.blocking(), b.shallow());
							varSub.put(term.binders(i)[j], binders[i][j]);
							sorts.put(binders[i][j], sorts.get(term.binders(i)[j]));
						}
						subterms[i] = substitute(term.sub(i), varSub, metaSub, sorts, contextPos + Standardizer.subPosition(i, term.arity()), false);
						for (int j = 0; j < term.binders(i).length; j++)
							varSub.remove(term.binders(i)[j]);
					}
					ret = factory.newConstruction(factory.makeConstructor(term.constructor()), binders, subterms);
				}
				break;

			case META_APPLICATION : {
				String mvar = term.metaVariable();
				Pair<Variable[],GenericTerm> combination = metaSub.get(mvar);
				if (combination == null)
				{
					// Unsubstituted meta-variable (probably environment reference).
					ret = (GenericTerm) term;
				}
				else
				{
					Map<Variable,Term> substitution = new HashMap<Variable,Term>();
					for (int i = 0; i < term.arity(); i++)
						substitution.put(combination.head()[i], term.sub(i));
					ret = substituteVariables(combination.tail(), substitution, varSub, metaSub, sorts, contextPos, excludePS || Standardizer.hasPropertySet(term), new HashMap<Variable,Variable>());
				}
			}
		}

		Map<String,Term> properties = new HashMap<String,Term>();
		properties.put(STANDARDIZED, factory.nil());
		
		if (!excludePS && Standardizer.hasPropertySet(term))
		{
			PropertiesHolder A = Util.propertiesHolder(term);
			for (String key : A.propertyNames())
			{
				Term value = A.getProperty(key);
				String newKey = key;
				for (Variable v : varSub.keySet())
					if (key.equals(v.name()))
						newKey = varSub.get(v).name();
				properties.put(newKey, substitute(value, varSub, metaSub, sorts, contextPos + "o" + (key.charAt(0) == '#' ? "M" + key.substring(1) : key) + "c", false));
			}
		}
		
		ret = Util.makePropertiesConstraintsWrapper(ret, null, properties, null, null);
		sorts.put(ret, sorts.get(term));
		return ret;
	}

	/**
	 * This function does part of the work for substitute: given a term which
	 * follows the conventions for our own rules, and a substitution which
	 * assigns to variables a subterm of a user-given meta-term, determines
	 * term gamma', where gamma' maps a variable x to gamma(x) with substitute
	 * applied on it.
	 * @param term a term, which is a subterm of a left-hand side created by
	 *   us, and thus follows all the usual naming conventions; its sorts are
	 *   saved in subtermSorts
	 * @param gamma a substitution which maps variables to terms which are the
	 *   of a right-hand side which follows normal conventions (either part of
	 *   our own generated rules, or a copy of a user-given right-hand side);
	 *   all sorts have been saved in sorts;
	 *   all free variables in term are either in the domain of gamma, or in
	 *   the domain of boundReplace, or are truly free both here and in the
	 *   left-hand side this term comes from
	 * @param varSub, metaSub: see substitute, these parameters are only given
	 *   to pass on
	 * @param sorts gives a sort denotation for all terms occurring either in
	 *   term or in the range of the substitution (including subterms), and is
	 *   also used to save the sort denotations for the result
	 * @param currentPosition the current position in the term we are creating
	 *   (used for variable namings)
	 * @param excludeProperties if set to true, and this term has a property
	 *   set, the property set is not included in the result
	 * @param boundReplace variables which are bound are renamed to a new
	 *   variable (with standard naming scheme), and saved here
	 * @throws CRSException an error is given if there are problems with the
	 *   substitution, which may cause an exception to be thrown
	 */
	private GenericTerm substituteVariables(Term term, Map<Variable,Term> gamma,
											Map<Variable,Variable> varSub,
											Map<String,Pair<Variable[],GenericTerm>> metaSub,
											Map<Object,Term> sorts,
											String currentPosition,
											boolean excludeProperties,
											Map<Variable,Variable> boundReplace) throws CRSException
	{
		GenericTerm ret = null;

		if (term.kind() == Kind.VARIABLE_USE)
		{
			Variable x = term.variable();
			if (gamma.containsKey(x))
				return substitute(gamma.get(term.variable()), varSub, metaSub,
								  sorts, currentPosition, excludeProperties);
			if (boundReplace.containsKey(x))
				ret = factory.newVariableUse(boundReplace.get(x));
			else ret = factory.newVariableUse(x);
		}
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			GenericTerm[] subs = new GenericTerm[term.arity()];
			for (int i = 0; i < subs.length; i++)
			{
				Term relevantSub = term.sub(i);
				if (relevantSub.kind() == Kind.CONSTRUCTION) relevantSub = relevantSub.sub(0);
				subs[i] = substituteVariables(relevantSub, gamma, varSub, metaSub, sorts,
											  currentPosition + Standardizer.subPosition(i, term.arity()),
											  false, boundReplace);
			}
			ret = factory.newMetaApplication(term.metaVariable(), subs);
		}
		
		if (term.kind() == Kind.CONSTRUCTION)
		{
			Variable[][] binders = new Variable[term.arity()][];
			GenericTerm[] subterms = new GenericTerm[term.arity()];
			for (int i = 0; i < term.arity(); i++)
			{
				binders[i] = new Variable[term.binders(i).length];
				for (int j = 0; j < term.binders(i).length; j++)
				{
					Variable b = term.binders(i)[j];
					binders[i][j] = env.makeVariable("x" + currentPosition + "_" +  Standardizer.subVariablePosition(i, term.arity(), j, term.binders(i).length), b.promiscuous(), b.blocking(), b.shallow());
					boundReplace.put(b, binders[i][j]);
					sorts.put(binders[i][j], sorts.get(b));
				}
				subterms[i] = substituteVariables(term.sub(i), gamma, varSub, metaSub, sorts,
												  currentPosition + Standardizer.subPosition(i, term.arity()),
												  false, boundReplace);
			}
			ret = factory.newConstruction(factory.makeConstructor(term.constructor()), binders, subterms);
		}
		
		if (!excludeProperties && Standardizer.hasPropertySet(term))
		{
			Term reference = Util.propertiesHolder(term).getProperty(REFERENCE);
			GenericTerm[] args = new GenericTerm[reference.arity()];
			for (int i = 0; i < args.length; i++)
			{
				Variable x = env.makeVariable("r" + currentPosition + "_" + Standardizer.subPosition(i, args.length), true);
				args[i] = factory.newVariableUse(x);
				sorts.put(args[i], sorts.get(reference.sub(i)));
			}
			Map<String,Term> propertyNames = new HashMap<String,Term>();
			propertyNames.put(REFERENCE, reference);
			ret = Util.makePropertiesConstraintsWrapper(ret, null, propertyNames, null, null);
		}
		
		sorts.put(ret, sorts.get(term));
		return ret;
	}
	
	// ========== checks after the whole procedure ========== //
	
	/**
	 * Check whether there are any patterns which do not reduce to anything,
	 * and give warnings for all of them.
	 * 
	 * <p>Rule leading to a null contraction are removed.
	 */
	private void checkCompleteness()
	{
		for (Entry<String, List<StandardizedRule>> e : ruleQuadsByConstructor.entrySet())
		{
			for (Iterator<StandardizedRule> iterator = e.getValue().iterator(); iterator.hasNext();)
			{
				StandardizedRule rule = iterator.next();
				if (rule.two() == null)
				{
					if (!allowMissingCases)
						warning("Missing case for pattern " + unstandardize(rule.one()) + " near rule " + e.getKey() + ".");
					iterator.remove();
				}
			}
		}
	}

	/**
	 * Recovers all variables and meta-variables occurring in the given term.
	 * @param term A (recursively generic) term which follows our standard
	 *   conventions.
	 * @param metas Part of the return value; all meta-variables found in the
	 *   current term are added into metas.
	 * @param vars Part of the return value; all variables found in the current
	 *   term (free or not) are added into vars, with their name mapping to the
	 *   actual variable.
	 */
	private static void getVariablesAndMetas(Term term, Set<String> metas, Map<String,Variable> vars)
	{
		if (term == null) return;
		
		if (term.kind() == Kind.VARIABLE_USE)
			vars.put(term.variable().name(), term.variable());
		
		if (term.kind() == Kind.META_APPLICATION)
			metas.add(term.metaVariable());
		
		for (int i = 0; i < term.arity(); i++)
		{
			for (int j = 0; j < term.binders(i).length; j++)
				vars.put(term.binders(i)[j].name(), term.binders(i)[j]);
			getVariablesAndMetas(term.sub(i), metas, vars);
		}
		
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null)
		{
			for (String key : A.propertyNames())
				getVariablesAndMetas(A.getProperty(key), metas, vars);
			for (Variable key : A.propertyVariables())
			{
				vars.put(key.name(), key);
				getVariablesAndMetas(A.getProperty(key), metas, vars);
			}
			if (term instanceof PropertiesConstraintsWrapper)
			{
				PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) term;
				for (String mv : pcw.metaPropertyConstraints.keySet())
				{
					metas.add(mv);
					getVariablesAndMetas(pcw.getMetaProperty(mv), metas, vars);
				}
			}
		}
	}
	
	/**
	 * Checks whether variables and meta-variables used in keys actually occur,
	 * and in doing so recovers all variables used in the term.
	 * @param left A recursively generic term, following our own conventions;
	 *   the left-hand side of a rule.
	 * @param right A recursively generic term, following our own conventions;
	 *   the right-hand side of a rule.
	 * @param vars Part of the return value, is updated to contain all
	 *   name -> variable entries for all variables occurring in both terms
	 *   (including binders; for binders in the right, the x of the name is
	 *   replaced by a b).
	 * @param rulename used in error messages
	 * @throws CRSException If a variable or meta-variable occurs as a key
	 *   in left which does not occur elsewhere in left, or if a variable or
	 *   meta-variable occurs as a key in right which does not occur either
	 *   bound in right, or free in left or right, then an error is given,
	 *   which might cause an exception to be thrown.
	 */
	private void checkKeyPresence(Term left, Term right, Map<String,Variable> vars, Constructor rulename) throws CRSException
	{
		Set<String> metas = new HashSet<String>();
		Map<String,Variable> varsleft = new HashMap<String,Variable>();
		getVariablesAndMetas(left, metas, varsleft);
		Map<String,Variable> varsright = new HashMap<String,Variable>();
		getVariablesAndMetas(right, metas, varsleft);
		for (String var : varsleft.keySet())
			if (var.charAt(0) != 'x') varsright.put(var, varsleft.get(var));
		
		checkKeyPresence(left, metas, varsleft, rulename);
		checkKeyPresence(right, metas, varsright, rulename);
		
		if (vars != null)
		{
			for (Entry<String,Variable> e : varsleft.entrySet())
				vars.put(e.getKey(), e.getValue());
			for (Entry<String,Variable> e : varsright.entrySet())
			{
				if (e.getKey().charAt(0) == 'x')
					vars.put("b" + e.getKey().substring(1), e.getValue());
				else
					vars.put(e.getKey(), e.getValue());
			}
		}
	}
	
	/**
	 * Helping function for the other checkKeyPresence; assumes that metas
	 * contains all meta-variables occurring anywhere in the term (or a term
	 * this is a subterm of), and variables contains all variables.
	 */
	private void checkKeyPresence(Term term, Set<String> metas, Map<String,Variable> vars, Constructor rulename) throws CRSException
	{
		if (term == null) return;
		if (term.kind() == Kind.VARIABLE_USE)
		{
			String name = term.variable().name();
			vars.put(name, term.variable());
		}
		for (int i = 0; i < term.arity(); i++)
			checkKeyPresence(term.sub(i), metas, vars, rulename);
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A == null) return;
		for (String key : A.propertyNames())
		{
			if (key.equals(REFERENCE) || key.equals(STANDARDIZED)) continue;
			checkKeyPresence(A.getProperty(key), metas, vars, rulename);
		}
		for (String key : A.propertyNames())
		{
			if (key.equals(REFERENCE) || key.equals(STANDARDIZED)) continue;
			if (key.charAt(0) != '%' && !metas.contains(key) && !vars.containsKey(key))
				error("checking presence of keys in instantiation of rule " + rulename + ": "+
					  "some previous rule checked for (meta-)variable at position " +
					  key.substring(1) + ", which is instantiated here.");
		}
	}
	
	// ========== testing confluence ========== //
	
	/**
	 * Test whether critical pair is trivial --
	 * UNIMPLEMENTED (TODO for future expansion).
	 * Given an existing rule, and a data rule that overlaps with it, we want
	 * to know whether adding in the data rule really gives new information.
	 * This is to avoid endless adding of rules which don't really make a
	 * difference.
	 * <p>
	 * For example, suppose there is a function rule
	 * <pre>
	 * 	 Execute[+[a,b]] → Add[Execute[a],Execute[b]];
	 * </pre>
	 * But there is also a data rule:
	 * <pre>
	 * 	 +[+[a,b],c] → +[a,+[b,c]];
	 * </pre>
	 * Then it is normal to split the "a" in the Execute rule into cases, and
	 * alter the case
	 * <pre>
	 *   Execute[+[+[c,d],b]] → Execute[+[c,+[d,b]]];
	 * </pre>
	 * However, this creates a new case where the data rule applies, and we
	 * will also have to add rules:
	 * <pre>
	 *   Execute[+[+[+[e,f],d],b]] → Execute[+[+[e,+[f,d]],b]];
	 *   Execute[+[+[+[+[g,h],f],d],b]] → Execute[+[+[+[g,+[h,f]],d],b]];
	 *   ...
	 * </pre>
	 * This is pointless, however, as the new rules don't add new information.
	 * <p>
	 * This can be seen as follows: we already have a rule
	 * <pre>
	 *   Execute[+[+[c,d],b]] → Execute[+[c,+[d,b]]];
	 * </pre>
	 * The interesting case is when c = +[e,f]; we can either retain the old
	 * rule, or override it with a new rule:
	 * <pre>
	 * 	 Execute[+[+[+[e,f],d],b]] → Execute[+[+[e,f],+[d,b]]]; (old)
	 * 	 Execute[+[+[+[e,f],d],b]] → Execute[+[+[e,+[f,d]],b]]; (new)
	 * </pre>
	 * But suppose you did not add this extra rule; a term of the form
	 * Execute[+[+[+[e,f],d],b]] would reduce in two steps to
	 * Execute[+[e,+[f,+[d,b]]]], using only the existing rule.
	 * On the other hand, Execute[+[+[e,+[f,d]],b]], when we apply the same
	 * data rule on it twice, also reduces to Execute[+[e,+[f,+[d,b]]]].
	 * Thus, trying this data rule here does not give new information: the
	 * same normal form is reached, and it will not take much longer to do so.
	 * 
	 * <p>
	 * In conclusion, a critical pair <r1,r2> is considered sufficiently
	 * simple to ignore if we can find some term A such that
	 * <ul>
	 * <li> r1 reduces to A only with existing rules
	 * <li> r2 reduces to A with a combination of existing and data rules
	 * </ul>
	 * Noting that r1 and r2 are not very large, and hopefully the system
	 * is terminating, we could simply try reducing them a couple of times
	 * and seeing whether there's an overlap in the results.  False
	 * negatives for triviality are acceptable (if many reductions are
	 * needed to bring term1 and term2 together, chances are that it
	 * really is an optimisation to include the new rule).
	 * <p>
	 * Some things we should watch out for:
	 * <ul>
	 * <li> term1 and term2 are meta-terms, not terms; thus, it is likely
	 *     that standard functionality for rewriting will not work (not
	 *     even minding that the rules we work with are not necessarily
	 *     real rules, as they use compulsary variables and environments
	 *     with arguments).  Moreover, the "instantiates" function was
	 *     written with the assumption that p2 was part of a user-given
	 *     left-hand side (so does not use #Z[!x]) and does not contain
	 *     any $[NotMatch,...] subterms; this functionality would have to
	 *     be adapted before we could use it for rewriting.
	 * <li> a term #Z[x] OVERLAPS with #Y[], but does not INSTANTIATE it,
	 *     so should not be rewritten
	 * <li> term1 and term2 are right-hand sides; if one of them has a
	 *     subterm {#Γ} A this instantiates {#Γ ; k : v} B only if A
	 *     instantiates B, and in the left-hand side of the relevant
	 *     rule, #Γ comes equipped with a clause k : a, and v instantiates
	 *     a.  Thus, we will actually need to use the instantiated
	 *     left-hand side of these two rules as well.
	 * </ul>
	 * Since I (Cynthia) have little expertise in confluence, the above is
	 * a brainstorm, rather than a result based on sufficient experience /
	 * study of the use of data rules in the CRSX framework.  There might
	 * well be simpler or more correct ways.
	 * As such (and because time is short), I will leave this for future
	 * implementation.
	 * <p>
	 * Instead, the Completer will simply run the "respectDataRule" method
	 * only once for each data rule, which means that you cannot get a loop.
	 */
	boolean trivialCriticalPair(GenericTerm term1, GenericTerm term2,
								GenericTerm pattern)
	{
		// TODO!!
		return term1.equals(term2);
	}

	// ========== dispatchifying ========== //
	
	/**
	 * Main function for the dispatchify functionality: given a set of rules
	 * (which is supposed to be orthogonal and complete for the situation in
	 * which this set is used), all headed by the same symbol F, create some
	 * rules where only the first argument may be something other than a fully
	 * extended meta-variable.  In the result, Fi[...] should effectively
	 * reduce to all that F[...] previously reduced to (within the given set),
	 * but may use more than one step to do so. 
	 */
	private List<StandardizedRule> dispatchify(Set<StandardizedRule> relevantRules, final Map<Object,Term> sortsSave) throws CRSException
	{
		final List<StandardizedRule> ret = new ArrayList<StandardizedRule>();
		
		// If rule set is trivial 
		final Set<StandardizedRule> rs = new HashSet<StandardizedRule>();
		for (StandardizedRule r : relevantRules)
			if (r.two() != null)
				rs.add(r);
		if (rs.size() == 1)
			relevantRules = rs;
		
//		String rulename = rs.iterator().next().getName().symbol();
//		if (rulename.contains("R-R4-R4a-Form-for-at2-1"))
//			System.out.println("Have rule.");
//		
		// STEP 1: find a position where we can split, and decide what to split on
		final Pair<Integer,Object> splitPos = getSplitPosition(relevantRules);
		if (splitPos == null)
		{
			// We are done: nothing to split - there can be only one rule, and return the normal form of it
			StandardizedRule rule = relevantRules.iterator().next();
			Map<String, List<Term>> options = rule.four();
			if (options == null)
				options = new HashMap<String, List<Term>>();
			List<Term> compileTypes = new ArrayList<Term>();
			compileTypes.add(factory.literal("Contract"));
			options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes); 
			rule.setFour(options);
			ret.add(rule);
			return ret;
		}
		
		// STEP 2: we must split - shuffle the position that needs to be split to the front
		if (splitPos.head().intValue() >= 1)
			shuffle(relevantRules, sortsSave, ret, splitPos.head());
		// TODO: shuffling should be done on the generated calls.
		
		// STEP 3: deal with the various possibilities for splitting
		final Object split = splitPos.tail();
		if (split instanceof String)
			splitByKey(ret, relevantRules, (String) split, ((Integer) splitPos.head()).intValue() == -1 ? -1 : 0, sortsSave);
		else if (split instanceof Integer && ((Integer) split).intValue() == 0)
			splitByConstructor(ret, relevantRules, sortsSave);
		else if (split instanceof Integer && ((Integer) split).intValue() == 1)
			splitByPropertySet(ret, relevantRules, sortsSave);
		else 
			splitByBinderPresence(ret, relevantRules, ((int[]) splitPos.tail())[0], ((int[]) splitPos.tail())[1], sortsSave);

		return ret;
	}

	/**
	 * Creates a rule swapping constructor at position <code>pos</code> to position 0. Update the given set of <code>rules</code>.
	 * 
	 * <p>For a list of rules 
	 * <pre>
	 *    {#E}F[..., A1, ...] -> C1
	 *    F[..., An, ...] -> C2 creates:
	 * <ol>
	 * <li>F$1[#0...#p...#n] -> F$2[#p, #0...#n]
	 * <li>F is renamed to F$2 in given rules.
	 * </ol>
	 * 
	 * @param rules
	 * @param sortsSave
	 * @param ret
	 * @param splitPos
	 * @throws CRSException
	 */
    protected void shuffle(Set<StandardizedRule> rules, Map<Object, Term> sortsSave, List<StandardizedRule> ret, int pos)
            throws CRSException
    {
	    StandardizedRule currentRule = rules.iterator().next();
	    GenericTerm example = currentRule.getPattern();
	    Constructor newsymbol = env.internalSymbol(example.constructor());
	    
	    // make a rule that swaps position 0 and pos
	    Constructor symbol = example.constructor();
	    GenericTerm newPattern = createFromExample(example, symbol.symbol(), false, 0, false, true, null);
	    GenericTerm newContractum = createFromExample(example, newsymbol.symbol(), false, 0, false, true, null);
	    Variable[] binds0 = newContractum.binders(0);
	    GenericTerm arg0 = newContractum.sub(0);
	    newContractum.replaceSub(0, newContractum.binders(pos), newContractum.sub(pos));
	    newContractum.replaceSub(pos, binds0, arg0);
	    
	    Term exampleSort = sortGet(sortsSave, example);
	    if (exampleSort != null)
	    	sortPut(sortsSave, newContractum, exampleSort);
	    
	    List<Term> compileTypes = new ArrayList<Term>();
	    compileTypes.add(factory.parse("Shuffle"));
	    Map<String, List<Term>> options = new HashMap<String, List<Term>>();
	    options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);
	    
	    // Account for the free variables occurring in properties
	    if (currentRule.getOptions() != null)
	    {
	    	List<Term> freeOption = currentRule.four().get(Builder.FREE_OPTION_SYMBOL);
	    	if (freeOption != null)
	    		options.put(Builder.FREE_OPTION_SYMBOL, new ArrayList<Term>(freeOption));
	    }
		ret.add(new StandardizedRule(factory, newPattern, newContractum, currentRule.getName(), options));

	    // Declare new symbol with positions 0 and pos swapped
	    GenericTerm newForm = getForm(example, newsymbol.symbol(), sortsSave, true);
	    binds0 = newForm.binders(0);
	    arg0 = newForm.sub(0);
	    newForm.replaceSub(0, newForm.binders(pos), newForm.sub(pos));
	    newForm.replaceSub(pos, binds0, arg0);
	    factory.setSortForm(exampleSort, null, newForm, true, true);
	    sortPut(sortsSave, newForm, exampleSort);
	    
	    // morph the rules we are working with to use shuffled forms.
	    for (StandardizedRule rule : rules)
	    {
	    	GenericTerm pattern = rule.one();
	    	final int a = pattern.arity();
	    	Constructor newconstructor = factory.makeConstructor(newsymbol);
	    	Variable[][] newbinders =  new Variable[a][];
	    	GenericTerm[] newsubterms = new GenericTerm[a];
	    	for (int i =0; i < a; ++i)
	    	{
	    		newbinders[i] = pattern.binders(i);
	    		newsubterms[i] = pattern.sub(i);
	    	}
	    	PropertiesHolder ph = Util.propertiesHolder(pattern);
	    	binds0 = newbinders[0];
	    	arg0 = newsubterms[0];
	    	newbinders[0] = newbinders[pos];
	    	newsubterms[0] = newsubterms[pos];
	    	newbinders[pos] = binds0;
	    	newsubterms[pos] = arg0;
    		GenericTerm newpattern = factory.newConstruction(newconstructor, newbinders, newsubterms);
	    	{
	    		PropertiesConstraintsWrapper pcw = Util.makePropertiesConstraintsWrapper(newpattern, null, null, null, null);
	    		pcw.setProperties(ph);
	    		newpattern = pcw;
	    	}
	    	sortPut(sortsSave, newpattern, exampleSort);
	    	rule.setOne(newpattern);
	    }
    }

	/**
	 * Creates normal standardized rule
	 * @param rule
	 * @return
	 * @throws CRSException
	 */
    protected StandardizedRule createNormalRule(StandardizedRule rule) throws CRSException
    {
//	    if (Util.symbol(rule.getPattern()).contains("CRSX2Text"))
//	    	warning("karma");
//	    
	    Map<String,String> metaRename = new HashMap<String,String>();
	    Map<String,Variable> varChange = new HashMap<String,Variable>();
	    lookupFreeVariablesAndMetas(rule.getPattern(), varChange, metaRename);
	    lookupFreeVariablesAndMetas(rule.getContractum(), varChange, metaRename);
	    
	    GenericTerm pattern = createNormalTerm(rule.getPattern(), varChange, metaRename, "", null, null);
	    Map<String,Integer> metaCounts = new HashMap<String, Integer>();
	    GenericTerm contractum = createNormalTerm(rule.getContractum(), varChange, metaRename, "", null, metaCounts);
	     
		// Rename meta variable occuring in the options
		Map<String, List<Term>> options = new HashMap<String, List<Term>>();
		if (rule.four() != null)
		{
			for (Map.Entry<String, List<Term>> e : rule.four().entrySet())
			{
				List<Term> os = new ArrayList<Term>();
				for (Term oldo : e.getValue())
				{
					GenericTerm o = createNormalTerm(oldo, varChange, metaRename, "", null, null);
					if (o.kind() != Kind.META_APPLICATION || o.metaVariable() != null)
						os.add(o);
				}
				options.put(e.getKey(), os);
			}
		}
		// Analyze rule.
		Map<String, Variable> patternVars = new HashMap<String, Variable>();
		Set<String> patternMetas = new HashSet<String>();
		getVariablesAndMetas(pattern, patternMetas, patternVars);

		Map<String, Variable> usedVars = new HashMap<String, Variable>();
		Set<String> usedMetas = new HashSet<String>();
		getVariablesAndMetas(contractum, usedMetas, usedVars);

		// Recalculate Discards.
		Set<String> discardedMetas = new HashSet<String>();
		discardedMetas.addAll(patternMetas);
		discardedMetas.removeAll(usedMetas);
		List<Term> discards = new ArrayList<Term>();
		for (String mv : discardedMetas)
			discards.add(factory.newMetaApplication(mv, GenericTerm.NO_TERMS));
		if (discards.isEmpty())
			options.remove(Builder.DISCARD_OPTION_SYMBOL);
		else
			options.put(Builder.DISCARD_OPTION_SYMBOL, discards);

		// Recalculate Copy options.
		Set<String> shares = new HashSet<String>();
		if (options.containsKey(Builder.SHARE_OPTION_SYMBOL))
			for (Term o : options.get(Builder.SHARE_OPTION_SYMBOL))
				shares.add(o.metaVariable());
		
		List<Term> copies = new ArrayList<Term>();
		for (String m : metaCounts.keySet())
			if (!shares.contains(m))
				if (metaCounts.get(m) > 1)
					copies.add(factory.newMetaApplication(m, GenericTerm.NO_TERMS));
		if (!copies.isEmpty())
			options.put(Builder.COPY_OPTION_SYMBOL, copies);
		
	    List<Term> compileTypes = new ArrayList<Term>();
	    compileTypes.add(factory.parse("Contract"));
	    options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);
	    
	    return new StandardizedRule(factory, pattern, contractum, env.internalSymbol(rule.getName()), options); 
    }
	
	/**
	 * Given a set of rules to dispatchify, finds a position where the dispatchifier can
	 * best do its work.  In the result pair, the first element is the position where to
	 * split (-1 for a split in the property set at root level, otherwise the index of an
	 * immediate subterm), and the second element is one of:
	 * <ul>
	 * <li> 0 (Integer) indicates a constructor split (possibly including variables)
	 * <li> 1 (Integer) indicates a term with property set / variable split
	 * <li> a String indicates a split on absence / presence of a key (the string is the
	 *   	name of that key)
	 * <li> an array of integers indicates a split on presence of bound variables; the
	 *	   first number indicates what to split on (0 for presence in the whole term,
	 *	   1 for presence in the term excluding the property set, 2 for presence in
	 *	   the property set), the other numbers indicate the indexes of binders to
	 *     split on.
	 * </ul>
	 * A null value indicates that no split is possible.
	 * 
	 * @throws CRSException
	 */
	private Pair<Integer,Object> getSplitPosition(Set<StandardizedRule> relevantRules) throws CRSException
	{
		// TODO: when splitting on presence of bound variable, should return only 1 position.
		// TODO: also why the binder position is not always 0?
		
		boolean allMetas = true;
		
		if (factory.verbosity() >= 6)
			factory.message("-----------\nSplitting "+relevantRules);
		
		Pair<Integer,Object> best = null;
		for (int i = -1; true; i++)
		{
			boolean constructorsOrVariables = true;
				// will stay true if all terms at this position are either constructors
				// or variables (so are not meta-variables)
			boolean propertiesOrVariables = true;
				// will stay true if all terms at this position are either variables,
				// or have a property set
			Map<Integer,Boolean> specialVariables = new HashMap<Integer,Boolean>();
				// will be altered to contain the indices of those bound variables which
				// either don't occur or occur explicitly in all patterns at position i;
				// the value is set to true if there is a location where this variable
				// is absent
			Map<Integer,Boolean> specialVariablesNonPS = new HashMap<Integer,Boolean>();
			Map<Integer,Boolean> specialVariablesInPS = new HashMap<Integer,Boolean>();
				// these sets are altered to contain the indices of those bound variables
				// which are special in the term excluding the property set, or just in
				// the property set, respectively
			Set<String> keys = new HashSet<String>();
				// will be altered to contain the names of those keys which are named
				// (either as present or as absent) in all property set keys
			boolean encounteredVariable = false;
				// will be set to true if anything in this position is just a variable
			boolean encounteredNonMeta = false;
				// will be set to true if anything on this position is something other than x1...xn.#Z[x1,...,xn]
			boolean encounteredNonMetaWithRef = false;
				// will be set to true if anything on this position is something other than x1...xn.{#Γ[x1,...,xn]} #Z[x1,...,xn]
			
			boolean toofar = false;
			int firstround = 0;
			for (StandardizedRule rule : relevantRules)
			{
				firstround++;
				GenericTerm pattern = rule.one();
				if (i >= pattern.arity()) { toofar = true; break; }
				
				Term relevant = (i == -1 ? pattern : pattern.sub(i));

				// basic simplicity checks on the property sets
				boolean hasPropertySet = Standardizer.hasPropertySet(relevant);
				if (hasPropertySet)
				{
					encounteredNonMeta = true;
					Iterator<String> it = Util.propertiesHolder(relevant).propertyNames().iterator();
					while (it.hasNext())
					{
						String p = it.next();
						if (!p.equals(STANDARDIZED) && !p.equals(REFERENCE))
							encounteredNonMetaWithRef = true; // there is a key other than the reference
					}
				}
				else encounteredNonMetaWithRef = true;
				
				// check for common property set keys
				if (firstround == 1 || !keys.isEmpty())
				{
					if (!Standardizer.hasPropertySet(relevant)) keys.clear();
					else
					{
						PropertiesHolder A = Util.propertiesHolder(relevant);
						if (firstround == 1)
						{
							for (String name : A.propertyNames())
								if (name.charAt(0) != '$' && (name.charAt(0) == '#'  || name.charAt(0) == '%'
									|| name.charAt(0) == 'x'|| name.charAt(0) == 'z'))
									keys.add(name);
						}
						else
						{
							Set<String> props = new HashSet<String>();
							for (String name : A.propertyNames())
								if (keys.contains(name)) props.add(name);
							keys.addAll(props);
						}
					}
				}

				if (i == -1) continue;

				// check for compulsary / absent bound variables
				if (firstround == 1 || !specialVariables.isEmpty() || !specialVariablesNonPS.isEmpty() || !specialVariablesInPS.isEmpty())
				{
					Set<String> certain1 = new HashSet<String>();
					Set<String> possible1 = new HashSet<String>();
					getBoundOccurrences(relevant, certain1, possible1, true);
					Set<String> certain2 = null;
					Set<String> possible2 = null;
					if (hasPropertySet)
					{
						certain2 = new HashSet<String>();
						possible2 = new HashSet<String>();
						Term reference = Util.propertiesHolder(relevant).getProperty(REFERENCE);
						getBoundOccurrences(reference, certain2, possible2, false);
					}
						
					if (firstround == 1) for (int j = 0; j < pattern.binders(i).length; j++)
					{
						String xname = pattern.binders(i)[j].name();
						Integer num = new Integer(j);
						if (certain1.contains(xname)) { specialVariables.put(num, Boolean.FALSE); specialVariablesNonPS.put(num, Boolean.FALSE); }
						if (certain2 != null && certain2.contains(xname)) { specialVariables.put(num, Boolean.FALSE); specialVariablesInPS.put(num, Boolean.FALSE); }
						if (!possible1.contains(xname))
						{
							specialVariablesNonPS.put(num, Boolean.TRUE);
							if (possible2 == null || !possible2.contains(xname)) specialVariables.put(num, Boolean.TRUE);
						}
						if (possible2 != null && !possible2.contains(xname)) specialVariablesInPS.put(num, Boolean.TRUE);
					}
					else
					{
						Set<Integer> removeVariables = new HashSet<Integer>();
						for (Integer j : specialVariables.keySet())
						{
							String xname = pattern.binders(i)[j.intValue()].name();
							if (!possible1.contains(xname) && (possible2 == null || !possible2.contains(xname)))
								specialVariables.put(j, Boolean.TRUE);
							else if (!certain1.contains(xname) && (certain2 == null || !certain2.contains(xname)))
								removeVariables.add(j);
						}
						for (Integer j : removeVariables) specialVariables.remove(j);
						if (hasPropertySet)
						{
							removeVariables.clear();
							for (Integer j : specialVariablesNonPS.keySet())
							{
								String xname = pattern.binders(i)[j.intValue()].name();
								if (!possible1.contains(xname)) specialVariablesNonPS.put(j, Boolean.TRUE);
								else if (!certain1.contains(xname)) removeVariables.add(j);
							}
							for (Integer j : removeVariables) specialVariablesNonPS.remove(j);
							removeVariables.clear();
							for (Integer j : specialVariablesInPS.keySet())
							{
								String xname = pattern.binders(i)[j.intValue()].name();
								if (!possible2.contains(xname)) specialVariablesInPS.put(j, Boolean.TRUE);
								else if (!certain2.contains(xname)) removeVariables.add(j);
							}
							for (Integer j : removeVariables) specialVariablesNonPS.remove(j);
						}
						else { specialVariablesInPS.clear(); specialVariablesNonPS.clear(); }
					}
				}
				
				if (relevant.kind() == Kind.META_APPLICATION)
				{
					constructorsOrVariables = false;
					if (relevant.arity() != pattern.binders(i).length)
						encounteredNonMeta = encounteredNonMetaWithRef = true;
					/*
					// a term with compulsary variables may be counted as just a meta-variable
					// if there are no counteracting terms with missing variables
					if (!encounteredNonMeta || !encounteredNonMetaWithRef)
						for (int j = 0; j < relevant.arity(); j++)
							if (relevant.sub(j).kind() != Kind.VARIABLE_USE)
								encounteredNonMeta = encounteredNonMetaWithRef = true;
					*/
				}
				if (relevant.kind() == Kind.VARIABLE_USE) encounteredVariable = true;
				else if (!Standardizer.hasPropertySet(relevant)) propertiesOrVariables = false;
			}
			
			if (toofar) break;
			
			if (i >= 0 && encounteredNonMeta && encounteredNonMetaWithRef)
				allMetas = false;
			
			if (constructorsOrVariables && i > -1)
			{
				if (best == null || !(best.tail() instanceof Integer) || ((Integer) best.tail()).intValue() > 0)
					best = new Pair<Integer,Object>(new Integer(i), new Integer(0));
			}
			else if (propertiesOrVariables && encounteredVariable && i > -1)
			{
				if (best == null || !(best.tail() instanceof Integer) || ((Integer) best.tail()).intValue() > 1)
					best = new Pair<Integer,Object>(new Integer(i), new Integer(1));
			}
			else if (!keys.isEmpty() && (best == null || best.tail() instanceof int[]))
			{
				best = new Pair<Integer,Object>(new Integer(i), keys.iterator().next());
			}
			else if ((!specialVariables.isEmpty() || !specialVariablesNonPS.isEmpty() || !specialVariablesInPS.isEmpty()) && best == null)
			{
				for (int style = 0; style < 3; style++)
				{
					Map<Integer,Boolean> map = specialVariables;
					if (style == 1) map = specialVariablesNonPS;
					if (style == 2) map = specialVariablesInPS;
					
					if (!map.isEmpty() && best == null)
					{
						int totalAbsent = 0;
						for (Integer j : map.keySet())
							if (map.get(j).booleanValue()) totalAbsent++;
						if (totalAbsent > 0)
						{
							int[] specials = new int[totalAbsent+1];
							specials[0] = style;
							int k = 1;
							for (Integer a : map.keySet())
								if (map.get(a).booleanValue()) specials[k++] = a.intValue();
							best = new Pair<Integer,Object>(new Integer(i), specials);
						}
					}
				}
			}
		}
		
		if (best == null)
			if (!allMetas)
			{
				// Only legitimate reason is if *all* the relevantRules are dummies created to catch some missing case.
				String problematic = "";
				for (StandardizedRule r : relevantRules)
				{
					if (r.two() != null)
						problematic += " " + r.three();
				}
				if (!problematic.isEmpty())
					fatal("dispatchifying rules failed because no position could be chosen (rules"+problematic+").  This should not happen.");
			}
		
		return best;
	}
	
	/**
	 * This function goes through the given term (which is assumed to follow
	 * standard naming conventions, at least in so far that bound variables
	 * have a name starting with x and all free variables have different
	 * names) and creates a new variable for all free variables, given by
	 * name.  In addition, all meta-variables are given a new name.
	 */
	private void lookupFreeVariablesAndMetas(Term term, Map<String,Variable> varRenaming, Map<String,String> metaRenaming)
	{
		if (term == null) return;
		
		if (term.kind() == Kind.VARIABLE_USE)
		{
			String name = term.variable().name();
			if (!varRenaming.containsKey(name) && name.charAt(0) != 'x')
				varRenaming.put(name, env.makeVariable("y" + varRenaming.size(), term.variable().promiscuous(), term.variable().blocking(), term.variable().shallow()));
			return;
		}
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			String name = term.metaVariable();
			if (!metaRenaming.containsKey(name))
				metaRenaming.put(name, "#" + metaRenaming.size());
		}
		
		for (int i = 0; i < term.arity(); i++)
			lookupFreeVariablesAndMetas(term.sub(i), varRenaming, metaRenaming);
		
		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null)
			for (String name : A.propertyNames())
			{
				if (!name.startsWith("%") && !name.startsWith("#") && !varRenaming.containsKey(name))
					varRenaming.put(name, env.makeVariable("y" + varRenaming.size(), name.contains("¹"), name.contains("ᵇ"), name.contains("ˢ")));
				lookupFreeVariablesAndMetas(A.getProperty(name), varRenaming, metaRenaming);
			}
	}

	/**
	 * Given a (meta-)term which follows our own conventions, such as only using
	 * strings in property set keys, this function transforms it back to a normal
	 * (meta-)term.  All $Present tags are removed as well.  However, variable
	 * parameters to references remain.
	 * @param term The term to change.
	 * @param varChange Gives a different variable for all variables which occur
	 * 	 freely in the term.
	 * @param metaRename Gives a different name for all meta-variables in the term.
	 * @param numberBounds Indicates how many bound variables occur above this
	 *   term in some larger term we are interested in (to ensure different
	 *   variable names where clashes might be possible).
	 * @param constructorRename If this term is a construction, the copy will
	 *   instead use constructorRename as the new constructor; to use the
	 *   constructor that is there, just set this argument to null.
	 * @param repeatedMetas meta-variables that occur more than once
	 */
	GenericTerm createNormalTerm(Term term, Map<String,Variable> varChange, Map<String,String> metaRename,
								 String numberBounds, String constructorRename, Map<String, Integer> repeatedMetas) throws CRSException
	{
		if (term == null) return null;
		GenericTerm ret = null;
		switch (term.kind())
		{
			case VARIABLE_USE :
				ret = factory.newVariableUse(varChange.containsKey(term.variable().name()) ? varChange.get(term.variable().name()) : term.variable());
				break;

			case META_APPLICATION : {
				String mv = term.metaVariable();
				if (repeatedMetas != null)
				{
					Integer oldCount = repeatedMetas.containsKey(mv) ? repeatedMetas.get(mv) : 0;
					repeatedMetas.put(mv, oldCount + 1);
				}
				GenericTerm[] args = new GenericTerm[term.arity()];
				for (int i = 0; i < args.length; i++)
					args[i] = createNormalTerm(term.sub(i), varChange, metaRename, numberBounds+"-"+i, null, repeatedMetas);
				ret = factory.newMetaApplication(metaRename.get(mv), args);
				break;
			}
			
			case CONSTRUCTION :
				if (Util.symbol(term).equals(PRESENT))
				{
					ret = createNormalTerm(term.sub(0), varChange, metaRename, numberBounds, null, repeatedMetas);
				}
				else
				{
					GenericTerm[] subs = new GenericTerm[term.arity()];
					Variable[][] binds = new Variable[term.arity()][];
					for (int i = 0; i < subs.length; i++)
					{
						binds[i] = new Variable[term.binders(i).length]; // old variables
						for (int j = 0; j < binds[i].length; j++)
						{
							Variable b = term.binders(i)[j];
							if (varChange.containsKey(b.name()))
								binds[i][j] = varChange.get(b.name());
							else
							{
								binds[i][j] = env.makeVariable("x" + numberBounds + "_" + j, b.promiscuous(), b.blocking(), b.shallow());
								varChange.put(b.name(), binds[i][j]);
							}
						}
						subs[i] = createNormalTerm(term.sub(i), varChange, metaRename, numberBounds+"-"+i, null, repeatedMetas);
					}
					Constructor c = constructorRename == null ? term.constructor() : factory.makeConstructor(constructorRename);
					ret = factory.newConstruction(c, binds, subs);
				}
				break;
		}
		
		// Property set.
		Map<String,Term> propertyNames = new HashMap<String,Term>();
		Map<Variable,Term> propertyVars = new HashMap<Variable,Term>();
		Map<String, Term> propertyMetas = new HashMap<String, Term>();
		PropertiesHolder A = Util.propertiesHolder(term);
		propertyNames.put(STANDARDIZED, factory.nil());
		if (A != null)
			for (String name : A.propertyNames())
			{
				Term value = createNormalTerm(A.getProperty(name), varChange, metaRename, numberBounds, null, repeatedMetas);
				if (name.equals(REFERENCE)) propertyNames.put(REFERENCE, value);
				else if (name.equals(STANDARDIZED)) propertyNames.put(STANDARDIZED, value);
				else if (name.charAt(0) == '%') propertyNames.put(name.substring(1), value);
				else if (name.charAt(0) == '#') propertyMetas.put(metaRename.get(name), value);
				else if (!varChange.containsKey(name)) fatal("cannot deal with key " + name + " in " + term + ": unknown.");
				else propertyVars.put(varChange.get(name), value);
			}
		ret = Util.makePropertiesConstraintsWrapper(ret, null, propertyNames, propertyVars, propertyMetas);

		return ret;
	}
	
	/**
	 * Create a pattern based on an example.
	 * 
	 * Returns a new term of the form {#&Gamma;} F[s<sub>1</sub>,...,s<sub>S</sub>] where all s<sub>n</sub> (1 &le; i &le; S) have the form
	 * 
	 * <p align=center>  x<sub>n1</sub>..x<sub>nX<sub>n</sub></sub> <b>.</b> #n[x<sub>n1</sub>,...,x<sub>nX<sub>n</sub></sub>] </p>
	 * 
	 * with the same binders as example (as can be seen we follow the convention that a sequence of bs has length B).
	 *
	 * If the flattenFirst flag is true then the first argument of example should have the shape
	 * 
	 * <p align=center>  a<sub>1</sub>..a<sub>A</sub> <b>.</b> G[ b<sub>11</sub>..b<sub>iB<sub>1</sub></sub> <b>.</b> t<sub>1</sub>, ... , b<sub>N1</sub>..b<sub>TB<sub>T</sub></sub> <b>.</b> t<sub>T</sub> ] </p>
	 *
	 * which then leads to a sequence or arguments (where 1 &le; n &le; T)
	 * 
	 * <p align=center>  a<sub>1</sub>..a<sub>A</sub> b<sub>1n</sub>..b<sub>iB<sub>n</sub></sub> <b>.</b> #n<sub>n</sub>[a<sub>1</sub>,...,a<sub>A</sub>, b<sub>1n</sub>,...,b<sub>iB<sub>n</sub></sub>] </p>
	 * 
	 * The  {#&Gamma;} component is included if one of the following is true:
	 * <ul>
	 * <li>the example term has any properties,
	 * <li>F is a function with a function form sort set, or
	 * <li>the sort of F has a (data) sort set.
	 * </ul>
	 * 
	 * @param example term with arguments to create meta-application patterns for
	 * @param F the constructor (F) to actually use for the example
	 * @param flattenFirst whether the first argument of example should be flattened by behaving as if the arguments of the first construction were direct arguments of the example
	 * @param metaIndexStart indicates where counting should start for the meta-variable names (so use #(n+start)  instead of #n in the generated arguments)
	 * @param extra indicates whether an extra position should be created at the end (this position is expected to be filled in later, so holds only a single meta-variable)
	 * @param dropProperties whether to drop specific properties from the generated term
	 * @param metaRenamings renamings of meta-variables already committed to
	 * @throws CRSException if there is a serious inconsistency
	 */
	private GenericTerm createFromExample(Term example, String F, boolean flattenFirst, int metaIndexStart, boolean extra, boolean dropProperties, Map<String, String> metaRenamings) throws CRSException
	{
		assert example.kind() == Kind.CONSTRUCTION && example.constructor().literalSort() == null;
		
		if (metaRenamings == null)
			metaRenamings = new HashMap<String, String>();
		
		int firstSubArgs = 1; 
		int numberArgs = example.arity();
		if (flattenFirst)
		{
			firstSubArgs = example.sub(0).arity();
			numberArgs = example.arity() + firstSubArgs - 1;
		}
		if (extra) numberArgs++;
		
		Variable[][] binders = new Variable[numberArgs][];
		GenericTerm[] subterms = new GenericTerm[numberArgs];
		
		for (int i = 0; i < numberArgs; i++)
		{
			// determine which group of binders is considered
			int Nbinds;
			//boolean[] promisc = null;
			if (flattenFirst)
			{
				if (i < firstSubArgs)
				{
					Nbinds = example.binders(0).length + example.sub(0).binders(i).length;
				}
				else if (i-firstSubArgs+1 < example.arity())
				{
					Nbinds = example.binders(i-firstSubArgs+1).length;
				}
				else Nbinds = 0;	// might occur when extra is true
			}
			else if (i == numberArgs-1 && extra) Nbinds = 0;
			else
			{
				Nbinds = example.binders(i).length;
			}

			// create the relevant x1...xn.#k[x1,...,xn]
			binders[i] = new Variable[Nbinds];
			GenericTerm[] args = new GenericTerm[Nbinds];
			for (int j = 0; j < Nbinds; j++)
			{
				binders[i][j] = env.makeVariable("x" + j, true); // TODO: binders! 
				args[j] = factory.newVariableUse(binders[i][j]);
			}
			subterms[i] = standardPatternMetaApplication("#" + (metaIndexStart + i), args);
			if (i < example.arity() && example.sub(i).kind() == Kind.META_APPLICATION)
				metaRenamings.put(example.sub(i).metaVariable(), subterms[i].metaVariable());
		}
		Constructor c = factory.makeConstructor(F);
		GenericTerm ret = factory.newConstruction(c, binders, subterms);
		
		boolean includePropertyReference = Util.hasNoStandardProperties(example);
//		if (!includePropertyReference)
//		{
//			factory.formsOf(F);
//			includePropertyReference = true;
//		}
		if (!includePropertyReference)
		{
			Term sort = factory.sortOf(F);
			if (sort != null && factory.sortsetFor(Util.symbol(sort)) != null)
				includePropertyReference = true;
		}
		Map<String,Term> props = new HashMap<String, Term>();
		props.put(STANDARDIZED, factory.nil());
		if (includePropertyReference)
			props.put(REFERENCE, standardPatternMetaApplication("#Γ", new GenericTerm[0]));
		if (!dropProperties)
			for (String p : Util.propertiesHolder(example).propertyNames())
				if (!p.startsWith("$$"))
					props.put(Util.getOrKeep(metaRenamings, p), Util.getProperty(example, p));
		ret = Util.makePropertiesConstraintsWrapper(ret, null, props, null, null);
		return ret;
	}

	/**
	 * Given a term whose sorts are saved in sortsSave, returns a copy of the form it is declared with,
	 * except substitute the constructor with newSymbol.
	 * Note: works for both standardized and unstandardized terms: always return unstandardized form.
	 * @param example we would like the form of this term
	 * @param newSymbol we will substitute the root symbol of the returned form with this one (null means reuse the original form's symbol)
	 * @param sortsSave the saved term sorts
	 * @param useCurrentForm whether the form can be retrieved from the {@link Sorting} stored with {@link #factory}
	 * @throws CRSException if there is a catastrophic error
	 */
	synchronized GenericTerm getForm(Term example, String newSymbol, Map<Object,Term> sortsSave, boolean useCurrentForm) throws CRSException
	{
		String exampleSymbol = Util.symbol(example);
		Term exampleForm = null;
		
//		if (exampleSymbol.contains("FT-item-intersect2-record1"))
//				warning("karma");
		
		Set<Pair<Term,Term>> forms = factory.formsOf(exampleSymbol);
		if (forms == null || forms.size() == 0)
			warning("could not find form for "+example);
		else if (forms.size() > 1 && useCurrentForm)
			warning("several forms for "+example+": "+forms);
		else
		{
			Term form = forms.iterator().next().tail();
        	if (form.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(form)))
        		form = form.sub(0);
			if (form == null || form.arity() != example.arity())
			{
				if (useCurrentForm)
					warning("inconsistency:\n Example: "+example+"\n Form:  "+form);
			}
			else
			{
				exampleForm = form;
				if (useCurrentForm)
				{
					final int a = form.arity();
					for (int i = 0; i < a; ++i)
					{
						//GenericTerm sub = createCopy(exampleForm.sub(i), sortsSave); //.copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
						GenericTerm sub = (GenericTerm) exampleForm.sub(i).copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
						sub = sub.stripProperties();
						sortPut(sortsSave, example.sub(i), sub);
					}
				}
			}
		}

		GenericTerm[] subs = new GenericTerm[example.arity()];
		Variable[][] binds = new Variable[example.arity()][];
		for (int i = 0; i < subs.length; i++)
		{
			subs[i] = (GenericTerm) sortGet(sortsSave, example.sub(i));
			if (subs[i] == null && exampleForm != null && useCurrentForm)
				sortPut(sortsSave, example.sub(i), subs[i] = (GenericTerm) exampleForm.sub(i));
			if (subs[i] == null)
				factory.warning("Sort information may be incomplete (will try to recover) for subterm "+i+" of "+example);
			else
			{
				binds[i] = new Variable[example.binders(i).length];
				if (binds[i].length > 0)
				{
					subs[i] = Util.makePropertiesConstraintsWrapper(subs[i].stripProperties(), null, null, null, null);
					for (int j = 0; j < binds[i].length; j++)
					{
						if (exampleForm == null || exampleForm.binders(i) == null || exampleForm.binders(i).length < j)
							factory.error("PANIC...inconsistent example?");
						binds[i][j] = env.makeVariable("x" + j, exampleForm.binders(i)[j].promiscuous(), exampleForm.binders(i)[j].blocking(), exampleForm.binders(i)[j].shallow());
						Term binderSort = sortGet(sortsSave, example.binders(i)[j]);
						if (binderSort == null)
						{
							// Defensively get sort from example itself [sic].
							binderSort = Util.propertiesHolder(example.sub(i)).getProperty(example.binders(i)[j]);
						}
						((PropertiesConstraintsWrapper) subs[i]).setProperty(binds[i][j], binderSort);
					}
				}
			}
		}
		Constructor constructor = factory.makeConstructor(newSymbol == null ? exampleSymbol : newSymbol);
		if (Util.hasProperties(exampleForm))
		{
			constructor = Util.wrapWithProperties(factory, constructor, Util.propertiesHolder(exampleForm));
			if (constructor.getProperty(STANDARDIZED) != null)
			{
				// Defensive cleanup of standardized artifacts...
				constructor.setProperty(STANDARDIZED, null);
				constructor.setProperty(REFERENCE, null);
			}
		}
		GenericTerm form = factory.newConstruction(constructor, binds, subs);
		return form;
	}

	/**
	 * Given a set of rules, where the first position in the pattern is always
	 * a constructor or a variable, create rules for cases F[A[..., F[B[...],
	 * and so on.
	 * @param ret All new rules will be added to ret.
	 * @param relevantRules Contains the rules we should work with.
	 * @param numberSymbols Gives the index where we should start counting rules,
	 * 	 and is modified to reflect rules which were added
	 * @throws CRSException possible result of giving an error
	 */
	private void splitByConstructor(final List<StandardizedRule> ret,
									final Set<StandardizedRule> relevantRules,
									final Map<Object,Term> sortsSave) throws CRSException
	{
		if (factory.verbosity() > 2)
			factory.message("- splitting "+Util.symbol(relevantRules.iterator().next().getPattern())+" rules by FIRST CONSTRUCTOR");

		final List<StandardizedRule> additionalRules = new LinkedList<StandardizedRule>();
		final List<Object> splits = new LinkedList<Object>();
			// will contain indexes of variables and constructors we split on
		
		// check out all the forms which are used
		final MultiMap<Object,StandardizedRule> splitRules = new HashMultiMap<Object,StandardizedRule>();
			// the keys are either integers representing variables (-1 for a free variable, or its index for a binder)
			// or strings representing a constructor; the values are part of relevantRules
		
		for (StandardizedRule pair : relevantRules)
		{
			Term pattern = pair.one();
			Term arg = pattern.sub(0);
			if (arg.kind() == Kind.VARIABLE_USE)
			{
				int num = -1;
				for (int i = 0; i < pattern.binders(0).length; i++)
					if (arg.variable() == pattern.binders(0)[i])
						num = i;
				Integer in = new Integer(num);
				if (!splitRules.multiContainsKey(in)) splits.add(in);
				splitRules.multiAdd(in, pair);
			}
			else
			{
				String symb = Util.symbol(arg);
				if (!splitRules.multiContainsKey(symb)) splits.add(symb);
				splitRules.multiAdd(symb, pair);
			}
		}
		
		// order the split constructors, so we can deal with them in a nice order
		Collections.sort(splits, new Comparator<Object>()
			{
				public int compare(Object o1, Object o2)
				{
					if (o1 instanceof Integer)
					{
						if (!(o2 instanceof Integer)) return -1;
						else return ((Integer) o1).compareTo((Integer) o2);
					}
					else if (o2 instanceof Integer) return 1;
					else return ((String) o1).compareTo((String) o2);
				}
			});

		// for each of the rules, do the splitting
		for (Object o : splits)
		{
			Set<StandardizedRule> rules = splitRules.get(o);
			StandardizedRule firstRule = rules.iterator().next();
			GenericTerm examplePattern = firstRule.one();
			Constructor exampleName = firstRule.three();
			Constructor exampleSymbol = examplePattern.constructor();
			Term exampleSort = sortGet(sortsSave, examplePattern);
			GenericTerm exampleForm = getForm(examplePattern, null, sortsSave, true);
			Constructor newsymbol = env.internalSymbol(examplePattern.constructor());
			if (exampleSort != null && exampleSort.kind() == Kind.VARIABLE_USE)
			{
				// Recover from variable sort: reget from factory and substitute...
				Set<Pair<Term,Term>> originalFormPairs = factory.formsOf(Util.symbol(examplePattern));
				if (!originalFormPairs.isEmpty())
				{
					// Hack: actually update form to use right variable...
					Pair<Term,Term> originalFormPair = originalFormPairs.iterator().next();
					assert originalFormPair.head().kind() == Kind.VARIABLE_USE;
					Variable exampleSortVariable = exampleSort.variable();
					Variable originalSortVariable = originalFormPair.head().variable();
					exampleForm = (GenericTerm) originalFormPair.tail().copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
					if (exampleForm.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(exampleForm)))
						exampleForm = exampleForm.sub(0);
					Set<Variable> sortParams = new HashSet<Variable>();
					for (int i = 0; i < exampleForm.arity(); i++)
					{
						GenericTerm subi = exampleForm.sub(i);
						if (subi.kind() == Kind.VARIABLE_USE)
						{
							if (subi.variable().equals(originalSortVariable))
							{
								exampleForm.replaceSub(i, exampleForm.binders(i), factory.newVariableUse(exampleSortVariable));
								sortParams.add(exampleSortVariable);
							}
							else
								sortParams.add(subi.variable());
						}
						else
						{
							for (int j = 0; j < subi.arity(); j++)
							{
								GenericTerm subij = subi.sub(j);
								if (subij.kind() == Kind.VARIABLE_USE)
								{
									if (subij.variable().equals(originalSortVariable))
									{
										subi.replaceSub(j, subi.binders(j), factory.newVariableUse(exampleSortVariable));
										sortParams.add(exampleSortVariable);
									}
									else
										sortParams.add(subij.variable());
								}										
							}
						}
					}
					factory.setSortForm(exampleSort, sortParams, exampleForm, true, true);
				}
			}
			if (exampleSort == null)
				warning("Incomplete sort information for "+examplePattern);

			if (o instanceof Integer)
			{
				int oi = ((Integer) o).intValue();
				if (oi == -1)
				{
					// Encodes the FREE VARIABLE case: Create the rule {#Γ}F[x1...xn.z,#1,...,#m] → {#Γ}Fj[z,#1,...,#m]
					Variable z = env.makeVariable("z", true);
					//String originalVariableName = examplePattern.sub(0).variable().name();
					//
					GenericTerm pattern = createFromExample(examplePattern, exampleSymbol.symbol(), false, 0, false, false, null);
					pattern = pattern.stripProperties(); //pattern.removeProperty(originalVariableName);
					if (!(pattern instanceof PropertiesConstraintsWrapper))
						pattern = new PropertiesConstraintsWrapper(pattern, null, null, null, null); // the standardized convention
					pattern = pattern.wrapWithProperty(REFERENCE, factory.newMetaApplication("#Γ", GenericTerm.NO_TERMS), true);
					pattern = pattern.wrapWithProperty(STANDARDIZED, factory.nil(), true);
					Term patternSubSort = exampleForm.sub(0).stripProperties();
					pattern.replaceSub(0, pattern.binders(0), factory.newVariableUse(z));
					sortPut(sortsSave, pattern.sub(0), patternSubSort);
					sortPut(sortsSave, pattern, exampleSort);
					//
					GenericTerm contractum = createFromExample(examplePattern, newsymbol.symbol(), false, 0, false, false, null);
					contractum = contractum.stripProperties(); //contractum.removeProperty(originalVariableName);
					if (!(contractum instanceof PropertiesConstraintsWrapper))
						contractum = new PropertiesConstraintsWrapper(contractum, null, null, null, null); // the standardized convention
					contractum = contractum.wrapWithProperty(REFERENCE, factory.newMetaApplication("#Γ", GenericTerm.NO_TERMS), true);
					contractum = contractum.wrapWithProperty(STANDARDIZED, factory.nil(), true);
					contractum.replaceSub(0, null, factory.newVariableUse(z));
					sortPut(sortsSave, contractum, exampleSort);
					
					// Deal with options
					Map<String,List<Term>> os = new HashMap<String, List<Term>>();
					List<Term> fs = new ArrayList<Term>();
					fs.add(factory.newVariableUse(z));
					os.put(Builder.FREE_OPTION_SYMBOL, fs);
					// Set compileType
					List<Term> compileTypes = new ArrayList<Term>();
					compileTypes.add(factory.parse("Dispatch"));
					os.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);
					
					// Create rule and sort.
					ret.add(new StandardizedRule(factory, pattern, contractum, Util.wrapWithProperties(factory, factory.makeConstructor(exampleName.symbol()+"$vFree"), Util.propertiesHolder(pattern)), os));
					GenericTerm contractumForm = getForm(examplePattern, Util.symbol(contractum), sortsSave, false);
					for (Variable b : contractumForm.binders(0))
						contractumForm.sub(0).removeProperty(b);
					contractumForm.replaceSub(0, null, contractumForm.sub(0));
					factory.setSortForm(exampleSort, null, contractumForm, true, false);
					
					// change all the rules to have a meta-variable in place of the free variable
					// (since when getting to Fj we already know that it's a variable)
					Set<String> annoyingContractum = new HashSet<String>();
					for (StandardizedRule rule : rules)
					{
						GenericTerm oldPattern = rule.one();
						Variable x = oldPattern.sub(0).variable();
						//
						if (rule.four() != null && rule.four().containsKey(Builder.FREE_OPTION_SYMBOL))
						{
							// Check options for the obsolete Free declaration.
							for (Iterator<Term> it = rule.four().get(Builder.FREE_OPTION_SYMBOL).iterator(); it.hasNext();)
							{
								Variable v = Util.variableWithOptionalSortVariable(it.next());
								if (v == x) it.remove();
							}
						}
						// Replace the pattern constructor with Fj and update arguments and options.
						GenericTerm newPattern = createCopy(contractum, sortsSave); //copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
						if (!(newPattern instanceof PropertiesConstraintsWrapper))
							newPattern = new PropertiesConstraintsWrapper(newPattern, null, null, null, null); // the standardized convention
						newPattern.replaceSub(0, null, oldPattern.sub(0));
						for (int j = 1; j < newPattern.arity(); ++j)
							newPattern.replaceSub(j, oldPattern.binders(j), oldPattern.sub(j));
						PropertiesHolder oldProperties = Util.propertiesHolder(oldPattern);
						for (String key : oldProperties.propertyNames())
							newPattern = newPattern.wrapWithProperty(key, oldProperties.getProperty(key), false);
						replaceVariableByMetaVariable(newPattern, x, sortsSave, new HashSet<Term>(), false);
						//
						if (Util.hasProperty(oldPattern, x.name()))
						{
							String matchedMetaVariable = "#" + x.name().substring(1);
							GenericTerm xProperty = (GenericTerm) Util.getProperty(oldPattern, x.name());
							newPattern = newPattern.wrapWithProperty(matchedMetaVariable, xProperty, true);
						}
						else if (Util.hasNotProperty(oldPattern, x.name()))
						{
							String matchedMetaVariable = "#" + x.name().substring(1);
							newPattern = newPattern.wrapWithNotProperty(matchedMetaVariable, true);
						}
						//
						rule.setOne(newPattern);
						sortPut(sortsSave, newPattern, exampleSort);
						Set<Term> repeatedMetaVariables = new HashSet<Term>();
						if (rule.two() != null && rule.two().kind() == Kind.VARIABLE_USE && rule.two().variable() == x)
						{
							// Take special care of rules that erase to a variable.
							annoyingContractum.add(rule.three().symbol());
						}
						else if (replaceVariableByMetaVariable(rule.two(), x, sortsSave, repeatedMetaVariables, false))
						{
							// Usual case where variable is substituted with meta-variable.
							if (!repeatedMetaVariables.isEmpty())
							{
							 	if (rule.four() == null)
							 		rule.setFour(new HashMap<String, List<Term>>());
							 	List<Term> copied = rule.four().get(Builder.COPY_OPTION_SYMBOL);
							 	if (copied == null)
							 		rule.four().put(Builder.COPY_OPTION_SYMBOL, copied = new ArrayList<Term>());
							 	copied.addAll(repeatedMetaVariables);
							}
							if (rule.four() != null && rule.four().containsKey(Builder.FREE_OPTION_SYMBOL))
								rule.four().get(Builder.FREE_OPTION_SYMBOL).remove(x); // no longer free
						}
						else
						{
							// Replace failed so variable does not occur in contraction...
							if (rule.four() == null)
								rule.setFour(new HashMap<String, List<Term>>());
							if (!rule.four().containsKey(Builder.DISCARD_OPTION_SYMBOL))
								rule.four().put(Builder.DISCARD_OPTION_SYMBOL, new ArrayList<Term>());
							rule.four().get(Builder.DISCARD_OPTION_SYMBOL).add(standardPatternMetaApplication("#" + x.name().substring(1), GenericTerm.NO_TERMS));
							if (rule.four() != null && rule.four().containsKey(Builder.FREE_OPTION_SYMBOL))
								rule.four().get(Builder.FREE_OPTION_SYMBOL).remove(x); // no longer free
						}
					}
					// if the right-hand side IS that variable, the whole pair needs changing,
					// since you cannot alter the pointer to the head of a pair
					if (!annoyingContractum.isEmpty())
					{
						Set<StandardizedRule> replacementRules = new HashSet<StandardizedRule>();
						for (Iterator<StandardizedRule> it = rules.iterator(); it.hasNext();)
						{
							StandardizedRule r = it.next();
							if (annoyingContractum.contains(r.three().symbol()))
							{
								String xname = r.two().variable().name().substring(1);
								Term sort = sortGet(sortsSave, r.two());
								StandardizedRule replacement = new StandardizedRule(factory, r.one(), standardPatternMetaApplication("#" + xname, GenericTerm.NO_TERMS), r.three(), r.four());
								sortPut(sortsSave, replacement.two(), sort);
								replacementRules.add(replacement);
							}
							else
								replacementRules.add(r);
						}
						rules = replacementRules;
					}
					
					// declare the new symbol that was defined
					examplePattern = rules.iterator().next().one();
					contractumForm = getForm(examplePattern, newsymbol.symbol(), sortsSave, true);
					/*
					if (form == null && examplePattern.kind() == Kind.CONSTRUCTION)
					{
						// KRIS Oops: fall back to constructor form.
						List<Term> forms = factory.formsOf(sort, examplePattern.constructor());
						if (forms.size() == 1)
						{
							form = forms.get(0);
						}
					}
					*/
					factory.setSortForm(exampleSort, null, contractumForm, true, false);

					// continue splitting with these altered rules
					append(additionalRules, dispatchify(rules, sortsSave));
				}
				else
				{
					// create the rule F[x1...xn.xi,#1,...,#m] → Fj[#1,...,#m]
					GenericTerm pattern = createFromExample(examplePattern, exampleSymbol.symbol(), false, 0, false, false, null);
					pattern.replaceSub(0, pattern.binders(0), factory.newVariableUse(pattern.binders(0)[oi]));
					GenericTerm contractum = createFromExample(examplePattern, newsymbol.symbol(), true, 1, false, false, null);
					ret.add(new StandardizedRule(factory, pattern, contractum, factory.makeConstructor(exampleName.symbol() + "$v" + oi), null));

					// declare the new symbol that was defined
					Term sort = sortGet(sortsSave, examplePattern);
					{
						Variable[][] binders = new Variable[contractum.arity()][];
						GenericTerm[] sub = new GenericTerm[contractum.arity()];
						assert sub.length +1 == examplePattern.arity();
						for (int i = 0; i < sub.length; ++i)
						{
							binders[i] = exampleForm.binders(i+1);
							sub[i] = exampleForm.sub(i+1);
						}
						Term form = factory.newConstruction(newsymbol, binders, sub);
						factory.setSortForm(sort, null, form, true, false);
					}
					sortPut(sortsSave, pattern, sort);
					sortPut(sortsSave, contractum, sort);
					
					// remove the first argument of the relevant rules
					for (StandardizedRule rule : rules)
					{
						GenericTerm oldPattern = rule.one();
						Variable[][] binders = new Variable[oldPattern.arity()-1][];
						GenericTerm[] sub = new GenericTerm[oldPattern.arity()-1];
						for (int i = 1; i < oldPattern.arity(); i++)
						{
							binders[i-1] = oldPattern.binders(i);
							sub[i-1] = oldPattern.sub(i);
						}
						GenericTerm newPattern = factory.newConstruction(contractum.constructor(), binders, sub);
						if (oldPattern instanceof PropertiesConstraintsWrapper)
						{
							PropertiesConstraintsWrapper pcw =  Util.makePropertiesConstraintsWrapper(newPattern, null, null, null, null);
							pcw.setProperties((PropertiesConstraintsWrapper) oldPattern);
							newPattern = pcw;
						}
						rule.setOne(newPattern);
						sortPut(sortsSave, newPattern, sort);
					}
					
					// continue splitting with these altered rules
					append(additionalRules, dispatchify(rules, sortsSave));
				}
			}
			else
			{
				// (1) Create dispatch rule  {#Γ} F[{#Δ} A[#0,...,#n],#n+1,...,#m] → {#Γ} Fj[#0,...,#m, {#Δ} PropsOf$A]  (Fj = newsymbol)
				// (1a) - a few tidbits...
				int exampleArity = examplePattern.arity();
				Term exampleDispatcher = examplePattern.sub(0);
				String dispatcherSymbol = Util.symbol(exampleDispatcher);
				//Term dispatcherSort = sortGet(sortsSave, dispatcher);
				Term dispatcherSort = factory.sortOf((String) o);
				final int dispatcherArity = exampleDispatcher.arity();
				int totalArity = exampleArity + dispatcherArity - 1;
				boolean copyProperties = Standardizer.hasPropertySet(exampleDispatcher);
				// (1b) - pattern: make generic except for dispatch argument.
				GenericTerm pattern = createFromExample(examplePattern, exampleSymbol.symbol(), false, dispatcherArity-1, false, true, null);
				for (String k : Util.propertiesHolder(pattern).propertyNames())
					if (!k.startsWith("$$"))
						pattern.removeProperty(k);
				Variable[] dispatcherTopBinders = pattern.binders(0);
				int dispatcherTopRank = dispatcherTopBinders.length;
				Variable[][] binders = new Variable[dispatcherArity][];
				GenericTerm[] subterms = new GenericTerm[dispatcherArity];
				for (int i = 0; i < dispatcherArity; i++)
				{
					int dispatcherSubRank = exampleDispatcher.binders(i).length;
					GenericTerm[] args = new GenericTerm[dispatcherTopRank + dispatcherSubRank];
					binders[i] = new Variable[dispatcherSubRank];
					for (int j = 0; j < dispatcherTopRank; j++)
						args[j] = factory.newVariableUse(dispatcherTopBinders[j]);
					for (int j = 0; j < dispatcherSubRank; j++)
					{
						binders[i][j] = env.makeVariable("y" + j, true);
						args[dispatcherTopRank + j] = factory.newVariableUse(binders[i][j]);
					}
					subterms[i] = standardPatternMetaApplication("#0-" + i, args);
				}
				GenericTerm patternDispatcher = factory.newConstruction(factory.makeConstructor(exampleDispatcher.constructor()), binders, subterms);
				if (copyProperties)
				{
					GenericTerm[] args = new GenericTerm[dispatcherTopRank];
					for (int j = 0; j < dispatcherTopRank; j++)
						args[j] = factory.newVariableUse(dispatcherTopBinders[j]);
					patternDispatcher = Util.makePropertiesConstraintsWrapper(patternDispatcher, null, null, null, null);
					Term ref = standardPatternMetaApplication("#Δ", args);
					((PropertiesConstraintsWrapper) patternDispatcher).setProperty(REFERENCE, ref);
				}
				pattern.replaceSub(0, dispatcherTopBinders, patternDispatcher);
				// (1c) - contractum:
				GenericTerm contractum = createFromExample(examplePattern, newsymbol.symbol(), true, 0, copyProperties, false, null);
				for (String k : Util.propertiesHolder(contractum).propertyNames())
					if (!k.startsWith("$$"))
						contractum.removeProperty(k);
				for (int i = 0; i < dispatcherArity; ++i)
				{
					final int dispatcherSubRank = patternDispatcher.binders(i).length;
					if (dispatcherTopRank == 0)
						contractum.replaceSub(i, patternDispatcher.binders(i), patternDispatcher.sub(i));
					else
					{
						// -- recreate dispatcher arguments with added binders and arguments for contraction's variables...
						final Variable[] subbinders = new Variable[dispatcherTopRank + dispatcherSubRank];
						final GenericTerm[] subargs = new GenericTerm[dispatcherTopRank + dispatcherSubRank];
						for (int j = 0; j < dispatcherTopRank; ++j)
						{
							subbinders[j] = contractum.binders(i)[j];
							subargs[j] = factory.newVariableUse(subbinders[j]);
						}
						for (int j = 0; j < dispatcherSubRank; ++j)
						{
							final int jj = dispatcherTopRank + j;
							subbinders[jj] = patternDispatcher.binders(i)[j];
							subargs[jj] = factory.newVariableUse(subbinders[jj]);
						}
						GenericTerm patternDispatcherSub = patternDispatcher.sub(i);
						GenericTerm sub = factory.newMetaApplication(patternDispatcherSub.metaVariable(), subargs);
						sub = Util.makePropertiesConstraintsWrapper(sub, null, null, null, null);
						sub = sub.wrapWithProperty(STANDARDIZED, factory.nil(), false);
						if (patternDispatcherSub instanceof PropertiesConstraintsWrapper && ((PropertiesConstraintsWrapper) patternDispatcherSub).propertiesRef() != null)
							sub = sub.wrapWithProperty(REFERENCE, factory.newMetaApplication(((PropertiesConstraintsWrapper) patternDispatcherSub).propertiesRef(), GenericTerm.NO_TERMS), false);
						contractum.replaceSub(i, subbinders, sub);
					}
				}
				//(1d) - compose sort declaration for new symbol.
				GenericTerm contractumForm = unstandardize(createFromExample(examplePattern, newsymbol.symbol(), true, 0, copyProperties, false, null));
				contractumForm = contractumForm.stripProperties();
				GenericTerm examplePatternForm = getForm(examplePattern, null, sortsSave, true);
				final int examplePatternFormArity = examplePatternForm.arity();
				GenericTerm dispatcherForm = formOf(dispatcherSort, dispatcherSymbol);
				if (dispatcherForm == null)
					dispatcherForm = getForm(exampleDispatcher, Util.symbol(exampleDispatcher), sortsSave, true);
				for (int i = 0; i < dispatcherArity; ++i)
				{
					final int dispatcherSubRank = dispatcherForm.binders(i).length;
					GenericTerm sub = dispatcherForm.sub(i);
					if (dispatcherTopRank == 0)
						contractumForm.replaceSub(i, dispatcherForm.binders(i), sub);
					else
					{
						// -- recreate dispatcher arguments with added binders and arguments for contraction's variables...
						final Variable[] subbinders = new Variable[dispatcherTopRank + dispatcherSubRank];
						for (int j = 0; j < dispatcherTopRank; ++j)
						{
							subbinders[j] = contractumForm.binders(i)[j];
							sub = sub.wrapWithProperty(subbinders[j], Util.getProperty(examplePatternForm.sub(0), examplePatternForm.binders(0)[j]), false);
						}
						for (int j = 0; j < dispatcherSubRank; ++j)
						{
							subbinders[dispatcherTopRank + j] = dispatcherForm.binders(i)[j];
							sub = sub.wrapWithProperty(subbinders[dispatcherTopRank + j], Util.getProperty(dispatcherForm.sub(i), dispatcherForm.binders(i)[j]), false);
						}
						contractumForm.replaceSub(i, subbinders, sub);
					}
				}
				for (int i = 0; i < examplePatternFormArity-1; ++i)
				{
					contractumForm.replaceSub(dispatcherArity+i, examplePatternForm.binders(i+1), examplePatternForm.sub(i+1));
				}
				if (copyProperties)
				{
					// -- insert dispatcher properties holder into extra field last in contractum...
					String dispatcherPropertiesSymbol = "PropsOf$" + Util.symbol(exampleDispatcher);
					Constructor dispatcherPropertiesConstructor = factory.makeConstructor(dispatcherPropertiesSymbol);
					GenericTerm dispatcherProperties = factory.constant(dispatcherPropertiesConstructor);
					PropertiesConstraintsWrapper wrap = Util.makePropertiesConstraintsWrapper(dispatcherProperties, null, null, null, null);
					wrap.setProperty(STANDARDIZED, factory.nil());
					Variable[] newbinds = new Variable[dispatcherTopRank];
					GenericTerm[] args = new GenericTerm[dispatcherTopRank];
					for (int i = 0; i < dispatcherTopRank; i++)
					{
						newbinds[i] = env.makeVariable("x" + i, true);
						args[i] = factory.newVariableUse(newbinds[i]);
					}
					wrap.setProperty(REFERENCE, standardPatternMetaApplication("#Δ", args));
					contractum.replaceSub(contractum.arity()-1, newbinds, wrap);
					// -- insert dispatcherProperties sort if not previously used...
					GenericTerm dispatcherPropertiesSort;
					dispatcherPropertiesSort = (GenericTerm) factory.sortOf(dispatcherPropertiesConstructor.symbol());
					if (dispatcherPropertiesSort == null)
					{
						dispatcherPropertiesSort = factory.constant(factory.makeConstructor(dispatcherPropertiesSymbol+"_SORT"));
						factory.setSortForm(dispatcherPropertiesSort, null, unstandardize((GenericTerm) dispatcherProperties), false, false);
						Map<String,Term> dispatcherPropertiesSortSet = factory.sortsetFor(Util.symbol(dispatcherSort));
						factory.setSortsetFor(Util.symbol(dispatcherPropertiesSort), dispatcherPropertiesSortSet);
					}
					for (int i = 0; i < dispatcherTopRank; i++)
					{
						dispatcherPropertiesSort = Util.wrapWithProperty(dispatcherPropertiesSort, newbinds[i], Util.getProperty(exampleForm.sub(0), exampleForm.binders(0)[i]));
					}
					contractumForm.replaceSub(contractum.arity()-1, newbinds, dispatcherPropertiesSort);
				}
				contractumForm = Util.makePropertiesConstraintsWrapper(contractumForm.stripProperties(), null, Util.namedProperties(Util.propertiesHolder(examplePatternForm), factory), null, null);

				// (1e) - add options.
				List<Term> compileTypes = new ArrayList<Term>();
				compileTypes.add(factory.parse("Dispatch"));
				Map<String, List<Term>> options = new HashMap<String, List<Term>>();
				options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);

				// (1f) - register rule and sort.
				ret.add(new StandardizedRule(factory, pattern, contractum, Util.wrapWithProperties(factory, factory.makeConstructor(firstRule.getName().symbol()+"$"+exampleSymbol.symbol()+"$"+Util.symbol(exampleDispatcher)), exampleSymbol), options));
				factory.setSortForm(exampleSort, null, contractumForm, true, true); // TODO: polymorphic dispatch?

				// "flatten" the first argument of the relevant rules
				for (StandardizedRule rule : rules)
				{
					GenericTerm oldPattern = rule.one();
					int makeArgs = copyProperties ? totalArity+1 : totalArity;
					Variable[][] binds = new Variable[makeArgs][];
					GenericTerm[] subs = new GenericTerm[makeArgs];
					for (int i = 0; i < dispatcherArity; i++)
					{
						int subBinderLength = oldPattern.sub(0).binders(i).length;
						binds[i] = new Variable[dispatcherTopRank + subBinderLength];
						for (int j = 0; j < dispatcherTopRank; j++)
							binds[i][j] = oldPattern.binders(0)[j];
						// note: the same binder might get used several times in the resulting term;
						// this is not a problem because we will not actually *use* this pattern, merely its form
						for (int j = 0; j < subBinderLength; j++)
							binds[i][dispatcherTopRank+j] = oldPattern.sub(0).binders(i)[j];
						subs[i] = oldPattern.sub(0).sub(i);
					}
					for (int i = 1; i < exampleArity; i++)
					{
						binds[dispatcherArity+i-1] = oldPattern.binders(i);
						subs[dispatcherArity+i-1] = oldPattern.sub(i);
					}
					if (copyProperties)
					{
						Variable[] subbinds = oldPattern.binders(0);
						GenericTerm[] subargs = new GenericTerm[subbinds.length];
						for (int i = 0; i < subbinds.length; i++)
							subargs[i] = factory.newVariableUse(subbinds[i]);
						Set<String> mvars = oldPattern.mvars();
						int j;
						for (j = 0; mvars.contains("#propsof" + j); j++);
						subs[totalArity] = standardPatternMetaApplication("#propsof" + j, subargs);
						if (rule.four() == null)
							rule.setFour(new HashMap<String, List<Term>>());
						if (!rule.four().containsKey(Builder.DISCARD_OPTION_SYMBOL))
							rule.four().put(Builder.DISCARD_OPTION_SYMBOL, new ArrayList<Term>());	
						rule.four().get(Builder.DISCARD_OPTION_SYMBOL).add(standardPatternMetaApplication("#propsof" + j, GenericTerm.NO_TERMS));
						Map<String,Term> props = ((PropertiesConstraintsWrapper) oldPattern.sub(0)).getLocalProperties();
						subs[totalArity] = Util.makePropertiesConstraintsWrapper((GenericTerm) subs[totalArity], null, props, null, null);
						sortPut(sortsSave, subs[totalArity], contractumForm.sub(contractumForm.arity()-1));
						binds[totalArity] = subbinds;
					}
					GenericTerm newPattern = factory.newConstruction(factory.makeConstructor(newsymbol), binds, subs);
					newPattern = new PropertiesConstraintsWrapper(newPattern, null, null, null, null);
					for (String key : Util.propertiesHolder(oldPattern).propertyNames())
						newPattern = newPattern.wrapWithProperty(key, Util.propertiesHolder(oldPattern).getProperty(key), true);
					rule.setOne(newPattern);
					// TODO: finish this to recreate Copy+Weak options!
					//rule.setFour(fixupMetaOptions(rule.four()));
					sortPut(sortsSave, newPattern, sortGet(sortsSave, oldPattern));
				}

				// continue splitting with these altered rules
				append(additionalRules, dispatchify(rules, sortsSave));
			}
		}

		// append the new rules to the end of ret; this is done by means of additionalRules
		// rather than immediately to make sure the rules are in a neat order
		append(ret, additionalRules);
	}
//
//	private Map<String, List<Term>> fixupMetaOptions(GenericTerm contractum, Map<String, List<Term>> options)
//    {
//		Map<String,Integer> metaCounts = new HashMap<String, Integer>();
//		fixupMetaOptions1(contractum, metaCounts, false);
//	    for (String o : metaCounts.keySet())
//	    {
//	    	if (metaCounts.get(o) > 1)
//	    	{
//		    if (options == null)
//		    	options = new HashMap<String, List<Term>>();
//		    if (!options.containsKey(Builder.COPY_OPTION_SYMBOL))
//		    	options.
//	    	}
//	    }
//	   return options;
//    }
//
//	private void fixupMetaOptions1(Term term, Map<String,Integer> metaCounts, boolean inMeta)
//	{
//		PropertiesHolder ph = Util.propertiesHolder(term);
//		for (String property : ph.propertyNames())
//		{
//			if (property.startsWith("#"))
//				increaseMetaCounts(metaCounts, property, inMeta ? 2 : 1);
//			fixupMetaOptions1(ph.getProperty(property), metaCounts, inMeta);
//		}
//		for (Variable property : ph.propertyVariables())
//			fixupMetaOptions1(ph.getProperty(property), metaCounts, inMeta);
//		if (ph.isMeta())
//		{
//			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
//			if (pcw.propertiesRef() != null)
//				increaseMetaCounts(metaCounts, pcw.propertiesRef(), inMeta ? 2 : 1);
//			for (String metaProperty : pcw.metaPropertyConstraints.keySet())
//			{
//				increaseMetaCounts(metaCounts, metaProperty, inMeta ? 2 : 1);
//				fixupMetaOptions1(pcw.getMetaProperty(metaProperty), metaCounts, inMeta);
//			}
//		}
//		switch (term.kind())
//		{
//			case VARIABLE_USE :
//				break;
//			case CONSTRUCTION :
//				for (int i = 0; i < term.arity(); ++i)
//					fixupMetaOptions1(term.sub(i), metaCounts, inMeta);
//				break;
//			case META_APPLICATION :
//				for (int i = 0; i < term.arity(); ++i)
//					fixupMetaOptions1(term.sub(i), metaCounts, true);
//				break;
//		}
//	}
//	
//	private void increaseMetaCounts(Map<String, Integer> metaCounts, String metaVariable, int increase)
//    {
//		metaCounts.put(metaVariable,  (metaCounts.containsKey(metaVariable) ? metaCounts.get(metaVariable) + increase : increase));
//    }

	/**
	 * Given a term which follows the usual conventions (except that names of
	 * variables and meta-variables might not actually correspond to their
	 * position anymore), replace the variable x everywhere in the given term
	 * by the meta-variable #x.  This includes keys in property sets.
	 * The replacement is done inside the term itself, so no modified version
	 * needs to be returned.
	 *
	 * @param term to update
	 * @param x variable to replace
	 * @param sortsSave with stored sorts
	 * @param repeatedMetaVariables to record if meta-variables are repeated
	 * @param inMetaApplication whether to also replace inside meta-applications
	 * @return whether any variables were in fact replaced
	 * @throws CRSException
	 */
	boolean replaceVariableByMetaVariable(GenericTerm term, Variable x, Map<Object,Term> sortsSave, Set<Term> repeatedMetaVariables, boolean inMetaApplication) throws CRSException
	{
		boolean replaced = false;
		if (term == null)
			return replaced;
		Term termSort = sortGet(sortsSave, term);
		
		for (int i = 0; i < term.arity(); i++)
		{
			if (term.sub(i).kind() == Kind.VARIABLE_USE && term.sub(i).variable().equals(x))
			{
				String name = "#" + x.name().substring(1);
				GenericTerm meta = standardPatternMetaApplication(name, GenericTerm.NO_TERMS);
				if (repeatedMetaVariables != null && (sortContains(sortsSave, meta) || inMetaApplication))
					repeatedMetaVariables.add(meta);
				sortPut(sortsSave, meta, sortGet(sortsSave, term.sub(i)));
				term.replaceSub(i, term.binders(i), meta);
				replaced = true;
			}
			else
				replaced |= replaceVariableByMetaVariable((GenericTerm) term.sub(i), x, sortsSave, repeatedMetaVariables, inMetaApplication || term.kind() == Kind.META_APPLICATION);
		}
		
		if (term instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) term;
			boolean xAsKey = false;
			for (String key : pcw.propertyNames())
			{
				// Replace in properties with hack to allow for simple variable use.
				GenericTerm value = (GenericTerm) pcw.getProperty(key);
				if (value != null && value.kind() == Kind.VARIABLE_USE && value.variable().equals(x))
				{
					Term meta = standardPatternMetaApplication("#" + x.name().substring(1), GenericTerm.NO_TERMS);
					if (repeatedMetaVariables != null && (sortContains(sortsSave, meta) || inMetaApplication))
						repeatedMetaVariables.add(meta);
					sortPut(sortsSave, meta, sortGet(sortsSave, pcw.getProperty(key)));
					pcw.setProperty(key, meta);
					replaced = true;
				}
				else
					replaced |= replaceVariableByMetaVariable(value, x, sortsSave, repeatedMetaVariables, inMetaApplication || term.kind() == Kind.META_APPLICATION);
				if (key.equals(x.name())) xAsKey = true;
			}
			for (Variable key : pcw.propertyVariables())
			{
				GenericTerm value = (GenericTerm) pcw.getProperty(key);
				if (value != null && value.kind() == Kind.VARIABLE_USE && value.variable().equals(x))
				{
					Term meta = standardPatternMetaApplication("#" + x.name().substring(1), GenericTerm.NO_TERMS);
					if (repeatedMetaVariables != null && (sortContains(sortsSave, meta) || inMetaApplication))
						repeatedMetaVariables.add(meta);
					sortPut(sortsSave, meta, sortGet(sortsSave, pcw.getProperty(key)));
					pcw.setProperty(key, meta);
					replaced = true;
				}
				else
					replaced |= replaceVariableByMetaVariable(value, x, sortsSave, repeatedMetaVariables, inMetaApplication || term.kind() == Kind.META_APPLICATION);
				if (key == x) xAsKey = true;
			}
			for (String key : pcw.metaPropertyConstraints.keySet())
			{
				GenericTerm value = (GenericTerm) pcw.getMetaProperty(key);
				if (value != null && value.kind() == Kind.VARIABLE_USE && value.variable().equals(x))
				{
					Term meta = standardPatternMetaApplication("#" + x.name().substring(1), GenericTerm.NO_TERMS);
					if (repeatedMetaVariables != null && (sortContains(sortsSave, meta) || inMetaApplication))
						repeatedMetaVariables.add(meta);
					sortPut(sortsSave, meta, sortGet(sortsSave, pcw.getProperty(key)));
					pcw.setProperty(key, meta);
					replaced = true;
				}
				else
					replaced |= replaceVariableByMetaVariable(value, x, sortsSave, repeatedMetaVariables, inMetaApplication || term.kind() == Kind.META_APPLICATION);
			}
			if (xAsKey)
			{
				Term value = pcw.getProperty(x.name());
				pcw.removeProperty(x.name());
				pcw.setProperty("#" + x.name().substring(1), value);
				replaced = true;
			}
		}
		
		if (replaced)
			sortPut(sortsSave, term, termSort);
		return replaced;
	}

	/**
	 * Given a set of rules, where either the pattern itself has a property set
	 * with the given key (if "position" is set to -1), or its first argument
	 * has a property set with the given key, split into the cases where ¬k and
	 * k : v are used and create rules for both cases.
	 * @param ret All new rules will be added to ret.
	 * @param relevantRules Contains the rules we should work with, in the
	 *   form <contractum,pattern>
	 * @param numberSymbols Gives the index where we should start counting rules,
 	 * 	 and is modified to reflect rules which were added
	 * @param key the name of the key to split on; can be either a meta-variable
	 *   or a constructor, or a bound variable, but not a free variable
	 * @param position the position where we split; this can either be -1 for
	 *   the property set of the top-term, or 0 for the property set of the
	 *   first argument
	 * @throws CRSException possible result of giving an error
	 */
	private void splitByKey(List<StandardizedRule> ret,
							Set<StandardizedRule> relevantRules,
							String key, int position,
							Map<Object,Term> sortsSave) throws CRSException
	{
		if (factory.verbosity() > 2)
		{
			factory.message("- splitting "+Util.symbol(relevantRules.iterator().next().getPattern())+" rules by KEY("+key+","+position+")");
//			if (key.startsWith("#") && position == 0)
//				factory.message("karma");
		}

		List<StandardizedRule> additionalRules = new ArrayList<StandardizedRule>(5);

		// figure out what, exactly, the key is
		GenericTerm example = relevantRules.iterator().next().one();
		int keyBoundVarIndex = -1;
		int keyFreeVarIndex = -1;
		int keyMetaPosition = -1;
		String keyConstructorName = null;
		if (key.charAt(0) == '%')
		{
			keyConstructorName = key.substring(1);
		}
		else if (key.charAt(0) == 'x' && position != -1)
		{
			for (int i = 0; i < example.binders(position).length; i++)
				if (key.equals(example.binders(position)[i].name()))
					keyBoundVarIndex = i;
		}
		else if (key.charAt(0) == 'z' && position != -1)
		{
			for (int i = 0; i < example.arity(); i++)
				if (example.sub(i).kind() == Kind.VARIABLE_USE && example.sub(i).variable().equals(key))
					keyFreeVarIndex = i;
		}
		else if (key.charAt(0) == '#')
		{
			for (int i = 0; i < example.arity(); i++)
				if (example.sub(i).kind() == Kind.META_APPLICATION && example.sub(i).metaVariable().equals(key))
					keyMetaPosition = i;
		}
		if (keyBoundVarIndex == -1 && keyFreeVarIndex == -1 && keyMetaPosition == -1 && keyConstructorName == null)
			fatal("cannot find key " + key + " in pattern " + example);
		
		// separate those rules with and without the key
		Set<StandardizedRule> withKey = new HashSet<StandardizedRule>();
		Set<StandardizedRule> withoutKey = new HashSet<StandardizedRule>();
		for (StandardizedRule pair : relevantRules)
		{
			GenericTerm pattern = pair.one();
			if (position == -1)
			{
				if (Util.propertiesHolder(pattern).getProperty(key) == null)
					withoutKey.add(pair);
				else withKey.add(pair);
			}
			else
			{
				if (Util.propertiesHolder(pattern.sub(position)).getProperty(key) == null)
					withoutKey.add(pair);
				else withKey.add(pair);
			}
		}
		
		// if either withKey or withoutKey is empty, we could skip a step, but I
		// cannot imagine a situation where this would happen, so let's not cater
		// for that too much
		
		if (!withoutKey.isEmpty())
		{
			StandardizedRule currentRule = withoutKey.iterator().next();
			GenericTerm examplePattern = currentRule.one();
			Constructor symbol = examplePattern.constructor();
 			GenericTerm exampleForm = getForm(examplePattern, null, sortsSave, true);
			
			// create a new rule {#Γ ; ¬k} F[#0,...,#n-1] → {#Γ} Fj[#0,...,#n-1]
			// (taking into account that the property set might instead be around #0)
			PropertiesConstraintsWrapper propertySet;
			GenericTerm newPattern = createFromExample(examplePattern, symbol.symbol(), false, 0, false, false, null);
			Constructor newsymbol = env.internalSymbol(examplePattern.constructor());
			GenericTerm newContractum = createFromExample(examplePattern, newsymbol.symbol(), false, 0, false, false, null);
			// declare the new symbol that was defined
			Term sort = sortGet(sortsSave, examplePattern);
			Term form = getForm(examplePattern, newsymbol.symbol(), sortsSave, true);
			factory.setSortForm(sort, null, form, true, false);

			if (position == -1)
				propertySet = (PropertiesConstraintsWrapper) newPattern;
			else
			{
				GenericTerm[] args = new GenericTerm[newPattern.binders(position).length];
				for (int i = 0; i < args.length; i++)
					args[i] = factory.newVariableUse(newPattern.binders(position)[i]);
				GenericTerm reference = standardPatternMetaApplication("#Δ", args);
				PropertiesConstraintsWrapper lsub = Util.makePropertiesConstraintsWrapper((GenericTerm) newPattern.sub(position), null, null, null, null);
				lsub.setProperty(REFERENCE, reference);
				newPattern.replaceSub(position, newPattern.binders(position), lsub);
				for (int i = 0; i < args.length; i++)
					args[i] = factory.newVariableUse(newContractum.binders(position)[i]);
				reference = standardPatternMetaApplication("#Δ", args);
				PropertiesConstraintsWrapper rsub = Util.makePropertiesConstraintsWrapper((GenericTerm) newContractum.sub(position), null, null, null, null);
				rsub.setProperty(REFERENCE, reference);
				newContractum.replaceSub(position, newContractum.binders(position), rsub);
				propertySet = lsub;
			}
			Map<String,List<Term>> options = new HashMap<String, List<Term>>();
			if (keyBoundVarIndex != -1)
			{
				propertySet.setNotProperty(newPattern.binders(position)[keyBoundVarIndex]);
			}
			else if (keyFreeVarIndex != -1)
			{
				Variable v = newPattern.sub(keyFreeVarIndex).variable();
				propertySet.setNotProperty(v);
				GenericTerm keyUse = factory.newVariableUse(v);
				GenericTerm keySort = exampleForm.sub(keyFreeVarIndex);
				GenericTerm[] subs = {keyUse, keySort};
				GenericTerm freeContent = factory.newConstruction(factory.makeConstructor(Builder.FUNCTION_SORT_SYMBOL), GenericTerm.NO_BINDS, subs);
				List<Term> freeList = new ArrayList<Term>(1);
				freeList.add(freeContent);
				options.put(Builder.FREE_OPTION_SYMBOL, freeList);
			}
			else if (keyMetaPosition != -1)
				propertySet.setMetaProperty("#" + keyMetaPosition, null);
			else if (keyConstructorName != null)
				propertySet.setProperty(keyConstructorName, null);

			// Set compileType
			List<Term> compileTypes = new ArrayList<Term>();
			compileTypes.add(factory.parse("Contract"));
			options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);
			
			ret.add(new StandardizedRule(factory, newPattern, newContractum, factory.makeConstructor(currentRule.getName().symbol()
			        + "$" + newPattern.constructor().symbol()), options));

			// remove the key in question from the patterns of all relevant rules
			for (StandardizedRule pair : withoutKey)
			{
				if (position == -1)
					pair.one().removeProperty(key);
				else
					pair.one().sub(position).removeProperty(key);
			}
			
			// continue splitting with these altered rules
			append(additionalRules, dispatchify(withoutKey, sortsSave));
		}
		
		if (!withKey.isEmpty())
		{
			StandardizedRule currentRule = withKey.iterator().next();
			GenericTerm examplePattern = currentRule.one();
			Constructor symbol = examplePattern.constructor();
			GenericTerm exampleForm = getForm(examplePattern, null, sortsSave, true);
			
			// create a new rule {#Γ ; k : #n} F[#0,...,#n-1] → {#Γ} Fj[#0,...,#n-1,#n]
			// (taking into account that the property set might instead be around #0)
			PropertiesConstraintsWrapper propertySet;
			GenericTerm newPattern = createFromExample(examplePattern, symbol.symbol(), false, 0, false, true, null);
			Constructor newsymbol = env.internalSymbol(examplePattern.constructor());
			GenericTerm newContractum = createFromExample(examplePattern, newsymbol.symbol(), false, 0, true, true, null);
			// declare the new symbol that was defined
			Term sort = sortGet(sortsSave, examplePattern);
			
			GenericTerm newValue;
			if (position == -1)
			{
				propertySet = (PropertiesConstraintsWrapper) newPattern;
				newValue = standardPatternMetaApplication("#" + newPattern.arity(), GenericTerm.NO_TERMS);
				newContractum.removeProperty(key);
			}
			else
			{
				GenericTerm[] largs = new GenericTerm[newPattern.binders(position).length];
				GenericTerm[] rargs = new GenericTerm[newContractum.binders(position).length];
				Variable[] mbinds = new Variable[newPattern.binders(position).length]; 
				GenericTerm[] margs1 = new GenericTerm[newPattern.binders(position).length];
				GenericTerm[] margs2 = new GenericTerm[newPattern.binders(position).length];
				for (int i = 0; i < largs.length; i++)
				{
					largs[i] = factory.newVariableUse(newPattern.binders(position)[i]);
					rargs[i] = factory.newVariableUse(newContractum.binders(position)[i]);
					mbinds[i] = env.makeVariable("x" + i, true);
					margs1[i] = factory.newVariableUse(newPattern.binders(position)[i]);
					margs2[i] = factory.newVariableUse(mbinds[i]);
				}
				Term reference = standardPatternMetaApplication("#Δ", largs);
				PropertiesConstraintsWrapper lsub = Util.makePropertiesConstraintsWrapper((GenericTerm) newPattern.sub(position), null, null, null, null);
				lsub.setProperty(REFERENCE, reference);
				newPattern.replaceSub(position, newPattern.binders(position), lsub);
				reference = standardPatternMetaApplication("#Δ", rargs);
				PropertiesConstraintsWrapper rsub = Util.makePropertiesConstraintsWrapper((GenericTerm) newContractum.sub(position), null, null, null, null);
				rsub.setProperty(REFERENCE, reference);
				newContractum.replaceSub(position, newContractum.binders(position), rsub);
				propertySet = lsub;
				newValue = standardPatternMetaApplication("#" + newPattern.arity(), margs1);
				newContractum.replaceSub(newPattern.arity(), mbinds, standardPatternMetaApplication("#" + newPattern.arity(), margs2));
					// change the last argument of newContractum from #Z to /\x1...xn.#Z[x1,...,xn],
					// where the xi are the variables bound above the property set
			}
			GenericTerm keySort = null;
			GenericTerm valueSort = null;
			Map<String,List<Term>> options = new HashMap<String, List<Term>>();
			if (keyBoundVarIndex != -1)
			{
				assert position >= 0; //because root property set pattern cannot contain bound variables
				Variable v = newPattern.binders(position)[keyBoundVarIndex];
				propertySet.setProperty(key, newValue); //propertySet.setProperty(v, newValue);
				GenericTerm keyUse = factory.newVariableUse(v);
				keySort = (GenericTerm) Util.propertiesHolder(exampleForm.sub(position)).getProperty(exampleForm.binders(position)[keyBoundVarIndex]);
				valueSort = (GenericTerm) Util.propertiesHolder(exampleForm).getProperty(Util.symbol(keySort));
				GenericTerm[] subs = {keyUse, keySort};
				GenericTerm freeContent = factory.newConstruction(factory.makeConstructor(Builder.FUNCTION_SORT_SYMBOL), GenericTerm.NO_BINDS, subs);
				List<Term> freeList = new ArrayList<Term>(1);
				freeList.add(freeContent);
				options.put(Builder.FREE_OPTION_SYMBOL, freeList);
			}
			else if (keyFreeVarIndex != -1)
			{
				Variable v = newPattern.sub(keyFreeVarIndex).variable();
				propertySet.setProperty(key, newValue); //propertySet.setProperty(v, newValue);
				GenericTerm keyUse = factory.newVariableUse(v);
				keySort = exampleForm.sub(keyFreeVarIndex);
				if (position == -1)
					valueSort = (GenericTerm) Util.propertiesHolder(exampleForm).getProperty(Util.symbol(keySort));
				else
				{
					// TODO: find valueSort from property set associated with newPattern.sub(position) !!
					valueSort = null;
				}
				GenericTerm[] subs = {keyUse, keySort};
				GenericTerm freeContent = factory.newConstruction(factory.makeConstructor(Builder.FUNCTION_SORT_SYMBOL), GenericTerm.NO_BINDS, subs);
				List<Term> freeList = new ArrayList<Term>(1);
				freeList.add(freeContent);
				options.put(Builder.FREE_OPTION_SYMBOL, freeList);
			}
			else if (keyMetaPosition != -1)
			{
//				if (exampleForm.toString().contains("FT-item-intersect2-record"))
//					warning("karma");
				propertySet.removeProperty(key);
				propertySet.setProperty("#" + keyMetaPosition, newValue);
				keySort = exampleForm.sub(keyMetaPosition).stripProperties();
				valueSort = (GenericTerm) Util.propertiesHolder(exampleForm).getProperty(Util.symbol(keySort));
				if (valueSort == null)
				{
					// Desperate repair of uninstatiated sort variable.
					Term oldValue = Util.getProperty(examplePattern, key);
					valueSort = SortUtil.sortOf(factory, oldValue);
				}
			}
			else if (keyConstructorName != null)
			{
				//propertySet.setProperty(keyConstructorName, newValue);
				propertySet.setProperty(key, newValue);
				keySort = factory.newForm(CRS.STRING_SORT, GenericTerm.NO_TERMS); // TODO: non-string constant keys
				if (position == -1)
					valueSort = (GenericTerm) Util.propertiesHolder(exampleForm).getProperty(CRS.STRING_SORT);
				else
				{
					Set<Pair<Term,Term>> sfs = factory.formsOf(keyConstructorName);
					if (sfs != null && sfs.size() == 1)
					{
						Pair<Term,Term> sf = sfs.iterator().next();
						Term f = sf.tail(); // form
						valueSort = (GenericTerm) Util.getProperty(f, CRS.STRING_SORT);
					}
					if (valueSort == null)
					{
						Term s = exampleForm.sub(0);
						Map<String,Term> msf = factory.sortsetFor(Util.symbol(s));
						valueSort = (GenericTerm) msf.get(CRS.STRING_SORT);
					}
				}
			}
			else
			{
				//warning("bad karma: split-by-key with no key?!?");
			}
			
			// Declare existing free variables in properties
			if (currentRule.four() != null)
			{
				List<Term> free = currentRule.four().get(Builder.FREE_OPTION_SYMBOL);
				if (free != null)
				{
					List<Term> newFree = options.get(Builder.FREE_OPTION_SYMBOL);
					if (newFree == null)
					{
						newFree = new ArrayList<Term>(free);
						options.put(Builder.FREE_OPTION_SYMBOL, newFree);
					}
					else
						newFree.addAll(free); // TODO: check for duplicate?
				}
			}
			
			// Set compileType attribute.
			List<Term> compileTypes = new ArrayList<Term>();
			compileTypes.add(factory.parse("Contract"));
			options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);
			
			// Record rule.
			ret.add(new StandardizedRule(factory, newPattern, newContractum, factory.makeConstructor(currentRule.getName().symbol()
			        + "$" + newPattern.constructor().symbol()), options));
			{
				// Compute and record sort declaration!
				Term oldForm = getForm(examplePattern, newsymbol.symbol(), sortsSave, true);
				GenericTerm[] newFormSub = new GenericTerm[oldForm.arity() + 1];
				Variable[][] newFormBinders = new Variable[oldForm.arity() + 1][];
				for (int i = 0; i < oldForm.arity(); ++i)
				{
					newFormBinders[i] = oldForm.binders(i);
					newFormSub[i] = (GenericTerm) oldForm.sub(i);
				}
				newFormBinders[oldForm.arity()] = GenericTerm.NO_BIND;
				newFormSub[oldForm.arity()] = valueSort;
				Term form = factory.newConstruction(newsymbol, newFormBinders, newFormSub);
				factory.setSortForm(sort, null, form, true, true);
			}
			
			// Create rules that match on the cases for the property now in the first position.
			for (StandardizedRule rule : withKey)
			{
				GenericTerm pattern = rule.one();
				final int patternArity = pattern.arity();
				Term patternSort = sortGet(sortsSave, pattern);
				GenericTerm patternForm = getForm(pattern, null, sortsSave, true);
				PropertiesHolder ph = (position == -1 ? Util.propertiesHolder(pattern) : Util.propertiesHolder(pattern.sub(position)));
				GenericTerm value = (GenericTerm) ph.getProperty(key);
				sortPut(sortsSave, value, valueSort);
				
				if (position == -1)
	                pattern.removeProperty(key);
                else
	                pattern.sub(position).removeProperty(key);
				
				GenericTerm[] subs = new GenericTerm[newContractum.arity()];
				Variable[][] binds = new Variable[newContractum.arity()][];
				GenericTerm[] subsSort = new GenericTerm[newContractum.arity()];
				for (int i = 0; i < patternArity; i++)
				{
					binds[i] = pattern.binders(i);
					subs[i] = pattern.sub(i);
					// ...also update the sorts...
					Map<Variable,Term> bindsSort = new HashMap<Variable, Term>();
					for (int j = 0; j < binds[i].length; ++j)
					{
						Variable bij = binds[i][j];
						Variable patternBij = patternForm.binders(i)[j];
						GenericTerm bijSort = (GenericTerm) Util.propertiesHolder(patternForm.sub(i)).getProperty(patternBij);
						bindsSort.put(bij, bijSort);
					}
					if (patternForm.sub(i) == null)
						;//factory.message("bad karma: null subform");
					else
						subsSort[i] = Util.makePropertiesConstraintsWrapper(patternForm.sub(i).stripProperties(), null, null, bindsSort, null);
				}
				subs[patternArity] = value;
				if (position == -1)
					binds[patternArity] = new Variable[0];
				else
					binds[patternArity] = pattern.binders(0);
				subsSort[patternArity] = valueSort;
				GenericTerm alteredPattern = factory.newConstruction(factory.makeConstructor(newsymbol), binds, subs);
				GenericTerm alteredForm = factory.newConstruction(factory.makeConstructor(newsymbol), binds, subsSort);
				if (pattern instanceof PropertiesConstraintsWrapper)
				{
					PropertiesConstraintsWrapper pcw =  Util.makePropertiesConstraintsWrapper(alteredPattern, null, null, null, null);
					pcw.setProperties((PropertiesConstraintsWrapper) pattern);
					alteredPattern = pcw;
				}
				if (Util.hasPropertyRef(exampleForm) && !Util.hasProperties(exampleForm))
					System.out.println("ISSUE??");
					
				if (Util.hasProperties(exampleForm))
				{
					alteredForm = alteredForm.wrapWithPropertiesOf(exampleForm); // we cannot use exampleForm any more!
				}
				sortRemove(sortsSave, pattern);
				sortPut(sortsSave, alteredPattern, patternSort);
				rule.setOne(alteredPattern);
				factory.setSortForm(patternSort, null, alteredForm, true, true);
			}
			
			// continue splitting with these altered rules
			append(additionalRules, dispatchify(withKey, sortsSave));
		}
		
		append(ret, additionalRules);
	}

	/**
	 * Given a set of rules, where the first position in the pattern is always
	 * either a bound variable or a term with a property set, create rules for
	 * the case where it is a variable, and for the cases where it is not.
	 * @param ret All new rules will be added to ret.
	 * @param relevantRules Contains the rules we should work with, in the
	 *   form <contractum,pattern>
	 * @param numberSymbols Gives the index where we should start counting rules,
	 * 	 and is modified to reflect rules which were added
	 * @throws CRSException possible result of giving an error
	 */
	private void splitByPropertySet(List<StandardizedRule> ret,
									Set<StandardizedRule> relevantRules,
									Map<Object,Term> sortsSave) throws CRSException
	{
		if (factory.verbosity() > 2)
			factory.message("- splitting "+Util.symbol(relevantRules.iterator().next().getPattern())+" rules by VARIABLE/PROPERTY");

		List<StandardizedRule> additionalRules = new LinkedList<StandardizedRule>();
		
		// check out all the forms which are used
		MultiMap<Integer,StandardizedRule> splitRules = new HashMultiMap<Integer,StandardizedRule>();
			// the keys are either integers representing bound variables,
			// or -2 to denote the use of a property set
		
		for (StandardizedRule pair : relevantRules)
		{
			Term pattern = pair.one();
			Term arg = pattern.sub(0);
			if (arg.kind() == Kind.VARIABLE_USE)
			{
				int num = -1;
				for (int i = 0; i < pattern.binders(0).length; i++)
					if (arg.variable() == pattern.binders(0)[i])
						num = i;
				Integer in = new Integer(num);
				splitRules.multiAdd(in, pair);
			}
			else splitRules.multiAdd(new Integer(-2), pair);
		}

		int numberBinders = relevantRules.iterator().next().one().binders(0).length;
		
		// do the splitting for the bound variables
		for (int i = 0; i < numberBinders; i++)
		{
			Integer ii = new Integer(i);
			if (!splitRules.multiContainsKey(ii)) continue;
			Set<StandardizedRule> rules = splitRules.get(ii);
			StandardizedRule firstRule = rules.iterator().next();
			GenericTerm examplePattern = firstRule.one();
			Constructor symbol = examplePattern.constructor();
			Constructor newsymbol = env.internalSymbol(examplePattern.constructor());

			// create the rule {#Γ} F[x1...xn.xi,#1,...,#m] → {#Γ} Fj[#1,...,#m]
			{
				GenericTerm pattern = createFromExample(examplePattern, symbol.symbol(), false, 0, false, false, null);
				pattern.replaceSub(0, pattern.binders(0), factory.newVariableUse(pattern.binders(0)[i]));
				GenericTerm contractum = createFromExample(examplePattern, newsymbol.symbol(), true, 1, false, false, null);
				ret.add(new StandardizedRule(factory, pattern, contractum, factory.makeConstructor(firstRule.getName().symbol()
				        + "$" + pattern.constructor().symbol()), null));
				//TODO: sort??
			}
			
			// remove the first argument of the relevant rules
			for (StandardizedRule rule : rules)
			{
				GenericTerm pattern = rule.one();
				final int patternArity = pattern.arity();
				Variable[][] binders = new Variable[patternArity-1][];
				GenericTerm[] subs = new GenericTerm[patternArity-1];
				for (int j = 1; j < patternArity; j++)
				{
					binders[j-1] = pattern.binders(j);
					subs[j-1] = pattern.sub(j);
				}
				GenericTerm newPattern = factory.newConstruction(pattern.constructor(), binders, subs);
				if (pattern instanceof PropertiesConstraintsWrapper)
					newPattern = Util.makePropertiesConstraintsWrapper(newPattern, null, ((PropertiesConstraintsWrapper) pattern).getLocalProperties(), null, null);
				sortPut(sortsSave, newPattern, sortGet(sortsSave, pattern));
				rule.setOne(newPattern);
			}
			
			// declare the new symbol
			examplePattern = rules.iterator().next().one();
			Term sort = sortGet(sortsSave, examplePattern);
			Term form = getForm(examplePattern, newsymbol.symbol(), sortsSave, true);
			factory.setSortForm(sort, null, form, true, false);

			// continue splitting with these altered rules
			append(additionalRules, dispatchify(rules, sortsSave));
		}
		
		// split the remainder, where the identifying property is that the first argument has a property set
		Set<StandardizedRule> remainingRules = splitRules.get(new Integer(-2));
		StandardizedRule firstRule = remainingRules.iterator().next();
		GenericTerm examplePattern = firstRule.one();
		Constructor symbol = examplePattern.constructor();
		Constructor newsymbol = env.internalSymbol(examplePattern.constructor());
		
		// create the rule F[x1...xn.{#Δ[x1,...,xn]} #Z[x1,...,xn]] → Fj[x1...xn.{#Δ[x1,...,xn]} #Z[x1,...,xn]]
		GenericTerm pattern = createFromExample(examplePattern, symbol.symbol(), false, 0, false, false, null);
		GenericTerm[] args = new GenericTerm[pattern.binders(0).length];
		for (int i = 0; i < args.length; i++)
			args[i] = factory.newVariableUse(pattern.binders(0)[i]);
		GenericTerm reference = standardPatternMetaApplication("#Δ", args);
		PropertiesConstraintsWrapper wrapper = Util.makePropertiesConstraintsWrapper((GenericTerm) pattern.sub(0), null, null, null, null);
		wrapper.setProperty(REFERENCE, reference);
		pattern.replaceSub(0, pattern.binders(0), wrapper);
		GenericTerm contractum = createFromExample(examplePattern, env.internalSymbol(pattern.constructor()).symbol(), false, 0, false, false, null);
		contractum.replaceSub(0, pattern.binders(0), wrapper.copy(false, LinkedExtensibleMap.EMPTY_RENAMING));
		ret.add(new StandardizedRule(factory, pattern, contractum, factory.makeConstructor(firstRule.getName().symbol() + "$" + pattern.constructor().symbol()), null));
		
		// declare the new symbol
		Term sort = sortGet(sortsSave, examplePattern);
		Term form = getForm(examplePattern, newsymbol.symbol(), sortsSave, true);
		factory.setSortForm(sort, null, form, true, false);
		
		// altering the remaining rules is unnecessary, since the reduct has exactly the same form as the original
		// just dispatchify them and be done with it!
		append(additionalRules, dispatchify(remainingRules, sortsSave));
		
		// append all the new rules to the end of ret; this is done by means of additionalRules
		// rather than immediately to make sure the rules are in a neat order
		append(ret, additionalRules);
	}
	
	/**
	 * Given a set of rules, where the first position in the pattern always as 
	 * the following form:
	 * <pre>x0..xi..yn.{#Γ}#[ ... ]</pre>
	 * Create rules for each of the two cases where the first binding variable are explicitly absent or present.
	 * 
	 * @param ret All new rules will be added to ret.
	 * @param relevantRules Contains the rules we should work with, in the
	 *   form <contractum,pattern>
	 * @param numberSymbols Gives the index where we should start counting rules,
	 * 	 and is modified to reflect rules which were added
	 * @param splitWhat 0 for splitting argument 0, 1 for splitting the argument 0 with a property set, and
	 *                  2 for splitting the property set
	 * @param x position of the binder being considered
	 * @param sortsSave the sorts
	 * @throws CRSException possible result of giving an error
	 */
	private void splitByBinderPresence(List<StandardizedRule> ret,
									   Set<StandardizedRule> relevantRules,
									   int splitWhat, int x,
									   Map<Object,Term> sortsSave) throws CRSException
	{
		if (factory.verbosity() > 2)
			factory.message("- splitting "+Util.symbol(relevantRules.iterator().next().getPattern())+" rules by BINDER("+splitWhat+","+x+")");

		// the usual preparations (see also the other splitBy functions)
		List<StandardizedRule> additionalRules = new LinkedList<StandardizedRule>();

		// split in those rules where x is absent from the first argument, and where x is definitely present
		
		// For instance, when splitWhat == 0:
		//    F[x y.#[x, y]] is a rule with binder, as the binding variable occurs in #
		//    F[x y.#[y]] is not a rule with binder, as x does not occurs in #. Only the first binder is considered.
		
		Set<StandardizedRule> rulesWithBinder = new HashSet<StandardizedRule>();
		Set<StandardizedRule> rulesWithoutBinder = new HashSet<StandardizedRule>();
		for (StandardizedRule relevantRule : relevantRules)
		{
			GenericTerm pattern = relevantRule.one();
			Set<String> certain = new HashSet<String>();
			Set<String> possible = new HashSet<String>();
			Term term = pattern.sub(0);
			if (splitWhat == 2)
				term = Util.propertiesHolder(term).getProperty(REFERENCE);
			
			getBoundOccurrences(pattern.sub(0), certain, possible, splitWhat == 1);
			
			if (certain.contains(pattern.binders(0)[x].name()))
				rulesWithBinder.add(relevantRule);
			else
				rulesWithoutBinder.add(relevantRule);
		}
		
		if (!rulesWithoutBinder.isEmpty())
		{
			// Deal with rules where the given binder must be absent:
			// Add generic dispatch rule that matches and removes excluded binder, and proceed without the restriction.
			StandardizedRule rule1 = rulesWithoutBinder.iterator().next();
			GenericTerm examplePattern = rule1.one();
			Set<Integer> absent = new HashSet<Integer>();
			absent.add(x);
			StandardizedRule dispatchRule = binderForceRule(null, absent, examplePattern, rule1.getName().symbol(), splitWhat, sortsSave); 
			ret.add(dispatchRule);
			
			// Now update all the rules to proceed from the result of dispatchRule.
			for (StandardizedRule rule : rulesWithoutBinder)
			{
				GenericTerm oldPattern = rule.one();
				GenericTerm newPattern = createCopy(dispatchRule.two(), sortsSave); // pattern is modeled after result of dispatch...
				// Update first argument with proper binders after dispatch.
				if (splitWhat == 0)
				{
					// - if binder is fully absent update binders to omit it as generated by dispatcher. 
					final Variable[] binds = new Variable[newPattern.binders(0).length];
					for (int i = 0, j = 0; i < oldPattern.binders(0).length; i++)
						if (i != x)
							binds[j++] = oldPattern.binders(0)[i];
					newPattern.replaceSub(0, binds, oldPattern.sub(0));
				}
				else
				{
					// - binder partially absent from properties  so kept by dispatcher - relax absence restriction.
					Variable omitted = oldPattern.binders(0)[x];
					GenericTerm relaxed = relaxAbsence(oldPattern.sub(0), omitted);
					newPattern.replaceSub(0, oldPattern.binders(0), relaxed);
				}
				// Reuse all other arguments from original pattern.
				for (int i = 1; i < newPattern.arity(); ++i)
					newPattern.replaceSub(i, oldPattern.binders(i), oldPattern.sub(i));
				rule.setOne(newPattern);
				Term sort = sortGet(sortsSave, oldPattern);
				sortPut(sortsSave, newPattern, sort);
			}
			// Recursively process and add absence based rules.
			append(additionalRules, dispatchify(rulesWithoutBinder, sortsSave));
		}

		if (!rulesWithBinder.isEmpty())
		{
			// Deal with the rules where the given binder is certainly present:
			// add the new rule, where the left-hand side has a !x variable, and the right-hand side does not (but is otherwise the same, save for the symbol)
			StandardizedRule rule1 = rulesWithBinder.iterator().next();
			GenericTerm examplePattern = rule1.one();
			Set<Integer> present = new HashSet<Integer>();
			present.add(new Integer(x));
			StandardizedRule dispatchRule = binderForceRule(present, null, examplePattern, null, splitWhat, sortsSave); 
			ret.add(dispatchRule);

			// remove the presence requirement from the given rules
			for (StandardizedRule rule : rulesWithBinder)
			{
				boolean ok = rule.one().sub(0).kind() == Kind.META_APPLICATION;
				if (splitWhat == 0 && Standardizer.hasPropertySet(rule.one().sub(0))) ok = false;
				if (ok) removePresenceRequirement(rule.one().sub(0), rule.one().binders(0)[x], splitWhat != 1);
				else
				/**
				 * The rules have been expanded, which probably means that the !x has been
				 * split over the various places where it could be, which means that the
				 * idea above is most likely not correct.
				 * This should actually not happen without the user TRYING to do obnoxious
				 * things, like a $[NotMatch,...] not-matching on a meta-variable that does
				 * not get all expected arguments.  Still, it -could- happen.
				 * 
				 * We cannot leave the !x there: doing so would lead to an incomplete set
				 * of rules, and since "the term contains x" is not a stable property (an
				 * internal reduction could remove x) the output of the dispatchify
				 * process might not lead to an answer -- we lose confluence.  We could
				 * forbid it altogether, but the following solution works nicer when nothing
				 * too evil is done:
				 * 
				 * - remove the "presence of x" requirement in all meta-variables of
				 *   these rules; this likely leads to overlaps in the patterns
				 * - check for overlaps in the patterns; if two patterns overlap, and
				 *   A instantiates B, then check whether their contractums are equal
				 *   (taking the instantiating substitution into account); the
				 *   functionality for this already exists, except that overlaps and
				 *   instantiates make certain assumptions about their second argument
				 *   * if the patterns overlap but neither instantiates the other,
				 *     put them aside; there *should* be another pattern which they
				 *     both instantiate, and if such a pattern is not found, give an
				 *     error afterwards
				 *   * if A instantiates B but their outputs are different, give an
				 *     error, since there are multiple presence checks on the same
				 *     bound variable
				 *   * either way, if A instantiates B, throw away A!
				 * - the remaining rules do not overlap with each other, contain all
				 *   the previous cases and have no presence requirement on x anymore
				 *   
				 * TODO!!
				 */
					warning("completed rule " + print(rule.one()) + " → " +
						print(rule.two()) + " handles presence / absence requirements " +
						"in a way that makes dispatchifying in a completely correct / " +
						"confluent way impossible.");
			}
			
			// declare the new symbol
//			examplePattern = rulesWithBinder.iterator().next().one();
//			Term sort = sortGet(sortsSave, examplePattern);
//			Term form = getForm(examplePattern, env.internalSymbol(examplePattern.constructor()).symbol(), sortsSave, true);
//			factory.setSortForm(sort, null, form, true, false);

			// and dispatchify the remaining rules!
			append(additionalRules, dispatchify(rulesWithBinder, sortsSave));
		}
		
		// append all the new rules to the end of ret; this is done by means of additionalRules
		// rather than immediately to make sure the rules are in a neat order
		append(ret, additionalRules);
	}
	
	/** Make sure all meta-applications include the omitted variable. */
	private GenericTerm relaxAbsence(GenericTerm term, Variable omitted)
    {
		// Update meta-applications embedded in properties.
		PropertiesHolder ph = Util.propertiesHolder(term);
		Map<String, Term> relaxedProps = new HashMap<String, Term>();
		for (String key : ph.propertyNames())
		{
			Term value = ph.getProperty(key);
			value = relaxAbsence((GenericTerm) value, omitted);
			try
            {
	            ph.setProperty(key, value);
            }
            catch (CRSException e)
            {}
		}
		// Update "usual" terms.
		switch (term.kind())
		{
			case META_APPLICATION : {
				boolean needsOmitted = true;
				for (int i = 0; i < term.arity(); ++i)
					if (term.sub(i).variable() == omitted)
						needsOmitted = false;
				if (needsOmitted)
				{
					GenericTerm[] newArgs = new GenericTerm[term.arity()+1];
					for (int i = 0; i < term.arity(); ++i)
						newArgs[i] = term.sub(i);
					newArgs[term.arity()] = factory.newVariableUse(omitted);
					term = standardPatternMetaApplication(term.metaVariable(), newArgs);
					term = Util.makePropertiesConstraintsWrapper(term,null, relaxedProps, null, null);
				}
				return term;
			}		
			case CONSTRUCTION : {
				for (int i = 0; i < term.arity(); ++i)
					term.replaceSub(i, term.binders(i), relaxAbsence(term.sub(i), omitted));
				return term;
			}
			case VARIABLE_USE : {
				return term;
			}
		}
		return null; // unreachable
    }

	/** Given a pattern in which v sometimes occurs in the form !v, remove the ! from around v everywhere. */
	private void removePresenceRequirement(GenericTerm pattern, Variable v, boolean includePS)
	{
		if (pattern == null) return;
		
		for (int i = 0; i < pattern.arity(); i++)
			removePresenceRequirement(pattern.sub(i), v, true);
		
		PropertiesHolder A = Util.propertiesHolder(pattern);
		if (A != null && includePS) for (String name : A.propertyNames())
			removePresenceRequirement((GenericTerm) A.getProperty(name), v, true);
		
		if (pattern.kind() == Kind.META_APPLICATION)
			for (int i = 0; i < pattern.arity(); i++)
				if (pattern.sub(i).kind() == Kind.CONSTRUCTION && pattern.sub(i).sub(0).variable() == v)
					((GenericTerm) pattern).replaceSub(i, null, pattern.sub(i).sub(0));
	}
	
	/**
	 * Helping function for splitByBinderPresence: creates the rule which
	 * enforces absence/presence of a given number of variables.
	 * For extendability, this is written in such a way that multiple variables
	 * can be given as absent / present, even though it is currently only used
	 * for one variable at a time.
	 * @param present The indexes of those bound variables which must be present
	 * 	 (may be null).
	 * @param absent The indexes of those bound variables which must be absent
	 *   (may be null).
	 * @param example An example term, such that terms of that form should be
	 *   reduced.
	 * @param ruleName for messages
	 * @param splitWhat 0 if the first parameter of the created rules should be
	 *   a meta-variable (with absence/presence of the given variable enforced),
	 *   1 if it should be a meta-variable with a property set (where the given
	 *   variables are all non-compulsary-present in the given property set, and
	 *   absence/presence is enforced only in the meta-variable), or 2 if it is
	 *   a meta-variable with property set where absence/presence is enforced
	 *   only in the property set.
	 * @param sortSave 
	 * @return a pair <l,r> for a new rule Fi[...] → Fj
	 * @throws CRSException possible result of giving an error
	 */
	private StandardizedRule binderForceRule(Set<Integer> present, Set<Integer> absent, GenericTerm example, String ruleName, int splitWhat, Map<Object, Term> sortsSave) throws CRSException
	{
		// Start pattern (the first argument will be massaged below).
		final String newPatternSymbol = Util.symbol(example);
		GenericTerm pattern = createFromExample(example, newPatternSymbol, false, 0, false, false, null);
		
		// Start contractum (to be massaged below).
		final Constructor newContractumConstructor = env.internalSymbol(example.constructor());
		GenericTerm contractum = createFromExample(example, newContractumConstructor.symbol(), false, 0, false, false, null);

		// Accumulate options for new rule.
		Map<String,List<Term>> options = new HashMap<String,List<Term>>();
		List<Term> weaks = new ArrayList<Term>();
		options.put(Builder.WEAK_OPTION_SYMBOL, weaks);
		List<Term> compileTypes = new ArrayList<Term>();
		options.put(Builder.COMPILE_TYPE_OPTION_SYMBOL, compileTypes);
		
		// Get form for manipulation.
		GenericTerm contractumForm = getForm(example, newContractumConstructor.symbol(), sortsSave, true);
		
		// in the examples, suppose absent = x1, present = x2
		
		// no property sets in the way: make the rule F[x0 x1 x2.#0[x0,!x2],...] → F'[x0 x2.#0[x0,x2],...]
		if (splitWhat == 0)
		{
			GenericTerm[] args1 = new GenericTerm[pattern.sub(0).arity() - (absent == null ? 0 : absent.size())];
			GenericTerm[] args2 = new GenericTerm[args1.length];
			Variable[] binds2 = new Variable[args1.length];
			Variable[] binds2form = new Variable[args1.length];
			for (int i = 0, j = 0; i < pattern.sub(0).arity(); i++)
			{
				Integer num = new Integer(i);
				if (absent != null && absent.contains(num))
				{
					contractumForm.sub(0).removeProperty(contractumForm.binders(0)[i]);
					continue;
				}
				args1[j] = pattern.sub(0).sub(i);
				if (present != null && present.contains(num))
				{
					GenericTerm[] subs = new GenericTerm[1];
					subs[0] = args1[j];
					args1[j] = factory.newConstruction(factory.makeConstructor(PRESENT), null, subs);
				}
				args2[j] = contractum.sub(0).sub(i);
				binds2[j] = contractum.binders(0)[i];
				binds2form[j] = contractumForm.binders(0)[i];
				j++;
			}
			pattern.replaceSub(0, pattern.binders(0), standardPatternMetaApplication("#0", args1));
			contractum.replaceSub(0, binds2, standardPatternMetaApplication("#0", args2));
			contractumForm.replaceSub(0, binds2form, contractumForm.sub(0));
			compileTypes.add(factory.parse("BinderDispatch"));
			if (absent != null && absent.size() > 0)
				weaks.add(standardPatternMetaApplication("#0", GenericTerm.NO_TERMS));
		}
		
		// no property set restrictions, only the naked term is restricted:
		// make the rule F[x0 x1 x2.{#Γ[x0,x1,x2]} #0[x0,!x2]] → F'[x0 x1 x2.{#Γ[x0,x1,x2]} #0[x0,x2]]
		else if (splitWhat == 1)
		{
			GenericTerm[] refargs1 = new GenericTerm[pattern.sub(0).arity()];
			GenericTerm[] refargs2 = new GenericTerm[pattern.sub(0).arity()];
			GenericTerm[] args1 = new GenericTerm[pattern.sub(0).arity() - (absent == null ? 0 : absent.size())];
			GenericTerm[] args2 = new GenericTerm[args1.length];
			for (int i = 0, j = 0; i < pattern.sub(0).arity(); i++)
			{
				Integer num = new Integer(i);
				refargs1[i] = pattern.sub(0).sub(i);
				refargs2[i] = contractum.sub(0).sub(i);
				if (absent != null && absent.contains(num)) continue;
				args1[j] = factory.newVariableUse(pattern.binders(0)[i]);
				if (present != null && present.contains(num))
				{
					GenericTerm[] subs = new GenericTerm[1];
					subs[0] = args1[j];
					args1[j] = factory.newConstruction(factory.makeConstructor(PRESENT), null, subs);
				}
				args2[j] = factory.newVariableUse(contractum.binders(0)[i]);
				j++;
			}
			pattern.replaceSub(0, pattern.binders(0), Util.makePropertiesConstraintsWrapper(standardPatternMetaApplication("#0", args1), null, null, null, null));
			((PropertiesConstraintsWrapper) pattern.sub(0)).setProperty(REFERENCE, standardPatternMetaApplication("#Δ", refargs1));
			contractum.replaceSub(0, contractum.binders(0), Util.makePropertiesConstraintsWrapper(standardPatternMetaApplication("#0", args2), null, null, null, null));
			((PropertiesConstraintsWrapper) contractum.sub(0)).setProperty(REFERENCE, standardPatternMetaApplication("#Δ", refargs2));
			compileTypes.add(factory.parse("BinderDispatch"));
			if (absent != null && absent.size() > 0)
				weaks.add(standardPatternMetaApplication("#0", GenericTerm.NO_TERMS));
		}
		
		// presence restrictions are restrictions only on the property set
		// make the rule F[x0,x1,x2.{#Γ[x0,!x2]} #0[x0,x1,x2]] → F'[x0,x1,x2.{#Γ[x0,x2]} #0[x0,x1,x2]]
		else if (splitWhat == 2)
		{
			GenericTerm[] refargs1 = new GenericTerm[pattern.sub(0).arity() - (absent == null ? 0 : absent.size())];
			GenericTerm[] refargs2 = new GenericTerm[refargs1.length];
			for (int i = 0, j = 0; i < pattern.sub(0).arity(); i++)
			{
				Integer num = new Integer(i);
				if (absent != null && absent.contains(num)) continue;
				refargs1[j] = factory.newVariableUse(pattern.binders(0)[i]);
				if (present != null && present.contains(num))
				{
					GenericTerm[] subs = new GenericTerm[1];
					subs[0] = refargs1[j];
					refargs1[j] = factory.newConstruction(factory.makeConstructor(PRESENT), null, subs);
				}
				refargs2[j] = factory.newVariableUse(contractum.binders(0)[i]);
				j++;
			}
			pattern.replaceSub(0, pattern.binders(0), Util.makePropertiesConstraintsWrapper((GenericTerm) pattern.sub(0), null, null, null, null));
			((PropertiesConstraintsWrapper) pattern.sub(0)).setProperty(REFERENCE, standardPatternMetaApplication("#Δ", refargs1));
			contractum.replaceSub(0, contractum.binders(0), Util.makePropertiesConstraintsWrapper((GenericTerm) contractum.sub(0), null, null, null, null));
			((PropertiesConstraintsWrapper) contractum.sub(0)).setProperty(REFERENCE, standardPatternMetaApplication("#Δ", refargs2));
			compileTypes.add(factory.parse("BinderDispatch"));
			if (absent != null && absent.size() > 0)
				weaks.add(standardPatternMetaApplication("#Δ", GenericTerm.NO_TERMS));
		}
		
		// Add compile type
		Term sort = sortGet(sortsSave, example);
		sortPut(sortsSave, pattern, sort);
		sortPut(sortsSave,contractum, sort);
		factory.setSortForm(sort, null, contractumForm, true, false);
		
		return new StandardizedRule(factory, pattern, contractum,  factory.makeConstructor(ruleName + "$" + pattern.constructor()), options);
	}

	// ========== miscellaneous, helping functions ========== //

	/**
	 * Returns the forms F[ι1,...,ιn] : κ where F is the given constructor and
	 * κ the given sort; κ must be an instantiation of an actual form for which
	 * F is defined, and the returned form will be its instantiation.
	 * The result uses parts of the forms saved in the factory (constructors and
	 * variables only).
	 * @param sort to get form of (κ) 
	 * @param symbol to get form of (F)
	 */
	public GenericTerm formOf(Term sort, String symbol) throws CRSException
	{
		Set<Pair<Term, Term>> forms = factory.formsOf(symbol);
		for (Pair<Term,Term> pair : forms)
		{
			Map<Variable,Term> theta = new HashMap<Variable,Term>();
			if (Unifier.instantiates(sort, pair.head(), theta, factory))
			{
				Term form = pair.tail();
				GenericTerm[] subs = new GenericTerm[form.arity()];
				Variable[][] binds = new Variable[form.arity()][];
				for (int i = 0; i < subs.length; i++)
				{
					binds[i] = form.binders(i);
					Term a = Unifier.apply(form.sub(i), theta, factory);
					if (a instanceof GenericTerm) subs[i] = (GenericTerm) a;
					else subs[i] = Unifier.repeat_apply(a, new HashMap<Variable,Term>(), factory);
					if (binds.length > 0)
					{
						Map<Variable,Term> varSorts = new HashMap<Variable,Term>();
						for (int j = 0; j < binds[i].length; j++)
						{
							Term originalSort = Util.propertiesHolder(form.sub(i)).getProperty(binds[i][j]);
							varSorts.put(binds[i][j], Unifier.apply(originalSort, theta, factory));
						}
						subs[i] = new PropertiesConstraintsWrapper(subs[i], null, null, varSorts, null);
					}
				}
				return factory.newConstruction(form.constructor(), binds, subs);
			}
		}
		return null;
	}

	/**
	 * This appends the two given lists to each other.
	 * For whatever obscure reason this does not seem to be in-built functionality
	 * of List, causing this to be O(length of second list) rather than O(1)
	 * as it should be.
	 * @param <T>
	 */
	private <T> void append(List<T> l1, List<T> l2)
	{
		if (l2 != null)
		{
			Iterator<T> it = l2.iterator();
			while (it.hasNext()) l1.add(it.next());
		}
	}
	
	private GenericTerm subterm(GenericTerm term, List<Integer> position)
	{
		if (position.isEmpty()) return term;
		return subterm((GenericTerm) term.sub(position.get(0)), position.subList(1, position.size()));
	}
	
	/**
	 * Returns a string representation of the given sort or form, which
	 * is the same for "equal" declarations (modulo renaming of sort
	 * variables).  This ignores any sort sets.
	 * @param term a sort or form
	 * @param vars the sort variables encountered so far, and their naming
	 * 	 (these should have names _a0, ..., _an, with n = vars.size()-1)
	 * @return a suitable string representation
	 */
	private static String printSortFormModuloVariables(Term term, Map<Variable,String> vars)
	{
		if (term.kind() == Kind.VARIABLE_USE)
		{
			Variable x = term.variable();
			if (!vars.containsKey(x)) vars.put(x, "a_" + vars.size());
			return vars.get(x);
		}
		if (term.kind() == Kind.CONSTRUCTION)
		{
			if (Factory.SORT_VAR.equals(Util.symbol(term)))
				return printSortFormModuloVariables(term.sub(0), vars);
			String ret = Util.symbol(term);
			if (term.arity() == 0) return ret;
			for (int i = 0; i < term.arity(); i++)
			{
				if (i == 0) ret += "["; else ret += ",";
				if (term.binders(i).length != 0)
				{
					String sortset = "{";
					for (int j = 0; j < term.binders(i).length; j++)
					{
						ret += "x_" + j + ".";
						sortset += "x_" + j + ":" +
							printSortFormModuloVariables(Util.propertiesHolder(term.sub(i)).getProperty(term.binders(i)[j]), vars);
					}
					ret += sortset + "}";
				}
				ret += printSortFormModuloVariables(term.sub(i), vars);
			}
			return ret + "]";
		}
		return "ERR"; // should be a sort or form!
	}
	
	/**
	 * Returns a string representation of the given sort/form combination
	 * (which should uniquely identify a constructor, even from among
	 * overloaded constructors).
	 */
	public static String printDeclarationModuloVariables(Term sort, Term form)
	{
		Map<Variable,String> varmap = new HashMap<Variable,String>();
		return printSortFormModuloVariables(form, varmap) + " :: " +
			   printSortFormModuloVariables(sort, varmap);
	}
	
	/** only used for debugging information, should be removed! */
	String print(Term term)
	{
		String ret = "";
		
		if (term == null) return "??";
		
		if (term instanceof PropertiesConstraintsWrapper)
		{
			ret += "{ ";
			PropertiesConstraintsWrapper A = (PropertiesConstraintsWrapper) term;
			if (A.getProperty(REFERENCE) != null)
			{
				Term reference = A.getProperty(REFERENCE);
				ret += reference.metaVariable();
				if (reference.arity() > 0)
				{
					for (int i = 0; i < reference.arity(); i++)
						ret += (i == 0 ? "[" : ", ") + print(reference.sub(i));
					ret += "]";
				}
				ret += " ; ";
			}
			for (String key : A.propertyNames())
			{
				if (key.equals(REFERENCE)) continue;
				if (A.getProperty(key) == null)	ret += "¬" + key + " ; ";
				else ret += key + " : " + print((GenericTerm) A.getProperty(key)) + " ; ";
			}
			for (Variable key : A.propertyVariables())
			{
				if (A.getProperty(key) == null) ret += "¬" + key + " ; ";
				else ret += key + " : " + print((GenericTerm) A.getProperty(key)) + " ; ";
			}
			for (String key : A.propertyMetaVariables())
			{
				if (A.getMetaProperty(key) == null) ret += "¬" + key + " ; ";
				else ret += key + " : " + print((GenericTerm) A.getMetaProperty(key)) + " ; ";
			}
			if (ret.length() > 2)
				ret = ret.substring(0, ret.length()-2);
			ret += "} ";
		}
		
		if (term.kind() == Kind.VARIABLE_USE)
			return ret + term.variable().name();
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			ret += term.metaVariable();
			if (term.arity() > 0)
			{
				for (int i = 0; i < term.arity(); i++)
					ret += (i == 0 ? "[" : ", ") + print(term.sub(i));
				ret += "]";
			}
			return ret;
		}
		
		if (Util.symbol(term).equals(PRESENT))
			return ret + "! " + term.sub(0).variable().name();
		
		ret += Util.symbol(term);
		for (int i = 0; i < term.arity(); i++)
		{
			if (i == 0) ret += "[";
			else ret += ", ";
			for (int j = 0; j < term.binders(i).length; j++)
				ret += term.binders(i)[j].name() + ".";
			ret += print(term.sub(i));
		}
		if (term.arity() > 0) ret += "]";
		
		return ret;
	}
	
	public String toString()
	{
		String ret = "";
		for (String declaration : ruleQuadsByConstructor.keySet())
		{
			List<StandardizedRule> lst = ruleQuadsByConstructor.get(declaration);
			for (StandardizedRule q : lst)
			{
				GenericTerm l = q.one();
				GenericTerm r = q.two();
				Constructor rulename = q.three();
				ret += rulename.symbol() + "  " + print(l) + " → " + (r == null ? "?" : print(r)) + "\n";
			}
		}
		return ret;
	}
	
	// ========== error handling ========== //

	/**
	 * Give a warning to the user (but don't abort).
	 * @param txt the warning to be given
	 */
	private void warning(String txt)
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
	private void error(String txt) throws CRSException
	{
		factory.error(txt, "Completer error: ");
	}

	/** Throw a fatal error */
	private void fatal(String txt) throws CRSException
	{
		factory.fatal(txt, "Completer panic: ");
	}
}
