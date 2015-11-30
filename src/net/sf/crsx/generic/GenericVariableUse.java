/* Copyright (c) 2007,2013 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.Collection;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Contractum;
import net.sf.crsx.Kind;
import net.sf.crsx.Match;
import net.sf.crsx.MetaAnalyzer;
import net.sf.crsx.Pattern;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.EmptyIterable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Generic implementation of <em>variable occurrence</em> terms used internally by {@link GenericBuffer}.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericVariableUse.java,v 3.10 2014/01/06 03:11:09 krisrose Exp $
 */
public class GenericVariableUse extends GenericTerm implements Visitor.VariableUpdater, PropertiesHolder
{
	// State.

	/** The occurring variable. */
	Variable variable;

	/** The properties. */
	PropertiesWrapperConstructor properties = null;

	// Constructor.

	/**
	 * Create variable occurrence.
	 * @param factory to use
	 * @param variable to reference
	 * @param properties for the variable use
	 */
	public GenericVariableUse(GenericFactory factory, Variable variable, PropertiesWrapperConstructor properties)
	{
		super(factory);
		assert variable != null : "Variable occurrence cannot have null variable";
		this.variable = variable;
		this.properties = properties;
	}

	// Methods.

	void addProperties(PropertiesWrapperConstructor pcw)
	{
		if (properties == null)
			properties = pcw;
		else
		{
			properties.namedPropertyConstraints.putAll(pcw.namedPropertyConstraints);
			properties.variablePropertyConstraints.putAll(pcw.variablePropertyConstraints);
			properties.metaPropertyConstraints.putAll(pcw.metaPropertyConstraints);
		}
	}

	// GenericTerm...

	@Override
	public GenericTerm stripProperties()
	{
		properties = null;
		return this;
	}

	// GenericTerm+.Visitor.VariableUpdater...

	@Override
	final public void setVariable(Variable v)
	{
		variable = v;
	}

	private void setupProperties()
	{
		if (properties == null)
		{
			properties = new PropertiesWrapperConstructor(null, null, null, null);
		}
	}

	// Copyable...

