/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * IfDef expression $[IdDef, condition, term, term]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class IfDefExpr extends PropertyConstraintConstruction
{

	// Constructors 
	protected IfDefExpr(PropertyConstraint[] constraints, Term... args)
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
		final Properties properties = contractConstraints(context);

		boolean defined = false;
		switch (args[1].getKind())
		{
			case VARIABLE_KIND :
				VariableUse varUse = (VariableUse) args[1].contract(context);
				if (properties != null)
					defined = properties.getVariableProperty(varUse.var) != null;
				//                if (!defined)
				//                	defined = GeneratedCRSX.env.containsKey(varUse.var);
				break;
			case CONSTRUCTION_KIND :
				if (properties != null)
					defined = properties.getNamedProperty(args[1].getSymbol()) != null;
				if (!defined)
					defined = GeneratedCRSX.env.get(args[1].getSymbol()) != null;
				break;
			default :
			case META_APP_KIND :
				final Term key = args[1].contract(context);
				if (!Utils.isConstant(key))
					throw new RuntimeException("Second IfDef argument must be a constant");
				if (properties != null)
					defined = properties.getNamedProperty(key.getSymbol()) != null;
				if (!defined)
					defined = GeneratedCRSX.env.get(key.getSymbol()) != null;
		}

		return defined ? args[2].contract(context) : args[3].contract(context);
	}

}
