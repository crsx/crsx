/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen;

/**
 * 
 * @author villardl
 */
public interface Type
{
	/**
	 * Whether or not this is a primitive type
	 * @return
	 */
	public boolean isPrimitive();
	
	/**
	 * Whether or not this is a array type
	 * @return
	 */
	public boolean isArray();
	
	/**
	 * Gets array base type or null.
	 * @return
	 */
	public Type getBaseType();
}
