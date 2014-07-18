/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Meta application where some variable might need to be substituted
 * 
 * Can occur only in contractum.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class MetaApplicationSubst extends MetaApplicationReuse
{
	// State
 
	/** Variable-to-substitute positions in {@link MatchingContext} */
	final int[] varsPosition;

	/** Term to substitute with */
	final Term[] substs;

	// Constructors

	protected MetaApplicationSubst(int position, int[] varsPosition, Term[] substs)
	{
		this(position, null, varsPosition, substs);
	}

	protected MetaApplicationSubst(int position, PropertyConstraint[] constraints, int[] varsPosition, Term[] substs)
	{
		super(position, constraints);
 
		this.substs = substs;
		this.varsPosition = varsPosition;
	}

	// Overrides

	@Override
	public Term contract(MatchingContext context)
	{
		// Contract substitutes and get variable to substitute
		final Term[] contracted = new Term[substs.length];
		final Variable[] substVars = new Variable[substs.length];
		for (int i = 0; i < substs.length; i++)
		{
			contracted[i] = substs[i].contract(context);
			substVars[i] = context.getVarSubstitute(varsPosition[i]);
		}
		 
		
		// Substitute
		return substitute(context.getSubstitute(position), substVars, contracted);
		
	}

	// Helper
	
	/** 
	 * Substitutes variable uses 
	 * @param substVars which variable to substitute
	 * @param substitutes 
	 * 
	 */
	private Term substitute(Term term, Variable[] substVars, Term[] substitutes)
	{
		if (term.getKind() == Term.VARIABLE_KIND)
		{
			final Term subst = getSubstitute(((VariableUse)term).var, substVars, substitutes);
			if (subst != null)
				return subst;
		
			return term;
		} 
		
		// Recursively substitute
		final int arity = term.getArity();
		final Term[] args =  term.getArgs();
		for (int i = 0; i < arity; i ++)
			args[i] = substitute(term.getArgs()[i], substVars, substitutes);
		
		return term;
	}

	private Term getSubstitute(Variable variable, Variable[] substVars, Term[] substitutes)
	{
		for (int i = 0; i < substVars.length; i ++)
		{
			if (variable == substVars[i])
				return substitutes[i];
		}
		return null;
		
	}
}
