package net.sf.crsx;

public interface ErrorHandler
{
	/**
	 * Report an error from which we cannot recover (and never returns),
	 * as well as all previous errors from which we could recover.
	 * @param message to report
	 * @param pretext a string indicating the text that should be printed in
	 *   front of the error message; if not given, this defaults to "Error: " 
	 * @throws CRSException a fatal error is thrown as an exception
	 */
	public void fatal(String message, String... pretext) throws CRSException;
	
	/**
	 * Report error from which we can recover (if the method returns).
	 * @param message to report
	 * @param pretext a string indicating the text that should be printed in
	 *   front of the error message; if not given, this defaults to "Error: "
	 * @throws CRSException if the CRS is set up to consider all errors as
	 * 	 fatal
	 */
	public void error(String message, String... pretext) throws CRSException;
	
	/**
	 * Report a warning which should be printed, but which does not prevent
	 * further methods like normalization or sortification.
	 * @param message to report
	 * @param pretext a string indicating the text that should be printed in
	 *   from of the warning message; if not given, this defaults to "Warning: "
	 */
	public void warning(String message, String... pretext);
	
	/**
	 * If {@link #error(String)} was ever called then this method invokes
	 * {@link #fatal(String)}.
	 * @param message
	 * @throws CRSException
	 */
	public void errorCheck(String message) throws CRSException;
}
