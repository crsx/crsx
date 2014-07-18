/* Copyright (c) 2010 */
package net.sf.crsx.util;

import java.util.Collection;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Implementation of multi-map based on {@link SmallMap} and {@link SmallSet}.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SmallMultiMap.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class SmallMultiMap<Key, Value> extends SmallMap<Key, Set<Value>> implements MultiMap<Key, Value>
{
	// Constructors.
	
	/** Create empty multi value hash map. */
	public SmallMultiMap()
	{}
	
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

	public Set<Value> multiGet(Key key)
	{
		Set<Value> set = get(key);
		if (set == null)
			put(key, set = new HashSet<Value>());
		return set;
	}

    public boolean multiContainsKey(Key key)
    {
		Set<Value> set = get(key);
		return set != null && !set.isEmpty();
    }

	public boolean multiContains(Key key, Value value)
	{
		Set<Value> set = get(key);
		return set != null && set.contains(value);
	}

	public void multiAdd(Key key, Value value)
	{
		multiGet(key).add(value);
	}

	public void multiAddAll(Key key, Collection<Value> values)
	{
		multiGet(key).addAll(values);
	}

	public boolean multiRemove(Key key, Value value)
    {
		return multiGet(key).remove(value);
    }

	public boolean multiRemoveAll(Key key, Collection<Value> values)
    {
		boolean removed = false;
		for (Value v : values)
			if (multiRemove(key, v))
				removed = true;
		return removed;
    }
}
