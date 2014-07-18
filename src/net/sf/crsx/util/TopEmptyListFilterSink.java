/* Copyright © 2012 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Stack;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Sink;

/**
 * Filter:
 * 	$Cons[$Nil, A]  
 * 
 * @author villardl
 */
public class TopEmptyListFilterSink extends ManagedSink
{
	enum State {
		OUT, DELAY_CONS
	};

	// State

	/** Constructor stack */
	final Stack<Constructor> stack;

	protected int depth;

	/** State */
	protected State state;

	protected Constructor marker;

	public TopEmptyListFilterSink(Sink seed)
	{
		super(seed);

		this.stack = new Stack<Constructor>();
		state = State.OUT;
		marker = makeConstructor("NOSEND");
	}

	@Override
	public Sink start(Constructor constructor)
	{
		stack.push(constructor);

		if (!Util.isCons(constructor) && !Util.isNull(constructor))
			depth++;

		switch (state)
		{
			case OUT :
				if (Util.isCons(constructor) && depth == 1)
				{
					state = State.DELAY_CONS;
					return this;
				}

				// Just send
				super.start(constructor);
				return this;
			case DELAY_CONS :
				if (Util.isNull(constructor))
				{
					// Don't send $Cons[$Nil

					// Place special marker on constructor stack
					stack.pop();
					stack.pop();
					stack.push(marker);
					stack.push(marker);

				}
				else
				{
					super.start(makeConstructor(CRS.CONS_SYMBOL));
					super.start(constructor);
				}
				state = State.OUT;
				//break;
			default :
				return this;

		}

	}

	@Override
	public Sink end()
	{
		final Constructor constructor = stack.pop();
		if (!Util.isCons(constructor) && !Util.isNull(constructor) && constructor != marker)
			depth--;

		if (constructor == marker)
			return this;

		switch (state)
		{
			case DELAY_CONS :
				assert false; // Cons should have 2 parameters
				break;
			case OUT :
				super.end();
				break;
			default :
		}

		return this;
	}

	 
	@Override
	public Sink copy(Copyable source, boolean discard)
	{
		throw new UnsupportedOperationException();
	}

}
