package net.sf.crsx.util;

import java.util.Collection;
import java.util.Set;

/**
 * Extensible but immutable ("functional") set.
 * Category of sets building on (and confoirming to) the standard {@link Set} interface but
 * <ul>
 * <li>explicitly not supporting any of the "destructive" methods from {@link Set} but rather
 * <li>add several <em>extension</em> methods for building new sets with more elements.
 * </ul>
 *  
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: ExtensibleSet.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public interface ExtensibleSet<Value> extends Set<Value>
{
	/**
	 * Create new set which extends this one with a single element.
	 * @param value to add
	 * @return new map (original mapping is unchanged)
	 */
	public ExtensibleSet<Value> extend(Value value);

	/**
	 * Create new map which extends this one with all values in an array.
	 * @param values to add
	 * @return new map (original mapping is unchanged)
	 */
	public ExtensibleSet<Value> extend(Value[] values);

	/**
	 * Create new variable map which extends this one with all elements of collection.
	 * @param collection with values to add
	 * @return new map (original mapping is unchanged)
	 */
	public ExtensibleSet<Value> extend(Collection<Value> collection);
}
