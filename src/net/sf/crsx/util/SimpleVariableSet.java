/* Copyright (c) 2006, 2007 IBM Corporation. */

package net.sf.crsx.util;

import java.lang.reflect.Array;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;

import net.sf.crsx.Variable;

/**
 * Plain Immutable collection of CRS variables, extended with direct variable lookup method.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SimpleVariableSet.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class SimpleVariableSet implements ExtensibleSet<Variable>
{
	// Constants.
	
	/** Non-null empty. */
	public final static SimpleVariableSet EMPTY = new SimpleVariableSet(null, new Variable[0]);

    /** Create set based on collection. */
    public static SimpleVariableSet make(Collection<Variable> collection)
    {
        if (collection == null)
            return SimpleVariableSet.EMPTY;
        else if (collection instanceof SimpleVariableSet)
            return (SimpleVariableSet) collection;
        else
            return new SimpleVariableSet(null, collection.toArray(new Variable[collection.size()]));
    }


    /** Create set based on variable array. */
    public static SimpleVariableSet make(Variable[] binders)
    {
        return new SimpleVariableSet(null, binders);
    }

    
	// State.
	
	/** Parent in set. */
	final private SimpleVariableSet parent;
	
	/** Variables added in this to parent list. */
	final private Variable[] variables;
	
	// Constructor.
	
	/** Create link. */
	private SimpleVariableSet(SimpleVariableSet parent, Variable[] variable)
	{
		this.parent = parent;
		this.variables = variable;
	}

	// Methods.
	
	/** Lookup a particular variable by name. */
	public Variable lookup(String variableName)
	{
		SimpleVariableSet set = this;
		for (; set != null; set = set.parent)
			for (Variable v : set.variables)
				if (v.name().equals(variableName))
					return v;
		return null;
	}
	
	/** Return proper map from variable names to variables. */
	public Map<String, Variable> toMap()
	{
		Map<String, Variable> map = new HashMap<String, Variable>();
		for (Variable v : this)
			map.put(v.name(), v);
		return map;
	}
	
	// CRS.VariableSet...

	public SimpleVariableSet extend(Variable[] variables)
	{
		return (variables == null || variables.length == 0 ? this : new SimpleVariableSet(this, variables));
	}
	
	public SimpleVariableSet extend(Variable variable)
	{
		Variable[] vs = {variable};
		return new SimpleVariableSet(this, vs);
	}
	
	public SimpleVariableSet extend(Collection<Variable> collection)
	{
		Variable[] vs = new Variable[collection.size()];
		collection.toArray(vs);
		return extend(vs);
	}

	// Set<CRS.Variable>...

	public int size()
    {
    	SimpleVariableSet set = this;
		int z = 0;
		for (; set != null; set = set.parent)
			z += set.variables.length;
		return z;
    }

    public boolean isEmpty()
    {
    	SimpleVariableSet set = this;
		for (; set != null; set = set.parent)
			if (set.variables.length > 0)
				return false;
		return true;
    }

    public boolean contains(Object o)
    {
		for (SimpleVariableSet set = this; set != null; set = set.parent)
			for (Variable v : set.variables)
				if (v.equals(o))
					return true;
		return false;
    }

    public Iterator<Variable> iterator()
    {
    	return new Iterator<Variable>()
    	{
    		int index = 0;
    		SimpleVariableSet set = SimpleVariableSet.this;
			public boolean hasNext()
			{
				while (set != null)
				{
					if (index < set.variables.length)
						return true;
					set = set.parent;
					index = 0;
				}
				return false;
			}
			public Variable next()
			{
				if (hasNext())
					return set.variables[index++];
				throw new NoSuchElementException();
			}
			public void remove()
			{
				throw new UnsupportedOperationException();
			}
    	};
    }

    public Object[] toArray()
    {
    	SimpleVariableSet set = this;
		Variable[] array = new Variable[size()];
		int index = 0;
		for (; set != null; set = set.parent)
			for (Variable v : set.variables)
				array[index++] = v;
		return array;
    }

	@SuppressWarnings("unchecked")
	public <S> S[] toArray(S[] array)
    {
		Class<?> arrayClass = array.getClass();
		Class<?> arrayComponentClass = arrayClass.getComponentType();
		if (!(arrayComponentClass.isAssignableFrom(Variable.class)))
			throw new ArrayStoreException();

    	final int z = size();
    	if (array.length < z)
    		array = (S[]) Array.newInstance(arrayClass, z);

    	int index = 0;
    	for (SimpleVariableSet set = this; set != null; set = set.parent)
    		for (Variable v : set.variables)
    			array[index++] = (S) v;
    	return array;
    }
    
    public boolean add(Variable v)
    {
    	throw new UnsupportedOperationException();
    }

    public boolean remove(Object o)
    {
    	throw new UnsupportedOperationException();
    }

    public boolean containsAll(Collection<?> c)
    {
    	for (Object o : c)
    		if (!contains(o))
    			return false;
    	return true;
    }

    public boolean addAll(Collection<? extends Variable> c)
    {
    	throw new UnsupportedOperationException();
    }

    public boolean retainAll(Collection<?> c)
    {
    	throw new UnsupportedOperationException();
    }

    public boolean removeAll(Collection<?> c)
    {
    	throw new UnsupportedOperationException();
    }

    public void clear()
    {
    	throw new UnsupportedOperationException();
    }

    public boolean equals(Object o)
    {
    	Set<?> other = (Set<?>) o;
    	return (size() == other.size() && containsAll(other));
    }

    public int hashCode()
    {
    	int hash = 0;
    	for (SimpleVariableSet set = this; set != null; set = set.parent)
    		for (Variable v : set.variables)
    			hash += (v == null ? 0 : v.hashCode());
    	return hash;
    }

	// Object overrides.

	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		boolean following = false;
		for (SimpleVariableSet link = this; link != null; link = link.parent)
		{
			for (Variable v : link.variables)
			{
				if (following)
					sb.append(",");
				else
					following = true;
				sb.append(v.name());
			}
		}
		sb.append("]");
		return sb.toString();
	}
}
