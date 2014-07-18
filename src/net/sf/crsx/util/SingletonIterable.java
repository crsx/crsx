/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import java.util.Iterator;

/**
 * Helper to create singleton iterators.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class SingletonIterable<T> implements Iterable<T>
{
	// State
	
	/** Single member. */
	private T member;
	
	// Constructor.

    /** Create iterable with the one member. */
    public SingletonIterable(T member)
    {
    	this.member = member;
    }

    // Iterable<T>...
    
    public Iterator<T> iterator()
    {
        return new Iterator<T>()
        {
        	private boolean used;
            public boolean hasNext()
            {
            	return !used;
            }
            public T next()
            {
            	if (used) throw new IllegalStateException();
            	used = true;
            	return member;
            }
            public void remove()
            {
            	throw new IllegalStateException();
            }
        };
    }
}
