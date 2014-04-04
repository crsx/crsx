/* Copyright © 2009, 2012 IBM Corporation. */

package net.sf.crsx.util;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Parser;
import net.sf.crsx.Path;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.generic.PropertiesConstraintsWrapper;
import net.sf.crsx.generic.PropertiesWrapperConstructor;

/**
 * Various static utility functions.
 * (Cannot be instantiated.)
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: Util.java,v 3.17 2014/01/06 03:11:35 krisrose Exp $
 */
public final class Util
{
    /** Instances not possible. */
    private Util()
    {}
    
	/** Regular expression that conservatively approximates constructors that can be parsed without being quoted. */
	public static final java.util.regex.Pattern CONSTRUCTOR_PATTERN = java.util.regex.Pattern.compile(
			"(?:\\w*[$A-Z]+\\w*|[\u0391-\u218F\u2200-\u2307\u230C-\u2767\u276A-\u27E5\u27EC-\u2982\u2985-\uF000]|\\d+(?:[.]\\d+)?(?:[Ee]\\d+)?|[-@^*+`|\\\\!?$%=]+|(?:&(?:#\\d+|\\w+);)+|<(i|b|u|tt|q)>(?:[^<>&\n\r]|&(?:#[0-9]+|[-$A-Za-z0-9_]+);)+</\\1>)"
			+"(?:[-](?:[$A-Za-z]+\\w*|\\d+|[-@^*+`|\\\\!?$%=]+|(?:&(?:#\\d+|\\w+);)+))*");
			// TODO: handle more...

	/** Conservative approximation of string that it is safe to print as an unquoted variable name */
	public static final java.util.regex.Pattern VARIABLE_PATTERN = java.util.regex.Pattern.compile(
			"[a-z][A-Za-z0-9\u0391-\u218F\u2200-\u2307\u230C-\u2767\u276A-\u27E5\u27EC-\u2982\u2985-\uF000]*(?:[-_]+[A-Za-z0-9\u0391-\u218F\u2200-\u2307\u230C-\u2767\u276A-\u27E5\u27EC-\u2982\u2985-\uF000]+)*|v['][^']*[']|v[\"][^\"]*[\"]");

	/** Conservative approximation of string that it is safe to print as an unquoted meta-variable name. */
	public static final java.util.regex.Pattern META_VARIABLE_PATTERN = java.util.regex.Pattern.compile(
			"(?:[<]em[>].*[<][/]em[>]|[A-Za-z0-9_$\u0391-\u218F\u2200-\u2307\u230C-\u2767\u276A-\u27E5\u27EC-\u2982\u2985-\uF000]*[#]+[A-Za-z0-9_$#\u0391-\u218F\u2200-\u2307\u230C-\u2767\u276A-\u27E5\u27EC-\u2982\u2985-\uF000]*[*+?]?)(?:-[A-Za-z0-9$\u0391-\u218F\u2200-\u2307\u230C-\u2767\u276A-\u27E5\u27EC-\u2982\u2985-\uF000]*[*+?]?)*|[#]['][^']*[']|[#][\"][^\"]*[\"]");

    /** Whether this is a constant. */
    final public static boolean isConstant(Stub term)
    {
    	return term != null && term.kind() == Kind.CONSTRUCTION && term.arity() == 0;
    }

    /** Whether this is a literal constant. */
    final public static boolean isLiteral(Stub term)
    {
    	return isConstant(term) && term.constructor().literalSort() != null;
    }

    /** Whether this is a string constant. */
    final public static boolean isString(Stub term)
    {
    	return isConstant(term) && CRS.STRING_SORT.equals(term.constructor().literalSort());
    }

    /** Whether this is a numeric constant. */
    final public static boolean isNumeric(Stub term)
    {
    	return isConstant(term) && CRS.NUMERIC_SORT.equals(term.constructor().literalSort());
    }

    /** Whether this is a boolean constant. */
    final public static boolean isBoolean(Stub term)
    {
    	return isConstant(term) && CRS.BOOLEAN_SORT.equals(term.constructor().literalSort());
    }

    /** Whether this is a meta-application. */
    public static boolean isMetaApplication(Stub term)
    {
    	return term.kind() == Kind.META_APPLICATION;
    }

    /** Whether this is a plain application. */
    public static boolean isApply(Constructor constructor)
    {
    	return constructor != null && constructor.symbol().equals(CRS.APPLICATION_SYMBOL);
    }

    /** Whether this is a constructed sequence. */
    public static boolean isSequence(Term term)
    {
        do
        {
            if (term.kind() == Kind.CONSTRUCTION)
            {
                switch (term.arity())
                {
                    case 0 :
                        return term.constructor().symbol().equals(CRS.NIL_SYMBOL);
    
                    case 2 :
                        if (term.constructor().symbol().equals(CRS.CONS_SYMBOL))
                        {
                            term = term.sub(1);
                            continue;
                        }
                }
            }
            return false;
        }
        while (true);
    }

    /** Whether this is an empty sequence. */
    public static boolean isNull(Constructor constructor)
    {
        return constructor != null && constructor.symbol().equals(CRS.NIL_SYMBOL);
    }

    /** Whether this is an empty sequence. */
    public static boolean isNull(Term term)
    {
    	return term == null || (term.kind() == Kind.CONSTRUCTION && term.arity() == 0 && isNull(term.constructor()));
    }

    /** Whether this is the false constructor (for legacy reasons, the empty sequence is also considered as False) */
    public static boolean isFalse(Constructor constructor)
    {
    	return constructor != null && (constructor.symbol().equals(CRS.FALSE_SYMBOL) || constructor.symbol().equals(CRS.NIL_SYMBOL));
    }
    
    /** Whether this is a non-empty sequence. */
    public static boolean isCons(Constructor constructor)
    {
        return constructor != null && constructor.symbol().equals(CRS.CONS_SYMBOL);
    }

    /** Whether this is a rule. */
    public static boolean isRule(Constructor constructor)
    {
    	return constructor != null && constructor.symbol().equals(Builder.RULE_SYMBOL);
    }

    /** Whether this is a (data) sort declaration. */
    public static boolean isSort(Constructor constructor)
    {
    	return constructor != null && constructor.symbol().equals(Builder.DATA_SORT_SYMBOL);
    }

    /** Whether this is a function sort declaration. */
    public static boolean isFunctionSort(Constructor constructor)
    {
    	return constructor != null && constructor.symbol().equals(Builder.FUNCTION_SORT_SYMBOL);
    }

    /** Whether this is an evaluation primitive. */
    public static boolean isEval(Constructor constructor)
    {
    	return constructor != null && constructor.symbol().equals(CRS.EVAL_SYMBOL);
    }

    /** Whether this is a special constructor...it starts with '$'. */
    public static boolean isSpecial(Constructor c)
    {
    	return c.symbol().startsWith("$") && !c.symbol().startsWith("$Text");
    }

    /** Whether this is a special constructor...it starts with '$'. */
    public static boolean isInvisibleProperty(String name)
    {
    	return name.startsWith("$$");
    }

    /** Whether this is a special sort...it starts with '$'. */
    public static boolean isBuiltinSort(String sort)
    {
    	return sort != null && sort.startsWith("$") && !sort.startsWith("$Text");
    }

    /** Whether this is a literal sort. */
    public static boolean isLiteralSort(String sort)
    {
    	return sort != null && (CRS.STRING_SORT.equals(sort) || CRS.BOOLEAN_SORT.equals(sort) || CRS.NUMERIC_SORT.equals(sort));
    }
    
