/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

/**
 * Key based on symbol and arity
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class SymbolArity
{
    // State
    
    public String symbol;
    public int arity;

    // Constructors
    
    public SymbolArity(String symbol, int arity)
    {
        this.symbol = symbol;
        this.arity = arity;
    }
    
    // Overrides
    
    @Override
    public boolean equals(Object obj)
    {
        return obj instanceof SymbolArity
                && ((SymbolArity) obj).symbol.equals(symbol) && ((SymbolArity) obj).arity == arity;
    }

    @Override
    public int hashCode()
    {
        return symbol.hashCode() | arity;
    }
}
