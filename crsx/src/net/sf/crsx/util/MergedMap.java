/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.util;

import java.util.AbstractMap;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;

/**
 * Map composed of several existing maps.
 * The map is peculiar in that it can be extended but entries cannot be removed, specifically,
 * <ul>
 * <li>{@link #put(Object, Object)} adds a mapping which cannot be removed (but can override an existing mapping),
 * <li>{@link #putAll(Map)} incorporates the provided map <em>by reference</em> thus the merged map will reflect changes to the original map, and
 * <li>all other modifications throw an {@link UnsupportedOperationException}. 
 * </ul>
 * @param <K> hash key type
 * @param <V> hash value type
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: MergedMap.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class MergedMap<K, V> extends AbstractMap<K,  V>
{
	// State.
	
	/** All the actual maps...newest added last. */
	final private List<Map<K, V>> maps = new ArrayList<Map<K, V>>();
	
	// Constructor.
	
	/**
	 * Create empty joined map (add member maps with {@link #putAll(Map)}).
	 */
	public MergedMap()
	{}
	
	// AbstractMap...

	@Override
	public Set<Map.Entry<K, V>> entrySet()
	{
		return new AbstractSet<Map.Entry<K, V>>()
		{
			@Override
			public Iterator<Map.Entry<K, V>> iterator()
			{
				return new Iterator<Map.Entry<K, V>>()
				{
					// State.
					/** The keys that have already been emitted. */
					final Set<K> keysEmitted = new HashSet<K>();
					/** The maps remaining to process. */
					final Iterator<Map<K, V>> mapIterator = maps.iterator();
					/** The current iterator. */
					private Iterator<Map.Entry<K, V>> entryIterator = mapIterator.next().entrySet().iterator();
					/** The current entry. */
					private Map.Entry<K, V> entry;
					// Iterator...
					public boolean hasNext()
					{
						while (entry == null)
						{
							while (!entryIterator.hasNext() && mapIterator.hasNext())
								entryIterator = mapIterator.next().entrySet().iterator();
							if (!entryIterator.hasNext())
								break; // terminate loop if all iterators exhausted
							entry = entryIterator.next();
							if (keysEmitted.contains(entry.getKey()))
								entry = null; // already emitted, skip
							else
								keysEmitted.add(entry.getKey()); // so we only emit it once
						}
						return (entry != null);
					}
					public java.util.Map.Entry<K, V> next()
					{
						if (hasNext())
						{
							assert entry != null;
							Map.Entry<K, V> e = entry;
							entry = null;
							return e;
						}
						throw new NoSuchElementException("JoinedMap exhausted");
					}
					public void remove()
					{
						throw new UnsupportedOperationException("JoinedMap cannot remove entries");
					}
				};
			}
			@Override
			public int size()
			{
				int size = 0;
				for (Iterator<Map.Entry<K, V>> it = iterator(); it.hasNext(); it.next())
					++size;
				return size;
			}
		};
	}

	// Map...

	@Override
	@SuppressWarnings("unchecked")
	public void putAll(Map<? extends K, ? extends V> map)
	{
		maps.add(0, (Map<K, V>) map); // most recent mappings are first
	}
	
	@Override
	public V put(K key, V value)
	{
		V old = get(key);
		putAll(new LinkedExtensibleMap<K, V>().extend(key, value));
		return old;
	}
}
