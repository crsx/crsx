/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import java.util.ArrayList;
import java.util.List;

/**
 * Stack of values of some type.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class StackOf<T>
{
    // State.
    
    private int tos; // first index that is not used
    private final int chunk; // size increment
    private T[] stack; // actual stack
    
    /** Create stack. */
    @SuppressWarnings("unchecked")
    public StackOf()
    {
        chunk = 100;
        tos = 0;
        stack = (T[]) new Object[chunk];
    }
    
    // Methods.

    /** Push a value on the stack. */
    @SuppressWarnings("unchecked")
    public void push(T t)
    {
        if (tos == stack.length)
        {
            T[] newStack = (T[]) new Object[stack.length + 50];
            System.arraycopy(stack, 0, newStack, 0, tos);
            stack = newStack;
        }
        stack[tos++] = t;
    }
    
    /** Pop a value off the stack. */
    public T pop()
    {
        assert tos > 0;
        return stack[--tos];
    }

    /** Peek at the top value of the stack. */
    public T top()
    {
        assert tos > 0;
        return stack[tos-1];
    }

    /** Poke value at top of stack. */
    public void poke(T t)
    {
        assert tos > 0;
        stack[tos-1] = t;
    }

    /** Stack size. */
    public int size()
    {
        return tos;
    }
    
    /** Whether empty. */
    public boolean isEmpty()
    {
        return tos == 0;
    }
    
    public String toString()
    {
    	List<T> list = new ArrayList<T>();
    	for (int i = 0; i < size(); ++i)
    		list.add(stack[i]);
    	return list.toString();
    }
}
