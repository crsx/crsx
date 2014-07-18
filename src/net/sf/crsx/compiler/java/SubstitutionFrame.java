// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.util.Arrays;

/**
 * 
 * @author villardl
 */
public class SubstitutionFrame
{
	// Static
	
	final public static boolean[] RENAME_ALL = new boolean[0];
	
	
	// State
	
	/** Parent frame (or null) */
	SubstitutionFrame parent;

	/** Number of variable-substitute pairs in all parent frames */
	int parentCount;

	/** number of variable-substitute pairs in this frame */
	int count;

	/** Count redex variables to substitute, in order */
	Variable[] variables;

	/**  count redex subterms to substitute for variables, in order */
	Term[] substitutes;

	/**  Weakenings for each substitute */
	VariableSetLink[][] weakenings;

	/** Whether substitute is caused by a binder renaming. */
	boolean[] renamings;
	 

	// Constructor

	
	public SubstitutionFrame(SubstitutionFrame parent, int parentCount, int count, Variable[] variables, Term[] substitutes)
	{
		this.parent = parent;
		this.parentCount = parentCount;
		this.count = count;
		this.variables = variables;
		this.substitutes = substitutes;
		this.weakenings = null;
		this.renamings = null; // rename none 
	}
	
	public SubstitutionFrame(SubstitutionFrame parent, int parentCount, int count, Variable[] variables, Term[] substitutes, boolean[] renamings)
	{
		this.parent = parent;
		this.parentCount = parentCount;
		this.count = count;
		this.variables = variables;
		this.substitutes = substitutes;
		this.weakenings = null;
		this.renamings = renamings;
	}

	// Overrides

	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		sb.append("{ parent :").append(parent == null ? "<no parent>" : parent.toString()).append(", parentCount :").append(
		        parentCount).append(", count:").append(count).append(", variables:").append(Arrays.toString(variables)).append(
		        ", substitutes:").append(Arrays.toString(substitutes)).append("}");
		return sb.toString();
	}

}
