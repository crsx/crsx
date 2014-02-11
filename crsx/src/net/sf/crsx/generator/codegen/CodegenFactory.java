/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.generator.codegen;

/**
 * 
 * @author villardl
 */
public abstract class CodegenFactory
{
	
	/**
	 * Create a new standalone block. 
	 * @return
	 */
	public abstract Block newBlock();
	
	/**
	 * Create a new standalone class body. 
	 * @param classname  
	 * @return
	 */
	public abstract ClassBody newClassBody(String classname);
	
	/**
	 * Create a new class reference type.
	 * 
	 * <ul>
	 * <li>In Java: Classname
	 * <li>In C: Classname*
	 * </ul>
	 * 
	 * @param classname
	 * @return
	 */
	public abstract Type newClassReferenceType(String classname);
	
	/**
	 * Create a new array of reference type.
	 * 
	 * <ul>
	 * <li>In Java: Type[]
	 * <li>In C: Type*
	 * </ul>
	 * 
	 * @param classname
	 * @return
	 */
	public abstract Type newArrayReferenceType(Type type);
	
	/**
	 * Create a new primitive type.
	 * 
	 * <ul>
	 * <li>In Java: Name
	 * <li>In C: Name
	 * </ul>
	 * 
	 * @param name
	 * @return
	 */
	public abstract Type newPrimitiveType(String name);
}
