/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.util;

import java.math.BigDecimal;
import java.util.Map;

import net.sf.crsx.CRS;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Variable;

/**
 * Plain implementation of constructor based on just a long integer.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: BigDecimalConstructor.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
final public class BigDecimalConstructor extends AbstractLiteralConstructor
{
	// State.

	/** The constructor symbol. */
	final private BigDecimal value;

	// Constructor.

	/**
	 * Create constructor for big number.
	 */
	public BigDecimalConstructor(BigDecimal big)
	{
		value = big;
	}

	// Constructor...

	public String symbol()
	{
		return value.toString();
	}

	public String literalSort()
	{
		return CRS.NUMERIC_SORT;
	}
	
	public Object object()
	{
		return value;
	}

	public void javaInvokeStart(SourceBuilder java, String sinkName, Map<Variable, String> variable2java)
	{
		java.wrapExpression("", ".start(" + sinkName + ".makeLiteral(new java.math.BigDecimal(" + Util.quoteJava(symbol()) + "), CRS.NUMERIC_SORT))");
	}
}
