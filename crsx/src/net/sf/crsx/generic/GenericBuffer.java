/* Copyright (c) 2008 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.ArrayList;
import java.util.List;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Maker.CallBack;
import net.sf.crsx.Maker.ContinuationSinkSetter;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.util.DelegateMaker;
import net.sf.crsx.util.LinkedExtensibleMap;

/**
 * Generic buffer for capturing terms from a sink to a stored term, used internally by {@link GenericFactory}.
 * Not thread-safe: expects to be fully instantiated before being read.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericBuffer.java,v 3.0 2012/12/17 18:04:53 krisrose Exp $
 */
class GenericBuffer
{
	// State.
	
	/** For constructing the term. */
	final protected GenericFactory factory;
	
	/** Whether constructed terms are flexible... */
	final protected boolean flexibility;
	
	/** Current call-back. */
	protected Maker.CallBack callBack;
	
	/** Continuation {@link Sink} returned after buffer exhausted (and {@link #callBack} invoked). */
	protected Sink continuationSink;
	/** Helper to permit setting of the continuation. */
	final protected ContinuationSinkSetter continuationSinkSetter = new ContinuationSinkSetter()
		{
			public void setContinuationSink(Sink continuation)
			{
				continuationSink = continuation;
			}
		};

	// Constructor.
	
	/**
	 * Create buffer ready to build a sink that can accept a term.
	 * The constructed term will be a {@link GenericTerm}.
	 * @param flexible whether the returned terms will have {@link GenericTerm#isFlexible()}
	 * @param continuation the {@link Sink} to return after the {@link CallBack} has been invoked
	 * @param maker used to build the term
	 */
	protected GenericBuffer(GenericFactory factory, boolean flexible, Sink continuation)
	{
		this.factory = factory;
		this.flexibility = flexible;
		this.continuationSink = continuation;
	}
	
	// Methods.
	
	/**
	 * Create sink that will invoke the specified call-back when done
	 * @param callBack of which {@link Maker.CallBack#store(Variable[], Term, ContinuationSinkSetter)} is invoked when subterm finished
	 */
	public Sink sink(CallBack callBack)
	{
		this.callBack = callBack;
		return new BaseSink();
	}
	
	// Helper classes (that implement the receiving Sink in various stages).

	/** Root (and base) sink. */
	private class BaseSink extends DelegateMaker implements Sink
	{
		// State.
		/** Binders for next subterm. */
		Variable[] binders;

		// Constructor.
		BaseSink()
		{}

		// Methods.
		/** Store finished child subterms (with {@link #binders})! */
		Sink store(GenericTerm sub)
		{
			// This method is invoked by the completed term so invokes the call-back and passes control to the continuation.
			callBack.store(binders, sub, continuationSinkSetter);
			binders = null;
			return continuationSink;
		}
		
		// DelegateMaker...
        @Override
        final public Maker maker()
        {
	        return factory;
        }

		// Sink...
		public Sink binds(Variable[] binders)
		{
			// Create new variables and bind to them.
			assert this.binders == null : "cannot set multiple binder sets on subterm?!?";
			this.binders = binders;
			return this;
		}
		public Sink use(Variable variable)
		{
			return store(factory.newVariableUse(variable));
		}
		public Sink start(Constructor constructor)
		{
			// Normal constructor: Delegate to construction subsink whose .end() will call our store().
			return new ConstructionSubSink(this, constructor); // push!
		}
		public Sink end()
		{
			assert false : "No construction to end.";
			return null;
		}
		public Sink startMetaApplication(String name)
		{
			// Delegate to subsink whose .endMetaApplication() will call our store().
			return new MetaApplicationSubSink(this, name); // push!
		}
		public Sink endMetaApplication()
		{
			assert false : "No meta-application to end.";
			return null;
		}
		public Sink copy(Copyable source, boolean discard)
		{
			if (discard && source instanceof GenericTerm)
			{
				// The term can be reused instead of "copy & discard".
				return store((GenericTerm) source);
			}
			else
			{
				// Generic case: get source to copy itself into the buffer...
				return source.copy(this, discard, new LinkedExtensibleMap<Variable, Variable>());
			}
		}
	}
	 

	/** Sink instance used to populate {@link FixedGenericConstruction}. */
	private class ConstructionSubSink extends BaseSink
	{
		// State.
		private BaseSink parent; // where the entire construction should be added
		private Constructor constructor; // of construction
		private List<Variable[]> subBinds; // binders for subterms of construction
		private List<GenericTerm> subSub; // subterms of construction

		// Constructor.
		/**
		 * Sink to process the subterms of a construction.
		 * (Handles the children of the construction 
		 * @param parent that this subterm is added to
		 * @param constructor to use
		 */
		ConstructionSubSink(BaseSink parent, Constructor constructor)
		{
			this.parent = parent;
			this.constructor = constructor;
			subBinds = new ArrayList<Variable[]>();
			subSub = new ArrayList<GenericTerm>();
		}

		// BaseSink overrides.
		@Override
		Sink store(GenericTerm subTerm)
		{
			// Insert construction subterm in the right place.
			subBinds.add(binders != null ? binders : Sink.NO_VARIABLES);
			subSub.add(subTerm);
			binders = null;
			return this; // ready to add another subterm
		}
		@Override
		public Sink end()
		{
			Variable[][] bs = subBinds.toArray(new Variable[subBinds.size()][]);
			GenericTerm[] ss = subSub.toArray(new GenericTerm[subSub.size()]);
			if (constructor instanceof PropertiesWrapperConstructor)
            {
                // This ends a special property wrapper...
				/* KRIS...
                assert ss.length == 1 : "Property constraint wrapper can only wrap a single nonbinder term ("+Arrays.asList(ss)+")";
                assert bs[0].length == 0 : "Property constraint wrapper can only wrap term without binders";
                */
                return parent.store(PropertiesConstraintsWrapper.wrapWith((PropertiesWrapperConstructor) constructor, ss[0]));
            }
            else
			{
			    // Generic construction.
				return parent.store(factory.newConstruction(constructor, bs, ss));
			}
		}
	}

	/** Sink instance used to populate {@link GenericMetaApplication}. */
	private class MetaApplicationSubSink extends BaseSink
	{
		// State.
		private BaseSink parent; // where the entire construction should be added
		private String name; // of metavarible
		private List<Term> subSub; // subterms of construction

		// Constructor.
		/**
		 * Create sink that holds a constructor under construction [sic].
		 * @param parent that this subterm is added to
		 * @param symbol of constructor
		 */
		MetaApplicationSubSink(BaseSink parent, String name)
		{
			this.parent = parent;
			this.name = name;
			subSub = new ArrayList<Term>();
		}

		// BaseSink overrides.
		@Override
		Sink store(GenericTerm subTerm)
		{
			// Insert meta-application subterm in the right place.
			assert binders == null : "meta-application argument cannot have binders?!?";
			subSub.add(subTerm);
			return this; // ready to add another subterm
		}
		@Override
		public Sink binds(Variable[] oldBinders)
		{
			assert false : "Cannot have binders on subterm of meta-application!";
			return  this;
		}
		@Override
		public Sink endMetaApplication()
		{
			return parent.store(new GenericMetaApplication(factory, name, subSub.toArray(new GenericTerm[subSub.size()])));
		}
	}
}
