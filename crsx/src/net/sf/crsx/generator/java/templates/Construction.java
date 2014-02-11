/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Base class for construction
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public abstract class Construction extends Term
{
	// State

	/** Arguments */
	protected final Term[] args;

	// Constructors 

	/** Constructs a construction to be used in any places (term ,pattern, contractum) */
	protected Construction(Term... args)
	{
		this.args = (args == null || args.length == 0) ? null : args;
	}

	// Methods

	/** 
	 * Normalize arguments 
	 */
	protected void normalizeArgs(Rule[] rules)
	{
		// Be conservative: normalize all arguments.
		if (args != null)
			for (int i = 0; i < args.length; i++)
				args[i] = args[i].normalize(rules);
	}

	// Overrides

	@Override
	final public int getKind()
	{
		return CONSTRUCTION_KIND;
	}

	@Override
	final public int getArity()
	{
		return args == null ? 0 : args.length;
	}

	@Override
	final public Term[] getArgs()
	{
		return args;
	}

	// Debugging

	public String toString()
	{
		return getSymbol();
	}

}
