/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates /*]]*/;

/**
 * Property constraints of the form var: term
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 *
 */
public class VarTermProperty extends PropertyConstraint
{
	// State

	/** Variable position in {@link MatchingContext} */
	final protected int varPosition;

	/** Pattern to match or contractum */
	final protected Term patternOrContractum;

	/** Is this a free variable? */
	final protected boolean free;
	
	// Constructors

	public VarTermProperty(int varPosition, boolean free, Term patternOrContractum)
	{
		this.varPosition = varPosition;
		this.patternOrContractum = patternOrContractum;
		this.free = free;
	}

	// Overrides

	@Override
	public boolean match(Properties properties, MatchingContext context)
	{
		final Term term = properties.getVariableProperty(context.getVarSubstitute(varPosition));
		return term != null && patternOrContractum.match(term, context);
	}

	/**
	 * Add a variable property 
	 */
	@Override
	public void contract(Properties properties, MatchingContext context)
	{
		Variable var;
		if (free)
		{
			var = new Variable(null);
			context.setVarSubstitute(varPosition, var);
		}
		else
			var = context.getVarSubstitute(varPosition);
		
		properties.setVariableProperty(var, patternOrContractum.contract(context));
	}

}
