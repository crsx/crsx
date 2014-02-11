/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx.util;

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Helper to create empty iterators.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class EmptyIterable<T> implements Iterable<T>,  Iterator<T>
{
	// Constructor.

    /** Create empty iterable. */
    public EmptyIterable()
    {}

    // Iterable<T>...
    
    public Iterator<T> iterator()
    {
        return this;
    }
    
    // Iterator<T>...

    public boolean hasNext()
    {
    	return false;
    }
    
    public T next()
    {
    	throw new NoSuchElementException();
    }
    
    public void remove()
    {
    	throw new IllegalStateException();
    }
}
