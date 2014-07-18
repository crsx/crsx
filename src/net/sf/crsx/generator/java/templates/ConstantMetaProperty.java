/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Property of the form <blockquote>'constant': #meta</blockquote>
 * 
 * @author villardl
 */
public class ConstantMetaProperty extends PropertyConstraint
{
	// State

	/** Constant symbol */
	final protected String symbol;

	/** Meta variable position in the pattern or contractum */
	final protected int position;

	// Constructors

	protected ConstantMetaProperty(String symbol, int position)
	{
		super();
		this.symbol = symbol;
		this.position = position;
	}

	// Overrides

	/**
	 * Binds #meta to the property value named 'constant'
	 * 
	 * If the property does not exist, an exception is thrown (as a sanity check)
	 */
	@Override
	public boolean match(Properties properties, MatchingContext context)
	{
		if (properties == null)
		{
			context.setSubstitute(position, null);
			return true;
		}

		final Term value = properties.getNamedProperty(symbol);
		if (value == null)
			throw new RuntimeException("Undefined named property: " + symbol);

		context.setSubstitute(position, value);
		return true;
	}

	/**
	 * Sets the property named 'constant' to the value bound to #meta
	 */
	@Override
	public void contract(Properties properties, MatchingContext context)
	{
		 properties.setNamedProperty(symbol, context.getSubstitute(position));
	}

}
