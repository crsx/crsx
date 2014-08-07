/* Copyright (c) 2012 IBM Corporation. */

package net.sf.crsx.util;

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

/**
 * Plain implementation of constructor based on just a long integer.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: AbstractLiteralConstructor.java,v 3.3 2013/12/05 03:28:30 krisrose Exp $
 */
public abstract class AbstractLiteralConstructor implements Constructor
{
	// Constructor...
	
	abstract public Object object();
	
	abstract public String literalSort();
	
	public String symbol()
	{
		return object().toString();
	}
	
	public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		if (that instanceof PropertiesConstructor)
			that = ((PropertiesConstructor) that).constructor;
		return literalSort().equals(that.literalSort()) && symbol().equals(that.symbol());
	}
	
	final public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{}
	
	final public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		return this;
	}
	
	final public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
    {
        return true;
    }
    
	final public Constructor oldunify(ExtensibleMap<Variable,Variable> thisBound, Map<Variable, Variable> thisBaseVariable, Map<String, String> thisBaseMeta, Constructor that, ExtensibleMap<Variable, Variable> thatBound, Map<Variable, Variable> thatBaseVariable, Map<String, String> thatBaseMeta, Match unifyMatch, ExtensibleMap<Variable, Variable> unifyBound, Map<String, List<Pair<ExtensibleMap<Variable, Variable>, Term>>> unifiedMatched)
    {
        return (equals(that) ? this : null);
    }

	final public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
	{
        return (equals(that) ? this : null);
	}

	final public Constructor copy(ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	final public void normalize(CRS crs) throws CRSException
	{}

	final public void visit(Visitor visitor, ExtensibleSet<Variable> bound)
	{}

	final public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	final public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		writer.append(CRS.STRING_SORT.equals(literalSort()) ? Util.quoteJava(symbol()) : symbol());
	}

	final public SortedSet<Path> paths(Path base)
	{
		return new TreeSet<Path>();
	}

	public void javaInvokeStart(SourceBuilder java, String sinkName, Map<Variable, String> variable2java)
	{
		java.wrapExpression("", ".start(" + sinkName + ".makeLiteral(" + Util.quoteJava(symbol()) + "," + Util.quoteJava(literalSort()) + "))");
	}

	final public Constructor baseConstructor()
	{
		return this;
	}

	// PropertiesHolder...

	final public Iterable<String> propertyNames()
	{
		return new EmptyIterable<String>();
	}

	final public Term getProperty(String name)
	{
		return null;
	}

	final public Iterable<Variable> propertyVariables()
	{
		return new EmptyIterable<Variable>();
	}

	final public Term getProperty(Variable variable)
	{
		return null;
	}

	final public boolean canSetProperty(String name)
	{
		return false;
	}
	
	final public boolean canSetProperty(Variable variable)
	{
		return false;
	}
	
	final public void setProperty(String name, Term value)
	{}
	
	final public void setProperty(Variable variable, Term value)
	{}

	final public void setProperties(PropertiesHolder properties) throws CRSException
	{
		for (String name : properties.propertyNames())
			setProperty(name, properties.getProperty(name));
		for (Variable variable : properties.propertyVariables())
			setProperty(variable, properties.getProperty(variable));
	}

	final public boolean isMeta()
	{
		return false;
	}

	// Object...

	public boolean equals(Object that)
	{
		return that != null && that instanceof Constructor && symbol().equals(((Constructor) that).symbol());
	}

	public int hashCode()
	{
		return object().hashCode();
	}

	final public String toString()
	{
		StringWriter w = new StringWriter();
		try
		{
			appendTo(w, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, true, true, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (IOException e)
		{}
		return w.toString();
	}
}
