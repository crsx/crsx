/* Copyright © 2007, 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * Valuation is the result of a successful match of a rule, ready to contract.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Valuation.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Valuation
{
	/** The name of the match that succeeded (for tracing, etc.). */
	String name();

	/** Get the substitute matched by a particular meta-variable. */
	Substitute getSubstitute(String metaVariable);

    /** Get the variable in redex that has been prematched by a particular variable in contractum. */
    Variable getVariable(Variable variable);

	/**
	 * Contract! 
	 * @param sink to send contraction to.
	 */
	Sink contract(Sink sink);

	/** Hint to the rewrite engine that the contraction should not be searched for redexes right away. */
	boolean leave();
	
	/**
	 * Static contract.  
	 * @param sink to send static contraction to.
	 */
	Sink staticContract(Sink sink);
	
}
