/* Copyright (c) 2006, 2009 IBM Corporation. */

package net.sf.crsx.generic;

import net.sf.crsx.Constructor;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Generic implementation of <em>construction<em> {@link Term}s
 * that stores the binders and subterms.
 * Only supports the {@link #replaceSub(int, Variable[], GenericTerm)} mutation operation.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: FixedGenericConstruction.java,v 3.1 2013/09/12 01:36:59 krisrose Exp $
 */
public class FixedGenericConstruction extends GenericConstruction
{
	// State.
	
	/** Bindings. */
	final protected Variable[][] binders;

	/** Subterms. */
	final protected GenericTerm[] sub;

	// Constructor.
	
	/**
	 * Create constructor term.
	 * @param factory for {@link #maker()}
	 * @param constructor to use - the instance will be used directly
	 * @param binds with binders for each subterm (reused directly so must be fresh)
	 * @param sub with subterms (without binders) - the instances will be used directly
	 */
	protected FixedGenericConstruction(GenericFactory factory, Constructor constructor, Variable[][] binds, GenericTerm[] sub)
	{
		super(factory, constructor);
		assert binds.length == sub.length : "Construction must have same number of binders and subterms.";
		this.binders = binds;
		if (binds.length != sub.length || (binds.length != 0 && binds[0] == null))
			assert false : "inconsistent binders";
		this.sub = sub;
	}
	
	// GenericTerm...
	
	@Override
	Variable[][] allBinders()
	{
		return binders;
	}
	
	@Override
	GenericTerm[] allSubs()
	{
		return sub;
	}

	@Override
	final public void replaceSub(int i, Variable[] bs, GenericTerm t)
	{
		if (i < 0 || i >= sub.length)
			throw new IndexOutOfBoundsException("Trying to set non-existant subterm?");
		binders[i] = (bs == null ? NO_BIND : bs);
		sub[i] = t;
	}

    // Stub...

	@Override
	final public int arity()
	{
		return sub.length;
	}

    @Override
    final public Constructor constructor()
    {
        return constructor;
    }
    
	// Term...

	@Override
	final public Variable[] binders(int i)
	{
		if (i >= binders.length)
			throw new IndexOutOfBoundsException("Bad binders index!");
		return binders[i];
	}

	@Override
	final public GenericTerm sub(int i)
	{
		if (i >= arity())
			throw new IndexOutOfBoundsException();
		return sub[i];
	}
}
