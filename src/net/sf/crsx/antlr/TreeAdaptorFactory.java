/* Copyright (c) 2009 IBM Corporation. */
package net.sf.crsx.antlr;

import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Sink;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.Util;

import org.antlr.runtime.RecognitionException;
import org.antlr.runtime.Token;
import org.antlr.runtime.TokenStream;
import org.antlr.runtime.tree.TreeAdaptor;

/**
 * Common term/AST tree adapter for <a href="http://crsx.sf.net">CRSX</a> and <a href="http://www.antlr.org">ANTLR</a>. 
 * <ul>
 * <li>Can be used as a CRSX factory to generate terms that can later be processed with ANTLR tree grammars.
 * <li>Can be used as an ANTLR AST tree adaptor to generate terms that CRSX can rewrite.
 * </ul>
 * The generated terms have the following properties:
 * <ul>
 * <li>The value of CRSX {@link Term#constructor()} and ANTLR {@link TreeAdaptor#getToken(Object)} is always a {@link CommonTokenConstructor} instance.
 * <li>The value of CRSX {@link Term#sub(int)}, <em>etc.</em>, and ANTLR {@link TreeAdaptor#create(Token)}, <em>etc.</em>, is always a {@link GenericTerm} instance. 
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
 * @version $Id: TreeAdaptorFactory.java,v 3.1 2013/12/09 05:48:40 krisrose Exp $
 */
public class TreeAdaptorFactory extends CommonTokenFactory implements TreeAdaptor
{
	// Constructors.

	/**
	 * Create factory.
	 * The passed environment must contain a binding for the symbol {@link Factory#GRAMMAR_PROPERTY} with a grammar configuration
	 * (In addition, a true value for {@link GenericFactory#FLEXIBLE} is added.)
	 */
	public TreeAdaptorFactory()
	{
		set(FLEXIBLE, truth());
	}

	// Factory<GenericTerm>...

	/* @see net.sf.crsx.generic.GenericFactory#addGrammar(java.lang.String)*/
	@Override
	public void addGrammar(String grammar, Collection<String> categories) throws CRSException
	{
		// Relies on catching exceptions...good we do not do this often?
		boolean committed = false;
		try
		{
			// Try to find the ANTLR parserBase.g classes.
			Util.classInstance0(this, grammar+"Lexer");
			Util.classInstance0(this, grammar+"Parser");
			committed = true; // got both classes...
			net.sf.crsx.Parser p = new AntlrTreeCrsxParser().parser(this);
			// Populate the categories.
			p = p.parser(this);
			if (categories != null)
			{
				for (String category : categories)
					categoryParser.put(category, p);
			}
			else
			{
				// Extract categories from net.sf.crsx.Parser implementation.
				for (String category : p.categories())
					if (!categoryParser.containsKey(category))
						categoryParser.put(category, p);
			}
			return;
		}
		catch (CRSException e)
		{
			if (committed)
				throw new CRSException("ANTLR parser class error ("+e+")");
			// Otherwise there was no ANTLR tree parser/lexer pair and we can fall back to loading normal parsers.
		}
		super.addGrammar(grammar, categories);
	}

	// GenericFactory (Parser)...

	@Override
	public Sink parse(Sink sink, String category, Reader reader, String unit, int line, int column, ExtensibleMap<String, Variable> bound) throws CRSException, IOException
	{
		if (bound == null) bound = LinkedExtensibleMap.EMPTY_SCOPE;
		Term term = parse(reader, category, unit, line, column, bound);
		return term.copy(sink, true, LinkedExtensibleMap.EMPTY_RENAMING);
	}

	// TreeAdapter...

	public GenericTerm create(Token payload)
	{
		if (metaToken() != null && payload.getText().startsWith(metaToken())) return newMeta(payload.getText());
		return constant(createToken(payload));
	}

	public GenericTerm create(int tokenType, Token fromToken)
	{
		if (metaToken() != null && fromToken.getText().startsWith(metaToken())) return newMeta(fromToken.getText());
		CommonTokenConstructor t = createToken(fromToken);
		t.setType(tokenType);
		return constant(t);
	}

	public GenericTerm create(int tokenType, Token fromToken, String text)
	{
		if (metaToken() != null && text.startsWith(metaToken())) return newMeta(text);
		CommonTokenConstructor t = createToken(fromToken);
		t.setType(tokenType);
		t.setText(text);
		return constant(t);
	}

	public GenericTerm create(int tokenType, String text)
	{
		if (metaToken() != null && text.startsWith(metaToken())) return newMeta(text);
		return constant(createToken(tokenType, text));
	}
	
