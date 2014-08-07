/* Copyright © 2007, 2008 IBM Corporation. */

package net.sf.crsx;

import net.sf.crsx.util.ExtensibleMap;

/**
 * Extension of terms to support use as contractum (rule right hand side).
 * <p>
 * Contracting with a valuation consists of building a copy of the contraction term,
 * except that a {@link Valuation} specifies how some specific subterm forms are dealt with differently,
 * as follows:
 * 
 * <ul>
 * 
 * <li>Variables are renamed, if defined.
 * 
 * <li>Meta-applications are substituted, if defined, with the {@link Substitute} obtained by {@link Valuation#getSubstitute(String)},
 *      where the meta-application arguments are inserted for the corresponding substitution variables.<p>
 * 
 * <li>Special "evaluation terms" of the form $[...] (with {@link Constructor#symbol()} == {@link CRS#EVAL_SYMBOL})
 *      are not copied but instead the result term is computed depending on the precise {@link Primitive} form of the term.
 * 
 * </ul>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Contractum.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Contractum extends Term
{
    /**
     * Contract this fragment of contractum (rule right hand side) to sink.
     * 
     * @param sink to send the fragment to
     * @param valuation from successful matching of left-hand side (contains the full contractum of which this is a fragment)
     * @param renamings already decided mappings of variables for the contraction (maps variables in contractum to variables to use in result of contraction)
     * @return the sink after reception of the contracted subterm
     */
    Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings);
}
