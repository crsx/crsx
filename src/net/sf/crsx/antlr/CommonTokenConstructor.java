
package net.sf.crsx.antlr;

import java.io.IOException;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Maker;
import net.sf.crsx.Match;
import net.sf.crsx.Parser;
import net.sf.crsx.Path;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.EmptyIterable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.PropertiesConstructor;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

import org.antlr.runtime.CharStream;
import org.antlr.runtime.CommonToken;
import org.antlr.runtime.Lexer;
import org.antlr.runtime.RecognizerSharedState;
import org.antlr.runtime.Token;

/**
 * <a href="http://www.antlr.org">ANTLR</a> token implementation that doubles as a
 * CRSX {@link Constructor}.
 * 
 * Extends the standard ANTLR {@link CommonToken} with methods so the token can be used as a
 * CRSX {@link Constructor}.  The constructor includes the following properties (available through the
 * {@link PropertiesHolder} interface):
 * <ul>
 * <li> $Text: <em>string</em> - see {@link Token#getText()}.
 * <li> $FileLocation: <em>string</em>
 * <li> $LineLocation: <em>integer</em>
 * <li> $ColumnLocation: <em>integer</em> (offset by 1 character).
 * <li> $Channel: <em>integer</em> - see {@link Token#getChannel()}.
 * <li> $TokenIndexRange: <em>integer</em> - see {@link org.antlr.runtime.tree.TreeAdaptor#getTokenStartIndex(Object)}
 * 		and {@link org.antlr.runtime.tree.TreeAdaptor#getTokenStopIndex(Object)}.
 * </ul>
 * TODO: more precise magic tokens: text-aware and not, binders, variables.
 * 
 * @author <a href="mailto:evarose@users.souceforge.net">Eva Rose</a>
 */
public class CommonTokenConstructor extends CommonToken implements Token, Constructor
{
	// Constants.

	private static final long serialVersionUID = -3528905428088123506L;

	/** Property names. */
	final public static String TEXT = "$Text", CHANNEL = "$Channel";

	/** Special token types. */
	public final static int NIL_TYPE = -1, ERROR_TYPE = -2, CRSX_TYPE = -3;

	// State.

	/** Factory. */
	final CommonTokenFactory factory;

	/** Parent of owning node...ignored by CRSX but maintained by TreeAdaptor. */
	private GenericTerm parent;

	/** Whether this particular token has an input location (concretely or virtually). */
	private CharStream stream;
	
	// Constructors.

	/** Create token corresponding to anonymous token with just a type. */
	public CommonTokenConstructor(CommonTokenFactory factory, int type)
	{
		super(type);
		this.factory = factory;
	}

	/** Create anonymous token based on just the type and name.*/
	public CommonTokenConstructor(CommonTokenFactory factory, int type, String text)
	{
		super(type, text);
		this.factory = factory;
	}
	
	/** Create token from substring and channel of character stream. */
	public CommonTokenConstructor(CommonTokenFactory factory, CharStream input, int type, int channel, int start, int stop,
			String[] names)
	{
		super(input, type, channel, start, stop);
		this.factory = factory;
		if (names != null)
		{
			stream = input;
			if (factory.symbols == null)
				factory.symbols = names;
			else
				assert names == factory.symbols : "Attempt to use GenericFactoryTreeAdaptor for multiple parsers?";
		}
	}

	/**
	 * Special token for use by custom {@link Lexer#emit()}.
	 * @param input characters
	 * @param state of the token reader
	 * @param stop points to the end of gthe token
	 * @param names of tokens
	 */
	public CommonTokenConstructor(CommonTokenFactory factory, CharStream input, RecognizerSharedState state, int stop,
			String[] names)
	{
		this(factory, input, state.type, state.channel, state.tokenStartCharIndex, stop, names);
		setLine(state.tokenStartLine);
		setText(state.text);
		setCharPositionInLine(state.tokenStartCharPositionInLine);
	}

	/** Create token wrapping an existing token. */
	public CommonTokenConstructor(Token payload)
	{
		super(payload);
		CommonTokenConstructor t = (CommonTokenConstructor) payload;
		factory = t.factory;
		stream = t.stream;
	}

