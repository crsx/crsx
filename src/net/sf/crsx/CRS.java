/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

import java.io.IOException;
import java.util.Map;
import java.util.Set;


/**
 * Combinatory Reduction System (CRS) for rewriting higher-order terms and syntax.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: CRS.java,v 3.5 2013/12/18 20:16:17 villardl Exp $
 */
public interface CRS
{
    /** CRSX URI. */
    public static final String URI = "http://crsx.sourceforge.net";
    /** CRSX VERSION. */
    public static final String VERSION = "30";

    /** CRSX XML category. */
    public static final String XML = "?xml";
    
	/** Constructor name for application. */
	public final static String APPLICATION_SYMBOL = "@";
	/** Constructor name for sequences. */
	public final static String CONS_SYMBOL = "$Cons";
	/** Constructor name for sequences. */
	public final static String NIL_SYMBOL = "$Nil";
	/** Constructor name for plain truth. */
	public final static String TRUE_SYMBOL = "$True";
	/** Constructor name for plain false. */
	public final static String FALSE_SYMBOL = "$False";
	/** Constructor name for evaluation. */
	public final static String EVAL_SYMBOL = "$";
	/** Constructor name for lists. */
	public final static String LIST_SORT = "$List";
	/** Constructor name for strings. */
	public final static String STRING_SORT = "$String";
	/** Constructor name for booleans. */
	public final static String BOOLEAN_SORT = "$Boolean";
	/** Constructor name for integers. */
	public final static String NUMERIC_SORT = "$Numeric";
	/** Constructor name for $TryResult. */
	public final static String TRYRESULT_SORT = "$TryResult";
	/** Constructor name for $TrySuccess. */
	public final static String TRYSUCCESS_SYMBOL = "$TrySuccess";
	/** Constructor name for $TryFailure. */
	public final static String TRYFAILURE_SYMBOL = "$TryFailure";
	/** Constructor name for $NativeSort. */
	public final static String NATIVE_SORT = "$NativeSort";
	
	/** {@link for CRSX: Declaration*. */
	public static final String REIFY_CRSX = "CRSX";
	/** Reify constructor for Declaration:  &forall; x . Declaration. */
	public static final String REIFY_POLYMORPHIC = "POLYMORPHIC";
	/** Reify constructor for Declaration: Sort ::= Form*. */
	public static final String REIFY_DATA = "DATA";
	/** Reify constructor for Declaration: Form :: Sort. */
	public static final String REIFY_FUNCTION = "FUNCTION";
	/** Reify constructor. */
	public static final String REIFY_SORT_VARIABLE = "SORT-VARIABLE";
	/** Reify constructor. */
	public static final String REIFY_SORT_PROPERTY = "SORT-PROPERTY";
	/** Reify constructor. */
	public static final String REIFY_SORT = "SORT";
	/** Reify constructor. */
	public static final String REIFY_SORT_ALLOWS_VARIABLES = "SORT-ALLOWS-VARIABLES";
	/** Reify constructor. */
	public static final String REIFY_SORT_SET = "SORT-SET";
	/** Reify constructor. */
	public static final String REIFY_FORM = "FORM";
	/** Reify constructor. */
	public static final String REIFY_FORM_BINDER = "FORM-BINDER";
	/** Reify constructor. */
	public static final String REIFY_FORM_ARGUMENT = "FORM-ARGUMENT";

	/** Reify constructor for Declaration:  Constructor[ Option* ] : Term &rarr; Term. */
	public static final String REIFY_RULE = "RULE";
	/** Reify constructor for Option. */
	public static final String REIFY_RULE_OPTION = "OPTION";
	/** Reify constructor for NoOption. */
	public static final String REIFY_NOPTION = "NOPTION";
	
