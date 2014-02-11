/* Copyright © 2007, 2008 IBM Corporation. */

package net.sf.crsx;

import net.sf.crsx.util.ExtensibleMap;

/**
 * Aspects of CRS term that permits investigation of the root term as well as copying of the entire term.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Stub.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Stub extends Copyable
{
	/** Get the maker for creating term artifacts. */
	Maker maker();
	
	/**
	 * The kind of the root of the contents.
	 * <ul>
	 * <li>{@link Kind#VARIABLE_USE} for variable occurrence terms,
	 * <li>{@link Kind#CONSTRUCTION} for construction terms, or
	 * <li>{@link Kind#META_APPLICATION} for meta-application terms.
	 * </ul>
	 */
	Kind kind();
	
	/**
	 * The constructor of the first term to be sent if it is a construction, null otherwise.
	 * @see #kind()
	 */
	Constructor constructor();
	
	/**
	 * The variable of the first term to be sent if it is a variable occurrence, null otherwise.
	 * @see #kind()
	 */
	Variable variable();

	/**
	 * The name of the meta-variable of the first term to be sent if it is a meta-application, null otherwise.
	 * @see #kind()
	 */
	String metaVariable();
	
	/**
	 * The arity (number of subterms) of constructor and meta-application terms.
	 * Always 0 for variable occurrence terms.
	 */
	int arity();
	
	/**
	 * Return a fresh, fully materialized copy of term built from the content of the stub.
	 * @param discard whether this stub instance will not be used any further
	 * @param renames of variables bound in the context (null means none)
	 */
	Term copy(boolean discard, ExtensibleMap<Variable, Variable> renames);
}