	/**
	 * Helper to generate special terms.
	 * Tokens that start with the magic string set with the {@link #META_TOKEN_PROPERTY} are special.
	 * If the prefix is # then the following tokens are recognized :
	 * <ul>
	 * <li>#<em>id</em> (with em>id</em> any UNICODE identifier) - parse as meta-variable.
	 * <li>#<em>id</em>"<em>text</em>" - parse <em>text</em> after {@link Util#unquoteJava(String)}
	 * <li>#<em>id</em>{<em>text</em>} - parse {<em>text</em>}#<em>id</em> after {@link Util#unbrace(String)}
	 * </ul>
	 */
	private GenericTerm newMeta(String text)
	{
		assert metaToken() != null && text.startsWith(metaToken());
		
		// Derive text to parse clasically...
		String prefix = metaToken();
		text = text.substring(prefix.length());
		{
			int extraPrefixEnd = 0;
			while (extraPrefixEnd < text.length() && Character.isUnicodeIdentifierPart(text.charAt(extraPrefixEnd))) ++extraPrefixEnd;
			if (extraPrefixEnd > 0)
			{
				prefix = prefix + text.substring(0, extraPrefixEnd);
				text = text.substring(extraPrefixEnd);
			}
		}

		if (text.startsWith("\"") || text.startsWith("'"))
		{
			text = Util.unquoteJava(text); // TODO: more checking...?
		}
		else if (text.startsWith("{") && text.endsWith("}"))
		{
			text = "{" + Util.unbrace(text) + "}" + prefix;
		}
		else
		{
			// Alright...the entire text is the meta-variable.
			text = prefix + text;
		}
		try
		{
			// Now parse.
			return parse(text);
		}
		catch (CRSException e)
		{
			throw new IllegalArgumentException(e);
		}
	}

	public GenericTerm dupNode(Object treeNode)
	{
		GenericTerm node = (GenericTerm) treeNode;
		final int arity = node.arity();
		switch (node.kind())
		{
			case CONSTRUCTION : {
				Variable[][] binders = new Variable[arity][];
				GenericTerm[] sub = new GenericTerm[arity];
				for (int i = 0; i < arity; ++i)
				{
					binders[i] = node.binders(i);
					sub[i] = node.sub(i);
				}
				node = newConstruction(node.constructor(), binders, sub);
				break;
			}
			case META_APPLICATION : {
				GenericTerm[] sub = new GenericTerm[arity];
				for (int i = 0; i < arity; ++i)
					sub[i] = node.sub(i);
				node = newMetaApplication(node.metaVariable(), sub);
				break;
			}
			case VARIABLE_USE :
				node = newVariableUse(node.variable());
				break;
		}
		return node;
	}

	public GenericTerm dupTree(Object tree)
	{
		GenericTerm parent = dupNode(tree);
		final int arity = parent.arity();
		for (int i = 0; i < arity; ++i)
		{
			GenericTerm child = dupTree(parent.sub(i));
			parent.replaceSub(i, parent.binders(i), child);
			realSetParent(child, parent);
		}
		return parent;
	}

	public GenericTerm errorNode(TokenStream input, Token start, Token stop, RecognitionException e)
	{
		return constant(new ErrorTokenConstructor(this, input, start, stop, e));
	}

	public boolean isNil(Object tree)
	{
		return tree != null && CRS.NIL_SYMBOL.equals(((GenericTerm) tree).constructor());
	}

	public void addChild(Object t, Object child)
	{
		if (t != null && child != null)
		{
			GenericTerm parent = (GenericTerm) t;
			if (isNil(child))
			{
				// Add all children of child...
				GenericTerm list = (GenericTerm) child;
				for (int i = 0; i < list.arity(); ++i)
					addSub(parent, GenericTerm.NO_BIND, list.sub(i));
			}
			else
			{
				// Just add the child as a single subtree.
				addSub(parent, GenericTerm.NO_BIND, (GenericTerm) child);
			}
		}
	}
	/** Helper to invoke {@link GenericTerm#addSub(Variable[], GenericTerm)} and {@link #setParent(Object, Object)} together. */
	private void addSub(GenericTerm parent, Variable[] binds, GenericTerm child)
	{
		try
		{
			parent.addSub(binds, child);
			realSetParent(child, parent);
		}
		catch (CRSException e)
		{
			throw new UnsupportedOperationException(e);
		}
	}

	public GenericTerm becomeRoot(Object newRoot, Object oldRoot)
	{
		assert newRoot != null;
		// Mutate newRoot as t.
		GenericTerm t = (GenericTerm) newRoot;
		if (oldRoot == null)
		{
			// old=null, new=r yields r ... the same.
			// old=null, new=^(nil r) yields ^(nil r) ... the same.
		}
		else
		{
			GenericTerm old = (GenericTerm) oldRoot;
			// Make sure t is just the root node.
			if (isNil(newRoot))
				t = (GenericTerm) t.sub(0); // new = ^(nil r)
			// Insert children into t.
			if (isNil(oldRoot))
			{
				// old=^(nil a b c), new=^(nil r) yields ^(r a b c)
				// old=^(nil a b c), new=r yields ^(r a b c)
				for (int i = 0; i < old.arity(); ++i)
					addSub(t, old.binders(i), old.sub(i));
			}
			else
			{
				// old=^(a b c), new=r yields ^(r ^(a b c))
				// old=^(a b c), new=^(nil r) yields ^(r ^(a b c))
				addSub(t, GenericTerm.NO_BIND, old);
			}
		}
		return t;
	}

