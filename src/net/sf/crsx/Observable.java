/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx;

/**
 * Object that can be observed by an {@link Observer}.
 * 
 * @author Takahide Nogayama
 * @version $Id: Observable.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Observable
{
	/**
	 * Add an observer.
	 */
	public void addObserver(Observer observer);

	/**
	 * Remove an observer.
	 */
	public void deleteObserver(Observer observer);

	/**
	 * Notify all observers.
	 */
	public void notifyObservers(Object[] observedObjects);
}
