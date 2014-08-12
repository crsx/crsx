/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.io.StringWriter;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Maker;
import net.sf.crsx.Match;
import net.sf.crsx.Path;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.EmptyIterable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SimpleVariableSet;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Plain implementation of constructor based on just an index
 * into the constant list of {@link GenericFactory}.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericIndexedConstructor.java,v 3.3 2013/12/05 03:28:28 krisrose Exp $
 */
final public class GenericIndexedConstructor implements Constructor
{
	// State.

	/** The factory with the symbols... */
	final GenericFactory factory;

	/** The constructor's index. */
	final public int index;

	// Constructor.

	/** Create constructor with specific symbol name and index. */
	public GenericIndexedConstructor(GenericFactory factory, int index)
	{
		this.factory = factory;
		this.index = index;
	}

	// Constructor implementation...

	public String symbol()
	{
		return factory.constantSymbol(index);
	}

	public String literalSort()
	{
		return null;
	}

	public String object()
	{
		return symbol();
	}
	
	@Override
	public boolean isClosure()
	{
		return false;
	}

	public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		return that != null
				&& (that instanceof GenericIndexedConstructor
						? index == ((GenericIndexedConstructor) that).index
						: symbol().equals(that.symbol()));
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{}

	public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		return this;
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		return true;
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound)
	{}

	public Constructor oldunify(ExtensibleMap<Variable, Variable> thisBound, Map<Variable, Variable> thisBaseVariable, Map<String, String> thisBaseMeta, Constructor that, ExtensibleMap<Variable, Variable> thatBound, Map<Variable, Variable> thatBaseVariable, Map<String, String> thatBaseMeta, Match unifyMatch, ExtensibleMap<Variable, Variable> unifyBound, Map<String, List<Pair<ExtensibleMap<Variable, Variable>, Term>>> unifiedMatched)
	{
		return (equals(that) ? this : null);
	}

	public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
	{
		return (equals(that) ? this : null);
	}

	public Constructor copy(ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	public void normalize(CRS crs) throws CRSException
	{}

	public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps)
			throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		writer.append(literalSort() != null ? Util.quoteJava(symbol()) : Util.externalizeConstructor(symbol()));
	}

	final public SortedSet<Path> paths(Path base)
	{
		return new TreeSet<Path>();
	}

	public void javaInvokeStart(SourceBuilder java, String sinkName, Map<Variable, String> variable2java)
	{
		if (!java.seeded())
			java.seedExpression(sinkName);
		java.wrapExpression("", ".start(" + sinkName + ".makeConstructor(" + Util.quoteJava(symbol()) + "))");
	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		return new EmptyIterable<String>();
	}

	public Term getProperty(String name)
	{
		return null;
	}

	public Iterable<Variable> propertyVariables()
	{
		return new EmptyIterable<Variable>();
	}

	public Term getProperty(Variable variable)
	{
		return null;
	}

	public boolean canSetProperty(String name)
	{
		return false;
	}

	public boolean canSetProperty(Variable variable)
	{
		return false;
	}

	public void setProperty(String name, Term value)
	{}

	public void setProperty(Variable variable, Term value)
	{}

	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		for (String name : properties.propertyNames())
			setProperty(name, properties.getProperty(name));
		for (Variable variable : properties.propertyVariables())
			setProperty(variable, properties.getProperty(variable));
	}

	@Override
	public void removeProperty(Variable variable) throws CRSException
	{}

	public boolean isMeta()
	{
		return false;
	}

	// Object...

	public boolean equals(Object that)
	{
		return that != null && match(null, (Constructor) that, SimpleVariableSet.EMPTY, null, true, SimpleVariableSet.EMPTY, null);
	}

	public int hashCode()
	{
		return index;
	}

	public Constructor baseConstructor()
	{
		return this;
	}

	public String toString()
	{
		StringWriter w = new StringWriter();
		try
		{
			appendTo(
					w, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, true, true,
					LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (IOException e)
		{}
		return w.toString();
	}
}
