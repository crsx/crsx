/* Copyright (c) 2014 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import net.sf.crsx.Builder;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.generic.sort.SortUtil;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SimpleVariableSet;
import net.sf.crsx.util.Util;

/**
 * Simplify contractum.
 * 
 
 * <p>
 * A simplify contraction as the following characteristics:
 * <ul>
 * <li>Deep closures are transformed into shallow closure and continuation (see below)
 * <li>Meta closures are transformed into closure and substitution (see below)
 * </ul>
 * 
 * <p>
 * A deep closure is a closure where binder uses don't only occur directly on the closure itself
 * but at a deeper level. For instance:
 * 
 * <pre>F[b.{#E}DeepClosure[C[b]]]</pre>
 * 
 * is a deep closure because b occurs in a construction that is not directly where the binder has been defined.
 * It is instead simplified as follows:
 * 
 * <pre>
 * F[b.DeepClosure$C[{#E}Prop, b]] 
 * DeepClosure$C[{#E}#Prop, #b] → {#E}DeepClosure[C[#b]];
 * </pre>
 * 
 * <p>
 * A meta closure is a contraction on the form: 
 * 
 * <pre>  b<sub>1</sub>....b<sub>n</sub>....{#E}#[a<sub>1</sub> ... a<sub>n</sub>]</pre>
 * 
 * where the arguments contains the bound variables <code>b<sub>1..n</sub></code>.
 * <p>
 * It is rewriting as a closure effectively delaying the meta-substitution:
 * 
 * <pre>  b<sub>1</sub>....b<sub>n</sub>.{#E}Delay<i>I</i>[a<sub>1</sub> ... a<sub>n</sub>, ba<sub>1</sub> ... ba<sub>n</sub>.#[ba<sub>1</sub> ... ba<sub>n</sub>]]</pre>
 * 
 * 
 * <p>
 * Meta notes:
 * Needs to run after the sorter. Designed to run in parallel.
 * 
 * @author villardl
 */
public class Simplifier
{

	// The factory 
	private GenericFactory factory;

	// The global CRS system
	private GenericCRS crs;

	// Property holder counter
	int holderCounter;

	// 
	public Simplifier(GenericCRS crs)
	{
		super();

		this.crs = crs;
		this.factory = crs.factory;
		this.holderCounter = 1;
	}

	/**
	 * Implements $Simplify
	 * 
	 * @throws CRSException 
	 */
	public void simplify(Map<String, GenericRule> ruleByName) throws CRSException
	{
		Env1 state = new Env1();

		// First pass: simplify meta-closures
		for (Entry<String, GenericRule> entry : ruleByName.entrySet())
		{
			GenericRule rule = entry.getValue();

			state.changed = false;
			state.rule = rule;
			GenericTerm newContractum = eliminateMetaClosure(state, (GenericTerm) rule.getContractum(), SimpleVariableSet.EMPTY);

			if (state.changed)
			{
				GenericRule newRule = new GenericRule(crs, rule.name, rule.pattern, newContractum, rule.options);
				entry.setValue(newRule);
			}

		}

		// TODO: should avoid this step by maintaining the sort structure is the new rules..
		crs.sortify();

		// Second pass: simplify deep closures
		Collection<GenericRule> pendingRules = ruleByName.values();
		List<GenericRule> updatedRules = new LinkedList<>();
		state.counter = 1;

		while (!pendingRules.isEmpty())
		{
			state.newrules = new LinkedList<>();
			for (GenericRule rule : ruleByName.values())
			{

				// Some $ primitives are currently not properly sorted. Ignore rules containing those.
				PrimitiveDetector detector = new PrimitiveDetector();
				rule.getContractum().visit(detector, SimpleVariableSet.EMPTY);

				if (!detector.hasPrimitive)
				{
					state.changed = false;
					state.rule = rule;
					GenericTerm newContractum = eliminateDeepClosure(
							state, (GenericTerm) rule.getContractum(), new LinkedExtensibleSet<Pair<Variable, Term>>());

					if (state.changed)
					{
						GenericRule newRule = new GenericRule(crs, rule.name, rule.pattern, newContractum, rule.options);
						updatedRules.add(newRule);
					}
				}
			}

			// Add new rules to CRS
			for (GenericRule rule : state.newrules)
				crs.addRule(rule.name(), rule);

			// Continue with added rules
			pendingRules = state.newrules;

			crs.sortify();
		}

	}

