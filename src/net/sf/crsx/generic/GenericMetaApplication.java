/* Copyright (c) 2006, 2008 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Maker.ContinuationSinkSetter;
import net.sf.crsx.Match;
import net.sf.crsx.MetaAnalyzer;
import net.sf.crsx.Pattern;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SimpleVariableSet;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Generic implementation of <em>meta-application</em> terms used internally by {@link GenericBuffer}.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericMetaApplication.java,v 3.9 2014/02/03 20:09:57 krisrose Exp $
 */
public class GenericMetaApplication extends GenericTerm
{
	// State.

	/** Symbol. */
	final String metaVariable;

	/** The subterms. */
	final GenericTerm[] sub;

	/** Whether this meta-application is forced. */
	final boolean data;

	/** 
	 * Reference management, based on context:
	 * pattern    : 0=DISCARD, > 0=USE[Counter]
	 * contractum : > 0=USE[Counter]
	 * other      : -3=N/A,
	 */
	int count;

	/** Rewrite system or null. */
	final CRS crs;

	// Constructor.

	/** Construct meta-application. */
	public GenericMetaApplication(GenericFactory factory, String metaVariable, GenericTerm[] sub)
	{
		this(factory, metaVariable, sub, false, null);
	}

	/**
	 * Construct meta-application with link to host CRS.
	 * @param factory for generic term management
	 * @param metaVariable of meta-application
	 * @param sub subterms of meta-application
	 * @param data whether the meta-application is forced
	 * @param crs rewrite system (may be null)
	 */
	public GenericMetaApplication(GenericFactory factory, String metaVariable, GenericTerm[] sub, boolean data, CRS crs)
	{
		super(factory);
		this.metaVariable = metaVariable;
		this.sub = sub;
		this.data = data;
		this.crs = crs;
		this.count = -3; // Not applicable
	}

	// GenericTerm...

	@Override
	GenericTerm[] allSubs()
	{
		return sub;
	}

	@Override
	public void replaceSub(int i, Variable[] bs, GenericTerm t)
	{
		assert bs == null || bs.length == 0 : "meta-application cannot have binders";
		sub[i] = t;
	}

	@Override
	public GenericTerm stripProperties()
	{
		return this;
	}

	// Copyable...

