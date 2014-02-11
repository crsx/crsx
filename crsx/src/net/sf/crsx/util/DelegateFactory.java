/* Copyright © 2008 IBM Corporation. */
package net.sf.crsx.util;

import java.io.IOException;
import java.io.Reader;
import java.math.BigDecimal;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.Builder;
import net.sf.crsx.CRSException;
import net.sf.crsx.Copyable;
import net.sf.crsx.Factory;
import net.sf.crsx.Maker;
import net.sf.crsx.Parser;
import net.sf.crsx.Sink;
import net.sf.crsx.Stub;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * {@link Factory} that delegates all methods to another.
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: DelegateFactory.java,v 3.1 2013/12/09 05:48:39 krisrose Exp $
 */
public abstract class DelegateFactory<T extends Term> extends DelegateMaker implements Factory<T>
{
	// Methods.
	
	/** The factory to delegate to.*/
	public abstract Factory<T> factory();
	
	// Factory...

	public Builder builder()
	{
		return factory().builder();
	}

    public T parse(Reader reader, String category, String unit, int firstLine, int firstColumn, ExtensibleMap<String, Variable> bound) throws CRSException
    {
        return factory().parse(reader, null, null, 1, 1, null);
    }

    public T literal(String text)
    {
        return factory().literal(text);
    }
    
	public T literal(long integer)
	{
		return factory().literal(integer);
	}
	
    public T literal(double d)
    {
	    return factory().literal(d);
    }

    public T literal(BigDecimal b)
    {
	    return factory().literal(b);
    }

    public T literal(boolean test)
    {
	    return factory().literal(test);
    }

	public T materialize(Copyable copyable, boolean discard)
	{
		return factory().materialize(copyable, discard);
	}

	public void process(Term term) throws CRSException
    {
        factory().process(term);
    }

    public boolean defined(String name)
	{
		return factory().defined(name);
	}

    public Stub get(String name)
	{
		return factory().get(name);
	}

	public void set(String name, Stub value)
	{
		factory().set(name, value);
	}

    public Sink sink(Appendable appendable)
    {
        return factory().sink(appendable);
    }

	public void message(String text)
	{
		factory().message(text);
	}

	public void setSinker(Class<? extends Sinker> sinkClass)
	{
		factory().setSinker(sinkClass);
	}

	public void setSortForm(Term sort, Set<Variable> sortParams, Term form, boolean function, boolean override) throws CRSException
	{
		factory().setSortForm(sort, sortParams, form, function, false);
	}
	
	public Set<String> getSortedConstructors()
	{
		return factory().getSortedConstructors();
	}
	
	public void setSortAlias(String name, String alias) throws CRSException
	{
		factory().setSortAlias(name, alias);
	}

    public String unalias(String sort)
    {
	    return factory().unalias(sort);
    }

	/*
	public void reform(Iterable<Pattern> patterns, Iterable<Contractum> contractae)
	{
		factory().reform(patterns, contractae);
	}
	*/

	public void addGrammar(String classname, Collection<String> categories) throws CRSException
	{
		factory().addGrammar(classname, categories);
	}

	public boolean hasGrammar(String classname, Collection<String> categories)
	{
		return factory().hasGrammar(classname, categories);
	}

	// Sorting...

	public Iterable<String> sorts()
	{
		return factory().sorts();
	}

	public Set<String> sortDataSymbols(String name)
	{
		return factory().sortDataSymbols(name);
	}
	
	public boolean isSortConstructor(String name)
	{
		return factory().isSortConstructor(name);
	}
	
	public boolean sortAllowsVariables(String name)
	{
		return factory().sortAllowsVariables(name);
	}
	
    public Set<String> sortsWithClosedData()
    {
	    return factory().sortsWithClosedData();
    }

	public Term sortOf(String constructor)
	{
		return factory().sortOf(constructor);
	}

    public List<Variable> sortParams(String sort)
    {
	    return factory().sortParams(sort);
    }

    public Term formOf(String sort, String constructor)
    {
	    return factory().formOf(sort, constructor);
    }
	
	public Set<Pair<Term,Term>> formsOf(String constructor)
	{
		return factory().formsOf(constructor);
	}

	public boolean isFunction(String constructor)
	{
		return factory().isFunction(constructor);
	}

	public boolean isData(String constructor)
	{
		return factory().isData(constructor);
	}

	// Parser...

	public Parser parser(Factory<? extends Term> factory)
	{
		return factory().parser(factory); // sic
	}
	
	public Sink parse(Sink sink, String category, Reader reader, String unit, int line, int column, ExtensibleMap<String, Variable> bound) throws CRSException, IOException
	{
		return factory().parse(sink, category, reader, unit, line, column, bound);
	}

	public Iterable<String> categories()
	{
		return factory().categories();
	}

	public void setParserVerbose(boolean verbose)
	{
		factory().setParserVerbose(verbose);
	}

	public void setParserLocation(boolean captureLocations)
	{
		factory().setParserLocation(captureLocations);
	}
	
	// DelegateMaker...
	
	final public Maker maker()
	{
		return factory();
	}
	
	// ErrorHandler
	
	public void fatal(String message, String... pretext) throws CRSException
	{
		factory().fatal(message, pretext); 
	}
	
	public void error(String message, String... pretext) throws CRSException
	{
		factory().error(message, pretext);
	}
	
	public void warning(String message, String... pretext)
	{
		factory().warning(message, pretext);
	}
	
	public void errorCheck(String message) throws CRSException
	{
		factory().errorCheck(message);
	}

	public Map<String, Term> sortsetFor(String sort)
    {
	    return factory().sortsetFor(sort);
    }
}
