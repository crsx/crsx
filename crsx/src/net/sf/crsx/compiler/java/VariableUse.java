// Copyright (c) 2010, 2012 IBM Corporation.
package net.sf.crsx.compiler.java;

/**
 * Variable use term.
 * 
 * @author villardl
 */
public class VariableUse extends Term
{
	// State
	
	/** Variable being used. */
	final public Variable variable;  
	
	// Constructor 
	
	public VariableUse(Variable variable)
    {
	    this.variable = variable;
    }

	// Overrides
	
	protected void unlink()
	{
		assert nr > 0;

		nr--;
	}

	// Debugging
	
	public String toString()
	{
		return variable.toString();
	}
}
