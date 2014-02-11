/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

/**
 * Implementation of map wrapping an {@link ExtensibleMap}.
 * Does not support {@link #remove(Object)}.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class SmallMap<K,V> implements Map<K, V>
{
	/** The extensible map. */
	private ExtensibleMap<K,V> map;
	
	/** Create empty map. */
	public SmallMap()
	{
		map = new LinkedExtensibleMap<K, V>();
	}
	
	// Methods.
	
	/** Return extensible version of the map. */
	public ExtensibleMap<K,V> getExtensibleMap()
	{
		return map;
	}

    // Map...

	public int size()
    {
    	return map.size();
    }

	public boolean isEmpty()
	{
		return map.isEmpty();
	}

	public boolean containsKey(Object key)
	{
		return map.containsKey(key);
	}

	public boolean containsValue(Object value)
	{
		return map.containsValue(value);
	}

	public V get(Object key)
	{
		return map.get(key);
	}

    // Modification Operations

	public V put(K key, V value)
	{
		V old = get(key);
		map = map.extend(key, value);
		return old;
	}

	public V remove(Object key)
	{
		throw new UnsupportedOperationException("SmallMap does not support Map.remove()");
	}

    // Bulk Operations

	public void putAll(Map<? extends K, ? extends V> m)
	{
		for (Map.Entry<? extends K, ? extends V> e : m.entrySet())
			put(e.getKey(), e.getValue());
	}
	
	public void clear()
	{
		map = new LinkedExtensibleMap<K, V>();
	}

    // Views

	public Set<K> keySet()
	{
		return map.keySet();
	}

	public Collection<V> values()
	{
		return map.values();
	}

	public Set<Map.Entry<K, V>> entrySet()
	{
		return map.entrySet();
	}

    // Comparison and hashing

	public boolean equals(Object o)
	{
		return map.equals(o);
	}

	public int hashCode()
	{
		return map.hashCode();
	}
	
	public String toString()
	{
		return map.toString();
	}
}