	// Methods.

	/** Whether this is a "textual" token that must have a {@link #TEXT} property even when it does not originate from the input. */
	protected boolean isTextual()
	{
		String[] syms = factory.symbols();
		String textPrefix;
		return syms != null
				&& type >= 0 && type < syms.length
				&& (textPrefix = Util.symbol(factory.get(TreeAdaptorFactory.TEXT_TOKEN_PREFIX_PROPERTY))) != null
				&& syms[type].startsWith(textPrefix);
	}

	/** Return previously {@link #setParent(GenericTerm)}. */
	public GenericTerm getParent()
	{
		return parent;
	}

	/** Set value of {@link #getParent()}. */
	public void setParent(GenericTerm parent)
	{
		this.parent = parent;
	}

	// Overrides of CommonToken...

	@Override
	public void setChannel(int channel)
	{
		super.setChannel(channel);
	}

	@Override
	public void setCharPositionInLine(int charPositionInLine)
	{
		super.setCharPositionInLine(charPositionInLine);
	}

	@Override
	public void setType(int t)
	{
		super.setType(t);
	}

	@Override
	public void setLine(int line)
	{
		super.setLine(line);
	}

	@Override
	public void setTokenIndex(int index)
	{
		super.setTokenIndex(index);
	}

	@Override
	public void setStartIndex(int start)
	{
		super.setStartIndex(start);
	}

	@Override
	public void setStopIndex(int stop)
	{
		super.setStopIndex(stop);
	}

	// Implementation of Constructor...

	public String symbol()
	{
		switch (type)
		{
			case NIL_TYPE :
				return ("$$NIL");
			case ERROR_TYPE :
				return ("$$ERROR");
			case CRSX_TYPE :
				return (getText());
			default : {
				String[] symbols = factory.symbols();
				return symbols != null && type >= 0 && type < symbols.length ? symbols[type] : getText();
			}
		}
	}

	public String literalSort()
	{
		return null; // not a literal but a Constructor with a $Text property...
	}

	public Token object()
	{
		return this;
	}

