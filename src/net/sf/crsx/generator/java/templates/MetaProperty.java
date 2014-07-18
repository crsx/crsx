/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Property of the form #c
 * 
 * @author villardl
 */
public class MetaProperty extends PropertyConstraint
{
	// State

	/** Meta variable position in {@link MatchingContext} */
	final protected int position;

	// Constructor

	public MetaProperty(int position)
	{
		this.position = position;
	}

	// Overrides

	@Override
	public boolean match(Properties properties, MatchingContext context)
	{
		context.setProperties(properties);
		return true;
	}

	@Override
	public void contract(Properties properties, MatchingContext context)
	{
		properties.namedProperties = context.getProperties().namedProperties;
		properties.varProperties = context.getProperties().varProperties;
	}

}
