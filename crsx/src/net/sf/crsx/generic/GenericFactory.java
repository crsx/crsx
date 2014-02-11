/* Copyright (c) 2007, 2012 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.FileWriter;
import java.io.Flushable;
import java.io.IOException;
import java.io.Reader;
import java.io.StringReader;
import java.io.StringWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Parser;
import net.sf.crsx.Pattern;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.analysis.Unifier;
import net.sf.crsx.parser.ClassicParser;
import net.sf.crsx.util.AbstractLiteralConstructor;
import net.sf.crsx.util.BigDecimalConstructor;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.DoubleConstructor;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.HashMultiMap;
import net.sf.crsx.util.IntegerConstructor;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.LiteralStringConstructor;
import net.sf.crsx.util.MultiMap;
import net.sf.crsx.util.ObjectConstructor;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.SimpleTermSink;
import net.sf.crsx.util.Sinker;
import net.sf.crsx.util.TraceSink;
import net.sf.crsx.util.Util;

/**
 * Generic CRS factory, used by the CRSX rules interpreter.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericFactory.java,v 3.16 2014/01/16 13:16:55 krisrose Exp $
 */
public class GenericFactory implements Factory<GenericTerm>
{
	// Static.
    /** If set then used as width of printed terms. */
    final public static String WIDTH = "width";
    
    /** If set then all variable names are given canonical names. */
    final public static String CANONICAL_VARIABLES = "canonical-variables";

    /** If set then linear variable names do not include a linear marker. */
    final public static String NO_LINEAR_VARIABLES = "omit-linear-variables";

    /** If set then {@link #makeBuffer(net.sf.crsx.Maker.CallBack)} creates flexible terms. */
    final public static String FLEXIBLE = "flexible";

    /** If set then {@link #makeBuffer(net.sf.crsx.Maker.CallBack)} creates flexible terms. */
    final public static String SPECIAL_VARIABLE_KEY = "$$VARIABLE";
    
    /** If set to true, that it is allowed to have a sort constructor with the same name as a term constructor */
    final public static boolean ALLOWSORTOVERLOADING = true;

	/** Regular expression for pattern specification. */
	final protected static java.util.regex.Pattern parserSpecificationPattern =
		java.util.regex.Pattern.compile("\\s*" // leading space
				+"(?:([({])\\s*" // '{' before bindings - echoed as discriminator
				
				+ "(\\p{Alpha}\\w*|['][^';]*[']|[\"][^\";]*[\"])\\s*" // first binding's grammar name
				+ "(?:"
				+  "(:)\\s*" // ':' of first binding
				+  "[(]\\s*(?:" // '(' before categories of first binding
				+   "(\\p{Alpha}\\w*|['][^';]*[']|[\"][^\";]*[\"])\\s*;\\s*" // a category of first binding followed by ';'
				+  ")*([)])\\s*" // ')' after categories of first binding - echoed as terminator
				+ ")?"
				
				+ "(?:;\\s*" // ';' leading to another binding
				+  "(?:" // subsequent bindings can be omitted
				+   "(\\p{Alpha}\\w*|['][^';]*[']|[\"][^\";]*[\"])\\s*" // subsequent binding's grammar name
				+   "(?:"
				+    "(:)\\s*" // ':' of optional subsequent binding - echoed as indicator
				+    "[(]\\s*(?:" // '(' before categories of subsequent binding
				+     "(\\p{Alpha}\\w*|['][^';]*[']|[\"][^\";]*[\"])\\s*;\\s*" // a category of subsequent binding followed by ';'
				+    ")*([)])\\s*" // ')' after categories of subsequent binding - echoed as terminator
				+   ")?"
				+  ")?" // end of subsequent binding
				+ ")*" // all subsequent bindings
				
				+"([})])\\s*)*" // } after bindings - echoed as terminator
				
				+"(\\p{Alpha}\\w*|['][^';]*[']|[\"][^';]*[\"])?\\s*" // default/fall-back grammar name
				);
	
    // State.
    
	/** Constructor for internal sequence terminator, and false. */
	final public Constructor nilConstructor;

	/** Constructor for internal sequence node. */
	final public Constructor consConstructor;

	/** Constructor for internal truth value. */
	final public Constructor trueConstructor;
	final public GenericTerm trueTerm;
	
	/** Constructor for internal false value. */
	final public Constructor falseConstructor;
	final public GenericTerm falseTerm;
	
	/** Constructor for internal try call values. */
	final public Constructor trySuccessConstructor;
	final public GenericTerm trySuccessTerm;
	final public Constructor tryFailureConstructor;
	final public GenericTerm tryFailureTerm;
	
	/** Replacement term reader. */
	final private Parser classicParser;

	/** Maps parser categories (including <b>null<b>) to grammar names. */
	final protected Map<String, Parser> categoryParser = new HashMap<String, Parser>();
	
	/** Environment. */
	final private Map<String, Stub> environment;

    /** Symbol of indexed constructors. */
	final private List<String> indexedSymbol;

	/** Indexed constructors by symbol. */
	final private Map<String, GenericIndexedConstructor> symbolConstant;
	
    /** Indexed constructors by index. */
	final private List<GenericIndexedConstructor> indexConstant;

	/** Maps each sort constructor to its parameter list . Master list of sorts. */
	final private Map<String, List<Variable>> sortParams = new HashMap<String, List<Variable>>();
	
	/** Maps each sort constructor name to the set of data symbols which define the sort. */
	final private MultiMap<String, String> sortDataSymbols = new HashMultiMap<String, String>();
	
	/** Maps an aliased sort constructor name to its value */
	final Map<String, String> sortAliases = new HashMap<String, String>();

	/** The sort constructors that permit matching against variables. */
	final private Set<String> sortsWithVariables = new HashSet<String>();

	/** The sort constructors that permit matching against variables. */
	final private Set<String> sortsWithClosedData = new HashSet<String>();
	
	/** The sort constructors which come with a sort set. */
	final private Map<String,Map<String,Term>> sortsWithSortSet = new HashMap<String,Map<String,Term>>();
	
	/** Maps each constructor name to a set of pairs <sort,form>. */
	final private MultiMap<String, Pair<Term, Term>> constructorSortForm = new HashMultiMap<String, Pair<Term, Term>>();

	/** Constructors occurring only in function positions in patterns. */
	final private Set<String> functionConstructors = new HashSet<String>();
	
	/** Constructors occurring only in data positions in patterns. */
	final private Set<String> dataConstructors = new HashSet<String>();
	
	/** Class to use for output sinks. */
	private Class<? extends Sinker> sinkClass;

    /** Constructions we're watching for in contractions... */
    final Set<String> watchedConstructions = new HashSet<String>();
    
    /** The so far accumulated (recoverable) errors. */
    final List<String> errors = new ArrayList<String>();

    /** Globally free variables. */
    final private Map<String,Variable> globalFreeVariables = new HashMap<String, Variable>();
	
	// Constructor.

