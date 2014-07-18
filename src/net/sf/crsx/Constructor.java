/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

import java.io.IOException;
import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;

import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.StackedMap;

/**
 * Constructor for construction CRS terms.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Constructor.java,v 3.3 2013/12/05 03:28:27 krisrose Exp $
 */
public interface Constructor extends PropertiesHolder
{
	/**
	 * The principal "function symbol" of this constructor.
	 * Does not completely represent the constructor but
	 * it is guaranteed that constructors with different symbols are different.
	 * Hence should <em>not</em> be used as the basis for equality and matching
	 * but <em>can</em> be used to fulfill the {@link Object#hashCode()} contract.
	 */
	String symbol();
	
	/**
	 * The literal sort of this literal constructor, or null for non-literals.
	 */
	String literalSort();

    /**
     * The "natural object" corresponding to the constructor.
     * If the constructor was created with {@link Maker#makeConstructor(Object)} then that object is returned,
     * in other cases may be null.
     */
    Object object();
    
	/**
	 * Whether this constructor (used in a {@link Pattern}) matches the other constructor (used in the redex).
	 * <p>
	 * TODO: Describe precisely what constructor matching means...
	 * <p>
	 * For standard terms this can be implemented using {@link #equals(Object)}.
	 * 
	 * @param match in progress
	 * @param other constructor to match against - must be normalized
     * @param bound variables of redex that are matched from bound variables in pattern
	 * @param contractionCount occurrence count for each meta-application (-1 for unknown; may be null if promiscuous true)
	 * @param promiscuous whether the matched term needs to be duplicateable
	 * @param once variables that are only permitted once in this subterm (not mutated)
	 * @param onceSeen variables in once that have already been seen (only touched when once not empty)
	 */
	boolean match(Match match, Constructor other, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen);

    /**
     * Return whether all subterms embedded in this constructor obey the restrictions implied by the arguments.
     * @param forbidden variables that are not allowed (not mutated)
     * @param once variables that are allowed exactly once (not mutated)
     * @param onceSeen variables from once that have been seen so are now forbidden (mutated if once not empty)
     * @param promiscuous whether the matched term needs to be duplicateable
     * @param bound bound variables
     */
    boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound);

    /**
     * Add all free variables in this term term to the set, except those that are bound.
     * @param set where free variables will be inserted (using the destructive {@link Set#add(Object)}) 
     * @param bound variables (that should not be considered free)
     * @param includemetaapps TODO
     * @param base TODO
     */
    void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base);

	/**
	 * Copy this constructor as part of a subterm subject to substitution.
	 * (Invoked by {@link Term#subsubstitute(Sink, Valuation, ExtensibleMap, ExtensibleMap, ExtensibleMap, Set)}.)
	 * @param maker for term construction
	 * @param valuation of original match (for nested contractions)
	 * @param renamings in effect in contractum (for nested contractions)
	 * @param substitution maps the variables in the pattern to the corresponding fragments of the contractum
	 * @param bound variables locally in this term
	 * @param possible variables that can still occur in redex needing substitution
	 */
	Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable,Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable,Variable> bound, Set<Variable> possible);

    /**
     * Visit all subterms that are contained <em>within</em> the constructor itself.
     * (For usual simple constructors this is a no-op.)
     * @param visitor to use
     * @param bound variables from context
     * @throws CRSException 
     */
    void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException;

    /**
     * Constructor unification method...NOT IMPLEMENTED.
     * 
     * @param that the constructor to unify with
     * @return the unification constructor, or null if unification fails.
     */
    public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime);
    
	/**
	 * Build copy of the constructor.
	 * (For standard terms this can be implemented by returning <code>this</code>,
	 * for non-constant constructors this probably involves cloning.)
	 * @param renamings variables in the context
	 */
	Constructor copy(ExtensibleMap<Variable,Variable> renamings);

	/**
	 * Result of contracting this constructor (used in a {@link Contractum}).
	 * (For usual simple constructors this can return itself.)
	 *  
	 * @param valuation with substitutes (from pattern to term)
	 * @param renamings with renamings mandated by context (from contractum to matched term)
	 */
	Constructor contract(Valuation valuation, ExtensibleMap<Variable,Variable> renamings);

	/**
	 * Normalize the constructor (destructively).
	 * @param crs rewrite system that is requesting the normalization
	 * @throws CRSException if use of crs throws it
	 */
	void normalize(CRS crs) throws CRSException;
	
	/**
	 * Write the constructor in external form suitable for reparsing.
	 * @param writer to write to
	 * @param used bound variable names
	 * @param depth remaining sublevels to print (or -1 for all)
	 * @param full force printing to use full expanded syntax (so no abbreviated syntax)
	 * @param namedProps whether named properties are printed
	 * @param variableProps whether variable properties are printed
	 * @param omitProps specific variable properties to omit
	 * @throws IOException
	 */
	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException;
	
	/**
	 * Whether this constructor is identical to that constructor.
	 */
	boolean equals(Object that);
	
	/**
	 * Constructors obey the {@link Object#equals(Object)}/{@link Object#hashCode()} contract.
	 */
	int hashCode();

	/**
	 * The 'base' constructor to use for hash lookups.
	 * For delegates should follow the indirection; also must be idempotent.
	 */
	Constructor baseConstructor();
	
	/**
	 * Generate code for invocation of {@link Sink#start(Constructor)}.
	 * Notice that the code may be left at a higher nesting level than it currently has.
	 * @param code to append the Java source text to
	 * @param sinkName name of sink to use
	 * @param variable2java maps varables to their Java name
	 */
	void javaInvokeStart(SourceBuilder code, String sinkName, Map<Variable, String> variable2java);

	/**
	 * Extend the given base path with all the possible subterms of this term as provided by the constructor.
	 * @param base path to this term
	 * @return paths to all the subterms
	 */
	SortedSet<Path> paths(Path base);
}
