/* Copyright (c) 2010 */
package net.sf.crsx.antlr;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.util.Util;

import org.antlr.runtime.CharStream;
import org.antlr.runtime.RecognizerSharedState;
import org.antlr.runtime.Token;

/**
 * Factory for use with <a href="http://crsx.sf.net">CRSX</a> and <a href="http://www.antlr.org">ANTLR</a> tokens. 
 * <ul>
 * <li>Can be used as a CRSX factory to generate terms that retain ANTLR location information.
 * </ul>
 * The generated terms have the following properties:
 * <ul>
 * <li>The value of CRSX {@link Term#constructor()} is always a {@link CommonTokenConstructor} instance.
 * <li>The value of CRSX {@link Term#sub(int)} is always a {@link GenericTerm} instance. 
 * </ul>
 * The factory is sensitive to special environment variables (through{@link #set(String, Stub)} and {@link #get(String)}):
 * <ul>
 * <li>package - this package name is prepended, if set, to all class names (see .
 * <li>grammar - this <b>must</b> be set to a <em>grammar-configuration</em> as detailed below <em>before</em> any parsing is attempted.
 * <li>flexible - this is set (to True) by the factory, and <b>should</b> remain so until <em>all</em> ANTLR processing (involving tree manipulation) has been performed.
 * </ul>
 *	<blockquote>
 *		<em>parser-configuration</em> : ( '{' <em>binding</em> (';' <em>binding</em>)* '}' )? <em>grammar-name</em>? ;<br>
 *		<em>binding</em> : <em>grammar-name</em> ( ':' '(' <em>category-name</em> (';' <em>category-name</em>)* ')' )? ;
 *	</blockquote>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: CommonTokenFactory.java,v 3.0 2012/12/17 18:04:48 krisrose Exp $
 */
public class CommonTokenFactory extends GenericFactory 
{
	// Constants.
	
	/** Name of option to ignore Token properties in the term representation (for meta-processing)... */
	final public static String META_PROPERTY = "meta";

	/** Name of meta-term prefix property. */
	final public static String META_TOKEN_PROPERTY = "meta-token";

	/** Name of meta-term prefix property. */
	final public static String TEXT_TOKEN_PREFIX_PROPERTY = "text-token-prefix";
	
	// State.
	
	/** Prefix of token that triggers meta-treatment, if enabled. */
	String metaToken;

	/** Prefix of token that triggers using token as text token. */
	String textPrefix;

	/** With type to name mapping for CRSX. */
	String[] symbols;
	
	// Methods.

	/**
	 * The symbols used...or null.
	 */
	String[] symbols()
	{
		return symbols;
	}
	
	/** Whether the factory enables meta-token. */
	public String metaToken()
	{
		return metaToken;
	}

	/** Whether the factory supports meta-construction. */
	String textTokenPrefix()
	{
		return textPrefix;
	}
	
	/**
	 * Create "normal" token with characters from input stream.
	 * @param input with characters
	 * @param state of recognizer (contains most of the token information)
	 * @param endCharIndex so the end of the token text can be located
	 * @param names 
	 */
	public CommonTokenConstructor createToken(CharStream input, RecognizerSharedState state, int endCharIndex, String[] names)
	{
		return new CommonTokenConstructor(this, input, state, endCharIndex, names);
	}

	/**
	 * Create unattached token of type.
	 * @param type of the token to create
	 * @param text of token
	 */
	protected CommonTokenConstructor createToken(int type, String text)
	{
		return new CommonTokenConstructor(this, type, text);
	}
	
	/**
	 * Create fresh copy of existing token.
	 * @param fromToken to copy
	 */
	protected CommonTokenConstructor createToken(Token fromToken)
	{
		return new CommonTokenConstructor(fromToken);
	}

	@Override
	protected Iterable<String> categories(String grammar) throws CRSException
	{
		try
		{
			// First try to use as ANTLR grammar.
			Class<?> c = Util.classForName(this, grammar+"Parser");
			if (!(org.antlr.runtime.Parser.class.isAssignableFrom(c)))
				throw new CRSException("Dummy so we use the CRSX parser convention...");
			Method[] ms = c.getDeclaredMethods();
			List<String> cs = new ArrayList<String>();
			for (Method m : ms)
			{
				// HACK! relies on the hard-coded ANTLR return type names...
				if (m.getReturnType().getCanonicalName().endsWith("_return"))
					cs.add(m.getName());
			}
			return cs;
		}
		catch (CRSException e)
		{
			return super.categories(grammar);
		}
	}

	// GenericFactory (Maker)...
	
	/* @see net.sf.crsx.generic.GenericFactory#set(java.lang.String, net.sf.crsx.Stub)*/
	@Override
	public void set(String name, Stub value)
	{
		super.set(name, value);

		// Further cases with side effects...
		if (META_TOKEN_PROPERTY.equals(name))
		{
			metaToken = Util.symbol(value);
		}
		else	if (TEXT_TOKEN_PREFIX_PROPERTY.equals(name))
		{
			textPrefix = Util.symbol(value);
		}
	}

	@Override
	public CommonTokenConstructor makeConstructor(Object object)
	{
		// Note: This is the only actual implementation of .makeConstructor() used by the generic implementation!
	    if (object instanceof Constructor)
			return createToken(CommonTokenConstructor.CRSX_TYPE, ((Constructor) object).symbol());
		// Tokens are packaged.
		if (object instanceof Token)
			return createToken((Token) object);
//		if (object.toString().startsWith("{"))
//			warning("bad karma: constructor named with {?}?");
		// Fall back to using the text representation.
		return createToken(CommonTokenConstructor.CRSX_TYPE, object.toString());
	}
	
	
}
