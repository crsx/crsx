/* Copyright (c) 2008 IBM Corporation. */

package net.sf.crsx.joel;

import java.io.IOException;
import java.lang.reflect.Array;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Match;
import net.sf.crsx.Path;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.SourceBuilder;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.generic.GenericFactory;
import net.sf.crsx.util.EmptyIterable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.Pair;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Factory for interpreting Joel script directly as object creation instructions.
 * (Effectively a small non-recursive Java interpreter...)
 * <p>
 * The {@link Category} constructions (returned by the embedded {@link #makeConstructor(Object)} when their names are requested)
 * support special operations; all other constructions are just interpreted as the result of their {@link Constructor#object()}, ignoring any arguments.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: JoelFactory.java,v 3.4 2013/12/09 05:48:40 krisrose Exp $
 */
public class JoelFactory extends GenericFactory
{
	// Static.

	static int function_count = 0;

	/** Maps built-in types to their boxed version. */
	final public static Map<Class<?>, Class<?>> BOXED_TYPE = new IdentityHashMap<Class<?>, Class<?>>();
	{
		BOXED_TYPE.put(Integer.TYPE, Integer.class);
		BOXED_TYPE.put(Long.TYPE, Long.class);
		BOXED_TYPE.put(Short.TYPE, Short.class);
		BOXED_TYPE.put(Byte.TYPE, Byte.class);
		BOXED_TYPE.put(Character.TYPE, Character.class);
		BOXED_TYPE.put(Double.TYPE, Double.class);
		BOXED_TYPE.put(Float.TYPE, Float.class);
		BOXED_TYPE.put(Boolean.TYPE, Boolean.class);
	}

	/** Version of {@link Class#isAssignableFrom(Class)} fixed to respect boxing. */
	public static boolean isAssignableFrom(Class<?> target, Class<?> source)
	{
		return BOXED_TYPE.get(target) == source || target == BOXED_TYPE.get(source) || target.isAssignableFrom(source);
	}

	/** Convert an object to a string. */
	private static String strung(Object object)
	{
		return (object instanceof String ? (String) object : object.toString());
	}

	/** Convert an object to a character. */
	private static Character charred(Object object)
	{
		return (object instanceof Character ? (Character) object : strung(object).charAt(0));
	}

	/** Convert an object to an integer. */
	private static Integer integrate(Object object)
	{
		return (object instanceof Integer ? (Integer) object : Integer.parseInt(object.toString()));
	}

	/** Convert an object to an integer. */
	private static Class<?> classify(Object object)
	{
		try
		{
			return Class.forName(strung(object));
		}
		catch (ClassNotFoundException e)
		{
			throw new RuntimeException(e);
		}
	}

	// Helper classes.

	/** Implementations of call-back action. */
	public static interface ObjectCallBack
	{
		/** Call-back to export constructed object structure. */
		void store(Object object);
	}

	/**
	 * Special constructors for object creation and manipulation.
	 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
	 */
	public enum Category implements Constructor {
		/**
		 * New[<em>class</em>, <em>argument</em>,...].
		 * Simulates Java object creation expression <b>new</b> <em>class</em>(<em>argument</em>,...).
		 */
		NEW("New") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new New(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "(new ", true, "(", false, ",", ",", "))");
			}
		},
		/**
		  * Invoke[<em>object</em>, <em>method</em>, <em>argument</em>,...].
		  * Simulates Java method invocation expression <em>object</em>.<em>method</em>(<em>argument</em>,...).
		  */
		INVOKE("Invoke") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new Invoke(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "(", false, ".", false, "(", ",", "))");
			}
		},
		/** 
		  * NewArray[<em>class</em>, <em>length</em>].
		  * Simulates Java array creation expression <b>new</b> <em>class</em>[<em>length</em>].
		  */
		NEW_ARRAY("NewArray") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new NewArray(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "new ", true, "[", false, "", "", "]");
			}
		},
		/** 
		  * ArraySet[<em>array</em>, <em>index</em>, <em>value</em>].
		  * Simulates Java array assignment expression <em>array</em>[<em>index</em>] = <em>value</em>.
		  */
		ARRAY_SET("ArraySet") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new ArraySet(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "(", false, "[", false, "] =", "", ")");
			}
		},
		/**
		  * ArrayGet[<em>array</em>, <em>index</em>].
		  * Simulate Java array access expression <em>array</em>[<em>index</em>].
		  */
		ARRAY_GET("ArrayGet") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new ArrayGet(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "(", false, "[", false, "", "", "])");
			}
		},
		/**
		 * Static[<em>class</em>, <em>method</em>, <em>argument</em>,...].
		 * Simulate Java static method invocation expression <em>class</em>.<em>method</em>(<em>argument</em>,...).
		 */
		STATIC("Static") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new Static(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "(", true, "[", false, "", "", "])");
			}
		},
		/**
		 * Null.
		 * Simulates the Java expression <b>null</b>.
		 */
		NULL("Null") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				parent.store(null);
				return host.new Skip(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "null", false, "", false, "", "", "");
			}
		},
		/**
		 * False.
		 * Simulates the Java expression <b>false</b>.
		 */
		FALSE("False") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				parent.store(false);
				return host.new Skip(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "false", false, "", false, "", "", "");
			}
		},
		/**
		 * True.
		 * Simulates the Java expression <b>true</b>.
		 */
		TRUE("True") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				parent.store(true);
				return host.new Skip(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "true", false, "", false, "", "", "");
			}
		},
		/**
		 * Integer[<em>term</em>].
		 * The <em>term</em> interpreted directly as a Java <b>int</b>.
		 */
		INTEGER("Integer") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new IntegerLiteral(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "", true, "", false, "", "", "");
			}
		},
		/**
		 * String[<em>term</em>].
		 * Simulates the Java literal string expression "<em>term</em>".
		 * (Only truly needed when the <em>term</em> may look like one of the other constructors.)
		 */
		STRING("String") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new StringLiteral(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "\"", true, "\"", false, "", "", "");
			}
		},
		/**
		 * Character[<em>term</em>].
		 * Simulates the Java literal character expression '<em>term</em>'.
		 */
		CHARACTER("Character") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new CharacterLiteral(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				return host.new JavaExpression(parent, "'", true, "'", false, "", "", "");
			}
		},
		/**
		 * Let[<em>type</em>, <em>value</em>, <em>variable</em> . <em>body</em>].
		 * 
		 * Create a declaration where the <em>variable</em> is bound to the evaluated <em>value</em>
		 * when <em>body</em> is processed.
		 * 
		 * Corresponds to the Java snippet 
		 */
		LET("Let") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new Let(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				// TODO
				return null;
			}
		},
		/**
		  * GenerateSymbol[<em>prefix</em>].
		  * A unique constructor, using the <em>prefix</em> as the initial part of the name.
		  */
		GENERATE_SYMBOL("GenerateSymbol") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new GenerateSymbol(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				// TODO!
				return null;
			}
		},
		/**
		 * EnvironmentSet[<em>name</em>, <em>value</em>, <em>body</em>].
		 * Set the <em>name</em> environment value to <em>value</em> inside <em>body</em>.
		 */
		ENVIRONMENT_SET("EnvironmentSet") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new Skip(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				// TODO!
				return null;
			}
		},
		/**
		 * EnvironmentGet[<em>name</em>].
		 * Get the value of the <em>name</em> environment value.
		 */
		ENVIRONMENT_GET("EnvironmentGet") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new Skip(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				// TODO!
				return null;
			}
		},
		/**
		 * Skip.
		 * Simulates the empty Java statement.
		 */
		SKIP("Skip") {
			@Override
			Link push(JoelFactory host, Link parent)
			{
				return host.new Skip(parent);
			}

			@Override
			JavaLink javaPush(JoelFactory host, JavaLink parent)
			{
				// TODO!
				return null;
			}
		};

		// State.
		/** CRS symbol. */
		final String symbol;

		// Constructor.
		/** Create (unique) constructor constant. */
		Category(String name)
		{
			this.symbol = name.intern();
		}

		// Methods.
		/**
		 * Handler for {@link Sink#start(Constructor)} with the constructor.
		 * Invariant: return link that will call our {@link Link#store(Object)} for each argument,
		 * and whose {@link Sink#end()} will return this,
		 * 
		* @param host the root {@link JoelFactory}
		* @param parent link
		 * @return new link whose matching end() will return the parent (the corresponding pop)
		 */
		abstract Link push(JoelFactory host, Link parent);

		/**
		 * Handler for code generation of {@link Sink#start(Constructor)} with the constructor.
		 * Invariant: return link whose {@link Sink#end()} will return this.
		 * @param host the root {@link JoelFactory}
		 * @param parent link
		 */
		abstract JavaLink javaPush(JoelFactory host, JavaLink parent);

		// Object...
		/** String form is CRS form. */
		public String toString()
		{
			return symbol;
		}

		// Constructor...
		public String symbol()
		{
			return symbol;
		}

		public String literalSort()
		{
			return null;
		}

		public Object object()
		{
			return this;
		}

		public boolean match(Match match, Constructor that, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
		{
			return equals(that);
		}

		public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
		{}

		public Constructor subsubstitute(Maker maker, Valuation valuation, ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
		{
			return this;
		}

		public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
		{
			return true;
		}

		public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
		{}

		public Constructor oldunify(ExtensibleMap<Variable, Variable> thisBound, Map<Variable, Variable> thisBaseVariable, Map<String, String> thisBaseMeta, Constructor that, ExtensibleMap<Variable, Variable> thatBound, Map<Variable, Variable> thatBaseVariable, Map<String, String> thatBaseMeta, Match unifiedMatch, ExtensibleMap<Variable, Variable> unifiedBound, Map<String, List<Pair<ExtensibleMap<Variable, Variable>, Term>>> unifiedMatched)
		{
			return equals(that) ? this : null;
		}

		public Constructor unify(Unification unification, Constructor that, StackedMap<Variable> rho, StackedMap<Variable> rhoprime)
		{
			return equals(that) ? this : null;
		}

		public Constructor copy(ExtensibleMap<Variable, Variable> renamings)
		{
			return this;
		}

		public Constructor contract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
		{
			return this;
		}

		public Constructor staticContract(Valuation valuation, ExtensibleMap<Variable, Variable> renamings)
		{
			return this;
		}

		public void normalize(CRS crs) throws CRSException
		{}

		public void appendTo(Appendable writer, Map<Variable, String> used, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean sortProps)
				throws IOException
		{
			if (depth <= 0)
			{
				writer.append("...");
				return;
			}
			writer.append(symbol);
		}

		public SortedSet<Path> paths(Path base)
		{
			return new TreeSet<Path>();
		}

		public void javaInvokeStart(SourceBuilder code, String sinkName, Map<Variable, String> variable2java)
		{
			code.wrapExpression("", ".start(" + Category.class.getCanonicalName() + "." + name() + ")");
		}

		public Constructor baseConstructor()
		{
			return this;
		}

		// PropertiesHolder...
		public Iterable<String> propertyNames()
		{
			return new EmptyIterable<String>();
		}

		public Term getProperty(String name)
		{
			return null;
		}

		public Iterable<Variable> propertyVariables()
		{
			return new EmptyIterable<Variable>();
		}

		public Term getProperty(Variable variable)
		{
			return null;
		}

		public boolean canSetProperty(String name)
		{
			return false;
		}

		public boolean canSetProperty(Variable variable)
		{
			return false;
		}

		public void setProperty(String name, Term value)
		{}

		public void setProperty(Variable variable, Term value)
		{}

		@Override
		public void removeProperty(Variable variable) throws CRSException
		{}

		public void setProperties(PropertiesHolder properties)
		{}

		public boolean isMeta()
		{
			return false;
		}
	};

	// State.

	/** Where to send received result(s). */
	final ObjectCallBack callBack;

	/** Counter of unique symbols. */
	private int generateSymbolCounter;

	/** The built-in constructors by name. */
	private final Map<String, Constructor> constructors = new HashMap<String, Constructor>();

	// Constructor.

	/**
	 * Create factory from precreated environment.
	 * @param env to use (null means "none")
	 * @param callBack to invoke for each complete object tree passed to {@link #sink()} (should not be null)
	 */
	public JoelFactory(Map<String, Stub> env, ObjectCallBack callBack)
	{
		super();
		for (Map.Entry<String, Stub> e : env.entrySet())
			set(e.getKey(), e.getValue());
		this.callBack = callBack;
		for (Category cat : Category.values())
			constructors.put(cat.symbol(), cat);
	}

	/**
	 * Create factory from precreated environment that discards the final object structures built by {@link #sink()}.
	 * @param env to use (null means "none")
	 */
	public JoelFactory(Map<String, Stub> env)
	{
		this(env, new ObjectCallBack()
			{
				public void store(Object object)
				{}
			});
	}

	/**
	 * Anonymous constructor using an empty environment and
	 * discarding the final object structures built by {@link #sink()}.
	 */
	public JoelFactory()
	{
		this(null, new ObjectCallBack()
			{
				public void store(Object object)
				{}
			});
	}

	// Factory...

	public Sink sink(Appendable appendable)
	{
		// Construct the "root" link that stores directly to the factory callBack.
		return new Link(null)
			{
				public void store(Object sub)
				{
					if (sub == null)
						System.out.println("Got null?!?");
					callBack.store(sub);
				}
			};
	}

	/**
	 * Create sink that generates Java code for object structure...
	 * @param callBack of which {@link ObjectCallBack#store(Object)} is invoked when object finished
	 */
	public Sink javaSink(final SourceBuilder java)
	{
		// Construct the "root" link for Java generation...
		return new JavaLink(null)
			{
				@Override
				SourceBuilder java()
				{
					return java;
				}

				@Override
				String lookup(Variable variable)
				{
					throw new RuntimeException("Unknown variable " + variable);
				}
			};
	}

	// Maker implementation...

	public Constructor makeConstructor(Object object)
	{
		Constructor c = constructors.get(object);
		return (c != null ? c : super.makeConstructor(object));
	}

	// Helper classes (implement Sink).

	/** Base generation link. */
	abstract private class Link implements ObjectCallBack, Sink
	{
		// State.
		final protected Link parent; // where the entire construction should be added

		// Constructors.
		Link(Link parent)
		{
			this.parent = parent;
		}

		// Methods.
		/** Lookup variable up the chain. */
		Object lookup(Variable variable)
		{
			assert parent != null : "Could not find variable " + variable + "!?!";
			return (parent == null ? null : parent.lookup(variable));
		}

		// ObjectCallBack...
		public abstract void store(Object object);

		// Maker...
		final public Constructor makeConstructor(Object object)
		{
			return JoelFactory.this.makeConstructor(object);
		}

		public Constructor makeLiteral(Object object, String sort)
		{
			return JoelFactory.this.makeLiteral(object, sort);
		}

		final public Variable makeVariable(String name, boolean promiscuous)
		{
			return JoelFactory.this.makeVariable(name, promiscuous);
		}
		
		final public Variable makeVariable(String name, boolean promiscuous, boolean blocking, boolean shallow)
		{
			return JoelFactory.this.makeVariable(name, promiscuous, blocking, shallow);
		}

		final public Variable freeVariable(String name, boolean promiscuous, boolean create)
		{
			return JoelFactory.this.freeVariable(name, promiscuous, create);
		}

		final public Variable freeVariable(String name, boolean promiscuous, boolean blocking, boolean shallow, boolean create)
		{
			return JoelFactory.this.freeVariable(name, promiscuous, blocking, shallow, create);
		}

		final public Sink makeBuffer(Maker.CallBack callBack)
		{
			return JoelFactory.this.makeBuffer(callBack);
		}

		// Sink...
		public Sink binds(Variable[] binders)
		{
			throw new UnsupportedOperationException("Binders not allowed for " + getClass().getName());
		}

		public Sink use(Variable variable)
		{
			store(lookup(variable));
			return this;
		}

		public Sink start(Constructor constructor)
		{
			// Common case is one of the special operators.
			Object object = constructor.object();
			if (object instanceof Category)
				return ((Category) object).push(JoelFactory.this, this);

			// Sequences evaluate but discard the head.
			if (Util.isCons(constructor))
				return new Last(this);
			if (Util.isNull(constructor))
				return new Skip(this);

			// Fall back to just use the constructor base object.
			store(object);
			return new Skip(this);
		}

		public Sink end()
		{
			assert parent != null : "No construction to end.";
			return parent;
		}

		public Sink startMetaApplication(String name)
		{
			throw new UnsupportedOperationException("ObjectBuffer does not support meta-applications!");
		}

		public Sink endMetaApplication()
		{
			assert false : "No meta-application to end.";
			return null;
		}

		public Sink copy(Copyable source, boolean discard)
		{
			// Generic case: get source to copy itself.
			return source.copy(this, discard, new LinkedExtensibleMap<Variable, Variable>());
		}

		// Sic.
		public String toString()
		{
			StringBuilder b = new StringBuilder(super.toString() + " {");
			for (Link link = this; link != null; link = link.parent)
			{
				String binder = link.binderString();
				if (binder != null)
					b.append("\n  " + binder);
			}
			b.append(" }");
			return b.toString();
		}

		/** Internal to return null or a text describing a local binder. */
		String binderString()
		{
			return null;
		}
	}

	/** Dummy handler ignoring the arguments. */
	private class Skip extends Link
	{
		// Constructor.
		public Skip(Link parent)
		{
			super(parent);
		}

		// Link...
		@Override
		public void store(Object object)
		{}
	}

	/** For sequences where only the last is propagated. */
	private class Last extends Link
	{
		private Object last;

		// Constructor.
		public Last(Link parent)
		{
			super(parent);
		}

		// Link...
		@Override
		public void store(Object object)
		{
			last = object;
		}

		@Override
		public Sink end()
		{
			parent.store(last);
			return super.end();
		}
	}

	/** Sink used to generate invocation. */
	private class Static extends Link
	{
		// State.
		private Class<?> clazz; // class to invoke method on
		private String name; // name of method to invoke
		private List<Object> arguments = new ArrayList<Object>(); // list of the arguments

		// Constructor.
		Static(Link parent)
		{
			super(parent);
		}

		// Link...
		@Override
		public void store(Object sub)
		{
			if (clazz == null)
			{
				clazz = classify(sub); // first argument is class name
				assert clazz != null : "Bad class name: " + sub;
			}
			else if (name == null)
			{
				name = strung(sub); // second argument is method name
				assert name != null : "Bad method name: " + sub;
			}
			else
			{
				arguments.add(sub); // remaining arguments are parameters
			}
		}

		@Override
		public Sink end()
		{
			parent.store(invokeStatic(clazz, name, arguments));
			return super.end();
		}
	}

	/** Sink instance used to construct new object structure. */
	private class New extends Link
	{
		// State.
		private Class<?> clazz; // to construct instance of
		private List<Object> arguments = new ArrayList<Object>(); // of construction

		// Constructor.
		New(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			if (clazz == null)
			{
				clazz = classify(sub); // first argument is class name
				assert clazz != null : "Could not instantiate class for " + sub;
			}
			else
			{
				arguments.add(sub); // following arguments are constructor arguments
			}
		}

		@Override
		public Sink end()
		{
			parent.store(newInstance(clazz, arguments));
			return super.end(); // pop!
		}
	}

	/** Sink used to generate invocation. */
	private class Invoke extends Link
	{
		// State.
		private Object object; // object to invoke method on or extract field from
		private String name; // name of method to invoke
		private List<Object> arguments = new ArrayList<Object>(); // list of the arguments

		// Constructor.
		Invoke(Link parent)
		{
			super(parent);
		}

		// Link...
		@Override
		public void store(Object sub)
		{
			if (object == null)
			{
				object = sub; // first argument is object
				assert object != null : "Null object?!?";
			}
			else if (name == null)
			{
				name = strung(sub); // second argument is method or field name
				assert name != null : "Bad method name: " + sub;
			}
			else
				arguments.add(sub); // following arguments are method arguments
		}

		@Override
		public Sink end()
		{
			parent.store(invoke(object, name, arguments));
			return super.end();
		}
	}

	/** Sink instance used to construct new array structure. */
	private class NewArray extends Link
	{
		// State.
		private Class<?> clazz; // to construct array instance of
		private int size; // size of array

		// Constructor.
		NewArray(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			if (clazz == null)
			{
				try
				{
					clazz = Class.forName(sub.toString());
				}
				catch (ClassNotFoundException e)
				{
					throw new UnsupportedOperationException(e);
				}
			}
			else
			{
				size = Integer.parseInt(sub.toString());
			}
		}

		@Override
		public Sink end()
		{
			try
			{
				// Materialize and pop array.
				parent.store(Array.newInstance(clazz, size));
				return super.end();
			}
			catch (IllegalArgumentException e)
			{
				throw new RuntimeException(e);
			}
			catch (SecurityException e)
			{
				throw new RuntimeException(e);
			}
		}
	}

	/** Handles ArraySet[<em>array</em>, <em>index</em>, <em>value</em>] after .start(). */
	private class ArraySet extends Link
	{
		// State.
		private Object[] array;
		private Integer index;

		// Constructor.
		ArraySet(Link parent)
		{
			super(parent);
		}

		// Link...
		@Override
		public void store(Object sub)
		{
			if (array == null)
				array = (Object[]) sub;
			else if (index == null)
				index = integrate(sub);
			else
			{
				array[index] = sub;
				parent.store(sub); // value is stored value
			}
		}
	}

	/** Sink instance used to generate primitive value. */
	private class ArrayGet extends Link
	{
		// State.
		private Object[] array;

		// Constructor.
		ArrayGet(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			if (array == null)
				array = (Object[]) sub;
			else
				parent.store(array[integrate(sub)]);
		}
	}

	/** Sink instance used to generate strings. */
	private class StringLiteral extends Link
	{
		// State.
		/** String accumulation. */
		final protected StringBuilder builder = new StringBuilder();
		/** Nesting level. */
		int nesting;

		// Constructor.
		StringLiteral(Link parent)
		{
			super(parent);
			nesting = 1;
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			assert false : "Literal has no subobjects?!?";
		}

		// Sink...
		@Override
		public Sink start(Constructor constructor)
		{
			nesting++;
			builder.append(constructor.symbol());
			return this;
		}

		@Override
		public Sink end()
		{
			if (--nesting <= 0)
			{
				parent.store(builder.toString());
				return parent;
			}
			else
			{
				return this;
			}
		}

		@Override
		public Sink use(Variable variable)
		{
			builder.append(variable.name());
			return this;
		}
	}

	/** Sink instance used to generate primitive value. */
	private class CharacterLiteral extends Link
	{
		// Constructor.
		CharacterLiteral(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			parent.store(charred(sub));
		}
	}

	/** Sink instance used to generate primitive value. */
	private class IntegerLiteral extends Link
	{
		// Constructor.
		IntegerLiteral(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			parent.store(integrate(sub));
		}
	}

	/** Sink instance used to generate primitive value. */
	private class GenerateSymbol extends Link
	{
		// Constructor.
		GenerateSymbol(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		public void store(Object sub)
		{
			parent.store(strung(sub) + (++generateSymbolCounter));
		}
	}

	/** Sink used to generate binding. */
	private class Let extends Link
	{
		// State.
		private byte last = 0; // number of processed arguments
		private Object value; // bound value
		private Variable bound; // bound variable

		// Constructor.
		Let(Link parent)
		{
			super(parent);
		}

		// Link overrides.
		@Override
		Object lookup(Variable variable)
		{
			return variable.equals(bound) ? value : parent.lookup(variable);
		}

		@Override
		String binderString()
		{
			return " " + bound + "=" + value;
		}

		public void store(Object sub)
		{
			// Deal differently with the two subterms.
			switch (++last)
			{
				case 1 :
					// First argument is type...ignored in the dynamic case!
					break;
				case 2 :
					// Second subterm is the value.
					value = sub;
					break;
				case 3 :
					// Third subterm is the body, which should have a binder.
					assert bound != null : "Bound variable missing in third argument of Let[type, value, variable.body].";
					parent.store(sub);
					break;
				default :
					throw new IllegalArgumentException("Must have form Let[value, variable.body].");
			}
		}

		@Override
		public Sink binds(Variable[] binders)
		{
			assert last == 2 : "Binders only allowed on third argument of Let[type, value, variable.body]";
			assert binders.length == 1 : "Only one binder allowed in Let[type, value, variable.body]";
			bound = binders[0];
			assert bound != null : "Attempt to bind null variable name?!?";
			return this;
		}

		@Override
		public Sink end()
		{
			assert bound != null : "Bound variable missing in third argument of Let[type, value, variable.body].";
			assert last == 3 : "Wrong argument count for Let[type, value, variable.body]";
			return super.end();
		}
	}

	/** Helper for generating Java source. */
	private abstract class JavaLink implements Sink
	{
		// State.
		/** Parent link. */
		final JavaLink parent;
		/** Index. */
		byte index;
		/** Expression, so far. */
		final StringBuilder expression = new StringBuilder();

		// Constructor.
		/**
		 * Create link for source creation...
		 * @param parent link for parent
		 */
		JavaLink(JavaLink parent)
		{
			this.parent = parent;
		}

		// Methods.
		/** Get the builder. */
		SourceBuilder java()
		{
			return parent.java();
		}

		/** Lookup variable up the chain. */
		String lookup(Variable variable)
		{
			return parent.lookup(variable);
		}

		/**
		 * Do everything that needs to be done after the n'th argument (and before the n+1'st).
		 * @param n the argument number (0 means before the first argument)
		 * @param end whether this was the last argument
		 */
		void next(int n, boolean end)
		{}

		// Maker...
		final public Constructor makeConstructor(Object object)
		{
			return JoelFactory.this.makeConstructor(object);
		}
		
		public Constructor makeLiteral(Object object, String sort)
		{
			return JoelFactory.this.makeLiteral(object, sort);
		}

		final public Variable makeVariable(String name, boolean promiscuous)
		{
			return JoelFactory.this.makeVariable(name, promiscuous);
		}
		
		final public Variable makeVariable(String name, boolean promiscuous, boolean blocking, boolean shallow)
		{
			return JoelFactory.this.makeVariable(name, promiscuous, blocking, shallow);
		}

		final public Variable freeVariable(String name, boolean promiscuous, boolean create)
		{
			return JoelFactory.this.freeVariable(name, promiscuous, create);
		}


		final public Variable freeVariable(String name, boolean promiscuous, boolean blocking, boolean shallow, boolean create)
		{
			return JoelFactory.this.freeVariable(name, promiscuous, blocking, shallow, create);
		}

		
		final public Sink makeBuffer(Maker.CallBack callBack)
		{
			return JoelFactory.this.makeBuffer(callBack);
		}

		// Sink...
		public Sink binds(Variable[] binders)
		{
			throw new UnsupportedOperationException("Binders not allowed for " + getClass().getName());
		}

		public Sink use(Variable variable)
		{
			next(index++, false);
			expression.append(lookup(variable));
			return this;
		}

		public Sink start(Constructor constructor)
		{
			Object object = constructor.object();
			if (object instanceof Category)
				return ((Category) object).javaPush(JoelFactory.this, this);

			// Sequences add head as statement.
			if (Util.isCons(constructor))
				return new JavaStatement(this);
			if (Util.isNull(constructor))
				return new JavaExpression(this, "", false, "", false, "", "", ""); // prints nothing

			// Fall back to just use the constructor base object symbol as a string.
			return new JavaExpression(this, "\"", true, "\"", false, "", "", "");
		}

		public Sink end()
		{
			return parent;
		}

		public Sink startMetaApplication(String name)
		{
			throw new UnsupportedOperationException("ObjectGenerator does not support meta-applications!");
		}

		public Sink endMetaApplication()
		{
			assert false : "No meta-application to end.";
			return null;
		}

		public Sink copy(Copyable source, boolean discard)
		{
			// Generic case: get source to copy itself.
			return source.copy(this, discard, new LinkedExtensibleMap<Variable, Variable>());
		}
	}

	/** Helper for generating Java expression. */
	private class JavaExpression extends JavaLink
	{
		// State.
		final String pre, sep1, sep2, sep3s, post;
		final boolean literal1, literal2;
		byte last;

		// Constructor.
		/**
		 * Create link for expression with subexpressions.
		 * @param parent link for parent
		 * @param pre text before subexpressions
		 * @param literal1 first subexpressions should be used as literal name (not expression)
		 * @param sep1 separator after first argument
		 * @param literal2 second subexpressions should be used as literal name (not expression)
		 * @param sep2 separator after second argument
		 * @param sep3s separator after third and following (but not last) argument
		 * @param post text after subexpressions
		 */
		JavaExpression(JavaLink parent, String pre, boolean literal1, String sep1, boolean literal2, String sep2, String sep3s,
				String post)
		{
			super(parent);
			assert parent != null : "Cannot create non-root expression";
			this.pre = pre;
			this.literal1 = literal1;
			this.sep1 = sep1;
			this.literal2 = literal2;
			this.sep2 = sep2;
			this.sep3s = sep3s;
			this.post = post;
		}

		// JavaLink
		@Override
		void next(int n, boolean end)
		{
			switch (n)
			{
				case 0 :
					expression.append(pre);
					if (end)
						expression.append(post);
					break;
				case 1 :
					expression.append(sep1);
					if (end)
						expression.append(post);
					break;
				case 2 :
					expression.append(sep2);
					if (end)
						expression.append(post);
					break;
				default :
					expression.append(end ? post : sep3s);
					break;
			}
		}

		public Sink end()
		{
			java().wrapExpression("", post);
			return super.end();
		}
	}

	/**
	 * Invoke named static method of class.
	 * @param <T> class type
	 * @param clazz to invoke method on
	 * @param name name of method
	 * @param arguments to method
	 * @return result of the invocation
	 */
	@SuppressWarnings("unchecked")
	static <T> Object invokeStatic(Class<T> clazz, String name, List<Object> arguments)
	{
		assert clazz != null : "Missing class?!?";
		assert name != null : "Missing method name ?!?";
		try
		{
			final int arity = arguments.size();
			final Object[] argument = arguments.toArray();
			final Class[] actual = new Class[arity];
			for (int i = 0; i < arity; ++i)
				actual[i] = (argument[i] == null ? Object.class : argument[i].getClass());

			// Invoke the first method that matches...
			// NOTE: the following does NOT work:
			//  java.lang.reflect.Method m = clazz.getMethod(methodName, signature);
			TryMethod : for (java.lang.reflect.Method m : clazz.getMethods())
			{
				Class[] declared = m.getParameterTypes();
				if (arity == declared.length && name.equals(m.getName()))
				{
					for (int i = 0; i < arity; ++i)
					{
						if (argument[i] != null && !isAssignableFrom(declared[i], actual[i]))
							continue TryMethod;
					}
					// Got through: found it!
					return m.invoke(null, argument);
				}
			}
			if (arity == 0)
			{
				// No method found. Try the fields!
				for (java.lang.reflect.Field f : clazz.getFields())
					if (name.equals(f.getName()))
						return f.get(null);
			}
			// Did not find it...fail miserably.
			throw new NoSuchMethodException("No " + clazz.getName() + "method " + name + types(actual));
		}
		catch (InvocationTargetException e)
		{
			throw new RuntimeException(e);
		}
		catch (SecurityException e)
		{
			throw new RuntimeException(e);
		}
		catch (NoSuchMethodException e)
		{
			throw new RuntimeException(e);
		}
		catch (IllegalArgumentException e)
		{
			throw new RuntimeException(e);
		}
		catch (IllegalAccessException e)
		{
			throw new RuntimeException(e);
		}
	}

	/**
	 * Helper to locate and invoke a constructor for a given class.
	 * @param <T> type of class to instantiate
	 * @param clazz the class to instantiate
	 * @param arguments for constructor
	 * @return instance!
	 */
	@SuppressWarnings("unchecked")
	public static <T> T newInstance(Class<T> clazz, List<Object> arguments)
	{
		try
		{
			assert clazz != null : "Missing class?!?";
			final int arity = arguments.size();

			if (arity == 0)
				return clazz.newInstance();

			final Class[] actual = new Class[arity];
			final Object[] argument = arguments.toArray();
			for (int i = 0; i < arity; ++i)
				actual[i] = (argument[i] == null ? Object.class : argument[i].getClass());

			// Invoke the first constructor that matches...
			// NOTE: the following does NOT work:
			//  java.lang.reflect.Constructor<?> c = clazz.getConstructor(signature);
			TryConstructors : for (java.lang.reflect.Constructor c : clazz.getConstructors())
			{
				Class[] declared = c.getParameterTypes();
				if (arity == declared.length)
				{
					for (int i = 0; i < arity; ++i)
					{
						if (argument[i] != null && !isAssignableFrom(declared[i], actual[i]))
							continue TryConstructors;
					}
					// Got through: found it!
					return (T) c.newInstance(argument);
				}
			}
			// Did not find it...fail miserably.
			throw new NoSuchMethodException("No " + clazz.getName() + types(actual));
		}
		catch (InvocationTargetException e)
		{
			throw new RuntimeException(e);
		}
		catch (IllegalArgumentException e)
		{
			throw new RuntimeException(e);
		}
		catch (InstantiationException e)
		{
			throw new RuntimeException(e);
		}
		catch (IllegalAccessException e)
		{
			throw new RuntimeException(e);
		}
		catch (SecurityException e)
		{
			throw new RuntimeException(e);
		}
		catch (NoSuchMethodException e)
		{
			throw new RuntimeException(e);
		}
	}

	/**
	 * Invoke named method on object.
	 * @param <T> class type
	 * @param object to invoke method on
	 * @param name name of method
	 * @param arguments to method
	 * @return result of the invocation
	 */
	@SuppressWarnings("unchecked")
	static <T> Object invoke(T object, String name, List<Object> arguments)
	{
		assert object != null : "Missing object?!?";
		assert name != null : "Missing method name ?!?";
		try
		{
			final Class clazz = object.getClass();
			final int arity = arguments.size();
			final Object[] argument = arguments.toArray();
			final Class[] actual = new Class[arity];
			for (int i = 0; i < arity; ++i)
				actual[i] = (argument[i] == null ? Object.class : argument[i].getClass());

			// Invoke the first method that matches...
			// NOTE: the following does NOT work:
			//  java.lang.reflect.Method m = object.class.getMethod(methodName, signature);
			TryMethod : for (java.lang.reflect.Method m : clazz.getMethods())
			{
				Class[] declared = m.getParameterTypes();
				if (arity == declared.length && name.equals(m.getName()))
				{
					for (int i = 0; i < arity; ++i)
					{
						if (argument[i] != null && !isAssignableFrom(declared[i], actual[i]))
							continue TryMethod;
					}
					// Got through: found it!
					if (arity == 1)
						return m.invoke(object, argument[0]);
					else
						return m.invoke(object, argument);
				}
			}
			if (arity == 0)
			{
				// No method found. Try the fields!
				for (java.lang.reflect.Field f : clazz.getFields())
					if (name.equals(f.getName()))
						return f.get(object);
			}
			// Did not find it...fail miserably.
			throw new NoSuchMethodException("No " + clazz.getName() + " method " + name + types(actual));
		}
		catch (InvocationTargetException e)
		{
			throw new RuntimeException(e.getCause());
		}
		catch (SecurityException e)
		{
			throw new RuntimeException(e);
		}
		catch (NoSuchMethodException e)
		{
			throw new RuntimeException(e);
		}
		catch (IllegalArgumentException e)
		{
			throw new RuntimeException(e);
		}
		catch (IllegalAccessException e)
		{
			throw new RuntimeException(e);
		}
	}

	/** Helper for generating Java statement. */
	private class JavaStatement extends JavaLink
	{
		// State.
		boolean following;

		// Constructor.
		JavaStatement(JavaLink parent)
		{
			super(parent);
		}

		// Sink...
		public Sink start(Constructor constructor)
		{
			// Make previous value into a statement.
			if (following)
				java().addStatement(java().wrapExpression("", ";").harvest());
			else
				following = true;
			return super.start(constructor); // 
		}
	}

	/** Print signature array. */
	static String types(Class<?>[] classes)
	{
		StringBuilder b = new StringBuilder();
		boolean first = true;
		for (Class<?> c : classes)
		{
			b.append(first ? '(' : ',');
			b.append(c.getName());
			first = false;
		}
		b.append(')');
		return b.toString();
	}
}
