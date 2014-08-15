/* Copyright © 2008, 2013 IBM Corporation. */
/* Copyright © 2014 Kristoffer H. Rose <krisrose@crsx.org> */

package net.sf.crsx;

import java.util.HashMap;
import java.util.Map;

/**
 * Type of computation or patterns.
 * TODO: Carry full type information for each.
 */
public enum Primitive
{
	// Meta-term construction.
	
	/**
	 * $[C, [#name [, #list]]] for constant #name, result is construction with #name as constructor and arguments #list.
	 * The argument list is encoded as a list terms with elements $B[b0 . $B[b1 . ... subterm0 ...]]
	 * where the bs are the binders for the subterm (so no binders means no $Bs).
	 * $[C[Sort],...] only matches constructions of the Sort.
	 */
    CONSTRUCTION("C", 0, 2),
     /** $[M, #name [, #list] ] for constant #name, result is meta-application with #name as constructor and arguments #list. */
    META_APPLICATION("M", 0, 2),
     /** $[V, #name] for constant #name, result is <em>unique and free</em> variable with name #name (no variable capture possible!). */
    VARIABLE("V", 0, 1),
	/**
	 * $[P, #properties, #term] corresponds to {<u>properties</u>}#term where the #properties are the quoted version of <u>properties</u>. 
	 * Quoting represents property lists as list terms with the following members:
	 * <ul>
	 * <li>$RP[#ref] - there is a "catch-all" environment reference where the meta-variable matches #ref.
	 * <li>$NP[#name, #term] - there is a named property where the name matches #name and the value matches #term. 
	 * <li>$VP[#variable, #term] - there is a variable property where the variable matches #variable and the value matches #term. 
	 * <li>$MP[#metavariable, #term] - there is a metaproperty where the meta-variable matches #metavariable and the value matches #term. 
	 * </ul>
	 */
	PROPERTIES("P", 2, 2),
	 /** $[NamedProperty, #name, #value, #t] for constant #name builds the property association {#name:#value}#t. */
	PROPERTY_NAMED("NamedProperty", 3, 3),
	 /** $[NotNamedProperty;, #name, #t] for constant #name builds the property exclusion pattern {&not;#name}#t (constructor is really <q>P-&amp;not;</q>). */
	PROPERTY_NAMED_NOT("NotNamedProperty", 2, 2),
	 /** $[VariableProperty, #name, #value, #t] for constant or variable #name builds the property association {name:#value}#t. */
	PROPERTY_VARIABLE("VariableProperty", 3, 3),
	 /** $[NotVariableProperty;, #name, #t] for constant #name builds the property exclusion pattern {&not;#name}#t (constructor is really <q>P-&amp;not;</q>). */
	PROPERTY_VARIABLE_NOT("NotVariableProperty", 2, 2),
	 /** $[CollectsProperties, #name, #t] for constant or meta-variable #name builds the property pattern {#name}#t. */
	PROPERTY_COLLECT("CollectsProperties", 2, 2),
	/** $[{#loc}PassLocationProperties, TERM] returns TERM except the updated with location information from {#loc}. */  
	PASS_LOCATION_PROPERTIES("PassLocationProperties", 1, 1),
	
	// Variable manipulations.
	
	/** $[{Env}FreeVariables[S?], t] evaluates to the free variables in the term t (of sort S, if given, in domain of Env, if given), as a $Cons/$Nil list (of sort $List[S], if given). */
	FREE_VARIABLES("FreeVariables", 1, 1),
	/** $[IntersectVariables[S?], vs1, vs2] with vs1,vs2 lists of variables, returns a new list with just variables in both vs1 and vs2, or sort S (if given). */
	INTERSECT_VARIABLES("IntersectVariables", 2, 2),
	/** $[UnionVariables[S?], vs1, vs2] with vs1,vs2 lists of variables, returns a new list with the variables in vs2 also in vs1 of sort S (if given). */
	UNION_VARIABLES("UnionVariables", 2, 2),
	/** $[ExceptVariables[S?], vs1, vs2] with vs1,vs2 lists of variables, returns a new list with just variables in vs1 but not in vs2, or sort S (if given). */
	EXCEPT_VARIABLES("ExceptVariables", 2, 2),
	
    // String operations.
    
