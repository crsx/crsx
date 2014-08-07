/* Copyright (c) 2011,2012 IBM Corporation. */

package net.sf.crsx.analysis;

import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.generic.GenericTerm;
import net.sf.crsx.util.Util;

/**
 * Determines the unification of two given sorts.
 * Used by the sorter, but also for instance to ensure that, when a
 * constructor is defined with multiple sort declarations, these sort
 * declarations are actually disjunct.
 * <p>
 * In these functions, we work with a non-recursive sort substitution
 * (usually named theta) by considering theta^omega, that is, the
 * composition theta^n where n is sufficiently large that the range
 * of theta^n does not contain any type variables in its domain.
 * Since theta is non-recursive, and has finite domain, such n can
 * always be found.
 * <p>
 * Since we are always considering sorts, we do not consider property
 * sets, and constructor equality only considers string equality.
 * 
 * @author Cynthia Kop
 */
public class Unifier
{
	/**
	 * Given a sort, a sort variable and a sort substitution, returns
	 * whether sort theta^omega contains the given sort variable.
	 * This is needed to ensure that adding [x:=sort] to the sort
	 * substitution does not cause recursion.
	 * @param sort a sort to be checked
	 * @param x the type variable whose occurrence is tested for
	 * @param theta a non-recursive type substitution
	 * @return true if there is some n such that sort theta^n contains
	 *   x, false otherwise; if theta is not non-recursive, then the
	 *   function may loop indefinitely instead
	 * @throws CRSException if the given sort is not a valid sort
	 */
	static private boolean contains(Term sort, Variable x, Map<Variable, Term> theta) throws CRSException
	{
		if (sort.kind() == Kind.VARIABLE_USE)
		{
			Variable y = sort.variable();
			if (theta.containsKey(y))
				return contains(theta.get(y), x, theta);
			else
				return x == y;
		}
		else
		//if (sort.kind() == Kind.CONSTRUCTION) //Kris
		{
			for (int i = 0; i < sort.arity(); i++)
				if (contains(subSort(sort, i), x, theta))
					return true;
			return false;
		}
		//else throw new CRSException("Illegal sort " + sort);
	}

	/**
	 * Given a form F[&rho;0,...,&rho;n] where &rho;_index = x1...xn.s, returns s
	 */
	public static Term subSort(Term form, int index)
	{
		Term f = form.sub(index);
		return f.kind() == Kind.CONSTRUCTION && Factory.SORT_VAR.equals(Util.symbol(f)) ? f.sub(0) : f;
	}

	/**
	 * Given a sort and sort substitution, determines the term obtained by applying theta to sort (just once).
	 * @param sort the sort to apply the substitution on (including variable properties sortings)
	 * @param theta the sort substitution to be applied
	 * @param factory used to form copies
	 * @return A proper copy of sort, with theta applied on it (and ignoring property sets)
	 * @throws CRSException if bad inconsistency in sort
	 */
	static public GenericTerm apply(Term sort, Map<Variable, Term> theta, GenericFactory factory) throws CRSException
	{
		if (sort.kind() == Kind.VARIABLE_USE)
		{
			Variable x = sort.variable();
			if (theta.containsKey(x))
				return (GenericTerm) theta.get(x).copy(false, null);
			else
				return factory.newVariableUse(x);
		}
		else
		{
			String s = Util.symbol(sort);
			GenericTerm[] subterms = new GenericTerm[sort.arity()];
			for (int i = 0; i < sort.arity(); i++)
			{
				GenericTerm child = apply(subSort(sort, i), theta, factory);
				if (child == null)
					return null;
				subterms[i] = child;
			}
			Constructor c = factory.makeConstructor(s);
			for (Variable p : c.propertyVariables())
				if (theta.containsKey(p) && theta.get(p).kind() == Kind.VARIABLE_USE)
				{
					Term pSort = c.getProperty(p);
					c.setProperty(p, null);
					c.setProperty(theta.get(p).variable(), pSort);
				}
			return factory.newConstruction(c, null, subterms);
		}
	}

