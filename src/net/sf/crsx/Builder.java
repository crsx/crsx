/* Copyright © 2008, 2012 IBM Corporation. */

package net.sf.crsx;

import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * In-progress construction of a {@link CRS} with limited scripting capability.
 * The CRS is constructed from a sequence of invocations of {@link #load(Sink, Term)},
 * where the parameter term is a "script" of CRSX rules and directives.
 * The effect of the invocation is that all rules in the script have been added to the system being built,
 * directives with system effects have been executed, and
 * the results of any term-generating directives have been added to the "context sink".
 * 
 * <p>
 * 
 * The <em>script</em> term is first evaluated (see {@link Contractum#contract(Sink, Valuation, net.sf.crsx.util.ExtensibleMap)}),
 * and then interpreted as a directive in one of the following forms:
 * 
 * <dl>
 * 
 * <dt>$Rule[ <em>name</em><sub>opt</sub>, <em>pattern</em>, <em>contractum</em> ]
 * <dd>Add rule to the CRS being built.
 *  <ul>
 *  <li><em>name</em> - an optional term where the constructor symbol is used as the rule name,
 *      and any arguments are rule annotations (see below).
 *  <li><em>pattern</em> - pattern term of rule (see {@link Pattern}).
 *  <li><em>contractum</em> - contractum term of rule (see {@link Contractum}).
 *  </ul>
 *  where the rule annotations should be of the following:
 *  <ul>
 *  <li>Free[v,...] - permits the variables v,... to occur free in <em>pattern</em> (and thus match free variables).
 *  <li>Fresh[v,...] - permits the variables v,... to occur free in <em>contractum</em> (and thus create fresh free variables).
 *  <li>Meta[#,...] - permits the meta-variables #,... to occur only in <em>contractum</em> (and thus create meta-applications).
 *  <li>Discard[#,...] - permits the meta-variables #,... to occur only in <em>pattern</em> (and thus contraction can delete the matched subterm).
 *  <li>Copy[#,...] - permits the meta-variables #,... to occur more than once in <em>contractum</em> (thus permits contraction to duplicate matched subterms).
 *  <li>Share[#,...] - permits the meta-variables #,... to occur more than once in <em>contractum</em>
 *  	<strong>and</strong> assert that they will always match normal form subterms (so do not need to be copied).
 *  <li>Weak[#,...] - permits the meta-variables #,... to occur in patterns in weakened form, i.e., without all the possible bound variables (so matching does a variable occurrence check). 
 *  <li>Comparable[#,...] - permits the meta-variables #,... to occur multiple times in <em>pattern</em> (and thus match equal subterms).
 *  <li>Leaf - asserts that the result of contracting the rule will always be a normal form.
 *  <li>Shallow[v,...] - asserts that the variable v is shallow (occurs as direct parameter of the bound construction).
 *  </ul>
 *  Note that the standard parser allows the special form ( <em>name</em> : )?<em>pattern</em> &rarr; <em>contractum</em> for rules
 *  (where "(...)?" denotes optionality).
 * <p>
 * 
 * <dt><em>constructor</em>[( <em>directive</em> ; ... ; <em>directive</em> ; )]
 * <dt>( <em>directive</em> ; ... ; <em>directive</em> ; )
 * <dd>Process the nested directives.
 *      If the <em>constructor</em> form is used then the name of all embedded rules will have their name prefixed with the <em>constructor</em> symbol.
 *      The form 
 *      <blockquote>
 *          ( <em>directive</em> ; ... ; <em>directive</em> ; )
 *      </blockquote>
 *      denotes a sequence (right-recursive use of {@link CRS#CONS_SYMBOL} terminated with {@link CRS#NIL_SYMBOL}).
 * <p>
 * 
 * <dt>$Sort[ <em>name</em>,  ( <em>form</em> ; ... ; <em>form</em> ; )]
 * <dd>Set sort membership and form of indicated constructors.  Each <em>form</em> defines the sort and shape of one constructor as follows:
 * 		<blockquote>
 * 		<em>form</em> ::= <em>constructor</em>[ <em>argument</em>, ..., <em>argument</em> ]<br>
 * 		<em>argument</em> ::= <em>name</em> | *
 * 		</blockquote>
 * 		where each <em>argument</em> identifies the argument as either belonging to a specific <em>name</em>d sort
 * 		or * to indicate an unconstrained argument.
 * <p>
 * 
 * <dt>$Term[ <em>term</em> ]
 * <dd>Send <em>term</em> to the context sink.
 *      The <em>term</em> is first evaluated (see {@link Contractum#contract(Sink, Valuation, net.sf.crsx.util.ExtensibleMap)}).
 * <p>
 * 
 * <dt>$Normalize[ <em>term</em> ]
 * <dd>Normalize the <em>term</em> with the (so far) constructed CRS and send the result to the context sink.
 *      The <em>term</em> is first evaluated (see {@link Contractum#contract(Sink, Valuation, net.sf.crsx.util.ExtensibleMap)}).
 * <p>
 * 
 * <dt>$Set[ <em>name</em>, <em>directive</em> ]
 * <dd>Process <em>directive</em> with the context sink set to
 *      store the result term in the <em>name</em> context variable.
 *      The <em>directive</em> is first evaluated (see {@link Contractum#contract(Sink, Valuation, net.sf.crsx.util.ExtensibleMap)}).
 * <p>
 * 
 * <dt>$Message[ <em>constant</em>, <em>write-file</em><sub>opt</sub> ]
 * <dd>Append constructor symbol name of <em>constant</em> to <em>write-file</em> (defaults to '' corresponding to System.out).
 *      The <em>constant</em> is first evaluated (see {@link Contractum#contract(Sink, Valuation, net.sf.crsx.util.ExtensibleMap)}).
 * <p>
 * 
 * <dt>$Verbose[ <em>verbose</em><sub>opt</sub>, <em>write-file</em><sub>opt</sub> ]
 * <dd>Set verbosity to the integer level <em>verbose</em> (defaults to 1),
 *      sending the verbose messages to the <em>write-file</em> (defaults to '' corresponding to System.out).
 * <p>
 * 
 * <dt>$EmbeddedParser[ <em>class</em> ]
 * <dd>Set the "embedded parser" to a new instance of the <em>class</em>.
 * <p>
 * 
 * <dt>$Sink[ <em>class</em> ]
 * <dd>Calls the current {@link Factory}'s  {@link Factory#setSinker(Class)} with an instance of <em>class</em>.
 * <p>
 * 
 * <dt>$DumpRules
 * <dd>Send the entire CRS as a term to the context sink. 
 * <p>
 * 
 * <dt>$DumpRules
 * <dd>Send the entire CRS as a term to the context sink. 
 * <p>
 * 
 * <dt>$Compile[<em>generator-class</em>, <em>generator-dir</em>, <em>package-name</em>, <em>stand-alone</em>]
 * <dd><b>NOTE</b>: Subject to change. Generate a source program equivalent to the current rule system:
 * 		<ul>
 * 		<li><em>generator-class</em> - class name of the implementation of {@link net.sf.crsx.generator.Generator} used to do the compilation,
 * 		<li><em>generator-dir</em> - directory to store the generated files in,
 * 		<li><em>package-name</em> - program unit name to use for the generated files (see generator documentation for details), and
 * 		<li><em>stand-alone</em> - if non-() then the generated files can run without the crsx.jar file (should be () for non-Java generators).
 * 		</ul>
 * <p>
 * 
 * <dt>$DumpRules
 * <dd>Send the entire CRS as a term to the context sink. 
 * <p>
 * 
 * </dl>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Builder.java,v 3.7 2014/02/07 20:18:10 villardl Exp $
 */
public interface Builder
{
	/** Internal constructor name for entire CRSs. */
	public final static String CRS_SYMBOL = "$CRS";
	/** Internal constructor name for rules as passed to {@link #load(Sink, Term)}. */
	public final static String RULE_SYMBOL = "$Rule";
	/** Internal constructor name for $Term directive as passed to {@link #load(Sink, Term)}. */
	public final static String TERM_SYMBOL = "$Term";
	/** Internal constructor name for $Sort directive as passed to {@link #load(Sink, Term)}. */
	public final static String DATA_SORT_SYMBOL = "$Sort";
	/** Internal constructor name for $SortAlias directive as passed to {@link #load(Sink, Term)}. */
	public final static String SORT_ALIAS_SYMBOL = "$SortAlias";
	/** Internal constructor name for $Function directive as passed to {@link #load(Sink, Term)}. */
	public final static String FUNCTION_SORT_SYMBOL = "$FunctionSort";
	/** Internal constructor name for polymorphic type declarations. */
	public final static String POLYMORHIC_SORT_VARIABLE_SYMBOL = "\u2200";
	/** @see #load(Sink, Term) */
	public final static String USE_SYMBOL = "$Use";
	/** Internal constructor name for $Normalize directive as passed to {@link #load(Sink, Term)}. */
	public final static String NORMALIZE_SYMBOL = "$Normalize";
	/** Internal constructor name for $Compile directive as passed to {@link #load(Sink, Term)}. */
	public final static String COMPILE_SYMBOL = "$Compile";
	/** Internal constructor name for $Set directive as passed to {@link #load(Sink, Term)}. */
	public final static String SET_SYMBOL = "$Set";
	/** Internal constructor name for $Unset directive as passed to {@link #load(Sink, Term)}. */
	public final static String UNSET_SYMBOL = "$Unset";
	/** Internal constructor name for $Comment directive as passed to {@link #load(Sink, Term)}. */
	public final static String COMMENT_SYMBOL = "$Comment";
	/** Internal constructor name for $Send directive as passed to {@link #load(Sink, Term)}. */
	public final static String SEND_SYMBOL = "$Send";
	/** Internal constructor name for $Message directive as passed to {@link #load(Sink, Term)}. */
	public final static String MESSAGE_SYMBOL = "$Message";
    /** Internal constructor name for $Verbose directive as passed to {@link #load(Sink, Term)}. */
    public final static String VERBOSE_SYMBOL = "$Verbose";
    /** Internal constructor name for $Watch directive as passed to {@link #load(Sink, Term)}. */
    public final static String WATCH_SYMBOL = "$Watch";
    /** Internal constructor name for $EmbeddedParser directive as passed to {@link #load(Sink, Term)}. */
    public final static String EMBEDDED_PARSER_SYMBOL = "$EmbeddedParser";
    /** Internal constructor name for $Parser directive as passed to {@link #load(Sink, Term)}. */
    public final static String PARSER_SYMBOL = "$Parser";
    /** Internal constructor name for $AddGrammar directive as passed to {@link #load(Sink, Term)}. */
    public final static String ADD_GRAMMAR_SYMBOL = "$AddGrammar";
    /** Internal constructor name for $CheckGrammar directive as passed to {@link #load(Sink, Term)}. */
    public final static String CHECK_GRAMMAR_SYMBOL = "$CheckGrammar";
    /** Internal constructor name for $Check directive as passed to {@link #load(Sink, Term)}. */
    public final static String CHECK_SYMBOL = "$Check";
    /** Internal constructor name for $Sink directive as passed to {@link #load(Sink, Term)}. */
    public final static String SINK_SYMBOL = "$Sink";
    /** Internal constructor name for $CheckSorts directive as passed to {@link #load(Sink, Term)}. */
    public final static String CHECK_SORTS_SYMBOL = "$CheckSorts";
    /** Internal constructor name for $Locify directive as passed to {@link #load(Sink, Term)}. */
    public final static String LOCIFY_SYMBOL = "$Locify";
    /** Internal constructor name for $DumpRules directive as passed to {@link #load(Sink, Term)}. */
    public final static String DUMP_RULES_SYMBOL = "$DumpRules";
    /** Internal constructor name for $Dispatchify directive as passed to {@link #load(Sink, Term)}. */
    public final static String DISPATCHIFY_SYMBOL = "$Dispatchify";
    /** Internal constructor name for $Reify directive as passed to {@link #load(Sink, Term)}. */
    public final static String REIFY_SYMBOL = "$Reify";
    /** Internal constructor name for $Sortify directive as passed to {@link #load(Sink, Term)}. */
    public final static String SORTIFY_SYMBOL = "$Sortify";
    /** Internal constructor name for $Meta as passed to {@link #load(Sink, Term)}. */
    public final static String META_SYMBOL = "$Meta";
    /** Internal constructor name for $Print as passed to {@link #load(Sink, Term)}. */
    public final static String PRINT_SYMBOL = "$Print";
    /** $Lax directive (and environment constant) for automatically fixing rule declarations. */
    public final static String LAX_SYMBOL = "$Lax";
    /** $Assert directive. */
    public final static String ASSERT_SYMBOL = "$Assert";
    /** Internal constructor name for $Simplify directive as passed to {@link #load(Sink, Term)}. */
    public final static String SIMPLIFY_SYMBOL = "$Simplify";
    /** Internal constructor name for $Inline directive as passed to {@link #load(Sink, Term)}. */
    public final static String INLINE_SYMBOL = "$Inline";
    
    
    /** Constructor for "Free" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String FREE_OPTION_SYMBOL = "Free";
    /** Constructor for "Fresh" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String FRESH_OPTION_SYMBOL = "Fresh";
    /** Constructor for "Global" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String GLOBAL_OPTION_SYMBOL = "Global";
    /** Constructor for "Meta" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String META_OPTION_SYMBOL = "Meta";
    /** Constructor for "Share" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String SHARE_OPTION_SYMBOL = "Share";
    /** Constructor for "Copy" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String COPY_OPTION_SYMBOL = "Copy";
    /** Constructor for "Discard" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String DISCARD_OPTION_SYMBOL = "Discard";
    /** Constructor for "Weak" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String WEAK_OPTION_SYMBOL = "Weak";
    /** Constructor for "Comparable" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String COMPARABLE_OPTION_SYMBOL = "Comparable";
    /** Constructor for "Leaf" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String LEAF_OPTION_SYMBOL = "Leaf";
    /** Constructor for "Priority" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String PRIORITY_OPTION_SYMBOL = "Priority";
    /** Constructor for "Fallback" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String FALLBACK_OPTION_SYMBOL = "Fallback";
    /** Constructor for "Lax" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String LAX_OPTION_SYMBOL = "Lax";
    /** Constructor for "Data" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String DATA_OPTION_SYMBOL = "Data";
    /** Constructor for "Mixed" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String MIXED_OPTION_SYMBOL = "Mixed";
    /** Constructor for "Watch" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String WATCH_OPTION_SYMBOL = "Watch";
    /** Constructor for "Inline" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String INLINE_OPTION_SYMBOL = "Inline";
    /** Constructor for "Main" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String MAIN_OPTION_SYMBOL = "Main";
    
    /** Constructor for EXPERIMENTAL "FreshReuse" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String FRESH_REUSE_OPTION_SYMBOL = "FreshReuse";
    /** Constructor for EXPERIMENTAL "FreshReuseOrigin" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String FRESH_REUSE_ORIGIN_OPTION_SYMBOL = "FreshReuseOrigin";
    /** Constructor for EXPERIMENTAL "CompileType" option used by $Rule in {@link #load(Sink, Term)}. */
    public final static String COMPILE_TYPE_OPTION_SYMBOL = "CompileType";
    
    /** Factory for creating and exchanging further CRSs and terms. */
	Factory<? extends Term> factory();

	/** Name of CRS under construction. */
	String name();

	/** Set name of CRS under construction. */
	void setName(String name);

    /**
     * Load CRSX rules and execute directives with a specific "context sink".
     * (See class description for details.)
     * 
     * @param sink to send any generated structures to or null to use the factory default sink as necessary
     * @param script term with script, as described above, which may be destroyed by the loading
     * 
     * @return the sink after processing (may be null if no output produced)
     * @throws CRSException if rules cannot be added or directive is malformed
     */
    Sink load(Sink sink, Term script) throws CRSException;

    /**
     * Merge (copies of) all the rules of another builder into this one.
     * @param other builder with rules to include
     * @throws CRSException when the addition leads to name conflicts
     */
    void merge(Builder other) throws CRSException;
    
	/**
	 * Remove a rewrite rule by name.
	 * @param name of rule to remove
	 */
	void removeRule(String name);

	/** Set of the names of all rules added so far. */
	Set<String> ruleNames();

	/**
	 * The options of a specific rule.
	 * @param name of rule
	 */
	Map<String,List<Term>> ruleOptions(String name);

	/**
	 * The pattern term (left hand side) of a specific rule.
     * Free variables are shared among {@link #rulePattern(String)} and {@link #ruleContractum(String)}.
	 * @param name of rule
	 */
	Pattern rulePattern(String name);

	/**
	 * The contractum term (right hand side) of a specific rule.
     * Free variables are shared among {@link #rulePattern(String)} and {@link #ruleContractum(String)}.
	 * @param name of rule
	 */
	Contractum ruleContractum(String name);

	/**
	 * Extract CRS from built collection of rules. 
	 * @param discard whether the builder will be used further
	 */
	CRS toCRS(boolean discard);
}
