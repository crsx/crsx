/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx.generic;

import net.sf.crsx.CRS;
import net.sf.crsx.Constructor;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.util.Buffer;

/**
 * Construct sequence of multiple terms captured from a sink.
 * (Internal because the sequence uses destructive "tail updates" of {@link GenericTerm}.) 
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: SequenceBuffer.java,v 3.0 2012/12/17 18:04:54 krisrose Exp $
 */
public class SequenceBuffer extends Buffer
{
	/** The last cons unit of sequence. */
	GenericTerm tail;
	
	// Constructor.

	/**
	 * Create instance.
	 * @param maker for {@link Maker#makeBuffer(net.sf.crsx.Maker.CallBack)}
	 */
	public SequenceBuffer(GenericFactory maker)
	{
		super(maker);
	}
	
	// Buffer...
	
	public Sink sink()
	{
		storedBinders = Sink.NO_VARIABLES;
		storedTerm = null;
		tail = null;
		final Constructor cons = maker.makeConstructor(CRS.CONS_SYMBOL);
		final GenericTerm nil = ((GenericFactory) maker).newConstruction(maker.makeConstructor(CRS.NIL_SYMBOL), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
		
		return maker.makeBuffer(new Maker.CallBack()
		{
			@Override
			public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
			{
				if (binders == null) binders = Sink.NO_VARIABLES;
				Variable bss[][] = {binders, Sink.NO_VARIABLES};
				GenericTerm ss[] = {(GenericTerm) term, nil};
				GenericTerm newTail = ((GenericFactory) maker).newConstruction(cons, bss, ss);
				
				if (storedTerm == null)
				{
					storedTerm = newTail;
					tail = newTail;
				}
				else
				{
					assert tail != null : "Internal state of SequenceBuffer broken (tail==null)?!?";
					tail.replaceSub(1, Sink.NO_VARIABLES, newTail);
					tail = newTail;
				}
			}
		});
	}
}
