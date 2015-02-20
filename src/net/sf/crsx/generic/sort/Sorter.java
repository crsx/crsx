/* Copyright (c) 2010,2012 IBM Corporation. */

package net.sf.crsx.generic.sort;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.analysis.Unifier;
import net.sf.crsx.generic.GenericEvaluator;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericRule;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.generic.PropertiesConstraintsWrapper;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.HashMultiMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.MultiMap;
import net.sf.crsx.util.NonNullHashMap;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.Util;

/**
 * This class is used to check whether a given set of rules is properly sorted.
 * <p>
 * This class takes a set of rules, and a factory which contains declarations
 * for the constructors used in the given set of rules.
 * It is not required that all constructors occurring in the factory have been
 * declared, but if a symbol is not declared, then it is assumed to be (a)
 * monomorphic, and (b) not overloaded.  It may, however, have a sort set.
 * <p>
 * The Sorter assigns sort denotations (implemented as hidden properties) to
 * all constructor symbols, and keeps track of the sort denotations for
 * variables and meta-variables in each rule.
 * <p>
 * If all variables, meta-variables and constructor occurrences can be
 * assigned a sort denotation, then the sort denotations for variables,
 * meta-variables and constructors are saved in the relevant rules, any
 * undeclared symbols are declared (in the factory) and the Sorter returns
 * with success.
 * If not, the Sorter returns with an exception and no sort denotations
 * are supplied.
 */
public class Sorter
{
	/**
	 * The factory which contains the sort information about some of the
	 * constructor symbols which occur in the rules (and where the remaining
	 * symbols should be declared by the Sorter afterwards); the factory is
	 * also used to construct sorts (which, after all, are represented as
	 * terms) 
	 */ 
	private GenericFactory factory;
	
	/** The number of (recoverable) errors encountered so far. */
	private int errorcount;
	
	/**
	 * The number of sort variables created by the Sorter so far;
	 * this is kept track of to give the fresh type variables unique names, so
	 * as to ease debugging and have a nicer output.
	 */
	private int sortvarsCreated;
	
	/**
	 * For all non-overloaded declared constructors F, maps the string F- to
	 * the corresponding sort declaration &lt;sort,form&gt;;
	 * for all overloaded declared constructors F, maps the strings F-1, ...
	 * to a sort declaration &lt;sort,form&gt;
	 * (see overloadedConstructors for a further explanation).
	 */
	private Map<String, Pair<Term,Term>> declaredConstructors;
	
	/**
	 * Maps all undeclared symbols to a sort declaration <sort,form>, which the
	 * Sorter must fill in
	 */
	private Map<String, Pair<Term,Term>> undeclaredConstructors;
	
	/**
	 * All symbols which are declared as overloaded are split in groups by
	 * their arity; for instance F[Nat], F[x.Nat] and F[Nat,Bool] are all
	 * distinguishable for how they are used, so are considered as different
	 * groups, while F[Nat] and F[Bool] may not be distinguishable from their
	 * use, so are part of the same group.
	 * <p>
	 * Every group of this overloaded symbol is given an index, and for each
	 * index the variable overloadedConstructors contains an entry F-i : &lt;the
	 * set of terms in group i&gt;.  For example, if F may occur with forms
	 * F[Nat], F[x.Nat], F[Nat,Bool] and F[Bool] (and, say, all the same sort
	 * Nat]), then overloadedConstructors might contain
	 * <ul>
	 * <li>F-1 : { &lt;Nat,F[Nat]&gt;, &lt;Nat,F[Bool]&gt; }
	 * <li>F-2 : { &lt;Nat,F[x.Nat]&gt; }
	 * <li>F-3 : { &lt;Nat,F[Nat,Bool]&gt; }
	 * </ul>
	 * 
	 * The same names F-i are used as the keys in declaredConstructors, with a
	 * declaration that fits all forms in that group, for instance:
	 * <ul>
	 * <li>F-1 : &lt;Nat,F[&alpha;]&gt;
	 * <li>F-2 : &lt;Nat,F[x.Nat]&gt;
	 * <li>F-3 : &lt;Nat,F[Nat,Bool]&gt;
	 * </ul>
	 */
	private Map<String, Set<Pair<Term,Term>>> overloadedConstructors;
	
	/** True if the user may specify rules whose root is a data constructor. */
	private boolean allowDataFunctions;

	/** True if the user may omit declarations. */
	private boolean allowUndeclared;
	
	/**
	 * Set to true if there are overloaded constructors with sort declarations
	 * which may not be distinguishable
	 */
	private boolean nonTrivialOverloading;

	/**
	 * Keeps track of the variables we have encountered so far, and the sort
	 * that was associated with them.  The key is the rule this variable occurs
	 * in.
	 */
	Map<String,Map<Variable,Term>> varSortsPerRule;
	
	/**
	 * Keeps track of the meta-variables we have encountered so far, and the
	 * input and output sorts (of the form [output, input 1, ..., input n]).
	 * The key is the name of the rule this meta-variable appears in.
	 */
	Map<String,Map<String,Term[]>> metaSortsPerRule;
	
	/**
	 * Keeps track of the instances of constructors occurring anywhere in the
	 * rule, and assigns them both a sort and a form; since constructors are
	 * sometimes used in multiple places in the same rule (they shouldn't be,
	 * but they are), this is saved on the term containing the constructor
	 * instead (for now)
	 */
	Map<String,Map<Term,Pair<Term,Term>>> constructorSortsPerRule;
	
	/**
	 * Keeps track of meta-variables for each rule which are used inconsistently,
	 * that is, sometimes with property set and sometimes without.  Although at
	 * present this is only used for warnings, its purpose is to assign a property
	 * set to those meta-variables.
	 */
	MultiMap<String,String> inconsistentMetaVariables;
	
	/**
	 * Keeps track of the sorts assigned to free variables, together with the
	 * rules they appear in.  This is used to make sure that all sorts with
	 * syntactic variables have those variables declared.
	 */
	Map<Variable,String> syntacticVariableUse;

	/** The form of each primitive. */
	Map<Primitive,Term> primitiveForm;
	
	// ========== Communicating with the User ========== //

	/**
	 * Give a warning to the user (but don't abort).
	 * @param txt the warning to be given
	 */
	private void warning(String txt)
	{
		factory.warning(txt, "Sort warning: ");
	}
	
	/**
	 * Give an error message to the user, which is collected and not shown
	 * until either too many errors have been encountered, or until some
	 * other functionality calls errorCheck
	 * @param txt the error to be displayed
	 * @throws CRSException if too many errors have been encountered, or the
	 *   error handler (the calling CRS) is set to be strict about errors 
	 */
	private void error(String txt) throws CRSException
	{
		factory.error(txt, "Sort error: ");
		errorcount++;
		if (errorcount >= 500)
			factory.errorCheck("Too many sort errors, cannot continue.");
	}
	
	/**
	 * Return some information about the current status of the sortifier.
	 */
	public String toString()
	{
		return "Sortifier;\n" +
			   "  Declared symbols are: " + declaredConstructors + "\n" +
			   "  Overloaded symbols are: " + overloadedConstructors + "\n" +
			   "  Undeclared symbols are: " + undeclaredConstructors + "\n";
	}

	// ========== Quickly getting sort information ========== //
	
