/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Variable. 
 * 
 * Each instance defines a unique variable; v1 == v2 means that v1 and v2 are the same variable.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class Variable 
{
    // State
 
    /** Suggested variable name */
    final protected String name;

    // Constructors

    public Variable(String name)
    {
        this.name = name;
    }
    
    // Methods
    
    /**
     * @return variable suggested name. Might be null
     */
    public String getName()
    {
        return name;
    }
    
    // Debugging
    
    public String toString()
    {
        return name;
    }

}
