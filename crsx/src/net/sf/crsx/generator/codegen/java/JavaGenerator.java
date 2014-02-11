/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator.codegen.java;

import java.io.File;
import java.util.Iterator;

import net.sf.crsx.generator.AbstractGenerator;
import net.sf.crsx.generator.Code;
import net.sf.crsx.generator.ConstructorEntry;
import net.sf.crsx.generator.SymbolArity;
import net.sf.crsx.generator.codegen.CodegenFactory;

/**
 * Java code generator for simplified CRS rule collections.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class JavaGenerator extends AbstractGenerator
{

	// State

	/** Parameters for {@link #copy(String, String[])}*/
	protected String[] copyParams;

	// Contructors

	public JavaGenerator()
	{
		super();

		parseTemplates(new File("src/net/sf/crsx/generator/java/templates"), ".java");
	}

	// Overrides
	

	@Override
	protected CodegenFactory makeCodegenFactory()
	{
		return new JavaCodegenFactory();
	}

	
	// Implements Generator

	public void end()
	{
		super.end();

		// Copy non-configurable files 
		copy("MatchingContext.java", copyParams);
		copy("Term.java", copyParams);
		copy("NativeSink.java", copyParams);
		copy("Rule.java", copyParams);
		copy("Variable.java", copyParams);
		copy("VariableUse.java", copyParams);
		copy("Construction.java", copyParams);
		copy("MetaApplicationReuse.java", copyParams);
		copy("MetaApplicationSubst.java", copyParams);
		copy("ConcatenationExpr.java", copyParams);
		copy("TermConstructionExpr.java", copyParams);
		copy("IfDefExpr.java", copyParams);
		copy("PlusExpr.java", copyParams);
		copy("IfExpr.java", copyParams);
		copy("GetExpr.java", copyParams);
		copy("IndexExpr.java", copyParams);
		copy("ContainsExpr.java", copyParams);
		copy("SubstringExpr.java", copyParams);
		copy("PropertyConstraint.java", copyParams);
		copy("Properties.java", copyParams);
		copy("PropertyConstraintConstruction.java", copyParams);
		copy("VarTermProperty.java", copyParams);
		copy("MetaTermProperty.java", copyParams);
		copy("NotVariableProperty.java", copyParams);
		copy("ConstantMetaProperty.java", copyParams);
		copy("VarMetaProperty.java", copyParams);
		copy("NotMetaProperty.java", copyParams);
		copy("NamedVariableProperty.java", copyParams);
		copy("MetaProperty.java", copyParams);
		copy("ContractumConstruction.java", copyParams);
		copy("ContractumVariableUse.java", copyParams);
		copy("ContractumFreshVariableUse.java", copyParams);
		copy("FunctionConstruction.java", copyParams);
		copy("PatternConstruction.java", copyParams);
		copy("PatternVariableUse.java", copyParams);
		copy("TermConstruction.java", copyParams);
		copy("ErrorExpr.java", copyParams);
		copy("NotMatchExpr.java", copyParams);
		copy("Utils.java", copyParams);
		copy("TextSink.java", copyParams);
		copy("TermSink.java", copyParams);

		copy("XPath2FIX.java", copyParams);

		if (!standalone)
		{
			copy("FromSink.java", copyParams);
			copy("ToSink.java", copyParams);
		}
	}

	@Override
	public void start()
	{
		// Fix destination
		String p = packageName.replace(".", File.separator);
		dest = new File(dest, p);

		super.start();

		copyParams = new String[]
			{"PACKAGE", packageName};
	}
 
	@Override
	protected void generateDictionary()
	{
		super.generateDictionary();

		Code dictionary = templates.get("Dictionary.java").instantiate();

		StringBuilder builder = new StringBuilder();

		int count = 0;
		for (Iterator<SymbolArity> iterator = constructors.keySet().iterator(); iterator.hasNext();)
		{
			ConstructorEntry entry = constructors.get(iterator.next());
			builder.append("add(\"").append(escape(entry.getSymbol())).append("\",").append(entry.getId()).append(");\n");
			count++;
		}
		dictionary.setParameter("DICTIONARY", builder.toString());
		dictionary.setParameter("COUNT", Integer.toString(count));

		dictionary.setParameter("PACKAGE", packageName);
		serialize("Dictionary.java", dictionary);

		// Configure GeneratedCRS
		Code run = templates.get("GeneratedCRSX.java").instantiate();
		run.setParameter("PACKAGE", packageName);
		run.setParameter("TERMCOUNT", Integer.toString(getTermCount()));
		run.setParameter("RULES", crsxClassBody.toString()); 
		run.setParameter("STATICINIT", crsxStaticInitBlock.toString()); 

		if (standalone)
		{
			run.setParameter("IMPORTSINK", "");
			run.setParameter("NORMALIZESINK", "");
		}

		serialize("GeneratedCRSX.java", run);
	} 

}
