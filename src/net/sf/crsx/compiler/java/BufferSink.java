// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import static net.sf.crsx.compiler.java.Referenceable.LINK;
import static net.sf.crsx.compiler.java.Referenceable.LINK_COUNT;
import static net.sf.crsx.compiler.java.Referenceable.LINK_LINK;
import static net.sf.crsx.compiler.java.Referenceable.UNLINK;
import static net.sf.crsx.compiler.java.Term.ARITY;
import static net.sf.crsx.compiler.java.Term.IS_DATA;
import static net.sf.crsx.compiler.java.Term.IS_NF;
import static net.sf.crsx.compiler.java.Term.IS_CLOSED;
import static net.sf.crsx.compiler.java.Term.IS_VARIABLE_USE;
import static net.sf.crsx.compiler.java.Term.RANK;
import static net.sf.crsx.compiler.java.Term.SETSUB;
import static net.sf.crsx.compiler.java.Term.SUB;
import static net.sf.crsx.compiler.java.Variable.MAKE_VARIABLE;

/**
 * Buffer Sink
 * 
 * Correspond to the bufferXXX static functions in crsx.c 
 * 
 * @author <a href="researcher.watson.ibm.com/researcher/view.php?person=us-villard">Lionel Villard</a>.
 */
final public class BufferSink extends Sink
{
	// Constant

	/** Buffer segment size */
	final public static int BUFFER_SEGMENT_SIZE = 127;

	/** Special not-closed marker */
	final public static VariableSetLink NOT_CLOSED = VariableSetLink.add(null, MAKE_VARIABLE("dummy", false, false));
	
	// Static

	/** Free buffer. */
	final public static void freeBuffer(Sink sink)
	{}

	/** Create a new buffer sink */
	final public static Sink makeBuffer()
	{
		return new BufferSink();
	}

	/** Extract the constructed term */
	final public static Term bufferTerm(Sink sink)
	{
		final BufferSink buffer = (BufferSink) sink;
		assert buffer.lastTop < 0;
		final Term term = buffer.term;
		Crsx.check(term);
		return term;
	}

	// State

	/** The term collected by the buffer (after it is done) */
	public Term term;

	/**  the first segment; all allocated segments available through segment ->next chain TODO: include first segment here! */
	public BufferSegment first;

	/**  the last segment (with top of stack in it) or NULL when empty */
	public BufferSegment last;

	/** index of top entry (in last segment) or <0 when empty */
	public int lastTop;

	/** local weakenings for next START  */
	public VariableSetLink pendingWeakenings;

	/** named properties for next START  */
	public NamedPropertyLink pendingNamedProperties;

	/** Variable properties for next START  */
	public VariablePropertyLink pendingVariableProperties;

	/** Is pending named properties closed */
	public boolean namedPropertiesClosed;
	
	// Constructors

	public BufferSink()
	{
		this.lastTop = -1;
		this.namedPropertiesClosed = true;
	}

	// Buffer manipulation

	/**
	 * Push term on stack.
	 * 
	 * @param term Reference is transferred
	 */
	final protected void bufferPush(Term term)
	{
		++this.lastTop;
		if (last == null || lastTop >= BUFFER_SEGMENT_SIZE)
		{
			if (last != null && last.next != null)
			{
				// Already got a segment ready
				assert last.next.previous == last;
				last = last.next;
			}
			else if (last == null && first != null)
			{
				// Reuse previous first segment.
				last = first;
			}
			else
			{
				// Insert an additional segment.
				BufferSegment segment = new BufferSegment();
				if (first == null)
				{
					assert last == null;
					first = segment;
				}
				else if (last != null)
				{
					assert first != null;
					last.next = segment;
				}
				segment.previous = last;
				segment.next = null;
				last = segment;
			}
			lastTop = 0;
		}
		last.termEntry[lastTop] = term;
		last.indexEntry[lastTop] = 0;
		last.freeVars[lastTop] = null;
	}

	final protected void bufferPop()
	{
		// Not needed in Java.
		//if (last.freeVars[lastTop] != null)
		//	last.freeVars[lastTop].unlink();
		
		--lastTop;
		if (lastTop < 0 && last != null)
		{
			// Pop last segment.
			last = last.previous;

			// Reset top.
			if (last != null)
				lastTop = BUFFER_SEGMENT_SIZE - 1;
		}
	}

