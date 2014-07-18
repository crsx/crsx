/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.generator.codegen.Block;
import net.sf.crsx.generator.codegen.FormalParameters;
import net.sf.crsx.generator.codegen.LocalVariable;
import net.sf.crsx.generator.codegen.Type;

/**
 * 
 * @author villardl
 */
public class BaseFormalParameters extends BaseContext implements FormalParameters
{

	// Constructors

	protected BaseFormalParameters(BaseContext parent)
	{
		super(parent);

		// Start a new variable scope
		this.variables = new HashMap<String, LocalVariable>();
	}

	// Implements FormalParameters

	public Block body()
	{
		getOutput().append(") {");
		return new BaseBlock(this);
	}

	public Block methodThrows(String exceptionNames)
	{
		getOutput().append(')');
		if (exceptionNames != null)
			getOutput().append(exceptionNames);
		getOutput().append("\n{");
		return new BaseBlock(this);
	}

	public FormalParameters param(Type type, LocalVariable name)
	{
		getOutput().append(type).append(' ').append(name);
		return new NextBaseFormalParameters(parent, variables);
	}

	// Inner classes

	class NextBaseFormalParameters extends BaseFormalParameters
	{
		// Constructors

		protected NextBaseFormalParameters(BaseContext parent, Map<String, LocalVariable> variables)
		{
			super(parent);

			this.variables = variables;
		}

		// Overrides

		@Override
		public FormalParameters param(Type type, LocalVariable name)
		{
			getOutput().append(',').append(type).append(' ').append(name);
			return this;
		}

	}

}
