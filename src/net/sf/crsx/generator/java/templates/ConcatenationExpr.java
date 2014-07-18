/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /* ]] */;


/**
 * Concatenation of the form $[:, c1, c2, ...]
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ConcatenationExpr extends PropertyConstraintConstruction
{

    // Constructors

    /** Construct a concatenation expr */
    public ConcatenationExpr(PropertyConstraint[] constraints, Term... args)
    {
        super(constraints, args);
    }

    // Overrides

    @Override
    public Term contract(MatchingContext context)
    {
        StringBuilder builder = new StringBuilder();

        for (int i = 1; i < args.length; i++)
        {
            Term c = args[i].contract(context);
            if (!Utils.isConstant(c))
                throw new RuntimeException("Concatenation arguments ($[:, ...]) must be constants");

            builder.append(c.getSymbol());
        }

        return Dictionary.SINGLETON.createConstructor(builder.toString(), null, null, (Term[]) null);
    }

    @Override
    public boolean match(Term term, MatchingContext context)
    {
        throw new UnsupportedOperationException();
    }

}
