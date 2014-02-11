// Copyright (c) 2013 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.lang.reflect.Field;
import java.util.IdentityHashMap;
import java.util.Map;
import java.util.Stack;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Variable;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.util.DelegateMaker;

/**
 * Interpreter {@link net.sf.crsx.Sink} to compiler {@link Sink}
 * 
 * @author villardl
 */
public class Sink2Sink extends DelegateMaker implements net.sf.crsx.Sink
{
	// State

	/** Target sink */
	final protected Sink target;

	/** Class containing compiled descriptors */
	final protected Class<?> descriptors;

	/** Descriptor stack */
	protected Stack<ConstructionDescriptor> descStack;

	/** Variable mapping */
	protected Map<Variable, net.sf.crsx.compiler.java.Variable> varMapping;

	// Constructor

	public Sink2Sink(Sink target, Class<?> descriptors)
	{
		this.target = target;
		this.descriptors = descriptors;

		descStack = new Stack<ConstructionDescriptor>();
		varMapping = new IdentityHashMap<Variable, net.sf.crsx.compiler.java.Variable>();

	}

	// Overrides

	@Override
	public net.sf.crsx.Sink start(Constructor constructor)
	{
		String symbol = constructor.symbol();
		
		if (constructor.literalSort() != null)
		{
			// Literal
			target.literal(symbol);
			descStack.push(Literal.LITERAL_CONSTRUCTION_DESC);
		}
		else
		{
			ConstructionDescriptor desc = (ConstructionDescriptor) readField(descriptors.getInterfaces(), "descriptor" + symbol);
			if (desc == null)
			{
				target.literal(symbol); 
				descStack.push(Literal.LITERAL_CONSTRUCTION_DESC);
			}
			else
			{
				target.start(desc);
				descStack.push(desc);
			}
		}
		return this;
	}

	@Override
	public net.sf.crsx.Sink end()
	{
		ConstructionDescriptor desc = descStack.pop();
		
		if (desc != Literal.LITERAL_CONSTRUCTION_DESC)
			target.end(desc);
		return this;
	}

	@Override
	public net.sf.crsx.Sink binds(Variable[] binders)
	{
		net.sf.crsx.compiler.java.Variable[] vars = new net.sf.crsx.compiler.java.Variable[binders.length];
		for (int i = 0; i < binders.length; i++)
		{
			net.sf.crsx.compiler.java.Variable var = net.sf.crsx.compiler.java.Variable.MAKE_VARIABLE(
			        binders[i].name(), true, !binders[i].promiscuous());
			vars[i] = var;
			varMapping.put(binders[i], var);
		}

		target.binds(vars);
		return this;
	}

	@Override
	public net.sf.crsx.Sink use(Variable variable)
	{
		net.sf.crsx.compiler.java.Variable var = varMapping.get(variable);
		target.use(var);
		return this;
	}

	@Override
	public net.sf.crsx.Sink startMetaApplication(String name)
	{
		throw new RuntimeException();
	}

	@Override
	public net.sf.crsx.Sink endMetaApplication()
	{
		throw new RuntimeException();
	}

	@Override
	public net.sf.crsx.Sink copy(Copyable source, boolean discard)
	{
		throw new RuntimeException();
	}

	@Override
	public Maker maker()
	{
		return new GenericFactory();
	}

	// Helper

	protected Object readField(Class<?>[] c, String name)
	{
		Field f = null;
		for (int i = 0; i < c.length; i++)
		{
			try
			{
				f = c[i].getDeclaredField(name);
			}
			catch (SecurityException e)
			{
				e.printStackTrace();
			}
			catch (NoSuchFieldException e)
			{}
		}

		try
		{
			if (f == null)
			{
				System.out.println("Warning: can't find descriptor for " + name);
			}
			else
				f.setAccessible(true);
			
			return f == null ? null : f.get(null);
		}
		catch (IllegalArgumentException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IllegalAccessException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;

	}

}
