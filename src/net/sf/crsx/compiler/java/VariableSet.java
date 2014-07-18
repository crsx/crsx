
package net.sf.crsx.compiler.java;

import static net.sf.crsx.compiler.java.Term.ARITY;
import static net.sf.crsx.compiler.java.Term.BINDER;
import static net.sf.crsx.compiler.java.Term.IS_VARIABLE_USE;
import static net.sf.crsx.compiler.java.Term.RANK;
import static net.sf.crsx.compiler.java.Term.SUB;
import static net.sf.crsx.compiler.java.Term.VARIABLE;
import static net.sf.crsx.compiler.java.Term.c_variableProperty;

/**
 * Variable set.
 * 
 * <p>See Crsx.c VariableSet section
 * 
 * @author villardl
 */
public class VariableSet
{
	// Static

	final public static VariableSet makeVariableSet()
	{
		return new VariableSet();

	}

	final public static boolean containsVariable(VariableSet set, Variable variable)
	{
		return (set == null || VariableSetLink.variableSetLinkFor(set.link, variable) == null) ? false : true;
	}


	final public static boolean addVariable(VariableSet set, Variable variable)
	{
		assert variable.name != null;
		
		VariableSetLink link;
		for (link = set.link; link != null; link = link.link)
			if (link.variable == variable)
				return false;
		
		link = new VariableSetLink();
		link.variable = variable;
		link.link = set.link;
		set.link = link;
		return true;
	}

	final public static void addVariables(VariableSet set, VariableSetLink link)
	{
		for (; link != null; link = link.link)
			addVariable(set, link.variable);
	}

	final public static VariableSet makeFreeVariableSet(Term term, SortDescriptor sort, boolean constrained, VariablePropertyLink props)
	{
		VariableSet free = makeVariableSet();
		makeFreeVariableSet2(free, term, sort, constrained, props, (VariableSetLink) null);
		Term.UNLINK(term);
		return free;
	}

	final public static void freeVariableSet(VariableSet set)
	{
		// noop
	}

	void freeVariableSetLinks(VariableSetLink link)
	{
		// noop
	}

	// Internal: does NOT free the term.
	final private static void makeFreeVariableSet2(VariableSet free, Term term, SortDescriptor sort, boolean constrained, VariablePropertyLink props, VariableSetLink boundLink)
	{
		if (term != null)
		{
			if (IS_VARIABLE_USE(term))
			{
				Variable v = VARIABLE(term);
				if (VariableSetLink.variableSetLinkFor(boundLink, v) == null && !containsVariable(free, v))
					if (!constrained || c_variableProperty(props, v) != null)
						addVariable(free, v);
			}
			else
			{
				final int arity = ARITY(term);
				int i = 0;
				for (; i < arity; ++i)
				{
					VariableSetLink subBoundLink = boundLink;
					int j, rank = RANK(term, i);
					for (j = 0; j < rank; ++j)
					{
						VariableSetLink newLink = new VariableSetLink();
						newLink.variable = BINDER(term, i, j);
						newLink.link = subBoundLink;
						subBoundLink = newLink;
					}
					makeFreeVariableSet2(free, SUB(term, i), sort, constrained, props, subBoundLink);
					//for (j = 0; j < rank; ++j)
					//{
						//VariableSetLink oldLink = subBoundLink;
					//	subBoundLink = subBoundLink.link;
						//FREE(oldLink);
					//}
				}
				{
					NamedPropertyLink nlink = ((Construction) term).namedProperties;
					for (; nlink != null; nlink = nlink.link)
						if (nlink.name != null)
							makeFreeVariableSet2(free, nlink.term(), sort, constrained, props, boundLink);
				}
				{
					VariablePropertyLink vlink = ((Construction) term).variableProperties;
					for (; vlink != null; vlink = vlink.link)
						if (vlink.variable != null)
							makeFreeVariableSet2(free, vlink.term(), sort, constrained, props, boundLink);
				}
			}
		}
	}

	// State

	/** Next variable */
	public VariableSetLink link;

}
