/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.OutputStream;
import java.io.Writer;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.sax.SAXTransformerFactory;
import javax.xml.transform.sax.TransformerHandler;
import javax.xml.transform.stream.StreamResult;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Factory;
import net.sf.crsx.Maker;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

import org.xml.sax.ContentHandler;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.AttributesImpl;

/**
 * Sink that sends a SAX event representation of CRSX term to a SAX {@link ContentHandler}.
 * (The companion {@link SinkContentHandler}, used by the standard parser's "XML" category, can read such terms back.)
 * The representation is quite naive.
 * <ul>
 * 
 * <li>The prefix crs: (really {@link #CRS_PREFIX}) is used for internal names in the {@link CRS#URI} namespace
 * 		and v {@link #VARIABLE_PREFIX} is used for variable names in the {@link #VARIABLE_URI} namespace.
 * 		<p>
 * 
 * <li>Constructors become element tags (with subterm binders and subterms as children), with two exceptions:
 *		<ul>
 *		<li>CRSX sequences (using $Cons/$Nil) are translated to single  &lt;crs:s&gt;...&lt;/crs:s&gt; elements (really {@link #SEQUENCE})
 *			with the sequence members providing the child elements.
 *		<li>If a constructor name is in the provided "wrapper" set then it is printed as a
 *			&lt;crs:c crs:name="<em>wrapper</em>"&gt;<em>text</em>&lt;/crs:c&gt; element
 *			(really {@link #CONSTANT} tag with {@link #NAME} attribute,)
 *			where the text is the constructor of the single constant child of the wrapper construction.
 * 		</ul>
 * 		<p>
 * 
 * <li>Variables binders become constant terms of the form &lt;crs:b&gt; ... &lt;crs:b&gt; (really {@link #BINDER})
 * 		where ... is a sequence of a &lt;v:<em>name</em>/&gt; child per bound variable,
 *      where <em>name</em> is a unique identifier for that variable;
 * 		the scope is the <em>following</em> construction child as described just above.
 * 		<p>
 * 	
 * <li>Variable uses (free or bound) become constant terms of the form &lt;v:<em>name</em>/&gt;,
 *      where <em>name</em> is a unique identifier for that variable.
 * 		<p>
 * 
 * <li>Properties become attributes with the property as the attribute name (for variables as v:<em>name</em>)
 * 		and the string value of the property as attribute value...
 * 
 * </ul>
 * When tags are created from CRSX symbols then all characters that are not allowed in names are encoded
 * as _<em>code</em>_ with <em>code</em> the ASCII/Unicode decimal value, additionally _ itself is encoded as __ (two _s).
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class SAXSink extends DelegatingMaker implements Sinker
{
    /** Prefix used. */
    public final static String CRS_PREFIX = "crs";
    
    /** Namespace to use for variables. */
    public final static String VARIABLE_URI = CRS.URI + "/variable";
    /** Prefix to use for variables. */
    public final static String VARIABLE_PREFIX = "v";
    /** Name of element tag used for sequence elements. */
    public final static String SEQUENCE = "s";
    /** Name of element tag used for constructor wrapper. */
    public final static String CONSTANT = "c";
    /** Name of element tag used for binder wrapper. */
    public final static String BINDER = "b";
    /** Name attribute for constructor (local part). */
    public final static String NAME = "name";
    
    // State.
    
    /** Target for SAX events. */
    private ContentHandler handler;
    
    /** Namespace URI. */
    private String userURI;
    
    /** Whether constructor is constant wrapper for some type. */
    private Set<String> constantWrapperType;
    
    /** Non-null between start and end event of constant wrapper. */
    private String currentWrapper;
    
    /** Open element tags (as triples uri,local,prefix+local). */
    final StackOf<Triple<String,String,String>> names = new StackOf<Triple<String,String,String>>();
    
    /** Shared attribute creation structure. */
    private final AttributesImpl attributes = new AttributesImpl();
    
    /** Unique names for variables */
    private final Map<Variable, String> uniqueVariableNames = new HashMap<Variable, String>();
    /** Counter to ensure unique names for variables. */
    private int uniqueCounter;
    
    /** Return after full term has been serialized. */
    private Sink continuation;
    
    // Constructor.
    
    /** Create uninitialized sink. */
    public SAXSink()
    {}
    
    /**
     * Create sink that echoes the result to an existing SAX event stream.
     * @param maker used for generating constructions
     * @param handler target for SAX events
     * @param uri to use for generated elements (use "" to not have a namespace)
     * @param wrapper constructors with symbols in this set are output as special crs:c wrappers
     * 		containing just the single constant child of the wrapper
     */
    public SAXSink(Maker maker, ContentHandler handler, String uri, Set<String> wrappers)
    {
        super(maker);
        this.handler = handler;
        this.userURI = uri;
        this.constantWrapperType = wrappers;
    }
    
    /**
     * Create sink that echoes the result as XML to a file.
     * The file Uses the UTF-8 encoding, omits the xml declaration, and indents the result.
     * @param maker used for generating constructions
     * @param output file
     * @param uri to use for generated elements (use "" to not have a namespace)
     * @param wrapper constructors with symbols in this set are output as special crs:c wrappers
     * 		containing just the single constant child of the wrapper
     * @throws TransformerConfigurationException 
     * @throws SAXException 
     */
    public SAXSink(Maker maker, OutputStream output, String uri, Set<String> wrappers) throws TransformerConfigurationException, SAXException
    {
        super(maker);
 
        // Serialize to writer.
        StreamResult streamResult = new StreamResult(output);
        SAXTransformerFactory transformerFactory = (SAXTransformerFactory) SAXTransformerFactory.newInstance();
        TransformerHandler transformerHandler = transformerFactory.newTransformerHandler();
        Transformer serializer = transformerHandler.getTransformer();

        serializer.setOutputProperty(OutputKeys.ENCODING,"UTF-8");
        serializer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION,"yes");
        serializer.setOutputProperty(OutputKeys.INDENT,"yes");
        transformerHandler.setResult(streamResult);

        this.handler = transformerHandler;
        this.userURI = uri;
        this.constantWrapperType = wrappers;
    }

    /**
     * Create sink that echoes the result as XML to a Java Unicode writer.
     * @param maker used for generating constructions
     * @param writer to output to
     * @param uri to use for generated elements (use "" to not have a namespace)
     * @param wrapper constructors with symbols in this set are output as special crs:c wrappers
     * 		containing just the single constant child of the wrapper
     * @throws TransformerConfigurationException 
     * @throws SAXException 
     */
    public SAXSink(Maker maker, Writer writer, String uri, Set<String> wrappers) throws TransformerConfigurationException, SAXException
    {
        super(maker);
 
        // Serialize to writer.
        StreamResult streamResult = new StreamResult(writer);
        SAXTransformerFactory transformerFactory = (SAXTransformerFactory) SAXTransformerFactory.newInstance();
        TransformerHandler transformerHandler = transformerFactory.newTransformerHandler();
        Transformer serializer = transformerHandler.getTransformer();
        serializer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION,"yes");
        serializer.setOutputProperty(OutputKeys.INDENT,"yes");

        transformerHandler.setResult(streamResult);
        this.handler = transformerHandler;

        this.userURI = uri;
        this.constantWrapperType = wrappers;
    }

    // Methods.
    
    /** Set the SAX content handler. */
    public void setContentHandler(ContentHandler handler)
    {
    	this.handler = handler;
    }

    // Sinker.
    
	public void setFactory(Factory<? extends Term> factory)
	{
		super.setMaker(factory);
		
        userURI = factory.defined("XML-uri") ? factory.get("XML-uri").constructor().symbol() : "";
        
        if (factory.defined("XML-constant-wrappers"))
        {
            constantWrapperType = new HashSet<String>();
        	Constructor c = factory.get("XML-constant-wrappers").constructor();
        	if (c != null && c instanceof PropertiesHolder)
        	{
        		PropertiesHolder ph = (PropertiesHolder) c;
        		for (String name : ph.propertyNames())
        			constantWrapperType.add(name);
        	}
        }
	}

	@SuppressWarnings("unchecked")
	public void setAppendable(Appendable appendable)
	{
        if (!(appendable instanceof FormattingAppendable))
        {
        	int width = 120;
        	int indent = 0;
        	if (maker() instanceof Factory)
        	{
        		Factory<Term> factory = (Factory<Term>) maker();
        		width = factory.defined("width") ? Integer.parseInt(factory.get("width").constructor().symbol()) : width;
        		indent = factory.defined("indent") ? Integer.parseInt(factory.get("indent").constructor().symbol()) : indent;
        	}
        	appendable = FormattingAppendable.format(appendable, width, indent, Integer.MAX_VALUE);
        }
        Writer writer = (Writer) appendable;

        // Serialize to writer.
        StreamResult streamResult = new StreamResult(writer);
        SAXTransformerFactory transformerFactory = (SAXTransformerFactory) SAXTransformerFactory.newInstance();
        TransformerHandler transformerHandler;
		try
		{
			transformerHandler = transformerFactory.newTransformerHandler();
		}
		catch (TransformerConfigurationException e)
		{
			transformerHandler = null;
		}
        Transformer serializer = transformerHandler.getTransformer();
        serializer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION,"yes");
        serializer.setOutputProperty(OutputKeys.INDENT,"yes");
        transformerHandler.setResult(streamResult);
        handler = transformerHandler;
	}

	public void setContinuation(Sink continuation)
	{
		this.continuation = continuation;
	}

    // Sink.
    
    public Sink start(Constructor constructor)
    {
		assert attributes.getLength() == 0 : "Attributes not cleaned up?";
    	try
    	{
    		if (names.isEmpty())
    			startDocument();
    		
    		if (Util.isNull(constructor) || Util.isCons(constructor))
    		{
    			if (names.isEmpty() || (names.top() != null && !(CRS_PREFIX+":"+SEQUENCE).equals(names.top().three())))
    			{
    				// It is the outermost $Nil or $Cons of a group...record it.
        			handler.startElement(CRS.URI, SEQUENCE, CRS_PREFIX+":"+SEQUENCE, attributes);
        			names.push(new Triple<String,String,String>(CRS.URI, SEQUENCE, (CRS_PREFIX+":"+SEQUENCE)));
    			}
    			else
    			{
    				// An inner $Nil or $Cons...to be ignored.
    				names.push(null);
    			}
    		}
    		else if (currentWrapper != null)
    		{
    			// This is the constant inside a constant wrapper
    			String constant = constructor.symbol();
    			if (constant.startsWith("_") || constant.trim().length() == 0)
    				constant = "_" + constant + "_"; // protect white space and _s
   				handler.characters(constant.toCharArray(), 0, constant.length());
    			names.push(null); // to ignore end
    		}
    		else if (constantWrapperType != null && constantWrapperType.contains(constructor.symbol()))
    		{
    			// This is a constructor wrapping a constant.
    			currentWrapper = constructor.symbol();
    			attributes.addAttribute(CRS.URI, NAME, CRS_PREFIX+":"+NAME, "xs:string", currentWrapper); 
    			addPropertyAttributes(constructor);
    			handler.startElement(CRS.URI, CONSTANT, CRS_PREFIX+":"+CONSTANT, attributes);
    			names.push(new Triple<String,String,String>(CRS.URI, CONSTANT, (CRS_PREFIX+":"+CONSTANT)));
    	        attributes.clear();
    		}
    		else
    		{
    			// This is a normal tag to translate to an element.
    			String tag = namify(constructor.symbol());
    			addPropertyAttributes(constructor);
    			handler.startElement(userURI, tag, tag, attributes);
    			names.push(new Triple<String, String, String>(userURI, tag, tag));
    	        attributes.clear();
    		}
            return this;
    	}
    	catch (SAXException e)
        {
            throw new RuntimeException(e);
        }
    }

    /** Helper to add all the properties of constructor to {@link #attributes}. */
    void addPropertyAttributes(Constructor constructor)
    {
    	if (constructor instanceof PropertiesHolder)
    	{
    		PropertiesHolder properties = (PropertiesHolder) constructor;
    		for (String name : properties.propertyNames())
    		{
    			String att = namify(name);
    			attributes.addAttribute("", att, att, "xs:string", properties.getProperty(name).toString());
    		}
    		for (Variable variable : properties.propertyVariables())
    		{
    			String att = name(variable);
    			attributes.addAttribute(VARIABLE_URI, att, VARIABLE_PREFIX+":"+att, "xs:string", properties.getProperty(variable).toString());
    		}
    	}
    }
    
    /** Helper to send start document SAX event. */
    private void startDocument() throws SAXException
    {
        handler.startDocument();
        handler.startPrefixMapping(CRS_PREFIX, CRS.URI);
        handler.startPrefixMapping(VARIABLE_PREFIX, VARIABLE_URI);
    }
    
    public Sink end()
    {
    	try
    	{
    		Triple<String,String,String> triple = names.pop();
    		if (triple != null)
    		{
    			String uri = triple.one();
    			String tag = triple.two();
    			String prefixedtag = triple.three();
    			handler.endElement(uri, tag, prefixedtag);
    			currentWrapper = null;
    		}
    		if (names.isEmpty())
    		{
    			endDocument();
    			return continuation;
    		}
            return this;
    	}
        catch (SAXException e)
        {
            throw new RuntimeException(e);
        }
    }
    
    /** Helper to send end document SAX event. */
    private void endDocument() throws SAXException
    {
        handler.endPrefixMapping(VARIABLE_PREFIX);
        handler.endPrefixMapping(CRS_PREFIX);
        handler.endDocument();
    }

    public Sink binds(Variable[] binders)
    {
    	Sink sink = this;
    	try
    	{
    		handler.startElement(CRS.URI, BINDER, CRS_PREFIX+":"+BINDER, attributes);
    		for (Variable b : binders)
    		{
    	        String name = name(b);
                handler.startElement(VARIABLE_URI, name, VARIABLE_PREFIX+":"+name, attributes);
                handler.endElement(VARIABLE_URI, name, VARIABLE_PREFIX+":"+name);
    		}
    		handler.endElement(CRS.URI, BINDER, CRS_PREFIX+":"+BINDER);
    	}
    	catch (SAXException e)
    	{
    		throw new RuntimeException(e);
    	}
    	return sink;
    }

    public Sink use(Variable variable)
    {
        assert attributes.getLength() == 0 : "Attributes not cleaned up?";
        String name = name(variable);
        try
        {
            if (names.isEmpty())
                startDocument();
            handler.startElement(VARIABLE_URI, name, VARIABLE_PREFIX+":"+name, attributes);
            handler.endElement(VARIABLE_URI, name, VARIABLE_PREFIX+":"+name);
            if (names.isEmpty())
            {
                endDocument();
                return continuation;
            }
            attributes.clear();
            return this;
        }
        catch (SAXException e)
        {
            throw new RuntimeException(e);
        }
    }
    
    private String name(Variable variable)
    {
    	String name = uniqueVariableNames.get(variable);
        if (name == null)
        {
            name = namify(variable.name()) + "-" + (++uniqueCounter);
            uniqueVariableNames.put(variable, name);
        }
        return name;
    }
    
    
    public Sink startMetaApplication(String name)
    {
        throw new UnsupportedOperationException("PANIC: No meta-application support in XML.");
    }
    
    public Sink endMetaApplication()
    {
        throw new UnsupportedOperationException("PANIC: No meta-application support in XML.");
    }
    
    public Sink copy(Copyable source, boolean discard)
    {
        return source.copy(this, discard, LinkedExtensibleMap.EMPTY_RENAMING);
    }

    // Helpers.
    
    /** Make sure name is legal (local) element or attribute name. */
    static String namify(final String name)
    {
        StringBuilder b = new StringBuilder();
        char c = name.charAt(0);
        if (Character.isLetter(c))
            b.append(c);
        else if (c == '_')
            b.append("__");
        else
            b.append("_" + ((int)c) +"_");
        
        for (int i = 1; i < name.length(); ++i)
        {
            c = name.charAt(i);
            if (Character.isLetterOrDigit(c) || c == '-')
                b.append(c);
            else if (c == '_')
                b.append("__");
            else
                b.append("_" + ((int)c) +"_");
        }
        return b.toString();
    }

	public void close() throws IOException
	{
		// TODO!
	}
}
