/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.Reader;

import net.sf.crsx.CRSException;
import net.sf.crsx.Factory;
import net.sf.crsx.Parser;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Delegates to another parser.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegateParser.java,v 3.1 2013/12/09 05:48:39 krisrose Exp $
 */
public abstract class DelegateParser implements Parser
{
	/** The parser that this one delegates to. */
	protected abstract Parser delegate();
	
	// Parser...
	
	public Parser parser(Factory<? extends Term> factory)
	{
		return delegate().parser(factory);
	}
	
	public Sink parse(Sink sink, String category, Reader reader, String unit, int line, int column, ExtensibleMap<String, Variable> bound) throws CRSException, IOException
	{
		return delegate().parse(sink, category, reader, unit, line, column, bound);
	}
    
	public void setParserVerbose(boolean verbose)
	{
		delegate().setParserVerbose(verbose);
	}

	public void setParserLocation(boolean captureLocations)
	{
		delegate().setParserLocation(captureLocations);
	}

	public Iterable<String> categories()
	{
		return delegate().categories();
	}
}