	/**
	 * Simplify meta-closure on a term
	 * 
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateMetaClosure(Env1 state, GenericTerm term, ExtensibleSet<Variable> bound) throws CRSException
	{
		if (term instanceof PropertiesConstraintsWrapper)
		{
			// Recursively simplify properties.
			PropertiesConstraintsWrapper props = (PropertiesConstraintsWrapper) term;

			// TODO: simplify properties

			props.term = eliminateMetaClosure(state, props.term, bound);
			return props;
		}
		else
		{
			switch (term.kind())
			{
				case CONSTRUCTION :
					return eliminateMetaClosure(state, (GenericConstruction) term, bound);
				case META_APPLICATION :
					return eliminateMetaClosure(state, (GenericMetaApplication) term, bound);
				case VARIABLE_USE :
				default :
					return term;
			}
		}
	}

	/**
	 * Simplify meta-closure on a construction
	 * 
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateMetaClosure(Env1 state, GenericConstruction term, ExtensibleSet<Variable> bound)
			throws CRSException
	{
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			ExtensibleSet<Variable> subbound = bound.extend(term.binders(i));
			GenericTerm newsub = eliminateMetaClosure(state, term.sub(i), subbound);
			term.replaceSub(i, term.binders(i), newsub);
		}
		return term;
	}

	/**
	 * Simplify meta-closure on a meta application
	 *
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateMetaClosure(Env1 state, GenericMetaApplication term, ExtensibleSet<Variable> bound)
			throws CRSException
	{
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			ExtensibleSet<Variable> subbound = bound.extend(term.binders(i));
			GenericTerm newsub = eliminateMetaClosure(state, term.sub(i), subbound);
			term.replaceSub(i, term.binders(i), newsub);
		}

		if (state.rule.metaClosure(term, bound))
		{
			// Replace meta by Delay 
			Constructor delay = factory.makeConstructor("Delay" + term.arity());

			Variable[][] allbinders = new Variable[term.arity() + 1][];
			GenericTerm[] subs = new GenericTerm[term.arity() + 1];

			// In order to preserve variable name and binder, gets the metavar on the pattern
			GenericTerm metaOnPattern = state.rule.getMetaOnPattern(term.metaVariable);

			// Make binders.
			Variable[] binders = new Variable[term.arity()];
			GenericTerm[] args = new GenericTerm[term.arity()];
			for (int i = term.arity() - 1; i >= 0; i--)
			{
				Variable original = metaOnPattern.sub(i).variable();
				binders[i] = factory.makeVariable(original.name(), original.promiscuous());
				args[i] = factory.newVariableUse(binders[i]);

				allbinders[i] = GenericTerm.NO_BIND;
			}
			allbinders[term.arity()] = binders;

			// Make subs
			System.arraycopy(term.allSubs(), 0, subs, 0, term.allSubs().length);
			subs[term.arity()] = factory.newMetaApplication(term.metaVariable, args);

			// Finally make generic closure using Delay.
			state.changed = true;
			return factory.newConstruction(delay, allbinders, subs);
		}

		return term;
	}

	/**
	 * Simplify deep-closure on a term
	 * 
	 * @param state
	 * @param term
	 * @param bound variable, with sort.
	 * 
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateDeepClosure(Env1 state, GenericTerm term, ExtensibleSet<Pair<Variable, Term>> bound)
			throws CRSException
	{
		if (term instanceof PropertiesConstraintsWrapper)
		{
			// Recursively simplify properties.
			PropertiesConstraintsWrapper props = (PropertiesConstraintsWrapper) term;

			// TODO: simplify properties

			props.term = eliminateDeepClosure(state, props.term, bound);
			return props;
		}
		else
		{
			switch (term.kind())
			{
				case CONSTRUCTION :
					return eliminateDeepClosure(state, (GenericConstruction) term, bound);
				case META_APPLICATION :
					return eliminateDeepClosure(state, (GenericMetaApplication) term, bound);
				case VARIABLE_USE :
				default :
					return term;
			}
		}
	}

	/**
	 * Simplify deep-closure of a construction
	 * 
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateDeepClosure(Env1 state, GenericConstruction term, ExtensibleSet<Pair<Variable, Term>> bound)
			throws CRSException
	{
		if (Util.isEval(term.constructor))
			return term;

		String rulename = state.rule.name();

		for (int i = term.arity() - 1; i >= 0; i--)
		{
			GenericTerm sub = term.sub(i);
			Variable[] binders = term.binders(i);

			Pair<Term, Term> sortDeclaration = getSortDeclaration(rulename, term.constructor.symbol());
			Term[] binderSorts = getBindersSort(rulename, sortDeclaration.tail(), i);

			final boolean hasClosureMarker = sub.constructor() != null && sub.constructor().isClosure();
			final boolean hasDeepBinders = state.rule.isDeepClosure(term, i);
			if (hasClosureMarker && hasDeepBinders)
			{
				// The sub is a deep closure so eliminate...only if has marker

				ExtensibleSet<Pair<Variable, Term>> subbound = extend(bound, binders, binderSorts);

				Env2 env = new Env2(state.rule, subbound, sub.arity());

				GenericTerm contractum = rewrite(env, term, i, sub, binders, subbound);

				// Replace sub with call to the new closure.
				Constructor name = factory.makeConstructor(state.rule.name() + "$C$" + state.counter++);
				GenericTerm newsub = factory.newConstruction(
						name, env.argsBinders.toArray(GenericTerm.NO_BINDS), env.args.toArray(GenericTerm.NO_TERMS));
				term.replaceSub(i, binders, newsub);
				env.rule.reconcile();
				
				//System.out.println("=======\nupdated rule:" + state.rule);

				// Create new rule corresponding to the new closure
				GenericTerm pattern = factory.newConstruction(
						name, env.patternBinders.toArray(GenericTerm.NO_BINDS), env.patternArgs.toArray(GenericTerm.NO_TERMS));

				Pair<Term, Term> subSortDeclaration = getSortDeclaration(rulename, sub.constructor().symbol());
				if (subSortDeclaration == null)
					fatal("Missing sort declaration for construction " + sub.constructor().symbol() + " in rule " + rulename);

				// Wrap both pattern and contractum with properties reference (if form has it)
				final boolean subHasProperties = Util.hasProperties(subSortDeclaration.head())
						|| Util.hasProperties(subSortDeclaration.tail());
				final boolean subHasRef = Util.hasPropertyRef(sub);
				if (!subHasRef && subHasProperties)
				{
					String metaref = "#E$C";
					pattern = pattern.wrapWithPropertiesRef(metaref, true);
					contractum = contractum.wrapWithPropertiesRef(metaref, true);
				}

				HashMap<String, List<Term>> options = new HashMap<>(4);
				options.put(Builder.LAX_OPTION_SYMBOL, new LinkedList<Term>());

				GenericRule rule = new GenericRule(crs, name, pattern, contractum, options);

				//System.out.println("=======\nnew rule:" + rule);

				// Set meta sorts to rule so that the sortifier does not have to run after each main iteration (see simplify)!
				Map<String, Term> metavarSorts = new HashMap<>(8); // Map meta variable name to sorts
				for (int j = 0; j < env.patternArgs.size(); j++)
					metavarSorts.put(env.patternArgs.get(j).metaVariable(), env.patternArgsSort.get(j));

				rule.setMetaVariableSorts(metavarSorts);

				state.newrules.add(rule);

				// Add sort for new rule
				GenericTerm form = factory.newConstruction(
						name, env.patternBindersSort.toArray(GenericTerm.NO_BINDS),
						env.patternArgsSort.toArray(GenericTerm.NO_TERMS));

				if (!subHasRef && subHasProperties)
				{
					PropertiesHolder properties = null;
					if (Util.hasProperties(subSortDeclaration.head()))
						properties = Util.propertiesHolder(subSortDeclaration.head()); // data
					if (properties == null && Util.hasProperties(subSortDeclaration.tail()))
						properties = Util.propertiesHolder(subSortDeclaration.tail()); // function

					if (properties != null)
					{
						for (String prop : properties.propertyNames())
							form = form.wrapWithProperty(prop, properties.getProperty(prop), true);

						assert !properties.propertyVariables().iterator().hasNext();
					}
				}

				// The new closure is a function: strip properties (they are on the form)
				Term sortTerm = subSortDeclaration.head();
				if (Util.hasProperties(sortTerm))
					sortTerm = ((PropertiesConstraintsWrapper) sortTerm).term;

				factory.setSortForm(sortTerm, null, form, true, false);
			}
			else
			{
				if (hasDeepBinders)
				{
					if (factory.defined(Factory.SHOW_POTENTIAL_CLOSURE_OPTION))
						warning("construction "
								+ Util.symbol(sub) + " contains deep binder uses. Consider using the closure marker (^) in rule "
								+ rulename);
				}

				ExtensibleSet<Pair<Variable, Term>> subbound = extend(bound, binders, binderSorts);

				GenericTerm newsub = eliminateDeepClosure(state, term.sub(i), subbound);
				term.replaceSub(i, binders, newsub);
			}
		}
		return term;
	}

	/**
	 * Simplify a meta application
	 *
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 */
	private GenericTerm eliminateDeepClosure(Env1 state, GenericMetaApplication term, ExtensibleSet<Pair<Variable, Term>> bound)
	{
		// TODO: how to get the binders sorts?

		//		for (int i = term.arity() - 1; i >= 0; i--)
		//		{
		//			ExtensibleSet<Pair<Variable, Term>> subbound = extend(bound, term.binders(i), getBindersSort(state.rule.name(), symbol, subindex));
		//
		//			ExtensibleSet<Variable> subbound = bound.extend(term.binders(i));
		//			GenericTerm newsub = eliminateMetaClosure(state, term.sub(i), subbound);
		//			term.replaceSub(i, term.binders(i), newsub);
		//		}

		return term;
	}

