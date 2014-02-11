/* Copyright © 2008, 2009  IBM Corporation. */
package net.sf.crsx.run;

import java.io.Closeable;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Factory;
import net.sf.crsx.Observable;
import net.sf.crsx.Observer;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.antlr.CommonTokenFactory;
import net.sf.crsx.antlr.TreeAdaptorFactory;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.pg.PG;
import net.sf.crsx.util.DummyPausingObserver;
import net.sf.crsx.util.Util;


/**
 * Simple command line interface to do "CRS execution".
 * 
 * <h4>Usage</h4>
 * Crsx [<em>option</em>[=<em>value</em>]]...
 * 
 * <h4>Master options</h4>
 * The following options are interpreted directly by the CRSX command, and modify what other options are available.
 * In addition, all options as well as environment/system variables are placed in the internal environment for use by the rewrite rules.
 * For convenience, leading "-" characters are removed from options and omitted values default to 1;
 * environment variables with a leading "CRSX_" prefix are translated to the corresponding lower case options
 * (so "CRSX_VERBOSE_COMPILER" as well as "verbose-compiler" in the environment will set the verbose-compiler option);
 * and finally the command line can have options prefixed with "no-" to cancel options set in the environment
 * (so add no-verbose-compilerin the command line to cancel the previous option from the environment).
 * <dl>
 * 
 * <dt>factory=<em>class</em>
 * <dd>Instantiate <em>class</em> as the master {@link Factory}. (Defaults to using {@link net.sf.crsx.generic.GenericFactory}.)
 * <p>
 * 
 * <dt>antlr
 * <dd>Permits the use of ANTLR grammars that do not use <code>output=AST</code>.
 *		(Short for factory={@link net.sf.crsx.antlr.CommonTokenFactory}.)
 * <p>
 * 
 * <dt>antlr-tree
 * <dd>Permits the use of ANTLR grammars including ones using <code>output=AST</code>.
 * 		(Really short for factory={@link net.sf.crsx.antlr.TreeAdaptorFactory}.)
 * <p>
 * 
 * <dt>script=<em>script-name</em>
 * <dd>Use <em>script-name</em>, which can be a predefined name or a URL, as the master script instead of <em>default</em>.
 * <p>
 * 
 * <dt>script-category=<em>category</em>
 * <dd>In case the master script is written in a non-standard syntax the category that the parser should use to parse it can be specified.
 * 
 * </dl>
 * 
 * <h4>Default script options</h4>
 * 
 * The following options are supported by the default script,
 * i.e., should only be expected to work if the script=... option is <em>not</em> used.
 * <dl>
 * 
 * </dl>
 * 
 * <h4>Default factory option</h4>
 * 
 * The following options are supported by the default factory.
 * i.e., should only be expected to work if the script=... option is <em>not</em> used.
 * <dl>
 * 
 * <dt>grammar=<em>grammar-configuration</em>
 * <dd>Start processing with the specified grammars.  TODO: describe format.
 * <p>
 * 
 * <dt>rules=<em>url</em>
 * <dd>Get the CRS rules from <em>file</em>. 
 * <p>
 * 
 * <dt>rules-term=<em>term</em>
 * <dd>Get the CRS rules from <em>term</em>. 
 * <p>
 * 
 * <dt>input=<em>url</em>
 * <dd>Use the rules to normalize term stored in <em>file</em>. (Cannot be combined with term=...).
 * <p>
 * 
 * <dt>term=<em>term</em>
 * <dd>Use the rules to normalize <em>term</em>. (Cannot be combined with input=... below).
 * <p>
 * 
 * <dt>category=<em>category</em>
 * <dd>Use the non-terminal <em>category</em> for the root term.
 * 		As a special case, <em>category</em> can be the value <code>?xml</code>,
 * 		which parses the special XML format of {@link net.sf.crsx.util.SAXSink}.
 * <p>
 * 
 * <dt>verbose=<em>number</em>
 * <dd>Set the verbosity of normalization to <em>number</em>. (Default is 0.)
 * <p>
 * 
 * <dt>verbose-compiler=<em>number</em>
 * <dd>Set the verbosity of rule compilation to <em>number</em>. (Default is 0.)
 * <p>
 * 
 * <dt>embedded-parser=<em>class</em>
 * <dd>Use the <em>class</em> to parse embedded terms.
 * 
 * </dl>
 * 
 * 
 * 
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: Crsx.java,v 3.4 2014/01/06 03:11:35 krisrose Exp $
 */
public class Crsx
{
    /** Usage text. */
    final static String USAGE = "Usage: Crsx [script=file] [option[=value]x...";

	/** Option... */
	public final static String SCRIPT_OPTION = "script";
	/** Option... */
	public final static String SCRIPT_CATEGORY_OPTION = "script-category";
	/** Option... */
	public final static String FACTORY_OPTION = "factory";
	/** Option... */
	public final static String ANTLR_TREE_OPTION = "antlr-tree";
	/** Option... */
	public final static String ANTLR_OPTION = "antlr";
	/** The default script. */
    public final static String DEFAULT_SCRIPT = "run/default";
    /** Default script location. */
    public final static String DEFAULT_RESOURCE_PREFIX = "/net/sf/crsx";
    
    // State.
    
    /** The builder used. */
    private Builder builder;
    
    // Methods.
    
    /**
	 * @return the builder used
	 */
	public Builder builder()
	{
		return builder;
	}

	List<Observer> observers = new ArrayList<Observer>();;
	public void addObserver(Observer paramObserver) {
		observers.add(paramObserver);
	}
	
