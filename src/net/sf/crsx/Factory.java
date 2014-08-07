/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

import java.io.Reader;
import java.math.BigDecimal;
import java.util.Collection;
import java.util.Set;

import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.Sinker;

/**
 * Top level factory for creating and managing {@link CRS} rewrite systems and terms.
 * Instances should have a nullary constructor to permit anonymous instantiation.
 *
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Factory.java,v 3.3 2013/12/09 05:48:40 krisrose Exp $
 */
public interface Factory<T extends Term> extends Maker, Parser, Sorting, ErrorHandler
{
	// Constants.

	/** Environment variable that, when {@link #set(String, Stub)}, makes parsing verbose. */
	public final static String PARSE_VERBOSE = "parse-verbose";

	/** Environment variable that, when {@link #set(String, Stub)}, makes parsing track locations. */
	public final static String PARSE_LOCATIONS = "parse-locations";

	/** Environmant variable with all the active parsers. */
	final public static String GRAMMAR_PROPERTY = "grammar";

	/** Option... */
	public final static String TRACE_OPTION = "trace";

	/** Option... */
	public final static String OUTPUT_OPTION = "output";

	/** Option... */
	public final static String PACKAGE_OPTION = "package";

	/** Name of environment variable with base URL for relative URLs. */
	public final static String BASE_URL = "base-url";

	/** Name of environment variable with prefix for resources. */
	public final static String RESOURCE_PREFIX = "resource-prefix";

	/** Name of environment variable that omits all properties from full form printout of standard CRSX terms. */
	public final static String OMIT_PROPERTIES= "omit-properties";

	/** Name of environment variable that omits all named properties from full form printout of standard CRSX terms. */
	public final static String OMIT_NAMED_PROPERTIES= "omit-named-properties";

	/** Name of environment variable that omits all variable properties from full form printout of standard CRSX terms. */
	public final static String OMIT_VARIABLE_PROPERTIES= "omit-variable-properties";

	/** Name of environment variable that forces full form printout (with no abbreviations) of standard CRSX terms. */
	public final static String SIMPLE_TERMS = "simple-terms";
	
	/** Maximum indentation level when printing out a term or text. */
	public final static String MAX_INDENT_LEVEL = "max-indent";

	/** Whether all errors are fatal environment variable. */
    public final static String ALL_FATAL_OPTION = "all-fatal";

	/** Environment variable that, when {@link #set(String, Stub)}, makes compilation verbose. */
	public final static String COMPILE_VERBOSE_OPTION = "compile-verbose";

	/** Environment variable that, when {@link #set(String, Stub)}, makes rewriting verbose. */
    public final static String VERBOSE_OPTION = "verbose";

	/** Environment variable that, when {@link #set(String, Stub)}, makes rewriting verbose. */
    public final static String VERBOSE_DEPTH_OPTION = "verbose-depth";
    
    /** Environment variable that, when {@link #set(String, Stub)}, makes property sets hidden while printing. */
    public final static String IGNORE_ENVIRONMENT_OPTION = "ignore-environment";

    /** Environment variable that, when {@link #set(String, Stub)}, makes $Sortify permit undeclared mono-morphic constructors. */
    public final static String ALLOW_UNDECLARED_OPTION = "allow-undeclared";

    /** Environment variable that, when {@link #set(String, Stub)}, makes $Sortify permit more than 6 anonymous rules of the same name. */
    public final static String ALLOW_UNNAMED_RULES_OPTION = "allow-unnamed-rules";

    /** Environment variable that, when {@link #set(String, Stub)}, makes $Dispatchify permit missing cases in rules. */
    public final static String ALLOW_MISSING_CASES_OPTION = "allow-missing-cases";

    /** Environment variable that, when {@link #set(String, Stub)}, makes $Sortify permit undeclared mono-morphic constructors. */
    public final static String STRICT_FUNCTIONAL = "strict-functional";

    /** Environment variable that, when {@link #set(String, Stub)}, makes $Dispatchify quietly allow overlaps. */
    public final static String ALLOW_OVERLAPS_OPTION = "allow-overlaps";
    
    /** Environment variable that, when {@link #set(String, Stub)}, makes CRSX run in parallel */
    public final static String PARALLEL_OPTION = "parallel";

	// Methods.

	/**
	 * Create builder that allows manual construction of a {@link CRS}.
	 * @return builder with no incorporated rules
	 */
	public Builder builder();

