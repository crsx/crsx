/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

import java.io.Closeable;

/**
 * Java interface to building block-structured source code.
 * Works with two assumptions:
 * <ol>
 * <li>Statements are organized into delimited blocks.
 * <li>Code is organized in statements and expressions,
 * 		where an expression E can be promoted to an assignment statement.
 * </ol>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SourceBuilder.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface SourceBuilder extends Closeable
{
	/**
	 * Open a nested block after the last statement.  Increases {@link #nesting()}.
	 * The current expression is retained.
	 * @param opener for the block (for Java "{" works)
	 * @return this (for convenience)
	 */
	SourceBuilder openBlock(CharSequence opener);
	
	/**
	 * Close the current block. Only valid when an inner block has been created and &not;{@link #seeded()}. 
	 * Decreases {@link #nesting()}.
	 * @param closer for the block (for Java "}" works)
	 * @return this (for convenience)
	 */
	SourceBuilder closeBlock(CharSequence closer);
	
	/** The current nesting level. */
	int nesting();
	
	/**
	 * Whether an expression is currently under construction.
	 * Set by {@link #seedExpression(CharSequence)} and cleared by {@link #harvest()}.
	 */
	boolean seeded();
	
	/**
	 * Seed the current expression to indicated expression.
     * (Undefined if there is already a current expression.)
	 * @return this (for convenience)
	 */
	SourceBuilder seedExpression(CharSequence expression);

    /**
     * Wrap the current expression to produce a new expression in the current block.
     * The new expression will consist of the previous one between the pre and post fragments.
     * (Undefined if there is no current expression.)
     * @return this (for convenience)
     */
    SourceBuilder wrapExpression(CharSequence pre, CharSequence post);
    
	/**
	 * Extract the current expression, and clear it.
	 */
	CharSequence harvest();
	
	/**
	 * Add a new statement to the current block, after all previous statements.
	 * Changes neither the nesting nor the current expression. 
	 * @return this (for convenience)
	 */
	SourceBuilder addStatement(CharSequence statement);
	
	/** Get number at each invocation that is unique across the use of this builder. */
	int count();
	
	/** The prefix (applied before the indentation). */
	String prefix();
	
	/** Set the {@link #prefix()}. */
	void setPrefix(String prefix);
}
