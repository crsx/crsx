/* Copyright © 2006, 2012 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.Closeable;
import java.io.FileWriter;
import java.io.Flushable;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Match;
import net.sf.crsx.MetaAnalyzer;
import net.sf.crsx.Observable;
import net.sf.crsx.Observer;
import net.sf.crsx.Path;
import net.sf.crsx.Pattern;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.generic.sort.Sorter;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.ConstructorFilterSink;
import net.sf.crsx.util.ContextStack;
import net.sf.crsx.util.EmptyIterable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.FunctionFilterSink;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.PropertiesConstructor;
import net.sf.crsx.util.Quad;
import net.sf.crsx.util.Sinker;
import net.sf.crsx.util.SortedHashMultiMap;
import net.sf.crsx.util.SortedMultiMap;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.TopEmptyListFilterSink;
import net.sf.crsx.util.Util;

/**
 * Generic (naïve interpretive) implementation of {@link CRS} used as the default by {@link GenericFactory}.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericCRS.java,v 3.30 2014/01/06 03:11:09 krisrose Exp $
 */
public class GenericCRS implements CRS, Builder, Constructor, Term, Observable
{
	// State.

	/** Factory... */
	final GenericFactory factory;

	/** Rules by name. */
	final private Map<String, GenericRule> ruleByName;

	/** Rules by constructor - may not include all rules! */
	final private Map<Constructor, ArrayList<GenericRule>> rulesByConstructor;
	
	/** Whether rule by constructor structure is current. */
	private boolean rulesByConstructorDirty;

	/** The global variables. */
	final Set<Variable> global = new HashSet<Variable>();

	/** CRS name. */
	private String name;

	/** How verbose to be about rewritings. */
	private int verbosity;
	private int verbosity_depth;

	/** "Standard output" for CRS. */
	private Appendable appendable;

	/** Where verbose messages are dropped. */
	private Appendable verboseWriter;

	/** Visit count used by {@link #normalize(Term)}. */
	long visitCount;

	/** Match count used by {@link #normalize(Term)}. */
	long matchCount;

	/** Rewrite count used by {@link #normalize(Term)}. */
	private long rewriteCount;

	/** Substitution copy count... */
	long substituteByCopy;

	/** Substitution count. */
	long substituteProper;

	/** Time in ms when current normalization started. */
	long rewriteStartMS;

	/** System used for preprocessing all rules. */
	private GenericCRS metaCRS;

	/** System used for post-procesing normalized result. */
	private GenericCRS printCRS;

	/** Whether the CRS is locked for further rules. */
	boolean locked;

	/** Rule contractions we're watching for... */
	final Set<String> watchedRules = new HashSet<String>();

	/** List of observers. */
	final List<Observer> observers = new ArrayList<Observer>();

	/** Last result of any $Dispatchify, in {@link Completer} "standard form". */
	List<Quad<GenericTerm, GenericTerm, Constructor, Map<String, List<Term>>>> lastDispatchify;

	// Constructor.

	/**
	 * Anonymous constructor.
	 * Uses fresh {@link GenericFactory}
	 */
	public GenericCRS()
	{
		this(new GenericFactory());
	}

	/**
	 * Create new CRS.
	 * The created CRS has no rules and no name.
	 * @param factory to use for parsing and term creation
	 */
	public GenericCRS(GenericFactory factory)
	{
		this.factory = factory;
		ruleByName = new LinkedHashMap<String, GenericRule>();
		rulesByConstructor = new HashMap<Constructor, ArrayList<GenericRule>>();
	}

	/**
	 * Create new CRS from existing one.
	 * @param factory to use for parsing and term creation
	 * @param name of CRS
	 * @param rules of CRS (indexed by name)
	 */
	public GenericCRS(GenericFactory factory, String name, Map<String, GenericRule> rules)
	{
		this(factory);
		this.name = name;
		ruleByName.putAll(rules);
		rulesByConstructorDirty = true;
	}

	// Methods.

