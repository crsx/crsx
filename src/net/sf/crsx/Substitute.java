/* Copyright © 2007, 2008 IBM Corporation. */

package net.sf.crsx;


/**
 * Substitute (what a matched meta-variable maps to).
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Substitute.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Substitute
{
	/**
	 * Whether the substitute can be extended to also match term with binders.
	 * This holds when both binders and term are identical to the ones already registered. 
	 * (It is used for non-linear patterns)
	 * @param match where the mappings from the pattern to the (full) term are kept (including this one) 
	 * @param binders of the meta-application pattern - must be the same
	 * @param term to match against - must be equal to what was previously matched.
	 */
	boolean rematch(Match match, Variable[] binders, Term term); 
	
	/**
	 * Apply the substitute to a list of contractum replacement fragments!
	 * @param valuation with result of match
	 * @param replacement terms for the substitute's binders (where further substitutions will happen)
	 * @return the result of the substitution
	 */
	Copyable substitute(Valuation valuation, Term[] replacement);
	
	/**
	 * Statically apply the substitute to a list of contractum replacement fragments!
	 * @param valuation with result of match
	 * @param replacement terms for the substitute's binders (where further substitutions will happen)
	 * @return the result of the substitution
	 */
	Copyable staticSubstitute(Valuation valuation, Term[] replacement);
	
	
	/** The bindings of this substitute. */
	Variable[] getBindings();
	
	/** The body of the substitute (where the variables of {@link #getBindings()} are bound). */
	Term getBody();
	
	/** Replace the body in the substitutie. Note: free variables cannot change. */
	void replaceBody(Term replacement);
}
