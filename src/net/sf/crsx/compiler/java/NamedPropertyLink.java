// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.util.HashSet;

/**
 * Named property
 *
 * @author villardl
 */
public class NamedPropertyLink extends Referenceable
{
	// Constants
	
	public static final String CLOSED_PROPERTY = "\\closed\\";

	// Static
	
	public static final boolean IS_PROPERTY_CLOSED(NamedPropertyLink link)
	{
		return link.name == CLOSED_PROPERTY;
	}
	
	
	// State
	
	/** Next */
	protected NamedPropertyLink link;

	/** Property name */
	protected String name;

	/** Term or Weakening */
	protected Object termOrWeakening;

	// Constructors

	/** Clone link (except link) */
	protected NamedPropertyLink(NamedPropertyLink link)
	{
		this.name = link.name;
		this.termOrWeakening = link.termOrWeakening;
	}

	public NamedPropertyLink(String name, Term term, NamedPropertyLink link)
	{
		this.name = name;
		this.termOrWeakening = term;
		this.link = link;
	}

	public NamedPropertyLink(String name, Variable weakening, NamedPropertyLink link)
	{
		this.name = name;
		this.termOrWeakening = weakening;
		this.link = link;
	}

	// Methods

	/**
	 * Term when name != null
	 */
	final public Term term()
	{
		return (Term) termOrWeakening;
	}

	/**
	 * Weakening when name == null - indicates free variable known to not occur
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
			if (name != null)
				UNLINK(term());

			NamedPropertyLink link = this.link;
			this.link = null;
			while (link != null)
			{
				if (--link.nr == 0)
				{
					if (link.name != null)
						UNLINK(link.term());

					link = link.link;
				}
				else
					break;
			}
		}
	}

	// Inner class

	public static class NamedPropertyLinkHolder
	{
		NamedPropertyLink link;
	}

	// Debugging

	public boolean isCircular()
	{
		HashSet<NamedPropertyLink> set = new HashSet<NamedPropertyLink>();
		for (NamedPropertyLink link = this; link != null; link = link.link)
		{
			if (set.contains(link))
				return true;
			set.add(link);
		}
		return false;
	}

	public int count()
	{
		int count = 0;
		for (NamedPropertyLink link = this; link != null; link = link.link)
		{
			count++;
		}
		return count;
	}

	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		int count = 1;
		if (name == null)
			sb.append("<weakening ").append(weakening().name).append(">");
		else
			sb.append('"').append(name).append("\": <Term>");
		for (NamedPropertyLink link = this.link; link != null; link = link.link)
		{
			if (link.name == null)
				sb.append(", <weakening ").append(link.weakening().name).append(">");
			else
				sb.append(",\"").append(link.name).append("\": <Term>");
			count++;
		}
		sb.insert(0, "[" + count + "]");
		return sb.toString();
	}

}