	public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		if (!symbol().equals(that.symbol()))
			return false;
		return PropertiesConstructor.checkProperties(this, that, match, bound, contractionCount, promiscuous, once, onceSeen);
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		return true;
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		PropertiesConstructor.addFree(this, set, bound, includemetaapps, base);
	}

	public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		return this;
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		visitor.visitProperties(true);

		// Just the constant properties.
		for (String k : propertyNames())
		{
			Term t = getProperty(k);
			visitor.visitNamedProperty(k, true);
			if (t != null)
				t.visit(visitor, bound);
			visitor.visitNamedProperty(k, false);
		}

		visitor.visitProperties(false);
	}

	public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
	{
		return equals(that) ? this : null;
	}

	public CommonTokenConstructor copy(ExtensibleMap<Variable, Variable> renamings)
	{
		return new CommonTokenConstructor(this);
	}

	public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}
	
	public Constructor staticContract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	public void normalize(CRS crs) throws CRSException
	{}

	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		if (writer instanceof FormattingAppendable)
			((FormattingAppendable) writer).open("");
		if (namedProps)
			PropertiesConstructor.appendPropertiesTo(this, writer, used, depth - 1, full, namedProps, variableProps, omitProps, sortProps);
		writer.append(literalSort() != null
				? Util.quoteJava(symbol())
				: Util.externalizeConstructor(text != null ? text : symbol()));
		if (writer instanceof FormattingAppendable)
			((FormattingAppendable) writer).close("");
	}

	final public SortedSet<Path> paths(Path base)
	{
		SortedSet<Path> paths = new TreeSet<Path>();
		for (String name : propertyNames())
			paths.add(base.extend(name));
		for (Variable variable : propertyVariables())
			paths.add(base.extend(variable));
		return paths;
	}

	public void javaInvokeStart(SourceBuilder code, String sinkName, Map<Variable, String> variable2java)
	{
		throw new UnsupportedOperationException("TODO: Implement Java code emit for CommonTokenConstructor!");
	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		List<String> list = new ArrayList<String>();
		if (text != null && isTextual())
			list.add(TEXT);
		if (stream != null)
		{
			list.add(Parser.TOKEN_FILE_LOCATION);
			if (line > 0)
				list.add(Parser.TOKEN_LINE_LOCATION);
			if (charPositionInLine > 0)
				list.add(Parser.TOKEN_COLUMN_LOCATION);
			if (channel > 0)
				list.add(CHANNEL);
		}
		return list;
	}

	public Term getProperty(String name)
	{
		if (name.equals(TEXT) && text != null && isTextual())
			return factory.literal(text);
		if (stream != null)
		{
			if (name.equals(Parser.TOKEN_COLUMN_LOCATION) && charPositionInLine > 0)
				return Buffer.materializeTagged(factory, Parser.TOKEN_COLUMN_LOCATION_WRAPPER, charPositionInLine);
			if (name.equals(Parser.TOKEN_LINE_LOCATION) && line > 0)
				return Buffer.materializeTagged(factory, Parser.TOKEN_LINE_LOCATION_WRAPPER, line);
			if (name.equals(Parser.TOKEN_FILE_LOCATION))
				return Buffer.materializeTagged(factory, Parser.TOKEN_FILE_LOCATION_WRAPPER, stream.getSourceName());
			if (name.equals(CHANNEL) && channel > 0)
				return factory.literal(Integer.toString(channel));
		}
		return null;
	}

	public boolean canSetProperty(String name)
	{
		if (name.equals(TEXT) && isTextual())
			return true;
		if (stream != null)
		{
			if (name.equals(Parser.TOKEN_COLUMN_LOCATION))
				return true;
			if (name.equals(Parser.TOKEN_LINE_LOCATION))
				return true;
			if (name.equals(CHANNEL))
				return true;
		}
		return false;
	}

	public void setProperty(String name, Term value) throws CRSException
	{
		try
		{
			if (name.equals(TEXT) && isTextual())
				setText(Util.symbol(value));
			else if (stream != null)
			{

				if (name.equals(Parser.TOKEN_COLUMN_LOCATION))
					setCharPositionInLine(Integer.parseInt(Util.symbol(value)));
				else if (name.equals(Parser.TOKEN_LINE_LOCATION))
					setLine(Integer.parseInt(Util.symbol(value)));
				else if (name.equals(CHANNEL))
					setChannel(Integer.parseInt(Util.symbol(value)));
			}
			else
				throw new CRSException("Property " + name + " cannot be set directly on CommonToken");
		}
		catch (NumberFormatException e)
		{
			throw new CRSException("Property " + name + " must be set to numeric value", e);
		}
	}

	public Iterable<Variable> propertyVariables()
	{
		return new EmptyIterable<Variable>();
	}

	public Term getProperty(Variable variable)
	{
		return null;
	}

	public boolean canSetProperty(Variable variable)
	{
		return false;
	}

	public void setProperty(Variable key, Term value) throws CRSException
	{
		throw new CRSException("Variable property cannot be set directly on CommonToken");
	}

	@Override
	public void removeProperty(Variable variable) throws CRSException
	{}

	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		for (String name : properties.propertyNames())
			setProperty(name, properties.getProperty(name));
		for (Variable variable : properties.propertyVariables())
			setProperty(variable, properties.getProperty(variable));
	}

	public boolean isMeta()
	{
		return false;
	}

	// Object...

	@Override
	public String toString()
	{
		StringWriter w = new StringWriter();
		try
		{
			appendTo(
					w, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, false, false,
					LinkedExtensibleSet.EMPTY_VARIABLE_SET, false);
		}
		catch (IOException e)
		{
			// Really.
		}
		return w.toString();
	}

	@Override
	public boolean equals(Object that)
	{
		if (that == null)
			return false;
		if (!(that instanceof Constructor))
			return false;
		Constructor c = (Constructor) that;
		return symbol() == null ? c.symbol() == null : symbol().equals(c.symbol());
	}

	public int hashCode()
	{
		return symbol().hashCode();
	}

	public Constructor baseConstructor()
	{
		return this;
	}
}