	/**
	 * Parse term.
	 * @param reader with term in default text form
	 * @param category to parse (null parses the default category, if any)
	 * @param unit to identify the source of the compilation unit
	 * @param bound variables that should be bound in the parsed term (but occurrences may use a different syntax)
	 * @param line number of the first line (1-based)
	 * @param column of the first column (1- based)
	 * @throws CRSException in case the text cannot be parsed
	 */
	public T parse(Reader reader, String category, String unit, int firstLine, int firstColumn, ExtensibleMap<String, Variable> bound) throws CRSException;

	/**
	 * Create literal string term.
	 * @param text of term
	 */
	public T literal(String text);

	/** Create literal numeric term. */
	public T literal(long i);

	/** Create literal numeric term. */
	public T literal(double d);

	/** Create literal numeric term. */
	public T literal(BigDecimal b);

	/** Create literal boolean term. */
	public T literal(boolean test);
	
	/**
	 * Materialize a term.
	 * @param thing what to materialize
	 * @param discard whether the thing is needed afterwards
	 * @return
	 */
	public T materialize(Copyable thing, boolean discard);

	/**
	 * Evaluate directive.
	 * @param directive to evaluate (see {@link Builder#load(Sink, Term)})
	 * @throws CRSException if something is wrong
	 */
	public void process(Term directive) throws CRSException;

	/**
	 * Get "writer sink"  for disposing of a result.
	 * @param appendable to append to or null to use factory default
	 * @return sink that can be appended to
	 */
	public Sink sink(Appendable appendable);

	/**
	 *  Print a message.
	 * @param text to print (possibly marked with prefix)
	 */
	public void message(String text);
	
	/** Whether named term exists in environment. */
	public boolean defined(String name);

	/** Get named term from environment, or null when undefined. */
	public Stub get(String name);

	/**
	 * Set named term in environment.
	 * @param name of environment value
	 * @param value to set it to or <b>null</b> to unset it
	 */
	public void set(String name, Stub value);

	/**
	 * Set the class used by {@link #sink(Appendable)}.
	 * @param sinkClass to use - must have a constructor that takes two arguments: a {@link Factory} and an {@link Appendable}.
	 */
	public void setSinker(Class<? extends Sinker> sinkClass);

	/**
	 * Add a new sort form (as well as the sort itself if it has not been used before).
	 * Note that the  form may contain $sort[] wrappers that should be ignored (except for holding binder type properties).
	 * @param sort the sort to add the form to
	 * @param sortParams variables denoting parameter sorts
	 * @param form new allowed shape of the sort (see {@link Sorting#formsOf(String, Constructor)})
	 * @param function whether the constructor is restricted in rules to be used as a function (true) or data symbol (false)
	 * @param override replace any existing forms for the sort rather than add it in
	 * @throws CRSException if the added sort form would introduce inconsistencies
	 */
	public void setSortForm(Term sort, Set<Variable> sortParams, Term form, boolean function, boolean override) throws CRSException;
	
	/**
	 * Make one sort an alias for another.
	 * @param name to keep
	 * @param alias to make into an alias for the named sort
	 * @throws CRSException if the given alias is already set
	 */
	public void setSortAlias(String name, String alias) throws CRSException;
	
    /**
     * Recreate all data/function markers in forms based on the provided list of patterns.
     * @param patterns defining function/data constructors
     * @param contractae with corresponding contraction terms so all used symbols are captured
     */
    //public void reform(Iterable<Pattern> patterns, Iterable<Contractum> contractae);

	/**
	 * Remove sorts (and all the associated forms).
	 * @param names of the sorts
	 */
	// public void removeSorts(Set<String> names);

	/**
	 * Check whether the given term satisfies the current sort constraints.
	 * @param prefix text for use in error messages (intended to describe the context; TODO: standardize)
	 * @param term to check
	 * @param metaSorts maintained map of meta-variables to (sort, [argForm1,...,argFormN])
	 * @param variableSorts maintained map of declared context variable sorts
	 * @param total whether all (sub)terms must be sorted
	 * @param data whether all constructions must be data constructions
	 * @throws CRSException may be thrown with an error message if the sorts are not respected
	 */
	//public void checkSorts(String prefix, Term term, final Map<String, Pair<String, Term[]>> metaSorts, final Map<Variable,String> variableSorts, final boolean total, final boolean data) throws CRSException;

	/**
	 * Add an additional grammar to use for subsequent parsing.
	 * @param classname of the new grammar
	 * @param categories to load (null means "load all")
	 * @throws CRSException if loading the grammar fails
	 */
	public void addGrammar(String classname, Collection<String> categories) throws CRSException;

	/**
	 * Check whether the indicated grammar is available in the factory with support for the indicated categories.
	 * @param classname of the grammar
	 * @param categories it should support (null means that there are no category requirements)
	 */
	public boolean hasGrammar(String classname, Collection<String> categories);
}