	/** Helper to write to the verbose output. */
	void verboseWrite(String s)
	{
		try
		{
			if (verboseWriter != null)
			{
				verboseWriter.append(s);
				if (verboseWriter instanceof OutputStreamWriter)
					((OutputStreamWriter) verboseWriter).flush();
			}
		}
		catch (IOException e)
		{
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}

	/**
	 * Add a new rule from the $Rule directive...
	 * @param directive with rule term
	 * @param prefix for rule name
	 * @throws CRSException if an unrecoverable error occurs
	 */
	void addRule(Term directive, String prefix) throws CRSException
	{
		// $Rule[Pattern, Contractum]
		// $Rule[Name, Pattern, Contractum]
		// $Rule[Name[Lax], Pattern, Contractum]
		String name = Util.symbol(directive.sub(0));
		switch (directive.arity())
		{
			case 2 : {
				if (!name.startsWith(prefix))
					name = prefix + name;
				String base = name;
				for (int i = 1; ruleByName.containsKey(name = base + "-" + i); ++i);
				if (name.endsWith("-11") && !factory.defined(Factory.ALLOW_UNNAMED_RULES_OPTION))
					warning("More than 10 unnamed " + base + " rules - consider individual rule names!");
				addRule(name, (Pattern) directive.sub(0), (Contractum) directive.sub(1), LinkedExtensibleMap.EMPTY_NAMED_LIST);
				return;
			}
			case 3 : {
				if ("-".equals(name))
				{
					name = Util.symbol(directive.sub(1));
					if (!name.startsWith(prefix))
						name = prefix + name;
					String base = name;
					for (int i = 1; ruleByName.containsKey(name = base + "-" + i); ++i);
					if (name.endsWith("-11") && !factory.defined(Factory.ALLOW_UNNAMED_RULES_OPTION))
						warning("More than 10 unnamed " + base + " rules - consider individual rule names!");
				}
				else
				{
					if (!name.startsWith(prefix))
						name = prefix + name;
					if (ruleByName.containsKey(name))
					{
						error("Duplicate explicit rule name (second rule named " + name + " ignored)");
						return;
					}
				}
				Term nameTerm = directive.sub(0);
				Map<String, List<Term>> options = new HashMap<String, List<Term>>();
				for (int i = 0; i < nameTerm.arity(); ++i)
				{
					Term optionTerm = nameTerm.sub(i);
					String optionName = Util.symbol(optionTerm);
					if (optionName.startsWith(CRS.EVAL_SYMBOL))
						optionName = optionName.substring(CRS.EVAL_SYMBOL.length());
					List<Term> terms;
					if (options.containsKey(optionName))
						terms = options.get(optionName);
					else
						options.put(optionName, (terms = new ArrayList<Term>()));
					for (int j = 0; j < optionTerm.arity(); ++j)
						terms.add(optionTerm.sub(j));
				}
				addRule(name, (Pattern) directive.sub(1), (Contractum) directive.sub(2), options);
				return;
			}
		}
		error("CRS contains bad rule (rule '" + directive + "' ignored)");
		return;
	}

	/**
	 * Add a rewrite rule to the CRS under construction.
	 * @param name of the rule (not '-')
	 * @param pattern with rule pattern
	 * @param contractum with rule contractum
	 * @param options arguments to name as constructor symbol to list of argument terms
	 * @throws CRSException if rules cannot be added or "lhs → rhs" is not a proper rule in the CRS
	 */
	void addRule(String name, Pattern pattern, Contractum contractum, Map<String, List<Term>> options) throws CRSException
	{
		//GenericRule rule = new GenericRule(this, Util.wrapWithProperties(factory, factory.makeConstructor(name), Util.propertiesHolder(pattern)), pattern, contractum, options);
		GenericRule rule = new GenericRule(this, factory.makeConstructor(name), pattern, contractum, options);
		indexRule(rule);
		if (verbosity >= 3)
			verboseWrite(rule.toString() + "\n");
	}

	void addRule(String name, GenericRule rule) throws CRSException
	{
		if (rule.crs != this)
			throw new CRSException("Cannot add rule from another CRS");
		
		indexRule(rule);
		if (verbosity >= 3)
			verboseWrite(rule.toString() + "\n");

	}
	
	
	/**
	 * (Re)generate (if needed) and return rules by constructor structure.
	 * @return
	 */
	private Map<Constructor, ArrayList<GenericRule>> rulesByConstructor()
	{
		if (rulesByConstructorDirty)
		{
			rulesByConstructor.clear();
			for (GenericRule rule : ruleByName.values())
			{
				// Add rule to rules associated with the function symbol.
				Constructor c = rule.pattern.constructor();
				if (c != null)
				{
					if ("$".equals(c.symbol()) && Util.isConstant(rule.pattern.sub(0)))
					{
						String primitive = Util.symbol(rule.pattern.sub(0));
						// Some special cases for root $ patterns...
						if (Primitive.CONSTRUCTION.symbol.equals(primitive)
						        && rule.pattern.arity() > 1 && Util.isConstant(rule.pattern.sub(1)))
						{
							// $[C, constant, #args]
							c = rule.pattern.sub(1).constructor();
						}
					}
					c = c.baseConstructor();

					ArrayList<GenericRule> crules = rulesByConstructor.get(c);
					if (crules == null)
						rulesByConstructor.put(c, crules = new ArrayList<GenericRule>());
					insertRule(crules, rule);
				}
			}
			rulesByConstructorDirty = false;
		}
		return rulesByConstructor;
	}
	
	/** Insert rule respecting Priority and Fallback options... */
	private void insertRule(List<GenericRule> crules, GenericRule rule)
	{
		if (rule.options != null && rule.options.containsKey(PRIORITY_OPTION_SYMBOL))
		{
			crules.add(0, rule);
			return;
		}
		if (rule.options != null && rule.options.containsKey(FALLBACK_OPTION_SYMBOL))
		{
			crules.add(rule);
			return;
		}
		for (int i = 0; i < crules.size(); ++i)
		{
			Map<String, List<Term>> os = crules.get(i).options;
			if (os != null && os.containsKey(FALLBACK_OPTION_SYMBOL))
			{
				crules.add(i, rule);
				return;
			}
		}
		crules.add(rule);
	}

	/** Insert rule into constructor-based index. */
	private void indexRule(GenericRule rule)
	{
		ruleByName.put(rule.name(), rule);
		rulesByConstructorDirty = true;
	}

	// Builder...

	public Factory<? extends Term> factory()
	{
		return factory;
	}

	public String name()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public Sink load(Sink sink, Term directives) throws CRSException
	{
		sink = loadDirective(sink, "", (GenericTerm) directives, true);
		errorCheck("Processing aborted because of errors.");
		return sink;
	}

	/** Helper to make sure {@link #appendable} is instantiated. */
	private Appendable makeAppendable()
	{
		if (appendable == null)
		{
			try
			{
				appendable = factory.defined(Factory.OUTPUT_OPTION) ? new FileWriter(
				        Util.symbol(factory.get(Factory.OUTPUT_OPTION))) : System.out;
			}
			catch (IOException e)
			{
				throw new RuntimeException("output=... parameter error: ", e);
			}
		}
		return appendable;
	}

	/** Helper to make sure sink is instantiated. */
	private Sink makeSink(Sink sink)
	{
		if (sink == null)
			sink = factory.sink(makeAppendable());
		return sink;
	}

	/**
	 * Actually load a directive.
	 * @param sink to send result of loading to (no action for rules)
	 * @param prefix for all rules
	 * @param directive to load
	 * @param allowRule whether the directive can be a rule
	 * @return sink after it has received any terms loaded
	 * @throws CRSException if needed
	 */
	@SuppressWarnings("unchecked")
	Sink loadDirective(Sink sink, String prefix, GenericTerm directive, boolean allowRule) throws CRSException
	{
		try
		{
			if (verbosity >= 6)
				verboseWrite("\n<!-- Loading\n" + directive + "\n-->\n");

			if (metaCRS != null)
				directive = metaCRS.normalize(directive);

			if (directive.kind() == Kind.CONSTRUCTION)
			{
				String symbol = Util.symbol(directive);
				int arity = directive.arity();

				// Expand top-level evaluation.
				while (symbol.equals(CRS.EVAL_SYMBOL))
				{
					GenericTerm computed = GenericEvaluator.compute(directive, global);
					if (computed == null)
						break;
					// Update with evaluation result.
					directive = computed;
					if (metaCRS != null)
						directive = metaCRS.normalize(directive);
					symbol = Util.symbol(directive);
					arity = directive.arity();
				}

				// Process directive.
				if (symbol.equals(Builder.RULE_SYMBOL))
				{
					if (!allowRule)
					{
						error("Rules not allowed here (rule " + name + " ignored)");
						return sink;
					}
					addRule(directive, prefix);
					return sink;
				}
				else if (symbol.equals(Builder.SORT_ALIAS_SYMBOL))
				{
					evaluateArguments(arity, directive);
					if (arity == 2 && Util.isConstant(directive.sub(0)) && Util.isConstant(directive.sub(1)))
					{
						// $SortAlias[Name, Name]
						factory.setSortAlias(Util.symbol(directive.sub(0)), Util.symbol(directive.sub(1)));
						return sink;
					}
				}
				else if (symbol.equals(Builder.DATA_SORT_SYMBOL))
				{
					evaluateArguments(arity, directive);
					if (arity == 2 && Util.isSequence(directive.sub(1)))
					{
						// $Sort[Name, (Form;...;Form;)]
						Term sort = directive.sub(0);
						if (directive.sub(0).arity() != 0)
						{
							error("Only polymorphic sorts use sort variables in the "
							        + "sort declaration; sort parameters for " + sort + " ignored.");
							sort = factory.literal(Util.symbol(directive.sub(0)));
						}
						Term tail = directive.sub(1);
						while (Util.isCons(tail.constructor()))
						{
							Term form = tail.sub(0);
							factory.setSortForm(sort, LinkedExtensibleSet.EMPTY_VARIABLE_SET, form, false, false); // add data form!
							tail = tail.sub(1);
						}
						if (tail.arity() != 0 || !Util.isNull(tail.constructor()))
						{
							error("Bad $Sort form sequence (" + tail + ", ignored)."); // probably unreachable
						}
						return sink;
					}
				}
				else if (symbol.equals(Builder.FUNCTION_SORT_SYMBOL))
				{
					evaluateArguments(arity, directive);
					if (arity == 2)
					{
						// $FunctionSort[ Form, Sort ]
						Term form = directive.sub(0);
						Term sort = directive.sub(1);

						//if (sort.kind() != Kind.CONSTRUCTION && sort.kind() != Kind.VARIABLE_USE) //Kris
						//	warning("Unsupported $FunctionSort directive (" + directive.toString().trim() + ", ignored).");
						//else
						factory.setSortForm(sort, LinkedExtensibleSet.EMPTY_VARIABLE_SET, form, true, false);
						return sink;
					}
				}
				else if (symbol.equals(Builder.POLYMORHIC_SORT_VARIABLE_SYMBOL))
				{
					// ∀ x...x . SortDeclaration (as above).
					evaluateArguments(arity, directive);
					Set<Variable> params = new HashSet<Variable>();
					GenericTerm declaration = directive;
					// Extract sort variables.
					while (symbol.equals(Builder.POLYMORHIC_SORT_VARIABLE_SYMBOL) && arity == 1)
					{
						Variable[] tvars = declaration.binders(0);
						for (int i = 0; i < tvars.length; i++)
							params.add(tvars[i]);
						declaration = declaration.sub(0);
						if (declaration.kind() != Kind.CONSTRUCTION)
						{
							error("\u2200 should only be used in sort declarations.");
							return sink;
						}
						symbol = Util.symbol(declaration);
						arity = declaration.arity();
						evaluateArguments(arity, declaration);
					}
					if (declaration.kind() == Kind.CONSTRUCTION
					        && symbol.equals(Builder.DATA_SORT_SYMBOL) && arity == 2
					        && declaration.sub(0).kind() == Kind.CONSTRUCTION && Util.isSequence(declaration.sub(1)))
					{
						// ∀ a..a . $Sort[ {KeySort:ValueSort;...} Name[a..a], (Form;...;Form;)]
						Term sort = declaration.sub(0);
						Set<Variable> test = new HashSet<Variable>();
						for (int i = 0; i < sort.arity(); i++)
						{
							Term x = sort.sub(i);
							if (x.kind() != Kind.VARIABLE_USE || !params.contains(x.variable()) || test.contains(x.variable()))
								throw new CRSException("Parameters to sorts declarations must be unique variables.");
							test.add(x.variable());
						}
						if (test.size() < params.size())
						{
							warning("Not all variables in the \u2200 declaration in " + directive + " occur in the sort.");
							params = test;
						}
						Term tail = declaration.sub(1);
						while (Util.isCons(tail.constructor()))
						{
							// - Each Form.
							Term form = tail.sub(0);
							factory.setSortForm(sort, params, form, false, false); // add data form!
							tail = tail.sub(1);
						}
						if (tail.arity() != 0 || !Util.isNull(tail.constructor()))
						{
							error("Bad $Sort form sequence (" + tail + ", ignored)."); // probably unreachable
						}
						return sink;
					}
					if (declaration.kind() == Kind.CONSTRUCTION && symbol.equals(Builder.FUNCTION_SORT_SYMBOL) && arity == 2)
					{
						// ∀ a..a . $FunctionSort[ Form, Sort ]
						Term form = declaration.sub(0);
						Term sort = declaration.sub(1);

						factory.setSortForm(sort, params, form, true, false);
						return sink;
					}
				}
				else if (symbol.equals(Builder.TERM_SYMBOL))
				{
					evaluateArguments(arity, directive);
					if (arity == 1)
					{
						// $Term[term]
						return directive.sub(0).copy(makeSink(sink), true, LinkedExtensibleMap.EMPTY_RENAMING);
					}
				}
				else if (symbol.equals(Builder.NORMALIZE_SYMBOL))
				{
					evaluateArguments(arity, directive);
					switch (arity)
					{
						case 1 :
							// $Normalize[term]
							return normalize(makeSink(sink), directive.sub(0), true);
						case 2 :
							// $Normalize[term, packagename] --- for testing of compiled rules!
							if (directive.sub(1) == null || !Util.isConstant(directive.sub(1)))
								return normalize(makeSink(sink), directive.sub(0), true);

							// Used compiled rules
							return normalize(makeSink(sink), directive.sub(0), Util.symbol(directive.sub(1)), true);
					}
				}
				else if (symbol.equals(Builder.USE_SYMBOL))
				{
					evaluateArguments(arity, directive);
					if (arity == 1 && Util.isConstant(directive.sub(0)))
					{
						// $Use[resource-or-url]
						String resource = Util.symbol(directive.sub(0));
						if (factory.defined("$Provides$" + resource))
							return sink; // already loaded so a no-op
						if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
							factory.message(directive.toString());
						Reader reader = Util.resourceReader(factory, resource);
						factory.set("$Provides$" + resource, factory.literal(resource));
						return load(makeSink(sink), factory.parse(reader, null, resource, 1, 1, null));
					}
				}
				else if (symbol.equals(Builder.SET_SYMBOL))
				{
					// $Set[name[, directive]]
					if (arity >= 1 && Util.isConstant(directive.sub(0)) && arity <= 2)
					{
						String key = Util.symbol(directive.sub(0));
						if (arity == 1)
						{
							factory.set(key, factory.literal(1));
						}
						else
						{
							Buffer buffer = new Buffer(factory);
							loadDirective(buffer.sink(), prefix, directive.sub(1), false);
							factory.set(key, buffer.term(true));
						}
						return sink;
					}
				}
				else if (symbol.equals(Builder.UNSET_SYMBOL))
				{
					// $Unset[name]
					if (arity == 1 && Util.isConstant(directive.sub(0)))
					{
						String key = Util.symbol(directive.sub(0));
						factory.set(key, null);
						return sink;
					}
				}
				else if (symbol.equals(Builder.COMMENT_SYMBOL))
				{
					// $Comment[...]
					return sink;
				}
				else if (symbol.equals(Builder.SEND_SYMBOL))
				{
					// $Send[Term]
					return directive.sub(0).copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING);
				}
				else if (symbol.equals(Builder.MESSAGE_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $Message[Constant]
					// $Message[Constant, WriteFile]
					switch (arity)
					{
						case 1 : {
							Appendable a = makeAppendable();
							a.append(Util.symbol(directive.sub(0)));
							a.append("\n");
							if (a instanceof Flushable)
								((Flushable) a).flush();
							return sink;
						}
						case 2 :
							output(directive.sub(1)).append(Util.symbol(directive.sub(0)) + "\n");
							return sink;
					}
				}
				else if (symbol.equals(Builder.WATCH_SYMBOL))
				{
					evaluateArguments(arity, directive);
					((GenericFactory) factory).watchedConstructions.add(Util.symbol(directive.sub(0)));
					return sink;
				}
				else if (symbol.equals(Builder.VERBOSE_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $Verbose[]
					// $Verbose[Verbose]
					// $Verbose[Verbose, WriteFile]
					switch (arity)
					{
						case 0 :
							setVerbosity(1, System.out);
							return sink;

						case 1 :
							if (Util.isConstant(directive.sub(0)))
							{
								int verbosity = Integer.parseInt(Util.symbol(directive.sub(0)));
								setVerbosity(verbosity, System.out);
								return sink;
							}
							break;

						case 2 :
							if (Util.isConstant(directive.sub(0)) && Util.isConstant(directive.sub(1)))
							{
								int verbosity = Integer.parseInt(Util.symbol(directive.sub(0)));
								setVerbosity(verbosity, output(directive.sub(1)));
								return sink;
							}
					}
				}
				else if (symbol.equals(Builder.CHECK_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $Check[symbol [, value]]
					if (arity >= 1 && arity <= 2 && Util.isConstant(directive.sub(0)))
					{
						String s = Util.symbol(directive.sub(0));
						if (!factory.defined(s))
							fatal("$Check directive failed: symbol " + s + " is not defined?");
						if (arity == 2 && !sub(1).equals(factory.get(s)))
							fatal("$Check directive failed: symbol " + s + " does not have the value " + sub(1) + "?");
						return sink;
					}
				}
				else if (symbol.equals(Builder.CHECK_GRAMMAR_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $CheckGrammar[Class]
					// TODO: $CheckGrammar[Class, (Category;...;Category;)]
					if (arity == 1 && Util.isConstant(directive.sub(0)))
					{
						String g = Util.symbol(directive.sub(0));
						if (!factory.hasGrammar(g, null))
							fatal("$CheckParser directive failed: parser " + g + " has not been loaded?");
						return sink;
					}
				}
				else if (symbol.equals(Builder.ADD_GRAMMAR_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $AddGrammar[Class]
					// TODO: $AddGrammar[Class, (Category;...;Category;)]
					if (arity == 1 && Util.isConstant(directive.sub(0)))
					{
						factory.addGrammar(Util.symbol(directive.sub(0)), null);
						return sink;
					}
				}
				else if (symbol.equals(Builder.SINK_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $Sink[Class]
					if (arity == 1 && Util.isConstant(directive.sub(0)))
					{
						Class<Sinker> sinkClass = (Class<Sinker>) Util.classForName(factory, Util.symbol(directive.sub(0)));
						factory.setSinker(sinkClass);
						return sink;
					}
				}

				// Experimental directives here!
				else if (symbol.equals(Builder.SORTIFY_SYMBOL) || symbol.equals(Builder.CHECK_SORTS_SYMBOL))
				{
					// $Sortify
					// $CheckSorts (obsolete)
					if (directive.arity() == 0)
					{
						if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
							factory.message(directive.toString());
						sortify();
						return sink;
					}
				}
				else if (symbol.equals(Builder.LAX_SYMBOL))
				{
					// $Lax
					if (directive.arity() == 0)
					{
						factory.set(Builder.LAX_SYMBOL, factory.literal("1"));
						return sink;
					}
				}
				else if (symbol.equals(Builder.META_SYMBOL))
				{
					// $Meta[Directives]
					// Load the directives into the meta-CRS
					if (directive.arity() == 1)
					{
						if (metaCRS == null)
						{
							metaCRS = new GenericCRS(factory);
							metaCRS.setVerbosity(verbosity, verboseWriter);
						}
						return metaCRS.load(makeSink(sink), directive.sub(0));
					}
				}
				else if (symbol.equals(Builder.PRINT_SYMBOL))
				{
					// $Print[Directives]
					// Load the directives into the print-CRS
					if (directive.arity() == 1)
					{
						if (printCRS == null)
						{
							printCRS = new GenericCRS(factory);
							printCRS.setVerbosity(0, verboseWriter);
						}
						return printCRS.load(makeSink(sink), directive.sub(0));
					}
				}
				else if (symbol.equals(Builder.ASSERT_SYMBOL))
				{
					// $Assert[ Expression[, FailureMessage[, SuccessMessage]] ]
					if (arity == 1
					        || (arity > 1 && Util.isConstant(directive.sub(1)) && (arity == 2 || (arity == 3 && Util.isConstant(directive.sub(2))))))
					{
						Buffer buffer = new Buffer(factory);
						loadDirective(buffer.sink(), prefix, directive.sub(0), false);
						Term test = buffer.term(true);
						if (Util.isTrue(test))
						{
							if (arity == 3)
							{
								Appendable a = makeAppendable();
								a.append(Util.symbol(directive.sub(2)));
								a.append("\n");
								if (a instanceof Flushable)
									((Flushable) a).flush();
							}
							return sink;
						}
						else
						{
							if (arity == 1)
								warning("$Assert failed: " + directive.sub(0));
							else
								warning(Util.symbol(directive.sub(1)));
						}
						return sink;
					}
				}
				else if (symbol.equals(Builder.DUMP_RULES_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $DumpRules[ [filename [, part]] ]

					boolean toSink = (arity == 0 || arity >= 1
					        && (Util.isNull(directive.sub(0).constructor()) || "1".equals(Util.symbol(directive.sub(0)))));
					String part = (arity == 2 ? Util.symbol(directive.sub(1)) : null);
					Sink s;
					Buffer b = null;
					if (toSink)
						s = makeSink(sink);
					else
					{
						b = new Buffer(factory);
						s = b.sink();
					}
					//
					s = dumpRules(s, part);
					//
					if (toSink)
						sink = s;
					else
					{
						Term t = b.term(false);
						assert t != null : "Generated dumped rules term is not buffered!";
						Appendable a = output(directive.sub(0));
						t.appendTo(a, new HashMap<Variable, String>(), Integer.MAX_VALUE, factory.defined(Factory.SIMPLE_TERMS), true, true, null);
						if (a instanceof Flushable)
							((Flushable) a).flush();
						if (a instanceof Closeable)
							((Closeable) a).close();
					}
					return sink;
				}
				else if (symbol.equals(Builder.REIFY_SYMBOL))
				{
					evaluateArguments(arity, directive);
					// $Reify[ [filename] ]
					// $Reify[ [stem, (family1....familyn)] ]
					boolean toSink = (arity == 0 && (Util.isNull(directive.sub(0).constructor()) || "1".equals(Util.symbol(directive.sub(0)))));

					Sink s;
					Buffer b = null;
					if (toSink)
						s = makeSink(sink);
					else
					{
						b = new Buffer(factory);
						s = b.sink();
					}
					//
					s = reify(s, new HashMap<String, Term>(), new IdentityHashMap<Variable, Term>(), new HashMap<String, Reifier>());
					//
					if (toSink)
						sink = s;
					else
					{
						if (verbosity > 0)
							System.out.println("Dumping reified rules");

						final Term t = b.term(true);
						assert t != null : "Generated dumped rules term is not buffered!";
						
						// TODO: Avoid dumping full .crs?
						if (arity < 2)
						{
							Appendable a = output(directive.sub(0));
							Sink s2 = factory.sink(a);
							t.copy(s2, arity < 2, LinkedExtensibleMap.EMPTY_RENAMING);
							if (a instanceof Flushable)
								((Flushable) a).flush();
							if (a instanceof Closeable)
								((Closeable) a).close();
						}
						else
						{
							dumpModules(directive, t);
						}
					}
					return sink;
				}
				else if (symbol.equals(Builder.DISPATCHIFY_SYMBOL))
				{
					if (arity == 0)
					{
						if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
							factory.message(directive.toString());
						dispatchify();
						return sink;
					}
				}
				else if (symbol.equals(Builder.LOCIFY_SYMBOL))
				{
					if (arity == 0)
					{
						if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
							factory.message(directive.toString());
						locify();
						return sink;
					}
				}
				else if (symbol.equals(Builder.SIMPLIFY_SYMBOL))
				{
					if (arity == 0)
					{
						if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
							factory.message(directive.toString());
						new Simplifier(this).simplify(ruleByName);
						return sink;
					}
				}
				else if (Util.isSequence(directive))
				{
					// ( Directive ;...; Directive ;)
					while (!symbol.equals(CRS.NIL_SYMBOL))
					{
						sink = loadDirective(sink, prefix, directive.sub(0), allowRule);
						directive = directive.sub(1);
						symbol = Util.symbol(directive);
					}
					return sink;
				}
				else if (directive.arity() == 0)
				{
					// Constant are just copied to the output.
					return directive.copy(makeSink(sink), true, LinkedExtensibleMap.EMPTY_RENAMING);
				}
				else if (directive.arity() == 1 && Util.isSequence(directive.sub(0)))
				{
					// C[ ( Directive ;...; Directive ;) ]
					if ("".equals(prefix) && name() == null)
						setName(Util.symbol(directive));

					prefix = prefix + Util.symbol(directive) + "-";
					directive = directive.sub(0);
					symbol = Util.symbol(directive);
					while (!symbol.equals(CRS.NIL_SYMBOL))
					{
						sink = loadDirective(sink, prefix, directive.sub(0), allowRule);
						directive = directive.sub(1);
						symbol = Util.symbol(directive);
					}
					return sink;
				}
			}
		}
		catch (NumberFormatException e)
		{
			error("Badly formed integer in " + directive + " (" + e.getMessage() + ")");
		}
		catch (IOException e)
		{
			error("I/O error in " + directive + ": " + e.getMessage());
		}
		error("Unsupported directive: " + directive);
		return sink;
	}

	/**
	 * Dump modules
	 * @param directive
	 * @param t
	 * @throws CRSException
	 * @throws IOException
	 */
	protected void dumpModules(GenericTerm directive, final Term t) throws CRSException, IOException
	{
		//System.out.println("Available processors: " + Runtime.getRuntime().availableProcessors());
		
		ExecutorService pool = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
		
		// stem, (family1....familyn)
		final String stem = Util.symbol(directive.sub(0));
		int i = stem.lastIndexOf('.');
		final String ext = i != -1 ? stem.substring(i) : "";

		Term family = directive.sub(1);
		while (family != null)
		{
			if (Util.isCons(family.constructor()))
			{
				final String name = Util.symbol(family.sub(0));

				// Generate minimal rules.crs input .dr file
				pool.execute(new Runnable()
					{
						public void run()
						{
							try
							{
								Appendable a = output(stem.replace(ext, "_" + name) + ext);
								Sink fsink = factory.sink(a);
								
								fsink = new TopEmptyListFilterSink(fsink);
								fsink = new FunctionFilterSink(fsink, name);
								fsink = new ConstructorFilterSink(fsink, new String[]
									{"DATA", "POLYMORPHIC"}, 2);
								
								t.copy(fsink, false, new LinkedExtensibleMap<Variable, Variable>());

								if (a instanceof Flushable)
									((Flushable) a).flush();
								if (a instanceof Closeable)
									((Closeable) a).close();
							}
							catch (CRSException e)
							{
								e.printStackTrace();
							}
							catch (IOException e)
							{
								e.printStackTrace();
							}
						}
					});

				// Generate minimal header.crs input .dr file  
				pool.execute(new Runnable()
					{
						public void run()
						{
							try
							{
								Appendable a = output(stem.replace(ext, "_" + name + "_header") + ext);
								Sink fsink = factory.sink(a);
								
								fsink = new TopEmptyListFilterSink(fsink);
								fsink = new FunctionFilterSink(fsink, name);
								fsink = new ConstructorFilterSink(fsink, new String[]
									{"DATA", "POLYMORPHIC"}, 2);
								fsink = new ConstructorFilterSink(fsink, new String[]
									{"RULE"}, 3);
								
								t.copy(fsink, false, new LinkedExtensibleMap<Variable, Variable>());

								if (a instanceof Flushable)
									((Flushable) a).flush();
								if (a instanceof Closeable)
									((Closeable) a).close();
							}
							catch (CRSException e)
							{
								e.printStackTrace();
							}
							catch (IOException e)
							{
								e.printStackTrace();
							}
						}
					});

				family = family.sub(1);
			}
			else
				family = null;
		}

		// Generates minimal sorts.crs input dr file 
		pool.execute(new Runnable()
			{
				public void run()
				{
					try
					{
						Appendable a = output(stem.replace(ext, "_data") + ext);
						Sink nsink = factory.sink(a);
						
						Sink esink = new TopEmptyListFilterSink(nsink);
						Sink rsink = new ConstructorFilterSink(esink, new String[]
							{"FUNCTION"}, 2);
						
						t.copy(rsink, false, new LinkedExtensibleMap<Variable, Variable>());

						if (a instanceof Flushable)
							((Flushable) a).flush();
						if (a instanceof Closeable)
							((Closeable) a).close();
					}
					catch (CRSException e)
					{
						e.printStackTrace();
					}
					catch (IOException e)
					{
						e.printStackTrace();
					}
				}
			});
		
		pool.shutdown();
	}
	
	/** Helper to evaluate arguments of directive. */
	private void evaluateArguments(final int arity, GenericTerm directive) throws CRSException
	{
		for (int i = 0; i < arity; ++i)
		{
			GenericTerm ti = directive.sub(i);
			if (metaCRS != null)
				ti = metaCRS.normalize(ti);
			if (ti.kind() == Kind.CONSTRUCTION && Util.symbol(ti).equals(CRS.EVAL_SYMBOL))
			{
				GenericTerm computed = GenericEvaluator.compute(ti, global);
				if (computed != null)
				{
					if (metaCRS != null)
						computed = metaCRS.normalize(computed);
					computed.copy(directive.replaceSubSink(i), true, LinkedExtensibleMap.EMPTY_RENAMING);
				}
			}
		}
	}

	/** Helper to obtain output file. */
	private Appendable output(Term term) throws CRSException
	{
		return output(Util.symbol(term));
	}

	/** Helper to obtain output file. */
	private Appendable output(String name) throws CRSException
	{
		try
		{
			return "".equals(name) ? makeAppendable() : new FileWriter(name);
		}
		catch (IOException e)
		{
			fatal("I/O error: " + e);
		}
		return null; // never reached
	}

	public void merge(Builder other) throws CRSException
	{
		// Sorts already added because the factory is shared...
		// Add rules.
		for (String name : other.ruleNames())
		{
			Pattern pattern = (Pattern) Buffer.materialize(factory, other.rulePattern(name), false);
			Contractum contractum = (Contractum) Buffer.materialize(factory, other.ruleContractum(name), false);
			Map<String, List<Term>> options = other.ruleOptions(name);
			addRule(name, pattern, contractum, options);
		}
	}

	public void removeRule(String name)
	{
		ruleByName.remove(name);
		rulesByConstructorDirty = true;
	}

	public Set<String> ruleNames()
	{
		return ruleByName.keySet();
	}

	public Map<String, List<Term>> ruleOptions(String name)
	{
		return ruleByName.get(name).getOptions();
	}

	public Pattern rulePattern(String name)
	{
		return ruleByName.get(name).pattern;
	}

	public Contractum ruleContractum(String name)
	{
		return ruleByName.get(name).contractum;
	}

	public CRS toCRS(boolean discard)
	{
		return discard ? this : new GenericCRS(factory, name, ruleByName);
	}

	// CRS...

	public boolean isEmpty()
	{
		return ruleByName.isEmpty();
	}

	public Sink normalize(Sink sink, Term term, boolean discard) throws CRSException
	{
		if (!discard)
			term = Buffer.materialize(sink, term, false); // copy to preserve original term

		// Term can be discarded and we have no streaming implementation: normalize in place and then copy.
		if (verbosity >= 1)
			verboseWrite("\n// Normalizing with " + ruleByName.size() + " rules\n");
		rewriteStartMS = System.currentTimeMillis();
		Term normalized = normalize(term);
		if (verbosity >= 1)
		{
			verboseWrite("// Normal form with "
			        + name()
			        + " after "
			        + rewriteCount
			        + " rewrites"
			        + (verbosity >= 2
			                ? " ("
			                        + (System.currentTimeMillis() - rewriteStartMS) + "ms, " + matchCount + " attempts, "
			                        + visitCount + " node visits, " + substituteByCopy + " copies, " + substituteProper
			                        + " proper substitutions" + ")"
			                : "") + "\n");
		}
		if (printCRS != null)
			normalized = printCRS.normalize(normalized);
		return normalized.copy(sink, true, LinkedExtensibleMap.EMPTY_RENAMING);
	}

	private Sink normalize(Sink sink, Term term, String packageName, boolean discard)
	{
		// TODO Hmm.. not ideal here since the input term is already built in memory   

		// Try to instantiate packageName.Run
		try
		{
			Class<?> c1 = Class.forName(packageName + ".GeneratedCRS");

			Object run = c1.newInstance();
			c1.getMethod("normalize", Sink.class, Term.class).invoke(run, sink, term);
		}
		catch (Exception e)
		{
			throw new RuntimeException("Normalizing using generated rules failed: " + e.getMessage(), e);
		}
		return null;
	}

	public GenericTerm normalize(Term t) throws CRSException
	{
		GenericTerm term = (GenericTerm) t;
		errorCheck("Errors prevent normalization.");
		ContextStack context = new ContextStack();
		context.setRoot(term);

		try
		{
			while (true)
			{
				Valuation sigma = valuation(term);
				if (sigma != null)
				{
					// (1) There is a top redex.  Rewrite it and retry.
					long count = rewriteCount + 1;
					if (verbosity > 6)
						verboseWrite("*********************\n*** (0) Topterm is a redex.\n" + context);
					if (verbosity >= 5)
						verboseWrite("// TopRedex["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
					Buffer b = new Buffer(factory);
					if (verbosity >= 3)
						verboseWrite("// →[" + sigma.name() + " " + count + "]\n");
					contraction(sigma, b.sink(), term, null, 0, context);
					term = (GenericTerm) b.term(true);
					context.setRoot(term);

					if (verbosity >= 4)
						verboseWrite("// TopContraction["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
				}
				else if (normalizeChildren(term, context))
				{
					// (2) There was no top redex but we could rewrite the children so we should retry.
				}
				else
				{
					// (3) There was no top redex and no children could be rewritten so we are done.
					assert term != null;
					if (!observers.isEmpty())
					{
						notifyObservers(null, term, null, context);
					}
					return term;
				}
			}
		}
		catch (IOException e)
		{
			throw new RuntimeException("Verbose output failed: " + e.getMessage());
		}
	}

	/** Helper for {@link #normalize(Term)}. */
	private boolean normalizeChildren(Term parent, ContextStack context) throws IOException, CRSException
	{
		// Internal stack for nested rewrites.
		assert parent != null : "Can only rewrite children of an actual parent!";
		assert context.isTrivial() : "Rewriting needs a trivial context!";

		// The initial current state is the first subterm of parent.
		int arity = parent.arity();
		int index = 0;
		boolean changed = false; // whether any rewrites were done
		boolean exhausted = false; // whether the children of parents were just exhausted

		// Infinite loop broken when normal form reached.
		while (true)
		{
			if (verbosity > 6)
				verboseWrite("\n*********************\nCONTEXT:\n" + context + "\n");
			if (index >= arity)
			{
				// There is no current subterm.

				if (context.isTrivial())
				{
					if (verbosity > 6)
						verboseWrite("*********************\n*** (1) no more nodes to search.\n");
					// Done.
					return changed;
				}
				else
				{
					if (verbosity > 6)
						verboseWrite("*********************\n*** (2) No more siblings.\n");
					// Move back to parent with the "exhausted" marker.
					parent = context.lastParent();
					arity = parent.arity();
					index = context.lastIndex();
					context.unextend();
					exhausted = true;
				}
			}
			else
			{
				// Try to rewrite the current subterm.

				Term term = parent.sub(index); // there is a subterm
				
				Valuation sigma = valuation(term); // see if it is a redex
				if (sigma == null)
				{
					// Not a redex.
					if (exhausted)
					{
						// Done here, for now...
						if (verbosity > 6)
							verboseWrite("*********************\n*** (3) Subterm is not a redex and all children are in normal form.\n");
						// Should only complain if normal form otherwise reached...
						//                        if (term.kind() == Kind.CONSTRUCTION && functions.contains(Util.symbol(term)))
						//                        	error("Function error: the application\n"+term+"\ndoes not match any rule!");
						// Advance to next sibling.
						++index;
						exhausted = false;
					}
					else
					{
						if (verbosity > 6)
							verboseWrite("*********************\n*** (4) Subterm is not a redex but children may need reducing.\n");
						// Move to first child.
						context.extend(parent, index);
						parent = term;
						arity = parent.arity();
						index = 0;
					}
				}
				else
				{
					long count = rewriteCount + 1;
					// Got a redex to reduce and repeat.
					if (verbosity > 6)
						verboseWrite("*********************\n*** (5) Subterm is a redex.\n" + context);
					// Contract it and repeat!
					if (verbosity >= 5)
						verboseWrite("// Redex["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
					Sink contractionSink = parent.replaceSubSink(index);
					contractionSink = contractionSink.binds(parent.binders(index));

					if (verbosity >= 3)
					{
						verboseWrite("// →[" + sigma.name() + " " + count + "]\n");
						if (verbosity >= 4)
						{
							// Use buffer when debugging...
							Buffer b = new Buffer(factory);
							contraction(sigma, b.sink(), term, parent, index, context);
							Term contraction = b.term(true);
							verboseWrite("// Contraction["+ sigma.name() + " " +count +"]:\n" + Util.toString(contraction, verbosity_depth) + "\n");
							contraction.copy(contractionSink, true, LinkedExtensibleMap.EMPTY_RENAMING);
						}
						else
							contraction(sigma, contractionSink, term, parent, index, context);
					}
					else
						contraction(sigma, contractionSink, term, parent, index, context);
					changed = true;
					exhausted = false;
				}
			}
		}
	}

	public Term rewrite1(Term term) throws CRSException
	{
		errorCheck("Errors prevent normalization.");
		try
		{
			// Try root contraction.
			Valuation sigma = valuation(term);
			if (sigma != null)
			{
				long count = rewriteCount + 1;
				if (verbosity >= 5)
					verboseWrite("// Redex["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
				Buffer b = new Buffer(factory);
				contraction(sigma, b.sink(), term, null, 0, null);
				term = b.term(true);
				if (verbosity >= 3)
				{
					verboseWrite("// →[" + sigma.name() + " " + count + "]\n");
					if (verbosity >= 4)
						verboseWrite("// Contraction["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
				}
				return term;
			}

			// Try inner destructive contraction.
			if (innerrewrite1(term))
				return term;

			// Fail.
			return null;
		}
		catch (IOException e)
		{
			throw new RuntimeException("Verbose output failed: " + e.getMessage());
		}
	}

	/**
	 * Rewrite leftmost <em>contained</em> redex destructively.
	 * @param parent term whose subterms are searched for a redex (recursively)
	 * @return whether the rewrite succeeded
	 * @throws IOException 
	 * @throws CRSException 
	 */
	private boolean innerrewrite1(Term parent) throws IOException, CRSException
	{
		// Search subterms.
		int arity = parent.arity();
		for (int i = 0; i < arity; ++i)
		{
			Term term = parent.sub(i);
			Valuation sigma = valuation(term);
			if (sigma != null)
			{
				// Found redex...rewrite and replace!
				long count = rewriteCount + 1;
				if (verbosity >= 5)
					verboseWrite("// Redex["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
				contraction(sigma, parent.replaceSubSink(i).binds(parent.binders(i)), term, parent, i, null);
				if (verbosity >= 3)
				{
					verboseWrite("// →[" + sigma.name() + " " + count + "]\n");
					if (verbosity >= 4)
						verboseWrite("// Contraction["+ sigma.name() + " " +count +"]:\n" + Util.toString(term, verbosity_depth) + "\n");
				}
				return true;
			}
			if (innerrewrite1(term))
			{
				// Rewrite succeeded recursively in term.
				return true;
			}
		}
		return false;
	}

	/**
	 * Check if some rule matches term.
	 * @param term to match
	 * @return valuation, if there is a match, or null if not
	 * @throws IOException 
	 * @throws CRSException 
	 */
	private Valuation valuation(Term term) throws IOException, CRSException
	{
		++visitCount;

		Constructor c = term.constructor();
		if (c == null)
			return null;

		c.normalize(this);
		return valuationFrom(rulesByConstructor().get(c.baseConstructor()), term);
	}

	/**
	 * Contract the previously generated valuation
	 * @param sigma valuation (non-null)
	 * @param sink to send contracted term to
	 * @return sink after it has received contracted term
	 * @param term to rewrite shortly or null if not available (for debugging)
	 * @param parent of term, or null if none (for debugging)
	 * @param index of term under parent or -1 if not available (TODO: use paths so we can also handle property events)
	 * @return
	 */
	private Sink contraction(Valuation sigma, Sink sink, Term term, Term parent, int index, ContextStack context)
	{
		++rewriteCount;
		if (!observers.isEmpty())
		{
			// TODO: use index?
			notifyObservers(parent, term, sigma, context);
		}
		if (watchedRules.contains(sigma.name()))
		{
			System.out.println("StartRuleWatch: " + sigma.name());
		}
		sink = sigma.contract(sink);
		if (watchedRules.contains(sigma.name()))
		{
			System.out.println("EndRuleWatch: " + sigma.name());
		}
		return sink;
	}

	/**
	 * Check if some rule from a specific list matches term.
	 * @param rs with rule names to consider (may be null)
	 * @param term to match
	 * @return valuation, if there is a match, or null if not
	 * @throws IOException 
	 */
	private Valuation valuationFrom(Iterable<GenericRule> rs, Term term) throws IOException
	{
		if (rs != null)
		{
			for (GenericRule r : rs)
			{
				Valuation sigma = r.match(term);
				++matchCount;
				if (sigma != null)
					return sigma; // got match!
			}
		}
		return null;
	}

	public void setVerbosity(int verb, Appendable writer)
	{
		verbosity = verb;
		verboseWriter = writer;
		if (metaCRS != null)
			metaCRS.setVerbosity(verb, writer);
		verbosity_depth = Util.getInteger(factory, Factory.VERBOSE_DEPTH_OPTION, 11);
	}

	public int getVerbosity()
	{
		return verbosity;
	}

	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps)
	        throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		writer.append("\n" + name + "[(\n");
		for (GenericRule r : ruleByName.values())
		{
			r.appendTo(writer, used, depth - 1, namedProps, variableProps);
			writer.append("\n;\n");
		}
		writer.append(")]\n\n");
	}

	private void warning(String message)
	{
		factory.warning(message);
	}

	void error(String message) throws CRSException
	{
		factory.error(message);
	}

	private void fatal(String message) throws CRSException
	{
		factory.fatal(message);
	}

	private void errorCheck(String message) throws CRSException
	{
		factory.errorCheck(message);
	}

	//	/**
	//	 * Update term to use free variable occurrences from specific list. 
	//	 * @param term to update
	//	 * @param free list of free variables to use the first of
	//	 * @param bound variables to not substitute
	//	 * @throws CRSException 
	//	 */
	//	static void useVariables(Term term, final Set<Variable> free, SimpleVariableSet bound) throws CRSException
	//	{
	//	    final Visitor visitor = new Visitor()
	//	    {
	//            @Override
	//            public void visitFree(Variable v, VariableUpdater updater) throws CRSException
	//            {
	//                // Not bound so might need replacement...search!
	//                String s = v.name();
	//                for (Variable fv : free)
	//                {
	//                    if (v == fv)
	//                    {
	//                        break; // already got it
	//                    }
	//                    if (s.equals(fv.name()))
	//                    {
	//                        updater.setVariable(fv);
	//                        break; // replaced it
	//                    }
	//                }
	//            }
	//	    };
	//	    term.visit(visitor, bound);
	//	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		return ruleByName.keySet();
	}

	public Term getProperty(String name)
	{
		GenericRule rule = ruleByName.get(name);
		if (rule == null)
			return null;
		return Buffer.materialize(factory, rule, false);
	}

	public Iterable<Variable> propertyVariables()
	{
		return new EmptyIterable<Variable>();
	}

	public Term getProperty(Variable variable)
	{
		return null;
	}

	public boolean canSetProperty(String name)
	{
		return true;
	}

	public boolean canSetProperty(Variable variable)
	{
		return false;
	}

	public void setProperty(String name, Term value) throws CRSException
	{
		addRule(value, "");
	}

	public void setProperty(Variable variable, Term value) throws CRSException
	{
		throw new CRSException("setProperty not implemented for variables...");
	}

	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		for (String name : properties.propertyNames())
			setProperty(name, properties.getProperty(name));
		for (Variable variable : properties.propertyVariables())
			setProperty(variable, properties.getProperty(variable));
	}
	
	

	@Override
	public void removeProperty(Variable variable) throws CRSException
	{
		throw new CRSException("removeProperty not implemented");
	}

	public boolean isMeta()
	{
		return true;
	}

	// Constructor...

	public String symbol()
	{
		return CRS_SYMBOL;
	}

	public String literalSort()
	{
		return null;
	}

	public Object object()
	{
		return null;
	}

	public boolean match(Match match, Constructor other, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		return other.symbol().equals(Builder.CRS_SYMBOL)
		        && PropertiesConstructor.checkProperties(this, other, match, bound, contractionCount, promiscuous, once, onceSeen);
	}

	public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		throw new UnsupportedOperationException();
	}

	public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
	{
		throw new UnsupportedOperationException();
	}

	public Constructor copy(ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		return this;
	}

	public void normalize(CRS crs) throws CRSException
	{
		// Should this do anything?
	}

	public boolean equals(Object that)
	{
		return this == that;
	}

	public int hashCode()
	{
		return System.identityHashCode(this); // do not attempt to check whether different CRSs are the same.
	}

	public Constructor baseConstructor()
	{
		return this;
	}

	public void javaInvokeStart(SourceBuilder code, String sinkName, Map<Variable, String> variable2java)
	{
		throw new UnsupportedOperationException(); // you gotta be kidding
	}

	// Copyable...

	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		return sink.start(discard && renames.isEmpty() ? this : copy(renames)).end();
	}

	// Stub...

	public Maker maker()
	{
		return factory;
	}

	public Kind kind()
	{
		return Kind.CONSTRUCTION;
	}

	public Constructor constructor()
	{
		return this;
	}
	
	public Variable variable()
	{
		return null;
	}

	public String metaVariable()
	{
		return null;
	}

	public int arity()
	{
		return 0;
	}

	public Term copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		return new GenericCRS(factory, name, ruleByName);
	}

	// Term...

	public Variable[] binders(int index)
	{
		return GenericTerm.NO_BIND;
	}

	public Term sub(int index)
	{
		throw new IndexOutOfBoundsException();
	}

	public Sink replaceSubSink(int index)
	{
		throw new IndexOutOfBoundsException();
	}

	public void setVariable(Variable variable)
	{
		throw new UnsupportedOperationException();
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		for (GenericRule r : ruleByName.values())
		{
			if (!r.pattern.checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;
			if (!r.contractum.checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;
		}
		return true;
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		for (GenericRule r : ruleByName.values())
		{
			r.pattern.addFree(set, bound, includemetaapps, null);
			r.contractum.addFree(set, bound, includemetaapps, base);
		}
	}
	
	public void addMetaCounts(Map<String, Integer> counts)
	{
		for (GenericRule r : ruleByName.values())
		{
			r.pattern.addMetaCounts(counts);
			r.contractum.addMetaCounts(counts);
		}
	}
	
	final public void analyzeMetaUseContractum(Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
	{
		// Never called by reifier.
	}

	final public void analyzeMetaUsePattern(Map<String, Integer> counts)
	{
		// Never called by reifier.
	}
	
	public boolean equalsModulo(Term second, ExtensibleMap<Variable, Variable> renamings)
	{
		throw new UnsupportedOperationException(); // you gotta be kidding
	}

	public Sink subsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		throw new UnsupportedOperationException(); // you gotta be kidding
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		throw new UnsupportedOperationException(); // you gotta be kidding
	}

	public SortedSet<Path> paths(Path base)
	{
		throw new UnsupportedOperationException();
	}

	// Object overrides.

	public String toString()
	{
		StringBuilder b = new StringBuilder();
		try
		{
			FormattingAppendable a = FormattingAppendable.format(b, 120, 0, Integer.MAX_VALUE);
			if (visitCount > 0)
			{
				a.append("<blockquote>\n  "
				        + rewriteCount + " rewrites, " + matchCount + " attempts, " + visitCount + " node visits" + ", "
				        + substituteByCopy + " copies, " + substituteProper + " proper substitutions" + "\n</blockquote>\n");
			}
			a.flush();
			dumpRules(factory.sink(a), null);
			//appendTo(a, new HashMap<Variable, String>());
			a.flush();
		}
		catch (IOException e)
		{}
		return b.toString();
	}

	// Helpers...

	/** Lock the system to prevent further changes. */
	void lock()
	{
		locked = true;
		metaCRS = null;
	}

	/**
	 * Dump rule term to sink (returning the sink afterwards). 
	 * @param part prefix of names of rules to include
	 */
	public Sink dumpRules(Sink sink, String part)
	{
		// Emit entire system.
		int declarationEnds = 0;
		if (name != null)
		{
			sink = sink.start(sink.makeConstructor(name)); // crs-name[
			++declarationEnds;
		}

		// Assemble sort declaration components and forms from rules.
		final Set<String> constructors = factory.getSortedConstructors();
		final SortedMultiMap<String, Pair<Term, Term>> functionForms = new SortedHashMultiMap<String, Pair<Term, Term>>();
		final Map<String, Term> fullSort = new HashMap<String, Term>();
		final SortedMultiMap<String, Term> dataForms = new SortedHashMultiMap<String, Term>();
		final SortedMultiMap<String, GenericRule> rulesByFunction = new SortedHashMultiMap<String, GenericRule>();
		classifySymbols(constructors, dataForms, functionForms, fullSort, rulesByFunction, rulesByFunction);

		// Sort aliases.
		for (Map.Entry<String, String> e : factory.sortAliases.entrySet())
		{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
			++declarationEnds;
			sink = sink.start(sink.makeConstructor(Builder.SORT_ALIAS_SYMBOL)); // $SortAlias[
			sink = sink.start(sink.makeLiteral(e.getValue(), CRS.STRING_SORT)).end(); // name
			sink = sink.start(sink.makeLiteral(e.getKey(), CRS.STRING_SORT)).end(); // alias
			sink = sink.end(); // ] of $SortAlias
		}

		// Data sort declarations.
		for (Map.Entry<String, Set<Term>> e : dataForms.entrySet())
		{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
			++declarationEnds;
			int innerEnds = 0;
			// ∀x1...xn.$SORT['name'[x1,...,xn], (Form;...)]
			String sortname = e.getKey();
///System.out.println("DUMPING SORT "+sortname);
			Term sort = fullSort.get(sortname);
			// - Polymorphism prefix.
			for (int i = 0; i < sort.arity(); i++)
			{
				sink = sink.start(sink.makeConstructor(Builder.POLYMORHIC_SORT_VARIABLE_SYMBOL)); // ∀[
				++innerEnds;
				Variable[] bs =
					{sort.sub(i).variable()};
				sink = sink.binds(bs); // xi.
			}
			sink = sink.start(sink.makeConstructor(Builder.DATA_SORT_SYMBOL)); // $Sort[
			innerEnds++;
			// - Sort with possible properties prefix.
			//Map<String, Term> sortset = factory.sortsetFor(Util.symbol(sort));
			//if (sortset != null) //Kris: TODO: already in sort?
			//	sink = PropertiesWrapperConstructor.start(sink, null, sortset, null, null); // {Key : Value; ...}
			sort.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING);
			//if (sortset != null)
			//	sink = sink.end();
			// - Variable form, if any.
			if (factory.sortAllowsVariables(Util.symbol(sort)))
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
				++innerEnds;
				sink = sink.use(sink.makeVariable("variable", true));
			}
			// - Data forms.
			for (Term form : e.getValue())
			{
				if (form.kind() != Kind.VARIABLE_USE) // since variable case already emitted
				{
					sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
					++innerEnds;
					sink = form.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING);
				}
			}
			sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
			while (innerEnds-- > 0)
				sink = sink.end(); // ]]]] of inner $Cons/$Sort/∀
		}

		// Print function declarations (sort (if any) + rules).
		for (Map.Entry<String, Set<GenericRule>> e : rulesByFunction.entrySet())
		{
			String function = e.getKey();

			// Find sort for function, if any.
			if (functionForms.multiContainsKey(function))
				for (Pair<Term, Term> p : functionForms.get(function))
				{
					Term sort = p.head();
					Term form = p.tail();
					if (function.equals(Util.symbol(form)))
					{
						// Function sort form.
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
						++declarationEnds;
						// - Polymorphism prefix.
						Set<Variable> params = new HashSet<Variable>();
						sort.addFree(params, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, null);
						form.addFree(params, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, null);
						int innerEnds = 0;
						for (Variable param : params)
						{
							sink = sink.start(sink.makeConstructor(Builder.POLYMORHIC_SORT_VARIABLE_SYMBOL)); // ∀[
							++innerEnds;
							Variable[] bs =
								{param};
							sink = sink.binds(bs);
						}
						// - Actual sort...
						sink = sink.start(sink.makeConstructor(Builder.FUNCTION_SORT_SYMBOL)); // $FunctionSort[
						++innerEnds;
						sink = form.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING);
						sink = sort.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING);
						while (innerEnds-- > 0)
							sink = sink.end(); // ]] of inner $FunctionSort/∀s
					}
				}

			TreeMap<String, GenericRule> functionRulesByName = new TreeMap<String, GenericRule>();
			for (GenericRule rule : e.getValue())
				functionRulesByName.put(rule.name(), rule);
			for (GenericRule rule : functionRulesByName.values())
			{
				String rulename = rule.name();
				if (rulename.startsWith(name + "-"))
					rulename = rulename.substring(name.length() + 1);
				Term pattern = rule.getPattern();
				assert function.equals(Util.symbol(pattern));
				Term contractum = rule.getContractum();

				// Rule.
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
				++declarationEnds;
				sink = sink.start(sink.makeConstructor(Builder.RULE_SYMBOL)); // $Rule[
				// - Name.
				sink = sink.start(sink.makeConstructor(rulename)); // rulename[
				// - Compute fresh options...
				Map<Variable,Term> freshReused = new HashMap<Variable, Term>(); // extracted for later
				if (rule.getOptions().containsKey(Builder.FRESH_OPTION_SYMBOL))
				{
					Map<Variable,Term> fresh = new HashMap<Variable, Term>();  // fresh variables (so we can remove the reused ones).
					for (Term t : rule.getOptions().get(Builder.FRESH_OPTION_SYMBOL))
						if (t != null && t.kind() == Kind.VARIABLE_USE)
							fresh.put(t.variable(), factory.newVariableUse(t.variable()));
					if (rule.reused != null && !rule.reused.isEmpty())
						for (Variable v : rule.reused.values())
							if (fresh.containsKey(v))
								freshReused.put(v, fresh.remove(v));
					// - Fresh option.
					if (!fresh.isEmpty())
					{
						sink = sink.start(sink.makeConstructor(Builder.FRESH_OPTION_SYMBOL)); // Fresh[
						for (Variable v : fresh.keySet())
							sink = fresh.get(v).copy(sink, false, null);
						sink = sink.end(); // ] of Fresh
					}
				}
				// - FreshReuse option.
				if (rule.getOptions().containsKey(Builder.FRESH_REUSE_OPTION_SYMBOL))
				{
					for (Term t : rule.getOptions().get(Builder.FRESH_REUSE_OPTION_SYMBOL))
						if (t != null)
							freshReused.put(t.variable(), t);
				}
				if (!freshReused.isEmpty())
				{
					sink = sink.start(sink.makeConstructor("FreshReuse")); // FreshReuse[
					for (Variable v : freshReused.keySet())
						sink = freshReused.get(v).copy(sink, false, null);
					sink = sink.end(); // ] of FreshReuse
				}
				// - Other options.
				for (Map.Entry<String, List<Term>> oe : rule.getOptions().entrySet())
				{
					String optionName = oe.getKey();
					List<Term> optionValues = oe.getValue();
					if (optionName == null || optionName.startsWith("Fresh"))
						continue; // Hack to skip dummy and fresh options!!
					if (!optionValues.isEmpty())
					{
						sink = sink.start(sink.makeConstructor(optionName)); // option[
						for (Term t : optionValues)
							sink = t.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING); // option-value
						sink = sink.end(); // ] of option
					}
				}
				sink = sink.end(); // ] of name
				sink = pattern.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING); // pattern
				sink = contractum.copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING); // contractum
				sink = sink.end(); // ] of $Rule
			}
		}

		// End.
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
		while (declarationEnds-- > 0)
			sink = sink.end(); // ]]] of all outer $Cons/crsx-name
		return sink;
	}

