/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /* ]] */;

import java.util.ArrayList;
import java.util.List;

/**
 * Term construction of the form $[C, Name, Args]
 * 
 * When used in a pattern, assumes the following constraint:
 * <pre>... $[C, .., #args] -> ... $[C, ..., #args]</pre> where #args occurs only within the 2 term constructions.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class TermConstructionExpr extends PropertyConstraintConstruction
{
	// Static

	/** Special kind of term */
	final private static int SEQUENCE_KIND = 3;

	// Constructors

	public TermConstructionExpr(PropertyConstraint[] constraints, Term... args)
	{
		super(constraints, args);
	}

	// Overrides

	@Override
	public boolean match(Term term, MatchingContext context)
	{
		// Match only constructions. 
		matchConstraints(term.getProperties(), context);

		if (term.getKind() == CONSTRUCTION_KIND)
		{
			if (args[1].match(
					Dictionary.SINGLETON.createConstructor(term.getSymbol(), term.getProperties(), (Variable[][]) null), context))
			{
				if (args.length >= 3)
					args[2].match(new Sequence(term.getArgs(), term.getBinders()), context);

				return true;
			}
		}
		return false;
	}

	@Override
	public Term contract(MatchingContext context)
	{
		// Evaluate properties
		Properties properties = contractConstraints(context);

		// Evaluate expressions
		Term c1 = args[1].contract(context);
		Term c2 = args[2].contract(context);

		// c1 should be a constant. 
		if (!Utils.isConstant(c1))
			throw new RuntimeException("First argument of the term construction ($[C, ...]) expression must be a constant");

		// Flatten
		List<Term> args = new ArrayList<Term>();
		List<Variable[]>  binders = new ArrayList<Variable[]>();
		final boolean hasSubbinders = flatten(c2, args, binders);
		
		Variable[][] subbinders = null;
		if (hasSubbinders)
		{
			subbinders = new Variable[binders.size()][];
			subbinders = binders.toArray(subbinders);
		}
		
		Term[] argsArray = new Term[args.size()];
		argsArray = args.toArray(argsArray);
		 
		return Dictionary.SINGLETON.createConstructor(c1.getSymbol(), properties, subbinders, argsArray);
	}

	// Helpers 

	/**
	 * Flatten the given term by eliminating $cons occurrences and the Sequence occurrence
	 * @return true when bindings bubbled up to the level of the constructed term.
	 *			In this case, <code>binders</code> contains those bindings
	 */
	private static boolean flatten(Term term, List<Term> args, List<Variable[]> binders)
	{
		if (Utils.isCons(term))
			return flatten((FunctionConstruction) term, args, binders);
		
		args.add(term);
		return false;
	}

	private static boolean flatten(FunctionConstruction cons, List<Term> args, List<Variable[]> binders)
	{
		boolean hasSubbinders = flatternArg(cons.args[0], args, binders, cons.subbinders == null ? null : cons.subbinders[0]);
		hasSubbinders |= flatternArg(cons.args[1], args, binders, cons.subbinders == null ? null : cons.subbinders[1]);
		return hasSubbinders;
	}

	private static boolean flatternArg(Term term, List<Term> args, List<Variable[]> binders, Variable[] subbinders)
	{
		if (Utils.isCons(term))
			return flatten((FunctionConstruction) term, args, binders);

		if (term.getKind() == SEQUENCE_KIND)
		{
			final Sequence sequence = (Sequence) term;
			final Term[] terms = sequence.terms;
			final Variable[][] bindings = sequence.bindings;
			boolean hasSubbinders = false;
			if (terms != null)
			{
				for (int i = 0; i < terms.length; i++)
				{
					if (!Utils.isNil(terms[i]))
					{
						args.add(terms[i]);
						binders.add(bindings == null ? null : bindings[i]);

						hasSubbinders |= (bindings != null && bindings[i] != null);
					}
				}
			}

			return hasSubbinders;
		}
		if (!Utils.isNil(term))
		{
			args.add(term);
			binders.add(subbinders);
			return subbinders != null;
		}
		return false;
	}

	 
	/** Represents a sequence of terms. */
	static public class Sequence extends Term
	{
		// State

		/** Term sequence */
		final protected Term[] terms;

		/** Bindings */
		final protected Variable[][] bindings;

		// Constructor

		public Sequence(Term[] terms, Variable[][] bindings)
		{
			this.terms = terms;
			this.bindings = bindings;
		}

		// Overrides

		@Override
		public boolean match(Term term, MatchingContext context)
		{
			throw new UnsupportedOperationException();
		}

		@Override
		public Term contract(MatchingContext context)
		{
			return this;
		}

		@Override
		public int getArity()
		{
			return terms.length;
		}

		@Override
		public int getKind()
		{
			return SEQUENCE_KIND;
		}

	}
}
