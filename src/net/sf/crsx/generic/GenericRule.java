/* Copyright (c) 2006, 2012 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Kind;
import net.sf.crsx.Match;
import net.sf.crsx.Pattern;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SimpleVariableSet;
import net.sf.crsx.util.SmallSet;
import net.sf.crsx.util.Util;

/**
 * Generic implementation of a rewrite rule.
 * Each instance represents one particular rewrite rule.
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: GenericRule.java,v 3.17 2013/12/18 20:16:16 villardl Exp $
 */
public class GenericRule implements Copyable
{
	// State.

	/** The host CRS. */
	final GenericCRS crs;

	/** Name */
	final Constructor name;

	/** Options. */
	final Map<String, List<Term>> options;

	/** LHS. */
	Pattern pattern;

	/** RHS */
	Contractum contractum;

	/** For meta-variables that can just be copied (no substitutions) we give the contraction occurrence count. */
	final Map<String, Integer> explicitCount;

	/** Map free variable to their sort */
	final Map<String, Term> free;

	/** The fresh variables in contractum that should be created, with their declarations. */
	final Map<String, Term> fresh;

	/** The global variables in contractum where the rule system copy should be used. */
	final Map<String, Term> global;

	/** Map bound variables in pattern to what (bound or fresh) variable they can be reused as in contractum. */
	Map<Variable, Variable> reused;

	/** Map bound variables in pattern to the pattern meta-application meta-variable and index. */
	Map<Variable, Pair<String, Integer>> reusedOrigin;

	/** Set of meta-variables to evaluate before contraction. */
	final Set<String> forced;

	/** What valuations created from this rule return from {@link Valuation#leave()}. */
	boolean leaf;

	/** Whether the rule is tolerantly loaded... */
	boolean lax;

	/** Which sorts are associated with the free variables (set by the sorter) */
	private Map<Variable, Term> variableSorts;

	/** Which sorts are associated with the meta-variables (set by the sorter) */
	private Map<String, Term> metaVariableSorts;

	/** 
	 * Which sorts and forms are associated with the constructors (set by the sorter)
	 * <p>Saved on the construction rather than the constructor to avoid problems when the same constructor is used
	 * twice in the same rule with different sorts (this technically shouldn't happen, but sometimes it does) */
	private Map<Term, Pair<Term, Term>> constructorSorts;

	/** Which sorts are associated with sort parameters (for polymorphic sorts) */
	private Map<String, Map<Variable, Term>> paramSorts;

	/** Set of comparable meta application */
	private Set<String> comparable;

	/** Set of discarded meta application */
	private Set<String> discarded;

	/** Set of shared meta application */
	private Set<String> shared;

	/** Set of copied meta application */
	private Set<String> copied;

	/** Set of weak meta application */
	private Set<String> weak;

	/** Set of shallow binders */
	private Set<Variable> shallow;

	// Constructor.

	/**
	 * Construct rewrite rule.
	 * @param crs hosting the rule
	 * @param ruleName of rule
	 * @param pattern that should match the redex
	 * @param contractum for constructing the result - may be modified destructively
	 * @param options arguments to name as constructor symbol to list of argument terms (see {@link Builder} for options)
	 * @throws CRSException when the rule is malformed
	 */
	protected GenericRule(GenericCRS crs, Constructor ruleName, Pattern pattern, Contractum contractum,
			Map<String, List<Term>> options) throws CRSException
	{
		if (options == null)
			options = new HashMap<String, List<Term>>();

		if (crs.factory.verbosity() >= 6)
			crs.factory.message("Adding rule: \n  " + ruleName + options + " :\n  " + pattern + "\n  →  " + contractum);

		this.crs = crs;
		this.name = ruleName;

		this.options = options;
		this.variableSorts = null;
		this.metaVariableSorts = null;

		this.free = new HashMap<String, Term>(4);
		this.fresh = new HashMap<String, Term>(4);
		this.global = new HashMap<String, Term>(2);
		this.comparable = new HashSet<String>(2);
		this.discarded = new HashSet<String>(8);
		this.shared = new HashSet<String>(8);
		this.copied = new HashSet<String>(2);
		this.weak = new HashSet<String>(2);
		this.shallow = new HashSet<Variable>(2);

		this.forced = new HashSet<String>(4);
		this.pattern = pattern;
		this.contractum = contractum;
		this.explicitCount = new HashMap<String, Integer>();

		reconcile();
	}

	// Methods.

	/** Gets rule name */
	public Constructor getName()
	{
		return name;
	}

	/** Gets rule pattern (lhs). */
	public Pattern getPattern()
	{
		return pattern;
	}

	/** Gets rule contractum (rhs). */
	public Contractum getContractum()
	{
		return contractum;
	}

	/** Gets rule option */
	public Map<String, List<Term>> getOptions()
	{
		return options;
	}

	/** 
	 * Gets the variable occurring in the pattern which can be reused for the given variable occurring in the contractum
	 * @param var occurring in the contractum
	 * @return variable being reused. Null if none.
	 */
	public Variable getReused(Variable var)
	{
		for (Map.Entry<Variable, Variable> e : reused.entrySet())
		{
			if (e.getValue() == var)
				return e.getKey();
		}
		return null;
	}

	/**
	 * Get the meta-variable and argument index (0-based) of the occurrence in the pattern of the variable to be reused as  var (!).
	 */
	public Pair<String, Integer> getFreshOrigin(Variable var)
	{
		Variable v = getReused(var);
		return (v == null ? null : reusedOrigin.get(v));
	}

	/**
	 * Gets the contraction occurrence count for the given meta application
	 * @param meta application name
	 * @return
	 */
	public Integer getExplicitCount(String meta)
	{
		return explicitCount.get(meta);
	}

	/**
	 * Gets fresh variable sort declaration. 
	 * @param name variable name
	 * @return A sort or null if no fresh variable of the given name.
	 */
	public Term getFresh(Variable var)
	{
		return fresh.get(var.name());
	}

	/**
	 * Get the rule name
	 * @return
	 */
	public String name()
	{
		return name.symbol();
	}

