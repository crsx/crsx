/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * <a href="http://en.wikipedia.org/wiki/Partially_ordered_set">Partial order</a>.
 * 
 * A <em>partial order</em> is a binary relation "≤" over a set P which is reflexive, antisymmetric, and transitive,
 * i.e., for all a, b, and c in P, we have that:
 * <ul>
 * <li>a ≤ a (reflexivity);
 * <li>if a ≤ b and b ≤ a then a = b (antisymmetry);
 * <li>if a ≤ b and b ≤ c then a ≤ c (transitivity).
 * </ul>
 * The ≤ operation is implemented by {@link #precedes(PartialOrder)} and = must be implemented by {@link #equals(Object)}.
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
interface PartialOrder<P extends PartialOrder<P>>
{
    /** Whether this value precedes (by ≤) the other value. */
    boolean precedes(P other);
}
