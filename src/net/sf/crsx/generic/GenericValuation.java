/* Copyright (c) 2006, 2007 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.Map;

import net.sf.crsx.Match;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.Util;

/**
 * Generic implementation of a valuation.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericValuation.java,v 3.0 2012/12/17 18:04:54 krisrose Exp $
 */
class GenericValuation implements Valuation
{
	// State.

	/** Rule of the valuation. */
	final protected GenericRule rule;

	/** Map from meta-variable names to substitutes, and of free variables. */
	final protected Match match;

    /** Renamings of bound variables (). */
    final Map<Variable, Variable> reuse;
    
    // Constructor.
	
	/**
	 * Construct valuation mapping patterns 
	 * @param rule to contract
	 * @param match of rule's pattern against a term
	 * @param reuse maps variables in contractum to the corresponding bound variable in redex to reuse
	 * @param noMeta set to true only when the 
	 */
	GenericValuation(GenericRule rule, Match match, Map<Variable, Variable> reuse, boolean noMeta)
	{
		this.rule = rule;
		this.match = match;
		this.reuse = reuse;
	}
	
	// Valuation...
	
	public String name()
	{
		return rule.name();
	}

	public Substitute getSubstitute(String metaVariable)
	{
		return match.getSubstitute(metaVariable);
	}

    public Variable getVariable(Variable variable)
    {
        Variable v = reuse.get(variable);
        if (v == null)
            v = match.getVariable(variable);
        return v;
    }

    public Sink contract(Sink sink)
	{
    	// Allocate fresh variables.
    	ExtensibleMap<Variable, Variable> mapped = LinkedExtensibleMap.EMPTY_RENAMING;
    	for (Term vd : rule.fresh.values())
    	{
    		Variable v = Util.variableWithOptionalSortVariable(vd);
    		Variable freshV = sink.makeVariable(v.name(), v.promiscuous(), v.blocking(), v.shallow());
    		mapped = mapped.extend(v, freshV);
    	}
        // ENTRY POINT to Contractum.contract().
		return rule.contract(sink, this, mapped);
	}
    
	public boolean leave()
    {
        return rule.leaf;
    }

	// Sic.
	
    public String toString()
	{
		return "Valuation ["+rule.name()+"]: "+match+" --> "+rule.contractum;
	}
}
