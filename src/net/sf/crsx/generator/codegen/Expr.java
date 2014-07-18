/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen;

/** 
 * Expression 
 */
public interface Expr extends Context
{

	/**
	 * Null reference or pointer
	 * @return
	 */
	public Expr nil();

	/**
	 * Local variable reference. Usage: <blockquote>.local("v") </blockquote> corresponds to the Java <code>v</code>.
	 * 
	 * @param variable to reference
	 * @return expression continuation context
	 */
	public Expr local(LocalVariable variable);

	/**
	 * Construct object instance.
	 * 
	 * <p>Usage: <pre>make(type) <i>Arg </i> <sub>1 </sub> .next() <i>Arg </i> <sub>2 </sub> .end() </pre>
	 * 
	 * Generates:
	 * <ul>
	 * <li>In Java: <blockquote>new Type( ...)</blockquote>
	 * <li>In C: <blockquote>new Type( ...)</blockquote>
	 * </ul>
	 * 
	 * @param Type
	 */
	public Expr make(Type type);

	/**
	 * Construct array of another type.
	 *  
	 * <p>Usage: <blockquote>make(type) <i>Size1 </i> .next() <i>Size2</i> ... .end() </blockquote>
	 * 
	 * Generates:
	 * <ul>
	 * <li>In Java: <blockquote>new Type[ ... ][ ... ]</blockquote>
	 * <li>In C: <blockquote>new std::vector< std::vector < ... > >(Size1)</blockquote>
	 * </ul>
	 * 
	 * @param Type
	 */
	public Expr makeArray(Type type);

	/**
	 * Operator expression. Usage:
	 * 
	 * <blockquote>.op("+") <i>Expr </i> <sub>1 </sub> .next()...next() <i>Expr </i> <sub>n </sub> .end()
	 * </blockquote>
	 * 
	 * corresponding to <blockquote>( <i>Expr </i> <sub>1 </sub> +...+ <i>Expr </i> <sub>n </sub>) </blockquote>
	 * <p>
	 * Note: do <em>not</em> use for (object reference) assignments!
	 * 
	 * @param operator string with the Java operator
	 * @return expression context for first actual parameter
	 */
	public Expr op(String operator);

	/**
	 * Function or prefix operator expression. Usage:
	 * 
	 * <blockquote>.op("f") <i>Expr </i> <sub>1 </sub> .next()...next() <i>Expr </i> <sub>n </sub> .end()
	 * </blockquote>
	 * 
	 * corresponding to <blockquote>f( <i>Expr </i> <sub>1 </sub> ,..., <i>Expr </i> <sub>n </sub>) </blockquote>
	 * 
	 * <p>
	 * Note: do <em>not</em> use for (object reference) assignments!
	 * 
	 * @param operator string with the Java operator
	 * @return expression context for first actual parameter
	 */
	public Expr fun(String function);

	/**
	 * Literal expression or built-in.
	 * 
	 * @param literal string with Java/C literal
	 * @return expression context where literal has just been added
	 */
	public Expr literal(String literal);

	/**
	 * Literal integer.
	 * 
	 * @param i literal integer
	 */
	public Expr integer(int i);
	
	/**
	 * Literal boolean.
	 * 
	 * @param i literal boolean
	 */
	public Expr bool(boolean i);

	/**
	 * Literal string expression.
	 * 
	 * @param literal string with Java literal string content
	 * @return expression context where literal has just been added
	 */
	public Expr string(String string);

	/**
	 * Cast expression.
	 * <p>
	 * Usage: <blockquote>.cast("Type"). <i>Expr </i> .castEnd() </blockquote> 
	 * corresponds to in Java
	 * <bockquote>((Type) <i>Expr </i>) </blockquote>
	 * 
	 * @param type to cast to
	 * @return expression context ready to accept the expression to cast
	 */
	public Expr cast(String type);

	/**
	 * @see Block#expr
	 * @return block context with statement expression added
	 */
	public Block exprEnd();

	/**
	 * Assignment statement. 
	 * 
	 * <p>Usage: <blockquote>.assignExpr(). <i>Expr </i> .endExpr() </blockquote> 
	 * 
	 * @param assignOp  
	 * @return expression context to generate assignment operands
	 */
	public Expr assign(String assignOp);

	/**
	 * Array index.  
	 * <p>Usage: <blockquote>.index() <i> index </i> .end() </blockquote>
	 */
	public Expr index();

	/**
	 * Field reference. Usage: <blockquote><i>Expr </i> .ref("f") </blockquote> corresponds to the Java <i>Expr
	 * </i> <code>.f</code>.
	 * 
	 * @param field name
	 * @return expression continuation context
	 */
	public Expr ref(String field);

	/**
	 * Continue to next parameter in parameter list.
	 * 
	 * @see #invoke, #op
	 * @return expression context for next actual parameter
	 */
	public Expr next();
	
	/** 
	 * Omit the expression
	 */
	public Expr omit();

	/**
	 * Finish parameter list.
	 * 
	 * @see #attach, #detach, #invoke, #op
	 * @return expression context where invocation, construction or operation has just been added
	 */
	public Expr end();

	/**
	 * @see #cast
	 */
	public Expr castEnd();

	
}