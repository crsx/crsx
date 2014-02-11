/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.generator.codegen;
 
/**
 * 
 * @author villardl
 */
public interface ClassBody extends Context
{
	/**
	 * Add method member to class.
	 * <p>
	 * Usage: the following invocation adds a method declaration to a ClassBody instance:
	 * 
	 * <blockquote>.methodDeclaration("Comment", "test"). <i>returnType </i>. <i>param(type <sub>i </sub>,
	 * name <sub>i </sub>) </i>* .methodThrows("TestException"). <i>Block </i> .declarationEnd() </blockquote>
	 * 
	 * The MethodSignature will set the return type. This corresponds to
	 * <ul>
	 * <li>in Java: <blockquote>TODO </blockquote>
	 * <li>in C++:
	 * </ul>
	 * 
	 * @param comment javadoc comment describing the method (or null) 
	 * @param modifiers  
	 * @param name of the method
	 * @return method signature context
	 */
	public MethodSignature methodDeclaration(String comment, Modifier[] modifiers, String name);
}
