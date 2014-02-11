// Copyright (c) 2010, 2012 IBM Corporation.

package net.sf.crsx.compiler.java;

import static net.sf.crsx.compiler.java.Referenceable.LINK_COUNT;
import static net.sf.crsx.compiler.java.Referenceable.UNLINK;
import static net.sf.crsx.compiler.java.Referenceable.UNLINK_LINK;
import static net.sf.crsx.compiler.java.Sink.ADD_PROPERTY_NAMED;
import static net.sf.crsx.compiler.java.Sink.ADD_PROPERTY_VARIABLE;
import static net.sf.crsx.compiler.java.Sink.ADD_PROPERTY_WEAKEN;
import static net.sf.crsx.compiler.java.Sink.COPY;
import static net.sf.crsx.compiler.java.Sink.LITERALU;
import static net.sf.crsx.compiler.java.Sink.USE;
import static net.sf.crsx.compiler.java.Term.ARITY;
import static net.sf.crsx.compiler.java.Term.BINDER;
import static net.sf.crsx.compiler.java.Term.BINDERS;
import static net.sf.crsx.compiler.java.Term.IS_CONSTRUCTION;
import static net.sf.crsx.compiler.java.Term.IS_FUNCTION;
import static net.sf.crsx.compiler.java.Term.IS_LITERAL;
import static net.sf.crsx.compiler.java.Term.IS_NF;
import static net.sf.crsx.compiler.java.Term.IS_NO_STEP;
import static net.sf.crsx.compiler.java.Term.IS_VARIABLE_USE;
import static net.sf.crsx.compiler.java.Term.RANK;
import static net.sf.crsx.compiler.java.Term.SETSUB;
import static net.sf.crsx.compiler.java.Term.SUB;
import static net.sf.crsx.compiler.java.Term.VARIABLE;
import static net.sf.crsx.compiler.java.Variable.IS_LINEAR;
import static net.sf.crsx.compiler.java.Variable.MAKE_VARIABLE;
import static net.sf.crsx.compiler.java.NamedPropertyLink.IS_PROPERTY_CLOSED;

import java.io.IOException;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import net.sf.crsx.compiler.java.NamedPropertyLink.NamedPropertyLinkHolder;
import net.sf.crsx.compiler.java.VariablePropertyLink.VariablePropertyLinkHolder;
import net.sf.crsx.util.Util;

/**
 * Straight port of crsx.[h|c] to Java.
 * 
 * @author <a href="researcher.watson.ibm.com/researcher/view.php?person=us-villard">Lionel Villard</a>.
 */
final public class Crsx
{

	final private static boolean DEBUG = true;
	
	final public static void CRSX_CHECK_SORT(Term term, SortDescriptor sort)
	{
		//		if (term.descriptor.sortDescriptor != sort)
		//		{
		//			throw new RuntimeException("Invalid sort");
		//		}
	}

	final public static void WEAKENINGS_OF(Sink sink, Term term)
	{
		// TODO: this is not working and I don't know why.
		weakenings_of(sink, term);
	}

	final public static void WEAKENINGS_COPY(Term source, Term target)
	{
		//weakenings_copy(source, target);
	}

	final public static Term NORMALIZE(Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		return normalize(term, ancestors);
	}

	final public static Term COMPUTE(final Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		return IS_NF(term) ? term : compute(term, ancestors);
	}

	final public static Term FORCE(final Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		return IS_NO_STEP(term) ? term : force(term, ancestors);
	}

	final public static void SUBSTITUTE(final Sink sink, final Term term,  final SubstitutionFrame substitution, final Variable[] weakenings)
	{
		Crsx.metaSubstitute(sink, term, substitution, weakenings);
	}

	final public static void LOAD_TERM(Sink sink, String name)
	{
		throw new RuntimeException("Not implemented yet");
	}

	final public static void SAVE_TERM(String name, Term term)
	{
		throw new RuntimeException("Not implemented yet");
	}

	// Logger
	//final private static Logger LOGGER = Logger.getLogger(Crsx.class.getName());

	/////////////////////////////////////////////////////////////////////////////////
	//Weakening helper.

	public static void weakenings_of(Sink sink, Term term)
	{		
//		if (IS_CONSTRUCTION(term))
//		{
//			sink.weakeningRef((Construction) term);
//			/*Construction construction = (Construction) term;
//			VariableSetLink ws;
//			for (ws = construction.weakenings; ws != null; ws = ws.link)
//				sink.weaken(ws.variable);*/
//		}
	}

	public static void weakenings_copy(Term source, Term target)
	{
//		if (IS_CONSTRUCTION(source) && IS_CONSTRUCTION(target))
//		{
//			Construction sourceConstruction = (Construction) source;
//			Construction targetConstruction = (Construction) target;
//			VariableSetLink s, t = targetConstruction.weakenings;
//			for (s = sourceConstruction.weakenings; s != null; s = s.link)
//			{
//				if (VariableSetLink.variableSetLinkFor(t, s.variable) == null)
//				{
//					VariableSetLink newt = new VariableSetLink();
//					newt.variable = s.variable;
//					newt.link = t;
//					t = newt;
//				}
//			}
//			targetConstruction.weakenings = t;
//		}
	}

	/////////////////////////////////////////////////////////////////////////////////
	//Computation.

	// TODO: inline?
	public static class ContextEntry
	{
		Term term;
		int index;

		public ContextEntry(Term term, int index)
		{
			this.term = term;
			this.index = index;
		}

	};

