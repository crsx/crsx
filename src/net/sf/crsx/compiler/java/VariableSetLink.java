// Copyright (c) 2013 IBM Corporation.

package net.sf.crsx.compiler.java;


/**
 * Variable set implemented as linked list.
 * 
 * Sets are copied on write.
 * 
 * @author <a href="researcher.watson.ibm.com/researcher/view.php?person=us-villard">Lionel Villard</a>.
 */
public class VariableSetLink extends Referenceable
{

	// Static helpers

	/**
	 * Search variable in given set.
	 * 
	 * @param set
	 * @param variable
	 * @return
	 */
	final public static VariableSetLink variableSetLinkFor(VariableSetLink set, Variable variable)
	{
		for (; set != null; set = set.link)
		{
			if (set.variable == variable)
				return set;
		}
		
		return null;
	}
	
	/**
	 * Create variable set from variable array 
	 * @param vars
	 * @return
	 */
	final public static VariableSetLink create(Variable[] vars)
	{
		if (vars == null)
			return null;
		
		VariableSetLink link = null;
		for (int i = 0; i < vars.length; i ++)
		{
			VariableSetLink newlink = new VariableSetLink();
			newlink.nr = 1;
			newlink.variable = vars[i];
			newlink.link = link;
			link = newlink;
		}
		return link;
	}
	
	/**
	 * Add given variable to given set.
	 * 
	 * @param set. May be null. Transfer reference.
	 * @param var to add
	 */
	public static VariableSetLink add(VariableSetLink set, Variable var)
	{
		if (var == null)
			return set;
		
		if (set == null)
		{
			set = new VariableSetLink();
			set.nr = 1;
			set.variable = var;
			//set.link = null;
			return set;
		}
		
		if (!set.contains(var))
		{
			// Insert.
			if (set.nr > 1)
			{
				set.nr --;
				set = set.copy();
			}
			
			VariableSetLink l = new VariableSetLink();
			l.nr = 1;
			l.variable = var;
			l.link = set;
			set = l;
		}
		
		return set;
	}
	
	/**
	 * Merge the two sets.
	 * 
	 * @param first. Reference is transferred.	  
	 * @param second. Reference is transferred.	  
	 * @return
	 */
	public static VariableSetLink mergeAll(VariableSetLink first, VariableSetLink second)
	{
		if (first == null)
			return second;
	
		return first.merge(second);
	}
		
	
	// State
	
	/** Next variable */
	public VariableSetLink link;

	/** Variable */
	public Variable variable;

	// Constructor
	
	public VariableSetLink()
    {
    }
	
	/** Clone link */
	public VariableSetLink(VariableSetLink link)
    {
	    this.variable = link.variable;
    }
	
	// Methods
	
	/**
	 * Tells whether this link or subsequent links contains the given variable
	 * 
	 * @param v
	 * @return
	 */
	public boolean contains(Variable v)
	{
		return variableSetLinkFor(this, v) != null;
	}

	/**
	 * Copy this set.
	 */
	public VariableSetLink copy()
	{
		VariableSetLink top = null;
		VariableSetLink last = null;
		VariableSetLink link = this;
		while (link != null)
		{
			VariableSetLink copy = new VariableSetLink(link);
			copy.link = last;
			copy.nr = 1;
			
			if (top == null)
				top = copy;
			
			last = copy;
			link = link.link;			
		}
		return top;
	}

	
	/**
	 * Add all given variables. 
	 * 
	 * <p>Note: this method mutates this set
	 */
	public VariableSetLink addAll(Variable[] vars)
	{
		if (vars == null)
			return this;
		
		VariableSetLink oldtop = this;
		VariableSetLink top = this;
		
		for (int i = 0; i < vars.length; i ++)
		{
			if (!oldtop.contains(vars[i]))
			{
				VariableSetLink link = new VariableSetLink();
				link.nr = 1;
				link.variable = vars[i];
				link.link = top;
				top = link;
			}
		}
		return top;
	}
	
	
	/**
	 * Computes intersection
	 * 
	 * <p>Note: this method mutates this set
	 */
	public VariableSetLink intersect(VariableSetLink other)
	{
		return intersect(other, null);
	}
	
	/**
	 * Computes intersection
	 */
	public VariableSetLink intersect(VariableSetLink other, VariableSetLinkHolder removed)
	{
		if (other == null)
		{
			if (removed != null)
				removed.link = this;
			return null;
		}
		
		VariableSetLink link = this;
		VariableSetLink top = null;
		VariableSetLink prev = null;		
		while (link != null)
		{
			assert link.nr == 1;
			
			if (!other.contains(link.variable))
			{
				// Remove link.
				final VariableSetLink next = link.link;
				
				if (prev != null)
					prev.link = next; // transfer ref
						
				// Add to removed list.
				if (removed != null)
				{
					link.link = removed.link;
					removed.link = link;
				}
				else
				{
					link.link = null;
				}
					
				link = next;				
			}
			else
			{
				// Process next.
				if (top == null)
					top = link;
				
				prev = link;
				link = link.link;
			}			
		}
		
		return top;
	}
	

