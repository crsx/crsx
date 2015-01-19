/* Copyright (c) 2007, 2010  IBM Corporation. */

package net.sf.crsx.util;

import java.io.IOException;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
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
import net.sf.crsx.Pattern;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;

/**
 * Extension of existing constructor with a name-and-variable-to-term property map.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: PropertiesConstructor.java,v 3.6 2013/12/05 03:28:30 krisrose Exp $
 */
public class PropertiesConstructor extends DelegateConstructor
{
	// Constants.

	/** Term class name. */
	final public static String TERM = Term.class.getCanonicalName();

	/** Variable class name. */
	final public static String VARIABLE = Variable.class.getCanonicalName();

	/** This class name. */
	final public static String PROPERTIES_CONSTRUCTOR = PropertiesConstructor.class.getCanonicalName();

	// Static.

	/** Static version of {@link Constructor#addFree(Set, ExtensibleSet, boolean, String, Set<Variabkle>)} for just visiting the properties. */
	public static void addFree(PropertiesHolder properties, Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		for (String property : properties.propertyNames())
		{
			Term value = properties.getProperty(property);
			if (value != null)
				value.addFree(set, bound, includemetaapps, base);
		}
		for (Variable v : properties.propertyVariables())
		{
			if (!bound.contains(v) && (base == null || base.contains(v)))
				set.add(v);
			Term value = properties.getProperty(v);
			if (value != null)
				value.addFree(set, bound, includemetaapps, base);
		}
	}

	/**
	 * Check that all match constraints implied by some pattern properties are satisfied by some other properties. 
	 * @param pattern properties to check
	 * @param that properties to check against
	 * @param match success so far
	 * @param bound variables bound in the context 
	 * @param contractionCount occurrence count for each meta-application (-1 for unknown; may be null if promiscuous true)
	 * @param promiscuous whether the matched term needs to be duplicatable
	 * @param once variables that are only permitted once in this subterm (not mutated)
	 * @param onceSeen variables in once that have already been seen (only mutated when once not empty)
	 */
	public static boolean checkProperties(PropertiesHolder pattern, PropertiesHolder that, Match match, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		// Check named properties.
		if (pattern != null)
		{
			if (that == null)
				return false; // fail because there are no properties to match

			// Check that every constraint is accounted for.
			for (String key : pattern.propertyNames())
			{
				if (key.startsWith("$"))
					continue;
				Pattern valuePattern = (Pattern) pattern.getProperty(key);
				assert valuePattern != null : "Negative named property " + key + "?";
				// The constraint is that there is a matching property for key.
				Term thatTerm = that.getProperty(key);
				if (thatTerm == null)
					return false; // match fails because there is no property for key
				if (!valuePattern.match(match, thatTerm, bound, contractionCount, promiscuous, once, onceSeen))
					return false; // match fails because the actual property does not match
				// This point reached when required property matches...
			}
			for (Variable key : pattern.propertyVariables())
			{
				Variable thatKey = match.getVariable(key);
				if (thatKey == null)
					return false; // fails because we have not previously established a mapping for variable
				Pattern valuePattern = (Pattern) pattern.getProperty(key);
				assert valuePattern != null : "Negative variable property " + key + "?";
				// The constraint is that there is a matching property for key.
				Term thatValue = that.getProperty(thatKey);
				if (thatValue == null)
					return false; // match fails because there is no property for key
				if (!valuePattern.match(match, thatValue, bound, contractionCount, promiscuous, once, onceSeen))
					return false; // match fails because the actual property does not match
				// This point reached when required property matches...
			}
		}
		// This point reached when all actual property constraints satisfied.
		return true;
	}

