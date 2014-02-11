/* Copyright © 2012 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Stack;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * Filter:
 * 	FUNCTION[Name, ...]
 * 
 * when the name prefix does not match the given prefix
 * 
 * @author villardl
 */
public class FunctionFilterSink extends ManagedSink
{
	enum State {
		OUT, SEND, FILTER, DELAY_FUNCTION
	};

	// State

	/** Filter by prefix */
	final String prefix;

	/** Constructor stack */
	final Stack<Constructor> stack;

	/** FUNCTION depth */
	protected int functionDepth;

	/** DATA depth */
	protected int dataDepth;

	/** State */
	protected State state;

	/** Last FUNCTION constructor seen */
	protected Constructor functionConstructor;

	public FunctionFilterSink(Sink seed, String prefix)
	{
		super(seed);

		this.stack = new Stack<Constructor>();
		this.prefix = prefix;
		state = State.OUT;
	}

	@Override
	public Sink start(Constructor constructor)
	{
		stack.push(constructor);

		final boolean isFunction = "FUNCTION".equals(constructor.symbol());

		if (isFunction)
		{
			functionConstructor = constructor;
			functionDepth++;
		}

		switch (state)
		{
			case OUT :
				if (isFunction && functionDepth == 1)
				{
					state = State.DELAY_FUNCTION;
					return this;
				}

				// Just send
				super.start(constructor);
				return this;
			case FILTER :
				return this;
			case SEND :
				super.start(constructor);
				return this;
			case DELAY_FUNCTION :
				String symbol = constructor.symbol();
				final boolean filter = !symbol.startsWith(prefix);
				if (filter)
				{
					// Replace by $Nil
					super.start(sink.makeConstructor(CRS.NIL_SYMBOL));
					super.end();

					state = State.FILTER;
				}
				else
				{
					// Don't filter... send FUNCTION
					super.start(functionConstructor);
					super.start(constructor); // Name

					state = State.SEND;
				}
				//break;
			default :
				return this;

		}

	}

	@Override
	public Sink end()
	{
		final Constructor constructor = stack.pop();
		final boolean isFunction = "FUNCTION".equals(constructor.symbol());
	
		if (isFunction)
			functionDepth--;

		switch (state)
		{
			case OUT :
			case SEND :
				super.end();
				break;
			case DELAY_FUNCTION :
				// Literal "FUNCTION"
				state = State.OUT;
				super.start(constructor);
				super.end();
				break;
			case FILTER :
			default :
		}

		if (isFunction && functionDepth == 0)
			state = State.OUT;

		return this;
	}

	@Override
	public Sink binds(Variable[] binders)
	{
		if (state != State.FILTER)
			return super.binds(binders);

		return this;
	}

	@Override
	public Sink use(Variable variable)
	{
		if (state != State.FILTER)
			return super.use(variable);

		return this;
	}

	@Override
	public Sink startMetaApplication(String name)
	{
		if (state != State.FILTER)
			return super.startMetaApplication(name);
		return this;
	}

	@Override
	public Sink endMetaApplication()
	{
		if (state != State.FILTER)
			return super.endMetaApplication();
		return this;
	}

	@Override
	public Sink copy(Copyable source, boolean discard)
	{
		throw new UnsupportedOperationException();
	}

}
