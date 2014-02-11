/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import net.sf.crsx.Maker;

/**
 * Delegate {@link Maker} that delegates through reference.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: DelegatingMaker.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class DelegatingMaker extends DelegateMaker
{
    // State.
    
    /** Real Maker. */
    private Maker maker;
    
    // Constructor.
    
    /** Create uninitialized delegating maker... */
    public DelegatingMaker()
    {}

    /** Create delegating maker... */
    public DelegatingMaker(Maker maker)
    {
        this.maker = maker;
    }
    
    // Methods.
    
    /** Set the maker to delegate to. */
    public void setMaker(Maker maker)
    {
    	this.maker = maker;
    }
    
    // DelegateMaker...

    /** The maker that is delegated to. */
    public Maker maker()
    {
    	return maker;
    }
}
