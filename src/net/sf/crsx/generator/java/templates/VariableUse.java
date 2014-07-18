/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Variable use.
 * 
 * See subclasses for variable use in pattern and contractum.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class VariableUse extends Term
{
    // State

    /** Variable being used */
    final protected Variable var;
 
    // Constructors

    /** Construct a variable use appearing in the term to rewrite */
    protected VariableUse(Variable var)
    {
        this.var = var;
    }
 
    // Overrides
    
    @Override
    final public int getKind()
    {
        return VARIABLE_KIND;
    }

    @Override
    final public int getArity()
    { 
        return 0;
    }
    
    @Override
    public void normalize(Rule[] rules, NativeSink sink)
    {
        // TODO: check for rules....

        normalizeSubs(rules, sink);
    }

    @Override
    protected void normalizeSubs(Rule[] rules, NativeSink sink)
    {
        super.normalizeSubs(rules, sink);
        sink.use(this.var);
    }

    @Override
    public Term contract(MatchingContext context)
    {
        throw new AssertionError("Not a contractum");
    }

    @Override
    public boolean match(Term term, MatchingContext context)
    {
        throw new AssertionError("Not a pattern");
    }
}
