/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import net.sf.crsx.generator.codegen.Type;

/**
 * 
 * @author villardl
 */
public class BaseType implements Type
{
	// State

	/**
	 * Type name
	 */
	final protected String name;

	/**
	 * Is this a primitive type?
	 */
	final protected boolean isPrimitive;
	 

	// Constructors

	public BaseType(String name, boolean isPrimitive)
	{
		this.name = name;
		this.isPrimitive = isPrimitive; 
	}

	// Overrides

	public String toString()
	{
		return name;
	}

	public boolean isPrimitive()
	{
		return isPrimitive;
	}

	public boolean isArray()
	{
		return false;
	}

	public Type getBaseType()
	{
		return null;
	}
}
