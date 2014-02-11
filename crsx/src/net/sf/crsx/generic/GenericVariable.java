/* Copyright (c) 2006, 2007 IBM Corporation. */

package net.sf.crsx.generic;

import net.sf.crsx.Variable;
import net.sf.crsx.util.Util;

/**
 * Generic implementation of <em>variable</em> used by {@link GenericFactory}.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericVariable.java,v 3.4 2013/09/17 20:47:02 krisrose Exp $
 */
class GenericVariable implements Variable
{
    /**
     * Return fresh variable with specific {@link #name()} and {@link #promiscuous()} values.
     * @param name of variable
     * @param promiscuous whether multiple occurrences of variable permitted
     */
    static GenericVariable makeVariable(String name, boolean promiscuous)
    {
        return (promiscuous ? new GenericVariable(name) : new Linear(name));
    }
    /** Helper class to support variables with {@link #promiscuous()} false. */
    static class Linear extends GenericVariable
    {
        public Linear(String symbol)
        {
            super(symbol);
        }
        public boolean promiscuous()
        {
            return false;
        }
    }
    
	// State.
	
	/** Symbol. */
	String name;

	// Constructors.
	
	/**
	 * Create unique variable.
	 * @param name of variable (not semantically significant, may be modified)
	 */
	private GenericVariable(String name)
	{
		this.name = name;
	}

	// CRS.Variable implementation.

	public String name()
	{
		return name;
	}
	
	public boolean promiscuous()
	{
	    return true;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public boolean equals(Object that)
	{
		return this == that;
	}

    public int compareTo(Variable o)
    {
		return this.name().compareTo(o.name());
    }
	
	// Sic.
	
	public String toString()
	{
		return (promiscuous() ? "" : "\u00B9") + Util.externalizeVariable(name);
	}
}