	final protected void bufferInsert(Term childTerm, VariableSetLink freeVars)
	{
		assert childTerm != null;
		if (lastTop < 0)
		{
			term = childTerm; // global result term
		}
		else
		//(lastTop >= 0)
		{
			final Term term = last.termEntry[lastTop];
			final int index = last.indexEntry[lastTop];

			SETSUB(term, index, childTerm);
			last.indexEntry[lastTop] += 1;
			
			// Free variables are the union of all subterm free variables.
			if (freeVars == NOT_CLOSED)
			{
				//last.freeVars[lastTop].unlink(); Not needed in Java.
				last.freeVars[lastTop] = freeVars;
			}
			else if (freeVars != null && last.freeVars[lastTop] != NOT_CLOSED)
				last.freeVars[lastTop] = VariableSetLink.mergeAll(last.freeVars[lastTop], freeVars);			
			
		}
	}

	final protected Term bufferTopTerm()
	{
		assert lastTop >= 0 && last != null;

		return last.termEntry[lastTop];
	}

	final protected int bufferTopIndex()
	{
		assert lastTop >= 0 && last != null;

		return last.indexEntry[lastTop];
	}

	final protected VariableSetLink bufferTopFreeVars()
	{
		assert lastTop >= 0 && last != null;

		return last.freeVars[lastTop];
	}

	
	// Buffer management.

	@Override
	public Term term()
	{
		assert lastTop < 0;
		Crsx.check(term);
		return term;
	}

	@Override
	public Sink start(ConstructionDescriptor descriptor)
	{
		final Construction construction;

		if (pendingNamedProperties != null && namedPropertiesClosed && pendingNamedProperties.name != NamedPropertyLink.CLOSED_PROPERTY)
		{
			// Insert marker
			pendingNamedProperties = new NamedPropertyLink(NamedPropertyLink.CLOSED_PROPERTY, (Term)null,  pendingNamedProperties);
			pendingNamedProperties.nr = 1;
		}
		
		if (descriptor == Literal.LITERAL_CONSTRUCTION_DESC) // literal?
		{
			construction = new Literal(pendingWeakenings, pendingNamedProperties, pendingVariableProperties, null);
		}
		else
		{
			construction = new Construction(descriptor, pendingWeakenings, pendingNamedProperties, pendingVariableProperties,
			        false, false);
		}
		construction.nr = 1;

		// Already initialized
		//construction.nf = false;
		//construction.nostep = false;

		bufferPush(construction); // suspend current construction in favor of children
		
		pendingWeakenings = null;
		pendingNamedProperties = null;
		pendingVariableProperties = null;
		namedPropertiesClosed = true;

		return this;
	}

	@Override
	public Sink end(ConstructionDescriptor descriptor)
	{
		assert lastTop >= 0 : "Can't end non-started structure.";
		
		Construction childTerm = (Construction) bufferTopTerm(); // Reference is transferred: see bufferPop() below.
		assert ARITY(childTerm) == bufferTopIndex();
		
		// Update nf and nostep fields of construction.
		if (IS_DATA(childTerm))
		{
			boolean nf = true; // optimistic
			int i = ARITY(childTerm);
			while (nf && (--i) >= 0)
			{
				if (!IS_NF(SUB(childTerm, i)))
				{
					nf = false;
					break;
				}
			}
			childTerm.nf = nf;
		}
		else
		{
			childTerm.nostep = false;
		}
		
		
		// TODO: this does not seem to improve perf. More evaluation is needed.
		//if (Term.IS_CONSTRUCTION(childTerm))
		//	((Construction) childTerm).propagateWeakenings();
		
		// Update 'closed' flag
		VariableSetLink freeVars = bufferTopFreeVars(); // subterm free variables.
		// bufferTop(buffer)->freeVars = NULL;
		
		bufferPop();
		
		if (last != null)
		{
			Construction parentTerm = (Construction) bufferTopTerm();
			if (freeVars != null && freeVars != NOT_CLOSED)
			{
				// If free variables binders are defined at this level, remove them.
				freeVars = freeVars.removeAll(Term.BINDERS(parentTerm, bufferTopIndex()));
			}

			if (freeVars == null)
				childTerm.closed = true; // No free variables -> the term is closed.			
			
		}
		
		bufferInsert(childTerm, freeVars); // Transfer freeVars on parent.
		
		pendingWeakenings = null;
		pendingNamedProperties = null;
		pendingVariableProperties = null;
		namedPropertiesClosed = true;

		return this;
	}

