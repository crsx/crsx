/* Copyright © 2011, 2012 IBM Corporation. */

package net.sf.crsx.generic.completer;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.Constructor;
import net.sf.crsx.Term;
import net.sf.crsx.generic.Completer;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.util.Quad;

/** 
 * Represents a standardized rule as used by the {@link Completer}.
 * <p>
 * A rule is "standardized" when:
 * <ul>
 * <li>All variables are renamed to start with 'x' if 
 * <li>A property list reference is replaced with a named property with key {@link #REFERENCE}.
 * <li>All variable properties are replaced with named properties with the variable
 * </ul>
 */
public class StandardizedRule extends Quad<GenericTerm, GenericTerm, Constructor, Map<String, List<Term>>>
{
	// Constructor
	
	private final GenericFactory factory;

	/** Create standardized rule structure. */
	public StandardizedRule(GenericFactory factory, GenericTerm pattern, GenericTerm contraction, Constructor name, Map<String, List<Term>> options)
	{
		super(pattern, contraction, name, options);
		this.factory = factory;
		assert check();
	}
	
	@Override
	public void setOne(GenericTerm value)
	{
		super.setOne(value);
		assert check();
	}

	@Override
	public void setTwo(GenericTerm value)
	{
		super.setTwo(value);
		assert check();
	}

	/** Consistency check. */
	private boolean check()
	{
		Term contractum = getContractum();
		if (contractum != null)
		{
			Set<String> patternMetas = new HashSet<String>();
			Standardizer.addMetas(getPattern(), patternMetas);
			Set<String> contractumMetas = new HashSet<String>();
			Standardizer.addMetas(getContractum(), contractumMetas);
			contractumMetas.removeAll(patternMetas);
			if (!contractumMetas.isEmpty())
			{
				factory.warning("PANIC: internal rule "+getName()+" generated with undefined  contraction meta-variables "+contractumMetas);
				return false;
			}
		}
		return true;
	}
	
	// Methods

	/** Get rule pattern */
	final public GenericTerm getPattern()
	{
		return one();
	}

	/** Get rule contractum */
	final public GenericTerm getContractum()
	{
		return two();
	}

	/** Get rule name */
	final public Constructor getName()
	{
		return three();
	}

	/** Get rule options */
	final public Map<String, List<Term>> getOptions()
	{
		return four();
	}

	/** Safely set given option value */
	final public void setOption(String name, List<Term> value)
	{
		if (getOptions() == null)
			setFour(new HashMap<String, List<Term>>(5));
		getOptions().put(name, value);
	}

	// Object

	public String toString()
	{
		return "\nSTANDARD " + three() + four() + "\n : " + one() + "\n → " + two();
	}
}