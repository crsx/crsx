/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

import java.util.IdentityHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Stack;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.util.DelegatingMaker;
import net.sf.crsx.util.LinkedExtensibleMap;

/**
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class FromSink extends DelegatingMaker implements Sink
{
	// State

	/** top-level term */
	protected Term term;

	/** Stack of constructors */
	final protected Stack<Constructor> stack;

	/** Associated list of arguments */
	final protected Stack<List<Term>> argsStack;

	/** Associated list of subbinders */
	protected Stack<List<Variable[]>> subbindersStack;

	/** Map external variable to generated variables */
	final protected Map<net.sf.crsx.Variable, Variable> vars;

	/** Seen {@link FromSink#binds(net.sf.crsx.Variable[])}? */
	protected boolean bindsSeen;

	// Constructors

	public FromSink(Maker maker)
	{
		super(maker);
		stack = new Stack<Constructor>();
		argsStack = new Stack<List<Term>>();
		subbindersStack = new Stack<List<Variable[]>>();
		vars = new IdentityHashMap<net.sf.crsx.Variable, Variable>();
	}

	// Methods

	public Term getTerm()
	{
		return term;
	}

	// Implements Sink

	public Sink binds(net.sf.crsx.Variable[] binders)
	{
		Variable[] b = new Variable[binders.length];
		for (int i = 0; i < binders.length; i++)
		{
			b[i] = new Variable(binders[i].name());
			this.vars.put(binders[i], b[i]);
		}

		subbindersStack.peek().add(b);
		bindsSeen = true;
		return this;
	}

	public Sink copy(Copyable source, boolean discard)
	{
		return source.copy(this, discard, new LinkedExtensibleMap<net.sf.crsx.Variable, net.sf.crsx.Variable>());
	}

	public Sink start(Constructor constructor)
	{
		if (!bindsSeen && subbindersStack.size() > 0)
			subbindersStack.peek().add(null);
		else
			bindsSeen = false;

		stack.push(constructor);
		argsStack.push(new LinkedList<Term>());
		subbindersStack.push(new LinkedList<Variable[]>());
		return this;
	}

	public Sink end()
	{
		final Constructor constructor = stack.pop();
		final List<Term> argsList = argsStack.pop();
		final List<Variable[]> subbindersList = subbindersStack.pop();
		Variable[][] subbinders = new Variable[subbindersList.size()][];
		subbinders = subbindersList.toArray(subbinders);

		final Term[] args = argsList.size() > 0 ? argsList.toArray(new Term[argsList.size()]) : null;

		Properties properties = new Properties();
		for (String key : constructor.propertyNames())
		{
			properties.setNamedProperty(key, Dictionary.SINGLETON.createConstructor(
					constructor.getProperty(key).constructor().symbol(), null, null, (Term[]) null));
		}
			 
		final Term term = Dictionary.SINGLETON.createConstructor(constructor.symbol(), properties, subbinders, args);

		if (stack.size() == 0)
			this.term = term;
		else
			argsStack.peek().add(term);

		return this;
	}

	public Sink startMetaApplication(String name)
	{
		throw new AssertionError();
	}

	public Sink endMetaApplication()
	{
		throw new AssertionError();
	}

	public Sink use(net.sf.crsx.Variable variable)
	{
		Variable var = vars.get(variable);
		if (var == null)
		{
			// This is a free variable.
			var = new Variable(variable.name());
		}

		Term term = new VariableUse(var);

		if (subbindersStack.size() > 0)
			subbindersStack.peek().add(null);

		if (stack.size() > 0)
			argsStack.peek().add(term);
		else
			this.term = term;

		return this;
	}

}
