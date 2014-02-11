/* Copyright © 2009 IBM Corporation. */
package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;



/**
 * Plus expression $[Plus, term, term]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class PlusExpr extends PropertyConstraintConstruction
{
    
    // Constructors 
    protected PlusExpr(PropertyConstraint[] constraints, Term ... args)
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
