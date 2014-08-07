/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * Instances of this interface are used to consume a piece of a {@link Term}.
 * Every instance can be <em>used only once</em>.
 * Most methods return the instance to use for the next consumption operation.
 * <p>
 * The sequence of method calls (each on the previously returned instance) should obey the grammar
 * <blockquote>
 * <i>Term</i> ::= start(<i>symbol</i>) <i>Abstraction</i>* end()
 * 	| use(<i>variable</i>)
 * 	| startMetaApplication(<i>name</i>) <i>Term</i>* endMetaApplication()
 * <br>
 * <i>Abstraction</i> ::= ( bind(<i>variable</i>) )? <i>Term</i>
 * </blockquote>
 * The captured term will have all locally bound variables renamed.
 * <p>
 * Implementations <b>I</b> should implement a constructor of signature
 * <pre>
 * public <b>I</b>(Maker maker, Appendable appendable);
 * </pre>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Sink.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Sink extends Maker
{
	/** Constant empty array of variables. */
	public static final Variable[] NO_VARIABLES = {};
	
	/**
	 * Start construction subterm.
	 * @param constructor to use
	 * @return continuation sink to use for subsequent operation (never null)
	 */
	public Sink start(Constructor constructor);
	
	/**
	 * End of constructor subterm
	 * @return continuation sink to use for subsequent operation
	 *     - may return <b>null</b> if it does not make sense to send further events
	 */
	public Sink end();
	
	/**
	 * Insert binder wrapper around current construction subterm.
	 * @param binders to be bound here - <em>must</em> be fresh (not used in any existing terms) 
	 * @return continuation sink to use for subsequent operation (never null)
	 */
	public Sink binds(Variable[] binders);
	
	/**
	 * Insert variable occurrence subterm.
	 * @param variable to reference
	 * @return continuation sink to use for subsequent operation
	 *     - may return <b>null</b> if it does not make sense to send further events
	 */
	public Sink use(Variable variable);
	
	/**
	 * Start a meta-application subterm.
	 * @param name of meta-variable to use
	 * @return continuation sink to use for subsequent operation (never null)
	 */
	public Sink startMetaApplication(String name);
	
	/**
	 * End of previously started meta-application subterm.
	 * @return continuation sink to use for subsequent operation
	 *     - may return <b>null</b> if it does not make sense to send further events
	 */
	public Sink endMetaApplication();
	
	/**
	 * Equivalent to {@link Copyable#copy} with empty environment, which you should use instead! 
	 * Ship entire term represented by source to this sink.
	 * @param source of term to copy
	 * @param discard whether the source is needed again
	 * 		(if true then the {@link #stub(Sink, boolean))} is the last method invoked on this instance)
	 * @return continuation sink to use for subsequent operation
	 *     - may return <b>null</b> if it does not make sense to send further events
	 *  @deprecated
	 */
	public Sink copy(Copyable source, boolean discard);
}
