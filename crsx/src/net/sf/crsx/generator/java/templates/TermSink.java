/* Copyright © 2009 IBM Corporation. */

package /*[PACKAGE[*/net.sf.crsx.generator.java.templates/*]]*/;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Constructs a term.
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class TermSink extends NativeSink
{

    // State

    /** Stack of term id to construct */
    final protected Stack<Integer> terms;

    /** Stack of term arguments */
    final protected Stack<List<Term>> args;

    /** Stack of sub-binders */
    final protected Stack<List<Variable[]>> subbinders;

    /** Last received binders */
    protected Variable[] binders;

    /** Top-level constructed term */
    private Term term;

    // Constructors

    public TermSink()
    {
        terms = new Stack<Integer>();
        args = new Stack<List<Term>>();
        subbinders = new Stack<List<Variable[]>>();
    }

    // Methods

    /**
     * @return the term
     */
    public Term getTerm()
    {
        return term;
    }

    // Overrides

    @Override
    public void binds(Variable[] binders)
    {
        this.binders = binders;
    }

    @Override
    public void end(int id)
    {
        List<Term> argsList = args.pop();
        Term[] argsArray;
        if (argsList == null)
            argsArray = null;
        else
        {
            argsArray = new Term[argsList.size()];
            argsArray = argsList.toArray(argsArray);
        }

        List<Variable[]> subbinderList = subbinders.pop();
        Variable[][] subbinderArray;
        if (subbinderList == null || subbinderList.size() == 0)
            subbinderArray = null;
        else
        {
            subbinderArray = new Variable[subbinderList.size()][];
            subbinderArray = subbinderList.toArray(subbinderArray);
        }

        // TODO: properties
        final Term term = Dictionary.SINGLETON.createConstructor(id, null, subbinderArray, argsArray);

        if (args.size() > 0)
            args.peek().add(term);
        else
            this.term = term;
    }

    @Override
    public void start(int id)
    {
        if (!subbinders.isEmpty())
        {
            subbinders.peek().add(binders);
            binders = null;
        }
         
        terms.push(id);
        args.push(new ArrayList<Term>());
        subbinders.push(new ArrayList<Variable[]>());
    }

    @Override
    public void use(Variable name)
    {
        if (args.size() > 0)
            args.peek().add(new VariableUse(name));
        else
            this.term = new VariableUse(name);
    }

}
