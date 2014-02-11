/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.util;

import java.io.Closeable;
import java.io.IOException;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;


/**
 * Managed {@link Sink} does not require the user to update the "sink continuation":
 * all {@link Sink} methods are guaranteed to return <code>this</code>
 * (or <code>null</code> when the managed sink is exhausted).
 * Specifically this means that one can replace a code fragment
 * <pre>
 *   s = s.start(C); s = s.end(C);
 * </pre>
 * with
 * <pre>
 *   { ManagedSink ms = new ManagedSink(s); ms.start(C); ms.end(C); s = ms.sink();}
 * </pre>
 * Every event is sent to the managed sink and the managed sink is continuously updated.
 * The managed sink events still return the sink reference so the managed sink can be passed on as an ordinary sink.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: ManagedSink.java,v 3.1 2013/04/26 15:14:43 villardl Exp $
 */
public class ManagedSink extends DelegateMaker implements Sink, Closeable
{
	// State.
	
	/** The managed sink. */
	protected Sink sink;

	// Constructor.
	
	/**
	 * Create delegating sink, sending the first event to the initial sink.
	 */
	public ManagedSink(Sink seed)
	{
		sink = seed;
	}

	// Methods.

	/** The sink that is returned when managed sink is exhausted. */
	protected Sink continuation()
	{
		return null;
	}
	
	/** Return the managed sink. */
	final public Sink sink()
	{
		return sink;
	}
	
	// DelegateMaker...
	
	final public Maker maker()
	{
		return sink;
	}
	
	// Sink...
	
	public Sink start(Constructor constructor)
	{
		sink = sink.start(constructor);
		return (sink != null ? this : continuation());
	}
	
	public Sink end()
	{
		sink = sink.end();
		return (sink != null ? this : continuation());
	}
	
	public Sink binds(Variable[] binders)
	{
		sink = sink.binds(binders);
		return (sink != null ? this : continuation());
	}
	
	public Sink use(Variable variable)
	{
		sink = sink.use(variable);
		return (sink != null ? this : continuation());
	}
	
	public Sink startMetaApplication(String name)
	{
		sink = sink.startMetaApplication(name);
		return (sink != null ? this : continuation());
	}
	
	public Sink endMetaApplication()
	{
		sink = sink.endMetaApplication();
		return (sink != null ? this : continuation());
	}
	
	public Sink copy(Copyable source, boolean discard)
	{
		sink = sink.copy(source, discard);
		return (sink != null ? this : continuation());
	}
	
	// Closeable...
	
	public void close()
	{
		if (sink != null && sink instanceof Cloneable)
	        try
            {
	            ((Closeable) sink).close();
            }
            catch (IOException e)
            {}
	}
}
