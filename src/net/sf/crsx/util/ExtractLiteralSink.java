/* Copyright © 2012 IBM Corporation. */

package net.sf.crsx.util;

import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * Extract LITERAL/CONSTRUCTION[KDATA, SYMBOL, BINDERS] within PROPERTY or GET or IFDEF
 * 
 * @author villardl
 */
public class ExtractLiteralSink extends ManagedSink
{
	enum State {
		FILTER, ACCEPT, IN_LITERAL, IN_EVALUATOR, IN_PROPERTY, IN_CONSTRUCTION
	};

	// State

	/** Crsx term depth */
	protected int depth;

	/** Number of literals */
	protected int literalCount;

	/** Seen literals */
	protected Set<String> literals;

	/** State stack */
	protected Stack<State> state;

	public ExtractLiteralSink(Sink seed)
	{
		super(seed);

		state = new Stack<State>();
		state.push(State.FILTER);
		depth = 0;
		literalCount = 0;
		literals = new HashSet<String>();
		//		literals.add("$FileLocation");
		//		literals.add("$LineLocation");
		//		literals.add("$ColumnLocation");
	}

	@Override
	public Sink start(Constructor constructor)
	{
		depth++;

		if ("PROPERTY".equals(constructor.symbol()))
		{
			state.push(State.IN_PROPERTY);
		}
		else if ("EVALUATOR".equals(constructor.symbol()))
		{
			state.push(State.IN_EVALUATOR);
		}
		else if ("LITERAL".equals(constructor.symbol()) && state.peek() != State.IN_LITERAL)
		{
			switch (state.peek())
			{
				case IN_PROPERTY :
					// Only want to accept the first literal, so patch the state
					state.pop();
					state.push(State.FILTER);
					state.push(State.IN_LITERAL);
					break;
				case ACCEPT :
					state.push(State.IN_LITERAL);
					break;
				case FILTER :
					state.push(State.FILTER);
					break;
				case IN_LITERAL : // Could be "LITERAL", thus the guard above
				case IN_CONSTRUCTION :
					// hmm shouldn't happen
					throw new RuntimeException();
				default :
					break;
			}
		}
		else if ("CONSTRUCTION".equals(constructor.symbol()))
		{
			state.push(State.IN_CONSTRUCTION);
		}
		else
		{
			switch (state.peek())
			{
				case IN_PROPERTY :
					state.pop();
					state.push(State.FILTER);
					state.push(State.FILTER);
					break;
				case IN_EVALUATOR :
					// This is the evaluator name.

					state.pop();
					String eval = constructor.symbol();
					if (eval.equals("Get") || eval.equals("IfDef"))
						state.push(State.ACCEPT);
					else
						state.push(State.FILTER);
					state.push(State.FILTER); // does not matter: will be popped right away.

					break;
				case IN_LITERAL :
					if (!constructor.symbol().equals("$Cons") && !literals.contains(constructor.symbol()))
					{
						literals.add(constructor.symbol());

						super.start(sink.makeConstructor(CRS.CONS_SYMBOL));
						super.start(constructor);
						super.end();

						literalCount++;
					}
					state.pop();
					state.push(State.FILTER); // Skip literal sort.
					state.push(State.FILTER);

					break;
				case IN_CONSTRUCTION :
					if (constructor.symbol().equals("KDATA"))
					{
						// parent construction is data. The next start event is the data constructor symbol: add it 
						state.pop();
						state.push(State.IN_LITERAL);
					}
					else
					{
						state.pop();
						state.push(State.FILTER);
					}
					state.push(State.IN_LITERAL); // does not matter: will be popped right away.
					break;
				default :
					// Inherit state
					state.push(state.peek());

			}
		}
		return this;
	}

	@Override
	public Sink end()
	{
		depth--;
		state.pop();

		if (depth == 0)
		{
			super.start(sink.makeConstructor(CRS.NIL_SYMBOL));
			super.end();

			for (int i = 0; i < literalCount; i++)
				super.end();
		}

		return this;
	}

	@Override
	public Sink binds(Variable[] binders)
	{
		return this;
	}

	@Override
	public Sink use(Variable variable)
	{
		return this;
	}

	@Override
	public Sink startMetaApplication(String name)
	{
		return this;
	}

	@Override
	public Sink endMetaApplication()
	{
		return this;
	}

	@Override
	public Sink copy(Copyable source, boolean discard)
	{
		throw new UnsupportedOperationException();
	}

}
