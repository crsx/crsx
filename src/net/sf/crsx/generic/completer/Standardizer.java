/* Copyright © 2011, 2012 IBM Corporation. */

package net.sf.crsx.generic.completer;

import static net.sf.crsx.generic.Completer.REFERENCE;
import static net.sf.crsx.generic.Completer.STANDARDIZED;
import static net.sf.crsx.generic.Completer.printDeclarationModuloVariables;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Kind;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.analysis.Unifier;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericRule;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.generic.PropertiesConstraintsWrapper;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.Util;

/**
 * Standardizes rule.
 * 
 * @author villardl
 */
final public class Standardizer
{
	// State

	/** Term factory */
	final private GenericFactory factory;

	/** Environment */
	final private Environment env;

	// Constructor

	public Standardizer(Environment env)
	{
		this.env = env;
		this.factory = env.factory;
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
	public StandardizedRule standardizeRule(GenericRule rule, Map<Object, Term> sorts, Map<String, Term> keysorts)
	        throws CRSException
	{
//		if (rule.name().contains("EB-Code-ForDo-Emit-Tuple-2"))
//			factory.warning("karma");
		
		// STEP 1: figure out the positions where all free variables and
		// meta-variables occur (this is tricky because they might occur
		// only inside property sets)
		Map<String, String> metaVariablePositions = new HashMap<String, String>();
		Map<Variable, String> variablePositions = new HashMap<Variable, String>();
		getUnknownPositions(rule.getPattern(), metaVariablePositions, variablePositions, rule.name(), true);
		getUnknownPositions(rule.getContractum(), metaVariablePositions, variablePositions, rule.name(), false);

		// STEP 2: find out which meta-variables are used inconsistently
		Set<String> explicitMeta = new HashSet<String>();
		getExplicitMetaVariables(rule.getPattern(), explicitMeta);
		getExplicitMetaVariables(rule.getContractum(), explicitMeta);

		// STEP 3: get the standardized terms out!
		GenericTerm l, r;
		Map<String, Term[]> setMetaVariableArgs = new HashMap<String, Term[]>();
		Map<Variable, Variable> varSubstitution = new HashMap<Variable, Variable>();
		List<Variable> bound = new LinkedList<Variable>();
		l = standardize(
		        rule.getPattern(), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution, "",
		        explicitMeta, bound, rule, sorts, keysorts, true, false);
		r = standardize(
		        rule.getContractum(), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution, "",
		        explicitMeta, bound, rule, sorts, keysorts, false, false);

		// STEP 4: translate the options...
		Map<String, List<Term>> options = new HashMap<String, List<Term>>();
		for (Map.Entry<String, List<Term>> e : rule.getOptions().entrySet())
		{
			List<Term> os = new ArrayList<Term>();
			for (Term oldo : e.getValue())
			{
				GenericTerm o = standardize(
				        oldo, metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution, "", explicitMeta,
				        bound, rule, sorts, keysorts, false, false);
				if (o.kind() != Kind.META_APPLICATION || o.metaVariable() != null)
					os.add(o);
			}
			options.put(e.getKey(), os);
		}
		return new StandardizedRule(factory, l, r, rule.getName(), options);
	}

	/**
	 * Given a normal user-defined term, bring it in the form we can easily
	 * work with, following naming conventions, special use of property sets
	 * and making property set use explicit where it should be.
	 * @param term the term to standardize
	 * @param metaVariablePositions maps every meta-variable to the position
	 *   in the term where it occurs, and reference meta-variables to their
	 *   position preceded with Γ
	 * @param variablePositions maps all bound variables to their position,
	 *   preceded by x for bound variables, y for free variables occurring
	 *   only in the right-hand of a rule, and z for free variables occurring
	 *   in the left-hand side of a rule; this method updates variablePositions
	 *   to also contain entries for variables used as arguments to reference
	 *   meta-variables (fresh in the right-hand side), which will start with
	 *   an r
	 * @param setMetaVariableArgs the sorts of (bound) variables used as
	 *   arguments to reference meta variables
	 * @param varSubstitution maps variables in the original term to variables
	 *   in the new term; this is updated by this function to contain new
	 *   substitutions
	 * @param contextPos the current position in a bigger term
	 * @param explicitMeta those meta-variables which should have explicit
	 *   meta-variables (it may currently be the case, however, that they do
	 *   not)
	 * @param bound contains those variables which have been bound by a
	 *   bigger term which the current term is a subterm of (the translation
	 *   of those occurring in the original term)
	 * @param rule gives sorts for (all subterms of) the given term
	 * @param sorts should be updated to contain all the sorts for (subterms
	 *   of) the result term
	 * @param keysorts an initially empty mapping, used to save the sorts for
	 *   keys in meta-property sets (which are not subterms, so not covered by
	 *   sorts)
	 * @param left whether this term is part of the left-hand side of a rule
	 *   (if not, it is part of the right-hand side)
	 * @param belowSemantic set to true if, in the larger term, this term is
	 *   used below a semantic binder
	 */
	public GenericTerm standardize(Term term, Map<String, String> metaVariablePositions, Map<Variable, String> variablePositions, Map<String, Term[]> setMetaVariableArgs, Map<Variable, Variable> varSubstitution,
			String contextPos, Set<String> explicitMeta, List<Variable> bound, GenericRule rule, Map<Object, Term> sorts, Map<String, Term> keysorts, boolean left, boolean belowSemantic)
	        throws CRSException
	{
		if (term == null)
			return null;
		if (Util.hasProperty(term, STANDARDIZED))
			return (GenericTerm) term;

		GenericTerm ret = null;
		Map<String, Term> namedProperties = new HashMap<String, Term>();
		switch (term.kind())
		{
			case VARIABLE_USE : {
				Variable x = term.variable();
				if (!varSubstitution.containsKey(x))
					varSubstitution.put(x, env.makeVariable(variablePositions.get(x), x.promiscuous()));
				Variable y = varSubstitution.get(x);
				ret = factory.newVariableUse(y);
				if (sorts.containsKey(y))
					sorts.put(ret, sorts.get(y)); // bound variables have already been saved in sorts
				else
					sorts.put(ret, rule.getVariableSort(x));
				break;
			}

			case META_APPLICATION : {
				GenericTerm[] args = new GenericTerm[term.arity()];
				for (int i = 0; i < args.length; i++)
					args[i] = standardize(
					        term.sub(i), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution, contextPos
					                + subPosition(i, args.length), explicitMeta, bound, rule, sorts, keysorts, left, belowSemantic);
				if (!metaVariablePositions.containsKey(term.metaVariable()))
					//factory.env.error("Unbound meta-application "+term+" used in rule "+rule.name());
					metaVariablePositions.put(term.metaVariable(), "un" + metaVariablePositions.size());
				ret = factory.newMetaApplication("#" + metaVariablePositions.get(term.metaVariable()), args);
				break;
			}

			case CONSTRUCTION :  
				if (CRS.EVAL_SYMBOL.equals(Util.symbol(term)) && term.arity() > 0)
				{
					GenericTerm[] args = new GenericTerm[term.arity()];
					String symbol = Util.symbol(term.sub(0));
					args[0] = factory.constant(factory.makeLiteral(symbol, CRS.STRING_SORT));
					//if (symbol.equals("Get") || symbol.equals("IfDef"))
					{
						//if (left)
						//{
						//	fatal("$["+symbol+",...] occurs in the left-hand side of rule " + rule.name() + ", not supported!");
						//	return null;
						//}
						if (term.sub(0).arity() > 0)
						{
							args[0] = standardize(
									term.sub(0), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution,
									symbol.equals(Primitive.NOT_MATCH.symbol) ? contextPos : contextPos + subPosition(0, args.length), explicitMeta, bound, rule,
											sorts, keysorts, left, belowSemantic);
						}
						if (term.sub(0) instanceof PropertiesConstraintsWrapper)
						{
							Map<String, Term> subPropertyNames = new HashMap<String, Term>();
							String ref = ((PropertiesConstraintsWrapper) term.sub(0)).getRef();
							subPropertyNames.put(
									REFERENCE,
									getReference(
											"#" + metaVariablePositions.get(ref), contextPos + "0", null, setMetaVariableArgs.get(ref),
											sorts, rule.name()));
							args[0] = Util.makePropertiesConstraintsWrapper(args[0], null, subPropertyNames, null, null);
						}
					}
					for (int i = 1; i < term.arity(); i++)
					{
						args[i] = standardize(
						        term.sub(i), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution,
						        symbol.equals(Primitive.NOT_MATCH.symbol) ? contextPos : contextPos + subPosition(i, args.length), explicitMeta, bound, rule,
						        sorts, keysorts, left, belowSemantic);
					}
					ret = factory.newConstruction(factory.makeConstructor(CRS.EVAL_SYMBOL), null, args);
				}

				else if (term.constructor().literalSort() != null)
				{
					ret = factory.newConstruction(term.constructor(), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
				}

				else if (Util.isVariableWithOptionalSort(term)) // v::Sort declaration
				{
					Variable x = Util.variableWithOptionalSortVariable(term);
					if (!varSubstitution.containsKey(x))
						varSubstitution.put(x, env.makeVariable(variablePositions.get(x), x.promiscuous()));
					Variable y = varSubstitution.get(x);
					GenericTerm sort = (GenericTerm) Util.variableWithOptionalSortSort(term);
					//ret = Util.makeVariableWithSort(factory, Util.variableWithOptionalSortVariable(term), standardize(Util.variableWithOptionalSortSort(term), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution, pos, explicitMeta, bound, rule, sorts, keysorts, left, belowSemantic));
					ret = Util.makeVariableWithSort(factory, y, sort);
				}

				else
				// non-$ non-literal
				{
					Constructor constructor = term.constructor();
					String symbol = constructor.symbol();
					GenericTerm[] args = new GenericTerm[term.arity()];
					Variable[][] binds = new Variable[term.arity()][];
					Pair<Term,Term> pair = rule.getConstructorDeclaration(term);
					Term form = (pair == null ? null : rule.getConstructorDeclaration(term).tail());
					if (form == null)
					{
						// KRIS Oops: Form is missing: extract from constructor if declared.
						Set<Pair<Term,Term>> forms = factory.formsOf(Util.symbol(term));
						if (forms.size() >= 1)
							form = forms.iterator().next().tail();
					}
					for (int i = 0; i < args.length; i++)
					{
						binds[i] = new Variable[term.binders(i).length];
						PropertiesHolder subHolder = form == null ? null : Util.propertiesHolder(form.sub(i));
						boolean semanticBinder = false;
						for (int j = 0; j < term.binders(i).length; j++)
						{
							Variable b = term.binders(i)[j];
							binds[i][j] = env.makeVariable(variablePositions.get(b), b.promiscuous());
							varSubstitution.put(term.binders(i)[j], binds[i][j]);
							bound.add(binds[i][j]);
							if (subHolder != null)
							{
								Term binderSort = subHolder.getProperty(form.binders(i)[j]);
								if (binderSort.kind() != Kind.CONSTRUCTION || !factory.sortAllowsVariables(Util.symbol(binderSort)))
									semanticBinder = true;
								sorts.put(binds[i][j], binderSort);
							}
						}
						// postulate sort for subterm 
						if (form != null)
							sorts.put(term.sub(i), form.sub(i)); // TODO: check if this is needed?
						args[i] = standardize(
						        term.sub(i), metaVariablePositions, variablePositions, setMetaVariableArgs, varSubstitution, contextPos
						                + subPosition(i, args.length), explicitMeta, bound, rule, sorts, keysorts, left,
						        belowSemantic || semanticBinder);

						if (form != null)
							sorts.put(args[i], form.sub(i)); // record sort of standardized form
						for (int j = 0; j < term.binders(i).length; j++)
						{
							varSubstitution.remove(term.binders(i)[j]);
							bound.remove(bound.size() - 1);
						}
					}

					if (!symbol.equals(CRS.EVAL_SYMBOL)
							&& rule.getSubSort(term) != null
					        && !(rule.getSubSort(term).kind() == Kind.CONSTRUCTION && rule.getSubSort(term).constructor().symbol().equals(CRS.STRING_SORT))
					        && factory.formsOf(symbol).size() != 1)
					{
						Pair<Term, Term> dec = rule.getConstructorDeclaration(term);
						String declaration = printDeclarationModuloVariables(dec.head(), dec.tail());
						symbol = env.overloadedSymbolsByForm.get(declaration);
						if (symbol == null)
							break;
					}
					ret = factory.newConstruction(factory.makeConstructor(symbol), binds, args);
				}
				break;
		}

		Term termsort = rule.getSubSort(term);
		if (termsort == null)
		{
			termsort = sorts.get(term);
		}
		if (hasPropertySet(term)
		        || (term.kind() == Kind.META_APPLICATION && explicitMeta.contains(term.metaVariable()))
		        || (term.kind() == Kind.CONSTRUCTION
		                && ((term == null
		                			&& CRS.EVAL_SYMBOL != null)
		                	  || !CRS.EVAL_SYMBOL.equals(Util.symbol(term)))
		                && termsort != null && termsort.kind() != Kind.VARIABLE_USE
		                && factory != null && factory.sortsetFor(Util.symbol(termsort)) != null))
		{
			PropertiesHolder ph = Util.propertiesHolder(term);
			Term reference = null;
			if (left)
			{
				Term[] argsorts = new Term[bound.size()];
				int k = 0;
				for (Variable v : bound)
					argsorts[k++] = sorts.get(v);
				if (ph != null
				        && ph instanceof PropertiesConstraintsWrapper && ((PropertiesConstraintsWrapper) ph).getRef() != null)
				{
					reference = getReference("#Γ" + contextPos, contextPos, bound, argsorts, sorts, rule.name());
					String oldref = ((PropertiesConstraintsWrapper) ph).getRef();
					metaVariablePositions.put(oldref, "Γ" + contextPos);
					setMetaVariableArgs.put(oldref, belowSemantic ? null : argsorts);
				}
			}
			else
			{
				if (ph != null && ph instanceof PropertiesConstraintsWrapper && ((PropertiesConstraintsWrapper) ph).getRef() != null)
				{
					String oldref = ((PropertiesConstraintsWrapper) ph).getRef();
					reference = getReference("#" + metaVariablePositions.get(oldref), contextPos, null, setMetaVariableArgs.get(oldref), sorts, rule.name());
				}
			}

			if (reference != null)
				namedProperties.put(REFERENCE, reference);

			if (ph != null)
				for (String key : ph.propertyNames())
				{
					Set<Pair<Term, Term>> forms = factory.formsOf(key);
					if (forms != null && forms.size() == 1)
					{
						for (Pair<Term, Term> pair : forms)
							if (pair.tail().arity() == 0)
								keysorts.put("%" + key, pair.head());
					}
					namedProperties.put(
					        "%" + key,
					        standardize(
					                ph.getProperty(key), metaVariablePositions, variablePositions, setMetaVariableArgs,
					                varSubstitution, contextPos + subPositionKey(key, false, metaVariablePositions, variablePositions),
					                explicitMeta, bound, rule, sorts, keysorts, left, belowSemantic));
				}

			if (ph != null)
				for (Variable key : ph.propertyVariables())
				{
					if (varSubstitution.containsKey(key) && sorts.containsKey(varSubstitution.get(key)))
						keysorts.put(variablePositions.get(key), sorts.get(varSubstitution.get(key)));
					else
						keysorts.put(variablePositions.get(key), rule.getVariableSort(key));

					namedProperties.put(
					        variablePositions.get(key),
					        standardize(
					                ph.getProperty(key), metaVariablePositions, variablePositions, setMetaVariableArgs,
					                varSubstitution, contextPos + subPositionKey(key, false, metaVariablePositions, variablePositions),
					                explicitMeta, bound, rule, sorts, keysorts, left, belowSemantic));
				}

			if (ph != null && ph instanceof PropertiesConstraintsWrapper)
			{
				PropertiesConstraintsWrapper B = (PropertiesConstraintsWrapper) ph;
				for (String key : B.propertyMetaVariables())
				{
					keysorts.put("#" + metaVariablePositions.get(key), rule.getMetaVariableSort(key));
					namedProperties.put(
					        "#" + metaVariablePositions.get(key),
					        standardize(
					                B.getMetaProperty(key), metaVariablePositions, variablePositions, setMetaVariableArgs,
					                varSubstitution, contextPos + subPositionKey(key, true, metaVariablePositions, variablePositions),
					                explicitMeta, bound, rule, sorts, keysorts, left, belowSemantic));
				}
			}
		}

		namedProperties.put(STANDARDIZED, factory.nil());
		ret = Util.makePropertiesConstraintsWrapper(ret, null, namedProperties, null, null);
		sorts.put(ret, rule.getSubSort(term));

		return ret;
	}

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
	public GenericTerm generalStandardizedPattern(Term form, Term sort, String constructor, String pos, List<Variable> bound, Map<Object, Term> sorts, boolean omitPropertySet)
	        throws CRSException
	{
		Constructor F = factory.makeConstructor(constructor);
		Variable[][] binders = new Variable[form.arity()][];
		GenericTerm[] args = new GenericTerm[form.arity()];

		for (int i = 0; i < form.arity(); i++)
		{
			Variable[] formBinders = form.binders(i);
			binders[i] = new Variable[formBinders.length];
			for (int j = 0; j < binders[i].length; j++)
				binders[i][j] = env.makeVariable("x" + pos + subVariablePosition(i, form.arity(), j, binders[i].length), formBinders[j].promiscuous());

			// determine the arguments for the meta-variable application
			GenericTerm[] mvarargs = new GenericTerm[binders[i].length + bound.size()];
			int k = 0;
			for (Variable v : bound)
			{
				mvarargs[k] = factory.newVariableUse(v);
				sortPut(sorts, mvarargs[k], sortGet(sorts, v));
				k++;
			}
			for (int j = 0; j < binders[i].length; j++)
			{
				mvarargs[k] = factory.newVariableUse(binders[i][j]);
				Term bsort = Util.propertiesHolder(form.sub(i)).getProperty(form.binders(i)[j]);
				sortPut(sorts, mvarargs[k], bsort);
				sortPut(sorts, binders[i][j], bsort);
				k++;
			}

			// determine the subterm itself, and save its sort
			String posname = pos + subPosition(i, form.arity());
			args[i] = standardPatternMetaApplication("#" + posname, mvarargs);
			if (binders[i].length == 0)
				sortPut(sorts, args[i], form.sub(i));
			else
				sortPut(sorts, args[i], Unifier.apply(form.sub(i), new HashMap<Variable, Term>(), factory));
		}

		// we know all subterms and binders; finish off by creating the term
		GenericTerm ret = factory.newConstruction(F, binders, args);

		// Add dummy property to mark as standardized.
		Map<String, Term> propNames = new HashMap<String, Term>();
		propNames.put(STANDARDIZED, factory.nil());

		// Add a $$REFERENCE-style properties reference if the form permits properties.
		if (!omitPropertySet
		        && ((sort.kind() != Kind.VARIABLE_USE && sort.arity() == 0 && factory.sortsetFor(Util.symbol(sort)) != null) || Util.hasNonVariableProperties(form)))
		{
			GenericTerm[] mvarargs = new GenericTerm[bound.size()];
			int k = 0;
			for (Variable v : bound)
			{
				mvarargs[k] = factory.newVariableUse(v);
				sortPut(sorts, mvarargs[k], sorts.get(v));
				k++;
			}
			propNames.put(REFERENCE, standardPatternMetaApplication("#Γ" + pos, mvarargs));
			// we don't save sorts for the reference, as a reference meta-variable is unsorted
		}
		ret = Util.makePropertiesConstraintsWrapper(ret, null, propNames, null, null);

		// Update sort mapping for main term...
		sortPut(sorts, ret, sort);

		return ret;
	}

	/** Create pattern meta-application in "standardized" form. */
	public PropertiesConstraintsWrapper standardPatternMetaApplication(String metaVariable, GenericTerm[] mvarargs)
	{
		GenericTerm ret = factory.newMetaApplication(metaVariable, mvarargs);
		Map<String, Term> propNames = new HashMap<String, Term>();
		propNames.put(STANDARDIZED, factory.nil());
		return Util.makePropertiesConstraintsWrapper(ret, null, propNames, null, null);
	}

	/** Create constant in "standardized" form. */
	public PropertiesConstraintsWrapper standardConstant(String symbol)
	{
		GenericTerm ret = factory.newConstruction(factory.makeConstructor(symbol), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
		Map<String, Term> propNames = new HashMap<String, Term>();
		propNames.put(STANDARDIZED, factory.nil());
		return Util.makePropertiesConstraintsWrapper(ret, null, propNames, null, null);
	}

	/** Return copy of term where standardization has been reversed. */
	public GenericTerm unstandardize(GenericTerm term)
	{
		if (!Util.hasProperty(term, STANDARDIZED))
			return term;
		// Compute base variable naming used.
		ExtensibleMap<String, Variable> vars = new LinkedExtensibleMap<String, Variable>();
		final Set<Variable> fv = new HashSet<Variable>();
		term.addFree(fv, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, null);
		for (Variable v : fv)
			vars = vars.extend(v.name(), v);
		// Unstandardize.
		return unstandardize(term, vars, LinkedExtensibleMap.EMPTY_RENAMING);
	}

	/**
	 * Return copy of term where standardization has been reversed.
	 * @param standardizedTerm
	 * @param vars
	 */
	public GenericTerm unstandardize(GenericTerm standardizedTerm, ExtensibleMap<String, Variable> vars, ExtensibleMap<Variable, Variable> renamings)
	{
		// Extract actual properties from term.
		boolean hasProperties = false;
		boolean needsConstraintsWrapper = false;
		String nuRef = null;
		Map<String, Term> nuNamedProperties = new HashMap<String, Term>();
		Map<Variable, Term> nuVariableProperties = new IdentityHashMap<Variable, Term>();
		Map<String, Term> nuMetaProperties = new HashMap<String, Term>();

		// Unstandardize properties.
		PropertiesHolder ph = Util.propertiesHolder(standardizedTerm);
		if (ph != null)
		{
			// - named properties encode lots of stuff.
			for (String key : ph.propertyNames())
			{
				GenericTerm value = (GenericTerm) ph.getProperty(key);
				if (key.equals(STANDARDIZED))
				{
					// ignore
				}
				else if (key.equals(REFERENCE))
				{
					// $$REFERENCE key means the value is an encoded property reference meta-variable.
					hasProperties = needsConstraintsWrapper = true;
					nuRef = Util.symbol(value);
				}
				else if (vars.containsKey(key))
				{
					hasProperties = true;
					Variable v = vars.get(key); // the key is the name of variable from the context
					if (value == null)
						needsConstraintsWrapper = true;
					else
						value = unstandardize(value, vars, renamings);
					Variable v2 = renamings.get(v);
					nuVariableProperties.put((v2 == null ? v : v2), value);
				}
				else if (key.startsWith("%"))
				{
					hasProperties = true;
					if (value == null)
						needsConstraintsWrapper = true;
					else
						value = unstandardize(value, vars, renamings);
					nuNamedProperties.put(key.substring(1), value);
				}
				else if (key.startsWith("#"))
				{
					hasProperties = needsConstraintsWrapper = true;
					if (value != null)
						value = unstandardize(value, vars, renamings);
					nuMetaProperties.put(key, value);
					hasProperties = true;
				}
				else 
				{
					// Is this a bound variable?
					boolean bound = false;
					for (Entry<Variable, Variable> e : renamings.entrySet())
                    {
	                    if (e.getKey().name().equals(key))
	                    {
	                    	bound = true;
	                    	hasProperties = needsConstraintsWrapper = true;
	                    	if (value != null)
	    						value = unstandardize(value, vars, renamings);
	                    	nuVariableProperties.put(e.getValue(), value);
	                    	break;
	                    }
                    } 
					
					if (!bound)
					{

						if (value == null)
							needsConstraintsWrapper = true;
						else
							value = unstandardize(value, vars, renamings);
						nuNamedProperties.put(key, value);
						hasProperties = true;
					}
				}
			}
			// - variable properties are just copied over (for idempotency)
			for (Variable key : ph.propertyVariables())
			{
				GenericTerm value = (GenericTerm) ph.getProperty(key);
				if (value == null)
					needsConstraintsWrapper = true;
				else
					value = unstandardize(value, vars, renamings);
				Variable v2 = renamings.get(key);
				nuVariableProperties.put((v2 == null ? key : v2), value);
				hasProperties = true;
			}
			// - existing property reference and meta-properties are also just copied over (for idempotency)
			if (ph.isMeta())
			{
				PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
				String realRef = pcw.getRef();
				if (realRef != null && nuRef != null)
					if (factory.verbosity() >= 4)
						factory.message(("Standardized term has both encoded and raw reference (" + standardizedTerm + ")"));
				for (String key : pcw.propertyMetaVariables())
				{
					GenericTerm value = (GenericTerm) pcw.getMetaProperty(key);
					if (value != null)
						value = unstandardize(value, vars, renamings);
					nuMetaProperties.put(key, value);
				}
				if (nuRef != null || !nuMetaProperties.isEmpty())
					hasProperties = needsConstraintsWrapper = true;
			}
		}

		// Construct new binders and subterms.
		if (standardizedTerm == null)
			env.warning("bad karm: null standard term");
		
		final int arity = standardizedTerm.arity();
		Variable[][] nuBinders = new Variable[arity][];
		GenericTerm[] nuSub = new GenericTerm[arity];
		for (int i = 0; i < arity; ++i)
		{
			Variable[] bs = standardizedTerm.binders(i);
			GenericTerm sub = (GenericTerm) standardizedTerm.sub(i);
			ExtensibleMap<Variable, Variable> subrenamings = renamings;
			nuBinders[i] = new Variable[bs.length];
			for (int j = 0; j < bs.length; ++j)
			{
				Variable b = bs[j];
				Variable nub = factory.makeVariable(b.name(), b.promiscuous());
				subrenamings = subrenamings.extend(b, nub);
				nuBinders[i][j] = nub;
			}
			nuSub[i] = unstandardize(sub, vars, subrenamings);
		}

		// Construct new term with new properties.
		GenericTerm nuTerm = null;
		switch (standardizedTerm.kind())
		{
			case VARIABLE_USE : {
				Variable v = renamings.get(standardizedTerm.variable());
				nuTerm = factory.newVariableUse(v == null ? standardizedTerm.variable() : v);
				if (hasProperties)
					nuTerm = Util.makePropertiesConstraintsWrapper(
					        nuTerm, nuRef, nuNamedProperties, nuVariableProperties, nuMetaProperties);
				break;
			}
			case META_APPLICATION :
				nuTerm = factory.newMetaApplication(standardizedTerm.metaVariable(), nuSub);
				if (hasProperties)
					nuTerm = Util.makePropertiesConstraintsWrapper(
					        nuTerm, nuRef, nuNamedProperties, nuVariableProperties, nuMetaProperties);
				break;

			case CONSTRUCTION :
				Constructor c = standardizedTerm.constructor();
				Constructor nuc = (c.literalSort() != null
				        ? factory.makeLiteral(c.object(), c.literalSort())
				        : factory.makeConstructor(c.object()));

				if (needsConstraintsWrapper)
				{
					nuTerm = factory.newConstruction(nuc, nuBinders, nuSub);
					nuTerm = Util.makePropertiesConstraintsWrapper(
					        nuTerm, nuRef, nuNamedProperties, nuVariableProperties, nuMetaProperties);
				}
				else
				{
					if (hasProperties)
					{
						try
						{
							nuc = Util.wrapWithProperties(factory, nuc, nuNamedProperties, nuVariableProperties);
						}
						catch (CRSException e)
						{}
					}
					nuTerm = factory.newConstruction(nuc, nuBinders, nuSub);
				}
		}

		return nuTerm;
	}

	/**
	 * For all variables (bound and free), meta-variables and reference meta-variables
	 * everywhere in the given term, save the position where they occur.
	 * Note: this works only because we have required that terms are linear both in
	 * variables and in meta-variables, and that every (meta-)variable which appears as
	 * the key of a property set also appears at a place where it is not a key.
	 * We do require that the same variable is not used in multiple places as a binder.
	 * @param topterm a term to modify
	 * @param metaVariablePositions positions for each of the meta-variables
	 * @param varPositions positions where the variables first occur, preceded by
	 *   x for bound variables (here, the position is the position of the binder),
	 *   z for free variables and y for fresh variables
	 * @param rulename for error messages
	 * @param left whether we're working on the left-hand side of a rule, as opposed
	 *   to the right-hand side (when all meta-variables should already be known,
	 *   bound variables are not very interesting and we are only concerned about
	 *   fresh variables)
	 * @throws CRSException for this to be possible, it is necessary that the variable
	 *   and meta-variable keys in pattern can be resolved to a unique position without
	 *   being known (this is also necessary for the property set lookup to be
	 *   meaningful); if this is not the case, an error is given, which might lead to
	 *   an exception being thrown
	 */
	private void getUnknownPositions(Term topterm, Map<String, String> metaVariablePositions, Map<Variable, String> varPositions, String rulename, boolean left)
	        throws CRSException
	{
		LinkedList<Pair<Term, Pair<String, Object>>> stack = new LinkedList<Pair<Term, Pair<String, Object>>>();
		stack.addLast(new Pair<Term, Pair<String, Object>>(topterm, new Pair<String, Object>("", null)));
		int skipped = 0;
		while (!stack.isEmpty())
		{
			Pair<Term, Pair<String, Object>> info = stack.pop();
			Term term = info.head();
			String pos = info.tail().head();
			Object ob = info.tail().tail();

			// if ob is not null, it is either a variable or a meta-variable,
			// which must be known for "pos" to be accurate
			if (ob != null)
			{
				if (ob instanceof Variable && varPositions.containsKey((Variable) ob))
					pos = pos + subPositionKey(ob, false, metaVariablePositions, varPositions);
				else if (ob instanceof String && metaVariablePositions.containsKey((String) ob))
					pos = pos + subPositionKey(ob, true, metaVariablePositions, varPositions);
				else
				{
					// postpone renaming unknowns in term until we DO know pos
					stack.addLast(info);
					skipped++;
					if (skipped >= stack.size())
					{
						if (left)
							env.error("rule "
							        + rulename
							        + " uses lookup tables with unknown keys which cannot be resolved to anything that is directly used.");
						else
							env.error("rule "
							        + rulename
							        + " saves a fresh variable as a key in a property set which is not used elsewhere in the term; this creates a dead reference.");
						return;
					}
					continue;
				}
			}
			// the variable skipped denotes how often we have postponed an
			// element of the stack in line, to make sure we don't end up in
			// an infinite loop
			skipped = 0;

			switch (term.kind())
			{
				case VARIABLE_USE : {
					Variable x = term.variable();
					if (!varPositions.containsKey(x) && left)
						varPositions.put(x, "z" + pos);
					if (!varPositions.containsKey(x) && !left)
						varPositions.put(x, "y" + pos);
					break;
				}
				case META_APPLICATION :
					if (left)
						metaVariablePositions.put(term.metaVariable(), pos);
					else
						for (int i = 0; i < term.arity(); i++)
							stack.addLast(new Pair<Term, Pair<String, Object>>(term.sub(i), new Pair<String, Object>(pos
							        + subPosition(i, term.arity()), null)));
					break;

				case CONSTRUCTION :
					if (Util.symbol(term).equals(CRS.EVAL_SYMBOL) && term.arity() > 0)
					{
						if (term.sub(0).kind() == Kind.CONSTRUCTION && term.sub(0).constructor().symbol().equals(Primitive.NOT_MATCH.symbol))
						{
							// the children of a $[NotMatch] should be considered at the same
							// depth as this term
							for (int i = 1; i <= 2; i++)
								stack.addLast(new Pair<Term, Pair<String, Object>>(term.sub(i), new Pair<String, Object>(pos, null)));
						}
						else
						{
							// other $-constructions can only occur in the right-hand side of
							// the rules; just check their subterms!
							for (int i = 0; i < term.arity(); i++)
								stack.addLast(new Pair<Term, Pair<String, Object>>(term.sub(i), new Pair<String, Object>(pos
								        + subPosition(i, term.arity()), null)));
						}
					}
					else
					{
						for (int i = 0; i < term.arity(); i++)
						{
							for (int j = 0; j < term.binders(i).length; j++)
								varPositions.put(
								        term.binders(i)[j],
								        "x" + pos + subVariablePosition(i, term.arity(), j, term.binders(i).length));
							stack.addLast(new Pair<Term, Pair<String, Object>>(term.sub(i), new Pair<String, Object>(pos
							        + subPosition(i, term.arity()), null)));
						}
					}
					break;
			}

			// deal with the property set, if it has one
			PropertiesHolder A = Util.propertiesHolder(term);
			if (A != null)
			{
				if (A instanceof PropertiesConstraintsWrapper)
				{
					String ref = ((PropertiesConstraintsWrapper) A).getRef();
					if (ref != null && left)
						metaVariablePositions.put(ref, "Γ" + pos);
					Set<Entry<String, Term>> set = ((PropertiesConstraintsWrapper) A).getLocalMetaProperties().entrySet();
					for (Entry<String, Term> pair : set)
						if (pair.getValue() != null)
							stack.addLast(new Pair<Term, Pair<String, Object>>(pair.getValue(), new Pair<String, Object>(pos,
							        pair.getKey())));
				}
				for (Variable var : A.propertyVariables())
					if (A.getProperty(var) != null)
						stack.addLast(new Pair<Term, Pair<String, Object>>(A.getProperty(var), new Pair<String, Object>(pos, var)));
				for (String fun : A.propertyNames())
					if (A.getProperty(fun) != null)
						stack.addLast(new Pair<Term, Pair<String, Object>>(A.getProperty(fun), new Pair<String, Object>(pos
						        + "o%" + fun + "c", null)));
			}
		}
	}

	/**
	 * Add to result all the meta-variables occurring in term which
	 * occur with a property set.
	 */
	private void getExplicitMetaVariables(Term term, Set<String> result)
	{
		if (term == null)
			return;

		if (term.kind() == Kind.META_APPLICATION && hasPropertySet(term))
			result.add(term.metaVariable());

		for (int i = 0; i < term.arity(); i++)
			getExplicitMetaVariables(term.sub(i), result);

		PropertiesHolder A = Util.propertiesHolder(term);
		if (A == null)
			return;
		for (String n : A.propertyNames())
			getExplicitMetaVariables(A.getProperty(n), result);
		for (Variable v : A.propertyVariables())
			getExplicitMetaVariables(A.getProperty(v), result);
		if (A instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper B = (PropertiesConstraintsWrapper) A;
			for (String m : B.propertyMetaVariables())
				getExplicitMetaVariables(B.getMetaProperty(m), result);
		}
	}

	/** Helper for safe saving of sorts. */
	private void sortPut(Map<Object, Term> sorts, Object key, Term sort)
	{
//		if (key == null)
//			env.warning("bad karma: null key");
		if (sort != null && sort instanceof GenericTerm)
			sort = ((GenericTerm) sort).stripProperties();
		sorts.put(key, sort);
	}

	/** Helper for safe retrieval of sorts. */
	private Term sortGet(Map<Object, Term> sorts, Object key)
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
//							env.warning("bad karma: had to look up variable " + o + " by name!");
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
	public Term sortRemove(Map<Object, Term> sorts, Object key)
	{
		return sorts.remove(key);
	}

	/** Helper for safe saving of sorts. */
	public boolean sortContains(Map<Object, Term> sorts, Object key)
	{
		return sorts.containsKey(key);
	}

	/**
	 * Create a term for a reference meta-variable, binding either a given list
	 * of variables, or a number of fresh variables
	 * @param name The name of the reference meta-variable we should use.
	 * @param pos The position in the original term where this term occurs.
	 * @param vars All the bound variables occurring in the environment of this
	 *   term, or null if the bound variables are not of interest (in this case,
	 *   fresh variables should be used).
	 * @param varSorts Assigns sorts to each of the bound variables, or to the
	 *   variables that should be freshly created; if varSorts and vars are both
	 *   null, an error message is given.
	 * @param sortsSave Used to save the sorts of the newly created subterms.
	 * @param rulename The name of the rule for which we should do this (used
	 *   in error messages).
	 * @return A term of the form #Γpos[x1,...,xn], where the xi are either the
	 *   given bound variables, or Nvars fresh ones.
	 * @throws CRSException possible result of giving an error if fresh
	 *   variables have to be created for a reference which may not take fresh
	 *   variables.
	 */
	private GenericTerm getReference(String name, String pos, List<Variable> vars, Term[] varSorts, Map<Object, Term> sortsSave, String rulename)
	        throws CRSException
	{
		GenericTerm[] args = varSorts == null ? null : new GenericTerm[varSorts.length];
		if (vars == null)
		{
			if (varSorts == null)
			{
				env.error("Property set reference in "
				        + rulename + " used below a binder of a sort "
				        + "that does not allow variables (or unknown sort).  Usage in the "
				        + "contractum of the rule could cause these variables to become free.");
				varSorts = new Term[0];
				args = new GenericTerm[0];
			}
			if (varSorts.length > 0)
				env.warning("Property set reference in "
				        + rulename + " used below a binder.  Usage "
				        + "in the contractum of the rule could cause bound variables to "
				        + "become free.  This is allowed, but may not be intended.");
			for (int i = 0; i < args.length; i++)
			{
				args[i] = factory.newVariableUse(env.makeVariable("r" + pos + "_" + subPosition(i, varSorts.length), true));
				sortPut(sortsSave, args[i], varSorts[i]);
			}
		}
		else
			for (int i = 0; i < varSorts.length; i++)
			{
				args[i] = factory.newVariableUse(vars.get(i));
				sortPut(sortsSave, args[i], varSorts[i]);
			}

		return standardPatternMetaApplication(name, args);
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
	public GenericTerm copyAndReplace(Term term, Map<Object, Term> sorts, Map<Term, GenericTerm> replacements)
	{
		if (term == null)
			return null;
		if (replacements.containsKey(term))
			return replacements.get(term);

		GenericTerm ret = null;
		switch (term.kind())
		{
			case VARIABLE_USE :
				ret = factory.newVariableUse(term.variable());
				break;

			case META_APPLICATION : {
				GenericTerm[] args = new GenericTerm[term.arity()];
				for (int i = 0; i < args.length; i++)
					args[i] = copyAndReplace(term.sub(i), sorts, replacements);
				ret = factory.newMetaApplication(term.metaVariable(), args);
				break;
			}
			case CONSTRUCTION : {
				GenericTerm[] args = new GenericTerm[term.arity()];
				Variable[][] binds = new Variable[term.arity()][];
				for (int i = 0; i < args.length; i++)
				{
					binds[i] = new Variable[term.binders(i).length];
					for (int j = 0; j < binds[i].length; j++)
						binds[i][j] = term.binders(i)[j];
					// note: no need to save sorts of binds, since they should already be in sorts!
					args[i] = copyAndReplace(term.sub(i), sorts, replacements);
				}
				ret = factory.newConstruction(factory.makeConstructor(term.constructor()), binds, args);
				break;
			}
		}

		PropertiesHolder A = Util.propertiesHolder(term);
		if (A != null)
		{
			Map<String, Term> namedPropertiesConstraints = new HashMap<String, Term>();
			for (String name : A.propertyNames())
				namedPropertiesConstraints.put(name, copyAndReplace(A.getProperty(name), sorts, replacements));
			ret = Util.makePropertiesConstraintsWrapper(ret, null, namedPropertiesConstraints, null, null);
		}

		if (sorts != null && sorts.containsKey(term))
			sortPut(sorts, ret, sorts.get(term));
		return ret;
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
	public GenericTerm createCopy(Term term, Map<Object, Term> sorts)
	{
		return copyAndReplace(term, sorts, new HashMap<Term, GenericTerm>());
	}

	// Helpers..

	/**
	 * To satisfy standard naming conventions, we need a string which
	 * uniquely identifies a given position.  In a term F[s1,s2] we
	 * call the positions for s1 and s2 just "1" and "2"
	 * respectively.  But in a term with more than 10 immediate
	 * subterms, the first two would need to be named "01" and "02".
	 * This function determines the position-strings for the
	 * immediate subterms of a term with a given arity.
	 */
	public static String subPosition(int pos, int arity)
	{
		int arlen = 1;
		while (arity >= 10) // compute log10(arity)
		{
			arity /= 10;
			arlen++;
		}
		String ret = "" + (pos + 1);
		while (ret.length() < arlen)
			ret = "0" + ret;
		return ret;
	}

	/**
	 * To satisfy standard naming conventions, we need a string which uniquely
	 * identifies the binder at a given position; as in subPosition, this must
	 * respect the arity of the term and the number of binders, so positions
	 * are for instance 01_001, 01_103 and 99_018.
	 */
	public static String subVariablePosition(int pos, int arity, int binder, int numbinds)
	{
		String base = subPosition(pos, arity) + "_";
		int bindlen = 1;
		while (numbinds >= 10)
		{
			numbinds /= 10;
			bindlen++;
		}
		String b = "" + binder;
		while (b.length() < bindlen)
			b = "0" + b;
		return base + b;
	}

	/**
	 * Returns the sub-position for a value in a property set, which is
	 * associated with the given key.  The key may be a string name, a
	 * meta-variable name or a variable, and in the latter two cases its
	 * standard name is given by the last two parameters.
	 * @param key Either a string or a variable: the key associated to the
	 *   property whose position we want to know.
	 * @param isMeta Indicates whether the key should be seen as a
	 *   meta-variable (if it is a string).  If not, and key is a string,
	 *   then it is considered as a constructor.
	 * @param metaPos Assigns to all meta-variables (including the given
	 *   key if that is a meta-variable) their position in a larger term.
	 * @param varPos Assigns to all variables (including the given key if
	 *   that is a variable) a name, either starting with x (bound variable),
	 *   y (fresh variable) or z (free variable), denoting its position in
	 *   a rule.
	 * @return The sub-position to be used for the value associated with
	 *   the given key.
	 */
	public static String subPositionKey(Object key, boolean isMeta, Map<String, String> metaPos, Map<Variable, String> varPos)
	{
		if (key instanceof Variable)
			return "o" + varPos.get((Variable) key) + "c";
		if (isMeta)
			return "o#" + metaPos.get((String) key) + "c";
		return "o%" + key + "c";
	}

	/**
	 * Returns whether the given term either has a non-empty property set,
	 * or an empty property set indicated by a PropertiesConstraintsWrapper
	 * (standardization establishes this - the function is also used for
	 * the original rules, which is why there are more checks).
	 */
	public static boolean hasPropertySet(Term term)
	{
		PropertiesHolder ph = Util.propertiesHolder(term);
		if (ph == null)
			return false;
		Iterator<String> its = ph.propertyNames().iterator();
		if (its.hasNext())
		{
			if (!STANDARDIZED.equals(its.next()) || its.hasNext())
				return true; // only return true if NON-$$STANDARDIZED property
		}
		if (ph.propertyVariables().iterator().hasNext())
			return true;
		if (ph.isMeta())
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
			if (pcw.getRef() != null)
				return true;
			if (pcw.propertyMetaVariables().iterator().hasNext())
				return true;
		}
		return false;
	}
	
	/**
	 * Add all meta-variables in standardized term 
	 * @param term
	 * @param metas
	 */
	public static void addMetas(Term term, Set<String> metas)
	{
		if (term == null)
			return;
		if (term.kind() == Kind.META_APPLICATION)
				metas.add(term.metaVariable());
		for (int i = 0; i < term.arity(); ++i)
			addMetas(term.sub(i), metas);
		PropertiesHolder ph = Util.propertiesHolder(term);
		if (ph != null)
			for (String p : ph.propertyNames())
			{
				if (p.startsWith("#"))
					metas.add(p);
				addMetas(ph.getProperty(p), metas);
			}
	}
}
