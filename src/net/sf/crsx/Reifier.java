/* Copyright (c) 2012 IBM Corporation */
package net.sf.crsx;

import java.util.Map;

/**
 * Helper for reifying a term in a special way.
 */
public interface Reifier
{
	/**
	 * Send term representing this term using the sorts of reify.crs.
	 * @param sink to send to
	 * @param term the term to reify
	 * @param metaArgSort map every meta-variable argument to the required sort
	 * @param freeSort map every free variable to the required sort
	 * @param subReifiers with special instructions
	 * @return sink after it has received reified term
	 */
	Sink reify(Sink sink, Term term, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers);
}
