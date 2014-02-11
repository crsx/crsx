/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * If expression $[If, term, term, term]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class IfExpr extends PropertyConstraintConstruction
{

	// Constructors 

	protected IfExpr(PropertyConstraint[] constraints, Term... args)
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
		throw new UnsupportedOperationException();
	}

}
