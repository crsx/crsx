/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;



/**
 * Construction occurring in pattern
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class PatternConstruction extends PropertyConstraintConstruction
{
    // State

    /** Construction unique ID (-1, 0, 1, 2 for data construction) */
    final protected int id;
    
    /** First position in {@link MatchingContext} for binders. -1 if there is no binders. Only valid for pattern. */
    final protected int bindersStartingPosition;

    // Constructor

    /** Construct a pattern */
    protected PatternConstruction(int id, int bindersStartingPosition, PropertyConstraint[] constraints, Term... args)
    {
        super(constraints, args);

        this.id = id;
        this.bindersStartingPosition = bindersStartingPosition;  
    }

    // Overrides

    @Override
    public boolean match(Term term, MatchingContext context)
    {
        if (term instanceof FunctionConstruction)
        {
            final FunctionConstruction otherCons = (FunctionConstruction) term;

            if (id != otherCons.getID())
                return false;

          
            // First: Check arguments
            if (args != null)
            {
                for (int i = 0; i < args.length; i++)
                    if (!args[i].match(otherCons.args[i], context))
                        return false;
            }

            // Then: check properties
            if (!matchConstraints(term.getProperties(), context))
            	return false;
            

            // The term might matches: check subbinders count and set binders position in MatchingContext to be used during contraction
            if (bindersStartingPosition != -1)
            {
                int pos = bindersStartingPosition;
                final Variable[][] subbinders = otherCons.getBinders();
                for (int i = 0; i < subbinders.length; i++)
                {
                    final Variable[] binders = subbinders[i];
                    if (binders != null)
                    {
                        for (int j = 0; j < binders.length; j++)
                            if (binders[j] != null)
                                context.setVarSubstitute(pos++, binders[j]);
                    }
                }
            }

            return true;
        }
        return false;
    }


	@Override
    public Term contract(MatchingContext context)
    {
        throw new AssertionError("Not a contractum");
    }

}
