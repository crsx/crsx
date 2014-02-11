/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.Reader;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Parser;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Parser that generates a list of constant constructors, one per line, named as the contents of the line.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: LineParser.java,v 3.2 2013/12/09 05:48:39 krisrose Exp $
 */
public class LineParser implements Parser
{
	// State.

	/** Whether we report progress. */
	private boolean noisy;

	/** Whether we report the line number of each constructor. */
	private boolean enumerate;
	
	// Constructor.
	
	/**
	 * Create one.
	 */
	public LineParser()
	{}

	// Parser.

	public Parser parser(Factory<? extends Term> factory)
	{
		return this; // since no embedded parsers possible
	}
	
	public Sink parse(Sink sink, String category, Reader reader, String identifier, int firstLine, int firstColumn, ExtensibleMap<String, Variable> bound)
			throws CRSException, IOException
	{
		if (category != null)
			throw new UnsupportedOperationException("Line parser does not support categories.");
		
		boolean more = true;
		int character;
		StringBuilder line = new StringBuilder();
		int count = 0;
		Constructor cons = sink.makeConstructor(CRS.CONS_SYMBOL);
		Constructor nil = sink.makeConstructor(CRS.NIL_SYMBOL);
		while (more)
		{
			switch (character = reader.read())
			{
				case -1 :
					more = false;
				case '\n' : {
					sink = sink.start(cons);
					String text = line.toString();
					
					Constructor c = sink.makeLiteral(text, CRS.STRING_SORT);
					if (enumerate)
						c = Util.wrapWithLocation(sink, c, identifier, count + firstLine, 1);
					sink = sink.start(c).end();
					++count;
					if (noisy)
						System.out.println("Line "+count+": "+text);
					line = new StringBuilder();
					break;
				}
					
				default :
					line.append((char) character);
					break;
			}
		}
		sink = sink.start(nil).end();
		while (count-- > 0)
			sink = sink.end();
		return sink;
	}

	public Iterable<String> categories()
	{
		return new EmptyIterable<String>();
	}

	public void setEmbeddedParser(Parser subparser) throws CRSException
	{
		throw new CRSException("Line parser does not support embedded parser.");
	}

	public void setParserVerbose(boolean verbose)
	{
		noisy = verbose;
	}

	public void setParserLocation(boolean capture)
	{
		enumerate = capture;
	}
}
