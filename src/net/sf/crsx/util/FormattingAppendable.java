/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx.util;

import java.io.Closeable;
import java.io.Flushable;
import java.io.IOException;
import java.io.Writer;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;
import java.util.regex.Pattern;

/**
 * Variant of appendable that takes care of indentation and joining short fragments by converting newlines
 * to spaces if space permits.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: FormattingAppendable.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class FormattingAppendable extends Writer
{
	// Constants.
	
	/** Spaces used for indentation. */
	final static String SPACES = "                                                                                                                                                                                                                                                          ";

	//final private String m(String s) {return "["+indent+":"+s+"]";}
	final private String m(String s) {return "";}

	final private Pattern PATTERN1 = Pattern.compile("\n[ ]*");
	final private Pattern PATTERN2 = Pattern.compile("\0+[ ]*");
	
	// Static.

    /**
     * Create formatter.
     * If the appendable is already a formatter or null then it is simply returned unchanged.
     * @param appendable to send reformatted text to
     * @param width of lines
     * @param initialindentation to use for top-level formatting unit.
     * @param maxindentation 
     */
    public static FormattingAppendable format(Appendable appendable, int width, int initialindentation, int maxindentation)
    {
        if (appendable == null)
            return null;
        if (appendable instanceof FormattingAppendable)
            return (FormattingAppendable) appendable;
        return new FormattingAppendable(appendable, width, initialindentation, maxindentation);
    }
    
	/** 
	 * Indentation string for level. 
	 * @param maxindent 
	 */
	private static String indentation(int level, int maxindent)  
	{
		if (level > maxindent)
			level = maxindent;
		
		if (level < 0)
			return "";
		else if (level < SPACES.length())
	        return SPACES.substring(0, level);
	    else
	    {
	        StringBuilder b = new StringBuilder();
	        do
	        {
	            b.append(SPACES);
	            level -= SPACES.length();
	        }
	        while (level >= SPACES.length());
	        b.append(SPACES.substring(0, level));
	        return b.toString();
	    }
	}

	/** Insert level indentation after every newline. */ 
	private String indent(String s, int level) throws IOException
	{
		final String nl = isEscape() ? "\\n" : "\n";
		final String indentation = cachedIndentation(level, maxindent);
		//return s.replaceAll("\n[ ]*", nl + m("N") + indentation).replaceAll("\0+[ ]*",  nl + m("Z") + indentation);
		s = PATTERN1.matcher(s).replaceAll(nl + m("N") + indentation);
		s = PATTERN2.matcher(s).replaceAll(nl + m("Z") + indentation);
		return s;
	}
	
	// State.
	
	/** Target for the formatted text. */
	final private Appendable appendable;
	
	/** Maximal width of the formatted text. */
	final private int width;
	
	/** Current indent. */
	private int indent;
	
	/** Max indent. */
	private int maxindent;
	
	/** Cached indent strings */
	private String[] cachedIndentation;
	
	/** Escape characters to be valid in Java/C string? */
	private boolean escape;
	
	/** Indents. */
	private Stack<Integer> indents = new Stack<Integer>();
	
	/** Current innermost formatting unit, or null if none. */
	private StringBuilder topOpening = null;
	
	/** Pushed formatting unit. */
	private List<StringBuilder> pushedOpenings = new LinkedList<StringBuilder>();

	// Constructor.
	
	/**
	 * Create formatter.
	 * @param appendable to send reformatted text to -- do not nest!
	 * @param width of lines
	 * @param initialindentation to use for top-level formatting unit.
	 * @param maxindentation  
	 */
	protected FormattingAppendable(Appendable appendable, int width, int initialindentation, int maxindentation)
	{
		assert !(appendable instanceof FormattingAppendable);
		this.appendable = appendable;
		this.width = width;
		indent = initialindentation;
		this.maxindent = maxindentation; 
		if (this.maxindent > 0)
		{
			int realmax = Math.min(this.maxindent, 100);
			cachedIndentation = new String[realmax];
			for (int i = realmax - 1; i >= 0; i --)
			cachedIndentation[i] = indentation(i, realmax);
		}
	}
	
	// Methods.
	
	/** 
	 * Indentation string for level, eventually coming from cache
	 * @param maxindent 
	 */ 
	private String cachedIndentation(int level, int maxindent)  
	{
		if (cachedIndentation != null && level < cachedIndentation.length)
			return cachedIndentation[level];
		
		return indentation(level, maxindent);
	}
	
	/** Escaping? */
	public boolean isEscape()
    {
	    return escape;
    }

	/** Set escape mode */
	public void setEscape(boolean escape)
    {
	    this.escape = escape;
    }

	/** Increase the indentation and start a new formatting unit with open string. */
	public void open(String open) throws IOException
	{
		open(open, 1);
	}

	/** Increase the indentation by extra and start a new formatting unit with open string. */
	public void open(String open, int extra) throws IOException
	{
		indents.push(indent);
		indent += extra;
		if (topOpening != null)
			pushedOpenings.add(topOpening);
		topOpening = new StringBuilder();
		append(m("OPEN")+open);
	}
	
	/** End current formatting unit with close string, and decrease indentation. */
	public void close(String close) throws IOException
	{		
		final String nl = isEscape() ? "\\n" : "\n";
		if (topOpening == null)
		{
			// Writing directly...
			indent = indents.pop();
			appendable.append(m("CLOSE1")+close.replace("\0", "").replace("\u21B2", nl));
		}
		else
		{
			// Got an open string...take it out and see if it fits...
			String s = topOpening.toString();
			
			if (indent + s.length() < width)
			{
				// It fits!  Insert it in context as a single unit, including the closing.
				String sWithClosing = (s + close).replace('\n', ' ').replace("\0", ""); //.trim();

				if (pushedOpenings.isEmpty())
				{
					// We were at the top level. Output and clear context.
					appendable.append(m("CLOSE2")+sWithClosing.replace("\u21B2", nl));
					indent = indents.pop();
					topOpening = null;
				}
				else
				{
					// There is a context to append to.
					topOpening = pushedOpenings.remove(pushedOpenings.size() - 1);
					topOpening.append(m("CLOSE3")+sWithClosing);
					indent = indents.pop();
				}
			}
			else
			{
				// It does not fit.  Dump all pushed lines with proper indentation and revert to direct printing with newlines.
				for (int i = 0; i < pushedOpenings.size(); ++i)
				{
					String unit = pushedOpenings.get(i).toString();
					int unitIndent = indents.elementAt((indents.size() - pushedOpenings.size()) + i);
					unit = indent(unit, unitIndent);
					appendable.append(unit.replace("\u21B2", nl));
				}
				pushedOpenings.clear();
			    s = s.replace("\0", nl); // activate "hidden" newlines
			    String shift = "";
			    if (s.endsWith("\n"))
			    {
			    	shift = nl;
			    	s = s.substring(0, s.length()-1);
			    }
			    s = indent(s, indent);
				appendable.append(m("CLOSE4")+s.replace("\u21B2", nl));
				indent = indents.pop();
				close = close.replace("\0", nl); // activate "hidden" newlines
				appendable.append(indent(shift+close, indent).replace("\u21B2", nl));
				topOpening = null;
			}
		}
	}

	/** Force vertical space with current indentation. */
	public void vspace(String space) throws IOException
	{
		append(m("VSPACE")+space + indentation(indent, maxindent));
	}
	
	// Appendable...

	public Writer append(char c) throws IOException
	{
		String nl = escape ? "\\n" : "\n";
		
		if (topOpening == null)
		{
			if (c == '\n' || c == '\0')
				appendable.append(nl + indentation(indent, maxindent).replace("\u21B2", nl));
			else if (c == '\u21B2')
				appendable.append(nl);
			else if (c == '\t')
				appendable.append(escape ? "\\t" : "\t");
			else  
				appendable.append(c);
		}
		else
		{
			if (c == '\n')
				topOpening.append(nl);
			else if (c == '\t')
				topOpening.append(escape ? "\\t" : "\t");
			else
				topOpening.append(c);
		}
		return this;
	}

	public Writer append(CharSequence csq) throws IOException
	{
		for (int i = 0; i < csq.length(); ++i)
			append(csq.charAt(i));
		return this;
	}

	public Writer append(CharSequence csq, int start, int end) throws IOException
	{
		for (int i = start; i < end; ++i)
			append(csq.charAt(i));
		return this;
	}

	// Flushable...

	@Override
	public void flush() throws IOException
	{
		if (appendable instanceof Flushable)
			((Flushable) appendable).flush();
	}

	// Closeable...

	@Override
	public void close() throws IOException
	{
		if (appendable instanceof Closeable)
			((Closeable) appendable).close();
	}
	
	// Writer...

	@Override
	public void write(char[] cbuf, int off, int len) throws IOException
	{
		int end = off + len;
		for (int i = off; i < end; ++i)
			append(cbuf[i]);
	}
}
