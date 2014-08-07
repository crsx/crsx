package net.sf.crsx.util;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Set;

import net.sf.crsx.Constructor;
import net.sf.crsx.Variable;

/**
 * Immutable set.
 * @param <E> type of elements
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: LinkedExtensibleSet.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class LinkedExtensibleSet<E> implements ExtensibleSet<E>
{
	// Static.
	
	/** Create extensible set from existing set. */
	public static <T> ExtensibleSet<T> immutable(Collection<T> set)
	{
		return new LinkedExtensibleSet<T>().extend(set);
	}
	
	/** Empty set of strings. */
	public static ExtensibleSet<String> EMPTY_STRING_SET = new LinkedExtensibleSet<String>();
	
	/** Empty set of variables. */
	public static ExtensibleSet<Variable> EMPTY_VARIABLE_SET = SimpleVariableSet.EMPTY;

	/** Empty set of constructors. */
	public static ExtensibleSet<Constructor> EMPTY_CONSTRUCTOR_SET = new LinkedExtensibleSet<Constructor>();
	

	// Constructor.
	
	/** Create empty extensible set. */
	public LinkedExtensibleSet()
	{}

	// ExtensibleSet<E>...

	public ExtensibleSet<E> extend(E value)
	{
		return new Link<E>(null, value); // empty always extended
	}

	final public ExtensibleSet<E> extend(E[] values)
	{
		ExtensibleSet<E> extended = this;
		for (E e : values)
			extended = extended.extend(e);
		return extended;
	}

	final public ExtensibleSet<E> extend(Collection<E> values)
	{
		ExtensibleSet<E> extended = this;
		for (E e : values)
			extended = extended.extend(e);
		return extended;
	}
	
	// Set<E>...

    public int size()
    {
    	return 0;
    }

    public boolean isEmpty()
    {
    	return true;
    }

    public boolean contains(Object o)
    {
    	return false;
    }

    public Iterator<E> iterator()
    {
    	return new Iterator<E>()
    	{
			public boolean hasNext()
			{
				return false;
			}
			public E next()
			{
				throw new NoSuchElementException();
			}
			public void remove()
			{
				throw new UnsupportedOperationException();
			}
    	};
    }

    public Object[] toArray()
    {
    	Object[] os = {};
    	return os;
    }

    public <T> T[] toArray(T[] a)
    {
    	if (a == null)
    		throw new NullPointerException();
    	return a;
    }

    // Modification Operations

    final public boolean add(E o)
    {
		throw new UnsupportedOperationException();
    }

    final public boolean remove(Object o)
    {
    	throw new UnsupportedOperationException();
    }

    // Bulk Operations

    public boolean containsAll(Collection<?> c)
    {
    	return false;
    }

    final public boolean addAll(Collection<? extends E> c)
    {
		throw new UnsupportedOperationException();
    }

    final public boolean retainAll(Collection<?> c)
    {
		throw new UnsupportedOperationException();
    }

    final public boolean removeAll(Collection<?> c)
    {
		throw new UnsupportedOperationException();
    }

    final public void clear()
    {
		throw new UnsupportedOperationException();
    }

    // Comparison and hashing

    public boolean equals(Object o)
    {
    	return ((Set<?>) o).isEmpty();
    }

    public int hashCode()
    {
    	return 0;
    }
    
    public String toString()
    {
    	return "{}";
    }
    
	// Helper class.
	
	/**
	 * Create a link for one extra set member.
	 * @param <E> member type
	 * 
	 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
	 * @version $Id: LinkedExtensibleSet.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
	 */
	static protected class Link<E> extends LinkedExtensibleSet<E>
	{
		// State.
		/** Parent link. */
		final protected Link<E> parent;
		/** Added element. */
		final protected E element;
		/** Create link with additional element. */
		protected Link(Link<E> parent, E e)
		{
			this.parent = parent;
			element = e;
			assert parent == null || !parent.contains(e) : "Link created for existing element...";
		}
		
		// ExtensibleSet<E>...

		public ExtensibleSet<E> extend(E e)
		{
			return (parent != null && parent.contains(e) ? this : new Link<E>(this, e));
		}

		// Set<E>...

		public int size()
		{
			int z = 0;
			for (Link<E> link = this; link != null; link = link.parent)
				++z;
			return z;
		}

		public boolean isEmpty()
		{
			return false;
		}

		public boolean contains(Object o)
		{
			for (Link<E> link = this; link != null; link = link.parent)
				if (link.element.equals(o))
					return true;
			return false;
		}

		public Iterator<E> iterator()
		{
			return new Iterator<E>()
			{
				/** Current link. */
				Link<E> next = Link.this;
				// Iterator<E>...
				public boolean hasNext()
				{
					return next != null;
				}
				public E next()
				{
					if (next == null)
						throw new NoSuchElementException();
					E e = next.element;
					next = next.parent;
					return e;
				}
				public void remove()
				{
					throw new UnsupportedOperationException();
				}
			};
		}

		public Object[] toArray()
		{
			// TODO: optimize.
			List<E> list = new ArrayList<E>();
			for (Link<E> link = this; link != null; link = link.parent)
				list.add(link.element);
			return list.toArray();
		}

		public <T> T[] toArray(T[] a)
		{
			// TODO: optimize...
			List<E> list = new ArrayList<E>();
			for (Link<E> link = this; link != null; link = link.parent)
				list.add(link.element);
			return list.toArray(a);
		}

		public boolean containsAll(Collection<?> c)
		{
			// TODO: optimize...
			for (Object o : c)
				if (!contains(o))
					return false;
			return true;
		}

		// Comparison and hashing

		public boolean equals(Object other)
		{
			Set<?> otherSet = (Set<?>) other;
			int z = otherSet.size();
			for (Link<E> link = this; link != null; link = link.parent)
			{
				if (!otherSet.contains(link.element))
					return false; // one of our elements missing in otherSet
				--z;
			}
			return z == 0; // succeed if we exhausted otherSet.
		}

		public int hashCode()
		{
			int h = 0;
			for (Link<E> link = this; link != null; link = link.parent)
				h += link.element.hashCode();
			return h;
		}
		
		public String toString()
		{
			StringBuilder b = new StringBuilder();
			b.append('{'); 
			for (Link<E> link = this; link != null; link = link.parent)
			{
				b.append(link.element.toString());
				if (link.parent != null) b.append(", ");
			}
			b.append('}'); 
			return b.toString();
		}
	}
}
