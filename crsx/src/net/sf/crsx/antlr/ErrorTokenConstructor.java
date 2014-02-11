/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.antlr;

import org.antlr.runtime.RecognitionException;
import org.antlr.runtime.Token;
import org.antlr.runtime.TokenStream;

/**
 * Fake token constructor for errors.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: ErrorTokenConstructor.java,v 3.0 2012/12/17 18:04:48 krisrose Exp $
 */
class ErrorTokenConstructor extends CommonTokenConstructor
{
	// State.

	private static final long serialVersionUID = -3991922321141127297L;
	
	/** Where tokens come from. */
	final TokenStream input;
	
	/** Limits of error. */
	final Token start, stop;
	
	/** Exception base. */
	RecognitionException e;

	// Constructor.
	
	/**
	 * Create error container.
	 * @param factory owning it all
	 * @param input where tokens come from
	 * @param start token of error
	 * @param stop token of error
	 * @param e exception base
	 */
	public ErrorTokenConstructor(TreeAdaptorFactory factory, TokenStream input, Token start, Token stop, RecognitionException e)
	{
		super(factory, ERROR_TYPE);
		assert input != null && start != null;
		this.input = input;
		this.start = start;
		this.stop = stop;
		this.e = e;
	}
	
	// Constructor...
	
	public String symbol()
	{
		return input.toString(start, stop);
	}

	// Object overrides.
	
	@Override
	public String toString()
	{
		int startLine = start.getLine();
		int stopLine = stop.getLine();
		String text = input.toString(start, stop);
		return input.getSourceName()
				+ ", l:"
				+ startLine
				+ (startLine != stopLine ? "-" + stopLine : ", p:"
						+ start.getCharPositionInLine() + "-" + start.getCharPositionInLine()) + ": " + text;
	}

	@Override
	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
		result = prime * result + ((start == null) ? 0 : start.hashCode());
		result = prime * result + ((stop == null) ? 0 : stop.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj)
	{
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof ErrorTokenConstructor))
			return false;
		ErrorTokenConstructor other = (ErrorTokenConstructor) obj;
		return (start.equals(other.start) && stop.equals(other.stop));
	}
}
