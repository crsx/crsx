/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

import net.sf.crsx.util.ExtensibleMap;

/**
 * Aspect of CRS terms permitting copying the term to a {@link Sink}.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Copyable.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Copyable
{
	/**
	 * Copy the term represented by this stub to a sink, returning the sink to use for subsequent operations.
	 * <p>
	 * <b>Note:</b> This is similar to {@link Sink#copy(Copyable, boolean)} and when implementing it care is needed
	 * to avoid tight loops. Basically the rule is that {@link #copy(Sink, boolean, ExtensibleMap)} should <em>not</em>
	 * invoke {@link Sink#copy(Copyable, boolean)} on the sink argument; indeed the preferred strategy is to <em>always</em>
	 * use this method and never {@link Sink#copy(Copyable, boolean)}.
	 * 
	 * @param sink to copy to: this specific instance can no longer be used
	 * @param discard whether this Copyable instance is guaranteed to not be used any more
	 * @param renames from the context (variables already committed to sink)
	 */
	Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames);
}
