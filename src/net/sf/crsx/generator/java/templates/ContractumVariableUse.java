/* Copyright © 2009 IBM Corporation. */
package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Variable use occurring in contractum
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ContractumVariableUse extends VariableUse
{
    // State
    
    /** Position of this variable use in the contractum */
    final protected int position;
 
    // Constructor
    
    protected ContractumVariableUse(int position)
    {
        super(null);
        
        this.position = position;
    }

    // Overrides
    
    @Override
    public void normalize(Rule[] rules, NativeSink sink)
    {
        throw new AssertionError("Not a term-to-rewrite");
    }

    @Override
    protected void normalizeSubs(Rule[] rules, NativeSink sink)
    {
        throw new AssertionError("Not a term-to-rewrite");
    }
    
    @Override
    public Term contract(MatchingContext context)
    {
        return new VariableUse(context.getVarSubstitute(position));
    }

}
