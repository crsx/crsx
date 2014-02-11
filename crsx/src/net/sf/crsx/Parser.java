/* Copyright © 2008,2010 IBM Corporation. */

package net.sf.crsx;

import java.io.IOException;
import java.io.Reader;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.util.ExtensibleMap;

/**
 * Instances permit creation of new CRSX terms from text.
 * Parsers must have a nullary constructor, and the first thing after construction is that the {@link #setFactory(Factory)} method is invoked.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Parser.java,v 3.4 2013/12/09 05:48:40 krisrose Exp $
 */
public interface Parser
{
	/** Name for location attribute. */
	final public static String
		TOKEN_FILE_LOCATION = "$FileLocation",
		TOKEN_LINE_LOCATION = "$LineLocation",
		TOKEN_COLUMN_LOCATION = "$ColumnLocation";
	
	final public static String
		TOKEN_FILE_LOCATION_WRAPPER = "STRING",
		TOKEN_LINE_LOCATION_WRAPPER = "STRING",
		TOKEN_COLUMN_LOCATION_WRAPPER = "STRING";

	/** The categories supported by this parser. May repeat categories and may not include null even if supported. */
	public Iterable<String> categories();

	/**
	 * All parsers for actual use must be retrieved by this method, providing a factory.
	 * Each parser retrieved in this way can be used once, and be aware that CRSX may keep several parsers running simultaneously.
	 * @param factory that controls the parser
	 */
	public Parser parser(Factory<? extends Term> factory);
	
	/**
	 * Read complete term from text and send it to a sink.
	 * Should parse terms created with {@link Term#appendTo(Appendable, Map, int, boolean, boolean, boolean, Set)}.
	 * @param sink to send the term that is read to
	 * @param category to parse (or null for the default or "?xml" for CRSX/XML)
	 * @param reader with term to parse - left ready to read text after the term
	 * @param unit to identify the source of the compilation unit (null for none)
	 * @param line number of the first line (1-based)
	 * @param column of the first column (1- based)
	 * @param bound variables that are bound in the context (null allowed if none)
	 * @return sink after it has been sent the read term
	 * @throws CRSException if the content of the reader cannot be interpreted as a term
	 * @throws IOException if an i/o error occurs
	 */
	public Sink parse(Sink sink, String category, Reader reader, String unit, int line, int column, ExtensibleMap<String, Variable> bound) throws CRSException, IOException;

	/** Set verbosity of parser (to track down grammar errors). */
	public void setParserVerbose(boolean verbose);

	/** Set whether parser includes properties that track the extent of each constructor. */
	public void setParserLocation(boolean captureLocations);
}
