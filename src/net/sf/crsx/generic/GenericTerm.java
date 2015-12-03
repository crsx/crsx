/* Copyright (c) 2007,2010 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.Flushable;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Path;
import net.sf.crsx.Pattern;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Base class for terms used internally by {@link GenericBuffer}.
 * Extends plain terms with creation and mutation operations.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericTerm.java,v 3.8 2014/01/06 03:11:09 krisrose Exp $
 */
abstract public class GenericTerm implements Pattern, Contractum
{
	// Static.

	/** No terms. */
	static public final GenericTerm[] NO_TERMS =
		{};

	/** No binders. */
	static public final Variable[][] NO_BINDS =
		{};

	/** No binders. */
	static public final Variable[] NO_BIND =
		{};

	/** Symbol for (promiscuous) binders after $[C] matching. */
	static public final String BIND = "$B";

	/** Symbol for linear binders after $[C] matching. */
	static public final String BIND_LINEAR = "$BL";

	// State.

	/** Maker and factory. */
	final GenericFactory factory;

	// Constructor.

	/** Create term with factory. */
	protected GenericTerm(GenericFactory factory)
	{
		this.factory = factory;
	}

	// Methods.

	/**
	 * Return variant of the term with no properties.
	 * Destorys the term itself and shares all subterms (with any binders).
	 */
	public abstract GenericTerm stripProperties();

	/** Whether the term permits arity changes. */
	public boolean isFlexible()
	{
		return false;
	}

	/** Return binders for all subterms as array. */
	Variable[][] allBinders()
	{
		return NO_BINDS;
	}

	/** Return all subterms as array. */
	GenericTerm[] allSubs()
	{
		return NO_TERMS;
	}

	/** @return all free variables in this term */
	public Set<Variable> freeVariables()
	{
		return Util.freeVariables(this);
	}

	/**
	 * Insert an extra term with binders just before an existing subterm.
	 * (Override for terms that support it.)
	 * @param index 0-based index of existing subterm to insert before
	 * @param binders to insert (may be null for none)
	 * @param extra to insert
	 * @throws CRSException if the term is immutable
	 */
	public void insertSub(int index, Variable[] binders, GenericTerm extra) throws CRSException
	{
		throw new CRSException("No subterm " + index);
	}

	/**
	 * Add an extra term with binders to the end of the subterm list.
	 * (Override for terms that support it.)
	 * @param binders (may be null for none)
	 * @param extra
	 * @throws CRSException
	 */
	public void addSub(Variable[] binders, GenericTerm extra) throws CRSException
	{
		throw new CRSException("Cannot add extra term");
	}

	/**
	 * Remove the index'th binder/subterm pair.
	 * (Override for terms that support it.)
	 * @param index
	 * @throws CRSException
	 */
	public void deleteSub(int index) throws CRSException
	{
		throw new CRSException("No subterm " + index);
	}

	/**
	 * Set the index'th subterm (0-based) to replacement with binders (destructively).
	 * (Override for terms that support it.)
	 * @param index
	 * @param binders (may be null for none)
	 * @param replacement
	 */
	public void replaceSub(int index, Variable[] binders, GenericTerm replacement)
	{
		throw new IndexOutOfBoundsException("No subterm " + index);
	}

	/**
	 * Add extra subterms with binders to the end of the list of subterms and binders.
	 * (Naïve implementation based on {@link #insertSub(int, Variable[], GenericTerm)}.)
	 * @param index 0-based index of existing subterm to insert before
	 * @param extras
	 * @throws CRSException
	 */
	public void insertSubs(int index, List<Pair<Variable[], GenericTerm>> extras) throws CRSException
	{
		for (Pair<Variable[], GenericTerm> p : extras)
			insertSub(index++, p.head(), p.tail());
	}

	/**
	 * Add extra subterms with binders to the end of the list of subterms and binders.
	 * (Naïve implementation based on {@link #addSub(Variable[], GenericTerm)}.)
	 * @param extras
	 * @throws CRSException
	 */
	public void addSubs(List<Pair<Variable[], GenericTerm>> extras) throws CRSException
	{
		for (Pair<Variable[], GenericTerm> p : extras)
			addSub(p.head(), p.tail());
	}

	/**
	 * Remove multiple subterms (starting with the first and ending with the last, 0-based).
	 * (Naïve implementation based on {@link #deleteSub(int)}.)
	 * @param first
	 * @param last
	 * @throws CRSException
	 */
	public void deleteSubs(int first, int last) throws CRSException
	{
		for (int i = first; i <= last; ++i)
			deleteSub(first);
	}