	/**
	 * Rewrite term so that it contains no deep binders.
	 * 
	 * @param parent term's parent
	 * @param subindex 
	 * @param term 
	 * @param binders
	 * @param subbound 
	 * @return The term without deep binders, to be used within the closure body. 
	 * @throws CRSException 
	 */
	private GenericTerm rewrite(Env2 env, GenericTerm parent, int subindex, GenericTerm term, Variable[] binders, ExtensibleSet<Pair<Variable, Term>> bound)
			throws CRSException
	{
		if (Util.hasProperties(term))
		{
			Map<String, Term> newMetas = new HashMap<>(4);
			PropertiesConstraintsWrapper wrapper = null;
			if (term instanceof PropertiesConstraintsWrapper)
			{
				wrapper = (PropertiesConstraintsWrapper) term;

				String metaref = wrapper.propertiesRef();
				if (metaref != null)
				{
					// Capture {#E}Propx (if not captured yet)
					String prop = env.metavars.get(metaref);
					if (prop == null)
					{
						GenericTerm holder = makePropRefHolder(env, wrapper, subindex == 0 && Util.isEval(parent.constructor()));

						GenericTerm matcher = factory.newMetaApplication(metaref + env.patternArgs.size(), GenericTerm.NO_TERMS).wrapWithPropertiesRef(
								metaref, false);

						env.patternBinders.add(GenericTerm.NO_BIND);
						env.patternArgs.add(matcher);

						env.patternBindersSort.add(GenericTerm.NO_BIND);
						env.patternArgsSort.add(factory.sortOf(holder.constructor().symbol()));

						env.argsBinders.add(GenericTerm.NO_BIND);
						env.args.add(holder);

						env.metavars.put(metaref, holder.constructor().symbol());
					}
				}

				Map<String, Term> metaProperties = wrapper.metaPropertyConstraints;
				if (metaProperties != null)
				{
					for (Entry<String, Term> entry : metaProperties.entrySet())
					{
						GenericTerm newkey = rewrite(
								env, parent, subindex, factory.newMetaApplication(entry.getKey(), GenericTerm.NO_TERMS),
								GenericTerm.NO_BIND, bound);

						GenericTerm newterm = rewrite(
								env, parent, subindex, (GenericTerm) entry.getValue(), GenericTerm.NO_BIND, bound);

						// Always move meta inside closure
						newMetas.put(newkey.metaVariable(), newterm);
					}
				}
			}

			PropertiesHolder properties = Util.propertiesHolder(term);

			for (String name : properties.propertyNames())
			{
				GenericTerm newterm = rewrite(env, null, -1, (GenericTerm) properties.getProperty(name), GenericTerm.NO_BIND, bound);
				properties.setProperty(name, newterm);
			}

			List<Variable> oldVarProps = new LinkedList<>();

			for (Variable variable : properties.propertyVariables())
			{
				GenericTerm newkey = rewrite(env, parent, subindex, factory.newVariableUse(variable), GenericTerm.NO_BIND, bound);

				GenericTerm newterm = rewrite(
						env, parent, subindex, (GenericTerm) properties.getProperty(variable), GenericTerm.NO_BIND, bound);

				if (newkey.variable() == variable)
				{
					// Just update entry
					properties.setProperty(variable, newterm);
				}
				else
				{
					// Convert variable property to meta properties
					assert newkey.kind() == Kind.META_APPLICATION;

					newMetas.put(newkey.metaVariable(), newterm);
					oldVarProps.add(variable);
				}
			}

			for (Variable variable : oldVarProps)
				properties.removeProperty(variable);

			if (wrapper != null && wrapper.metaPropertyConstraints != null)
				wrapper.metaPropertyConstraints.clear();
			for (Entry<String, Term> entry : newMetas.entrySet())
			{
				term = term.wrapWithMetaProperty(entry.getKey(), entry.getValue(), true);
			}
		}

		switch (term.kind())
		{
			case VARIABLE_USE : {
				final Variable var = term.variable();

				if (contains(env.freeBinders, var) || !contains(bound, var))
				{
					// This is either a binder occurring before the term being rewritten
					// or it's a free/fresh variable.
					// Either case: they need to be captured!
					String meta = env.metavars.get(var);
					if (meta == null)
					{
						GenericTerm metavar = factory.newMetaApplication(
								"#" + term.variable().name() + env.patternArgs.size(), GenericTerm.NO_TERMS);
						env.metavars.put(var, metavar.metaVariable());

						env.patternBinders.add(GenericTerm.NO_BIND);
						env.patternArgs.add(metavar);

						env.patternBindersSort.add(GenericTerm.NO_BIND);

						Term varSort = getSort(bound, var);
						if (varSort == null)
						{
							// This is either a free or fresh variable. Sort is stored in the rule Option
							varSort = env.rule.getFresh(var);
							if (varSort == null)
							{
								// Free variable.
								varSort = env.rule.getVariableSort(var);
								if (varSort == null)
									fatal("Missing sort for free variable " + var.name() + " in rule " + env.rule.name());
							}
						}
						if (varSort.kind() != Kind.VARIABLE_USE && Util.isVariableWithOptionalSort(varSort))
							varSort = Util.variableWithOptionalSortSort(varSort);

						env.patternArgsSort.add(varSort);

						env.argsBinders.add(GenericTerm.NO_BIND);
						env.args.add(factory.newVariableUse(var));

						return metavar;
					}
					return factory.newMetaApplication(meta, GenericTerm.NO_TERMS);
				}

				return term;
			}
			case CONSTRUCTION :
				if (term.arity() == 0)
					return term;

				for (int i = 0; i < term.arity(); i++)
				{
					ExtensibleSet<Pair<Variable, Term>> subbound = bound;
					if (term.binders(i).length > 0)
						subbound = extend(bound, term.binders(i), getBindersSort(env.rule.name(), term.constructor().symbol(), i));

					GenericTerm sub = rewrite(env, term, i, term.sub(i), term.binders(i), subbound);
					term.replaceSub(i, term.binders(i), sub);
				}

				return term;

			case META_APPLICATION :
			default :
				// Capture (if not already captured!).
				String meta = env.metavars.get(term.metaVariable());
				if (meta == null)
				{
					// Capture metavar (which is potentially an abstraction)

					// A[a0...C[a1... #[...]]]
					// capture a1.#[a1] as a0 is before the closure
					GenericTerm metaSort = (GenericTerm) env.rule.getMetaVariableSort(term.metaVariable());
					if (metaSort == null)
						fatal("Missing sort for meta variable " + term.metaVariable() + " in rule " + env.rule.name());

					Variable[] patternBinders;
					GenericTerm[] patternSubs;
					Variable[] patternBindersSort;

					final int arity = term.arity();
					if (arity > 0)
					{
						GenericTerm original = env.rule.getMetaOnPattern(term.metaVariable());

						ArrayList<Variable> patternBindersA = new ArrayList<>();
						ArrayList<Variable> patternBindersSortA = new ArrayList<>();

						ArrayList<Term> patternSubsA = new ArrayList<>(); // Subs of the captured metavariable. All variables.

						for (int i = 0; i < arity; i++)
						{
							Term sub = term.sub(i);

							// If the contractum reuse a binder, preserve its name. Otherwise gets the name from the pattern.
							Variable var;
							if (sub.kind() == Kind.VARIABLE_USE)
								var = sub.variable();
							else
								var = original.sub(i).variable();

							// The variable is a binder occurring in the closure. Need to capture the binder
							Variable capturedBinder = factory.makeVariable(var.name(), var.promiscuous());
							patternBindersA.add(capturedBinder);

							patternSubsA.add(factory.newVariableUse(capturedBinder));

							// Update binder sorts
							Variable binderOnSort = factory.makeVariable(var.name(), var.promiscuous());
							patternBindersSortA.add(binderOnSort);
							Term varSort = env.rule.getVariableSort(var);
							if (varSort == null)
								fatal("Missing sort for variable " + var + " in rule " + env.rule.name());

							metaSort = metaSort.wrapWithProperty(binderOnSort, varSort, false); // binderOnSort.{binderOnSort:varSort}.MetaSort
							//							}
						}

						patternBinders = patternBindersA.toArray(GenericTerm.NO_BIND);
						patternSubs = patternSubsA.toArray(GenericTerm.NO_TERMS);
						patternBindersSort = patternBindersSortA.toArray(GenericTerm.NO_BIND);
					}
					else
					{
						patternBinders = GenericTerm.NO_BIND;
						patternSubs = GenericTerm.NO_TERMS;
						patternBindersSort = GenericTerm.NO_BIND;
					}

					GenericTerm metavar = factory.newMetaApplication(term.metaVariable(), patternSubs);

					env.patternBinders.add(patternBinders);
					env.patternArgs.add(metavar);

					env.patternBindersSort.add(patternBindersSort);
					env.patternArgsSort.add(metaSort);

					// Compute closure call arguments: same as on pattern
					env.argsBinders.add(patternBinders);
					env.args.add(metavar);

					env.metavars.put(term.metaVariable(), metavar.metaVariable());
				}

				// Substitute meta variable arguments
				GenericTerm[] metasubs;
				if (term.arity() == 0)
					metasubs = GenericTerm.NO_TERMS;
				else
				{
					metasubs = new GenericTerm[term.arity()];
					for (int i = 0; i < term.arity(); i++)
						metasubs[i] = rewrite(env, term, i, term.sub(i), GenericTerm.NO_BIND, bound);
				}

				GenericTerm metavar = factory.newMetaApplication(term.metaVariable(), metasubs);
				return metavar;
		}
	}

