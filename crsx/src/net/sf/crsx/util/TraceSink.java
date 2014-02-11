/* Copyright (c) 2007 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Sink implementation that merely forwards everything to another
 * but appends a textual trace of the operations to a log.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: TraceSink.java,v 3.1 2013/12/09 05:48:39 krisrose Exp $
 */
public class TraceSink implements Sink
{
	// State.
	
	/** Where the trace goes. */
	final Writer log;

	/** The sink to forward next operation to. */
	private Sink sink;

	/** The prefix for the log. */
	private String prefix;

    /** Copy behavior... */
    final private boolean unfoldCopy;
    
    /** The level of nesting of the tracing. */
    private int subtreeCount;

    /** The level of nesting of the tracing. */
    private int nesting;

	// Constructor.
	
	/**
	 * Create sink that forwards everything to other sink (which it takes over).
	 * @param real sink to forward to
     * @param log to send trace to
     * @param unfoldCopy whether the {@link #copy(Copyable, boolean)} operation should unfold or delegate.
     * @param subtreeCount how many subtrees to trace for (or 0 for an unlimited sequence)
     * @param prefix to use for messages sent to the log file
	 */
	public TraceSink(Sink real, Writer log, boolean unfoldCopy, int subtreeCount, String prefix)
	{
		this.sink = real;
		this.log = log;
		this.unfoldCopy = unfoldCopy;
		this.subtreeCount = subtreeCount;
		this.prefix = prefix;
		nesting = 0;
	}
    
    /**
     * Create sink that forwards single subterm to other sink (which it takes over).
     * Output is sent to system out.
     * @param real sink to forward the subterm to
     */
    public TraceSink(Sink real)
    {
        this(real, new OutputStreamWriter(System.out), false, 1, "");
    }
    
	// Sink...
	
	public Sink start(Constructor constructor)
	{
		try
		{
			log.write(prefix+"start("+constructor.toString()+") "+nesting+"\n");
			log.flush();
		}
		catch (IOException e)
		{}
		sink = sink.start(constructor);
		++nesting;
		prefix = prefix + " ";
		return this;
	}

	public Sink end()
	{
		if (nesting == 0)
			return sink.end(); // tracing done

		--nesting;
		prefix = prefix.substring(0, prefix.length()-1);
		try
		{
			log.write(prefix+"end() "+nesting+"\n");
			log.flush();
		}
		catch (IOException e)
		{}
		sink = sink.end();
		
		if (nesting == 0 && --subtreeCount == 0)
			return sink; // all desired subtrees have been traced

		return this;
	}
	
	public Sink binds(Variable[] binders)
	{
		try
		{
			log.write(prefix+"bind([");
			boolean first = true;
			for (Variable v : binders)
			{
				if (first) first = false; else log.write(",");
				log.write(v.name());
			}
			log.write("]) "+nesting+"\n");
			log.flush();
		}
		catch (IOException e)
		{}
		sink = sink.binds(binders);
		return this;
	}

	public Sink startMetaApplication(String name)
	{
		try
		{
			log.write(prefix+"startMetaApplication("+name+") "+nesting+"\n");
			log.flush();
		}
		catch (IOException e)
		{}
		sink = sink.startMetaApplication(name);
		++nesting;
		prefix = prefix + " ";
		return this;
	}

	public Sink endMetaApplication()
	{
		if (nesting == 0)
			return sink.end(); // tracing done

		--nesting;
		prefix = prefix.substring(0, prefix.length()-1);
		try
		{
			log.write(prefix+"endMetaApplication() "+nesting+"\n");
			log.flush();
		}
		catch (IOException e)
		{}
		sink = sink.endMetaApplication();
		
		if (nesting == 0 && --subtreeCount == 0)
			return sink; // all desired subtrees have been traced

		return this;
	}

	public Sink use(Variable variable)
	{
		try
		{
			log.write(prefix+"use("+variable.name()+") "+nesting+"\n");
			log.flush();
		}
		catch (IOException e)
		{}
		sink = sink.use(variable);
		
		if (nesting == 0 && --subtreeCount == 0)
			return sink; // all desired subtrees have been traced

		return this;
	}
	
	public Sink copy(Copyable stub, boolean discard)
	{
	    if (unfoldCopy)
	        return stub.copy(this, discard, LinkedExtensibleMap.EMPTY_RENAMING);
	    else
	    {
	    	Buffer b = new Buffer(sink);
	    	b.sink().copy(stub, false);
	    	Term term = b.term(true);
	    	try
	    	{
	    		log.write(prefix+"copy("+term+", "+discard+") "+nesting+"\n");
	    		log.flush();
	    	}
	    	catch (IOException e)
	    	{}
	    	sink = sink.copy(term, discard);
	    	
			if (nesting == 0 && --subtreeCount == 0)
				return sink; // all desired subtrees have been traced

	    	return this;
	    }
	}
	
	// Maker...

	public Constructor makeConstructor(Object object)
	{
		try
		{
			log.write(prefix+"makeConstructor("+object+")\n");
			log.flush();
		}
		catch (IOException e)
		{}
		return sink.makeConstructor(object);
	}

	/* @see net.sf.crsx.Maker#makeLiteral(java.lang.Object, java.lang.String)*/
    public Constructor makeLiteral(Object object, String sort)
    {
		try
		{
			log.write(prefix+"makeLiteral("+object+","+sort+")\n");
			log.flush();
		}
		catch (IOException e)
		{}
		return sink.makeLiteral(object, sort);
    }

	public Variable makeVariable(String name, boolean promiscuous)
	{
		try
		{
			log.write(prefix+"makeVariable("+name+")\n");
			log.flush();
		}
		catch (IOException e)
		{}
		return sink.makeVariable(name, promiscuous);
	}

	public Variable freeVariable(String name, boolean promiscuous, boolean create)
    {
		try
		{
			log.write(prefix+"freeVariable("+name+","+promiscuous+","+create+")\n");
			log.flush();
		}
		catch (IOException e)
		{}
		return sink.freeVariable(name, promiscuous, create);
    }

	public Sink makeBuffer(Maker.CallBack callBack)
	{
		try
		{
			log.write(prefix+"makeBuffer(...)\n");
			log.flush();
		}
		catch (IOException e)
		{}
		Sink raw = sink.makeBuffer(callBack);
		Sink traced = new TraceSink(raw, log, unfoldCopy, 0, prefix+"|");
		return traced;
	}
}
