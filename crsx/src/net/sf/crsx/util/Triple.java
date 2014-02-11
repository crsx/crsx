/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.util;

/**
 * Utility to return triple of values.
 * Equal when the components are equal.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Triple.java,v 3.0 2012/12/17 18:04:59 krisrose Exp $
 */
public class Triple<One, Two, Three> implements Cloneable
{
	// State.
	
	/** First component. */
	final private One one;
	/** Second component. */
	final private Two two;
	/** Third component. */
	private Three three;
	
	// Constructor.
	
	/** Create triple with the specified values. */
	public Triple(One one, Two two, Three three)
	{
		this.one = one;
		this.two = two;
		this.three = three;
	}
	
	// Methods.
	
	/** First component. */
	public One one() { return one; }
	/** Second component. */
	public Two two() { return two; }
	/** Third component. */
	public Three three() { return three; }
	/** Set the third component. */
	public void setThree(Three three)
	{
		this.three = three;
	}
	
	// Object...

    @Override
	public boolean equals(Object that)
	{
		if (this == that)
			return true;
		Triple<?, ?, ?> p = (Triple<?, ?, ?>) that;
		return (one == p.one || (one != null && one.equals(p.one)))
			&& (two == p.two || (two != null && two.equals(p.two)))
			&& (three == p.three || (three != null && three.equals(p.three)));
	}

    @Override
	public int hashCode()
	{
		return (one == null ? 0 : one.hashCode())
			+ (two == null ? 0 : two.hashCode())
			+ (three == null ? 0 : three.hashCode());
	}

    @Override
	public String toString()
	{
		return "(" + one + "," + two + "," + three + ")";
	}
}
