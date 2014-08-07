/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.SortedMap;

/**
 * Extends sorted maps with safe addition of a single element to the image set.
 * The sorted version always iterates over the mappings in key order (the individual sets are not sorted). 
 * @param <Key> hash key
 * @param <Value> hash value set member type
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SortedMultiMap.java,v 3.0 2012/12/17 18:04:59 krisrose Exp $
 */
public interface SortedMultiMap<Key,Value> extends SortedMap<Key,Set<Value>>
{
	/** True if all keys map to the empty set. */
	public boolean multiEmpty();

	/** Is the multi-map for a particular key empty? */
	public boolean multiEmpty(Key key);

	/** Number of keys that map to non-empty sets. */
	public int multiSize();

	/** Get the number of values in the set for key. */
	public int multiSize(Key key);

	/** Does key map to a specific value? */
	public boolean multiContains(Key key, Value value);
	
	/** Get set of values mapped to by key. */
	public Set<Value> multiGet(Key key);
	
	/** Add single value to map for key. */
	public void multiAdd(Key key, Value value);

	/** Add multiple values to map for key. */
	public void multiAddAll(Key key, Collection<Value> values);

	/** Remove a value from the map for the key and report if anything was in fact removed. */
	public boolean multiRemove(Key key, Value value);

	/** Remove values from the map for the key and report if anything was in fact removed. */
	public boolean multiRemoveAll(Key key, Collection<Value>  values);
	
	/** Does key map to any values? */
	public boolean multiContainsKey(Key key);
	
	/** Keys that map to a non-empty set. */
	public Set<Key> multiKeySet();
	
	/** Using this interferes with {@link SortedMultiMap} functionality. */
    @Deprecated
    public boolean containsKey(Object key);
	/** Using this interferes with {@link SortedMultiMap} functionality. */
    @Deprecated
    public Set<Key> keySet();
	/** Using this interferes with {@link SortedMultiMap} functionality. */
    @Deprecated
    public Set<Value> put(Key key, Set<Value> value);
	/** Using this interferes with {@link SortedMultiMap} functionality. */
    @Deprecated
    public void putAll(Map<? extends Key, ? extends Set<Value>> map);
}