	/** Reify constructor for: PROPERTY-REF[ $String, #Term ] */
	public static final String REIFY_PROPERTY_REF = "PROPERTY-REF";
	/** Reify constructor for: PROPERTY[ #Term, #Term, #Term ] */
	public static final String REIFY_PROPERTY = "PROPERTY";
	/** Reify constructor for: PROPERTY-NOT[ #Term, #Term ] */
	public static final String REIFY_PROPERTY_NOT = "PROPERTY-NOT";
	/** Reify constructor for: CONSTRUCTION[ $String, $List[#Binder] ] */
	public static final String REIFY_CONSTRUCTION = "CONSTRUCTION";
	/** Reify constructor for: LITERAL[ $String, #PrimitiveType] */
	public static final String REIFY_LITERAL = "LITERAL";
	/** Reify constructor for: VARIABLE-USE[ #Variable ] */
	public static final String REIFY_VARIABLE_USE = "VARIABLE-USE";
	/** Reify constructor for: META-APPLICATION[ $String, $List[#MetaArgument], #Use ] */
	public static final String REIFY_META_APPLICATION = "META-APPLICATION";
	/** Reify constructor for: BINDER[ #Promiscuity, binder : #Variable . #Binder ] */
	public static final String REIFY_BINDER = "BINDER";
	/** Reify constructor for: PROMISCUOUS */
	public static final String REIFY_PROMISCUOUS = "PROMISCUOUS";
	/** Reify constructor for: LINEAR */
	public static final String REIFY_LINEAR = "LINEAR";
	/** Reify constructor for: BLOCK */
	public static final String REIFY_FUNCTION_KIND = "KFUNCTION";
	/** Reify constructor for: PERMIT */
	public static final String REIFY_DATA_KIND = "KDATA";
	/** Reify constructor for: SHALLOW */
	public static final String REIFY_SHALLOW = "SHALLOW";
	/** Reify constructor for: DEEP */
	public static final String REIFY_DEEP = "DEEP";
	/** Reify constructor for: META-USE */
	public static final String REIFY_META_USE = "META-USE";
	/** Reify constructor for: OTHER */
	public static final String REIFY_OTHER = "OTHER";
	/** Reify constructor for: ARGUMENT[ #Term ] */
	public static final String REIFY_ARGUMENT = "ARGUMENT";
    /** Reify constructor for: STRING */
	public static final String REIFY_STRING = "STRING";
    /** Reify constructor for: NUMERIC */
	public static final String REIFY_NUMERIC = "NUMERIC";
    /** Reify constructor for: BOOLEAN */
	public static final String REIFY_BOOLEAN = "BOOLEAN";
	/** Reify constructor for: META-REQUIRED-VARIABLE[ #Variable ] */
	public static final String REIFY_META_REQUIRED_VARIABLE = "META-REQUIRED-VARIABLE";
	/** Reify constructor */
	public static final String REIFY_EVALUATOR = "EVALUATOR";
	/** Reify constructor for: NA */
	public static final String REIFY_NA = "NA";
	/** Reify constructor for: USE[ #counter ] */
	public static final String REIFY_USE = "USE";
	/** Reify constructor for: DISCARD */
	public static final String REIFY_DISCARD = "DISCARD";
	
	/** Factory for creating and exchanging CRSs and terms. */
	Factory<? extends Term> factory();

	/** Name of the CRS. */
	String name();

	/** True when the CRS has no rules. */
	boolean isEmpty();
	
    /**
     * Use CRS to normalize term and send the result to the sink, returning the sink after reception.
     * @param sink to send normalized term to
     * @param term to normalize
     * @param discard whether the term can be destroyed by the normalizer
     * @return sink after reception
     * @throws CRSException if something goes wrong
     */
    Sink normalize(Sink sink, Term term, boolean discard) throws CRSException;

	/**
	 * Use CRS to normalize term (possibly destructively) and return normal form where no further reduction is possible.
	 * @param term to find and destructively rewrite subterms in until no more rewrites can be found
	 * @return rewritten term (may be the same Term instance)
	 * @throws CRSException if something goes wrong
	 */
	Term normalize(Term term) throws CRSException;

	/**
	 * Rewrite topmost leftmost redex (possibly destructively).
	 * @param term to find and destructively rewrite subterm in
	 * @return rewritten term (may be the same Term instance) or null if the term is a normal form
	 * @throws CRSException if something goes wrong
	 */
	Term rewrite1(Term term) throws CRSException;

	/**
	 * Set the verbosity.
	 * @param verb verbosity TODO: describe levels
	 * @param writer to send verbose messages to
	 */
	void setVerbosity(int verb, Appendable writer);

	/** Get the verbosity. */
	int getVerbosity();
	
 	/**
 	 * Generate text version of this CRS.
 	 * The written text can be reparsed with {@link Parser} of the {@link #factory()}.
 	 * @param used names to avoid
 	 * @param depth remaining sublevels to print (or -1 for all)
 	 * @param full TODO
 	 * @param namedProps whether to include properties
 	 * @param variableProps TODO
 	 * @param omitProps TODO
 	 * @param w to append the text to
 	 * @throws IOException if an i/o error occurs
 	 */
	void appendTo(Appendable w, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException;
	
	
}
