/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.generator.codegen.common;

import net.sf.crsx.generator.codegen.ClassBody;
import net.sf.crsx.generator.codegen.MethodSignature;
import net.sf.crsx.generator.codegen.Modifier;

/**
 * 
 * @author villardl
 */
public class BaseClassBody extends BaseContext implements ClassBody
{
	// State
	
	/** Classname */
	final protected String classname;
	
	// Constructor
	
	/** 
	 * Constructs a standalone class body 
	 * @param classname 
	 */
	public BaseClassBody(String classname)
	{
		super();
		
		this.classname = classname;
	}
	
	// Implements ClassBody


	public MethodSignature methodDeclaration(String comment, Modifier[] modifiers, String name)
	{ 
		return new BaseMethodSignature(this, modifiers, name);
	}

}
