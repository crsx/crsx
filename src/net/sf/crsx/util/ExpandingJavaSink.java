/* Copyright (c)  2008 IBM Corporation. */
package net.sf.crsx.util;

import java.util.Map;

import net.sf.crsx.Constructor;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Variable;

/**
 * Code generating sink hacked to emit previously allocated variables and subterms.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: ExpandingJavaSink.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class ExpandingJavaSink extends PlainJavaSink
{
	// State.
	
	/** Maps variables in term to the parsed variable name. */
	final Map<Variable, String> variable2name;
	
	/** Maps meta-variable to invocation for generating it? */
	final Map<String, Triple<String, String, String>> metavariable2expr;

	/** Set when ignoring variable occurrences... */
	boolean ignoreVariableUse;
	
	/** Statement to execute when meta-application ends. */
	String pendingMetaApplicationEnd;
	
	// Constructor.
	
	/**
	 * Create instance that emits Java code for received sink events.
	 * 
	 * @param maker in case someone asks this sink to create constructors or variables...
	 * @param makerName with name of variable that generated code can use as factory
	 * @param sinkName name of sink variable that the generated code should maintain
	 * @param java for the code text
	 * @param variable2java the Java names for actual {@link Variable}s
	 * @param variable2name maps variables in term to the parsed variable name
	 * @param metavariable2expr maps meta-variables in term to expression triples:
	 *		<ol>
	 *		<li>necessary setup statements,
	 * 		<li>method invocations to begin the meta-variable, and
	 * 		<li>method invocations to end the meta-variable, or <b>null</b> for meta-variables where the parameter variables should be ignored.
	 * 		</ol>
	 */
	public ExpandingJavaSink(Maker maker, String sinkName, SourceBuilder java, Map<Variable, String> variable2java, Map<Variable, String> variable2name, Map<String, Triple<String, String, String>> metavariable2expr)
	{
		super(maker, sinkName, java, variable2java);
		this.variable2name = variable2name;
		this.metavariable2expr = metavariable2expr;
	}
	
	// Sink...

	public Sink start(Constructor constructor)
	{
		return super.start(constructor);
	}

	public Sink end()
	{
		return super.end();
	}

	public Sink use(Variable variable)
	{
		return (ignoreVariableUse ? this : super.use(variable));
	}

	public Sink binds(Variable[] binders)
	{
		java.openBlock("{"); // sic

		// Go through the binder variables...
		StringBuilder bs = new StringBuilder();
		BINDERS: for (Variable b : binders)
		{
			if (bs.length() > 0) bs.append(",");

			// First search for predefinition of the binder. 
			for (Map.Entry<Variable, String> e : variable2java.entrySet())
			{
				Variable v = e.getKey();
				String j = e.getValue(); // Java
				if (v.name().equals(b.name()))
				{
					// v is the stand-in for b in the parsed term.
					bs.append(j); // put in generated binding list
					variable2java.put(b, j); // make sure references expand right
					continue BINDERS;
				}
			}
			
			// The variable is previously unknown...create it and make sure it is used!
			String n = "v_"+java.count();
			java.addStatement(VARIABLE+" "+n+" = "+sinkName+".makeVariable("+Util.quoteJava(b.name())+","+b.promiscuous()+");");
			bs.append(n); // put in generated binding list
			variable2java.put(b, n); // make sure references expand right		
		}

		// Emit binders.
		String bsName = "bs"+java.count();
		java.addStatement(VARIABLE+"[] "+bsName+" = {"+bs+"};");
		java.wrapExpression("", ".binds("+bsName+")");
		
		return this;
	}

	public Sink startMetaApplication(String name)
	{
		// If this meta-variable corresponds to a non-terminal then output the requested non-terminal...
		Triple<String, String, String> lookup = metavariable2expr.get(name);
		if (lookup != null)
		{
			// Delegate code generation to production.
			String one = lookup.one();
			if (one.length() > 0)
			    java.addStatement(one);
			String two = lookup.two();
			if (two.length() > 0)
			{
			    if (!java.seeded())
			        java.seedExpression(sinkName);
                java.wrapExpression("", two);
			}
			pendingMetaApplicationEnd = lookup.three();
			ignoreVariableUse = (pendingMetaApplicationEnd == null);
			return this;
		}
		else
			return super.startMetaApplication(name);
	}

	public Sink endMetaApplication()
	{
		if (ignoreVariableUse)
		{
			// Restart generation!
			ignoreVariableUse = false;
			return this;
		}
		else if (pendingMetaApplicationEnd != null)
		{
			java.wrapExpression("", pendingMetaApplicationEnd);
			return this;
		}
		else
			return super.endMetaApplication();
	}
}
