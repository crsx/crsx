/* Copyright © 2009 IBM Corporation. */
package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Fresh variable occurring in contractum
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ContractumFreshVariableUse extends VariableUse
{
    // State

    /** Suggested variable name */
    final protected String name;
    
    /** Position in {@link MatchingContext} */
    final protected int position;
 
    // Constructor
    
    protected ContractumFreshVariableUse(String name, int position)
    {
        super(null);
        
        this.name = name;
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
        final Variable var = new Variable(name);
        context.setVarSubstitute(position, var);
        return new VariableUse(var);
    }

}
