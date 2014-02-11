/* Copyright (c) 2006, 2009 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.ArrayList;
import java.util.List;

import net.sf.crsx.Constructor;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Generic implementation of <em>construction<em> {@link Term}s
 * that stores the binders and subterm.
 * Supports mutation operations fully.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: FlexibleGenericConstruction.java,v 3.0 2012/12/17 18:04:53 krisrose Exp $
 */
public class FlexibleGenericConstruction extends GenericConstruction
{
	// State.
	
	/** Bindings. */
	final protected List<Variable[]> binders;

	/** Subterms. */
	final protected List<GenericTerm> sub;
	
	// Constructor.
	
	/**
	 * Create constructor term.
	 * @param maker for {@link #maker()}
	 * @param constructor to use - the instance will be used directly
	 */
	protected FlexibleGenericConstruction(GenericFactory maker, Constructor constructor)
	{
		super(maker, constructor);
		this.binders = new ArrayList<Variable[]>();
		this.sub = new ArrayList<GenericTerm>();
	}

	// GenericTerm...

	@Override
	public boolean isFlexible()
	{
		return true;
	}

	@Override
	Variable[][] allBinders()
	{
		return binders.toArray(new Variable[binders.size()][]);
	}
	
	@Override
	GenericTerm[] allSubs()
	{
		return sub.toArray(new GenericTerm[sub.size()]);
	}

	@Override
	public void insertSub(int i, Variable[] bs, GenericTerm s)
	{
		binders.add(i, (bs == null ? NO_BIND : bs));
		sub.add(i, s);
	}

	@Override
	public void addSub(Variable[] bs, GenericTerm s)
	{
		binders.add((bs == null ? NO_BIND : bs));
		sub.add(s);
	}
	
	@Override
	public void deleteSub(int i)
	{
		binders.remove(i);
		sub.remove(i);
	}

	@Override
	public void replaceSub(int i, Variable[] bs, GenericTerm t)
	{
		binders.set(i, (bs == null ? NO_BIND : bs));
		sub.set(i, t);
	}

    // Stub...

	@Override
	final public int arity()
	{
		return sub.size();
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
		return binders.get(i);
	}

	@Override
	final public GenericTerm sub(int i)
	{
		return sub.get(i);
	}
}
