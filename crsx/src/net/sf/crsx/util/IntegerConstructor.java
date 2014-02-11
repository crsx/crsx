/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.util;

import net.sf.crsx.CRS;

/**
 * Plain implementation of constructor based on just a long integer.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: IntegerConstructor.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
final public class IntegerConstructor extends AbstractLiteralConstructor
{
	// State.

	/** The constructor symbol. */
	final private long integer;

	// Constructor.

	/**
	 * Create constructor for an integer.
	 */
	public IntegerConstructor(long integer)
	{
		this.integer = integer;
	}

	// Constructor...

	public String symbol()
	{
		return Long.toString(integer);
	}

	public String literalSort()
	{
		return CRS.NUMERIC_SORT;
	}
	
	public Object object()
	{
		return Long.valueOf(integer);
	}

	public int hashCode()
	{
		return (int) integer;
	}
}
