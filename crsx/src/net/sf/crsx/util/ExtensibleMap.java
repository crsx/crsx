package net.sf.crsx.util;

import java.util.List;
import java.util.Map;

/**
 * Extensible but immutable map (also known as "functional" map).
 * Category of maps building on (and conforming to) the standard {@link Map} interface but
 * <ul>
 * <li>explicitly not supporting any of the "destructive" update methods from {@link Map} but rather
 * <li>adds several <em>extension</em> methods for building new maps with extra mappings.
 * </ul>
 *  
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: ExtensibleMap.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public interface ExtensibleMap<Key,Value> extends Map<Key,Value>
{
	/**
	 * Create new map which extends this one with a single mapping.
	 * @param key that is mapped
	 * @param value what it is mapped to
	 * @return new map (original mapping is unchanged)
	 */
	public ExtensibleMap<Key,Value> extend(Key key, Value value);

	/**
	 * Create new map which extends this one with all pairwise mappings between key and value arrays.
	 * @param keys that are to be mapped
	 * @param values with what the keys map to (in order)
	 * @return new map (original mapping is unchanged)
	 */
	public ExtensibleMap<Key,Value> extend(Key[] keys, Value[] values);

	/**
	 * Create new variable map which extends this one with all mappings from an existing map.
	 * @param map with mappings to add to new map
	 * @return new map (original mapping is unchanged)
	 */
	public ExtensibleMap<Key,Value> extend(Map<Key,Value> map);
	
	/** Return the reverse extensible map. If more than one key maps to a particular value then one of the mappings is picked. */
	public ExtensibleMap<Value, Key> reverse();
	
	/**
	 * Return the result of applying the map to every member of a list.
	 * @param keys with arguments
	 * @return list with the element-wise mapping of keys
	 */
	public List<Value> getAll(List<Key> keys);
}
