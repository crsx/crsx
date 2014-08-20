/* Copyright © 2006, 2010 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.Collection;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeSet;

import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Kind;
import net.sf.crsx.Maker;
import net.sf.crsx.Maker.ContinuationSinkSetter;
import net.sf.crsx.Match;
import net.sf.crsx.MetaAnalyzer;
import net.sf.crsx.Path;
import net.sf.crsx.Pattern;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.FormattingAppendable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;

/**
 * Internal class with most of the logic for construction generic terms.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericConstruction.java,v 3.14 2014/01/06 03:11:09 krisrose Exp $
 */
public abstract class GenericConstruction extends GenericTerm
{
	// State.
	
	/** Symbol. */
	final protected Constructor constructor;
	
	// Constructor.
	
	/**
	 * Create constructor term.
	 * @param factory for {@link #maker()}
	 */
	public GenericConstruction(GenericFactory factory, Constructor constructor)
	{
		super(factory);
		this.constructor = constructor;
	}

	// GenericTerm...

    @Override
    public GenericTerm stripProperties()
    {
    	if (constructor.literalSort() != null)
    		return factory.newConstruction(factory.makeLiteral(constructor.object(), constructor.literalSort()), allBinders(), allSubs());
    	else
    		return factory.newConstruction(factory.makeConstructor(constructor.object()), allBinders(), allSubs());
    }

    @Override
    public void removeProperty(String name)
    {
    	try
        {
	        constructor.setProperty(name, null);
        }
        catch (CRSException e)
        {}
    }

    @Override
    public void removeProperty(Variable variable)
    {
    	try
        {
    		constructor.setProperty(variable, null);
        }
        catch (CRSException e)
        {}
    }

    // Copyable...

