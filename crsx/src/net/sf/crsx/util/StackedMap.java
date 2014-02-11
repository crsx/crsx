package net.sf.crsx.util;

import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

/** 
 * Implements an environment using a stack of extensible maps. Keys and values must the be the same type.
 * 
 * One map is pushed on the stack for each scoping level. 
 * When leaving a scoping level, the topmost map is popped from the stack
 * 
 * @author jjohann
 *
 */
public class StackedMap<K> implements Map<K, K>{
	

	private Stack<Map<K, K>> stack;
	
	public StackedMap(){
		stack = new Stack<Map<K, K>>();
		stack.push(new HashMap<K, K>());
	}

	/**
	 * Enter new scoping level
	 */
	public void pushscope(){
		stack.push(new HashMap<K, K>());
	}
	
	/**
	 * Leave scoping level
	 */
	public void popscope(){
		stack.pop();
	}
	
	/**
	 * Returns the value bound to a key
	 * 
	 * @param key the key to be found
	 * @return the value to which the key is bound, or null if the key is not bound
	 */
	public K get(Object key){
		for (int i = stack.size()-1; i > 0; i--){
			Map<K, K> map = stack.get(i);
			K value = map.get(key);
			if (value != null){
				return value;
			}
		}
		return null;
	}
	
	/**
	 * Returns the last value found in a chain of lookups, i.e., if x is bound to y, 
	 * y is bound to z, and z is not bound, deeplookup(x) will return z. 
	 * 
	 * @param key the key to start the lookup.
	 * @return the final value found.
	 */
	public K deepLookup(K key){
		K value = get(key);
		K last = value;
		while (value != null){
			last = value;
			value = get(value);
		}
		return last;
	} 
	
	/**
	 * Extends the environment with a new association, in the current scope
	 * 
	 * @param key the key to be associated
	 * @param value the value to be associated with
	 */
	public K put(K key, K value){
		K prev = get(key);
		stack.peek().put(key, value);
		return prev;
	}

	public void clear() {
		stack.clear();
		stack.push(new HashMap<K, K>());
	}

	public boolean containsKey(Object key) {
		for (Map<K, K> m : stack){
			if (m.containsKey(key)){
				return true;
			}
		}
		return false;
	}

	public boolean containsValue(Object value) {
		for (Entry<K, K> entry : this.entrySet()){
			if (entry.getValue().equals(value)){
				return true;
			}
		}
		return false;
	}

	public Set<java.util.Map.Entry<K, K>> entrySet() {
		Set<K> seenkeys = new HashSet<K>();
		Set<java.util.Map.Entry<K, K>> set = new HashSet<java.util.Map.Entry<K, K>>();
		for (Map<K, K> m : stack){
			for (java.util.Map.Entry<K, K> entry : m.entrySet()){
				if (!seenkeys.contains(entry.getKey())){
					set.add(entry);
					seenkeys.add(entry.getKey());
				}
			}
		}
		return set;
	}

	public boolean isEmpty() {
		return stack.size() == 1 && stack.peek().isEmpty();
	}

	public Set<K> keySet() {
		Set<K> set = new HashSet<K>();
		for (Map<K, K> m : stack){
			set.addAll(m.keySet());
		}
		return set;
	}

	public void putAll(Map<? extends K, ? extends K> map) {
		stack.peek().putAll(map);
	}

	/**
	 * Remove not supported
	 */
	public K remove(Object key) {
		throw new UnsupportedOperationException("Remove operation not supported on StackedVariableMap");
	}

	public int size() {
		int size = 0;
		for (Map<K, K> m : stack){
			size += m.size();
		}
		return size;
	}

	public Collection<K> values() {
		Set<K> seenkeys = new HashSet<K>();
		Collection<K> values = new LinkedList<K>();
		for (Map<K, K> m : stack){
			for (java.util.Map.Entry<K, K> entry : m.entrySet()){
				if (!seenkeys.contains(entry.getKey())){
					values.add(entry.getValue());
					seenkeys.add(entry.getKey());
				}
			}
		}
		return values;
	}
}
