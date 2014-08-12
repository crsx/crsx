/* Copyright (c) 2007, 2008 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.CRSException;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Simple holder of properties (including meta-properties, if so desired).
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericProperties.java,v 3.1 2013/10/06 15:38:26 krisrose Exp $
 */
public class GenericProperties implements PropertiesHolder
{
	// State.

	/** The reference to the properties. */
	protected String propertiesRef;

	/** Named properties. */
	public Map<String, Term> namedPropertyConstraints;

	/** Bound variable properties. */
	protected Map<Variable, Term> variablePropertyConstraints;

	/** Bound variable properties. */
	protected Map<String, Term> metaPropertyConstraints;
	
	/** Whether the properties are known to have been normalized... */
	public boolean propertiesNormalized;

	// Constructor.
	
	/**
	 * Create empty properties.
	 */
	GenericProperties()
	{
		this(null, null, null, null);
	}

	/**
	 * Create property constraint constructor.
	 * @param propertiesRef permitting reference to properties
	 * @param namedPropertyConstraints associated to the constructor
	 * @param variablePropertyConstraints associated to the constructor
	 * @param metaPropertyConstraints associated to the constructor
	 */
	GenericProperties(String propertiesRef, Map<String, Term> namedPropertyConstraints,
			Map<Variable, Term> variablePropertyConstraints, Map<String, Term> metaPropertyConstraints)
	{
		this.propertiesRef = propertiesRef;
		this.namedPropertyConstraints = (namedPropertyConstraints == null ? new HashMap<String, Term>() : namedPropertyConstraints);
		this.variablePropertyConstraints = (variablePropertyConstraints == null ? new HashMap<Variable, Term>() : variablePropertyConstraints);
		this.metaPropertyConstraints = (metaPropertyConstraints == null ? new HashMap<String, Term>() : metaPropertyConstraints);
	}

	// Methods.

	/** Set one named property constraint. */
	public void setPropertyConstraint(String key, Term value)
	{
		namedPropertyConstraints.put(key, value);
		propertiesNormalized = false;
	}

	/** Set one variable property constraint. */
	public void setPropertyConstraint(Variable key, Term value)
	{
		variablePropertyConstraints.put(key, value);
		propertiesNormalized = false;
	}

	/** Set a bunch of properties. */
	public void setPropertyConstraints(Map<String, Term> ps)
	{
		namedPropertyConstraints.putAll(ps);
		propertiesNormalized = false;
	}

	/** Set a bunch of variable properties. */
	public void setVarPropertyConstraints(Map<Variable, Term> ps)
	{
		variablePropertyConstraints.putAll(ps);
		propertiesNormalized = false;
	}

	/** Set meta-variable name. */
	public void setMeta(String ref)
	{
		propertiesRef = ref;
	}

	/** Whether the wrapper has no property constraonts at all... */
	public boolean isEmpty()
	{
		return (propertiesRef == null
				&& namedPropertyConstraints.isEmpty() && variablePropertyConstraints.isEmpty() && metaPropertyConstraints.isEmpty());
	}

	// PropertiesHolder.

	public Iterable<String> propertyNames()
	{
		return namedPropertyConstraints.keySet();
	}

	public Term getProperty(String name)
	{
		return namedPropertyConstraints.get(name);
	}

	public boolean canSetProperty(String name)
	{
		return name != null;
	}
	
	public void setProperty(String key, Term value)
	{
		if (value != null)
			namedPropertyConstraints.put(key, value);
		else
			namedPropertyConstraints.remove(key);
	}

	public Iterable<Variable> propertyVariables()
	{
		return variablePropertyConstraints.keySet();
	}

	public Term getProperty(Variable variable)
	{
		return variablePropertyConstraints.get(variable);
	}

	public boolean canSetProperty(Variable variable)
	{
		return variable != null;
	}

	public void setProperty(Variable key, Term value)
	{
		if (value != null)
			variablePropertyConstraints.put(key, value);
		else
			variablePropertyConstraints.remove(key);
	}
	
	@Override
	public void removeProperty(Variable variable) throws CRSException
	{
		variablePropertyConstraints.remove(variable);
	}

	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		for (String name : properties.propertyNames())
			setProperty(name, properties.getProperty(name));
		for (Variable variable : properties.propertyVariables())
			setProperty(variable, properties.getProperty(variable));
	}
	
	public boolean isMeta()
	{
		if (propertiesRef != null)
			return true;
		if (!metaPropertyConstraints.isEmpty())
			return true;
		if (namedPropertyConstraints.containsValue(null))
			return true;
		if (variablePropertyConstraints.containsValue(null))
			return true;
		return false;
	}
}