	/**
	 * Reconcile information stored on the option/pattern/contractum with cached value
	 * @throws CRSException 
	 */
	public void reconcile() throws CRSException
	{
		// Extract information from options...
		// Free[v,...]
		free.clear();
		if (options.containsKey(Builder.FREE_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.FREE_OPTION_SYMBOL))
			{
				if (!Util.isVariableWithOptionalSort(z))
					ruleError("Only variables can be specified as Free (" + z + ")", false, false);
				else
					free.put(Util.variableWithOptionalSortVariable(z).name(), z);
			}
		}
		// Fresh[v,...] and FreshReuse[v,...] (not distinguished by interpreter)
		fresh.clear();
		if (options.containsKey(Builder.FRESH_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.FRESH_OPTION_SYMBOL))
			{
				if (!Util.isVariableWithOptionalSort(z))
					ruleError("Only variables can be specified as Fresh (" + z + ")", false, false);
				else if (free.containsKey(Util.variableWithOptionalSortVariable(z).name()))
					ruleError("Variable cannot be specified as both Free and Fresh (" + z + ")", false, false);
				else
					fresh.put(Util.variableWithOptionalSortVariable(z).name(), z);
			}
		}
		if (options.containsKey(Builder.FRESH_REUSE_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.FRESH_REUSE_OPTION_SYMBOL))
			{
				if (!Util.isVariableWithOptionalSort(z))
					ruleError("Only variables can be specified as Fresh (" + z + ")", false, false);
				else if (free.containsKey(Util.variableWithOptionalSortVariable(z).name()))
					ruleError("Variable cannot be specified as both Free and Fresh (" + z + ")", false, false);
				else
					fresh.put(Util.variableWithOptionalSortVariable(z).name(), z);
			}
		}
		// Global[v,...]
		global.clear();
		if (options.containsKey(Builder.GLOBAL_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.GLOBAL_OPTION_SYMBOL))
			{
				if (!Util.isVariableWithOptionalSort(z))
					ruleError("Only variables can be specified as Global (" + z + ")", false, false);
				else
				{
					Variable v = Util.variableWithOptionalSortVariable(z);
					if (free.containsKey(v.name()))
						ruleError("Variable cannot be specified as both Free and Global (" + v + ")", false, false);
					else if (fresh.containsKey(v.name()))
						ruleError("Variable cannot be specified as both Fresh and Global (" + v + ")", false, false);
					else
					{
						for (Variable gv : crs.global)
							if (v.name().equals(gv.name()))
							{
								v = gv; // pick 
								break;
							}
						global.put(v.name(), crs.factory.newVariableUse(v));
						if (!crs.global.contains(v))
							crs.global.add(v);
					}
				}
			}
		}
		comparable.clear();
		if (options.containsKey(Builder.COMPARABLE_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.COMPARABLE_OPTION_SYMBOL))
			{
				if (z.kind() != Kind.META_APPLICATION || z.arity() > 0)
					ruleError("Only meta-variable names can be specified as Comparable (" + z + ")", false, false);
				else
					comparable.add(z.metaVariable());
			}
		}
		discarded.clear();
		if (options.containsKey(Builder.DISCARD_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.DISCARD_OPTION_SYMBOL))
			{
				if (z.kind() != Kind.META_APPLICATION || z.arity() > 0)
					ruleError("Only meta-variable names can be specified with Discard (" + z + ")", false, false);
				else
					discarded.add(z.metaVariable());
			}
		}
		shared.clear();
		if (options.containsKey(Builder.SHARE_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.SHARE_OPTION_SYMBOL))
			{
				if (z.kind() != Kind.META_APPLICATION || z.arity() > 0)
					ruleError("Only meta-variable names can be specified with Share (" + z + ")", false, false);
				else
					shared.add(z.metaVariable());
			}
		}
		copied.clear();
		if (options.containsKey(Builder.COPY_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.COPY_OPTION_SYMBOL))
			{
				if (z.kind() != Kind.META_APPLICATION || z.arity() > 0)
					ruleError("Only meta-variable names can be specified with Copy(" + z + ")", false, false);
				else
					copied.add(z.metaVariable());
			}
		}
		weak.clear();
		if (options.containsKey(Builder.WEAK_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.WEAK_OPTION_SYMBOL))
			{
				if (z.kind() != Kind.META_APPLICATION || z.arity() > 0)
					ruleError("Only meta-variable names can be specified as Weak (" + z + ")", false, false);
				else
					weak.add(z.metaVariable());
			}
		}
		// Data[#,...]
		forced.clear();
		if (options.containsKey(Builder.DATA_OPTION_SYMBOL))
		{
			for (Term z : options.get(Builder.DATA_OPTION_SYMBOL))
			{
				if (z.kind() != Kind.META_APPLICATION || z.arity() > 0)
					ruleError("Only meta-variable names can be specified with Data (" + z + ")", false, false);
				else
					forced.add(z.metaVariable());
			}
		}
		// Meta.
		boolean allowMeta = options.containsKey(Builder.META_OPTION_SYMBOL);
		// Leaf.
		leaf = options.containsKey(Builder.LEAF_OPTION_SYMBOL);
		// Lax.
		lax = crs.factory().defined(Builder.LAX_SYMBOL) || options.containsKey(Builder.LAX_OPTION_SYMBOL);
		// Watch.
		if (options.containsKey(Builder.WATCH_OPTION_SYMBOL))
			crs.watchedRules.add(name());

		// Repair basic options.
		if (lax)
		{
			reused = null;

			// Free.
			Set<Variable> patternFree = new HashSet<Variable>(4);
			pattern.addFree(patternFree, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, null);
			for (Variable v : patternFree)
				if (!free.containsKey(v.name()))
					free.put(v.name(), crs.factory.newVariableUse(v)); // TODO: typefor (Variable v : patternFree)
			List<String> unusedNames = new ArrayList<String>();
			for (Map.Entry<String, Term> z : free.entrySet())
				if (!patternFree.contains(Util.variableWithOptionalSortVariable(z.getValue())))
					unusedNames.add(z.getKey());
			for (String n : unusedNames)
				free.remove(n);
			/// Set<Variable> contractumFresh = new HashSet<Variable>(); contractum.addFree(contractumFresh, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, null); contractumFresh.removeAll(patternFree); 
			/// for (Variable v : contractumFresh)
			/// 	if (!fresh.containsKey(v.name()))
			/// 		fresh.put(v.name(), crs.factory.newVariableUse(v));
			// Compare/Discard/Copy.
			Map<String, Integer> patternMetaCounts = new HashMap<String, Integer>();
			pattern.addMetaCounts(patternMetaCounts);
			Map<String, Integer> contractumMetaCounts = new HashMap<String, Integer>();
			contractum.addMetaCounts(contractumMetaCounts);
			for (String m : patternMetaCounts.keySet())
			{
				int count = patternMetaCounts.get(m);
				if (count > 1)
				{
					comparable.add(m);
				}
				if (!contractumMetaCounts.containsKey(m))
				{
					if (!discarded.contains(m))
						discarded.add(m);
				}
				else if (contractumMetaCounts.get(m) > 1)
				{
					copied.add(m);
				}
			}
		}

		// Check pattern (and extract meta-applications).
		Map<String, Term> patternMetaApplications = new HashMap<String, Term>(4);
		Set<String> patternPropertiesRefs = new HashSet<String>(4);
		Map<String, Integer> patternOccurrences = new HashMap<String, Integer>(4);
		Map<String, String> patternMetaSorts = new HashMap<String, String>(4);
		checkPattern(
				pattern, free, comparable, weak, patternMetaApplications, patternPropertiesRefs, patternMetaSorts,
				SimpleVariableSet.EMPTY, patternOccurrences);

		// Check contractum (and extract explicit counts and reusable binders).
		List<String> contractumMetaVariables = new ArrayList<String>();
		Map<String, Integer> contractumOccurrences = new HashMap<String, Integer>();
		Set<String> nonExplicit = new HashSet<String>();
		Map<Variable, Variable> reusable = new HashMap<Variable, Variable>();
		Map<Variable, Pair<String, Integer>> reusableOrigin = new HashMap<Variable, Pair<String, Integer>>();
		checkContractum(
				contractum, free, !allowMeta, shared, copied, discarded, shallow, patternMetaApplications, patternPropertiesRefs,
				patternMetaSorts, contractumMetaVariables, contractumOccurrences, nonExplicit, reusable, reusableOrigin);

		reused = reusable;
		reusedOrigin = reusableOrigin;
		for (Variable v : reused.values())
		{
			fresh.remove(v.name());
		}

		explicitCount.clear();
		for (String m : patternMetaApplications.keySet())
		{
			if (!nonExplicit.contains(m))
			{
				// Only occurs in explicit configuration - record count, if useful!
				Integer count = ((shared != null && shared.contains(m)) ? Integer.valueOf(1) : contractumOccurrences.get(m));
				if (count != null && count > 0)
					explicitCount.put(m, count);
			}
		}
	}

	/**
	 * Search for the meta declaration of the given name on the pattern
	 * @param name 
	 * @throws CRSException 
	 */
	public GenericTerm getMetaOnPattern(final String name) throws CRSException
	{
		final GenericTerm[] result = new GenericTerm[1];

		final Visitor visitor = new Visitor()
			{
				@Override
				public void visitMetaApplication(Term metaApplication, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start && metaApplication.metaVariable().equals(name))
						result[0] = (GenericTerm) metaApplication;
					super.visitMetaApplication(metaApplication, start, bound);
				}

			};
		pattern.visit(visitor, SimpleVariableSet.EMPTY);
		return result[0];

	}

	/**
	 * Give a sort denotation for the variables occurring freely in this rule.
	 * @param varSorts the sort denotation, should contain entries for all free variables in the rule
	 */
	public void setVariableSorts(Map<Variable, Term> varSorts)
	{
		variableSorts = varSorts;

		// Also stuff the relevant declarations into Free/Fresh/FreshReuse/Global options.
		if (options.containsKey(Builder.FREE_OPTION_SYMBOL))
			options.put(Builder.FREE_OPTION_SYMBOL, insertVariableSorts(options.get(Builder.FREE_OPTION_SYMBOL), varSorts));
		if (options.containsKey(Builder.FRESH_OPTION_SYMBOL))
			options.put(Builder.FRESH_OPTION_SYMBOL, insertVariableSorts(options.get(Builder.FRESH_OPTION_SYMBOL), varSorts));
		if (options.containsKey(Builder.FRESH_REUSE_OPTION_SYMBOL))
			options.put(
					Builder.FRESH_REUSE_OPTION_SYMBOL,
					insertVariableSorts(options.get(Builder.FRESH_REUSE_OPTION_SYMBOL), varSorts));
		if (options.containsKey(Builder.GLOBAL_OPTION_SYMBOL))
			options.put(Builder.GLOBAL_OPTION_SYMBOL, insertVariableSorts(options.get(Builder.GLOBAL_OPTION_SYMBOL), varSorts));
	}

	private List<Term> insertVariableSorts(List<Term> oldDeclarations, Map<Variable, Term> varSorts)
	{
		List<Term> newDeclarations = new ArrayList<Term>();
		for (Term d : oldDeclarations)
		{
			Variable v = Util.variableWithOptionalSortVariable(d);
			GenericTerm sort = (GenericTerm) varSorts.get(v);
			newDeclarations.add(sort == null ? d : Util.makeVariableWithSort(crs.factory, v, sort));
		}
		return newDeclarations;
	}

	/**
	 * Give an output sort denotation for the variables occurring freely in this rule.
	 * @param metavarSorts the output sort denotation, should contain entries for all meta-variables in the rule
	 */
	public void setMetaVariableSorts(Map<String, Term> metavarSorts)
	{
		metaVariableSorts = metavarSorts;
	}

	/**
	 * Give a sort and form denotation for the occurrences of constructors in this rule.
	 * @param constructorSorts maps constructors to their sort and form
	 */
	public void setConstructorSorts(Map<Term, Pair<Term, Term>> consSorts)
	{
		constructorSorts = consSorts;
	}

	/**
	 * Give a sort denotation for the sort variables occurring freely in sorts of this rule.
	 * @param parSorts maps each sort variable to the sort it is instantiated to
	 */
	public void setParamSorts(Map<String, Map<Variable, Term>> parSorts)
	{
		paramSorts = parSorts;
	}

	/**
	 * Returns the sort of a given variable which occurs freely in the rule, if
	 * this data has previously been set with {@link #setVariableSort}
	 * @param x a variable, which occurs freely in the rule
	 * @return the sort of the given variable, or null if this sort has
	 *   not been set
	 */
	public Term getVariableSort(Variable x)
	{
		if (variableSorts != null && variableSorts.containsKey(x))
			return variableSorts.get(x);
		else
		{
			// The sort hasn't been cached. Try to recompute it.
			Pair<Term, Integer> decl;
			try
			{
				decl = findBinder(x);

				if (decl != null)
				{
					Pair<Term, Term> sortDeclaration = getConstructorDeclaration(decl.head());
					if (sortDeclaration != null)
					{
						Term form = sortDeclaration.tail();

						Variable[] bindersOnTerm = decl.head().binders(decl.tail());
						for (int i = bindersOnTerm.length - 1; i >= 0; i--)
						{
							if (bindersOnTerm[i] == x)
							{
								Variable binderOnForm = form.binders(decl.tail())[i];

								return ((PropertiesHolder) form.sub(decl.tail())).getProperty(binderOnForm);
							}
						}
					}

				}
				return null;
			}
			catch (CRSException e)
			{
				throw new RuntimeException(e);

			}

		}
	}

	/**
	 * Returns the output sort of a given meta-variable which occurs freely in
	 * the rule, if this data has previously been set with
	 * {@link #setMetaVariableSort}
	 * @param Z a meta-variable, which occurs freely in the rule
	 * @return the output sort of the given meta-variable, or null if this sort
	 *   has not been set
	 */
	public Term getMetaVariableSort(String Z)
	{
		if (metaVariableSorts != null && metaVariableSorts.containsKey(Z))
			return metaVariableSorts.get(Z);
		else
			return null;
	}

	/**
	 * Returns the sort and form of the root-symbol occurrence of subterm,
	 * which occurs somewhere in this rule, assuming this data was previously
	 * set with {@Link setConstructorSort}
	 * @param subterm a term of the form F[s1,...,sn]
	 * @return a pair <sort,form> which gives the (instantiated) declaration
	 *   of the constructor F
	 */
	public Pair<Term, Term> getConstructorDeclaration(Term subterm)
	{
		if (constructorSorts != null && constructorSorts.get(subterm) != null)
			return constructorSorts.get(subterm);
		else
			return null;
	}

	/**
	 * Return instantiation of sort parameter for this rule.
	 * @param sort
	 * @param param
	 */
	public Term getParamSort(String sort, Variable param)
	{
		return (paramSorts.containsKey(sort) ? paramSorts.get(sort).get(param) : null);
	}

	/**
	 * Returns the sort of the given subterm occurring somewhere in the rules
	 * @param subterm the pointer to the subterm we're interested in
	 * @return the sort it occurs with, as saved with the set...Sorts declarations
	 */
	public Term getSubSort(Term subterm)
	{
		if (subterm.kind() == Kind.VARIABLE_USE)
			return getVariableSort(subterm.variable());
		else if (Util.isVariableWithOptionalSort(subterm))
			return Util.variableWithOptionalSortSort(subterm);
		if (subterm.kind() == Kind.META_APPLICATION)
			return getMetaVariableSort(subterm.metaVariable());
		Pair<Term, Term> sortform = getConstructorDeclaration(subterm);
		if (sortform == null)
			return null;
		else
			return sortform.head();
	}

	/**
	 * Whether the sub is a construction with deep use of binders declared on the sub. Ignore properties.
	 * @param index of the sub
	 * @throws CRSException 
	 */
	public boolean hasDeepBinderUses(Term term, int index) throws CRSException
	{
		if (term.binders(index) != null)
		{
			Term sub = term.sub(index);
			if (sub.kind() == Kind.VARIABLE_USE || sub.arity() == 0)
			{
				// either identity function or constant. Either way no deep binder uses
				return false;
			}

			// sub is a construction/meta application with binders and optionally with properties.
			Variable[] binders = term.binders(index);
			for (int i = 0; i < sub.arity(); i++)
			{
				Term subsub = sub.sub(i);

				switch (subsub.kind())
				{
					case VARIABLE_USE :
						if (sub.binders(i) == null || sub.binders(i).length == 0)
						{
							// Term of the form T[ ... x..y.S[...v..] ..]
							// This is not a deep variable. 
							// Continue on the next sub...

						}
						else
						{
							// Term of the form T[ ... x..y.S[...z.v..] ..]

							// This is either the identity function or constant.
							// That's considered deep
							return true;
						}
						break;
					case META_APPLICATION :
					case CONSTRUCTION :
					default :
						// Check if the subsub contains at least one binder use.
						// TODO: addFree is a bit overkill. 
						Set<Variable> free = new HashSet<Variable>();
						ExtensibleSet<Variable> bound = SimpleVariableSet.EMPTY;
						subsub.addFree(free, bound, true, null);

						for (int j = 0; j < binders.length; j++)
							if (free.contains(binders[j]))
								return true;
				}
			}
		}

		return false;
	}

	/**
	 * Whether the sub is a construction that contains other constructions..
	 * @param index of the sub
	 * @throws CRSException 
	 */
	public boolean hasConstruction(Term term, int index) throws CRSException
	{
		if (term.binders(index) != null)
		{
			Term sub = term.sub(index);
			if (sub.kind() == Kind.VARIABLE_USE || sub.arity() == 0)
				return false;

			for (int i = 0; i < sub.arity(); i++)
			{
				Term subsub = sub.sub(i);
				if (subsub.kind() == Kind.CONSTRUCTION)
					return true;
			}
		}
		return false;
	}

	/**
	 * Whether the sub is a construction that contains unordered variable uses. Ignore properties.
	 * @param index of the sub
	 * @throws CRSException 
	 */
	public boolean hasUnorderedShallowBinderUses(Term term, int index) throws CRSException
	{
		//if (hasBinders(term, index))
		if (term.binders(index) != null)
		{
			Term sub = term.sub(index);
			if (sub.kind() == Kind.VARIABLE_USE || sub.arity() == 0)
				return false;

			// sub is a construction/meta application with binders and optionally with properties.
			Variable[] binders = term.binders(index);
			int nextVarPos = 0;

			for (int i = 0; i < sub.arity(); i++)
			{
				Term subsub = sub.sub(i);

				switch (subsub.kind())
				{
					case VARIABLE_USE :
						Variable var = subsub.variable();
						if (nextVarPos < binders.length - 1 && !(var.name().equals(binders[nextVarPos++].name())))
							return true;
						break;
					case META_APPLICATION :
					case CONSTRUCTION :
					default :
						break;
				}
			}
		}

		return false;
	}

	/**
	 * Whether the sub does not use all direct binders.
	 * @param index of the sub
	 * @throws CRSException 
	 */
	public boolean hasWeakBinders(Term term, int index) throws CRSException
	{
		Variable[] binders = term.binders(index);
		if (binders != null)
		{
			HashSet<Variable> remainingBinders = new HashSet<Variable>();
			for (Variable variable : binders)
				remainingBinders.add(variable);

			removeUsedBinders(remainingBinders, term.sub(index));
			return !remainingBinders.isEmpty();
		}
		return false;
	}

	/**
	 * Whether the sub does not use all direct binders.
	 * @param index of the sub
	 * @throws CRSException 
	 */
	private void removeUsedBinders(HashSet<Variable> binders, Term term) throws CRSException
	{
		if (binders.isEmpty())
			return;

		switch (term.kind())
		{
			case VARIABLE_USE :
				binders.remove(term.variable());
				break;
			case CONSTRUCTION :
			case META_APPLICATION :
			default :
				for (int i = 0; i < term.arity(); i++)
				{
					removeUsedBinders(binders, term.sub(i));
					if (binders.isEmpty())
						break;
				}
				break;
		}
	}

	/**
	 * Determine whether the give meta variable, when used in the contractum
	 * requires meta-substitution when evaluated.
	 * 
	 * @param metavar 
	 * @return true when the metavar requires substitution. False otherwise or if term is not meta
	 */
	public boolean requireSubstitution(Term meta, Set<Variable> bound)
	{
		if (meta.kind() == Kind.META_APPLICATION)
		{
			for (int i = meta.arity() - 1; i >= 0; i--)
			{
				Term sub = meta.sub(i);
				if (sub.kind() != Kind.VARIABLE_USE)
					return true;
				Variable var = sub.variable();

				// If the variable is fresh, then always assume substitution is needed, even when it can be reused.
				if (!bound.contains(var))
					return true;

				if (getReused(var) == null)
					return true;
			}
		}
		return false;
	}

	/**
	 * Determine whether the given term is a meta-application with
	 * 
	 * <p>
	 * A meta-application for which substitution is not required is
	 * not considered to be a meta-closure.
	 */
	public boolean metaClosure(Term meta, Set<Variable> bound)
	{
		if (meta.kind() == Kind.META_APPLICATION)
		{
			if (requireSubstitution(meta, bound))
			{
				Set<Variable> usedBoundVariables = ((GenericMetaApplication) meta).freeVariables();
				usedBoundVariables.retainAll(bound);
				return !usedBoundVariables.isEmpty();
			}
		}

		return false;
	}

	/**
	 * Whether the term is marked as "inline"
	 */
	public boolean inline()
	{
		return options != null && options.containsKey(Builder.INLINE_OPTION_SYMBOL);
	}

	/**
	 * Attempt to apply the rule.
	 * @param term to match rule against
	 * @return valuation with successful unification result, or null if there is no match
	 */
	Valuation match(Term term)
	{
		int verbosity = this.crs.getVerbosity();
		if (verbosity >= 6)
		{
			this.crs.verboseWrite("<!-- Trying rule [" + name() + "]" + (verbosity > 6 ? " on " + term : "") + " -->\n");
		}

		if (options.containsKey(Builder.FALLBACK_OPTION_SYMBOL))
		{
			// Fallback rules not considered until all arguments are non-functions.
			for (int i = 0; i < term.arity(); ++i)
			{
				Term s = term.sub(i);
				if (s.kind() == Kind.CONSTRUCTION)
					if (crs.factory.isFunction(Util.symbol(s)))
						return null;
			}
		}

		Match match = new GenericMatch(this.crs, explicitCount, global); // tracks what is matched
		if (pattern.match(
				match, term, SimpleVariableSet.EMPTY, explicitCount, false, SimpleVariableSet.EMPTY, new HashSet<Variable>()))
		{
			// Success...construct valuation!
			ExtensibleMap<Variable, Variable> boundReuse = new LinkedExtensibleMap<Variable, Variable>();
			for (Map.Entry<Variable, Variable> e : reused.entrySet())
			{
				Variable patternVariable = e.getKey();
				Variable contractumVariable = e.getValue();
				Variable redexVariable = match.getVariable(patternVariable);
				boundReuse = boundReuse.extend(contractumVariable, redexVariable);
			}
			return new GenericValuation(this, match, boundReuse, false);
		}
		return null;
	}

	/**
	 * Contract this fragment of contractum (rule right hand side) to sink.
	 * Reduces Data-declared fragments followed by contraction.
	 * @param sink to send the fragment to
	 * @param valuation from successful matching of left-hand side (contains the full contractum of which this is a fragment)
	 * @param renamings already decided mappings of variables for the contraction (maps variables in contractum to variables to use in result of contraction)
	 * @return the sink after reception of the contracted subterm
	 */
	Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		for (String metaVariable : forced)
		{
			Substitute substitute = valuation.getSubstitute(metaVariable);
			if (substitute == null)
				continue;
			try
			{
				Term body = substitute.getBody();
				if (body == null)
					continue;
				Term replacement = crs.normalize(body);
				if (replacement == null)
					continue;
				substitute.replaceBody(replacement);
			}
			catch (CRSException e)
			{
				throw new RuntimeException(e);
			}
		}
		// ENTRY POINT to Contractum.contract().
		return contractum.contract(sink, valuation, renamings);
	}

	/**
	 * Statically contract this fragment of contractum (rule right hand side) to sink.
	 * Reduces Data-declared fragments followed by contraction.
	 * @param sink to send the fragment to
	 * @param valuation from successful matching of left-hand side (contains the full contractum of which this is a fragment)
	 * @param renamings already decided mappings of variables for the contraction (maps variables in contractum to variables to use in result of contraction)
	 * @return the sink after reception of the contracted subterm or null if contraction failed.
	 */
	Sink staticContract(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		if (!forced.isEmpty())
		{
			// no way to forced inlined term.
			return null;
		}
		return contractum.staticContract(sink, valuation, renamings);
	}

	/**
	 * Check that term is a well-formed pattern and construct list of pattern meta-applications.
	 * @param pattern to search
	 * @param free free variables allowed in pattern (where they must occur)
	 * @param comparable meta-variables that may be used more than once in the pattern
	 * @param weak meta-variables that are permitted to not have complete list of bound variables
	 * @param metaApplications to accumulate metaapplications
	 *    - all the metaapplications of term will have been added in order on successful return
	 *    (for non-linear patterns some metavariable will have been added more than once)
	 * @param propertiesRefs to accumulate the special meta-applications used for properties references
	 * @param metaSorts sorts of meta-variables implied by the rule 
	 * @param bound variables in context
	 * @param occurrences number of times this meta-variable occurs in the pattern
	 * @param allowFree whether free variables can be matched
	 * @throws CRSException if term is not a subpattern
	 */
	private void checkPattern(final Term pattern, final Map<String, Term> free, final Set<String> comparable, final Set<String> weak, final Map<String, Term> metaApplications, final Set<String> propertiesRefs, final Map<String, String> metaSorts, final SimpleVariableSet bound, final Map<String, Integer> occurrences)
			throws CRSException
	{
		// Free variables that have not yet been encountered.
		final Set<Variable> unusedFree = new HashSet<Variable>();
		for (Term freeDecl : free.values())
			unusedFree.add(Util.variableWithOptionalSortVariable(freeDecl));
		// Visitor that checks pieces of the pattern and augments structures in the process...
		final Visitor visitor = new Visitor()
			{
				/** Linear variables that have already been used. */
				final Set<Variable> linearVariables = new HashSet<Variable>();

				/** Sorts of bound variables in the pattern. */
				final Map<Variable, String> boundVariableSorts = new HashMap<Variable, String>();

				/** Nesting of primitive wrappers... */
				private int primitiveNesting;

				/** Internal error. handling */
				private void error(String msg, boolean recoverable) throws CRSException
				{
					ruleError(msg, lax && recoverable, recoverable);
				}

				@Override
				public void visitPrimitive(Primitive primitive, boolean start) throws CRSException
				{
					if (start)
						++primitiveNesting;
					else
						--primitiveNesting;
				}

				@Override
				public void visitPrimitiveNormal(Primitive primitive, boolean start) throws CRSException
				{
					if (start)
						--primitiveNesting;
					else
						++primitiveNesting;
				}

				@Override
				public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start && primitiveNesting == 0)
						checkConstructionSort(construction, "pattern", boundVariableSorts, metaSorts);
				}

				@Override
				public void visitMetaApplication(Term term, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start)
					{
						// Check the metaapplication 
						final int arity = term.arity();
						final String metaVariable = term.metaVariable();
						final Term previous = metaApplications.get(metaVariable);
						if (previous == null)
						{
							// New meta-application - check it has only distinct bound variable arguments. 
							metaApplications.put(metaVariable, term);
							final List<Variable> seen = new ArrayList<Variable>(arity);
							for (int i = 0; i < arity; ++i)
							{
								Term t = term.sub(i);
								if (t.kind() != Kind.VARIABLE_USE)
									error("pattern meta-application " + term + " contains non-variable argument " + t, false);
								else
								{
									Variable v = t.variable();
									if (seen.contains(v))
										error(
												"pattern meta-application " + term + " contains repeated variable argument " + t,
												false);
									else if (!bound.contains(v))
										error(
												"pattern meta-application " + term + " contains unbound variable argument " + t,
												false);
									else
										seen.add(v);
								}
							}
							if (seen.size() < bound.size() && !weak.contains(metaVariable))
							{
								error("pattern meta-application " + term + " omits bound variables yet is not declared Weak", true);
								weak.add(metaVariable);
							}
							occurrences.put(metaVariable, 1);
						}
						else
						{
							// Already seen - check that is permitted!
							if (!comparable.contains(metaVariable))
							{
								error(
										"pattern meta-application "
												+ term + " cannot be used more than once without a Comparable declaration",
										true);
								comparable.add(metaVariable);
							}
							// Check it is the same and does not include non-promiscuous variables!
							if (arity != previous.arity())
								error("pattern meta-application " + term + " used with different arity by " + previous, false);
							else
								for (int i = 0; i < arity; ++i)
								{
									Variable previousV = previous.sub(i).variable();
									Term t = term.sub(i);
									if (t.kind() != Kind.VARIABLE_USE)
										error("pattern meta-application " + term + " contains non-variable argument " + t, false);
									else
									{
										Variable v = t.variable();
										if (!previousV.equals(v))
											error(
													"repeated pattern meta-application "
															+ term + " contains different variable (" + t
															+ ") from previous instances (" + previous + ")",
													false);
										else if (!v.promiscuous())
											error(
													"repeated pattern meta-application "
															+ term + " contains non-promiscuous variable (" + t + ")",
													false);
									}
								}
							occurrences.put(metaVariable, occurrences.get(metaVariable) + 1);
						}
					}
				}

				@Override
				public void visitMetaProperty(String name, boolean start, boolean hasMapping) throws CRSException
				{
					if (start)
					{
						// TODO: should do a proper check. For now just account for it
						final Term previous = metaApplications.get(name);
						if (previous == null)
						{
							// First occurrence
							Term metaVariable = crs.factory.newMetaApplication(name, null);
							metaApplications.put(name, metaVariable);
							occurrences.put(name, 1);
						}
					}
				}

				@Override
				public void visitBound(Variable v, VariableUpdater updater) throws CRSException
				{
					if (!v.promiscuous())
					{
						if (linearVariables.contains(v))
							error("pattern uses non-promiscuous bound variable twice (" + v + " in " + pattern + ")", false);
						else
							linearVariables.add(v);
					}
					if (fresh.containsKey(v.name()))
						error("pattern reuses name declared as fresh as bound (" + v + " in " + pattern + ")", true);
					if (free.containsKey(v.name()))
						error("pattern reuses name declared as free as bound (" + v + " in " + pattern + ")", true);
				}

				@Override
				public void visitFree(Variable v, VariableUpdater updater) throws CRSException
				{
					unusedFree.remove(v);
					if (!free.containsKey(v.name()) && !global.containsKey(v.name()))
					{
						error("pattern contains unauthorized free variable (" + v + " in " + pattern + ")", true);
						free.put(v.name(), crs.factory.newVariableUse(v));
					}
					if (fresh.containsKey(v.name()))
					{
						error(
								"pattern contains free variable that is declared fresh in contractum ("
										+ v + " in " + pattern + ")",
								true);
						free.put(v.name(), fresh.remove(v.name()));
					}
					else
					{
						if (!v.promiscuous())
						{
							if (linearVariables.contains(v))
								error("pattern uses non-promiscuous free variable twice (" + v + " in " + pattern + ")", false);
							else
								linearVariables.add(v);
						}
						for (Term g : global.values())
						{
							Variable gv = Util.variableWithOptionalSortVariable(g);
							if (v.name().equals(gv.name()))
								updater.setVariable(gv); // use global instance
						}
					}
				}

				@Override
				public void visitPropertiesRef(String metaVariable, boolean start) throws CRSException
				{
					if (start && primitiveNesting == 0)
					{
						if (propertiesRefs.contains(metaVariable) && !comparable.contains(metaVariable))
						{
							error(
									"pattern uses non-comparable environment capture meta-variable twice (" + metaVariable + ")",
									true);
							comparable.add(metaVariable);
						}
						propertiesRefs.add(metaVariable);
					}
				}
			};
		pattern.visit(visitor, SimpleVariableSet.EMPTY);
		if (!unusedFree.isEmpty())
		{
			ruleError(name + " rule pattern omits free variables so they cannot be matched " + unusedFree, true, true);
			for (Variable v : unusedFree)
				free.remove(v.name());
		}
	}

	private void checkConstructionSort(Term construction, String where, Map<Variable, String> boundVariableSorts, Map<String, String> metaSorts)
			throws CRSException
	{
		/*
		final Constructor constructor = construction.constructor();
		Set<String> sorts = crs.factory().sortsOf(constructor);
		if (sorts != null && sorts.size() == 1)
		{
			final String sort = sorts.iterator().next();
			final Term form = crs.factory().formOf(sort, constructor);
			final int arity = construction.arity();
			if (form == null)
				crs.error(where + " construction sort problem: " + construction + " sort " +sort+" has  no forms", lax);
			else if (arity != form.arity())
				crs.error(where + " construction sort mismatch: " + construction + " has arity different from declaration in sort " +sort, lax);
			else
				for (int i = 0; i < arity; ++i)
				{
					final Variable[] binders = construction.binders(i);
					final Variable[] formBinders = form.binders(i);
					if (binders.length != formBinders.length)
						crs.error(where + " construction sort mismatch: " + construction + "'s "+i+" parameter has binder rank different from declaration in sort " +sort, lax);
					else
					{
						final Term formSub = form.sub(i);
						final PropertiesHolder formSubProperties = Util.propertiesHolder(formSub);
						for (int j = 0; j < binders.length; ++j)
						{
							final Variable binder = binders[j];
							final Variable formBinder = formBinders[j];
							final String binderSort = Util.symbol(formSubProperties.getProperty(formBinder));
							boundVariableSorts.put(binder, binderSort);
						}
						final String subSort = crs.factory().getSortByName(Util.symbol(form.sub(i)));
						if (!subSort.equals(Sorting.ANY_SORT))
						{
							final Term sub = construction.sub(i);
							switch (sub.kind())
							{
								case CONSTRUCTION : {
									final Constructor c = sub.constructor();
									Set<String> ss = crs.factory().sortsOf(c);
									if (ss != null && ss.size() == 1)
									{
										final String s = crs.factory().getSortByName(ss.iterator().next());
										// TODO
										if (!subSort.equals(s))
											crs.error(where + " construction sort mismatch: " + construction + "'s "+i+" parameter has sort " +s+" instead of "+subSort, lax);
									}
									break;
								}
								case VARIABLE_USE : {
									String s = crs.factory().getSortByName(boundVariableSorts.get(sub.variable()));
									if (s != null)
										crs.error(where + " construction sort mismatch: " + construction + "'s "+i+" parameter has sort " +s+" instead of "+subSort, lax);
									break;
								}
								case META_APPLICATION : {
									String s = crs.factory().getSortByName(metaSorts.get(sub.metaVariable()));
									if (s != null)
										crs.error(where + " construction sort mismatch: " + construction + "'s "+i+" parameter has sort " +s+" instead of "+subSort, lax);
									break;
								}
							}
						}
					}
				}
		}
		*/
	}

	/**
	 * Check that term is well-formed contractum for a given list of pattern meta-applications.
	 * @param contractum to check
	 * @param free free variables from the pattern, with their declaration
	 * @param noMeta if set then the contractum does not permit unmatched meta-applications
	 * @param shared contains the names of meta-variables that can occur more than once and should be shared
	 * @param copied contains the names of meta-variables that can occur more than once and may be copied
	 * @param discarded contains the names of meta-variables that do not occur in the contractum
	 * @param shallow contains the shallow variable names
	 * @param patternMetaApplications meta-applications from the pattern
	 * @param patternPropertiesRefs meta-applications used to reference properties in pattern
	 * @param patternMetaSorts sort constraints on meta-variables from pattern
	 * @param contractumMetaVariables to accumulate all metaapplications into
	 *    - on succesful completion contains all the contractum metaapplications in order
	 * @param contractionCounts maps each meta-variable to 0 or null if unused, positive if number of uses known, -1 if unknown.
	 * @param nonExplicit contains those meta-variables that occur in non-explicit configuration
	 * @param reusable populated with mapping from bound variables in {@link #patternMetaApplications} to those in {@link #term}
	 * @param reusableOrigin maps bound variable in pattern to combined meta-variable/index 
	 * @param that the contraction is in (for errors)
	 * @throws CRSException when contractum is malformed
	 */
	private void checkContractum(final Term contractum, final Map<String, Term> free, final boolean noMeta, final Set<String> shared, final Set<String> copied, final Set<String> discarded, final Set<Variable> shallow, final Map<String, Term> patternMetaApplications, final Set<String> patternPropertiesRefs, final Map<String, String> patternMetaSorts, final List<String> contractumMetaVariables, final Map<String, Integer> contractionCounts, final Set<String> nonExplicit, final Map<Variable, Variable> reusable, final Map<Variable, Pair<String, Integer>> reusableOrigin)
			throws CRSException
	{
		//if (Util.isConstant(contractum) && crs.factory().isSortConstructor(Util.symbol(contractum)))
		//	crs.factory.warning(name + " rule contractum seems to be a sort -- maybe this should be a sort declaration?");
		final Set<String> usedFresh = new HashSet<String>();

		// Shallow variables (candidates)
		final Map<Variable, Boolean> maybeShallow = new IdentityHashMap<Variable, Boolean>(4);

		final Visitor visitor = new Visitor()
			{
				/** Internal error. handling */
				private void error(String msg, boolean recoverable) throws CRSException
				{
					ruleError(msg, lax && recoverable, recoverable);
				}

				/** Keep track of linearity of each meta-application argument - initially true. */
				final List<Boolean> linearSubstitutionContexts = new ArrayList<Boolean>();

				{
					linearSubstitutionContexts.add(true);
				}

				/** Linear variables that have already been used. */
				final Set<Variable> linearVariables = new HashSet<Variable>(4);

				/** Sorts of bound variables in the pattern. */
				final Map<Variable, String> boundVariableSorts = new HashMap<Variable, String>(4);

				/** Nesting of primitive wrappers... */
				private int primitiveNesting;

				/** Expect inlined pattern argument  */
				private boolean declmeta;

				/** Binders stack. */
				final Deque<Variable[]> scopedBinders = new ArrayDeque<Variable[]>();

				/** Pending Metavariable stack. */
				final Deque<List<String>> pendingScopedMeta = new ArrayDeque<List<String>>();

				/** Metavariable stack. */
				final Deque<List<String>> scopedMeta = new ArrayDeque<List<String>>();

				@Override
				public void visitPrimitive(Primitive primitive, boolean start) throws CRSException
				{
					if (start)
						++primitiveNesting;
					else
						--primitiveNesting;
				}

				@Override
				public void visitPrimitiveNormal(Primitive primitive, boolean start) throws CRSException
				{
					if (start)
						--primitiveNesting;
					else
						++primitiveNesting;
				}

				@Override
				public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start && declmeta)
					{
						if (!Util.symbol(construction).matches("Tuple[0-9]*"))
							error(
									"pattern argument contractum must either be a meta variable or a TupleN construction ("
											+ construction + ")",
									false);
					}

					if (start && primitiveNesting == 0)
						checkConstructionSort(construction, "contractum", boundVariableSorts, patternMetaSorts);

				}

				@Override
				public void visitConstructionSub(Term construction, int index, boolean start, Set<Variable> bound)
						throws CRSException
				{
					if (start)
					{
						Variable[] binders = construction.binders(index);

						// Binders on meta cannot be shallow 
						if (construction.sub(index).kind() != Kind.META_APPLICATION)
						{
							for (int i = 0; i < binders.length; i++)
								maybeShallow.put(binders[i], true);
						}

						// Disallow binders in pattern argument
						if (declmeta && binders.length > 0)
							error("pattern argument in contractum cannot contain binders (" + construction + ")", false);

						scopedBinders.push(binders);

						if (construction instanceof GenericEvaluator && index > 0)
						{
							switch (((GenericEvaluator) construction).primitive())
							{
								case LET :
									if (index == 1)
									{
										declmeta = true;
										pendingScopedMeta.push(new ArrayList<String>());
									}
									else if (index == 3)// Body: pending scoped metas are now in scope
										scopedMeta.push(pendingScopedMeta.pop());
									break;
								case FOR :
									if (index == 1) // variables
									{
										declmeta = true;
										pendingScopedMeta.push(new ArrayList<String>());
									}
									else if (index == 3) // params
									{
										declmeta = true;
										pendingScopedMeta.push(new ArrayList<String>());
									}
									else if (index == 5) // body
									{
										// both, variable and params are inscope 
										scopedMeta.push(pendingScopedMeta.pop()); // params
										scopedMeta.push(pendingScopedMeta.pop()); // variables
									}
									break;
								default :
									break;
							}
						}
					}

					super.visitConstructionSub(construction, index, start, bound);

					if (!start)
					{
						scopedBinders.pop();

						if (construction instanceof GenericEvaluator && index > 0)
						{
							switch (((GenericEvaluator) construction).primitive())
							{
								case LET :
									if (index == 1)
										declmeta = false;
									else if (index == 3)
										scopedMeta.pop();
									break;
								case FOR :
									if (index == 1 || index == 3)
										declmeta = false;
									else if (index == 5)
									{
										// Only variables goes out of scope.
										scopedMeta.pop(); // variables
									}
									else if (index == 6)
									{
										scopedMeta.pop(); // params
									}
									break;
								default :
									break;
							}
						}
					}
				}

				@Override
				public void visitMetaApplication(Term term, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start)
					{
						if (declmeta)
						{
							final String metaVariable = term.metaVariable();
							Term pattern = patternMetaApplications.get(metaVariable);
							if (pattern != null)
								error("contractum cannot redeclare meta-variable (" + term + ")", false);
							pendingScopedMeta.peek().add(metaVariable);
						}
						else
						{
							// Check the meta-application.
							final String metaVariable = term.metaVariable();
							if (patternPropertiesRefs.contains(metaVariable))
								error(
										"contractum uses property reference meta-variable in regular meta-application ("
												+ term + ")",
										false);
							contractumMetaVariables.add(metaVariable);
							if (discarded.contains(metaVariable))
							{
								error("contractum uses discarded meta-variable (" + term + ")", true);
								discarded.remove(metaVariable);
							}
							Term pattern = patternMetaApplications.get(metaVariable);
							if (pattern == null && noMeta)
							{
								if (!hasMeta(metaVariable, scopedMeta))
									error("contractum uses undefined meta-variable (" + term + ")", false);
							}
							final int arity = term.arity();
							if (pattern != null && arity != pattern.arity())
								error("contractum uses meta-variable with wrong arity (" + term + ")", false);

							// Check if this meta-variable occurs in non-explicit configuration (Bloo & Rose, RTA '96).
							// Explicit means that the arguments are the same variables as in the pattern...which means they can be reused!
							// If ALL variables are reused then the contractum is 'explicit'.
							if (pattern != null && !nonExplicit.contains(metaVariable))
							{
								// Candidate for being explicit...
								Map<Variable, Variable> newReusable = new HashMap<Variable, Variable>();
								boolean explicit = true; // so far
								CheckExplicit : for (int i = 0; i < arity; ++i)
								{
									Term sub = term.sub(i);
									if (sub.kind() == Kind.VARIABLE_USE)
									{
										Variable contractumVariable = sub.variable();
										if (free.containsKey(contractumVariable.name()))
										{
											explicit = false;
											break; // FAIL because we're substituting an existing free variable!
										}
										if (pattern.arity() <= i)
											error(
													"rule contractum has inconsistent arity for pattern meta-application ("
															+ pattern + ")",
													false);
										Variable patternVariable = pattern.sub(i).variable();

										if (patternVariable.blocking())
											break; // FAIL because functional binders can't be reused.

										Variable reusedPatternVariable = reusable.get(patternVariable);
										if (newReusable.containsValue(contractumVariable))
										{
											explicit = false;
											break; // FAIL because we're copying a free variable to two bound positions
										}
										if (reusedPatternVariable == null)
										{
											reusedPatternVariable = newReusable.get(patternVariable);
											if (reusedPatternVariable == null)
											{
												for (Map.Entry<String, Term> e : free.entrySet())
													if (Util.variableWithOptionalSortVariable(e.getValue()) == contractumVariable)
													{
														explicit = false;
														break CheckExplicit; // FAIL because we must properly substitute existing free variables
													}
												reusedPatternVariable = contractumVariable;
												newReusable.put(patternVariable, reusedPatternVariable);
												reusableOrigin.put(patternVariable, new Pair<String, Integer>(metaVariable, i));
											}
										}
										if (!reusedPatternVariable.equals(contractumVariable))
										{
											explicit = false;
											break; // FAIL because the variable could not be reused without conflict
										}
									}
									else
									{
										// Non-variable.
										explicit = false;
										break;
									}
								}
								if (explicit)
									reusable.putAll(newReusable); // commit the variable reuses
								else
									nonExplicit.add(metaVariable);
							}

							// Register the meta-variable contraction count, if it can be known...
							if (linearSubstitutionContexts.get(linearSubstitutionContexts.size() - 1))
							{
								// Context is linear so try to include in count (unless already non-linear, i.e., Integer.MAX_VALUE).
								Integer count = contractionCounts.get(metaVariable);
								if (count == null)
									// First occurrence...sofar linear!
									contractionCounts.put(metaVariable, 1);
								else if (count > 0)
								{
									// Following occurrence. 
									if (!shared.contains(metaVariable)
											&& !copied.contains(metaVariable)
											&& (noMeta || patternMetaApplications.containsKey(metaVariable)))
									{
										error(
												"contractum uses non-shared/copyable meta-variable twice (" + metaVariable + ")",
												true);
									}
									contractionCounts.put(metaVariable, count + 1);
								}
							}
							else
							{
								// Used to require explicit Copy[]...
								if (!shared.contains(metaVariable)
										&& !copied.contains(metaVariable)
										&& (noMeta || patternMetaApplications.containsKey(metaVariable)))
								{
									error(
											"contractum uses non-shared/copyable meta-variable in place that may be copied ("
													+ metaVariable + ")",
											true);
									copied.add(metaVariable);
								}
								// Not linear (nested in substitution) so insist the meta-variable cannot be counted.
								contractionCounts.put(metaVariable, -1);
								// TODO: count should be incremented normally for substitution for non-promiscuous variable...later.
							}
						}
					}
				}

				@Override
				public void visitMetaProperty(String metaVariable, boolean start, boolean hasMapping) throws CRSException
				{
					if (declmeta)
						error(
								"pattern argument in contraction cannot contain meta property ("
										+ metaVariable + " in " + contractum + ")",
								false);

					// When meta-variable is used to construct property key (name or variable)...pieces from visitMetaApplication above.
					if (start)
					{
						contractumMetaVariables.add(metaVariable);
						if (discarded.contains(metaVariable))
						{
							error("contractum uses discarded meta-variable (" + metaVariable + ")", true);
							discarded.remove(metaVariable);
						}
						Term pattern = patternMetaApplications.get(metaVariable);
						if (pattern == null && noMeta)
							error("contractum uses undefined meta-variable (" + metaVariable + ")", false);
						if (pattern != null && 0 != pattern.arity())
							error("contractum uses meta-variable with wrong arity (" + metaVariable + ")", false);

						// Register the meta-variable contraction count, if it can be known...
						if (linearSubstitutionContexts.get(linearSubstitutionContexts.size() - 1))
						{
							// Context is linear so try to include in count (unless already non-linear, i.e., Integer.MAX_VALUE).
							Integer count = contractionCounts.get(metaVariable);
							if (count == null)
								// First occurrence...sofar linear!
								contractionCounts.put(metaVariable, 1);
							else if (count > 0)
							{
								// Following occurrence. 
								if (!shared.contains(metaVariable) && !copied.contains(metaVariable) && noMeta)
								{
									error("contractum uses non-shared/copyable meta-variable twice (" + metaVariable + ")", true);
									copied.add(metaVariable);
								}
								contractionCounts.put(metaVariable, count + 1);
							}
						}
						else
						{
							// Used to require explicit Copy[]...
							if (!shared.contains(metaVariable) && !copied.contains(metaVariable) && noMeta)
							{
								error(
										"contractum uses non-shared/copyable meta-variable in place that may be copied ("
												+ metaVariable + ")",
										true);
								copied.add(metaVariable);
							}
							// Not linear (nested in substitution) so insist the meta-variable cannot be counted.
							contractionCounts.put(metaVariable, -1);
							// TODO: count should be incremented normally for substitution for non-promiscuous variable...later.
						}
					}
				}

				@Override
				public void visitMetaApplicationSub(Term term, int index, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start)
					{
						final String metaVariable = term.metaVariable();
						Term pattern = patternMetaApplications.get(metaVariable); // may be null when free meta-variables allowed
						if (pattern != null
								&& pattern.arity() == term.arity()
								&& linearSubstitutionContexts.get(linearSubstitutionContexts.size() - 1))
						{
							// Push linearity of this meta-application argument.
							Variable patternVariable = pattern.sub(index).variable();
							linearSubstitutionContexts.add(patternVariable != null && !patternVariable.promiscuous());
						}
						else
						{
							linearSubstitutionContexts.add(false);
						}

						// meta does not define binders
						scopedBinders.push(GenericTerm.NO_BIND);
					}
					else
					{
						// Pop linearity of this meta-application argument.
						linearSubstitutionContexts.remove(linearSubstitutionContexts.size() - 1);

						scopedBinders.pop();
					}
				}

				/* @see net.sf.crsx.Visitor#visitPropertiesRef(java.lang.String, boolean)*/
				@Override
				public void visitPropertiesRef(String metaVariable, boolean start) throws CRSException
				{
					if (declmeta)
						error(
								"pattern argument in contraction cannot property reference ("
										+ metaVariable + " in " + contractum + ")",
								false);

					if (start)
					{
						if (!patternPropertiesRefs.contains(metaVariable) && noMeta)
							error("contractum uses undefined property reference meta-variable (" + metaVariable + ")", false);
					}
				}

				@Override
				public void visitBound(Variable v, VariableUpdater updater) throws CRSException
				{
					if (declmeta)
						error(
								"pattern argument in contraction cannot contain bound variable (" + v + " in " + contractum + ")",
								false);

					if (!v.promiscuous())
					{
						if (linearVariables.contains(v))
							error("contractum uses non-promiscuous bound variable twice (" + v + " in " + contractum + ")", false);
						//                        if (!linearSubstitutionContexts.get(linearSubstitutionContexts.size() - 1))
						//                            crs.error("contractum uses non-promiscuous bound variable in promiscuous context (" + v + " in " + contractum + ")", false);
						else
							linearVariables.add(v);
					}
					if (fresh.containsKey(v.name()))
						error("contraction reuses name declared as fresh as bound (" + v + " in " + contractum + ")", true);
					if (free.containsKey(v.name()))
						error("contraction reuses name declared as free as bound (" + v + " in " + contractum + ")", true);

					if (!Util.contains(scopedBinders.peek(), v)) // x.x case
					{
						if (scopedBinders.size() >= 2)
						{
							Variable[] last = scopedBinders.pop();

							if (!Util.contains(scopedBinders.peek(), v)) // x.C[x] case
							{
								maybeShallow.remove(v);
								if (v.shallow())
									error(
											"contraction uses a deep variable declared as shallow ("
													+ v + " in " + contractum + ")",
											true);
							}

							scopedBinders.push(last);
						}
					}
				}

				@Override
				public void visitFree(Variable v, VariableUpdater updater) throws CRSException
				{
					if (declmeta)
						error("pattern argument in contraction cannot free variable (" + v + " in " + contractum + ")", false);

					// Maybe global?
					for (Term g : global.values())
					{
						Variable gv = Util.variableWithOptionalSortVariable(g);
						if (v.name().equals(gv.name()))
						{
							v = gv;
							updater.setVariable(v); // use global instance
							break;
						}
					}
					if (!free.containsKey(v.name()) && !fresh.containsKey(v.name()) && !global.containsKey(v.name()))
					{
						error("contractum contains unauthorized fresh variable (" + v + ")", false);
					}
					Variable realV = Util.variableWithOptionalSortVariable(free.get(v.name()));
					if (realV == null)
					{
						realV = v;
						if (lax && !global.containsKey(v.name()) && !fresh.containsKey(v.name()))
						{
							fresh.put(v.name(), crs.factory.newVariableUse(v));
							updater.setVariable(realV);
						}
					}
					if (!realV.promiscuous())
					{
						if (linearVariables.contains(realV))
						{} //error("contractum uses linear free variable twice (" + contractum + ")", false);
							//if (!linearSubstitutionContexts.get(linearSubstitutionContexts.size() - 1))
							//	error("contractum uses non-promiscuous free variable in promiscuous context (" + realV + " in " + contractum + ")", false);
						linearVariables.add(realV);
					}
					if (!free.containsKey(v.name()) && !global.containsKey(v.name()))
						usedFresh.add(v.name());
					if (shallow.contains(v))
						error("contractum declared free variable as shallow (" + v + ")", true);
				}
			};
		contractum.visit(visitor, SimpleVariableSet.EMPTY);

		// Check for forgotten meta-applications.

		Set<String> unused = new SmallSet<String>(patternMetaApplications.keySet());
		unused.removeAll(contractumMetaVariables);
		for (String u : unused)
			if (!discarded.contains(u))

			{
				ruleError("contractum discards meta-variable without Discard declaration (" + u + ")", true, false);
				discarded.add(u);
			}

		// Check for unused fresh.
		Set<String> declaredFresh = new HashSet<String>(fresh.keySet());
		declaredFresh.removeAll(usedFresh);
		if (!declaredFresh.isEmpty())

		{
			ruleError("rule declares fresh variables not used in contractum (" + declaredFresh + ")", true, false);
			for (String varname : declaredFresh)
				fresh.remove(varname);
		}

		shallow.clear();
		for (Variable v : maybeShallow.keySet())

		{
			if (!v.shallow())
			{
				//ruleError("contraction uses a shallow variable but marker is missing (" + v + " in " + contractum + ")", true, true);
				((GenericVariable) v).setShallow(true);
			}

			shallow.add(v);
		}

	}

	/**
	 * Test meta is inscoped
	 * @param meta to look for
	 * @return
	 * @throws CRSException 
	 */
	private boolean hasMeta(final String meta, final Deque<List<String>> inscope)
	{
		for (List<String> metas : inscope)
		{
			if (metas.contains(meta))
				return true;
		}
		return false;
	}

	/**
	 * Gets the construction holding the binder corresponding to the variable
	 * @param x
	 * @return
	 * @throws CRSException 
	 */
	private Pair<Term, Integer> findBinder(final Variable x) throws CRSException
	{
		@SuppressWarnings("unchecked")
		final Pair<Term, Integer>[] result = new Pair[1];
		result[0] = null;
		final Visitor visitor = new Visitor()
			{

				@Override
				public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start && result[0] == null)
					{
						for (int i = construction.arity() - 1; i >= 0; i--)
						{
							if (Util.contains(construction.binders(i), x))
							{
								result[0] = new Pair<Term, Integer>(construction, i);
								break;
							}

						}
					}
					super.visitConstruction(construction, start, bound);
				}

			};
		pattern.visit(visitor, SimpleVariableSet.EMPTY);
		if (result[0] == null)
			contractum.visit(visitor, SimpleVariableSet.EMPTY);

		return result[0];
	}

	/**
	 * Report a possibly recoverable error.
	 * @param message to report
	 * @param recoverable whether rule can be recovered (changed to a warning when rule is {@link #lax})
	 * @param fully whether rule can be fully recovered (so no warning issued when rule is {@link #lax})
	 * @throws CRSException if fatal error thrown
	 */
	void ruleError(String message, boolean recoverable, boolean fully) throws CRSException
	{
		if (recoverable && lax)
		{
			if (!fully)
				crs.factory.warning(message, "Warning in rule " + name + " (fixed): ");
		}
		else
			crs.factory.error(message, "Error in rule " + name + ": ");
	}

	/**
	 * Write a textual representation of the rule.
	 * @param w to write to
	 * @param used variable names
	 * @param depth remaining before cut-off
	 * @param namedProps whether we include properties
	 * @param variableProps TODO
	 * @throws IOException in case of write failure
	 */
	void appendTo(Appendable w, Map<Variable, String> used, int depth, boolean namedProps, boolean variableProps) throws IOException
	{
		// Name with options.
		if (w instanceof FormattingAppendable)
			((FormattingAppendable) w).open(Util.externalizeConstructor(name()));
		else
			w.append(Util.externalizeConstructor(name()));
		//
		Set<Variable> free = new SmallSet<Variable>();
		pattern.addFree(free, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, null);
		if (!free.isEmpty() || !fresh.isEmpty() || !global.isEmpty() || !options.isEmpty())
		{
			if (w instanceof FormattingAppendable)
				((FormattingAppendable) w).open("[");
			else
				w.append("[");
			String sep = "";
			if (!free.isEmpty())
			{
				w.append(sep + Builder.FREE_OPTION_SYMBOL + Util.variableSetToString(free, used) + "\n");
				sep = ", ";
			}
			if (!fresh.isEmpty())
			{
				w.append(sep + Builder.FRESH_OPTION_SYMBOL + "[");
				String innerSep = "";
				for (Map.Entry<String, Term> e : fresh.entrySet())
				{
					w.append(
							innerSep
									+ Util.safeVariableName(
											Util.variableWithOptionalSortVariable(e.getValue()), used, false, false));
					Term sort = e.getValue();
					if (sort != null)
					{
						w.append(" : ");
						sort.appendTo(w, used, depth, false, namedProps, variableProps, null, false);
					}
					innerSep = ", ";
				}
				w.append("]\n");
				sep = ", ";
			}
			if (!global.isEmpty())
			{
				w.append(sep + Builder.GLOBAL_OPTION_SYMBOL + "[");
				String innerSep = "";
				for (Map.Entry<String, Term> e : global.entrySet())
				{
					w.append(
							innerSep
									+ Util.safeVariableName(
											Util.variableWithOptionalSortVariable(e.getValue()), used, false, false));
					Term sort = e.getValue();
					if (sort != null)
					{
						w.append(" : ");
						sort.appendTo(w, used, depth, false, namedProps, variableProps, null, false);
					}
					innerSep = ", ";
				}
				w.append("]\n");
				sep = ", ";
			}
			for (String o : options.keySet())
			{
				if (!o.equals(Builder.FREE_OPTION_SYMBOL)
						&& !o.equals(Builder.FRESH_OPTION_SYMBOL) && !o.equals(Builder.GLOBAL_OPTION_SYMBOL))
				{
					w.append(sep + o + "[");
					String innerSep = "";
					for (Term t : options.get(o))
					{
						w.append(innerSep);
						t.appendTo(w, used, depth, false, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false);
						innerSep = ",";
					}
					w.append("]");
					sep = ", ";
				}
			}
			if (w instanceof FormattingAppendable)
				((FormattingAppendable) w).close("]");
			else
				w.append("]");
		}
		w.append(" :");
		if (!reused.isEmpty())
		{
			w.append(" // Reuse:");
			for (Map.Entry<Variable, Variable> e : reused.entrySet())
				w.append(
						" "
								+ Util.safeVariableName(e.getKey(), used, false, false) + ":"
								+ Util.safeVariableName(e.getValue(), used, false, false));
		}
		w.append("\n");

		// Pattern.
		pattern.appendTo(w, used, depth - 1, false, namedProps, variableProps, null, false);
		// Arrow.
		w.append("\n→\n");
		// Contraction.
		contractum.appendTo(w, used, depth - 1, false, namedProps, variableProps, null, false);

		if (w instanceof FormattingAppendable)
			((FormattingAppendable) w).close("");
	}

	public String toString()
	{
		StringBuilder w = new StringBuilder();
		try
		{
			appendTo(w, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, false);
		}
		catch (IOException e)
		{}
		return w.toString();
	}

	// Copyable.

	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		sink = sink.start(sink.makeConstructor(Builder.RULE_SYMBOL));
		sink = sink.start(sink.makeConstructor(name())).end();
		sink = pattern.copy(sink, discard, renames);
		sink = contractum.copy(sink, discard, renames);
		sink = sink.end();
		return sink;
	}

}