	/**
	 * Gets the sort declaration corresponding to the given constructor symbol
	 * @param rulename
	 * @param symbol
	 * @return
	 * @throws CRSException
	 */
	protected Pair<Term, Term> getSortDeclaration(String rulename, String symbol) throws CRSException
	{
		Pair<Term, Term> sortDeclaration = null;
		Set<Pair<Term, Term>> formSet = factory.formsOf(symbol);
		if (formSet != null && formSet.size() == 1)
			sortDeclaration = formSet.iterator().next();

		if (sortDeclaration == null)
			fatal("Missing sort declaration for symbol " + symbol + " in rule " + rulename);

		return sortDeclaration;
	}

	/**
	 * Extract binders sort from given sub
	 * 
	 * @throws CRSException 
	 */
	protected Term[] getBindersSort(String rulename, String symbol, int subindex) throws CRSException
	{
		Pair<Term, Term> sortDeclaration = getSortDeclaration(rulename, symbol);
		return getBindersSort(rulename, sortDeclaration.tail(), subindex);
	}

	/**
	 * Extract binders sort from given sub
	 * @param rulename TODO
	 * 
	 * @throws CRSException 
	 */
	protected Term[] getBindersSort(String rulename, Term form, int subindex) throws CRSException
	{
		// Extract binder sorts
		Variable[] formBinders = form.binders(subindex);
		Term subSort = form.sub(subindex);

		Term[] binderSorts = new Term[formBinders.length];
		for (int j = 0; j < formBinders.length; j++)
		{
			binderSorts[j] = Util.getProperty(subSort, formBinders[j]);
			if (binderSorts[j] == null)
				fatal("Missing sort for binder " + formBinders[j] + " in rule " + rulename);
		}

		return binderSorts;
	}

