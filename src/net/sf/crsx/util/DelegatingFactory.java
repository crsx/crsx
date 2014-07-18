/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx.util;

import net.sf.crsx.Factory;
import net.sf.crsx.Term;

/**
 * Delegating factory that delegates to constant factory.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegatingFactory.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class DelegatingFactory<T extends Term> extends DelegateFactory<T> implements Factory<T>
{
    // State.
    
    /** The factory to delegate to. */
    final Factory<T> factory;
    
    // Constructor.
    
	/** Create factory that delegates all to another. */
	public DelegatingFactory(Factory<T> basis)
	{
		factory = basis;
	}
	
	// DelegateFactory...
	
	final public Factory<T> factory()
	{
		return factory;
	}
}
