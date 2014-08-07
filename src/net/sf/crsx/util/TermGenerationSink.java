/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.util;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * Interpret term creation commands and forward the generated term.
 * 
 * <pre>
 * <em>Term<em> ::= 
 *   Start[constructor]
 *   End
 *   Bind[variable, <em>Term</em>]
 *   StartMeta[Name]
 *   EndMeta
 *   Use[variable]
 *   
 *   Constructor[Name, constructor . <em>Term<em>]
 *   Variable[Name, variable . <em>Term<em>]
 * </pre>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 */
public class TermGenerationSink extends DelegateMaker implements Sink
{
	// Constants.
	
	/**
	 * 
	 */
	public enum Command
	{
		/** Start[constructor] */
		START("Start"),
		/** End */
		END("End"),
		/** Bind[variable, <em>Term</em>] */
		BIND("Bind"),
		/** StartMeta[Name] */
		START_META("StartMeta"),
		/** EndMeta */
		END_META("EndMeta"),
		/** Use[variable] */
		USE("Use"),
		/** Constructor[constructor] */
		CONSTRUCTOR("Constructor"),
		/** Variable[constructor] */
		VARIABLE("Variable");
		
		final String symbol;
		/** Set the name. */
		Command(String name)
		{
			this.symbol = name;
		}
	};
	
	// State.
	
	/** Target for generated term. */
	private Sink sink;
	
	// Constructor.
	
	/**
	 * Create new sink ready to interpret term generation.
	 * @param initialSink initial sink in chain of sinks to send the generated term to
	 */
	public TermGenerationSink(Sink initialSink)
	{
		sink = initialSink;
	}
	
	// DelegateMaker...

    @Override
    public Maker maker()
    {
	    return sink;
    }

	// Sink...

	public Sink start(Constructor constructor)
	{
		//if (constructor.symbol().equals(anObject))
		return this;
	}
	
	public Sink end()
	{
		return this;
	}
	
	public Sink binds(Variable[] binders)
	{
		return this;
	}
	
	public Sink use(Variable variable)
	{
		return this;
	}
	
	public Sink startMetaApplication(String name)
	{
		return this;
	}
	
	public Sink endMetaApplication()
	{
		return this;
	}
	
	public Sink copy(Copyable source, boolean discard)
	{
		return this;
	}
}
