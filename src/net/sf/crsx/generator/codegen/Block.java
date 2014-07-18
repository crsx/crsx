/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen;


/** 
 * Block of statements. 
 */
public interface Block extends Context
{
	/**
	 * add a comment
	 *
	 */
	public Block comment(String comment);
	
	/**
	 * Expression statement. End it with {@link Expr#endExpr}.
	 */
	public Expr expr();

  
	/**
	 * Local variable declaration followed by an assignment.
	 *  
	 * <p>Generates: 
	 * <ul>
	 * <li>In Java: <pre>Type variable =</pre>
	 * <li>In C: <pre>Type variable =</pre>
	 * </ul> 
	 *  
	 * @param comment 
	 * @param type
	 * @param variable used within remainder on block
	 *  
	 */
	public Expr localDeclaration(String comment, Type type, LocalVariable variable);
	
	/**
	 * Ends method declaration
	 * @see ClassBody#methodDeclaration
	 * @return class generation context with method declaration added
	 */
	public ClassBody methodDeclarationEnd();
  
}