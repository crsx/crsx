/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import net.sf.crsx.generator.codegen.FormalParameters;
import net.sf.crsx.generator.codegen.MethodSignature;
import net.sf.crsx.generator.codegen.Modifier;
import net.sf.crsx.generator.codegen.Type;

/**
 * 
 * @author villardl
 */
public class BaseMethodSignature extends BaseContext implements MethodSignature
{
	// State

	/** Method name */
	final protected String name;

	/** Method modifiers */
	final protected Modifier[] modifiers;

	// Constructors

	/**
	 * Constructor a method signature
	 * @param modifiers  
	 * @param name of the method
	 */
	protected BaseMethodSignature(BaseContext parent, Modifier[] modifiers, String name)
	{
		super(parent);

		this.name = name;
		this.modifiers = modifiers;
	}

	// Implements MethodSignature

	public FormalParameters returnType(Type type)
	{
		if (modifiers != null)
		{
			for (int i= 0;i < modifiers.length; i ++)
			{
				if (i > 0)
					getOutput().append(' ');
				switch (modifiers[i])
				{
					case STATIC:
						getOutput().append("static");
				} 
			}
			getOutput().append(' ');
		}
		
		getOutput().append(type == null ? "void" : type).append(' ').append(name).append('(');
		return new BaseFormalParameters(this);
	}
}
