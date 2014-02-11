/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import net.sf.crsx.generator.codegen.Block;
import net.sf.crsx.generator.codegen.Expr;
import net.sf.crsx.generator.codegen.LocalVariable;
import net.sf.crsx.generator.codegen.Type;

/**
 * 
 * @author villardl
 */
public class BaseExpr extends BaseContext implements Expr
{

	// Constructors

	BaseExpr(BaseContext parent)
	{
		super(parent);
	}

	// Implements Expr

	public Expr cast(String type)
	{
		throw new RuntimeException();
	}

	public Expr fun(String function)
	{
		getOutput().append(function).append("(");
		return this;
	}

	public Expr integer(int i)
	{
		getOutput().append(Integer.toString(i));
		return this;
	}

	public Expr bool(boolean bool)
	{
		getOutput().append(bool ? "true" : "false");
		return this;
	}

	public Expr literal(String literal)
	{
		getOutput().append(literal);
		return this;
	}

	public Expr string(String string)
	{
		getOutput().append('"').append(string).append('"');
		return this;
	}

	public Expr local(LocalVariable variable)
	{
		getOutput().append(variable);
		return this;
	}

	public Expr make(Type type)
	{
		getOutput().append("new ").append(type).append("(");
		return this;
	}

	public Expr makeArray(Type type)
	{
		getOutput().append("new ").append(type).append("[");
		return new MakeArrayExpr(type, this);
	}

	public Expr nil()
	{
		getOutput().append("null");
		return this;
	}

	public Expr omit()
	{
		return this;
	}

	public Expr op(String operator)
	{
		throw new RuntimeException();
	}

	public Expr self()
	{
		throw new RuntimeException();
	}

	public Expr assign(String assignOp)
	{
		getOutput().append("=");
		return this;
	}

	public Expr castEnd()
	{
		throw new RuntimeException();
	}

	public Expr end()
	{
		getOutput().append(")");
		return this;
	}

	public Block exprEnd()
	{
		getOutput().append(";\n");
		return (Block) parent;
	}

	public Expr index()
	{
		getOutput().append("[");
		return new IndexExpr(this);
	}

	public Expr next()
	{
		getOutput().append(",");
		return this;
	}

	public Expr ref(String field)
	{
		throw new RuntimeException();
	}

	// Inner classes

	protected static class MakeArrayExpr extends IndexExpr
	{
		// State

		/** Array base type */
		protected Type type;
 
		// Constructors

		protected MakeArrayExpr(Type type, BaseExpr next)
		{
			super(next);
 
			this.type = type;
		}

		@Override
		public Expr next()
		{
			// Expect an array type as a base type
			type = type.getBaseType();
			getOutput().append("][");
			return this;
		}

	}

	protected static class IndexExpr extends BaseExpr
	{
		// State

		/** Continuing expression */
		final protected BaseExpr expr;

		// Constructors

		protected IndexExpr(BaseExpr next)
		{
			super(next.parent);

			this.expr = next;
		}

		@Override
		public Expr end()
		{
			getOutput().append("]");
			return expr;
		}

	}

}
