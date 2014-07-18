/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.java;

import java.util.HashMap;

import net.sf.crsx.generator.codegen.Block;
import net.sf.crsx.generator.codegen.ClassBody;
import net.sf.crsx.generator.codegen.CodegenFactory;
import net.sf.crsx.generator.codegen.LocalVariable;
import net.sf.crsx.generator.codegen.Type;
import net.sf.crsx.generator.codegen.common.BaseArrayType;
import net.sf.crsx.generator.codegen.common.BaseBlock;
import net.sf.crsx.generator.codegen.common.BaseClassBody;
import net.sf.crsx.generator.codegen.common.BaseType;

/**
 * 
 * @author villardl
 */
public class JavaCodegenFactory extends CodegenFactory
{

	@Override
	public Type newPrimitiveType(String name)
	{
		return new BaseType(name, true);
	}

	@Override
	public Type newClassReferenceType(String classname)
	{
		return new BaseType(classname, false);
	}

	@Override
	public Type newArrayReferenceType(Type type)
	{
		return new BaseArrayType(type);
	}

	@Override
	public Block newBlock()
	{
		return new BaseBlock(new StringBuilder(), new HashMap<String, LocalVariable>());
	}

	@Override
	public ClassBody newClassBody(String classname)
	{
		return new BaseClassBody(classname);
	}

}