	/**
	 * Given a form F[&rho;0,...,&rho;n] where &rho;_index = x1...xn.s, returns s
	 */
	static Term subSort(Term form, int index)
	{
		Term f = form.sub(index);
		return f.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(f)) ? f.sub(0) : f;
	}

	/**
	 * Given a form F[&rho;0,...,&rho;n] where &rho;_index = x1...xn.s, returns s
	 */
	static void setSubSort(GenericTerm form, int index, GenericTerm subsort)
	{
		GenericTerm f = form.sub(index);
		if (f.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(f)))
			f.replaceSub(0, f.binders(0), subsort);
		else
			form.replaceSub(index, form.binders(index), subsort);
	}
	
	/**
	 * Given a form F[&rho;0,...,&rho;n] where &rho;_i = x1:&iota;1...xn:&iota;n.s, returns &iota;j 
	 */
	private Term binderSort(Term form, int i, int j)
	{
		Variable x = form.binders(i)[j];
		return Util.propertiesHolder(form.sub(i)).getProperty(x);
	}
	
	// ========== Building Sorts ========== //

	/**
	 * Given a sort, this creates a full copy which is a GenericTerm recursively.
	 * @param sort the sort to copy
	 * @param includeSortSet if this is true, and sort has some sort set associated
	 *   with it (which should only contain variables and strings), then the sort set
	 *   is also copied and included in the result; if not, the result is a basic sort
	 * @return a full copy of the given sort
	 * @throws CRSException if the given sort is not, in fact, a sort
	 */
	GenericTerm copySort(Term sort, boolean includeSortSet) throws CRSException
	{
		GenericTerm ret = Unifier.repeat_apply(sort, new HashMap<Variable,Term>(), factory);
		
		if (!includeSortSet) return ret;
		PropertiesHolder A = Util.propertiesHolder(sort);
		if (A == null) return ret;
		
		Map<String,Term> propertyNames = null;
		if (A.propertyNames().iterator().hasNext()) propertyNames = new HashMap<String,Term>();
		for (String name : A.propertyNames())
			propertyNames.put(name, copySort(A.getProperty(name), false));
		
		Map<Variable,Term> propertyVars = null;
		if (A.propertyVariables().iterator().hasNext()) propertyVars = new HashMap<Variable,Term>();
		for (Variable var : A.propertyVariables())
			propertyVars.put(var, copySort(A.getProperty(var), false));
		
		if (propertyNames == null && propertyVars == null) return ret;

		if (Util.propertiesHolder(ret) == null)
			return Util.makePropertiesConstraintsWrapper(ret, null, propertyNames, propertyVars, null);

		PropertiesHolder B = Util.propertiesHolder(ret);
		for (Entry<String,Term> e : propertyNames.entrySet())
			B.setProperty(e.getKey(), e.getValue());
		for (Entry<Variable,Term> e : propertyVars.entrySet())
			B.setProperty(e.getKey(), e.getValue());
		
		return ret;
	}
	
	/**
	 * Given a generic term, this returns the term unmodified.
	 * Otherwise, this returns a GenericTerm presentation of the given sort
	 * (which must be a sort, that is, no binders or meta-variables).
	 */
	GenericTerm makeGeneric(Term sort) throws CRSException
	{
		if (sort instanceof GenericTerm) return (GenericTerm) sort;
		else return copySort(sort, true);
	}
	
	/**
	 * Create a fresh sort variable.
	 * @return the newly created type variable
	 */
	private Variable freshSortVariable()
	{
		sortvarsCreated++;
		return factory.makeVariable("a" + sortvarsCreated, true);
	}
	
	/**
	 * Create a fresh sort variable as a term.
	 * @return the newly created sort variable
	 */
	private GenericTerm freshSortVariableUse()
	{
		return factory.newVariableUse(freshSortVariable());
	}

	/**
	 * Creates a construction of the form
	 * F[x11...x1n.{x11:&iota;11,...,x1n:&iota;1n}&kappa;1,...,xm1...xmk.{xm1:&iota;m1,...,xmk:&iota;mk}&kappa;m]
	 * @param constructor the constructor F of the result
	 * @param sorts the &kappa;1,...,&kappa;m, which are used as the arguments
	 * @param binds the binders xij; this may be null, in which case new variables are created
	 * @param bindersorts the sorts &iota;ij of the binders
	 * @return the created form
	 * @throws CRSException if manipulating the property sets goes wrong; shouldn't happen
	 */
	private GenericTerm freshForm(Constructor c, GenericTerm[] sorts, Variable[][] binds, Term[][] bindersorts) throws CRSException
	{
		// initialize binds if this hasn't been done
        if (bindersorts == null)
        {
            bindersorts = new Term[sorts.length][];
			for (int i = 0; i < bindersorts.length; i++)
				bindersorts[i] = new Term[0];
        }
		if (binds == null)
		{
			int varcounter = 0;
			binds = new Variable[bindersorts.length][];
			for (int i = 0; i < binds.length; i++)
			{
				binds[i] = new Variable[bindersorts[i].length];
				for (int j = 0; j < binds[i].length; j++)
					binds[i][j] = factory.makeVariable("x" + (++varcounter), true);
			}
		}
		
		// fix up sorts to carry the bindersorts
		for (int i = 0; i < sorts.length; i++)
		{
			PropertiesHolder A = Util.propertiesHolder(sorts[i]);
			if (bindersorts[i].length > 0 && (A == null || !A.canSetProperty(binds[i][0])))
			{
				sorts[i] = new PropertiesConstraintsWrapper(sorts[i], null, null, null, null);
				A = Util.propertiesHolder(sorts[i]);
			}
			for (int j = 0; j < bindersorts[i].length; j++)
				A.setProperty(binds[i][j], bindersorts[i][j]);
		}
		
		return factory.newConstruction(c, binds, sorts);
	}
	
	/**
	 * Creates a form F[a_1,...,a_n], where the a_i are all
	 * different sort variables, and there are no binders.
	 * @param symbol the name of the form (F) -- if this name is a meta-variable name, a meta-application is created, otherwise a construction
	 * @param arity the number n of arguments to the constructor
	 * @return the created form
	 */
	private GenericTerm freshForm(String symbol, int arity)
	{
		GenericTerm args[] = new GenericTerm[arity];
		for (int i = 0; i < args.length; i++) args[i] = freshSortVariableUse();
		return factory.newForm(symbol, args);
	}
	
	/**
	 * Create a fresh form, with sort variables for all arguments.
	 * @param example a term having this form
	 * @return the newly created form
	 * @throws CRSException if there is an error in saving the sorts of the
	 *   binders (this shouldn't happen)
	 */
	private Term freshForm(Term example) throws CRSException
	{
		Constructor c = example.constructor();
		GenericTerm[] subs = new GenericTerm[example.arity()];
		Term[][] bindersorts = new Term[example.arity()][];
		for (int i = 0; i < subs.length; i++)
		{
			subs[i] = freshSortVariableUse();
			bindersorts[i] = new Term[example.binders(i).length];
			for (int j = 0; j < bindersorts[i].length; j++)
				bindersorts[i][j] = freshSortVariableUse();
		}
		return freshForm(c, subs, null, bindersorts);
	}
	
	/**
	 * given a sort declaration <sort,form>, creates a renaming which replaces
	 * all type variables occurring in either form or sort by fresh variables
	 */
	private ExtensibleMap<Variable,Variable> freshRenaming(Term sort, Term form)
	{
		Set<Variable> vars = new HashSet<Variable>();
		sort.addFree(vars, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
		form.addFree(vars, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
		Map<Variable,Variable> renaming = new HashMap<Variable,Variable>();
		for (Variable x : vars)
			renaming.put(x, freshSortVariable());
		return new LinkedExtensibleMap<Variable,Variable>().extend(renaming);
	}
	
	// ========== Initialization ========== //
	
	/**
	 * Instantiate sortification process.
	 * @param fac a factory, which we use both for the sort declarations we
	 *   will use (and add to), and to give error messages
	 * @param sloppy whether it is allowed to have rules whose root symbol is
	 *   a data symbol
	 * @param infer whether undeclared constructors are allowed
	 * @throws CRSException if something went wrong with the initialization
	 */
	public Sorter(GenericFactory fac, boolean sloppy, boolean infer) throws CRSException
	{
		sortvarsCreated = 0;
		factory = fac;
		errorcount = 0;

		declaredConstructors = new HashMap<String,Pair<Term,Term>>();
		undeclaredConstructors = new HashMap<String,Pair<Term,Term>>();
		overloadedConstructors = new HashMap<String,Set<Pair<Term,Term>>>();
		allowDataFunctions = sloppy;
		allowUndeclared = infer;

		grabSymbols();
	}
	
	/**
	 * This function returns the full arity of the given term / form.
	 * Here, the full arity is a sequence [k1,...,kn] where ki indicates the
	 * number of binders at the ith position; n is the standard arity of form.
	 * The arity is represented as a string for easier handling and returned.
	 * @param form the term whose arity is to be checked
	 * @return a String-encoding of the full arity
	 */
	private String getArityCode(Term form)
	{
		int k = form.arity();
		String ret = "[";
		for (int i = 0; i < k; i++)
		{
			if (i != 0) ret += ",";
			ret += form.binders(i).length;
		}
		return ret + "]";
	}

	/**
	 * Take a list of all known symbols from the factory, and save them as
	 * declared symbols; if symbols occur with more than one sort declaration
	 * having the same full arity, then they are saved with polymorphic sort
	 * declarations and also saved in the overloadedConstructor-mapping.
	 * @throws CRSException an exception may be thrown if the factory is set
	 *   up incorrectly (for instance, not all sorts are really sorts)
	 */
	private void grabSymbols() throws CRSException
	{
		nonTrivialOverloading = false;
		Set<String> allConstructors = factory.getSortedConstructors();
		for (String f : allConstructors)
		{
			Set<Pair<Term,Term>> declarations = factory.formsOf(f);
			if (declarations == null || declarations.isEmpty()) continue;
			if (declarations.size() == 1)
			{
				declaredConstructors.put(f + "-", declarations.iterator().next());
				continue;
			}
			
			// we have an overloaded symbol; make groups of the different arities it occurs with
			Map<String,Set<Pair<Term,Term>>> arities = new HashMap<String,Set<Pair<Term,Term>>>();
			for (Pair<Term,Term> declaration : declarations)
			{
				String arityCode = getArityCode(declaration.tail());
				if (!arities.containsKey(arityCode))
					arities.put(arityCode, new HashSet<Pair<Term,Term>>());
				arities.get(arityCode).add(declaration);
			}

			// create different symbols for all of the arities, and if some
			// arity is only used with a specific sort declaration, save the
			// symbol with that declaration; otherwise make it polymorphic
			int i = 0;
			for (String arityCode : arities.keySet())
			{
				i++;
				String symbol = f + "-" + i;
				Set<Pair<Term,Term>> pairs = arities.get(arityCode);
				if (pairs.size() == 1) declaredConstructors.put(symbol, pairs.iterator().next());
				else
				{
					nonTrivialOverloading = true;
					
					// we will create a sort and form
					Term sort;
					GenericTerm formsorts[];
					Term[][] bindersorts;
					
					// initially, we set them to mimic just one of the existing declarations
					Pair<Term,Term> declaration = pairs.iterator().next();
					sort = copySort(declaration.head(), false);
					Term exampleform = declaration.tail();
					formsorts = new GenericTerm[exampleform.arity()];
					bindersorts = new Term[exampleform.arity()][];
					for (int k = 0; k < formsorts.length; k++)
					{
						formsorts[k] = copySort(subSort(exampleform,k), false);
						bindersorts[k] = new Term[exampleform.binders(k).length];
						for (int j = 0; j < bindersorts[k].length; j++)
							bindersorts[k][j] = copySort(binderSort(exampleform, k, j), false);
					}

					// and then for every other declaration where some position is not
					// the same, set that position to a variable
					for (Pair<Term,Term> pair : pairs)
					{
						Term psort = pair.head();
						Term pform = pair.tail();
						Set<Variable> FTV = new HashSet<Variable>();
						psort.addFree(FTV, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
						pform.addFree(FTV, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
						if (!FTV.isEmpty())
							error("Sort problem "+pform+": Non-trivial overloading (multiple constructors with the same full arity) "+
						          "is only allowed when all instances of the overloaded constructor have a "+
								  "monomorphic sort and form.");
						/*
						boolean hasProperties = false;
						if (Util.propertiesHolder(psort) != null &&
							Util.propertiesHolder(psort).propertyNames().iterator().hasNext()) hasProperties = true;
						if (Util.propertiesHolder(pform) != null &&
							Util.propertiesHolder(pform).propertyNames().iterator().hasNext()) hasProperties = true;
						for (int k = 0; k < pform.arity(); k++)
							if (Util.propertiesHolder(pform.sub(k)) != null &&
								Util.propertiesHolder(pform.sub(k)).propertyNames().iterator().hasNext()) hasProperties = true;
						if (hasProperties)
							error("Non-trivial overloading (multiple constructors with the same full arity) "+
								  "is only allowed when no instances of the overloaded constructor have any "+
								  "sort sets.");
						*/
						
						if (sort.kind() != Kind.VARIABLE_USE && !Unifier.unifiable(sort, psort, factory))
							sort = freshSortVariableUse();
						for (int k = 0; k < pform.arity(); k++)
						{
							Term pformsub = subSort(pform, k);
							if (formsorts[k].kind() != Kind.VARIABLE_USE && !Unifier.unifiable(formsorts[k],pformsub, factory))
								formsorts[k] = freshSortVariableUse();
							for (int j = 0; j < bindersorts[k].length; j++)
							{
								Term vSort = binderSort(pform, k, j);
								if (bindersorts[k][j].kind() != Kind.VARIABLE_USE && Unifier.unifiable(bindersorts[k][j], vSort, factory))
									bindersorts[k][j] = freshSortVariableUse();
							}
						}
					}
					Term form = freshForm(factory.makeConstructor(f), formsorts, null, bindersorts);

					// and save the result
					declaredConstructors.put(symbol, new Pair<Term,Term>(sort,form));
					overloadedConstructors.put(symbol, pairs);
				}
			}
		}
	}

	// ========== Sorting Process ========== //

	/**
	 * Solve the sorts in the current rules, and assign sort sets indicating
	 * the sort constraints used in all rules (sort assignments of variables
	 * and meta-variables, as well as indications of the sort and form of all
	 * occurrences of a constructor).
	 * Since the rules and symbols are all part of the original term, the
	 * result, a fully typed set of rules, does not need to be returned.
	 * @param rules the rules to sortify, listed by their name
	 * @throws CRSException if sortification is unsuccessful
	 */
	public void runSortify(Map<String,GenericRule> rules) throws CRSException
	{
		varSortsPerRule = new HashMap<String,Map<Variable,Term>>();
		metaSortsPerRule = new HashMap<String,Map<String,Term[]>>();
		constructorSortsPerRule = new HashMap<String,Map<Term,Pair<Term,Term>>>();
		inconsistentMetaVariables = new HashMultiMap<String,String>();
		syntacticVariableUse = new HashMap<Variable,String>();
		
		preSortificationChecks(rules);
		mainSortification(rules);
		postSortificationChecks(rules);
		
		// save the data we found in the rule
		for (String name : rules.keySet())
		{
			GenericRule rule = rules.get(name);
			rule.setVariableSorts(varSortsPerRule.get(name));
			rule.setConstructorSorts(constructorSortsPerRule.get(name));
			
			Map<String,Term[]> metaSorts = metaSortsPerRule.get(name);
			Map<String,Term> mSorts = new HashMap<String,Term>();
			for (String k : metaSortsPerRule.get(name).keySet())
				if (metaSorts.get(k).length != 0) mSorts.put(k, metaSorts.get(k)[0]);
			rule.setMetaVariableSorts(mSorts);
		}
	}

	/**
	 * Do the checks which must be done before starting the sortifying: check
	 * whether all rules which use property sets have those sets declared,
	 * make sure arities are respected, and as this involves going through the
	 * terms anyway, save limited sort information while we're at it (in the
	 * global variables for sort sets, varSortsPerRule etc.)
	 * @param rules the rules which should be checked and modified
	 * @throws CRSException if any errors are encountered (errors are saved up
	 *   during the checks, but thrown in one go at the end, since sort
	 *   checking should not continue if the initial checks fail)
	 */
	private void preSortificationChecks(Map<String,GenericRule> rules) throws CRSException
	{
		//checkSyntacticDataBinders();

		for (Map.Entry<String,GenericRule> e : rules.entrySet())
		{
			String name = e.getKey();
			GenericRule rule = e.getValue();

			// check arities, and save polymorphic sorts for all variables,
			// meta-variables and previously unknown function symbols
			Map<Variable,Term> varSorts = new HashMap<Variable,Term>();   // Free and fresh variable sorts.
			Map<String,Term[]> metaSorts = new HashMap<String,Term[]>();
			Map<Term,Pair<Term,Term>> constructorSorts = new IdentityHashMap<Term,Pair<Term,Term>>();
			
			// Add variable sorts from options.
			List<Term> optionDeclarations = new ArrayList<Term>();
			if (rule.getOptions().containsKey(Builder.FREE_OPTION_SYMBOL))
				optionDeclarations.addAll(rule.getOptions().get(Builder.FREE_OPTION_SYMBOL));
			if (rule.getOptions().containsKey(Builder.FRESH_OPTION_SYMBOL))
			{
				List<Term> option = rule.getOptions().get(Builder.FRESH_OPTION_SYMBOL);
				for (Term o : option)
				{
					optionDeclarations.add(o);
					
					if (o.kind() == Kind.VARIABLE_USE)
						error("Unspecified fresh variable " + o);
				}
				
				
			}
			if (rule.getOptions().containsKey(Builder.FRESH_REUSE_OPTION_SYMBOL))
				optionDeclarations.addAll(rule.getOptions().get(Builder.FRESH_REUSE_OPTION_SYMBOL));
			if (rule.getOptions().containsKey(Builder.GLOBAL_OPTION_SYMBOL))
				optionDeclarations.addAll(rule.getOptions().get(Builder.GLOBAL_OPTION_SYMBOL));
			for (Term o : optionDeclarations)
				if (Util.isVariableWithOptionalSort(o))
				{
					Variable v = Util.variableWithOptionalSortVariable(o);
					Term sort = Util.variableWithOptionalSortSort(o);
					if (sort != null)
						varSorts.put(v, sort);
				}

			varSortsPerRule.put(name, varSorts);
			metaSortsPerRule.put(name, metaSorts);
			constructorSortsPerRule.put(name, constructorSorts);

			Map<String,Integer> mvarUsage = new HashMap<String,Integer>();
				// save 1 for a meta-variable with a property set, 0 without,
			    // -1 if it has occurred as a property set key
			arityCheck(rule.getPattern(), rule.getName(), mvarUsage);
			arityCheck(rule.getContractum(), rule.getName(), mvarUsage);
		}
		factory.errorCheck("Errors prevent completing the sortification process.");
	}

	/**
	 * Check the requirement that when a data constructor uses binders, those
	 * binders are only for syntactic variables.  This is to make sure the
	 * system might be complete; otherwise we may have a normal form F[x.G[x]],
	 * where G is a function constructor and F data.
	 * If this requirement fails, a warning is printed.
	 */
	private void checkSyntacticDataBinders()
	{
		for (String F : factory.getSortedConstructors())
		{
			if (!factory.isData(F)) continue;
			Set<Pair<Term,Term>> forms = factory.formsOf(F);
			for (Pair<Term,Term> pair : forms)
			{
				Term form = pair.tail();
	        	if (form.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(form)))
	        		form = subSort(form, 0);
				for (int i = 0; i < form.arity(); i++)
					for (int j = 0; j < form.binders(i).length; j++)
					{
						Term bindersort = Util.propertiesHolder(form.sub(i)).getProperty(form.binders(i)[j]);
						if (bindersort.arity() != 0 ||
							!factory.sortAllowsVariables(Util.symbol(bindersort)))
						{
							warning("data constructor " + Util.symbol(form) + " in sort " +
									pair.head() + " uses non-syntactic variable as binder.  ");
						}
					}
			}
		}
	}
	
	/**
	 * Returns whether the given term is equipped with a property set.
	 */
	private boolean hasPropertySet(Term term)
	{
		PropertiesHolder ph = Util.propertiesHolder(term);
		if (ph == null) return false;
		if (ph.propertyNames().iterator().hasNext()) return true;
		if (ph.propertyVariables().iterator().hasNext()) return true;
		if ((ph instanceof PropertiesConstraintsWrapper)) return ((PropertiesConstraintsWrapper) ph).hasUnknownKeys();
		return false;
	}
	
	/**
	 * Go through the term, giving an error if any (sufficiently serious)
	 * arity violations are encountered.  In the process, all variables are
	 * assigned a polymorphic sort and all meta-variables a polymorphic sort
	 * declaration of the form [output sort, input sort 1, ... , input sort n]
	 * (or [] for meta-set-variables); this is saved in the global variables.
	 * @param term the sort to check
	 * @param rulename name of the rule, used for error-messages and to save
	 *   the assigned sort data
	 * @param mvarUsage for all meta-variables: 0 if we have seen it before
	 *   without a property set, 1 if we have seen it with, -1 if it is not
	 *   allowed to have a property set
	 * @throws CRSException possible consequence of giving (too many) errors
	 */
	private void arityCheck(Term term, Constructor rulename, Map<String,Integer> mvarUsage) throws CRSException
    {
		// get the sets to save declarations for this rule, for easier handling
		Map<Variable,Term> varSorts = varSortsPerRule.get(rulename.symbol());
		Map<String,Term[]> metaSorts = metaSortsPerRule.get(rulename.symbol());
		Map<Term,Pair<Term,Term>> constructorSorts = constructorSortsPerRule.get(rulename.symbol());
		
		boolean hasProperties = hasPropertySet(term);
		
		// term is a variable: give it a sort and return
		if (term.kind() == Kind.VARIABLE_USE)
		{
			// TODO: if this is a variable declared in options, then give it the sort which it was declared with
			if (!varSorts.containsKey(term.variable()))
			{
				Variable alpha = freshSortVariable();
				varSorts.put(term.variable(), factory.newVariableUse(alpha));
				syntacticVariableUse.put(alpha, rulename.symbol());
			}
			if (hasProperties)
				error("unexpected property set with variable " + term + " in rule " + rulename + ".");
			return;
		}

		// meta-application: make sure its arity is consistent with previous and future arities
		// and if there's a property set associated with it, that its requirements are saved
		if (term.kind() == Kind.META_APPLICATION)
		{
			// get data
			String mvar = term.metaVariable();
			int arity = term.arity();
			
			// if it's a new one, just save it with default settings
			if (!metaSorts.containsKey(mvar))
			{
				Term[] declaration = new Term[arity+1];
				for (int i = 0; i <= arity; i++) declaration[i] = freshSortVariableUse();
				metaSorts.put(mvar, declaration);
				mvarUsage.put(mvar, hasProperties ? new Integer(1) : new Integer(0));
			}
			// if it's not a new one, check whether it corresponds with the last declaration
			//TODO: the rules here are too restrictive but not checkng as I do now is not good either...
			//---need a way to check but also allow specially marked "naked and delayed" functions and sorts...
			else
			{
				//if (metaSorts.get(mvar).length == 0)
				//	error("inconsistent use of meta-variable " + mvar + " in rule " + rulename +
				//		  ": used both as a reference and a normal meta-variable");
				//if (metaSorts.get(mvar).length != arity+1)
				//	error("inconsistent arity use of meta-variable " + mvar + " in rule " + rulename + ".");
				if (hasProperties)
				{
					if (mvarUsage.get(mvar).intValue() == -1)
						error("inconsistent use of meta-variable " + mvar + " in rule " + rulename +
							  ": used both with a property set, and as key inside one!");
				//	else if (mvarUsage.get(mvar).intValue() == 0)
				//	{
				//		warning("inconsistent use of meta-variable " + mvar + " in rule " + rulename +
				//				": used both with a property set and without!");
				//		inconsistentMetaVariables.multiAdd(rulename, mvar);
				//		mvarUsage.put(mvar, new Integer(1));
				//	}
				}
				//if (mvarUsage.get(mvar).intValue() == 1)
				//{
				//	warning("inconsistent use of meta-variable " + mvar + " in rule " + rulename +
				//			": used both with a property set and without!");
				//	inconsistentMetaVariables.multiAdd(rulename, mvar);
				//}
			}

			// recursively check children
			for (int i = 0; i < term.arity(); i++)
			{
				if (term.binders(i).length != 0)
					error("binders in rule " + rulename + " may only occur beneath a constructor");
				arityCheck(term.sub(i), rulename, mvarUsage);
			}
			
			// recursively check property set and save its requirements
			if (hasProperties) arityCheckPropertySet(Util.propertiesHolder(term), rulename, mvarUsage);
			return;
		}
		
		// now term must be a construction
		String F = Util.symbol(term);
		
		// $-construction
		if (Util.isEval(term.constructor()) && term.arity() > 0)
		{
			if (hasProperties) arityCheckPropertySet(Util.propertiesHolder(term), rulename, mvarUsage);
			arityCheckDollarConstruction(term, rulename, mvarUsage);
			return;
		}

		// Literals...
		else if (Util.isLiteral(term))
		{
			if (term.arity() == 0)
				constructorSorts.put(term, new Pair<Term,Term>(freshForm(term.constructor().literalSort(), 0), term.copy(false, null)));
			else error("literal " + term + " in rule " + rulename + " used as constructor with arguments");
		}
		
		// construction with a uniquely declared constructor: check whether the form follows the declaration
		else if (term.kind() == Kind.CONSTRUCTION && declaredConstructors.containsKey(F+"-"))
		{
			Term sort = declaredConstructors.get(F+"-").head();
			Term form = declaredConstructors.get(F+"-").tail();
			if (!getArityCode(term).equals(getArityCode(form)))
			{
				error("Subterm " + term + " in rule " + rulename + " does not follow "+
			          "the declaration of " + F + " (" + 
			          declaredConstructors.get(F+"-").tail() + ")");
				return;
			}
			ExtensibleMap<Variable,Variable> renaming = freshRenaming(sort, form);
			constructorSorts.put(term, new Pair<Term,Term>(sort.copy(false, renaming), form.copy(false, renaming)));
		}
		
		// construction with a previously encountered constructor: check whether the form follows the declaration then assigned
		else if (term.kind() == Kind.CONSTRUCTION && undeclaredConstructors.containsKey(F))
		{
			Term sort = undeclaredConstructors.get(F).head();
			Term form = undeclaredConstructors.get(F).tail();
			if (!getArityCode(term).equals(getArityCode(form)))
			{
				error("Constructor " + F + " not declared as an overloaded symbol, " +
					  "but does occur with different full arities; in subterm " + term +
					  "with arity " + getArityCode(term) + ", previously as " +
					  getArityCode(undeclaredConstructors.get(F).tail()));
				return;
			}
			constructorSorts.put(term, new Pair<Term,Term>(sort, form));
				// not a fresh copy, because undeclared symbols may not be polymorphic
		}
		
		// construction with an overloaded constructor: check whether any of its forms fits the declaration
		else if (term.kind() == Kind.CONSTRUCTION && declaredConstructors.containsKey(F+"-1"))
		{
			String arcode = getArityCode(term);
			int fits = -1;
			for (int i = 1; fits == -1 && declaredConstructors.containsKey(F+"-"+i); i++)
			{
				if (arcode.equals(getArityCode(declaredConstructors.get(F+"-"+i).tail()))) fits = i;
			}
			if (fits == -1)
				error("constructor " + F + " occurs in " + term + " (in rule " + rulename +
					  ") with a form that does not correspond with any of its " +
					  "overloaded declarations.");
			else {
				Term sort = declaredConstructors.get(F+"-"+fits).head();
				Term form = declaredConstructors.get(F+"-"+fits).tail();
				ExtensibleMap<Variable,Variable> renaming = freshRenaming(sort, form);
				constructorSorts.put(term, new Pair<Term,Term>(sort.copy(false, renaming), form.copy(false, renaming)));
			}
		}
		
		// construction with a so-far undeclared constructor: add it to undeclaredConstructors
		else
		{
			Term sort = freshSortVariableUse();
			Term form = freshForm(term);
			undeclaredConstructors.put(Util.symbol(term), new Pair<Term,Term>(sort,form));
			if (!Util.symbol(term).equals("@") && !allowUndeclared)
				warning("undeclared constructor (" + Util.symbol(term) + ") in rule " + rulename.symbol());
			constructorSorts.put(term, new Pair<Term,Term>(sort, form));
		}
		
		Pair<Term,Term> pair = constructorSorts.get(term);
		if (pair == null)
		{
			error("unexpected missing constructorSort for " + term + "?!?");
			return;
		}
		Term form = pair.tail();
			// in the null case, it must be an integer, so has arity 0

		// term with children: check the children
		for (int i = 0; i < term.arity(); i++)
		{
			// save the sorts of binders
			if (term.binders(i).length != 0)
			{
				for (int j = 0; j < form.binders(i).length; j++)
					varSorts.put(term.binders(i)[j], binderSort(form, i, j));
			}
			// call the function on the children
			arityCheck(term.sub(i), rulename, mvarUsage);
			// undo the sort saving of binders
			for (int j = 0; j < term.binders(i).length; j++)
				varSorts.remove(term.binders(i)[j]);
		}

		if (hasProperties)
			arityCheckPropertySet(Util.propertiesHolder(term), rulename, mvarUsage);
	}
	
	/**
	 * Go through the given property set, recursively calling arityCheck on all
	 * key:value-pairs.
	 * @param ph the property set to check
	 * @param rulename the name of the rule being checked (for use in error
	 * 	 messages)
	 * @param mvarUsage for all meta-variables: 0 if we have seen it before
	 *   without a property set, 1 if we have seen it with, -1 if it is not
	 *   allowed to have a property set
	 * @throws CRSException possible consequence of giving (too many) errors 
	 */
	private void arityCheckPropertySet(PropertiesHolder ph, Constructor rulename, Map<String,Integer> mvarUsage) throws CRSException
	{
		Map<Variable,Term> varSorts = varSortsPerRule.get(rulename.symbol());
		Map<String,Term[]> metaSorts = metaSortsPerRule.get(rulename.symbol());
		
		String ref = null;
		if ((ph instanceof PropertiesConstraintsWrapper) && ((PropertiesConstraintsWrapper) ph).getRef() != null)
			ref = ((PropertiesConstraintsWrapper) ph).getRef();
		
		if (ref != null && metaSorts.containsKey(ref) && metaSorts.get(ref).length != 0)
			error("using meta-variable " + ref + " in rule " + rulename + " both as meta-variable and set-meta-variable!");
		else if (!metaSorts.containsKey(ref))
			metaSorts.put(ref, new Term[0]);

		// recursively check all of the values in the property set
		
		// properties x : p, with x a variable
		Iterable<Variable> vprops = ph.propertyVariables();
		for (Variable key : vprops)
		{
			Term value = ph.getProperty(key);

			// p is a term, check it
			if (value != null) arityCheck(value, rulename, mvarUsage);
			
			// make sure we have a sort for key
			if (!varSorts.containsKey(key))
			{
				Variable alpha = freshSortVariable();
				varSorts.put(key, factory.newVariableUse(alpha));
				syntacticVariableUse.put(alpha, rulename.symbol());
			}
		}

		for (String key : ph.propertyNames())
		{
			Term value = ph.getProperty(key);
			if (value != null) arityCheck(value, rulename, mvarUsage);
		}
		
		/*
		// properties F : p, with F a constructor (which cannot be polymorphic, and must have arity 0)
		// outcommented because it cannot currently happen, all keys are strings or variables
		Iterable<String> sprops = A.propertyNames();
		for (String key : sprops)
		{
			Term value = A.getProperty(key);
			
			// p is a term, check it
			if (value != null) arityCheck(value, rulename, mvarUsage);
			
			// check whether F is supposed to have arity 0
			String err = "inconsistent arity: constructor symbol " + key +
			  " occurs with arity 0 in rule " + rulename;
			if (undeclaredConstructors.containsKey(key))
			{
				if (undeclaredConstructors.get(key).tail().arity() != 0)
					error(err + "; previously used with arity " +
						  undeclaredConstructors.get(key).tail().arity() + ".");
			}
			else if (declaredConstructors.containsKey(key + "-"))
			{
				if (declaredConstructors.get(key + "-").tail().arity() != 0)
					error(err + "; symbol was declared with arity " +
						  declaredConstructors.get(key + "-").tail().arity() + ".");
				if (declaredConstructors.get(key + "-").head().kind() == Kind.VARIABLE_USE)
					error("polymorphic symbol (" + key + ") occurs as a key in " +
						  "a property set in rule " + rulename + ".");
			}
			else if (declaredConstructors.containsKey(key + "-1"))
			{
				// TODO: do we want to permit this at all?
				int ok = -1;
				for (int i = 1; declaredConstructors.containsKey(key + "-" + i); i++)
					if (declaredConstructors.get(key + "-" + i).tail().arity() == 0) ok = i;
				if (ok == -1) error(err + "; all of the overloaded declarations of " +
							        key + " have greater arity.");
				if (declaredConstructors.get(key + "-" + ok).head().kind() == Kind.VARIABLE_USE)
					error("overloaded symbol (" + key + ") does not have a unique "+
						  "arity-0 sort, so cannot be used as a key in a property "+
						  "set.");
			}
			else if (!factory.isInteger(key)) // previously unknown symbol!
			{
				Term sort = freshSortVariableUse();
				Term form = factory.constant(key);
				undeclaredConstructors.put(key, new Pair<Term,Term>(sort,form));
			}
		}
		*/
		
		// properties #Z : p, with #Z a meta-variable
		if (ph instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
			Iterable<String> mprops = pcw.propertyMetaVariables();
			for (String key : mprops)
			{
				Term value = pcw.getMetaProperty(key);
				
				// p is a term, check it
				if (value != null)
					arityCheck(value, rulename, mvarUsage);
				
				// make sure #Z is used with correct arity
				if (!metaSorts.containsKey(key))
				{
					Term[] declaration = new Term[1];
					declaration[0] = freshSortVariableUse();
					metaSorts.put(key, declaration);
				}
				else if (metaSorts.get(key).length != 1)
					error("meta-variable " + key + " in rule " + rulename +
						  "used with inconsistent arity.");
			
				// make sure #Z does not occur elsewhere with a property set
				if (mvarUsage.containsKey(key) && mvarUsage.get(key).intValue() == 1)
					error("inconsistent use of meta-variable " + key + " in rule " + rulename +
							  ": used both with a property set, and as key inside one!");
				else
					mvarUsage.put(key, new Integer(-1));
			}
		}
	}
	
	/**
	 * Do the work of arityCheck in case the given term is a dollar-construction,
	 * except checking the property set (this is assumed to already have been done).
	 * @see arityCheck
	 */
	private void arityCheckDollarConstruction(Term term, Constructor rulename, Map<String,Integer> mvarUsage) throws CRSException
	{
		if (term.arity() == 0)
			return;
		// check subterms
		for (int i = 1; i < term.arity(); i++)
			arityCheck(term.sub(i), rulename, mvarUsage);
		
		// the case distinction below will determine the sort/form denotation for the term
		GenericTerm[] sorts =  new GenericTerm[term.arity()-1];
		GenericTerm sort = dollarSortForms(term, sorts, rulename);
		if (term.arity() > 0 && Util.hasProperties(term.sub(0)))
		{
			PropertiesHolder ph = Util.propertiesHolder(term.sub(0));
			if (ph != null) arityCheckPropertySet(ph, rulename, mvarUsage);
		}
		String cmd = term.arity() == 0 ? "" : Util.symbol(term.sub(0)); 
		constructorSortsPerRule.get(rulename.symbol()).put(term, new Pair<Term,Term>(sort, factory.newForm((CRS.EVAL_SYMBOL + cmd), sorts)));
	}
	
	/**
	 * Helper to populate the form and return the result sort of 
	 * @param term with $-expression
	 * @param argumentforms will be set to the sorts of the arguments of the $-expression (following the command thus indexed 0..arity-1; null entries are unconstrained
	 * @return sort of dollar form or null if one cannot be determined
	 * @throws CRSException in case of an error
	 */
	GenericTerm dollarSortForms(Term term, GenericTerm[] argumentsorts, Constructor rulename) throws CRSException
	{
		assert term.arity() == argumentsorts.length+1;
		if (term.arity() == 0)
		{
			error("Illegal " + CRS.EVAL_SYMBOL + "-construction in rule " + rulename + ": " + term);
			return null;
		}
		Term main = term.sub(0);
		if (main.kind() != Kind.CONSTRUCTION)
		{
			error("Illegal " + CRS.EVAL_SYMBOL + "-construction in rule " + rulename + ": " + term);
			return null;
		}
		String cmd = Util.symbol(main);
		Primitive primitive = Primitive.which(cmd);
		
		// check arity
		if (primitive == null)
		{
			error("unknown " + CRS.EVAL_SYMBOL + "-construction in rule " + rulename + ": " + term);
			return null;
		}
		int arity = term.arity() - 1;
		if (arity < primitive.minArgCount || primitive.maxArgCount < arity)
		{
			error(CRS.EVAL_SYMBOL + "-construction in rule " + rulename + " has incorrect arity: " + term);
			return null;
		}

		// the case distinction below will determine the sort/form denotation for the term
		GenericTerm sort = null;
		switch (primitive)
		{
			case EMPTY_SEQUENCE : {
				// test on list of anything
				argumentsorts[0] = freshForm(CRS.LIST_SORT, 1);
				sort = freshForm(CRS.BOOLEAN_SORT, 0);
				break;
			}
			case CONTAINS :
			case STARTS_WITH :
			case ENDS_WITH :
			case MATCH_REGEX :
			case STRING_EQ :
			case STRING_LT :
			case HAS_URL : {
				// test of string(s)
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);
				sort = freshForm(CRS.BOOLEAN_SORT, 0);
				break;
			}
			case LENGTH :
			case INDEX :
			case DECIMAL :
			case HEX :
			case DECODE_POINT : {
				// generate number from string(s)
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);
				sort = freshForm(CRS.NUMERIC_SORT, 0);
				break;
			}
			case SUBSTRING : {
				// generate string from string and numbers
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
				for (int i = 1; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.NUMERIC_SORT, 0);
				sort = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case SPLIT : {
				// generate list of strings from strings
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);
				GenericTerm[] sorts = {freshForm(CRS.STRING_SORT, 0)};
				sort = freshForm(factory.makeConstructor(CRS.LIST_SORT), sorts, null, null);
				break;
			}
			case REPLACE :
			case SQUASH :
			case ESCAPE :
			case RESCAPE :
			case MANGLE :
			case URL :
			case CONCATENATION :
			case BEFORE_FIRST :
			case AFTER_FIRST :
			case TO_FIRST :
			case FROM_FIRST :
			case TRIM :
			case UP_CASE :
			case DOWN_CASE : {
				// generate string from string(s)
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);
				sort = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case PLUS :
			case TIMES :
			case MINUS :
			case DIVIDE :
			case MODULO :
			case ABSOLUTE :
			case BIT_AND :
			case BIT_OR :
			case BIT_XOR :
			case BIT_MINUS :
			case BIT_SHIFT_LEFT :
			case BIT_SHIFT_RIGHT :
			case BIT_NOT : {
				// generate number from number(s)
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.NUMERIC_SORT, 0);
				sort = freshForm(CRS.NUMERIC_SORT, 0);
				break;
			}
			case ELAPSED:
				sort = freshForm(CRS.NUMERIC_SORT, 0);
				break;
			case PROFILE_ENTER : {
				Variable alpha = freshSortVariable();
				argumentsorts[0] = freshForm(CRS.NUMERIC_SORT, 0);
				argumentsorts[1] = freshForm(CRS.STRING_SORT, 0);
				argumentsorts[2] = factory.newVariableUse(alpha);
				sort = factory.newVariableUse(alpha);
				break;
			}
			case PROFILE_EXIT : {
				Variable alpha = freshSortVariable();
				argumentsorts[0] = freshForm(CRS.NUMERIC_SORT, 0);
				argumentsorts[1] = factory.newVariableUse(alpha);
				sort = factory.newVariableUse(alpha);
				break;
			}
			case EQ :
			case DEEP_EQ :
			case NE :
			case SAME_VARIABLE :
			case LESSER_VARIABLE : {
				// test two values of identical type
				Variable alpha = freshSortVariable();
				argumentsorts[0] = factory.newVariableUse(alpha);
				argumentsorts[1] = factory.newVariableUse(alpha);
				sort = freshForm(CRS.BOOLEAN_SORT, 0);
				
				if (primitive == Primitive.DEEP_EQ && argumentsorts.length == 3)
					argumentsorts[2] = freshForm(CRS.BOOLEAN_SORT, 0);
				break;
			}
			case BIT_SUB_SET_EQ :
			case LT :
			case GT :
			case LE :
			case GE :
			case NUMEQ :
			case NUMNE : {
				// Test two numeric values
				argumentsorts[0] = freshForm(CRS.NUMERIC_SORT, 0);
				argumentsorts[1] = freshForm(CRS.NUMERIC_SORT, 0);
				sort = freshForm(CRS.BOOLEAN_SORT, 0);
				break;
			}
			case LITERAL : {
				// Test one value...
				argumentsorts[0] = factory.newVariableUse(freshSortVariable());
				sort = freshForm(CRS.BOOLEAN_SORT, 0);
				break;
			}
			case MATCH :
			case NOT_MATCH : {
				// match has two arguments and is of the same type
				Variable alpha = freshSortVariable();
				argumentsorts[0] = factory.newVariableUse(alpha);
				argumentsorts[1] = factory.newVariableUse(alpha);
				sort = factory.newVariableUse(alpha);
				break;
			}
			case PICK : 
			case REVERSE_PICK : {
				argumentsorts[0] = freshForm(CRS.NUMERIC_SORT, 0);
				argumentsorts[1] = freshForm(CRS.LIST_SORT, 1);
				sort = factory.newVariableUse(subSort(argumentsorts[1], 0).variable());
				break;
			}
			case LIST_LENGTH : {
				argumentsorts[0] = freshForm(CRS.LIST_SORT, 1);
				sort = freshForm(CRS.NUMERIC_SORT, 0);
				break;
			}			
			case IF :
			case IF_ZERO :
			case IF_EMPTY :
			case IF_DEF :
			case IF_LINEAR : {
				Variable alpha = freshSortVariable();
				if (primitive == Primitive.IF) argumentsorts[0] = freshForm(CRS.BOOLEAN_SORT, 0);
				else if (primitive == Primitive.IF_ZERO) argumentsorts[0] = freshForm(CRS.NUMERIC_SORT, 0);
				else if (primitive == Primitive.IF_EMPTY) argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
				else if (primitive == Primitive.IF_DEF) argumentsorts[0] = freshSortVariableUse();
				else
				{
					error("unknown " + CRS.EVAL_SYMBOL + "-construction in rule " + rulename + ": " + term);
					return null;
				}
				argumentsorts[1] = factory.newVariableUse(alpha);
				if (arity >= 3)
					argumentsorts[2] = factory.newVariableUse(alpha);
				sort = factory.newVariableUse(alpha);
				break;
			}
			case GET : 
			case GET_REF : {
				PropertiesHolder B = Util.propertiesHolder(term.sub(0));
				if (B == null || !(B instanceof PropertiesConstraintsWrapper))
				{
					// The system environment has type {$String:$String} but we can override that with Get[Sort]
					argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
					sort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : freshForm(CRS.STRING_SORT, 0));
					if (argumentsorts.length == 2)
						argumentsorts[1] = (GenericTerm) sort.copy(false, null);
					if (B != null && (B.propertyNames().iterator().hasNext() || B.propertyVariables().iterator().hasNext()))
						error("Rule " + rulename + " wrong use of $[{PROPERTIES}Get,...]: PROPERTIES should be a single reference meta-variable or omitted entirely for system environment.");
				}
				else
				{
					// Create sort variables for sorts unless result sort is given with Get[Sort].
					argumentsorts[0] = freshSortVariableUse();
					sort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : freshSortVariableUse());
					if (argumentsorts.length == 2)
						argumentsorts[1] = (GenericTerm) sort.copy(false, null);
					if (B.propertyNames().iterator().hasNext() || B.propertyVariables().iterator().hasNext()
							|| !(B instanceof PropertiesConstraintsWrapper) || !((PropertiesConstraintsWrapper) B).getLocalMetaProperties().isEmpty() ||((PropertiesConstraintsWrapper) B).getRef() == null) 
						error("Rule " + rulename + " wrong use of $[{PROPERTIES}Get,...]: PROPERTIES should be a single reference meta-variable or omitted entirely for system environment.");
				}
				break;
			}
			case KEYS : {
				GenericTerm elementSort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : freshSortVariableUse());
				GenericTerm[] sorts = {elementSort};
				sort = freshForm(factory.makeConstructor(CRS.LIST_SORT), sorts, null, null);
				break;
			}
			case FORMAT_NUMBER :
			case ENCODE_POINT : {
				// generate string from numeric
				argumentsorts[0] = freshForm(CRS.NUMERIC_SORT, 0);
				sort = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case SHOW :
			case SYMBOL : {
				// generate string from anything
				argumentsorts[0] = freshSortVariableUse();
				sort = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case HASH_CODE : {
				// generate numeric from anything
				argumentsorts[0] = freshSortVariableUse();
				sort = freshForm(CRS.NUMERIC_SORT, 0);
				break;
			}
			case COMPUTE :
			case PASS_LOCATION_PROPERTIES :  {
				// generate term from term
				Variable alpha = freshSortVariable();
				argumentsorts[0] = factory.newVariableUse(alpha);
				sort = factory.newVariableUse(alpha);
				break;
			}
			case DUMP :
			case PRINT :
			case ECHO :{
				// string and term to (same) term
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
				if (argumentsorts.length == 1)
					sort = factory.nil();
				else
				{
					Variable alpha = freshSortVariable();
					argumentsorts[1] = factory.newVariableUse(alpha);
					sort = factory.newVariableUse(alpha);
				}
				break;
			}
			case TRACE : {
				// optional string and term to (same) term
				Variable alpha = freshSortVariable();
				sort = factory.newVariableUse(alpha);
				if (argumentsorts.length == 1)
					argumentsorts[0] = factory.newVariableUse(alpha);
				else
				{
					argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
					argumentsorts[1] = factory.newVariableUse(alpha);
				}
				break;
			}
			case ERROR :{
				// error...all string arguments!
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);
				sort = freshSortVariableUse();
				break;
			}
			case FORGIVABLEERROR : {
				// term and all string
				Variable alpha = freshSortVariable();
				sort = factory.newVariableUse(alpha);
				
				for (int i = 0; i < argumentsorts.length - 1; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);

				argumentsorts[argumentsorts.length - 1] = factory.newVariableUse(alpha);
				break;
			}
			case FORMAT: {
				// error...all string arguments!
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0);
				sort = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case LOAD_TERM : {
				sort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : freshSortVariableUse());
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case PARSE_URL :
			case PARSE_TEXT : {
				sort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : freshSortVariableUse());
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
				argumentsorts[1] = freshForm(CRS.STRING_SORT, 0);
				break;
			}
			case SAVE_TERM : {
				Variable alpha = freshSortVariable();
				sort = factory.newVariableUse(alpha);
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0);
				argumentsorts[1] = freshSortVariableUse();
				argumentsorts[2] = factory.newVariableUse(alpha);
				break;
			}
			
			case FREE_VARIABLES : {
				GenericTerm variableSort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : factory.newVariableUse(freshSortVariable()));
				sort = freshForm(CRS.LIST_SORT, 1);
				setSubSort(sort, 0, variableSort);
				argumentsorts[0] = factory.newVariableUse(freshSortVariable());
				break;
			}
			case INTERSECT_VARIABLES :
			case UNION_VARIABLES :
			case EXCEPT_VARIABLES : {
				GenericTerm variableSort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : factory.newVariableUse(freshSortVariable()));
				sort = freshForm(CRS.LIST_SORT, 1);
				setSubSort(sort, 0, variableSort);
				argumentsorts[0] = sort;
				argumentsorts[1] = sort;
				break;
			}

			case CALL:
				sort = freshForm(CRS.STRING_SORT, 0); // Return sort
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0); // function  name
				for (int i = 1; i < arity; i ++)
					argumentsorts[i] = freshForm(CRS.STRING_SORT, 0); 
