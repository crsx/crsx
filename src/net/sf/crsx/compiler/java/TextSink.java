// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import static net.sf.crsx.compiler.java.Term.ARITY;
import static net.sf.crsx.compiler.java.Term.IS_CONSTRUCTION;
import static net.sf.crsx.compiler.java.Term.SUB;
import static net.sf.crsx.compiler.java.Term.SYMBOL;

import java.io.IOException;

/**
 * Outputs formatted text terms as plain text.
 * 
 * <p>
 * Expect fully normalize text term, without embedded terms.
 * 
 * @author villardl
 */
public class TextSink extends Sink
{
	// State

	/** Output */
	final protected Appendable output;

	/** $TextChars descriptor */
	final protected ConstructionDescriptor textChars;

	/** $textBreak descriptor */
	final protected ConstructionDescriptor textBreak;

	// Constructor

	public TextSink(Appendable output, ConstructionDescriptor textChars, ConstructionDescriptor textBreak)
	{
		this.output = output;
		this.textChars = textChars;
		this.textBreak = textBreak;
	}

	// Overrides

	@Override
	public Term term()
	{
		throw new RuntimeException("TextSink does not create terms");
	}

	@Override
	public Sink start(ConstructionDescriptor descriptor)
	{
		return this;
	}

	@Override
	public Sink end(ConstructionDescriptor descriptor)
	{
		return this;
	}

	@Override
	public Sink literal(String text)
	{
		try
		{
			output.append(text);
		}
		catch (IOException e)
		{
			throw new RuntimeException(e);
		}
		return this;
	}

	@Override
	public Sink use(Variable variable)
	{
		throw new RuntimeException();
	}

	@Override
	public Sink binds(Variable[] binds)
	{
		throw new RuntimeException();
	}

	@Override
	public Sink copy(Term term, SubstitutionFrame renamings)
	{
		// TODO: could make it a reusable component
		assert renamings == null;

		if (IS_CONSTRUCTION(term))
		{
			Construction construction = (Construction) term;
			if (construction.descriptor == textChars || construction.descriptor == textBreak)
				literal(SYMBOL(construction.sub[0]));
			else
			{
				start(construction.descriptor);
				for (int i = 0; i < ARITY(term); i++)
					copy(SUB(construction, i), null);
				end(construction.descriptor);
			}
		}
		else
		{
			throw new RuntimeException("Malformed text term");
		}

		return this;
	}

	@Override
	public Sink weakeningRef(Construction construction)
	{
		return this;
	}

	@Override
	public Sink weaken(Variable variable)
	{
		return this;
	}

	@Override
	public Sink propertyRef(Construction construction)
	{
		throw new RuntimeException();
	}

	@Override
	public Sink propertyNamed(String name, Term term)
	{
		throw new RuntimeException();
	}

	@Override
	public Sink propertyVariable(Variable variable, Term term)
	{
		throw new RuntimeException();
	}

	@Override
	public Sink propertyWeaken(Variable variable)
	{
		throw new RuntimeException();
	}

	@Override
	public Sink propertiesReset()
	{
		throw new RuntimeException();
	}

	@Override
    public Sink properties(NamedPropertyLink namedProperties, VariablePropertyLink variableProperties)
    {
	    // TODO Auto-generated method stub
	    return null;
    }

}