	/**
	 * Standard normalization function.
	 * 
	 * Implements outermost evaluate-before-copy normalization: Repeatedly picks one of the following steps until DONE:
	 *(1) If term is marked as nf with no parent (so at the root of the nf subterm) then we are DONE.
	 *(2) If term is marked as nf with a parent and a following sibling then advance to the following sibling.
	 *(3) If term is marked as nf with a parent but no following sibling then pop to parent.
	 *(4) If term is a function invocation that is not marked as nostep and that we can in fact step then do so and update term to the result.
	 *(5) If term is a function invocation that is not marked as nostep and that we can in fact not step then mark it as nostep.
	 *(6) If term is a non-nf data term or a nostep function application with a non-nf child then push term and switch to that child.
	 *(7) If term is a non-nf data term or a nostep function application with only nf children then mark it as nf.
	 *
	 * NOTE:  
	 * The following C code:
	 * <pre>
	 *    normalize(&term)
	 * </pre>
	 * corresponds to the following Java code:
	 * <pre>
	 *   term = normalize(term)
	 * </pre>
	 * 
	 * @param term to normalize. The reference is transferred.
	 * @param ancestor terms
	 *
	 * @return updated term.
	 */
	public static Term normalize(Term term, ArrayList<Crsx.ContextEntry> stackold)
	{
		if (IS_NF(term))
			return term; // (0) if term is a variable or already in normal form then we are DONE.

		ArrayList<ContextEntry> stack = new ArrayList<Crsx.ContextEntry>();  // The stack owns references to terms
		while (true)
		{
			if (IS_NF(term))
			{
				if (emptyStack(stack)) // stack empty
				{
					// (1) If term is marked as nf (or a variable) with no parent (so at the root of the nf subterm) then we are DONE.
					//freeContextEntryStack(stack);
					//*termp = term; // updated term; reference transferred back.
					return term;
				}
				else
				{
					// Store term in normal form back to parent.
					Term parent = Term.LINK(topStack(stack).term);
					int parentIndex = topStack(stack).index;
					UNLINK(SUB(parent, parentIndex));
					SETSUB(parent, parentIndex, term); // term reference transferred to subterm

					final int parentArity = ARITY(parent);
					if (++parentIndex < parentArity)
					{
						// (2) If term is marked as nf (or a variable) with a parent and a following sibling then advance to the following sibling.
						topStack(stack).index = parentIndex;
						term = Term.LINK(SUB(parent, parentIndex));
						UNLINK(parent);
					}
					else
					{
						// (3) If term is marked as nf (or a variable) with a parent but no following sibling then pop to parent.
						term = parent;
						UNLINK(topStack(stack).term);
						popStack(stack);
						// TODO: swap the transfers to avoid extra UNLINK.
					}
				}
			}
			else if (IS_FUNCTION(term) && !IS_NO_STEP(term))
			{
				Sink sink = BufferSink.makeBuffer();
				//if (step(sink, term, ancestors)) // Reference is transferred and consumed only when step succeeds
				if (step(sink, term, stack)) // Reference is transferred and consumed only when step succeeds
				{
					// (4) If term is a function invocation that is not marked as nostep and that we can in fact step then do so and update term to the result.
					term = BufferSink.bufferTerm(sink); // Reference is transferred
				}
				else
				{
					// (5) If term is a function invocation that is not marked as nostep and that we can in fact not step then mark it as nostep.
					((Construction) term).nostep = true;
				}
				BufferSink.freeBuffer(sink); // always free buffer, even when not actually used!				
			}
			else
			{
				int index = 0;
				final int arity = ARITY(term);
				while (index < arity && IS_NF(SUB(term, index)))
					++index;
				if (index < arity)
				{
					// (6) If term is a non-nf data term or a nostep function application with a non-nf child then push term and switch to that child.
					if (IS_FUNCTION(term))
						((Construction) term).nostep = false;
					ContextEntry entry = new ContextEntry(Term.LINK(term), index);
					pushStack(stack, entry);
					UNLINK(term); // TODO: really just reference transfer from term to stack
					term = Term.LINK(SUB(term, index));
				}
				else
				{
					// (7) If term is a non-nf data term or a nostep function application with only nf children then mark it as nf.
					((Construction) term).nf = true;
				}		
			}
		}
	}

	/**
	 * Force term computation
	 * 
	 * @param term. The reference is transferred.
	 * @return
	 */
	final public static Term force(Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		assert term != null;
		if (!IS_NO_STEP(term))
		{
			while (IS_FUNCTION(term))
			{				
				Sink sink = new BufferSink();
				if (!step(sink, term, ancestors)) // Reference is transferred and consume only when succeed
				{
					((Construction) term).nostep = true;
					break;
				}
				term = sink.term(); // reload and try again...
				//FREE_BUFFER(sink);
			}
		}
		return term;
	}

	static int stepCount = 0;
	/**
	 * Execute one normalization step.
	 *
	 * <p>Weakenings on ancestors are preserved. This is safe because no existing variables not in the term scope
	 * can become in its scope. However some variables can disappear but still present in ancestor weakenings.   
	 * 
	 * @param sink
	 * @param term. The reference is transferred
	 * @param ancestor terms
	 * @return
	 */
	final static private boolean step(Sink sink, Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		assert check(term);

		if (DEBUG)
		{
			stepCount++;
			
			System.out.println("["+stepCount+"]step:" + term.descriptor.name(term) + "============================");
			
			try
            {
                fprintTermTop(System.out, term, 10000, new VariableSet(), 1, true, 8, true);
                System.out.println();
            }
            catch (IOException e)
            {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }		
		}
	
		boolean step = term.descriptor.step(sink, term, ancestors);
		
		return step;
	}

	/**
	 * Compute term
	 * 
	 * @param term. The reference is transferred
	 * @return
	 */
	public static Term compute(Term term, ArrayList<Crsx.ContextEntry> ancestors)
	{
		assert term != null;

		final Term rterm = normalize(term, ancestors);
		return rterm;
	}

	// Stack management

	final public static <T> void pushStack(ArrayList<T> stack, T element)
	{
		stack.add(element);
	}

	final public static <T> T popStack(ArrayList<T> stack)
	{
		return stack.isEmpty() ? null : stack.remove(stack.size() - 1);
	}

	final public static <T> T topStack(ArrayList<T> stack)
	{
		return stack.isEmpty() ? null : stack.get(stack.size() - 1);
	}

	final public static boolean emptyStack(ArrayList<?> stack)
	{
		return stack.isEmpty();
	}

	/////////////////////////////////////////////////////////////////////////////////
	//Substitution.
	//
	// Usage:
	// metaSubstitute(sink, term, substitution)
	// sink - where we send events to.
	// term - the redex fragment that we are copying.
	// substitution - captures the maps v1->Arg1,... derived from the fact that the pattern
	// had #Meta[ v1, ..., vN ] and the contraction had #Meta[ Arg1, ..., ArgN ].
	// weakenings - Additional weakenings on the term, excluding where variables are substituted.
	// renaming - whether substitution operates in renaming mode or not. When just renaming, variable scoping is preserved.
	//            
	//
	// NOTE: DOES unlink (or transfer) both term and substitution.
	//
	// The helpers take three additional arguments:
	// weakened - the variables in the substitution that have been eliminated locally by weakenings.
	// exhausted - the variables in the substitution that are linear and have been globally eliminated.	
	//