	/**
	 * Remove given variable. 
	 * 
	 * <p>Note: this method mutates this set
	 */
	public VariableSetLink remove(Variable var)
	{
		VariableSetLink top = this;
		VariableSetLink link = this;
		VariableSetLink prev = null;
		
		while (link != null)
		{
			assert link.nr == 1;
			
			if (link.variable == var)
			{
				if (prev == null) // First?
				{
					top = link.link;
					
					link.link = null;
					
					link = top;
				}
				else
				{
					prev.link = link.link;
					link.link = null;
					link = prev.link;					
				}
			}
			else
				link = link.link;
		}
		 
		return top;
	}
	
	/**
	 * Whether the variable array contains the given variable 	 
	 */
	public static boolean contains(Variable[] vars, Variable var)
	{
		for (int i = 0; i < vars.length; i ++)
			if (vars[i] == var)
				return true;
		return false;
	}
	
	/**
	 * Remove all given variables. 	 
	 */
	public VariableSetLink removeAll(Variable[] vars)
	{
		if (vars == null)
			return this;
		
		VariableSetLink set = this;
		if (set.nr > 1)
			set = set.copy();
		
		VariableSetLink link = set;
		VariableSetLink top = null;
		VariableSetLink last = null;
		int c = vars.length;
		while (link != null)
		{
			if (contains(vars, link.variable))
			{
				if (last != null)
					last.link = link.link;
				
				VariableSetLink next = link.link;
				
				link.link = null;
				//freeVariableSetLinks(link);
				
				link = next;
				
				c--;
				if (c == 0)
					break;
			}
			else
			{
				if (top == null)
					top = link;
				
				last = link;
				link = link.link;
			}	
		}
		 
		return top;
	}
	
	/**
	 * Removes all variables contained in other
	 *  
	 * @param other. Reference is *not* transferred.
	 * @return
	 */
	public VariableSetLink minus(VariableSetLink other)
	{
		if (other == null)
			return this;
		
		VariableSetLink set = this;
		if (set.nr > 1)
		{
			set.nr --;
			set = set.copy();
		}
		
		VariableSetLink link = set;
		VariableSetLink top = null;
		VariableSetLink last = null;		
		
		int c = other.count();
		while (link != null)
		{
			if (other.contains(link.variable))
			{
				VariableSetLink next = link.link;
				
				if (last != null)
					last.link = next;
				
				link.link = null;
				//freeVariableSetLinks(link);
				
				link = next;
				
				c--;
				if (c == 0)
					break;
			}
			else
			{
				if (top == null)
					top = link;
				
				last = link;
				link = link.link;
			}					
		}
		
		return top;
	}


	/**
	 * Merge the two sets.
	 * 
	 * @param other. Reference is transferred.
	 * @return 
	 */
	public VariableSetLink merge(VariableSetLink second)
	{
		VariableSetLink set = this.minus(second);
	
		if (set == null)
			return second;
		
		if (set.nr > 1)
		{
			set.nr --;
			set = set.copy();
		}
		
		VariableSetLink link = set;
		while (link.link != null)
			link = link.link;
		
		if (second.nr > 1)
		{
			second.nr --;
			second = second.copy();
		}
		
		link.link = second; // transfer ref
		
		return set;
	}
	
	/**
	 * Count number of links  
	 */
	public int count ()
	{
		VariableSetLink link = this;
		int c = 0;
		while (link != null)
		{
			c++;
			link = link.link;
		}
		return c;
	}
	
	// Overrides

	@Override
    protected void unlink()
    {
		assert nr > 0;
		
		if (--nr == 0)
		{
			// Avoid deep recursive calls
			VariableSetLink link = this.link;
			this.link = null;
			while (link != null)
			{
				if (--link.nr == 0)
				{
					VariableSetLink newLink = link.link;
					
					link.variable = null;
					link.link = null;
					
					link = newLink;					
				}
				else
					break;
			}			
		}
    }
	
	// Inner classes
	
	public static class VariableSetLinkHolder
	{
		public VariableSetLink link;
	}
	
	// Helper for debugging only.
	
	public boolean containsName(String v)
	{
		for (VariableSetLink link = this; link != null; link = link.link)
		{
			if (link.variable.name.equals(v))
				return true;
		}
		return false;
	}
	
	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		sb.append("<");
		int count = 1;
		sb.append(variable.toString());
		for (VariableSetLink link = this.link; link != null; link = link.link)
		{
			sb.append(", ").append(link.variable);
			count++;
		}
		sb.append(">");
		sb.insert(0, "[" + count + "]");
		return sb.toString();
	}


}
