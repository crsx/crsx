/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;


import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringReader;
import java.io.Writer;
import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.CRSException;
import net.sf.crsx.util.LinkedExtensibleMap;

public class XPath2FIX
{
	/**
	 * @param args
	 * @throws CRSException 
	 * @throws IOException 
	 */
	public static void main(String[] args) throws CRSException, IOException
	{
		// Parse XPath
		//XPath2 parser = new XPath2();
	
		FromSink sink = new FromSink(null);
		StringReader reader = new StringReader("1");

		LinkedExtensibleMap<String, net.sf.crsx.Variable> bound = new LinkedExtensibleMap<String, net.sf.crsx.Variable>();
		Map<String, net.sf.crsx.Variable> free = new HashMap<String, net.sf.crsx.Variable>();
		//parser.parse(sink, "x_path", reader, bound, free);
		
		
		GeneratedCRSX crsx = new GeneratedCRSX(); 
		
		Writer writer = new PrintWriter(System.out);
		crsx.normalize(sink.term, new TextSink(writer));
		writer.flush();

	}

}
