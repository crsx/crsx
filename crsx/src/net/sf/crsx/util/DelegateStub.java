/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx.util;

import net.sf.crsx.Constructor;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Delegate to another stub.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegateStub.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public abstract class DelegateStub extends DelegateCopyable implements Stub
{
	// Methods. 
	
	/** The delegation method. */
	abstract protected Stub delegate();
	
	// Stub...

	// @see net.sf.crsx.Stub#maker()
	public Maker maker()
	{
		return delegate().maker();
	}

	// @see net.sf.crsx.Stub#kind()
	public Kind kind()
	{
		return delegate().kind();
	}

	// @see net.sf.crsx.Stub#constructor()
	public Constructor constructor()
	{
		return delegate().constructor();
	}

	// @see net.sf.crsx.Stub#variable()
	public Variable variable()
	{
		return delegate().variable();
	}

	// @see net.sf.crsx.Stub#metaVariable()
	public String metaVariable()
	{
		return delegate().metaVariable();
	}

	// @see net.sf.crsx.Stub#arity()
	public int arity()
	{
		return delegate().arity();
	}

    public Term copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
    {
        return delegate().copy(discard, renames);
    }
}
