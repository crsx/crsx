/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /*]]*/;

/**
 * Construction with property constraints
 * 
 * @author villardl
 */
public abstract class PropertyConstraintConstruction extends Construction
{

	// State

	/** Property constraints */
	final protected PropertyConstraint[] constraints;

	// Constructor

	protected PropertyConstraintConstruction(PropertyConstraint[] constraints, Term... args)
	{
		super(args);

		this.constraints = constraints;
	}

	// Methods

	/** Match property constraints */
	protected boolean matchConstraints(Properties properties, MatchingContext context)
	{
		if (constraints != null)
		{
			for (int i = 0; i < constraints.length; i++)
				if (!constraints[i].match(properties, context))
					return false;
		}
		return true;
	}

	/** Contract property constraints */
	protected Properties contractConstraints(MatchingContext context)
	{
		if (constraints == null)
			return null;

		final Properties properties = new Properties();
		for (int i = 0; i < constraints.length; i++)
			constraints[i].contract(properties, context);
		return properties;
	}

}
