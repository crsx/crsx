/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Error expression of the following form:
 * <ul>
 * <li>$[Error]
 * <li>$[Error, Constant]
 * <li>$[Error, Constant, ExceptionClassName (constant)]
 * </ul>
 * 
 * Can only appear in contractum
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ErrorExpr extends PropertyConstraintConstruction
{
    // Constructor

    /** Construct an error expr */
    public ErrorExpr(PropertyConstraint[] constraints, Term... args)
    {
        super(constraints, args);
    }

    // Overrides

    @Override
    public Term contract(MatchingContext context)
    {
        switch (args.length)
        {
            case 2 :
                throw new RuntimeException(args[1].getSymbol());
            case 3 :
                try
                {
                    Class<?> clazz = Class.forName(args[2].getSymbol());
                    java.lang.reflect.Constructor<?> c = clazz.getConstructor(String.class);
                    throw (RuntimeException) c.newInstance(args[1].getSymbol());
                }
                catch (Exception e)
                {
                    throw new RuntimeException(e);
                }
            case 1 :
            default :
                throw new RuntimeException();

        }
    }

    @Override
    public boolean match(Term term, MatchingContext context)
    {
        throw new AssertionError("Not a pattern");
    }

}
