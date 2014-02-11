/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * <a href="http://en.wikipedia.org/wiki/Lattice_(order)">Lattice order</a>.
 * 
 * A {@link PartialOrder} (L, ≤) is a <em>join-semilattice</em> (or <em>upper semilattice</em>)  if it satisfies
 * <strong>Existence of binary joins:</strong>
 * For any two elements a and b of L, the set {a, b} has a join, a∨b (also known as least upper bound (lub) or supremum).
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @param <L> the implementation class itself (to make operations binary)
 */
interface JoinSemiLattice<L extends JoinSemiLattice<L>> extends PartialOrder<L>
{
    /** Return the join of this and the other member of the lattice. */
    L join(L other);
}
