/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import net.sf.crsx.Sink;
import net.sf.crsx.Term;

/**
 * Context builder as path of parent terms and subterm indices.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class ContextStack
{
    // State.
    
    private final int chunk; // array allocation increment size
    private int tos; // first index that is not used
    private Term[] parents; // list (from top to innermost) of parent term
    private int[] indices; // list (from top to innermost) of index of subterm
    
	private Term root;
	
    // Constructor.
    
    /** Create stack of integers. */
    public ContextStack()
    {
        chunk = 100;
        tos = 0;
        parents = new Term[chunk];
        indices = new int[chunk];
    }
    
    // Methods.
    
    /**
     * Extend the path with a new parent term and the index of one of its subterms.
     * @param parent to add
     * @param index to add
     */
    public void extend(Term parent, int index)
    {
        final int length = indices.length;
        if (tos == length)
        {
            int[] newIndices = new int[length + 50];
            System.arraycopy(indices, 0, newIndices, 0, tos);
            indices = newIndices;
            Term[] newParents = new Term[length + 50];
            System.arraycopy(parents, 0, newParents, 0, tos);
            parents = newParents;
        }
        indices[tos] = index;
        parents[tos] = parent;
        ++tos;
    }
    
    /** Is this the trivial context? */
    public boolean isTrivial()
    {
        return tos == 0;
    }
    
    /** Undo the most recent {@link #extend(Term, int)}. */
    public void unextend()
    {
        assert !isTrivial() : "Stack is empty!";
        parents[--tos] = null;
    }
    
    /** Last parent in path. */
    public Term lastParent()
    {
        return parents[tos-1];
    }
    
    /** Last index in path. */
    public int lastIndex()
    {
        return indices[tos-1];
    }
    
    /** 
     * Fill (and destroy) the context.
     * Leaves the context as "trivial".
     * @param filler to put in the hole
     * @return term obtained by filling the hole
     */
    public Term fill(Term filler)
    {
        while (!isTrivial())
        {
            final Term parent = lastParent();
            final int index = lastIndex();
            final Term sub = parent.sub(index);
            if (sub != filler)
            {
                Sink sink = parent.replaceSubSink(index);
                sink.copy(filler, true);
            }
            filler = parent;
            unextend();
        }
        return filler;
    }
    
    public Term getRoot()
	{
		return root;
	}

	public void setRoot(Term root)
	{
		this.root = root;
	}

    // Object.
    
    public String toString()
    {
    	StringBuilder b = new StringBuilder();
    	b.append(Integer.toString(tos)+":");
    	for (int i = 0; i < tos; ++i)
    		b.append(" "+Util.symbol(parents[i])+"."+indices[i]);
    	return b.toString();
    }
}
