/* Copyright (c) 2007, 2008 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Maker;
import net.sf.crsx.Match;
import net.sf.crsx.Path;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.PlainJavaSink;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Pseudo-constructor with property constraints for use in patterns and contractions.
 * Not useful except passing property constraints to a {@link Sink}.
 * Do not use in proper terms!
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: PropertiesWrapperConstructor.java,v 3.5 2013/12/05 03:28:28 krisrose Exp $
 */
public class PropertiesWrapperConstructor extends GenericProperties implements Constructor
{
	// Constants.

	/** Term class name. */
	final public static String TERM = Term.class.getCanonicalName();
	/** Variable class name.*/
	final public static String VARIABLE = Variable.class.getCanonicalName();

	// Static utilities.

	/**
	 * Helper function to "start" properties annotation constraint wrapper.
	 * @param sink that should receive the extended start action with an annotated constructor
	 * @param reference to use
	 * @param namedPropertyConstraints to use (not cloned)
	 * @param variablePropertyConstraints to use (not cloned)
	 * @param metaPropertyConstraints to use (not cloned)
	 * @return sink to where the normal start action is going to be sent (as well as the required matching end)
	 */
	public static Sink start(Sink sink, String reference, Map<String, Term> namedPropertyConstraints, Map<Variable, Term> variablePropertyConstraints, Map<String, Term> metaPropertyConstraints)
	{
		return sink.start(new PropertiesWrapperConstructor(reference, namedPropertyConstraints, variablePropertyConstraints,
				metaPropertyConstraints));
	}

