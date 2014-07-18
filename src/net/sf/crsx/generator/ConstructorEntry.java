/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

/**
 * Stores useful information about constructors
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ConstructorEntry
{
    // State

    /** Constructor unique id */
    final private int id;

    /** Constructor symbol */
    final private String symbol;

    /** Constructor arity */
    final private int arity;
    
    /** Whether this is a data construction (no rule) */
    private boolean isDataConstruction;

    // Constructor

    ConstructorEntry(int id, String symbol, int arity)
    {
        this.symbol = symbol;
        this.arity = arity;
        this.id = id;
        this.setDataConstruction(true);  
    }

    // Overrides

    /** Gets symbol */
    public String getSymbol()
    {
        return symbol;
    }

    /** Gets arity */
    public int getArity()
    {
        return arity;
    }

    /** Gets ID */
    public int getId()
    {
        return id;
    }
    
    /**
     * @param isDataConstruction the isDataConstruction to set
     */
    public void setDataConstruction(boolean isDataConstruction)
    {
        this.isDataConstruction = isDataConstruction;
    }

    /**
     * @return the isDataConstruction
     */
    public boolean isDataConstruction()
    {
        return isDataConstruction;
    }
    
    @Override
    public boolean equals(Object obj)
    {
        return obj instanceof ConstructorEntry
                && ((ConstructorEntry) obj).getSymbol().equals(getSymbol()) && ((ConstructorEntry) obj).getArity() == getArity();
    }

    @Override
    public int hashCode()
    {
        return getSymbol().hashCode() | getArity();
    }


}