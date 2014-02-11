/* Copyright (c) 2012 */
package net.sf.crsx.util;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * HashMap restricted to not permit null keys.
 */
public class NonNullHashMap<K,V> extends HashMap<K, V>
{
    private static final long serialVersionUID = 1L;
	
	// Constructor.
	
	/**
     * 
     */
    public NonNullHashMap()
    {
	    super();
    }

	/**
     * @param capacity
     * @param loadFactor
     */
    public NonNullHashMap(int capacity, float loadFactor)
    {
	    super(capacity, loadFactor);
    }

	/**
     * @param capacity
     */
    public NonNullHashMap(int capacity)
    {
	    super(capacity);
    }

	/**
     * @param map
     */
    public NonNullHashMap(Map<? extends K, ? extends V> map)
    {
	    super(map);
    }

	public void clear()
    {
		super.clear();
    }

	public boolean containsKey(Object key)
    {
	    return super.containsKey(key);
    }

	public boolean containsValue(Object value)
    {
	    return super.containsValue(value);
    }

	public Set<java.util.Map.Entry<K, V>> entrySet()
    {
	    return super.entrySet();
    }

	public V get(Object key)
    {
	    return super.get(key);
    }

	public boolean isEmpty()
    {
	    return super.isEmpty();
    }

	public Set<K> keySet()
    {
	    return super.keySet();
    }

	public V put(K key, V value)
    {
		if (key == null || value == null)
			throw new NullPointerException();
	    return super.put(key, value);
    }

	public void putAll(Map<? extends K, ? extends V> map)
    {
		super.putAll(map);
    }

	public V remove(Object key)
    {
	    return super.remove(key);
    }

	public int size()
    {
	    return super.size();
    }

	public Collection<V> values()
    {
	    return super.values();
    }
}
