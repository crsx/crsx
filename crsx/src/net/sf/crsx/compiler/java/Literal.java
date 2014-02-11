// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.util.ArrayList;

/**
 * Literal term
 * 
 * @author <a href="researcher.watson.ibm.com/researcher/view.php?person=us-villard">Lionel Villard</a>.
 */
public class Literal extends Construction
{

	// State

	/** Literal text */
	public String text;

	// Constructor

	/**
	 * Make string literal
	 * @param text
	 */
	public Literal(String text)
	{
		this(null, null, null, text);
		this.nf = true;
		this.nostep = true;
		this.nr = 1;
	}

	public Literal(VariableSetLink weakenings, NamedPropertyLink namedProperties, VariablePropertyLink variableProperties,
	        String text)
	{
		super(Literal.LITERAL_CONSTRUCTION_DESC, weakenings, namedProperties, variableProperties, false, false);
		this.text = text;
	}

	// Special construction descriptor just for literal

	final public static ConstructionDescriptor LITERAL_CONSTRUCTION_DESC = new ConstructionDescriptor(null, 1, 0, 0, null, -1)
		{

			@Override
			public boolean step(Sink sink, Term term, final ArrayList<Crsx.ContextEntry> ancestors)
			{
				return false;
			}

			@Override
			public String name(Term term)
			{
				return ((Literal) term).text;
			}
		};

}
