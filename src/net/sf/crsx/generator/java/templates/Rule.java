/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;

/**
 * CRSX Rule.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class Rule
{
    // State
    
    /** Contractum */
    final protected Term contractum;
    
    /** Pattern */
    final protected Term pattern;
    
    // Constructors
    
    Rule(Term pattern, Term contractum)
    {
        this.contractum = contractum;
        this.pattern = pattern;
    }
    
    // Methods
    
    /** Returns the rule pattern */
    public Term getPattern()
    {
        return pattern;
    }
    
    /** Returns the rule contractum */
    public Term getContractum()
    {
        return contractum;
    }
    
    /** 
     * Tells whether the arguments of the top constructor must be normalize before applying this rule.
     * 
     * @param id
     * @return The maximum normalization depth for each argument. 
     */
    public int[] getArgNormalizationFlags(int id)
    {
        return null;
    } 
}
