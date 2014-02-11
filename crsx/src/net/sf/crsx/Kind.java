/* Copyright © 2007, 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * Kinds of CRS terms as returned by {@link Stub#kind()}.
 *
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Kind.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public enum Kind
{
	/** Term is construction. */
	CONSTRUCTION,
	/** Term is a variable occurrence. */
	VARIABLE_USE,
	/** Term is a meta-application. */
	META_APPLICATION
}
