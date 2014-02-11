/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * TODO: Map that adds to/removes from a provided base map without mutating it. 
 * Does not support null values.
 *
 * @param <K> Key type
 * @param <V> Value type
 */
public class DeltaMap<K,V> implements Map<K, V>
{
	// State.
	
	/** Base map (not mutated). */
	final private Map<K,V> base;
	
	/** Delta map (mutated). */
	final private Map<K,V> delta;
	
	/** Number of maps in base not covered by delta. */
	int baseUnique;

	/** Nbumber of maps in delta that erase a map in base. */
	int deltaRemoved;
	
	// Constructor.
	
	/**
	 * Create delta map that adds to/removes from the provided base map without mutating it. 
	 */
	public DeltaMap(Map<K,V> baseMap)
	{
		base = baseMap;
		baseUnique = baseMap.size();
		delta = new HashMap<K, V>();
		deltaRemoved = 0;
	}
	
    // Map...

	public int size()
    {
    	return baseUnique + delta.size() - deltaRemoved;
    }

	public boolean isEmpty()
	{
		return size() == 0;
	}

	public boolean containsKey(Object key)
	{
		return (delta.containsKey(key) ? delta.get(key) != null : base.containsKey(key));
	}

	public boolean containsValue(Object value)
	{
		if (value == null)
			return false;
		
		if (delta.containsValue(value))
			return true;
		
		for (Map.Entry<K, V> e : base.entrySet())
		{
			K k = e.getKey();
			V v = e.getValue();
			if (v.equals(value))
				return (!delta.containsKey(k)); // cannot be mapped to value!
		}
		return false;
	}

	public V get(Object key)
	{
		V value = delta.get(key);
		if (value == null && !delta.containsKey(key))
			value = base.get(key);
		return value;
	}

    // Modification Operations

	public V put(K key, V value)
	{
		if (value == null)
			throw new NullPointerException();
		
		V old;
		if (delta.containsKey(key))
		{
			// Already handled in delta.
			old = delta.put(key, value);
			if (old == null)
				--deltaRemoved; // no longer removing from base
		}
		else
		{
			// Not yet in delta - get old from base, then add in delta.
			old = base.get(key);
			delta.put(key, value);
			if (old != null)
				--baseUnique; // added shadowing 
		}
		return old;
	}

	@SuppressWarnings("unchecked") // see comments below on the two unchecked casts
	public V remove(Object key)
	{
		V old;
		if (delta.containsKey(key))
		{
			// Delta defines it.
			old = delta.get(key);
			if (old != null)
			{
				// Removing value that is currently mapped by delta.
				delta.put((K) key, null); // unsafe cast checked by containsKey
				++deltaRemoved;
			}
		}
		else
		{
			// Base defines it, if any...
			old = base.get(key);
			if (old != null)
			{
				// Removing value that is currently mapped by base.
				delta.put((K) key, null); // unsafe cast checked by getKey != null
				--baseUnique;
				++deltaRemoved;
			}
		}
		return old;
	}

    // Bulk Operations

	public void putAll(Map<? extends K, ? extends V> m)
	{
		for (Map.Entry<? extends K, ? extends V> e : m.entrySet())
			put(e.getKey(), e.getValue());
	}
	
	public void clear()
	{
		delta.clear();
		for (Map.Entry<K,V> e : base.entrySet())
			delta.put(e.getKey(), null);
		baseUnique = 0;
		deltaRemoved = delta.size();
	}

    // Views

	public Set<K> keySet()
	{
		Set<K> keys = new HashSet<K>(base.keySet());
		for (Map.Entry<K,V> e : delta.entrySet())
		{
			K k = e.getKey();
			V v = e.getValue();
			if (v == null)
				keys.remove(k);
			else
				keys.add(k);
		}
		return keys;
	}

	public Collection<V> values()
	{
		Collection<V> values = new ArrayList<V>();
		for (V v : delta.values())
			if (v != null)
				values.add(v);
		for (Map.Entry<K, V> e : base.entrySet())
			if (!delta.containsKey(e.getKey()))
				values.add(e.getValue());
		return values;
	}

	public Set<Map.Entry<K, V>> entrySet()
	{
		Set<Map.Entry<K, V>> entries = new HashSet<Entry<K,V>>();
		for (Map.Entry<K,V> e : delta.entrySet())
			if (e.getValue() != null)
				entries.add(e);
		for (Map.Entry<K,V> e : base.entrySet())
			if (!delta.containsKey(e.getKey()))
				entries.add(e);
		return entries;
	}

    // Comparison and hashing

	public boolean equals(Object o)
	{
		return delta.equals(o);
	}

	public int hashCode()
	{
		return delta.hashCode();
	}
}