	/**
	 * Classify the symbols of this rule system.
	 * @param constructors must be set to all constructor symbols before call (not updated)
	 * @param dataForms updated with all data forms indexed by symbol
	 * @param functionForms updated with all function forms from {@link Factory#formsOf(String)} for all sorted symbols, indexed by symbol
	 * @param fullSort updated with the full form of every sort, by sort name
	 * @param rulesByFunction updated with all non-shuffle rules (overridden by {@link #lastDispatchify}) indexed by function symbol
	 * @param shuffleRulesByFunction updated with shuffle rules
	 */
	private void classifySymbols(Set<String> constructors, SortedMultiMap<String, Term> dataForms, SortedMultiMap<String, Pair<Term, Term>> functionForms, Map<String, Term> fullSort, SortedMultiMap<String, GenericRule> rulesByFunction, SortedMultiMap<String, GenericRule> shuffleRulesByFunction)
	{
		// Updated with all data forms from {@link Factory#formsOf(String)} for all sorted symbols.
		final Set<Pair<Term, Term>> allDataForms = new HashSet<Pair<Term, Term>>();

		for (String symbol : constructors)
		{
			if (symbol.length() == 0 || (symbol.charAt(0) == '$' && !symbol.startsWith("$Text")))
				continue;
			if (factory.isFunction(symbol))
				functionForms.multiAddAll(symbol, factory.formsOf(symbol));
			else
				allDataForms.addAll(factory.formsOf(symbol));
		}
		for (Pair<Term, Term> declaration : allDataForms)
		{
			Term sort = declaration.head();
			Term form = declaration.tail();
			fullSort.put(Util.symbol(sort), sort);
			dataForms.multiAdd(Util.symbol(sort), form);
		}

		for (String varsort : factory.getSortsWithVariables())
		{
			dataForms.multiAdd(varsort, factory.newVariableUse(factory.makeVariable("variable", true)));
			if (!fullSort.containsKey(varsort))
				fullSort.put(varsort, factory.literal(varsort));
		}

		for (Map.Entry<String, GenericRule> e : ruleByName.entrySet())
		{
			GenericRule rule = e.getValue();
			rulesByFunction.multiAdd(Util.symbol(rule.pattern), rule);
		}

		// Override with dispatchified rules.
		if (lastDispatchify != null)
		{
			// - remove...
			for (Quad<GenericTerm, GenericTerm, Constructor, Map<String, List<Term>>> q : lastDispatchify)
			{
				Term pattern = q.one();
				String function = Util.symbol(pattern);
				rulesByFunction.remove(function);
			}
			// - fabricate rules...
			for (Quad<GenericTerm, GenericTerm, Constructor, Map<String, List<Term>>> q : lastDispatchify)
				try
				{
					GenericTerm pattern = q.one();
					String function = Util.symbol(pattern);
					GenericTerm contractum = q.two();
					Constructor rulename = q.three(); //function + (pattern.arity() > 0 && pattern.sub(0).kind() == Kind.CONSTRUCTION ? "-" + Util.symbol(pattern.sub(0)) : "");
//					if (rulename.symbol().contains("EB-Code-ForDo-Emit-Tuple-2"))
//						factory.warning("karma");

					Map<String, List<Term>> options = q.four();
					if (contractum != null) // defensive to avoid follow-on errors from dispatchifier failure
					{
						if (options.containsKey(Builder.COMPILE_TYPE_OPTION_SYMBOL) && "Shuffle".equals(Util.symbol(options.get(Builder.COMPILE_TYPE_OPTION_SYMBOL).get(0))))
						{
							shuffleRulesByFunction.multiAdd(function, new GenericRule(this, rulename, pattern, contractum, options));
							if (!function.contains("$"))
								shuffleRulesByFunction.multiAdd(function, new GenericRule(this, rulename, pattern, contractum, options)); // add dummy shuffle rule for external symbols.
						}
						else
							rulesByFunction.multiAdd(function, new GenericRule(this, rulename, pattern, contractum, options));
					}
				}
				catch (CRSException e1)
				{}
		}
	}