	/**
	 * Print {}-list prefix with simple properties (no pattern properties).
	 * @param properties to print
	 * @param writer to append to
	 * @param used variable names
	 * @param depth remaining sublevels to print (or -1 for all)
	 * @param full force printing to use full expanded syntax (so no abbreviated syntax)
	 * @param namedProps whether named properties are printed
	 * @param variableProps whether variable properties are printed
	 * @param omitProps specific variable properties to omit
	 * @param sortProps TODO
	 * @throws IOException
	 */
	public static void appendPropertiesTo(PropertiesHolder properties, Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		Iterator<String> namedPropertyIterator = properties.propertyNames().iterator();
		Iterator<Variable> variablePropertyIterator = properties.propertyVariables().iterator();
		if (omitProps == null)
			omitProps = LinkedExtensibleSet.EMPTY_VARIABLE_SET;

		// make sure we only do the following if there are non-hidden properties to print
		boolean visibleProperties = false;
		while (namedPropertyIterator.hasNext() && !visibleProperties)
		{
			String next = namedPropertyIterator.next();
			if (next != null && (next.length() < 2 || !next.substring(0, 2).equals("$$")))
				visibleProperties = true;
		}
		while (variablePropertyIterator.hasNext() && !visibleProperties)
		{
			Variable next = variablePropertyIterator.next();
			if (next != null && !omitProps.contains(next))
				visibleProperties = true;
		}
		namedPropertyIterator = properties.propertyNames().iterator();
		variablePropertyIterator = properties.propertyVariables().iterator();

		if (visibleProperties)
		{
			if (!namedProps && !variableProps)
			{
				writer.append("{...}");
				return;
			}
			String semi, sep = "";
			if (writer instanceof FormattingAppendable)
			{
				((FormattingAppendable) writer).open("{\0");
				semi = ";\n";
			}
			else
			{
				writer.append("{");
				semi = "; ";
			}
			if (namedProps)
			{
				if (sortProps)
				{
					ArrayList<String> list = new ArrayList<String>();

					while (namedPropertyIterator.hasNext())
						list.add(namedPropertyIterator.next());
					
					Collections.sort(list);
					namedPropertyIterator = list.iterator();
				}
				
				while (namedPropertyIterator.hasNext())
				{
					String key = namedPropertyIterator.next();
					if (key != null && key.length() > 2 && key.substring(0, 2).equals("$$"))
						continue;
					Term value = properties.getProperty(key);
					if (Util.isNull(value.constructor()))
					{
						writer.append(sep + (full ? Util.quoteJava(key) : Util.externalizeLiteral(key)));
					}
					else
					{
						writer.append(sep + (full ? Util.quoteJava(key) : Util.externalizeLiteral(key)) + " : ");
						value.appendTo(writer, used, depth - 1, full, namedProps, variableProps, null, sortProps);
					}
					sep = semi;
				}
			}
			if (variableProps)
			{
				if (sortProps)
				{
					ArrayList<Variable> list = new ArrayList<Variable>();

					while (variablePropertyIterator.hasNext())
						list.add(variablePropertyIterator.next());
					
					Collections.sort(list);
					variablePropertyIterator = list.iterator();
				}
				
				
				while (variablePropertyIterator.hasNext())
				{
					Variable key = variablePropertyIterator.next();
					if (!omitProps.contains(key))
					{
						Term value = properties.getProperty(key);
						if (Util.isNull(value.constructor()))
						{
							writer.append(sep + Util.safeVariableName(key, used, false, false));
						}
						else
						{
							writer.append(sep + Util.safeVariableName(key, used, false, false) + " : ");
							value.appendTo(writer, used, depth - 1, full, true, variableProps, null, sortProps);
						}
						sep = semi;
					}
				}
			}
			if (writer instanceof FormattingAppendable)
				((FormattingAppendable) writer).close("}\0");
			else
				writer.append("}");
		}
	}

	// State.

	/** The maker. */
	final protected Maker maker;

	/** Named properties. */
	public Map<String, Term> namedProperties;

	/** Variable properties. */
	protected Map<Variable, Term> variableProperties;

	/** Empty constant properties...immutable! */
	public final static Map<String, Term> EMPTY_PROPERTIES = new LinkedExtensibleMap<String, Term>();

	/** Empty variable properties...immutable! */
	public final static Map<Variable, Term> EMPTY_VAR_PROPERTIES = new LinkedExtensibleMap<Variable, Term>();

	/** Whether the properties are known to have been normalized... */
	public boolean propertiesNormalized;

	// Constructor...