    /** $[:, #1, #2, ...] corresponds to the constant with constructor named as the concatenation of the string value of the arguments. */
    CONCATENATION(":", 0, Integer.MAX_VALUE),
    /** $[Replace, #1, #2, #3] corresponds to string #1 with all occurrences of #2 replaced by #3 in the string. */
    REPLACE("Replace", 3, 3),
    /** $[Squash, #1] corresponds to constant #1 with all occurrences of white space collapsed to single ordinary spaces. */
    SQUASH("Squash", 1, 1),
    /** $[Index, #1, #2] returns the index in constant #1 of the first occurrence of #2 in the constructor symbol. */
    INDEX("Index", 2, 2),
    /** $[Contains, #1, #2] returns whether constant #1 contains the substring constant #2. */
    CONTAINS("Contains", 2, 2),
    /** $[StartsWith, #1, #2] returns whether constant #1 starts with the substring constant #2. */
    STARTS_WITH("StartsWith", 2, 2),
    /** $[EndsWith, #1, #2] returns whether constant #1 ends with the substring constant #2. */
    ENDS_WITH("EndsWith", 2, 2),
    /** $[Length, #1] returns the number of characters in constant #1. */
    LENGTH("Length", 1, 1),
    /** $[Substring, #1, #2, #3] corresponds to substring of constant #1 starting at #2 ending before #3 (defaults to the end) in the constructor symbol (0-indexed). */
    SUBSTRING("Substring", 2, 3),
    /** $[Escape, #1] returns #1 as a string (quoted with "s and replacing internal "s with \" and special characters with \-escaped version). */
    ESCAPE("Escape", 1, 1),
    /** $[Rescape, #1] Interprets # as a string (including quotes) and returns internal version where quotes and escapes have been interpreted. */
    RESCAPE("Rescape", 1, 1),
    /** $[Mangle, #1] returns #1 as a constant suitable for use as the tail end of an identifier in (at least) Java and C. */
    MANGLE("Mangle", 1, 1),
    /** $[Split, #string, #sep-regex] corresponds to a list of strings (#1;#2;...;#n;) that are the substrings of #string separated by instances of #sep-redex. */
    SPLIT("Split", 2, 2),
    /** $[BeforeFirst, #string, #separator[, #fallback]] is the constructor named as #string except all characters from the first occurrence of #separator are omitted. */
    BEFORE_FIRST("BeforeFirst", 2, 3),
    /** $[AfterFirst, #string, #separator[, #fallback]] is the constructor named as #string except all characters up to the first occurrence of #separator are omitted. */
    AFTER_FIRST("AfterFirst", 2, 3),
    /** $[ToFirst, #string, #separator[, #fallback]] is the constructor named as #string except all characters after the first occurrence of #separator are omitted. */
    TO_FIRST("ToFirst", 2, 3),
    /** $[FromFirst, #string, #separator[, #fallback]] is the constructor named as #string except all characters before the first occurrence of #separator are omitted. */
    FROM_FIRST("FromFirst", 2, 3),
    /** $[DownCase, #string) is a lower case version of #string. */
    DOWN_CASE("DownCase", 1, 1),
    /** $[UpCase, #string) is a lower case version of #string. */
    UP_CASE("UpCase", 1, 1),
    /** $[EncodePoint, #int] returns a Unicode string corresponding to the single character with code point #int. */
    ENCODE_POINT("EncodePoint", 1, 1),
    /** $[DecodePoint, #string] returns a the code point of the first character of the Unicode #string. */
    DECODE_POINT("DecodePoint", 1, 1),
    /** $[Trim, #string) has extreme spaces removed. */
    TRIM("Trim", 1, 1),
    
    // Sequence operations.

    /** $[EmptySequence, #sequence]] is true if the #sequence is (), false if it is any other construction. */
    EMPTY_SEQUENCE("EmptySequence", 1, 1),

    // Numeric operations.
    
	 /** $[Plus, #1, #2, ...] for constant integers #1, #2,..., result is the sum. */
	PLUS("Plus", 1, Integer.MAX_VALUE),
	 /** $[Minus, #1, #2] for constant integers #1, #2, result is their difference (#1 - #2). */
	MINUS("Minus", 2, 2),
	 /** $[Times, #1, #2, ...] for constant integers #1, #2,..,. result is their product. */
	TIMES("Times", 1, Integer.MAX_VALUE),
	 /** $[Divide, #1, #2] for constant integers #1, #2, result is their integer quotient (#1 / #2). */
	DIVIDE("Divide", 2, 2),
	/** $[Modulo, #1, #2] for constant integers #1, #2, result is integer remainder. */
	MODULO("Modulo", 2, 2),
	/** $[NumericEqual, #1, #2]  test equality of #1, #2, result is boolean. */
	NUMEQ("NumericEqual", 2, 2),
	/** $[Absolute, #1]  gives the absolute value. */
	ABSOLUTE("Absolute", 1, 1),

