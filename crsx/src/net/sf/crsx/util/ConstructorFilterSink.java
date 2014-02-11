/* Copyright © 2012 IBM Corporation. */

package net.sf.crsx.util;

import java.util.Arrays;
import java.util.Stack;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * Filter:
 * 	Constructor[ ...]
 * replace by $Nil
 * @author villardl
 */
public class ConstructorFilterSink extends ManagedSink
{
	enum State {
		OUT, SEND, FILTER
	};

	// State

	/** Constructor stack */
	final Stack<Constructor> stack;

	/** Name of the constructor to filter */
	final protected String[] names;
	final protected int depth;
	
	protected int currentDepth;

	/** State */
	protected State state;

	public ConstructorFilterSink(Sink seed, String[] names, int depth)
	{
		super(seed);

		this.stack = new Stack<Constructor>();
		state = State.OUT;
		this.names = names;
		this.depth = depth;
	}

	@Override
	public Sink start(Constructor constructor)
	{
		stack.push(constructor);
		
		if (!Util.isCons(constructor) && !Util.isNull(constructor))
			currentDepth++;
		
		boolean isData = false;
		String symbol = constructor.symbol();
		for (String name : names)
			if (name.equals(symbol))
				isData = true;

		switch (state)
		{
			case OUT :
				if (isData && depth == currentDepth)
				{
					// Replace by $Nil
					super.start(sink.makeConstructor(CRS.NIL_SYMBOL));
					super.end();

					state = State.FILTER;
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
			default :
				return this;

		}

	}

	@Override
	public Sink end()
	{
		final Constructor constructor = stack.pop();
		if (!Util.isCons(constructor) && !Util.isNull(constructor))
			currentDepth--;

		boolean isData = false;
		String symbol = constructor.symbol();
		for (String name : names)
			if (name.equals(symbol))
				isData = true;

		switch (state)
		{
			case OUT :
			case SEND :
				super.end();
				break;
			case FILTER :
			default :
		}

		if (isData && depth - 1 == currentDepth)
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
