/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

import java.io.IOException;
import java.io.Writer;
import java.util.Stack;

/**
 * Prints a term as text form
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class TextSink extends NativeSink
{

    // State

    /** Stack of term id */
    final protected Stack<Integer> terms;

    /** Stack of term argument count */
    final protected Stack<Integer> argCount;

    /** Random-access stack of bound variables. Null values delimits frame */
    final protected Stack<Variable> bounds;

    /** Random-access stack of corresponding variable name. */
    final protected Stack<String> names;

    /** Indent count */
    protected int indent;

    /** Last seen binders */
    protected Variable[] binders;

    /** Where to send the term */
    final private Writer writer;

    // Constructors

    public TextSink(Writer writer)
    {
        terms = new Stack<Integer>();
        argCount = new Stack<Integer>();
        bounds = new Stack<Variable>();
        names = new Stack<String>();
        this.writer = writer;
    }

    // Methods

    /** Gets the name of the given variable (null if not bound) */
    protected String getVarname(Variable var)
    {
        for (int i = bounds.size() - 1; i >= 0; i--)
        {
            if (bounds.get(i) == var)
                return names.get(i);
        }
        return makeVarname(null);
    }

    /** Make variable name */
    protected String makeVarname(String name)
    { 
        if (name == null)
        	name = "v";
        int i = 0;
        while (names.contains(name))
            name = name + i++;
        return name;
    }

    // Overrides

    @Override
    public void binds(Variable[] binders)
    {
        this.binders = binders;
    }

    @Override
    public void start(int id)
    {
        try
        {
            if (!terms.isEmpty())
            {
                writer.write(argCount.peek() > 0 ? ",\n" : "[\n");
                argCount.push(argCount.pop() + 1);
            }

            indent += 2;
            for (int i = 0; i < indent; i++)
                writer.write(" ");

            bounds.push(null);
            names.push(null);
            if (binders != null)
            {
                for (int i = 0; i < binders.length; i++)
                {
                    bounds.push(binders[i]);
                    String name = makeVarname(binders[i].getName());
                    names.push(name);

                    if (i > 0)
                        writer.write(" ");
                    writer.write(name);
                }
                writer.write(".");

                binders = null;
            }

            writer.write(Dictionary.SINGLETON.getName(id));
            terms.push(id);
            argCount.push(0);
        }
        catch (IOException e)
        {
            throw new RuntimeException(e);
        }

    }

    @Override
    public void end(int id)
    {
        try
        {
            bounds.pop();
            names.pop();
            while (!bounds.isEmpty() && bounds.peek() != null)
            {
                bounds.pop();
                names.pop();
            }

            terms.pop();
            int count = argCount.pop();
            if (count > 0)
                writer.write("]");

            indent -= 2;
        }
        catch (IOException e)
        {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void use(Variable name)
    {
        try
        {
            if (!terms.isEmpty())
            {
                writer.write(argCount.peek() > 0 ? "," : "[");
                argCount.push(argCount.pop() + 1);
            }
            
            writer.write(getVarname(name));
        }
        catch (IOException e)
        {
            throw new RuntimeException(e);
        }
    }

}