	@Override
	public Sink literal(String text)
	{
		start(Literal.LITERAL_CONSTRUCTION_DESC);
		((Literal) bufferTopTerm()).text = text; // descriptor set by start
		end(Literal.LITERAL_CONSTRUCTION_DESC);
		return this;
	}

	@Override
	public Sink use(Variable variable)
	{
		VariableUse use = new VariableUse(variable);
		// use.term.descriptor = NULL; // this ensures the term is understood as a VariableUse (set by VariableUse constructor)
		bufferInsert((Term) LINK(use), VariableSetLink.add(null, variable));
	
		pendingWeakenings = null;
		pendingNamedProperties = null;
		pendingVariableProperties = null;
		return this;
	}

	@Override
	public Sink binds(Variable[] binds)
	{
		assert lastTop >= 0 : "Can only have binders on proper construction subterms";

		int index = bufferTopIndex();
		Term term = bufferTopTerm();

		assert term.descriptor != null;
		assert 0 <= index && index < ARITY(term);
		assert binds.length == RANK(term, index);

		final Construction c = (Construction) term;
		int binderOffset = Term.bindersOffset(c, index);
		for (int i = 0; i < binds.length; ++i)
		{
			c.binders[binderOffset + i] = binds[i];
		}
		//System.arraycopy(binds, 0, c.binders, bindersOffset(c, index), binds.length);
		return this;
	}

	@Override
	public Sink copy(Term term, SubstitutionFrame renamings)
	{	
		// If properties are the same and no additional weakenings, just share!
		if (IS_VARIABLE_USE(term)
		        || (pendingNamedProperties == ((Construction) term).namedProperties && 
		            pendingVariableProperties == ((Construction) term).variableProperties && 
		            pendingWeakenings == null))
		{
			UNLINK(pendingNamedProperties);
			pendingNamedProperties = null;
			UNLINK(pendingVariableProperties);
			pendingVariableProperties = null;
			
			bufferInsert(term, freeVars(term));  
			return this;
		}

		if (LINK_COUNT(term) == 1)
		{
			// Reuse original term (with updated properties and weakenings).
			Construction construction = (Construction) term;

			// Is there new properties/weakenings to copy?
			mergeProperties(construction);
			
			bufferInsert(term, freeVars(term));
		}
		else
		{
			// Term cannot be reused: copy
			
			if (IS_VARIABLE_USE(term))
			{
				USE(this, Term.VARIABLE(term));
				UNLINK(term);
			}
			else
			{
				// construction
				final Construction c = (Construction) term;

				// share properties and weakenings
				NamedPropertyLink namedLink = pendingNamedProperties;
				pendingNamedProperties = (NamedPropertyLink) LINK_LINK(c.namedProperties);
				VariablePropertyLink variableLink = pendingVariableProperties;
				pendingVariableProperties = (VariablePropertyLink) LINK_LINK(c.variableProperties);
				
				VariableSetLink weakeningLink = pendingWeakenings;
				pendingWeakenings = (VariableSetLink) LINK_LINK(c.weakenings);

				start(c.descriptor);

				pendingNamedProperties = namedLink;
				pendingVariableProperties = variableLink;
				pendingWeakenings = weakeningLink;

				mergeProperties((Construction) bufferTopTerm());

				if (Term.IS_LITERAL(term))
				{
					((Literal) bufferTopTerm()).text = ((Literal) term).text;
				}
				else
				{	
					final int a = ARITY(c);
					for (int i = 0; i < a; i++)
					{
						int rank = Term.RANK(c, i);
						if (rank == 0)
						{
							// Just copy
							copy(Term.LINK(SUB(c, i)), null);
						}
						else
						{
							// Term has binders... create new ones and substitute...
							// -- i'th subterm with binders, second and following copy: add new binders to substitution!
							// --- allocate substitution
							Variable[] oldBinders = Term.BINDERS(c, i);
							Variable[] subBinders = new Variable[rank]; // escapes
							VariableUse[] subUses = new VariableUse[rank]; // does not escape
							
							// RENAME_ALL make sure weakenings are preserved.
							SubstitutionFrame subSubstitution = new SubstitutionFrame(null, 0, rank, oldBinders, subUses, SubstitutionFrame.RENAME_ALL);

							// --- populate per binder
							for (int j = 0; j < rank; ++j)
							{
								String oldname = oldBinders[j].name;
								int baseendp = oldname.lastIndexOf('_');
								String basename = oldname;
								if (baseendp != -1)
								{
									basename = basename.substring(0, baseendp);
								}
								boolean isLinear = Variable.IS_LINEAR(oldBinders[j]);
								subBinders[j] = Variable.MAKE_VARIABLE(oldBinders[j].name, true, isLinear); // escapes

								subUses[j] = new VariableUse(subBinders[j]); // escapes
								//subUses[j].descriptor = NULL;
								subUses[j].nr = 1;
								//subUses[j].variable = subBinders[j];
							}
							// --- send new binders
							binds(subBinders);

							Crsx.metaSubstitute(this, Term.LINK(SUB(term, i)), subSubstitution, null);
						}
					}
				}

				end(c.descriptor);
			}
			UNLINK(term);
		}

		//assert pendingWeakenings == null;
		assert pendingNamedProperties == null;
		assert pendingVariableProperties == null;

		return this;
	}


