/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Map;

import net.sf.crsx.CRS;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Variable;

/**
 * Plain implementation of constructor based on just a long integer.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DoubleConstructor.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
final public class DoubleConstructor extends AbstractLiteralConstructor
{
	// State.

	/** The constructor symbol. */
	final private double value;

	// Constructor.

	/**
	 * Create constructor for an integer.
	 */
	public DoubleConstructor(double d)
	{
		this.value = d;
	}

	// Constructor...

	public String symbol()
	{
		return Double.toString(value);
	}

	public String literalSort()
	{
		return CRS.NUMERIC_SORT;
	}
	
	public Object object()
	{
		return Double.valueOf(value);
	}

	public void javaInvokeStart(SourceBuilder java, String sinkName, Map<Variable, String> variable2java)
	{
		java.wrapExpression("", ".start(" + sinkName + ".makeLiteral(Double.valueOf(" + value + "), CRS.NUMERIC_SORT))");
	}
}
