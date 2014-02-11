// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import static net.sf.crsx.compiler.java.Sink.BUFFER_TERM;
import static net.sf.crsx.compiler.java.Sink.END;
import static net.sf.crsx.compiler.java.Sink.FREE_BUFFER;
import static net.sf.crsx.compiler.java.Sink.MAKE_BUFFER;
import static net.sf.crsx.compiler.java.Sink.PROPERTIES_RESET;
import static net.sf.crsx.compiler.java.Sink.START;

import java.lang.reflect.Field;
import java.util.ArrayList;

/**
 * Test for Java compiler text mode.
 * 
 * @author villardl
 */
public class Main
{

	/** Function generating term */
	protected static void sendTerm(Sink sink, ConstructionDescriptor desc)
	{
		PROPERTIES_RESET(sink);
		START(sink, desc);
		END(sink, desc);
	}

	/** Create term */
	protected static Term makeTerm(ConstructionDescriptor desc)
	{
		Sink sink = MAKE_BUFFER();
		sendTerm(sink, desc);
		Term term = BUFFER_TERM(sink);
		FREE_BUFFER(sink);
		return term;
	}

	/** Main program */
	public static void main(String[] args)
	{
		if (args.length != 1)
			printUsage("Invalid number of arguments");

		String name = args[0];
		int ld = name.lastIndexOf('.');
		if (ld == -1)
			printUsage("Argument malformed: " + name);

		String classname = name.substring(0, ld);

		String fieldName = name.substring(ld + 1);
		try
		{
			Class<?> clazz = Class.forName(classname);

			Field field = clazz.getField(fieldName);
			ConstructionDescriptor desc = (ConstructionDescriptor) field.get(null);

			Term term = makeTerm(desc);
			term = Crsx.normalize(term, new ArrayList<Crsx.ContextEntry>());
			Crsx.printTerm(term);

		}
		catch (ClassNotFoundException e)
		{
			e.printStackTrace();
			printUsage(e.getLocalizedMessage());
		}
		catch (SecurityException e)
		{
			e.printStackTrace();
			printUsage(e.getLocalizedMessage());
		}
		catch (NoSuchFieldException e)
		{
			e.printStackTrace();
			printUsage(e.getLocalizedMessage());
		}
		catch (IllegalArgumentException e)
		{
			e.printStackTrace();
			printUsage(e.getLocalizedMessage());
		}
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
			printUsage(e.getLocalizedMessage());
		}

	}

	private static void printUsage(String message)
	{
		if (message != null)
			System.out.println(message);
		System.out.print("Usage:\njava ");
		System.out.print(Main.class.getName());
		System.out.println(" Classname.DescriptorName");
		System.exit(-1);
	}

}
