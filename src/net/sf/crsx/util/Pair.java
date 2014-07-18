/* Copyright © 2009, 2012 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Map.Entry;

/**
 * Utility to return pair of values.
 * Equal when members are equal.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Pair.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class Pair<Head, Tail> implements Cloneable, Entry<Head, Tail>
{
	// State.
	
	/** First component (immutable). */
	final private Head head;
	/** Second component. */
	private Tail tail;
	
	// Constructor.
	
	/** Create pair with the specified values for {@link #head()} and {@link #tail()}. */
	public Pair(Head head, Tail tail)
	{
		this.head = head;
		this.tail = tail;
		if (tail == null)
			this.tail = null;
	}

	/** Create pair with the specified values for {@link #head()} and {@link #tail()}. */
	public Pair(Entry<Head, Tail> entry)
	{
		this.head = entry.getKey();
		this.tail = entry.getValue();
	}
	
	// Methods.
	
	/** Return the head value set up by the constructor. */
	public Head head() { return head; }
	/** Return the tail value set up by the constructor. */
	public Tail tail() { return tail; }

    // Map.Entry<Head,Tail>

    public Head getKey()
    {
        return head;
    }

    public Tail getValue()
    {
        return tail;
    }
    
    public Tail setValue(Tail value)
    {
    	Tail old = tail;
        tail = value;
        return old;
    }
    
	// Object...

    @Override
	public boolean equals(Object that)
	{
		if (this == that)
			return true;
		Pair<?, ?> p = (Pair<?, ?>) that;
		return (head == p.head || (head != null && head.equals(p.head)))
			&& (tail == p.tail || (tail != null && tail.equals(p.tail)));
	}

    @Override
	public int hashCode()
	{
		return (head == null ? 0 : head.hashCode()) + (tail == null ? 0 : tail.hashCode());
	}
    
    public String toString()
    {
    	return "<"+Util.show(head)+","+Util.show(tail)+">";
    }
	
    // Cloneable.

    @Override
    protected Object clone() throws CloneNotSupportedException
    {
        return new Pair<Head, Tail>(head, tail);
    }
}
