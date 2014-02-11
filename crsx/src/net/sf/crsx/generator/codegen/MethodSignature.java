/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen;

/**
 * 
 * @author villardl
 */
public interface MethodSignature extends Context
{

	/**
	 * Sets the return type of the method and returns the formal parameter list construction.
	 * 
	 * @param type the return type of the method, or null if the method returns nothing (void)
	 * @see methodDeclaration, constructorDeclaration
	 */
	public FormalParameters returnType(Type type);

}
