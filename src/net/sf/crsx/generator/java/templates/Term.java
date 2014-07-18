/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Base class for generated terms.
 *  
 * There are 3 {@link #getKind() kinds} of terms:
 * <ul>
 * <li>Construction: see {@link FunctionConstruction}
 * <li>Meta-application: see {@link MetaApplicationReuse}
 * <li>Variable use: see {@link VariableUse}
 * </ul> 
 *  
 * In addition, a term can occur either in a pattern, a contractum, or a term to rewrite. This table summarizes 
 * what operations are allowed for the occurrence type:
 * <table border="1">
 * <tr>
 * <th></th>
 * <th>{@link #normalize(Rule[], NativeSink, Map<String, Term>, Map<Variable, Term>) Normalization} </th>
 * <th>{@link #match(Term, MatchingContext) Matching}</th>
 * <th>{@link #contract(MatchingContext) Contraction}</th>
 * </tr>
 * <tr>
 * <th>Term</th>
 * <th>X</th>
 * <th></th>
 * <th></th>
 * </tr><tr>
 * <th>Pattern</th>
 * <th></th>
 * <th>X</th>
 * <th></th>
 * </tr><tr>
 * <th>Contractum</th>
 * <th></th>
 * <th></th>
 * <th>X</th>
 * </tr>
 * </table>
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public abstract class Term
{
	// Constants

	/** Term kinds */
	final public static int CONSTRUCTION_KIND = 0;
	final public static int VARIABLE_KIND = 1;
	final public static int META_APP_KIND = 2;

	// Constructors

	protected Term()
	{}

	// Methods 

	/** Gets kind of term */
	public abstract int getKind();

	/**
	 * The arity (number of subterms) of constructor and meta-application terms.
	 * Always 0 for variable occurrence terms.
	 */
	public abstract int getArity();

	/** 
	 * Gets term arguments
	 * @return read-only list of argument, or null if none. Always null for {@link VariableUse}
	 */
	public Term[] getArgs()
	{
		return null;
	}

	// Methods for construction

	/** 
	 * Gets the construction symbol.
	 * @return a non-null symbol
	 * @throws AssertionError if called on something else than a construction 
	 */
	public String getSymbol()
	{
		return null;
	}

	/** 
	 * Gets the variable bounds by the construction
	 * @throws AssertionError if called on something else than a construction
	 */
	public Variable[][] getBinders()
	{
		return null;
	}

	/** 
	 * Gets the term properties
	 */
	public Properties getProperties()
	{
		return null;
	}

	/** 
	 * Sets the term properties
	 */
	public void setProperties(Properties properties)
	{}

	// Operations on term to rewrite

	/**
	 * Normalizes this term according to the list of rules.
	 * @param rules  
	 * @param sink to output the normalization
	 * @throws AssertionError whenever this method is called on a pattern or contractum.
	 */
	public void normalize(Rule[] rules, NativeSink sink)
	{}

	/**
	 * Normalizes the sub terms only.
	 * @param rules  
	 * @param sink
	 * @throws AssertionError whenever this method is called on a pattern or contractum.
	 */
	protected void normalizeSubs(Rule[] rules, NativeSink sink)
	{}

	/**
	 * Normalizes this term according to the list of rules.
	 * @param rules   
	 * @return the normalized term
	 * @throws AssertionError whenever this method is called on a pattern or contractum.
	 */
	public Term normalize(Rule[] rules)
	{
		return this;
	}

	// Operations on pattern

	/**
	 * Try to match this pattern to the given term
	 * @return true if the term matches. In this case, the context contains the substitutions and variable bindings
	 * @throws AssertionError whenever this method is called on a term that is not a pattern.
	 */
	public abstract boolean match(Term term, MatchingContext context);

	// Operations on contractum

	/**
	 * Contracts this contractum using the context computed during the matching step
	 * 
	 * @param context 
	 * @return contracted term.
	 * @throws AssertionError whenever this method is called on a term that is not a contractum.
	 */
	public abstract Term contract(MatchingContext context);

}
