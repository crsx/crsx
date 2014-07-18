/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates /*]]*/;

/**
 * Property of the form &not; #Meta
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class NotMetaProperty extends PropertyConstraint
{
	// State

	/** #Meta position in {@link MatchingContext} */
	final protected int metaPosition;

	// Constructors

	NotMetaProperty(int metaPosition)
	{
		this.metaPosition = metaPosition;
	}

	// Overrides

	@Override
	public boolean match(Properties properties, MatchingContext context)
	{
		//        final Term key = context.getSubstitute(metaPosition);
		//        if (Utils.isConstant(key))
		//            return GeneratedCRSX.namedProps.get(key.getSymbol()) == null;
		//        return true;

		throw new UnsupportedOperationException();
	}

	@Override
	public void contract(Properties properties, MatchingContext context)
	{ 
		throw new UnsupportedOperationException();
	}

}
