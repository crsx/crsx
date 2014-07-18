/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Property of the form <var>:#meta
 * 
 * @author villardl
 */
public class VarMetaProperty extends PropertyConstraint
{
	// State

	/** Variable position in {@link MatchingContext} */
	final protected int varPosition;

	/** #Meta position in {@link MatchingContext} */
	final protected int metaPosition;

	// Constructors

	public VarMetaProperty(int varPosition, int metaPosition)
	{
		this.varPosition = varPosition;
		this.metaPosition = metaPosition;
	}

	// Overrides

	@Override
	public boolean match(Properties properties, MatchingContext context)
	{
		// TODO: check semantic
		context.setSubstitute(metaPosition, properties.getVariableProperty(context.getVarSubstitute(varPosition)));

		return true;
	}

	@Override
	public void contract(Properties properties, MatchingContext context)
	{
		properties.setVariableProperty(context.getVarSubstitute(varPosition), context.getSubstitute(metaPosition));
	}

}
