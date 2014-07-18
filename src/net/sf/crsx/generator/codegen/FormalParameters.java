/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen;
 

public interface FormalParameters extends Context
{

	/**
	 * Add formal parameter. 
	 * 
	 * <p>Usage: <blockquote>.param(type, variable) </blockquote> provided the variable is
	 * fresh. The variable will be bound in the scope of the declaration. 
	 * 
	 * This corresponds to:
	 * <ul>
	 * <li>In Java: <blockquote> </blockquote>
	 * <li>In C++:
	 * </ul>
	 * 
	 * @see ClassBody#method
	 * @param type of parameter
	 * @param name of parameter
	 * @return updated parameter list
	 */
	public FormalParameters param(Type type, LocalVariable name);
	
	/**
	 * Class body. Ends with {@link Block#methodDeclarationEnd()} 
	 * @return
	 */
	public Block body();

	/**
	 * 
	 * @see ClassBody#method
	 * @param exceptionNames list of exception names, or null for none
	 * @return block context for the method's statements
	 */
	public Block methodThrows(String exceptionNames);

}
