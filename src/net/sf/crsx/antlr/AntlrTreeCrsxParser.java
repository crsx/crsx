/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.antlr;

import net.sf.crsx.Factory;
import net.sf.crsx.Parser;
import net.sf.crsx.Term;
import net.sf.crsx.util.DelegateParser;

/**
 * ANTLR CRSX parser bridge.
 * Create <code><em>class</em>.java</code> that extends this class to use the combined ANTLR grammar
 * in <code><em>class</em>Parser.java</code> and <code><em>class</em>Lexer.java</code>.
 * Requires that {@link #parser(Factory)} is invoked with an instance of {@link TreeAdaptorFactory}.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: AntlrTreeCrsxParser.java,v 3.0 2012/12/17 18:04:48 krisrose Exp $
 */
public class AntlrTreeCrsxParser extends DelegateParser
{
	// State.
	
	/** The factory we're using. */
	protected TreeAdaptorFactory factory;
	
	// Parser...

	public Parser parser(Factory<? extends Term> f)
	{
		if (f != null) return new AntlrTreeCrsxParser().parser(f);
		factory = (TreeAdaptorFactory) f;
		return this;
	}

	// DelegateParser...

	@Override
	protected net.sf.crsx.Parser delegate()
	{
		return factory;
	}
}
