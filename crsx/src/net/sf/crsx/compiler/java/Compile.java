// Copyright (c) 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import java.io.Closeable;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.net.URI;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.tools.JavaCompiler;
import javax.tools.SimpleJavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

import net.sf.crsx.Builder;
import net.sf.crsx.CRSException;
import net.sf.crsx.Factory;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.antlr.CommonTokenFactory;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.run.Crsx;
import net.sf.crsx.text.TextSink;
import net.sf.crsx.util.Util;

/**
 * Compile CRSX rule to Java code
 * @author villardl
 */
public class Compile
{
	// Constants

	final private static HashMap<String, String> REIFIED_OPTIONS = new HashMap<String, String>();
	final private static HashMap<String, String> TEXT_OPTIONS = new HashMap<String, String>();

	static
	{
		// TODO: Should really have this on the command line!
		
		REIFIED_OPTIONS.put(Factory.RESOURCE_PREFIX, Crsx.DEFAULT_RESOURCE_PREFIX);

		REIFIED_OPTIONS.put("grammar", "('net.sf.crsx.text.Text';)");
		REIFIED_OPTIONS.put("dispatchify", "1");
		REIFIED_OPTIONS.put("allow-undeclared", "1");
		REIFIED_OPTIONS.put("allow-overlaps", "1");
		REIFIED_OPTIONS.put("reify", "1");

		TEXT_OPTIONS.put(Factory.RESOURCE_PREFIX, Crsx.DEFAULT_RESOURCE_PREFIX);
		TEXT_OPTIONS.put("grammar", "('net.sf.crsx.text.Text';)");

	}

	// State

	private String packageName;
	private String destination;
	private String input;
	private boolean source;
	private String name;

	// Constructors

	public Compile()
	{
		this.packageName = "";
		this.destination = ".";

	}

	// Methods

	/**
	 * Compile given rules. 
	 * @param rulefilename
	 */
	public void compile()
	{
		try
		{
			// Reify
			String reified = reify();

			// Generates Java code
			TEXT_OPTIONS.put("term", reified);
			TEXT_OPTIONS.put("PACKAGE", packageName);

			String jsorts = java("compiler/java/jsorts.crs");
			String jheader = java("compiler/java/jheader.crs");
			String jrules = java("compiler/java/jrules.crs");

			dumpSources(jsorts, jheader, jrules, reified);

			// TODO: compile java file/genreate jar
		}

		catch (CRSException e)
		{
			e.printStackTrace();
		}
	}

	private void dumpSources(String jsorts, String jheader, String jrules, String reified)
	{
		if (source)
		{
			try
			{
				final String prefix = destination + File.separator + name;

				FileWriter writer = new FileWriter(prefix + "Sorts.java");
				writer.append(jsorts);
				writer.close();

				writer = new FileWriter(prefix + ".java");
				writer.append(jheader);
				writer.close();

				writer = new FileWriter(prefix + "Module.java");
				writer.append(jrules);
				writer.close();
				
				writer = new FileWriter(prefix + ".dr");
				writer.append(reified);
				writer.close();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}
	}

	private String java(String rules) throws CRSException
	{
		TEXT_OPTIONS.put("rules", rules);

		return text();

	}

	/** Run reifier */
	protected String reify() throws CRSException
	{
		REIFIED_OPTIONS.put("rules", input);
		GenericFactory factory = new CommonTokenFactory();
		Builder builder = newBuilder(factory, REIFIED_OPTIONS);

		StringBuilder result = new StringBuilder();
		Sink sink = factory.sink(result);
		runDefault(builder, sink);

		name = builder.name();
		return result.toString();

	}

	/** Run given rules and return text */
	protected String text() throws CRSException
	{
		GenericFactory factory = new CommonTokenFactory();
		StringBuilder result = new StringBuilder();

		TextSink sink = new TextSink();
		sink.setFactory(factory);
		sink.setAppendable(result);

		Builder builder = newBuilder(factory, TEXT_OPTIONS);
		runDefault(builder, sink);

		return result.toString();
	}

	/** Run default CRSX script */
	private void runDefault(Builder builder, Sink sink) throws CRSException
	{
		// Get the script.
		final String script = Crsx.DEFAULT_SCRIPT;
		String scriptCategory = null;
		Reader scriptReader = Util.resourceReader(builder.factory(), script);
		Term directive = builder.factory().parse(scriptReader, scriptCategory, script, 1, 1, null);

		Sink after = builder.load(sink, directive);
		if (after instanceof Closeable)
		{
			try
			{
				((Closeable) after).close();
			}
			catch (IOException e)
			{
				// Ignore
			}
		}
	}

	/**
	 * Create new CRS system from parameters
	 * @param options
	 * @return
	 * @throws CRSException
	 */
	protected Builder newBuilder(GenericFactory factory, Map<String, String> options) throws CRSException
	{
		for (Map.Entry<String, String> e : options.entrySet())
			factory.set(e.getKey(), factory.literal(e.getValue()));

		return factory.builder();

		//		Sink after = builder.load(null, directive);
		//		if (after instanceof Closeable)
		//			((Closeable) after).close();
	}

	/**
	 * Compile the given Java source code
	 * 
	 * @param java
	 */
	public void compileJava(final String java)
	{
		try
		{
			// Compile
			JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();

			List<JavaSourceFromString> unitsToCompile = new ArrayList<JavaSourceFromString>();
			unitsToCompile.add(new JavaSourceFromString("Main", java));

			StandardJavaFileManager fileManager = compiler.getStandardFileManager(null, null, null);

			compiler.getTask(null, fileManager, null, null, null, unitsToCompile).call();
			fileManager.close();
		}
		catch (Exception e)
		{
			throw new RuntimeException(e);
		}

	}

	/**
	 * A file object used to represent source coming from a string.
	 */
	public static class JavaSourceFromString extends SimpleJavaFileObject
	{
		/**
		 * The source code of this "file".
		 */
		final String code;

		/**
		 * Constructs a new JavaSourceFromString.
		 * 
		 * @param name the name of the compilation unit represented by this file object
		 * @param code the source code for the compilation unit represented by this file object
		 */
		JavaSourceFromString(String name, String code)
		{
			super(URI.create("string:///" + name.replace('.', '/') + Kind.SOURCE.extension), Kind.SOURCE);
			this.code = code;
		}

		@Override
		public CharSequence getCharContent(boolean ignoreEncodingErrors)
		{
			return code;
		}
	}

	// Command line support

	public void printUsage(String message)
	{
		if (message != null)
			System.out.println(message);

		System.out.print("Usage:\njava ");
		System.out.print(Compile.class.getName());
		System.out.println(" [options] rules.crs"
		        + "\n\nwhere options is" + "\n\n\tpackage=<package-name>\tpackage name of generated Java code"
		        + "\n\tdir=<directory>\tdestination directory" + "\n\tsource\tDump source code");

		System.exit(-1);
	}

	public void processArgs(String[] args)
	{
		if (args.length == 0)
			printUsage("Missing rule file.");

		for (int i = 0; i < args.length - 1; i++)
		{
			if (args[i].startsWith("package="))
			{
				packageName = args[i].substring("package=".length());
			}
			else if (args[i].startsWith("dir="))
			{
				destination = args[i].substring("dir=".length());
			}
			else if ("source".equals(args[i]))
			{
				source = true;
			}
			else
				printUsage("Invalid argument:" + args[i]);
		}

		input = args[args.length - 1];

		compile();

	}

	public static void main(String[] args)
	{
		new Compile().processArgs(args);
	}

}
