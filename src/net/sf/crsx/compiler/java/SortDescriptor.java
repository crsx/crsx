// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

/**
 * Sort descriptor
 * 
 * @author villardl
 */
final public class SortDescriptor
{	
	
	// State

	/** Name of the sort */
	final public String name;

	/** Array of data constructor */
	final public ConstructionDescriptor[] constructors;

	/** Array of corresponding data constructor names */
	final public String[] constructorNames;

	/**  Array of corresponding internal data constructor names (for START and END macro *generation*) */
	final public String[] constructorInternalNames;

	/** Previous Sort Descriptor */
	final SortDescriptor previous;

	// Constructors

	public SortDescriptor(final String name, final int descriptorCount, final SortDescriptor previous)
	{
		this.name = name;
		this.constructors = new ConstructionDescriptor[descriptorCount];
		this.constructorNames = new String[descriptorCount];
		this.constructorInternalNames = new String[descriptorCount];
		this.previous = previous;
	}
	 

}
