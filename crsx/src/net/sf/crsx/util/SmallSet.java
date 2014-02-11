/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx.util;

import java.util.AbstractSet;
import java.util.Collection;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Implementation of set using a singly linked list (stack). Useful for small sets.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class SmallSet<E> extends AbstractSet<E>
{
    // State.
    
    /** Top of stack of added elements. */
    protected Link<E> top;
    
    /** Helper class for stack elements. */
    protected static class Link<E>
    {
        Link<E> parent;
        final E element;
        Link(Link<E> parent, E element)
        {
            this.parent = parent;
            this.element = element;
        }
    }
    
    // Constructors.
    
    /** Create empty small set. */
    public SmallSet()
    {}

    /** Create small set with same content as existing collection. */
    public SmallSet(Collection<E> collection)
    {
    	for (E e : collection)
    		add(e);
    }

    /**
     * Create small set with single member.
     */
    public SmallSet(E member)
    {
    	add(member);
    }
    

    // [Abstract]Set implementation.
    
    public int size()
    {
        int size = 0;
        for (Link<E> link = top; link != null; link = link.parent)
            ++size;
        return size;
    }

    public Iterator<E> iterator()
    {
        return new Iterator<E>()
        {
            Link<E> next = top;
            Link<E> child; // the child of what next() will or (if used) has just returned 
            boolean used = false; // true just after next()
            public boolean hasNext()
            {
                if (used)
                {
                    used = false;
                    child = next;
                    next = next.parent;
                }
                return (next !=null);
            }
            public E next()
            {
                if (!hasNext()) throw new NoSuchElementException();
                used = true;
                return next.element;
            }
            public void remove()
            {
                if (!used) throw new IllegalStateException();
                // Redirect stack around just used link.
                if (child == null)
                    top = next.parent;
                else
                    child.parent = next.parent;
                next = next.parent;
                used = false;
            }
        };
    }

    @Override
    public boolean add(E e)
    {
        if (contains(e))
            return false;
        else
        {
            top = new Link<E>(top, e);
            return true;
        }
    }

    @Override
    public boolean isEmpty()
    {
        return (top == null);
    }

    @Override
    public void clear()
    {
        top = null;
    }

    @Override
    public boolean contains(Object e)
    {
        for (Link<E> link = top; link != null; link = link.parent)
        {
            if (e.equals(link.element))
                return true;
        }
        return false;
    }
}
