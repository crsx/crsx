/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * <a href="http://en.wikipedia.org/wiki/Lattice_(order)">Lattice order</a>.
 * 
 * A {@link PartialOrder} (L, ≤) is a <em>meet-semilattice</em> or <em>lower semilattice</em> if it satisfies
 * <strong>Existence of binary meets:</strong>
 * For any two elements a and b of L, the set {a, b} has a meet, a∧b (also known as greatest lower bound (glb) or infimum).
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @param <L> the implementation class itself (to make operations binary)
 */
interface MeetSemiLattice<L extends MeetSemiLattice<L>> extends PartialOrder<L>
{
    /** Return the meet of this and the other member of the lattice. */
    L meet(L other);
}
