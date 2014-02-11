/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.pg;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.generic.GenericFactory;

/**
 * Helper for creating CRS parsers.
 * 
 * <h4>Usage</h4>
 *  
 * <quote>
 * java -jar crsx.jar net.sf.crsx.pg.PG [-html] [-constants] [-serializer] [-source=sourcedir] [-parseroption] inputURL
 * </quote>
 * Produces a parser generator file from the PG specification retrieved from the inputURL (with base file:.). 
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: PG.java,v 3.0 2012/12/17 18:04:56 krisrose Exp $
 */
public class PG
{
	/**
	 * Generate CRS parser and optionally documentation.
	 * @param args command line arguments (see Usage)
	 */
	public static void main(String args[])
	{
		String message = null;
		try
		{
		    boolean createHtml = false;
		    boolean createConstants = false;
            boolean createSerializer = false;
		    String source = ".";
		    String inputUrl = null;

		    // Option defaults.
		    final Map<String, String> parserOptions = new HashMap<String, String>();
		    parserOptions.put("STATIC", "false");
		    parserOptions.put("JDK_VERSION", "\"1.5\"");
		    parserOptions.put("ERROR_REPORTING", "true");
		    parserOptions.put("BUILD_PARSER", "true");
		    parserOptions.put("BUILD_TOKEN_MANAGER", "true");
		    parserOptions.put("FORCE_LA_CHECK", "true");
		    parserOptions.put("SANITY_CHECK ", "true");
		    
		    for (int index = 0; index < args.length; ++index)
		    {
		        String option = args[index];
		        if (option.startsWith("-html"))
		            createHtml = true;
		        else if (option.startsWith("-constants"))
		            createConstants = true;
                else if (option.startsWith("-serializer"))
                    createSerializer = true;
		        else if (option.startsWith("-source="))
		            source = option.substring(8);
                else if (option.matches("-[A-Z_0-9]+=.+"))
                    parserOptions.put(option.substring(1, option.indexOf('=')), option.substring(option.indexOf('=')+1));
		        else if (!option.startsWith("-"))
		            inputUrl = option;
		        else
		            throw new IllegalArgumentException("Unknown option: " + option);
		    }
		    
            URL url = new URL(new URL("file:."), inputUrl);
            new PGParser(url.openStream())
                .Grammar(new GenericFactory(), inputUrl, source, createHtml, createConstants, createSerializer, parserOptions);
			return;
		}
		catch (MalformedURLException e)
		{
			message = e.getMessage();
		}
		catch (IOException e)
		{
			message = e.getMessage();
		}
		catch (ParseException e)
		{
			message = e.getMessage();
		}
		catch (IllegalArgumentException e)
		{
		    message = e.getMessage();
		}
		System.err.println("Usage: PG input-url [output-file]"+(message==null?"":" ("+message+")"));
		System.exit(1);
	}
}
