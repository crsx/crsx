/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /* ]] */;

import java.util.ArrayList;

/**
 * Matching context
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class MatchingContext
{
	// State

	/** List of meta application substitutes */
	protected ArrayList<Term> substitutes;

	/** List of variable substitutes */
	private ArrayList<Variable> varSubstitutes;

	/** List of meta application substitutes occurring in properties */
	private ArrayList<Properties> propertySubstitutes;
	
	/** Properties. Support for {@link MetaProperty} */
	private Properties properties;

	// Constructors

	MatchingContext()
	{
		substitutes = new ArrayList<Term>();
		varSubstitutes = new ArrayList<Variable>();
		propertySubstitutes = new ArrayList<Properties>();
	}

	// Methods

	public Term getSubstitute(int i)
	{
		return substitutes.get(i);
	}

	public void setSubstitute(int position, Term term)
	{
		while (substitutes.size() <= position)
			substitutes.add(null);

		substitutes.set(position, term);
	}

	public void setVarSubstitute(int position, Variable variable)
	{
		while (varSubstitutes.size() <= position)
			varSubstitutes.add(null);

		varSubstitutes.set(position, variable);
	}

	public Variable getVarSubstitute(int position)
	{
		if (position < 0 || position >= varSubstitutes.size() )
			throw new RuntimeException();

		return varSubstitutes.get(position);
	}

	public void setPropertySubstitute(int position, Properties properties)
	{
		while (propertySubstitutes.size() <= position)
			propertySubstitutes.add(null);

		propertySubstitutes.set(position, properties);
	}

	public Properties getPropertySubstitute(int position)
	{
		if (position < 0 || position >= propertySubstitutes.size())
			throw new RuntimeException();

		return propertySubstitutes.get(position);
	}

	/**
	 * @param properties the properties to set
	 */
	public void setProperties(Properties properties)
	{
		this.properties = properties;
	}

	/**
	 * @return the properties
	 */
	public Properties getProperties()
	{
		return properties;
	}
}
