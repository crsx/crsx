
package net.sf.crsx.compiler.java;

import java.util.ArrayList;

/**
 * Construction with no steps.
 * 
 * <p>PORT NOTE: only Java.
 * 
 * @author villardl
 */
final public class DataConstructionDescriptor extends ConstructionDescriptor
{
	// State
	
	/** Construction symbol */
	final protected String name;
	
	// Constructors

	public DataConstructionDescriptor(String name, SortDescriptor sortDescriptor, int sortoffset, int arity, int bindercount, int[] binderoffset, int index)
	{
		super(sortDescriptor, sortoffset, arity, bindercount, binderoffset, index);
		this.name = name;
	}

	// Overrides
	
	@Override
	final public String name(Term term)
	{
		return name;
	}

	@Override
	final public boolean step(Sink sink, Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		return false;
	}

}