	/**
	 * Given a sort and sort substitution, determines the repeated
	 * application from the sort substitution to the sort.
	 * If theta is not non-recursive, then this may loop indefinitely.
	 * @param sort a sort to be substituted
	 * @param theta a type substitution
	 * @return sort theta^omega, or NULL if sort is not a legal sort
	 * @param factory the factory to build the resulting term
	 * @throws CRSException if the given sort is not a valid sort
	 */
	static public GenericTerm repeat_apply(Term sort, Map<Variable, Term> theta, GenericFactory factory) throws CRSException
	{
		if (sort == null)
			return factory.nil();
		
		if (sort.kind() == Kind.VARIABLE_USE)
		{
			Variable x = sort.variable();
			if (theta.containsKey(x))
				return repeat_apply(theta.get(x), theta, factory);
			else
				return factory.newVariableUse(x);
		}
		else
		//if (sort.kind() == Kind.CONSTRUCTION) //Kris
		{
			String c = Util.symbol(sort);
			GenericTerm[] subterms = new GenericTerm[sort.arity()];
			for (int i = 0; i < sort.arity(); i++)
			{
				GenericTerm child = repeat_apply(subSort(sort, i), theta, factory);
				if (child == null)
					return null;
				subterms[i] = child;
			}
			return factory.newForm(c, subterms);
		}
		//else throw new CRSException("Illegal sort " + sort);
	}