	/** $[Hex,#hex] corresponds to the integer with hex digits #hex. */
	HEX("Hex", 1, 1),
	/** $[Decimal,#s] corresponds to the integer with digits #s. */
	DECIMAL("Decimal", 1, 1),
	
	/** $[BitAnd, #i1, #i2] is the integer with the bits common to #i1 and #i2. */
	BIT_AND("BitAnd", 2, 2),
	/** $[BitOr, #i1, #i2] is the integer with the bits in either #i1 and/or #i2. */
	BIT_OR("BitOr", 2, 2),
	/** $[BitXor, #i1, #i2] is the integer with the bits in precisely one of #i1 and #i2. */
	BIT_XOR("BitXor", 2, 2),
	/** $[BitNot, #i] is the integer with the opposite bits of #i. */
	BIT_NOT("BitNot", 1, 1),
	/** $[BitMinus, #i1, #i2] is the integer with the bits in #i1 which are not in #i2. */
	BIT_MINUS("BitMinus", 2, 2),
	
	// Logical operators.
	
	/** $[And, #1, #2] for constant booleans #1, #2, result is boolean. */
	AND("And", 2, 2),
	/** $[Or, #1, #2] for constant booleans #1, #2, result is boolean. */
	OR("Or", 2, 2),
	/** $[Not, #1] for constant boolean #1, result is boolean. */
	NOT("Not", 1, 1),

	// Comparisons.

	/** $[BitSubSetEq, #i1, #i2] is True or $Nil depending on whether all bits in #i1 are also in #i2. */
	BIT_SUB_SET_EQ("BitSubSetEq", 2, 2),
	
	 /** $[Equal, #1, #2] test equality of #1, #2, result is boolean. */
	EQ("Equal", 2, 2),
	 /** $[NotEqual, #1, #2] test inequality of #1, #2, result is boolean. */
	NE("NotEqual", 2, 2),
	 /** $[LessThan, #1, #2] for constant integers #1, #2, result is boolean. */
	LT("LessThan", 2, 2),
	 /** $[GreaterThan, #1, #2] for constant integers #1, #2, result is boolean. */
	GT("GreaterThan", 2, 2),
	 /** $[LessThanOrEqual, #1, #2] for constant integers #1, #2, result is boolean. */
	LE("LessThanOrEqual", 2, 2),
	/** $[GreaterThanOrEqual, #1, #2] for constant integers #1, #2, result is boolean. */
	GE("GreaterThanOrEqual", 2, 2),
	 /** $[StringLessThan, #1, #2] for strings #1, #2, result is boolean. */
	STRING_LT("StringLessThan", 2, 2),
	
	/** $[DeepEqual, #1, #2 [, #3]]  test equality of #1, #2 as terms, result is boolean. If #3 is $True, also compare environment (default) */
	DEEP_EQ("DeepEqual", 2, 3),
	/** $[SameVariable, x, y] returns whether x and y are the same variable. */
	SAME_VARIABLE("SameVariable", 2, 2),
	/** $[LesserVariable, x, y] returns whether x is lesser than y in the global variable order. */
	LESSER_VARIABLE("LesserVariable", 2, 2),
	/** $[VariableNameIs, v, #name, #result] the variable name associated with v is #name and return as result. */
	VARIABLE_NAME_IS("VariableNameIs", 3, 3),
	
	// Matching.
	
	/**
	 * $[Match, #pattern, #], is the same as #, except # must also match #pattern.
	 * (In a pattern, we match against #pattern before also matching against #.
	 * In a computation or contraction, we compute # and then match it against #pattern,
	 * returning the value of # if it matches or () if it does not.)
	 */
	MATCH("Match", 2, 2),
    /**
     * $[NotMatch, #p, #], is the same as # but only when it does <em>not</em> match #pattern.
	 * (In a pattern, we match against #pattern, which must fail, before also matching against #.
	 * In a computation or contraction, we compute # and then match it against #pattern,
	 * returning value if it does not match or () if it does.)
     */
    NOT_MATCH("NotMatch", 1, 2),
    
