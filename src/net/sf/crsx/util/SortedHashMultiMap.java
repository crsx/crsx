/* Copyright (c) 2010 */
package net.sf.crsx.util;

import java.util.Collection;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.SortedMap;
import java.util.TreeMap;

/**
 * Implementation of multi-map based on standard TreeMap and TreeSet.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SortedHashMultiMap.java,v 3.2 2013/04/12 04:13:53 krisrose Exp $
 */
public class SortedHashMultiMap<Key, Value> extends TreeMap<Key, Set<Value>> implements SortedMultiMap<Key, Value>
{
	/** Serial ID... */
	private static final long serialVersionUID = -5650476837311576983L;

	// Constructors.
	
	/** Using default key comparison. */
    public SortedHashMultiMap()
    {
	    super();
    }

    @SuppressWarnings("unused")
    private SortedHashMultiMap(Comparator<? super Key> arg0)
    {
	    super(arg0);
    }

    @SuppressWarnings("unused")
    private SortedHashMultiMap(Map<? extends Key, ? extends Set<Value>> arg0)
    {
	    super(arg0);
    }

    @SuppressWarnings("unused")
    private SortedHashMultiMap(SortedMap<Key, ? extends Set<Value>> arg0)
    {
	    super(arg0);
    }

	// MultiHashMap...
	
	public boolean multiEmpty()
	{
		for (Set<Value> values : values())
			if (!values.isEmpty())
				return false;
		return true;
	}

	public boolean multiEmpty(Key key)
	{
		Set<Value> set = get(key);
		return set == null || set.isEmpty();
	}

	public int multiSize()
	{
		int z = 0;
		for (Set<Value> values : values())
			if (!values.isEmpty())
				++z;
		return z;
	}

	public int multiSize(Key key)
	{
		Set<Value> set = get(key);
		return set == null ? 0 : set.size();
	}

	public Set<Key> multiKeySet()
    {
		Set<Key> set = new HashSet<Key>();
		for (Map.Entry<Key,Set<Value>> e : super.entrySet())
		{
			Set<Value> vs = e.getValue();
			if (vs != null && !vs.isEmpty())
				set.add(e.getKey());
		}
		return set;
    }

	public boolean multiContains(Key key, Value value)
	{
		Set<Value> set = get(key);
		return set != null && set.contains(value);
	}

	public Set<Value> multiGet(Key key)
	{
		Set<Value> set = get(key);
		if (set == null)
			super.put(key, set = new HashSet<Value>());
		return set;
	}
	
    public boolean multiContainsKey(Key key)
    {
		Set<Value> set = get(key);
		return set != null && !set.isEmpty();
    }

	public void multiAdd(Key key, Value value)
	{
		if (key == null)
			throw new NullPointerException();
		multiGet(key).add(value);
	}

	public void multiAddAll(Key key, Collection<Value> values)
	{
		if (!values.isEmpty())
			multiGet(key).addAll(values);
	}

	public boolean multiRemove(Key key, Value value)
	{
		if (key == null)
			throw new NullPointerException();
		Set<Value> set = get(key);
		return (set != null && set.remove(value));
	}

	public boolean multiRemoveAll(Key key, Collection<Value> values)
	{
		boolean removed = false;
		for (Value v : values)
			if (multiRemove(key, v))
				removed = true;
		return removed;
	}

	// Object...
	
	public String toString()
	{
		StringBuilder b = new StringBuilder();
		b.append("{");
		String sep = "";
		for (Map.Entry<Key,Set<Value>> e : entrySet())
		{
			b.append(sep + e.getKey() + " = " + e.getValue());
			sep = ";\n ";
		}
		b.append("}");
		return b.toString();
	}
}