	/**
	 * Given two sorts and a type substitution, checks whether sort1 theta^omega
	 * and sort2 theta^omega are unifiable.  If they are, theta is updated in
	 * such a way that sort1 theta^omega = sort2 theta^omega is the principal
	 * unification of sort1 and sort2
	 * @param sort1 a sort to be unified
	 * @param sort2 a sort to be unified
	 * @param theta a type substitution, which may initially contain some
	 *   substitutions, or just be empty
	 * @param factory TODO
	 * @return TRUE if sort1 and sort2 can be unified, FALSE if not; if theta
	 *   is not non-recursive, then the method may loop instead
	 * @throws CRSException if either of the given sorts is not a valid sort
	 */
	static public boolean unify_help(Term sort1, Term sort2, Map<Variable, Term> theta, GenericFactory factory) throws CRSException
	{
		if (sort1 == null || sort2 == null)
		{
//			factory.warning("bad karma: unify_help with null sort ("+sort1+" vs "+sort2+")");
			return false; // defensive
		}

		// Resolve aliases.
		if (sort1.arity() == 0 && sort1.kind() == Kind.CONSTRUCTION)
			sort1 = factory.newConstruction(factory.makeConstructor(factory.unalias(Util.symbol(sort1))), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
		if (sort2.arity() == 0 && sort2.kind() == Kind.CONSTRUCTION)
			sort2 = factory.newConstruction(factory.makeConstructor(factory.unalias(Util.symbol(sort2))), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);

		if (sort1.kind() == Kind.VARIABLE_USE)
		{
			Variable x = sort1.variable();
			if (sort2.kind() == Kind.VARIABLE_USE && x == sort2.variable())
				return true;
			if (theta.containsKey(x))
				return unify_help(theta.get(x), sort2, theta, factory);
			while (sort2.kind() == Kind.VARIABLE_USE && theta.containsKey(sort2.variable()))
				sort2 = theta.get(sort2.variable());
			if (sort2.kind() == Kind.VARIABLE_USE && x == sort2.variable())
				return true;
			if (contains(sort2, x, theta))
				return false;
			theta.put(x, sort2);
			return true;
		}

		if (sort2 != null && sort2.kind() == Kind.VARIABLE_USE)
		{
			Variable y = sort2.variable();
			if (theta.containsKey(y))
				return unify_help(sort1, theta.get(y), theta, factory);
			if (contains(sort1, y, theta))
				return false;
			theta.put(y, sort1); // unify the unbound sort variable
			return true;
		}

		/*//Kris
		if (sort1.kind() != Kind.CONSTRUCTION)
			throw new CRSException("Illegal sort: " + sort1);
		if (sort2.kind() != Kind.CONSTRUCTION)
			throw new CRSException("Illegal sort: " + sort2);
			*/

		if (!Util.symbol(sort1).equals(Util.symbol(sort2)))
		{
			sort1 = factory.renameSortConstructors(sort1);
			sort2 = factory.renameSortConstructors(sort2);
		}
		if (!Util.symbol(sort1).equals(Util.symbol(sort2)))
			return false;
		if (sort1.arity() != sort2.arity())
			return false;
		for (int i = 0; i < sort1.arity(); i++)
			if (!unify_help(subSort(sort1, i), subSort(sort2, i), theta, factory))
				return false;
		return true;
	}

	/**
	 * Returns the unification of any two given sorts, or null if they
	 * cannot be unified.
	 * @param sort1 a sort
	 * @param sort2 a sort
	 * @return null if the sorts cannot be unified, or their unification
	 *   (a proper copy, which does not depend on the sorti) if they can be
	 * @param factory the factory to build the resulting term
	 * @throws CRSException if either of the given sorts is not a valid sort
	 */
	static public GenericTerm unify(Term sort1, Term sort2, GenericFactory factory) throws CRSException
	{
		Map<Variable, Term> theta = new HashMap<Variable, Term>();
		if (!unify_help(sort1, sort2, theta, factory))
			return null;
		else
			return repeat_apply(sort1, theta, factory);
	}

	/**
	 * Returns whether it is possible to unify the given two sorts.
	 * @param factory TODO
	 * @return true if the sorts can be unified, false if not.
	 * @throws CRSException if either sort1 or sort2 is not really a sort
	 */
	static public boolean unifiable(Term sort1, Term sort2, GenericFactory factory) throws CRSException
	{
		Map<Variable, Term> theta = new HashMap<Variable, Term>();
		return unify_help(sort1, sort2, theta, factory);
	}

	/**
	 * returns whether sort1 is an instantiation of sort2 with some sort
	 * substitution theta; the given substitution theta is adapted to hold
	 * the required substitution if true is returned
	 * @param sort1 more specific sort
	 * @param sort2 less specific sort
	 * @param theta an originally empty sort substitution, which will contain
	 *   the required sort substitution if true is returned
	 * @param factory with sort alias information
	 * @return true if sort1 instantiates sort2, false otherwise
	 * @throws CRSException if either sort1 or sort2 is not really a sort
	 */
	static public boolean instantiates(Term sort1, Term sort2, Map<Variable, Term> theta, GenericFactory factory) throws CRSException
	{
		// Resolve aliases.
		if (sort1.arity() == 0 && sort1.kind() == Kind.CONSTRUCTION)
			sort1 = factory.newConstruction(factory.makeConstructor(factory.unalias(Util.symbol(sort1))), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
		if (sort2.arity() == 0 && sort2.kind() == Kind.CONSTRUCTION)
			sort2 = factory.newConstruction(factory.makeConstructor(factory.unalias(Util.symbol(sort2))), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);

		// Follow Theta.
		if (sort2.kind() == Kind.VARIABLE_USE)
		{
			Variable x = sort2.variable();
			if (theta.containsKey(x))
				return sort1.equals(theta.get(x));
			theta.put(x, sort1);
			return true;
		}
		else
		//if (sort2.kind() == Kind.CONSTRUCTION) //Kris
		{
			if (sort1.kind() != Kind.CONSTRUCTION)
				return false;
			if (sort1.arity() != sort2.arity())
				return false;
			if (!Util.symbol(sort1).equals(Util.symbol(sort2)))
				return false;
			for (int i = 0; i < sort1.arity(); i++)
			{
				if (!instantiates(subSort(sort1, i), subSort(sort2, i), theta, factory))
					return false;
			}
			return true;
		}
		//else throw new CRSException("Illegal form: " + sort2);
	}

	/**
	 * Returns whether two given sorts are equal.
	 * Different from sort1.equals(sort2) because property sets are ignored
	 * (so you can use this for the sort used in a form like F[x.{x:Nat}Bool],
	 * and obtain that {x:Nat}Bool is equal to Bool).
	 * @param factory for sort information
	 */
	static public boolean equalSorts(GenericFactory factory, Term sort1, Term sort2)
	{
		if (sort1 == null || sort2 == null)
			return false;
		if (sort1.kind() != sort2.kind())
			return false;
		if (sort1.kind() == Kind.VARIABLE_USE)
			return sort1.variable() == sort2.variable();
		if (sort1.kind() == Kind.CONSTRUCTION)
		{
			if (!factory.unalias(Util.symbol(sort1)).equals(factory.unalias(Util.symbol(sort2))))
				return false;
			if (sort1.arity() != sort2.arity())
				return false;
			for (int i = 0; i < sort1.arity(); i++)
				if (!equalSorts(factory, subSort(sort1, i), subSort(sort2, i)))
					return false;
			return true;
		}
		return false; // shouldn't happen
	}
}