	public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renames)
	{
	    sink = sink.start(discard && renames.isEmpty() ? constructor() : constructor().copy(renames));
		if (discard)
		{
			// If this term is being discarded then we can reuse the local variables.
			for (int i = 0; i < arity(); ++i)
				sink = sub(i).copy(binders(i).length == 0 ? sink : sink.binds(binders(i)), discard, renames); 
		}
		else
		{
			// Need to create fresh variables to avoid clashes.
			for (int i = 0; i < arity(); ++i)
			{
				Variable[] bs = new Variable[binders(i).length];
				ExtensibleMap<Variable, Variable> localRenames = renames;
				if (bs.length > 0)
				{
					for (int j = 0; j < bs.length; ++j)
					{
					    Variable v = binders(i)[j];
						localRenames = localRenames.extend(v, (bs[j] = sink.makeVariable(v.name(), v.promiscuous(), v.blocking(), v.shallow())));
					}
					sink = sink.binds(bs);
				}
				sink = sub(i).copy(sink, discard, localRenames);
			}
		}
		sink = sink.end();
		return sink;
	}

    // Stub...

	final public Kind kind()
	{
		return Kind.CONSTRUCTION;
	}

    @Override
    abstract public Constructor constructor();
    
	@Override
	abstract public int arity();

    @Override
    public GenericTerm copy(boolean discard, ExtensibleMap<Variable, Variable> renames)
    {
		if (renames == null)
			renames = LinkedExtensibleMap.EMPTY_RENAMING;
        if (discard && renames.isEmpty())
            return this;
        
        final Constructor c = constructor().copy(renames);
        final int a = arity();
        final Variable[][] bss = new Variable[a][];
        final GenericTerm[] ss = new GenericTerm[a];
        for (int i = 0; i < a; ++i)
        {
            final Variable[] bs = new Variable[binders(i).length];
            ExtensibleMap<Variable, Variable> r = renames;
            for (int j = 0; j < bs.length; ++j)
            {
                Variable v = binders(i)[j];
                bs[j] = factory.makeVariable(v.name(), v.promiscuous(), v.blocking(), v.shallow());
                r = r.extend(v, bs[j]);
            }
            bss[i] = bs;
            GenericTerm subi = sub(i);
//            if (subi == null)
//            	factory.warning("bad karma...null subterm!");
            ss[i] = subi.copy(discard, r);
        }
        return newConstruction(c, bss, ss, false);
    }
    
	// Term...
    
	private GenericTerm newConstruction(Constructor c, Variable[][] bss, GenericTerm[] ss, boolean b)
	{
		return factory.newConstruction(c, bss, ss);
	}

	@Override
	abstract public Variable[] binders(int i);

	@Override
	abstract public GenericTerm sub(int i);

	@Override
	final public Sink replaceSubSink(final int i)
	{
		return factory.makeBuffer(new Maker.CallBack()
		{
			@Override
			public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
			{
				replaceSub(i, binders, (GenericTerm) term);
			}
		});
	}
	
	//private static int checks = 0;

	final public boolean checkFree(Collection<Variable> forbidden, Collection<Variable> once, Collection<Variable> onceSeen, boolean promiscuous, ExtensibleSet<Variable> bound)
	{
		/*
	    if ("Procedure".equals(this.constructor.symbol()))
		    System.out.println("CheckFree "+(++checks));
	    if (checks > 60000)
		    System.out.println("Really?!?");
	    */
	    if (!constructor().checkFree(forbidden, once, onceSeen, promiscuous, bound))
	        return false;
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
			if (!sub(i).checkFree(forbidden, once, onceSeen, promiscuous, bound.extend(binders(i))))
				return false;
		return true;
	}

	final public void addFree(Set<Variable> set, ExtensibleSet<Variable> bound, boolean includemetaapps, Set<Variable> base)
	{
		constructor.addFree(set, bound, includemetaapps, base);
		final int arity = arity();
		//final Term sortTerm = factory.sortOf(constructor.symbol());
		for (int i = 0; i < arity; ++i)
		{
			Term s = sub(i);
			s.addFree(set, bound.extend(binders(i)), includemetaapps, base);
		}
	}
	
	final public void addMetaCounts(Map<String, Integer> counts)
	{
		for (String key : constructor.propertyNames())
		{
			Term t = constructor.getProperty(key);
			if (t != null) t.addMetaCounts(counts);
		}
		for (Variable key : constructor.propertyVariables())
		{
			Term t = constructor.getProperty(key);
			if (t != null) t.addMetaCounts(counts);
		}
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
		{
			Term s = sub(i);
			if (s != null) s.addMetaCounts(counts);
		}
	}
	
	public void analyzeMetaUseContractum(Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers)
	{
		// The order in which the analysis is performed is significant.
		if (constructor.literalSort() == null && subAnalyzers.containsKey(constructor.symbol()))
    	{
    		MetaAnalyzer a = subAnalyzers.get(constructor.symbol());
    		a.analyzeMetaUseContractum(this, counts, subAnalyzers);
    	}
		else
		{
			final int arity = arity();
			for (int i = arity -1; i >= 0; --i)
			{
				Term s = sub(i);
				if (s != null) s.analyzeMetaUseContractum(counts, subAnalyzers);
			}
		}
		Stack<Term> terms = new Stack<Term>();
		for (Variable key : constructor.propertyVariables())
		{
			Term t = constructor.getProperty(key);
			if (t != null) terms.push(t);
		}
		while (!terms.isEmpty())
			terms.pop().analyzeMetaUseContractum(counts, subAnalyzers);
		
		for (String key : constructor.propertyNames())
		{
			Term t = constructor.getProperty(key);
			if (t != null) terms.push(t);
		}
		while (!terms.isEmpty())
			terms.pop().analyzeMetaUseContractum(counts, subAnalyzers);	
	}
	
	public void analyzeMetaUsePattern(Map<String, Integer> counts)
	{
		// Just propagate..
		for (String key : constructor.propertyNames())
		{
			Term t = constructor.getProperty(key);
			if (t != null) t.analyzeMetaUsePattern(counts);
		}
		for (Variable key : constructor.propertyVariables())
		{
			Term t = constructor.getProperty(key);
			if (t != null) t.analyzeMetaUsePattern(counts);
		}
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
		{
			Term s = sub(i);
			if (s != null) s.analyzeMetaUsePattern(counts);
		}
	}
	
	final public Sink subsubstitute(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable,Variable> bound, Set<Variable> possible)
	{
		if (possible.isEmpty())
			return copy(sink, false, bound); // Copying means there will be no substitutions so only pass redex bound variable renamings
		
		sink = sink.start(constructor().subsubstitute(sink, valuation, renamings, substitution, bound, possible));
		
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
		{
			ExtensibleMap<Variable,Variable> innerBound = bound;
			final Variable[] b = binders(i);
			if (b.length > 0)
			{
				Variable[] newb = new Variable[b.length];
				for (int j = 0; j < b.length; ++j)
				{
				    Variable v = b[j];
					newb[j] = factory.makeVariable(v.name(), v.promiscuous(), v.blocking(), v.shallow());
				}
				innerBound = bound.extend(b, newb);
				sink = sink.binds(newb);
			}
			sink = sub(i).subsubstitute(sink, valuation, renamings, substitution, innerBound, possible);
		}
		
		return sink.end();
	}

    public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
    {
        visitor.visitConstruction(this, true, bound);
        visitor.visitConstructor(constructor(), true, bound);
        constructor().visit(visitor, bound);
        visitor.visitConstructor(constructor(), false, bound);
        final int arity = arity();
        for (int i = 0; i < arity; ++i)
        {
            visitor.visitConstructionSub(this, i, true, bound);
            sub(i).visit(visitor, bound.extend(binders(i)));
            visitor.visitConstructionSub(this, i, false, bound);
        }
        visitor.visitConstruction(this, false, bound);
    }

    final public boolean equalsModulo(Term that, ExtensibleMap<Variable,Variable> renamings)
	{
		if (that.kind() != Kind.CONSTRUCTION)
			return false;

		final int arity = arity();
		if (arity != that.arity())
			return false;

		if (!constructor().equals(that.constructor()))
			return false;

		for (int i = 0; i < arity; ++i)
		{
			final Variable[] thisBinders = binders(i);
			final Variable[] thatBinders = that.binders(i);
			if (thisBinders.length != thatBinders.length)
				return false;
			ExtensibleMap<Variable,Variable> innerRenamings = renamings;
			for (int b = 0; b < thisBinders.length; ++b)
				innerRenamings = innerRenamings.extend(thisBinders[b], thatBinders[b]);
			if (!sub(i).equalsModulo(that.sub(i), innerRenamings))
				return false;
		}
		return true;
	}

	final public void appendTermTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean outer, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException
	{
		if (full)
		{
			appendSimpleTo(writer, used, noLinear, depth, full, namedProps, variableProps, omitProps);
			return;
		}
		
		if (depth <= 0)
		{
			writer.append("...");
			return;
		}
		boolean opened = false;
		Term t = this;
		
		// Handle "lambda prefix",
		if (arity() == 1 && binders(0) != null && binders(0).length == 1)
		{
			writer.open(outer ? "" : "(");
			opened = true;
			constructor().appendTo(writer, used, depth-1, full, namedProps, variableProps, omitProps);
			omitProps = null;
			Variable coloned;
			do
			{
				writer.append(" ");
				Variable v = t.binders(0)[0];
				String n = Util.safeVariableName(v, used, noLinear, false);
				writer.append(n);
				t = t.sub(0);
				coloned = null;
				if (Util.hasProperty(t, v))
				{
					writer.append(" : ");
					Util.getProperty(t, coloned = v).appendTo(writer, used, depth-1, full, namedProps, variableProps, omitProps);
				}
			}
			while (t.arity() == 1 && constructor().equals(t.constructor()) && t.binders(0).length == 1 && Util.hasAtMostVariableProperty(t, coloned));
			writer.append(" .\n");
			if (coloned != null)
			{
				if (omitProps == null)
					omitProps = new HashSet<Variable>();
				omitProps.add(coloned);
			}
		}
		
		// Handle sequence.
		while (t != null)
		{
			if (Util.isNull(t.constructor()) && t.arity() == 0)
			{
				if (!opened)
				{
					writer.open(outer ? "" : "(");
					opened = true;
				}
				t = null;
			}
			else if (Util.isCons(t.constructor()) && t.arity() == 2 && t.binders(0).length == 0 && t.binders(1).length == 0)
			{
				if (!opened)
				{
					writer.open(outer ? "" : "(\0");
					opened = true;
				}
				
				writer.open("");
				 if (t.sub(0) instanceof GenericConstruction)
					((GenericConstruction) t.sub(0)).appendRuleTo(writer, used, noLinear, depth, full, namedProps, variableProps, omitProps, true);
				else
					t.sub(0).appendTo(writer, used, depth-1, full, namedProps, variableProps, omitProps);
				
				if (t.sub(1).arity() == 0 && Util.isNull(t.sub(1).constructor()))
				{
					writer.append(';');
					t = null; // Special case for sequence termination
				}
				else
				{
					writer.append(';');
					t = t.sub(1);
				}
				writer.close("");
				writer.append('\n');
			}
			else
				break;
		}

		if (t != null)
		{
			if (t instanceof GenericConstruction)
				((GenericConstruction) t).appendRuleTo(writer, used, noLinear, depth, full, namedProps, variableProps, omitProps, opened); // always applied if t==this
			else
				t.appendTo(writer, used, depth, full, namedProps, variableProps, omitProps);
		}

		if (opened)
		{
			writer.close("");
			writer.append(outer ? "" : ")");
		}
	}

	/**
	 * Write construction in traditional way.
	 * @param writer to write to
	 * @param used maps already encountered variables to their printed name
	 * @param noLinear TODO
	 * @param depth remaining sublevels to print (or -1 for all)
	 * @param namedProps whether to include named properties in the output
	 * @param variableProps whether to include variable properties in the output
	 * @param omitProps specific variable properties to exclude
	 * @param nested whether in parentheses
	 * @throws IOException if the writing fails
	 */
	private void appendRuleTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps, boolean nested) throws IOException
	{
		if (Util.isRule(this.constructor()))
		{
			switch (arity())
			{
				case 2 :
					writer.open(nested ? "" : "(");
					sub(0).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.append("\n→\n");
					sub(1).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.close(nested ? "" : ")");
					writer.append("\n");
					return;
				case 3 :
					writer.open(nested ? "" : "(");
					sub(0).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.append(" :\n");
					sub(1).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.append("\n→\n");
					sub(2).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.close(nested ? "" : ")");
					writer.append("\n");
					return;
			}
		}
		else if (Util.isSort(this.constructor()))
		{
			switch (arity())
			{
				case 2 :
					writer.open(nested ? "\n" : "(\n");
					sub(0).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					Variable[] params = binders(1);
					if (params.length > 0)
					{
						writer.append("[");
						for (int p = 0; p < params.length; ++p)
							writer.append((p>0?",":"") + Util.safeVariableName(params[p], used, noLinear, false));
						writer.append("]");
					}
					writer.append("\n::=\n");
					sub(1).appendTo(writer, used, depth-1,full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.close(nested ? "" : ")");
					writer.append("\n");
					return;
			}
		}
		else if (Util.isFunctionSort(this.constructor()))
		{
			switch (arity())
			{
				case 2 :
					writer.open(nested ? "" : "(");
					sub(0).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.append("\n::\n");
					sub(1).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
					writer.close(nested ? "" : ")");
					writer.append("\n");
					return;
			}
		}
		appendFunctionTo(writer, used, noLinear, depth, nested, full, namedProps, variableProps, omitProps);
	}
	
	/**
	 * Write this function part of application to writer, without parentheses.
	 * @param writer to write to
	 * @param noLinear TODO
	 * @param depth remaining depth to p
	 * @param nested if true then a subexpression 
	 * @param namedProps whether to include named properties in the output
	 * @param variableProps whether to include variable properties in the output
	 * @param omitProps specific variable properties to exclude
	 * @throws IOException if the writing fails
	 */
	private void appendFunctionTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean nested, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException
	{
		if (Util.isApply(this.constructor()) && arity() == 2)
		{
			if (!nested)
				writer.open("(");
			// Special case for binary application...
			if (sub(0) instanceof GenericConstruction)
				((GenericConstruction) sub(0)).appendFunctionTo(writer, used, noLinear, depth, true, full, namedProps, variableProps, omitProps);
			else
				sub(0).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);

			writer.append("\n");
			sub(1).appendTo(writer, used, depth-1, full, namedProps, variableProps, LinkedExtensibleSet.EMPTY_VARIABLE_SET);
			if (!nested)
				writer.close(")");
		}
		else if (nested)
			appendTermTo(writer, used, noLinear, depth-1, false, full, namedProps, variableProps, omitProps); // retry top-level print
		else
			appendSimpleTo(writer, used, noLinear, depth-1, full, namedProps, variableProps, omitProps);
	}

	/**
	 * Write construction in traditional way.
	 * @param writer to write to
	 * @param noLinear TODO
	 * @param depth remaining depth
	 * @param full TODO
	 * @param namedProps whether to include named properties in the output
	 * @param variableProps whether to include variable properties in the output
	 * @param omitProps specific variable properties to exclude
	 * @throws IOException if the writing fails
	 */
	private void appendSimpleTo(FormattingAppendable writer, Map<Variable, String> used, boolean noLinear, int depth, boolean full, boolean namedProps, boolean variableProps, Set<Variable> omitProps) throws IOException
	{
		final int arity = arity();
		if (arity == 0)
			constructor().appendTo(writer, used, depth-1, full, namedProps, variableProps, omitProps);
		else
		{
			constructor().appendTo(writer, used, depth-1, full, namedProps, variableProps, omitProps);
			writer.open(arity == 1 && sub(0) != null && Util.isCons(sub(0).constructor()) ? "[" : "[\0");
			for (int i = 0; i < arity; ++i)
			{
				if (i > 0) writer.append(",\n");
				Set<Variable> coloned = new HashSet<Variable>();
				if (binders(i) != null && binders(i).length > 0)
				{
					for (int j = 0; j < binders(i).length; ++j)
					{
						if (j > 0) writer.append(" ");
						Variable v = binders(i)[j];
						String n = Util.safeVariableName(v, used, noLinear, false);
						writer.append(n);
						if (Util.hasProperty(sub(i), v))
						{
							writer.append(" : ");
							Util.getProperty(sub(i), v).appendTo(writer, used, depth+1, full, namedProps, variableProps, null);
							coloned.add(v);
						}
					}
					writer.open(" .\n");
				}
				if (sub(i) instanceof GenericTerm)
					((GenericTerm) sub(i)).appendTermTo(writer, used, noLinear, depth-1, false, full, namedProps, variableProps, coloned);
				else if (sub(i) != null)
					sub(i).appendTo(writer, used, depth-1, full, namedProps, variableProps, coloned);
                if (binders(i) != null && binders(i).length > 0)
                    writer.close("");
			}
			writer.close("]");
		}
	}

    public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
    {
    	int ends = 0;
    	
    	// Properties from constructor.
    	SortedSet<String> propertyNames = new TreeSet<String>();
    	for (String p : constructor.propertyNames())
    		propertyNames.add(p);
    	for (String p : propertyNames)
    	{
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY)); // PROPERTY[
    		++ends;
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_LITERAL)); // LITERAL[
    		sink = sink.start(sink.makeLiteral(p, CRS.STRING_SORT)).end(); // "p"
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[
    		sink = sink.start(factory.makeLiteral(CRS.STRING_SORT, CRS.STRING_SORT)).end(); // "$String"
    		sink = sink.start(factory.nilConstructor).end(); // ()
    		sink = sink.end(); // ] of SORT
    		sink = sink.end(); // ] of LITERAL
    		sink = constructor.getProperty(p).reify(sink, metaArgSort, freeSort, subReifiers); // t
    	}
    	SortedSet<Variable> propertyVariables = new TreeSet<Variable>();
    	for (Variable v : constructor.propertyVariables())
    		propertyVariables.add(v);
    	for (Variable v : propertyVariables)
    	{
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_PROPERTY)); // PROPERTY[
    		++ends;
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_VARIABLE_USE)).use(v).end(); // v
    		sink = constructor.getProperty(v).reify(sink, metaArgSort, freeSort, subReifiers); // t
    	}
    	
    	// Actual term.
    	if (constructor.literalSort() != null)
    	{
    		// Literal.
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_LITERAL)); // LITERAL[
    		sink = sink.start(sink.makeLiteral(constructor.symbol(), CRS.STRING_SORT)).end(); // literal
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_SORT)); // SORT[
    		sink = sink.start(sink.makeLiteral(constructor.literalSort(), CRS.STRING_SORT)).end(); // sort
    		sink = sink.start(factory.nilConstructor).end(); // ()
    		sink = sink.end(); // ] of SORT
    		sink = sink.end(); // ] of LITERAL
    	}
    	else if (subReifiers.containsKey(constructor.symbol()))
    	{
    		Reifier r = subReifiers.get(constructor.symbol());
    		sink = r.reify(sink, this, metaArgSort, freeSort, subReifiers);
    	}
    	else
    	{
    		// Real construction...
    		sink = sink.start(sink.makeConstructor(CRS.REIFY_CONSTRUCTION)); // CONSTRUCTION[
    		++ends;
    		sink = sink.start(sink.makeLiteral(constructor.symbol(), CRS.STRING_SORT)).end(); // c
    		Term sort = factory.sortOf(constructor.symbol());
    		Term form = sort == null ? null : factory.formOf(Util.symbol(sort), constructor.symbol());
    		for (int i = 0; i < arity(); ++i)
    		{
    			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
    			++ends;
    			Variable[] formBinders = form == null ? null : form.binders(i);
    			Term formSort = form == null ? null : form.sub(i);
    			for (int j = 0; j < binders(i).length; ++j)
    			{
    				Variable b = binders(i)[j];
    				sink = sink.start(sink.makeConstructor(CRS.REIFY_BINDER)); // BINDER[
    				sink = sink.start(sink.makeConstructor(b.promiscuous() ? CRS.REIFY_PROMISCUOUS : CRS.REIFY_LINEAR)).end(); // LINEAR/PROMISCUOUS
    				sink = sink.start(sink.makeConstructor(b.blocking() ? CRS.REIFY_BLOCK : CRS.REIFY_PERMIT)).end();
    				sink = sink.start(sink.makeConstructor(b.shallow() ? CRS.REIFY_SHALLOW : CRS.REIFY_DEEP)).end();
    		    				Term binderSort = formSort == null ? factory.nil() : Util.propertiesHolder(formSort).getProperty(formBinders[j]);
    				sink = GenericCRS.reifySort(factory, sink, binderSort);
    				freeSort.put(b, binderSort);
    				sink = Util.occurrenceDescription(sink, sub(i), b); // (OTHER/META-USE[]/...)
    				Variable[] binders = {b};
    				sink = sink.binds(binders); // bij .
    			}
    			sink = sink.start(sink.makeConstructor(CRS.REIFY_ARGUMENT)); // ARGUMENT[
    			sink = GenericCRS.reifySort(factory, sink, formSort);
    			sink = sub(i).reify(sink, metaArgSort, freeSort, subReifiers); // subi
    			sink = sink.end(); // ] of ARGUMENT
    			for (@SuppressWarnings("unused") Variable b : binders(i))
    				sink = sink.end(); // ] of BINDER
    		}
    		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // NIL (of list of arguments)
    	}
    	while (ends-- > 0)
    		sink = sink.end(); // ]]]]] of CONS/CONSTRUCTION/PROPERTY
	    return sink;
    }

	public SortedSet<Path> paths(Path base)
	{
		SortedSet<Path> paths = super.paths(base);
		paths.addAll(constructor.paths(base));
		return paths;
	}
	
	// Pattern...
	
	public boolean match(Match match, Term redex, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		final int arity = arity();
		if (redex.kind() != Kind.CONSTRUCTION || arity != redex.arity())
			return false; // we shouldn't be here...
		for (int i = 0; i < arity; ++i)
		{
			final Variable[] patternBinders = binders(i);
			final Variable[] termBinders = redex.binders(i);
			final int binderLength = patternBinders.length;
			if (binderLength != termBinders.length)
				return false;
			
            // Visit binders...
			 for (int j = 0; j < binderLength; ++j)
			 {
			     Variable pb = patternBinders[j];
			     Variable b = termBinders[j];
			     if (!pb.promiscuous() && b.promiscuous())
			         return false; // linear pattern binder does not match unrestricted real binder
			     match.putVariable(pb, b);
			 }
// TODO: linearity.
//            ExtensibleSet<Variable> nestedOnce = SimpleVariableSet.make(once);
//            for (int j = 0; j < binderLength; ++j)
//            {
//                Variable v = patternBinders[j];
//                Variable b = termBinders[j];
//                
//                // We are matching v -> b.
//                if (v.promiscuous())
//                    if (b.promiscuous())
//                        ; // v -> b : safe
//                    else
//                        return false; // v -> ¹b : fail
//                else
//                    if (b.promiscuous())
//                        nestedOnce = nestedOnce.extend(b); // ¹v -> b : we must check that b occurs linearly
//                    else
//                        ; // ¹v -> ¹b : safe
//            }
//			Collection<Variable> nestedOnceSeen = (onceSeen == null ? new HashSet<Variable>() : onceSeen);
//			 
			 if (!((Pattern) sub(i)).match(match, redex.sub(i), bound.extend(termBinders), contractionCount, promiscuous, once, onceSeen))
			     return false;
		}
		
		// We check the constructor last so variables in variable property constraints have already been matched.
		return constructor().match(match, redex.constructor(), bound, contractionCount, promiscuous, once, onceSeen);
	}

	@Override
	protected Unification unifyThese(Unification unification,
			Pattern that, StackedMap<Variable> rho,
			StackedMap<Variable> rhoprime, Set<String> existingMVars) throws CRSException {

		switch(that.kind()){
		case CONSTRUCTION : {
			if (that instanceof GenericEvaluator){
				//Delegate (look at this mess!)
				return ((GenericEvaluator)that).unifyThese(unification, this, rhoprime, rho, existingMVars);
			}
			int arity = this.arity();
			Unification u = unification;
			
			if (arity != that.arity())
			{
				//different number of children. Unification fails.
				return null;
			}

			for (int subIndex = 0; subIndex < arity; ++subIndex)
			{
                if (this.binders(subIndex).length != that.binders(subIndex).length)
                {
                	// different subterm binder rank, so fail
                    return null;
                }
            }

            // Attempt to construct unified subterms...
            //Variable[][] bss = new Variable[arity][]; // base subterm binders
            //Term[] ss = new Term[arity]; // base subterms
            for (int subIndex = 0; subIndex < arity; ++subIndex)
            {
            	Variable[] xs = this.binders(subIndex);
            	Variable[] xprimes = that.binders(subIndex); 

            	int bLength = xs.length; 
            	assert bLength == xprimes.length;
            	
            	//Entering new scope level.
            	rho.pushscope();
            	rhoprime.pushscope();
            	
            	//add binder associations for new scope
            	for (int bIndex = 0; bIndex < bLength; bIndex++){
            		Variable freshvar = factory.makeVariable(xs[bIndex].name() + xprimes[bIndex].name(), false, false, false);
            		rho.put(xs[bIndex], freshvar);
            		rhoprime.put(xprimes[bIndex], freshvar);
            	}
            	
            	//Unify subterm
            	Unification subU = ((GenericTerm)(this.sub(subIndex))).unifyThese(u, 
            																	  (GenericTerm)(that.sub(subIndex)), 
            																	  rho, 
            																	  rhoprime, 
            																	  existingMVars);
            	
            	if (subU == null){
            		//subterm unification failed
            		return null;
            	}
            	
            	//Unification of subterm succeeded. Exit scope and update unification for next subterm
            	rho.popscope();
            	rhoprime.popscope();
            	u = subU;
            }
            
            //Unification of subterms succeeded. Unification of constructors remains

			Constructor c = this.constructor().unify(u, that.constructor(), rho, rhoprime);
    		if (c == null){
    			//Constructors do not match. Unification fails
    			return null;
    		}
    		
    		return u;
             
		}
    	case VARIABLE_USE:{
    		//Construction does not unify with variable.
    		return null; 
    	}
    	case META_APPLICATION:{
    		//Delegate to GenericMetaApplication.unifyThese()
    		return ((GenericMetaApplication)that).unifyThese(unification, this, rhoprime, rho, existingMVars);
    	}
    	}
    	assert false;
    	return null;
	}

	
    // Contractum...
	
	@Override
	protected void generateBitmasks(Set<Variable> legalvars,
			StackedMap<Variable> rhoprime, StackedMap<Variable> inscope,
			Map<String, Boolean[]> bitmasks,
			Map<String, GenericMetaApplication> occurrences) {
		int arity = this.arity();
		for (int i = 0; i < arity; i++){
			inscope.pushscope();
			Variable[] binds = this.binders(i);
			for (int j = 0; j < binds.length; j++){
				inscope.put(binds[j], binds[j]);
			}
			((GenericTerm)this.sub(i)).generateBitmasks(legalvars, rhoprime, inscope, bitmasks, occurrences);
			inscope.popscope();
		}
	}

	public Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings)
	{
		if (factory.watchedConstructions.contains(constructor().symbol()))
		{
        	System.out.println("ConstructorWatch: "+constructor().symbol());
		}
		sink = sink.start(constructor().contract(valuation, renamings));
		
		final int arity = arity();
		for (int i = 0; i < arity; ++i)
		{
			// Bindings for i'th subterm are those from the redex.
			ExtensibleMap<Variable,Variable> innerRenamings = renamings;
			Variable[] currentBinds = binders(i);
			if (currentBinds.length > 0)
			{
				// Construct renamings for subterm construction.
				Variable[] mappedBinds = new Variable[currentBinds.length];
				for (int b = 0; b < currentBinds.length; ++b)
				{
					Variable currentVariable = currentBinds[b];
					Variable renamedVariable = valuation.getVariable(currentVariable); // already allocated?
					if (renamedVariable == null)
					{
					    // This is the normal case where fresh bound variables are needed - the above is merely to allow preallocation of all bound variables by Valuation. 
					    renamedVariable = factory.makeVariable(currentVariable.name(), currentVariable.promiscuous(), currentVariable.blocking(), currentVariable.shallow());
					}
                    innerRenamings = innerRenamings.extend(currentVariable, renamedVariable);
					mappedBinds[b] = renamedVariable;
				}
				sink = sink.binds(mappedBinds);
			}
			
			// Copy subterm using the new bindings.
			sink = ((Contractum) sub(i)).contract(sink, valuation, innerRenamings);
		}
		
		return sink.end();
	}

	@Override
	protected boolean occurs(String mvar, Unification unification) {
		for (int i = 0; i < arity(); i++){
			if (((GenericTerm) sub(i)).occurs(mvar, unification)){
				return true;
			}
		}
		return false;
	}

	public Set<String> mvars() {
		//return all metavariables of subterms
		Set<String> result = new HashSet<String>();
		int arity = this.arity();
		for (int i = 0; i < arity; i++){
			result.addAll(((GenericTerm)sub(i)).mvars());
		}
		//TODO: Add metavariables from constructor properties
		return result;
	}

	@Override
	public GenericTerm makeUnificationCopy(StackedMap<Variable> varrenamings,
										   Map<String, String> mvarrenamings) {

		//TODO: Might need to pass mvarrenamings along as well.
		ExtensibleMap<Variable, Variable> renamings = new LinkedExtensibleMap<Variable, Variable>();
        final Constructor c = constructor().copy(renamings.extend(varrenamings));
        
        final int a = arity();
        final Variable[][] bss = new Variable[a][];
        final GenericTerm[] ss = new GenericTerm[a];
        for (int i = 0; i < a; ++i)
        {
            final Variable[] bs = new Variable[binders(i).length];
            varrenamings.pushscope();
            for (int j = 0; j < bs.length; ++j)
            {
                Variable v = binders(i)[j];
                bs[j] = v;
                varrenamings.put(v, v);
            }
            bss[i] = bs;
            ss[i] = ((GenericTerm) sub(i)).makeUnificationCopy(varrenamings, mvarrenamings);
            varrenamings.popscope();
        }
        return newConstruction(c, bss, ss, false);
	}

	@Override
	public GenericTerm applySubstitutes(Unification unification) {
		Constructor newc = this.constructor().copy(LinkedExtensibleMap.EMPTY_RENAMING);
		
		Variable[][] newbinds = new Variable[this.arity()][];
		GenericTerm[] newsubs = new GenericTerm[this.arity()];
		for (int i = 0; i < newsubs.length; i++){
			newbinds[i] = new Variable[this.binders(i).length];
			System.arraycopy(this.binders(i), 0, newbinds[i], 0, this.binders(i).length);
			newsubs[i] = ((GenericTerm)(this.sub(i))).applySubstitutes(unification);
		}
		return newConstruction(newc, newbinds, newsubs, false);
	}
	
	// Object...

    @Override
    public int hashCode()
    {
    	int h = constructor().hashCode() + Kind.CONSTRUCTION.ordinal();
    	return h;
    }
}