	/**
	 * Implements $Sortify.
	 * Analyze the sorts of the system rules and inject the sorts into the system.
	 * @throws CRSException if system cannot sortify
	 */
	void sortify() throws CRSException
	{
		errorCheck("Errors prevent $Sortify.");

		if (verbosity > 0)
			System.out.print("// Starting Sortifier...");

		Sorter sorter = new Sorter(factory, (Util.getInteger(factory, Factory.STRICT_FUNCTIONAL, 0) == 0), (Util.getInteger(
		        factory, Factory.ALLOW_UNDECLARED_OPTION, 0) > 0));
		sorter.runSortify(ruleByName);

		if (verbosity > 0)
			System.out.print("done.");
	}

	/**
	 * Implements $Dispatchify.
	 * Sortify, complete, and record modified rules in {@link #lastDispatchify}.
	 */
	void dispatchify() throws CRSException
	{
		errorCheck("Errors prevent Sortify (required for dispatchify).");

		sortify();
		errorCheck("Errors prevent $Dispatchify");
		if (verbosity > 0)
			System.out.println("// Starting Dispatchify...\n\t1. Running completer");

		Completer completer = new Completer(factory, (Util.getInteger(factory, Factory.ALLOW_OVERLAPS_OPTION, 0) > 0), ruleByName);
		if (verbosity > 0)
			System.out.print("\t2. Running dispatchifier....");
		lastDispatchify = completer.dispatchify();
		if (verbosity > 0)
			System.out.println("done.");
	}
	
