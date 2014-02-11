/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.util;

/**
 * Small map with default value for {@link #get(Object)}.
 * @author krisrose
 */
public class SmallMapWithDefault<K, V> extends SmallMap<K, V>
{
	// State.
	
	/** Default value. */
	final V defaultValue;
	
	// Constructor.
	
	/**
	 * Instantiate map with default value.
	 */
	public SmallMapWithDefault(V v)
	{
		defaultValue = v;
	}
	
	// Map.
	
	@Override
	public V get(Object key)
	{
		V value = super.get(key);
		return (value != null ? value : defaultValue);
	}
}
