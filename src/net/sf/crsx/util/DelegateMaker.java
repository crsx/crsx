/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import net.sf.crsx.Constructor;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * {@link Maker} that delegates all methods. 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: DelegateMaker.java,v 3.1 2013/12/09 05:48:39 krisrose Exp $
 */
public abstract class DelegateMaker implements Maker
{
    // Methods.
	
    /** The maker that is delegated to. */
    public abstract Maker maker();
    
    // Maker.
    
    final public Constructor makeConstructor(Object object)
    {
        return maker().makeConstructor(object);
    }
    
    final public Constructor makeConstructor(Object object, boolean closure)
	{
		return maker().makeConstructor(object, closure);
	}

	final public Constructor makeLiteral(Object object, String sort)
    {
	    return maker().makeLiteral(object, sort);
    }

	final public Variable makeVariable(String name, boolean promiscuous)
    {
        return maker().makeVariable(name, promiscuous);
    }
	
	final public Variable freeVariable(String name, boolean promiscuous, boolean create)
    {
		return maker().freeVariable(name, promiscuous, create);
    }

	final public Sink makeBuffer(CallBack callBack)
    {
        return maker().makeBuffer(callBack);
    }
}