	/**
	 * Create constructor from scratch.
	 * 
	 * @param maker to use
	 * @param base to extend with the properties
	 * @param properties named properties associated to the constructor (or null for none <em>and</em> disallowing {@link #setProperty(String, Term)})
	 * @param varProperties variable properties associated to the constructor (or null for none <em>and</em> disallowing {@link #setProperty(Variable, Term)})
	 */
	public PropertiesConstructor(Maker maker, Constructor base, Map<String, Term> properties, Map<Variable, Term> varProperties)
	{
		super(base);
		this.maker = maker;
		assert base != null;

		if (base instanceof PropertiesConstructor)
		{
			PropertiesConstructor old = (PropertiesConstructor) base;
			if (properties == null || properties.isEmpty())
				namedProperties = old.namedProperties;
			else
			{
				namedProperties = new HashMap<String, Term>(old.namedProperties);
				namedProperties.putAll(namedProperties);
			}
			if (varProperties == null || varProperties.isEmpty())
				variableProperties = old.variableProperties;
			else
			{
				variableProperties = new HashMap<Variable, Term>(old.variableProperties);
				variableProperties.putAll(old.variableProperties);
			}
		}
		else
		{
			namedProperties = new HashMap<String, Term>();
			if (properties != null)
				namedProperties.putAll(properties);
			variableProperties = new HashMap<Variable, Term>();
			if (varProperties != null)
				variableProperties.putAll(varProperties);
		}
	}

	/**
	 * Clone constructor.
	 * Creates new properties map but shares the property values ("shallow copy").
	 */
	public PropertiesConstructor(PropertiesConstructor old)
	{
		this(old.maker, old.constructor, old.namedProperties, old.variableProperties);
	}

	// Methods.

	/** The wrapped constructor. */
	public Constructor getWrappedConstructor()
	{
		return constructor;
	}

	/** The local named properties. */
	Map<String, Term> getLocalProperties()
	{
		return namedProperties;
	}

	/** The variable properties. */
	Map<Variable, Term> getLocalVariableProperties()
	{
		return variableProperties;
	}

	/** Set a bunch of properties. */
	public void setNamedProperties(Map<String, Term> ps)
	{
		if (ps != null && !ps.isEmpty())
		{
			if (namedProperties.isEmpty())
				namedProperties = ps;
			else
				namedProperties.putAll(ps);
			propertiesNormalized = false;
		}
	}

	/** Set a bunch of variable properties. */
	public void setVariableProperties(Map<Variable, Term> ps)
	{
		if (ps != null && !ps.isEmpty())
		{
			if (variableProperties.isEmpty())
				variableProperties = ps;
			else
				variableProperties.putAll(ps);
			propertiesNormalized = false;
		}
	}

	// Constructor...

	public boolean equals(Object that)
	{
		return that instanceof Constructor && symbol().equals(((Constructor) that).symbol());

		//		if (!super.equals(that))
		//			return false;
		//
		//		// Must be the same kind of constructor!
		//		if (!(that instanceof PropertiesConstructor))
		//			return false;
		//		final PropertiesConstructor thatConstructor = (PropertiesConstructor) that;
		//
		//		// Compare properties.
		//		final Map<String, Term> thatProperties = thatConstructor.namedProperties;
		//		if (namedProperties == thatProperties)
		//			return true;
		//		if (thatProperties == null)
		//			return false;
		//		return namedProperties.equals(thatProperties);

	}

	public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		// First check that the real constructor matches (ignoring properties).
		if (!constructor.match(match, that, bound, contractionCount, promiscuous, once, onceSeen))
			return false;

