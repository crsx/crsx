/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Data construction occurring in the contractum
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ContractumConstruction extends Construction
{
	// State

	/** Construction unique ID.*/
	final protected int id;

	/** Reusable binders position in {@link MatchingContext}. */
	final protected int[][] reused;

	/** Properties */
	final protected PropertyConstraint[] constraints;

	// Constructors

	protected ContractumConstruction(int id, int[][] reused, PropertyConstraint[] constraints, Term... args)
	{
		super(args);

		this.id = id;
		this.reused = reused;
		this.constraints = constraints;
	}

	// Overrides

	@Override
	public String getSymbol()
	{
		return Dictionary.SINGLETON.getName(id);
	}

	@Override
	public boolean match(Term term, MatchingContext context)
	{
		throw new AssertionError("Not a pattern");
	}

	@Override
	public Term contract(MatchingContext context)
	{
		// First: process binders.
		Variable[][] subbinders = null;
		if (reused != null)
		{
			subbinders = new Variable[reused.length][];
			for (int i = 0; i < reused.length; i++)
			{ 
				if (reused[i] != null)
				{
					final int length = reused[i].length;
					subbinders[i] = new Variable[length];
					for (int j = 0; j < length; j++)
					{
						int position = reused[i][j];
						if ((position & 0x1000) != 0) // This is a new subbinding
						{
							subbinders[i][j] = new Variable(null);
							context.setVarSubstitute(position & 0xFFF, subbinders[i][j]);
						}
						else
							subbinders[i][j] = context.getVarSubstitute(position);

					}
				}
				else
					subbinders[i] = null;
			}
		}

		// Then: contract arguments 
		Term[] contractedArgs = null;
		if (args != null)
		{
			contractedArgs = new Term[args.length];

			for (int i = 0; i < args.length; i++)
				contractedArgs[i] = GeneratedCRSX.dispatch(args[i].contract(context));
		}

		// Then: contract properties
		Properties properties = null;
		if (constraints != null)
		{
			properties = new Properties();
			for (int i = 0; i < constraints.length; i++)
				constraints[i].contract(properties, context);
		}

		// TODO: inline dispatch

		return Dictionary.SINGLETON.createConstructor(id, properties, subbinders, contractedArgs);
	}

}