	/**
	 * Extend set with new binders and associated sort
	 * 
	 * @param binders
	 * @param binderSorts
	 * @return
	 */
	private ExtensibleSet<Pair<Variable, Term>> extend(ExtensibleSet<Pair<Variable, Term>> set, Variable[] binders, Term[] binderSorts)
	{
		if (binders == null)
			return set;

		for (int i = 0; i < binders.length; i++)
			set = set.extend(new Pair<Variable, Term>(binders[i], binderSorts[i]));

		return set;
	}

	/**
	 * Whether the set contains the variable
	 * @param set
	 * @param var
	 * @return
	 */
	private boolean contains(Set<Pair<Variable, Term>> set, Variable var)
	{
		for (Pair<Variable, Term> pair : set)
		{
			if (pair.head().equals(var))
				return true;
		}
		return false;
	}

	/**
	 * Get variable sort
	 * @param set
	 * @param var
	 * @return A form or null if not found
	 */
	private Term getSort(ExtensibleSet<Pair<Variable, Term>> set, Variable var)
	{
		for (Pair<Variable, Term> pair : set)
		{
			if (pair.head().equals(var))
				return pair.tail();
		}
		return null;
	}

	/**
	 * Make a construction holding the properties.
	 * 
	 * <p>Create a new data construction for the properties sort, if needed
	 * 
	 * @param env
	 * @param properties
	 * @param evaluator whether the properties are on the first argument of a $ function
	 * @return
	 * @throws CRSException
	 */
	private GenericTerm makePropRefHolder(Env2 env, PropertiesConstraintsWrapper properties, boolean evaluator) throws CRSException
	{
		final GenericRule rule = env.rule;
		String propref = properties.getRef();

		Map<String, Term> propertiesSort = SortUtil.sortSetOf(factory, rule, properties, evaluator);
		if (propertiesSort == null || propertiesSort.size() == 0)
			fatal("Missing properties sort for term " + properties + " in rule " + rule.name());

		String holderSymbol = env.propHolder.get(propertiesSort);
		if (holderSymbol == null)
		{
			int counter;
			synchronized (factory)
			{
				counter = holderCounter++;
			}

			holderSymbol = "PropsOf$C$" + counter;
			GenericConstruction holderCons = factory.constant(factory.makeConstructor(holderSymbol));

			// Make a data sort for it 
			GenericTerm holderSort = factory.constant(factory.makeConstructor(holderSymbol + "$Sort"));
			for (Entry<String, Term> entry : propertiesSort.entrySet())
				holderSort = holderSort.wrapWithProperty(entry.getKey(), entry.getValue(), false);

			factory.setSortForm(holderSort, null, holderCons, false, false);

			if (factory.sortsetFor(Util.symbol(holderSort)) == null)
			{
				fatal("Failed inserting sort set for " + holderSymbol + "$Sort");
			}

			env.propHolder.put(propertiesSort, holderSymbol);
		}

		GenericConstruction holderCons = factory.constant(factory.makeConstructor(holderSymbol));
		return holderCons.wrapWithPropertiesRef(propref, false);
	}

