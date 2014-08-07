/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.StringWriter;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Maker;
import net.sf.crsx.Match;
import net.sf.crsx.Path;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;

/**
 * Constructor that delegates all operations!
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegateConstructor.java,v 3.3 2013/12/05 03:28:30 krisrose Exp $
 */
public abstract class DelegateConstructor implements Constructor
{
	/** Constructor to delegate to. */
	final protected Constructor constructor;

	/**
	 * Create delegate.
	 * @param constructor to delegate to.
	 */
	public DelegateConstructor(Constructor constructor)
	{
		this.constructor = constructor;
	}

	// Constructor...

	// @see net.sf.crsx.Constructor#symbol()
	public String symbol()
	{
		return constructor.symbol();
	}

	// @see net.sf.crsx.Constructor#literalSort()
    public String literalSort()
    {
    	return constructor.literalSort();
    }

	// @see net.sf.crsx.Constructor#object()
	public Object object()
	{
		return constructor.object();
	}

	// @see net.sf.crsx.Constructor#match(net.sf.crsx.Match, net.sf.crsx.Constructor, net.sf.crsx.util.ExtensibleMap)
	public boolean match(Match match, Constructor other, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		return constructor.match(match, other, bound, contractionCount, promiscuous, once, onceSeen);
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		return constructor.checkFree(forbidden, once, onceSeen, promiscuous, bound);
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		constructor.addFree(set, bound, includemetaapps, base);
	}

	public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		return constructor.subsubstitute(maker, valuation, renamings, substitution, bound, possible);
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		constructor.visit(visitor, bound);
	}

	public Constructor unify(Unification unification, Constructor that,
			StackedMap<Variable> rho,
			StackedMap<Variable> rhoprime) {
    	return constructor.unify(unification, that, rho, rhoprime);
	}

	// @see net.sf.crsx.Constructor#copy(net.sf.crsx.util.ExtensibleMap)
	public Constructor copy(ExtensibleMap<Variable, Variable> renamings)
	{
		return constructor.copy(renamings);
	}

	public void normalize(CRS crs) throws CRSException
	{
		constructor.normalize(crs);
	}

	// @see net.sf.crsx.Constructor#contract(net.sf.crsx.Valuation, net.sf.crsx.util.ExtensibleMap)
	public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		assert constructor != this;
		return constructor.contract(valuation, renamings);
	}

	// @see net.sf.crsx.Constructor#appendTo(java.lang.Appendable)
	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException
	{
		constructor.appendTo(writer, used, depth-1, full, namedProps, variableProps, omitProps);
	}

	/* @see net.sf.crsx.Constructor#paths(net.sf.crsx.Path)*/
	public SortedSet<Path> paths(Path base)
	{
		return constructor.paths(base);
	}

	// @see net.sf.crsx.Constructor#javaInvokeStart(net.sf.crsx.BlockBuilder, java.lang.String)
	public void javaInvokeStart(SourceBuilder code, String sinkName, Map<Variable, String> variable2java)
	{
		constructor.javaInvokeStart(code, sinkName, variable2java);
	}

	public Constructor baseConstructor()
	{
		return constructor.baseConstructor();
	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		return constructor.propertyNames();
	}

	public Term getProperty(String name)
	{
		return constructor.getProperty(name);
	}

	public Iterable<Variable> propertyVariables()
	{
		return constructor.propertyVariables();
	}

	public Term getProperty(Variable variable)
	{
		return constructor.getProperty(variable);
	}

	public boolean canSetProperty(String name)
	{
		return constructor.canSetProperty(name);
	}
	
	public boolean canSetProperty(Variable variable)
	{
		return constructor.canSetProperty(variable);
	}
	
	public void setProperty(String name, Term value) throws CRSException
	{
		constructor.setProperty(name, value);
	}
	
	public void setProperty(Variable variable, Term value) throws CRSException
	{
		constructor.setProperty(variable, value);
	}
	
	public boolean isMeta()
	{
		return constructor.isMeta();
	}

	// Object...

	public boolean equals(Object that)
	{
		return constructor.equals(that);
	}

	public int hashCode()
	{
		return constructor.hashCode();
	}

	public String toString()
	{
		StringWriter w = new StringWriter();
		try
		{
			appendTo(w, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, false, false, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (IOException e)
		{}
		return w.toString();
	}
}