	@Override
	public Sink weakeningRef(Construction construction)
	{
		// Must be the first weakening event
		assert pendingWeakenings == null;
		
		pendingWeakenings = (VariableSetLink) LINK_LINK(construction.weakenings);
		return this;
	}

	@Override
	public Sink weaken(Variable variable)
	{
		if (variable.bound && VariableSetLink.variableSetLinkFor(pendingWeakenings, variable) == null) // only bound variables are kept weak
		{
			VariableSetLink link = new VariableSetLink();
			link.nr = 1;
			link.link = pendingWeakenings;
			link.variable = variable;
			pendingWeakenings = link;
		}
		return this;
	}

	@Override
	@Deprecated
	public Sink propertyRef(Construction construction)
	{
		return properties((NamedPropertyLink) LINK_LINK(construction.namedProperties), (VariablePropertyLink) LINK_LINK(construction.variableProperties));		
	}
	
	@Override
	public Sink properties(NamedPropertyLink namedProperties, VariablePropertyLink variableProperties)
	{
		// Must be first property event.
		assert pendingNamedProperties == null && pendingVariableProperties == null;

		pendingNamedProperties = namedProperties;
		pendingVariableProperties = variableProperties;
		
		namedPropertiesClosed = namedProperties == null || namedProperties.name == NamedPropertyLink.CLOSED_PROPERTY;		
		return this;
	}

	@Override
	public Sink propertyNamed(String name, Term term)
	{
		pendingNamedProperties = (NamedPropertyLink) LINK(new NamedPropertyLink(name, Term.LINK(term), pendingNamedProperties));
		namedPropertiesClosed &= IS_CLOSED(term);
		return this;
	}

	@Override
	public Sink propertyVariable(Variable variable, Term term)
	{
		pendingVariableProperties = (VariablePropertyLink) LINK(new VariablePropertyLink(variable, Term.LINK(term),
		        pendingVariableProperties));
		return this;
	}

	@Override
	public Sink propertyWeaken(Variable weakening)
	{
		// If so far no properties, ignore weakenings.
		
		if (weakening.bound && (pendingNamedProperties != null || pendingVariableProperties != null)) // only bound variables added...
		{
			{
				NamedPropertyLink link;
				for (link = pendingNamedProperties; link != null; link = link.link)
					if (link.name == NamedPropertyLink.CLOSED_PROPERTY || (link.name == null && link.termOrWeakening == weakening))
						return this; // escape because we already have this weakening!
				// TODO: rulescompiler should not insert redundant weakenings (for REBOUND variables)!
			}
			
			pendingNamedProperties = (NamedPropertyLink) LINK(new NamedPropertyLink(null, weakening, pendingNamedProperties));
			pendingVariableProperties = (VariablePropertyLink) LINK(new VariablePropertyLink(null, weakening,
			        pendingVariableProperties));
		}
		return this;
	}

	@Override
	public Sink propertiesReset()
	{
		UNLINK(pendingWeakenings);
		pendingWeakenings = null;
		UNLINK(pendingNamedProperties);
		pendingNamedProperties = null;
		UNLINK(pendingVariableProperties);
		pendingVariableProperties = null;
		return this;
	}

