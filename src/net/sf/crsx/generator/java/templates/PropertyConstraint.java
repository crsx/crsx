/* Copyright © 2009 IBM Corporation. */
package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /*]]*/;


/**
 * Base class for property constraint
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public abstract class PropertyConstraint
{

	/**
	 * Apply property constraint occurring in a pattern
	 * @param properties list of properties attached to the term being matched.
	 * @param context
	 * @return
	 */
    public abstract boolean match(Properties properties, MatchingContext context);
   
    /**
     * Apply property constraint occurring in a contractum
     * @param properties
     * @param context
     */
    public abstract void contract(Properties properties, MatchingContext context);

}
