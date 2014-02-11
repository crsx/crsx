/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx.util;

import net.sf.crsx.Copyable;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * Delegate to another copyable.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegateCopyable.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public abstract class DelegateCopyable implements Copyable
{
	// Methods. 
	
	/** The delegation method. */
	abstract protected Copyable delegate();
	
	// Copyable...

	// @see net.sf.crsx.Copyable#copy(net.sf.crsx.Sink, boolean)
	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		return delegate().copy(sink, discard, renames);
	}
}
