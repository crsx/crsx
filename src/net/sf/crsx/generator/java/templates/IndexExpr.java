/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Index expression $[Index, term, term]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class IndexExpr extends PropertyConstraintConstruction
{

	// Constructors 

	protected IndexExpr(PropertyConstraint[] constraints, Term... args)
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
