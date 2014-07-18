// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.io.IOException;

/**
 * Term.
 * @author villardl
 */
public abstract class Term extends Referenceable
{
	// Static Utility mimicking C macros 

	final public static String True = "$True";
	final public static String Nil = "$Nil";

	// For Any terms

	final public static int ARITY(Term term)
	{
		return IS_VARIABLE_USE(term) ? 0 : term.descriptor.arity;
	}

	final public static boolean IS_VARIABLE_USE(Term term)
	{
		return term.descriptor == null;
	}

	final public static boolean IS_CONSTRUCTION(Term term)
	{
		return term.descriptor != null;
	}

	final public static boolean IS_FUNCTION(Term term)
	{
		return IS_CONSTRUCTION(term) && (TAG(term) == 0);
	}

	final public static boolean IS_DATA(Term term)
	{
		return IS_CONSTRUCTION(term) && (TAG(term) > 0);
	}

	final public static boolean IS_LITERAL(Term term)
	{
		return IS_DATA(term) && SORT(term) == null;
	}

	final public static boolean IS_NF(Term term)
	{
		return IS_VARIABLE_USE(term) || ((Construction) term).nf;
	}

	final public static boolean IS_CLOSED(Term term)
	{
		return !IS_VARIABLE_USE(term) && ((Construction) term).closed;
	}
	
	final public static boolean IS_NO_STEP(Term term)
	{
		return IS_VARIABLE_USE(term) || ((Construction) term).nostep;
	}
	
	// For use terms.
	final public static Variable VARIABLE(Term term)
	{
		return ((VariableUse) term).variable;
	}

	// For construction terms:

	final public static SortDescriptor SORT(Term term)
	{
		return term.descriptor.sortDescriptor;
	}

	final public static int TAG(Term term)
	{
		return term.descriptor.sortoffset;
	}

	/**
	 * Get the subterm at the given index.
	 * 
	 * <p>Note: in C, SUB returns a pointer to a term, which can be then updated.
	 * In Java, use SETSUB when the term needs to be updated
	 * 
	 * @param term
	 * @param index
	 * @return
	 */
	final public static Term SUB(Term term, int index)
	{
		assert term.nr > 0;
		assert ((Construction) term).sub[index].nr > 0 : "Reference count must be at least 1 (Term: " + Term.SYMBOL(((Construction) term).sub[index]) + ":" + ((Construction) term).sub[index].hashCode() + ")";

		return ((Construction) term).sub[index];
	}

	/**
	 * Set subterm at given index
	 * 
	 * @param term
	 * @param index
	 * @param sub subterm to set. Reference is transferred.
	 * @return
	 */
	final public static Term SETSUB(Term term, int index, Term sub)
	{
		assert term.nr > 0;
		assert sub.nr > 0;

		return ((Construction) term).sub[index] = sub;
	}
	
	/**
	 * Reset sub at given index
	 * @param term
	 */
	public static void UNLINK_SUB(Term term, int index)
	{
		((Construction) term).unlinkSub(index);
	}
	

	/** Gets the number of variables bound for the index'th subterm */
	final public static int RANK(Term term, int index)
	{
		final ConstructionDescriptor d = term.descriptor;
		return d.binderoffset[index + 1] - d.binderoffset[index];
	}

	final public static String c_name(final Term term)
	{
		return term.descriptor.name(term);
	}

	final public static String SYMBOL(final Term term)
	{
		if (IS_VARIABLE_USE(term))
			return ((VariableUse) term).variable.name;

		return c_name(term);
	}

	final public static String TEXT(final Term term)
	{
		return TEXT((Literal) term);
	}

	final public static String TEXT(final Literal term)
	{
		return term.text;
	}

	final public static long LONGLONG(final Term term)
	{
		return Long.valueOf(c_name(term));
	}

	final public static double DOUBLE(final Term term)
	{
		return Double.valueOf(c_name(term));
	}

	/** Get all subterms binders */
	final public static Variable[] BINDERS(Construction c)
	{
		return c.binders;
	}

	/** Get ith subbinders */
	final public static Variable[] BINDERS(Construction c, int i)
	{
		int n = RANK(c, i);
		if (n == 0)
			return null;

		Variable[] subbinders = new Variable[n];
		int offset = c.descriptor.binderoffset[i];
		while (--n >= 0)
		{
			subbinders[n] = c.binders[n + offset];
		}
		return subbinders;
	}

	/** Get the index of the first binder for the i'th subterm*/
	final public static int bindersOffset(Construction c, int i)
	{
		return c.descriptor.binderoffset[i];
	}

	/** Get the j'th binder of the i'th subterm */
	final public static Variable BINDER(Term t, int i, int j)
	{
		return BINDER((Construction) t, i, j);
	}

	/** Get the j'th binder of the i'th subterm */
	final public static Variable BINDER(Construction c, int i, int j)
	{
		return c.binders[c.descriptor.binderoffset[i] + j];
	}

	final public static Term GLOBAL_PROPERTY(Term key)
	{
		return null; // TODO
	}

	final public static Term PROPERTY(Term term, Term key)
	{
		return PROPERTY((Construction) term, key);
	}

	final public static Term PROPERTY(Construction construction, Term key)
	{
		return DPROPERTY(construction.namedProperties, construction.variableProperties, key);
	}

	final public static Term DPROPERTY(NamedPropertyLink namedProperties, VariablePropertyLink variableProperties, Term key)
	{
		return (IS_VARIABLE_USE(key) ? c_variableProperty(variableProperties, VARIABLE(key)) : c_namedProperty(
		        namedProperties, SYMBOL(key)));
	}
	
	final public static Term NAMED_PROPERTY(Term term, String key)
	{
		return NAMED_PROPERTY((Construction) term, key);
	}
	
	final public static NamedPropertyLink NAMED_PROPERTIES(Term term)
	{
		return NAMED_PROPERTIES((Construction) term);
	}

	final public static NamedPropertyLink NAMED_PROPERTIES(Construction term)
	{
		return term.namedProperties;
	}
	
	final public static Term NAMED_PROPERTY(Construction term, String key)
	{
		return c_namedProperty(term.namedProperties, key);
	}

	final public static Term VARIABLE_PROPERTY(Term term, Variable key)
	{
		return VARIABLE_PROPERTY((Construction) term, key);
	}

	final public static Term VARIABLE_PROPERTY(Construction term, Variable key)
	{
		return c_variableProperty(term.variableProperties, key);
	}

	final public static VariablePropertyLink VARIABLE_PROPERTIES(Term term)
	{
		return VARIABLE_PROPERTIES((Construction) term);
	}

	final public static VariablePropertyLink VARIABLE_PROPERTIES(Construction term)
	{
		return term.variableProperties;
	}
	
	final public static Term c_namedProperty(NamedPropertyLink link, String name)
	{
		for (; link != null; link = link.link)
			if (name.equals(link.name))
				return link.term();
		return null;

	}

	final public static Term c_variableProperty(VariablePropertyLink link, Variable variable)
	{
		for (; link != null; link = link.link)
			if (variable == link.variable)
				return link.term();
		return null;
	}

	final public static Literal makeStringLiteral(String text)
	{
		return new Literal(text);
	}

	// State

	/** Descriptor of the term. Null for variables */
	public ConstructionDescriptor descriptor;

	// Overrides
		
	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		try
		{
			Crsx.fprintTermTop(sb, this, Integer.MAX_VALUE, new VariableSet(), 0, true, 10, true);
		}
		catch (IOException e)
		{}
		return sb.toString();
	}

}
