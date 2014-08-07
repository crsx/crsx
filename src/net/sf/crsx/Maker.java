/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx;

/**
 * Common interface of all components that can create basic building blocks of and with terms.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: Maker.java,v 3.1 2013/12/09 05:48:40 krisrose Exp $
 */
public interface Maker
{
	/**
	 * Create a constructor from the given object.
	 * What the object should be depends on the notion of term used;
	 * two conventions are supported by all implementations:
	 * <ul>
	 * <li>A simple String value creates a constructor "with that name".
	 * <li>A constructor (from the same or a compatible {@link Maker}) duplicates the constructor. 
	 * </ul>
	 * @param object with constructor configuration
	 * @throws ClassCastException if the object is not useful for making a constructor
	 * 		(this is implementation dependent)
	 */
	public Constructor makeConstructor(Object object);

	/**
	 * Create a literal constructor from the given object with the specified sort.
	 * The object can be
	 * <ul>
	 * <li>A simple String value creates a literal with that value.
	 * <li>A numeric value can be used to create a numeric literal.
	 * </ul>
	 * @param object with literal
	 * @param sort of literal
	 * @throws ClassCastException if the object is not useful for making a literal of such a sort
	 */
	public Constructor makeLiteral(Object object, String sort);
	
	/**
	 * Create a unique variable instance.
	 * @param name hint for use when assigning a name to the variable
	 * @param promiscuous whether the variable can be used more than once
     */
	public Variable makeVariable(String name, boolean promiscuous);

	/**
	 * Retrieve global free variable.
	 * @param name of variable
	 * @param promiscuous whether variable is permitted duplication
	 * @param create whether variable should be created if not there
	 */
	public Variable freeVariable(String name, boolean promiscuous, boolean create);
	
	/**
	 * Create a buffer ready to receive data.
	 * When the sink has received a full term (with optional binders prefix) then it
	 * will invoke {@link CallBack#finished(Variable[], Term)} of the passed callBack.
	 */
	public Sink makeBuffer(CallBack callBack);
	
	/** Created by buffer to permit changing buffer continuation sink from <code>null</code>. */
	public interface ContinuationSinkSetter
	{
		/** Invoke this method to change the sink returned when buffer full to the given continuation sink. */
		public void setContinuationSink(Sink continuation);
	}
	
	/** Should be created by user to capture the call-back action for one {@link Maker#makeBuffer(net.sf.crsx.Maker.CallBack)}. */
	public static abstract class CallBack {
		/**
		 * Call-back action invoked when buffer full just before the continuation sink is returned (by default null).
		 * @param binders top-level binders (for nested terms) - guaranteed unique by sink user
		 * @param term received through sink
		 * @param continuationSetter to set the continuation sink different from null
		 */
		public abstract void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter);
	}
}
