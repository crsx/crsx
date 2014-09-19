/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.text;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.ManagedSink;
import net.sf.crsx.util.Sinker;
import net.sf.crsx.util.Util;

/**
 * Outputs formatted text terms as plain text.
 * TODO: describe the term forms...
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: TextSink.java,v 3.7 2014/01/06 03:11:30 krisrose Exp $
 */
public class TextSink extends ManagedSink implements Sinker
{
	// Static.
	
    /** Whether it is safe to echo the symbol of a particular constructor directly. */
    private static boolean isSafe(Constructor constructor)
	{
    	return isSafe(constructor.symbol());
	}
    
    /** Whether it is safe to echo the symbol of a particular constructor directly. */
    private static boolean isSafe(String symbol)
	{
    	final int length = symbol == null ? 0 : symbol.length();
    	for (int i = 0; i  < length; ++i)
    	{
    		switch (symbol.charAt(i))
    		{
    			case '\u00AB' : // «
    				if (i+ 1 < length && symbol.charAt(i + 1) == '\u00AB')
    				{
    					i++;
    					break;
    				}
    				return false;
    			case '\u00BB' : // »
    				if (i+ 1 < length && symbol.charAt(i + 1) == '\u00BB')
    				{
    					i++;
    					break;
    				}
    				return false;
    			case '\u2020' : // †
    				if (i+ 1 < length && symbol.charAt(i + 1) == '\u2020')
    				{
    					i++;
    					break;
    				}
    				return false;
    			case '\u00B6' : // ¶
    			case '\u2021' : // ‡
    			case '\u27E6' : case '\u27E7' : // ⟦⟧
    			case '\u2983' : case '\u2984' : // ⦃⦄
    				return false;
    		}
    	}
    	return true;
	}

	// State
    
    /** Factory to use for creations... */
    protected Factory<? extends Term> factory;
    
    boolean canonicalVariables = false;
    
    boolean noLinearMarkers = false;
    
    /** Where to append the formatted text. */
    protected FormattingAppendable output;
    
    /** The sink returned by event that exhausts text sink. */
    protected Sink continuation;

    // Constructor.
    
    /**
     * {@link Sinker} constructor:
     * must be followed by invocations of {@link #setFactory(Factory)} and {@link #setAppendable(Appendable)} before use!
     */
    public TextSink()
    {
    	super(null);
    }

    /**
     * Print a text term.
     * @param text to print
     * @param appendable to print to
     * @param existing variable name
     * @throws IOException if there is an output error
     */
    public void appendText(Term text, Appendable appendable, Map<Variable, String> namings, Set<String> existing) throws IOException
    {
    	FormattingAppendable f = FormattingAppendable.format(appendable, 132, 0, 50);
    	
    	// The really common case...
    	while (text.kind() == Kind.CONSTRUCTION && text.constructor().symbol().equals("$TextCons") && text.arity() == 2)
    	{
			appendText(text.sub(0), f, namings, existing);
			text = text.sub(1);
    	}
    	// ...and all the other cases.
    	switch (text.kind())
    	{
    		case CONSTRUCTION : {
    			String s = text.constructor().symbol();
    			
    			if (s.equals("$TextNil") && text.arity() == 0)
    			{
    				break; // no output
    			}
    			else if (s.equals("$TextChars") && text.arity() == 1)
    			{
    				Term sub = text.sub(0);
    				if (Util.isConstant(sub) && isSafe(sub.constructor()))
    				{
    					String symbol = unescape(Util.symbol(sub)); 
    					f.append(symbol);
    					break;
    				}
    				else
    				{
    					f.append("\u2020"); // † prefix denoting non-trivial character term
    				}
    			}
    			else if (s.equals("$TextBreak") && text.arity() == 1)
    			{
    				Term sub = text.sub(0);
    				if (Util.isConstant(sub) && isSafe(sub.constructor()))
    				{
    					String brk = Util.symbol(sub);
    					f.append(brk.isEmpty() ? "\n" : brk);
    					break;
    				}
    				else
    				{
    					f.append("\u2021"); // ‡ prefix denoting non-trivial break term
    				}
    			}
    			else if (s.equals("$TextTerm") && text.arity() == 1)
    			{
    				text.sub(0).appendTo(f, namings, Integer.MAX_VALUE, false, true, true, null);
    				break;
    			}
    			else if (s.equals("$TextSeparator") && text.arity() == 0)
    			{
					f.append('\0');
					break;
    			}
    			else if ((s.equals("$TextGroup") || s.equals("$TextEmbed")) && text.arity() == 1)
    			{
    				f.open("", 0);
    				appendText(text.sub(0), f, namings, existing);
    				f.close("");
    				break;
    			}
    			else if (s.equals("$TextIndent") && text.arity() == 1)
    			{
    				f.open("", 2);
    				appendText(text.sub(0), f, namings, existing);
    				f.close("");
    				break;
				}
				else if (s.equals("$TextString") && text.arity() == 1)
				{
					boolean escape = f.isEscape();
					f.setEscape(true);
					appendText(text.sub(0), f, namings, existing);
					f.setEscape(escape);
					break;
				}
    			// complex construction (possibly after prefix) -- fall through!
    		}
    		
    		default : // META_APPLICATION and complex constructions
    			f.append("\u00ab ");
    			text.appendTo(f, namings, Integer.MAX_VALUE, false, true, true, null);
    			f.append(" \u00bb");
    			break;

    		case VARIABLE_USE : {
    			Variable v = text.variable();
    			String name = namings.get(v);
    			if (name == null)
    			{
    				name = Util.safeVariableName(v, namings, noLinearMarkers, (factory != null && factory.defined("trust-generated-variable-names")));
    				namings.put(v, name);
    				existing.add(name);
    			}
    			f.append(name);
    			break;
    		}
    	}
    	f.flush();
    }

	private String unescape(String text)
	{
		return text.replaceAll("««", "«").replaceAll("»»", "»").replaceAll("††", "†");
	}
    
    // Sinker...


	public void setFactory(Factory<? extends Term> factory)
	{
		this.factory = factory;
		canonicalVariables = factory.defined(GenericFactory.CANONICAL_VARIABLES);
		noLinearMarkers = factory.defined(GenericFactory.NO_LINEAR_VARIABLES);
		sink = factory.makeBuffer(new Maker.CallBack()
			{
				@Override
				public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
				{
					try
					{
						Map<Variable, String> namings = new HashMap<Variable, String>();
						if (canonicalVariables) namings.put(null, "1");
						appendText(term, output, namings, new HashSet<String>());
						continuationSetter.setContinuationSink(continuation);
					}
					catch (IOException e)
					{
						throw new RuntimeException("Printing of Text failed", e);
					}
				}
			});
	}
	
	public void setAppendable(Appendable appendable)
	{
		int maxindentation = factory.defined(Factory.MAX_INDENT_LEVEL) ? Integer.parseInt(factory.get(Factory.MAX_INDENT_LEVEL).constructor().symbol()) : Integer.MAX_VALUE;
		
		output = FormattingAppendable.format(appendable, 72, 0, maxindentation);
	}

	public void setContinuation(Sink continuation)
	{
		this.continuation = continuation;
	}
}
