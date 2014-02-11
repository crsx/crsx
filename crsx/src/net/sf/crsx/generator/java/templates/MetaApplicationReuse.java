/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

/**
 * Meta application where all variables can be reused.
 * 
 * Can occur only in pattern or contractum.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class MetaApplicationReuse extends Term
{
	// State

	/** Meta variable position in the pattern or contractum */
	final protected int position;

	/** Property constraints */
	final protected PropertyConstraint[] constraints;

	// Constructors

	protected MetaApplicationReuse(int position)
	{
		this(position, null);
	}

	protected MetaApplicationReuse(int position, PropertyConstraint[] properties)
	{
		super();
		this.position = position;
		this.constraints = properties;
	}

	// Overrides

	@Override
	public int getKind()
	{
		return META_APP_KIND;
	}

	@Override
	public int getArity()
	{
		return 0;
	}

	@Override
	protected void normalizeSubs(Rule[] rules, NativeSink sink)
	{
		throw new AssertionError("Not a term to rewrite");
	}

	@Override
	public void normalize(Rule[] rules, NativeSink sink)
	{
		throw new AssertionError("Not a term to rewrite");
	}

	@Override
	public boolean match(Term term, MatchingContext context)
	{
		if (constraints != null)
		{
			for (int i = 0; i < constraints.length; i++)
				if (!constraints[i].match(term.getProperties(), context))
					return false;
		}

		context.setSubstitute(position, term);
		return true;
	}

	@Override
	public Term contract(MatchingContext context)
	{
		final Term term = context.getSubstitute(position);

		if (constraints != null)
		{
			Properties properties = term.getProperties();
			if (properties == null)
				properties = new Properties();
			
			for (int i = 0; i < constraints.length; i++)
				constraints[i].contract(properties, context);

			term.setProperties(properties);
		}
		
		return term;
	}
}
