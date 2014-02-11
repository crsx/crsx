// Copyright (c) 2010, 2012 IBM Corporation.
package net.sf.crsx.compiler.java;

import java.util.HashSet;

/** 
 * Variable Property
 * 
 * @author villardl
 */
public class VariablePropertyLink extends Referenceable
{
	
	// State

	/** Next */
	protected VariablePropertyLink link;
	
	/** Variable. Null when link is a weakening. */
	protected Variable variable;

	/** Term or Weakening */
	protected Object termOrWeakening;

	// Constructor
	
	/** Clone except link */
	public VariablePropertyLink(VariablePropertyLink link)
    {
	    this.variable = link.variable;
	    this.termOrWeakening = link.termOrWeakening;
    }
 
	public VariablePropertyLink(Variable variable, Term term, VariablePropertyLink link)
    {
	   this.variable = variable;
	   this.termOrWeakening = term;
	   this.link = link;
    }


	public VariablePropertyLink(Variable variable, Variable weakening, VariablePropertyLink link)
    {
	   this.variable = variable;
	   this.termOrWeakening = weakening;
	   this.link = link;
    }

	// Methods

	/**
	 * Term when variable != null
	 */
	final public Term term()
	{
		return (Term) termOrWeakening;
	}

	/**
	 * Variable when variable == null - indicates free variable known to not occur
	 * @return
	 */
	final public Variable weakening()
	{
		return (Variable) termOrWeakening;
	}
	
	// Overrides
	
	protected void unlink()
	{
		assert nr > 0;

		nr--;

		if (nr == 0)
		{
			if (variable != null)
				UNLINK(term());

			VariablePropertyLink link = this.link;
			this.link = null;
			while (link != null)
			{
				if (--link.nr == 0)
				{
					if (link.variable != null)
						UNLINK(link.term());
		
					link = link.link;
				}
				else
					break;
			}
		}
	}

	// Inner class
	
	final public static class VariablePropertyLinkHolder
	{
		VariablePropertyLink link;
	}
	
	// Debugging
	
	public boolean containsName(String name)
	{
		VariablePropertyLink link = this;
		while (link != null && (link.variable == null || !link.variable.name.equals(name)))
			link = link.link;
		return link != null;
	}
	
	public boolean isCircular()
	{
		HashSet<VariablePropertyLink> set = new HashSet<VariablePropertyLink>();
		for (VariablePropertyLink link = this; link != null; link = link.link)
		{
			if (set.contains(link))
				return true;
			set.add(link);
		}
		return false;
	}
	
	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		int count = 1;
		if (variable == null)
			sb.append("<weakening ").append(weakening().name).append(">");
		else
			sb.append('"').append(variable.name).append("\": <Term>");
		for (VariablePropertyLink link = this.link; link != null; link = link.link)
		{
			if (link.variable == null)
				sb.append(", <weakening ").append(link.weakening().name).append(">");
			else
				sb.append(",\"").append(link.variable.name).append("\": <Term>");
			count ++;
		}
		sb.insert(0, "[" + count + "]");
		return sb.toString();
	}

}
