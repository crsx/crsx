/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import java.io.IOException;
import java.io.Writer;

/**
 * Wrapper around {@link Appendable}.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class AppendableWriter extends Writer
{
    // Static.
    
    /**
     * Writer to appendable.
     * @param appendable
     */
    public static Writer writer(Appendable appendable)
    {
        return (appendable instanceof Writer ? (Writer) appendable : new AppendableWriter(appendable));
    }
    
    // State.
    
    /** Wrapped appendable. */
    final Appendable appendable;
    
    // Constructor.
    
    /**
     * Wrap.
     * @param a to wrap
     */
    public AppendableWriter(Appendable a)
    {
        appendable = a;
    }
    
    // Writer implementation.

    @Override
    public void close() throws IOException
    {}

    @Override
    public void flush() throws IOException
    {}

    @Override
    public void write(char[] cbuf, int off, int len) throws IOException
    {
        for (int i = 0; i < len; ++i)
            appendable.append(cbuf[off+i]);
    }
}
