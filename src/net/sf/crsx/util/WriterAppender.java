package net.sf.crsx.util;

import java.io.Closeable;
import java.io.IOException;
import java.io.Writer;

/**
 * Use a writer as an appender, flushing after every append.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: WriterAppender.java,v 3.0 2012/12/17 18:04:59 krisrose Exp $
 */
public class WriterAppender implements Appendable, Closeable
{
	final Writer writer;
	
	/** Initialize. */
	public WriterAppender(Writer writer)
	{
		this.writer = writer;
	}

	public Appendable append(CharSequence csq) throws IOException
	{
		writer.append(csq);
		writer.flush();
		return this;
	}

	public Appendable append(char c) throws IOException
	{
		writer.append(c);
		writer.flush();
		return this;
	}

	public Appendable append(CharSequence csq, int start, int end) throws IOException
	{
		writer.append(csq, start, end);
		writer.flush();
		return this;
	}

	@Override
	public void close() throws IOException
	{
		writer.close();
	}
}