//				Variable alpha = freshSortVariable();
//				sort = factory.newVariableUse(alpha);
//				
//				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0); // function  name
//				
//				// Arguments can be of any types.
//				for (int i = 1; i < arity; i ++)
//				{
//					Variable beta = freshSortVariable();
//					argumentsorts[i] = factory.newVariableUse(beta);
//				}
				break;
			case TRYCALL:
				GenericTerm variableSort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : factory.newVariableUse(freshSortVariable()));
				sort = freshForm(CRS.TRYRESULT_SORT, 1); // Return sort name
				setSubSort(sort, 0, variableSort);
				
				argumentsorts[0] = freshForm(CRS.STRING_SORT, 0); // function  name
				
				if (term.sub(0) == null || term.sub(0).arity() != arity)
					error("Rule " + rulename + " Missing or wrong number of argument sort names. Use $[TryCall[returnSort, argSort1, ...], ...]");
				
				for (int i = 1; i < argumentsorts.length; i ++)
					argumentsorts[i] = (GenericTerm) term.sub(0).sub(i); 
				break;

			case VARIABLE_NAME_IS : {
				Variable alpha = freshSortVariable();
				sort = factory.newVariableUse(alpha);
				argumentsorts[0] = factory.newVariableUse(freshSortVariable());
				argumentsorts[1] = freshForm(CRS.STRING_SORT, 0);
				argumentsorts[2] = factory.newVariableUse(alpha);
				break;
			}

			case CAST :
				argumentsorts[0] = freshSortVariableUse();
				sort = (GenericTerm) (term.sub(0).arity() > 0 ? term.sub(0).sub(0) : freshSortVariableUse());
				break;

			case HAS_GRAMMAR :
			case PARSE :
			case PARSE_RESOURCE :
			case LOAD :
			case SAVE :
			case SCRIPT :
			case NORMALIZE :
			case IS_INTEGER :
			case SORT_OF :
			case CHECK_SORT_OF :
			case UNIFY :
			case CONSTRUCTION :
			case META_APPLICATION :
			case VARIABLE :
			case PROPERTIES :
			case PROPERTY_NAMED :
			case PROPERTY_NAMED_NOT :
			case PROPERTY_VARIABLE :
			case PROPERTY_VARIABLE_NOT :
			case PROPERTY_COLLECT :
			case IGNORE :
			default :
				for (int i = 0; i < argumentsorts.length; i++)
					argumentsorts[i] = freshSortVariableUse();
				sort = freshSortVariableUse();
				warning("use of $["+primitive.symbol+",...] in rule " + rulename + " not sort checked");
				break;
		}

		/*
		// construction operatiors
		if (cmd.equals("V"))
		{
			warning("use of $[V,...] in rule " + rulename + " means that badly sorted terms may appear");
			form[0] = freshForm(CRS.STRING_SORT, 0);
			sort = freshSortVariableUse();
		}

		else if (cmd.equals("M") || cmd.equals("C"))
		{
			arityCheck(term.sub(1), varSorts, metaSorts, rulename);
			Term arg2 = term.sub(2);
			while (arg2.arity() == 2)
			{
				arityCheck(term.sub(0), varSorts, metaSorts, rulename);
				arg2 = arg2.sub(1);
			}
			if (cmd.equals("M"))
			{
				warning("use of $[M,...] in rule " + rulename + " means that badly sorted terms may appear");
				sort = freshSortVariableUse();
			}
			else if (cmd.equals("C") && term.sub(0).arity() == 0)
			{
				warning("use of $[C,...] in rule " + rulename + " means that badly sorted terms may appear");
				sort = freshSortVariableUse();
			}
			else
			{
				sort = term.sub(0).sub(0);
				factory.checkLegalSort(sort, new HashSet<Variable>());
			}
		}
		 */

		return sort;
	}
	
	/**
	 * Given a set of rules, which all carry sort annotations with the constructors,
	 * and sort annotations for all variables and meta-variables occurring in these
	 * rules (as saved in the relevant ...SortsPerRule variables), attempts to unify
	 * the sorts in such a way that the rules are well-sorted. 
	 * @param rules the rules to sortify
	 * @throws CRSException if the unification fails
	 */
	private void mainSortification(Map<String,GenericRule> rules) throws CRSException
	{
		/* checks which do not take the property sets into account */
		Map<Variable,Term> theta = new HashMap<Variable,Term>();
		for (Map.Entry<String,GenericRule> e : rules.entrySet())
		{
			String name = e.getKey();
			GenericRule rule = e.getValue();
			
			Term lsort = termUnification(rule.getPattern(), theta, rule.getName());
			Term rsort = termUnification(rule.getContractum(), theta, rule.getName());
			if (!Unifier.unify_help(lsort, rsort, theta, factory))
			{
				error("The two sides of rule " + name + " cannot be unified. The rule expects a " + lsort.toString() + " but the contractum sort is " + rsort.toString());
				theta.clear();
			}
		}
		
		/* obtaining a result */
		sortSubstituteSystem(theta);

		/* check whether all sorts with syntactic variables are declared or unknown */
		checkSyntacticVariables(theta, false);

		/* do checks on the property sets */
		checkPropertyConstraints(rules, theta);
		
		/* if respecting overloaded sort declarations gives extra information,
		 * use that additional information - we may need to do this several
		 * times, because the additional information could cause further
		 * overloaded symbols to become known
		 */
		if (nonTrivialOverloading)
		{
			theta = overloadTestResults(rules);
			while (theta != null) 
			{
				sortSubstituteSystem(theta);
				theta = overloadTestResults(rules);
			}
		}
		
		factory.errorCheck("Errors in the unification process prevent continuation of the Sorter.");
	}
	
	/**
	 * Given a term where all constructors have a polymorphic sort denotation,
	 * and sort denotations for all variables and meta-variables occurring in
	 * the term, this attempts to find a most general unification of the sort
	 * variables to make the whole term well-sorted.  This unification will be
	 * saved in theta (in fact, theta^omega as discussed in Unifier.java will
	 * be the required sort substitution), and respect the substitutions
	 * already present in theta.
	 * @param term a term with sort denotations for all symbols, save in the
	 * 	 relevant...SortsPerRule variables
	 * @param theta a sort substitution which must be respected, and which will
	 *   be updated, so when done, term theta^omega will be a well-sorted term
	 * @param rulename used for errormessages and to look up sort denotations
	 * @return the sort of term
	 * @throws CRSException if unification fails
	 */
	private Term termUnification(Term term, Map<Variable,Term> theta, Constructor rulename) throws CRSException
	{
		if (term == null) return null;
		switch (term.kind())
		{
			case VARIABLE_USE :
				return varSortsPerRule.get(rulename.symbol()).get(term.variable());

			case META_APPLICATION : {
				Term[] declaration = metaSortsPerRule.get(rulename.symbol()).get(term.metaVariable());
				for (int i = 0; i < term.arity(); i++)
				{
					Term test = termUnification(term.sub(i), theta, rulename);
					if (!Unifier.unify_help(declaration[i+1], test, theta, factory))
					{
						error("cannot unify " + Unifier.repeat_apply(test, theta, factory) + " and " +
								Unifier.repeat_apply(declaration[i+1], theta, factory) + " in rule " +
								rulename + " (given input sort " + (i+1) + " of meta-variable " +
								term.metaVariable() + " and expected input sort respectively).");
						theta.clear();
						return declaration[0];
					}
				}
				PropertiesHolder ph = Util.propertiesHolder(term);
				if (ph != null) propertiesUnification(ph, theta, rulename);
				return declaration[0];
			}
			case CONSTRUCTION : {
				if (Util.symbol(term).equals(CRS.EVAL_SYMBOL) && term.arity() > 0)
					return dollarConstructionUnification(term, theta, rulename);

				Pair<Term,Term> declaration = constructorSortsPerRule.get(rulename.symbol()).get(term);
				Term sort = declaration.head();
				Term form = declaration.tail();
				for (int i = 0; i < term.arity(); i++)
				{
					Variable[] termBinders = term.binders(i);
					Map<Variable,Term> varSorts = varSortsPerRule.get(rulename.symbol());
					for (int j = 0; j < termBinders.length; j++)
						varSorts.put(termBinders[j], binderSort(form, i, j));
					Term subsort = termUnification(term.sub(i), theta, rulename);
					if (!Unifier.unify_help(subSort(form,i), subsort, theta, factory))
					{
						String constructor = Util.symbol(term);
						if (constructor.equals(CRS.EVAL_SYMBOL))
							constructor += Util.symbol(term.sub(0));
						error("cannot unify " + Unifier.repeat_apply(subsort, theta, factory) + " and " +
								Unifier.repeat_apply(subSort(form,i), theta, factory) + " in rule " + rulename +
								" (given input sort " + (i+1) + " of constructor " +
								constructor + " and expected sort respectively)");
						theta.clear();
					}
					for (int j = 0; j < termBinders.length; j++)
						varSorts.remove(termBinders[j]);
				}

				// recursive work on the property set
				propertiesUnification(Util.propertiesHolder(term), theta, rulename);
				return sort;
			}
		}
		return null; //not reached
	}

	/**
	 * helping function for termUnification, recursively calls termUnification
	 * for all values in the given property set
	 * @param ph a property set (might be null)
	 * @param rulename used for printing error messages and looking up denotations
	 * @throws CRSException if not all valuables can be unified
	 */
	private void propertiesUnification(PropertiesHolder ph, Map<Variable,Term> theta, Constructor rulename) throws CRSException
	{
		if (ph == null)
			return;
		
		for (String k : ph.propertyNames())
			termUnification(ph.getProperty(k), theta, rulename);

		for (Variable k : ph.propertyVariables())
			termUnification(ph.getProperty(k), theta, rulename);

		if (ph instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
			for (String k : pcw.propertyMetaVariables())
				termUnification(pcw.getMetaProperty(k), theta, rulename);
		}
	}

	/**
	 * Do the work of {@link #termUnification(Term, Map, String)} in case the given term is a dollar-construction,
	 */
	private Term dollarConstructionUnification(Term term, Map<Variable,Term> theta, Constructor rulename) throws CRSException
	{
		final int arity = term.arity();
		if (arity == 0)
			return null;
		GenericTerm[] argumentsorts =  new GenericTerm[arity-1];
		GenericTerm resultsort = dollarSortForms(term, argumentsorts, rulename);
		for (int i = 0; i < arity-1; i++)
		{
			Term subsort = termUnification(term.sub(i+1), theta, rulename);
			if (subsort != null && !Unifier.unify_help(argumentsorts[i], subsort, theta, factory))
			{
				String constructor = Util.symbol(term);
				if (constructor.equals(CRS.EVAL_SYMBOL))
					constructor += Util.symbol(term.sub(0));
				error("cannot unify " + Unifier.repeat_apply(subsort, theta, factory) + " and " +
						Unifier.repeat_apply(argumentsorts[i], theta, factory) + " in rule " + rulename +
						" (given input sort " + (i+1) + " of constructor " +
						constructor + " and expected sort respectively)");
				theta.clear();
			}
		}
		propertiesUnification(Util.propertiesHolder(term.sub(0)), theta, rulename);
		return resultsort;
	}
	
	/**
	 * In declaredConstructors, some of the information on the sort constraints
	 * for overloaded symbols may have been dropped (if there are multiple
	 * instances of the overloaded symbol which have the same full arity).
	 * This method checks whether the current sort denotations for the rules
	 * respect the original declarations, that is, that for all occurrences
	 * F : &lt;&iota;,F[&rho;1,...,&rho;n]&gt; anywhere in a rule where F is an overloaded symbol,
	 * this sort declaration matches with at least one of the declarations F
	 * was declared with.  An exception is thrown if this is not the case.
	 *<p>
	 * If the sort declaration &lt;&iota;,F[&rho;1,...,&rho;n]&gt; matches with _exactly_ one
	 * overloaded declaration of F, this might give new information (for
	 * instance if F has declarations &lt;Bool,F[Bool]&gt; and &lt;Nat,F[Nat]&gt; and
	 * here occurs with input sort Nat, then we know that it's output sort must
	 * be Nat as well).  If any information like this is found, the resulting
	 * sort substitution is returned.  If no such information is found, null is
	 * returned.
	 * @param rules the rules to sort check
	 * @return null if no new information was found, otherwise a sort
	 * 	 substitution which should be applied on the whole system (this sort
	 *   substitution will map sort variables to monomorphic sorts)
	 * @throws CRSException if the current sort denotations do not respect the
	 *   original definitions
	 */
	private Map<Variable,Term> overloadTestResults(Map<String,GenericRule> rules) throws CRSException
	{
		Map<Variable,Term> sortSubstitution = null;
			// used to keep track of the return value

		// make a list of all non-trivially overloaded symbols in the ru)les,
		// together with the rule name
		LinkedList<Term> stack = new LinkedList<Term>();
		LinkedList<Pair<Term,Pair<String,String>>> overloads = new LinkedList<Pair<Term,Pair<String,String>>>();
		
		for (Entry<String,GenericRule> e : rules.entrySet())
		{
			stack.add(e.getValue().getPattern());
			stack.add(e.getValue().getContractum());
			while (!stack.isEmpty())
			{
				Term last = stack.removeLast();
				for (int i = 0; i < last.arity(); i++) stack.add(last.sub(i));
				if (last.kind() != Kind.CONSTRUCTION) continue;
				String F = Util.symbol(last) + "-";
				if (!overloadedConstructors.containsKey(F+"1")) continue;
				String arcode = getArityCode(last);
				int fits = -1;
				for (int i = 1; fits == -1 && declaredConstructors.containsKey(F+i); i++)
				{
					if (arcode.equals(getArityCode(declaredConstructors.get(F+i).tail()))) fits = i;
				}
				F = F + fits;
				if (overloadedConstructors.get(F).size() == 1) continue;
				overloads.addLast(new Pair<Term,Pair<String,String>>(last, new Pair<String,String>(F,e.getKey())));
			}
		}
		
		// for all the non-trivially overloaded symbols we encountered, see whether they give new information
		for (Pair<Term,Pair<String,String>> info : overloads)
		{
			Term term = info.head();
			String F = info.tail().head();
			String rulename = info.tail().tail();
			Pair<Term,Term> declaration = constructorSortsPerRule.get(rulename).get(term);
			Term sort = declaration.head();
			Term form = declaration.tail();
			Set<Pair<Term,Term>> possibleDeclarations = new HashSet<Pair<Term,Term>>();
			Map<Variable,Term> unifier = null;
			for (Pair<Term,Term> pair : overloadedConstructors.get(F))
			{
				Map<Variable,Term> theta = new HashMap<Variable,Term>();
				Term psort = pair.head();
				Term pform = pair.tail();
				boolean ok = true;
				
				if (sort.kind() == Kind.VARIABLE_USE && sortSubstitution != null && sortSubstitution.containsKey(sort.variable()))
						sort = sortSubstitution.get(sort.variable());
				if (!Unifier.instantiates(psort, sort, theta, factory)) ok = false;
				for (int i = 0; i < form.arity() && ok; i++)
				{
					Term sub = subSort(form, i);
					if (sub.kind() == Kind.VARIABLE_USE && sortSubstitution != null && sortSubstitution.containsKey(sub.variable()))
						sub = sortSubstitution.get(sub.variable());
					if (!Unifier.instantiates(subSort(pform,i), sub, theta, factory)) ok = false;
					for (int j = 0; j < form.binders(i).length && ok; j++)
					{
						Term xsort = binderSort(form, i, j);
						if (xsort.kind() == Kind.VARIABLE_USE && sortSubstitution != null && sortSubstitution.containsKey(xsort.variable()))
							xsort = sortSubstitution.get(xsort.variable());
						Term ysort = binderSort(pform, i, j);
						if (!Unifier.instantiates(ysort, xsort, theta, factory)) ok = false;
					}
				}
				if (ok) { possibleDeclarations.add(pair); unifier = theta; }
			} 

			if (possibleDeclarations.size() == 0)
			{
				int k = F.lastIndexOf('-');
				error("could not determine sort for (overloaded) constructor " +
					  F.substring(0,k) + " in rule " + rulename);
			}
			if (possibleDeclarations.size() != 1 || unifier.isEmpty()) continue;
			if (sortSubstitution == null) sortSubstitution = new HashMap<Variable,Term>();
			for (Entry<Variable,Term> e : unifier.entrySet())
				sortSubstitution.put(e.getKey(), e.getValue());
		}
		
		return sortSubstitution;
	}
	
	/**
	 * Checks constraints on sort sets, makes sure they are all satisfied
	 * (possibly applying some additional sort substitution in the process),
	 * and save the derived conclusions about which sorts have which property
	 * sets.
	 * @param theta TODO
	 * @throws CRSException possible result of an error if the constraints cannot be satisfied.
	 */
	private void checkPropertyConstraints(Map<String,GenericRule> rules, Map<Variable, Term> theta) throws CRSException
	{
		/********************
		 * To make sure the property constraints are satisfied, we should do the following:
		 * - collect all constraints k:v ∈ &lt;sortset with sort &iota;&gt;
		 * - collect all constraints k:&lt;something&gt; ∈ &lt;sortset with sort &iota;&gt;
		 * - collect all constraints "#&Gamma; is used on the left with sort 1 and on the right with
		 * 	 sort 2, so &lt;sortset with sort 1&gt; ⊆ &lt;sortset with sort 2&gt;";
		 *   this is probably not intended, so we check this for inclusion ONLY if both the
		 *   sorts have sort sets declared, otherwise we save it as an equality constraint
		 * - from the information k:v ∈ &lt;sortset with sort &iota;&gt; create new sort sets
		 * The sorts in question are represented with an object, and are all either strings
		 * or variables.  If they would be anything else, they could not have a sort set.
		 ********************/
		
		// STEP 1: determine all the requirements for inclusion and equality
		Map<String,String> setMetaVarDef = new NonNullHashMap<String,String>();
			// map reference meta-variables #&Gamma; to the sort set designator (S+sort or F+function-symbol) they belong to
		MultiMap<String,Pair<Pair<Object,Term>,Constructor>> sortSetContains = new HashMultiMap<String,Pair<Pair<Object,Term>,Constructor>>();
			// map sort designators to triples <key sort, value sort, rule name where this requirement comes from>;
			// if the value sort is null this indicates just a requirement on the key being present
		Map<String,String> sortSetEquals = new NonNullHashMap<String,String>();
			// map sort set  designator to a "main" sort set designator with the same sort set (S-sort never maps to F-symbol)

		Set<Variable> syntacticVariableSorts = new HashSet<Variable>();
		for (Entry<String,GenericRule> e : rules.entrySet())
		{
			determineSortSetConstraints(e.getValue().getPattern(), true, e.getValue().getName(), setMetaVarDef, sortSetEquals, sortSetContains, syntacticVariableSorts, new HashMap<Variable,Term>(), theta);
			determineSortSetConstraints(e.getValue().getContractum(), false, e.getValue().getName(), setMetaVarDef, sortSetEquals, sortSetContains, syntacticVariableSorts, new HashMap<Variable,Term>(), theta);
		}
		
		// STEP 2: check whether constraints for declared set sorts are satisfied
		//Map<Variable,Term> foobar = new HashMap<Variable,Term>();
		for (String sort : sortSetContains.multiKeySet())
		{
			if (factory.sortsetFor(sort) == null) continue;
			if (sort.startsWith("S"))
			{
				for (Pair<Pair<Object,Term>,Constructor> entry : sortSetContains.multiGet(sort))
				{
					Object key = entry.head().head();
					testMembership(key, entry.head().tail(), factory.sortsetFor(sort.substring(1)),
							key instanceof Variable && syntacticVariableSorts.contains((Variable) key),
							sort, entry.tail(), theta
					);
				}
			}
		}
		
		// STEP 3a: if there are sorts which occur with a property set but do not have one
		// declared, and we do not have any key/value pairs to derive the sort set, protest
		for (Entry<String,String> e : setMetaVarDef.entrySet())
		{
			String sortdesignate = e.getValue();
			if (sortSetEquals.containsKey(sortdesignate))
				sortdesignate = sortSetEquals.get(sortdesignate);
			String sortname = sortdesignate.substring(1);
			if (sortdesignate.startsWith("S") && !sortSetContains.multiContainsKey(sortdesignate) && factory.sortsetFor(sortname) == null)
				error("Encountered property set for sort " + sortname + " which is not declared to have a sort set; "+
					  "if this is intentional, please declare the sort set of a function sort set for rule " + e.getKey());
		}
		
		// STEP 3b: deal with the remaining sort sets
		for (String sortdesignate : sortSetContains.multiKeySet())
		{
			if (sortdesignate == null)
				continue;
			String symbol = sortdesignate.substring(1);
			if (sortdesignate.startsWith("S") && factory.sortsetFor(symbol) != null) continue;
//Kris: allow syntactic variables in sort sets...			
//			if (factory.sortAllowsVariables(sort))
//			{
//				error("sort with syntactic variables (" + sort + ") used with a property set in " + 
//					  sortSetContains.get(sort).iterator().next().tail());
//				continue;
//			}
			
			// collect all the key:value pairs with known keys
			Map<String,Term> sortset = new HashMap<String,Term>();
			for (Pair<Pair<Object,Term>,Constructor> entry : sortSetContains.multiGet(sortdesignate))
			{
				Object k = entry.head().head();
				if (k instanceof Variable && theta.containsKey(k))
				{
					while (theta.containsKey(k) && theta.get(k).kind() == Kind.VARIABLE_USE)
						k = theta.get(k).variable();
					if (theta.containsKey(k) && theta.get(k).kind() == Kind.CONSTRUCTION && theta.get(k).arity() == 0)
						k = Util.symbol(theta.get(k));
				}
				if (!(k instanceof String)) continue;
				String key = (String) k;
				if (!sortset.containsKey(key))
					sortset.put(key, null);
				Term oldvalue = sortset.get(key);
				Term newvalue = entry.head().tail();
				if (newvalue == null) continue;
				if (oldvalue == null && newvalue != null) { sortset.put(key, newvalue); continue; }
				if (!Unifier.unify_help(oldvalue, newvalue, theta, factory))
				{
					error("cannot determine sort set for " + (sortdesignate.startsWith("S") ? "sort " : "function ") + symbol + ": used " +
						  "keys of sort " + key + " are used with non-unifiable values.");
					return;
				}
			}
			
			// choose the sort set for this sort as the union of the known requirements,
			// IF it is monomorphic
			String sortsetdescription = "";
			for (String k : sortset.keySet())
			{
				Set<Variable> FV = new HashSet<Variable>();
				Term valueSort = sortset.get(k);
				if (valueSort == null && symbol != null)
				{
					Set<Pair<Term,Term>> sortForms = factory.formsOf(symbol);
					for (Pair<Term,Term> p : sortForms)
					{
						PropertiesHolder formSortSet = Util.propertiesHolder(p.getValue());;
						Term sort = formSortSet.getProperty(k);
						if (sort != null)
						{
							valueSort = sort;
							break;
						}
					}
				}
				if (valueSort != null) valueSort = Unifier.repeat_apply(valueSort, theta, factory);
				if (valueSort == null || FV.size() != 0)
				{
					error("cannot determine sort set for : value for " + (sortdesignate.startsWith("S") ? "sort " : "function ") + symbol + ": " +
						  "key " + k + " can be resolved only to " + valueSort + " which " +
						  "is not monomorphic.");
					return;
				}
				sortsetdescription += k + " : " + valueSort.toString() + "; ";
				sortset.put(k, valueSort);
			}
			if (sortdesignate.startsWith("S"))
			{
//				for (Pair<Pair<Object,Term>,Constructor> entry : sortSetContains.multiGet(sortdesignate))
//				{
//					System.out.println(entry.tail().symbol());
//				}
				warning((sortdesignate.startsWith("S") ? "sort " : "function ") + symbol + " used with sort sets, even though this is not declared.  From usage, the sort set is guessed to be: { " + sortsetdescription + "}.");
				factory.setSortsetFor(symbol, sortset);
			}
			else //sortdesignate.startsWith("%")
			{
//				// Add requirements to function symbol form!
//				Set<Pair<Term,Term>> forms = factory.formsOf(symbol);
//				if (forms != null && forms.size() == 1)
//				{
//					Pair<Term,Term> p = forms.iterator().next();
//					GenericTerm f = (GenericTerm) p.tail().copy(false, null);
//		        	if (f.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(f)))
//		        		f = f.sub(0);
//					// old form brutally reused
//					Constructor c = Util.wrapWithProperties(factory, f.constructor(), sortset, null);
//					factory.setSortForm(p.head(), null, factory.newConstruction(c, f.allBinders(), f.allSubs()), factory.isFunction(symbol), true);
//				}
//				else
//				{
//					warning((sortdesignate.startsWith("S") ? "sort " : "function ") + symbol + " used with sort sets, even though this is not declared.  From usage, the sort set is guessed to be: { " + sortsetdescription + "}.");
//				}
			}

			// and check whether the rest of the requirements respects this sort set!
			for (Pair<Pair<Object,Term>,Constructor> entry : sortSetContains.multiGet(sortdesignate))
			{
				Object k = entry.head().head();
				if (!(k instanceof Variable)) continue;
				testMembership(k, entry.head().tail(), sortset,
							   syntacticVariableSorts.contains((Variable) k),
							   symbol, entry.tail(), theta
							  );
			}
		}
		
		// STEP 4: finish off by substituting all that we've learned!
		// This includes requiring that any remaining syntactic variables
		// have been resolved to having a syntactic sort.
		if (!theta.isEmpty()) sortSubstituteSystem(theta);
		checkSyntacticVariables(theta, true);
	}

	/**
	 * Given that the term is completely sorted (all sort denotations are
	 * given in the the varSortsPerRule, metaSortsPerRule and
	 * constructorSortsPerRule variables), return the output sort of the given
	 * term.
	 * @param s a term whose output sort to determine
	 * @param rulename the rule that the given term is part of
	 * @param boundSorts TODO
	 * @return the output sort of s
	 */
	private Term getSort(Term s, String rulename, Map<Variable, Term> boundSorts)
	{
		Term sort;
		if (s == null)
			sort = null;
		switch (s.kind())
		{
			case VARIABLE_USE :
				sort = varSortsPerRule.get(rulename).get(s.variable());
				if (sort == null)
					sort = boundSorts.get(s.variable());
				break;
			case META_APPLICATION :
				sort = metaSortsPerRule.get(rulename).get(s.metaVariable())[0];
				break;
			default :
				sort = constructorSortsPerRule.get(rulename).get(s).head();
		}
		if (sort == null)
			return null;
		return sort;
	}
	
	/**
	 * Determine the sort set constraints for the given term, which is part of a rule.
	 * Save these constraints in the parameters.
	 * @param term the term to investigate (recursively)
	 * @param left whether the term is part of the left-hand side of a rule or not
	 * @param rulename the name of the rule the term is part of
	 * @param setMetaVarDef map reference meta-variables #&Gamma; to the sort set designator (S+sort or F+function) they belong to
	 * @param sortSetEquals when constraints ensure that sortset(sort A) =
	 *   sortset(sort B) one is assigned to the other as its ``main'' sort set designator
	 * @param sortSetContains map sort designates to triples &lt;key sort, value sort, rule name
	 * 	 where this requirement comes from&gt;; value sort may be null if the only
	 *   requirement is the presence of some key
	 * @param freeVariables keep track of the sorts of free variables for which the
	 *   sort is thus far unknown, as those sorts must be a sort with syntactic
	 *   variables, which can often make the difference in determining membership
	 *   of a given sort set
	 * @param boundVariables to keep track of the sorts of free variables, we
	 *   must also know which variables are bound, and we keep track of the sorts
	 *   of these variables.
	 * @param theta map from sort variables to sorts
	 */
	private void determineSortSetConstraints(Term term, boolean left, Constructor rulename,
			Map<String,String> setMetaVarDef, Map<String,String> sortSetEquals,
			MultiMap<String,Pair<Pair<Object,Term>,Constructor>> sortSetContains,
			Set<Variable> freeVariables, Map<Variable,Term> boundVariables, Map<Variable, Term> theta) throws CRSException
	{
		// Recurse into subterms.
		for (int i = 0; i < term.arity(); i++)
		{
			if (i == 0 && term.kind() == Kind.CONSTRUCTION && Util.symbol(term).equals(CRS.EVAL_SYMBOL))
				continue;

			if (term.binders(i).length > 0)
			{
				Term form = constructorSortsPerRule.get(rulename.symbol()).get(term).tail();
				PropertiesHolder A = Util.propertiesHolder(form.sub(i));
				for (int j = 0; j < term.binders(i).length; j++)
					boundVariables.put(term.binders(i)[j], A.getProperty(form.binders(i)[j]));
			}
			determineSortSetConstraints(term.sub(i), left, rulename, setMetaVarDef, sortSetEquals, sortSetContains, freeVariables, boundVariables, theta);
			for (int j = 0; j < term.binders(i).length; j++)
				boundVariables.remove(term.binders(i)[j]);
		}
		
		// deal with $[{#&Gamma;}Get,a,b]
		if (term instanceof GenericEvaluator)
		{
			GenericEvaluator eval = (GenericEvaluator) term;
			switch (eval.primitive())
			{
				case GET :
				case GET_REF : {
					PropertiesHolder op = Util.propertiesHolder(eval.sub(0));
					if (left)
						error("$[Get,...] occurs in the left-hand side of rule " + rulename + "; should only occur on the right.");
					else if (op == null || !(op instanceof PropertiesConstraintsWrapper))
					{
						// System environment constraints already recorded by arityCheck.
					}
					else
					{
						String ref = rulename + " -- " + ((PropertiesConstraintsWrapper) op).getRef();
						if (!setMetaVarDef.containsKey(ref))
							error("Unconstrained reference meta-variable in $[Get,...] in rule " + rulename + ": " + ref);
						else
						{
							Term keysort = getSort(term.sub(1), rulename.symbol(), boundVariables);
							Object ks = (keysort.kind() == Kind.VARIABLE_USE ? keysort.variable() : Util.symbol(keysort));
							sortSetContains.multiAdd(setMetaVarDef.get(ref), new Pair<Pair<Object,Term>,Constructor>(new Pair<Object,Term>(ks, getSort(term, rulename.symbol(), boundVariables)), rulename));
						}
					}
					break;
				}
			}
		}

		if (!hasPropertySet(term)) return;
		// We have to check the properties on term.
		String sortsetdesignate = null;

		// Identify any function-specific sortset.
		List<Pair<Term,Term>> functionSortSet = new ArrayList<Pair<Term,Term>>();
		if (term.kind() == Kind.CONSTRUCTION && factory.isFunction(Util.symbol(term)))
		{
			Constructor c = term.constructor();
			Set<Pair<Term,Term>> sortforms = factory.formsOf(c.symbol());
			if (sortforms != null && sortforms.size() == 1)
			{
				Term form = sortforms.iterator().next().tail();
				if (Util.hasNonVariableProperties(form))
				{
					sortsetdesignate = "%"+Util.symbol(form);
					for (Pair<Term,Term> p : Util.allProperties(Util.propertiesHolder(form), factory))
						functionSortSet.add(new Pair<Term, Term>(p.head(), p.tail()));
				}
			}
		}
		
		// If no function sort set is available then look for one for the sort.
		if (sortsetdesignate == null)
		{
			Term sort = getSort(term, rulename.symbol(), boundVariables);
			if (SortUtil.isBuiltinSort(Util.symbol(sort)))
			{
				//error("rule " + rulename + " uses a property set on a literal (" + term + ").");
				//return;
			}
			else if (sort.kind() == Kind.VARIABLE_USE)
			{
				// We attempt to constrain these later.
			}
			else
			{
				// Try the sort set (or recorded alias).
				sortsetdesignate = "S" + Util.symbol(sort);
				if (sortSetEquals.containsKey(sortsetdesignate))
					sortsetdesignate = sortSetEquals.get(sortsetdesignate);
			}
		}

		// Deal with the actual properties on term.
		PropertiesHolder ph = Util.propertiesHolder(term);
		
		// deal with a possible reference meta-variable #&Gamma;
		String ref = null;
		if (ph instanceof PropertiesConstraintsWrapper)
			ref = ((PropertiesConstraintsWrapper) ph).getRef();
		if (ref != null)
		{
			String originalref = ref;
			ref = rulename + " -- " + ref;
			if (left)
			{
				// In a rule pattern this defines the sort of the properties reference.
				if (sortsetdesignate != null) setMetaVarDef.put(ref, sortsetdesignate);
			}
			else
			{
				// In a rule contractum the properties reference must already be sorted.
				boolean known = false;
				// Get the sort set designate from the pattern (or the alias).
				String othersortsetdesignate = setMetaVarDef.get(ref);
				if (sortSetEquals.containsKey(othersortsetdesignate))
					othersortsetdesignate = sortSetEquals.get(othersortsetdesignate);
				if (othersortsetdesignate == null)
				{
					error("rule reference meta-variable " + ref + " not defined!");
					return;
				}
				if (othersortsetdesignate.startsWith("%"))
				{
					// The ref sort set is already associated with a function constructor. //Kris
					known = true;
					// If we have no local designate we got it now!
					if (sortsetdesignate == null)
						sortsetdesignate = othersortsetdesignate;
				}
				else // othersortdesignate.startsWith("S")
				{
					if (sortsetdesignate == null)
					{
						warning("rule " + rulename + " uses an unconstrained property set at a position where sort is polymorphic so sort set could not be derived.");
					}
					else if (!sortsetdesignate.equals(othersortsetdesignate))
					{
						// We need to unify two sort set designates.
						if (sortsetdesignate.startsWith("S"))
						{
							String sortcons = sortsetdesignate.substring(1);
							String othersortcons = othersortsetdesignate.substring(1);
							Map<String,Term> S = factory.sortsetFor(othersortcons);
							Map<String,Term> T = factory.sortsetFor(sortcons);
							if (S == null && T == null)
							{
								// term has no function symbol sort set and term's sort has no data sort set...
								warning("in " + rulename + " rule reference meta-variable " + ref + " is used where no sort sets have been defined (make sure the subexpressions of sort " + othersortcons + 
										" and " + sortcons + " have sorts sets defined).");
							}
							else if (T == null)
							{
								// term has no function symbol sort set and term's sort has no data sort set...
								warning("in " + rulename + " rule reference meta-variable " + originalref + " causes unusual requirement [sort set for " + othersortcons + " = " + S  +
										"] ⊆ [sort set for " + sortcons + " is undefined].  It is recommended to declare the data sort set for sort " + sortcons + ".\n" +
								"Assuming equality of sort sets was intended.");
							}
							else if (S == null)
							{
								// reference variable has no function symbol sort set and no data sort set...
								warning("rule reference meta-variable " + originalref + " causes unusual requirement [sort set for " + othersortcons + " is undefined]" +
										" ⊆ [sort set for " + sortcons + " = " + T + "].  If you intended " +
										"strict inclusion, please declare the sort set for these sorts.\n" +
								"Assuming equality of sort sets was intended.");
							}
							else
							{
								known = true;
//								for (String k : S.keySet())
//								{
//									if (!T.containsKey(k) || !Unifier.equalSorts(factory, S.get(k), T.get(k)))
//									{
//										error("sorts cannot be unified for the reference meta-variable " + originalref + " in the rule " + rulename +
//												"\n\t" + othersortcons + " sort set is: " + S + "\n\t"
//												+ sortcons + " sort set is: " + T);
//										break;
//									}
//								}
							}
						}
					}
				}
				// if they're not known sort sets, say that they must be equal!
				if (!known)
				{
					String a, b;
					if (factory.sortsetFor(othersortsetdesignate.substring(1)) != null) { a = sortsetdesignate; b = othersortsetdesignate; }
					else { a = othersortsetdesignate; b = sortsetdesignate; }

					if (a != null && b != null)
						sortSetEquals.put(a, b);
					
					if (b != null)
						for (String k : sortSetEquals.keySet())
							if (sortSetEquals.get(k).equals(a)) sortSetEquals.put(k, b);
				}
			}
		}

		// grab all the key-value pairs
		Set<Pair<Term,Term>> contents = new HashSet<Pair<Term,Term>>();

		if (sortsetdesignate != null)
		{
			// Identify any function-specific sortset.
			if (functionSortSet.isEmpty() && sortsetdesignate.startsWith("%"))
			{
				Constructor c = factory.makeConstructor(sortsetdesignate.substring(1));
				Set<Pair<Term,Term>> sortforms = factory.formsOf(c.symbol());
				if (sortforms != null && sortforms.size() == 1)
				{
					Term form = sortforms.iterator().next().tail();
					for (Pair<Term,Term> p : Util.allProperties(Util.propertiesHolder(form), factory))
						functionSortSet.add(p);
				}
			}

			// grab pairs with variable keys
			for (Variable x : ph.propertyVariables())
			{
				// First get sort of key variable.
				Term keySort;
				if (boundVariables.containsKey(x)) keySort = boundVariables.get(x);
				else keySort = varSortsPerRule.get(rulename.symbol()).get(x);
				// Next get sort of value term.
				Term valueSort = null;
				if (ph.getProperty(x) != null)
					valueSort = getSort(ph.getProperty(x), rulename.symbol(), boundVariables);
				if (keySort != null && valueSort != null && valueSort.kind() == Kind.VARIABLE_USE && !functionSortSet.isEmpty()) 
				{
					for (Pair<Term,Term> p : functionSortSet)
					{
						if (Unifier.equalSorts(factory, keySort, p.head())) // key sort is right
						{
							if (valueSort.kind() == Kind.VARIABLE_USE)
								theta.put(valueSort.variable(), p.tail());
							// Replace with proper sort!
							valueSort = p.tail();
						}
					}
				}
				contents.add(new Pair<Term,Term>(keySort, valueSort));
				if (!boundVariables.containsKey(x) && keySort.kind() == Kind.VARIABLE_USE)
					freeVariables.add(keySort.variable());
			}
		}
		/*
		// grab pairs with constructor keys - outcommented because there are no actual constructor keys yet, only strings
		for (String F : A.propertyNames())
		{
			Term value = null;
			if (A.getProperty(F) != null) value = getSort(A.getProperty(F), rulename);
			Term key = null;
			if (declaredConstructors.containsKey(F + "-")) key = declaredConstructors.get(F + "-").head();
			else if (undeclaredConstructors.containsKey(F)) key = undeclaredConstructors.get(F).head();
			else if (factory.isInteger(F)) key = factory.constant(CRS.INT_SORT);
			else for (int i = 1; declaredConstructors.containsKey(F + "-" + i); i++)
			{
				if (getArityCode(declaredConstructors.get(F + "-" + i).tail()).equals("[]"))
					key = declaredConstructors.get(F + "-" + i).head();
			}
			if (key == null) { error("key " + F + " in rule " + rulename + " undeclared, shouldn't happen!"); return; }
			contents.add(new Pair<Term,Term>(key, value));
		}
		*/
		// grab pairs with string keys
		for (String F : ph.propertyNames())
		{
			Term keySort = factory.constant(factory.makeConstructor(CRS.STRING_SORT));
			Term valueSort = null;
			if (ph.getProperty(F) != null)
				valueSort = getSort(ph.getProperty(F), rulename.symbol(), boundVariables);
			if (keySort != null && (valueSort == null || valueSort.kind() == Kind.VARIABLE_USE) && !functionSortSet.isEmpty()) 
			{
				for (Pair<Term,Term> p : functionSortSet)
				{
					if (Unifier.equalSorts(factory, keySort, p.head())) // key sort is right
					{
						if (valueSort != null && valueSort.kind() == Kind.VARIABLE_USE)
							theta.put(valueSort.variable(), p.tail());
						// Replace with proper sort!
						valueSort = p.tail();
					}
				}
			}
			contents.add(new Pair<Term,Term>(keySort, valueSort));
		}
		// grab pairs with meta-variable keys
		if (ph instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper ph2 = (PropertiesConstraintsWrapper) ph;
			for (String Z : ph2.propertyMetaVariables())
			{
				Term value = null;
				if (ph2.getMetaProperty(Z) != null) value = getSort(ph2.getMetaProperty(Z), rulename.symbol(), boundVariables);
				Term zsort = metaSortsPerRule.get(rulename.symbol()).get(Z)[0];
				contents.add(new Pair<Term, Term>(zsort, value));
			}
		}
		
		// Handle the key/value pairs (make sure they are added).
		for (Pair<Term,Term> pair : contents)
		{
			Term keySortTerm = pair.head();
			Term valueSortTerm = pair.tail();
			if (keySortTerm.kind() == Kind.VARIABLE_USE)
			{
				if (valueSortTerm != null && sortsetdesignate != null)
					sortSetContains.multiAdd(sortsetdesignate, new Pair<Pair<Object,Term>,Constructor>(new Pair<Object,Term>(keySortTerm.variable(), valueSortTerm), rulename));
			}
			else
			{
				if (keySortTerm.arity() > 0)
				{
					error("something of sort " + keySortTerm + " appears as a key in a property set in rule " + rulename + "; only basic sorts are allowed.");
					return;
				}
				//Kris: if looking at a construction then check whether the construction has the sort set.
				Constructor c = term.constructor();
				boolean inSymbolSort = false;
				if (term.kind() == Kind.CONSTRUCTION) //&& factory.isFunction(c)
				{
					Set<Pair<Term,Term>> forms = factory.formsOf(c.symbol());
					if (forms != null && forms.size() == 1)
					{
						Term form = forms.iterator().next().tail();
						// key/value pair might be declared on symbolis a function so we should add it to the function.
						for (Pair<Term,Term> keyValueSymbolSort : Util.allProperties(Util.propertiesHolder(form), factory))
						{
							if (Unifier.equalSorts(factory, keySortTerm, keyValueSymbolSort.head()))
							{
								inSymbolSort = true;
								if (!Unifier.equalSorts(factory, valueSortTerm, keyValueSymbolSort.tail()) && sortsetdesignate != null)
									sortSetContains.multiAdd(sortsetdesignate, new Pair<Pair<Object,Term>,Constructor>(new Pair<Object,Term>(Util.symbol(keySortTerm), valueSortTerm), rulename));
								break;
							}
						}
					}
				}
				if (!inSymbolSort && sortsetdesignate != null)
				{
					// The term is not a function call that can carry sort sets so add constraint to the main sort.
					sortSetContains.multiAdd(sortsetdesignate, new Pair<Pair<Object,Term>,Constructor>(new Pair<Object,Term>(Util.symbol(keySortTerm), valueSortTerm), rulename));
				}
			}
		}
	}

	/**
	 * Checks whether a given key:value pair is in the given sort set, possibly
	 * after applying theta on it.
	 * @param key a key representing a sort, which must either be a Variable or a String
	 * @param value either a sort, or null if the value is not of interest
	 * @param sortset a completely well-defined sort set
	 * @param syntacticKey whether the key sort is syntactic; this is only
	 * 	 set when the key is a variable, because if not, we already know whether it is
	 * @param sort the name of the sort this sort set comes with, for error messages
	 * @param rulename the rule which causes this restriction, for error messages
	 * @param theta a sort substitution, which should be applied on key/value and
	 *   which may be modified to ensure that key:value ∈ sortset
	 * @throws CRSException if we cannot derive the sorts for key and value, or if
	 *   we can but they are not a pair in sortset, an error is given, which may
	 *   lead to an exception being thrown
	 */
	private void testMembership(Object key, Term value, Map<String,Term> sortset,
								boolean syntacticKey, String sort, Constructor rulename,
								Map<Variable,Term> theta) throws CRSException
	{
		String skey = (key instanceof Variable ? null : (String) key);
		Variable vkey = (key instanceof Variable ? (Variable) key : null);
		
		// make sure we have full information about key (and that it isn't an
		// illegal sort if we take theta into account)
		while (vkey != null && theta.containsKey(vkey))
		{
			if (theta.get(vkey).kind() == Kind.VARIABLE_USE) vkey = theta.get(vkey).variable();
			else if (theta.get(vkey).arity() == 0) { skey = Util.symbol(theta.get(vkey)); vkey = null; }
			else
			{
				error("rule " + rulename + " has a property set containing a key " +
					  "of sort " + theta.get(vkey) + "; only basic sorts are " +
					  "allowed as keys in sort sets.");
				return;
			}
		}
		
		// if key is a string, it's easy to check for the match!
		if (skey != null)
		{
			if (!sortset.containsKey(skey) || (value != null && !Unifier.unify_help(value, sortset.get(skey), theta, factory)))
				error("rule " + rulename + " has a property set with a requirement of " +
					  "sort " + key + " : " + (value == null ? "?" : value) +
					  "; this does not match the declared sort set for " + sort);
			return;
		}
		
		// otherwise key is a variable; check how many items it matches (hopefully 1!)
		Set<String> match = new HashSet<String>();
		if (value != null) value = Unifier.repeat_apply(value, theta, factory);
		for (String k : sortset.keySet())
		{
			Map<Variable,Term> theta2 = new HashMap<Variable,Term>();
			if (syntacticKey && !factory.sortAllowsVariables(k)) continue;
			if ((value != null && !Unifier.unify_help(value, sortset.get(k), theta2, factory)) ||
				!Unifier.unify_help(factory.literal(k), factory.newVariableUse(vkey), theta2, factory)) continue;
			
			match.add(k);
		}
		if (match.size() == 0)
		{
			error("could not match " + key + (syntacticKey ? " (syntactic) : " : " : ") +
				  (value == null ? "?" : value) + " with any of the sorts in the sort set declared for " + sort + " (could not deal with rule " +
				  rulename + ")");
		}
		else if (match.size() > 1)
			error("rule " + rulename + "has a property set with a requirement of " +
				  key + " : " + (value == null ? "?" : value) + "; unfortunately we could not determine whether this holds in the declared sort set for sort " + sort);
		else // match.size() == 1!
		{
			String k = match.iterator().next();
			theta.put(vkey, factory.literal(k));
			if (value != null) Unifier.unify_help(value, sortset.get(k), theta, factory);
		}
	}
	
	/**
	 * For all sort variables which have been saved as the sort of a
	 * syntactic variables, check whether theta resolves them to a
	 * sort constructor which allows syntactic variables.  If theta
	 * resolves them to a sort constructor which does not yet allow
	 * syntactic variables, this gives a warning and makes the sort
	 * accept syntactic variables.
	 * @param theta a sort substitution
	 * @param finish if set to true, all syntactic variables MUST be
	 *   resolved to a sort constructor with syntactic variables; if
	 *   set to false, some restrictions may remain in the global
	 *   syntacticVariableUse variable.
	 * @throws CRSException
	 */
	private void checkSyntacticVariables(Map<Variable,Term> theta, boolean finish) throws CRSException
	{
		Map<Variable,String> remainder = new HashMap<Variable,String>();
		
		for (Variable x : syntacticVariableUse.keySet())
		{
			String rulename = syntacticVariableUse.get(x);
			while (theta.containsKey(x) && theta.get(x).kind() == Kind.VARIABLE_USE)
				x = theta.get(x).variable();
			if (!theta.containsKey(x))
				remainder.put(x, rulename);
			else if (theta.get(x).arity() > 0)
				error("syntactic variable in rule " + rulename + " has sort " +
					  theta.get(x).toString() + "; only basic sorts may have syntactic variables.");
			else
			{
				String sort = Util.symbol(theta.get(x));
				if (!factory.sortAllowsVariables(sort))
				{
					warning("syntactic variable in rule " + rulename + " has sort " +
							sort + ", which is not declared to have syntactic variables. " +
							"Adding this to the declaration.");
					factory.setSortForm(freshForm(sort, 0), LinkedExtensibleSet.EMPTY_VARIABLE_SET, factory.newVariableUse(x), false, true); // TODO: is allowSort parameter safe?
				}
			}
		}
		
		if (finish)
		{
			for (Entry<Variable,String> e : remainder.entrySet())
			{
				error("sort for syntactic variable " + e.getKey() + " in rule " + e.getValue() + " cannot be resolved.  Please declare it.");
			}
		}
		
		syntacticVariableUse = remainder;
	}
	
	/**
	 * Applies a non-recursive sort substitution as often as is effective on
	 * all sort denotations in varSortsPerRule, metaSortsPerRule and
	 * constructorSortsPerRule.
	 * @see substituteSortDenotations, Unifier.repeat_apply
	 * @throws CRSException if some sort denotation is not actually a sort
	 */
	private void sortSubstituteSystem(Map<Variable,Term> theta) throws CRSException
	{
		// optimize theta: get rid of cases [&alpha;1:=&alpha;2, &alpha;2:=&iota;]
		for (Variable v : theta.keySet()) if (theta.get(v).kind() == Kind.VARIABLE_USE)
		{
			Variable x = theta.get(v).variable();
			Set<Variable> equiv = new HashSet<Variable>();
			equiv.add(v);
			Term value = null;
			while (theta.containsKey(x))
			{
				equiv.add(x);
				value = theta.get(x);
				if (value.kind() == Kind.VARIABLE_USE) x = value.variable();
				else break;
			}
			if (value != null) for (Variable w : equiv) theta.put(w, value);
		}
		
		// apply the requirements on all denotations
		for (String name : constructorSortsPerRule.keySet()) 
		{
			Map<Variable,Term> varSorts = varSortsPerRule.get(name);
			for (Variable x : varSorts.keySet())
				varSorts.put(x, Unifier.repeat_apply(varSorts.get(x), theta, factory));
			Map<String,Term[]> metaSorts = metaSortsPerRule.get(name);
			for (String Z : metaSorts.keySet())
			{
				Term[] declaration = metaSorts.get(Z);
				for (int i = 0; i < declaration.length; i++)
					declaration[i] = Unifier.repeat_apply(declaration[i], theta, factory);
			}
			Map<Term,Pair<Term,Term>> constructorSorts = constructorSortsPerRule.get(name);
			for (Term t : constructorSorts.keySet())
			{
				Term sort = Unifier.repeat_apply(constructorSorts.get(t).head(), theta, factory);
				Term form = constructorSorts.get(t).tail();
				GenericTerm[] args = new GenericTerm[form.arity()];
				Variable[][] binds = new Variable[form.arity()][];
				Term[][] bindersorts = new Term[form.arity()][];
				for (int i = 0; i < form.arity(); i++)
				{
					args[i] = Unifier.repeat_apply(subSort(form, i), theta, factory);
					binds[i] = form.binders(i);
					bindersorts[i] = new Term[form.binders(i).length];
					for (int j = 0; j < binds[i].length; j++)
					{
						Term vsort = binderSort(form, i, j);
						vsort = Unifier.repeat_apply(vsort, theta, factory);
						bindersorts[i][j] = vsort;
					}
				}
				if (Util.hasProperties(form))
				{
					// Form has constructor-local sort set.
					String symbol = form.constructor().symbol();
					PropertiesHolder ph = Util.propertiesHolder(form);
					Constructor c = factory.makeConstructor(symbol);
					for (Pair<Term,Term> p : Util.allProperties(ph, factory))
					{
						Term pkeysort = Unifier.repeat_apply(p.getKey(), theta, factory);
						Term pvaluesort = Unifier.repeat_apply(p.getValue(), theta, factory);
						if (pvaluesort.kind() == Kind.VARIABLE_USE)
						{
							// TODO: variable case?
						}
						switch (pkeysort.kind())
						{
							case VARIABLE_USE :
								c = Util.wrapWithProperty(factory, c, pkeysort.variable(), pvaluesort);
								break;
							case CONSTRUCTION :
								c = Util.wrapWithProperty(factory, c, Util.symbol(pkeysort), pvaluesort);
								break;
							case META_APPLICATION :
								error("Ignoring property " + pkeysort + " : " + pvaluesort);
						}
					}
					form = freshForm(c, args, binds, bindersorts);
				}
				else
				{
					form = freshForm(form.constructor(), args, binds, bindersorts);
				}
				constructorSorts.put(t, new Pair<Term,Term>(sort, form));
			}
		}
		
		// apply requirements on undeclared symbols
		for (String F : undeclaredConstructors.keySet())
		{
			Term sort = Unifier.repeat_apply(undeclaredConstructors.get(F).head(), theta, factory);
			Term form = undeclaredConstructors.get(F).tail();
			GenericTerm[] args = new GenericTerm[form.arity()];
			Variable[][] binds = new Variable[form.arity()][];
			Term[][] bindersorts = new Term[form.arity()][];
			for (int i = 0; i < form.arity(); i++)
			{
				args[i] = Unifier.repeat_apply(subSort(form, i), theta, factory);
				binds[i] = form.binders(i);
				bindersorts[i] = new Term[form.binders(i).length];
				for (int j = 0; j < binds[i].length; j++)
				{
					Term vsort = binderSort(form, i, j);
					vsort = Unifier.repeat_apply(vsort, theta, factory);
					bindersorts[i][j] = vsort;
				}
			}
			form = freshForm(form.constructor(), args, binds, bindersorts);
			undeclaredConstructors.put(F, new Pair<Term,Term>(sort,form));
		}
	}

	/**
	 * Find the set of all constructors in rules which occur as the root of one
	 * (or more) of the patterns.
	 */
	private Set<String> functionSymbols(Map<String,GenericRule> rules)
	{
		Set<String> ret = new HashSet<String>();
		for (Entry<String,GenericRule> e : rules.entrySet())
			ret.add(Util.symbol(e.getValue().getPattern()));
		return ret;
	}
	
	/**
	 * Find the set of all constructors in rules which occur in a pattern,
	 * excepting the root position.
	 */
	private MultiMap<String,String> dataSymbols(Map<String,GenericRule> rules)
	{
		MultiMap<String,String> ret = new HashMultiMap<String,String>();
		for (Entry<String,GenericRule> e : rules.entrySet())
		{
			Term pattern = e.getValue().getPattern();
			LinkedList<Term> parts = new LinkedList<Term>();
			parts.addLast(pattern);
			while (!parts.isEmpty())
			{
				Term last = parts.removeLast();
				for (int i = 0; i < last.arity(); i++)
				{
					if (last.sub(i).kind() == Kind.CONSTRUCTION)
					{
						ret.multiAdd(Util.symbol(last.sub(i)), e.getKey());
						parts.addLast(last.sub(i));
					}
				}
			}
		}
		return ret;
	}
	
	/**
	 * This method checks whether all symbols occurring in the given term which
	 * have been declared as overloaded, have been assigned exactly one of
	 * their possible declarations.  If not, an error is given.
	 * (Note: due to overloadTestResults, which should have been called before
	 * getting to this point, we already know that _at least_ one of the
	 * possible declarations fits).
	 * @param term the term to check
	 * @param rulename used in the error message and for checking denotations
	 * @throws CRSException if there is a constructor which has more than one
	 *   potential sort declaration
	 */
	private void checkOverloadedUse(Term term, String rulename) throws CRSException
	{
		for (int i = 0; i < term.arity(); i++)
			checkOverloadedUse(term.sub(i), rulename);
		if (term.kind() != Kind.CONSTRUCTION) return;
		String F = Util.symbol(term) + "-";
		if (!overloadedConstructors.containsKey(F + "1")) return;
		String arcode = getArityCode(term);
		int fits = -1;
		for (int i = 1; fits == -1 && declaredConstructors.containsKey(F+i); i++)
		{
			if (arcode.equals(getArityCode(declaredConstructors.get(F+i).tail()))) fits = i;
		}
		F = F + fits;
		if (overloadedConstructors.get(F).size() == 1) return;
		Pair<Term,Term> declaration = constructorSortsPerRule.get(rulename).get(term);
		Term sort = declaration.head();
		Term form = declaration.tail();
		
		Set<Variable> FTV = new HashSet<Variable>();
		sort.addFree(FTV, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
		form.addFree(FTV, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
		if (!FTV.isEmpty())
			error("could not uniquely determine sort of overloaded symbol in " + term + " in rule " + rulename);
	}
	
	/**
	 * After all constructors, variables and meta-variables have been assigned
	 * a sort or sort declaration in such a way that the entire system is
	 * well-sorted, postSortificationChecks is called to see whether the system
	 * is used in a way it is intended to be used.
	 * @throws CRSException if there are problems, for instance a function
	 *   constructor being used as data.
	 */
	private void postSortificationChecks(Map<String,GenericRule> rules) throws CRSException
	{
		// 1: are all undeclared symbols monomorphic? (if not, it's not fatal - for now)
		for (String F : undeclaredConstructors.keySet())
		{
			Term sort = undeclaredConstructors.get(F).head();
			Term form = undeclaredConstructors.get(F).tail();
			Set<Variable> FV = new HashSet<Variable>();
			sort.addFree(FV, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
			form.addFree(FV, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
			if (!FV.isEmpty())
				warning("could not resolve a unique monomorphic sort for undeclared constructor " + F + ", treating as polymorphic.");
		}
		
		// 2. is every symbol used either as a data symbol, or as a function symbol (and if not, is that allowed?)
		Set<String> defineds = functionSymbols(rules); 
		MultiMap<String,String> data = dataSymbols(rules);
		for (String F : declaredConstructors.keySet())
		{
			// TODO - cases for ints and strings, although that should probably be done by the parser!
			if (factory.isData(F) && defineds.contains(F) && !allowDataFunctions)
				error("symbol " + F + " declared as a data constructor, but used to specify a rule.");
			if (factory.isFunction(F) && data.multiContainsKey(F))
			{
				Set<String> relevantRules = data.get(F);
				String rulename = (relevantRules.size() == 1 ? "rule " : "rules");
				for (String name : relevantRules)
				{
					if (rulename.length() != 0) rulename = rulename + ", ";
					rulename += name;
				}
				error("symbol " + F + " declared as a function constructor, but used at a data symbol in " + rulename + ".");
			}
		}
		for (String F : undeclaredConstructors.keySet())
		{
			Term sort = undeclaredConstructors.get(F).head();
			Term form = undeclaredConstructors.get(F).tail();
			Set<Variable> sortParams = new HashSet<Variable>();
			sort.addFree(sortParams, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
			form.addFree(sortParams, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
			
			if (data.multiContainsKey(F))
			{
				if (sort.kind() != Kind.CONSTRUCTION || sort.arity() != 0)
					error("undeclared data constructor " + F + " has polymorphic output sort " + sort +
						  "; if this is what you intended, please declare it.");
				if (defineds.contains(F) && !allowDataFunctions)
					error("undeclared constructor " + F + " occurs both as a function constructor and as a data constructor");
				factory.setSortForm(undeclaredConstructors.get(F).head(), sortParams, form, true, false); // TODO: is allowSort parameter safe?
			}
			else if (defineds.contains(F))
				factory.setSortForm(undeclaredConstructors.get(F).head(), sortParams, form, true, false);
			else if (sort.kind() != Kind.CONSTRUCTION || (!Util.symbol(sort).equals(CRS.STRING_SORT)))
				// TODO: change this if strings are implemented in their own special way
			{
				boolean isData = (sort.kind() == Kind.CONSTRUCTION && sort.arity() == 0);
				if (!allowUndeclared)
					warning("undeclared constructor " + F + " does not occur in any pattern; "+
							"thus, it is neither a function nor a data constructor, and not "+
							"every term reduces to a normal form.  Treating it as a "+
							(isData ? "data" : "function") + " constructor for now.");
				factory.setSortForm(undeclaredConstructors.get(F).head(), sortParams, form, !isData, false);
			}
		}

		// 3: have all overloaded symbols been assigned one of their uses?
		for (Entry<String,GenericRule> e : rules.entrySet())
		{
			checkOverloadedUse(e.getValue().getPattern(), e.getKey());
			checkOverloadedUse(e.getValue().getContractum(), e.getKey());
		}
	}
}
