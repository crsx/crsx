/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Property of the form &not; var
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class NotVariableProperty extends PropertyConstraint
{
    // State

    /** Variable position in {@link MatchingContext} */
    final protected int varPosition;

    // Constructors

    public NotVariableProperty(int varPosition)
    {
        this.varPosition = varPosition;
    }

    // Overrides
    
    @Override
    public boolean match(Properties properties, MatchingContext context)
    {
        //return GeneratedCRSX.varProps.get(context.getVarSubstitutes(varPosition)) == null;

    	throw new UnsupportedOperationException();
    }

    @Override
    public void contract(Properties properties, MatchingContext context)
    {
    	throw new UnsupportedOperationException();
    }

}
