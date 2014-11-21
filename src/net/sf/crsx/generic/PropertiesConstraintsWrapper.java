/* Copyright (c) 2007, 2010 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Match;
import net.sf.crsx.MetaAnalyzer;
import net.sf.crsx.Path;
import net.sf.crsx.Pattern;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.PropertiesConstructor;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Extension of existing term with annotation constraints for use in patterns and contractions.
 * Allows
 * <ul>
 * <li>exclusions of certain properties (set to null) on matching,
 * <li>matching of property value on matching,
 * <li>setting new property values on contraction, and
 * <li>copying of otherwise unspecified properties on contraction.
 * </ul>
 * As a term it merely delegates all operations to the term it wraps.
 * <p>
 * <b>TODO:</b> This is a rather heavy-weight implementation intended for rule patterns,
 * not actual runtime use...
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: PropertiesConstraintsWrapper.java,v 3.14 2014/01/06 03:11:09 krisrose Exp $
 */
public class PropertiesConstraintsWrapper extends DelegateGenericTerm implements Pattern, Contractum, PropertiesHolder
{
	// Constants.

	/** Base term. */
	public GenericTerm term;

	/** The reference to the properties. */
	protected String propertiesRef;

	/** Named properties. */
	protected Map<String, Term> namedPropertyConstraints;

	/** Variable properties. */
	protected Map<Variable, Term> variablePropertyConstraints;

	/** Meta-variable properties. */
	protected Map<String, Term> metaPropertyConstraints;
	
	/** Meta-variable properties use count. */
	protected Map<String, Integer> metaPropertyUses;
	
	// Constructor...

	/**
	 * Create annotation match/contract prefix around term.
	 * @param term to wrap
	 * @param propertiesRef permitting reference to properties (not copied)
	 * @param namedPropertiesConstraints associated to the constructor (not copied)
	 * @param variablePropertiesConstraints
	 * @param metaPropertyConstraints associated to the constructor (not copied)
	 */
	public PropertiesConstraintsWrapper(GenericTerm term, String propertiesRef, Map<String, Term> namedPropertiesConstraints,
			Map<Variable, Term> variablePropertiesConstraints, Map<String,Term> metaPropertyConstraints)
	{
		super(term.maker());
		this.term = term;
		if (term instanceof PropertiesConstraintsWrapper)
	        if (Util.getInteger(factory, GenericFactory.VERBOSE_OPTION, 0) >= 0)
            	factory.message(("WARNING: nested properties wrapper ("+term+")"));
		this.propertiesRef = propertiesRef;
//		if (propertiesRef != null && Util.CONSTRUCTOR_PATTERN.matcher(propertiesRef).matches())
//			factory.warning("bad karma: impossible reference meta-variable!");
		this.namedPropertyConstraints = (namedPropertiesConstraints == null ? new HashMap<String, Term>() : namedPropertiesConstraints);
		this.variablePropertyConstraints = (variablePropertiesConstraints == null ? new HashMap<Variable, Term>() : variablePropertiesConstraints);
		this.metaPropertyConstraints = (metaPropertyConstraints == null ? new HashMap<String, Term>() : metaPropertyConstraints);		
	}

	/**
	 * Create property constraint...
	 */
	PropertiesConstraintsWrapper(PropertiesWrapperConstructor c, GenericTerm t)
	{
		this(t, c.propertiesRef, c.namedPropertyConstraints, c.variablePropertyConstraints, c.metaPropertyConstraints);
	}

	/**
	 * Create duplicate of existing term with property constraint wrapper.
	 * @param pcw property constraints wrapper
	 * @param reuseTerm whether to reuse the term component or also copy that
	 */
	public PropertiesConstraintsWrapper(PropertiesConstraintsWrapper pcw, boolean reuseTerm)
	{
		super(pcw.maker());
		propertiesRef = pcw.propertiesRef;
		namedPropertyConstraints = new HashMap<String, Term>(pcw.namedPropertyConstraints);
		variablePropertyConstraints = new HashMap<Variable, Term>(pcw.variablePropertyConstraints);
		metaPropertyConstraints = new HashMap<String,Term>(pcw.metaPropertyConstraints);
		this.term = (reuseTerm ? pcw.term : pcw.term.copy(false, null));
	}

	// Methods.

	/** Set a bunch of property constraints. */
	public void setPropertyConstraints(Map<String, Term> ps)
	{
		if (ps != null) namedPropertyConstraints.putAll(ps);
	}

	/** Set a bunch of variable property constraints. */
	public void setVariablePropertyConstraints(Map<Variable, Term> ps)
	{
		if (ps != null) variablePropertyConstraints.putAll(ps);
	}
	
	public void setMetaPropertyConstraints(Map<String, Term> ps)
	{
		if (ps != null) metaPropertyConstraints.putAll(ps);
	}

	/** The constant properties. */
	public Map<String, Term> getLocalProperties()
	{
		return namedPropertyConstraints;
	}

	/** The variable properties. */
	public Map<Variable, Term> getLocalVariableProperties()
	{
		return variablePropertyConstraints;
	}

	/** The meta properties. */
	public Map<String, Term> getLocalMetaProperties()
	{
		return metaPropertyConstraints;
	}

	/** Whether the wrapper contains any unknown keys (hidden in meta-variables)... */
	public boolean hasUnknownKeys()
	{
		return propertiesRef != null || !metaPropertyConstraints.isEmpty();
	}

	/** The ref. */
	public String getRef()
	{
		return propertiesRef;
	}

	/** Set properties reference. */
	public void setPropertiesRef(String ref)
	{
		propertiesRef = ref;
	}
	
	public Term getProperty(String name)
	{
		//return namedPropertyConstraints.get(name);
		if (namedPropertyConstraints.containsKey(name))
			return namedPropertyConstraints.get(name);
		PropertiesHolder contained = Util.propertiesHolder(term);
		if (contained != null)
			return contained.getProperty(name);
		return null;
	}

	public Term getProperty(Variable variable)
	{
		//return variablePropertyConstraints.get(variable);
		if (variablePropertyConstraints.containsKey(variable))
			return variablePropertyConstraints.get(variable);
		PropertiesHolder contained = Util.propertiesHolder(term);
		if (contained != null)
			return contained.getProperty(variable);
		return null;
	}

	/** Get meta property. */
	public Term getMetaProperty(String key)
	{
		return metaPropertyConstraints.get(Util.externalizeMetaVariable(key));
	}
	
	public boolean hasNotProperty(String key)
	{
		return namedPropertyConstraints.containsKey(key) && namedPropertyConstraints.get(key) == null;
	}

	public boolean canSetProperty(String name)
	{
		return name != null;
	}

	public boolean canSetProperty(Variable variable)
	{
		return variable != null;
	}

	public void setProperty(String name, Term value) throws CRSException
	{
		term.removeProperty(name);
		namedPropertyConstraints.put(name, value);
		/*		
		if (value != null)
			namedPropertyConstraints.put(name, value);
		else
		{
			namedPropertyConstraints.remove(name);
			PropertiesHolder contained = Util.propertiesHolder(term);
			if (contained != null && contained.canSetProperty(name))
				contained.setProperty(name, null);
			else
				namedPropertyConstraints.put(name, null);
		}
		*/
	}

	public void setProperty(Variable variable, Term value) throws CRSException
	{
		term.removeProperty(variable);
		variablePropertyConstraints.put(variable, value);
		/*
		if (value != null)
			variablePropertyConstraints.put(variable, value);
		else
		{
			variablePropertyConstraints.remove(variable);
			PropertiesHolder contained = Util.propertiesHolder(term);
			if (contained != null && contained.canSetProperty(variable))
				contained.setProperty(variable, null);
			else
				variablePropertyConstraints.put(variable, null);
		}
		*/
	}

	/** Add a meta property. */
	void setMetaProperty(String key, Term value)
	{
		metaPropertyConstraints.put(key, value);
	}

	/** Set an explicit negative named property. */
	void setNotProperty(String key)
	{
		term.removeProperty(key);
		namedPropertyConstraints.put(key, null);
	}

	/** Set an explicit negative variable property. */
	void setNotProperty(Variable key)
	{
		term.removeProperty(key);
		variablePropertyConstraints.put(key, null);
	}

	/** Add a negative meta property. */
	void setNotMetaProperty(String key)
	{
		metaPropertyConstraints.put(key, null);
	}
	
	// DelegateGenericTerm...
	
	public final GenericTerm term()
	{
		return term;
	}
	
	// GenericTerm...

	@Override
	public GenericTerm stripProperties()
	{
		return term.stripProperties();
	}

	@Override
	public void removeProperty(String key)
	{
		namedPropertyConstraints.remove(key);
		term.removeProperty(key);
	}

	@Override
	public void removeProperty(Variable key)
	{
		variablePropertyConstraints.remove(key);
		term.removeProperty(key);
	}

	@Override
	public void removeMetaProperty(String key)
	{
		metaPropertyConstraints.remove(key);
		term.removeMetaProperty(key);
	}

	// PropertiesHolder...

	public Iterable<String> propertyNames()
	{
		//return new HashSet<String>(namedPropertyConstraints.keySet());
		PropertiesHolder contained = Util.propertiesHolder(term);
		if (namedPropertyConstraints.isEmpty() && contained != null)
			return contained.propertyNames();
		Set<String> set = new HashSet<String>(namedPropertyConstraints.keySet());
		if (contained != null)
			for (String name : contained.propertyNames())
				set.add(name);
		return set;
	}

	public Iterable<Variable> propertyVariables()
	{
		//return new HashSet<Variable>(variablePropertyConstraints.keySet());
		PropertiesHolder contained = Util.propertiesHolder(term);
		if (variablePropertyConstraints.isEmpty() && contained != null)
			return contained.propertyVariables();
		Set<Variable> set = new HashSet<Variable>(variablePropertyConstraints.keySet());
		if (contained != null)
			for (Variable variable : contained.propertyVariables())
				set.add(variable);
		return set;
	}
	
	/** Return all meta-variable keys occurring in this property set */
	public Iterable<String> propertyMetaVariables()
	{
		return new HashSet<String>(metaPropertyConstraints.keySet());
	}