    /**
     * Compute sort of term as can be derived from a top-down investigation. 
     * @param factory for checking sorts
     * @param term to guess the sort of
     */
    public static GenericTerm sortOf(GenericFactory factory, Term term)
    {
    	if (term == null || term.kind() != Kind.CONSTRUCTION)
    		return null;
    	String literalSort = term.constructor().literalSort();
    	if (literalSort != null)
    		return factory.constant(factory.makeLiteral(literalSort, CRS.STRING_SORT));
    	Set<Pair<Term,Term>> sortforms = factory.formsOf(Util.symbol(term));
    	if (sortforms == null || sortforms.isEmpty())
    		return null;
    	// Search for a form that can be used to retrieve sort!
    	for (Pair<Term,Term> sortform : sortforms)
    	{
        	Term form = sortform.tail();
        	if (form.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(form)))
        		form = form.sub(0);
        	if (form.arity() != term.arity())
        		continue;
        	// We found a form that fits.
        	Map<Variable,Term> variableSorts = impliedVariableSorts(factory, term, form);
        	GenericTerm sort = (GenericTerm) sortform.head();
        	// TODO: Sort variables...not just variable sorts!!!
    		if (sort.kind() == Kind.VARIABLE_USE && variableSorts.containsKey(sort.variable()))
    		{
    			// Sort is variable that we could resolve.
    			return (GenericTerm) variableSorts.get(sort.variable());
    		}
    		else if (sort.arity() == 0)
    		{
    			// Got a sort with no sort variables so we are done.
    			return sort;
    		}
    		else
    		{
    			// Got a polymorphic sort that we shall instantiate as much as possible.
    			GenericTerm[] argumentSorts = new GenericTerm[sort.arity()];
    			for (int i = 0; i < argumentSorts.length; ++i)
    				if (sort.sub(i).kind() == Kind.VARIABLE_USE && variableSorts.containsKey(sort.sub(i).variable()))
    					argumentSorts[i] = (GenericTerm) variableSorts.get(sort.sub(i).variable());
    				else
    					argumentSorts[i] = sort.sub(i); // alas
    			return factory.newForm(Util.symbol(sort), argumentSorts);
    		}
    	}
    	return null; // failed to find sort
    }
    
	/**
	 * Compute any sort variable bindings implied by relationship between term and form.
	 * @param factory for term creation and sort lookups
	 * @param term to extract information from
	 * @param form of the term
	 * @return map from variables to sorts that are implied by the term having the sort
	 */
	public static Map<Variable,Term> impliedVariableSorts(GenericFactory factory, Term term, Term form)
    {
		assert term.kind() == Kind.CONSTRUCTION && form.kind() == Kind.CONSTRUCTION; 
		assert Util.symbol(term).equals(Util.symbol(form));
		assert term.arity() == form.arity();
		Map<Variable,Term> impliedVariableSorts = new IdentityHashMap<Variable, Term>();
		for (int i = 0; i < term.arity(); ++i)
		{
			Term formSub = form.sub(i);
			// TODO: also extract form *binder sorts* to add constraints.
			if (formSub.kind() == Kind.VARIABLE_USE)
			{
				Term sub = term.sub(i);
				Term subSort = sortOf(factory, sub);
				if (subSort != null)
					impliedVariableSorts.put(formSub.variable(), subSort);
			}
		}
	    return impliedVariableSorts;
    }

	/**
	 * Whether the constructor is a data constructor.
	 * @param factory with sorts
	 * @param constructor to check
	 */
	public static boolean isData(GenericFactory factory, Constructor constructor)
    {
		boolean result = (constructor != null && factory.isData(constructor.symbol())); 
		System.out.println("IS_DATA("+constructor.symbol()+") = "+result);
		return result;
    }
	
	/** Return the array with the rank (number of binders) of each subterm. */
	public static int[] ranks(Term form)
	{
		int[] ranks = new int[form.arity()];
		for (int i = 0; i < ranks.length; ++i)
			ranks[i] = form.binders(i).length;
		return ranks;
	}
	
	/** Return the array of variable parameters of the sort term. */
	public static Variable[] sortParams(Term sortTerm)
    {
		final Variable[] params = new Variable[sortTerm.arity()];
		for (int i = 0; i < params.length; ++i)
			params[i] = sortTerm.sub(i).variable();
	    return params;
    }

	/** Global randomizer */
	final public static Random RANDOM = new Random(); 
	
	/**
	 * Return unique name for v that can be reparsed...
	 * @param v variable to get name for
	 * @param used collects all already named variables and their names (may be modified)
	 *   - as a special case, if used maps null then that is used as the variable index and bumped!
	 * @param omitLinearity set to avoid linearity marker
	 * @param omitEncoding set to avoid encoding (v"...") of non-standard names.
	 */
	public static String safeVariableName(Variable v, Map<Variable, String> used, boolean omitLinearity, boolean omitEncoding)
	{
		String n = used.get(v);
		if (n == null)
		{
			if (used.containsKey(null))
			{
				String[] words = v.name().split("[-_0-9]", 2);
				n = words[0];
				n = n.replaceAll("__V[0-9]+¹", "");
				if (n.isEmpty() || !n.matches("[a-z][A-Za-z0-9]*")) n = "v";
				int i = Integer.parseInt(used.get(null));
				n = n + "__V" + i;
				used.put(null, Integer.toString(i+1));
				used.put(v, n);
			}
			else
			{
				// Add v in used.
				n = v.name(); // first try the name...
				if (used != null && used.containsValue(n))
				{
					// Existing name already used...bump it until unique
					// Try random name
					int modulo = 100;
					do
					{
						String bumped = n + "_" + (Math.abs(RANDOM.nextInt()) % modulo);
						if (!used.containsValue(bumped))
						{
							v.setName(bumped);
							n = bumped;
							break;
						}

						// Increase modulo to have better chance of finding a unique variable name earlier
						modulo += 100;
					}
					while (true);
				}
				used.put(v, n);
			}
		}
		return (omitLinearity || v.promiscuous() ? "" : "\u00B9") + (omitEncoding ? n : externalizeVariable(n));
	}
	
	/**
	 * Output variable set in context.
	 * @param set of variables to output
	 * @param used variable names already used (see {@link #safeVariableName(Variable, Map, boolean, boolean)})
	 * @return variables between [] separated by comma
	 */
	public static String variableSetToString(Set<Variable> set, Map<Variable, String> used)
	{
		StringBuilder b = new StringBuilder();
		b.append('[');
		String sep = "";
		for (Variable v : set)
		{
			b.append(sep);
			b.append(safeVariableName(v, used, false, false));
			sep = ",";
		}
		b.append(']');
		return b.toString();
	}

	/** Get implicit integer from factory environment variable. */
	public static int getInteger(Factory<? extends Term> factory, String name, int fallback)
	{
		if (factory.defined(name))
		{
			Stub t = factory.get(name);
			if (t.kind() == Kind.CONSTRUCTION)
			{
				String s = t.constructor().symbol();
				try
				{
					return Integer.parseInt(s);
				}
				catch (NumberFormatException e)
				{}
			}
			return 1;
		}
		return fallback;
	}
	
    /** Utility to export &lang;CONSTRUCTOR&rang; token in reparseable form. */
	public static String externalizeConstructor(String symbol)
	{
		return CONSTRUCTOR_PATTERN.matcher(symbol).matches()
			? symbol
			: Util.singleQuoteJava(symbol); // fall back to quoting as Java string
	}

    /** Utility to export literal &lang;CONSTRUCTOR&rang; token in reparseable form. */
	public static String externalizeLiteral(String symbol)
	{
		return CONSTRUCTOR_PATTERN.matcher(symbol).matches()
			? symbol
			: Util.quoteJava(symbol); // fall back to quoting as Java string
	}
	
	/** Utility to export &lang;VARIABLE&rang; token in reparseable form. */
	public static String externalizeVariable(String name)
	{
		return name == null ? "vNULL" :
			VARIABLE_PATTERN.matcher(name).matches()
			? name
			: "v" + Util.quoteJava(name); // fall back to quoting as Java string
	}

	/** Utility to export &lang;METAVARIABLE&rang; token in reparseable form. */
	public static String externalizeMetaVariable(String name)
	{
		return META_VARIABLE_PATTERN.matcher(name).matches()
			? name
			: "#" + Util.quoteJava(name); // fall back to quoting
	}

	/**
	 * Append unescaped characters from string.
	 * @param appendable to append to
	 * @param stringWithEscapes text to append after resolving escape sequences
	 * @param begin index of first character to output
	 * @param end index of character just after last to output
	 * @param quote character for which two consecutive copies are reduced to one
	 * @throws IOException if there is an output error
	 */
	public static void appendUnescaped(Appendable appendable, String stringWithEscapes, int begin, int end, char quote) throws IOException
	{
		if (stringWithEscapes == null)
			return;

		for (int i = begin; i < end; ++i)
		{
			char c = stringWithEscapes.charAt(i);
			if (c == quote)
			{
				// Possibly repeated quote.
				c = stringWithEscapes.charAt(++i);
				if (c != quote)
					appendable.append(quote); // not a repeated quote so echo the quote and continue...
			}
			if (c == '\\')
			{
				// Escape characters.
				switch (c = stringWithEscapes.charAt(++i))
				{
					case 'b' : appendable.append('\b'); break;
					case 't' : appendable.append('\t'); break;
					case 'n' : appendable.append('\n'); break;
					case 'f' : appendable.append('\f'); break;
					case 'r' : appendable.append('\r'); break;

					case '0' : case '1' : case '2' : case '3' :
						appendable.append((char) Integer.parseInt(stringWithEscapes.substring(i, i+3), 8)); i += 3;
						break;

					case 'u' : {
						String sub = (stringWithEscapes.length()-i < 5 ? stringWithEscapes.substring(i+1) : stringWithEscapes.substring(i+1, i+5));
						appendable.append((char) Integer.parseInt(sub, 16)); i += sub.length();
						break;
					}

					case 'U' : {
						int codePoint = Integer.parseInt(stringWithEscapes.substring(i+1, i+9), 16); i += 8;
						char[] chars = Character.toChars(codePoint);
						for (char surrogate : chars) appendable.append(surrogate);
						break;
					}

					default :
						appendable.append(c);
						if (Character.isHighSurrogate(c))
							appendable.append(c = stringWithEscapes.charAt(++i));
				}
			}
			else
			{
				appendable.append(c);
				if (Character.isHighSurrogate(c))
					appendable.append(c = stringWithEscapes.charAt(++i));
			}
		}
	}
	
	/**
	 * Generalized quote remover.
	 * <ol>
	 * <li>Removes leading and trailing spaces.
	 * <li>Removes one quote character from each end.
	 * <li>
	 * </ol>
	 * @param quotedString
	 * @return
	 */
	public static String unquoteJava(String quotedString)
	{
		if (quotedString == null || quotedString.length() == 0)
			return "";
		quotedString = quotedString.trim();
		assert quotedString.length() >= 2;
		char quote = quotedString.charAt(0);
		switch (quote)
		{
			case '\'' : case '"' :
				assert quote == quotedString.charAt(quotedString.length() - 1) : "Bad Java string: " + quotedString;
				break;
		}
		StringBuilder b = new StringBuilder();
		try
		{
			Util.appendUnescaped(b, quotedString, 1, quotedString.length()-1, quote);
		}
		catch (IOException e)
		{
			assert false : "Unexpected exception: "+e.getMessage();
		}
		return b.toString();
	}

	/** Convert string to Java-compatible source form. */
	public static String quoteJava(String s)
	{
		StringBuilder b = new StringBuilder();
		b.append('"');
		quoteJavaContent(s, b);
		b.append('"');
		return b.toString();
	}

	/** Convert string to Java-compatible source form. */
	public static String singleQuoteJava(String s)
	{
		StringBuilder b = new StringBuilder();
		b.append('\'');
		quoteJavaContent(s, b);
		b.append('\'');
		return b.toString();
	}

	/** Convert string to Java-compatible source form. */
	public static void quoteJavaContent(String s, StringBuilder b)
	{
		for (int i = 0; i < s.length(); ++i)
		{
			char c = s.charAt(i);
			if (Character.isHighSurrogate(c))
			{
				int codepoint = Character.codePointAt(s, i++);
				if (codepoint < 0xFFFF)
					b.append("\\u" + hex(codepoint, "0000"));
				else
					b.append("\\U" + hex(codepoint, "00000000"));
			}
			else
				quotedJavaChar(c, b);
		}
	}

	/** Convert string to Java/C identifier form with leading _M_ (reversible and idempotent, suspicious characters are replaced with hex form). */
	public static String quoteJavaIdentifierPart(String s)
	{
		if (s.startsWith("_M_")) return s; // already mangled!
		StringBuilder b = new StringBuilder();
		b.append("_M_");
		final int n = s.length();
		for (int i = 0; i < n; ++i)
		{
			char c = s.charAt(i);
			switch (c)
			{
				case '-' : {
					if (i+1 >= s.length() || ('A' <= s.charAt(i+1) && s.charAt(i+1) <= 'Z'))
						b.append("_");
					else
						b.append("__");
					break;
				}
				case '_' : b.append("_x"); break;
				case '~' : b.append("_w"); break;
				case '$' : b.append("_s"); break;
				case '#' : b.append("_h"); break;
				default :
					if (c <= '~')
					{
						if (Character.isJavaIdentifierPart(c))
							b.append(c);
						else
							b.append("_" + hex(c, "00").toLowerCase());
					}
					else
						b.append("_u" + hex(c, "0000").toLowerCase());
			}
		}
		return b.toString();
	}
	
	/** Reverse the effect of {@link #quoteJavaIdentifierPart(String)}. */
	public static String unquoteJavaIdentifierPart(String s)
	{
		if (!s.startsWith("_M_")) return s; // already unmangled!
		StringBuilder b = new StringBuilder();
		for (int i = 3; i < s.length(); ++i)
		{
			char c = s.charAt(i);
			if (c == '_' && (++i) < s.length())
			{
				switch (c = s.charAt(i))
				{
					case '_' : b.append("-"); break;
					case 'x' : b.append("_"); break;
					case 'w' : b.append("~"); break;
					case 's' : b.append("$"); break;
					case 'h' : b.append("#"); break;
					
					case '0' : case '1' : case '2' : case '3' : case '4' : case '5' : case '6' : case '7' : case '8' : case '9' :
					case 'a' : case 'b' : case 'c' : case 'd' : case 'e' : case 'f' :
						b.append(Integer.parseInt(s.substring(i, i+2), 16));
						break;
					case 'u' :
						b.append(Integer.parseInt(s.substring(i, i+4), 16));
					default :
						b.append("-"+c);
				}
			}
			else
			{
				b.append(c);
			}
		}
		return b.toString();
	}

	/**
	 * Convert character to Java-compatible source form for use in a string.
	 * @param c character
	 * @param b stream to append to
	 */
	public static void quotedJavaChars(String chars, StringBuilder b)
	{
		for (int i = 0; i < chars.length(); ++i)
			quotedJavaChar(chars.charAt(i), b);
	}
	
	/**
	 * Convert character to Java-compatible source form for use in a string.
	 * @param c character
	 * @param b stream to append to
	 */
	public static void quotedJavaChar(char c, StringBuilder b)
	{
		switch (c)
		{
			case '\b' : b.append("\\b"); break;
			case '\t' : b.append("\\t"); break;
			case '\n' : b.append("\\n"); break;
			case '\f' : b.append("\\f"); break;
			case '\r' : b.append("\\r"); break;
			case '\'' : b.append("\\'"); break;
			case '\"' : b.append("\\\""); break;
			case '\\' : b.append("\\\\"); break;
			default :
				if (Character.isISOControl(c))
					b.append("\\" + octal((int) c, "000"));
				else if (c <= '~')
					b.append(c);
				else if (c <= '\377')
					b.append("\\" + octal((int) c, "000"));
				else
					b.append("\\u" + hex((int) c, "0000"));
		}
	}

	/** Return hex string for character inserted right adjusted in template. */
	public static String hex(int c, String template)
	{
		String s = Integer.toHexString(c);
		return template.substring(s.length()) + s;
	}

	/** Return octal string for character inserted right adjusted in template. */
	public static String octal(int c, String template)
	{
		String s = Integer.toOctalString(c);
		return template.substring(s.length()) + s;
	}

	/**
	 * Return string without surrounding {}s, replacing {{ and }} inside with single { and }, respectively.
	 * @throws IllegalArgumentException if the string has internal { or } characters that are not double.
	 */
	public static String unbrace(String s)
	{
		if (!s.startsWith("{") || !s.endsWith("}")) throw new IllegalArgumentException("unbrace of string without leading { and trailing }");
		{
			int firstEnd = s.indexOf('}');
			int lastBegin = s.lastIndexOf('{');
			if (lastBegin == 0 && firstEnd == s.length()-1)
				return s.substring(1, s.length()-1);
		}
		
		StringBuilder b = new StringBuilder();
		for (int i = 1; i < s.length()-1; ++i)
		{
			char c = s.charAt(i);
			switch (c)
			{
				case '{' :
				case '}' :
					if (i == s.length()-1 || s.charAt(i+1) != c) throw new IllegalArgumentException("unbrace of string with lone { or } character.");
					++i;
			}
			b.append(c);
		}
		return b.toString();
	}

	/**
	 * Unwrap two characters from either end.
	 * @param s to unwrap characters from
	 * @return string without the characters.
	 */
	public static String unwrap2(String s)
	{
		if (s == null) return s;
		return s.substring(2, s.length()-2);
	}

	/**
	 * Return materialized term.
	 * @param stub to materialize 
	 * @param discard whether the stub can then be discarded
	 */
	public static Term materialize(Stub stub, boolean discard)
	{
		return stub == null ? null : stub.copy(discard, null);
	}
	
	/**
	 * Defensive symbol extraction.
	 * @param stub to extract the symbol of
	 * @return {@link Constructor#symbol()} of the stub, or null if this is not possible
	 */
	public static String symbol(Stub stub)
	{
		if (stub != null)
		{
			switch (stub.kind())
			{
				case CONSTRUCTION :
					Constructor c = stub.constructor();
					if (c == null)
						return null;
					return c.symbol();
				case META_APPLICATION :
					return stub.metaVariable();
				case VARIABLE_USE :
					return stub.variable().name();
			}
		}
		return null;
	}
	
	/**
	 * Defensive subterm.
	 */
	public static Term sub(Term term, int index)
	{
		if (term != null)
			return term.sub(index);
		return null;
	}
	
	/**
	 * Lookup class.
	 * @param factory with environment where package=... prefix is obtained in className is not qualified
	 * @param className name of class
	 * @throws CRSException if anything goes wrong...
	 */
	public static Class<?> classForName(Factory<? extends Term> factory, String className) throws CRSException
	{
		if (!className.contains(".") && factory.defined(Factory.PACKAGE_OPTION))
			className = Util.symbol(factory.get(Factory.PACKAGE_OPTION)) + "." + className;
		try
		{
			// load if additional class loader is added 
			String path = className.replace(".", "/") + ".class";
			if (Thread.currentThread().getContextClassLoader().getResource(path) != null)
				return Thread.currentThread().getContextClassLoader().loadClass(className);

			// if Util.class.getClassLoader().getResource(path) return instance of URL,
			// Class.forName(className) returns class.
			return Class.forName(className);
		}
		catch (ClassNotFoundException e)
		{
			throw new CRSException(e);
		}
	}

	/**
	 * Create class instance.
	 * @param factory with environment where package=... prefix is obtained in className is not qualified
	 * @param className name of class
	 * @throws CRSException if anything goes wrong...
	 */
	public static Object classInstance0(Factory<? extends Term> factory, String className) throws CRSException
	{
		try
		{
			return classForName(factory, className).newInstance();
		}
		catch (InstantiationException e)
		{
			throw new CRSException(e);
		}
		catch (IllegalAccessException e)
		{
			throw new CRSException(e);
		}
	}
	
	/**
	 * Invoke a dynamically named method with zero arguments.
	 * @param object to invoke the method on
	 * @param type in type hieharchy of object containing the method
	 * @param methodName to invoke
	 * @throws CRSException if anything goes wrong...
	 */
	public static Object invoke0(Object object, Class<?> type, String methodName) throws CRSException
	{
		try
		{
			Method m = type.getMethod(methodName);
			return m.invoke(object);
		}
		catch (SecurityException e)
		{
			throw new CRSException(e);
		}
		catch (NoSuchMethodException e)
		{
			throw new CRSException(e);
		}
		catch (IllegalArgumentException e)
		{
			throw new CRSException(e);
		}
		catch (IllegalAccessException e)
		{
			throw new CRSException(e);
		}
		catch (InvocationTargetException e)
		{
			throw new CRSException(e);
		}
	}
	
	/**
	 * Invoke a dynamically named method with one argument.
	 * @param object to invoke the method on
	 * @param type in type hieharchy of object containing the method
	 * @param methodName to invoke
	 * @param argument to method
	 * @param argumentType declared type of argument in method
	 * @throws CRSException if anything goes wrong...
	 */
	public static Object invoke1(Object object, Class<?> type, String methodName, Object argument, Class<?> argumentType) throws CRSException
	{
		try
		{
			Method m = type.getMethod(methodName, argumentType);
			return m.invoke(object, argument);
		}
		catch (SecurityException e)
		{
			throw new CRSException(e);
		}
		catch (NoSuchMethodException e)
		{
			throw new CRSException(e);
		}
		catch (IllegalArgumentException e)
		{
			throw new CRSException(e);
		}
		catch (IllegalAccessException e)
		{
			throw new CRSException(e);
		}
		catch (InvocationTargetException e)
		{
			throw new CRSException(e);
		}
	}

	/**
	 * Load all data into a string and then reissue it...
	 * @param reader to buffer
	 * @throws CRSException if anything goes wrong
	 */
	public static String read(Reader reader) throws CRSException
	{
		StringBuilder b = new StringBuilder();
		char[] cbuf = new char[1000];
		int z;
		try
		{
			while ((z = reader.read(cbuf)) >= 0)
				b.append(cbuf, 0, z);
		}
		catch (IOException e)
		{
			throw new CRSException(e);
		}
		return b.toString();
	}

	/**
	 * Copy the location of an existing constructor, if any, to a new one.
	 * @param maker to use for creation
	 * @param target the new constructor that should have the same location
	 * @param original the constructor with a location
	 * @return the new constructor after it has been given the location (possibly by wrapping)
	 */
	public static Constructor copyLocation(Maker maker, Constructor target, Constructor original)
	{
		if (original != null)
		{
			try
            {
				Term file = original.getProperty(Parser.TOKEN_FILE_LOCATION); 
				if (file != null)
					target = Util.wrapWithProperty(maker, target, Parser.TOKEN_FILE_LOCATION, file);
				Term line = original.getProperty(Parser.TOKEN_LINE_LOCATION); 
				if (line != null)
					target = Util.wrapWithProperty(maker, target, Parser.TOKEN_LINE_LOCATION, line);
				Term column = original.getProperty(Parser.TOKEN_LINE_LOCATION); 
				if (column != null)
					target = Util.wrapWithProperty(maker, target, Parser.TOKEN_COLUMN_LOCATION, column);
            }
            catch (NumberFormatException e)
            {}
            catch (CRSException e)
            {}
		}
		return target;
	}

    /** Return the propertiesholder for the term, or null if none. The result may be a {@link PropertiesConstraintsWrapper}. */
    public static PropertiesHolder propertiesHolder(Term term)
    {
    	return (term == null || term instanceof PropertiesHolder ? (PropertiesHolder) term : term.constructor());
    }
    
    /** Whether term has a property. */
    public static boolean hasProperty(Term term, Variable variable)
    {
    	PropertiesHolder ph = propertiesHolder(term);
    	return ph != null && ph.getProperty(variable) != null;
    }

    /** Whether term has a property. */
    public static boolean hasProperty(Term term, String name)
    {
    	PropertiesHolder ph = propertiesHolder(term);
    	return ph != null && ph.getProperty(name) != null;
    }

    /** Whether term has a negated property. */
    public static boolean hasNotProperty(Term term, String name)
    {
    	return term instanceof PropertiesConstraintsWrapper && ((PropertiesConstraintsWrapper) term).hasNotProperty(name);
    }

    /** Whether term has any properties at all.  A properties reference does not count. */
    public static boolean hasProperties(Term term)
    {
    	if (term == null) return false;
    	PropertiesHolder ph = propertiesHolder(term);
    	if (ph == null) return false;
	    if (ph.propertyNames().iterator().hasNext())
	    	return true; // succeed because named properties
	    if (ph.propertyVariables().iterator().hasNext())
	    	return true; // succeed because variable properties
	    if (ph.isMeta())
	    {
    		if (ph instanceof PropertiesConstraintsWrapper)
    		{
    			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
    			if (pcw.propertyMetaVariables().iterator().hasNext())
    				return true; // succeed because there are meta-properties
    		}
	    }
	    return false; // no success means failure...
    }

    /** Whether term has any properties at all.  A properties reference does not count. */
    public static boolean hasNonVariableProperties(Term term)
    {
    	PropertiesHolder ph = propertiesHolder(term);
	    if (ph.propertyNames().iterator().hasNext())
	    	return true; // succeed because named properties
	    if (ph.isMeta())
	    {
    		if (ph instanceof PropertiesConstraintsWrapper)
    		{
    			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
    			if (pcw.propertyMetaVariables().iterator().hasNext())
    				return true; // succeed because there are meta-properties
    		}
	    }
	    return false; // no success means failure...
    }

    /**
     * Whether term is of special case where it has at most one variable property.
     * @param term to test
     * @param variable only property permitted (or null for none permitted) 
     */
	public static boolean hasAtMostVariableProperty(Term term, Variable variable)
    {
    	PropertiesHolder ph = propertiesHolder(term);
	    if (ph.propertyNames().iterator().hasNext())
	    	return false; // fail because non-variable properties
	    Iterator<Variable> vs = ph.propertyVariables().iterator();
	    if (vs.hasNext())
	    {
	    	if (vs.next() != variable)
	    		return false; // fail because bad variable property
		    if (vs.hasNext())
	    		return false; // fail because more than the single permitted variable property
	    }
	    if (ph.isMeta())
	    	return false; // fail because there are meta-properties
	    return true; // no fail means success
    }
	
    /** Get property from term or null. */
    public static Term getProperty(Term term, Variable variable)
    {
    	PropertiesHolder ph = propertiesHolder(term);
    	return ph == null ? null : ph.getProperty(variable);
    }

    /** Get property from term or null. */
    public static Term getProperty(Term term, String name)
    {
    	PropertiesHolder ph = propertiesHolder(term);
    	return ph == null ? null : ph.getProperty(name);
    }

    /** Whether term has a property reference. */
    public static boolean hasPropertyRef(Term term)
    {
    	return term instanceof PropertiesConstraintsWrapper && ((PropertiesConstraintsWrapper) term).propertiesRef() != null;
    }

    /** Property reference. */
    public static String propertyRef(Term term)
    {
    	return term instanceof PropertiesConstraintsWrapper ? ((PropertiesConstraintsWrapper) term).propertiesRef() : null;
    }

    /** Get property from term or null. */
    public static GenericTerm wrapWithProperty(GenericTerm term, Variable key, Term value)
    {
    	PropertiesHolder ph = propertiesHolder(term);
    	if (ph != null)
    	{
    		try
    		{
    			ph.setProperty(key, value);
    			return term;
    		}
    		catch (CRSException e)
    		{}
    	}
    	// Fallback.
    	Map<Variable,Term> extra = new HashMap<Variable, Term>();
    	extra.put(key, value);
    	return new PropertiesConstraintsWrapper(term, null, null, extra, null);
    }

    /** Set a property and return term with property set. */
    public static GenericTerm wrapWithProperty(GenericTerm term, String key, Term value)
    {
    	PropertiesHolder ph = propertiesHolder(term);
    	if (ph != null)
    	{
	        try
            {
	            ph.setProperty(key, value);
    			return term;
            }
            catch (CRSException e)
            {}
    	}
    	// Fallback.
    	Map<String,Term> extra = new HashMap<String, Term>();
    	extra.put(key, value);
    	return new PropertiesConstraintsWrapper(term, null, extra, null, null);
    }

    /**
     * Get a list with a pair for every key in the properties of the term. 
     * @param term to look for properties in
     * @param factory to generate the terms
     */
    public static List<Pair<Term,Term>> allProperties(PropertiesHolder ph, GenericFactory factory)
    {
    	List<Pair<Term,Term>> list = new ArrayList<Pair<Term,Term>>();
    	for (String n : ph.propertyNames())
    		list.add(new Pair<Term, Term>(factory.constant(factory.makeLiteral(n, CRS.STRING_SORT)), ph.getProperty(n)));
    	for (Variable v : ph.propertyVariables())
    		list.add(new Pair<Term, Term>(factory.newVariableUse(v), ph.getProperty(v)));
    	if (ph.isMeta())
    	{
    		if (ph instanceof PropertiesConstraintsWrapper)
    		{
    			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ph;
    			for (String m : pcw.propertyMetaVariables())
    	    		list.add(new Pair<Term, Term>(factory.newMetaApplication(m, null), pcw.getMetaProperty(m)));
    		}
    	}
    	return list;
    }
    
    /**
     * Get the named properties...
     */
    public static Map<String,Term> namedProperties(PropertiesHolder ph, GenericFactory factory)
    {
    	Map<String,Term> list = new HashMap<String, Term>();
    	for (String n : ph.propertyNames())
    		list.put(n, ph.getProperty(n));
    	return list;
    }

	/**
	 * Add or remove a single named property to a constructor, returning the possibly wrapped extended constructor.
	 * @param maker for constructor generation
	 * @param constructor to set properties on
	 * @param name of property
	 * @param value to set or modify the property to (or null to remove it)
	 * @throws CRSException if the property is impossible to set
	 */
	public static Constructor wrapWithProperty(Maker maker, Constructor constructor, String name, Term value) throws CRSException
	{
		if (constructor.canSetProperty(name))
		{
			constructor = constructor.copy(null);
		}
		else
		{
			Map<String, Term> namedProperties = new HashMap<String, Term>();
			Map<Variable, Term> variableProperties = new HashMap<Variable, Term>();
			constructor = new PropertiesConstructor(maker, constructor, namedProperties, variableProperties);
		}
		constructor.setProperty(name, value);
		return constructor;
	}

	/**
	 * Add or remove a single variable property to a constructor, returning the possibly wrapped extended constructor.
	 * @param maker for constructor generation
	 * @param constructor to set properties on
	 * @param variable to add a property value for
	 * @param value of property (or null to remove it)
	 */
	public static Constructor wrapWithProperty(Maker maker, Constructor constructor, Variable variable, Term value)
	{
		if (constructor.canSetProperty(variable))
		{
			constructor = constructor.copy(null);
		}
		else
		{
			Map<String, Term> namedProperties = new HashMap<String, Term>();
			Map<Variable, Term> variableProperties = new HashMap<Variable, Term>();
			constructor = new PropertiesConstructor(maker, constructor, namedProperties, variableProperties);
		}
		try
        {
	        constructor.setProperty(variable, value);
        }
        catch (CRSException e)
        {}
		return constructor;
	}

	/**
	 * Set desired properties on the constructor, wrapping it if necessary - and then return the changed constructor.
	 * If no properties provided then returns constructor unmodified. (Does not copy meta-properties.)
	 * @param maker for constructor generation
	 * @param constructor to set properties on
	 * @param namedProperties to set (null means none)
	 * @param variableProperties to set (null means none)
	 * @throws CRSException if any of the properties are impossible to set
	 */
	public static Constructor wrapWithProperties(Maker maker, Constructor constructor, Map<String, Term> namedProperties, Map<Variable, Term> variableProperties) throws CRSException
	{
		if (constructor instanceof PropertiesConstructor)
		{
			PropertiesConstructor pc = (PropertiesConstructor) constructor;
			pc.setNamedProperties(namedProperties);
			pc.setVariableProperties(variableProperties);
			return constructor;
		}
		else if ((namedProperties == null || namedProperties.isEmpty()) && (variableProperties == null || variableProperties.isEmpty()))
		{
			return constructor;
		}
		else
		{
			return new PropertiesConstructor(maker, constructor, namedProperties, variableProperties);
		}
	}

	/**
	 * Set properties on the constructor, wrapping it if necessary - and then return the changed constructor.
	 * If no properties provided then returns constructor unmodified. (Does not copy meta-properties.)
	 * @param maker for constructor generation
	 * @param constructor to set properties on
	 * @param properties to set (null means none)
	 */
	public static Constructor wrapWithProperties(Maker maker, Constructor constructor, PropertiesHolder properties) throws CRSException
	{
		if (properties != null)
		{
			if (constructor instanceof PropertiesConstructor)
				((PropertiesConstructor) constructor).setProperties(properties);
			else
			{
				for (String name : properties.propertyNames())
					constructor = wrapWithProperty(maker, constructor, name, properties.getProperty(name));
				for (Variable variable : properties.propertyVariables())
					constructor = wrapWithProperty(maker, constructor, variable, properties.getProperty(variable));
			}
		}
		return constructor;
	}

	/**
	 * Add the ref property reference to all function symbols in term (not data, not meta-applications, not variables).
	 * @param factory with type information
	 * @param term to populate
	 * @param ref to insert
	 * @return destructively updated term
	 */
	public static GenericTerm inherit(GenericFactory factory, GenericTerm term, String ref)
	{
		if (factory.isFunction(Util.symbol(term)))
			term = term.wrapWithPropertiesRef(ref, true);
		final int z = term.arity();
		for (int i = 0; i < z; ++i)
			term.replaceSub(i, term.binders(i), inherit(factory, term.sub(i), ref));
		return term;
	}

	/**
	 * Add the ref property reference to all data symbols and variables in term (not functions, not meta-applications).
	 * @param factory with type information
	 * @param term to populate
	 * @param ref to insert
	 * @return destructively updated term
	 */
	public static GenericTerm synthesize(GenericFactory factory, GenericTerm term, String ref)
	{
		if (factory.isData(Util.symbol(term)))
			term = term.wrapWithPropertiesRef(ref, true);
		final int z = term.arity();
		for (int i = 0; i < z; ++i)
			term.replaceSub(i, term.binders(i), inherit(factory, term.sub(i), ref));
		return term;
	}
	
	/**
	 * Special variant for wrapping with properties describing the location of something.
	 * @param maker for creating constants
	 * @param c constructor to wrap
	 * @param file name of file (null to not set)
	 * @param line number of first line (1-based, 0 to not set)
	 * @param column number of first column (1-based, 0 to not set)
	 * @throws CRSException on failure
	 */
	public static Constructor wrapWithLocation(Maker maker, Constructor c, String file, int line, int column)
	{
		try
		{
			if (file != null)
				c = Util.wrapWithProperty(maker, c, Parser.TOKEN_FILE_LOCATION, Buffer.materializeTagged(maker, Parser.TOKEN_FILE_LOCATION_WRAPPER, file));
			if (line > 0)
				c = Util.wrapWithProperty(maker, c, Parser.TOKEN_LINE_LOCATION, Buffer.materializeTagged(maker, Parser.TOKEN_LINE_LOCATION_WRAPPER, line));
			if (column > 0)
				c = Util.wrapWithProperty(maker, c, Parser.TOKEN_COLUMN_LOCATION, Buffer.materializeTagged(maker, Parser.TOKEN_COLUMN_LOCATION_WRAPPER, column));
		}
		catch (CRSException e)
		{}
		return c;
	}
	
	/**
	 * Make a copy of a map of named properties.
	 * @param named properties (may map some values to null)
	 * @param renames to propagate
	 * @param discard whether the map should be discarded afterwards
	 */
	public static Map<String, Term> copyNamedProperties(Map<String, Term> named, ExtensibleMap<Variable, Variable> renames, boolean discard)
	{
		if (discard && renames.isEmpty())
			return named; // copy by reference since the reuse cannot be observed.
		else
		{
			// Create new map with copies of all the properties.
			Map<String, Term> np = new HashMap<String, Term>();
			for (Map.Entry<String, Term> e : named.entrySet())
			{
				String k = e.getKey();
				Term v = e.getValue();
				np.put(k, v == null ? null : v.copy(discard, renames));
			}
			return np;
		}
	}

	/**
	 * Make a copy of a map of variable properties.
	 * @param variabled properties (may map some values to null)
	 * @param renames to propagate
	 * @param discard whether the map should be discarded afterwards
	 */
	public static Map<Variable, Term> copyVariableProperties(Map<Variable, Term> variabled, ExtensibleMap<Variable, Variable> renames, boolean discard)
	{
		renames = (renames != null ? renames : LinkedExtensibleMap.EMPTY_RENAMING);
		if (discard && renames.isEmpty()) // TODO:  if renames and fv(variabled) disjoint 
			return variabled;
	
		Map<Variable, Term> vp = new HashMap<Variable, Term>();
		for (Map.Entry<Variable, Term> e : variabled.entrySet())
		{
			Variable k = e.getKey();
			if (renames.containsKey(k))
				k = renames.get(k);
			Term v = e.getValue();
			vp.put(k, v == null ? null : v.copy(discard, renames));
		}
		return vp;
	}
	
	/**
	 * Whether the stub represents a True value (not null, not 0, not the empty sequence or string, not $False).
	 * @param stub to investigate
	 */
	public static boolean isTrue(Stub stub)
	{
		if (stub == null)
			return false;
		if (stub.kind() != Kind.CONSTRUCTION)
			return true;
		Constructor c = stub.constructor();
		if (isNull(c) || c.symbol().length() == 0 || c.symbol().equals("0") || c.symbol().equals(CRS.FALSE_SYMBOL))
			return false;
		return true;
	}

	/**
	 * Return a reader for the passed resource.
	 * @param factory 
	 * @param resource to give reader to - either an actual Java resource (as managed by the class loader) or a URL.
	 * @return the reader ready to read the resource
	 * @throws CRSException if the resource cannot be read
	 */
	public static Reader resourceReader(Factory<? extends Term> factory, String resource) throws CRSException
	{
		try
		{
			// Eclipse plugin set encoding of eclipse project beforehand
			String encoding = ThreadLocalProperties.getProperty(ThreadLocalProperties.FILE_ENCODING);

			// First try resource wihout prefix...
			if (Thread.currentThread().getContextClassLoader().getResource(resource) != null)
			{
				InputStream resourceStream = Thread.currentThread().getContextClassLoader().getResourceAsStream(resource);
				return wrapInputStreamInReader(resourceStream, encoding);
			}

			InputStream resourceStream = factory.getClass().getResourceAsStream(resource);
			if (resourceStream != null)
				return wrapInputStreamInReader(resourceStream, encoding);
			
			// try full path
			File file = new File(resource);
			if (file.exists())
				return wrapInputStreamInReader(new FileInputStream(file), encoding);
			
			// ...then resource with prefix, if any...
			String resourcePrefix = Util.symbol(factory.get(Factory.RESOURCE_PREFIX));
			if (resourcePrefix != null)
			{
				resourceStream = factory.getClass().getResourceAsStream(resourcePrefix+"/"+resource);
				if (resourceStream != null)
					return wrapInputStreamInReader(resourceStream, encoding);
			}
			// ...finally fall back to URL.
			URL base = new URL("file:."); // be paranoid
			String parseContextURL = Util.symbol(factory.get(Factory.BASE_URL));
			if (parseContextURL != null)
				base = new URL(base, parseContextURL.toString());
			URL resolved = new URL(base, resource);
			return wrapInputStreamInReader(resolved.openStream(), encoding);
		}
		catch (MalformedURLException e)
		{
			throw new CRSException(e);
		}
		catch (IOException e)
		{
			throw new CRSException(e);
		}
	}

	private static final Reader wrapInputStreamInReader(InputStream resourceStream, String encoding) throws UnsupportedEncodingException {
		if (encoding == null)
			return new InputStreamReader(resourceStream); // default encoding is used
		else
			return new InputStreamReader(resourceStream, encoding);
	}
	
	/** Create singleton array. */
	public static Term[] singletonTerms(Term term)
	{
		Term[] terms = new Term[1];
		terms[0] = term;
		return terms;
	}
	
	/** Create singleton set. */
	public static <T> Set<T> singletonSet(T member)
	{
		Set<T> set = new SmallSet<T>();
		set.add(member);
		return set;
	}
	
	/** Print array. */
	public static <T> String show(T[] array)
	{
		StringBuilder b = new StringBuilder();
		b.append("[");
		for (int i = 0; i < array.length; ++i)
			b.append((i == 0 ? "" : ", ")+show(array[i]));
		b.append("]");
		return b.toString();
	}

	/** Print collection. */
	public static <T> String show(Collection<T> collection)
	{
		StringBuilder b = new StringBuilder();
		b.append("[");
		String sep = "";
		for (T member : collection)
		{
			b.append(sep+show(member));
			sep = ", ";
		}
		b.append("]");
		return b.toString();
	}

	/** Print map. */
	public static <K, V> String show(Map<K, V> map)
	{
		StringBuilder b = new StringBuilder();
		b.append("{");
		String sep = "";
		for (Map.Entry<K, V> e : map.entrySet())
		{
			b.append(sep+show(e.getKey())+"="+show(e.getValue()));
			sep = "; ";
		}
		b.append("}");
		return b.toString();
	}
	
	public static <H,T> String show(Pair<H, T> pair)
	{
		return "("+show(pair.head())+","+show(pair.tail())+")";
	}

	public static <One, Two, Three> String show(Triple<One, Two, Three> triple)
	{
		return "("+show(triple.one())+","+show(triple.two())+","+show(triple.three())+")";
	}

	/** Print object. */
	public static String show(Object object)
	{
		return object == null ? "null" : object.toString();
	}

	/**
	 *  Create array containing the elements of a list.
	 * @param term with list
	 * @param discard whether term can be invalidated by the operation
	 * @param renamings in effect for the copy...
	 */
	public static GenericTerm[] unconsArray(Term term, boolean discard, ExtensibleMap<Variable, Variable> renamings)
	{
		assert isSequence(term);
		List<Term> list = new ArrayList<Term>();
		while (Util.isCons(term.constructor()))
		{
			list.add(term.sub(0));
			term = term.sub(1).copy(discard, renamings);
		}
		assert isNull(term);
		return list.toArray(new GenericTerm[list.size()]);
	}

	/**
	 * Create array containing the subterms of term.
	 * @param term with subterms
	 * @param discard whether term can be invalidated by the operation
	 * @param renamings in effect for the copy...
	 */
	public static Term[] subsArray(Term term, boolean discard, ExtensibleMap<Variable, Variable> renamings)
	{
		Term[] subs = new Term[term.arity()];
		for (int i = 0; i < subs.length; ++i)
			subs[i] = term.sub(i).copy(discard, renamings);
		return subs;
	}

	/**
	 * Generate list of paths describing where the patterns are different.
	 * @param <T> real Term subtype used
	 * @param factory used for generating terms
	 * @param functionPatterns to find minimal different paths in
	 */
	public static <T extends Term> List<Path> differencePaths(Factory<? extends Term> factory, List<T> functionPatterns)
	{
		List<Path> differences = new ArrayList<Path>();
		List<List<Variable>> binders = new ArrayList<List<Variable>>();
		for (@SuppressWarnings("unused") T t : functionPatterns) binders.add(new ArrayList<Variable>());
		addDifferencePaths(differences, factory, Path.EMPTY, functionPatterns, null);
		return differences;
	}
	@SuppressWarnings("unchecked")
	private static <T extends Term> void addDifferencePaths(List<Path> differences, Factory<? extends Term> factory, Path path, List<T> subterms, Term sort)
	{
		if (!subterms.isEmpty())
		{
			T first = subterms.get(0);
			switch (first.kind())
			{
				case CONSTRUCTION : {
					Constructor c = first.constructor().baseConstructor();
					int a = first.arity();
					boolean different = false;
					for (T s : subterms)
					{
						if (s.kind() != Kind.CONSTRUCTION || !c.equals(s.constructor().baseConstructor()) || a != s.arity())
						{
							different = true;
						}
						else if (s.kind() == Kind.CONSTRUCTION)
						{
							// TODO: verify that all choices are of a single sort...
						}
					}
					if (different)
						differences.add(path);
					else
					{
						// All subterms are constructions c[...]
						T form = null;
						Set<Pair<Term,Term>> forms = factory.formsOf(c.symbol());
						for (Pair<Term,Term> pair : forms)
						{
							if (!pair.head().equals(sort)) continue;
							if (form == null) form = (T) pair.tail();
							else { form = null; break; }
						}
						for (int i = 0; i < a; ++i)
						{
							List<T> sss = new ArrayList<T>(); for (T s : subterms) sss.add((T) s.sub(i));
							Term subsort = (form == null ? null : form.sub(i));
							addDifferencePaths(differences, factory, path.extend(i), sss, subsort);
						}
					}
					break;
				}
				case VARIABLE_USE : {
					// TODO: Currently only identifies globally identical free variables...should really include locally bound ones, too.
					Variable v = first.variable();
					boolean different = false;
					for (T s : subterms)
						if (s.kind() != Kind.VARIABLE_USE || v != s.variable())
						{
							different = true;
							break;
						}
					if (different)
						differences.add(path);
					break;
				}
				case META_APPLICATION : {
					differences.add(path);
					break;
				}
			}
		}
	}

	/**
	 * Create pattern that is as specific as possible yet matches all terms.
	 * TODO: integrate with differencePaths?
	 * @param sink to send the pattern to
	 * @param terms that the pattern must match
	 * @return sink after having sent pattern
	 */
	public static Sink unifier(Sink sink, List<Term> terms)
	{
		return unifier2(sink, terms, new ArrayList<String>(), new ArrayList<String>(), new ArrayList<Variable>(), LinkedExtensibleMap.EMPTY_RENAMING);
	}
	public static Sink unifier2(Sink sink, List<Term> terms, List<String> metaVariables, List<String> propsVariables, List<Variable> bound, ExtensibleMap<Variable, Variable> renames)
	{
		Term first = terms.get(0);
		boolean sameKind = true;
		for (Term t : terms)  if (first.kind() != t.kind()) {sameKind = false; break;}
		if (sameKind)
		{
			Same : switch (first.kind())
			{
				case CONSTRUCTION : { // all terms are constructors
					String symbol = Util.symbol(first);
					for (Term t : terms)
					{
						if (!symbol.equals(Util.symbol(t)) || first.arity() != t.arity())
							break Same; // different constructor symbols or arities
						for (int i = 0; i < t.arity(); ++i)
							if (first.binders(i).length != t.binders(i).length)
								break Same; // different rank for subterm
					}
					// Success: all terms have similar constructor structure.  Emit construction (with catch-all properties) and recurse.
					String pv = "##props" + (propsVariables.size() + 1);
					propsVariables.add(pv);
					sink = PropertiesWrapperConstructor.start(sink, pv, null, null, null); // {#$propsi}
					sink = sink.start(first.constructor());
					for (int i = 0; i < first.arity(); ++i)
					{
						// Emit (and record mapping of) binders for subterm.
						List<Variable> subbound = bound;
						if (first.binders(i).length > 0)
						{
							Variable[] newBinders = new Variable[first.binders(i).length];
							for (int j = 0; j < newBinders.length; ++j) newBinders[j] = sink.makeVariable(first.binders(i)[j].name(), first.binders(i)[j].promiscuous());
							for (Term t : terms)
								renames = renames.extend(t.binders(i), newBinders);
							sink = sink.binds(newBinders);
							subbound = new ArrayList<Variable>(bound);
							for (Variable b : newBinders) subbound.add(b);
						}
						// Emit subterm.
						List<Term> subterms = new ArrayList<Term>();
						for (Term t : terms) subterms.add(t.sub(i));
						sink = unifier2(sink, subterms, metaVariables, propsVariables, subbound, renames);
					}
					sink = sink.end();
					sink = sink.end(); // or {#$propsi}
					return sink;
				}

				case VARIABLE_USE : { // all terms are variable usage terms
					Variable v = renames.get(first.variable());
					if (v == null) v = first.variable();
					for (Term t : terms)
					{
						Variable v2 = renames.get(t.variable());
						if (v2 == null) v2 = t.variable();
						if (v != v2)
							break Same; // different variables
					}
					// Success: all terms are the same variable.
					sink = sink.use(v);
					return sink;
				}
			}
		}
		// Fall-back to fresh meta-variable with all possible bound variables ("saturated" pattern meta-application).
		String mv = "##" + (metaVariables.size() + 1);
		metaVariables.add(mv);
		sink = sink.startMetaApplication(mv);
		for (Variable b : bound)
			sink = sink.use(b);
		sink = sink.endMetaApplication();
		return sink;
	}
	
	/** Return set of all free variables in term. */
	public static Set<Variable> freeVariables(Term term)
	{
		final Set<Variable> free = new HashSet<Variable>();
		Visitor addFree = new Visitor()
		{
            @Override
		    public void visitUse(Term use, boolean start, Set<Variable> bound) throws CRSException
		    {
            	if (start)
            	{
            		Variable v = use.variable();
            		if (!bound.contains(v))
            			free.add(v);
            	}
		    }
		};
		try
		{
			term.visit(addFree, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
		}
		catch (CRSException e)
		{}
		return free;
	}

	/**
	 * Convert a term to a string up to a certain depth.
	 * @param term to convert
	 * @param depth number of levels to convert (negative means unlimited)
	 * @return string representing the term
	 */
	public static String toString(Term term, int depth)
	{
		StringBuilder b = new StringBuilder();
		try
		{
			term.appendTo(b, new HashMap<Variable, String>(), depth, false, true, true, null);
		}
		catch (IOException e)
		{}
		return b.toString();
	}

	/**
	 * Create annotation match/contract prefix around term.
	 * @param term to wrap
	 * @param propertiesRef permitting reference to properties (not copied)
	 * @param namedPropertiesConstraints associated to the constructor (not copied)
	 * @param variablePropertiesConstraints
	 * @param metaPropertyConstraints associated to the constructor (not copied)
	 * @param purgeNames
	 * @param purgeVariables
	 * @param purgeMetaVariables
	 */
	public static PropertiesConstraintsWrapper makePropertiesConstraintsWrapper(GenericTerm term, String propertiesRef, Map<String, Term> namedPropertiesConstraints,
			Map<Variable, Term> variablePropertiesConstraints, Map<String,Term> metaPropertyConstraints)
	{
		PropertiesConstraintsWrapper pcw;
		if (term instanceof PropertiesConstraintsWrapper)
		{
			pcw = new PropertiesConstraintsWrapper((PropertiesConstraintsWrapper) term, true);
			if (propertiesRef != null) pcw.setPropertiesRef(propertiesRef);
			pcw.setPropertyConstraints(namedPropertiesConstraints);
			pcw.setVariablePropertyConstraints(variablePropertiesConstraints);
			pcw.setMetaPropertyConstraints(metaPropertyConstraints);
		}
		else
		{
			pcw = new PropertiesConstraintsWrapper(term, propertiesRef, namedPropertiesConstraints, variablePropertiesConstraints, metaPropertyConstraints);
		}
		return pcw;
	}
	
	/**
	 * Helper class for collecting occurrences of variable.
	 * After processing visitor, the {@link #occurrences} field will contain one element per occurrence, which is either a Pair(MetaVar,Index) or null.
	 * @author krisrose
	 */
	static class CountingVisitor extends Visitor
	{
		final Variable variable;
		List<Pair<String,Integer>> occurrences = new ArrayList<Pair<String,Integer>>();
		CountingVisitor(Variable variable)
		{
			this.variable = variable;
		}
        @Override
        public void visitMetaApplicationSub(Term metaApplication, int index, boolean start, Set<Variable> bound) throws CRSException
        {
        	if (!start && metaApplication.sub(index).kind() == Kind.VARIABLE_USE && metaApplication.sub(index).variable() == variable)
        	{
        		// Replace pushed 'null' with proper pair.
        		final int last = occurrences.size()-1;
        		assert last >= 0 && occurrences.get(last) == null;
        		occurrences.set(last, new Pair<String, Integer>(metaApplication.metaVariable(), index));
        	}
        }
		@Override
        public void visitUse(Term use, boolean start, Set<Variable> bound) throws CRSException
        {
        	if (start && use.variable() == variable)
        		occurrences.add(null);
        }
        @Override
        public void visitVariableProperty(Variable property, boolean start, boolean hasMapping) throws CRSException
        {
        	if (start && property == variable)
        		occurrences.add(null);
        }
	}
	
	/**
	 * Returns  list with one element per occurrence of the variable, which is either a Pair(MetaVar,Index) or null for a non-meta-application-subterm occurrence.
	 * @param term to count in
	 * @param variable to look for
	 */
	public static List<Pair<String,Integer>> metaUses(Term term, Variable variable)
	{
		CountingVisitor visitor = new CountingVisitor(variable);
		try
        {
	        term.visit(visitor, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
        }
        catch (CRSException e)
        {}
        return visitor.occurrences;
	}

	/**
	 * Returns  list with one element per occurrence of the variable, which is either a Pair(MetaVar,Index) or null for a non-meta-application-subterm occurrence.
	 * @param term to count in
	 * @param metaVarCount count of each metavariable
	 * @param variable to look for
	 */
	public static Map<String,Integer> metaVars(Term term)
	{
		final HashMap<String, Integer> metaVarCount = new HashMap<String, Integer>();
		addMetaVars(term, metaVarCount);
        return metaVarCount;
	}

	/**
	 * Returns  list with one element per occurrence of the variable, which is either a Pair(MetaVar,Index) or null for a non-meta-application-subterm occurrence.
	 * @param term to count in
	 * @param metaVarCount count of each metavariable
	 * @param variable to look for
	 */
	public static void addMetaVars(Term term, final HashMap<String, Integer> metaVarCount)
	{
		Visitor visitor = new Visitor()
		{
            @Override
            public void visitMetaApplication(Term metaApplication, boolean start, Set<Variable> bound) throws CRSException
            {
	            if (start)
	            {
	            	String mv = metaApplication.metaVariable();
	            	metaVarCount.put(mv, (metaVarCount.containsKey(mv) ? metaVarCount.get(mv)+1 : 1));
	            }
            }
		};
		try
        {
	        term.visit(visitor,  LinkedExtensibleSet.EMPTY_VARIABLE_SET);
        }
        catch (CRSException e)
        { }
	}
	
	/**
	 * Generate special occurrence term in reified BINDER structure...
	 * @param sink to send to
	 * @param term to search for occurrences
	 * @param binder to search for
	 */
	public static Sink occurrenceDescription(Sink sink, Term term, Variable binder)
	{
		final List<Pair<String,Integer>> occs = metaUses(term, binder);
		for (Pair<String,Integer> pair : occs)
		{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL));
			if (pair == null)
					sink = sink.start(sink.makeLiteral(CRS.REIFY_OTHER, CRS.STRING_SORT)).end();
			else
			{
				final String mv = pair.head();
				final Integer index = pair.tail();
				sink = sink.start(sink.makeConstructor(CRS.REIFY_META_USE)).start(sink.makeLiteral(mv, CRS.STRING_SORT)).end().start(sink.makeLiteral(index, CRS.NUMERIC_SORT)).end().end();
			}
		}
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end();
		for (@SuppressWarnings("unused") Pair<String,Integer> pair : occs)
			sink = sink.end();
		return sink;
	}

	/** Whether the argument is a term of the form (x) or  (x : Term). */
	public static boolean isVariableWithOptionalSort(Term z)
    {
		return z.kind() == Kind.VARIABLE_USE || (Builder.FUNCTION_SORT_SYMBOL.equals(Util.symbol(z)) && z.arity() == 2 && z.sub(0).kind() == Kind.VARIABLE_USE); 
    }
	
	/** Return the variable from a variable with optional sort of the form (x) or  (x : Term). */
	public static Variable variableWithOptionalSortVariable(Term z)
	{
		if (z == null)
			return null;
		assert isVariableWithOptionalSort(z);
		if (z.kind() == Kind.VARIABLE_USE)
			return z.variable();
		else
			return z.sub(0).variable();
	}

	/** Return the variable from a variable with optional sort of the form (x) or  (x : Term). */
	public static Term variableWithOptionalSortSort(Term z)
	{
		if (z == null)
			return null;
		assert isVariableWithOptionalSort(z);
		if (z.kind() == Kind.VARIABLE_USE)
			return null;
		else
			return z.sub(1);
	}

	/** Generate a variable with sort pair suitable for use in sorted variable options. */
	public static GenericTerm makeVariableWithSort(GenericFactory factory, Variable variable, GenericTerm sort)
    {
		GenericTerm use = factory.newVariableUse(variable);
		Variable[][] binders = {GenericTerm.NO_BIND, GenericTerm.NO_BIND};
		GenericTerm[] subterms = {use, sort};
		return factory.newConstruction(factory.makeConstructor(Builder.FUNCTION_SORT_SYMBOL), binders, subterms);
    }

	/** Return index path to leftmost regular subterm where the two terms differ, or null if they are the same. */
	public static List<Integer> discriminatorPath(Term t1, Term t2)
    {
		List<Integer> prefix = new ArrayList<Integer>();
		if (discriminatorPath(t1, t2, prefix))
		{
			//System.err.println("Discriminator \n"+t1+" vs "+t2+"\n = "+prefix);
			return prefix;
		}
		else
			return null;
    }
	private static boolean discriminatorPath(Term t1, Term t2, List<Integer> prefix)
    {
		final int arity = t1.arity();
		if (t1.kind() != Kind.CONSTRUCTION || t2.kind() != Kind.CONSTRUCTION || arity != t2.arity() || Util.symbol(t1).equals(Util.symbol(t2)))
			return true; // prefix is correct because the terms differ here
		for (int i = 0; i < arity; ++i)
		{
			prefix.add(i);
			if (discriminatorPath(t1.sub(i), t2.sub(i), prefix))
				return true; // pass found difference
			prefix.remove(prefix.size()-1);
		}
		return false; // no difference found
    }

	/**
	 * Create singleton list.
	 * @param e single element
	 */
	public static <E> List<E> singleton(E e)
    {
		List<E> list = new ArrayList<E>(1);
		list.add(e);
		return list;
    }

	/**
	 * Return value from relational map, or key if there is no maping.
	 * @param map
	 * @param key
	 * @return
	 */
	public static <S> S getOrKeep(Map<S,S> map, S key)
    {
		S value = map.get(key);
		return (value == null ? key : value);
    }

	/**
	 * Create a $Cons/$Nil list from set.
	 * @param factory to use for generating terms
	 * @param set to enumerate
	 * @return term with list
	 */
	public static GenericTerm listifyVariableSet(GenericFactory factory, Set<Variable> set)
	{
		GenericTerm t = factory.nil();
		for (Variable v : set)
			t = factory.cons(GenericTerm.NO_BIND, factory.newVariableUse(v), GenericTerm.NO_BIND, t);
		return t;
	}

	/**
	 * Convert a $Cons/$Nil list of variables to a Java set of the same variables. 
	 * @param sub
	 * @return
	 */
	public static Set<Variable> extractVariableSet(GenericTerm sub)
    {
		Set<Variable> vs = new TreeSet<Variable>();
		while (Util.isCons(sub.constructor()))
		{
			if (sub.sub(0).kind() == Kind.VARIABLE_USE)
				vs.add(sub.sub(0).variable());
			sub = sub.sub(1);
		}
		return vs;
    }
}
