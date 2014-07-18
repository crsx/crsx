/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Get expression $[Get, term, term]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class GetExpr extends PropertyConstraintConstruction
{
	// Constructors 

	protected GetExpr(PropertyConstraint[] constraints, Term... args)
	{
		super(constraints, args); 
	}

	// Overrides

	@Override
	public boolean match(Term term, MatchingContext context)
	{
		throw new UnsupportedOperationException();
	}

	@Override
	public Term contract(MatchingContext context)
	{
		// Evaluate property constraints
		Properties properties = contractConstraints(context);
		 
		// Evaluate property key
		final Term key = args[0].contract(context);
		
		// Must be a constant
		if (!Utils.isConstant(key))
			throw new RuntimeException("First Get argument must be a constant");
		
		if (properties != null)
		{
			final Term value = properties.getNamedProperty(key.getSymbol());
			if (value != null)
				return value;
		}

		final String value = GeneratedCRSX.env.get(args[0]);
		if (value != null)
			return Dictionary.SINGLETON.createConstructor(value, properties, null, (Term[]) null);
		
		return args[1];
	}

}