	/** Set properties from existing set. */
	public void setProperties(PropertiesHolder properties) throws CRSException
	{
		if (properties == null)
			return;
		if (properties instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) properties;
			if (pcw.propertiesRef != null)
			{
				if (propertiesRef != null)
					throw new CRSException("Double property reference wrapper on "+Util.symbol(this));
				propertiesRef = pcw.propertiesRef;
			}
			namedPropertyConstraints.putAll(pcw.namedPropertyConstraints);
			variablePropertyConstraints.putAll(pcw.variablePropertyConstraints);
			metaPropertyConstraints.putAll(pcw.metaPropertyConstraints);
		}
		else
		{
			for (String name : properties.propertyNames())
				setProperty(name, properties.getProperty(name));
			for (Variable variable : properties.propertyVariables())
				setProperty(variable, properties.getProperty(variable));
		}
	}

	/** The properties ref (otherwise null). */
	public String propertiesRef()
	{
		return propertiesRef;
	}
	
	public boolean isMeta()
	{
		if (propertiesRef != null)
			return true;
		if (!metaPropertyConstraints.isEmpty())
			return true;
		if (namedPropertyConstraints.containsValue(null))
			return true;
		if (variablePropertyConstraints.containsValue(null))
			return true;
		return false;
	}
	
	// Copyable...

	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		Map<String, Term> namedPropertyConstraints2;
		Map<Variable, Term> variablePropertyConstraints2;
		Map<String, Term> metaPropertyConstraints2;
		renames = (renames != null ? renames : LinkedExtensibleMap.EMPTY_RENAMING);
		if (renames.isEmpty())
		{
			namedPropertyConstraints2 = namedPropertyConstraints;
			variablePropertyConstraints2 = variablePropertyConstraints;
			metaPropertyConstraints2 = metaPropertyConstraints;
		}
		else
		{
			namedPropertyConstraints2 = Util.copyNamedProperties(namedPropertyConstraints, renames, discard);
			variablePropertyConstraints2 = Util.copyVariableProperties(variablePropertyConstraints, renames, discard);
			metaPropertyConstraints2 = copyMetaProperties(metaPropertyConstraints, renames, discard);
		}
		sink = PropertiesWrapperConstructor.start(sink, propertiesRef, namedPropertyConstraints2, variablePropertyConstraints2, metaPropertyConstraints2);
		sink = term.copy(sink, discard, renames);
		sink = sink.end();
		return sink;
	}

	// Stub...

	static Map<String, Term> copyMetaProperties(Map<String, Term> metaPropertyConstraints, ExtensibleMap<Variable, Variable> renames, boolean discard)
	{
		if (discard && renames.isEmpty())
			return metaPropertyConstraints; // copy by reference since the reuse cannot be observed.
		else
		{
			// Create new map with copies of all the properties.
			Map<String,Term> np = new HashMap<String, Term>();
			for (Entry<String, Term> p : metaPropertyConstraints.entrySet())
			{
				String k = p.getKey();
				Term v = p.getValue();
				np.put(k, v == null ? null : v.copy(discard, renames));
			}
			return np;
		}
	}

	public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		if (renames == null)
			renames = LinkedExtensibleMap.EMPTY_RENAMING;
		if (discard && renames.isEmpty())
			return this;

		GenericTerm t = term.copy(discard, renames);
		Map<String, Term> np = Util.copyNamedProperties(namedPropertyConstraints, renames, discard);
		Map<Variable, Term> vp = Util.copyVariableProperties(variablePropertyConstraints, renames, discard);
		Map<String,Term> mp = copyMetaProperties(metaPropertyConstraints, renames, discard);
		return new PropertiesConstraintsWrapper(t, propertiesRef, np, vp, mp);
	}

	// Term...

	// @see net.sf.crsx.Term#addFree(java.util.Set, net.sf.crsx.util.ExtensibleSet)
	public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		for (Term t : namedPropertyConstraints.values())
			if (t != null) t.addFree(set, bound, includemetaapps, base);
		for (Variable v : variablePropertyConstraints.keySet())
			if (!bound.contains(v) && (base == null || base.contains(v)))
				set.add(v); // TODO: check sort membership from properties sort!
		for (Term t : variablePropertyConstraints.values())
			if (t != null) t.addFree(set, bound, includemetaapps, base);
		for (Term t : metaPropertyConstraints.values())
			if (t != null) t.addFree(set, bound, includemetaapps, base);
		term.addFree(set, bound, includemetaapps, base);
	}
	
	public void addMetaCounts(Map<String, Integer> counts)
	{
		if (propertiesRef != null)
			counts.put(propertiesRef, counts.containsKey(propertiesRef) ? counts.get(propertiesRef)+1 : 1);
		for (Term t : namedPropertyConstraints.values())
			if (t != null) t.addMetaCounts(counts);
		for (Term t : variablePropertyConstraints.values())
			if (t != null) t.addMetaCounts(counts);
		for (String m : metaPropertyConstraints.keySet())
			counts.put(m, counts.containsKey(m) ? counts.get(m)+1 : 1);
		for (Term t : metaPropertyConstraints.values())
			if (t != null) t.addMetaCounts(counts);
		term.addMetaCounts(counts);
	}
	
	final public void analyzeMetaUseContractum(Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
	{
		// The order must be the reverse of the reify order.
		term.analyzeMetaUseContractum(counts, subAnalyzers);
		
		for (Term t : metaPropertyConstraints.values())
			if (t != null) t.analyzeMetaUseContractum(counts, subAnalyzers); 
		
		metaPropertyUses = new HashMap<String, Integer>(4);
		
		if (metaPropertyConstraints != null)
		{
			for (String m : metaPropertyConstraints.keySet()) 
			{
				counts.put(m, counts.containsKey(m) ? counts.get(m)+1 : 1);
				metaPropertyUses.put(m, counts.get(m));
			}
		}
		
		for (Term t : variablePropertyConstraints.values())
			if (t != null) t.analyzeMetaUseContractum(counts, subAnalyzers); 
		
		for (Term t : namedPropertyConstraints.values())
			if (t != null) t.analyzeMetaUseContractum(counts, subAnalyzers);  
		
		if (propertiesRef != null)
		{
			counts.put(propertiesRef, counts.containsKey(propertiesRef) ? counts.get(propertiesRef)+1 : 1);	
			metaPropertyUses.put(propertiesRef,  counts.get(propertiesRef));
		}
	}
	
	public void analyzeMetaUsePattern(Map<String, Integer> counts)
	{
		if (propertiesRef != null)
		{	
			metaPropertyUses = new HashMap<String, Integer>(4);
			
			if (counts.get(propertiesRef) == null)
			{
				// Properties ref is discarded
				metaPropertyUses.put(propertiesRef, 0);				
			}
			else
			{
				metaPropertyUses.put(propertiesRef, counts.get(propertiesRef)); // Total count
			}

		}
		
		for (Term t : namedPropertyConstraints.values())
			if (t != null) t.analyzeMetaUsePattern(counts);
		for (Term t : variablePropertyConstraints.values())
			if (t != null) t.analyzeMetaUsePattern(counts);
		for (String m : metaPropertyConstraints.keySet())
			counts.put(m, counts.containsKey(m) ? counts.get(m)+1 : 1);
		for (Term t : metaPropertyConstraints.values())
			if (t != null) t.analyzeMetaUsePattern(counts);
		term.analyzeMetaUsePattern(counts);
		
		
	}

	// @see net.sf.crsx.Term#checkNo(java.util.Collection)
	public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		for (Term t : namedPropertyConstraints.values())
			if (t != null && !t.checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;
		for (Term t : metaPropertyConstraints.values())
			if (t != null && !t.checkFree(forbidden, once, onceSeen, promiscuous, bound))
				return false;
		for (Map.Entry<Variable, Term> e : variablePropertyConstraints.entrySet())
		{
			Variable v = e.getKey();
			Term t = e.getValue();
			if (t != null)
			{
				if (forbidden.contains(v) || onceSeen.contains(v))
					return false;
				if (once.contains(v))
					onceSeen.add(v);
				if (!t.checkFree(forbidden, once, onceSeen, promiscuous, bound))
					return false;
			}
		}
		return term.checkFree(forbidden, once, onceSeen, promiscuous, bound);
	}

	// @see net.sf.crsx.Term#subsubstitute(net.sf.crsx.Valuation, net.sf.crsx.util.ExtensibleMap, net.sf.crsx.util.ExtensibleMap, net.sf.crsx.util.ExtensibleMap)
	public Sink subsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		if (possible.isEmpty())
			return copy(sink, false, bound); // Copying means there will be no substitutions so only pass redex bound variable renamings
		
		// New wrapper properties...
		String r = propertiesRef; // pass catch-all.
		Map<String, Term> np = new HashMap<String, Term>(); // new named properties
		Map<Variable, Term> vp =new HashMap<Variable, Term>(); // new variable properties
		Map<String, Term> mp = new HashMap<String, Term>(); // new meta properties
		for (Map.Entry<String, Term> e : namedPropertyConstraints.entrySet())
		{
			String name = e.getKey();
			Buffer b = new Buffer(sink);
			Sink result = e.getValue().subsubstitute(b.sink(), valuation, renamings, substitution, bound, possible);
			assert result == null;
			Term value = (GenericTerm) b.term(true);
			np.put(name, value);
		}
		for (Map.Entry<Variable, Term> e : variablePropertyConstraints.entrySet())
		{
			Variable variable = e.getKey();
			// First build copy of value.
			Buffer b = new Buffer(sink);
			Sink result = e.getValue().subsubstitute(b.sink(), valuation, renamings, substitution, bound, possible);
			assert result == null;
			Term value = (GenericTerm) b.term(true);
			// Now see whether the variable is morphed into something else...
			Variable v = bound.get(variable);
			if (v != null)
			{
				variable = v; // property variable renamed in copy
				vp.put(variable, value);
			}
			else
			{
				Contractum subContractum = substitution.get(variable);
				if (subContractum ==  null)
				{
					vp.put(variable, value); // property variable external to copy thus not touched
				}
				else
				{
					// Variable is substituted...better be to something that can still be used as a property key!
					b = new Buffer(sink);
					result = subContractum.contract(b.sink(), valuation, renamings);
					assert result == null;
					Term key = b.term(true);
					switch (key.kind())
					{
						case CONSTRUCTION :
							if (!Util.isConstant(key))
								throw new RuntimeException("Property rewrite error: substituted " + variable + " with " + key + " not usable as a property key!");
							np.put(Util.symbol(key), value); // variable substituted with constant
							break;
						case VARIABLE_USE :
							vp.put(key.variable(), value); // variable substituted by another
							break;
						case META_APPLICATION :
							mp.put(key.metaVariable(), value);
							break;
					}
				}
			}
		}
		for (Map.Entry<String, Term> e : metaPropertyConstraints.entrySet())
		{
			String metaKey = e.getKey();
			Buffer b = new Buffer(sink);
			Sink result = e.getValue().subsubstitute(b.sink(), valuation, renamings, substitution, bound, possible);
			assert result == null;
			Term value = (GenericTerm) b.term(true);
			mp.put(metaKey, value);
		}

		PropertiesWrapperConstructor c = new PropertiesWrapperConstructor(r, np, vp, mp);
		sink = sink.start(c);
		sink = term.subsubstitute(sink, valuation, renamings, substitution, bound, possible);
		return sink.end();
	}

	public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
	{
		// REVISIT: assumes that term is a construction.

		Constructor constructor = term.constructor();
		if (term.kind() == Kind.CONSTRUCTION)
		{
			visitor.visitConstruction(this, true, bound);
			visitor.visitConstructor(constructor, true, bound);
		}

		visitor.visitProperties(true);
		
		if (propertiesRef != null)
		{
			visitor.visitPropertiesRef(propertiesRef, true);
			visitor.visitPropertiesRef(propertiesRef, false);
		}

		for (String k : namedPropertyConstraints.keySet())
		{
			if (!Util.isInvisibleProperty(k))
			{
				Term t = namedPropertyConstraints.get(k);
				visitor.visitNamedProperty(k, true);
				if (t != null)
					t.visit(visitor, bound);
				visitor.visitNamedProperty(k, false);
			}
		}

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

			visitor.visitVariableProperty(property, true, value != null);

			if (bound.contains(property))
				visitor.visitBound(property, updater);
			else
				visitor.visitFree(property, updater);
			if (value != null)
				value.visit(visitor, bound);

			visitor.visitVariableProperty(property, false, value != null);
		}

		for (Entry<String, Term> p : metaPropertyConstraints.entrySet())
		{
			Term v = p.getValue();
			visitor.visitMetaProperty(p.getKey(), true, v != null);
			if (v != null)
				v.visit(visitor, bound);
			visitor.visitMetaProperty(p.getKey(), false, v != null);
		}

		visitor.visitProperties(false);

		if (term.kind() == Kind.CONSTRUCTION)
		{
			visitor.visitConstructor(constructor, false, bound);
			final int arity = term.arity();
			for (int i = 0; i < arity; ++i)
			{
				visitor.visitConstructionSub(term, i, true, bound);
				term.sub(i).visit(visitor, bound.extend(term.binders(i)));
				visitor.visitConstructionSub(term, i, false, bound);
			}
			visitor.visitConstruction(this, false, bound);
		}
		else
		{
			term.visit(visitor, bound);
		}
	}

	// Pattern...

	public boolean match(Match match, Term that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		// Match contained term.
		
		if (!((Pattern) term).match(match, that, bound, contractionCount, promiscuous, once, onceSeen))
			return false;
		
		// Special case for catch-all property list.
		if (propertiesRef != null
				&& namedPropertyConstraints.isEmpty() && variablePropertyConstraints.isEmpty() && metaPropertyConstraints.isEmpty()
				&& that instanceof PropertiesConstraintsWrapper)
		{
			PropertiesConstraintsWrapper p = (PropertiesConstraintsWrapper) that;
			match.putSubstitute(propertiesRef, new MatchedPropertiesDummySubstitute(p));
			
			return true;
		}

		// Get actual properties.
		boolean propertiesCopied = true;
		boolean meta = false; // set if meta-level properties encountered in redex
		Map<String, Term> thatNamedProperties = new HashMap<String, Term>();
		Map<Variable, Term> thatVariableProperties = new HashMap<Variable, Term>();
		if (that instanceof PropertiesConstraintsWrapper)
		{
			// Get properties directly from other wrapper.
			PropertiesConstraintsWrapper thatPropertiesHolder = (PropertiesConstraintsWrapper) that;
			if (thatPropertiesHolder.propertiesRef != null)
				return false; // cannot match when term contains catch-all meta-variable...
			thatNamedProperties = thatPropertiesHolder.namedPropertyConstraints;
			thatVariableProperties = thatPropertiesHolder.variablePropertyConstraints;
			propertiesCopied = false;
			meta = thatPropertiesHolder.isMeta();
		}
		else if (that instanceof PropertiesHolder)
		{
			// Copy properties from property-holding term. 
			PropertiesHolder thatPropertiesHolder = (PropertiesHolder) that;
			for (String p : thatPropertiesHolder.propertyNames())
				thatNamedProperties.put(p, thatPropertiesHolder.getProperty(p));
			for (Variable v : thatPropertiesHolder.propertyVariables())
				thatVariableProperties.put(v, thatPropertiesHolder.getProperty(v));
			meta = thatPropertiesHolder.isMeta();
		}
		else
		{
			// ...or off constructor.
			Constructor c = that.constructor();
			if (c != null)
			{
				// Copy properties from property-holding term. 
				PropertiesHolder thatPropertiesHolder = (PropertiesHolder) c;
				for (String p : thatPropertiesHolder.propertyNames())
					thatNamedProperties.put(p, thatPropertiesHolder.getProperty(p));
				for (Variable v : thatPropertiesHolder.propertyVariables())
					thatVariableProperties.put(v, thatPropertiesHolder.getProperty(v));
				meta = c.isMeta();
			}
		}

		// Are we collecting missing properties for catch-all?
		boolean collectProperties = false;
		boolean exactProperties = false;
		if (propertiesRef != null)
		{
			collectProperties = true;
			if (!propertiesCopied)
			{
				thatNamedProperties = new HashMap<String, Term>(thatNamedProperties);
				thatVariableProperties = new HashMap<Variable, Term>(thatVariableProperties);
				propertiesCopied = true;
			}
			Substitute previous = match.getSubstitute(propertiesRef);
			if (previous != null)
			{
				if (!(previous instanceof MatchedPropertiesDummySubstitute))
					return false; // failed because previous use of catch-all was not as a catch-all...
				else
				{
					MatchedPropertiesDummySubstitute subst = (MatchedPropertiesDummySubstitute) previous;
					thatNamedProperties.putAll(subst.namedProperties);
					thatVariableProperties.putAll(subst.variableProperties);
					exactProperties = true;
					meta = meta || subst.meta;
				}
			}
		}

		// Check named property constraints.
		for (Map.Entry<String, Term> e : namedPropertyConstraints.entrySet())
		{
			String name = e.getKey();
			Pattern valuePattern = (Pattern) e.getValue();
			if (!matchNamedProperty(
					name, valuePattern, thatNamedProperties, thatVariableProperties, match, bound, contractionCount, promiscuous,
					once, onceSeen))
				return false;
		}
		if (exactProperties && !thatNamedProperties.isEmpty())
			return false; // with exact match we cannot allow extra properties in that

		// Check variable property constraints.
		for (Map.Entry<Variable, Term> e : variablePropertyConstraints.entrySet())
		{
			Variable variable = e.getKey();
			Pattern valuePattern = (Pattern) e.getValue();
			//                if (thatKey == null)
			//                	return false; // fails because we're not searching for variables...TODO?
			if (!matchVariableProperty(
					variable, valuePattern, thatNamedProperties, thatVariableProperties, match, bound, contractionCount,
					promiscuous, once, onceSeen))
				return false;
		}
		if (exactProperties && !thatVariableProperties.isEmpty())
			return false; // with exact match we cannot allow extra properties in that

		// Check meta-properties...
		for (Map.Entry<String, Term> p : metaPropertyConstraints.entrySet())
		{
			// Compute meta-property (must already be matched).
			String keyMetaVariable = p.getKey();
			Substitute s = match.getSubstitute(keyMetaVariable);
			if (s == null)
				throw new UnsupportedOperationException("Cannot match with unbound property meta-variable ("
						+ keyMetaVariable + ")");
			assert s.getBindings().length == 0 : "Cannot have binders on property meta-variable?";
			Term key = s.getBody();
			switch (key.kind())
			{
				case VARIABLE_USE :
					if (!matchVariableProperty(
							key.variable(), (Pattern) p.getValue(), thatNamedProperties, thatVariableProperties, match, bound,
							contractionCount, promiscuous, once, onceSeen))
					{
						return false;
					}
					break;
				case CONSTRUCTION :
					if (Util.isConstant(key))
					{
						if (!matchNamedProperty(
								Util.symbol(key), (Pattern) p.getValue(), thatNamedProperties, thatVariableProperties, match,
								bound, contractionCount, promiscuous, once, onceSeen))
							return false;
						break;
					}
				default :
					throw new UnsupportedOperationException("Contractum property that is neither variable nor constant.");
			}
		}
		// This point reached when all actual property constraints satisfied.

		// Inject pseudo-match of properties, if needed.
		if (!exactProperties && collectProperties)
			match.putSubstitute(propertiesRef, new MatchedPropertiesDummySubstitute(thatNamedProperties, thatVariableProperties, meta));

		return true; // success...
	}

	/** Helper to match a single named property. */
	boolean matchNamedProperty(String name, Pattern valuePattern, Map<String, Term> thatNamedProperties, Map<Variable, Term> thatVariableProperties, Match match, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		if (valuePattern == null)
		{
			// The constraint is that there is no property for key.
			if (thatNamedProperties != null)
			{
				Term thatProperty = thatNamedProperties.get(name);
				if (thatProperty != null)
					return false; // match fails because forbidden property is present
			}
			// This point reached when forbidden property not there...
		}
		else
		{
			// The constraint is that there is a matching property for key.
			if (thatNamedProperties == null)
				return false; // match fails because there are no properties so not for key
			Term thatTerm = thatNamedProperties.get(name);
			if (thatTerm == null)
				return false; // match fails because there is no property for key
			if (!valuePattern.match(match, thatTerm, bound, contractionCount, promiscuous, once, onceSeen))
				return false; // match fails because the actual property does not match
			// This point reached when required property matches...
		}
		return true;
	}

	/** Helper to match a single named property. */
	boolean matchVariableProperty(Variable variable, Pattern valuePattern, Map<String, Term> thatNamedProperties, Map<Variable, Term> thatVariableProperties, Match match, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		Variable thatVariable = match.getVariable(variable);
		if (thatVariable == null) thatVariable = variable; // handle non-linear case
		if (valuePattern == null)
		{
			// The constraint is that there is no property for key.
			if (thatVariableProperties != null)
			{
				Term thatVarProperty = thatVariableProperties.get(thatVariable);
				if (thatVarProperty != null)
					return false; // match fails because forbidden property is present
			}
			// This point reached when forbidden property not there...
		}
		else
		{
			// The constraint is that there is a matching property for key.
			if (thatVariableProperties == null)
				return false; // match fails because there are no properties so not for key
			Term thatVarTerm = thatVariableProperties.get(thatVariable);
			if (thatVarTerm == null)
				return false; // match fails because there is no property for key
			if (!valuePattern.match(match, thatVarTerm, bound, contractionCount, promiscuous, once, onceSeen))
				return false; // match fails because the actual property does not match
			// This point reached when required property matches...
		}
		return true;
	}

	public Contractum oldunify(ExtensibleMap<Variable, Variable> thisBound, Map<Variable, Variable> thisBaseVariable, Map<String, String> thisBaseMeta, Pattern that, ExtensibleMap<Variable, Variable> thatBound, Map<Variable, Variable> thatBaseVariable, Map<String, String> thatBaseMeta, Match unifyMatch, ExtensibleMap<Variable, Variable> unifyBound, Map<String, List<Pair<ExtensibleMap<Variable, Variable>, Term>>> unifiedMatched)
	{
		// TODO Auto-generated method stub...
		throw new UnsupportedOperationException("Cannot unify property constraints wrappers");
	}

	@Override
	protected Unification unifyThese(Unification unification, Pattern that,
			StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			Set<String> existingMVars) throws CRSException {
		assert that instanceof PropertiesConstraintsWrapper : "Term not normalized before unification, " +
				"properties exist at non-root position in term, or attempting to unify GenericTerm with" +
				"non-GenericTerm";
		PropertiesConstraintsWrapper thatprop = (PropertiesConstraintsWrapper)that;
		
		int thispropertycount = namedPropertyConstraints.size() + 
								variablePropertyConstraints.size() +
								metaPropertyConstraints.size();
		int thatpropertycount = thatprop.namedPropertyConstraints.size() + 
								thatprop.variablePropertyConstraints.size() +
								thatprop.metaPropertyConstraints.size();
		
		if (thispropertycount > 1 || thatpropertycount > 1){
			throw new CRSException("Property list contains more than one constraint. Unification " +
					"cannot be determined");
		}
			
		Unification u = ((GenericTerm)this.term).unifyThese(unification, 
															(Pattern)((PropertiesConstraintsWrapper) that).term, 
															rho, rhoprime, existingMVars);
		if (u == null){
			return null;
		}
		
		//unification of term succeeded. Check unification of properties
		assert this.propertiesRef != null && thatprop.propertiesRef != null :
			"PropertiesConstraintsWrapper without catch-all";

		//Get hold of constraints of that
		Map<String, Term> thatnamedconstraints = thatprop.namedPropertyConstraints;
		Map<Variable, Term> thatvarconstraints = thatprop.variablePropertyConstraints;
		Map<String, Term> thatmetaconstraints = thatprop.metaPropertyConstraints;

		if (this.namedPropertyConstraints.size() == 1){
			//Find entry
			Entry<String, Term> thisnamedProperty = this.namedPropertyConstraints.entrySet().iterator().next();
			
			//Find entry to match against
			if(thatnamedconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatnamedProperty = thatnamedconstraints.entrySet().iterator().next();
				
				return unifyNamedWithNamed(thisnamedProperty, thatnamedProperty, 
										   this.propertiesRef, thatprop.propertiesRef, 
										   rho, rhoprime, 
										   u, existingMVars);
			}
			else if (thatvarconstraints.size() == 1){
				//Find entry
				Entry<Variable, Term> thatvarProperty = thatvarconstraints.entrySet().iterator().next();
				
				return unifyNamedWithVariable(thisnamedProperty, thatvarProperty, 
											  this.propertiesRef, thatprop.propertiesRef, 
											  rho, rhoprime, 
											  u, existingMVars);
			}
			else if (thatmetaconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatmetaProperty = thatmetaconstraints.entrySet().iterator().next();
				
				return unifyNamedWithMeta(thisnamedProperty, thatmetaProperty, 
										  this.propertiesRef, thatprop.propertiesRef, 
										  rho, rhoprime, 
										  u, existingMVars);
			}
			else {
				assert thatpropertycount == 0;
				return unifyNamedWithEmpty(thisnamedProperty, 
										   this.propertiesRef, thatprop.propertiesRef, 
										   rho, rhoprime, 
										   u, existingMVars);
			}
		}
		else if (this.variablePropertyConstraints.size() == 1){
			//Find entry
			Entry<Variable, Term> thisvariableProperty = this.variablePropertyConstraints.entrySet().iterator().next();
			
			//Find entry to match against
			if(thatnamedconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatnamedProperty = thatnamedconstraints.entrySet().iterator().next();

				return unifyNamedWithVariable(thatnamedProperty, thisvariableProperty, 
											  thatprop.propertiesRef, this.propertiesRef, 
											  rhoprime, rho, 
											  u, existingMVars);
			}
			else if (thatvarconstraints.size() == 1){
				//Find entry
				Entry<Variable, Term> thatvarProperty = thatvarconstraints.entrySet().iterator().next();

				return unifyVariableWithVariable(thisvariableProperty, thatvarProperty, 
												 this.propertiesRef, thatprop.propertiesRef, 
												 rho, rhoprime, 
												 u, existingMVars);
			}
			else if (thatmetaconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatmetaProperty = thatmetaconstraints.entrySet().iterator().next();

				return unifyVariableWithMeta(thisvariableProperty, thatmetaProperty, 
											 this.propertiesRef, thatprop.propertiesRef, 
											 rho, rhoprime, 
											 u, existingMVars);
			}
			else {
				assert thatpropertycount == 0;
				return unifyVariableWithEmpty(thisvariableProperty, 
											  this.propertiesRef, thatprop.propertiesRef, 
											  rho, rhoprime, 
											  u, existingMVars);
			}
		}
		else if (this.metaPropertyConstraints.size() == 1){
			//Find entry
			Entry<String, Term> thismetaproperty = this.metaPropertyConstraints.entrySet().iterator().next();
			
			//Find entry to match against
			if(thatnamedconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatnamedProperty = thatnamedconstraints.entrySet().iterator().next();

				return unifyNamedWithMeta(thatnamedProperty, thismetaproperty, 
										  thatprop.propertiesRef, this.propertiesRef, 
										  rhoprime, rho, 
										  u, existingMVars);
			}
			else if (thatvarconstraints.size() == 1){
				//Find entry
				Entry<Variable, Term> thatvarProperty = thatvarconstraints.entrySet().iterator().next();

				return unifyVariableWithMeta(thatvarProperty, thismetaproperty, 
											 thatprop.propertiesRef, this.propertiesRef, 
											 rhoprime, rho, 
											 u, existingMVars);
			}
			else if (thatmetaconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatmetaProperty = thatmetaconstraints.entrySet().iterator().next();

				return unifyMetaWithMeta(thismetaproperty, thatmetaProperty, 
										 this.propertiesRef, thatprop.propertiesRef, 
										 rho, rhoprime, 
										 u, existingMVars);
			}
			else {
				assert thatpropertycount == 0;

				return unifyMetaWithEmpty(thismetaproperty, 
										  this.propertiesRef, thatprop.propertiesRef, 
										  rho, rhoprime, 
										  u, existingMVars);
			}
		}
		else {
			assert thispropertycount == 0;
			//No constraints, only catchall.

			//Find entry to match against
			if(thatnamedconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatnamedProperty = thatnamedconstraints.entrySet().iterator().next();

				return unifyNamedWithEmpty(thatnamedProperty, 
										   thatprop.propertiesRef, this.propertiesRef, 
										   rhoprime, rho, 
										   u, existingMVars);
			}
			else if (thatvarconstraints.size() == 1){
				//Find entry
				Entry<Variable, Term> thatvarProperty = thatvarconstraints.entrySet().iterator().next();

				return unifyVariableWithEmpty(thatvarProperty, 
											  thatprop.propertiesRef, this.propertiesRef, 
											  rhoprime, rho, 
											  u, existingMVars);
			}
			else if (thatmetaconstraints.size() == 1){
				//Find entry
				Entry<String, Term> thatmetaProperty = thatmetaconstraints.entrySet().iterator().next();

				return unifyMetaWithEmpty(thatmetaProperty, 
										 thatprop.propertiesRef, this.propertiesRef, 
										 rhoprime, rho,
										 u, existingMVars);
			}
			else {
				assert thatpropertycount == 0;
				
				return unifyEmptyWithEmpty(this.propertiesRef, thatprop.propertiesRef, 
										   rho, rhoprime, 
										   u, existingMVars);
			}
		}
	}

	/**
	 * Generate a fresh metavariable - used extensively, so factored out.
	 * @param existingMVars the set of metavariables that already exist. 
	 * @return a fresh metavariable. The metavariable is added to the set by this method.
	 */
    private static String freshMetaVar(Set<String> existingMVars){
		String newmetavar = GenericUnification.makeMetaVar("PropConstWrap", existingMVars);
		existingMVars.add(newmetavar);
		return newmetavar;
    }
	
    /**
     * Unification helper. Unifies a named property with a named property
     * @param named1 the first named property
     * @param named2 the second named property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the second set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
    private static Unification unifyNamedWithNamed(Entry<String, Term> named1, Entry<String, Term> named2,
												   String catchall1, String catchall2,
												   StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
												   Unification u, Set<String> existingMVars) throws CRSException {
		String freshmvar = freshMetaVar(existingMVars);
		if (named1.getKey().equals(named2.getKey())){
			//Same constant property
			if (named1.getValue() == null && named2.getValue() == null){
				//Properties agree that variable should not be bound. Create empty substitutes and return
				u.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				u.putSubstitute(catchall2, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				return u;
			}
			else if (named1.getValue() != null && named2.getValue() != null){
				//Constant bound in both lists. Attempt to unify
				Unification u1 = ((GenericTerm)named1.getValue()).unifyThese(u, ((GenericTerm)named2.getValue()), 
						rho, rhoprime, existingMVars);

				if (u1 == null){
					//Unification failed.
					return null;
				}
				
				//Unification succeded. Add empty substitutes to unification and return
				u1.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				u1.putSubstitute(catchall2, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				return u1;
			}
			else {
				//Property lists disagree. Unification fails
				return null;
			}
		}
		else {
			//Different constants
			//Add substitutes for catchalls, and return
			u.putSubstitute(catchall1, new Variable[0], createConstantPropertiesConstraintsWrapper(freshmvar, 
																								   named2.getKey(), 
																								   named2.getValue()));
			u.putSubstitute(catchall2, new Variable[0], createConstantPropertiesConstraintsWrapper(freshmvar, 
																								   named1.getKey(), 
																								   named1.getValue()));
			return u;
		}
	}
	
    /**
     * Unification helper. Unifies a named property with a variable property
     * @param named1 the named property
     * @param var2 the variable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the second set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyNamedWithVariable(Entry<String, Term> named1, Entry<Variable, Term> var2,
			   										  String catchall1, String catchall2,
			   										  StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			   										  Unification u, Set<String> existingMVars){
		//Unification succeeds automatically
		String freshmvar = freshMetaVar(existingMVars);
		u.putSubstitute(catchall1, new Variable[0], createVariablePropertiesConstraintsWrapper(freshmvar, 
																							   var2.getKey(), 
																							   var2.getValue()));
		u.putSubstitute(catchall2, new Variable[0], createConstantPropertiesConstraintsWrapper(freshmvar, 
																							   named1.getKey(), 
																							   named1.getValue()));
		return u;
	}

    /**
     * Unification helper. Unifies a named property with a metavariable property
     * @param named1 the named property
     * @param meta2 the metavariable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the second set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyNamedWithMeta(Entry<String, Term> named1, Entry<String, Term> meta2,
			   									  String catchall1, String catchall2,
			   									  StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			   									  Unification u, Set<String> existingMVars) throws CRSException{
		Substitute sub = u.getSubstitute(meta2.getKey());
		assert sub != null : "Property key metavariable does not occur in term";
		assert sub.getBindings().length == 0 : "Property key metavariable has illegal arity";
		
		GenericTerm subbody = (GenericTerm)sub.getBody();
		switch(subbody.kind()){
		case CONSTRUCTION:{
			//Key is a constant. Unify using namedwithnamed
			return unifyNamedWithNamed(named1, new Pair<String, Term>(Util.symbol(subbody), meta2.getValue()), 
									   catchall1, catchall2, 
									   rho, rhoprime, 
									   u, existingMVars);
		}
		case VARIABLE_USE: {
			//Key is a variable. Unify using namedwithvariable
			return unifyNamedWithVariable(named1, new Pair<Variable, Term>(subbody.variable(), meta2.getValue()), 
									 	  catchall1, catchall2, 
									 	  rho, rhoprime, 
									 	  u, existingMVars);
		}
		case META_APPLICATION:
		default: {
			assert false : "Metavariable property key maps to invalid key";
			return null;
		}
		}
	}
	
    /**
     * Unification helper. Unifies a named property with an empty set of properties
     * @param named1 the named property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the empty set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyNamedWithEmpty(Entry<String, Term> named1, 
			   									   String catchall1, String catchall2,
			   									   StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			   									   Unification u, Set<String> existingMVars){
		//Unification succeeds automatically
		String freshmvar = freshMetaVar(existingMVars);
		u.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
		u.putSubstitute(catchall2, new Variable[0], createConstantPropertiesConstraintsWrapper(freshmvar, 
																							   named1.getKey(), 
																							   named1.getValue()));
		return u;
	}

    /**
     * Unification helper. Unifies a variable property with a variable property
     * @param var1 the first variable property
     * @param var2 the second variable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the second set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyVariableWithVariable(Entry<Variable, Term> var1, Entry<Variable, Term> var2,
			   									   		 String catchall1, String catchall2,
			   									   		 StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			   									   		 Unification u, Set<String> existingMVars) throws CRSException{
		Variable v1 = u.getVariable(var1.getKey());
		Variable v2 = u.getVariable(var2.getKey());
		assert v1 != null && v2 != null : "Unknown variable key in property";
		
		String freshmvar = freshMetaVar(existingMVars);
		if (v1.equals(v2)){
			//Same variable. 
			if (var1.getValue() == null && var2.getValue() == null){
				//Properties agree that variable must not be bound. Create empty substitutes and return
				u.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				u.putSubstitute(catchall2, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				return u;
			}
			else if (var1.getValue() != null && var2.getValue() != null){
				//Both variables bound. Attempt to unify terms.
				Unification u1 = ((GenericTerm)var1.getValue()).unifyThese(u, (GenericTerm)var2.getValue(), 
						rho, rhoprime, existingMVars);

				if (u1 == null){
					//Unification of terms failed.
					return null;
				}
				
				//Unification succeeds. Add empty substitutes and return
				u1.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				u1.putSubstitute(catchall2, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
				return u1;
			}
			else {
				//Property lists disagree on binding of variable. Unification fails
				return null;
			}
		}
		else {
			//Different variables. Unification succeeds
			u.putSubstitute(catchall1, new Variable[0], createVariablePropertiesConstraintsWrapper(freshmvar, 
																								   var2.getKey(), 
																								   var2.getValue()));
			u.putSubstitute(catchall2, new Variable[0], createVariablePropertiesConstraintsWrapper(freshmvar, 
																								   var1.getKey(), 
																								   var1.getValue()));
			return u;
		}
	}

    /**
     * Unification helper. Unifies a variable property with a metavariable property
     * @param var1 the variable property
     * @param meta2 the metavariable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the second set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyVariableWithMeta(Entry<Variable, Term> var1, Entry<String, Term> meta2,
		   		 									 String catchall1, String catchall2,
		   		 									 StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
		   		 									 Unification u, Set<String> existingMVars) throws CRSException{
		Substitute sub = u.getSubstitute(meta2.getKey());
		assert sub != null : "Property key metavariable does not occur in term";
		assert sub.getBindings().length == 0 : "Property key metavariable has illegal arity";
		
		GenericTerm subbody = (GenericTerm)sub.getBody();
		switch(subbody.kind()){
		case CONSTRUCTION:{
			//Key is a constant. Unify using namedwithvariable
			return unifyNamedWithVariable(new Pair<String, Term>(Util.symbol(subbody), meta2.getValue()), var1,  
										  catchall2, catchall1,  
										  rhoprime, rho,  
									      u, existingMVars);
		}
		case VARIABLE_USE: {
			//Key is a variable. Unify using variablewithvariable
			return unifyVariableWithVariable(var1, new Pair<Variable, Term>(subbody.variable(), meta2.getValue()), 
									 	  	 catchall1, catchall2, 
									 	  	 rho, rhoprime, 
									 	  	 u, existingMVars);
		}
		case META_APPLICATION:
		default: {
			assert false : "Metavariable property key maps to invalid key";
			return null;
		}
		}
	}
	
    /**
     * Unification helper. Unifies a variable property with an empty set of properties
     * @param var1 the variable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the empty set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyVariableWithEmpty(Entry<Variable, Term> var1, 
		   		 									  String catchall1, String catchall2,
		   		 									  StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
		   		 									  Unification u, Set<String> existingMVars){
		//Unification succeeds automatically
		String freshmvar = freshMetaVar(existingMVars);
		u.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
		u.putSubstitute(catchall2, new Variable[0], createVariablePropertiesConstraintsWrapper(freshmvar, 
																							   var1.getKey(), 
																							   var1.getValue()));
		return u;
	}

    /**
     * Unification helper. Unifies a metavariable property with a metavariable property
     * @param meta1 the first metavariable property
     * @param meta2 the second metavariable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the second set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyMetaWithMeta(Entry<String, Term> meta1, Entry<String, Term> meta2,
				 								 String catchall1, String catchall2,
				 								 StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
				 								 Unification u, Set<String> existingMVars) throws CRSException{
		Substitute sub = u.getSubstitute(meta1.getKey());
		assert sub != null : "Property key metavariable does not occur in term";
		assert sub.getBindings().length == 0 : "Property key metavariable has illegal arity";
		
		GenericTerm subbody = (GenericTerm)sub.getBody();
		switch(subbody.kind()){
		case CONSTRUCTION:{
			//Key is a constant. Unify using namedwithmeta
			return unifyNamedWithMeta(new Pair<String, Term>(Util.symbol(subbody), meta1.getValue()), meta2,  
									  catchall1, catchall2,   
									  rho, rhoprime,   
									  u, existingMVars);
		}
		case VARIABLE_USE: {
			//Key is a variable. Unify using variablewithvariable
			return unifyVariableWithMeta(new Pair<Variable, Term>(subbody.variable(), meta1.getValue()), meta2, 
									 	 catchall1, catchall2, 
									 	 rho, rhoprime, 
									 	 u, existingMVars);
		}
		case META_APPLICATION:
		default: {
			assert false : "Metavariable property key maps to invalid key";
			return null;
		}
		}
	}

    /**
     * Unification helper. Unifies a metavariable property with an empty set of properties
     * @param meta1 the metavariable property
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the empty set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyMetaWithEmpty(Entry<String, Term> meta1, 
			 									  String catchall1, String catchall2,
			 									  StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			 									  Unification u, Set<String> existingMVars){
		Substitute sub = u.getSubstitute(meta1.getKey());
		assert sub != null : "Property key metavariable does not occur in term";
		assert sub.getBindings().length == 0 : "Property key metavariable has illegal arity";
		
		GenericTerm subbody = (GenericTerm)sub.getBody();
		switch(subbody.kind()){
		case CONSTRUCTION:{
			//Key is a constant. Unify using namedwithmeta
			return unifyNamedWithEmpty(new Pair<String, Term>(Util.symbol(subbody), meta1.getValue()),   
									  catchall1, catchall2,   
									  rho, rhoprime,   
									  u, existingMVars);
		}
		case VARIABLE_USE: {
			//Key is a variable. Unify using variablewithvariable
			return unifyVariableWithEmpty(new Pair<Variable, Term>(subbody.variable(), meta1.getValue()),  
									 	  catchall1, catchall2, 
									 	  rho, rhoprime, 
									 	  u, existingMVars);
		}
		case META_APPLICATION:
		default: {
			assert false : "Metavariable property key maps to invalid key";
			return null;
		}
		}
	}
	
    /**
     * Unification helper. Unifies an empty set of properties with another empty set of properties
     * @param catchall1 the catchall metavariable of the first set of properties
     * @param catchall2 the catchall metavariable of the empty set of properties
     * @param rho bindings for the first set of properties
     * @param rhoprime bindings for the second set of properties
     * @param u current unification
     * @param existingMVars set of existing metavariables
     * @return the result of unifying the properties, or null if unification fails
     * @throws CRSException if unification cannot be determined.
     */
	private static Unification unifyEmptyWithEmpty(String catchall1, String catchall2,
			  							 		   StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			  									   Unification u, Set<String> existingMVars){
		String freshmvar = freshMetaVar(existingMVars);
		u.putSubstitute(catchall1, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
		u.putSubstitute(catchall2, new Variable[0], createEmptyPropertiesConstraintsWrapper(freshmvar));
		return u;
	}
	
	
	private static GenericTerm createDummyTerm(){
		GenericFactory factory = new GenericFactory();
		return factory.constant(new GenericIndexedConstructor(factory, 0));
	}
	
	/**
	 * Generate an (almost) empty PropertiesConstraintsWrapper
	 * @param propertiesRef the metavariable acting as property catch-all. Can be null.
	 * @param t the body of the PropertiesConstraintsWrapper. Will never be read except
	 *          to get hold of a Maker.
	 * @return a fresh PropertiesConstraintsWrapper with no constraints.
	 */
	private static PropertiesConstraintsWrapper createEmptyPropertiesConstraintsWrapper(String propertiesRef){
		return new PropertiesConstraintsWrapper(createDummyTerm(), 
												propertiesRef, 
												new HashMap<String, Term>(), 
												new HashMap<Variable, Term>(), 
												new HashMap<String, Term>());
	}
	
	/**
	 * Generate a PropertiesConstraintWrapper with a catchall metavariable and a constant property.
	 * @param propertiesRef the catchall. Can be null.
	 * @param key the key of the constant property
	 * @param t the term of the constant property
	 * @return a fresh PropertiesConstraintWrapper 
	 */
	private static PropertiesConstraintsWrapper createConstantPropertiesConstraintsWrapper(String propertiesRef, String key, Term t){
		Map<String, Term> map = new HashMap<String, Term>();
		map.put(key, t);
		return new PropertiesConstraintsWrapper(createDummyTerm(), 
												propertiesRef, 
												map, 
												new HashMap<Variable, Term>(), 
												new HashMap<String, Term>());
	}
	
	/**
	 * Generate a PropertiesConstraintWrapper with a catchall metavariable and a constant property.
	 * @param propertiesRef the catchall. Can be null.
	 * @param key the key of the variable property
	 * @param t the term of the variable property
	 * @return a fresh PropertiesConstraintsWrapper
	 */
	private static PropertiesConstraintsWrapper createVariablePropertiesConstraintsWrapper(String propertiesRef, Variable key, Term t){
		Map<Variable, Term> map = new HashMap<Variable, Term>();
		map.put(key, t);
		return new PropertiesConstraintsWrapper(createDummyTerm(), 
												propertiesRef, 
												new HashMap<String, Term>(), 
												map, 
												new HashMap<String, Term>());
	}

	public Set<String> mvars() {
		Set<String> set = new HashSet<String>();
		if (term instanceof Pattern){
			set.addAll(((Pattern)term).mvars());
		}
		for (Term t : namedPropertyConstraints.values()){
			if (t != null && t instanceof Pattern){
				set.addAll(((Pattern) t).mvars());
			}
		}
		for (Term t : variablePropertyConstraints.values()){
			if (t != null && t instanceof Pattern){
				set.addAll(((Pattern) t).mvars());
			}
		}
		for (Entry<String, Term> p : metaPropertyConstraints.entrySet()){
			set.add(p.getKey());
			Term t = p.getValue();
			if (t != null && t instanceof Pattern){
				set.addAll(((Pattern) t).mvars());
			}
		}
		return set;
	}
	
	@Override
	public PropertiesConstraintsWrapper applySubstitutes(Unification unification) {
		PropertiesConstraintsWrapper newProp;
		if (this.propertiesRef != null && unification.getSubstitute(propertiesRef) != null){
		 	Substitute sub = unification.getSubstitute(propertiesRef);
		 	assert sub.getBindings().length == 0 && sub.getBody() instanceof PropertiesConstraintsWrapper :
					"Catchall metavariable bound to illegal substitute";
		 	newProp = combineProperties((PropertiesConstraintsWrapper)sub.getBody());
	    }
		else {
			//Catchall unbound. Combine with empty PropertiesConstraintsWrapper to get a fresh copy of
			//this object's constraints.
			newProp = combineProperties(new PropertiesConstraintsWrapper(null,
																		 null,
																		 new HashMap<String, Term>(),
																		 new HashMap<Variable, Term>(),
																		 new HashMap<String, Term>()));
		}
		
		//Replace bound metavariable keys
		Map<String, Term> unbound = new HashMap<String, Term>();
		
		for (Entry<String, Term> p : newProp.metaPropertyConstraints.entrySet()){
			Substitute keysub = unification.getSubstitute(p.getKey());
			if (keysub != null){
				assert keysub.getBindings().length == 0 : "Property key metavariable bound to illegal substitute";
				Term body = keysub.getBody();
				switch (body.kind()){
				case CONSTRUCTION:{
					String constructor = Util.symbol(body);
					assert !newProp.namedPropertyConstraints.containsKey(constructor) : "Property key metavariable " +
							"bound to constant for which a property already exists.";
					newProp.namedPropertyConstraints.put(constructor, p.getValue());
				}
				case VARIABLE_USE:{
					Variable var = body.variable();
					assert !newProp.variablePropertyConstraints.containsKey(var) : "Property key metavariable " +
						    "bound to variable for which a property already exists.";
					newProp.variablePropertyConstraints.put(var, p.getValue());
				}
				case META_APPLICATION:
				default:{
					assert false : "Property key metavariable bound to illegal key";
					return null;
				}
				}
			}
			else {
				//Unbound key. Add to list of unbound
				unbound.put(p.getKey(), p.getValue());
			}
		}
		//Remove replaced keys (replace original map with map of unmapped properties)
		newProp.metaPropertyConstraints = unbound;
		
		//Rename variable property keys
		Map<Variable, Term> newVarProps = new HashMap<Variable, Term>();
		for (Entry<Variable, Term> e : variablePropertyConstraints.entrySet()){
			Variable v = unification.getVariable(e.getKey());
			if (v == null){
				//No renaming - use same key as before
				v = e.getKey();
			}
			assert !newVarProps.containsKey(v) : "Multiple variable properties renamed to same key";
			newVarProps.put(v, e.getValue());
		}
		newProp.variablePropertyConstraints = newVarProps;
		
		//Apply substitutions to all subterms, and build new PropertiesConstraintsWrapper
		Map<String, Term> named = new HashMap<String, Term>();
		Map<Variable, Term> vars = new HashMap<Variable, Term>();
		Map<String, Term> metas = new HashMap<String, Term>();
		for (Entry<String, Term> e : newProp.namedPropertyConstraints.entrySet()){
			if (e.getValue() == null){
				named.put(e.getKey(), null);
			}
			else {
				named.put(e.getKey(), ((GenericTerm)e.getValue()).applySubstitutes(unification));
			}
		}
		for (Entry<Variable, Term> e : newProp.variablePropertyConstraints.entrySet()){
			if (e.getValue() == null){
				vars.put(e.getKey(), null);
			}
			else {
				vars.put(e.getKey(), ((GenericTerm)e.getValue()).applySubstitutes(unification));
			}
		}
		for (Entry<String, Term> p : newProp.metaPropertyConstraints.entrySet()){
			if (p.getValue() == null){
				metas.put(p.getKey(), null);
			}
			else {
				metas.put(p.getKey(), ((GenericTerm)p.getValue()).applySubstitutes(unification));
			}
		}

		return new PropertiesConstraintsWrapper(((GenericTerm)this.term).applySubstitutes(unification),
												newProp.propertiesRef,
												named,
												vars,
												metas);
	}
	
	
	/**
	 * Helper method for applySubstitution. Combined this PropertiesConstraintsWrapper and another into a new
	 * PropertiesConstraintsWrapper containing all properties of both PropertiesConstraintsWrappers.
	 * The returned PropertiesConstraintsWrapper will not contain a term.
	 * @param that the other PropertiesConstraintsWrapper
	 * @return a fresh PropertiesConstraintsWrapper with the combined properties 
	 */
	private PropertiesConstraintsWrapper combineProperties(PropertiesConstraintsWrapper that) {
		//Find proper catchall. Use catchall from that, if it exists.
		String newPropertiesRef;
		if (that.propertiesRef != null){
			newPropertiesRef = that.propertiesRef;
		}
		else {
			newPropertiesRef = this.propertiesRef;
		}

		//Combine named properties
		Map<String, Term> newNamedMap = new HashMap<String, Term>();
		newNamedMap.putAll(namedPropertyConstraints);
		for (Entry<String, Term> e : that.namedPropertyConstraints.entrySet()){
			assert !newNamedMap.containsKey(e.getKey()) : "Unable to combine properties - duplicate constant key";
			newNamedMap.put(e.getKey(), e.getValue());
		}
		
		//Combine variable properties
		Map<Variable, Term> newVariableMap = new HashMap<Variable, Term>();
		newVariableMap.putAll(variablePropertyConstraints);
		for (Entry<Variable, Term> e : that.variablePropertyConstraints.entrySet()){
			assert !newVariableMap.containsKey(e.getKey()) : "Unable to combine properties - duplicate variable key";
			newVariableMap.put(e.getKey(), e.getValue());
		}
		
		//Combine metavariable properties
		Map<String, Term> newMetaMap = new HashMap<String, Term>();
		newMetaMap.putAll(metaPropertyConstraints);
		for (Entry<String, Term> e : that.metaPropertyConstraints.entrySet()){
			assert !newMetaMap.containsKey(e.getKey()) : "Unable to combine properties - duplicate meta-variable key";
			newMetaMap.put(e.getKey(), e.getValue());
		}
		
		return new PropertiesConstraintsWrapper(createDummyTerm(), newPropertiesRef, newNamedMap, newVariableMap, newMetaMap);
	}


	@Override
	protected boolean occurs(String mvar, Unification unification) {
		if (propertiesRef != null){
			if (propertiesRef.equals(mvar)){
				return true;
			}
			Substitute sub = unification.getSubstitute(propertiesRef);
			if (sub != null){
				if (((GenericTerm)sub.getBody()).occurs(mvar, unification)){
					return true;
				}
			}
		}
		
		for (Term t : namedPropertyConstraints.values()){
			if (t != null && ((GenericTerm)t).occurs(mvar, unification)){
				return true;
			}
		}
		for (Term t : variablePropertyConstraints.values()){
			if (t != null && ((GenericTerm)t).occurs(mvar, unification)){
				return true;
			}
		}

		for (Entry<String, Term> p : metaPropertyConstraints.entrySet()){
			//Assume metavariables in key positions in properties only map to legal keys, i.e. substitute
			//does not contain metavariables.
			if (p.getKey().equals(mvar) || 
					(p.getValue() != null && ((GenericTerm)p.getValue()).occurs(mvar, unification))){
				return true;
			}
		}
		
		//term may be null, since catchall may be bound to a PropertiesConstraintsWrapper without a subterm
		if (this.term != null && ((GenericTerm)this.term).occurs(mvar, unification)){
			return true;
		}
		
		return false;
	}

	@Override
	protected void generateBitmasks(Set<Variable> legalvars,
			StackedMap<Variable> rhoprime, StackedMap<Variable> inscope,
			Map<String, Boolean[]> bitmasks,
			Map<String, GenericMetaApplication> occurrences) {
		assert false : "generateBitmasks called on PropertiesContraintsWrapper - " +
				"properties in non-root position?";
	}

	@Override
	public GenericTerm makeUnificationCopy(StackedMap<Variable> varrenamings,
			Map<String, String> mvarrenamings) {
		String newpropertiesref;
		if (propertiesRef == null){
			newpropertiesref = GenericUnification.makeMetaVar("freshcatchall", mvarrenamings.keySet());
		}
		else {
			newpropertiesref = mvarrenamings.get(propertiesRef);
		}
		
		Map<String, Term> newNamedproperties = new HashMap<String, Term>();
		for (Entry<String, Term> e : namedPropertyConstraints.entrySet()){
			if (e.getValue() == null){
				newNamedproperties.put(e.getKey(), null);
			}
			else {
				newNamedproperties.put(e.getKey(), 
								   	   ((GenericTerm)e.getValue()).makeUnificationCopy(varrenamings, 
								   			   										   mvarrenamings));
			}
		}
		
		Map<Variable, Term> newVariableproperties = new HashMap<Variable, Term>();
		for (Entry<Variable, Term> e : variablePropertyConstraints.entrySet()){
			if (e.getValue() == null){
				newVariableproperties.put(e.getKey(), null);
			}
			else {
				newVariableproperties.put(varrenamings.get(e.getKey()),
									      ((GenericTerm)e.getValue()).makeUnificationCopy(varrenamings, 
									    		  										  mvarrenamings));
			}
		}
		
		Map<String, Term> newMetaproperties = new HashMap<String, Term>();
		for (Entry<String, Term> p : metaPropertyConstraints.entrySet()){
			if (p.getValue() == null){
				newMetaproperties.put(p.getKey(), null);
			}
			else {
				newMetaproperties.put(mvarrenamings.get(p.getKey()),
									  ((GenericTerm)p.getValue()).makeUnificationCopy(varrenamings, 
											  										  mvarrenamings));
			}
		}
		
		return new PropertiesConstraintsWrapper(((GenericTerm)term).makeUnificationCopy(varrenamings, mvarrenamings),
												newpropertiesref, newNamedproperties, newVariableproperties, newMetaproperties);
	}
	
	// Contractum...

	public Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
	{
//		System.out.println("\nCONTRACTING PropertiesConstraintsWrapper\n"+this);
		
		if (propertiesRef != null && namedPropertyConstraints.isEmpty() && variablePropertyConstraints.isEmpty() && metaPropertyConstraints.isEmpty() && renamings.isEmpty())
		{
			// Special case when *only* properties reference.
			Substitute substitute = valuation.getSubstitute(propertiesRef);
			if (substitute instanceof MatchedPropertiesDummySubstitute) // hack...
			{
				MatchedPropertiesDummySubstitute matchedProperties = (MatchedPropertiesDummySubstitute) substitute;
				if (term.kind() == Kind.CONSTRUCTION && !matchedProperties.meta && !Util.isEval(term.constructor()))
				{
					try
					{
						sink = sink.start(Util.wrapWithProperties(sink, term.constructor(), matchedProperties.namedProperties, matchedProperties.variableProperties));
					}
					catch (CRSException e1)
					{}
					final int arity = arity();
					for (int i = 0; i < arity; ++i)
					{
						// Bindings for i'th subterm are those from the redex.
						ExtensibleMap<Variable,Variable> innerRenamings = renamings;
						Variable[] currentBinds = binders(i);
						if (currentBinds.length > 0)
						{
							// Construct renamings for subterm construction.
							Variable[] mappedBinds = new Variable[currentBinds.length];
							for (int b = 0; b < currentBinds.length; ++b)
							{
								Variable currentVariable = currentBinds[b];
								Variable renamedVariable = valuation.getVariable(currentVariable); // reuse?
								if (renamedVariable == null)
								{
								    // This is the normal case where fresh bound variables are needed - the above is merely to allow preallocation of all bound variables by Valuation. 
								    renamedVariable = factory.makeVariable(currentVariable.name(), currentVariable.promiscuous(), currentVariable.blocking(), currentVariable.shallow());
								}
			                    innerRenamings = innerRenamings.extend(currentVariable, renamedVariable);
								mappedBinds[b] = renamedVariable;
							}
							sink = sink.binds(mappedBinds);
						}
						// Copy subterm using the new bindings.
						sink = ((Contractum) sub(i)).contract(sink, valuation, innerRenamings);
					}
					sink = sink.end();
					return sink;
				}				
				
				// HACK: send by reference... 
				sink = PropertiesWrapperConstructor.start(sink,
						matchedProperties.propertiesRef, matchedProperties.namedProperties, matchedProperties.variableProperties,
						matchedProperties.metaPropertyConstraints);
				sink = ((Contractum) term).contract(sink, valuation, renamings);
				sink = sink.end();
				////System.out.println("DONE");
				return sink;
			}
		}
		
		// Components of contracted properties wrapper...
		String contractedPropertiesRef;
		Map<String, Term> contractedNamedPropertyConstraints;
		Map<Variable, Term> contractedVariablePropertyConstraints;
		Map<String, Term> contractedMetaPropertyConstraints = new HashMap<String, Term>();
		boolean needsWrapper = false; // whether properties can be handled by plain properties on constructor
		
		if (propertiesRef == null)
		{
			// Starting from scratch.
			contractedPropertiesRef = null;
			contractedNamedPropertyConstraints = new HashMap<String, Term>();
			contractedVariablePropertyConstraints = new HashMap<Variable, Term>();
		}
		else
		{
			Substitute dummy = valuation.getSubstitute(propertiesRef);
			if (dummy == null)
			{
				// Keep existing "free" meta-variable.
				contractedPropertiesRef = propertiesRef;
				needsWrapper = true;
				contractedNamedPropertyConstraints = new HashMap<String, Term>();
				contractedVariablePropertyConstraints = new HashMap<Variable, Term>();
			}
			else if (dummy instanceof MatchedPropertiesDummySubstitute) // hack...
			{
				// Start with matched properties.
				MatchedPropertiesDummySubstitute matchedProperties = (MatchedPropertiesDummySubstitute) dummy;
				contractedPropertiesRef = matchedProperties.propertiesRef;
				// HACK: reuse existing environment...
				contractedNamedPropertyConstraints = matchedProperties.namedProperties;
				contractedVariablePropertyConstraints = matchedProperties.variableProperties;
				contractedMetaPropertyConstraints = matchedProperties.metaPropertyConstraints;
				//
				needsWrapper = contractedPropertiesRef != null
					|| contractedNamedPropertyConstraints.containsValue(null)
					|| contractedVariablePropertyConstraints.containsValue(null)
					|| (contractedMetaPropertyConstraints != null && !contractedMetaPropertyConstraints.isEmpty());
			}
			else
			{
				throw new UnsupportedOperationException("Contraction of failed match with properties?");
			}
		}

		// Contract and add additional named property values.
		for (Map.Entry<String, Term> e : namedPropertyConstraints.entrySet())
		{
			String name = e.getKey();
			Contractum value = (Contractum) e.getValue();
			contractedNamedPropertyConstraints.put(name, (value == null ? null : Buffer.contraction(value, valuation, renamings)));
			if (value == null) needsWrapper = true;
		}

		// Contract and add additional variable properties.
		for (Map.Entry<Variable, Term> e : variablePropertyConstraints.entrySet())
		{
			Variable variable = e.getKey();
			Contractum value = (Contractum) e.getValue();
			Variable contractedVariable = renamings.get(variable); // bound locally?
			if (contractedVariable == null)
			{
				contractedVariable = valuation.getVariable(variable); // matched by pattern?
				if (contractedVariable == null)
					contractedVariable = variable; // free... TODO: perhaps create fresh variable...?
			}
			contractedVariablePropertyConstraints.put(contractedVariable, (value == null ? null : Buffer.contraction(value, valuation, renamings)));
			if (value == null) needsWrapper = true;
		}

		// Contract and add what is generated by meta-properties...
		for (Map.Entry<String, Term> p : metaPropertyConstraints.entrySet())
		{
			// Contract value.
			Term value = p.getValue();
			if (value != null)
				value = Buffer.contraction((Contractum) value, valuation, renamings);

			// Contract key and use to place value appropriately.
			String keyMetaVariable = p.getKey();
			Substitute s = valuation.getSubstitute(keyMetaVariable);
			if (s != null)
			{
				// Got a substitute...use it!
				assert s.getBindings().length == 0 : "Cannot have binders on property?";
				Term key = Buffer.materialize(maker(), s.substitute(valuation, NO_TERMS), true);
				switch (key.kind())
				{
					case VARIABLE_USE :
						contractedVariablePropertyConstraints.put(key.variable(), value);
						break;
					case CONSTRUCTION :
						if (Util.isConstant(key))
						{
							contractedNamedPropertyConstraints.put(Util.symbol(key), value);
							break;
						}
					default :
						throw new UnsupportedOperationException("Contracted property that is neither variable nor constant: " + key);
				}
			}
			else
			{
				// Fall-back for undefined meta-variable - keep pattern.
				contractedMetaPropertyConstraints.put(keyMetaVariable, value);
			}
		}

		// Send!
		if (needsWrapper || !(term instanceof GenericConstruction))
		{
			sink = PropertiesWrapperConstructor.start(sink, contractedPropertiesRef, contractedNamedPropertyConstraints, contractedVariablePropertyConstraints, contractedMetaPropertyConstraints);
			sink = ((Contractum) term).contract(sink, valuation, renamings);
			sink = sink.end();
		}
		else
		{
			sink = sink.start(new PropertiesConstructor(factory, term.constructor(), contractedNamedPropertyConstraints, contractedVariablePropertyConstraints));
			final int arity = arity();
			for (int i = 0; i < arity; ++i)
			{
				// Bindings for i'th subterm are those from the redex.
				ExtensibleMap<Variable,Variable> innerRenamings = renamings;
				Variable[] currentBinds = binders(i);
				if (currentBinds.length > 0)
				{
					// Construct renamings for subterm construction.
					Variable[] mappedBinds = new Variable[currentBinds.length];
					for (int b = 0; b < currentBinds.length; ++b)
					{
						Variable currentVariable = currentBinds[b];
						Variable renamedVariable = valuation.getVariable(currentVariable); // reuse?
						if (renamedVariable == null)
						{
						    // This is the normal case where fresh bound variables are needed - the above is merely to allow preallocation of all bound variables by Valuation. 
						    renamedVariable = factory.makeVariable(currentVariable.name(), currentVariable.promiscuous(), currentVariable.blocking(), currentVariable.shallow());
						}
	                    innerRenamings = innerRenamings.extend(currentVariable, renamedVariable);
						mappedBinds[b] = renamedVariable;
					}
					sink = sink.binds(mappedBinds);
				}
				// Copy subterm using the new bindings.
				sink = ((Contractum) sub(i)).contract(sink, valuation, innerRenamings);
			}
			sink = sink.end();
		}
		////System.out.println("DONE");
		return sink;
	}

	@Override
	public void appendTermTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean outer, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps) throws IOException
	{
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		if (namedProps || variableProps)
		{
			appendTo(writer, used, depth, propertiesRef, namedPropertyConstraints, variablePropertyConstraints, metaPropertyConstraints, full, namedProps, variableProps, omitProps, sortProps);
			writer.append("\0");
		}
		term.appendTo(writer, used, depth, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET, sortProps);
	}

    public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
    {
    	return reify(factory, sink, propertiesRef, namedPropertyConstraints, variablePropertyConstraints, metaPropertyConstraints, metaPropertyUses, term, metaArgSort, freeSort, subReifiers);
    }

	public SortedSet<Path> paths(Path base)
	{
		SortedSet<Path> paths = super.paths(base);
		for (String name : namedPropertyConstraints.keySet())
			paths.add(base.extend(name));
		for (Variable variable : variablePropertyConstraints.keySet())
			paths.add(base.extend(variable));
		// TODO: meta-properties and property-reference?
		return paths;
	}

	// Helper.
	/**
	 * Print constraint prefix. 
	 * @param writer
	 * @param used
	 * @param depth
	 * @param ref
	 * @param constraints
	 * @param varConstraints
	 * @param metaConstraints
	 * @param full TODO
	 * @param namedProps
	 * @param variableProps
	 * @param omitProps
	 * @param sortProps whether to sort properties
	 * @throws IOException
	 */
	static void appendTo(Appendable writer, Map<Variable, String> used, int depth, String ref, Map<String, Term> constraints, Map<Variable, Term> varConstraints, Map<String, Term> metaConstraints, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps) throws IOException
	{
		if (omitProps == null) omitProps = LinkedExtensibleSet.EMPTY_VARIABLE_SET;
		
		if (depth <= 0)
		{
			writer.append("{...}");
			return;
		}
		if (namedProps)
		{
			boolean varProps = false;
			if (varConstraints != null)
				for (Variable v : varConstraints.keySet())
					if (!omitProps.contains(v))
						varProps = true;
			// Print prefix.
			if (ref != null || (constraints != null && !constraints.isEmpty()) || varProps || (metaConstraints != null && !metaConstraints.isEmpty()))
			{
				String sep = "";
				if (writer instanceof FormattingAppendable)
					((FormattingAppendable) writer).open("{\0");
				else
					writer.append("{");
				if (ref != null)
				{
					writer.append(ref);
					sep = (writer instanceof FormattingAppendable ? sep = ";\n" : "; ");
				}

				if (constraints != null)
				{
					Map<String, Term> map = constraints;
					if (sortProps)
						map = new TreeMap<String, Term>(constraints);
					
					for (Map.Entry<String, Term> entry : map.entrySet())
					{
						String key = entry.getKey();
						if (key.length() >= 2 && key.substring(0,2).equals("$$"))
						{
							if (key.equals(Completer.REFERENCE))
							{
								writer.append(sep + entry.getValue().metaVariable()); // HACK: not safe for strange meta-variable names...
								sep = (writer instanceof FormattingAppendable ? sep = ";\n" : "; ");
							}
							continue;
						}
						Term value = entry.getValue();
						if (value == null)
						{
							writer.append(sep + "¬ " + Util.externalizeLiteral(key));
						}
						else if (Util.isNull(value.constructor()))
						{
							writer.append(sep + Util.externalizeLiteral(key));
						}
						else
						{
							writer.append(sep + Util.externalizeLiteral(key) + " : ");
							entry.getValue().appendTo(writer, used, depth-1, full, namedProps, variableProps, null, sortProps);
						}
						sep = (writer instanceof FormattingAppendable ? sep = ";\n" : "; ");
					}
				}
				if (varConstraints != null)
				{
					Map<Variable, Term> map = varConstraints;
					if (sortProps)
						map = new TreeMap<Variable, Term>(varConstraints);
					
					for (Map.Entry<Variable, Term> entry : map.entrySet())
					{
						Variable key = entry.getKey();
						if (!omitProps.contains(key))
						{
							Term value = entry.getValue();
							if (value == null)
							{
								writer.append(sep + "¬ " + (key == null ? "null" : Util.safeVariableName(key, used, false, false)));
							}
							else if (Util.isNull(value.constructor()))
							{
								writer.append(sep + Util.safeVariableName(key, used, false, false));
							}
							else
							{
								writer.append(sep + Util.safeVariableName(key, used, false, false) + " : ");
								entry.getValue().appendTo(writer, used, depth-1, full, namedProps, variableProps, null, sortProps);
							}
							sep = (writer instanceof FormattingAppendable ? sep = ";\n" : "; ");
						}
					}
				}
				if (metaConstraints != null)
				{
					Map<String, Term> map = metaConstraints;
					if (sortProps)
						map = new TreeMap<String, Term>(metaConstraints);
					
					for (Map.Entry<String, Term> p : map.entrySet())
					{
						String key = Util.externalizeMetaVariable(p.getKey());
						Term value = p.getValue();
						if (value == null)
						{
							writer.append(sep + "¬ " + (key == null ? "null" : key));
						}
						else if (Util.isNull(value.constructor()))
						{
							writer.append(sep + key);
						}
						else
						{
							writer.append(sep + key + " : ");
							value.appendTo(writer, used, depth-1, full, true, variableProps, null, sortProps);
						}
						sep = (writer instanceof FormattingAppendable ? sep = ";\n" : "; ");
					}
				}
				if (writer instanceof FormattingAppendable)
					((FormattingAppendable) writer).close("}\0");
				else
					writer.append("}");
			}
		}
	}

	/**
	 * Output reified wrapper.
	 * @param factory to use for sorts
	 * @param sink to send to
	 * @param ref property reference
	 * @param constraints named property constraints
	 * @param varConstraints variable property constraints
	 * @param metaConstraints meta-variable property constraints
	 * @param metaUses 
	 * @param term that is wrapped
	 * @param metaArgSort sorts of meta-arguments
	 * @param freeSort sorts of free variables
	 * @return sink after the output
	 */
	static Sink reify(GenericFactory factory, Sink sink, String ref, Map<String, Term> constraints, Map<Variable, Term> varConstraints, Map<String, Term> metaConstraints, Map<String, Integer> metaUses, Term term, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
	{
		int ends = 0;
		// Property reference.
		if (ref != null)
		{
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY_REF)); // PROPERTY-REF[
    		sink = sink.start(sink.makeLiteral(ref, CRS.STRING_SORT)).end(); // ref
    		
    		if (metaUses != null && metaUses.get(ref) != null)
    		{
	    		int count = metaUses.get(ref);
	    		if (count == -3)
	    			sink = sink.start(sink.makeConstructor(CRS.REIFY_NA)).end(); // NA
	    		else if (count == 0) // DISCARD
	    			sink = sink.start(sink.makeConstructor(CRS.REIFY_DISCARD)).end(); // DISCARD
	    		else
	    		{
	    			sink = sink.start(sink.makeConstructor(CRS.REIFY_USE)); // USE
	    			sink = sink.start(sink.makeLiteral(Integer.toString(count), CRS.NUMERIC_SORT)).end();
	    			sink = sink.end(); // ] of COPY
	    		}
	    	}
    		else
    		{
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_NA)).end(); // NA
    		}
    		++ends;
		}
    	// Named properties.
    	SortedSet<String> propertyNames = new TreeSet<String>();
    	for (String p : constraints.keySet())
    		propertyNames.add(p);
    	for (String name : propertyNames)
    	{
    		if (name.startsWith("$$")) continue;
    		Term value = constraints.get(name);
    		if (value == null)
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY_NOT)); // PROPERTY-NOT[
    		else
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY)); // PROPERTY[
    		++ends;
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_LITERAL)); // LITERAL[
    		sink = sink.start(sink.makeLiteral(name, CRS.STRING_SORT)).end(); // "name"
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[
    		sink = sink.start(factory.makeLiteral(CRS.STRING_SORT, CRS.STRING_SORT)).end(); // "$String"
    		sink = sink.start(factory.nilConstructor).end(); // ()
    		sink = sink.end(); // ] of SORT
    		sink = sink.end(); // ] of LITERAL
    		if (value != null)
    			sink = value.reify(sink, metaArgSort, freeSort, subReifiers); // value
    	}
    	// Variable properties.
    	SortedSet<Variable> propertyVariables = new TreeSet<Variable>();
    	for (Variable v : varConstraints.keySet())
    		propertyVariables.add(v);
    	for (Variable variable : propertyVariables)
    	{
    		Term value = varConstraints.get(variable);
    		if (value == null)
    		{
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY_NOT)); // PROPERTY-NOT[
    			++ends;
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_VARIABLE_USE)).use(variable).end(); // VARIABLE-USE[variable]
    		}
    		else
    		{
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY)); // PROPERTY[
    			++ends;
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_VARIABLE_USE)).use(variable).end(); // VARIABLE-USE[variable]
    			sink = value.reify(sink, metaArgSort, freeSort, subReifiers); // value
    		}
    	}
    	// Meta-properties.
    	for (Map.Entry<String, Term> e : metaConstraints.entrySet())
    	{
    		String key = e.getKey();
    		Term value = e.getValue();
    		Integer use = metaUses == null ? Integer.valueOf(0) : metaUses.get(key);
    		if (use == null)
    			use = Integer.valueOf(0);
    		if (value == null)
    		{
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY_NOT)); // PROPERTY-NOT[
    			++ends;
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_META_APPLICATION)).start(sink.makeLiteral(key, CRS.STRING_SORT)).end().start(sink.makeConstructor(CRS.NIL_SYMBOL)).end();
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_USE)).start(sink.makeLiteral(use.toString(), CRS.NUMERIC_SORT)).end().end(); // USE
    			sink = sink.end(); // ] of META-APPLICATION
    		}
    		else
    		{
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY)); // PROPERTY[
    			++ends;
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_META_APPLICATION)).start(sink.makeLiteral(key, CRS.STRING_SORT)).end().start(sink.makeConstructor(CRS.NIL_SYMBOL)).end();
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_USE)).start(sink.makeLiteral(use.toString(), CRS.NUMERIC_SORT)).end().end(); // USE
    			sink = sink.end(); // ] of META-APPLICATION
    			sink = value.reify(sink, metaArgSort, freeSort, subReifiers); // value
    		}
    	}
    	// Wrapped term.
    	sink = term.reify(sink, metaArgSort, freeSort, subReifiers);
    	// Close all open brackets.
    	while (ends-- > 0)
    		sink = sink.end(); // ]]]]]]] of PROPERTY-NOT/PROPERTY/PROPERTY-REF 
    	return sink;
	}

	/** Internal helper so we stuff the properties in the Substitute. */
	static class MatchedPropertiesDummySubstitute implements Substitute
	{
		/** Matched properties. */
		final Map<String, Term> namedProperties;
		/** Matched variable properties. */
		final Map<Variable, Term> variableProperties;
		final Map<String, Term> metaPropertyConstraints;
		final String propertiesRef;
		final boolean meta;

		// Constructor.
		/** Wrap matched properties. */
		MatchedPropertiesDummySubstitute(Map<String, Term> properties, Map<Variable, Term> varProperties, boolean meta)
		{
			this.propertiesRef = null;
			this.namedProperties = properties;
			this.variableProperties = varProperties;
			this.metaPropertyConstraints = new HashMap<String, Term>();
			this.meta = meta;
		}

		/** Wrap matched properties. */
		MatchedPropertiesDummySubstitute(String propertiesRef, Map<String, Term> properties, Map<Variable, Term> varProperties, Map<String, Term> metaPropertyConstraints)
		{
			this.propertiesRef = propertiesRef;
			this.namedProperties = properties;
			this.variableProperties = varProperties;
			this.metaPropertyConstraints = metaPropertyConstraints;
			meta = false;
		}

		/** Wrap matched properties. */
		MatchedPropertiesDummySubstitute(PropertiesConstraintsWrapper p)
		{
			this.propertiesRef = p.propertiesRef;
			this.namedProperties = p.namedPropertyConstraints;
			this.variableProperties = p.variablePropertyConstraints;
			this.metaPropertyConstraints = p.metaPropertyConstraints;
			meta = p.isMeta();
		}
		
		// Substitute...
		public boolean rematch(Match match, Variable[] bindings, Term term)
		{
			throw new UnsupportedOperationException("Misuse of MatchedPropertiesDummySubstitute?");
		}

		public Copyable substitute(Valuation valuation, Term[] replacement)
		{
			throw new UnsupportedOperationException("Misuse of MatchedPropertiesDummySubstitute?");
		}

		public Variable[] getBindings()
		{
			throw new UnsupportedOperationException("Misuse of MatchedPropertiesDummySubstitute?");
		}

		public Term getBody()
		{
			throw new UnsupportedOperationException("Misuse of MatchedPropertiesDummySubstitute?");
		}

		public void replaceBody(Term replacement)
		{
			throw new UnsupportedOperationException("Misuse of MatchedPropertiesDummySubstitute?");
		}

		public String toString()
		{
			return "{" + namedProperties + "+" + variableProperties + "+" + propertiesRef + "}";
		}
	}
	
	// Helper.

	/**
	 * Update an existing term to include additional constraints.
	 * @param constraints to add
	 * @param term to add constraints to (may be modified destructively)
	 * @return term with the constraints added
	 */
	static GenericTerm wrapWith(PropertiesWrapperConstructor constraints, GenericTerm term)
	{
		if (constraints.isEmpty())
			return term;
		String propertiesRef = constraints.propertiesRef;
		Map<String, Term> namedPropertyConstraints = constraints.namedPropertyConstraints;
		Map<Variable, Term> variablePropertyConstraints = constraints.variablePropertyConstraints;
		Map<String, Term> metaPropertyConstraints = constraints.metaPropertyConstraints;
		boolean hasRef = propertiesRef != null;
//		boolean hasNots = namedPropertyConstraints.containsValue(null) || variablePropertyConstraints.containsValue(null);
//		boolean hasMetas = !metaPropertyConstraints.isEmpty();
		
		if (term instanceof PropertiesConstraintsWrapper)
		{
			// Wrapping a wrapper - resuse existing wrapper when possible.
			PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) term;
			if (!hasRef || pcw.propertiesRef == null)
			{
				if (hasRef)
					pcw.propertiesRef = propertiesRef;
				pcw.setPropertyConstraints(namedPropertyConstraints);
				pcw.setVariablePropertyConstraints(variablePropertyConstraints);
				pcw.setMetaPropertyConstraints(metaPropertyConstraints);
				return pcw;
			}
		}
		
		else if (term instanceof GenericVariableUse)
		{
			((GenericVariableUse) term).addProperties(constraints);
		}
		
