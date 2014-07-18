/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import net.sf.crsx.generator.codegen.LocalVariable;

/**
 * Common implementation of {@link LocalVariable}
 * 
 * @author villardl
 */
public class BaseLocalVariable implements LocalVariable
{
	/** Unique variable name */
	final protected String name;

	// Constructors

	BaseLocalVariable(String name)
	{
		this.name = name;
	}

	// Implements LocalVariable
	
	public String getName()
	{
		return this.name;
	}

	@Override
	public String toString()
	{
		return name;
	} 

}
