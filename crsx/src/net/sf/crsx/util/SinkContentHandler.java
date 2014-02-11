/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.Reader;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Parser;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

import org.xml.sax.Attributes;
import org.xml.sax.Locator;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

/**
 * SAX content handler that interprets XML representation of term and sends it to a {@link Sink}.
 * The XML representation is compatible (and documented) with {@link SAXSink}.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class SinkContentHandler extends DefaultHandler
{
	// State.

	/** The target sink. */
	private Sink sink;
	
	/** Parser for property terms or null for constants? */
	final private Parser parser;

	/** The most recent locator. */
	private Locator locator;

	/** Helper class with actions associated to events. */
	private abstract class Handler
	{
		/** Map bound variable names to actual variables. */
		final ExtensibleMap<String, Variable> contextBound;
		ExtensibleMap<String, Variable> nextBound;
		/** Construct handler */
		Handler(ExtensibleMap<String, Variable> bound)
		{
			this.contextBound = bound;
			this.nextBound = bound;
		}
		/** Action before each child element of top element. */
		void beforeChild()
		{}
		/** Action for text child of top element. */
		void characters(char ch[], int start, int length)
		{
			nextBound = contextBound;
		}
		/** Start element of child. */
		void startElement(String uri, String localName, String qName, Attributes atts) throws SAXException
		{
			initialStartElement(uri, localName, qName, atts, nextBound);
			nextBound = contextBound;
		}
		/** Action for the end of top element. */
		void end()
		{}
	}

	/** Stack of handlers for children and end events. */
	final StackOf<Handler> stack = new StackOf<Handler>();

	/** Map variable names to actual variables. */
	final ExtensibleMap<String, Variable> initiallyBound;

	// Constructor.

	/**
	 * Create handler for XML form.
	 * @param sink target for the term
	 * @param parser for embedded terms (or null to prevent parsing)
	 * @param bound variables that are bound in the context (null allowed if none)
	 */
	public SinkContentHandler(Sink sink, Parser parser, ExtensibleMap<String, Variable> bound, Map<String, Variable> free)
	{
		this.sink = sink;
		this.parser = parser;
		this.initiallyBound = (bound != null ? bound : LinkedExtensibleMap.EMPTY_SCOPE);
	}

	// Methods.
	
	/** Get the sink (and invalidate the content handler). */
	public Sink getSink()
	{
		Sink s = sink;
		sink = null;
		return s;
	}
	
	/** Default processing of child start element. */
	void initialStartElement(String uri, String localName, String qName, final Attributes atts, final ExtensibleMap<String, Variable> bound) throws SAXException
	{
		// Emit appropriate events and push a handler for any children onto the stack.

		// The real stuff!
		if (!stack.isEmpty())
			stack.top().beforeChild();

		if (uri.equals(CRS.URI))
		{
			// Handle special crs:* elements.
			
			if (localName.equals(SAXSink.SEQUENCE))
			{
				// <crs:s> elements </crs:s>
				// A $Cons/$Nil sequence of children
				stack.push(new Handler(bound)
				{
					int length; // of sequence
					@Override
					void beforeChild()
					{
						++length;
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL));
					}
					@Override
					void end()
					{
						sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end();
						for (int i = 0; i < length; ++i)
							sink = sink.end();
					}
				});
			}
			else if (localName.equals(SAXSink.BINDER))
			{
				// <crs:b> <v:name/>* </crs:b>
				// List of binders for following child.
				stack.push(new Handler(bound)
				{
					List<Variable> variables = new ArrayList<Variable>(); // bound variables
					boolean nested; // handler deals with *both* outer (b) and inner (v) events...
					@Override
					void startElement(String uri, String localName, String qName, Attributes atts) throws SAXException
					{
						// Handle start of v:name child.
						if (!uri.equals(SAXSink.VARIABLE_URI))
							error(SAXSink.BINDER + " can only have CRSX variable (" + SAXSink.VARIABLE_URI + ") children");
						Variable v = sink.makeVariable(localName, true);
						nextBound = nextBound.extend(localName, v); // so uses are properly resolved!
						variables.add(v);
						nested = true; // so end() below just ends v:name
					}
					@Override
					void end()
					{
						if (nested)
							nested = false; // it was just v:name
						else
						{
							// Ending the crs:b
							Variable[] vs = new Variable[variables.size()];
							variables.toArray(vs);
							sink = sink.binds(vs); // send binders!
						}
					}
				});
			}
			else 	if (localName.equals(SAXSink.CONSTANT))
			{
				String tag = atts.getValue(CRS.URI, SAXSink.NAME);
				if (tag == null)
				{
					// <crs:c> text </crs:c>
					// The 'text' as a constant.
					stack.push(new Handler(bound)
					{
						StringBuilder text = new StringBuilder();
						@Override
						void beforeChild()
						{
							error(SAXSink.CONSTANT + " element cannot have children");
						}
						@Override
						void characters(char[] chars, int start, int length)
						{
							text.append(chars, start, length);
						}
						@Override
						void end()
						{
							String string = text.toString();
							if (string.startsWith("_"))
								string = string.substring(1, string.length()-1);
							Constructor c = sink.makeConstructor(string);
							c = propertize(c, atts, bound);
							sink = sink.start(c).end();
						}
					});
				}
				else
				{
					// <crs:c crs:name="C"> text </crs:c>
					// Encodes C['text'] ("wrapped" constant).
					Constructor c = sink.makeConstructor(tag);
					c = propertize(c, atts, bound);
					sink = sink.start(c);
					//
					stack.push(new Handler(bound)
					{
						StringBuilder text = new StringBuilder();
						@Override
						void beforeChild()
						{
							error(SAXSink.CONSTANT + " element cannot have children");
						}
						@Override
						void characters(char[] chars, int start, int length)
						{
							text.append(chars, start, length);
						}
						@Override
						void end()
						{
							String string = text.toString();
							if (string.startsWith("_"))
								string = string.substring(1, string.length()-1);
							Constructor c = sink.makeConstructor(string);
							sink = sink.start(c).end();
							sink = sink.end();
						}
					});
				}
			}
		}
		else if (uri.equals(SAXSink.VARIABLE_URI))
		{
			// <v:name/>
			// Variable use.
			Variable v = variable(localName, bound);
			sink = sink.use(v);
			//
			stack.push(new Handler(bound)
			{
				@Override
				void beforeChild()
				{
					error("Variable element cannot have content");
				}
				@Override
				void characters(char[] chars, int start, int length)
				{
					error("Variable element cannot have content");
				}
				@Override
				void end()
				{}
			});
		}
		else
		{
			// Other elements are constructor wrappers.
			Constructor c = sink.makeConstructor(unnamify(localName));
			c = propertize(c, atts, bound);
			sink = sink.start(c);
			stack.push(new Handler(bound)
			{
				@Override
				void beforeChild()
				{}
				@Override
				void end()
				{
					sink = sink.end();
				}
			});
		}
	}

	// Helpers.

	/**
	 * Integrate attributes into constructor as properties.
	 * @param c constructor to extend
	 * @param atts attributes with property values
	 * @param bound names of variables already bound in context
	 * @return constructor extended with properties in the attributes
	 */
	private Constructor propertize(Constructor c, Attributes atts, ExtensibleMap<String, Variable> bound)
	{                                                                                       
		Map<String, Term> namedProperties = new HashMap<String,Term>();
		Map<Variable, Term> variableProperties = new HashMap<Variable, Term>();
		for (int i = 0; i < atts.getLength(); ++i)
		{
			String uri = atts.getURI(i);
			String name = atts.getLocalName(i);
			String value = atts.getValue(i);
			if (uri.equals(SAXSink.VARIABLE_URI))
			{
				Variable variable = variable(name, bound);
				variableProperties.put(variable, parse(value));
			}
			else if (!uri.equals(CRS.URI))
			{
				namedProperties.put(name, parse(value));
			}
		}
		if (!namedProperties.isEmpty() && !variableProperties.isEmpty())
			c = new PropertiesConstructor(sink, c, namedProperties, variableProperties);
		return c;
	}
	
	/** Helper to find properly scoped variable for name. */
	private Variable variable(String name, ExtensibleMap<String, Variable> bound)
	{
		Variable variable = bound.get(name);
		if (variable == null)
		{
			// Not bound...perhaps free?
			variable = sink.freeVariable(name, true, true);
		}
		return variable;
	}

	/** Helper to parse a term. */
	private Term parse(String text)
	{
		try
		{
			Reader reader = new StringReader(text);
			Buffer buffer = new Buffer(sink);
			Sink afterParse = parser.parse(buffer.sink(), null, reader, null, 1, 1, null);
			if (afterParse != null)
				error("Garbage at end of property " + text);
			return buffer.term(true);
		}
		catch (CRSException e)
		{
			error("Property " + text + " error: " + e.getMessage());
		}
		catch (IOException e)
		{
			error("Property " + text + " error: " + e.getMessage());
		}
		return null; // not reached
	}

	/** Reverse the encoding of {@link SAXSink#namify(String)}. */
	String unnamify(final String name)
    {
        StringBuilder b = new StringBuilder();
        int i = 0, z = name.length();
        while (i < z)
        {
        	char c = name.charAt(i++);
        	if (c == '_')
        	{
        		c = name.charAt(i);
        		if (c == '_')
        			b.append('_');
        		else
        		{
        			int e = name.indexOf('_', i);
        			if (e < 0) error(name + " is not a proper CRSXML encoded name");
        			c = (char) Integer.parseInt(name.substring(i, e));
        			i = e+1;
        		}
        	}
        	b.append(c);
        }
        return b.toString();
    }

	/** Report error in the XML. */
	private void error(String mess)
	{
		throw new RuntimeException("CRSXML error (" + locator + "): " + mess);
	}

	// ContentHandler...

	public void setDocumentLocator(Locator locator)
	{
		this.locator = locator;
	}

	public void startDocument() throws SAXException
	{}

	public void endDocument() throws SAXException
	{}

	public void startPrefixMapping(String prefix, String uri) throws SAXException
	{}

	public void endPrefixMapping(String prefix) throws SAXException
	{}

	public void startElement(String uri, String localName, String qName, Attributes atts) throws SAXException
	{
		if (!stack.isEmpty())
			stack.top().startElement(uri, localName, qName, atts);
		else
			initialStartElement(uri, localName, qName, atts, initiallyBound);
	}
	
	public void endElement(String uri, String localName, String qName) throws SAXException
	{
		stack.pop().end();
	}

	public void characters(char ch[], int start, int length) throws SAXException
	{
		if (!stack.isEmpty())
			stack.top().characters(ch, start, length);
	}

	public void ignorableWhitespace(char ch[], int start, int length) throws SAXException
	{}

	public void processingInstruction(String target, String data) throws SAXException
	{}

	public void skippedEntity(String name) throws SAXException
	{}
}
