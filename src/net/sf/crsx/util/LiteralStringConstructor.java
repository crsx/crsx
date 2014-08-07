/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Collection;
import java.util.Map;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Match;
import net.sf.crsx.Variable;

/**
 * Plain implementation of string literal.
 * The string is <em>interned</em> to make comparison fast.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: LiteralStringConstructor.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
final public class LiteralStringConstructor extends AbstractLiteralConstructor
{
	// State.

	/** The constructor symbol. */
	final private String symbol;

	// Constructor.

	/** Create constructor with specific symbol name. */
	public LiteralStringConstructor(String symbol)
	{
		this.symbol = symbol.intern();
	}

	// Constructor implementation...

	public String symbol()
	{
		return symbol;
	}

	public String literalSort()
	{
		return CRS.STRING_SORT;
	}
	
	public Object object()
	{
		return symbol();
	}

	public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		return symbol == that.symbol();
	}

	// Object...

	public boolean equals(Object that)
	{
		return that != null && symbol == ((Constructor) that).symbol();
	}
}
