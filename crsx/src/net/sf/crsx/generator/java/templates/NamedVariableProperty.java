/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Property of the form 'name': var
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class NamedVariableProperty extends PropertyConstraint
{
	// State

	/** Property name */
	final protected String name;

	/** Variable position in {@link MatchingContext} */
	final protected int varPosition;

	// Constructors

	NamedVariableProperty(String name, int varPosition)
	{
		this.name = name;
		this.varPosition = varPosition;
	}

	// Overrides

	/**
	 * 
	 */
	@Override
	public boolean match(Properties properties, MatchingContext context)
	{
		//    	final Term term = GeneratedCRS.namedProps.get(name);
		//        return term != null && patternOrContractum.match(term, context);
		//throw new UnsupportedOperationException();
		// Not sure what to do here.
		
		return true;
	}

	@Override
	public void contract(Properties properties, MatchingContext context)
	{
		//        final Term key = context.getSubstitute(metaPosition);
		//        if (Utils.isConstant(key))
		//            GeneratedCRS.namedProps.put(key.getSymbol(), patternOrContractum.contract(context));
		throw new UnsupportedOperationException();
	}

}
