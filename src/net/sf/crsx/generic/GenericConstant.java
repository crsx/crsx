/* Copyright (c) 2006, 2007 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.Collection;
import java.util.Map;

import net.sf.crsx.Constructor;
import net.sf.crsx.Kind;
import net.sf.crsx.Match;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleMap;

/**
 * Generic implementation of <em>constant construction<em> {@link Term}s.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericConstant.java,v 3.0 2012/12/17 18:04:53 krisrose Exp $
 */
public class GenericConstant extends GenericConstruction
{
	// Constructor.
	
	/**
	 * Create constant constructor term.
	 * @param factory for {@link #maker()}
	 * @param constructor to use
	 */
	protected GenericConstant(GenericFactory factory, Constructor constructor)
	{
		super(factory, constructor);
	}

	// GenericTerm...

	@Override
	final public void replaceSub(int i, Variable[] bs, GenericTerm t)
	{
		throw new IndexOutOfBoundsException();
	}
	
	// Term...
	
	@Override
	final public Variable[] binders(int i)
	{
		throw new IndexOutOfBoundsException();
	}

	@Override
	public GenericTerm sub(int i)
	{
		throw new IndexOutOfBoundsException();
	}

	// Stub...

    @Override //specialized
	final public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
	    return sink.start(discard && renames.isEmpty() ? constructor : constructor.copy(renames)).end();
	}

    @Override
    final public Constructor constructor()
    {
        return constructor;
    }
    
	@Override
	final public int arity()
	{
		return 0;
	}
	
    @Override
    final public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
    {
		if (renames == null)
			renames = LinkedExtensibleMap.EMPTY_RENAMING;
        return discard && renames.isEmpty() ? this : factory.newConstruction(constructor.copy(renames), NO_BINDS, NO_TERMS);
    }
    
    // Pattern...

    @Override //specialized
	final public boolean match(Match match, Term redex, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		return redex.kind() == Kind.CONSTRUCTION && constructor().match(match, redex.constructor(), bound, contractionCount, promiscuous, once, onceSeen);
	}

    // Contractum...

    @Override //specialized
	final public Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings)
	{
		return sink.start(constructor.contract(valuation, renamings)).end();
	}
}
