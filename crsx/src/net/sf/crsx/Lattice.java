/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * <a href="http://en.wikipedia.org/wiki/Lattice_(order)">Lattice order</a>.
 * 
 * A {@link PartialOrder} (L, ≤) is a <em>lattice</em> is it is both an upper and lower semilattice.
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @param <L> the implementation class itself (to make operations binary)
 */
interface Lattice<L extends Lattice<L>> extends JoinSemiLattice<L>, MeetSemiLattice<L>
{}