		return checkProperties(this, that, match, bound, contractionCount, promiscuous, once, onceSeen);
	}

	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		constructor.addFree(set, bound, includemetaapps, base);
		for (Term t : namedProperties.values())
			t.addFree(set, bound, includemetaapps, base);
		for (Map.Entry<Variable, Term> e : variableProperties.entrySet())
		{
			Variable v = e.getKey();
			if (!bound.contains(v) && (base == null || base.contains(v)))
				set.add(v);
			e.getValue().addFree(set, bound, includemetaapps, base);
		}
	}

	public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		Constructor nc = constructor.subsubstitute(maker, valuation, renamings, substitution, bound, possible);
		Map<String, Term> np = new HashMap<String, Term>();
		for (Map.Entry<String, Term> e : getLocalProperties().entrySet())
		{
			String key = e.getKey();
			Term value = Buffer.subsubstitute(e.getValue(), valuation, renamings, substitution, bound, possible);
			np.put(key, value);
		}
		Map<Variable, Term> vp = new HashMap<Variable, Term>();
		for (Map.Entry<Variable, Term> e : getLocalVariableProperties().entrySet())
		{
			Variable v = e.getKey();
			{
				Variable v2 = bound.get(v);
				if (v2 != null)
					v = v2;
			}
			if (!substitution.containsKey(v))
			{
				// Only include non-substituted variables.
				Term value = Buffer.subsubstitute(e.getValue(), valuation, renamings, substitution, bound, possible);
				vp.put(v, value);
			}
		}
		return new PropertiesConstructor(maker, nc, np, vp);
	}

	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		if (!constructor.checkFree(forbidden, once, onceSeen, promiscuous, bound))
			return false;
		for (Term t : namedProperties.values())
			if (!t.checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;

		for (Map.Entry<Variable, Term> e : variableProperties.entrySet())
		{
			Variable v = e.getKey();
			if (forbidden.contains(v) || onceSeen.contains(v))
				return false;
			if (once.contains(v))
				onceSeen.add(v);
			if (!e.getValue().checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;
		}
		return true;
	}

	public void normalize(CRS crs) throws CRSException
	{
		constructor.normalize(crs);
		if (!propertiesNormalized)
		{
			for (Map.Entry<String, Term> e : namedProperties.entrySet())
				e.setValue(crs.normalize(e.getValue()));
			for (Map.Entry<Variable, Term> e : variableProperties.entrySet())
				e.setValue(crs.normalize(e.getValue()));
			propertiesNormalized = true;
		}
	}

	// @see net.sf.crsx.Constructor#copy(net.sf.crsx.util.ExtensibleMap)
	@Override
	public Constructor copy(ExtensibleMap<Variable, Variable> renames)
	{
		renames = (renames != null ? renames : LinkedExtensibleMap.EMPTY_RENAMING);
		Constructor c = super.copy(renames);
		if (c == constructor && renames.isEmpty())
		{
			// No need to duplicate...
			return this;
		}
		else
		{
			Map<String, Term> np = Util.copyNamedProperties(namedProperties, renames, false);
			Map<Variable, Term> vp = Util.copyVariableProperties(variableProperties, renames, false);
			return new PropertiesConstructor(maker, c, np, vp);
		}
	}

	//	public Constructor unify(Constructor other, ExtensibleMap<Variable, Variable> renamings)
	//	{
	//		if (properties == null || properties.size() == 0)
	//		{
	//			// When no properties just redirect to delegate.
	//			return super.unify(other, renamings);
	//		}
	//		else
	//		{
	//			Constructor c;
	//			Map<String, Term> ps = new HashMap<String, Term>();
	//			if (other instanceof PropertiesConstructor)
	//			{
	//				PropertiesConstructor otherPC = (PropertiesConstructor) other;
	//				// Create new constructor with the combined properties (or fail)!
	//				c = super.unify(otherPC.constructor, renamings);
	//				// First go through properties in this constructor.
	//				for (Map.Entry<String, Term> e : properties.entrySet())
	//				{
	//					String k = e.getKey();
	//					Term v1 = e.getValue();
	//					Term v2 = otherPC.properties.get(k); 
	//					if (v2 == null)
	//					{
	//						// Property is unique to this constructor.
	//						ps.put(k, v1.copy(renamings));
	//					}
	//					else
	//					{
	//						// Shared property: unify the values!
	//						ps.put(k, v1.unify(v2, renamings));
	//					}
	//				}
	//				// Second add properties only on other constructor.
	//				for (Map.Entry<String, Term> e : otherPC.properties.entrySet())
	//				{
	//					String k = e.getKey();
	//					if (!properties.containsKey(k))
	//						ps.put(k, e.getValue().copy(renamings));
	//				}
	//				return new PropertiesConstructor(maker, c, ps);
	//			}
	//			else
	//			{
	//				// When other has no properties then include the existing properties on the unified delegate...
	//				c = super.unify(other, renamings);
	//				for (Map.Entry<String, Term> e : properties.entrySet())
	//				{
	//					String k = e.getKey();
	//					Term v = e.getValue();
	//					ps.put(k, v.copy(renamings));
	//				}
	//			}
	//			return new PropertiesConstructor(maker, c, ps);
	//		}
	//	}

	@Override
	public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
	{
		//TODO
		throw new UnsupportedOperationException("Not implemented yet.");
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		visitor.visitProperties(true);

		//        if (namedProperties != null)
		//            for (Term t : namedProperties.values())
		//                t.visit(visitor, bound);

		for (String k : namedProperties.keySet())
		{
			Term t = namedProperties.get(k);
			visitor.visitNamedProperty(k, true);
			if (t != null)
				t.visit(visitor, bound);
			visitor.visitNamedProperty(k, false);
		}

		if (variableProperties != null)
		{
			for (final Variable property : variableProperties.keySet().toArray(new Variable[variableProperties.size()]))
			{
				final Term value = variableProperties.get(property);
				Visitor.VariableUpdater updater = new Visitor.VariableUpdater()
					{
						public void setVariable(Variable variable)
						{
							if (!property.equals(variable))
							{
								if (variableProperties.containsKey(variable))
									throw new RuntimeException("Error in variable property update: collapse of variable keys");
								variableProperties.remove(property);
								variableProperties.put(variable, value);
							}
						}
					};
				visitor.visitVariableProperty(property, true, value != null);

				if (bound.contains(property))
					visitor.visitBound(property, updater);
				else
					visitor.visitFree(property, updater);

				value.visit(visitor, bound);

				visitor.visitVariableProperty(property, false, value != null);
			}
		}

		visitor.visitProperties(false);
	}

	public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
		Constructor c = super.contract(valuation, renamings);
		if (namedProperties.isEmpty() && variableProperties.isEmpty())
		{
			// When no properties just eliminate the property wrapper!
			return c;
		}
		else
		{
			// Contract the properties!
			Map<String, Term> np = new HashMap<String, Term>();
			for (Map.Entry<String, Term> e : getLocalProperties().entrySet())
			{
				String key = e.getKey();
				Term value = e.getValue();
				Term contraction = Buffer.contraction((Contractum) value, valuation, renamings);
				np.put(key, contraction);
			}
			Map<Variable, Term> vp = new HashMap<Variable, Term>();
			for (Map.Entry<Variable, Term> e : getLocalVariableProperties().entrySet())
			{
				Variable patternKey = e.getKey();
				Variable contractedKey = renamings.get(patternKey);
				if (contractedKey == null)
				{
					contractedKey = valuation.getVariable(patternKey);
					if (contractedKey == null)
						contractedKey = patternKey; // unmatched variable not changed
				}
				Term value = e.getValue();
				Term contraction = Buffer.contraction((Contractum) value, valuation, renamings);
				vp.put(contractedKey, contraction);
			}
			try
			{
				return Util.wrapWithProperties(maker, c, np, vp);
			}
			catch (CRSException e)
			{
				throw new RuntimeException("Setting property failed during contraction", e);
			}
		}
	}

	public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
			throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		if (writer instanceof FormattingAppendable)
			((FormattingAppendable) writer).open("");
		if (namedProps || variableProps)
			appendPropertiesTo(this, writer, used, depth - 1, full, namedProps, variableProps, omitProps, sortProps);
		constructor.appendTo(writer, used, depth, full, namedProps, variableProps, omitProps, sortProps); //TODO: will omit nested properties...does this happen?
		if (writer instanceof FormattingAppendable)
			((FormattingAppendable) writer).close("");
	}

	final public SortedSet<Path> paths(Path base)
	{
		SortedSet<Path> paths = super.paths(base);
		for (String name : propertyNames())
			paths.add(base.extend(name));
		for (Variable variable : propertyVariables())
			paths.add(base.extend(variable));
		return paths;
	}

	public void javaInvokeStart(SourceBuilder java, String sinkName, Map<Variable, String> variable2java)
	{
		if ((namedProperties != null && namedProperties.size() > 0)
				|| (variableProperties != null && variableProperties.size() > 0))
		{
			// Create prefix to inject properties!
			java.openBlock("{");
			java.addStatement("java.util.Map<String, " + TERM + "> properties = new java.util.HashMap<String, " + TERM + ">();");
			if (namedProperties != null && namedProperties.size() > 0)
			{
				for (Map.Entry<String, Term> entry : namedProperties.entrySet())
				{
					String key = entry.getKey();
					Term term = entry.getValue();
					if (term != null)
					{
						PlainJavaSink.generateJavaToBuffer(
								java, term.maker(), term, sinkName, "properties.put(" + Util.quoteJava(key) + ", ", ".term(true));");
					}
				}
			}
			java.addStatement("java.util.Map<"
					+ VARIABLE + ", " + TERM + "> varProperties = new java.util.HashMap<" + VARIABLE + ", " + TERM + ">();");
			if (variableProperties != null && variableProperties.size() > 0)
			{
				for (Map.Entry<Variable, Term> entry : variableProperties.entrySet())
				{
					Variable key = entry.getKey();
					Term term = entry.getValue();
					if (term != null)
					{
						PlainJavaSink.generateJavaToBuffer(
								java, term.maker(), term, sinkName, "properties.put(" + variable2java.get(key) + ", ",
								".term(true));");
					}
				}
			}
			java.addStatement(java.wrapExpression(sinkName + " =", "").harvest()).closeBlock("}").wrapExpression("", "");
		}

		// Generate base constructor's start event.
		super.javaInvokeStart(java, sinkName, variable2java);
	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		if (namedProperties.isEmpty())
			return super.propertyNames();

		Iterator<String> wrapped = super.propertyNames().iterator();
		if (wrapped.hasNext())
		{
			Set<String> combined = new HashSet<String>(namedProperties.keySet());
			do
			{
				combined.add(wrapped.next());
			}
			while (wrapped.hasNext());
			return combined;
		}
		else
		{
			return namedProperties.keySet();
		}
	}

	public Iterable<Variable> propertyVariables()
	{
		if (variableProperties.isEmpty())
			return super.propertyVariables();

		Iterator<Variable> wrapped = super.propertyVariables().iterator();
		if (wrapped.hasNext())
		{
			Set<Variable> combined = new HashSet<Variable>(variableProperties.keySet());
			do
			{
				combined.add(wrapped.next());
			}
			while (wrapped.hasNext());
			return combined;
		}
		else
		{
			return variableProperties.keySet();
		}
	}

	public Term getProperty(String name)
	{
		Term value = namedProperties.get(name);
		return (value != null ? value : super.getProperty(name));
	}

	public Term getProperty(Variable variable)
	{
		Term value = variableProperties.get(variable);
		return (value != null ? value : super.getProperty(variable));
	}

	public boolean canSetProperty(String name)
	{
		return true;
	}

	public void setProperty(String key, Term value) throws CRSException
	{
		if (value == null)
		{
			if (super.canSetProperty(key))
				super.setProperty(key, value);
			namedProperties.remove(key);
		}
		else if (super.canSetProperty(key))
			super.setProperty(key, value);
		else
		{
			namedProperties.put(key, value);
			propertiesNormalized = false;
		}
	}

	public boolean canSetProperty(Variable variable)
	{
		return true;
	}

	public void setProperty(Variable key, Term value) throws CRSException
	{
		if (value == null)
		{
			if (super.canSetProperty(key))
				super.setProperty(key, value);
			variableProperties.remove(key);
		}
		else if (super.canSetProperty(key))
			super.setProperty(key, value);
		else
		{
			variableProperties.put(key, value);
			propertiesNormalized = false;
		}
	}

	@Override
	public void removeProperty(Variable variable) throws CRSException
	{
		variableProperties.remove(variable);
	}

	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		if (properties == null)
			return;
		if (properties instanceof PropertiesConstructor)
		{
			PropertiesConstructor pc = (PropertiesConstructor) properties;
			setNamedProperties(pc.namedProperties);
			setVariableProperties(pc.variableProperties);
		}
		else
		{
			for (String name : properties.propertyNames())
				setProperty(name, properties.getProperty(name));
			for (Variable variable : properties.propertyVariables())
				setProperty(variable, properties.getProperty(variable));
		}
	}

	public boolean isMeta()
	{
		return false;
	}

	// Object...

	public String toString()
	{
		StringWriter w = new StringWriter();
		try
		{
			appendTo(
					w, new HashMap<Variable, String>(), Integer.MAX_VALUE, false, true, true,
					LinkedExtensibleSet.EMPTY_VARIABLE_SET, false);
		}
		catch (IOException e)
		{
			// Really.
		}
		return w.toString();
	}
}
