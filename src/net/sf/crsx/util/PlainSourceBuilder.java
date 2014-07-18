package net.sf.crsx.util;

import java.io.Closeable;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import net.sf.crsx.SourceBuilder;

/**
 * Utility for composing source code.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: PlainSourceBuilder.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class PlainSourceBuilder implements SourceBuilder
{
	// Constants.
	
	/** Indentation fodder. */
	public final static String TABS = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	
	// State.

	/** Where declarations and statements are appended to. */
	final Appendable statements;
	
	/** Prefix to all statements. */
	String prefix;

	/** Current block nesting level. */
	int nesting;
	
	/** Unique count. */
	int count;
	
	/** Expressions under construction, or null when none. */
	List<StringBuilder> expressions = new ArrayList<StringBuilder>();
	
	// Constructor.

    /** Construct empty java builder. Use {@link #extract()} to get the string. */
    public PlainSourceBuilder()
    {
        statements = new StringBuilder();
        this.prefix = "";
    }

    /** Construct java builder that dumps to file. */
    public PlainSourceBuilder(String filename)
    {
        try
        {
            statements = new FileWriter(filename);
        }
        catch (IOException e)
        {
            throw new RuntimeException(e);
        }
        this.prefix = "";
    }
    
	/** Construct java builder around existing writer. */
	public PlainSourceBuilder(Appendable writer, String prefix)
	{
		statements = writer;
		this.prefix = prefix;
	}
	
	// Methods.
	
	/** Extract the string constructed starting by anonymous constructor. */
	public String extract()
	{
	    assert nesting == 0 : "Unmatched openBlock() in SourceBuilder!";
	    return ((StringBuilder) statements).toString();
	}

	// SourceBuilder...

    public SourceBuilder addStatement(CharSequence statement)
    {
        try
        {
        	String text = (statement instanceof String ? (String) statement : ""+statement);
        	String indent = prefix + TABS.substring(0, nesting);
            statements
                .append(indent)
                .append(text.replace("\n","\n"+indent))
                .append("\n");
        }
        catch (IOException e)
        {}
        return this;
    }

	public SourceBuilder openBlock(CharSequence opener)
	{
		addStatement(opener);
		++nesting;
		return this;
	}

	public SourceBuilder closeBlock(CharSequence closer)
	{
		if (nesting == 0)
			assert nesting > 0 : "Unmatched closeBlock() in SourceBuilder!";
		--nesting;
		addStatement(closer);
		return this;
	}
	
	public int nesting()
	{
		return nesting;
	}

	public SourceBuilder seedExpression(CharSequence seed)
	{
		expressions.add(new StringBuilder());
		expressions.get(expressions.size()-1).append(seed);
		return this;
	}

	public boolean seeded()
	{
		return !expressions.isEmpty();
	}

	public SourceBuilder wrapExpression(CharSequence pre, CharSequence post)
	{
	    assert seeded() : "Can only use wrapExpression() when SourceBuilder is seeded()!";
	    StringBuilder expression = expressions.get(expressions.size()-1);
        if (pre.length() > 0)
			expression.insert(0, pre+" ");
        if (post.length() > 0)
            expression.append(" "+post);
		return this;
	}

	public CharSequence harvest()
	{
		assert seeded() : "Can only harvest() when SourceBuilder is seeded()!";
		int last = expressions.size()-1;
		CharSequence harvested = expressions.get(last);
		expressions.remove(last);
		return harvested;
	}

	public int count()
	{
		return ++count;
	}

	public String prefix()
	{
		return prefix;
	}

	public void setPrefix(String prefix)
	{
		this.prefix = prefix;
	}

	// Closeable...
	
	public void close() throws IOException
    {
	    if (statements instanceof Closeable)
	        ((Closeable) statements).close();
    }

	

	// Sic.
	
    public String toString()
	{
		return statements.toString() + "\n[ "+ expressions + " ]";
	}
}