	final public static void metaSubstitute(Sink sink, Term term, SubstitutionFrame substitution, final Variable[] weakenings)
	{
		assert substitution == null || (substitution != null && substitution.parent == null);
		
		// Prepare helper bitsets for weakenings. 
		// None of the variables to substitute have been weakened yet.
		
		final int substitutionCount = (substitution != null ? substitution.parentCount + substitution.count : 0);
		BitSet unexhausted = new BitSet(substitutionCount);
		unexhausted.flip(0, substitutionCount);
		BitSet unweakened = new BitSet(substitutionCount);
		unweakened.flip(0, substitutionCount);


		if (DEBUG)
		{
			System.out.println("==================== START METASUBSTITUTE: " + Term.SYMBOL(term));
			
			for (int i = 0; i < substitutionCount; ++i)
			{
				System.out.print("[");
				System.out.print(substitution.variables[i]);
				
				System.out.print("] =>");				
				try
                {
	                fprintTermTop(System.out, substitution.substitutes[i], 10, new VariableSet(), 0, true, 6, false);
	                
                }
                catch (IOException e) {}
				System.out.println("");
			}
	
				try
	            {
					System.out.println("============== BEFORE =========");
		            fprintTermTop(System.out, term, 50, new VariableSet(), 1, true, 6, true);
					System.out.println("");
	            }
	            catch (IOException e)
	            {}
						
		}
		
		IntegerHolder size = new IntegerHolder();
		term = metaSubstituteTermUpdate(term, substitution, weakenings, null, substitutionCount, unexhausted, unweakened, size);
		
		if (DEBUG)
		{
			if (size.propertySize + size.termSize > 1000)
				System.out.println("LARGE (" + Term.SYMBOL(term) + "): property count:" + size.propertySize + " term count:" + size.termSize + " property term count:" + size.propertyTermSize); 
			
//			try
//            {
//				System.out.println("============== AFTER =========");
//	            fprintTermTop(System.out, term, 50, new VariableSet(), 1, 6, true);
//				System.out.println("");
//            }
//            catch (IOException e)
//            {}
		
			assert check(term);								
		}
		
		
		COPY(sink, term);

		// FREE_BITS(sink->context, unexhausted);
		// FREE_BITS(sink->context, unweakened);

		for (int i = 0; i < substitutionCount; ++i)
		{
			UNLINK(substitution.substitutes[i]);
		}		
	}

