/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * Helper to create iterators that chain several existing ones.
 * The individual iterators are instantiated "on demand" so the implementation is not robust for mutation of the passed iterables.
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public abstract class ChainedIterable<T> implements Iterable<T>
{
	// Static.

	/**
	 * Build chained iterable from list of iterables.
	 * @param <T> the type we iterate over
	 * @param list of iterables (used directly - not copied)
	 * @return joined iterable
	 */
	public static <T> Iterable<T> chain(final List<Iterable<T>> list)
	{
		return new ChainedIterable<T>()
		{
			@Override
			protected int iterableCount()
			{
				return list.size();
			}
			@Override
			protected Iterable<T> iterable(int i)
			{
				return list.get(i);
			}
		};
	}

	/**
	 * Build chained iterable from two iterables.
	 * @param <T> the type we iterate over
	 * @return joined iterable
	 */
	public static <T> Iterable<T> chain(final Iterable<T> first, final Iterable<T> second) 
	{
		return new ChainedIterable<T>()
		{
			@Override
			protected int iterableCount()
			{
				return 2;
			}
			@Override
			protected Iterable<T> iterable(int i)
			{
				switch (i)
				{
					case 0 : return first;
					case 1 : return second;
					default : throw new IndexOutOfBoundsException();
				}
			}
		};
	}
	
    // Constructor.

    /** Instantiate. */
	protected ChainedIterable()
    {}
    
	// Methods.
	
    /** Override with mechanism to get number of iterables. */
    protected abstract int iterableCount();

    /** Override with mechanism to get i'th iterable. */
    protected abstract Iterable<T> iterable(int i);

    // Iterable<T>...
    
    public Iterator<T> iterator()
    {
        return new Iterator<T>()
        {
        	// State
        	private Iterator<T> currentIterator; // null first and last; otherwise 
        	private int nextIterableIndex = 0;
        	
        	// Iterator<T>...
            public boolean hasNext()
            {
            	while (true)
            	{
                	if (currentIterator == null) // searching for new currentIterator in iterables
                	{
                		if (nextIterableIndex < iterableCount())
                			currentIterator = iterable(nextIterableIndex++).iterator(); // instantiate next iterator
                		else
                			return false; // all iterators exhausted (and currentIterator == null)
                	}
                	else // searching in currentIterator
                	{
                		if (currentIterator.hasNext())
                			return true; // iterator has a next item
                		else
                			currentIterator = null; // this iterator exhausted - search for a new one
                	}
            	}
            }
            
            public T next()
            {
            	if (!hasNext())
            		throw new NoSuchElementException();
            	return currentIterator.next();
            }
            
            public void remove()
            {
            	if (currentIterator == null)
            		throw new IllegalStateException();	
            	currentIterator.remove();
            }
        };
    }
}