	/**
	 * Helper function to "start" properties annotation constraint wrapper with copy of properties from existing term.
	 * @param sink that should receive the extended start action with an annotated constructor
	 * @param term from there the properties should be taken
	 * @return sink to where the normal start action is going to be sent (as well as the required matching end)
	 */
	public static Sink start(Sink sink, Term term)
	{
		String propertiesRef = null;
		Map<String, Term> namedPropertyConstraints = new HashMap<String, Term>();
		Map<Variable, Term> variablePropertyConstraints = new HashMap<Variable, Term>();
		Map<String, Term> metaPropertyConstraints = new HashMap<String, Term>();
		if (term instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) term;
			propertiesRef = pcw.propertiesRef;
			namedPropertyConstraints = pcw.namedPropertyConstraints;
			variablePropertyConstraints = pcw.variablePropertyConstraints;
			metaPropertyConstraints = pcw.metaPropertyConstraints;

		}
		else if (term instanceof PropertiesHolder)
		{
			PropertiesHolder properties = (PropertiesHolder) term;
			for (String name : properties.propertyNames())
				namedPropertyConstraints.put(name, properties.getProperty(name));
			for (Variable variable : properties.propertyVariables())
				variablePropertyConstraints.put(variable, properties.getProperty(variable));
		}
		//		Constructor c = term.constructor();
		//		if (c != null)
		//		{
		//			for (String name : c.propertyNames())
		//				namedPropertyConstraints.put(name, c.getProperty(name));
		//			for (Variable variable : c.propertyVariables())
		//				variablePropertyConstraints.put(variable, c.getProperty(variable));
		//		}
		sink = sink.start(new PropertiesWrapperConstructor(propertiesRef, namedPropertyConstraints, variablePropertyConstraints,
				metaPropertyConstraints));
		return sink;
	}

	// Constructor.

	/**
	 * Create property constraint constructor.
	 * @param propertiesRef permitting reference to properties
	 * @param namedPropertyConstraints associated to the constructor
	 * @param variablePropertyConstraints associated to the constructor
	 * @param metaPropertyConstraints associated to the constructor
	 */
	PropertiesWrapperConstructor(String propertiesRef, Map<String, Term> namedPropertyConstraints,
			Map<Variable, Term> variablePropertyConstraints, Map<String, Term> metaPropertyConstraints)
	{
		super(propertiesRef, namedPropertyConstraints, variablePropertyConstraints, metaPropertyConstraints);
	}

	// Constructor [sic]...

	public String symbol()
	{
		return "$Constraints$Dummy";
	}

	public String literalSort()
	{
		return null;
	}

	public Object object()
	{
		return symbol();
	}

	public void normalize(CRS crs) throws CRSException
	{
		if (!propertiesNormalized)
		{
			for (Map.Entry<String, Term> e : namedPropertyConstraints.entrySet())
				e.setValue(crs.normalize(e.getValue()));
			for (Map.Entry<Variable, Term> e : variablePropertyConstraints.entrySet())
				e.setValue(crs.normalize(e.getValue()));
			for (Map.Entry<String, Term> e : metaPropertyConstraints.entrySet())
				e.setValue(crs.normalize(e.getValue()));
			propertiesNormalized = true;
		}
	}

	public boolean match(Match match, Constructor other, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}

	public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		visitor.visitProperties(true);

		for (Term t : namedPropertyConstraints.values())
			t.visit(visitor, bound);

		for (final Variable property : variablePropertyConstraints.keySet().toArray(
				new Variable[variablePropertyConstraints.size()]))
		{
			final Term value = variablePropertyConstraints.get(property);
			Visitor.VariableUpdater updater = new Visitor.VariableUpdater()
				{
					public void setVariable(Variable variable)
					{
						if (!property.equals(variable))
						{
							if (variablePropertyConstraints.containsKey(variable))
								throw new RuntimeException("Error in variable property update: collapse of variable keys");
							variablePropertyConstraints.remove(property);
							variablePropertyConstraints.put(variable, value);
						}
					}
				};
			if (bound.contains(property))
				visitor.visitBound(property, updater);
			else
				visitor.visitFree(property, updater);
			value.visit(visitor, bound);
		}

		for (Term t : metaPropertyConstraints.values())
		{
			if (t != null)
				t.visit(visitor, bound);
		}

		propertiesNormalized = false;

		visitor.visitProperties(false);
	}

	public Constructor oldunify(ExtensibleMap<Variable, Variable> thisBound, Map<Variable, Variable> thisBaseVariable, Map<String, String> thisBaseMeta, Constructor that, ExtensibleMap<Variable, Variable> thatBound, Map<Variable, Variable> thatBaseVariable, Map<String, String> thatBaseMeta, Match unifyMatch, ExtensibleMap<Variable, Variable> unifyBound, Map<String, List<Pair<ExtensibleMap<Variable, Variable>, Term>>> unifiedMatched)
	{
		// TODO: Generate unified properties...?
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}

	public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
	{
		// TODO
		throw new UnsupportedOperationException("Operation not implemented yet.");
	}

	public Constructor copy(ExtensibleMap<Variable, Variable> renamings)
	{
		throw new RuntimeException("PropertiesWrapperConstructor.copy not permitted!");
	}

	public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}

	public Constructor staticContract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		throw new UnsupportedOperationException("Misuse of PropertiesWrapperConstructor?");
	}


	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		PropertiesConstraintsWrapper.appendTo(
				writer, used, depth, propertiesRef, namedPropertyConstraints, variablePropertyConstraints, metaPropertyConstraints,
				full, namedProps, variableProps, omitProps, sortProps);
	}

	final public SortedSet<Path> paths(Path base)
	{
		// TODO
		throw new UnsupportedOperationException("Operation not implemented yet.");
	}

	public void javaInvokeStart(SourceBuilder code, String sinkName, Map<Variable, String> variable2java)
	{
		// Create prefix to inject properties in what follows!
		code.openBlock("{");
		code.addStatement("java.util.Map<String, " + TERM + "> namedProperties = new java.util.HashMap<String, " + TERM + ">();");
		if (!namedPropertyConstraints.isEmpty())
		{
			for (Map.Entry<String, Term> entry : namedPropertyConstraints.entrySet())
			{
				String key = entry.getKey();
				Term term = entry.getValue();
				if (term == null)
				{
					code.addStatement("properties.put(" + Util.quoteJava(key) + ", null);");
				}
				else
				{
					PlainJavaSink.generateJavaToBuffer(code, term.maker(), term, sinkName, "properties.put("
							+ Util.quoteJava(key) + ", ", ".term(true));");
				}
			}
		}
		code.addStatement("java.util.Map<"
				+ VARIABLE + ", " + TERM + "> variableProperties = new java.util.HashMap<" + VARIABLE + ", " + TERM + ">();");
		if (!variablePropertyConstraints.isEmpty())
		{
			for (Map.Entry<Variable, Term> entry : variablePropertyConstraints.entrySet())
			{
				Variable key = entry.getKey();
				Term term = entry.getValue();
				if (term == null)
				{
					code.addStatement("properties.put(" + variable2java.get(key) + ", null);");
				}
				else
				{
					PlainJavaSink.generateJavaToBuffer(
							code, term.maker(), term, sinkName, "properties.put(" + variable2java.get(key) + ", ", ".term(true));");
				}
			}
		}
		code.addStatement(code.wrapExpression(sinkName + " =", "").harvest()).closeBlock("}").wrapExpression("", "");
	}

	public boolean equals(Object that)
	{
		throw new UnsupportedOperationException(
				"Misuse of PropertiesWrapperConstructor (only for passing into GenericBuffer.sink())?");
	}

	public int hashCode()
	{
		throw new UnsupportedOperationException(
				"Misuse of PropertiesWrapperConstructor (only for passing into GenericBuffer.sink())?");
	}

	public Constructor baseConstructor()
	{
		throw new UnsupportedOperationException(
				"Misuse of PropertiesWrapperConstructor (only for passing into GenericBuffer.sink())?");
	}

	public String toString()
	{
		StringBuilder b = new StringBuilder();
		try
		{
			appendTo(
					b, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, false, false,
					LinkedExtensibleSet.EMPTY_VARIABLE_SET, false);
		}
		catch (IOException e)
		{}
		return b.toString();
	}
}