	/**
     * Helper to exit with error.
     * @param message to print
	 * @throws CRSException 
     */
    static void oops(String message, Exception e) throws CRSException
    {
    	if (e == null)
    		throw new CRSException(message);
    	else if (message == null || message.length() == 0)
    		throw (e instanceof CRSException ? (CRSException) e : new CRSException(e));
    	else
            throw new CRSException(message, e);
    }

    /**
     * Real main program.
     * @param args options and arguments
     * @throws CRSException 
     */
    public void realMain(String[] args) throws CRSException
    {
        if (args.length == 0)
        {
            System.out.println(USAGE);
            System.exit(0);
        }

        Map<String, String> environment = new HashMap<String, String>();

        // System properties.
        for (Map.Entry<Object, Object> e : System.getProperties().entrySet())
        	environment.put(e.getKey().toString(), e.getValue().toString());
        
        environment.put("version", CRS.VERSION);
// TODO: properties file.
//        ResourceBundle variables = ResourceBundle.getBundle("net.sf.crsx.properties", Locale.ROOT);
//        for (String key : variables.keySet())
//        	environment.put(key, variables.getString(key));

        // System context environment.
        for (final Map.Entry<String,String> e : System.getenv().entrySet())
        {
        	String key = e.getKey(), value = e.getValue();
        	if (key.startsWith("CRSX_"))
        		key = key.substring("CRSX_".length()).toLowerCase().replace('_', '-');
        	environment.put(key, value);
        }

        // Option arguments.
        int first; // first non-option
        for (first = 0; first < args.length; ++first)
        {
        	// Record option.
        	String option = args[first];
        	while (option.startsWith("-")) option = option.substring(1);
        	String value = "1";
        	int valueIndex = option.indexOf('=');
        	if (valueIndex >= 0)
        	{
        		value = option.substring(valueIndex+1);
        		option = option.substring(0, valueIndex);
            	environment.put(option, value);
        	}
        	else if (option.startsWith("no-"))
        	{
        		option = option.substring("no-".length());
            	environment.remove(option);
        	}
        	else
        	{
        		environment.put(option, value);
        	}
        }
        if (first != args.length)
        	oops("Non-option arguments?", null);

        realMain(environment);
    }

    /**
     * Real main program.
     * @param options map each option to the string value or "" when none given
     * @throws CRSException 
     */
    @SuppressWarnings("unchecked")
    public void realMain(Map<String, String> options) throws CRSException
    {
    	try
    	{
    		// Special option side effect...
    		@SuppressWarnings("rawtypes")
			Class<? extends Factory> factoryClass = GenericFactory.class;
    		if (options.containsKey(FACTORY_OPTION)) factoryClass = (Class<GenericFactory>) Class.forName(options.get(FACTORY_OPTION));
    		else if (options.containsKey(ANTLR_TREE_OPTION)) factoryClass = TreeAdaptorFactory.class;
    		else if (options.containsKey(ANTLR_OPTION)) factoryClass = CommonTokenFactory.class;

    		// Make sure the resource prefix and script are set.
    		if (!options.containsKey(Factory.RESOURCE_PREFIX))
    			options.put(Factory.RESOURCE_PREFIX, DEFAULT_RESOURCE_PREFIX);
    		if (!options.containsKey(SCRIPT_OPTION))
    			options.put(SCRIPT_OPTION, DEFAULT_SCRIPT);
    		
    		// Copy environment into factory.
    		GenericFactory factory = (GenericFactory) factoryClass.newInstance();
    		for (Map.Entry<String, String> e : options.entrySet())
    			factory.set(e.getKey(), factory.literal(e.getValue()));
    		
    		// Get the script.
    		String script = options.get(SCRIPT_OPTION);
    		String scriptCategory = options.get(SCRIPT_CATEGORY_OPTION);
    		Reader scriptReader = Util.resourceReader(factory, script);
    		Term directive = factory.parse(scriptReader, scriptCategory, script, 1, 1, null);

    		// Process the script.
    		if (builder == null) builder = factory.builder();

    		if (options.containsKey(Factory.TRACE_OPTION))
    			((Observable) builder).addObserver(new DummyPausingObserver());
    		if (observers.size() > 0) {
    			for(int i = 0; i < observers.size(); i++)
        			((Observable) builder).addObserver(observers.get(i));
    		}
    		
    		Sink after = builder.load(null, directive);
    		if (after instanceof Closeable)
	            try
                {
	                ((Closeable) after).close();
                }
                catch (IOException e1)
                {
	                
                }
    		System.out.println();
    	}
    	catch (IllegalAccessException e)
    	{
    		oops("Not permitted to instantiate factory - ", e);
    	}
    	/*
    	catch (ClassCastException e)
    	{
    		oops("Cannot instantiate factory - ", e);
    	}
    	*/
    	catch (InstantiationException e)
    	{
    		oops("Cannot instantiate factory - ", e);
    	}
    	catch (ClassNotFoundException e)
    	{
    		oops("Cannot instantiate factory - ", e);
    	}
    }

	/**
     * Make executable.
     * @param args from command line
     */
    public static void main(String[] args)
    {
    	try
		{
            if (args.length == 0)
            {
                System.out.println(USAGE);
                System.exit(0);
            }
            String[] newArgs = new String[args.length];
            System.arraycopy(args, 1, newArgs, 0, args.length-1);
            if ("PG".equals(args[0]))
            	PG.main(newArgs);
            else if ("CRSX".equals(args[0]))
    			new Crsx().realMain(newArgs);
            else
            	new Crsx().realMain(args);
		}
		catch (CRSException e)
		{
			System.err.println(e.getMessage());
			System.exit(1);
		}
    }
}
