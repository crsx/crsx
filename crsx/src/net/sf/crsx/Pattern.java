/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.util.ExtensibleSet;

/**
 * Extension of term to behave as pattern (rule left hand side).
 * <p>
 * Matching a pattern against a term accumulates a {@link Valuation} 
 * by comparing each subterm in the pattern with the corresponding part of the term,
 * adding to the valuation as follows:
 * 
 * <ul>
 * 
 * <li>A construction pattern (not of the form $[...] described below) matches a construction term ...
 *      TODO
 *      and only when it can be recorded in the {@link Valuation} without conflict.
 * 
 * <li>A free variable pattern only matches a free variable term,
 *      and only when it can be recorded as the {@link Valuation} without conflict.
 * 
 * <li>A meta-application pattern (where the arguments must be distinct bound variables)
 *      matches any term provided two conditions are satisfied ... TODO
 * 
 * <li>Some special property forms are supported that are not, in fact, legal terms:
 *      <ul>
 *      <li>{var : pattern}#metavar
 *      <li>{Constant : pattern}#metavar
 *      <li>{#propertymetavar}#metavar
 *      <ul>
 *      These ... TODO
 * 
 * <li>Special "evaluation patterns" of the form $[...] (with {@link Constructor#symbol()} == {@link CRS#EVAL_SYMBOL})
 *      are not copied but instead the result term is computed depending on the precise form of the term:
 * <p>
 * <table border="1">
 * 
 * <tr><td>$[C, <i>c</i>, <i>s</i><sub>opt</sub>]</td><td>matches construction with <i>c</i> as constructor and arguments (defaults to ())<em>s</em></td></tr>
 * <tr><td>$[M, <i>c</i>, <i>s</i><sub>opt</sub>]</td><td>matches meta-application with <i>c</i> as meta-variable name and arguments <i>s</i> (defaults to ())</td></tr>
 * <tr><td>$[V, <i>c</i>]</td><td>matches <em>unique and free</em> variable with name <i>c</i></td></tr>
 * 
 * <tr><td>$[Match, <i>p</i><sub>1</sub>, <i>p</i><sub>2</sub>]</td><td>matches as <i>p</i><sub>2</sub> but only when it also matches <i>p</i><sub>1</sub></td></tr>
 * <tr><td>$[NotMatch, <i>p</i><sub>1</sub>, <i>p</i><sub>2</sub>]</td><td>matches as <i>p</i><sub>2</sub> but only when it does not match <i>p</i><sub>1</sub></td></tr>
 * <tr><td>$[MatchRegex, <i>c</i>, <i>p</i>]</td><td>matches as <i>p</i> but only for constants that fit the regular expression <i>c</i></td></tr>
 * <tr><td>$[IsInteger, <i>p</i>]</td><td>matches constants that both fit the regular expression "[-+]*[0-9]+" and also match <i>p</i></td></tr>
 * 
 * <tr><td>$[NamedProperty, <i>c</i>, <i>p</i><sub>1</sub>, <i>p</i><sub>2</sub>]</td><td>matches as property association {<i>c</i>:<i>p</i><sub>1</sub>}<i>p</i><sub>2</sub></td></tr>
 * <tr><td>$[NotNamedProperty, <i>c</i>, <i>p</i>]</td><td>matches as property exclusion {&not;<i>c</i>}<i>p</i></td></tr>
 * <tr><td>$[VariableProperty, <i>c</i>, <i>p</i><sub>1</sub>, <i>p</i><sub>2</sub>]</td><td>matches as property association {<i>v</i>:<i>p</i><sub>1</sub>}<i>p</i><sub>2</sub> with <i>v</i> a variable named as <i>c</i></td></tr>
 * <tr><td>$[NotVariableProperty, <i>c</i>, <i>p</i>]</td><td>matches as property exclusion {&not;<i>v</i>}<i>p</i> with <i>v</i> a variable named as <i>c</i></td></tr>
 * <tr><td>$[CollectsProperties, <i>c</i>, <i>p</i>]</td><td>matches as property collection {<i>c</i>}<i>p</i></td></tr>
 * 
 * <tr><td>$[If, <i>c</i>, <i>p</i><sub>1</sub>, <i>p</i><sub>2</sub>]</td><td>if <i>c</i> is True then matches as <i>p</i><sub>1</sub>otherwise as <i>p</i><sub>2</sub></td></tr>
 * <tr><td>$[Env, <i>c</i>, <i>p</i><sub>opt</sub>]</td><td>matches as value of environment variable <i>c</i> falling back to <i>p</i><sub>opt</sub></td></tr>
 * 
 * <tr><td>$[Error, <i>c</i><sub>1</sub>, <i>c</i><sub>2</sub><sub>opt</sub>]</td><td>emits the error message <i>c</i><sub>1</sub> using the exception <i>c</i><sub>2</sub></td></tr>
 * <tr><td>$[Trace, <i>t</i>, <i>p</i>]</td><td><i>t</i> is echoed and the result is the contraction of <i>p</i></td></tr>
 * </table>
 * <p>
 *      where
 *      <ul>
 *      <li><i>t</i> stands for an arbitrary term,
 *      <li><i>p</i> stands for an arbitrary term,
 *      <li><i>c</i> stands for an arbitrary constant (nullary construction),
 *      <li><em>i</em> stands for an integer constant, and
 *      <li><i>s</i> stands for a sequence (right-recursive use of {@link CRS#CONS_SYMBOL} terminated with {@link CRS#NIL_SYMBOL}).
 *      </ul>
 * 
 * </ul>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Pattern.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Pattern extends Term
{
	/**
	 * Whether this pattern matches term.
	 * <p>
	 * TODO: Describe precise semantics of match, including special match evaluation
	 * (currently in {@link GenericEvaluator}).
	 * 
	 * @param match meta-substitution so far mapping meta-application and free variable patterns
	 * 		in this pattern to fragments of the term, updated to reflect result of unification when successful
	 * @param redex to match against
     * @param bound variables of redex that are matched from bound variables in pattern
	 * @param contractionCount occurrence count for each meta-application (-1 for unknown; may be null if promiscuous true)
	 * @param promiscuous whether the matched term needs to be duplicateable
	 * @param once variables that are only permitted once in this subterm (not mutated)
	 * @param onceSeen variables in once that have already been seen (only mutated when once not empty)
     */
	boolean match(Match match, Term redex, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen);
	
    /**
     * Unify this and that pattern syntactically, if possible.
     * 
     * This method assumes that the parameter pattern is a full pattern without context, and that the 
     * target object (this) is (possibly) a subpattern of a bigger pattern, and hence has a context. 
     * 
     * @param that the pattern to unify this pattern with.
     * @param contextvars the variables already bound in the context of this pattern.
     * @return the resulting unification, or null if unification fails.
     * @throws CRSException if unification cannot be determined.
     */
    Unification unify(Pattern that, Set<Variable> contextvars) throws CRSException;
    
    /**
     * Return the set of metavariables occurring in this pattern
     * 
     * @return a set of metavariables.
     */
    //TODO: Consider introducing MetaVariable interface and returning Set<MetaVariable> instead.
    Set<String> mvars();
}