    /**
     * Create factory.
     */
    public GenericFactory()
    {
        environment = new HashMap<String, Stub>();
        indexedSymbol = new ArrayList<String>();
        symbolConstant = new HashMap<String, GenericIndexedConstructor>();
        indexConstant = new ArrayList<GenericIndexedConstructor>();
        nilConstructor = makeConstructor(CRS.NIL_SYMBOL);
        consConstructor = makeConstructor(CRS.CONS_SYMBOL);
        trueConstructor = new BooleanConstructor(true);
        falseConstructor = new BooleanConstructor(false);
        trySuccessConstructor = makeConstructor(CRS.TRYSUCCESS_SYMBOL);
        tryFailureConstructor = makeConstructor(CRS.TRYFAILURE_SYMBOL);
        
        classicParser = new ClassicParser();
        
    	// save arities for the pre-defined sort constructors
		sortParams.put(CRS.BOOLEAN_SORT, new ArrayList<Variable>(0));
		sortParams.put(CRS.STRING_SORT, new ArrayList<Variable>(0));
		sortParams.put(CRS.NUMERIC_SORT, new ArrayList<Variable>(0));

		// create $List[α]
    	Variable alpha = makeVariable("alpha", true);
		sortParams.put(CRS.LIST_SORT, Util.singleton(alpha));
    	GenericTerm[] listSubs = new GenericTerm[1]; listSubs[0] = newVariableUse(alpha);
    	Variable[][] binds = new Variable[1][]; binds[0] = new Variable[0];
    	GenericTerm lst = newConstruction(makeConstructor(CRS.LIST_SORT), binds, listSubs);
    	// define $Nil and $Cons
    	GenericTerm nil = constant(makeConstructor(CRS.NIL_SYMBOL));
    	GenericTerm[] consSubs = new GenericTerm[2];
    	consSubs[0] = newVariableUse(alpha);
    	consSubs[1] = lst.copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
    	binds = new Variable[2][]; binds[0] = binds[1] = new Variable[0];
    	GenericTerm cons = newConstruction(makeConstructor(CRS.CONS_SYMBOL), binds, consSubs);
    	
    	constructorSortForm.multiAdd(CRS.NIL_SYMBOL, new Pair<Term,Term>(lst, nil));
    	sortDataSymbols.multiAdd(CRS.LIST_SORT, CRS.NIL_SYMBOL);
		dataConstructors.add(CRS.NIL_SYMBOL);
		constructorSortForm.multiAdd(CRS.CONS_SYMBOL, new Pair<Term,Term>(lst, cons));
		sortDataSymbols.multiAdd(CRS.LIST_SORT, CRS.CONS_SYMBOL);
		dataConstructors.add(CRS.CONS_SYMBOL);
		
		// create booleans
		GenericTerm bool = constant(makeConstructor(CRS.BOOLEAN_SORT));
		trueTerm = constant(trueConstructor);
		falseTerm = constant(falseConstructor);
		constructorSortForm.multiAdd(CRS.TRUE_SYMBOL, new Pair<Term,Term>(bool, trueTerm));
		sortDataSymbols.multiAdd(CRS.BOOLEAN_SORT, CRS.TRUE_SYMBOL);
		dataConstructors.add(CRS.TRUE_SYMBOL);
		constructorSortForm.multiAdd(CRS.FALSE_SYMBOL, new Pair<Term,Term>(bool, falseTerm));
		sortDataSymbols.multiAdd(CRS.BOOLEAN_SORT, CRS.FALSE_SYMBOL);
		dataConstructors.add(CRS.FALSE_SYMBOL);
		
		// create $TryResult[α]
		alpha = makeVariable("alpha", true);
		sortParams.put(CRS.TRYRESULT_SORT, Util.singleton(alpha));
		GenericTerm[] trSubs = new GenericTerm[1]; trSubs[0] = newVariableUse(alpha);
		binds = new Variable[1][]; binds[0] = new Variable[0];
    	GenericTerm tryResult = newConstruction(makeConstructor(CRS.TRYRESULT_SORT), binds, trSubs);
    	
		// $TrySuccess[α]
    	GenericTerm[] tsSubs = new GenericTerm[1];
    	tsSubs[0] = newVariableUse(alpha);
    	binds = new Variable[1][]; binds[0] = new Variable[0];
    	trySuccessTerm = newConstruction(makeConstructor(CRS.TRYSUCCESS_SYMBOL), binds, tsSubs);
    	
    	// $TryFailure[$String]
    	GenericTerm[] tfSubs = new GenericTerm[1];
    	tfSubs[0] = newConstruction(makeConstructor(CRS.STRING_SORT), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
    	binds = new Variable[1][]; binds[0] = new Variable[0];
    	tryFailureTerm = newConstruction(makeConstructor(CRS.TRYFAILURE_SYMBOL), binds, tfSubs);
    	
    	constructorSortForm.multiAdd(CRS.TRYSUCCESS_SYMBOL, new Pair<Term,Term>(tryResult, trySuccessTerm));
		sortDataSymbols.multiAdd(CRS.TRYRESULT_SORT, CRS.TRYSUCCESS_SYMBOL);
		dataConstructors.add(CRS.TRYSUCCESS_SYMBOL);
		constructorSortForm.multiAdd(CRS.TRYFAILURE_SYMBOL, new Pair<Term,Term>(tryResult, trySuccessTerm));
		sortDataSymbols.multiAdd(CRS.TRYRESULT_SORT, CRS.TRYFAILURE_SYMBOL);
		dataConstructors.add(CRS.TRYFAILURE_SYMBOL);
		
		
		// don't create ints and strings, as there are infinitely many of them!
	}
    /** Internal class for the unique boolean values. */
    final private class BooleanConstructor extends AbstractLiteralConstructor
    {
    	boolean value;
    	BooleanConstructor(boolean value)
    	{
    		this.value = value;
    	}
    	@Override
    	final public String symbol()
    	{
    		return value ? CRS.TRUE_SYMBOL : CRS.FALSE_SYMBOL;
    	}
		@Override
        final public Object object()
        {
	        return Boolean.valueOf(value);
        }
		@Override
        final public String literalSort()
        {
	        return CRS.BOOLEAN_SORT;
        }
    }

	// Methods.

    /** Return the current vebosity. */
    public int verbosity()
    {
    	return Util.getInteger(this, VERBOSE_OPTION, 0);
    }
	/**
	 * Create a new construction.
	 * @param constructor to use
	 * @param binders to use
	 * @param subterms under the binders
	 */
	public GenericConstruction newConstruction(Constructor constructor, Variable[][] binders, GenericTerm[] subterms)
	{
		if (subterms == null)
			subterms = GenericTerm.NO_TERMS;
		if (binders == null)
		{
			binders = new Variable[subterms.length][];
			for (int i = 0; i < subterms.length; ++i)
				binders[i] = GenericTerm.NO_BIND;
		}
		if (constructor.symbol().equals(CRS.EVAL_SYMBOL) && subterms.length > 0)
        {
		    // Special $[...] forms.
            return new GenericEvaluator(this, constructor, binders, subterms);
        }
		if (defined(FLEXIBLE))
		{
			GenericConstruction t = new FlexibleGenericConstruction(this, constructor);
			try
			{
				final int arity = subterms.length;
				for (int i = 0; i < arity; ++i)
					t.addSub(binders[i], subterms[i]);
			}
			catch (CRSException e)
			{}
			return t;
		}
		if (subterms.length == 0)
			return new GenericConstant(this, constructor);
		for (int i = 0; i < subterms.length; ++i)
			if (subterms[i] == null)
				warning("Incomplete sort information for "+constructor+": please declare it explicitly (no sort information for argument "+i+")");
		return new FixedGenericConstruction(this, constructor, binders, subterms);
	}
	
	/**
	 * Create a new meta-application.
	 * @param metaVariable to use
	 * @param subterms of meta-application
	 */
	public GenericTerm newMetaApplication(String metaVariable, GenericTerm[] subterms)
	{
		if (subterms == null)
			subterms = GenericTerm.NO_TERMS;
//		if (metaVariable.equals("#Γ62"))
//			message("karma");
		return new GenericMetaApplication(this, metaVariable, subterms);
	}

	/**
	 * Create a new variable occurrence.
	 * @param variable occurrence
	 */
	public GenericTerm newVariableUse(Variable variable)
	{
		return new GenericVariableUse(this, variable, null);
	}

	/**
	 * Return modifiable copy of the combined system environment and system properties.
	 * Each property is stored as the constructor symbol of the mapped stub.
	 * (Helper that uses {@link #newConstruction(Constructor, Variable[][], Term[])}.)
	 */
	public Map<String, GenericTerm> systemEnvironment()
	{
		Map<String, GenericTerm> env = new HashMap<String, GenericTerm>();
		for (Map.Entry<String, String> e : System.getenv().entrySet())
			env.put(e.getKey(), literal(e.getValue()));
		for (Object p : System.getProperties().keySet())
		{
			String key = p.toString();
			env.put(key, literal(System.getProperty(key)));
		}
		return env;
	}

	/**
	 * Create constant.
	 * (Helper that uses {@link #newConstruction(Constructor, Variable[][], Term[])}.)
	 * @param constructor to use
	 */
	final public GenericTerm constant(Constructor constructor)
	{
		return newConstruction(constructor, GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
	}

	/** Helper to generate $Nil aka (). (Helper that uses {@link #newConstruction(Constructor, Variable[][], Term[])}.) */
	final public GenericTerm nil()
	{
		return newConstruction(nilConstructor, GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
	}

	/** Helper to generate $True term. */
	final public GenericTerm truth()
	{
		return trueTerm;
	}

	/** Helper to generate $False term. */
	final public GenericTerm lie()
	{
		return falseTerm;
	}

	/**
	 * Helper to generate $Cons[car, cdr] aka (car;cdr).
	 * (Helper that uses {@link #newConstruction(Constructor, Variable[][], Term[])}.)
	 * @param factory to use for constructor creation
	 * @param carbs binders for car term
	 * @param car head term
	 * @param cdrbs binders for cd term
	 * @param cdr tail term
	 * @return the term $Cons[ carbs . car, cdrbs . cdr ]
	 */
	final public GenericTerm cons(Variable[] carbs, GenericTerm car, Variable[] cdrbs, GenericTerm cdr)
	{
	    Variable[][] bs = {carbs, cdrbs};
	    GenericTerm[] ts = {car, cdr};
	    return newConstruction(makeConstructor(CRS.CONS_SYMBOL), bs, ts);
	}

	/**
	 * Helper to generate @[fun, arg] aka (fun arg).
	 * (Helper that uses {@link #newConstruction(Constructor, Variable[][], Term[])}.)
	 * @param factory to use for constructor creation
	 * @param funbs binders for fun term
	 * @param fun head term
	 * @param argbs binders for cd term
	 * @param arg tail term
	 * @return the term $Cons[ funbs . fun, argbs . arg ]
	 */
	final public GenericTerm app(Variable[] funbs, GenericTerm fun, Variable[] argbs, GenericTerm arg)
	{
	    Variable[][] bs = {funbs, argbs};
	    GenericTerm[] ts = {fun, arg};
	    return newConstruction(makeConstructor(CRS.APPLICATION_SYMBOL), bs, ts);
	}
	
	/**
	 * Just parse the text as a term and return it.
	 * @throws CRSException in case of an error
	 */
	final public GenericTerm parse(String text) throws CRSException
	{
		return parse(new StringReader(text), null, null, 1, 1, null);
	}
	
    /**
     * The indexed constructor for particular symbol.
     * Created if it does not already exist.
     * @param symbol to lookup
     */
    public GenericIndexedConstructor constantConstructor(String symbol)
    {
        GenericIndexedConstructor constructor = symbolConstant.get(symbol);
        if (constructor == null)
        {
            int index = indexedSymbol.size();
            indexedSymbol.add(symbol);
            constructor = new GenericIndexedConstructor(this, index);
            indexConstant.add(constructor);
            symbolConstant.put(symbol, constructor);
        }
        return constructor;
    }
    
	/**
	 * The indexed constructor with particular index.
	 * @param index to lookup
     * @throws IndexOutOfBoundsException if no such constructor was previously created by {@link #constantConstructor(String)}
	 */
	protected Constructor constantConstructor(int index)
	{
	    return indexConstant.get(index);
	}

    /**
     * The symbol of the indexed constructor with particular index.
     * @param index to lookup
     * @throws IndexOutOfBoundsException if no such constructor was previously created by {@link #constantConstructor(String)}
     */
	protected String constantSymbol(int index)
    {
        return indexedSymbol.get(index);
    }

	/** Add a single production linked to a grammar */
	public void addCategoryParser(String key, Parser parser)
	{
		categoryParser.put(key, parser);
	}

	public Constructor makeConstructor(Object object)
	{
	    // Note: This is the only actual implementation of .makeConstructor() used by the generic implementation!
	    if (object instanceof Constructor)
	    {
	        return ((Constructor) object).copy(LinkedExtensibleMap.EMPTY_RENAMING);
	    }
		if (object instanceof String)
		{
//			if (object.toString().startsWith("{"))
//				warning("bad karma: constructor named with {?}?");
		    return constantConstructor((String) object);
		}
		return new ObjectConstructor(object);
	}

    public Constructor makeLiteral(Object object, String sort)
    {
//    	if (object.toString().startsWith("'"))
//    		message("karma?!?");
	    // Note: This is the only actual implementation of .makeLiteral() used by the generic implementation!
    	if (CRS.STRING_SORT.equals(sort))
    	{
    		String string =  (object instanceof Constructor ? ((Constructor) object).symbol() : object.toString()); 
    	    return new LiteralStringConstructor(string);
    	}
    	if (CRS.NUMERIC_SORT.equals(sort))
    	{
    		if (object instanceof Integer || object instanceof Long)
    			return new IntegerConstructor(((Number) object).longValue());
    		if (object instanceof Double || object instanceof Float)
    			return new DoubleConstructor(((Number) object).doubleValue());
    		if (object instanceof BigDecimal)
    			return new BigDecimalConstructor((BigDecimal) object);

    		String string =  (object instanceof Constructor ? ((Constructor) object).symbol() : object.toString()); 
    		BigDecimal big = new BigDecimal(string);
    		try
    		{
    			long n = big.longValueExact();
    			return new IntegerConstructor(n);
    		}
    		catch (ArithmeticException e)
    		{
    			return new BigDecimalConstructor(big);
    		}
    	}
    	if (CRS.BOOLEAN_SORT.equals(sort))
    	{
    		if (object instanceof Boolean)
    			return ((Boolean) object).booleanValue() ? trueConstructor : falseConstructor;
    		
    		String string =  (object instanceof Constructor ? ((Constructor) object).symbol() : object.toString()); 
    		return CRS.TRUE_SYMBOL.equals(string) ? trueConstructor : falseConstructor;
    	}
    	assert false : "Illegal literal sort " + sort;
    	return null;
    }
    
	public Variable makeVariable(String name, boolean promiscuous)
	{
		Variable v = GenericVariable.makeVariable(name, promiscuous);
		if (verbosity() > 9) message("VARIABLE "+v+" CREATED");
		return v;
	}

	public Variable freeVariable(String name, boolean promiscuous, boolean create)
	{	String richName = (promiscuous ? "¹" : "") + name;
		if (create && !globalFreeVariables.containsKey(richName))
			globalFreeVariables.put(richName, makeVariable(name, promiscuous));
		return globalFreeVariables.get(richName);
	}
	
	public Sink makeBuffer(Maker.CallBack callBack)
	{
		return new GenericBuffer(this, environment.containsKey(FLEXIBLE), null).sink(callBack);
	}

	public Parser parser(Factory<? extends Term> factory)
	{
		return this; // handled by parse()
	}

	public Sink parse(Sink sink, String category, Reader reader, String unit, int line, int column, ExtensibleMap<String, Variable> bound) throws CRSException, IOException
	{
		Parser parser = getParser(category);
		int verbosity = Util.getInteger(this, PARSE_VERBOSE, 0);
		parser.setParserVerbose(verbosity > 0);
		if (verbosity >= 10)
			sink = new TraceSink(sink);
		int locations = Util.getInteger(this, PARSE_LOCATIONS, -1);
		if (locations >= 0)
			parser.setParserLocation(locations > 0);
		return parser.parse(sink, category, reader, unit, line, column, bound);
	}

	public Iterable<String> categories()
	{
		return categoryParser.keySet();
	}

	/**
	 * Helper to use reflection to extract the non-terminal names of specific grammar.
	 * @param grammar name to investigate
	 * @return list of all  category names
	 * @throws CRSException if something goes wrong with the reflection...
	 */
	protected Iterable<String> categories(String grammar) throws CRSException
	{
		// Actually just gets the categories from the parser itself...but some implementations override this to use reflection...
		Class<?> c = Util.classForName(this, grammar);
		if (!Parser.class.isAssignableFrom(c))
			throw new CRSException("Specified grammar "+grammar+" is not a parser");
		Parser p = (Parser) Util.classInstance0(this, grammar);
		return p.categories();
	}
	
	/**
	 * Get the parser that handles a particular category.
	 * @param category
	 * @throws CRSException if there is none
	 */
	protected Parser getParser(String category) throws CRSException
	{
		Parser p = categoryParser.get(category);
		return p != null ? p.parser(this) : classicParser.parser(this);
	}

	public void setParserVerbose(boolean verbose)
	{
		set(PARSE_VERBOSE, (verbose ? literal(1) : literal(0)));
	}
	
	public void setParserLocation(boolean captureLocations)
	{
		set(PARSE_LOCATIONS, (captureLocations ? literal(1) : literal(0)));
	}

    // Factory<GenericTerm>...

	public Builder builder()
	{
		return new GenericCRS(this);
	}

    public GenericTerm parse(Reader reader, String category, String unit, int firstLine, int firstColumn, ExtensibleMap<String, Variable> bound) throws CRSException
    {
    	// Collect events from streaming parser into buffer and return the built term.
        try
        {
            Buffer buffer = new Buffer(this);
            if (bound == null) bound = LinkedExtensibleMap.EMPTY_SCOPE;
            parse(buffer.sink(), category, reader, unit, firstLine, firstColumn, bound);
            Term crsTerm = buffer.term(true);
            return (GenericTerm) crsTerm; // should be safe because of the factory passed to buffer...
        }
        catch (IOException e)
        {
            throw new CRSException("IO error...: "+e); // not really possible?
        }
    }

	public GenericTerm literal(String text)
    {
	    return constant(makeLiteral(text, CRS.STRING_SORT));
    }

	public GenericTerm literal(char ch)
    {
		StringBuilder sb = new StringBuilder();
		sb.append(ch);
	    return constant(makeLiteral(sb.toString(), CRS.STRING_SORT));
    }

	public GenericTerm literal(long i)
    {
	    return constant(makeLiteral(Long.valueOf(i), CRS.NUMERIC_SORT));
    }

	public GenericTerm literal(double d)
    {
	    return constant(makeLiteral(Double.valueOf(d), CRS.NUMERIC_SORT));
    }

	public GenericTerm literal(BigDecimal big)
    {
	    return constant(makeLiteral(big, CRS.NUMERIC_SORT));
    }

	public GenericTerm literal(boolean test)
    {
	    return test ? trueTerm : falseTerm;
    }

	public GenericTerm materialize(Copyable thing, boolean discard)
	{
		Term materialized;
		if (thing instanceof Stub)
			materialized = ((Stub) thing).copy(discard, null);
		else
		{
			// Just a Copyable... 
			Buffer buffer = new Buffer(this);
			thing.copy(buffer.sink(), discard, null);
			materialized = buffer.term(true);
		}
		assert materialized instanceof GenericTerm;
		return (GenericTerm) materialized;
	}

	public Sink process(Sink sink, Term directive) throws CRSException
    {
	    return builder().load(sink, directive);
    }

	public void process(Term directive) throws CRSException
    {
	    builder().load(null, directive);
    }

    public boolean defined(String name)
	{
		return environment.containsKey(name);
	}

    public Stub get(String name)
	{
		return environment.get(name);
	}
    
	public synchronized void set(String name, final Stub value)
	{
		if (value != null)
			environment.put(name, value);
		else
			environment.remove(name);
		
		// Cases with side effects.
		if (Factory.GRAMMAR_PROPERTY.equals(name))
		{
			try
			{
				String list = Util.symbol(value).trim();
				java.util.regex.Matcher m = parserSpecificationPattern.matcher(list);
				if (!m.matches())
					throw new UnsupportedOperationException("Malformed parser specification");
				
				int i = 0;
				do
				{
					++i;
					i = parseGrammar(list, i);
				}
				while (list.charAt(i) == ';');
				++i;
				if (i < list.length())
					i = parseGrammar(list, i);
			}
			catch (CRSException e)
			{
				e.printStackTrace();
			}
		}
	}
	/** Helper to parse single grammar name. */
    private int parseGrammar(String list, int i) throws CRSException
    {
    	while (list.charAt(i) == ' ' || list.charAt(i) == ';') ++i;
    	if (list.charAt(i) == '"' || list.charAt(i) == '\'')
    	{
    		char quote = list.charAt(i++);
    		StringBuilder b = new StringBuilder();
    		for (char c = list.charAt(i); c != quote; c = list.charAt(++i)) b.append(c);
    		String grammar = b.toString();
    		addGrammarReally(grammar, null); // TODO: explicit category lists.
    		assert list.charAt(i) == quote;
    		++i;
    		while (list.charAt(i) == ' ') ++i;
    	}
    	return i;
    }

    public Sink sink(Appendable appendable)
    {
    	try
    	{
    		if (appendable == null)
    		{
    			appendable = defined(Factory.OUTPUT_OPTION) ? new FileWriter(Util.symbol(get(Factory.OUTPUT_OPTION))) : System.out;
    		}
    		if (defined(Factory.SIMPLE_TERMS))
    		{
    			// Simple terms explicitly requested...forces default width. 
    			Stub w = environment.get(WIDTH);
    			Stub m = environment.get(MAX_INDENT_LEVEL);
    			return new SimpleTermSink(this, FormattingAppendable.format(appendable, (w==null?100:Integer.parseInt(Util.symbol(w))), 0, (m==null?Integer.MAX_VALUE:Integer.parseInt(Util.symbol(m)))), defined(CANONICAL_VARIABLES));
    		}
    		else if (sinkClass != null)
    		{
    			// Use sink class!
    			Sinker sinker = sinkClass.newInstance();
    			sinker.setFactory(this);
    			sinker.setAppendable(appendable);
    			return sinker;
    		}
    		else
    		{
    			final Appendable a = appendable;
    			return makeBuffer(new CallBack()
    			{
    				@Override
    				public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
    				{
    					try
    					{
    						Map<Variable,String> variableNames = new HashMap<Variable, String>();
    						if (defined(CANONICAL_VARIABLES))
    							variableNames.put(null, "1");
    						term.appendTo(a, variableNames, Integer.MAX_VALUE, false, true, true, null);
    						if (a instanceof Flushable)
    							((Flushable) a).flush();
    					}
    					catch (IOException e)
    					{
    						throw new RuntimeException(e);
    					}
    				}
    			});
    		}
    	}
    	catch (SecurityException e)
    	{
    		throw new RuntimeException(e);
    	}
    	catch (IllegalArgumentException e)
    	{
    		throw new RuntimeException(e);
    	}
    	catch (InstantiationException e)
    	{
    		throw new RuntimeException(e);
    	}
    	catch (IllegalAccessException e)
    	{
    		throw new RuntimeException(e);
    	}
		catch (IOException e)
		{
			throw new RuntimeException(e);
		}
    }

	public synchronized void setSinker(Class<? extends Sinker> sinkClass)
	{
		this.sinkClass = sinkClass;
	}

	// Sorting

	public Iterable<String> sorts()
	{
		return sortParams.keySet();
	}
	
	public Term sortOf(String constructor)
	{
		Set<Pair<Term,Term>> forms = constructorSortForm.multiGet(constructor);
		for (Pair<Term,Term> pair : forms)
		{
			if (sortAliases.containsKey(Util.symbol(pair.head())))
			{
				try
				{
					error("Internal sort panic: sort "+pair.head()+" ");
				}
				catch (CRSException e)
				{
					throw new RuntimeException(e);
				}
			}
			return pair.head();
		}
		return null; 
	}
	
	public Set<String> sortDataSymbols(String sort)
	{
		if (sortAliases.containsKey(sort))
			sort = sortAliases.get(sort);
		return sortDataSymbols.multiGet(sort);
	}

	public boolean isSortConstructor(String sort)
	{
		if (sortAliases.containsKey(sort))
			sort = sortAliases.get(sort);
		return sortParams.containsKey(sort);
	}

	public boolean sortAllowsVariables(String sort)
	{
		if (sortAliases.containsKey(sort))
			sort = sortAliases.get(sort);
		return sortsWithVariables.contains(sort);
	}

	@Override
    public Set<String> sortsWithClosedData()
    {
		return sortsWithClosedData;
    }
	
	public Set<String> getSortsWithVariables()
	{
		return sortsWithVariables;
	}
	
	public Map<String,Term> sortsetFor(String sort)
	{
		if (sort == null)
			return null;
		if (sortAliases.containsKey(sort))
			sort = sortAliases.get(sort);
		return sortsWithSortSet.get(sort);
	}
	
    public String unalias(String sort)
    {
    	return (sortAliases.containsKey(sort) ? sortAliases.get(sort) : sort);
    }
    
	public synchronized void setSortsetFor(String sort, Map<String,Term> sortset)
	{
        if (verbosity() >= 6)
        	message(("Declaring data sort set "+sortset+" for "+sort));
		if (sortAliases.containsKey(sort))
			sort = sortAliases.get(sort);
		if (sortset == null || sortset.isEmpty())
			sortsWithSortSet.remove(sort);
		else
			sortsWithSortSet.put(sort, sortset);
	}

	/**
	 * Creates a plain sort form F[sub1,...,subn] without any binders.
	 * @param symbol the name of the constructor F-- if this name is a meta-variable name, a meta-application is created, otherwise a constrruction
	 * @param args the arguments sub1, ..., subn
	 * @return the created form
	 */
	public GenericTerm newForm(String symbol, GenericTerm[] sorts)
	{
		if (Util.META_VARIABLE_PATTERN.matcher(symbol).matches())
			return newMetaApplication(symbol, sorts);
		else
			return newConstruction(makeConstructor(symbol), null, sorts);
	}
	
    public List<Variable> sortParams(String sort)
    {
    	return sortParams.get(sort);
    }
    
	public Set<Pair<Term,Term>> formsOf(String constructor)
	{
		return constructorSortForm.multiGet(constructor);
	}
	
    public Term formOf(String sort, String constructor)
    {
    	Set<Pair<Term,Term>> sortForms = constructorSortForm.multiGet(constructor);
    	if (sortForms.size() == 1)
    		return sortForms.iterator().next().getValue();
    	if (sort != null)
    		for (Pair<Term,Term> sortForm : sortForms)
    			if (sort.equals(Util.symbol(sortForm.getKey())))
    				return sortForm.getValue();
    	return null;
    }
    
	public boolean isFunction(String constructor)
	{
		return functionConstructors.contains(constructor);
	}

	public boolean isData(String constructor)
	{
		return dataConstructors.contains(constructor);
	}

	/**
	 * Checks whether the given sort (possibly with sort set) or
	 * constructor with sort parameters contains any aliases.
	 * @param form the sort/construction to check
	 * @return true if the construction contains some aliased constructor
	 * @throws CRSException
	 */
	private boolean containsAliases(Term form) throws CRSException
	{
		PropertiesHolder A = Util.propertiesHolder(form);
		if (A != null)
		{
			Iterator<String> names = A.propertyNames().iterator();
			while (names.hasNext())
			{
				String name = names.next();
				if (sortAliases.containsKey(name)) return true;
				if (containsAliases(A.getProperty(name))) return true;
			}
			Iterator<Variable> vars = A.propertyVariables().iterator();
			while (vars.hasNext())
			{
				Variable var = vars.next();
				if (containsAliases(A.getProperty(var))) return true;
			}
		}
		
		if (form == null || form.kind() == Kind.VARIABLE_USE)
			return false;
		else
		{
			if (sortAliases.containsKey(Util.symbol(form))) return true;
			for (int i = 0; i < form.arity(); i++)
				if (containsAliases(form.sub(i))) return true;
			return false;
		}
	}
	
	/**
	 * Applies sort aliases on a given sort or a constructor with sort parameters.
	 * @param form the sort/construction to apply sort aliases on.
	 */
	private GenericTerm applySortAliases(Term form) throws CRSException
	{
		// apply sort aliases on the property set declaration
		PropertiesHolder A = Util.propertiesHolder(form);
		Map<String,Term> sconstraints = null;
		Map<Variable,Term> vconstraints = null;
		if (A != null && A.propertyNames().iterator().hasNext())
		{
			sconstraints = new HashMap<String,Term>();
			Iterator<String> names = A.propertyNames().iterator();
			while (names.hasNext())
			{
				String name = names.next();
				Term value = A.getProperty(name);
				if (sortAliases.containsKey(name)) name = sortAliases.get(name);
				value = applySortAliases(value);
				sconstraints.put(name, value);
			}
		}
		if (A != null && A.propertyVariables().iterator().hasNext())
		{
			vconstraints = new HashMap<Variable,Term>();
			Iterator<Variable> vars = A.propertyVariables().iterator();
			while (vars.hasNext())
			{
				Variable x = vars.next();
				vconstraints.put(x, applySortAliases(A.getProperty(x)));
			}
		}

		switch (form.kind())
		{
			case VARIABLE_USE:
				{
					GenericTerm ret = newVariableUse(form.variable());
					if (sconstraints == null && vconstraints == null) return ret;
					else return new PropertiesConstraintsWrapper(ret, null, sconstraints, vconstraints, null);
				}
			case CONSTRUCTION:
				{
					String symbol = Util.symbol(form);
					if (sortAliases.containsKey(symbol)) symbol = sortAliases.get(symbol);
					GenericTerm[] subs = new GenericTerm[form.arity()];
					Variable[][] binds = new Variable[form.arity()][];
					for (int i = 0; i < form.arity(); i++)
					{
						subs[i] = applySortAliases(form.sub(i));
						binds[i] = form.binders(i);
					}
					GenericTerm ret = newConstruction(makeConstructor(symbol), binds, subs);
					if (sconstraints == null && vconstraints == null) return ret;
					return new PropertiesConstraintsWrapper(ret, null, sconstraints, vconstraints, null);
				}
			case META_APPLICATION:
				{
					String symbol = Util.symbol(form);
					if (sortAliases.containsKey(symbol)) symbol = sortAliases.get(symbol);
					GenericTerm[] subs = new GenericTerm[form.arity()];
					for (int i = 0; i < form.arity(); i++)
						subs[i] = applySortAliases(form.sub(i));
					GenericTerm ret = newMetaApplication(symbol, subs);
					if (sconstraints == null && vconstraints == null) return ret;
					return new PropertiesConstraintsWrapper(ret, null, sconstraints, vconstraints, null);
				}

			// it shouldn't be possible to get here
			default: return null;
		}
	}
	
	/**
	 * Checks whether a given term is actually a sort (or might be):
	 * that is, a term which consists of variables and constructors
	 * only, and none of the constructors are known as term constructors.
	 * Also checks arities, and saves the arities of the symbols it encounters.
	 * If any problem is encountered, "error" is called and false returned
	 * @param sortTerm the term to check for being a sort
	 * @param sortVars any known sort variables; if this is null, then any
	 * 	 encountered variable may be treated as a sort variable
	 * @param boundVars any bound variables, whose declaration may occur in
	 *   the property set of sort (if null, all variable keys in property sets
	 *   are assumed to be bound variables
	 * @param allowSet whether it is allowed for the sort to be equipped with
	 *   a sort set
	 * @param hostSort TODO
	 * @return whether or not the given term is a legal sort
	 * @throws CRSException if sort is not a legal sort and sort checking is strict
	 */
	@SuppressWarnings("unused")
    public boolean checkLegalSort(Term sortTerm, Set<Variable> sortVars, Set<Variable> boundVars, boolean allowSet, Term hostSort) throws CRSException
	{
		if (hostSort == null) hostSort = sortTerm;
		// if it comes with a property set, check whether that's allowed, and
		// whether the property set is legal
		PropertiesHolder A = Util.propertiesHolder(sortTerm);
		if (A != null)
		{
			if (!allowSet && A.propertyNames().iterator().hasNext())
			{
				error("Sort " + hostSort + " error: " + sortTerm + " is equipped with a property set or sort set, but only a basic sort was expected here");
				return false;
			}
			if (!checkLegalSortSet(A, sortVars, boundVars, hostSort)) return false;
		}

		// variables are only allowed if they're sort variables
		if (sortTerm != null && sortTerm.kind() == Kind.VARIABLE_USE)
		{
//			if (sortVars != null && !sortVars.contains(sort.variable()))
//			{
//				error("Sort " + hostSort + " error: " + sort + " is a sort variable, which is either unknown or not permitted here");
//				return false;
//			}
			return true;
		}
		
		// a sort must be either a sort variable, checked above, or have the form
		// C[ι1,...,ιn] with C a sort constructor or -metavariable
		if (sortTerm == null) // || (sort.kind() != Kind.CONSTRUCTION && sort.kind() != Kind.META_APPLICATION)) //Kris
		{
			//error("not a sort: " + sort + " (check sortify warnings).");
			//Kris: avoid errors for now...
			return false;
		}

		// recursive checking; the children of a sort must be sorts, and may not have a sort set
		for (int i = 0; i < sortTerm.arity(); i++)
		{
			if (!checkLegalSort(sortTerm.sub(i), sortVars, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, hostSort)) return false; // TODO: is allowSort parameter safe?
			if (sortTerm.binders(i).length > 0)
			{
				error("sort " + sortTerm + " contains binders, which is illegal.");
				return false;
			}
		}
		
		// check the arity of the constructor
		String sort = Util.symbol(sortTerm);
		int arity = sortTerm.arity();
		
		if (sortAliases.containsKey(sort)) sort = sortAliases.get(sort);
		if (sortParams.containsKey(sort) && sortParams.get(sort).size() != arity)
		{
			error("sort " + sortTerm + " used with inconsistent arity (was " + sortParams.get(sort).size() + " previously)");
			return false;
		}
		if (!sortParams.containsKey(sort))
		{
			List<Variable> params = new ArrayList<Variable>(arity);
			for (int i = 0; i < arity; ++i)
				params.add(sortTerm.sub(i).variable());
			sortParams.put(sort, params);
		}
		
		// check whether it's ever used as a term constructor
		if (!ALLOWSORTOVERLOADING && constructorSortForm.multiContainsKey(sort))
		{
			error("sort " + sortTerm + " used both as a sort constructor " +
		          "and a term constructor.");
			return false;
		}
		return true;
	}
	
	/**
	 * Checks whether a given property set is a legal sort set (or might be):
	 * that is, a set of entries A : sort is a legal where A is the name of
	 * a sort constructor of arity 0 and sort is a legal sort
	 * @param A the property set to check for legality
	 * @param sortVars a set of variables which are known sort variables; if
	 * 	 this is null all encountered variables are counted as legal sorts
	 * @param boundVars any bound variables, whose declaration may occur in
	 *   the property set of sort (if null, all variable keys in property sets
	 *   are assumed to be bound variables
	 * @param hostSort TODO
	 * @return whether or not the given property set is a legal sort set
	 * @throws CRSException an error is given if sort is not a legal sort,
	 *   which may cause an exception to be thrown if all errors are considered
	 *   fatal
	 */
	public boolean checkLegalSortSet(PropertiesHolder A, Set<Variable> sortVars, Set<Variable> boundVars, Term hostSort) throws CRSException
	{
		if (A == null) return true;
		/*//Kris: need to rethink since we are using meta-variables as sorts
		if (A instanceof PropertiesConstraintsWrapper &&
			((PropertiesConstraintsWrapper)A).hasUnknownKeys())
		{
			error("sort set " + A + "is illegal: only sort constructors are allowed as keys in property sets of sort declarations");
			return false;
		}
		*/
		Set<Variable> emptyset = LinkedExtensibleSet.EMPTY_VARIABLE_SET;
		for (Pair<Term,Term> p : Util.allProperties(A, this))
		{
			Term keySort = p.head();
			Term valueSort = p.tail();
			if (keySort.kind() == Kind.VARIABLE_USE)
			{
				Variable x = keySort.variable();
				if (!boundVars.contains(x))
				{
					error("sort set " + A + " contains illegal variable key "+x);
					return false;
				}
			}
			else if (!checkLegalSort(keySort, sortVars, emptyset, true, hostSort))
				return false;
			else
			{
				if (!checkLegalSort(valueSort, sortVars, emptyset, true, hostSort))
					return false;
			}
		}
		return true;
	}

	/**
	 * Check recursively whether a sort can be assigned to a term.
	 * @param sort to check for
	 * @param term to check
	 * @param boundSorts sorts of bound variables in context
	 * @throws CRSException if the sort does not fit
	 */
	public void checkSortOf(Term sort, Term term, ExtensibleMap<Variable, Term> boundSorts, Map<Variable, Term> freeSorts, Map<String,Term> variableSorts) throws CRSException
    {
		error("Cannot check sorts dynamically yet");
	    switch (term.kind())
	    {
	    	case CONSTRUCTION : {
	    		
	    		break;
	    	}
	    	case VARIABLE_USE : {
	    		Variable v = term.variable();
	    		if (boundSorts.containsKey(v))
	    		{
	    			//Term variableSort = boundSorts.get(v);
	    		}
	    		break;
	    	}
	    	case META_APPLICATION :
	    }
    }
	/**
	 * Applies sort aliases on a given sort or constructor with sort parameters
	 * IF this sort (construction) contains aliases; if not, returns the orginal
	 * construction
	 * @param form the sort or sort construction to apply aliases on
	 * @return either the unmodified sort, or a copy with sort variables instantiated
	 */
	public Term renameSortConstructors(Term original) throws CRSException
	{
		if (!containsAliases(original)) return original;
		else return applySortAliases(original);
	}

	/**
	 * Returns whether the given declaration sort ::= form duplicates a pair
	 * in the given set of existing sort declarations; this takes
	 * polymorphism into account, in that a declaration is considered a
	 * duplicate if it unifies with an existing declaration.
	 * @param sort a sort
	 * @param form a constructor with sorts as arguments
	 * @param existing a set of sort/form pairs
	 * @return 1 if it truly duplicates a pair in existing, 2 if it unifies
	 *   with an existing declaration, 0 if there is no duplication
	 *   (note that it cannot both unify with AND truly duplicate an
	 *   existing pair, as the existing pairs are supposed to be
	 *   non-duplicating)
	 * @throws CRSException if sort is not a well-formed sort, or the
	 *   children of form are not well-formed sorts
	 */
	private int duplicateDeclaration(Term sort, Term form, Set<Pair<Term,Term>> existing) throws CRSException
	{
		if (existing == null) return 0;
		// for each of the existing pairs, check whether it corresponds with <sort,form>
		for (Pair<Term,Term> pair : existing)
		{
			Term otherSort = pair.head();
			Term otherForm = pair.tail();
			
			// if it has a different full arity, it does not correspond
			boolean dangerous = true;
			if (otherForm.arity() != form.arity()) dangerous = false;
			for (int i = 0; i < form.arity() && dangerous; i++)
				if (otherForm.binders(i).length != form.binders(i).length) dangerous = false;
			if (!dangerous) continue;

			// <otherSort,otherForm> does not unify with <sort,form>, it does not correspond
			Map<Variable,Term> theta = new HashMap<Variable,Term>();
			if (!Unifier.unify_help(sort, otherSort, theta, this)) continue;
			for (int i = 0; i < form.arity() && dangerous; i++)
			{
				if (!Unifier.unify_help(form.sub(i), otherForm.sub(i), theta, this)) { dangerous = false; continue; }
				Variable[] otherBinds = otherForm.binders(i);
				PropertiesHolder otherProp = Util.propertiesHolder(otherForm.sub(i));
				Variable[] binds = form.binders(i);
				PropertiesHolder prop = Util.propertiesHolder(form.sub(i));
				for (int j = 0; j < binds.length && dangerous; j++)
				{
					Variable x = binds[j], y = otherBinds[j];
					Term xsort = prop.getProperty(x);
					Term ysort = otherProp.getProperty(y);
					if (!Unifier.unify_help(xsort, ysort, theta, this)) dangerous = false;
				}
			}
			if (dangerous)
			{
				Set<Variable> vars = new HashSet<Variable>();
				for (Entry<Variable,Term> e : theta.entrySet())
				{
					if (e.getValue().kind() != Kind.VARIABLE_USE) return 2;
					vars.add(e.getValue().variable());
				}
				if (vars.size() == theta.size())
					return 1;
				return 2;
			}
		}
		return 0;
	}
	
	public synchronized void setSortForm(Term sortTerm, Set<Variable> sortParams, Term form, boolean function, boolean override) throws CRSException
    {
		if (verbosity() > 1)
		{
//			String formText = "setSortForm("+sortTerm+", "+sortParams+", "+form+")";
//			if (Util.hasProperty(form, "$$STANDARDIZED"))
//				message("bad karma: completer standardized");
//			if (formText.contains("¬"))
//				message("bad karma: " + formText);
//			if (formText.contains("FT-item-intersect2-record"))
//				warning("karma");
	    	if (verbosity() >= 6)
	    	{
	    		if (function)
	    			message(("Declaring function sort form " + form + " :: " + sortTerm));
	    		else
	    			message(("Declaring data sort form "+sortTerm+" ::= "+form));
	    	}
		}
    	if (sortTerm == null)
    	{
    		if (verbosity() >= 6)
            	message("bad karma: null sort");
    		return;
    	}
///		if ("Text".equals(Util.symbol(sortTerm)))
///        	message("karma: Text sort!");
    	if (sortParams == null)
    	{
    		sortParams = new HashSet<Variable>();
    		sortTerm.addFree(sortParams, LinkedExtensibleSet.EMPTY_VARIABLE_SET, false, null);
    	}
    	
    	if (!override && !checkPredeclaredConstructors(sortTerm, form, !function))
    	{
    		error("declaration " + (function ? form + " :: " + sortTerm : sortTerm + " ::= " + form) + " duplicates pre-declared constructor.");
    		return;
    	}
    	if (form instanceof PropertiesConstraintsWrapper)
    	{
    		PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) form;
    		if (pcw.propertiesRef != null)
        		error("declaration " + (function ? form + " :: " + sortTerm : sortTerm + " ::= " + form) + " has a properties reference?!?.");
    	}
    	
    	sortTerm = renameSortConstructors(sortTerm);
    	form = renameSortConstructors(form);
		String sort = Util.symbol(sortTerm);
    	if (sortTerm.kind() == Kind.VARIABLE_USE)
    	{
    		if (!function)
        		error("declaration " + sortTerm + " ::= " + form + " not permitted.");
    		sort = SPECIAL_VARIABLE_KEY;
    	}
    	String formSymbol = Util.symbol(form);
    	boolean hasSortSet = Util.propertiesHolder(sortTerm) != null && Util.propertiesHolder(sortTerm).propertyNames().iterator().hasNext();
    	boolean hasFormSet = Util.propertiesHolder(form) != null && Util.propertiesHolder(form).propertyNames().iterator().hasNext();
    	if (hasSortSet && hasFormSet)
    		hasFormSet = false; //warning("property sets on both the sort and form of " + form + " :: " + sortTerm + " undefined");
    	
    	// CHECK 1: legality of sort (including sort set).
    	if (!checkLegalSort(sortTerm, sortParams, LinkedExtensibleSet.EMPTY_VARIABLE_SET, !function, null))
    	{
    		error("encountered error while checking legality of declaration " + form + " :: " + sortTerm);
    		return;
    	}
    	if (!function)
    	{
    		Set<Variable> args = new HashSet<Variable>();
    		for (int i = 0; i < sortTerm.arity(); i++)
    		{
    			if (sortTerm.sub(i).kind() != Kind.VARIABLE_USE ||
    				args.contains(sortTerm.sub(i).variable()))
    			{
    				error("illegal declaration of data symbol: arguments to sort " + Util.symbol(sortTerm) + " should be distinct type variables.");
    				return;
    			}
    			else args.add(sortTerm.sub(i).variable());
    		}
    		if (args.size() != sortParams.size())
    			error("sort declaration: " + sortTerm + " - does not contain all bound sort variables!");
    		if (args.size() != 0 && hasSortSet)
    			error("sort declaration: " + sortTerm + " - it is not allowed for a polymorphic sort to be equippred with a sort set.");
    	}
    	
    	// CHECK 2: if the form is a variable, this should be a data symbol; if so, save it and return
    	if (form.kind() == Kind.VARIABLE_USE)
    	{
    		if (function)
    			error("cannot define a function with a variable as the root symbol!");
    		sortsWithVariables.add(sort);
    		if (hasFormSet)
    			warning("ignoring property set on variable");
    		if (hasSortSet)
        	{
        		Map<String,Term> sortSet = new HashMap<String,Term>();
        		Iterator<String> it = Util.propertiesHolder(sortTerm).propertyNames().iterator();
        		while (it.hasNext())
        		{
        			String key = it.next();
        			Term value = Util.propertiesHolder(sortTerm).getProperty(key);
        			sortSet.put(key, value);
        		}
        		sortsWithSortSet.put(Util.symbol(sortTerm), sortSet);
        	}
        	return;
    	}
    	
    	// CHECK 3: the form should be a meta-application or a variable!
    	// TODO: form should be meta-application but for now we allow constructions, too...
    	
    	// CHECK 4a: the form has arguments that must all be legal sorts.
   		for (int i = 0; i < form.arity(); i++)
   		{
   			GenericTerm sub = (GenericTerm) form.sub(i);
   			Variable[] binders = form.binders(i);
   			if (sub == null || binders == null)
   				warning("Incomplete sort information for "+formSymbol+": please declare explicitly (bad binders for sort argument "+i+")");
   			Set<Variable> binds = new HashSet<Variable>();
			if (binders != null) for (Variable v : binders) binds.add(v);
			
			if (!checkLegalSort(sub, sortParams, binds, true, sortTerm)) return; // TODO: is allowSort parameter safe?
    		
   			// check whether all binders are typed, and only binders are typed
   			PropertiesHolder properties = Util.propertiesHolder(sub);

			if (properties != null)
			{
				for (Variable v : properties.propertyVariables())
				{
					if (sortParams.contains(v))
					{
						error("sort " + sortTerm + " form "+form+" uses a sort variable as a property set key");
						return;
					}
					if (!binds.contains(v))
					{
						error("sort "+sortTerm+" form "+form+" gives type for irrelevant binder");
						return;
					}
					binds.remove(v);
				}
			}
			if (!binds.isEmpty())
			{
				error("sort "+sortTerm+" form "+form+" fails to provide type for binders "+binds);
				return;
			}
   		}
    	// CHECK 4b: the form has property key-value pairs that must all be legal sorts.
   		if (hasFormSet)
   		{
   			if (!checkLegalSortSet(Util.propertiesHolder(form), sortParams, LinkedExtensibleSet.EMPTY_VARIABLE_SET, null)) return;
   		}
    	
    	// CHECK 5: is the constructor not duplicating an existing constructor?
   		if (!override)
   		{
   			int duplicateTest = duplicateDeclaration(sortTerm, form, constructorSortForm.multiGet(formSymbol));
   			boolean duplicate = false;
   			if (duplicateTest == 1)
   			{
   				//warning("constructor " + formSymbol + " is declared more than once.");
   				duplicate = true;
   			}
   			if (duplicateTest == 2)
   			{
   				error("constructor " + formSymbol + " defined multiple times, with unifiable types.");
   				duplicate = true;
   			}
   			if (duplicate) return;
   		}
   	
		// All checks done!
		
		// Add correct construction form.
   		if (constructorSortForm.multiContainsKey(formSymbol))
   		{
   			if (override)
   			{
   				// Remove it first
   				constructorSortForm.remove(formSymbol);
   			}
			constructorSortForm.multiAdd(formSymbol, new Pair<Term,Term>(sortTerm, form));
   		}
   		else
   		{
   			constructorSortForm.multiAdd(formSymbol, new Pair<Term,Term>(sortTerm, form));
   		}
   		
//   		Set<Pair<Term,Term>> sortForms;
//   		if (!override && constructorSortForm.multiContainsKey(formSymbol))
//   		{
//   			sortForms = constructorSortForm.multiGet(formSymbol);
//   			//if (hasSortSet) sortForms.add(new Pair<Term,Term>(literal(Util.symbol(sort)), form));
//   			//else
//   			sortForms.add(new Pair<Term,Term>(sortTerm, form));
//   		}
//    	else
//    	{
//    		sortForms = new HashSet<Pair<Term,Term>>();
//    		sortForms.add(new Pair<Term,Term>(sortTerm, form));
//    		constructorSortForm.multiAddAll(formSymbol, sortForms);
//    	}
    	
    	// if it's a data symbol, remember it as a generator for this sort constructor separately
    	if (!function)
    	{
    		if (sortTerm.kind() == Kind.VARIABLE_USE)
    			error("Cannot deal with data constructor " + form + " which has an unknown sort.");
    		else
    			sortDataSymbols.multiAdd(Util.symbol(sortTerm), Util.symbol(form));
    	}
    	
    	// if the sort has a sort set, remember this set!
    	if (hasSortSet)
    	{
    		Map<String,Term> sortSet = new HashMap<String,Term>();
    		Iterator<String> it = Util.propertiesHolder(sortTerm).propertyNames().iterator();
    		while (it.hasNext())
    		{
    			String key = it.next();
    			Term value = Util.propertiesHolder(sortTerm).getProperty(key);
    			sortSet.put(key, value);
    		}
    		sortsWithSortSet.put(Util.symbol(sortTerm), sortSet);
    	}
    	
		String symbol = Util.symbol(form);
		if ((function && dataConstructors.contains(symbol)) ||
			(!function && functionConstructors.contains(symbol)))
		{
			error("symbol " + symbol + " is declared both as a data "+
					  "symbol and a defined symbol!");
		}
		if (function) functionConstructors.add(symbol);
		else dataConstructors.add(Util.symbol(form));
    }
    
    public Set<String> getSortedConstructors()
    {
    	return constructorSortForm.multiKeySet();
    }

	public synchronized void setSortAlias(String sort, String alias) throws CRSException
	{
		//m("ALIAS "+sort+" == "+alias);
		if (!sortParams.containsKey(sort))
			sortParams.put(sort,  new ArrayList<Variable>());
		else if (sortParams.get(sort).size() > 0)
			error(Builder.SORT_ALIAS_SYMBOL+" cannot be used on polymorphic sorts ("+sort+")");
		if (!sortParams.containsKey(alias))
			sortParams.put(alias,  new ArrayList<Variable>());
		else if (sortParams.get(alias).size() > 0)
			error(Builder.SORT_ALIAS_SYMBOL+" cannot be used on polymorphic sorts ("+alias+")");

		String realSort = sort;
		String realAlias = alias;
		
		// Compute transitive closure.
		while (sortAliases.containsKey(realSort)) realSort = sortAliases.get(realSort);
		while (sortAliases.containsKey(realAlias)) realAlias = sortAliases.get(realAlias);
		if (realSort.equals(realAlias))
			return; // redundant

		// Update the map.
		for (Map.Entry<String,String> p : sortAliases.entrySet())
		{
			String s = p.getValue();
			if (realAlias.equals(s))
				p.setValue(realSort);
		}
		sortAliases.put(realAlias, realSort);

		// Move sort information from the alias to the sort.
		sortParams.remove(realAlias); // already dentical
		
		if (sortDataSymbols.multiContainsKey(realAlias))
		{
			Set<String> aliasConstructors = sortDataSymbols.multiGet(realAlias);
			sortDataSymbols.multiAddAll(realSort, aliasConstructors);
			sortDataSymbols.remove(realAlias);
		}
		
		if (sortsWithVariables.contains(realAlias) || sortsWithVariables.contains(realSort))
		{
			sortsWithVariables.remove(realAlias);
			sortsWithVariables.add(realSort);
		}
		
		if (sortsWithSortSet.containsKey(realAlias))
		{
			if (sortsWithSortSet.containsKey(realSort))
				warning("Aliasing sorts with property sorts ("+realSort+" and "+realAlias+") TODO: implement unification!");
			else
				sortsWithSortSet.put(realSort, sortsWithSortSet.remove(realAlias));
		}

		for (Map.Entry<String, Set<Pair<Term, Term>>> e : constructorSortForm.entrySet())
		{
	    	// m("REDOING SORTS FOR "+e.getKey()); //XXX
			Set<Pair<Term,Term>> oldSortForms = e.getValue();
			Set<Pair<Term,Term>> newSortForms = new HashSet<Pair<Term,Term>>();
			
			for (Pair<Term,Term> olde : oldSortForms)
			{
				Term s = renameSortConstructors(olde.head());
				Term t = renameSortConstructors(olde.tail());
				
				// check whether the renamed s, t clash with anything
				int duplicateTest = duplicateDeclaration(s, t, newSortForms);
		   		if (duplicateTest == 2)
		   		{
		   			error("Aliasing " + realAlias + " to " + realSort + " leads to a clash: constructor " + e.getClass() + " occurs with unifiable type declarations.");
		   			continue;
		   		}
				
				if (duplicateTest == 0)
					newSortForms.add(new Pair<Term,Term>(s,t));
			}
			e.setValue(newSortForms);
		}
	}

	/**
	 * Check whether the given declaration tries to extend a pre-declared sort,
	 * or override a pre-declared constructor.
	 * @return true if there is no duplication problem with the given declaration
	 */
	private boolean checkPredeclaredConstructors(Term sort, Term form, boolean data)
	{
		if (form.kind() == Kind.CONSTRUCTION)
		{
			String symbol = Util.symbol(form);
			if (symbol.equals(CRS.NIL_SYMBOL)) return false;
			if (symbol.equals(CRS.CONS_SYMBOL)) return false;
			if (symbol.equals(CRS.TRUE_SYMBOL)) return false;
			if (symbol.equals(CRS.FALSE_SYMBOL)) return false;
			if (form.constructor().literalSort() != null) return false; 
		}
		if (data)
		{
			String symbol = Util.symbol(sort);
			if (symbol.equals(CRS.LIST_SORT)) return false;
			if (symbol.equals(CRS.BOOLEAN_SORT)) return false;
			if (symbol.equals(CRS.STRING_SORT)) return false;
			if (symbol.equals(CRS.NUMERIC_SORT)) return false;
		}
		return true;
	}

	/**
	 * 
	 * @param patterns
	 * @param contractae
	 */
    public void reform(Iterable<Pattern> patterns, Iterable<Contractum> contractae)
    {
    	// First reinitialize with all candidates for both kinds of symbol!
    	//dataConstructors.clear();
    	functionConstructors.clear();
    	final ExtensibleSet<Variable> nobound = LinkedExtensibleSet.EMPTY_VARIABLE_SET;

    	// Process patterns to get certain functions and data.
    	final Visitor patternArgumentVisitor = new Visitor()
    	{
    		@Override
    		public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
    		{
    			if (start)
    				dataConstructors.add(Util.symbol(construction));
    		}
    	};
    	for (final Pattern pattern : patterns)
    	{
    		assert pattern.kind() == Kind.CONSTRUCTION : "Patterns MUST be constructions...";
    		String symbol = Util.symbol(pattern);
    		functionConstructors.add(symbol);
    		dataConstructors.remove(symbol);
    		try
			{
        		pattern.constructor().visit(patternArgumentVisitor, nobound);
        		for (int i = 0; i < pattern.arity(); ++i)
        		{
        			ExtensibleSet<Variable> bound = nobound.extend(pattern.binders(i));
            		pattern.sub(i).visit(patternArgumentVisitor, bound);
        		}
			}
			catch (CRSException e)
			{}
    	}
    	
    	// Process contractae to add any missing data constructors.
    	final Visitor contractumVisitor = new Visitor()
    	{
    		@Override
    		public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
    		{
    			String symbol = Util.symbol(construction);
    			if (start && !functionConstructors.contains(symbol))
    				dataConstructors.add(symbol);
    		}
    	};
		try
		{
			for (final Contractum contractum : contractae)
				contractum.visit(contractumVisitor, nobound);
		}
		catch (CRSException e)
		{}

    	// Remove ambiguous symbols.
    	List<String> dataSymbols = new ArrayList<String>(dataConstructors);
    	for (String symbol : dataSymbols)
    	{
    		if (functionConstructors.contains(symbol))
    		{
    			dataConstructors.remove(symbol);
    			functionConstructors.remove(symbol);
    		}
    	}
    }

    /*
	public void removeSorts(Set<String> names)
	{
		Set<Constructor> members = new HashSet<Constructor>();
		for (String name : names)
		{
			members.addAll(sortMembers.multiGet(name));
			sortMembers.remove(name);
			sortsWithVariables.remove(name);
		}
		for (Constructor c : members)
		{
			constructorSortForm.remove(c.symbol());
		}
	}
	*/

	public void addGrammar(String grammar, Collection<String> categories) throws CRSException
	{
		addGrammarReally(grammar, categories);
		if (!defined(GRAMMAR_PROPERTY))
		{
			set(GRAMMAR_PROPERTY, literal("{'"+grammar+"'}"));
		}
		else
		{
			String allGrammars = Util.symbol(get(GRAMMAR_PROPERTY)).trim();
			allGrammars = allGrammars.substring(0, allGrammars.length()-1) + ";'" + grammar + "'}";
			set(GRAMMAR_PROPERTY, literal(allGrammars));
		}
	}

	/** Register the indicated parser for the indicated categories. */
	private void addGrammarReally(String grammar, Collection<String> categories) throws CRSException
	{
		// Get a parser class instance.
		Class<?> c = Util.classForName(this, grammar);
		if (!Parser.class.isAssignableFrom(c))
			throw new CRSException("Grammar "+grammar+" is not a parser class");
		Parser p = (Parser) Util.classInstance0(this, grammar);
		if (categories != null)
		{
			for (String category : categories)
				categoryParser.put(category, p);
		}
		else
		{
			// Extract categories from net.sf.crsx.Parser implementation.
			for (String category : p.categories())
				if (!categoryParser.containsKey(category))
					categoryParser.put(category, p);
		}
	}

	public boolean hasGrammar(String grammar, Collection<String> categories)
	{
		if (categories == null)
		{
			// Merely check that some category is supported by the parser...
			for (Parser p : categoryParser.values())
				if (p.getClass().getName().equals(grammar))
					return true;
			return false;
		}
		else
		{
			// Check that the specific categories are supported.
			for (String c : categories)
			{
				Parser p = categoryParser.get(c);
				if (p == null || !p.getClass().getName().equals(grammar))
					return false;
			}
			return true;
		}
	}

	public void warning(String message, String... pretext)
	{
		String pre = (pretext.length == 0 ? "Warning: " : pretext[0]);
		System.err.println(pre + message);
	}

	public void error(String message, String... pretext) throws CRSException
	{
		String pre = (pretext.length == 0 ? "Error-- " : pretext[0]);
		if (defined(Factory.ALL_FATAL_OPTION))
			throw new CRSException(assembleErrors(pre+message+"\n(All errors considered fatal, processing cannot continue.)"));
		else
			errors.add(pre + message);
	}

	public void errorCheck(String message) throws CRSException
	{
		if (!errors.isEmpty())
			throw new CRSException(assembleErrors(message));
	}

	public void fatal(String message, String... pretext) throws CRSException
	{
		String pre = (pretext.length == 0 ? "Error: " : pretext[0]);
		throw new CRSException(assembleErrors(pre+message+"\n(Fatal error, processing cannot continue.)"));
	}
	
    public void message(String text)
    {
    	System.out.println("// "+text.replace("\n", "\n//- "));
    }
    
	/** Build string with all delayed error messages. */
	private String assembleErrors(String finalMessage)
	{
		StringBuilder sb = new StringBuilder();
		for (String e : errors)
			sb.append(e + "\n");
		sb.append(finalMessage);
		return sb.toString();
	}
	
	final static String FRESH_PREFIX = "#-$";

	/**
	 * Return fresh meta-variable name which becomes bound (with arity 0) in metaSorts.
	 * @param metaSorts where meta-variables are bound
	 * @return the fresh meta-variable name (with fresh binding in metaSorts)
	 */
	static String freshMeta(Map<String,Pair<String,Term[]>> metaSorts)
	{
		for (int i = 0; i < 10000; ++i)
		{
			String key = FRESH_PREFIX+i;
			if (!metaSorts.containsKey(key))
			{
				metaSorts.put(key, new Pair<String,Term[]>(null, GenericTerm.NO_TERMS));
				return key;
			}
		}
		assert false : "Tried to generate more than 10000 dummy $Sort meta-variables!";
		return null;
	}
	
	// Object...
	
	public String toString()
	{
		StringWriter w = new StringWriter();
		w.append(super.toString());
		w.append(" "+environment);
		return w.toString();
	}
}
