// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

/**
 * Variable Term
 * 
 * @author villardl
 */
public class Variable  
{
	// Static Utilities

	// TODO: Not thread safe
	static private int stamp = 0;

	final static public Variable MAKE_VARIABLE(String basename, boolean bound, boolean linear)
	{
		int index = basename.indexOf('_');
		final String name;
		if (index == -1)
			name = basename + (++stamp);
		else
		{
			name = basename.substring(0, index + 1) + (++stamp);
		}
		return new Variable(name, bound, linear);
	}

	final static public Variable MAKE_BOUND_LINEAR_VARIABLE(String name)
	{
		return MAKE_VARIABLE(name, true, true);
	}

	final static public Variable MAKE_FRESH_LINEAR_VARIABLE(String name)
	{
		return MAKE_VARIABLE(name, false, true);
	}

	final static public Variable MAKE_BOUND_PROMISCUOUS_VARIABLE(String name)
	{
		return MAKE_VARIABLE(name, true, false);
	}

	final static public Variable MAKE_FRESH_PROMISCUOUS_VARIABLE(String name)
	{
		return MAKE_VARIABLE(name, false, false);
	}

	/** Unbind variable */
	final public static void UNBIND(Variable variable)
	{
		variable.bound = false;
	}

	/** Rebind variable */
	final public static void REBIND(Variable variable)
	{
		variable.bound = true;
	}
	
	/** Linear variable? */
	final public static boolean IS_LINEAR(Variable variable)
	{
		return variable.linear;
	}

	// State

	/** name...neither guaranteed to be globally unique nor the same as originally provided */
	final public String name;

	/** whether this variable is linear */
	public boolean linear;

	/** whether this variable is bound */
	public boolean bound;

	// Constructor

	private Variable(String name, boolean bound, boolean linear)
	{
		this.name = name;
		this.linear = linear;
		this.bound = bound;		
	}
	
	// Overrides
	
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		sb.append(name).append(linear ? "¹" : "").append(bound ? "!": "");
		return  sb.toString();
	}
}
