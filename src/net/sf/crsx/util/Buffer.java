/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Set;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;

/**
 * Simple buffering of terms captured from a sink.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Buffer.java,v 3.3 2013/12/05 03:28:30 krisrose Exp $
 */
public class Buffer extends DelegateMaker implements Copyable
{
    // Static.
    
    /**
     * Materialize term.
     * @param maker to use for materialization
     * @param source to materialize
     * @param discard set when this is the last use of source
     * @return the materialized term
     */
    public static Term materialize(Maker maker, Copyable source, boolean discard)
    {
        return new Buffer(maker).load(source, discard);
    }

    /**
     * Materialize constant term.
     * @param maker to use for materialization
     * @param constructor to use
     * @return the materialized term
     */
    public static Term materialize(Maker maker, Constructor constructor)
    {
    	Buffer b = new Buffer(maker);
    	b.sink().start(constructor).end();
    	return b.term(true);
    }

    /**
     * Materialize constant term.
     * @param maker to use for materialization
     * @param value to use
     * @return the materialized term
     */
    public static Term materialize(Maker maker, int value)
    {
    	Buffer b = new Buffer(maker);
    	b.sink().start(maker.makeConstructor(value)).end();
    	return b.term(true);
    }

    /**
     * Materialize constant term.
     * @param maker to use for materialization
     * @param value to use
     * @return the materialized term
     */
    public static Term materialize(Maker maker, String value)
    {
    	Buffer b = new Buffer(maker);
    	b.sink().start(maker.makeConstructor(value)).end();
    	return b.term(true);
    }

    /**
     * Materialize construction term with single child.
     * @param maker to use for materialization
     * @param constructor to use
     * @param child of construction
     * @param discard whether the child should be discarded (and thus may be reused)
     * @return the materialized term
     */
    public static Term materialize(Maker maker, Constructor constructor, Copyable child, boolean discard)
    {
    	Buffer b = new Buffer(maker);
    	child.copy(b.sink().start(constructor), discard, LinkedExtensibleMap.EMPTY_RENAMING).end();
    	return b.term(true);
    }
    
    /**
     * Return materialized contraction.
     * @param contractum to contract [sic]
     * @param valuation with match to contract with
     * @param renamings to 
     * @return contracted term
     */
    public static Term contraction(Contractum contractum, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
    {
        Buffer b = new Buffer(contractum.maker());
        contractum.contract(b.sink(), valuation, renamings);
        return b.term(true);
    }
    
    /**
     * Return materialized static contraction.
     * @param contractum to contract [sic]
     * @param valuation with match to contract with
     * @param renamings to 
     * @return contracted term
     */
    public static Term staticContraction(Contractum contractum, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
    {
        Buffer b = new Buffer(contractum.maker());
        contractum.staticContract(b.sink(), valuation, renamings);
        return b.term(true);
    }
    
    

	/**
	 * Load substituted term...
	 * @param valuation of original match (for nested contractions)
	 * @param renamings in effect
	 * @param substitution maps the variables in the pattern to the corresponding fragments of the contractum
	 * @param bound variables locally in this term
	 * @param possible variables that can still occur in redex needing substitution
	 */
    public static Term subsubstitute(Term term, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
    {
        Buffer b = new Buffer(term.maker());
        term.subsubstitute(b.sink(), valuation, renamings, substitution, bound, possible);
        return b.term(true);
    }

    /**
	 * Statically load substituted term...
	 * @param valuation of original match (for nested contractions)
	 * @param renamings in effect
	 * @param substitution maps the variables in the pattern to the corresponding fragments of the contractum
	 * @param bound variables locally in this term
	 * @param possible variables that can still occur in redex needing substitution
	 */
    public static Term staticSubsubstitute(Term term, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
    {
        Buffer b = new Buffer(term.maker());
        term.staticSubsubstitute(b.sink(), valuation, renamings, substitution, bound, possible);
        return b.term(true);
    }
    
    /**
     * Materialize constant term with wrapper construction.
     * @param maker to use for materialization
     * @param tag of wrapper construction
     * @param value to use
     * @return the materialized term
     */
    public static Term materializeTagged(Maker maker, String tag, String value)
    {
    	Buffer b = new Buffer(maker);
    	b.sink().start(maker.makeConstructor(tag)).start(maker.makeLiteral(value, CRS.STRING_SORT)).end().end();
    	return b.term(true);
    }

    /**
     * Materialize constant term with wrapper construction.
     * @param maker to use for materialization
     * @param tag of wrapper construction
     * @param value to use
     * @return the materialized term
     */
    public static Term materializeTagged(Maker maker, String tag, int value)
    {
    	Buffer b = new Buffer(maker);
    	b.sink().start(maker.makeConstructor(tag)).start(maker.makeLiteral(value, CRS.NUMERIC_SORT)).end().end();
    	return b.term(true);
    }

	// State.
	
	/** Maker of fine stuff. */
	final protected Maker maker;
	
	/** Stored binders for term or null. */
	protected Variable[] storedBinders;

	/** Stored term or null. */
	protected Term storedTerm;

	// Constructor.

	/**
	 * Create instance.
	 * @param maker for {@link Maker#makeBuffer(net.sf.crsx.Maker.CallBack)}
	 */
	public Buffer(Maker maker)
	{
		this.maker = maker;
	}
	
	// Methods.
	
	/**
	 * Return sink ready to receive a term for insertion in buffer.
	 * The result (as well as any later returned result) can be cast to {@link BufferSink}.
	 */
	public Sink sink()
	{
		storedBinders = null;
		storedTerm = null;
		return maker.makeBuffer(new Maker.CallBack()
		{
			@Override
			public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
			{
			    //assert storedBinders == null && storedTerm == null : "";
				storedBinders = binders;
				storedTerm = term;
			}
		});
	}
	
	/**
	 * Convenience method to materialize term instance.
	 * @param source
	 * @param discard
	 * @return
	 */
	public Term load(Copyable source, boolean discard)
	{
		source.copy(sink(), discard, LinkedExtensibleMap.EMPTY_RENAMING);
		return term(true);
	}
	
	/**
	 * Return the term that has been collected by the result of {@link #sink()}, or null if none. 
	 * @param discard set when this buffer will not be accessed any more
	 */
	public Term term(boolean discard)
	{
		Term t = storedTerm;
		if (discard) storedTerm = null;
		return t;
	}

	// DelegateMaker...
	
    public final Maker maker()
    {
    	return maker;
    }
    
	// Copyable...

	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		Term t = storedTerm;
		//assert t != null : "Attempt to copy buffer with no term inside!";
		if (discard) storedTerm = null;
		if (t != null)
		{
			if (storedBinders != null && storedBinders.length > 0)
				sink = sink.binds(storedBinders);
			sink = t.copy(sink, discard, renames);
		}
		return sink;
	}
}
