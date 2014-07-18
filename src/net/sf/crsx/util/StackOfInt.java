/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

/**
 * Stack of int values.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class StackOfInt
{
    private int tos; // first index that is not used
    private final int chunk;
    private int[] stack;
    
    /** Create stack of integers. */
    public StackOfInt()
    {
        chunk = 100;
        tos = 0;
        stack = new int[chunk];
    }

    public void push(int i)
    {
        if (tos == stack.length)
        {
            int[] newStack = new int[stack.length + chunk];
            System.arraycopy(stack, 0, newStack, 0, tos);
            stack = newStack;
        }
        stack[tos++] = i;
    }
    
    public int pop()
    {
        assert tos > 0;
        return stack[--tos];
    }
}
