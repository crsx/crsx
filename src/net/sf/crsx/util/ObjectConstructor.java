/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.util.Collection;
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

/**
 * Plain implementation of non-literal constructor based on immutable object.
 * Symbol calls the object's toString() method.
 * The object is supposed to be <em>immutable</em>.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: ObjectConstructor.java,v 3.3 2013/12/05 03:28:30 krisrose Exp $
 */
final public class ObjectConstructor implements Constructor
{
	// State.

	/** The constructor object.toString(). */
	final private Object object;
	
	// Constructor.

	/**
	 * Create constructor for an object.
	 * @param object of the constructor -
	 *      <em>must</em> be immutable,
	 *      <em>must</em> satisfy the {@link Object#hashCode()} contract,
	 * 		<em>should</em> have a meaningful {@link Object#toString()} method, and
	 *     <em>should</em> be immutable.
	 */
	public ObjectConstructor(Object object)
	{
		this.object = object;
	}
	
	// Constructor...

	public String symbol()
	{
		return object.toString();
	}

	public String literalSort()
	{
		return null;
	}

	public Object object()
	{
		return object;
	}

	public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		if (that instanceof PropertiesConstructor)
			that = ((PropertiesConstructor) that).constructor;
		return that instanceof ObjectConstructor && ((ObjectConstructor) that).object.equals(object);
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

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound)
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
		writer.append(object.toString());
	}

	final public SortedSet<Path> paths(Path base)
	{
		return new TreeSet<Path>();
	}

	public void javaInvokeStart(SourceBuilder java, String sinkName, Map<Variable, String> variable2java)
	{
		if (!java.seeded()) java.seedExpression(sinkName);
		java.wrapExpression("", ".start(" + sinkName + ".makeConstructor(" + Util.quoteJava(object.toString()) + "))");
	}

	public Constructor baseConstructor()
	{
		return this;
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

	@Override
	public void removeProperty(Variable variable) throws CRSException
	{}

	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		for (String name : properties.propertyNames())
			setProperty(name, properties.getProperty(name));
		for (Variable variable : properties.propertyVariables())
			setProperty(variable, properties.getProperty(variable));
	}

	public boolean isMeta()
	{
		return false;
	}

	// Object...

	public boolean equals(Object that)
	{
		return that != null && that instanceof ObjectConstructor && ((ObjectConstructor) that).object.equals(object);
	}

	public int hashCode()
	{
		return object.hashCode();
	}

	public String toString()
	{
		return Util.externalizeConstructor(object.toString());
	}
}
