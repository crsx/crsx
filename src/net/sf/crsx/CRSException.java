/* Copyright © 2006, 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * Exception for reporting CRS errors.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: CRSException.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public class CRSException extends Exception
{
	/** Sic. */
	private static final long serialVersionUID = -8898481920498428986L;

	/** Create one. */
	public CRSException(String message)
	{
		super(message);
	}
	
	/** Create one. */
	public CRSException(Exception exception)
	{
		super(exception);
	}
	
	/** Create one. */
	public CRSException(String message, Exception exception)
	{
		super(message, exception);
	}
}