	/**
	 * Replace sequence of children with another...
	 * (Naïve implementation based on the other mutation operations.)
	 * @param first
	 * @param last
	 * @param replacements
	 * @throws CRSException
	 */
	public void replaceSubs(int first, int last, List<Pair<Variable[], GenericTerm>> replacements) throws CRSException
	{
		int newLast = first + replacements.size() - 1;
		if (last <= newLast)
		{
			// replacements is longer - replace some, add some.
			for (int i = first; i <= last; ++i)
			{
				Pair<Variable[], GenericTerm> p = replacements.get(i - first);
				replaceSub(i, p.head(), p.tail());
			}
			for (int i = last + 1; i <= newLast; ++i)
			{
				Pair<Variable[], GenericTerm> p = replacements.get(i - first);
				addSub(p.head(), p.tail());
			}
		}
		else //last > newLast
		{
			// replacements is shorter - replace all then delete the rest
			for (Pair<Variable[], GenericTerm> p : replacements)
				replaceSub(first++, p.head(), p.tail());
			deleteSubs(newLast + 1, last);
		}
	}

	// Copyable...

	abstract public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames);

	// Stub...

	final public GenericFactory maker()
	{
		return factory;
	}

	abstract public Kind kind();

	public Constructor constructor()
	{
		return null;
	}

	public Variable variable()
	{
		return null;
	}

	public void setVariable(Variable v)
	{
		throw new UnsupportedOperationException();
	}

	public String metaVariable()
	{
		return null;
	}

	public int arity()
	{
		return 0;
	}

	abstract public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames);

	// Term...

	public Variable[] binders(int i)
	{
		throw new IndexOutOfBoundsException("no subterm " + i);
	}

	public GenericTerm sub(int i)
	{
		throw new IndexOutOfBoundsException("no subterm " + i);
	}

	public Sink replaceSubSink(int i)
	{
		throw new IndexOutOfBoundsException("no subterm " + i);
	}

	abstract public boolean equalsModulo(Term that, ExtensibleMap<Variable, Variable> renamings);

	final public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		FormattingAppendable f;
		if (writer instanceof FormattingAppendable)
			f = (FormattingAppendable) writer;
		else
		{
			int width = factory.defined("width") ? Integer.parseInt(factory.get("width").constructor().symbol()) : 120;
			int indentation = factory.defined("indent") ? Integer.parseInt(factory.get("indent").constructor().symbol()) : 0;
			int maxindentation = factory.defined(Factory.MAX_INDENT_LEVEL)
					? Integer.parseInt(factory.get(Factory.MAX_INDENT_LEVEL).constructor().symbol())
					: Integer.MAX_VALUE;
			f = FormattingAppendable.format(writer, width, indentation, maxindentation);
		}
		appendTermTo(
				f, used, factory.defined(GenericFactory.NO_LINEAR_VARIABLES), depth, false, factory.defined(Factory.SIMPLE_TERMS),
				!factory.defined(Factory.OMIT_PROPERTIES) && !factory.defined(Factory.OMIT_NAMED_PROPERTIES),
				!factory.defined(Factory.OMIT_PROPERTIES) && !factory.defined(Factory.OMIT_VARIABLE_PROPERTIES), omitProps,
				factory.defined(Factory.SORT_PROPERTIES));
		if (writer instanceof Flushable)
			((Flushable) writer).flush();
	}

	/**
	 * Helper to append a reparseable textual version of term to output.
	 * @param writer to write to
	 * @param used names already used for variables
	 * @param noLinear TODO
	 * @param depth remaining sublevels to print (or -1 for all)
	 * @param outer whether the term is an outermost list elemet
	 * @param full whether full term syntax should be used (omitting abbreviations)
	 * @param namedProps whether to include named properties in the output
	 * @param variableProps whether to include variable properties in the output
	 * @param omitProps specific variable properties to exclude
	 * @param sortProps TODO
	 * @throws IOException if the i/o fails
	 */
	abstract public void appendTermTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean outer, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException;

	public SortedSet<Path> paths(Path base)
	{
		SortedSet<Path> paths = new TreeSet<Path>();
		for (int i = 0; i < arity(); ++i)
			paths.add(base.extend(i));
		return paths;
	}

	// Pattern...

	public Unification unify(Pattern that, Set<Variable> contextvars) throws CRSException
	{

		//Build metavariable renamings
		Set<String> thismvars = this.mvars();
		Set<String> thatmvars = that.mvars();

		Set<String> mvars = new HashSet<String>(thismvars);
		mvars.addAll(thatmvars);

		Map<String, String> mvarrenamings = new HashMap<String, String>();
		for (String mvar : thismvars)
		{
			if (thatmvars.contains(mvar))
			{
				String newmvar = GenericUnification.makeMetaVar(mvar, mvars);
				mvarrenamings.put(mvar, newmvar);
			}
			else
			{
				mvarrenamings.put(mvar, mvar);
			}
		}

		//Build variable renamings
		Set<Variable> thisvars = new HashSet<Variable>();
		ExtensibleSet<Variable> thisbound = new LinkedExtensibleSet<Variable>();
		thisbound = thisbound.extend(contextvars);
		this.addFree(thisvars, thisbound, true, null);

		Set<Variable> thatvars = new HashSet<Variable>();
		ExtensibleSet<Variable> thatbound = new LinkedExtensibleSet<Variable>();//Always empty
		that.addFree(thatvars, thatbound, true, null);

		StackedMap<Variable> varrenamings = new StackedMap<Variable>();

		for (Variable var : thisvars)
		{
			if (thatvars.contains(var))
			{
				Variable newvar = this.maker().makeVariable(var.name(), false);
				varrenamings.put(var, newvar);
			}
			else
			{
				varrenamings.put(var, var);
			}
		}

		//Build pattern copies
		GenericTerm thiscopy = this.makeUnificationCopy(varrenamings, mvarrenamings);
		if (!(thiscopy instanceof PropertiesConstraintsWrapper))
		{
			String freshmvar = GenericUnification.makeMetaVar("freshcatchall", mvars);
			thiscopy = new PropertiesConstraintsWrapper(thiscopy, freshmvar, new HashMap<String, Term>(),
					new HashMap<Variable, Term>(), new HashMap<String, Term>());
			mvars.add(freshmvar);
			mvarrenamings.put(freshmvar, freshmvar);
		}
		GenericTerm thatcopy = ((GenericTerm) that).makeUnificationCopy(varrenamings, mvarrenamings);
		if (!(thatcopy instanceof PropertiesConstraintsWrapper))
		{
			String freshmvar = GenericUnification.makeMetaVar("freshcatchall", mvars);
			thatcopy = new PropertiesConstraintsWrapper(thatcopy, freshmvar, new HashMap<String, Term>(),
					new HashMap<Variable, Term>(), new HashMap<String, Term>());
			mvars.add(freshmvar);
			mvarrenamings.put(freshmvar, freshmvar);
		}

		//Generate variable mappings from context
		StackedMap<Variable> rho = new StackedMap<Variable>();
		for (Variable var : contextvars)
		{
			rho.put(var, this.factory.makeVariable(var.name(), false));
		}
		rho.pushscope();

		//Unify
		Unification us = thiscopy.unifyThese(
				new GenericUnification(thiscopy, thisbound, thatcopy), thatcopy, rho, new StackedMap<Variable>(), mvars);

		//Should probably return the unification
		//If so, apply renamings to unification before returning.
		return us;
	}

	/**
	 * Helper method for unification.
	 * @param unification current unification status
	 * @param that the pattern to unify against
	 * @param rho current environment of variables bound in first pattern, with associated fresh variables
	 * @param rhoprime current environment of variables bound in second patter, with associated fresh variables
	 * @param existingMVars the set of metavariables already occurring in either of the two patterns, and in their unification
	 * @return the final unification
	 */
	protected abstract Unification unifyThese(Unification unification, Pattern that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime, Set<String> existingMVars)
			throws CRSException;

	/**
	 * Occurs check for the metavariable mvar
	 * 
	 * @param mvar the name of the metavariable
	 * @param unification the current unification - any metavariable (!= mvar) encountered must be 
	 * substituted according to the getSubstitutePrime() method of unification. 
	 * 
	 * @return true if mvar occurs in the term (+ substitutions), false otherwise
	 */
	protected abstract boolean occurs(String mvar, Unification unification);

	/**
	 * Computes bitmasks and collects and occurrence of each metavariable.
	 * @param legalvars variables allowed to occur free
	 * @param rhoprime mapping of bound variables
	 * @param inscope variables in scope (bindings found in that). Initially empty.
	 * @param bitmasks bitmask map. Initially empty, but will be populated by the algorithm
	 * @param occurrences occurrence collection. Initially empty, but will be populated by algorithm
	 */
	protected abstract void generateBitmasks(Set<Variable> legalvars, StackedMap<Variable> rhoprime, StackedMap<Variable> inscope, Map<String, Boolean[]> bitmasks, Map<String, GenericMetaApplication> occurrences);

	/**
	 * Makes a new copy of this GenericTerm, while renaming free variables and metavariables.
	 * Primarily used before a unification attempt.
	 * @param varrenamings renamings of variables bound in the context. By convention, all variables
	 * 		  occurring in the two terms must be part of the keyset of varrenamings, and any variable not
	 * 		  needing renaming must map to itself. 
	 * @param mvarrenamings renamings of metavariables. By convention, all metavariables occurring in the two
	 * 		  terms must be part of the keyset of mvarrenamings, and any metavariable not needing renaming
	 * 		  must map to itself.
	 * @return a copy of this term
	 */
	public abstract GenericTerm makeUnificationCopy(StackedMap<Variable> varrenamings, Map<String, String> mvarrenamings);

	/**
	 * Applies all substitutes of a unification to the corresponding metaapplications in this object.
	 * Application is performed deeply, i.e., if the body of an introduced substitute contains a 
	 * metaapplication, and the metavariable of that metaapplication is bound to a substitute, that
	 * substitute is applied as well.
	 *  
	 * @param unification the unification
	 * @return a copy of this term, with metaapplications resolved.
	 */
	public abstract GenericTerm applySubstitutes(Unification unification);

	// Object...

	@Override
	final public String toString()
	{
		StringBuilder w = new StringBuilder();
		try
		{
			FormattingAppendable f = FormattingAppendable.format(w, Integer.MAX_VALUE, 0, Integer.MAX_VALUE);
			Map<Variable, String> variableNames = new HashMap<Variable, String>();
			appendTermTo(
					f, variableNames, factory.defined(GenericFactory.NO_LINEAR_VARIABLES), Integer.MAX_VALUE, false, false, true,
					true, new HashSet<Variable>(), false);
		}
		catch (IOException e)
		{
			return "Error: " + e;
		}
		return w.toString();
	}

	@Override
	final public boolean equals(Object other)
	{
		return this == other || (other instanceof Term && equalsModulo((Term) other, LinkedExtensibleMap.EMPTY_RENAMING));
	}

	@Override
	abstract public int hashCode();

	/**
	 * Create temporary variant of original term with just a name property change.
	 * @param name of property to set or unset
	 * @param value of property or null to remove the property
	 * @param reuse whether it is alright to reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to have property
	 */
	public GenericTerm wrapWithProperty(String name, Term value, boolean reuse)
	{
		try
		{
			if (this instanceof PropertiesConstraintsWrapper)
			{
				PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) this;
				pcw = new PropertiesConstraintsWrapper(pcw, reuse);
				pcw.setProperty(name, value);
				return pcw;
			}
			else if (this instanceof PropertiesHolder)
			{
				GenericTerm t = copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
				((PropertiesHolder) t).setProperty(name, value);
				return t;
			}
			else
			{
				Constructor c = Util.wrapWithProperty(factory, constructor(), name, value);
				return reconstruct(c, reuse);
			}
		}
		catch (CRSException e)
		{
			throw new RuntimeException("Property error ", e);
		}
	}

	static Term wrapWithNotProperty(String name, GenericTerm original, boolean reuse)
	{
		return original.wrapWithNotProperty(name, reuse);
	}

	/**
	 * Create temporary variant of original term with just an additional negated name property 
	 * @param name of property to negate
	 * @param reuse whether it is alright to reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to negate property
	 */
	public GenericTerm wrapWithNotProperty(String name, boolean reuse)
	{
		PropertiesConstraintsWrapper pcw = (this instanceof PropertiesConstraintsWrapper
				? new PropertiesConstraintsWrapper((PropertiesConstraintsWrapper) this, reuse)
				: new PropertiesConstraintsWrapper(this, null, null, null, null));
		pcw.setNotProperty(name);
		return pcw;
	}

	/**
	 * Create temporary variant of original term with just a variable property changed.
	 * @param name of property to set or unset
	 * @param value of property or null to remove the property
	 * @param reuse whether it is alright to reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to have property
	 */
	public GenericTerm wrapWithProperty(Variable variable, Term value, boolean reuse)
	{
		try
		{
			if (this instanceof PropertiesConstraintsWrapper)
			{
				PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) this;
				pcw = new PropertiesConstraintsWrapper(pcw, reuse);
				pcw.setProperty(variable, value);
				return pcw;
			}
			assert kind() == Kind.CONSTRUCTION;
			Constructor c = Util.wrapWithProperty(factory, constructor(), variable, value);
			return ((GenericTerm) this).reconstruct(c, reuse);
		}
		catch (CRSException e)
		{
			throw new RuntimeException("Property error ", e);
		}
	}

	/**
	 * Create temporary variant of original term with just a negated variable property added.
	 * @param variable to negate
	 * @param original term to create modified version of
	 * @param reuse whether it is alright to reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to have property
	 * @throws CRSException if property can't be set
	 */
	public GenericTerm wrapWithNotProperty(Variable variable, boolean reuse) throws CRSException
	{
		PropertiesConstraintsWrapper pcw = (this instanceof PropertiesConstraintsWrapper
				? new PropertiesConstraintsWrapper((PropertiesConstraintsWrapper) this, reuse)
				: new PropertiesConstraintsWrapper(this, null, null, null, null));
		pcw.setProperty(variable, null);
		return pcw;
	}

	/**
	 * Create variant of original term with just a meta property change.
	 * @param metaVar of property to set or unset
	 * @param value of property or null to remove the property
	 * @param reuse whether it is alright to reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to have property
	 */
	public GenericTerm wrapWithMetaProperty(String metaVar, Term value, boolean reuse)
	{
		if (this instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) this;
			pcw = new PropertiesConstraintsWrapper(pcw, reuse);
			if (value == null)
				pcw.removeMetaProperty(metaVar);
			else
				pcw.setMetaProperty(metaVar, value);
			return pcw;
		}
		if (value != null)
		{
			Map<String, Term> metaProps = new HashMap<String, Term>();
			metaProps.put(metaVar, value);
			return new PropertiesConstraintsWrapper(this, null, null, null, metaProps);
		}
		return null;
	}

	/**
	 * Create variant of original term with just a meta property exclusion.
	 * @param metaVar of property to explicitly make illegal
	 * @param reuse whether it is alright to reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to have property
	 */
	public GenericTerm wrapWithNotMetaProperty(String metaVar, boolean reuse)
	{
		if (this instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) this;
			pcw = new PropertiesConstraintsWrapper(pcw, reuse);
			pcw.setNotMetaProperty(metaVar);
			return pcw;
		}
		else
		{
			Map<String, Term> metaProps = new HashMap<String, Term>();
			metaProps.put(metaVar, null);
			return new PropertiesConstraintsWrapper(this, null, null, null, metaProps);
		}
	}

	/**
	 * Remove property.
	 * @param name property to remove
	 */
	public void removeProperty(String name)
	{}

	/**
	 * Remove property.
	 * @param variable property to remove
	 */
	public void removeProperty(Variable variable)
	{}

	/**
	 * Completely remove all traces of a meta property. 
	 * @param key to remove
	 */
	public void removeMetaProperty(String key)
	{}

	/**
	 * Create temporary variant of this term with just the properties reference changed.
	 * @param ref to replace with
	 * @param reuse whether it is permittedto reuse fragments of original (original itself is never modified)
	 * @return variant modified non-destructively to have property
	 */
	public GenericTerm wrapWithPropertiesRef(String ref, boolean reuse)
	{
		if (this instanceof PropertiesConstraintsWrapper && reuse)
		{
			((PropertiesConstraintsWrapper) this).setPropertiesRef(ref);
			return this;
		}
		else
			return new PropertiesConstraintsWrapper(this, ref, null, null, null);
	}

	/**
	 * Copy all properties (including meta-properties) from an 'extra' term onto this term.
	 * @param term to set properties on -- consumed by the call so should not be used further
	 * @param extra term with additional properties (null means none) -- also consumed by call!
	 * @return new term which is like original but includes all properties of extra
	 */
	public GenericTerm wrapWithPropertiesOf(Term extra) throws CRSException
	{
		if (extra == null)
		{
			return this;
		}
		else if (this instanceof PropertiesConstraintsWrapper) //sic
		{
			// term can already handle everything...
			((PropertiesConstraintsWrapper) this).setProperties(Util.propertiesHolder(extra));
			return this;
		}
		else if (extra instanceof PropertiesConstraintsWrapper)
		{
			// Got meta-properties...
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) extra;
			return new PropertiesConstraintsWrapper(this, pcw.propertiesRef, pcw.namedPropertyConstraints,
					pcw.variablePropertyConstraints, pcw.metaPropertyConstraints);
		}
		else if (kind() == Kind.CONSTRUCTION)
		{
			// No meta properties...add properties to constructor.
			return ((GenericTerm) this).reconstruct(Util.wrapWithProperties(factory, constructor(), Util.propertiesHolder(extra)),
					true);
		}
		else
		{
			// Term can't handle it...so just wrap.
			PropertiesConstraintsWrapper pcw = new PropertiesConstraintsWrapper(this, null, null, null, null);
			pcw.setProperties(Util.propertiesHolder(extra));
			return pcw;
		}
	}

	/**
	 * Helper to reconstruct construction with changed constructor.
	 * @param constructor new constructor to reconstruct with
	 * @param original term to create modified version of
	 * @param reuse whether it is alright to reuse fragments of original
	 * 		(original itself is never modified but if false then everything is copied)
	 */
	public GenericTerm reconstruct(Constructor constructor, boolean reuse)
	{
		if (reuse && this instanceof GenericTerm && factory instanceof GenericFactory)
		{
			GenericTerm old = (GenericTerm) this;
			return ((GenericFactory) factory).newConstruction(constructor, old.allBinders(), old.allSubs());
		}
		else
		{
			// Fall back to streaming...
			Buffer buffer = new Buffer(factory);
			Sink sink = buffer.sink();
			sink = sink.start(constructor);
			for (int i = 0; i < arity(); ++i)
			{
				if (reuse)
				{
					sink = sink.binds(binders(i));
					sink = sub(i).copy(sink, true, LinkedExtensibleMap.EMPTY_RENAMING);
				}
				else
				{
					final Variable[] oldBinders = binders(i);
					final int rank = oldBinders.length;
					final Variable[] newBinders = new Variable[rank];
					ExtensibleMap<Variable, Variable> renames = LinkedExtensibleMap.EMPTY_RENAMING;
					for (int j = 0; j < rank; ++j)
					{
						newBinders[j] = factory.makeVariable(
								oldBinders[j].name(), oldBinders[j].promiscuous(), oldBinders[j].blocking(),
								oldBinders[j].shallow());
						renames = renames.extend(oldBinders[j], newBinders[j]);
					}
					sink = sub(i).copy(sink, false, renames);
				}
			}
			sink = sink.end();
			assert sink == null;
			return (GenericTerm) buffer.term(true);
		}
	}

	/** Whether term contains a $-primitive   */
	public boolean hasEval()
	{
		HasPrimitive v = new HasPrimitive();
		try
		{
			visit(v, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (CRSException e)
		{}
		return v.hasPrimitive;
	}

	/** Whether term contains meta property key */
	public boolean hasMetaPropertyKey()
	{
		HasMetaPropertyKey v = new HasMetaPropertyKey();
		try
		{
			visit(v, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (CRSException e)
		{}
		return v.hasMeta;
	}

	/** Whether term contains a property reference */
	public boolean hasPropertyRef()
	{
		HasPropertyRef v = new HasPropertyRef();
		try
		{
			visit(v, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (CRSException e)
		{}
		return v.hasRef;
	}

	
	// Detect whether term contains a $ primitive  
	private static class HasPrimitive extends Visitor
	{
		// Whether the term has a primitive.
		boolean hasPrimitive;

		@Override
		public void visitPrimitive(Primitive primitive, boolean start) throws CRSException
		{
			hasPrimitive = true;
		}
	}

	// Detect whether term contains a Meta Property key  
	private static class HasMetaPropertyKey extends Visitor
	{
		// Whether the term has meta
		boolean hasMeta;

		@Override
		public void visitMetaProperty(String name, boolean start, boolean hasMapping) throws CRSException
		{
			hasMeta = true;
		}
	}
	

	// Detect whether term contains at least one property reference  
	private static class HasPropertyRef extends Visitor
	{
		// Whether the term has a property reference
		boolean hasRef;

		@Override
		public void visitPropertiesRef(String name, boolean start) throws CRSException
		{
			hasRef = true;
		}

	}

	/** Returns all metas occurring in this term */
	public void addMeta(final List<GenericMetaApplication> metas)
	{
		Visitor visitor = new Visitor()
			{
				@Override
				public void visitMetaApplication(Term metaApplication, boolean start, Set<Variable> bound) throws CRSException
				{
					if (start)
						metas.add((GenericMetaApplication) metaApplication);			
				}
			};
		try
		{
			visit(visitor, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (CRSException e)
		{}
	}

}