	@Override
	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		Variable v = (renames == null ? null : renames.get(variable));
		if (properties != null)
			sink = sink.start(properties);
		if (v == null)
		{
			if (factory.verbosity() > 9)
				factory.message("VARIABLE " + variable + " REFERENCE");
			sink = sink.use(variable);
		}
		else
		{
			if (factory.verbosity() > 9)
				factory.message("VARIABLE " + v + " COPIED AS " + v);
			sink = sink.use(v);
		}
		if (properties != null)
			sink = sink.end();
		return sink;
	}

	// Stub...

	@Override
	final public Kind kind()
	{
		return Kind.VARIABLE_USE;
	}

	@Override
	final public Variable variable()
	{
		return variable;
	}

	@Override
	public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		if (renames == null)
			renames = LinkedExtensibleMap.EMPTY_RENAMING;
		if (discard && renames.isEmpty())
		{
			if (factory.verbosity() > 9)
				factory.message("VARIABLE " + variable + " REUSED");
			return this;
		}

		Variable v = renames.get(variable);
		if (v == null)
		{
			if (factory.verbosity() > 9)
				factory.message("VARIABLE " + variable + " REFERENCE");
			return factory.newVariableUse(variable);
		}
		else
		{
			if (factory.verbosity() > 9)
				factory.message("VARIABLE " + v + " COPIED AS " + v);
			return factory.newVariableUse(v);
		}
	}

	// Term...

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		if (forbidden.contains(variable) || onceSeen.contains(variable))
			return false;
		if (once.contains(variable))
			onceSeen.add(variable);
		if (promiscuous)
			return (bound.contains(variable) || variable.promiscuous());
		return true;
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		if (!bound.contains(variable) && (base == null || base.contains(variable)))
			set.add(variable); // TODO: reports all variables regardless of sort
	}

	public void addMetaCounts(Map<String, Integer> counts)
	{}

	final public void analyzeMetaUseContractum(Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
	{}

	final public void analyzeMetaUsePattern(Map<String, Integer> counts)
	{}

	public Sink subsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		Variable v = bound.get(variable);
		if (v != null)
		{
			if (factory.verbosity() >= 6)
				factory.message("VARIABLE " + variable + " RENAMED TO " + v);
			return sink.use(v); // locally bound variable mapped to new definition
		}

		Contractum subContractum = substitution.get(variable);
		if (subContractum == null)
		{
			if (factory.verbosity() >= 6)
				factory.message("VARIABLE " + variable + " UNCHANGED");
			return sink.use(variable); // free variable just copied
		}

		if (!variable.promiscuous())
			possible.remove(variable); // used to switch to copying

		// ENTRY POINT to Contractum.contract().
		return subContractum.contract(sink, valuation, renamings);
	}

	public Sink staticSubsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		Variable v = bound.get(variable);
		if (v != null)
		{
			if (factory.verbosity() >= 6)
				factory.message("VARIABLE " + variable + " RENAMED TO " + v);
			return sink.use(v); // locally bound variable mapped to new definition
		}

		Contractum subContractum = substitution.get(variable);
		if (subContractum == null)
		{
			if (factory.verbosity() >= 6)
				factory.message("VARIABLE " + variable + " UNCHANGED");
			return sink.use(variable); // free variable just copied
		}

		if (!variable.promiscuous())
			possible.remove(variable); // used to switch to copying

		return subContractum.staticContract(sink, valuation, renamings);
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		visitor.visitUse(this, true, bound);
		if (bound.contains(variable))
			visitor.visitBound(variable, this);
		else
			visitor.visitFree(variable, this);
		visitor.visitUse(this, false, bound);
	}

	public void appendTermTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean outer, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		if (properties != null)
			properties.appendTo(writer, used, depth, full, namedProps, variableProps, omitProps, sortProps);
		if (variable == null)
			writer.append("null");
		else
			writer.append(Util.safeVariableName(variable, used, factory.defined(GenericFactory.NO_LINEAR_VARIABLES), false));
	}

	public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
	{
		sink = sink.start(sink.makeConstructor(CRS.REIFY_VARIABLE_USE));
		sink = sink.use(variable);
		sink = sink.end();
		return sink;
	}

	public boolean equalsModulo(Term that, ExtensibleMap<Variable, Variable> renamings)
	{
		if (that.kind() != Kind.VARIABLE_USE)
			return false;
		Variable mapped = renamings.get(variable);
		return (mapped != null ? mapped : variable).equals(that.variable());
	}

	// Pattern...

	public boolean match(Match match, Term term, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		if (term.kind() != Kind.VARIABLE_USE)
			return false;
		Variable v = match.getVariable(variable); // find if previously matched with variable
		if (v == null)
		{
			// Previously unmatched (locally free) variable - just record it if promiscuity is alright...
			v = term.variable();
			if (!variable.promiscuous() && v.promiscuous())
				return false;
			match.putVariable(variable, v);
		}
		else
		{
			// Previously matched variable
			if (!v.equals(term.variable()))
				return false; // fail because it was previously matched differently
			//            if (once.contains(v))
			//            {
			//                if (onceSeen.contains(v))
			//                    return false; // fail because it must be linear and was already seen
			//                else
			//                    onceSeen.add(v); // just record that linear has now been seen
			//            }
		}
		return true;
	}

	@Override
	protected Unification unifyThese(Unification unification, Pattern that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime, Set<String> existingMVars)
			throws CRSException
	{

		switch (that.kind())
		{

			case CONSTRUCTION : {
				//Variables and constructions do not unify, except if construction is a GenericEvaluator
				if (that instanceof GenericEvaluator)
				{
					return ((GenericEvaluator) that).unifyThese(unification, this, rhoprime, rho, existingMVars);
				}
				return null;
			}
			//Let metaaplication take care of stuff.
			//Switch order of arguments and results.
			case META_APPLICATION : {
				return ((GenericTerm) that).unifyThese(unification, this, rhoprime, rho, existingMVars);
			}
			//Variables
			case VARIABLE_USE : {
				Variable thisbound = rho.get(this.variable());
				Variable thatbound = rhoprime.get(that.variable());

				if (thisbound != null && thatbound != null)
				{
					if (thisbound.equals(thatbound))
					{
						//Both variables are bound inside pattern, and their binding occurrences match. 
						//Unification succeeds, with no more associations added
						return unification;
					}
					else
					{
						//Binding occurrences do not match. Unification fails.
						return null;
					}
				}
				else if (thisbound != null && thatbound == null)
				{
					Variable thatfree = unification.getVariable(that.variable());
					if (thatfree != null && thatfree.equals(thisbound))
					{
						//Free variable seen before, and matches this bound variable. Unify with no further action
						return unification;
					}
					else if (thatfree == null && !rhoprime.containsValue(thisbound))
					{
						//free variable not seen before, and bound variable does not match other bound variable
						//Unification succeeds. Update phi
						unification.putVariable(that.variable(), thisbound);
						return unification;
					}
					else
					{
						//Unification fails
						return null;
					}
				}
				else if (thisbound == null && thatbound != null)
				{
					//Similar to the above
					Variable thisfree = unification.getVariable(this.variable());
					if (thisfree != null && thisfree.equals(thatbound))
					{
						//Free variable seen before, and matches this bound variable. Unify with no further action
						return unification;
					}
					else if (thisfree == null && !rho.containsValue(thatbound))
					{
						//free variable not seen before, and bound variable does not match other bound variable
						//Unification succeeds. Update phi
						unification.putVariable(this.variable(), thatbound);
						return unification;
					}
					else
					{
						//Unification fails
						return null;
					}
				}
				else
				{
					//thisbound == thatbound == null
					Variable thisfree = unification.getVariable(this.variable());
					Variable thatfree = unification.getVariable(that.variable());
					if (thisfree != null && thatfree != null)
					{
						//both variables seen free before.
						if (thisfree.equals(thatfree))
						{
							//variables unified with each other before. Unify without changes
							return unification;
						}
						else if (!rhoprime.containsValue(thisfree) && !rho.containsValue(thatfree))
						{
							//variables unified with different free variables before.
							//map previous unification variables to new fresh variable
							Variable freshvar = this.maker().makeVariable(thisfree.name() + thatfree.name(), false);
							unification.putVariable(thisfree, freshvar);
							unification.putVariable(thatfree, freshvar);
							return unification;
						}
						else
						{
							//Variables seen before, but do not match each other. Unification fails.
							return null;
						}
					}
					else if (thisfree != null && thatfree == null)
					{
						//this variable seen before, 
						if (!rhoprime.containsValue(thisfree))
						{
							//Matched against a free variable. Update phi with binding of that to thisfree
							unification.putVariable(that.variable(), thisfree);
							return unification;
						}
						else
						{
							//Matched against bound variable. Unification fails.
							return null;
						}
					}
					else if (thisfree == null && thatfree != null)
					{
						//Similar to previous case
						if (!rho.containsValue(thatfree))
						{
							unification.putVariable(this.variable(), thatfree);
							return unification;
						}
						else
						{
							return null;
						}
					}
					else
					{
						//thisfree == thatfree == null
						//Neither variable seen before. Match towards fresh variable
						Variable freshvar = this.maker().makeVariable(this.variable().name() + that.variable().name(), false);
						unification.putVariable(this.variable(), freshvar);
						unification.putVariable(that.variable(), freshvar);
						return unification;
					}
				}
			}
		}
		assert false : "Control fell through unifyThese in GenericVariableUse";
		return null;
	}

	@Override
	protected void generateBitmasks(Set<Variable> legalvars, StackedMap<Variable> rhoprime, StackedMap<Variable> inscope, Map<String, Boolean[]> bitmasks, Map<String, GenericMetaApplication> occurrences)
	{
		//Nothing to check
	}

	// Contractum...

	public Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		Variable v = renamings.get(variable); // matched bound variable?
		if (v == null)
		{
			v = valuation.getVariable(variable); // matched free variable?
			if (factory.verbosity() >= 6)
				factory.message("VARIABLE " + variable + " REPLACED BY " + v);
		}
		if (v == null)
		{
			v = variable;
			if (factory.verbosity() >= 6)
				factory.message("VARIABLE " + variable);
		}
		return sink.use(v);
	}

	public Sink staticContract(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings)
	{
		return null;
		//return contract(sink, valuation, renamings);
	}


	@Override
	protected boolean occurs(String mvar, Unification unification)
	{
		return false;
	}

	public Set<String> mvars()
	{
		//No metavariables
		return new HashSet<String>();
	}

	@Override
	public GenericTerm makeUnificationCopy(StackedMap<Variable> varrenamings, Map<String, String> mvarrenamings)
	{
		Variable v = varrenamings.get(this.variable());
		return factory.newVariableUse(v != null ? v : this.variable());
	}

	@Override
	public GenericTerm applySubstitutes(Unification unification)
	{
		return ((GenericTerm) this.copy(false, LinkedExtensibleMap.EMPTY_RENAMING));
	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		return properties == null ? new EmptyIterable<String>() : properties.propertyNames();
	}

	public Term getProperty(String name)
	{
		return properties == null ? null : properties.getProperty(name);
	}

	public Iterable<Variable> propertyVariables()
	{
		return properties == null ? new EmptyIterable<Variable>() : properties.propertyVariables();
	}

	public Term getProperty(Variable variable)
	{
		return properties == null ? null : properties.getProperty(variable);
	}

	public boolean canSetProperty(String name)
	{
		return properties == null ? true : properties.canSetProperty(name);
	}

	public boolean canSetProperty(Variable variable)
	{
		return properties == null ? true : properties.canSetProperty(variable);
	}

	public void setProperty(String name, Term value) throws CRSException
	{
		setupProperties();
		properties.setProperty(name, value);
	}

	public void setProperty(Variable variable, Term value) throws CRSException
	{
		setupProperties();
		properties.setProperty(variable, value);
	}

	public void setProperties(PropertiesHolder props) throws CRSException
	{
		setupProperties();
		properties.setProperties(props);
	}

	public boolean isMeta()
	{
		return properties == null ? false : properties.isMeta();
	}

	// Object...

	@Override
	public int hashCode()
	{
		int h = Kind.VARIABLE_USE.ordinal();
		return h;
	}
}
