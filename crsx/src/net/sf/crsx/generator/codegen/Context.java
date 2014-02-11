/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen;


/** 
 * Context of the code currently under construction.
 */
public interface Context  
{
	/** Allocate unique local variable with the suggested name. */
	public LocalVariable fresh(String name);
	
	/** Use an existing variable */
	public LocalVariable use(String name);

}