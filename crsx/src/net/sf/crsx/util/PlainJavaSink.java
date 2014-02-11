/** Copyright © 2008 IBM Corporation */

package net.sf.crsx.util;

import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Pseudo-sink that generates Java code, which when compiled creates a term similar to the term shipped to the sink...
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: PlainJavaSink.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class PlainJavaSink extends DelegateMaker implements Sink
{
	// Static.

	/** Helper class to set text mode. */
	public static enum Mode { TOP, STATEMENT, SINK };

	/** Class name of {@link Variable} interface. */
	public static final String VARIABLE = Variable.class.getCanonicalName();
	/** Class name of {@link Constructor} interface. */
	public static final String CONSTRUCTOR = Constructor.class.getCanonicalName();
	/** Class name of {@link Term} interface. */
	public static final String TERM = Term.class.getCanonicalName();
	/** Class name of {@link Sink} interface. */
	public static final String SINK = Sink.class.getCanonicalName();
	/** Class name of {@link Buffer} interface. */
	public static final String BUFFER = Buffer.class.getCanonicalName();
	/** Class name of this class. */
	public static final String SELF = PlainJavaSink.class.getCanonicalName();

	/** Convert char to Java source form. */
    public static String quoteChar(char c)
    {
        StringBuilder b = new StringBuilder();
        b.append("'");
        switch (c)
        {
            case '\b' : b.append("\\b"); break;
            case '\t' : b.append("\\t"); break;
            case '\n' : b.append("\\n"); break;
            case '\f' : b.append("\\f"); break;
            case '\r' : b.append("\\r"); break;
            case '\'' : b.append("\\'"); break;
            case '\"' : b.append("\\\""); break;
            case '\\' : b.append("\\\\"); break;
            default :
                if (Character.isISOControl(c))
                    b.append("\\" + oct3(c));
                else if (c <= '~')
                    b.append(c);
                else if (c <= '\277')
                    b.append("\\" + oct3(c));
                else
                    b.append("\\u" + hex4(c));
        }
        b.append("'");
        return b.toString();
    }
    
	/** The 4 hex-digit value of char. */
	public static String hex4(char c)
	{
		String s = Integer.toHexString((int) c);
		return "0000".substring(s.length()) + s;
	}

    /** The char corresponding to the 4 hex-digit value. */
    public static char unhex4(String hex)
    {
        return (char) Integer.parseInt(hex, 16);
    }
    
	/** The 3 octal digit (8-bit) value of char. */
	public static String oct3(char c)
	{
		String s = Integer.toOctalString((int) c);
		return "000".substring(s.length()) + s;
	}
	
	/** The Java string (UTF-16) corresponding to the Unicode character u. */
	public static String unicode(int u)
	{
		StringBuilder b = new StringBuilder();
		b.append(Character.toChars(u));
		return b.toString();
	}

	/** Encode string as Java "$-token". */
    public static String javaIdentify(String s)
    {
        if (s == null || s.length() == 0)
            return "$E";
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s.charAt(i);
            switch (c)
            {
                case '$' : b.append("$$"); break;
                case '?' : b.append("$Q"); break;
                case '!' : b.append("$B"); break;
                case '-' : b.append("$_"); break;
                // More...here and below.
                default :
                    if (Character.isJavaIdentifierPart(c))
                        b.append(c);
                    else
                        b.append("$x" + hex4(c));
            }
        }
        return b.toString();
    }

    /** Decode Java "$-token" as string. */
    public static String javaUnidentify(String s)
    {
        StringBuilder b = new StringBuilder();
        int i = 0;
        while (i < s.length())
        {
            char c = s.charAt(i++);
            if (c == '$')
            {
                c = s.charAt(i++);
                switch (c)
                {
                    case 'E' : break;
                    case '$' : b.append('$'); break;
                    case 'Q' : b.append('?'); break;
                    case 'B' : b.append('!'); break;
                    case '_' : b.append('-'); break;
                    // More...here and above.
                    case 'x' : b.append(s.substring(i, i+4)); i += 4; break;
                    default : assert false : "Impossible character after '$' in $-token.";
                }
            }
            else
                b.append(c);
        }
        return b.toString();
    }

	/** Indent. */
	public static String indent(int in)
	{
		return "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
			.substring(0, in);
	}

	/**
	 * Generate code that sets the term target to the term.
	 * @param maker where constructors, variables, and buffers can be retrieved
	 * @param stub that can emit the term
	 * @param termPrefix prefix for final wrap - usually "return" or "v =" for some variable v (which must have been previously defined)
	 * @param termTail tail for final wrap - usually ";"
	 * @param java to send code to
	 */
	public static void generateJavaToTerm(String indent, Appendable a, Maker maker, Stub stub, String makerName, String termPrefix, String termTail)
	{
		generateJavaToBuffer(new PlainSourceBuilder(a, indent), maker, stub, makerName, termPrefix, ".term(true)" + termTail);
	}

	/**
	 * Generate code that creates a fresh buffer containing the term in the stub.
	 * @param java to send code to
	 * @param maker where constructors, variables, and buffers can be retrieved
	 * @param stub that can emit the term
	 * @param termTarget where the term should be stored: either "return" or "v =" for some variable v (which must have been previously defined)
	 */
	public static void generateJavaToBuffer(SourceBuilder java, Maker maker, Stub stub, String makerName, String lead, String trail)
	{
		java.openBlock("{");
		java.addStatement(BUFFER + " _buffer = new " + BUFFER + "(" + makerName + ");");
		java.addStatement(SINK + " _sink = _buffer.sink();");
		generateJavaToSink(java, maker, stub, "_sink");
		java.addStatement(lead + " _buffer" + trail);
		java.closeBlock("}");
	}

	/**
	 * Generate code that updates a named sink variable to contain the same term as is available on stub.
	 * @param java to send code text to
	 * @param maker where constructors, variables, and buffers can be retrieved
	 * @param source with term we wish to generate code for
	 * @param sinkName name of sink variable to continuously update
	 */
	public static void generateJavaToSink(SourceBuilder java, Maker maker, Copyable source, String sinkName)
	{
		PlainJavaSink j = new PlainJavaSink(maker, sinkName, java, null);
		j.copy(source, false);
		if (java.seeded())
			java.addStatement(java.wrapExpression(sinkName+" =", ";").harvest());
	}

	// State.

	/** Source of variables and constructors provided to sink user. */
	final protected Maker maker;
	
	/** The name of the sink used in the code. */
	final protected String sinkName;
	
	/** The writer to where Java  code is sent. */
	final protected SourceBuilder java;
	
	/** The initial nesting of the block builder that {@link #flush()} should reestablish. */
	final protected int javaBaseNesting;
	
	/** Names of variables from source term. */
	final protected Map<Variable, String> variable2java;

	// Constructor.

	/**
	 * Create instance that emits Java code for received sink events.
	 * @param maker in case someone asks this sink to create constructors or variables...
	 * @param sinkName name of sink variable that the generated code should maintain
	 * @param java for the code text - use {@link #flush()} before appending to it yourself
	 * @param variable2java with the Java expressions corresponding to the {@link Variable} to use for free variables
	 * 		(or null if there are none)
	 */
	public PlainJavaSink(Maker maker, String sinkName, SourceBuilder java, Map<Variable, String> variable2java)
	{
		this.maker = maker;
		this.sinkName = sinkName;
		this.java = java;
		this.javaBaseNesting = java.nesting();
		this.variable2java = (variable2java != null ? variable2java : new HashMap<Variable, String>());
	}
	
	// DelegateMaker...
	
    @Override
    final public Maker maker()
    {
	    return maker;
    }

	// Sink...

	public Sink start(Constructor constructor)
	{
		constructor.javaInvokeStart(java, sinkName, variable2java);
		return this;
	}

	public Sink end()
	{
		java.wrapExpression("", ".end()");
		return this;
	}

	public Sink binds(Variable[] binders)
	{
		java.openBlock("{");
		// Invent binder names, map the original variables to the new names, and emit binder of the new names.
		for (Variable v : binders)
		{
			String n = "v"+java.count();
			variable2java.put(v, n);
			java.addStatement(VARIABLE+" "+n+" = "+sinkName+".makeVariable("+Util.quoteJava(v.name())+","+v.promiscuous()+");");
		}
		StringBuilder b = new StringBuilder();
		boolean first = true;
		for (Variable v : binders)
		{
			b.append((first ? "" : ",") + variable2java.get(v));
			first = false;
		}
		String bs = "bs"+java.count();
		java.addStatement(VARIABLE+"[] "+bs+" = {"+b+"};");
		java.wrapExpression("", ".binds("+bs+")");
		return this;
	}

	public Sink use(Variable variable)
	{
		java.wrapExpression("", ".use("+variable2java.get(variable)+")");
		return this;
	}

	public Sink startMetaApplication(String name)
	{
		java.wrapExpression("", ".startMetaApplication("+Util.quoteJava(name)+")");
		return this;
	}

	public Sink endMetaApplication()
	{
		java.wrapExpression("", ".endMetaApplication()");
		return this;
	}

	public Sink copy(Copyable source, boolean discard)
	{
		return source.copy(this, false, new LinkedExtensibleMap<Variable, Variable>());
	}
	
	// Sic.
	
	public String toString()
	{
		return java.toString();
	}
}
