/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Factory;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.generic.GenericFactory;

/**
 * Sink that echoes the term in text form.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SimpleTermSink.java,v 3.5 2014/01/06 03:11:36 krisrose Exp $
 */
public class SimpleTermSink extends DelegatingMaker implements Sink
{
	// State.
	
	/** Where the term goes. */
	final FormattingAppendable appendable;
	
	/** Stack of scopes. */
	private StackOf<Pair<ExtensibleMap<Variable, String>, Integer>> stack = new StackOf<Pair<ExtensibleMap<Variable, String>, Integer>>();
	
	/** Top scope. */
	private ExtensibleMap<Variable, String> scope = LinkedExtensibleMap.EMPTY_NAMING;

	/** Used variable names. */
	private Map<Variable, String> used = new HashMap<Variable, String>();
	
	/** Top sibling count. */
	private int count;
	
	/** True just after binders or other force of separator. */
	private boolean pre;
	
	/** Omit linearity markers. */
	private boolean noLinear;

	// Constructor.
	
	/**
	 * Create sink.
	 * @param factory for configuration and creation
	 * @param target to send term to
	 * @param canonicalVariables TODO
	 */
	public SimpleTermSink(Factory<? extends Term> factory, Appendable target, boolean canonicalVariables)
	{
		super(factory);
		if (target instanceof FormattingAppendable)
			appendable = (FormattingAppendable) target;
		else
			appendable = FormattingAppendable.format(target, Integer.MAX_VALUE, 0, Integer.MAX_VALUE);
		if (canonicalVariables)
			used.put(null, "1");
		noLinear = factory.defined(GenericFactory.NO_LINEAR_VARIABLES);
	}
	
	// Methods.
	
	/** Helper to enter new argument list. */
	private void enter() throws IOException
	{
		stack.push(new Pair<ExtensibleMap<Variable, String>, Integer>(scope, count));
		appendable.open("");
		count = 0;
	}
	/** Helper to leave new argument list. */
	private void leave() throws IOException
	{
		appendable.close(count == 0 ? "" : "]");
		Pair<ExtensibleMap<Variable, String>, Integer> top = stack.pop();
		scope = top.head();
		count = top.tail();
	}
	/** Helper to issue separator right away. */
	private void preNext() throws IOException
	{
		if (!stack.isEmpty())
			appendable.append(count == 0 ? "[" : ",\n");
		pre = true;
	}
	/** Helper to advance to next argument. */
	private void next() throws IOException
	{
		if (!stack.isEmpty() && !pre)
			appendable.append(count == 0 ? "[" : ",\n");
		++count;
		pre = false;
	}

	// Sink...
	
	public Sink start(Constructor constructor)
	{
		try
		{
			next();
			constructor.appendTo(appendable, used, Integer.MAX_VALUE, true, true, true, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
			enter();
		}
		catch (IOException e)
		{}
		return this;
	}

	public Sink end()
	{
		try
		{
			leave();
			if (stack.isEmpty())
				appendable.flush();
		}
		catch (IOException e)
		{}
		return this;
	}
	
	public Sink binds(Variable[] binders)
	{
		try
		{
			preNext();
			if (binders.length > 0)
			{
				for (Variable v : binders)
				{
					String name = Util.safeVariableName(v, used, noLinear, false);
					for (int i = 1; scope.containsValue(name); ++i)
						name = v.name() + "-" + i;
					scope = scope.extend(v, name);
					appendable.append(name);
					appendable.append(" ");
				}
				appendable.append(". ");
			}
		}
		catch (IOException e)
		{}
		return this;
	}

	public Sink startMetaApplication(String name)
	{
		try
		{
			next();
			appendable.append(name);
			enter();
		}
		catch (IOException e)
		{}
		return this;
	}

	public Sink endMetaApplication()
	{
		try
		{
			leave();
		}
		catch (IOException e)
		{}
		return this;
	}

	public Sink use(Variable variable)
	{
		try
		{
			next();
			appendable.append(Util.safeVariableName(variable, used, noLinear, false));
		}
		catch (IOException e)
		{}
		return this;
	}

	public Sink copy(Copyable stub, boolean discard)
	{
		return stub.copy(this, discard, LinkedExtensibleMap.EMPTY_RENAMING);
	}
}
