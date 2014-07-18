/* Copyright © 2009 IBM Corporation. */
package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Various static utilities
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class Utils
{
    /** 
     * Is the given term a constant, ie a construction without arguments. 
     */
    final public static boolean isConstant(Term term)
    {
        return term.getKind() == Term.CONSTRUCTION_KIND && term.getArity() == 0;
    }
     
    /** Whether the given term is $Cons */
    public static boolean isCons(Term term)
    {
        return term instanceof FunctionConstruction && ((FunctionConstruction) term).id == 0;
    }

    /** Whether the given term is $Nil */
    public static boolean isNil(Term term)
    {
        return term instanceof FunctionConstruction && ((FunctionConstruction) term).id == 1;
    }
    
    /** 
     * Whether the given id corresponds to a data construction
     */
    public static boolean isDataConstruction(int id)
    {
        return id < 3;
    }
}
