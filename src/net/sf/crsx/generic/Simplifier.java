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
import net.sf.crsx.Sorting;
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
 * Performs closure conversion
 * 
 * <p>
 * In CRSX, closure conversion is equivalent to transforming deep binder occurrences into shallow occurrences.
 * Here an illustrative example of a deep binder occurrence:
 * 
 * <pre>... → {#E1}C1[b.{#E2}C2[C3[b]]]</pre>
 * 
 * It is simplified as follows:
 * 
 * <pre>
 * ...                  → {#E1}C1[b.C1$C[b, {#E2}Prop]] 
 * C1$C[#b, {#E2}#Prop] → {#E2}C2[C3[#b]];
 * </pre>
 * 
 * Where b occurs at the top-level, eliminating the need for meta-substitution. In addition, top-level binders don't have to be represented in the
 * final generated code.
 * 
 * <p>
 * Bound meta substitution (or curried function) should be treated with special care. A bound meta substitution is a contraction on the form: 
 * 
 * <pre>  b<sub>1</sub>....b<sub>n</sub>....{#E}#[a<sub>1</sub> ... a<sub>n</sub>]</pre>
 * 
 * where the arguments are not all trivial binder references to <code>b<sub>1..n</sub></code> (a deep occurrence occurs).
 * <p>
 * It is rewritten (uncurried) to a delayed unbound meta-substitution as follows:
 * 
 * <pre>  b<sub>1</sub>ᵇ....b<sub>n</sub>ᵇ.{#E}Delay<i>I</i>[a<sub>1</sub> ... a<sub>n</sub>, ba<sub>1</sub> ... ba<sub>n</sub>.#[ba<sub>1</sub> ... ba<sub>n</sub>]]</pre>
 * 
 * <p>
 * The above closure conversion can then be applied.
 *
 * <p>
 * The closure conversion also eliminate weak terms, when one or more of the non-occurring variable is functional. 
 * At runtime, all functional binders are bound, even the non-occurring ones.
 * 
 * <p>
 * The closure conversion guarantees the functional binders occur in the exact same order they have been declared, to allow, at runtime, faster positional binding.
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

		// First pass: eliminate deep function binders.
		Collection<GenericRule> pendingRules = ruleByName.values();
		List<GenericRule> updatedRules = new LinkedList<GenericRule>();
		state.counter = 1;

		while (!pendingRules.isEmpty())
		{
			if (crs.getVerbosity() > 0)
				System.out.println("Simplify " + pendingRules.size() + " rules");

			state.newrules = new LinkedList<GenericRule>();
			for (GenericRule rule : pendingRules)
			{
				// Some $ primitives are currently not properly sorted. Ignore rules containing those.
				//PrimitiveDetector detector = new PrimitiveDetector();
				//rule.getContractum().visit(detector, SimpleVariableSet.EMPTY);

				//if (!detector.hasPrimitive)
				{
					state.changed = false;
					state.rule = rule;

					GenericTerm newContractum = eliminateDeepBinders(
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

		// Second pass: eliminate currying 
		for (Entry<String, GenericRule> entry : ruleByName.entrySet())
		{
			GenericRule rule = entry.getValue();

			state.changed = false;
			state.rule = rule;
			GenericTerm newContractum = uncurry(state, null, (GenericTerm) rule.getContractum(), SimpleVariableSet.EMPTY);

			if (state.changed)
			{
				GenericRule newRule = new GenericRule(crs, rule.name, rule.pattern, newContractum, rule.options);
				entry.setValue(newRule);
			}

		}

		// TODO: should avoid this step by maintaining the sort structure is the new rules..
		crs.sortify();

	}

	//---------------- Eliminate deep functional binders

	/**
	 *  Simplify uses of deep binders in a term
	 * 
	 * @param state
	 * @param term
	 * @param bound variable, with sort.
	 * 
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateDeepBinders(Env1 state, GenericTerm term, ExtensibleSet<Pair<Variable, Term>> bound)
			throws CRSException
	{
		if (term instanceof PropertiesConstraintsWrapper)
		{
			// Recursively simplify properties.
			PropertiesConstraintsWrapper props = (PropertiesConstraintsWrapper) term;

			// TODO: simplify properties

			props.term = eliminateDeepBinders(state, props.term, bound);
			return props;
		}
		else
		{
			switch (term.kind())
			{
				case CONSTRUCTION :
					return eliminateDeepBinders(state, (GenericConstruction) term, bound);
				case META_APPLICATION :
					return eliminateDeepBinders(state, (GenericMetaApplication) term, bound);
				case VARIABLE_USE :
				default :
					return term;
			}
		}
	}

	/**
	 * Simplify uses of deep binders in a construction
	 * 
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm eliminateDeepBinders(Env1 state, GenericConstruction term, ExtensibleSet<Pair<Variable, Term>> bound)
			throws CRSException
	{
		String rulename = state.rule.name();
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			if (Util.isEval(term.constructor))
			{
				if (i > 0) // Ignore the first argument, always a constant
				{
					GenericTerm newsub = eliminateDeepBinders(state, term.sub(i), bound);
					term.replaceSub(i, null, newsub);
				}
			}
			else
			{
				GenericTerm sub = term.sub(i);
				Variable[] binders = term.binders(i);

				//Pair<Term, Term> sortDeclaration = getSortDeclaration(rulename, term.constructor.symbol());
				Pair<Term, Term> sortDeclaration = state.rule.getConstructorDeclaration(term);
				if (sortDeclaration == null)
				{
					sortDeclaration = getSortDeclaration(rulename, term.constructor.symbol());
				}
				Term[] binderSorts = getBindersSort(rulename, sortDeclaration.tail(), i);

				boolean recurse = true; // Should recursively eliminate deep binders?

				boolean hasFunctionalBinders = hasFunctionalBinders(binders);

				// If no functional binders, never rewrite.
				if (hasFunctionalBinders)
				{
					final boolean isSingleVariable = sub.variable() != null; // id function. 
					final boolean hasDeepBinders = state.rule.hasDeepBinderUses(term, i);
					final boolean hasWeakBinders = state.rule.hasWeakBinders(term, i);
					final boolean hasUnorderedBinders = state.rule.hasUnorderedShallowBinderUses(term, i);
					final boolean hasConstruction = state.rule.hasConstruction(term, i);

					if (isSingleVariable | hasDeepBinders | hasWeakBinders | hasUnorderedBinders | hasConstruction)
					{
						recurse = false; // No need to recurse as the sub is being rewritten.

						// Setup
						ExtensibleSet<Pair<Variable, Term>> subbound = extend(bound, binders, binderSorts);
						Env2 env = new Env2(state.rule, subbound, sub.arity());

						// Add the direct binders to the new contractum and pattern. This guarantee all binders
						// are used (eliminate weak binders) and in order.

						for (Variable var : binders)
						{
							GenericTerm metavar = factory.newMetaApplication(
									"#" + var.name() + env.patternArgs.size(), GenericTerm.NO_TERMS);

							// Add captured binder to pattern
							env.patternBinders.add(GenericTerm.NO_BIND);
							env.patternArgs.add(metavar);
							env.patternBindersSort.add(GenericTerm.NO_BIND);

							Term varSort = getBoundVariableSort(subbound, var);
							env.patternArgsSort.add(varSort);

							// And then to the new sub contractum
							env.argsBinders.add(GenericTerm.NO_BIND);
							env.args.add(factory.newVariableUse(var));

							// Register new metavariable
							env.metavars.put(var, metavar.metaVariable());
						}

						// Parse term and rewrite it. As a side effect, in Env, commute the new pattern arguments and sub-contractum.
						GenericTerm contractum = rewrite(env, term, i, sub, binders, subbound);

						// Replace sub with call to the new function.
						Constructor name = factory.makeConstructor(state.rule.name() + "$C$" + state.counter++);
						GenericTerm newsub = factory.newConstruction(
								name, env.argsBinders.toArray(GenericTerm.NO_BINDS), env.args.toArray(GenericTerm.NO_TERMS));
						term.replaceSub(i, binders, newsub);
						env.rule.reconcile();

						// Create new rule corresponding to the simplified function
						GenericTerm pattern = factory.newConstruction(
								name, env.patternBinders.toArray(GenericTerm.NO_BINDS),
								env.patternArgs.toArray(GenericTerm.NO_TERMS));

						// Gets construction sort. 
						Pair<Term, Term> subSortDeclaration = null;

						if (sub.kind() == Kind.CONSTRUCTION)
						{
							subSortDeclaration = getSortDeclaration(rulename, sub.constructor().symbol());
							if (subSortDeclaration == null)
								fatal(
										"Missing sort declaration for construction "
												+ sub.constructor().symbol() + " in rule " + rulename);
						}
						else
						{
							// Meta-application or variable use
							// For meta-application, there is currently no way to check if the environment is
							// require so always add it.
						}
						// Wrap both pattern and contractum with properties reference (if form has it)
						// but only if there are of the same sort.

						final boolean subHasProperties = sub.kind() == Kind.META_APPLICATION
								|| (subSortDeclaration != null
										&& (Util.hasProperties(subSortDeclaration.head())
												|| Util.hasProperties(subSortDeclaration.tail())));
						final boolean subHasRef = Util.hasPropertyRef(sub);
						if (!subHasRef && subHasProperties)
						{
							String metaref = "#E$C";
							pattern = pattern.wrapWithPropertiesRef(metaref, true);
							contractum = contractum.wrapWithPropertiesRef(metaref, true);
						}

						HashMap<String, List<Term>> options = new HashMap<String, List<Term>>(4);
						options.put(Builder.LAX_OPTION_SYMBOL, new LinkedList<Term>());

						GenericRule rule = new GenericRule(crs, name, pattern, contractum, options);

						// Set meta sorts to rule so that the sortifier does not have to run after each main iteration (see simplify)!
						Map<String, Term> metavarSorts = new HashMap<String, Term>(8); // Map meta variable name to sorts
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
							if (sub.kind() == Kind.META_APPLICATION)
							{
								// Hack: just add a top sortset
								form = form.wrapWithProperty("$String", factory.constant(factory.makeConstructor("$String")), true);
							}
							else
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

									assert!properties.propertyVariables().iterator().hasNext();
								}
							}

						}

						Term sortTerm;

						if (subSortDeclaration != null)
						{
							// Simplified rules don't have properties (they are on the form)
							sortTerm = subSortDeclaration.head();
						}
						else if (sub.metaVariable() != null)
						{
							// Get the sort of meta-application 
							sortTerm = rule.getMetaVariableSort(sub.metaVariable());
						}
						else
						{
							sortTerm = getBoundVariableSort(subbound, sub.variable());
						}

						if (Util.hasProperties(sortTerm))
							sortTerm = ((PropertiesConstraintsWrapper) sortTerm).term;

						if (sortTerm.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(sortTerm)))
							sortTerm = sortTerm.sub(0);

						factory.setSortForm(sortTerm, null, form, true, false);
					}
					else
					{
						if (hasDeepBinders)
						{
							if (factory.defined(Factory.SHOW_POTENTIAL_CLOSURE_OPTION))
								warning(
										"construction "
												+ Util.symbol(sub)
												+ " contains deep binder uses. Consider using the blocking marker ᵇ in rule "
												+ rulename);
						}

					}
				}

				if (recurse)
				{
					ExtensibleSet<Pair<Variable, Term>> subbound = extend(bound, binders, binderSorts);
					GenericTerm newsub = eliminateDeepBinders(state, term.sub(i), subbound);
					term.replaceSub(i, binders, newsub);
				}
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
	 * @throws CRSException 
	 */
	private GenericTerm eliminateDeepBinders(Env1 state, GenericMetaApplication term, ExtensibleSet<Pair<Variable, Term>> bound)
			throws CRSException
	{
		// Meta-applications don't hold binders. Just recursively eliminate deep binders...
		//		
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			GenericTerm newsub = eliminateDeepBinders(state, term.sub(i), bound);
			term.replaceSub(i, term.binders(i), newsub);
		}

		return term;
	}

	/**
	 * Rewrite term so that it contains no deep binders.
	 * 
	 * @param parent term's parent
	 * @param subindex 
	 * @param term sub term being rewritten.
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
			Map<String, Term> newMetas = new HashMap<String, Term>(4);
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

						GenericTerm matcher = factory.newMetaApplication(
								metaref + env.patternArgs.size(), GenericTerm.NO_TERMS).wrapWithPropertiesRef(metaref, false);

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
				GenericTerm newterm = rewrite(
						env, null, -1, (GenericTerm) properties.getProperty(name), GenericTerm.NO_BIND, bound);
				properties.setProperty(name, newterm);
			}

			List<Variable> oldVarProps = new LinkedList<Variable>();

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
				// Is it a bound variable?
				final boolean isBound = contains(bound, var);

				if (!isBound || contains(env.preBinders, var))
				{
					// This is either a binder occurring before the term being rewritten (already captured)
					// or it's a free/fresh variable (that might need to be captured)
					String meta = env.metavars.get(var);
					if (meta == null)
					{
						// This is a free/fresh variable that hasn't been captured yet. 

						GenericTerm metavar = factory.newMetaApplication(
								"#" + term.variable().name() + env.patternArgs.size(), GenericTerm.NO_TERMS);
						env.metavars.put(var, metavar.metaVariable());

						env.patternBinders.add(GenericTerm.NO_BIND);
						env.patternArgs.add(metavar);

						env.patternBindersSort.add(GenericTerm.NO_BIND);

						Term varSort = getVariableSort(var, bound, env.rule);
						env.patternArgsSort.add(varSort);

						env.argsBinders.add(GenericTerm.NO_BIND);
						env.args.add(factory.newVariableUse(var));

						return metavar;
					}
					return factory.newMetaApplication(meta, GenericTerm.NO_TERMS);
				}
				else
				{
					// This is a bound variable after the closure. Just use it

					return factory.newVariableUse(var);
				}
			}
			case CONSTRUCTION : {
				if (term.arity() == 0)
					return term;

				final boolean toplevel = env.toplevel;
				env.toplevel = false;
				for (int i = 0; i < term.arity(); i++)
				{
					ExtensibleSet<Pair<Variable, Term>> subbound = bound;
					if (term.binders(i).length > 0)
						subbound = extend(bound, term.binders(i), getBindersSort(env.rule.name(), term.constructor().symbol(), i));

					GenericTerm sub = rewrite(env, term, i, term.sub(i), term.binders(i), subbound);
					term.replaceSub(i, term.binders(i), sub);
				}
				env.toplevel = toplevel;
				return term;
			}
			case META_APPLICATION :
			default :
				// Capture (if not already captured!).
				String meta = env.metavars.get(term.metaVariable());
				if (meta == null)
				{
					// Capture metavar (which is potentially an abstraction)
					GenericTerm metaSort = (GenericTerm) env.rule.getMetaVariableSort(term.metaVariable());
					if (metaSort == null)
						fatal("Missing sort for meta variable " + term.metaVariable() + " in rule " + env.rule.name());

					Variable[] patternBinders;
					GenericTerm[] patternSubs;
					Variable[] patternBindersSort;

					// Only the meta on pattern contains the full list arguments.  
					GenericTerm original = env.rule.getMetaOnPattern(term.metaVariable());
					final int arity = original.arity();
					if (arity > 0)
					{
						patternBinders = new Variable[arity];
						patternSubs = new GenericTerm[arity];
						patternBindersSort = new Variable[arity];

						metaSort = factory.newForm(Sorting.SORT_VAR, new GenericTerm[]
							{metaSort});
						if (!(metaSort instanceof PropertiesConstraintsWrapper))
							metaSort = new PropertiesConstraintsWrapper(metaSort, null, null, null, null);

						for (int i = 0; i < arity; i++)
						{
							Variable var = original.sub(i).variable();
							Variable newvar = factory.makeVariable(var.name(), var.promiscuous(), var.blocking(), var.shallow());

							patternBinders[i] = newvar;
							patternSubs[i] = factory.newVariableUse(newvar);

							Term varSort = env.rule.getVariableSort(var);
							if (varSort == null)
								fatal("Missing sort for variable " + var + " in rule " + env.rule.name());

							Variable binderOnSort = factory.makeVariable(
									var.name(), var.promiscuous(), var.blocking(), var.shallow());

							patternBindersSort[i] = binderOnSort;

							metaSort = metaSort.wrapWithProperty(binderOnSort, varSort, false); // binderOnSort.{binderOnSort:varSort}.MetaSort
						}
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
					final boolean toplevel = env.toplevel;
					env.toplevel = false;

					metasubs = new GenericTerm[term.arity()];
					for (int i = 0; i < term.arity(); i++)
						metasubs[i] = rewrite(env, term, i, term.sub(i), GenericTerm.NO_BIND, bound);

					env.toplevel = toplevel;
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
			if (pair.head() == var)
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
	private Term getBoundVariableSort(ExtensibleSet<Pair<Variable, Term>> set, Variable var)
	{
		for (Pair<Variable, Term> pair : set)
		{
			if (pair.head().equals(var))
				return pair.tail();
		}
		return null;
	}

	/**
	 * Gets variable sort. Variable can either be free, bound or fresh.
	 * @throws CRSException 
	 */
	private Term getVariableSort(Variable var, ExtensibleSet<Pair<Variable, Term>> bound, GenericRule rule) throws CRSException
	{
		Term varSort = getBoundVariableSort(bound, var);
		if (varSort == null)
		{
			// This is either a free or fresh variable. Sort is stored in the rule Option
			if (rule.options.containsKey(Builder.FRESH_OPTION_SYMBOL))
			{
				for (Term z : rule.options.get(Builder.FRESH_OPTION_SYMBOL))
				{
					Variable v = Util.variableWithOptionalSortVariable(z);
					if (v == var)
					{
						varSort = Util.variableWithOptionalSortSort(z);
						break;
					}
				}
			}

			if (varSort == null)
			{
				// Free variable.
				varSort = rule.getVariableSort(var);
				if (varSort == null)
					fatal("Missing sort for free variable " + var.name() + " in rule " + rule.name());
			}
		}

		if (varSort.kind() != Kind.VARIABLE_USE && Util.isVariableWithOptionalSort(varSort))
			varSort = Util.variableWithOptionalSortSort(varSort);

		return varSort;
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
		{
			// Crsx is still very lax on property set sort. Just Create a generic one.
			propertiesSort = new HashMap<>(1);
			propertiesSort.put("$String", factory.constant(factory.makeConstructor("$String")));
			//fatal("Missing properties sort for term " + properties + " in rule " + rule.name());
		}
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

	private boolean hasFunctionalBinders(Variable[] binders)
	{
		if (binders == null)
			return false;
		for (int j = 0; j < binders.length; j++)
		{
			if (binders[j].blocking())
				return true;
		}
		return false;
	}

	//---------------- Uncurrying

	/**
	 * Uncurry a term
	 * 
	 * @param state
	 * @param term
	 * @param bound
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm uncurry(Env1 state, Variable[] binders, GenericTerm term, ExtensibleSet<Variable> bound) throws CRSException
	{
		if (term instanceof PropertiesConstraintsWrapper)
		{
			// Recursively simplify properties.
			PropertiesConstraintsWrapper props = (PropertiesConstraintsWrapper) term;

			// TODO: uncurry term in properties

			props.term = uncurry(state, null, props.term, bound);
			return props;
		}
		else
		{
			switch (term.kind())
			{
				case CONSTRUCTION :
					return uncurry(state, binders, (GenericConstruction) term, bound);
				case META_APPLICATION :
					return uncurry(state, binders, (GenericMetaApplication) term, bound);
				case VARIABLE_USE :
				default :
					return term;
			}
		}
	}

	/**
	 * Uncurry a construction
	 * 
	 * @param state
	 * @param term
	 * @param bound
	 * @param functional  
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm uncurry(Env1 state, Variable[] binders, GenericConstruction term, ExtensibleSet<Variable> bound)
			throws CRSException
	{
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			Variable[] subbinders = term.binders(i);

			ExtensibleSet<Variable> subbound = bound.extend(subbinders);
			GenericTerm newsub = uncurry(state, subbinders, term.sub(i), subbound);
			term.replaceSub(i, subbinders, newsub);
		}
		return term;
	}

	/**
	 * Uncurry a meta-application
	 *
	 * @param state
	 * @param term
	 * @param bound
	 * @param functional  
	 * @return
	 * @throws CRSException 
	 */
	private GenericTerm uncurry(Env1 state, Variable[] binders, GenericMetaApplication term, ExtensibleSet<Variable> bound)
			throws CRSException
	{
		// Recursively uncurry arguments
		for (int i = term.arity() - 1; i >= 0; i--)
		{
			GenericTerm newsub = uncurry(state, null, term.sub(i), bound);
			term.replaceSub(i, null, newsub);
		}

		int bindercount = binders == null ? 0 : binders.length;

		if (bindercount != term.arity() && hasFunctionalBinders(binders))
		{
			// This is a currying function. Rewrite using Delay function!
			Constructor delay = factory.makeConstructor("Delay" + term.arity());

			Variable[][] allbinders = new Variable[term.arity() + 1][];
			GenericTerm[] subs = new GenericTerm[term.arity() + 1];

			// In order to preserve variable name and binder, gets the metavar on the pattern
			GenericTerm metaOnPattern = state.rule.getMetaOnPattern(term.metaVariable);

			// Make binders.
			Variable[] newbinders = new Variable[term.arity()];
			GenericTerm[] args = new GenericTerm[term.arity()];
			for (int i = term.arity() - 1; i >= 0; i--)
			{
				Variable original = metaOnPattern.sub(i).variable();
				newbinders[i] = factory.makeVariable(
						original.name(), original.promiscuous(), original.blocking(), original.shallow());
				args[i] = factory.newVariableUse(newbinders[i]);

				allbinders[i] = GenericTerm.NO_BIND;
			}
			allbinders[term.arity()] = newbinders;

			// Make subs
			System.arraycopy(term.allSubs(), 0, subs, 0, term.allSubs().length);
			subs[term.arity()] = factory.newMetaApplication(term.metaVariable, args);

			// Finally make generic closure using Delay.
			state.changed = true;
			return factory.newConstruction(delay, allbinders, subs);
		}

		return term;

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

		final Set<Pair<Variable, Term>> preBinders; // Binders occurring before the rewrite

		final List<Variable[]> patternBinders; // New closure argument binders.
		final List<GenericTerm> patternArgs;// New closure pattern arguments. All metas.
		final List<Variable[]> patternBindersSort;
		final List<Term> patternArgsSort;// New closure pattern arguments sorts.

		final List<Variable[]> argsBinders; // Closure call binders ($Cx)
		final List<GenericTerm> args;// Closure call arguments ($Cx)

		final Map<Object, String> metavars; // Map capture variable/metavars to new metavar name in closure
		final Map<Map<String, Term>, String> propHolder;

		boolean toplevel; // The current term is the one being rewritten.

		public Env2(GenericRule rule, Set<Pair<Variable, Term>> preBinders, int arity)
		{
			this.rule = rule;
			this.preBinders = preBinders;

			patternBinders = new ArrayList<Variable[]>();
			patternArgs = new ArrayList<GenericTerm>();
			patternBindersSort = new ArrayList<Variable[]>();
			patternArgsSort = new ArrayList<Term>();

			argsBinders = new ArrayList<Variable[]>();
			args = new ArrayList<GenericTerm>();

			metavars = new HashMap<Object, String>();
			propHolder = new HashMap<Map<String, Term>, String>();
			toplevel = true;
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
