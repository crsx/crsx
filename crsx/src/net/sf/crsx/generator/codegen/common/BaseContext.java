/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import java.util.Map;

import net.sf.crsx.generator.codegen.ClassBody;
import net.sf.crsx.generator.codegen.Context;
import net.sf.crsx.generator.codegen.LocalVariable;

/**
 * 
 * @author villardl
 */
public class BaseContext implements Context
{
	// State

	/** Code gen output */
	protected StringBuilder builder;

	/** Parent context */
	protected BaseContext parent;

	/** Local variable in-scope. */
	protected Map<String, LocalVariable> variables;

	// Constructors

	protected BaseContext()
	{
		this.builder = new StringBuilder();
	}

	protected BaseContext(StringBuilder builder, Map<String, LocalVariable> variables)
	{
		this.parent = null;
		this.builder = builder;
		this.variables = variables;
	}

	protected BaseContext(BaseContext parent)
	{
		this.parent = parent;
		if (parent != null)
		{
			this.builder = parent.builder;
			this.variables = parent.variables;
		}
	}

	// Methods

	/** Gets output */
	public StringBuilder getOutput()
	{
		return builder;
	}

	/** Get parent context */
	public BaseContext getParent()
	{
		return parent;
	}

	/** Get the contextual class body (if any) */
	public ClassBody getContextualClassBody()
	{
		if (this instanceof ClassBody)
			return (ClassBody) this;
		return parent == null ? null : parent.getContextualClassBody();
	}

	// Implements Context

	public LocalVariable fresh(String name)
	{
		// TODO: optimizable
		int count = 0;
		String freshName = name;
		while (variables.get(freshName) != null)
			freshName = name + (count++);

		final LocalVariable lv = new BaseLocalVariable(freshName);
		variables.put(freshName, lv);
		return lv;
	}

	public LocalVariable use(String name)
	{
		return new BaseLocalVariable(name);
	}

	// Overrides

	@Override
	public String toString()
	{
		return getOutput().toString();
	}
}
