/* Copyright © 2009 IBM Corporation. */
package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;



/**
 * Substring expression $[Substring, term, term, term]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class SubstringExpr extends PropertyConstraintConstruction
{
    
    // Constructors 
    protected SubstringExpr(PropertyConstraint[] constraints, Term ... args)
    {
        super(constraints, args);
    }

    // Overrides
    
    @Override
    public Term contract(MatchingContext context)
    {
        throw new UnsupportedOperationException();
    }

    @Override
    public boolean match(Term term, MatchingContext context)
    {
        throw new UnsupportedOperationException();
    }
 

}
