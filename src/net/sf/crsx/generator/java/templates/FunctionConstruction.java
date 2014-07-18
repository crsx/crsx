/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Construction that can only occurs in term-to-rewrite
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class FunctionConstruction extends TermConstruction
{
	// Constructors

	/** 
	 * Constructs a term 
	 * @param Properties 
	 */
	protected FunctionConstruction(int id, Properties properties, Variable[][] subbinders, Term... args)
	{
		super(id, properties, subbinders, args);
	}

	// Overrides

	@Override
	public void normalize(Rule[] rules, NativeSink sink)
	{
		if (rules.length > id && rules[id] != null) // TODO: eliminate
		{
			final Rule rule = rules[id];

			normalizeArgs(rules);

			MatchingContext context = new MatchingContext(); // TODO: use a stack instead.

			if (rule.getPattern().match(this, context))
				GeneratedCRSX.dispatch(rule.getContractum().contract(context)).normalize(
						rules, sink);
			else
				normalizeSubs(rules, sink);
		}
		else
			normalizeSubs(rules, sink);
	}

	@Override
	protected void normalizeSubs(Rule[] rules, NativeSink sink)
	{
		sink.start(id);

		if (args != null)
			for (int i = 0; i < args.length; i++)
			{
				if (subbinders != null && subbinders[i] != null)
					sink.binds(subbinders[i]);

				args[i].normalize(rules, sink);
			}

		sink.end(id);
	}

	@Override
	public Term normalize(Rule[] rules)
	{
		if (rules.length > id && rules[id] != null) // TODO: eliminate
		{
			normalizeArgs(rules);

			final Rule rule = rules[id];
			MatchingContext context = new MatchingContext(); // TODO: use a stack instead.

			if (rule.getPattern().match(this, context))
				return GeneratedCRSX.dispatch(rule.getContractum().contract(context)).normalize(
						rules);
		}

		return super.normalize(rules);
	}

}
