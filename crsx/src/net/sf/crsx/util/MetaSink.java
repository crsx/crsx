/* Copyright © 2009 IBM Corporation. */
package net.sf.crsx.util;

import java.util.Map;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Helper class that emits meta-term with {@link Sink} events.
 * Specifically, creates a sequence of "event terms" of the following forms:
 * <ul>
 * <li>Start[c], with c a constant using the original constructor, for {@link Sink#start(Constructor)}. 
 * <li>End, for {@link .
 * <li>Binds[v<sub>1</sub>,...,v<sub>n</sub>], with v<sub>1</sub>,...,v<sub>n</sub> the bound variables
 * 		(but in the generated term they will, in fact, be free).
 * <li>Use[v], with v a variable.
 * <li>StartMetaApplication[c], where c is a constant named as the meta-variable.
 * <li>EndMetaApplication.
 * </ul>
 * Furthermore, terms that are inserted into the stream using
 * {@link #copy(Copyable, boolean)}
 * can be replaced with custom terms by populating the "copyable"
 * argument to the constructor.
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class MetaSink extends DelegateMaker implements Sink
{
	// State.
	
	/** Constructor name. */
	static final String START = "Start";
	/** Constructor name. */
	static final String END  = "End";
	/** Constructor name. */
	static final String BINDS = "Binds";
	/** Constructor name. */
	static final String USE = "Use";
	/** Constructor name. */
	static final String START_META_APPLICATION = "StartMetaApplication";
	/** Constructor name. */
	static final String END_META_APPLICATION = "EndMetaApplication";
	/** Constructor name. */
	static final String COPY = "Copy";
	
    // State.
    
    /** Where the meta-term goes...continuously updated, of course. */
    Sink metaSink;
    
    /** Map of known copyables... */
    final Map<Copyable, Term> copyables;
    
    /** Nesting level. */
    int nesting;
    /** Operator count. */
    int count;

	/** Reusable constructor. */
	final Constructor start;
	/** Reusable constructor. */
	final Constructor end;
	/** Reusable constructor. */
	final Constructor binds;
	/** Reusable constructor. */
	final Constructor use;
	/** Reusable constructor. */
	final Constructor startMetaApplication;
	/** Reusable constructor. */
	final Constructor endMetaApplication;
	/** Reusable constructor. */
	final Constructor cons;
	
    // Constructor.
    
    /**
     * Create meta-sink.
     * @param metaSink to send meta-term to
     * @param copyables
     */
    public MetaSink(Sink metaSink, Map<Copyable, Term> copyables)
    {
        this.metaSink = metaSink;
        this.copyables = copyables;
    	start = metaSink.makeConstructor(START);
        end = metaSink.makeConstructor(END);
    	binds = metaSink.makeConstructor(BINDS);
    	use = metaSink.makeConstructor(USE);
    	startMetaApplication = metaSink.makeConstructor(START_META_APPLICATION);
    	endMetaApplication = metaSink.makeConstructor(END_META_APPLICATION);
    	cons = metaSink.makeConstructor(CRS.CONS_SYMBOL);
    }

	// DelegateMaker...
	
    @Override
    final public Maker maker()
    {
	    return metaSink;
    }

    // Sink.
    
    public Sink start(Constructor constructor)
    {
    	metaSink = metaSink.start(cons);
        ++count;
        metaSink = metaSink.start(start).start(constructor).end().end();
    	++nesting;
        return this;
    }
    
    public Sink end()
    {
    	metaSink = metaSink.start(cons);
        ++count;
        metaSink = metaSink.start(end).end();
    	if ((--nesting) == 0)
    	{
    		// Unravel all the conses...
    		metaSink = metaSink.start(metaSink.makeConstructor(CRS.NIL_SYMBOL)).end();
    		for (int i = 0; i < count; ++i)
    			metaSink = metaSink.end();
    	}
        return this;
    }
    
    public Sink binds(Variable[] binders)
    {
    	metaSink = metaSink.start(cons);
        ++count;
        metaSink = metaSink.start(binds);
        for (Variable b : binders)
        	metaSink = metaSink.use(b);
        metaSink = metaSink.end();
        return this;
    }
    
    public Sink use(Variable variable)
    {
    	metaSink = metaSink.start(cons);
        ++count;
        metaSink = metaSink.start(use).use(variable).end();
        return this;
    }
    
    public Sink startMetaApplication(String name)
    {
    	metaSink = metaSink.start(cons);
        ++count;
    	Constructor c = metaSink.makeConstructor(name);
        metaSink = metaSink.start(startMetaApplication).start(c).end().end();
        return this;
    }
    
    public Sink endMetaApplication()
    {
    	metaSink = metaSink.start(cons);
        ++count;
        metaSink = metaSink.start(startMetaApplication).end();
        return this;
    }
    
    public Sink copy(Copyable source, boolean discard)
    {
    	if (copyables.containsKey(source))
    	{
        	metaSink = metaSink.start(cons);
            ++count;
    		metaSink = metaSink.copy(copyables.get(source), discard);
    		return this;
    	}
    	else
    	{
    		return source.copy(this, discard, LinkedExtensibleMap.EMPTY_RENAMING);
    	}
    }
}
