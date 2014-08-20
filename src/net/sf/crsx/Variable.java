/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * Variable in CRS term.
 * Standard equality on variables should work as expected, i.e.,
 * variables should only be {@link Object#equals(Object)}
 * if they represent the same variable instance.
 * <em>This means that {@link Variable} instances cannot be "captured".</em>
 *
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Variable.java,v 3.3 2013/11/20 05:08:17 krisrose Exp $
 */
public interface Variable extends Comparable<Variable>
{
	/**
	 * A string representing the variable.
	 * <em>Not guaranteed to parse</em> - for that use {@link net.sf.crsx.util.Util#safeVariableName(Variable, java.util.Map, boolean, boolean)}.
	 * <em>Not necessarily unique</em> - only {@link #equals(Object)} is guaranteed to test variable equality.
	 */
	String name();
	
    /**
     * Whether the variable permits more than occurrence.
     */
    boolean promiscuous();

    /**
     * Whether the variable blocks the term reduction.
     */
    boolean blocking();
    
    /**
     * Whether the variable occurs only at the same level it is bound.
     */
    boolean shallow();
    
	/**
	 * Set the name representing the variable.
	 * @param name some string to use for the name - does not need to be unique
	 */
	void setName(String name);
}