	public Object rulePostProcessing(Object root)
	{
		assert root != null;
		if (isNil(root))
		{
			final int count = getChildCount(root);
			if (count == 1)
				root = getChild(root, 0);
		}
		return root;
	}

	public int getUniqueID(Object node)
	{
		return System.identityHashCode(node);
	}

	// R e w r i t e  R u l e s

	public Object becomeRoot(Token newRoot, Object oldRoot)
	{
		GenericTerm t = create(newRoot);
		GenericTerm old = (GenericTerm) oldRoot;
		if (isNil(oldRoot))
		{
			for (int i = 0; i < old.arity(); ++i)
				addSub(t, old.binders(i), old.sub(i));
		}
		else
		{
			addSub(t, GenericTerm.NO_BIND, old);
		}
		return t;
	}

	// C o n t e n t

	public int getType(Object t)
	{
		return ((CommonTokenConstructor) ((GenericTerm) t).constructor()).getType();
	}

	public void setType(Object t, int type)
	{
		((CommonTokenConstructor) ((GenericTerm) t).constructor()).setType(type);
	}

	public String getText(Object t)
	{
		return ((CommonTokenConstructor) ((GenericTerm) t).constructor()).getText();
	}

	public void setText(Object t, String text)
	{
		((CommonTokenConstructor) ((GenericTerm) t).constructor()).setText(text);
	}

	public Token getToken(Object t)
	{
		return (CommonTokenConstructor) ((GenericTerm) t).constructor();
	}

	public void setTokenBoundaries(Object t, Token startToken, Token stopToken)
	{
		if (t != null && ((GenericTerm) t).kind() == Kind.CONSTRUCTION)
		{
			CommonTokenConstructor tt = (CommonTokenConstructor) ((GenericTerm) t).constructor();
			tt.setStartIndex(startToken.getTokenIndex());
			if (stopToken != null) tt.setStopIndex(stopToken.getTokenIndex());
		}
	}

	public int getTokenStartIndex(Object t)
	{
		if (t != null && ((GenericTerm) t).kind() == Kind.CONSTRUCTION)
			return ((CommonTokenConstructor) ((GenericTerm) t).constructor()).getStartIndex();
		else
			return 0;
	}

	public int getTokenStopIndex(Object t)
	{
		if (t != null && ((GenericTerm) t).kind() == Kind.CONSTRUCTION)
			return ((CommonTokenConstructor) ((GenericTerm) t).constructor()).getStopIndex();
		else
			return 0;
	}

	// N a v i g a t i o n  /  T r e e  P a r s i n g
	
	public GenericTerm getChild(Object t, int i)
	{
		return (GenericTerm) ((GenericTerm) t).sub(i);
	}

	public void setChild(Object t, int i, Object child)
	{
		((GenericTerm) t).replaceSub(i, GenericTerm.NO_BIND, (GenericTerm) child);
		realSetParent(child, t);
	}

	public GenericTerm deleteChild(Object t, int i)
	{
		GenericTerm parent = (GenericTerm) t;
		GenericTerm old = (GenericTerm) parent.sub(i);
		try
		{
			parent.deleteSub(i);
		}
		catch (CRSException e)
		{
			throw new UnsupportedOperationException(e);
		}
		return old;
	}

	public int getChildCount(Object t)
	{
		return ((GenericTerm) t).arity();
	}

	public GenericTerm getParent(Object t)
	{
		throw new UnsupportedOperationException("No parent support in ANTLR/CRSX term model.");
	}

	public void setParent(Object t, Object parent)
	{
		realSetParent(t, parent);
		throw new UnsupportedOperationException("No parent support in ANTLR/CRSX term model.");
	}
	/** Update parent/child relationship - NOT IMPLEMENTED. */
	private void realSetParent(Object child, Object parent)
	{
		// TODO: implement!
	}

	public int getChildIndex(Object t)
	{
		GenericTerm parent = getParent(t);
		for (int i = 0; i < parent.arity(); ++i)
			if (parent.sub(i) == t)
				return i;
		throw new IndexOutOfBoundsException();
	}

	public void setChildIndex(Object t, int index)
	{
		assert getChildIndex(t) == index;
	}

	public void replaceChildren(Object parent, int startChildIndex, int stopChildIndex, Object t)
	{
		GenericTerm p = (GenericTerm) parent;
		List<Pair<Variable[],GenericTerm>> newChildren = new ArrayList<Pair<Variable[],GenericTerm>>();
		GenericTerm cs = (GenericTerm) t;
		if (isNil(t))
		{
			for (int i = 0; i < cs.arity(); ++i)
			{
				GenericTerm child = cs.sub(i);
				newChildren.add(new Pair<Variable[], GenericTerm>(cs.binders(i), child));
				realSetParent(child, p);
			}
		}
		else
		{
			newChildren.add(new Pair<Variable[], GenericTerm>(GenericTerm.NO_BIND, cs));
			realSetParent(cs, p);
		}
		try
		{
			p.replaceSubs(startChildIndex, stopChildIndex, newChildren);
		}
		catch (CRSException e)
		{
			throw new UnsupportedOperationException(e);
		}
	}
}