	@Override
	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		sink = sink.startMetaApplication(metaVariable);
		for (Term t : sub)
			sink = t.copy(sink, discard, renames);
		return sink.endMetaApplication();
	}

	// Stub...

	@Override
	public Kind kind()
	{
		return Kind.META_APPLICATION;
	}

	@Override
	public int arity()
	{
		return sub.length;
	}

	@Override
	public String metaVariable()
	{
		return metaVariable;
	}

	@Override
	public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		if (renames == null)
			renames = LinkedExtensibleMap.EMPTY_RENAMING;
		if (discard && renames.isEmpty())
			return this;

		final String m = metaVariable;
		final int a = arity();
		final GenericTerm[] ss = new GenericTerm[a];
		for (int i = 0; i < a; ++i)
			ss[i] = sub[i].copy(discard, renames);
		return new GenericMetaApplication(factory, m, ss);
	}

	// Term...

	public Variable[] binders(int i)
	{
		return Sink.NO_VARIABLES;
	}

	public GenericTerm sub(int i)
	{
		assert i < arity();
		return sub[i];
	}

	public Sink replaceSubSink(final int i)
	{
		return factory.makeBuffer(new Maker.CallBack()
			{
				@Override
				public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
				{
					assert binders.length == 0 : "Cannot have binders on meta-application arguments!";
					sub[i] = (GenericTerm) term;
				}
			});
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
			if (!sub(i).checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;
		return true;
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		if (includemetaapps)
		{
			final int arity = arity();
			for (int i = 0; i < arity; ++i)
				sub[i].addFree(set, bound, includemetaapps, base); // TODO: not sort sensitive!
		}
	}

	public void addMetaCounts(Map<String, Integer> counts)
	{
		counts.put(metaVariable, counts.containsKey(metaVariable) ? counts.get(metaVariable) + 1 : 1);
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
			sub[i].addMetaCounts(counts);
	}

	final public void analyzeMetaUseContractum(Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
	{
		counts.put(metaVariable, counts.containsKey(metaVariable) ? counts.get(metaVariable) + 1 : 1);
		count = counts.get(metaVariable);

		final int arity = arity();
		for (int i = arity - 1; i >= 0; i--)
			// Reverse order
			sub[i].analyzeMetaUseContractum(counts, subAnalyzers);
	}

	final public void analyzeMetaUsePattern(Map<String, Integer> counts)
	{
		Integer c = counts.get(metaVariable);
		if (c == null)
			count = 0; // Meta variable is discarded
		else
			count = c;
	}

	public Sink subsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		if (possible.isEmpty())
			return copy(sink, false, bound); // Copying means there will be no substitutions so only pass redex bound variable renamings

		sink = sink.startMetaApplication(metaVariable);
		for (int i = 0; i < sub.length; ++i)
			sink = sub[i].subsubstitute(sink, valuation, renamings, substitution, bound, possible);
		return sink.endMetaApplication();
	}

	public boolean equalsModulo(Term that, ExtensibleMap<Variable, Variable> renamings)
	{
		if (that.kind() != Kind.META_APPLICATION)
			return false;

		final int arity = arity();
		if (arity != that.arity())
			return false;

		if (!metaVariable.equals(that.metaVariable()))
			return false;

		for (int i = 0; i < arity; ++i)
			if (!sub(i).equalsModulo(that.sub(i), renamings))
				return false;

		return true;
	}

	public void appendTermTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean outer, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		writer.append(Util.externalizeMetaVariable(metaVariable));
		final int arity = sub.length;
		if (arity > 0)
		{
			writer.open("[");
			sub[0].appendTo(writer, used, depth - 1, full, namedProps, variableProps, null, sortProps);
			for (int i = 1; i < arity; ++i)
			{
				writer.close(",\n");
				writer.open("");
				if (sub[i] instanceof GenericTerm)
					((GenericTerm) sub[i]).appendTermTo(
							writer, used, noLinear, depth - 1, false, full, namedProps, variableProps,
							LinkedExtensibleSet.EMPTY_VARIABLE_SET, sortProps);
				else
					sub[i].appendTo(writer, used, depth - 1, full, namedProps, variableProps, null, sortProps);
			}
			writer.close("]");
		}
	}

	public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
	{
		// Meta-application.
		sink = sink.start(sink.makeConstructor(CRS.REIFY_META_APPLICATION)); // META-APPLICATION[
		int ends = 0;
		sink = sink.start(sink.makeLiteral(metaVariable, CRS.STRING_SORT)).end();
		for (int i = 0; i < arity(); ++i)
		{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
			++ends;
			Term sort = metaArgSort.get(metaVariable + "-" + i);
			if (Completer.PRESENT.equals(Util.symbol(sub(i))))
			{
				Variable v = sub(i).sub(0).variable();
				sink = sink.start(sink.makeConstructor(CRS.REIFY_META_REQUIRED_VARIABLE)); // META-REQUIRED-VARIABLE[
				sink = sink.use(v); // variable
				sink = sink.end(); // ] of META-REQUIRED-VARIABLE
				if (sort == null)
					sort = freeSort.get(v);
			}
			else
			{
				if (sort == null && sub(i).kind() == Kind.VARIABLE_USE)
					sort = freeSort.get(sub(i).variable());
				sink = sink.start(sink.makeConstructor(CRS.REIFY_ARGUMENT)); // ARGUMENT[
				sink = GenericCRS.reifySort(factory, sink, sort);
				sink = sub(i).reify(sink, metaArgSort, freeSort, subReifiers); // argument
				sink = sink.end(); // ] of ARGUMENT
			}
		}
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // NIL
		while (ends-- > 0)
			sink = sink.end(); // ] of CONS
		if (count == -3)
			sink = sink.start(sink.makeConstructor(CRS.REIFY_NA)).end(); // NA
		else if (count == 0) // DISCARD
			sink = sink.start(sink.makeConstructor(CRS.REIFY_DISCARD)).end(); // DISCARD
		else
		{
			sink = sink.start(sink.makeConstructor(CRS.REIFY_USE)); // USE
			sink = sink.start(sink.makeLiteral(Integer.toString(count), CRS.NUMERIC_SORT)).end();
			sink = sink.end(); // ] of COPY
		}
		sink = sink.end(); // ] of META-APPLICATION
		return sink;
	}

	// Pattern...

	public boolean match(Match match, Term redex, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		// Usual match of pattern meta-application against a proper (non-meta-application) term.
		final int arity = sub.length;
		final Variable[] patternVariables = new Variable[arity]; // variable arguments to meta-application
		for (int i = 0; i < arity; ++i)
		{
			assert sub[i].kind() == Kind.VARIABLE_USE : "Pattern has non-variable meta-application argument (" + this + ")";
			patternVariables[i] = sub[i].variable();
		}

		Substitute substitute = match.getSubstitute(metaVariable);
		if (substitute == null)
		{
			// First match for meta-variable (usual linear case).
			// Compute forbidden bound variables.
			ExtensibleSet<Variable> forbidden = SimpleVariableSet.EMPTY;
			if (arity < bound.size())
			{
				List<Variable> vs = Arrays.asList(patternVariables);
				for (Variable b : bound)
					if (!vs.contains(b))
						forbidden = forbidden.extend(b);
			}
			// Compute whether the meta-variable itself is subject to duplication.
			boolean mightBeDuplicated = promiscuous || metaVariablePromiscuous(contractionCount);
			// Check, if needed.
			if (!forbidden.isEmpty() || (mightBeDuplicated && !once.isEmpty())) // TODO: check logic...
				if (!redex.checkFree(forbidden, once, onceSeen, mightBeDuplicated, bound))
					return false;

			// Record in matching.
			Variable[] bindings = new Variable[arity];
			for (int i = 0; i < arity; ++i)
				bindings[i] = match.getVariable(patternVariables[i]);
			match.putSubstitute(metaVariable, bindings, redex);
			return true;
		}
		else
		{
			// Rematch!
			Variable[] binders = new Variable[arity];
			for (int i = 0; i < arity; ++i)
				binders[i] = match.getVariable(patternVariables[i]);
			return substitute.rematch(match, binders, redex);
		}
	}

	/** Whether this meta-application might be contracted more than once for particular contraction. */
	private boolean metaVariablePromiscuous(Map<String, Integer> contractionCount)
	{
		if (contractionCount == null)
			return false; // 0 < 2.
		Integer count = contractionCount.get(metaVariable);
		if (count == null)
			return false; // 0 < 2.
		if (count == -1)
			return true; // unknown so assume promiscuous
		return (count > 1); // simple check
	}

	final public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		visitor.visitMetaApplication(this, true, bound);
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
		{
			visitor.visitMetaApplicationSub(this, i, true, bound);
			sub(i).visit(visitor, bound.extend(binders(i)));
			visitor.visitMetaApplicationSub(this, i, false, bound);
		}
		visitor.visitMetaApplication(this, false, bound);
	}

	final public Contractum oldunify(ExtensibleMap<Variable, Variable> thisBound, Map<Variable, Variable> thisBaseVariable, Map<String, String> thisBaseMeta, Pattern that, ExtensibleMap<Variable, Variable> thatBound, Map<Variable, Variable> thatBaseVariable, Map<String, String> thatBaseMeta, Match unifiedMatch, ExtensibleMap<Variable, Variable> unifiedBound, Map<String, List<Pair<ExtensibleMap<Variable, Variable>, Term>>> unifiedMatched)
	{
		// Note: this handles all combinations with meta-applications.

		// Properties of this pattern meta-application.
		String thisMetaVariable = metaVariable();
		String thisBaseMetaVariable = thisBaseMeta.get(thisMetaVariable);

		// Compute variable lists for this, also after mapping to unified term.  TODO: be lazy about it...
		int thisArity = arity();
		List<Variable> thisPatternVariables = new ArrayList<Variable>(thisArity);
		List<Variable> thisBasePatternVariables = new ArrayList<Variable>(thisArity);
		for (int i = 0; i < thisArity; ++i)
		{
			assert sub(i).kind() == Kind.VARIABLE_USE : "Unify applied to non-pattern meta-application (" + this + ")";
			Variable v = sub(i).variable();
			assert thisBound.containsKey(v) : "Unbound pattern variable slipped through?!?";
			assert !thisPatternVariables.contains(v) : "Repeated pattern variable slipped through?!?";
			thisPatternVariables.add(v);
			thisBasePatternVariables.add(thisBaseVariable.get(v));
		}

		// Unified structures.
		Substitute baseSubstitute;
		GenericTerm base = null;

		// Now deal with that.
		switch (that.kind())
		{
			case CONSTRUCTION :
			case VARIABLE_USE : {
				// The meta-application is being matched against some term.
				if (thisMetaVariable == null)
				{
					// Previously unmatched meta-variable: Setup corresponding base pattern and check it matches
					thisBaseMetaVariable = makeMetaVar(thisMetaVariable, thisBaseMeta, thatBaseMeta);
					thisBaseMeta.put(thisMetaVariable, thisBaseMetaVariable);
					base = unifiedMetaApplication(thisBaseMetaVariable, thisBound.getAll(thisPatternVariables));
					if (!base.match(
							unifiedMatch, that, SimpleVariableSet.make(thatBound.values()), null, true, SimpleVariableSet.EMPTY,
							null))
						return null; // this does not match, so fail

					assert !unifiedMatched.containsKey(thisBaseMetaVariable) : "Previously unmatched meta-variable already registered as matched?!?";
					List<Pair<ExtensibleMap<Variable, Variable>, Term>> matched = new LinkedList<Pair<ExtensibleMap<Variable, Variable>, Term>>();
					matched.add(new Pair<ExtensibleMap<Variable, Variable>, Term>(unifiedBound, that));
					unifiedMatched.put(thisBaseMetaVariable, matched);
				}
				else
				{
					// Previously matched meta-variable. Rematch the substitution against the new term. 
					thisBaseMetaVariable = thisBaseMeta.get(thisMetaVariable);
					base = unifiedMetaApplication(thisBaseMetaVariable, thisBound.getAll(thisPatternVariables));
					baseSubstitute = unifiedMatch.getSubstitute(thisBaseMetaVariable);
					assert baseSubstitute != null : "Lost previously matched unified substitute?!?";
					if (!baseSubstitute.rematch(unifiedMatch, baseSubstitute.getBindings(), that))
						return null; // this does not rematch that, so fail

					assert unifiedMatched.containsKey(thisBaseMetaVariable) : "Previously matched meta-variable not registered?!?";
					List<Pair<ExtensibleMap<Variable, Variable>, Term>> matched = unifiedMatched.get(thisBaseMetaVariable);
					matched.add(new Pair<ExtensibleMap<Variable, Variable>, Term>(unifiedBound, that));
				}
				return base; // success
			}

			case META_APPLICATION : {
				// The meta-application is being matched against that meta-application.
				// Unification succeeds if the base and unified can be updated consistently.

				// Record properties of that.
				String thatMetaVariable = that.metaVariable();
				String thatBaseMetaVariable = thatBaseMeta.get(thatMetaVariable);

				// Compute variable lists for that, also after mapping to unified term.
				int thatArity = that.arity();
				List<Variable> thatPatternVariables = new ArrayList<Variable>(thatArity);
				List<Variable> thatBasePatternVariables = new ArrayList<Variable>(thatArity);
				for (int i = 0; i < thatArity; ++i)
				{
					assert that.sub(i).kind() == Kind.VARIABLE_USE : "Unify applied to non-pattern meta-application (" + that + ")";
					Variable v = that.sub(i).variable();
					assert thatBound.containsKey(v) : "Unbound pattern variable slipped through?!?";
					assert !thatPatternVariables.contains(v) : "Repeated pattern variable slipped through?!?";
					thatPatternVariables.add(v);
					thatBasePatternVariables.add(thatBaseVariable.get(v));
				}

				// Compute common pattern variables.
				List<Variable> commonBasePatternVariables = new ArrayList<Variable>();
				commonBasePatternVariables.addAll(thisBasePatternVariables);
				commonBasePatternVariables.retainAll(thatBasePatternVariables);

				// Now derive the appropriate base pattern meta-application...
				if (thisBaseMetaVariable == null)
				{
					if (thatBaseMetaVariable == null)
					{
						// For two previously unknown meta-variables craft fresh base pattern meta-variable.
						thisBaseMetaVariable = makeMetaVar(thisMetaVariable + "-" + thatMetaVariable, thisBaseMeta, thatBaseMeta);
						thisBaseMeta.put(thisMetaVariable, thisBaseMetaVariable);
						thatBaseMetaVariable = thisBaseMetaVariable;
						thatBaseMeta.put(thatMetaVariable, thatBaseMetaVariable);

						// Fabricate initial base and baseSubstitute!
						base = unifiedMetaApplication(thisBaseMetaVariable, commonBasePatternVariables);
						base.match(
								unifiedMatch, base, SimpleVariableSet.make(thatBound.values()), null, true,
								SimpleVariableSet.EMPTY, null); // match with itself...really just to register as Substitute
						baseSubstitute = unifiedMatch.getSubstitute(thisBaseMetaVariable);
					}
					else
					{
						// Only that previously matched - make this an alias.
						thisBaseMetaVariable = thatBaseMetaVariable;
						thisBaseMeta.put(thisMetaVariable, thisBaseMetaVariable);
						baseSubstitute = unifiedMatch.getSubstitute(thatBaseMetaVariable);

						List<Variable> baseSubstituteBindings = Arrays.asList(baseSubstitute.getBindings());
						if (!baseSubstituteBindings.equals(commonBasePatternVariables))
						{
							// TODO: actually rematch with restricted variable list...
							return null;
						}
						base = unifiedMetaApplication(thatBaseMetaVariable, commonBasePatternVariables);
						if (!baseSubstitute.rematch(unifiedMatch, baseSubstituteBindings.toArray(new Variable[0]), that))
						{
							assert false : "Rematch of constructed pattern fails?!?";
							return null;
						}
					}
				}
				else
				{
					// This previously matched...
					baseSubstitute = unifiedMatch.getSubstitute(thisBaseMetaVariable);
					base = unifiedMetaApplication(thisBaseMetaVariable, Arrays.asList(baseSubstitute.getBindings()));
					//
					if (thatBaseMetaVariable == null)
					{
						// Only this previously matched - reuse for that.
						thatBaseMetaVariable = thisBaseMetaVariable;
						thatBaseMeta.put(thatMetaVariable, thatBaseMetaVariable);
						baseSubstitute = unifiedMatch.getSubstitute(thisBaseMetaVariable);

						List<Variable> baseSubstituteBindings = Arrays.asList(baseSubstitute.getBindings());
						if (!baseSubstituteBindings.equals(commonBasePatternVariables))
						{
							// TODO: actually rematch with restricted variable list...
							return null;
						}
						base = unifiedMetaApplication(thisBaseMetaVariable, commonBasePatternVariables);
						if (!baseSubstitute.rematch(unifiedMatch, baseSubstituteBindings.toArray(new Variable[0]), this))
						{
							assert false : "Rematch of constructed pattern fails?!?";
							return null;
						}
					}
					else if (thisBaseMetaVariable.equals(thatBaseMetaVariable))
					{
						// Already matched to each other -- nothing more to do.
					}
					else
					{
						// Both this and that previously matched but to different base patterns...join them!
						// TODO:  Join this and that match...rematch all for the combined base variable!
						return null;
					}
				}
				return base; // success
			}
		}
		assert false : "Matching against improper term";
		return null;
	}

	@Override
	protected Unification unifyThese(Unification unification, Pattern that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime, Set<String> existingMVars)
			throws CRSException
	{

		Substitute s = unification.getSubstitute(this.metaVariable());

		if (s != null)
		{
			//TODO : Fix for left-linearity
			assert false : "Metavariable already bound - not a left-linear system";
			//    		//Metavariable is already bound. Apply substitute and redo unification
			//    		Copyable c = s.substitute(new DummyValuation(), this.sub);
			//    		Buffer b = new Buffer(maker);
			//			c.copy(b.sink(), false, LinkedExtensibleMap.EMPTY_RENAMING);
			//    		return ((GenericTerm)(b.term(true))).unifyThese(unification, that, rho, rhoprime, existingMVars);
		}
		else
		{
			//Metavariable not bound yet.

			//TODO : Fix occurs check when non-linearity is introduced
			//    		//Occurs check
			//    		if (that.occurs(this.metaVariable(), unification)){
			//    			//this metavariable occurs in that pattern under substitution, so fail. 
			//    			return null;
			//    		}

			switch (that.kind())
			{
				case CONSTRUCTION : {
					//Check for GenericEvaluators, and delegate if needed
					if (that instanceof GenericEvaluator)
					{
						return ((GenericEvaluator) that).unifyThese(unification, this, rhoprime, rhoprime, existingMVars);
					}
					int arity = this.arity();

					//Compute free variables of that
					Set<Variable> thatFVmin = new HashSet<Variable>();
					that.addFree(thatFVmin, new LinkedExtensibleSet<Variable>(), false, null);

					//Compute allowable variables 
					Set<Variable> thisfree = new HashSet<Variable>();
					this.addFree(thisfree, new LinkedExtensibleSet<Variable>(), true, null);
					Set<Variable> rhothisfree = new HashSet<Variable>();
					for (Variable v : thisfree)
					{
						Variable rhov = rho.get(v);
						assert rhov != null : "Variable of metaapplication occurs unbound";
						rhothisfree.add(rhov);
					}

					//Check that free variables of that are allowed to occur
					for (Variable v : thatFVmin)
					{
						Variable rhoprimev = rhoprime.get(v);
						if (rhoprimev == null)
						{
							throw new CRSException("Metaapplication being unified with construction containing free variable");
						}
						if (!rhothisfree.contains(rhoprimev))
						{
							//Variable not allowed to occur. Unification fails.
							return null;
						}
					}

					//TODO: Fix when introducing non-linearity
					//Collect bitmasks for each metavariable and collect an occurrence for each metavariable
					Map<String, Boolean[]> bitmasks = new HashMap<String, Boolean[]>();
					Map<String, GenericMetaApplication> occurrences = new HashMap<String, GenericMetaApplication>();

					((GenericTerm) that).generateBitmasks(rhothisfree, rhoprime, new StackedMap<Variable>(), bitmasks, occurrences);

					//Assign new metavariable names to metavariables in that
					Map<String, String> newmvars = new HashMap<String, String>();
					for (String mvar : bitmasks.keySet())
					{
						String newmvar = GenericUnification.makeMetaVar(mvar, existingMVars);
						existingMVars.add(newmvar);
						newmvars.put(mvar, newmvar);
					}

					//Construct trivial substitutes for metavars in that, using newmvars and bitmasks, 
					//and add to unification.
					for (Map.Entry<String, GenericMetaApplication> entry : occurrences.entrySet())
					{
						Variable[] args = new Variable[entry.getValue().arity()];
						for (int i = 0; i < args.length; i++)
						{
							Variable argsource = entry.getValue().sub(i).variable();
							Variable argtarget = rhoprime.get(argsource);
							if (argtarget != null)
							{
								args[i] = argtarget;
							}
							else
							{
								//Variable bound below current node. Just reuse name.
								args[i] = argsource;
							}
						}

						Boolean[] bitmask = bitmasks.get(entry.getKey());
						LinkedList<Variable> bodyargs = new LinkedList<Variable>();
						for (int i = 0; i < bitmask.length; i++)
						{
							if (bitmask[i])
							{
								bodyargs.addLast(args[i]);
							}
						}

						GenericTerm body = unifiedMetaApplication(newmvars.get(entry.getKey()), bodyargs);
						//TODO: Figure out whether these substitutes should be added to sigma, or whether
						//they should be handled by unificationcopy
						unification.putSubstitute(entry.getKey(), args, body);
					}

					//Construct substitute for this
					Variable[] thissubbinders = new Variable[arity];
					for (int i = 0; i < arity; i++)
					{
						Variable subibinder = rho.get(((GenericTerm) sub[i]).variable());
						if (subibinder != null)
						{
							thissubbinders[i] = subibinder;
						}
						else
						{
							thissubbinders[i] = ((GenericTerm) sub[i]).variable();
						}
					}

					ExtensibleMap<Variable, Variable> renames = new LinkedExtensibleMap<Variable, Variable>().extend(rhoprime);

					GenericTerm thissubbody = (GenericTerm) ((GenericTerm) that).applySubstitutes(unification).copy(true, renames);

					//Construct substitute and add to unification
					unification.putSubstitute(this.metaVariable(), thissubbinders, thissubbody);

					return unification;

				}
				case VARIABLE_USE : {
					GenericTerm subbody;
					Variable localTarget = rhoprime.get(that.variable());

					if (localTarget == null)
					{
						throw new CRSException("Metaapplication being unified with free variable");
					}
					else
					{
						//Variable occurs bound. Unify if corresponding variable is allowed in metaapplication
						boolean found = false;
						for (int i = 0; i < sub.length && !found; i++)
						{
							Variable metaAppArg = ((GenericVariableUse) sub[i]).variable();
							Variable argTarget = rho.get(metaAppArg);
							assert argTarget != null : "Free variable occurs in metaapplication";
							if (argTarget.equals(localTarget))
							{
								found = true;
							}
						}
						if (found)
						{
							//Unification succeeds
							ExtensibleMap<Variable, Variable> renames = new LinkedExtensibleMap<Variable, Variable>();
							subbody = (GenericTerm) that.copy(false, renames.extend(rhoprime));
						}
						else
						{
							//Unification fails
							return null;
						}
					}

					Variable[] subbinders = new Variable[sub.length];
					for (int i = 0; i < sub.length; i++)
					{
						Variable rhov = rho.get(((GenericVariableUse) sub[i]).variable());
						assert rhov != null : "This assertion did not fail 20 lines ago!";
						subbinders[i] = rhov;
					}

					unification.putSubstitute(this.metaVariable(), subbinders, subbody);
					return unification;
				}
				case META_APPLICATION : {
					//Check that other metaapplication is not bound.
					Substitute thatbound = unification.getSubstitute(that.metaVariable());
					if (thatbound != null)
					{
						//TODO : Fix when introducing non-linearity
						assert false : "Metavariable already bound - non-linear system";
						//Other metavariable is bound. Apply substitute and redo call
						//    	    		Copyable c = thatbound.substitute(new DummyValuation(), ((GenericMetaApplication)that).sub);
						//    	    		Buffer b = new Buffer(that.maker());
						//						c.copy(b.sink(), false, LinkedExtensibleMap.EMPTY_RENAMING);
						//    	    		return this.unifyThese(unification, (GenericTerm)(b.term(true)), rho, rhoprime, existingMVars);
					}
					else
					{
						//Other metavariable is not bound. Create identical metaapplications and bind both 
						//metavariables to substitutes with that metaapplication as its body.

						//Create new metavariable
						String newmvar = GenericUnification.makeMetaVar(this.metaVariable() + that.metaVariable(), existingMVars);
						existingMVars.add(newmvar);

						//Create list of variables to apply new metavariable to.
						LinkedList<Variable> metaappargs = new LinkedList<Variable>();
						int arity = this.arity();
						int thatarity = that.arity();
						for (int i = 0; i < arity; i++)
						{
							Variable appargtarget = rho.get(sub[i]);
							assert appargtarget != null : "Variable occurs free in metaapplication";
							for (int j = 0; j < thatarity; j++)
							{
								Variable thatappargtarget = rhoprime.get(that.sub(j));
								assert thatappargtarget != null : "Variable occurs free in metaapplication";
								if (thatappargtarget.equals(appargtarget))
								{
									//Variable allowed to occur. Add to metaappargs, and move to outer loop
									metaappargs.addLast(appargtarget);
									break;
								}
								//else variable is not allowed to occur, so do not add. Continue searching.
							}
							//Variable either found and added, or not found and hence ignored. Continue outer loop
						}

						//Create new identical metaapplications
						GenericTerm thismetaapp = unifiedMetaApplication(newmvar, metaappargs);
						GenericTerm thatmetaapp = unifiedMetaApplication(newmvar, metaappargs);

						//Create argument lists for substitutes
						Variable[] thisargs = new Variable[arity];
						for (int i = 0; i < arity; i++)
						{
							Variable subi = ((GenericTerm) sub[i]).variable();
							Variable subiTarget = rho.get(subi);
							assert subiTarget != null : "This assertion did not fail 20 lines ago!";
							thisargs[i] = subiTarget;
						}

						Variable[] thatargs = new Variable[thatarity];
						for (int i = 0; i < thatarity; i++)
						{
							Variable subi = ((GenericTerm) that.sub(i)).variable();
							Variable subiTarget = rhoprime.get(subi);
							assert subiTarget != null : "This assertion did not fail 30 lines ago!";
							thatargs[i] = subiTarget;
						}

						unification.putSubstitute(newmvar, thisargs, thismetaapp);
						unification.putSubstitute(newmvar, thatargs, thatmetaapp);

						return unification;
					}
				}
			}
		}
		assert false : "Control fell through in GenericMetaApplication.unifyThese";
		return null;
	}

	/** Helper to create unused meta-variable name. */
	private static String makeMetaVar(String unifiedMetaVariable, Map<String, String> thisMeta, Map<String, String> thatMeta)
	{
		String result = unifiedMetaVariable;
		for (int i = 0; thisMeta.containsValue(result) || thatMeta.containsValue(result); ++i)
			result = unifiedMetaVariable + "-" + i;
		return result;
	}

	/** Helper to create meta-application with variable arguments. */
	private GenericTerm unifiedMetaApplication(String unifiedMetaVariable, List<Variable> variables)
	{
		int thisArity = variables.size();
		GenericTerm[] unifiedSub = new GenericTerm[thisArity];
		for (int i = 0; i < thisArity; ++i)
			unifiedSub[i] = new GenericVariableUse(factory, variables.get(i), null);
		return new GenericMetaApplication(factory, unifiedMetaVariable, unifiedSub);
	}

	@Override
	protected void generateBitmasks(Set<Variable> legalvars, StackedMap<Variable> rhoprime, StackedMap<Variable> inscope, Map<String, Boolean[]> bitmasks, Map<String, GenericMetaApplication> occurrences)
	{
		int arity = this.arity();
		Boolean[] bitmask;
		if (bitmasks.containsKey(this.metaVariable()))
		{
			bitmask = bitmasks.get(this.metaVariable());
		}
		else
		{
			//New occurrence
			occurrences.put(this.metaVariable(), this);
			bitmask = new Boolean[arity];
		}

		for (int i = 0; i < arity; i++)
		{
			if (bitmask[i])
			{
				//Check whether ith variable is allowed to occur
				Variable ith = ((GenericTerm) this.sub(i)).variable();
				Variable ithtarget = rhoprime.get(ith);
				bitmask[i] = inscope.containsKey(ith) || ithtarget == null || legalvars.contains(ithtarget);
			}
		}
	}

	// Contractum.

	public Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		Substitute s = valuation.getSubstitute(metaVariable);
		if (s != null)
		{
			if (data && crs != null)
			{
				try
				{
					Term nf = crs.normalize(s.getBody());
					s.replaceBody(nf);
				}
				catch (CRSException e)
				{}
			}
			// ENTRY POINT TO Substitute.substitute().
			return s.substitute(valuation, sub).copy(sink, true, renamings); // normal case...
		}
		else
		{
			// Otherwise just echo the meta-application itself (contracting the arguments).
			sink = sink.startMetaApplication(metaVariable);
			for (Term t : sub)
				sink = ((Contractum) t).contract(sink, valuation, renamings);
			return sink.endMetaApplication();
		}
	}

	@Override
	protected boolean occurs(String mvar, Unification unification)
	{
		if (this.metaVariable().equals(mvar))
		{
			//This is the mvar we're looking for.
			return true;
		}

		Substitute s = unification.getSubstitute(mvar);

		if (s == null)
		{
			//This is not the mvar, we're looking for, and this one is not bound.
			return false;
		}

		return ((GenericTerm) (s.getBody())).occurs(mvar, unification);
	}

	public Set<String> mvars()
	{
		Set<String> result = new HashSet<String>();
		result.add(this.metaVariable());
		return result;
	}

	@Override
	public GenericTerm makeUnificationCopy(StackedMap<Variable> varrenamings, Map<String, String> mvarrenamings)
	{
		String mv = mvarrenamings.get(this.metaVariable());
		if (mv == null)
		{
			mv = this.metaVariable();
		}

		GenericTerm[] subs = new GenericTerm[this.arity()];
		for (int i = 0; i < sub.length; i++)
		{
			subs[i] = ((GenericTerm) sub[i]).makeUnificationCopy(varrenamings, mvarrenamings);
		}

		return factory.newMetaApplication(mv, subs);
	}

	@Override
	public GenericTerm applySubstitutes(Unification unification)
	{
		Substitute s = unification.getSubstitute(this.metaVariable());

		if (s == null)
		{
			//Metavariable not bound. Apply substitutes to children, and return copy
			GenericTerm[] subs = new GenericTerm[this.arity()];
			for (int i = 0; i < subs.length; i++)
			{
				subs[i] = ((GenericTerm) this.sub(i)).applySubstitutes(unification);
			}
			return factory.newMetaApplication(this.metaVariable(), subs);
		}
		else
		{
			Copyable c = s.substitute(new DummyValuation(), this.sub);
			Buffer b = new Buffer(this.maker());
			c.copy(b.sink(), false, LinkedExtensibleMap.EMPTY_RENAMING);
			return ((GenericTerm) b.term(true)).applySubstitutes(unification);
		}
	}

	// Object...

	@Override
	public int hashCode()
	{
		int h = Kind.META_APPLICATION.ordinal() + metaVariable.hashCode();
		return h;
	}
}