	/**
	 * Substitute variables in given term and send result to given sink.
	 *  
	 * @param sink where we send events to
	 * @param term  the redex fragment that we are copying. Reference is transferred
	 * @param substitution  substitutions to perform in the redex: maps variables to non-redex terms
	 * @param substitutionCount  size of substitution (number of substituted variables)
	 * @param unexhausted - bits for all substituted variables, cleared after linear variables have been substituted (Global)
	 * @param unweakened bits for all substituted variables, cleared under weakening of the variable
	 */
	final public static void metaSubstituteTerm(Sink sink, Term term, SubstitutionFrame substitution, final Variable[] weakenings, 
			int substitutionCount, BitSet unexhausted, BitSet unweakened, IntegerHolder size)
	{
		size.termSize ++;
		
		if (IS_VARIABLE_USE(term))
		{
			Variable v = VARIABLE(term);
			SubstitutionFrame s;
			for (s = substitution; s != null; s = s.parent)
			{
				int offset = s.parentCount;
				for (int i = 0; i < s.count; ++i)
				{
					if (v == s.variables[i])
					{
						// (1) Found substitute for variable:
						// - it is already fully built so no substitution context necessary.
						final Term t = Term.LINK(s.substitutes[i]);
						COPY(sink, t); // Transfer reference
						if (IS_LINEAR(v))
						{
							// Substitutes is not needed anymore. Clear bit.
							// Don't free the substitute as it is needed for renaming weakenings.							
							unexhausted.clear(offset + i);
						}
						
						UNLINK(term);
						return;
					}				
				}
			}
			// (2) Variable that is not substituted: just echo.
			USE(sink, v); 
			UNLINK(term);
		}
		else
		// isConstruction(term)
		{
			// Constructions are copied and recursively populated.
			Construction construction = (Construction) term;
			
			// - Apply weakenings (clear bit), 
			BitSet localUnweakened = (BitSet) unweakened.clone();
			{
				VariableSetLink wsp = construction.weakenings;
				while (wsp != null)
				{
					Variable v = wsp.variable;				
					SubstitutionFrame s;
					WeakeningDone : for (s = substitution; s != null; s = s.parent)
					{
						final int offset = s.parentCount;
						for (int i = 0; i < s.count; ++i)
						{
							if (v == s.variables[i])
							{
								// Weakening of variable we are substituting: remove from bitmap!
								localUnweakened.clear(offset + i);
								
								if (Term.IS_VARIABLE_USE(s.substitutes[i]))
								{
									if (s.renamings != null && (s.renamings == SubstitutionFrame.RENAME_ALL || s.renamings[i]))
									{
										// The binder has been renamed. Scoping is preserved, so it is safe to rename the weakening
										sink.weaken(VARIABLE(s.substitutes[i]));
									}
								}
								
								break WeakeningDone; // break out of both loops
							}									
						}
					}
					wsp = wsp.link;
				}
			}
						
//			BitSet bitset = (BitSet) unexhausted.clone();
//			bitset.and(localUnweakened);
//			if (bitset.isEmpty()) // ANY_BITS is true if there are at least one bit set.
//			{
//				// (3) Term with no further substitution needed so revert to native copying (guaranteed not to return here).
//				
//				// Add non-substituted weakenings
////				if (weakenings != null)
////				{
////					for (int i = 0; i < weakenings.length; i ++)
////						sink.weaken(weakenings[i]);					
////				}
//					
//				COPY(sink, term); // Transfer reference
//				return;
//			}
			
			// Copy the construction weakenings
			// TODO: make it safe.
//			VariableSetLink wsp = construction.weakenings;
//			while (wsp != null)
//			{
//				sink.weaken(wsp.variable);
//				wsp = wsp.link;
//			}
			
			// - Properties (shared by (4) and (5))).
			metaSubstituteProperties(
			        sink, construction, substitution, weakenings, substitutionCount, unexhausted, (BitSet) localUnweakened.clone(), size);

			if (IS_LITERAL(term))
			{
				// (4) Literal: just recreated, including any properties.
				Literal literal = (Literal) term;
				LITERALU(sink, literal.text);
				UNLINK(term);
				return;
			}

			// (5) Generic construction: Fall back to proper substitution of generic reconstruction.

			// Start tag.
			sink.start(construction.descriptor);

			// Contents.
			int arity = construction.descriptor.arity;
			for (int i = 0; i < arity; ++i)
			{
				final int rank = RANK(term, i);
				if (rank == 0)
				{
					// --  i'th subterm with no binders: just continue copying.
					metaSubstituteTerm(
					        sink, Term.LINK(SUB(term, i)), substitution, weakenings, substitutionCount, unexhausted, (BitSet) localUnweakened.clone(), size);
				}
				else
				// rank > 0 so we have to substitute under binders
				{
					// -- i'th subterm with binders, second and following copy: add new binders to substitution!
					final int subSubstitutionCount = substitutionCount + rank; // new substitution size

					// --- allocate substitution
					Variable[] oldBinders = BINDERS(construction, i);
					Variable[] subBinders = new Variable[rank]; // escapes
					VariableUse[] subUses = new VariableUse[rank]; // does not escape
					SubstitutionFrame subSubstitution = new SubstitutionFrame(substitution, substitutionCount, rank, oldBinders,
					        subUses, SubstitutionFrame.RENAME_ALL); // does not escape

					// --- allocate bitmaps
					BitSet subUnexhausted = (BitSet) unexhausted.clone();
					BitSet subUnweakened = (BitSet) localUnweakened.clone();

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
						boolean isLinear = IS_LINEAR(oldBinders[j]);
						subBinders[j] = MAKE_VARIABLE(oldBinders[j].name, true, isLinear); // escapes

						subUses[j] = new VariableUse(subBinders[j]); // escapes
						//subUses[j].descriptor = NULL;
						subUses[j].nr = 1;
						//subUses[j].variable = subBinders[j];

						subUnexhausted.set(substitutionCount + j);
						subUnweakened.set(substitutionCount + j);
					}
					// --- send new binders
					sink.binds(subBinders);

					// --- now process subterm!
					metaSubstituteTerm(
					        sink, Term.LINK(SUB(term, i)), subSubstitution, weakenings, subSubstitutionCount, subUnexhausted,
					        (BitSet) subUnweakened.clone(), size);

					// (end of scope for newRenamings, newVs, and newUses)
					unexhausted.and(subUnexhausted); // MASK_BITS is AND_BITS with update.
					//for (int j = 0; j < rank; ++j)
					//	UNLINK(subUses[j]);
					subUnexhausted = null;
					subUnweakened = null;
				}
			}
			localUnweakened = null;

			// End tag.
			sink.end(construction.descriptor);
			
			UNLINK(term);
		}
	}

	/**
	 * Substitute properties until exhausted all weakening.
	 * 
	 * @param sink
	 * @param construction Reference is NOT transferred.
	 * @param substitution
	 * @param substitutionCount
	 * @param unexhausted
	 * @param unweakened
	 * @param mergeNamedProperties
	 * @param mergeVariableProperties
	 * @param namedStack
	 * @param namedLinkp  Resulting named link. Transfer reference back. 
	 * @param variableStack
	 * @param variableLinkp Resulting variable link. Transfer reference back.
	 */
	final private static void metaSubstitutePropertiesPrefix(Sink sink, Construction construction, SubstitutionFrame substitution,
			final Variable[] weakenings, int substitutionCount, BitSet unexhausted, BitSet unweakened /** Value */, 
			boolean mergeNamedProperties, boolean mergeVariableProperties, 
			ArrayList<NamedPropertyLink> namedStack, NamedPropertyLinkHolder namedLinkp, 
			ArrayList<VariablePropertyLink> variableStack, VariablePropertyLinkHolder variableLinkp, IntegerHolder size)
	{
		NamedPropertyLink namedLink;
		{
			// Collect prefix of named properties that need substitution.
			BitSet localUnweakened = (BitSet) unweakened.clone();
			for (namedLink = construction.namedProperties; namedLink != null; namedLink = namedLink.link)
			{
				if (IS_PROPERTY_CLOSED(namedLink) || (!ANY_BITS(AND_BITS(unexhausted, localUnweakened)) && !mergeNamedProperties))
				{
					// No more variables to metaSubstitute...the prefix is done!
					break;
				}
				
				// The new link, if any.
				String key = namedLink.name;
				if (key != null)
				{
					// - Regular key-value link is always inserted into prefix after substitution of value.
					NamedPropertyLink newLink = new NamedPropertyLink(key, (Term) null, null);
					//newLink.name = key;
					newLink.nr = 1;
					
					int currentTermSize = size.termSize;
					int currentPropertySize = size.propertySize;
					
					Sink propertysink = new BufferSink();
					metaSubstituteTerm(
					        propertysink, Term.LINK(namedLink.term()), substitution, weakenings, substitutionCount, unexhausted,
					        (BitSet) localUnweakened.clone(), size);

					size.propertyTermSize += size.termSize - currentTermSize;
					size.propertyTermSize += size.propertySize - currentPropertySize;
					
					newLink.termOrWeakening = propertysink.term(); // Transfer reference
					propertysink = null;
					pushStack(namedStack, newLink);
				}
				else
				{
					Variable v = namedLink.weakening();
					SubstitutionFrame s;
					NamedPropertyLink weakening = namedLink; // By default, preserve weakening
					
					NamedWeakeningDone : for (s = substitution; s != null; s = s.parent)
					{
						final int offset = s.parentCount;
						for (int i = 0; i < s.count; ++i)
						{
							if (v == s.variables[i])
							{
								// - Weakening for a substituted variable - clear bit
								localUnweakened.clear(offset + i);
								
								if (IS_VARIABLE_USE(s.substitutes[i]))
								{
									// Renaming: update weakening
									weakening = new NamedPropertyLink(key, VARIABLE(s.substitutes[i]), null);
									weakening.nr = 1;									
								}
								else
								{
									// The weakening is not needed anymore as the variable as been substituted.
									weakening = null;
								}
								
								break NamedWeakeningDone;
							}
						}
					}
					
					if (weakening != null)
						pushStack(namedStack, NamedPropertyLink.LINK(weakening));
				}
			}
			localUnweakened = null;
		}

		namedLinkp.link = namedLink;

		VariablePropertyLink variableLink;
		{
			// Collect prefix of variable properties that need substitution.
			BitSet localUnweakened = COPY_BITS(unweakened, substitutionCount);
			for (variableLink = construction.variableProperties; variableLink != null; variableLink = variableLink.link)
			{
				if (!ANY_BITS(AND_BITS(unexhausted, localUnweakened)) && !mergeVariableProperties)
				{
					// No more variables to metaSubstitute...the prefix is done!
					break;
				}				
				Variable key = variableLink.variable;
				if (key != null)
				{
					// - The link denotes an actual variable-value mapping.
					SubstitutionFrame s;
					VariableProcess : for (s = substitution; s != null; s = s.parent)
					{
						int i;
						for (i = 0; i < s.count; ++i)
						{
							if (key == s.variables[i]) // TODO: Check BIT?
							{
								Term keySubstitution = s.substitutes[i]; // Just peek... no need to link
								if (keySubstitution != null && IS_VARIABLE_USE(keySubstitution))
								{
									// This is a substitution of a variable for a variable!
									key = VARIABLE(keySubstitution);
								}
								break VariableProcess; 
							}
						}
					}
					
					// Mapped variable not (further) renamed - include in prefix after value substitution.
					VariablePropertyLink newLink = new VariablePropertyLink(key, (Term) null, null);
					//newLink.variable = key;
					newLink.nr = 1;
					Sink propertysink = new BufferSink();
					metaSubstituteTerm(
					        propertysink, Term.LINK(variableLink.term()), substitution, weakenings, substitutionCount, unexhausted,
					        COPY_BITS(localUnweakened, substitutionCount), size);
					newLink.termOrWeakening = propertysink.term();
					propertysink = null;
					pushStack(variableStack, newLink);
				}
				else
				{
					Variable v = variableLink.weakening();
					SubstitutionFrame s;
					VariablePropertyLink weakening = variableLink; // By default, preserve weakening
					
					VariableWeakeningDone : for (s = substitution; s != null; s = s.parent)
					{
						int offset = s.parentCount;
						for (int i = 0; i < s.count; ++i)
						{
							if (v == s.variables[i])
							{
								// - Weakening is for a substituted variable! 
								CLEAR_BIT(localUnweakened, offset + i);
		
								if (IS_VARIABLE_USE(s.substitutes[i]))
								{
									// Renaming: update weakening
									weakening = new VariablePropertyLink(key, ((VariableUse) s.substitutes[i]).variable, null);
									weakening.nr = 1;									
								}
								else
								{
									// The weakening is not needed anymore as the variable as been substituted.
									weakening = null;
								}
		
								break VariableWeakeningDone;
							}
						}
					}
					
					if (weakening != null)
						pushStack(variableStack, VariablePropertyLink.LINK(weakening));
				}
			}
			localUnweakened = null;
		}
		variableLinkp.link = variableLink;
	}

	/**
	 * Substitute properties. Send result to given sink.
	 * 
	 * @param sink
	 * @param construction Reference is NOT transferred.
	 * @param substitution
	 * @param substitutionCount
	 * @param unexhausted
	 * @param unweakened
	 */
	static void metaSubstituteProperties(Sink sink, Construction construction, SubstitutionFrame substitution, final Variable[] weakenings, int substitutionCount, BitSet unexhausted, BitSet unweakened /* unmutable */, IntegerHolder size)
	{
		boolean mergeNamedProperties = false;
		boolean mergeVariableProperties = false;
		if (sink instanceof BufferSink)
		{
			mergeNamedProperties = ((BufferSink) sink).pendingNamedProperties != null;
			mergeVariableProperties = ((BufferSink) sink).pendingVariableProperties != null;
		}

		if (mergeNamedProperties
		        || mergeVariableProperties || construction.namedProperties != null || construction.variableProperties != null)
		{
			// For prefix of named properties with substitution applied to values.
			ArrayList<NamedPropertyLink> namedStack = new ArrayList<NamedPropertyLink>(); // stack of properties to copy
			NamedPropertyLink namedLink; // the first link not copied (NULL if all)

			// For prefix of variable properties with substitution applied to keys and values.
			ArrayList<VariablePropertyLink> variableStack = new ArrayList<VariablePropertyLink>(); // stack of properties to copy
			VariablePropertyLink variableLink; // the first link not copied (NULL if all)

			// Collect prefixes.
			NamedPropertyLinkHolder namedHolder = new NamedPropertyLinkHolder();
			VariablePropertyLinkHolder variableHolder = new VariablePropertyLinkHolder();
			metaSubstitutePropertiesPrefix(
			        sink, construction, substitution, weakenings, substitutionCount, unexhausted, (BitSet) unweakened.clone(),
			        mergeNamedProperties, mergeVariableProperties, namedStack, namedHolder, variableStack, variableHolder, size);
			namedLink = namedHolder.link;
			variableLink = variableHolder.link;

			if (namedLink != null || variableLink != null)
			{
				sink.properties(Referenceable.LINK(namedLink), Referenceable.LINK(variableLink)); // Transfer references.
				//			// We need to emit a new reference...so create dummy construction for extraction of references...
				//			Construction c = new Construction(); // Temporary construction 
				//			//c.descriptor = null;
				//			//c.weakenings = null;
				//			c.namedProperties = namedLink;
				//			c.variableProperties = variableLink;
				//			//c.nf = false;
				//			//c.nostep = false;
				//			//c.ground = false;
				//			//c.constant = false;
				//			ADD_PROPERTY_REF(sink, c);
				size.propertySize++;
			}

			// Now "play" prefix events (backwards!).

			// Add weakenings corresponding to non-substituted properties
//			if (weakenings != null)
//			{
//				for (int i = 0; i < weakenings.length; i++)
//					sink.propertyWeaken(weakenings[i]);
//			}

			while (!emptyStack(namedStack))
			{
				NamedPropertyLink link = topStack(namedStack);
				popStack(namedStack);
				String key = link.name;
				if (key != null)
				{
					ADD_PROPERTY_NAMED(sink, key, link.term());
					size.propertySize++;
				}
				//  Weakenings are added once during variable weakening phase.			
				//			else if (link.weakening().bound)
				//				ADD_PROPERTY_WEAKEN(sink, link.weakening());
				UNLINK(link);
			}
			//namedStack = null;

			while (!emptyStack(variableStack))
			{
				VariablePropertyLink link = topStack(variableStack);
				popStack(variableStack);
				Variable key = link.variable;
				if (key != null)
				{
					ADD_PROPERTY_VARIABLE(sink, key, link.term());
					size.propertySize++;
				}
				else if (link.weakening().bound)
				{
					size.propertySize++;
					ADD_PROPERTY_WEAKEN(sink, link.weakening());
				}
				UNLINK(link);
			}
			//variableStack = null;  
		}
	}

	/**
	 * Substitute variables in given term.
	 * 
	 * @param term redex fragment that we are updating. Reference is transferred
	 * @param substitution
	 * @param substitutionCount
	 * @param unexhaustedp
	 * @param unweakened
	 * @return
	 */
	final private static Term metaSubstituteTermUpdate(Term term, SubstitutionFrame substitution, 
			final Variable[] weakenings, final VariableSetLink pendingWeakenings,
			int substitutionCount, BitSet unexhaustedp, BitSet unweakened, IntegerHolder size)
	{
		if (LINK_COUNT(term) > 1)
		{
			// Can't update term as it's shared. Fallback to copy-mode.
			
			Sink sink = new BufferSink();
			metaSubstituteTerm(sink, term, substitution, weakenings, substitutionCount, unexhaustedp, unweakened, size); // Ref is transferred
			term = sink.term();
			//FREE_BUFFER(sink);
			return term;
		}

		if (IS_VARIABLE_USE(term))
		{
			Variable v = VARIABLE(term);
			SubstitutionFrame s;
			for (s = substitution; s != null; s = s.parent)
			{
				final int offset = s.parentCount;
				for (int i = 0; i < s.count; ++i)
				{
					if (v == s.variables[i])
					{
						// (1) Found variable to substitute.
						// - it is already fully built so no substitution context necessary.
						UNLINK(term);
						term = Term.LINK(s.substitutes[i]);
						
						if (IS_LINEAR(v))
							CLEAR_BIT(unexhaustedp, offset + i);
					
						return term;
					}					
				}
			}
			// (2) Variable that is not substituted: leave it.
			return term;
		}
		else
		// IS_CONSTRUCTION(term)
		{
			Construction construction = (Construction) term;

			// - Clear bit set based on weakenings.
			BitSet localUnweakened = COPY_BITS(unweakened, substitutionCount);
			{
				VariableSetLink wsp = construction.weakenings;
				while (wsp != null)
				{
					Variable v = wsp.variable;
					SubstitutionFrame s;
					WeakeningDone : for (s = substitution; s != null; s = s.parent)
					{
						final int offset = s.parentCount;
						for (int i = 0; i < s.count; ++i)
						{
							if (v == s.variables[i])
							{
								// - Weakening of variable we are substituting: remove from bitmap!
								CLEAR_BIT(localUnweakened, offset + i);
								
								if (Term.IS_VARIABLE_USE(s.substitutes[i]))
								{
									if (s.renamings != null && (s.renamings == SubstitutionFrame.RENAME_ALL || s.renamings[i]))
									{
										// The binder has been renamed. Scoping is preserved, so it is safe to rename the weakening
										wsp.variable = VARIABLE(s.substitutes[i]);
									}									
								}
								
								break WeakeningDone; // break out of both inner loops to process next weakening
							}
						}					
					}
					wsp = wsp.link;
				}
			}

//			if (!ANY_BITS(AND_BITS(unexhaustedp, localUnweakened)))  
//			{
//				// (3) No further substitution is possible, so leave it.
//			
//				// Construction weakenings can be preserved.
//				if (pendingWeakenings != null)
//					construction.weakenings = pendingWeakenings.copy().merge(construction.weakenings);						
//				
//				// TODO: This is not safe. Need to look at properties?
////				if (construction.weakenings != null)
////					construction.weakenings.addAll(weakenings);
////				else
////					construction.weakenings = VariableSetLink.create(weakenings);			
//				
//				return term;
//			}

			// (4) Literal, and
			// (5) Generic construction: Generate copy of properties and then fall back to recursive substitution...
		
			// - create buffer.
			Sink sink = new BufferSink();
			// - copy all properties into buffer.
			metaSubstituteProperties(
			        sink, construction, substitution, weakenings, substitutionCount, unexhaustedp, (BitSet) localUnweakened.clone(), size);
			// - destroy property pointers in term itself (!).
			UNLINK_LINK(construction.namedProperties);
			construction.namedProperties = null;
			UNLINK_LINK(construction.variableProperties);
			construction.variableProperties = null;
		
			// Insert pushed down weakenings. Might be pushed down even further.
//			if (pendingWeakenings != null)
//				construction.weakenings = pendingWeakenings.copy().merge(construction.weakenings);
//			
//			VariableSetLink localPendingWeakenings = pendingWeakenings;
//			if (localPendingWeakenings != null)
//				localPendingWeakenings = localPendingWeakenings.copy();
//			
//			// Update weakenings.
//			if (construction.weakenings != null)
//			{
//				if (construction.weakenings.nr > 1)
//					construction.weakenings = construction.weakenings.copy();
//				
//				// Need to intersect with substitute weakenings
//				VariableSetLinkHolder holder = new VariableSetLinkHolder();
//				
//				SubstitutionFrame s;
//				UpdateWeakenings : for (s = substitution; s != null; s = s.parent)
//				{
//					final int offset = s.parentCount;
//					for (int i = 0; i < s.count; ++i)
//					{
//						if (localUnweakened.get(offset + i)) // Still not weakened?
//						{
//							final Term t = s.substitutes[i];
//							
//							if (Term.IS_CONSTRUCTION(t))
//							{
//								final VariableSetLink w = ((Construction) t).weakenings;
//								
//								 construction.weakenings = construction.weakenings.intersect(w, holder);
//								
//								// Add removed weakenings to list of weakening to propagate down.
//								if (localPendingWeakenings != null)
//									localPendingWeakenings = localPendingWeakenings.merge(holder.link);
//								else
//									localPendingWeakenings = holder.link;
//								
//								holder.link = null;																	
//							}
//							else // Variable
//								construction.weakenings = construction.weakenings.remove(VARIABLE(t));							
//						}
//						
//						if (construction.weakenings == null)
//							break UpdateWeakenings;							
//					}					
//				}				
//			}
			
			//construction.weakenings = null;
			
			// Send all new weakenings
//			if (weakenings != null)
//			{
//				for (int i = 0; i < weakenings.length; i ++)
//					sink.weaken(weakenings[i]);
//			}
			
			// - send property-less term to buffer (note: no substitution, relies on bufferCopy reference semantics).
			COPY(sink, construction); // Transfer reference (for term also)
			// - overwrite term with the new term with updated properties.
			term = sink.term(); // Transfer reference
			// - done with the buffer.
			//FREE_BUFFER(sink);
			
			// - now fall back to update the term itself!
			final int arity = term.descriptor.arity;
			//Term term = *termp;
			for (int i = 0; i < arity; ++i)
			{
				final int rank = RANK(term, i);
				if (rank > 0)
				{
					// -- duplicate nested binders should be considered weakenings.
					BitSet localUnweakened2 = COPY_BITS(unweakened, substitutionCount);
					SubstitutionFrame s;
					for (s = substitution; s != null; s = s.parent)
					{
						final int offset = s.parentCount;
						for (int ii = 0; ii < s.count; ++ii)
						{
							if (localUnweakened2.get(offset + ii))
							{
								for (int j = 0; j < rank; ++j)
									if (s.variables[ii] == BINDER(term, i, j))
									{
										CLEAR_BIT(localUnweakened2, offset + ii);
										break;
									}
							}
						}
					}
					SETSUB(term, i, metaSubstituteTermUpdate(SUB(term, i), substitution, weakenings, null, substitutionCount, unexhaustedp, (BitSet) localUnweakened2.clone(), size));
					localUnweakened2 = null;
				}
				else
					SETSUB(term, i, metaSubstituteTermUpdate(SUB(term, i), substitution, weakenings, null, substitutionCount, unexhaustedp, (BitSet) unweakened.clone(), size));
			}
			
			// Propagate common weakening up.
			// TODO: does not seem to improve anything at this stage
			//construction.propagateWeakenings();
			
			// Update nf field of construction.
			boolean nf = Term.IS_DATA(term);
			for (int i = 0; nf && i < arity; ++i)
				if (!IS_NF(SUB(term, i)))
					nf = false;
			
			construction.nf = nf;

			return term;
		}
	}

	/** Convert string to Java/C identifier form with leading _M_ (suspicious characters are replaced with hex form). */
	final public static String quoteJavaIdentifierPart(String s)
	{
		return Util.quoteJavaIdentifierPart(s);
	}

	/** The string with quotes. */
	final public static String quote(String s)
	{
		return "\"" + s.replace("\"", "\"\"") + "\"";
	}

	// Pattern Matching

	final public static boolean MATCHREGEX(String pattern, String value)
	{
		return value.matches(pattern); // TODO: should use ICU
	}

	// Failure.

	final public static int Default = 0;
	final public static int Msg = 1;
	final public static int Msg0 = 2;
	final public static int NoMsg = 3;

	final public static void ERRORF(int kind, String format, String... args)
	{
		String pattern = toJavaFormat(format);
		String msg = MessageFormat.format(pattern, (Object[]) args);
		throw new RuntimeException(msg);
	
	}

	/**
	 * Convert C format to Java format.
	 * 
	 * Note: implementation is incomplete!
	 * 
	 * @param format
	 * @return
	 */
	final public static String toJavaFormat(String format)
	{
		Pattern p = Pattern.compile("%s");
		Matcher m = p.matcher(format);
		StringBuffer sb = new StringBuffer();
		int count = 0;
		while (m.find())
		{
			m.appendReplacement(sb, "{" + count + "}");
			count ++;
		}
		m.appendTail(sb);
		return sb.toString();
	}

	// Debugging

	/**
	 * Check term invariants
	 * @param term
	 */
	final public static boolean check(Term term)
	{
		assert check(term, false, null);
		return true;
	}

	/**
	 * Check term invariants
	 * 
	 * @param term
	 * @param weakenings in-scope weakenings
	 * 
	 */
	final private static boolean check(Term term, boolean nf, VariableSetLink weakenings)
	{
		assert term != null : "Term must not be null";
		assert term.nr > 0 : "Reference count must be at least one.";
		
		if (IS_VARIABLE_USE(term))
	    {
	        Variable v = VARIABLE(term);
	        assert v != null : "Variable must not be null";
	        
	        assert checkWeakenings(weakenings, v) : v;
	    }
	    else
	    {
	        assert IS_CONSTRUCTION(term);
	        assert !nf || IS_NF(term);
	        
	        final Construction construction = (Construction) term;

	        // Compute local weakenings.
	        VariableSetLink localWeakenings = weakenings;
	        if (localWeakenings != null)
	        	localWeakenings = localWeakenings.copy();
	        
	        if (construction.weakenings != null)
	        {
	        	if (localWeakenings == null)
	        		localWeakenings = construction.weakenings.copy();
	        	else
	        		localWeakenings.merge(construction.weakenings.copy());
	        }
	        
	        // Check properties.
	        {
//	        	assert construction.namedProperties == null || !construction.namedProperties.isCircular() : "Named properties must not contain circular references";
//	        	VariableSetLink propertyWeakenings = localWeakenings == null ? null : localWeakenings.copy();
//	            
//	        	NamedPropertyLink link;
//	            for (link = construction.namedProperties; link != null; link = link.link)
//	            {
//	                if (link.name != null)
//	                {
//	                    check(link.term(), nf, propertyWeakenings, substitutionSize);
//	                }
//	                else
//	                {
//	                	// This is a weakenings
//	                	if (propertyWeakenings == null)
//	                	{
//	                		propertyWeakenings = new VariableSetLink();
//	                		propertyWeakenings.variable = link.weakening();
//	                	}
//	                	else
//	                		propertyWeakenings = propertyWeakenings.add(link.weakening());
//	                }
//	                
//	                for (Variable binder : substitutionSize.keySet())
//	    	        {
//	    	        	if (propertyWeakenings == null || !propertyWeakenings.contains(binder))
//	    	        		substitutionSize.get(binder).propertySize ++;	        	
//	    	        }
//	            }
	        }
	        {
	            assert construction.variableProperties == null || !construction.variableProperties.isCircular() : "Variable properties must not contain circular references";
	            
	            VariableSetLink propertyWeakenings = localWeakenings == null ? null : localWeakenings.copy();
	            VariablePropertyLink link;
	            for (link = construction.variableProperties; link != null; link = link.link)
	            {
	                if (link.variable != null)
	                {
	                	if (!checkWeakenings(localWeakenings, link.variable))
	                		assert checkWeakenings(localWeakenings, link.variable) : link.variable;
	                	
	                    check(link.term(), nf, propertyWeakenings);
	                }
	                else
	                {
	                	// This is a weakenings
	                	propertyWeakenings = VariableSetLink.add(propertyWeakenings, link.weakening());
	                }	                
	            }
	        }
	        	      
	        // Check binders and subterms.
	        final int arity = ARITY(term);
	        
	        int i;
	        for (i = 0; i < arity; ++i)
	        {
	        	boolean copied = false;
	        	VariableSetLink subweakenings = localWeakenings;	        		        	
	            final int rank = RANK(term,i);
	            int j;
	            for (j = 0; j < rank; ++j)
	            {
	            	Variable binder =  BINDER(term,i,j);
	            	assert binder != null : "Binder must not be null";	
	            	
	            	// If binder in weakening list, remove to allow nesting
	                if (subweakenings != null && subweakenings.contains(BINDER(term,i,j)))
	                {
	                	if (!copied)
	                	{
	                		subweakenings = subweakenings.copy();
	                		copied = true;
	                	}
	                	subweakenings = subweakenings.remove(BINDER(term,i,j));	                	
	                }
	            }
	            
	            check(SUB(term,i), IS_NF(term), subweakenings);	            
	        }
	        
	        
	    }
		return true;
	}
	
	final private static boolean checkWeakenings(VariableSetLink weakenings, Variable v)
	{
		if (weakenings == null)
			return true;
		
		return !weakenings.contains(v);
	}
	
	static class TermNR {
		public Term term;
		public int nr;
		
		public TermNR(Term term, int nr)
        {
	        this.term = term;
	        this.nr = nr;
        }

		@Override
		public boolean equals(Object other)
		{
			return other instanceof TermNR && ((TermNR) other).term == term;
		}

		@Override
        public int hashCode()
        {
	        return term.hashCode();
        }
		
	}
	
	static class IntegerHolder {
		int propertySize;
		int propertyTermSize;		
		int termSize;
	}
	
	final public static void fprintTerm(Appendable out, Term term) throws IOException
	{
		VariableSet set = VariableSet.makeVariableSet();
		fprintTermTop(out, term, -1, set, 1, true, 0, false);
		out.append("\n");
		//freeVariableSet(set);
	}

	final public static void printTerm(Term term)
	{
		try
		{
			fprintTerm(System.out, term);
		}
		catch (IOException e)
		{
			// Ignore
		}
	}

	final public static void ppt(Term term)
	{
		VariableSet set = VariableSet.makeVariableSet();
		try
		{
			fprintTermTop(System.out, term, 4, set, 2, true, 0, false);
			System.out.println("");
		}
		catch (IOException e)
		{
			// Ignore
		}
		//freeVariableSet(set);
	}

	final public static void pwt(Term term)
	{
		VariableSet set = VariableSet.makeVariableSet();
		try
		{
			fprintTermTop(System.out, term, 10, set, 2, true, 0, true);
			System.out.println("");
		}
		catch (IOException e)
		{
			// Ignore
		}
		//freeVariableSet(set);
	}

	final private static String SPACES = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ";

	final public static void fprintTermWithIndent(Appendable out, Term term) throws IOException
	{
		VariableSet set = VariableSet.makeVariableSet();
		fprintTermTop(out, term, Integer.MAX_VALUE, set, 1, true, 10, true);
		System.out.println("");
		//freeVariableSet(set);
	}

	final public static void printTermWithIndent(Term term)
	{
		try
		{
			fprintTermWithIndent(System.out, term);
		}
		catch (IOException e)
		{
			// Ignore
		}
	}

	/**
	 * Print literal so it is reparseable.
	 * Literals are in double quotes.
	 * @param context
	 * @throws IOException 
	 */
	final public static void fprintLiteral(Appendable out, String literal) throws IOException
	{
		out.append("\"");
		int i;
		char c;

		for (i = 0; i < literal.length(); i++)
		{
			c = literal.charAt(i);
			if ((!Character.isISOControl(c) || c == ' ') && c != '"')
				out.append(c);
			else
				out.append(new String(Character.toChars(c)));
		}
		out.append("\"");

	}

	// Print constructor in form that can be safely reparsed.
	// Constructors use single quotes unless safe to dump directly.
	final public static void fprintConstructor(Appendable out, String name) throws IOException
	{
		if (name == null || name.length() == 0)
		{
			out.append("''");
			return;
		}
		boolean rawsafe = true;
		char c = name.charAt(0);
		if (Character.isUpperCase(c))
		{
			int i;
			for (i = 1; i < name.length(); i++)
			{
				c = name.charAt(i);
				switch (c)
				{
					case '_' :
					case '-' :
					case '$' :
						break;
					default :
						if (!(Character.isLetter(c) || Character.isDigit(c)))
							rawsafe = false;
				}
			}
		}
		else if (Character.isDigit(c))
		{
			int i;
			for (i = 1; i < name.length(); i++)
			{
				c = name.charAt(i);
				switch (c)
				{
					case '0' :
					case '1' :
					case '2' :
					case '3' :
					case '4' :
					case '5' :
					case '6' :
					case '7' :
					case '8' :
					case '9' :
					case '.' :
					case 'E' :
					case 'e' :
						break;
					default :
						rawsafe = false;
				}
			}
		}
		else
		{
			rawsafe = false;
		}
		//
		if (rawsafe)
			out.append(name);
		else
		{
			out.append("'");
			int i;
			for (i = 0; i < name.length(); ++i)
			{
				c = name.charAt(i);
				if ((!Character.isISOControl(c) || c == ' ') && c != '\'')
					out.append(c);
				else
					out.append(new String(Character.toChars(c)));
			}
			out.append("'");
		}
	}

	final public static void fprintTermTop(Appendable out, Term term, int depth, VariableSet encountered, int indent, boolean indentFirst, int includeprops, boolean debug)
	        throws IOException
	{
		if (indentFirst && indent > 0 && depth > 1)
		{			
			out.append('\n').append(SPACES.subSequence(0, Math.min(indent, SPACES.length())));
		}
		if (term != null && term.descriptor != null)
		{
			String nm = term.descriptor.name(term);
			if (nm != null)
			{
				if (nm.equals("GlobalConstant"))
				{
					depth = -1;
				}
			}
		}
		if (term == null)
		{
			out.append("_");
		}
		else if (depth == 0)
		{
			out.append("...");
		}
		else if (IS_VARIABLE_USE(term))
		{
			Variable x = ((VariableUse) term).variable;
			//assert x.name != null;
			out.append(x.name).append(IS_LINEAR(x) ? "¹" : "");
		}
		else
		{
			if (debug)
			{
				Construction construction = (Construction) term;
				
				// If debugging then print weakenings.
				if (construction.weakenings != null)
				{
					out.append(construction.weakenings.toString());
				}
			}
			
			// Properties, if any.
			if (includeprops > 0)
			{
				Construction construction = (Construction) term;
				if (construction.namedProperties != null || construction.variableProperties != null)
				{
					out.append("{");
					String sep = "";
					int count = 0;
					{
						NamedPropertyLink link;
						for (link = construction.namedProperties; link != null; link = link.link)
						{
							if (link.name != null)
							{
								out.append(sep);
								if (indent > 0 && depth > 2)
									out.append('\n').append(SPACES.subSequence(0, indent + 1));
								fprintLiteral(out, link.name);
								out.append(" : ");
								fprintTermTop(out, link.term(), depth - 2, encountered, (indent > 0 ? indent + 2 : 0), false, includeprops, debug);
								sep = "; ";
							}
							else if (debug)
							{
								out.append(sep).append('<').append(link.weakening().name).append(
								        link.weakening().bound ? "" : "!").append('>');
								sep = "; ";
							}
							count ++;
							if (count >= includeprops)
								break;
						}
					}
					count = 0;
					{
						VariablePropertyLink link;
						for (link = construction.variableProperties; link != null; link = link.link)
						{
							if (link.variable != null)
							{
								out.append(sep);
								if (indent > 0 && depth > 2)
									out.append('\n').append(SPACES.subSequence(0, indent + 1));
								out.append(link.variable.name).append(IS_LINEAR(link.variable) ? "¹" : "").append(" : ");
								fprintTermTop(out, link.term(), depth - 2, encountered, (indent > 0 ? indent + 2 : 0), false, includeprops, debug);
								sep = "; ";
							}
							else if (debug)
							{
								out.append(sep).append('<').append(link.weakening().name).append(
								        link.weakening().bound ? "" : "!").append('>');
								sep = "; ";
							}
							count ++;
							if (count >= includeprops)
								break;
						}
					}
					if (indent > 0 && depth > 1)
						out.append('\n').append(SPACES.subSequence(0, indent));
					out.append("}\n");
				}
			}

			if (IS_LITERAL(term))
			{
				fprintLiteral(out, term.descriptor.name(term));
			}
			else
			{
				String nm = term.descriptor.name(term);
				final int arity = ARITY(term);
				// int isData = IS_DATA(term);
				if (arity == 0 && nm.length() == 0)
				{
					out.append("\"\"");
					return;
				}
				fprintConstructor(out, nm);
				 if (((Construction) term).nf)
		             out.append("{NF}");
		         if (((Construction) term).nostep)
		             out.append("{NS}");
		        out.append('{').append(Integer.toString(term.nr)).append("}");
				if (arity > 0)
				{
					out.append('[');
					int i;
					for (i = 0; i < arity; ++i)
					{
						if (i > 0)
							out.append(", ");
						// Binders.
						int rank = RANK(term, i);
						if (rank > 0)
						{
							int j;
							for (j = 0; j < rank; ++j)
							{
								if (j > 0)
									out.append(' ');
								// Bound variable that should be unique...
								Variable binder = BINDER(term, i, j);
								if (binder != null)
								{
									//ASSERT(context, !containsVariable(encountered, binder));
									VariableSet.addVariable(encountered, binder);
									out.append(binder.name).append(IS_LINEAR(binder) ? "¹" : "");
								}
								else
									out.append("vNULL");
							}
							out.append(". ");
						}
						// Subterm.
						fprintTermTop(out, ((Construction) term).sub[i], depth - 1, encountered, (indent > 0 ? indent + 1 : 0), true, includeprops, debug);
					}
					out.append(']');
				}
			}
		}
	}

	// Bit manipulation helpers

	final public static BitSet COPY_BITS(BitSet bs, int count)
	{
		return (BitSet) bs.clone();
	}

	final public static BitSet AND_BITS(BitSet bs1, BitSet bs2)
	{
		BitSet r = (BitSet) bs1.clone();
		r.and(bs2);
		return r;
	}

	final public static boolean ANY_BITS(BitSet bs)
	{
		return !bs.isEmpty();
	}

	final public static void CLEAR_BIT(BitSet bs, int i)
	{
		bs.clear(i);
	}

	// Dummies to prevent warnings... 
	final public static void permitUnusedTerm(Term t)
	{}

	final public static void permitUnusedTermP(Term t)
	{}

	final public static void permitUnusedInt(int i)
	{}

	final public static void permitUnusedLong(long i)
	{}

	final public static void permitUnusedVariable(Variable v)
	{}



}
