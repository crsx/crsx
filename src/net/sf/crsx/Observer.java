/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx;

/**
 * An observer of CRS evaluation events.
 * 
 * @author Takahide Nogayama
 * @version $Id: Observer.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface Observer
{
	/**
	 * Receive update!
	 * @param observable from whom the update comes
	 * @param observedObjects that were updated
	 */
	public void update(Observable observable, Object[] observedObjects);
}
