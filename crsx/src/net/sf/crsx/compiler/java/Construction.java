// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

/**
 * Construction term
 * 
 * @author villardl
 */
public class Construction extends Term
{
	// State

	/** Whether subterm known to be normal form */
	public boolean nf;

	/** Whether function construction subterm known to not currently be steppable */
	public boolean nostep;

	/** Whether term known to closed (no free variables) */
	public boolean closed;
	
	/** Named properties */
	public NamedPropertyLink namedProperties;

	/** variable properties */
	public VariablePropertyLink variableProperties;

	/** Free binders known to not occur in subterm (including properties). Does not include contextual binders */
	public VariableSetLink weakenings;
	
	/** Subterms */
	public Term[] sub;
	
	/** Flat array of sub binders. See {@link ConstructionDescriptor#binderoffset} */
	public Variable[] binders;

	// Constructors

	protected Construction()
	{}

	public Construction(ConstructionDescriptor descriptor,VariableSetLink weakenings,  NamedPropertyLink namedProperties,
	        VariablePropertyLink variableProperties, boolean nf, boolean nostep)
	{
		assert namedProperties == null || !namedProperties.isCircular();
		assert variableProperties == null || !variableProperties.isCircular();
		
		this.descriptor = descriptor;
		this.weakenings =weakenings; 
		this.namedProperties = namedProperties;
		this.variableProperties = variableProperties;
		
		this.nf = nf;
		this.nostep = nostep;

		sub = descriptor.arity > 0 ? new Term[descriptor.arity] : null;
		
		binders = descriptor.bindercount > 0 ? new Variable[descriptor.bindercount] : null;		
	}
	
	// Methods
	
	/**
	 * Unlink sub term at given index
	 * @param index
	 */
	final public void unlinkSub(int index)
	{
		sub[index].unlink();
		sub[index] = null;
	}
	
	/**
	 * Propagate sub-weakenings up to this construction
	 */
	final public void propagateWeakenings()
	{
		// If this construction has some properties, upward propagation is disabled
		// Indeed, each promoted weakening is only valid if one the following condition is met:
		// 1. the promoted weakening is among the leading property weakenings (cheap but incomplete?)
		// 2. the variable of the promoted weakening does not occur in the properties (expensive)
		
		//if (namedProperties != null || variableProperties != null)
		//	return;
		VariableSetLink newWeakenings = null;
		boolean init = true; // whether to init new weakening or compute intersection.
		
		// Start with properties weakening candidates.
		VariablePropertyLink link = variableProperties;
		if (link != null)
		{
			for (; link != null; link = link.link)
			{
				if (link.variable != null)
					break;
				
				if (newWeakenings == null)
				{
					newWeakenings = new VariableSetLink();
					newWeakenings.nr = 1;
					newWeakenings.variable = link.weakening();
					init = false;				
				}
				else
					newWeakenings = VariableSetLink.add(newWeakenings, link.weakening());					
			}
			
			if (newWeakenings == null) // properties but no weakening?
				return;
		}
		
		
		final int arity = descriptor.arity;
		int i = arity;
		
		// Propagate the weakenings upwards by computing the intersection
		// of all sub-weakenings. 				
		if (i > 0)
		{
			// First pass: intersect construction weakenings
			boolean hasVariable = false;
			while ((--i) >= 0)
			{
				Term sub = SUB(this, i);
				if (Term.IS_CONSTRUCTION(sub))
				{
					VariableSetLink cweakenings = ((Construction) sub).weakenings;
					if (cweakenings == null)
					{
						// Empty intersection
						newWeakenings = null;
						break;
					}
					
					if (init)
					{
						// Copy initial set of weakenings
						newWeakenings = cweakenings.copy();
						init = false; // From now on, intersect.						
					}
					else
					{
						// Intersect
						newWeakenings = newWeakenings.intersect(cweakenings);
						if (newWeakenings == null)
							break;
					}
				}
				else
				{
					hasVariable = true;
				}
			}
				
			if (newWeakenings != null && hasVariable)
			{
				// Remove variable uses.
				i = arity;
				
				while ((--i) >= 0)
				{
					Term sub = SUB(this, i);
					if (Term.IS_VARIABLE_USE(sub))
					{
						newWeakenings = newWeakenings.remove(((VariableUse) sub).variable);
						if (newWeakenings == null)
							break;
					}
				}
			}
			
			if (newWeakenings != null)
			{
				// Propagate down redundant weakenings 
				// Only safe on non-shared subs.

				// This is not strictly needed. 

				//				i = ARITY(this);
				//				
				//				while ((--i) >= 0)
				//				{
				//					Term sub = SUB(this, i);
				//					if (LINK_COUNT(sub) == 1 && Term.IS_CONSTRUCTION(sub))
				//					{
				//						final Construction c = (Construction) sub;
				//						VariableSetLink w = c.weakenings;
				//						if (LINK_COUNT(w) > 1)
				//						{
				//							w = w.copy();
				//							c.weakenings = w;
				//						}
				//						c.weakenings = w.minus(newWeakenings);
				//					}
				//				}
				//				

				// Propagation is done: merge with existing weakenings
				this.weakenings = newWeakenings.merge(this.weakenings);

			}
		}
	}

	// Overrides

	@Override
	protected void unlink()
	{
		assert nr > 0;
		nr--;
				
		if (nr == 0)
		{
			// Unlink properties and subterms..
			UNLINK_LINK(weakenings);
			UNLINK_LINK(namedProperties);
			UNLINK_LINK(variableProperties);
			if (sub != null)
			{
				int a = sub.length - 1;
				for (; a >= 0; a--)
				{
					sub[a].unlink();
				}
			}
			
		}
	}

}
