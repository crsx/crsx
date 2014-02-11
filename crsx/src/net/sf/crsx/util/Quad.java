/* Copyright © 2010, 2012 IBM Corporation. */

package net.sf.crsx.util;


/**
 * Utility to return triple of values.
 * Equal when the components are equal.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Quad.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class Quad<One, Two, Three, Four> implements Cloneable
{
	// State.
	
	/** First component. */
	private One one;
	/** Second component. */
	private Two two;
	/** Third component. */
	private Three three;
	/** Fourth component. */
	private Four four;
	
	// Constructor.
	
	/** Create triple with the specified values. */
	public Quad(One one, Two two, Three three, Four four)
	{
		this.one = one;
		this.two = two;
		this.three = three;
		this.four = four;
	}
	
	// Methods.
	
	/** First component. */
	public One one() { return one; }
	/** Second component. */
	public Two two() { return two; }
	/** Third component. */
	public Three three() { return three; }
	/** Fourth component. */
	public Four four() { return four; }

	/** Set first component. */
	public void setOne(One value) { one = value; }
	/** Set second component. */
	public void setTwo(Two value) { two = value; }
	/** Set third component. */
	public void setThree(Three value) { three = value; }
	/** Set fourth component. */
	public void setFour(Four value) { four = value; }

	// Object...

    @Override
	public boolean equals(Object that)
	{
		if (this == that)
			return true;
		Quad<?, ?, ?,?> p = (Quad<?, ?, ?,?>) that;
		return (one == p.one || (one != null && one.equals(p.one)))
			&& (two == p.two || (two != null && two.equals(p.two)))
			&& (three == p.three || (three != null && three.equals(p.three)))
			&& (four == p.four || (four != null && four.equals(p.four)));
	}

    @Override
	public int hashCode()
	{
		return (one == null ? 0 : one.hashCode())
			+ (two == null ? 0 : two.hashCode())
			+ (three == null ? 0 : three.hashCode())
			+ (four == null ? 0 : four.hashCode())	;
	}

    @Override
	public String toString()
	{
		return "(" + one + "," + two + "," + three + "," + four + ")";
	}
}