	// Helpers

	/**
	 * Helper merging pending properties and weakenings with the given construction properties and weakenings
	 * 
	 * @param construction
	 */
	protected void mergeProperties(Construction construction)
	{
		// Is there new named properties to copy?
		if (pendingNamedProperties != null && construction.namedProperties != pendingNamedProperties)
		{
			if (construction.namedProperties == null)
				construction.namedProperties = pendingNamedProperties; // transfer ref
			else
			{
				// Merge property lists. Unlink the single-linked prefix with the event-generated properties.
				NamedPropertyLink newTop = null, newLast = null;
				for (NamedPropertyLink link = pendingNamedProperties; link != null; link = link.link)
				{
					if (link == construction.namedProperties) // guard above ensures false on first iteration
						break; // avoid deep duplication of lists
					NamedPropertyLink newLink = new NamedPropertyLink(link);
					//newLink.link = null;
					//newLink.nr = 0;
					if (newLink.name != null)
						LINK(newLink.term());
					if (newTop != null)
						newLast.link = (NamedPropertyLink) LINK(newLink);
					else
						newTop = newLink;
					newLast = newLink;
				}
				newLast.link = construction.namedProperties; // transfer ref to old properties to tail of new.
				construction.namedProperties = (NamedPropertyLink) LINK_LINK(newTop);
				
				UNLINK(pendingNamedProperties);
			}
			assert construction.namedProperties == null || !construction.namedProperties.isCircular();
			pendingNamedProperties = null;
		}
		
		if (pendingNamedProperties != null)
		{
			UNLINK(pendingNamedProperties);
			pendingNamedProperties = null;
		}

		if (pendingVariableProperties != null && construction.variableProperties != pendingVariableProperties)
		{
			if (construction.variableProperties == null)
				construction.variableProperties = pendingVariableProperties;  // transfer ref
			else
			{
				// Merge property lists.
				VariablePropertyLink newTop = null, newLast = null;
				for (VariablePropertyLink link = pendingVariableProperties; link != null; link = link.link)
				{
					if (link == construction.variableProperties)
						break;

					VariablePropertyLink newLink = new VariablePropertyLink(link);
					//newLink.link = null;
					//newLink.nr = 0;
					if (newLink.variable != null)
						LINK(newLink.term());
					if (newTop != null)
						newLast.link = (VariablePropertyLink) LINK(newLink);
					else
						newTop = newLink;
					newLast = newLink;
				}
				newLast.link = construction.variableProperties;
				construction.variableProperties = (VariablePropertyLink) LINK(newTop);

				UNLINK(pendingVariableProperties);
			}			
			pendingVariableProperties = null;
		}
		if (pendingVariableProperties != null)
		{
			UNLINK(pendingVariableProperties);
			pendingVariableProperties = null;
		}
		
		if (pendingWeakenings != null)
		{
			if (construction.weakenings == null)
				construction.weakenings = pendingWeakenings; // Transfer ref
			else
			{
				if (construction.weakenings.nr == 1)
					construction.weakenings = VariableSetLink.mergeAll(pendingWeakenings, construction.weakenings); // Transfer ref
				else
					construction.weakenings = VariableSetLink.mergeAll(pendingWeakenings, construction.weakenings.copy()); // Transfer ref
			}
			
			pendingWeakenings = null;
		}		
	}

	final private VariableSetLink freeVars(Term term)
	{
		VariableSetLink freeVars;
		if (IS_VARIABLE_USE(term))
			freeVars = VariableSetLink.add(null, Term.VARIABLE(term));
		else
			freeVars = ((Construction) term).closed ? null : NOT_CLOSED;
		return freeVars;
	}

	// Inner classes

	class BufferSegment
	{
		public BufferSegment previous, next; // previous and next buffer segment (NULL for first/last)

		final public Term[] termEntry;
		final public int[] indexEntry;
		public VariableSetLink[] freeVars;

		public BufferSegment()
		{
			termEntry = new Term[BUFFER_SEGMENT_SIZE];
			indexEntry = new int[BUFFER_SEGMENT_SIZE];
			freeVars = new VariableSetLink[BUFFER_SEGMENT_SIZE];
		}
	};
}
