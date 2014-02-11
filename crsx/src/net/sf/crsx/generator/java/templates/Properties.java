/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

import java.util.HashMap;
import java.util.Map;

/**
 * Holds properties
 * 
 * @author villardl
 */
public class Properties
{

	// State

	/** Named properties */
	protected Map<String, Term> namedProperties;

	/** Variable properties */
	protected Map<Variable, Term> varProperties;

	// Methods

	/** Get the named property value */
	public Term getNamedProperty(String key)
	{
		return namedProperties == null ? null : namedProperties.get(key);
	}

	/** Set the named property value */
	public void setNamedProperty(String key, Term value)
	{
		if (namedProperties == null)
			namedProperties = new HashMap<String, Term>();

		namedProperties.put(key, value);
	}

	/** Get the variable property value */
	public Term getVariableProperty(Variable var)
	{
		return varProperties == null ? null : varProperties.get(var);
	}

	/** Set the variable property value */
	public void setVariableProperty(Variable key, Term value)
	{
		if (varProperties == null)
			varProperties = new HashMap<Variable, Term>();

		varProperties.put(key, value);

	}

}
