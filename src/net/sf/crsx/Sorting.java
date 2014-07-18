/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx;

import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.util.Pair;

/**
 * Describes the sorts of constructors in a system.
 *
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Sorting.java,v 3.1 2013/10/17 16:51:45 krisrose Exp $
 */
public interface Sorting
{
	/** Name of dummy wrapper for sort variables [sic]. */
	public static final String SORT_VAR = "$sort";
	
	/** All the declared sort names. */
	public Iterable<String> sorts();
	
	/**
	 * Get the sort of the constructor, or null if none.
	 * @param constructor to investigate the sort of
	 */
	public Term sortOf(String constructor);

	/**
	 * The list of parameters used by forms for the sort.
	 * @param sort to get parameters of
	 * @return sort parameter list or null if no such sort
	 */
	public List<Variable> sortParams(String sort);
	
	/**
	 * Obtain all the forms a constructor is declared with (if constructor
	 * is not an overloaded symbol, this is just 1 pair of &lt;sort,form&gt;, if it
	 * is undeclared this returns an empty set.
	 * Note that the returned forms may contain $sort[] wrappers that should be ignored.
	 * @param constructor the constructor we're interested in
	 * @return a set of &lt;sort,form&gt; pairs
	 */
	public Set<Pair<Term,Term>> formsOf(String constructor);

	/**
	 * Return the form of a particular constructor of a particular sort.
	 * @param sort to get form of
	 * @param constructor to get the form of
	 * @return the form or null if no such form exists; if the form contains sort parameters then these are the same returned by
	 * 	{@link #sortParams(String)}
	 */
	public Term formOf(String sort, String constructor);

	/**
	 * Return the set of data symbols that are members of a specific sort constructor.
	 * @param sort name of sort
	 */
	public Set<String> sortDataSymbols(String sort);
	
	/**
	 * Return whether there is a sort constructor by the given name.
	 * @param sort name of sort
	 */
	public boolean isSortConstructor(String sort);
	
	/**
	 * Return whether the sort permits the use of first-class variables.
	 * @param sort name of sort
	 */
	public boolean sortAllowsVariables(String sort);
	
	/** Sorts where all data terms of the sort are always closed (have no free variables). */
	public Set<String> sortsWithClosedData();
	
	/** Whether the constructor is only allowed as a function. */
	public boolean isFunction(String constructor);

	/** Whether the constructor is only allowed as a data constructor. */
	public boolean isData(String constructor);

	/** Query the names of all constructors which have been declared. */
    public Set<String> getSortedConstructors();
    
    /** Retrieve non-alias  equivalent of sort. If sort has no alias it is returned unchanged. */
    public String unalias(String sort);
    
	/**
	 * If the given sort should come with a sort set, returns the corresponding
	 * sort set, otherwise returns null.
	 */
	public Map<String,Term> sortsetFor(String sort);
}
