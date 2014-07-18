// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import static net.sf.crsx.compiler.java.Term.SYMBOL;

/**
 * Base class for sink implementations
 * 
 * @author villardl
 */
public abstract class Sink
{
	// Buffer creation 

	final public static BufferSink MAKE_BUFFER()
	{
		return new BufferSink();
	}

	final public static Term BUFFER_TERM(Sink sink)
	{
		return sink.term();
	}

	final public static void FREE_BUFFER(Sink sink)
	{}
	
	// Events

	final public static Sink START(final Sink sink, final ConstructionDescriptor c)
	{
		return sink.start(c);
	}

	final public static Sink END(final Sink sink, final ConstructionDescriptor c)
	{
		return sink.end(c);
	}

	final public static Sink USE(final Sink sink, final Variable variable)
	{
		return sink.use(variable);
	}

	final public static Sink BINDS(final Sink sink, final Variable[] binds)
	{
		return sink.binds(binds);
	}

	final public static Sink COPY(final Sink sink, final Term term)
	{
		return sink.copy(term, null);
	}

	final public static Sink LITERALU(final Sink sink, final String text)
	{
		return sink.literal(text);
	}

	final public static Sink LITERAL(final Sink sink, final String text)
	{
		return sink.literal(text);
	}

	final public static Sink LITERALNF(final Sink sink, final long text)
	{
		return sink.literal(Long.toString(text));
	}
	
	final public static Sink LITERALNF(final Sink sink, final double text)
	{
		return sink.literal(Double.toString(text));
	}
	
	final public static Sink ADD_PROPERTY_REF(final Sink sink, final Construction construction)
	{
		return sink.propertyRef(construction);
	}

	final public static Sink ADD_PROPERTY_REF(final Sink sink, final Term construction)
	{
		return sink.propertyRef((Construction) construction);
	}

	final public static Sink PROPERTIES(final Sink sink, final NamedPropertyLink namedProperties, final VariablePropertyLink variableProperties)
	{
		return sink.properties(namedProperties, variableProperties);
	}
	
	final public static Sink ADD_PROPERTY(final Sink sink, final Term term, final Term value)
	{
		if (Term.IS_VARIABLE_USE(term))
			return sink.propertyVariable(((VariableUse) term).variable, value);
		else
			return sink.propertyNamed(SYMBOL(term), value);
	}

	final public static Sink ADD_PROPERTY_NAMED(final Sink sink, final String name, final Term value)
	{
		return sink.propertyNamed(name, value);
	}

	final public static Sink ADD_PROPERTY_VARIABLE(final Sink sink, final Variable variable, final Term value)
	{
		return sink.propertyVariable(variable, value);
	}

	final public static Sink ADD_PROPERTY_WEAKEN(final Sink sink, final Variable variable)
	{
		return sink.propertyWeaken(variable);
	}

	final public static Sink PROPERTIES_RESET(final Sink sink)
	{
		return sink.propertiesReset();
	}

	final public static Sink WEAKEN(final Sink sink, final Variable variable)
	{
		return sink.weaken(variable);
	}

	// Abstract Methods

	/** Extract the term of the captured (and possibly step'd) term */
	public abstract Term term();

	/**  Start Event */
	public abstract Sink start(ConstructionDescriptor descriptor);

	/** End event */
	public abstract Sink end(ConstructionDescriptor descriptor);

	/** literal event */
	public abstract Sink literal(String text);

	/** Use event */
	public abstract Sink use(Variable variable);

	/** 
	 * Binds event 
	 * @param binds array of binders
	 */
	public abstract Sink binds(Variable binds[]);

	/** 
	 * Copy term as events with some renamings 
	 * 
	 * <p>Named and variable properties are not copied. 
	 * Use {@link #propertyRef(Construction)} before calling copy to copy properties.
	 * 
	 * <p>Weakenings are preserved.
	 * 
	 * @param term to copy. Reference is transferred
	 */
	public abstract Sink copy(Term term, SubstitutionFrame renamings);

	/** 
	 * Weaken following term to *not* permit variable
	 * @param variable Reference is transferred
	 */
	public abstract Sink weaken(Variable variable);

	/** Base weakenings for next START */
	public abstract Sink weakeningRef(Construction construction);
	
	/** Base properties for next START */
	public abstract Sink propertyRef(Construction construction);

	/** 
	 * Base properties for next START
	 * @param namedProperties Reference is transferred
	 * @param variableProperties Reference is transferred
	 */
	public abstract Sink properties(NamedPropertyLink namedProperties, VariablePropertyLink variableProperties);
	
	/** 
	 * Add named property to next START 
	 * @param term Reference is transferred
	 */
	public abstract Sink propertyNamed(String name, Term term);

	/** 
	 * Add variable property to next START 
	 * @param variable Reference is transfered
	 * @param term Reference is transferred
	 */
	public abstract Sink propertyVariable(Variable variable, Term term);

	/** 
	 * Add properties weakening to *preceding* properties for next START 
	 * @param variable Reference is transfered
	 */
	public abstract Sink propertyWeaken(Variable variable);

	
	/** Reset property state */
	public abstract Sink propertiesReset();
}
