/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Kind;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.Pair;

/**
 * GenericTerm that delegates all operations to another {@link #term()}.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegateGenericTerm.java,v 3.3 2014/01/06 03:11:09 krisrose Exp $
 */
abstract class DelegateGenericTerm extends GenericTerm
{
	// Constructor.
	
	/** Create delegate term. */
	protected DelegateGenericTerm(GenericFactory factory)
	{
		super(factory);
	}

	// Methods.
	
	/** The term that actually does the job. */
	abstract protected GenericTerm term();

	// GenericTerm...

	public GenericTerm stripProperties()
	{
		return term().stripProperties();
	}

	public boolean isFlexible()
	{
		return term().isFlexible();
	}
	
	Variable[][] allBinders()
	{
		return term().allBinders();
	}
	
	GenericTerm[] allSubs()
	{
		return term().allSubs();
	}
	
	public void insertSub(int index, Variable[] binders, GenericTerm extra) throws CRSException
	{
		term().insertSub(index, binders, extra);
	}

	public void addSub(Variable[] binders, GenericTerm extra) throws CRSException
	{
		term().addSub(binders, extra);
	}
	
	public void deleteSub(int index) throws CRSException
	{
		term().deleteSub(index);
	}

	public void replaceSub(int index, Variable[] binders, GenericTerm replacement)
	{
		term().replaceSub(index, binders, replacement);
	}

	public void insertSubs(int index, List<Pair<Variable[], GenericTerm>> extras) throws CRSException
	{
		term().insertSubs(index, extras);
	}

	public void addSubs(List<Pair<Variable[],GenericTerm>> extras) throws CRSException
	{
		term().addSubs(extras);
	}

	public void deleteSubs(int first, int last) throws CRSException
	{
		term().deleteSubs(first, last);
	}

	public void replaceSubs(int first, int last, List<Pair<Variable[],GenericTerm>> replacements) throws CRSException
	{
		term().replaceSubs(first, last, replacements);
	}
	
	// Copyable...

	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		return term().copy(sink, discard, renames);
	}

	// Stub...

	public Kind kind()
	{
		return term().kind();
	}

	public Constructor constructor()
	{
		return term().constructor();
	}

	public Variable variable()
	{
		return term().variable();
	}

	public void setVariable(Variable v)
	{
		term().setVariable(v);
	}

	public String metaVariable()
	{
		return term().metaVariable();
	}

	public int arity()
	{
		return term().arity();
	}

	public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
		return term().copy(discard, renames);
	}

	// Term...

	public Variable[] binders(int i)
	{
		return term().binders(i);
	}

	public GenericTerm sub(int i)
	{
		return term().sub(i);
	}

	public Sink replaceSubSink(int i)
	{
		return term().replaceSubSink(i);
	}

	public boolean equalsModulo(Term that, ExtensibleMap<Variable, Variable> renamings)
	{
		return term().equalsModulo(that, renamings);
	}
	
	public void appendTermTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean outer, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException
	{
		term().appendTermTo(writer, used, noLinear, depth, outer, full, namedProps, variableProps, omitProps);
	}

    public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
    {
    	return term().reify(sink, metaArgSort, freeSort, subReifiers);
    }
	
	// Object...

    @Override
    public int hashCode()
    {
    	return term().hashCode();
    }
}