	// ========== error handling ========== //

	/**
	 * Give a warning to the user (but don't abort).
	 * @param txt the warning to be given
	 */
	private void warning(String txt)
	{
		factory.warning(txt, "Simplifier warning: ");
	}

	/**
	 * Give an error message to the user, which is collected and not shown
	 * until factory.errorCheck is called.
	 * @param txt the error to be displayed
	 * @throws CRSException if the error handler (the calling CRS) is set
	 * to be strict about errors 
	 */
	//	private void error(String txt) throws CRSException
	//	{
	//		factory.error(txt, "Simplifier error: ");
	//	}

	/** Throw a fatal error */
	private void fatal(String txt) throws CRSException
	{
		factory.fatal(txt, "Simplifier panic: ");
	}

	// ========== Inner class helpers ========== //

	// Top-level environment
	private static class Env1
	{
		GenericRule rule;
		boolean changed;
		int counter;
		List<GenericRule> newrules;
	}

	// Sub environment used by deep-closure rewriter
	private static class Env2
	{
		final GenericRule rule;

		final Set<Pair<Variable, Term>> freeBinders; // Binders occurring before the rewrite

		final List<Variable[]> patternBinders; // New closure argument binders.
		final List<GenericTerm> patternArgs;// New closure pattern arguments. All metas.
		final List<Variable[]> patternBindersSort;
		final List<Term> patternArgsSort;// New closure pattern arguments sorts.