//		else if (term.kind() == Kind.CONSTRUCTION && !hasRef && !hasNots && !hasMetas)
//		{
//			// Just adding properties to construction.
//			Constructor c = term.constructor();
//			if (c instanceof PropertiesConstructor)
//			{
//				// Just add them to existing properties.
//				PropertiesConstructor pc = (PropertiesConstructor) c;
//				pc.setLocalProperties(namedPropertyConstraints);
//				pc.setLocalVariableProperties(variablePropertyConstraints);
//				return term;
//			}
//			else
//			{
//				// Create new construction with property-holding constructor.
//				PropertiesConstructor pc = new PropertiesConstructor(term.maker(), c, namedPropertyConstraints, variablePropertyConstraints);
//				final int arity = term.arity();
//				Variable[][] binds = new Variable[arity][];
//				Term sub[] = new Term[arity];
//				for (int i = 0; i < arity; ++i)
//				{
//					binds[i] = term.binders(i);
//					sub[i] = term.sub(i);
//				}
//				return term.maker().newConstruction(pc, binds, sub);
//			}
//		}
		
		// Fall-back to create a new wrapper.
		return new PropertiesConstraintsWrapper(term, propertiesRef, namedPropertyConstraints, variablePropertyConstraints, metaPropertyConstraints);
	}
}