    /** $[MatchRegex, #regex, #p], for constant #regex, is match pattern that only matches constants that fit the regular expression #regex and also match #p.
     *   Can also be used as evaluator where it returns the boolean result of whether */
    MATCH_REGEX("MatchRegex", 1, 2),
    /** $[IsInteger, #p] is match pattern that only matches constants that both fit the regular expression "[-+]*[0-9]+" and also match #p. */
    IS_INTEGER("IsInteger", 1, 2),
    
	/** TODO. */
	HAS_GRAMMAR("HasGrammar", 1, 2),
	/** $[{#}Parse[sort], #filename] loads a file by using the standard parser and category, respecting the variable name mapping {#} with entries "Name" : v. */
	PARSE("Parse", 1, 1),
	/** $[{#}ParseURL[sort], #category, #url] for constant arguments, evaluates to the term obtained by parsing the content of the #url as a #category term. */
	PARSE_URL("ParseURL", 2, 2),
	/** $[{#}ParseResource, #category, #name] for constant arguments, evaluates to the term obtained by getting and parsing the #name resource as a #category term. */
	PARSE_RESOURCE("ParseResource", 2, 2),
	/** $[{#}ParseText[sort], #category, #text] for constant arguments, evaluates to the term obtained by parsing the #text as a #category term. */
	PARSE_TEXT("ParseText", 2, 2),
	/** $[Load[sort], #r, #category] parses the resource #r using the category, if any, and returns the term. */
	LOAD("Load", 1, 2),
	/** $[Save, #term, #r, #category] stores the #term in a manner that can be reread with $[Load, #r, #category] (not always supported). */
	SAVE("Save", 1, 2),
	/** $[LoadTerm[#sort], #uri] parses the resource #uri, and returns the term. */
	LOAD_TERM("LoadTerm", 1, 1),
	/** $[SaveTerm, #uri, #term, #result] saves the #term under the specified #uri and then returns #result. */
	SAVE_TERM("SaveTerm", 3, 3),
	/** $[Script, term] creates an independent {@link Builder} and invokes {@link Builder#load} on term, returning the sequence of computed results (as a list)! */
	SCRIPT("Script", 1, 1),
	/** $[Normalize, term, crs] normalizes the term using the indicated crs and returns the result. */
	NORMALIZE("Normalize", 2, 2),
	
	/** $[If, #test, #true[, #false]] with constant #test evaluates as either #true or #false depending on whether test is true or false (empty sequence/string, zero, $False). */
	IF("If", 2, 3),
	/** $[Pick, #index, #list] with constant #index evaluates as the index'th member of list (starting from 0). */
	PICK("Pick", 2, 2),
	/** $[ReversePick, #index, #list] with constant #index evaluates as the index'th member of the reverse of list. */
	REVERSE_PICK("ReversePick", 2, 2),
	/** $[ListLegnth, #list] returns the length of list. */
	LIST_LENGTH("ListLength", 1, 1),
	/** $[IfZero, #i, #true[, #false]] with constant integer #i evaluates as either #true or #false depending on whether #i is zero. */
	IF_ZERO("IfZero", 2, 3),
	/** $[IfEmpty, #s, #true[, #false]] with constant string #s evaluates as either #true or #false depending on whether #s is the empty string. */
	IF_EMPTY("IfEmpty", 2, 3),
	/** $[{#environment}IfDef, #name, #true[, #false]] with constant #name evaluates as either #true or #false depending on whether name is defined in #environment. */
	IF_DEF("IfDef", 2, 3),
	/** $[IfLinear, v, #true[, #false]] is #true if v is a linear variable (¹v) otherwise #false or (). */
	IF_LINEAR("IfLinear", 2, 3),
	/** $[IfData, #t, #true[, #false]] is #true if #t is a data construction, oherwise #false or (). */
	IF_DATA("IfData", 2, 3),

	// Environment operations.

	/** $[{#Env}Keys[sort]] is the list of all keys in the #Env environment, of type $List[sort] (if specified). */
    KEYS("Keys", 0, 0),
	/** $[{#env}Get, name[, default]] return property or variable from the environment (either the properties in #env on Get or the global one). */
	GET("Get", 1, 2),
	/** $[{#env}GetRef, name[, default]] return property or variable from environment. */
	GET_REF("GetRef", 1, 2),
	
