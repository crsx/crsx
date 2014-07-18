/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

import java.io.File;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.crsx.CRSException;
import net.sf.crsx.Kind;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.generator.codegen.Block;
import net.sf.crsx.generator.codegen.ClassBody;
import net.sf.crsx.generator.codegen.CodegenFactory;
import net.sf.crsx.generator.codegen.Expr;
import net.sf.crsx.generator.codegen.LocalVariable;
import net.sf.crsx.generator.codegen.Modifier;
import net.sf.crsx.generator.codegen.Type;
import net.sf.crsx.generic.GenericRule;
import net.sf.crsx.generic.PropertiesConstraintsWrapper;

/**
 * Basic code generator (common to all platform) for simple CRS rule collections.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public abstract class AbstractGenerator implements Generator
{
	// Constants

	/** Generic construction subkind */
	final static protected int GENERIC_CONS = 0;

	/** Generic term construction  $[C, name, t...] */
	final static protected int GENERIC_TERM_CONS = 1;

	/** Generic concatenation $[:, c1, c2, ...] */
	final static protected int GENERIC_CONCATENATION = 2;

	/** Generic IfDef $[IfDef, term0, term1, term2] */
	final static protected int GENERIC_IFDEF = 3;

	/** Generic Error $[Error, ...] */
	final static protected int GENERIC_ERROR = 4;

	/** Generic NotMatch $[Error, ...] */
	final static protected int GENERIC_NOT_MATCH = 5;

	/** Generic Plus $[Plus, ...] */
	final static protected int GENERIC_PLUS = 6;

	/** Generic Get $[Get, ...] */
	final static protected int GENERIC_GET = 7;

	/** Generic If $[If, ...] */
	final static protected int GENERIC_IF = 8;

	/** Generic Contains $[Contains, ...] */
	final static protected int GENERIC_CONTAINS = 9;

	/** Generic Substring $[Subtring, ...] */
	final static protected int GENERIC_SUBSTRING = 10;

	/** Generic Index $[Index, ...] */
	final static protected int GENERIC_INDEX = 11;

	/** Maps expression name to constant */
	final static protected Map<String, Integer> EXPRESSIONS = new HashMap<String, Integer>();
	{
		EXPRESSIONS.put("C", GENERIC_TERM_CONS);
		EXPRESSIONS.put(":", GENERIC_CONCATENATION);
		EXPRESSIONS.put("IfDef", GENERIC_IFDEF);
		EXPRESSIONS.put("Error", GENERIC_ERROR);
		EXPRESSIONS.put("NotMatch", GENERIC_NOT_MATCH);
		EXPRESSIONS.put("Plus", GENERIC_PLUS);
		EXPRESSIONS.put("Get", GENERIC_GET);
		EXPRESSIONS.put("If", GENERIC_IF);
		EXPRESSIONS.put("Contains", GENERIC_CONTAINS);
		EXPRESSIONS.put("Substring", GENERIC_SUBSTRING);
		EXPRESSIONS.put("Index", GENERIC_SUBSTRING);
	}

	/** Associated pattern class name  */
	final static protected String[] PATTERN_CLASSNAME =
		{"PatternConstruction", "TermConstructionExpr", "ConcatenationExpr", "IfDefExpr", null, "NotMatchExpr", null, null, null,
				null, null, null};

	/** Associated contractum class name  */
	final static protected String[] CONTRACTUM_CLASSNAME =
		{"ContractumConstruction", "TermConstructionExpr", "ConcatenationExpr", "IfDefExpr", "ErrorExpr", null, "PlusExpr",
				"GetExpr", "IfExpr", "ContainsExpr", "SubstringExpr", "IndexExpr"};

	// State

	/** Constructors */
	protected Map<SymbolArity, ConstructorEntry> constructors;

	/** List of templates indexed by their name */
	protected Map<String, CodeTemplate> templates;

	/** Number of rules */
	protected int ruleCount;

	/** Number of dispatch rules (count only 1 per constructor)  */
	protected int dispatchRuleCount;

	/** Where to generate code */
	protected File dest;

	/** Package name */
	protected String packageName;

	/** Dependencies with interpreter allowed? */
	protected boolean standalone;

	/** Code generator for part of the GeneratedCRSX class body */
	protected ClassBody crsxClassBody;

	/** Code generator for part of the static initialization */
	protected Block crsxStaticInitBlock;

	/** Code generator factory */
	protected CodegenFactory cgFactory;

	/** Commonly used types */
	final protected Type propertyConstraintType;
	final protected Type propertyConstraintArrayType;
	final protected Type termType;
	final protected Type termArrayType;
	final protected Type ruleType;
	final protected Type ruleArrayType;
	final protected Type metaApplicationReuseType;
	final protected Type metaApplicationSubstType;
	final protected Type contractumFreshVariableUseType;
	final protected Type patternVariableUseType;
	final protected Type contractumVariableUseType;
	final protected Type namedVariablePropertyType;
	final protected Type constantMetaPropertyType;
	final protected Type metaTermPropertyType;
	final protected Type varTermPropertyType;
	final protected Type varMetaPropertyType;
	final protected Type metaPropertyType;
	final protected Type intType;
	final protected Type intArrayType;
	final protected Type intArrayArrayType;
	final protected Type variableType;
	final protected Type variableArrayType;

	// Constructors

	protected AbstractGenerator()
	{
		templates = new HashMap<String, CodeTemplate>();

		cgFactory = makeCodegenFactory();

		propertyConstraintType = cgFactory.newClassReferenceType("PropertyConstraint");
		propertyConstraintArrayType = cgFactory.newArrayReferenceType(propertyConstraintType);
		termType = cgFactory.newClassReferenceType("Term");
		termArrayType = cgFactory.newArrayReferenceType(termType);
		ruleType = cgFactory.newClassReferenceType("Rule");
		ruleArrayType = cgFactory.newArrayReferenceType(ruleType);
		intType = cgFactory.newPrimitiveType("int");
		intArrayType = cgFactory.newArrayReferenceType(intType);
		intArrayArrayType = cgFactory.newArrayReferenceType(intArrayType);

		variableType = cgFactory.newClassReferenceType("Variable");
		variableArrayType = cgFactory.newArrayReferenceType(variableType);

		metaApplicationReuseType = cgFactory.newClassReferenceType("MetaApplicationReuse");
		metaApplicationSubstType = cgFactory.newClassReferenceType("MetaApplicationSubst");
		patternVariableUseType = cgFactory.newClassReferenceType("PatternVariableUse");
		contractumVariableUseType = cgFactory.newClassReferenceType("ContractumVariableUse");
		contractumFreshVariableUseType = cgFactory.newClassReferenceType("ContractumFreshVariableUse");
		namedVariablePropertyType = cgFactory.newClassReferenceType("NamedVariableProperty");
		constantMetaPropertyType = cgFactory.newClassReferenceType("ConstantMetaProperty");
		varTermPropertyType = cgFactory.newClassReferenceType("VarTermProperty");
		varMetaPropertyType = cgFactory.newClassReferenceType("VarMetaProperty");
		metaTermPropertyType = cgFactory.newClassReferenceType("MetaTermProperty");
		metaPropertyType = cgFactory.newClassReferenceType("MetaProperty");

		crsxClassBody = cgFactory.newClassBody("GeneratedCRSX");
		crsxStaticInitBlock = cgFactory.newBlock();
	}

	// Methods

	/** Create the code generator factory */
	protected abstract CodegenFactory makeCodegenFactory();

	void setConstructor(Map<SymbolArity, ConstructorEntry> constructors)
	{
		this.constructors = constructors;
	}

	void setSrcRoot(String srcRoot)
	{
		this.dest = new File(srcRoot);
	}

	void setPackageName(String packageName)
	{
		this.packageName = packageName;
	}

	/** Whether dependencies with the interpreter are allowed */
	void setStandalone(boolean value)
	{
		this.standalone = value;
	}

	// Implement Generator

	public void generateRule(GenericRule rule) throws CRSException
	{
		final ConstructorEntry leader = constructors.get(new SymbolArity(rule.getPattern().constructor().symbol(),
				rule.getPattern().arity()));
		final Map<String, MetaPosition> metaApps = new HashMap<String, MetaPosition>();
		final Map<Variable, Integer> binders = new HashMap<Variable, Integer>();

		final String methodName = "addRule" + leader.getId();
		Block ruleBlock = crsxClassBody.methodDeclaration("Rule " + leader.getSymbol(), new Modifier[]
			{Modifier.STATIC}, methodName).returnType(null).body();

		crsxStaticInitBlock.expr().fun(methodName).end().exprEnd();

		final LocalVariable patternVar = ruleBlock.fresh("pattern");
		ruleBlock = ruleBlock.localDeclaration(null, termType, patternVar).exprEnd();
		ruleBlock = generate(rule, rule.getPattern(), ruleBlock, patternVar, -1, true, binders, metaApps);

		final LocalVariable contractumVar = ruleBlock.fresh("contractum");
		ruleBlock = ruleBlock.localDeclaration(null, termType, contractumVar).exprEnd();
		ruleBlock = generate(rule, rule.getContractum(), ruleBlock, contractumVar, -1, false, binders, metaApps);

		ruleBlock = ruleBlock.expr().fun("addRule").integer(leader.getId()).next().local(patternVar).next().local(contractumVar).end().exprEnd();

		crsxClassBody = ruleBlock.methodDeclarationEnd();
		ruleCount++;
	}

	public void generateDispatchRules(List<GenericRule> rules) throws CRSException
	{
		GenericRule rule = rules.get(0);
		final ConstructorEntry leader = constructors.get(new SymbolArity(rule.getPattern().constructor().symbol(),
				rule.getPattern().arity()));
		final String methodName = "addDispatchRules" + leader.getId();

		Block dispatchRuleBlock = crsxClassBody.methodDeclaration("Rule " + leader.getSymbol(), new Modifier[]
			{Modifier.STATIC}, methodName).returnType(null).body();

		crsxStaticInitBlock.expr().fun(methodName).end().exprEnd();

		final LocalVariable rulesVar = dispatchRuleBlock.fresh("rules");
		dispatchRuleBlock = dispatchRuleBlock.localDeclaration(null, ruleArrayType, rulesVar).assign("=").makeArray(ruleType).integer(
				rules.size()).end().exprEnd();

		for (int i = 0; i < rules.size(); i++)
		{
			rule = rules.get(i);

			final Map<String, MetaPosition> metaApps = new HashMap<String, MetaPosition>();
			final Map<Variable, Integer> binders = new HashMap<Variable, Integer>();

			final LocalVariable patternVar = dispatchRuleBlock.fresh("pattern");
			dispatchRuleBlock = dispatchRuleBlock.localDeclaration(null, termType, patternVar).exprEnd();
			dispatchRuleBlock = generate(rule, rule.getPattern(), dispatchRuleBlock, patternVar, -1, true, binders, metaApps);

			dispatchRuleBlock = dispatchRuleBlock.comment("Dispatch rule contractum for" + leader.getSymbol());

			final LocalVariable contractumVar = dispatchRuleBlock.fresh("contractum");

			dispatchRuleBlock = dispatchRuleBlock.localDeclaration(null, termType, contractumVar).exprEnd();
			dispatchRuleBlock = generate(rule, rule.getContractum(), dispatchRuleBlock, contractumVar, -1, false, binders, metaApps);

			dispatchRuleBlock = dispatchRuleBlock.expr().local(rulesVar).index().integer(i).end().assign("=").fun("createRule").local(
					patternVar).next().local(contractumVar).end().exprEnd();
		}

		dispatchRuleBlock = dispatchRuleBlock.expr().fun("addDispatchRules").integer(leader.getId()).next().local(rulesVar).end().exprEnd();

		dispatchRuleBlock.methodDeclarationEnd();
		dispatchRuleCount++;
	}

	public void start()
	{
		dest.mkdirs();
	}

	public void end()
	{
		generateDictionary();
	}

	// Methods

	/** Gets the number of constructors, including functions and data */
	final public int getTermCount()
	{
		return constructors.size();
	}

	protected void generateDictionary()
	{}

	/** Parses templates */
	protected void parseTemplates(File file, String ext)
	{
		if (file.isDirectory())
		{
			File[] files = file.listFiles();
			for (int i = 0; i < files.length; i++)
			{
				parseTemplates(files[i], ext);
			}
		}
		else if (file.getName().endsWith(ext))
		{
			CodeTemplate template = CodeTemplate.load(file);
			templates.put(template.getName(), template);
		}
	}

	/** Escape characters so that it become a valid C++ and Java source string */
	protected String escape(String string)
	{
		return string.replace("\\", "\\\\").replace("\"", "\\\"");
	}

	/** Convert NL character to space */
	protected String escapeNL(String string)
	{
		return string.replace('\n', ' ');
	}

	/** Serialize code in the dest dir */
	protected void serialize(String filename, Code code)
	{
		File file = new File(dest.getPath() + File.separator + filename);
		code.write(file);
	}

	/** Just copy file into the right place, considering the given parameters */
	protected void copy(String templateName, String[] params)
	{
		Code code = templates.get(templateName).instantiate();
		if (params != null)
		{
			for (int i = 0; i < params.length; i += 2)
			{
				code.setParameter(params[i], params[i + 1]);
			}
		}

		serialize(templateName, code);
	}

	/** Tells whether the given term is an expression */
	protected boolean isExpression(Term term)
	{
		return term.kind() == Kind.CONSTRUCTION && term.constructor().symbol().equals("$") && term.arity() > 0;
	}

	/** 
	 * Returns the subkind of the given construction
	 * @return see SUBKIND constants
	 */
	protected int getSubkind(Term term)
	{
		if (isExpression(term))
		{
			// TODO: might become a more generic algo here if there is a need for it.
			final String exprName = term.sub(0).constructor().symbol();
			Integer value = EXPRESSIONS.get(exprName);
			if (value == null)
				throw new RuntimeException("Unsupported expression: " + term);

			return value;
		}
		return GENERIC_CONS;
	}

	/** Tells whether this construction has any binders */
	protected boolean hasSubbinders(Term construction)
	{
		for (int i = 0; i < construction.arity(); i++)
		{
			if (construction.binders(i) != null && construction.binders(i).length > 0)
				return true;
		}
		return false;
	}

	/** Tells whether this term has any properties */
	protected boolean hasProperties(Term term)
	{
		if (term instanceof PropertiesConstraintsWrapper)
		{
			final PropertiesConstraintsWrapper holder = (PropertiesConstraintsWrapper) term;
			if (holder.getLocalMetaProperties() != null && holder.getLocalMetaProperties().size() > 0)
				return true;

			if (holder.getLocalProperties() != null && holder.getLocalProperties().size() > 0)
				return true;

			if (holder.getLocalVariableProperties() != null && holder.getLocalVariableProperties().size() > 0)
				return true;
		}
		return false;
	}

	/** Count the number of properties */
	private int getPropertyCount(PropertiesConstraintsWrapper holder)
	{
		int count = holder.getLocalMetaProperties() == null ? 0 : holder.getLocalMetaProperties().size();
		count += holder.getLocalProperties() == null ? 0 : holder.getLocalProperties().size();
		count += holder.getLocalVariableProperties() == null ? 0 : holder.getLocalVariableProperties().size();
		return count;
	}

	/** 
	 * Gets the binder substitute position as stored in MatchingContext 
	 * @param variable binder occurring in the contractum
	 */
	protected int getBinderSubstitute(GenericRule rule, Variable variable, Map<Variable, Integer> binders)
	{
		// Can this variable be reused?
		Variable patternVar = rule.getReused(variable);
		if (patternVar != null)
		{
			// Gets its position in the pattern
			return binders.get(patternVar);
		}
		else
		{
			// Might just be a free variable
			Integer position = binders.get(variable);
			if (position != null)
				return position;

			// This is a fresh variable.
			return -1;
		}

	}

	/**
	 * Get the class name for the given construction and context use 
	 */
	protected String getClassName(boolean pattern, Term construction)
	{
		return pattern ? PATTERN_CLASSNAME[getSubkind(construction)] : CONTRACTUM_CLASSNAME[getSubkind(construction)];
	}

	/** 
	 * Add meta apps of the given name if is has not yet been encountered yet 
	 * @param metaVar
	 */
	private void addMetaApps(String metaVar, Term metaApp, Map<String, MetaPosition> metapps)
	{
		if (metapps.get(metaVar) == null)
			metapps.put(metaVar, new MetaPosition(metapps.size(), metaApp));
	}

	/**
	 * Generates code for the given term
	 * @param rule  
	 * @param term
	 * @param block
	 * @param assignTo
	 * @param index
	 * @param isPattern
	 * @param binders  
	 * @param metaApps List of meta apps with their position in the rule 
	 * @return
	 */
	private Block generate(GenericRule rule, Term term, Block block, LocalVariable assignTo, int index, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		switch (term.kind())
		{
			case CONSTRUCTION :
				return generateConstruction(rule, term, block, assignTo, index, isPattern, binders, metaApps);
			case META_APPLICATION :
				return generateMetaApp(rule, term, block, assignTo, index, isPattern, binders, metaApps);
			case VARIABLE_USE :
				return generateVariableUse(rule, term, block, assignTo, index, isPattern, binders, metaApps);
			default :
				throw new AssertionError();
		}
	}

	/**
	 * Generates code for the given construction
	 * @param rule  
	 * @param term
	 * @param block
	 * @param assignTo
	 * @param index
	 * @param isPattern
	 * @param binders List of binders occurring in the pattern associated to their position. Includes free variables  
	 * @param metaApps List of meta apps with their position in the rule 
	 * @return
	 */
	private Block generateConstruction(GenericRule rule, Term term, Block block, LocalVariable assignTo, int index, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		// Generate properties
		LocalVariable cgProperties = null;
		if (hasProperties(term))
		{
			cgProperties = block.fresh("properties");
			block = generateProperties(rule, (PropertiesConstraintsWrapper) term, block, cgProperties, isPattern, binders, metaApps);
		}

		// Generate binders..
		int bindersStartingPosition = -1;
		LocalVariable cgReused = null;

		if (hasSubbinders(term))
		{
			bindersStartingPosition = binders.size();// - 1;

			if (isPattern)
			{
				for (int i = 0; i < term.arity(); i++)
				{
					Variable[] subbinders = term.binders(i);
					if (subbinders != null)
					{
						for (int j = 0; j < subbinders.length; j++)
							binders.put(subbinders[j], binders.size());
					}
				}
			}
			else
			{
				// Generate the reused parameter value

				cgReused = block.fresh("reused");

				//Type arrayType = cgFactory.newClassReferenceType("int[" + term.arity() + "]");

				block = block.localDeclaration(null, intArrayArrayType, cgReused).assign("=").makeArray(intArrayType).integer(
						term.arity()).next().omit().end().exprEnd();

				for (int i = 0; i < term.arity(); i++)
				{
					final Variable[] vars = term.binders(i);
					if (binders != null && vars.length > 0)
					{
						// In Java: int iXX[] = new int[size]; iXX[i] = xx;
						// In C: int* iXX[] = new int[size]; iXX[i] = xx; 
						LocalVariable cgI = block.fresh("i");
						block = block.localDeclaration(null, intArrayType, cgI).assign("=").makeArray(intType).integer(vars.length).end().exprEnd();

						for (int j = 0; j < vars.length; j++)
						{
							int position = getBinderSubstitute(rule, vars[j], binders);
							if (position == -1)
							{
								// This is a new subbinding
								position = binders.size() | 0x1000;
								binders.put(vars[j], binders.size());
							}

							block = block.expr().local(cgI).index().integer(j).end().assign("=").integer(position).exprEnd();

						}

						block = block.expr().local(cgReused).index().integer(i).end().assign("=").local(cgI).exprEnd();
					}
					else
					{

						block = block.expr().local(cgReused).index().integer(i).end().assign("=").nil().exprEnd();
					}

				}
			}
		}

		// Generate subs
		LocalVariable cgArgs = null;
		if (term.arity() > 0)
		{
			// In Java: Term[] args = new Term[ size ] 
			cgArgs = block.fresh("args");
			block = block.localDeclaration(null, termArrayType, cgArgs).assign("=").makeArray(termType).integer(term.arity()).end().exprEnd();

			for (int i = 0; i < term.arity(); i++)
				block = generate(rule, term.sub(i), block, cgArgs, i, isPattern, binders, metaApps);
		}

		// Generate construction
		final ConstructorEntry entry = constructors.get(new SymbolArity(term.constructor().symbol(), term.arity()));

		Expr expr;
		expr = block.expr().local(assignTo);
		if (index != -1)
			expr = expr.index().integer(index).end(); // [ index ]

		expr = expr.assign("=").make(cgFactory.newClassReferenceType(getClassName(isPattern, term)));

		if (getSubkind(term) == GENERIC_CONS)
		{
			// Generate id 
			expr = expr.integer(entry.getId());

			// Generate variable binders
			if (isPattern)
			{
				// Generate 'bindersStartingPosition' parameter
				expr = expr.next().integer(bindersStartingPosition);
			}
			else
			{
				expr = expr.next();
				// Generate 'reused'
				if (cgReused != null)
					expr = expr.local(cgReused);
				else
					expr = expr.nil();
			}

			// Generates properties
			expr = expr.next();
			if (cgProperties == null)
				expr = expr.nil();
			else
				expr = expr.local(cgProperties);

			// Generate subs
			expr = expr.next();
			if (cgArgs == null)
				expr = expr.nil();
			else
				expr = expr.local(cgArgs);

			// Close expression
			block = expr.end().exprEnd();
		}
		else
		{
			// This is an expression. For now use "interpreter".

			// Generate properties
			if (cgProperties == null)
				expr = expr.nil();
			else
				expr = expr.local(cgProperties);

			// Generate subs
			expr = expr.next();
			if (cgArgs == null)
				expr = expr.nil();
			else
				expr = expr.local(cgArgs);

			// Close expression
			block = expr.end().exprEnd();
		}

		return block;
	}

	/**
	 * Generates code for the given variable use
	 * @param rule  
	 * @param block
	 * @param assignTo
	 * @param index
	 * @param isPattern
	 * @param binders  
	 * @param metaApps List of meta apps with their position in the rule 
	 * @param term
	 * 
	 * @return
	 */
	private Block generateVariableUse(GenericRule rule, Term use, Block block, LocalVariable assignTo, int index, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		Expr expr = block.expr().local(assignTo);
		if (index > -1)
			expr = expr.index().integer(index).end();

		int position = getBinderSubstitute(rule, use.variable(), binders);
		final boolean free = position == -1;
		if (free)
		{
			// Allocate a spot in MatchingContext in case the variable is also used in the contractum
			position = binders.size();
			binders.put(use.variable(), position);
		}

		if (isPattern)
		{
			block = expr.assign("=").make(patternVariableUseType).integer(position).next().bool(free).end().exprEnd();
		}
		else
		{
			expr = expr.assign("=");
			if (free)
			{
				// This is the first occurrence of a fresh variable in the contractum

				// TODO: position should not be needed. 
				block = expr.make(contractumFreshVariableUseType).string(use.variable().name()).next().integer(position).end().exprEnd();
			}
			else
				block = expr.make(contractumVariableUseType).integer(position).end().exprEnd();
		}
		return block;
	}

	/**
	 * Generates code for the given meta application
	 * @param rule  
	 * @param metaApp
	 * @param block
	 * @param assignTo
	 * @param index
	 * @param isPattern
	 * @param binders  
	 * @param metaApps List of meta apps with their position in the rule 
	 * @return
	 */
	private Block generateMetaApp(GenericRule rule, Term metaApp, Block block, LocalVariable assignTo, int index, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		// Generate properties
		LocalVariable cgProperties = null;
		if (hasProperties(metaApp))
		{
			cgProperties = block.fresh("properties");
			block = generateProperties(
					rule, (PropertiesConstraintsWrapper) metaApp, block, cgProperties, isPattern, binders, metaApps);
		}

		if (isPattern)
			addMetaApps(metaApp.metaVariable(), metaApp, metaApps);

		final MetaPosition mp = metaApps.get(metaApp.metaVariable());

		// Is this a meta application occurring in a contractum and requiring substitution?
		Integer contractionCount = rule.getExplicitCount(metaApp.metaVariable());
		final boolean substitute = !isPattern && contractionCount == null && mp.metaApp.arity() > 0;
		LocalVariable cgSubstVars = null;
		LocalVariable cgSubsts = null;
		if (substitute)
		{
			// Generate variables to substitute position in MetaContext
			final int substCount = mp.metaApp.arity();

			cgSubstVars = block.fresh("substVars");
			block = block.localDeclaration(null, intArrayType, cgSubstVars).assign("=").makeArray(intType).integer(substCount).end().exprEnd();

			for (int i = 0; i < substCount; i++)
			{
				Variable var = mp.metaApp.sub(0).variable();
				Integer pos = binders.get(var);

				block = block.expr().local(cgSubstVars).index().integer(i).end().assign("=").integer(pos).exprEnd();
			}

			// Generate terms substitutes
			cgSubsts = block.fresh("substTerms");
			block = block.localDeclaration(null, termArrayType, cgSubsts).assign("=").makeArray(termType).integer(substCount).end().exprEnd();
			for (int i = 0; i < substCount; i++)
				block = generate(rule, metaApp.sub(i), block, cgSubsts, i, false, binders, metaApps);

		}

		// Generate MetaApplication ...
		Expr expr = block.expr().local(assignTo);
		if (index >= 0)
			expr = expr.index().integer(index).end();

		expr = expr.assign("=").make(substitute ? metaApplicationSubstType : metaApplicationReuseType).integer(mp.position);

		if (cgProperties != null)
			expr = expr.next().local(cgProperties);
		
		if (substitute)
		{
			expr = expr.next().local(cgSubstVars).next().local(cgSubsts);
		}

		return expr.end().exprEnd();
	}

	/**
	 * 
	 * @param rule  
	 * @param holder
	 * @param block
	 * @param cgProperties 
	 * @param isPattern  
	 * @param binders  
	 * @param metaApps  List of meta apps with their position in the rule 
	 * @return
	 */
	private Block generateProperties(GenericRule rule, PropertiesConstraintsWrapper holder, Block block, LocalVariable cgProperties, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		final int propertyCount = getPropertyCount(holder);
		if (propertyCount > 0)
		{
			// In Java: Property[] properties = new Property[ size ]

			block = block.localDeclaration(null, propertyConstraintArrayType, cgProperties).assign("=").makeArray(
					propertyConstraintType).integer(propertyCount).end().exprEnd();

			int i = 0;

			// Generates named properties
			for (String name : holder.propertyNames())
			{
				block = generateNamedProperty(
						rule, name, holder.getProperty(name), block, cgProperties, i++, isPattern, binders, metaApps);
			}

			// Generate variable properties
			for (Variable var : holder.propertyVariables())
			{
				block = generateVariableProperty(
						rule, var, holder.getProperty(var), block, cgProperties, i++, isPattern, binders, metaApps);
			}

			// Generate meta properties
			Map<String, Term> metaProps = holder.getLocalMetaProperties();
			if (metaProps != null)
			{
				for (String meta : metaProps.keySet())
					block = generateMetaProperty(rule, meta, metaProps.get(meta), block, cgProperties, i++, isPattern, binders, metaApps);
			}

		}
		else
		{
			block = block.localDeclaration(null, propertyConstraintArrayType, cgProperties).assign("=").nil().exprEnd();
		}
		return block;
	}

	/** 
	 * Generate code for the given named property 
	 * @param rule  
	 * @param name
	 * @param isPattern TODO
	 * @param binders  
	 * @param metaApps  List of meta apps with their position in the rule 
	  */
	private Block generateNamedProperty(GenericRule rule, String name, Term property, Block block, LocalVariable cgProperties, int i, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		Expr expr = block.expr().local(cgProperties);
		if (i >= 0)
			expr = expr.index().integer(i).end();
		expr = expr.assign("=");

		switch (property.kind())
		{
			case CONSTRUCTION : // "name" : "a"
				throw new RuntimeException("named construction property not supported");
				//return block;
			case META_APPLICATION : // "name":#x  
				if (isPattern)
					addMetaApps(property.metaVariable(), property, metaApps);

				block = expr.make(constantMetaPropertyType).string(name).next().integer(
						metaApps.get(property.metaVariable()).position).end().exprEnd();
				return block;
			case VARIABLE_USE : // "name" : var 
				block = expr.make(namedVariablePropertyType).string(name).next().integer(
						getBinderSubstitute(rule, property.variable(), binders)).end().exprEnd();
				return block;
			default :
				throw new AssertionError();
		}

	}

	/** 
	 * Generate code for the given variable property 
	 * @param rule   
	 * @param isPattern  
	 * @param binders  
	 * @param metaApps  List of meta apps with their position in the rule 
	 * @param name
	  */
	private Block generateVariableProperty(GenericRule rule, Variable var, Term property, Block block, LocalVariable cgProperties, int i, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		switch (property.kind())
		{
			case CONSTRUCTION : // <var>: term
			{
				LocalVariable cgPropTerm = block.fresh("propTerm");
				block = block.localDeclaration(null, termType, cgPropTerm).exprEnd();
				block = generate(rule, property, block, cgPropTerm, -1, isPattern, binders, metaApps);

				Expr expr = block.expr().local(cgProperties);
				if (i >= 0)
					expr = expr.index().integer(i).end();

				int varPosition = getBinderSubstitute(rule, property.variable(), binders);
				final boolean free = varPosition == -1;
				if (free) // free variable?
				{
					varPosition = binders.size();
					binders.put(var, varPosition);
				}

				block = expr.assign("=").make(varTermPropertyType).integer(varPosition).next().bool(free).next().local(cgPropTerm).end().exprEnd();
				break;
			}

			case META_APPLICATION : // <var>:#meta
			{
				if (isPattern)
					addMetaApps(property.metaVariable(), property, metaApps);

				Expr expr = block.expr().local(cgProperties);
				if (i >= 0)
					expr = expr.index().integer(i).end();
				block = expr.assign("=").make(varMetaPropertyType).integer(getBinderSubstitute(rule, property.variable(), binders)).next().integer(
						metaApps.get(property.metaVariable()).position).end().exprEnd();
				break;
			}

			case VARIABLE_USE : // <var1>:<var2>
				throw new RuntimeException("variable property not supported");
		}

		return block;
	}

	/** 
	 * Generate code for the given meta property 
	 * @param rule  
	 * @param pair
	 * @param binders  
	 * @param metaApps  List of meta apps with their position in the rule 
	  */
	private Block generateMetaProperty(GenericRule rule, String meta, Term property, Block block, LocalVariable cgProperties, int i, boolean isPattern, Map<Variable, Integer> binders, Map<String, MetaPosition> metaApps)
	{
		if (isPattern)
			addMetaApps(meta, null, metaApps);
		final MetaPosition mp = metaApps.get(meta);
		
		if (property == null)
		{
			// Property of the form  #c
			Expr expr = block.expr().local(cgProperties);
			if (i >= 0)
				expr = expr.index().integer(i).end();

			block = expr.assign("=").make(metaPropertyType).integer(mp.position).end().exprEnd();
		}
		else
		{
			// Property of the form #c: Term
			LocalVariable cgTerm = block.fresh("term");
			block = block.localDeclaration(null, termType, cgTerm).exprEnd();
			block = generate(rule, property, block, cgTerm, -1, isPattern, binders, metaApps);
			
			
			Expr expr = block.expr().local(cgProperties);
			if (i >= 0)
				expr = expr.index().integer(i).end();
			block = expr.assign("=").make(metaTermPropertyType).integer(mp.position).next().local(cgTerm).end().exprEnd();
		}
		return block;
	}

	// Inner classes

	static class MetaPosition
	{
		final int position;
		final Term metaApp;

		MetaPosition(int position, Term metaApp)
		{
			this.position = position;
			this.metaApp = metaApp;

		}
	}

}
