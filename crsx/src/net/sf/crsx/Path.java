/* Copyright © 2008, 2011 IBM Corporation. */

package net.sf.crsx;

import java.util.ArrayList;
import java.util.List;

import net.sf.crsx.generic.PropertiesConstraintsWrapper;
import net.sf.crsx.generic.PropertiesWrapperConstructor;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.Util;

/**
 * Immutable path in {@link Term}s.
 * A path can be used to identify  a subterm as well as create a copy where a particular subterm has been replaced by another.
 * Paths are independent of the term they are applied to, however, paths are only valid for terms where the path can be followed,
 * and the methods generally throw {@link IndexOutOfBoundsException} when a path attempts to leave a term.
 * <p>
 * In addition,
 * <ul>
 * <li>{@link #precedes(Path)} and {@link #meet(Path)} implements the <em>prefix order lower semilattice</em> 
 * 	where a.precedes(b) if one can extend the a path to b (including trivially), and
 * 	a.meet(b) is the common prefix of the a and b paths.
 * 
 * <li>{@link #compareTo(Path)} implements the <em>lexicographic</em> total ordering
 * 	that extends the prefix ordering so that any paths can be compared and a&lt;b implies that
 *		the first extension from the common prefix of a and b are ordered as follows:
 *		<ul>
 *		<li>{@link #extend(int)} &lt; {@link #extend(String)} &lt; {@link #extend(Variable)}.
 *		<li>{@link #extend(int)} steps are ordered as the index.
 *		<li>{@link #extend(String)} steps are ordered as the string ordering of the property name.
 *		<li>{@link #extend(Variable)} steps are ordered by their {@link System#identityHashCode(Object)}.
 *		</ul>
 * </ul>
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: Path.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public abstract class Path implements Comparable<Path>, MeetSemiLattice<Path>
{
	// State.
	
	/** Prefix path. */
	final Path prefix;
	/** Prefix step level. */
	final int level;
	
    // Constructor.

    /** Internal constructor for non-empty paths. */
    protected Path(Path prefix)
    {
    	this.prefix = prefix;
    	this.level = (prefix == null ? 0 : prefix.level+1);
    }
    
    // Methods.

    /** Whether this path is the empty path. */
    public boolean isEmpty()
    {
        return false;
    }
    
    /**
     * Return the subterm of term corresponding to the path.
     * Returns the identity for the {@link #EMPTY} path.
     * @throws IndexOutOfBoundsException if the term does not permit the path
     */
    abstract public Term of(Term term);

    /** Extend the path to select the index't subterm of what it selects now. */
    final public Path extend(int index)
    {
    	return new Sub(this, index);
    }

    /** Extend the path to select the named property of what it selects now. */
    final public Path extend(String name)
    {
    	return new NamedProperty(this, name);
    }

    /** Extend the path to select the variable property of what it selects now. */
    final public Path extend(Variable variable)
    {
    	return new VariableProperty(this, variable);
    }

    /**
     * Make a copy of context term where the subterm corresponding to path is replaced with the plug term.
     *
     * @param sink to send the copy to
     * @param context term to copy except for the subterm at path
     * @param discardContext whether context term is known to never be used after this call
     * @param binders variables used in plug for those of binders(context)
     * @param plug term to insert at path
     * @param discardPlug whether plug term is known to never be used after this call
     * @return sink after copy has been received
     * @throws IndexOutOfBoundsException if the term does not permit the path
     */
    final public Sink plug(Sink sink, Term context, boolean discardContext, Variable[] binders, Copyable plug, boolean discardPlug)
    {
    	return plugr(sink, Path.EMPTY, context, discardContext, 0,  new Variable[binders.length], binders, plug, discardPlug, LinkedExtensibleMap.EMPTY_RENAMING);
    }
    /**
     * Helper to support {@link #plug(Sink, Term, boolean, Variable[], Copyable, boolean)}.
     * 
     * @param sink to send the copy of subContext to
     * @param prefix path of subContext subterm in original context term
     * @param restContext fragment of original context to emit in this instance
     * @param discardContext whether context term is known to never be used elsewhere
     * @param contextBindersUsed number of variables in prefixBound already allocated
     * @param contextBinders variables bound by context (<b>note:</b> mutated continuously to be just right when hole encountered)
     * @param plugBinders variables in plug corresponding to bound variables
     * @param plug term to plug
     * @param discardPlug whethre term to plug is known to never be used elsewhere
     * @param renames variable renamings in effect
     * @return sink after copy of subContext fragment has been received
     */
    private Sink plugr(Sink sink, final Path prefix, final Term restContext, final boolean discardContext, final int contextBindersUsed, final Variable[] contextBinders, final Variable[] plugBinders, final Copyable plug, final boolean discardPlug, final ExtensibleMap<Variable, Variable> renames)
    {
		if (equals(prefix))
		{
			// This invocation corresponds to the hole...plug it!
			if (contextBindersUsed != plugBinders.length)
				throw new IndexOutOfBoundsException("Context mistake: free and bound variable lists not consistent!");
			return plug.copy(sink, discardPlug, renames.extend(plugBinders, contextBinders));
		}

		if (!prefix.precedes(this))
		{
			// This invocation is not on the path to the hole...just copy!
			return restContext.copy(sink, discardContext, renames);
		}

		// This invocation is along the path to the hole!

		// (Meta-)properties wrapper, if any...
		if (restContext instanceof PropertiesConstraintsWrapper)
		{
			// TODO: permit plugging property paths.
			sink = PropertiesWrapperConstructor.start(sink, restContext);
		}
		
		// Term.
		switch (restContext.kind())
		{
			case CONSTRUCTION : {
				Constructor c = restContext.constructor();
				sink = sink.start(c);
				for (int i = 0; i < restContext.arity(); ++i)
				{
					final Path p = prefix.extend(i);
					final Term t = restContext.sub(i);
					final Variable[] bs = restContext.binders(i);
					ExtensibleMap<Variable, Variable> rs = renames;
					if (bs.length > 0)
					{
						Variable[] subBinders = new Variable[bs.length];
						for (int j = 0; j < bs.length; ++j)
						{
							Variable b = bs[j];
							Variable b2 = sink.makeVariable(b.name(), b.promiscuous());
							if (contextBindersUsed+j < contextBinders.length)
								contextBinders[contextBindersUsed+j] = b2;
							subBinders[j] = b2;
						}
						sink = sink.binds(subBinders);
						rs = rs.extend(bs, subBinders);
					}
					sink = plugr(sink, p, t, discardContext, contextBindersUsed + bs.length, contextBinders, plugBinders, plug, discardPlug, rs);
				}
				sink = sink.end();
				break;
			}

			case VARIABLE_USE : {
				Variable v = restContext.variable();
				Variable v2 = renames.get(v);
				sink = sink.use(v2 != null ? v2 : v);
				break;
			}

			case META_APPLICATION : {
				String mv = restContext.metaVariable();
				sink = sink.startMetaApplication(mv);
				for (int i = 0; i < restContext.arity(); ++i)
				{
					Term tSub = restContext.sub(i);
					Path pSub = prefix.extend(i);
					sink = plugr(sink, pSub, tSub, discardContext, contextBindersUsed, contextBinders, plugBinders, plug, discardPlug, renames);
				}
				sink = sink.endMetaApplication();
				break;
			}
		}

		// Terminate meta-properties wrapper, if any.
		if (restContext instanceof PropertiesConstraintsWrapper)
			sink = sink.end();
		
		return sink;
    }

    /** Return all binders on the subterm of term bound along the path. */
    final public Variable[] binders(Term term)
    {
    	List<Variable> binders = new ArrayList<Variable>();
    	addBinders(term, binders);
    	return binders.toArray(new Variable[binders.size()]);
    }
    /** Add the binders in term to binders list. */
    protected void addBinders(Term term, List<Variable> binders)
    {}
    
    // Comparable...
    
	public int compareTo(Path other)
	{
		// Build static links to path components.
		final Path[] p1 = new Path[level+1]; {Path p = this; for (int i = level; i>=0; --i) {p1[i] = p; p = p.prefix;}}
		final Path[] p2 = new Path[other.level+1]; {Path p = other; for (int i = other.level; i>=0; --i) {p2[i] = p; p = p.prefix;}}
		int k = 0;
		
		while (k < p1.length && k < p2.length && p1[k].compareLastStep(p2[k]) == 0) ++k;
		
		if (k == p1.length)
			return (k == p2.length ? 0 : -1);
		else if (k == p2.length)
			return 1;
		else
			return p1[k].compareLastStep(p2[k]);
	}
    /** Whether this and the other path have the same last step (supports {@link #compareLastStep(Path)} and {@link #equals}). */
    abstract protected int compareLastStep(Path path);

	// PartialOrder...
	
	public boolean precedes(Path other)
	{
		// Check that this is a prefix of other.
		if (level > other.level) return false;
		while (level < other.level) other = other.prefix;
		assert level == other.level;
		return equals(other);
	}
	
	// MeetSemiLattice...
	
	public Path meet(Path other)
	{
		// Find common prefix of this and other.
		Path shorter, longer; if (level <= other.level) {shorter = this; longer = other;} else {shorter = other; longer = this;}
		while (shorter.level < longer.level) longer = longer.prefix;
		assert shorter.level == longer.level;
		while (!shorter.equals(longer)) {shorter = shorter.prefix; longer = longer.prefix;}
		assert shorter.equals(longer);
		return shorter;
	}

    // Object...

    @Override
    public boolean equals(Object other)
    {
    	Path path = (Path) other;
    	return this == path || (level == path.level  && compareLastStep(path) == 0 && prefix.equals(path.prefix));
    }
    
    @Override
    final public String toString()
    {
    	StringBuilder b = new StringBuilder();
    	appendTo(b);
    	return b.toString();
    }
    /** Helper to accumulate string value. */
    abstract protected void appendTo(StringBuilder builder);

    // Constants.
    
    /** The empty path singleton. */
    public final static Path EMPTY = new Path(null)
    {
        @Override
        public boolean isEmpty()
        {
            return true;
        }
        @Override
        public Term of(Term term)
        {
            return term;
        }
        @Override
        public boolean equals(Object other)
        {
            return other == EMPTY; // exploits singleton
        }
        @Override
		public int compareTo(Path o)
		{
			return o.isEmpty() ? 0 : -1;
		}
        @Override
		public Path meet(Path o)
		{
			return this;
		}
        @Override
		public boolean precedes(Path o)
		{
			return true;
		}
        @Override
		protected int compareLastStep(Path o)
		{
            return o.isEmpty() ? 0 : -1;
		}
        @Override
		protected void appendTo(StringBuilder builder)
        {
        	builder.append("$");
        }
    };
    
    // Helper classes.
    
    /** Path that ends in argument subterm. */
    protected final static class Sub extends Path
    {
    	// State.
    	final int index;

    	// Constructor.
    	protected Sub(Path prefix, int index)
    	{
    		super(prefix);
    		this.index = index;
    	}

    	// Path.
    	@Override
    	public Term of(Term term)
    	{
    		return prefix.of(term).sub(index);
    	}
		@Override
		protected void addBinders(Term term, List<Variable> binders)
		{
			prefix.addBinders(term, binders);
			for (Variable b : prefix.of(term).binders(index))
				binders.add(b);
		}
		@Override
		protected int compareLastStep(Path path)
		{
			return path instanceof Sub ? (index - ((Sub) path).index) : -1;
		}
		@Override
		protected void appendTo(StringBuilder builder)
        {
			prefix.appendTo(builder);
        	builder.append("." + index);
        }
    }

    /** Helper class for path extended to named property. */
    public final static class NamedProperty extends Path
    {
    	// State.
    	final String property;

    	// Constructor.
    	public NamedProperty(Path prefix, String property)
    	{
    		super(prefix);
    		this.property = property;
    	}
    	
    	// Path...
    	@Override
    	public Term of(Term term)
    	{
    		return Util.propertiesHolder(prefix.of(term)).getProperty(property);
    	}
		@Override
		protected int compareLastStep(Path path)
		{
			// Named properties compare internally as their property name and otherwise follow sub and precede variable steps.
			return path instanceof NamedProperty ? property.compareTo(((NamedProperty) path).property) : path instanceof Sub ? -1 : 1;
		}
		@Override
		protected void appendTo(StringBuilder builder)
        {
			prefix.appendTo(builder);
        	builder.append("." + Util.externalizeConstructor(property));
        }
    }

    /** Helper class for path extended to variable property. */
    public final static class VariableProperty extends Path
    {
    	// State.
    	final Variable property;

    	// Constructor.
    	public VariableProperty(Path prefix, Variable property)
    	{
    		super(prefix);
    		this.property = property;
    	}
    	
    	// Path...
    	@Override
    	public Term of(Term term)
    	{
    		return Util.propertiesHolder(prefix.of(term)).getProperty(property);
    	}
		@Override
		protected int compareLastStep(Path path)
		{
			// Variable properties compare internally by hashcode and externally come after otrher forms. 
			return path instanceof VariableProperty ? System.identityHashCode(property) - System.identityHashCode(((VariableProperty) path).property) : 1;
		}
		@Override
		protected void appendTo(StringBuilder builder)
        {
			prefix.appendTo(builder);
        	builder.append("." + Util.externalizeVariable(property.name()));
        }
    }
}
