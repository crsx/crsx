// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.util.ArrayList;

/**
 * Base class for Construction Descriptor
 */
public abstract class ConstructionDescriptor
{
	
	// State
	
	/** result sort for descriptor (might be null) */
	final public SortDescriptor sortDescriptor;

	/** Current descriptor tag offset in sort (>0 for data, 0 for functions) */
	final public int sortoffset;

	/** Number of subterms (TODO: not needed) */
	final public int arity;

	/** Number of binders (TODO: not strictly needed) */
	// Additional (compare to C version)
	final public int bindercount;

	/** Offset in {@link Construction#binders} array of first binder for each argument */
	final public int[] binderoffset;

	// Constructor

	/**
	 * Constructs a sort-less construction
	 * 
	 * @param sortoffset Sort index in sort. 
	 * @param arity
	 * @param binderoffset
	 * @param index
	 * 
	 * @see SortDescriptor#constructors
	 */
	protected ConstructionDescriptor(int sortoffset, int arity, int bindercount, int[] binderoffset)
	{
		this.sortDescriptor = null;
		this.sortoffset = sortoffset;
		this.arity = arity;
		this.bindercount = bindercount;
		this.binderoffset = binderoffset;
	}

	/**
	 * 
	 * @param sortDescriptor
	 * @param sortoffset
	 * @param arity
	 * @param bindercount
	 * @param binderoffset
	 * @param index
	 */
	protected ConstructionDescriptor(SortDescriptor sortDescriptor, int sortoffset, int arity, int bindercount, int[] binderoffset,
	        int index)
	{
		this.sortDescriptor = sortDescriptor;
		this.sortoffset = sortoffset;
		this.arity = arity;
		this.bindercount = bindercount;
		this.binderoffset = binderoffset;

		if (sortDescriptor != null)
			this.sortDescriptor.constructors[index] = this;
	}

	/** Descriptor name */
	public abstract String name(Term term);
	
	/**
	 * Rewrite the term to get closer to a top level data descriptor and 
	 * return whether an updated term was sent to sink 
	 */
	public abstract boolean step(Sink sink, Term term, ArrayList<Crsx.ContextEntry> ancestors);
}