	/** Helper to emit #$j in generated dispatch rule. */
	static Sink emitArgumentReference(Sink sink, int j, String m, Variable[][] binders)
	{
		if (binders[j].length > 0)
		{
			sink = sink.startMetaApplication(m);
			for (int i = 0; i < binders[j].length; ++i)
				sink = sink.use(binders[j][i]);
			sink = sink.endMetaApplication();
		}
		else
		{
			sink = sink.startMetaApplication(m).endMetaApplication();
		}
		return sink;
	}

	/**
	 * Implements $Locify.
	 * @throws CRSException
	 */
	void locify() throws CRSException
	{
		for (GenericRule rule : ruleByName.values())
		{
			String loc = extractLoc((GenericTerm) rule.pattern);
			boolean cleanLoc;
			if (loc != null)
				cleanLoc = true;
			else
			{
				cleanLoc = false;
				// There is no data loc, see if we can use the passed environment!
				String sort = Util.symbol(factory.sortOf(Util.symbol(rule.pattern)));
				Map<String,Term> sortset = factory.sortsetFor(sort);
				boolean candidate = sortset != null && factory.unalias("$StringEntrySort").equals(factory.unalias(Util.symbol(sortset.get("$String"))));
				if (candidate)
				{
					loc = Util.propertyRef(rule.pattern);
					if (loc == null)
                    {
	                    String ref = loc = "#$LOC";
	                    rule.pattern = ((GenericTerm) rule.pattern).wrapWithPropertiesRef(ref, true);
                    }
				}
			}
			if (loc != null)
			{
				// loc is explicit location reference to copy.
				rule.contractum = (Contractum) populateLoc((GenericTerm) rule.contractum, loc, cleanLoc);
			}
		}
	}
	/** Helper to extract (or set) the location properties meta-variable of a pattern. */ 
	private String extractLoc(GenericTerm pattern)
	{
		final int arity = pattern.arity();
		for (int i = 0; i < arity; ++i)
		{
			String subLoc = extractSubLoc((GenericTerm) pattern, i, true);
			if (subLoc != null)
				return subLoc;
		}
		return null;
	}
	/** Helper to extract (or set) the location properties meta-variable of a pattern child. */
	private String extractSubLoc(GenericTerm parent, int index, boolean outermost)
	{
		if (parent instanceof GenericEvaluator)
		{
			// Special cases for children of $.
			GenericEvaluator ge = (GenericEvaluator) parent;
			switch (ge.primitive())
			{
				case NOT_MATCH :
					if (index == 1)
						return null;
				default:
			}
		}
		GenericTerm child = parent.sub(index);
		if (child.kind() == Kind.CONSTRUCTION)
		{
			// Extract properties and property sorts.
			PropertiesHolder ph = Util.propertiesHolder(child);
			String sort = Util.symbol(factory.sortOf(Util.symbol(child)));
			Map<String,Term> sortset = factory.sortsetFor(sort);
			boolean candidate = factory.isData(Util.symbol(child)) && sortset != null && factory.unalias("$StringEntrySort").equals(factory.unalias(Util.symbol(sortset.get("$String"))));
			if (candidate && ph.isMeta() && ((PropertiesConstraintsWrapper) ph).getRef() != null)
			{
				// (1) Found a LOC on this data term -- return it.
				return ((PropertiesConstraintsWrapper) ph).getRef();
			}
			final int arity = child.arity();
			for (int i = 0; i < arity; ++i)
			{
				String subLoc = extractSubLoc(child, i, outermost && !candidate);
				if (subLoc != null)
				{
					// (2) Found a LOC in a subterm - return it.
					return subLoc;
				}
			}
			if (outermost && candidate)
			{
				// (3) There was no LOC and this is an outermost candidate so force it.
				parent.replaceSub(index, parent.binders(index), child.wrapWithPropertiesRef("#$LOC", true));
				return "#$LOC";
			}
		}
		// (4) There was no LOC so fail.
		return null;
	}
	
