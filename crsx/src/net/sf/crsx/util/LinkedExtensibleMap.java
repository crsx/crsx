/* Copyright (c) 2006, 2007 IBM Corporation. */

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

import net.sf.crsx.Contractum;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Immutable map implemented as linked stack of "mapping entry frames".
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: LinkedExtensibleMap.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class LinkedExtensibleMap<Key, Value> extends AbstractMap<Key, Value> implements ExtensibleMap<Key, Value>
{
	// Constants.

	/** Empty substitution. */
	final public static ExtensibleMap<Variable, Contractum> EMPTY_SUBSTITUTION = new LinkedExtensibleMap<Variable, Contractum>();

	/** No variable allocations. */
	final public static ExtensibleMap<String, Variable> EMPTY_SCOPE = new LinkedExtensibleMap<String, Variable>();

	/** No namings. */
	final public static ExtensibleMap<Variable, String> EMPTY_NAMING = new LinkedExtensibleMap<Variable, String>();

	/** No renamings. */
	final public static ExtensibleMap<Variable, Variable> EMPTY_RENAMING = new LinkedExtensibleMap<Variable, Variable>();

	/** No named terms. */
	final public static ExtensibleMap<String, Term> EMPTY_NAMED_PROPERTIES = new LinkedExtensibleMap<String, Term>();

	/** No named counters. */
	final public static ExtensibleMap<String, Integer> EMPTY_NAMED_COUNTS = new LinkedExtensibleMap<String, Integer>();

	/** No variable terms. */
	final public static ExtensibleMap<Variable, Term> EMPTY_VARIABLE_PROPERTIES = new LinkedExtensibleMap<Variable, Term>();

	/** No named lists of terms. */
	final public static ExtensibleMap<String, List<Term>> EMPTY_NAMED_LIST = new LinkedExtensibleMap<String, List<Term>>();

	// Constructors.

	/** Create empty map. */
	public LinkedExtensibleMap()
	{}

	// ExtensibleMap<Key,Value>...

	public ExtensibleMap<Key, Value> extend(Key from, Value to)
	{
		return new Link<Key, Value>(null, from, to);
	}

	final public ExtensibleMap<Key, Value> extend(Key[] from, Value[] to)
	{
		ExtensibleMap<Key, Value> map = this;
		for (int i = 0; i < from.length; ++i)
			map = map.extend(from[i], to[i]);
		return map;
	}

	final public ExtensibleMap<Key, Value> extend(Map<Key, Value> more)
	{
		ExtensibleMap<Key, Value> map = this;
		for (Map.Entry<Key, Value> e : more.entrySet())
			map = map.extend(e.getKey(), e.getValue());
		return map;
	}

	final public ExtensibleMap<Value, Key> reverse()
	{
		ExtensibleMap<Value, Key> map = new LinkedExtensibleMap<Value, Key>();
		for (Map.Entry<Key, Value> e : entrySet())
			map = map.extend(e.getValue(), e.getKey());
		return map;
	}

	public List<Value> getAll(List<Key> keys)
	{
		List<Value> values = new ArrayList<Value>(keys.size());
		for (Key key : keys)
			values.add(get(key));
		return values;
	}

	// Map<Key,Value> (as required by AbstractMap<Key,Value>)...

	public Set<Map.Entry<Key, Value>> entrySet()
	{
		return new LinkedExtensibleSet<Map.Entry<Key, Value>>();
	}

	public int size()
	{
		return 0;
	}

	public boolean isEmpty()
	{
		return true;
	}

	// Utility classes!

	/** Helper class to ensure links can be used as map entries. */
	static protected abstract class PreLink<Key, Value> extends LinkedExtensibleMap<Key, Value> implements Map.Entry<Key, Value>
	{
		protected PreLink()
		{}
	}

	/** Helper class for one additional entry. */
	static protected class Link<Key, Value> extends PreLink<Key, Value>
	{
		/** Parent (or null when no further maps). */
		final protected Link<Key, Value> parent;
		/** Key to map. */
		final protected Key key;
		/** Value to map to. */
		private Value value;
		/** Whether this overrides a mapping in parent. */
		final protected boolean keyOverrides;

		// Constructor.

		/** Create link. */
		Link(Link<Key, Value> parent, Key key, Value value)
		{
			this.parent = parent;
			this.key = key;
			this.value = value;
			keyOverrides = parent != null && parent.containsKey(key);
		}

		// Map.Entry<Key,Value>...

		public Key getKey()
		{
			return key;
		}

		public Value getValue()
		{
			return value;
		}

		public Value setValue(Value newValue)
		{
			Value previousValue = value;
			value = newValue;
			return previousValue;
		}

		// ExtensibleMap<Key,Value>...

		public ExtensibleMap<Key, Value> extend(Key from, Value to)
		{
			return new Link<Key, Value>(this, from, to);
		}

		// Map<Key,Value> (as required by AbstractMap<Key,Value)...

		public Set<Map.Entry<Key, Value>> entrySet()
		{
			return new AbstractSet<Map.Entry<Key, Value>>()
				{
					public int size()
					{
						int z = 0;
						for (Link<Key, Value> link = Link.this; link != null; link = link.parent)
							if (!link.keyOverrides)
								++z;
						return z;
					}

					public Iterator<Map.Entry<Key, Value>> iterator()
					{
						return new Iterator<Entry<Key, Value>>()
							{
								/** Next link to look at. */
								Link<Key, Value> next = Link.this;
								/** Keys we have returned entries for. */
								Set<Key> emittedKeys = new HashSet<Key>();

								// Iterator<Map.Entry<Key, Value>>...
								public boolean hasNext()
								{
									while (next != null && emittedKeys.contains(next.key))
										next = next.parent;
									return next != null;
								}

								public Map.Entry<Key, Value> next()
								{
									if (!hasNext())
										throw new NoSuchElementException();
									Map.Entry<Key, Value> entry = next;
									emittedKeys.add(next.key);
									next = next.parent;
									return entry;
								}

								public void remove()
								{
									throw new UnsupportedOperationException();
								}
							};
					}
				};
		}

		public int size()
		{
			int z = 0;
			for (Link<Key, Value> link = this; link != null; link = link.parent)
				if (!link.keyOverrides)
					++z;
			return z;
		}

		// Map<Key,Value> optimized

		/*
        public Value get(Object key)
        {
			for (Link<Key, Value> link = this; link != null; link = link.parent)
				if (link.key.equals(key))
					return value;
	        return null;
        }
        
        public Value put(Key key, Value value)
        {
			for (Link<Key, Value> link = this; link != null; link = link.parent)
				if (link.key.equals(key))
					link.value = value;
	        throw new UnsupportedOperationException("Cannot add new mappings destructively to ExtensibleMap.");
        }
        */

		public boolean isEmpty()
		{
			return false;
		}

		// Sic.

		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			boolean continued = false;
			sb.append("[");
			for (Map.Entry<Key, Value> e : entrySet())
			{
				if (e.getKey() != null)
				{
					if (continued)
						sb.append(", ");
					else
						continued = true;
					sb.append(e.getKey().toString());
					sb.append(" = ");
					sb.append(e.getValue().toString());
				}
			}
			sb.append("]");
			return sb.toString();
		}
	}
}
