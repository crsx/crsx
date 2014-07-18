/* Copyright © 2009 IBM Corporation. */
package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;


/**
 * NotMatch expression.
 * Support:
 * <ul>
 * <li>$[NotMatch, #not]
 * <li>$[NotMatch, #not, #p]
 * </ul>
 * 
 * Only valid in pattern.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 *
 */
public class NotMatchExpr extends Construction
{
    // Constructor 
    
    public NotMatchExpr(Term...args)
    {
        super(args);
    }
    
    // Overrides
    
    @Override
    public boolean match(Term term, MatchingContext context)
    {
        if (args[1].match(term, context))
            return false;
        
        return getArity() == 2 || args[2].match(term, context);
    }
    
    @Override
    public Term contract(MatchingContext context)
    { 
        throw new AssertionError("Not a contractum");
    }

}
