/* Copyright © 2009, 2010 IBM Corporation. */

package net.sf.crsx.util;

import java.io.Closeable;

import net.sf.crsx.Factory;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;

/**
 * Sink that can be instantiated from the command line.
 * Implementations must have a public default constructor
 * and must use both {@link #setFactory(Factory)} and {@link #setAppendable(Appendable)} before any {@link Sink} methods.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Sinker.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public interface Sinker extends Sink, Closeable
{
	/** Set the factory from which this sink was instantiated. */
	public void setFactory(Factory<? extends Term>  factory);
	/** Set the output of the sink. */
	public void setAppendable(Appendable appendable);
	/** Set the continuation returned when sink otherwise exhausted. */
	public void setContinuation(Sink continuation);
}