	// Sort stuff.
	
	/** $[SortOf, term] return the constant name of the sort of term, or () in case it is not known. */
	SORT_OF("SortOf", 1, 1),
	/** $[CheckSortOf, sort, term] return whether the constant sort name is in fact the sort of term. */
	CHECK_SORT_OF("CheckSortOf", 2, 2),
	
	// Input/output.
	
	/** $[URL, url[, base]] return fully qualified version of url using base (default system dependent) in case it is relative. */
	URL("URL", 1, 2),
	/** $[HasURL, url] checks whether the #url can be retrieved. */
	HAS_URL("HasURL", 1, 1),
	/** $[Print, #term [, #result]] prints #term (as term) and otherwise acts like #result (defaults to ()). */
	PRINT("Print", 1, 2),
	/** $[Echo, #constant[, #result]] echoes #constant (unquoted and without adding a newline) and otherwise acts like #result (defaults to ()). */
	ECHO("Echo", 1, 2),
	/** $[Show, #term] is a constant with the textual representation of #term as the string value. */
	SHOW("Show", 1, 1),
	/** $[FormatNumber, #number [,#format]] is a string representing the number. */
	FORMAT_NUMBER("FormatNumber", 1, 2),
	/** $[Format, #format [,#argument...]] generates a string from the #format string and the #arguments... strings. */
	FORMAT("Format", 1, Integer.MAX_VALUE),
	
	/** $[Compute, #term] is the same as #term except computed... */
	COMPUTE("Compute", 1, 1),
	
	/** $[{#Env}Inherit, #t] wil distribute the {#Env} to all function constructions in #t. */ 
	INHERIT("Inherit", 1, 1),
	/** $[{#Env}Synthesize, #t] wil distribute the {#Env} to all data constructions in #t. */ 
	SYNTHESIZE("Synthesize", 1, 1),

	/** $[Call[$ResultSort, $Arg1Sort, ...], #name, ...] */
	CALL("Call", 2, Integer.MAX_VALUE),
	/** $[TryCall[$ResultSort, $Arg1Sort, ...], #name, ...] */
	TRYCALL("TryCall", 2, Integer.MAX_VALUE),
	
    /** $[Dump, #prefix, #term] prints #prefix and #term and acts like #term. */
    DUMP("Dump", 2, 2),
    /** $[Error, #format [, #argument, ...]] emits an exception with text built from the #format string formatted with #argument... strings (as needed). */
    ERROR("Error", 1, Integer.MAX_VALUE),
    /** $[ForgivableError, #value, #format [, #argument, ...]] emits an exception or a warning with text built from the #format string formatted with #argument... strings (as needed). */
    FORGIVABLEERROR("ForgivableError", 2, Integer.MAX_VALUE),
	/** $[Trace, #message, #value]: first argument is echoed (unevaluated, to stderr!) second argument is then matched/contracted... */
	TRACE("Trace", 1, 2),
	
	/** Sort cast. */
	CAST("Cast", 1, 1),
	
    /** Type unification */
    UNIFY("Unify", 2, 2),
    
    /** Hash code. */
    HASH_CODE("HashCode", 1, 1),
    
    /** Dummy value with no values. */
    NULL("Null", 0, 0),
	/** Dummy "fall-back" value. */
	IGNORE("Ignore", 0, Integer.MAX_VALUE);
    
	/** The constant first symbol. */
    final public String symbol;
	/** Minimal number of arguments (excluding the constant). */
    final public int minArgCount;
	/** Maximum number of arguments (excluding the constant). */
    final public int maxArgCount;
    /** Form for the primitive arguments or null if  */
    Term form;
    
	/** Constructor for the members. */
	private Primitive(String s, int min, int max) {symbol = s.intern(); minArgCount = min; maxArgCount = max;}
	
	// Object...
	
	public String toString()
	{
		return symbol;
	}
	
	// Helpers.
	
    /** Reverse map to get primitive from name. */
    final static Map<String,Primitive> back = new HashMap<String, Primitive>();
    
	/** Get primitive corresponding to name, or null. */
	static public Primitive which(String name)
	{
		if (name.startsWith(CRS.EVAL_SYMBOL))
			name = name.substring(CRS.EVAL_SYMBOL.length());
		if (back.isEmpty())
		{
	    	for (Primitive p : values())
	    		back.put(p.symbol, p);
		}
		return back.get(name);
	}
}