	/**
	 *  Helper to insert the location properties meta-variable on missing data terms that accept it. 
	 * @param term to add location property to
	 * @param loc location property reference
	 * @param cleanLoc whether location property reference is just the location (otherwise a general environment) 
	 * @return updated term
	 */
	GenericTerm populateLoc(GenericTerm term, String loc, boolean cleanLoc)
	{
		GenericTerm result = term;
		boolean iseval = false;
		if (term.kind() == Kind.CONSTRUCTION)
		{
			// Extract properties and property sorts.
			PropertiesHolder ph = Util.propertiesHolder(term);
			String sort = Util.symbol(factory.sortOf(Util.symbol(term)));
			iseval = Util.isEval(term.constructor());
			boolean isdata = !iseval && factory.isData(Util.symbol(term));
			boolean isfun = !iseval && factory.isFunction(Util.symbol(term));
			Map<String,Term> sortset = null;
			if (isdata)
				sortset = factory.sortsetFor(sort);
			else if (isfun)
			{
				// For functions check their actual form.
				Term form = factory.formOf(sort, Util.symbol(term));
				PropertiesHolder formph = Util.propertiesHolder(form);
				if (formph != null)
				{
					sortset = new HashMap<String, Term>();
					for (String key : formph.propertyNames())
						sortset.put(key, formph.getProperty(key));
				}
			}
			boolean candidate = !iseval && sortset != null && factory.unalias("$StringEntrySort").equals(factory.unalias(Util.symbol(sortset.get("$String"))));
			if (candidate)
			{
				if (isdata)
				{
					if (!ph.isMeta() || ((PropertiesConstraintsWrapper) ph).getRef() == null)
					{
						// We have a data candidate without any properties reference -- add minimal clean environment.
						result = cleanLoc ? term.wrapWithPropertiesRef(loc, true) : wrapWithPassLocation(loc, term);
					}
					else // if (!cleanLoc) // would use clean top loc aggressively, currently local always overrides 
					{
						// We have a data candidate with an existing properties reference -- propagate *that* to subterm candidates.
						loc = ((PropertiesConstraintsWrapper) ph).getRef();
						cleanLoc = true;
					}
				}
				else if (isfun && cleanLoc)
				{
					if (!ph.isMeta() || ((PropertiesConstraintsWrapper) ph).getRef() == null)
					{
						// We have a clean loc reference and a function candidate without any properties reference -- just add it.
						result = term.wrapWithPropertiesRef(loc, true);
					}
					else
					{
						// We have a clean loc reference and a function candidate with an existing properties reference -- just add the minimal.
						result = wrapWithPassLocation(loc, term);
					}
				}
			}
		}
		// Recurse.
		final int arity = term.arity();
		for (int i = 0; i < arity; ++i)
			if (i>0 || !iseval)
				term.replaceSub(i, term.binders(i), populateLoc(term.sub(i), loc, cleanLoc));
		// Done.
		return result;
	}
	
	GenericTerm wrapWithPassLocation(String location, GenericTerm term)
	{
		Variable[][] binds = {GenericTerm.NO_BIND, GenericTerm.NO_BIND};
		GenericTerm[] sub = {factory.constant(factory.makeConstructor(Primitive.PASS_LOCATION_PROPERTIES)).wrapWithPropertiesRef(location, true), term};
		GenericTerm result = new GenericEvaluator(factory, factory.makeConstructor(CRS.EVAL_SYMBOL), binds, sub);
		return result;
	}
	
	/** Allow tools to observe CRSX steps. */
	public void addObserver(Observer observer)
	{
		int idx = observers.indexOf(observer);
		if (idx > 0)
			observers.remove(idx);
		observers.add(observer);
	}

	/** Allow tools to observe CRSX steps. */
	public void deleteObserver(Observer observer)
	{
		int idx = observers.indexOf(observer);
		if (idx > 0)
			observers.remove(idx);
	}

