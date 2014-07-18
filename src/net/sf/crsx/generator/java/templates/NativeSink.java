/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /*]]*/;

/**
 * 
 * 
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public abstract class NativeSink
{
    public abstract void start(int id);
    
    public abstract void end(int id);
    
    public abstract void binds(Variable[] binders);
    
    public abstract void use(Variable name);
}
