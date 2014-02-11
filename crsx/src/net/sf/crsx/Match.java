/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

import net.sf.crsx.util.ExtensibleMap;

/**
 * Match in progress.
 * Maps matched meta-variable names to {@link Substitute}s, and matched free variables.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Match.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Match extends Cloneable
{
	/**
	 * Return the substitute mapping for single meta-variable.
	 * @param metaVariable to substitute
	 * @return variable to rename it to, or null if none
	 */
	Substitute getSubstitute(String metaVariable);

	/**
	 * Add new substitute match.
	 * @param name of meta-variable that maps to substitute
	 * @param binders of substitute (variables from redex)
	 * @param term with part of redex matching the meta-application
	 */
	void putSubstitute(String name, Variable[] binders, Term term);

	/** Add new substitute match with preconstructed substitute. */
	void putSubstitute(String name, Substitute substitute);

	/**
	 * Look up variable mapping.
	 * @param variable to look up (variable from pattern and contractum)
	 * @return variable it maps to (in redex) or null if none
	 */
	Variable getVariable(Variable variable);

	/**
	 * Add free variable mapping.
	 * @param from of map (variable in pattern and/or contractum)
	 * @param to of map (variable  in redex)
	 */
	void putVariable(Variable from, Variable to);

	/** Return the free variable mappings as an extensible map (from variables in pattern and contractum to variables in redex). */
	ExtensibleMap<Variable,Variable> renamings();

	/** Create a clone of the match that is independent in the future. */
    Match clone();
}