	/** Allow tools to observe CRSX steps. */
	private void notifyObservers(Term parentTerm, Term termToBeReWritten, Valuation valuationToBeApplied, ContextStack context)
	{
		if (observers.size() == 0)
			return;
		notifyObservers(new Object[]
			{parentTerm, termToBeReWritten, valuationToBeApplied, context});
	}

	/** Allow tools to observe CRSX steps. */
	public void notifyObservers(Object[] observedObjects)
	{
		if (observers.size() == 0)
			return;
		for (Iterator<Observer> iterator = observers.iterator(); iterator.hasNext();)
		{
			Observer observer = iterator.next();
			observer.update(this, observedObjects);
		}
	}

	@Override
    public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
    {
	    return reify(sink); // dummy for CRS to be a valid term.
    }
	
	/**
	 * Send term representing all sort declarations and rules.
	 * The resulting term will be valid for the sorts in reified.crs.
	 * @param sink to send to
	 * @return sink after it has received reified term
	 */
	public Sink reify(Sink sink)
	{
		if (verbosity > 0)
			System.out.println("Running reifier");

		// System wrapper.
		sink = sink.start(sink.makeConstructor(REIFY_CRSX));
		int declarationEnds = 1; // Count every Declaration level start(...) that needs an end() at the end.
		sink = sink.start(sink.makeLiteral(name, CRS.STRING_SORT)).end(); // crs-name

		// Assemble sort declaration components and forms from rules.
		final Set<String> constructors = new TreeSet<String>(); constructors.addAll(factory.getSortedConstructors());
		final SortedMultiMap<String, Term> dataForms = new SortedHashMultiMap<String, Term>();
		final SortedMultiMap<String, Pair<Term, Term>> functionForms = new SortedHashMultiMap<String, Pair<Term, Term>>();
		final Map<String, Term> fullSort = new HashMap<String, Term>();
		final SortedMultiMap<String, GenericRule> rulesByFunction = new SortedHashMultiMap<String, GenericRule>();
		final SortedMultiMap<String, GenericRule> shuffleRulesByFunction = new SortedHashMultiMap<String, GenericRule>();
		classifySymbols(constructors, dataForms, functionForms, fullSort, rulesByFunction, shuffleRulesByFunction);

		// Add sort declarations for the matchable builtin sorts.
		try
		{
			Term boolDeclaration = factory.parse("A[" + CRS.BOOLEAN_SORT + ", " + CRS.FALSE_SYMBOL + ", " + CRS.TRUE_SYMBOL + "]");
			fullSort.put(CRS.BOOLEAN_SORT, boolDeclaration.sub(0));
			constructors.add(CRS.FALSE_SYMBOL);
			dataForms.multiAdd(CRS.BOOLEAN_SORT, boolDeclaration.sub(1));
			constructors.add(CRS.TRUE_SYMBOL);
			dataForms.multiAdd(CRS.BOOLEAN_SORT, boolDeclaration.sub(2));

//			Term nativeDeclaration = factory.parse("A[" + CRS.NATIVE_SORT + ", " + CRS.STRING_SORT +  ", " + CRS.NUMERIC_SORT + ", " + CRS.BOOLEAN_SORT + "]");
//			fullSort.put(CRS.NATIVE_SORT, nativeDeclaration.sub(0));
//			constructors.add(CRS.STRING_SORT);
//			dataForms.multiAdd(CRS.NATIVE_SORT, nativeDeclaration.sub(1));
//			constructors.add(CRS.NUMERIC_SORT);
//			dataForms.multiAdd(CRS.NATIVE_SORT, nativeDeclaration.sub(2));
//			constructors.add(CRS.BOOLEAN_SORT);
//			dataForms.multiAdd(CRS.NATIVE_SORT, nativeDeclaration.sub(3));
			
			GenericTerm listDeclaration = factory.parse("A["
			        + CRS.LIST_SORT + "[a], " + CRS.NIL_SYMBOL + ", " + CRS.CONS_SYMBOL + "[a, $List[a]]]");
			fullSort.put(CRS.LIST_SORT, listDeclaration.sub(0));
			constructors.add(CRS.NIL_SYMBOL);
			dataForms.multiAdd(CRS.LIST_SORT, listDeclaration.sub(1));
			constructors.add(CRS.CONS_SYMBOL);
			dataForms.multiAdd(CRS.LIST_SORT, listDeclaration.sub(2));
			
			Term tryCallDeclaration = factory.parse("A[" + CRS.TRYRESULT_SORT + "[a], " + CRS.TRYSUCCESS_SYMBOL +  "[a], " + CRS.TRYFAILURE_SYMBOL + "[$String]]");
			fullSort.put(CRS.TRYRESULT_SORT, tryCallDeclaration.sub(0));
			constructors.add(CRS.TRYSUCCESS_SYMBOL);
			dataForms.multiAdd(CRS.TRYRESULT_SORT, tryCallDeclaration.sub(1));
			constructors.add(CRS.TRYFAILURE_SYMBOL);
			dataForms.multiAdd(CRS.TRYRESULT_SORT, tryCallDeclaration.sub(2));

			
		}
		catch (CRSException e1)
		{}

		// Data sort declarations.
		for (Map.Entry<String, Set<Term>> e : dataForms.entrySet())
		{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
			++declarationEnds;
			int dataEnds = 0;
			Term sort = fullSort.get(e.getKey());
			// - Polymorphism prefix.
			for (int i = 0; i < sort.arity(); i++)
			{
				sink = sink.start(sink.makeConstructor(CRS.REIFY_POLYMORPHIC)); // POLYMORHIC[
				++dataEnds;
				Variable[] bs =
					{sort.sub(i).variable()};
				sink = sink.binds(bs);
			}
			// - Actual data declaration.
			sink = sink.start(sink.makeConstructor(CRS.REIFY_DATA)); // DATA[
			++dataEnds;
			// - Properties prefix for sort.
			int sortEnds = 0;
			Map<String, Term> sortset = factory.sortsetFor(Util.symbol(sort));
			if (sortset != null)
			{
				for (String key : sortset.keySet())
				{
					sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT_PROPERTY)); // SORT-PROPERTY[
					++sortEnds;
					sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[
					sink = sink.start(sink.makeLiteral(key, CRS.STRING_SORT)).end();
					sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // NIL
					sink = sink.end(); // ]
					
					sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[
					//sink = sink.start(sink.makeConstructor(Util.symbol(sortset.get(key)))).end(); // TODO: REVIEW
					sink = sink.start(sink.makeLiteral(Util.symbol(sortset.get(key)), CRS.STRING_SORT)).end();
					sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // NIL
					sink = sink.end(); // ]
					
					//sink = sortset.get(key).reify(sink);
				}
			}
			// - Sort itself.
			sink = reifySort(sink, sort);
			while (sortEnds-- > 0)
				sink = sink.end(); // ] end of inner SORT_PROPERTY*
			// - Variable form, if any.
			if (factory.sortAllowsVariables(Util.symbol(sort)))
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
				++dataEnds;
				sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT_ALLOWS_VARIABLES)).end();
			}
			// - Data forms.
			for (Term form : e.getValue())
			{
				if (form.kind() != Kind.VARIABLE_USE) // since variable case already emitted
				{
					sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
					++dataEnds;
					sink = reifyForm(sink, form);
				}
			}
			sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
			while (dataEnds-- > 0)
				sink = sink.end(); // ]]]] end of inner CONS*/DATA/POLYMORPHIC*
		}
		
		final Map<String,Reifier> shuffles = new HashMap<String, Reifier>();
		final Map<String,MetaAnalyzer> analyzerShuffles = new HashMap<String, MetaAnalyzer>();
		for (final String f : shuffleRulesByFunction.multiKeySet())
		{
			Set<GenericRule> rules = shuffleRulesByFunction.multiGet(f);
			GenericRule rule = rules.iterator().next();
			// Shuffle rule has shape  {#Γ} F1[ #1, ..., #n ] → {#Γ} F2[ #p1, ..., #pn ]
			final Constructor constructor = rule.contractum.constructor();
			final int[] permutation = new int[rule.pattern.arity()];
			for (int i = 0; i < permutation.length; ++i)
			{
				Term c = rule.contractum.sub(i);
				int source = -1;
				for (int j = 0; j < permutation.length; ++j)
					if (c.metaVariable().equals(rule.pattern.sub(j).metaVariable()))
					{
						source = j;
						break;
					}
				permutation[i] = source;
			}
			shuffles.put(f, new Reifier()
			{
				@Override
                public Sink reify(Sink sink, Term original, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
                {
					int ends = 0;
		    		sink = sink.start(sink.makeConstructor(CRS.REIFY_CONSTRUCTION)); // CONSTRUCTION[
		    		++ends;
		    		sink = sink.start(sink.makeLiteral(constructor.symbol(), CRS.STRING_SORT)).end(); // c
		    		Term sort = factory.sortOf(constructor.symbol());
		    		Term form = sort == null ? null : factory.formOf(Util.symbol(sort), constructor.symbol()); // form of target symbol
		    		for (int i = 0; i < original.arity(); ++i)
		    		{
		    			int source = permutation[i];
		    			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
		    			++ends;
		    			Variable[] formBinders = form == null ? null : form.binders(i);
		    			Term formSort = form == null ? null : form.sub(i);
		    			for (int j = 0; j < original.binders(source).length; ++j)
		    			{
		    				Variable b = original.binders(source)[j];
		    				sink = sink.start(sink.makeConstructor(CRS.REIFY_BINDER)); // BINDER[
		    				sink = sink.start(sink.makeConstructor(b.promiscuous() ? CRS.REIFY_PROMISCUOUS : CRS.REIFY_LINEAR)).end(); // LINEAR/PROMISCUOUS
		    				sink = sink.start(sink.makeConstructor(b.blocking() ? CRS.REIFY_BLOCK : CRS.REIFY_PERMIT)).end(); // BLOCK/PERMIT
		    				sink = sink.start(sink.makeConstructor(b.shallow() ? CRS.REIFY_SHALLOW : CRS.REIFY_DEEP)).end();
			    				Term binderSort = formSort == null ? factory.nil() : Util.propertiesHolder(formSort).getProperty(formBinders[j]);
		    				sink = GenericCRS.reifySort(factory, sink, binderSort);
		    				freeSort.put(b, binderSort);
		    				sink = Util.occurrenceDescription(sink, original.sub(source), b); // (OTHER/META-USE[]/...)
		    				Variable[] binders = {b};
		    				sink = sink.binds(binders); // bij .
		    			}
		    			sink = sink.start(sink.makeConstructor(CRS.REIFY_ARGUMENT)); // ARGUMENT[
		    			sink = GenericCRS.reifySort(factory, sink, formSort);
		    			sink = original.sub(source).reify(sink, metaArgSort, freeSort, subReifiers); // subi
		    			sink = sink.end(); // ] of ARGUMENT
		    			for (@SuppressWarnings("unused") Variable b : original.binders(source))
		    				sink = sink.end(); // ] of BINDER
		    		}
		    		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // NIL (of list of arguments)
					//
			    	while (ends-- > 0)
			    		sink = sink.end(); // ]] of CONS/CONSTRUCTION
				    return sink;
                }
			});
			
			analyzerShuffles.put(f, new MetaAnalyzer()
			{

					@Override
					public void analyzeMetaUseContractum(Term original, Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
					{
						for (int i = original.arity() - 1; i >= 0 ; i--)
			    		{
			    			int source = permutation[i];
			    			original.sub(source).analyzeMetaUseContractum(counts, subAnalyzers);
			    		}
					}
					
					public void analyzeMetaUsePattern(Term original, Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
					{
						for (int i = original.arity() - 1; i >= 0 ; i--)
			    		{
			    			int source = permutation[i];
			    			original.sub(source).analyzeMetaUsePattern(counts);
			    		}
					}            
            });
		}

		// Function declarations.
		for (String function : rulesByFunction.multiKeySet())
		{
			// Order rules as bound variables, free, constructions.
			List<GenericRule> functionRules = new ArrayList<GenericRule>();
			{
				Set<GenericRule> freeRules = new TreeSet<GenericRule>(new Comparator<GenericRule>() {
	                public int compare(GenericRule rule1, GenericRule rule2)
	                {
		                return rule1.name().compareTo(rule2.name());
	                }});
				Set<GenericRule> constructionRules = new TreeSet<GenericRule>(new Comparator<GenericRule>() {
	                public int compare(GenericRule rule1, GenericRule rule2)
	                {
		                return rule1.name().compareTo(rule2.name());
	                }});
				for (GenericRule r : rulesByFunction.multiGet(function))
				{
					if (r.pattern.arity() > 0 && r.pattern.sub(0).kind() == Kind.VARIABLE_USE)
					{
						Variable b = r.pattern.sub(0).variable();
						boolean bound = false;
						for (Variable bj : r.pattern.binders(0))
							if (bj == b)
								bound = true;
						if (bound)
							functionRules.add(r);
						else
							freeRules.add(r);
					}
					else
						constructionRules.add(r);
				}
				functionRules.addAll(freeRules);
				functionRules.addAll(constructionRules);
			}

			// Start function declaration.
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
			++declarationEnds;
			// Function declaration.
			sink = sink.start(sink.makeConstructor(CRS.REIFY_FUNCTION)); // FUNCTION[
			int functionEnds = 1;
			Term functionSort = null;
			// - Compute rule category and common prefix.
			String ruleNamePrefix = null;
			String compileType = null;
			Pattern previousPattern = null;
			List<Integer> discriminatorPath = null;
			for (GenericRule r : functionRules)
			{
				if (ruleNamePrefix == null)
					ruleNamePrefix = r.name();
				else
				{
					String otherRuleName = r.name();
					for (int i = 0; i < ruleNamePrefix.length(); ++i)
						if (i >= otherRuleName.length() || ruleNamePrefix.charAt(i) != otherRuleName.charAt(i))
						{
							ruleNamePrefix = ruleNamePrefix.substring(0, i);
							break;
						}
				}
				if (compileType == null && r.getOptions().containsKey(Builder.COMPILE_TYPE_OPTION_SYMBOL))
				{
					List<Term> compileTypes = r.getOptions().get(Builder.COMPILE_TYPE_OPTION_SYMBOL);
					if (compileTypes != null && compileTypes.size() == 1)
						compileType = Util.symbol(compileTypes.get(0));
				}
				if (previousPattern != null)
				{
					if (discriminatorPath == null)
						discriminatorPath = Util.discriminatorPath(previousPattern, r.pattern);
					//					else if (!discriminatorPath.equals(Util.discriminatorPath(previousPattern, r.pattern)))
					//						factory.message("internal bad karma: inconsistent dispatch between "+discriminatorPath+" and "+previousPattern+" vs "+r.pattern);
				}
				previousPattern = r.pattern;
			}
			sink = sink.start(sink.makeLiteral(ruleNamePrefix == null ? "" : ruleNamePrefix, CRS.STRING_SORT)).end(); // ruleNamePrefix
			// - Rule type.
			sink = sink.start(sink.makeLiteral(compileType == null ? "Dispatch" : compileType, CRS.STRING_SORT)).end(); // compileType
			// - Dispatch pattern.
			if (discriminatorPath != null)
				for (Integer n : discriminatorPath)
					sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)).start(
					        sink.makeConstructor(sink.makeLiteral(n, CRS.NUMERIC_SORT))).end();
			sink = factory.nil().copy(sink, false, LinkedExtensibleMap.EMPTY_RENAMING);
			if (discriminatorPath != null)
				for (int i = 0; i < discriminatorPath.size(); ++i)
					sink = sink.end();
			// - Function name.
			sink = sink.start(sink.makeLiteral(function, CRS.STRING_SORT)).end(); // function
			// - Forms.
			{
				int innerEnds = 0;
				for (Pair<Term, Term> p : functionForms.multiGet(function))
				{
					Term sort = p.head();
					if (functionSort == null)
						functionSort = sort;
					else if (!functionSort.equals(sort))
						warning("Inconsistent alternate sorts for function " + function + " ignored!");
					Term form = p.tail();
					sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
					++innerEnds;
					sink = reifyForm(sink, form); // form
				}
				sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
				while (innerEnds-- > 0)
					sink = sink.end(); // ] end of inner CONS
			}
			// - Sort.
			if (functionSort == null)
			{
				// Try data sort if hybrid symbol...
				Term sort = factory.sortOf(function);
				if (sort != null)
					functionSort = sort;
			}
			sink = reifySort(sink, functionSort);
			for (GenericRule rule : functionRules)
			{
				// - Rule.
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
				++functionEnds;
				String rulename = rule.name();
				Term pattern = rule.getPattern();
				Term contractum = rule.getContractum();
				sink = sink.start(sink.makeConstructor(CRS.REIFY_RULE)); // RULE[
				// Analyzes meta-variable uses
				Map<String, Integer> metaUses = new HashMap<String, Integer>();
				contractum.analyzeMetaUseContractum(metaUses, analyzerShuffles);
				pattern.analyzeMetaUsePattern(metaUses);
				// -- Rule name.
				sink = sink.start(sink.makeLiteral(rulename, CRS.STRING_SORT)).end(); // rulename
				// -- Rule options...
				Map<String,Term> metaArgSort = new HashMap<String, Term>();
				Map<Variable,Term> freeSort = new IdentityHashMap<Variable, Term>();
				{
					int optionEnds = 0;
					SortedMap<Variable, Term> freshReused = new TreeMap<Variable, Term>();
					if (rule.getOptions().containsKey(Builder.FRESH_OPTION_SYMBOL))
					{
						SortedMap<Variable,Term> fresh = new TreeMap<Variable, Term>(); // fresh variables (so we can remove the reused ones).
						for (Term t : rule.getOptions().get(Builder.FRESH_OPTION_SYMBOL))
							if (t != null)
								fresh.put(Util.variableWithOptionalSortVariable(t), t);
						if (rule.reused != null && !rule.reused.isEmpty())
							for (Variable v : rule.reused.values())
								if (fresh.containsKey(v))
									freshReused.put(v, fresh.remove(v));
						// --- Fresh option.
						if (!fresh.isEmpty())
						{
							for (Variable v : fresh.keySet())
							{
								Term freshOption = fresh.get(v);
								Term sort = Util.variableWithOptionalSortSort(freshOption);
								if (sort != null)
									freeSort.put(v,  sort);
								sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
								++optionEnds;
								sink = sink.start(sink.makeConstructor(CRS.REIFY_RULE_OPTION)); // OPTION[
								sink = sink.start(sink.makeLiteral(Builder.FRESH_OPTION_SYMBOL, CRS.STRING_SORT)).end(); // "Fresh"
								sink = freshOption.reify(sink, metaArgSort, freeSort, shuffles);
								sink = sink.end(); // ]] of VARIABLE-USE and RULE-OPTION
							}
						}
					}
					// --- FreshReuse option.
					if (rule.getOptions().containsKey(Builder.FRESH_REUSE_OPTION_SYMBOL))
					{
						for (Term t : rule.getOptions().get(Builder.FRESH_REUSE_OPTION_SYMBOL))
							if (t != null)
								freshReused.put(Util.variableWithOptionalSortVariable(t), t);
					}
					for (Variable v : freshReused.keySet())
					{
						Term freshOption = freshReused.get(v);
						Term sort = Util.variableWithOptionalSortSort(freshOption);
						if (sort != null)
							freeSort.put(v,  sort);
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
						++optionEnds;
						sink = sink.start(sink.makeConstructor(CRS.REIFY_RULE_OPTION)); // OPTION[
						sink = sink.start(sink.makeLiteral(Builder.FRESH_REUSE_OPTION_SYMBOL, CRS.STRING_SORT)).end(); // "FreshReuse"
						sink = freshOption.reify(sink, metaArgSort, freeSort, shuffles);
						sink = sink.end(); // ] of OPTION
						// --- tag on FreshReuseOrigin option as appropriate
						Pair<String,Integer> metaOrigin = rule.getFreshOrigin(v);
						if (metaOrigin != null)
						{
							sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
							++optionEnds;
							sink = sink.start(sink.makeConstructor(CRS.REIFY_RULE_OPTION)); // OPTION[
							sink = sink.start(sink.makeLiteral(Builder.FRESH_REUSE_ORIGIN_OPTION_SYMBOL, CRS.STRING_SORT)).end(); // "FreshReuseOrigin"
							sink = sink.start(sink.makeConstructor(Builder.FRESH_REUSE_ORIGIN_OPTION_SYMBOL)); // FreshReuseOrigin[
							sink = sink.use(v);
							sink = sink.start(sink.makeLiteral(metaOrigin.head(), CRS.STRING_SORT)).end(); // "#metavar"
							sink = sink.start(sink.makeLiteral(metaOrigin.tail(), CRS.NUMERIC_SORT)).end(); // the index
							sink = sink.end().end(); // ]] of FreshReuseOrigin/OPTION
						}
					}
					// --- Other options.
					for (Map.Entry<String, List<Term>> oe : rule.getOptions().entrySet())
					{
						String optionName = oe.getKey();
						List<Term> optionValues = oe.getValue();
						if (optionName == null || optionName.startsWith(Builder.FRESH_OPTION_SYMBOL))
							continue; // Hack to skip dummy and fresh options!!
						for (Term t : optionValues)
						{
							sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
							++optionEnds;
							sink = sink.start(sink.makeConstructor(CRS.REIFY_RULE_OPTION)); // OPTION[
							sink = sink.start(sink.makeLiteral(optionName, CRS.STRING_SORT)).end(); // option
							sink = t.reify(sink, metaArgSort, freeSort, shuffles); // option-value
							sink = sink.end(); // ] of RULE-OPTION
						}
					}
					sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
					while (optionEnds-- > 0)
						sink = sink.end(); // ]]] end of option list CONS*
				}
				// -- Rule pattern.
				sink = pattern.reify(sink, metaArgSort, freeSort, shuffles);
				// -- Rule contractum.
				sink = contractum.reify(sink, metaArgSort, freeSort, shuffles);
				sink = sink.end(); // ] of RULE
			}
			// - End of function.
			sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
			while (functionEnds-- > 0)
				sink = sink.end(); // ]] of all function level CONS and FUNCTION itself
		}
		// End of declarations..
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
		while (declarationEnds-- > 0)
			sink = sink.end(); // ]]] of all outer CONS/CRSX
		return sink;
	}

	/** Emit reified term for one sort reference. */
	private Sink reifySort(Sink sink, Term sort)
	{
		return reifySort(factory, sink, sort);
	}

	/** Emit reified term for one sort reference. */
	public static Sink reifySort(GenericFactory factory, Sink sink, Term sort)
	{
		if (sort == null)
		{
			sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
		}
		else if (sort.kind() == Kind.VARIABLE_USE)
		{
			sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT_VARIABLE)); // SORT-VARIABLE[
			sink = sink.use(sort.variable()); // v
			sink = sink.end(); // ]
		}
		else
		{
			sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[ 
			sink = sink.start(sink.makeLiteral(Util.symbol(sort), CRS.STRING_SORT)).end();
			int ends = 1;
			for (int i = 0; i < sort.arity(); ++i)
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
				++ends;
				sink = reifySort(factory, sink, sort.sub(i));
			}
			sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
			while (ends-- > 0)
				sink = sink.end(); // ]] of CONS and SORT
		}
		return sink;
	}

	/** Emit reified term for one non-variable form. */
	private Sink reifyForm(Sink sink, Term form)
	{
		int ends = 0;
		for (String name : Util.propertiesHolder(form).propertyNames())
		{
			sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT_SET)); // SORT-SET[
			++ends;
			sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[
			sink = sink.start(sink.makeLiteral(name, CRS.STRING_SORT)).end(); // name
			sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
			sink = sink.end(); // ] of SORT
			sink = reifySort(sink, Util.getProperty(form, name)); // sort
		}
		sink = sink.start(sink.makeConstructor(CRS.REIFY_FORM)); // FORM[
		++ends;
		sink = sink.start(sink.makeLiteral(Util.symbol(form), CRS.STRING_SORT)).end();
		for (int i = 0; i < form.arity(); ++i)
		{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
			++ends;
			Term arg = form.sub(i);
			int innerEnds = 0;
			for (Variable b : form.binders(i))
			{
				sink = sink.start(sink.makeConstructor(CRS.REIFY_FORM_BINDER)); // FORM-BINDER[
				++innerEnds;
				sink = reifySort(sink, Util.getProperty(arg, b));
				Variable[] bs = {b};
				sink = sink.binds(bs);
			}
			sink = sink.start(sink.makeConstructor(CRS.REIFY_FORM_ARGUMENT)); // FORM-ARGUMENT[
			++innerEnds;
			sink = reifySort(sink, arg);
			while (innerEnds-- > 0)
				sink = sink.end(); // ]] of FORM-ARGUMENT and FORM-BINDER
		}
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
		while (ends-- > 0)
			sink = sink.end(); // ]]] of CONSes and FORM and SORTSETs
		return sink;
	}
}
