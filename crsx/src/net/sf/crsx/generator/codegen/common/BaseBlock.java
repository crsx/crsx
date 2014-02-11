/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.common;

import java.util.Map;

import net.sf.crsx.generator.codegen.Block;
import net.sf.crsx.generator.codegen.ClassBody;
import net.sf.crsx.generator.codegen.Expr;
import net.sf.crsx.generator.codegen.LocalVariable;
import net.sf.crsx.generator.codegen.Type;

/**
 * 
 * @author villardl
 */
public class BaseBlock extends BaseContext implements Block
{
	 
	// Constructors

	/** Constructor for standalone block */
	public BaseBlock(StringBuilder output, Map<String, LocalVariable> variables)
	{
		super(null);
		
		this.builder = output;
		this.variables = variables; 
	}
	
	/** Construct a new block */
	public BaseBlock(BaseContext parent)
	{
		super(parent); 
	}

	 // Implements Block

	public Block comment(String comment)
	{
		getOutput().append("/**").append(comment).append("*/\n"); // TODO: escaping
		return this;
	}

	public Expr expr()
	{
		return new BaseExpr(this);
	}

	public Expr localDeclaration(String comment, Type type, LocalVariable variable)
	{
		getOutput().append(type);
		
		if (type.isArray())
		{
			Type arrayType = type;
			do
			{
				getOutput().append("[]");
				arrayType = arrayType.getBaseType();
			} while (arrayType.isArray());
		}
		getOutput().append(' ').append(variable);
		return new BaseExpr(this);
	}

	public ClassBody methodDeclarationEnd()
	{
		getOutput().append("\n}");
		return (ClassBody) parent.parent.parent;
	}
	 


}