		final List<Variable[]> argsBinders; // Closure call binders ($Cx)
		final List<GenericTerm> args;// Closure call arguments ($Cx)

		final Map<Object, String> metavars; // Map capture variable/metavars to new metavar name in closure
		final Map<Map<String, Term>, String> propHolder;

		public Env2(GenericRule rule, Set<Pair<Variable, Term>> freeBinders, int arity)
		{
			this.rule = rule;
			this.freeBinders = freeBinders;

			patternBinders = new ArrayList<>();
			patternArgs = new ArrayList<>();
			patternBindersSort = new ArrayList<>();
			patternArgsSort = new ArrayList<>();

			argsBinders = new ArrayList<>();
			args = new ArrayList<>();

			metavars = new HashMap<>();
			propHolder = new HashMap<>();

		}
	}

	// Detect whether term contains a $ primitive requiring sorting
	private static class PrimitiveDetector extends Visitor
	{
		// Whether the term has a primitive.
		boolean hasPrimitive;

		@Override
		public void visitPrimitive(Primitive primitive, boolean start) throws CRSException
		{
			switch (primitive)
			{
				case GET :
				case GET_REF :
					hasPrimitive = true;
					break;
				default :
					break;

			}
			super.visitPrimitive(primitive, start);
		}

	}

}
