/* Copyright (c) 2006, 2007 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

import net.sf.crsx.CRS;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Match;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.Util;

/**
 * Generic implementation of match in progress.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericMatch.java,v 3.2 2013/12/05 03:28:28 krisrose Exp $
 */
class GenericMatch implements Match, Cloneable
{
	// State.
    
    /** Host crs. */
    private final CRS crs;
	
	/** Matched variables. */
	private ExtensibleMap<Variable, Variable> matchedVariables = LinkedExtensibleMap.EMPTY_RENAMING;
	
	/** Top mapping link for meta-application matches. */
	private SubstituteLink lastSubstitute;
	
    /** Number of substitutions of explicit meta-applications in contractum. */
    private final Map<String, Integer> copyCount;
    
    // Constructor.
    
    /**
     * Create empty match. 
	 * @param crs it lives in (may be null with no ill effects)
	 * @param copyCount maps those meta-variables that are explicit to the number of times they will be substituted (null disables the feature)
	 * @param reusableBound maps bound variables in pattern to the variable in contractum they must be reused as (null means none)
	 */
	GenericMatch(CRS crs, Map<String, Integer> copyCount, Map<String, Term> global)
	{
	    this.crs = crs;
	    this.copyCount = (copyCount != null ? copyCount : LinkedExtensibleMap.EMPTY_NAMED_COUNTS);
	    if (global != null)
	    	for (Term g : global.values())
	    	{
	    		Variable gv = Util.variableWithOptionalSortVariable(g);
	    		matchedVariables = matchedVariables.extend(gv, gv); // global variables act as if already matched against themselves...
	    	}
	}

    /**  For cloning. */
    GenericMatch(GenericMatch old)
    {
        crs = old.crs;
        matchedVariables = old.matchedVariables;
        lastSubstitute = old.lastSubstitute;
        copyCount = old.copyCount;
    }
    
	// Match...

	public void putSubstitute(String name, Variable[] binders, Term term)
	{
		if (copyCount.containsKey(name))
		    // Use substitution that merely reuses bound variables and copies...
		    lastSubstitute = new SubstituteCreatedCopyLink(lastSubstitute, name, binders, term, copyCount.get(name));
		else
		    // Unoptimized generic substitution.
		    lastSubstitute = new SubstituteCreatedSubstituteLink(lastSubstitute, name, binders, term);
	}

	public void putSubstitute(String name, Substitute substitute)
	{
		assert substitute != null;
		lastSubstitute = new SubstituteDelegateLink(lastSubstitute, name, substitute);
	}
	
	public Substitute getSubstitute(String metaVariable)
	{
		for (SubstituteLink link = lastSubstitute; link != null; link = link.parent)
			if (link.from != null && link.from.equals(metaVariable))
				return link.getSubstitute();
		return null;
	}
	
	public void putVariable(Variable from, Variable to)
	{
		matchedVariables = matchedVariables.extend(from, to);
	}
	
	public Variable getVariable(Variable variable)
	{
		return matchedVariables.get(variable);
	}
	
    public ExtensibleMap<Variable, Variable> renamings()
	{
		return matchedVariables;
	}
    
    public Match clone()
    {
        return new GenericMatch(this);
    }
    
	// Helpers.

	/** Single substitute mapping. */
	protected abstract class SubstituteLink
	{
		/** Parent in link chain. */
		final SubstituteLink parent;
		/** Meta-variable mapped. */
		final String from;
		/** Construct link with substitute. */
		private SubstituteLink(SubstituteLink parent, String from)
		{
			this.parent = parent;
			this.from = from;
		}
		// Methods.
		/** Return the substitute for this link. */
		abstract Substitute getSubstitute();
        /** Check that there are no null variables... */
        boolean nonullvariable(Variable[] bs)
        {
            for (int i = 0; i < bs.length; ++i)
                if (bs[i] == null) return false;
            return true;
        }
	}

	/** Single substitute mapping. */
	protected class SubstituteDelegateLink extends SubstituteLink
	{
		Substitute substitute;
		/** Construct link with substitute. */
		private SubstituteDelegateLink(SubstituteLink parent, String from, Substitute substitute)
		{
			super(parent, from);
			this.substitute = substitute;
		}
		// SubstituteLink...
		Substitute getSubstitute()
		{
			return substitute;
		}
		// Object...
		public String toString()
		{
			return substitute.toString();
		}
	}

    /** Single substitute mapping. */
    final protected class SubstituteCreatedCopyLink extends SubstituteLink implements Substitute
    {
        /** Bindings of substitute (variables that occur in matched term). */
        final private Variable[] bindings;
        /** Body of substitute (actually matched term). */
        private Term matched;
        /** Number of outstanding uses of {@link #substitute(Sink, Valuation, ExtensibleMap, Term[])}. */
        private int substituteCount;
        /**
         * Construct link with substitute.
         * @param parent link
         * @param from meta-variable
         * @param bindings of substitute
         * @param body of substitute
         * @param count number of times {@link #substitute(Sink, Valuation, ExtensibleMap, Term[])} will be called (-1 means unknown)
         */
        private SubstituteCreatedCopyLink(SubstituteLink parent, String from, Variable[] bindings, Term body, int substituteCount)
        {
            super(parent, from);
            this.bindings = bindings;
            this.matched = body;
            assert nonullvariable(bindings);
            this.substituteCount = substituteCount;
        }
        // SubstituteLink...
        Substitute getSubstitute()
        {
            return this;
        }
        // Substitute...
        public boolean rematch(Match match, Variable[] bs, Term term)
        {
            // Meta-variable previously matched to substitute.
            // Multiple occurrences of a pattern meta-application must have same variables in the list.
            if (!Arrays.equals(bs, bindings))
                return false;
            
            return getBody().equalsModulo(term, LinkedExtensibleMap.EMPTY_RENAMING);
        }
		public Copyable substitute(final Valuation valuation, final Term[] sub)
		{
			return new Copyable()
			{
				public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renamings)
				{
		            final int arity = sub.length;
		            assert arity == bindings.length: "rhs meta-application arity does not match pattern for "+valuation.name()+" (probably meta-variable name clash with $Meta rules)";
		            if (crs instanceof GenericCRS) ++((GenericCRS) crs).substituteByCopy; // TODO: distinguish references...
		            sink = getBody().copy(sink, substituteCount==1, renamings); // discard the last occurrence(s)
		            if (substituteCount > 1) --substituteCount;
		            return sink;
				}
			};
        }
        public Variable[] getBindings()
        {
            return bindings;
        }
        public Term getBody()
        {
            return matched;
        }
		public void replaceBody(Term replacement)
		{
			matched = replacement;
		}

        // Object...
        public String toString()
        {
            StringBuilder w = new StringBuilder();
            Map<Variable,String> used = new HashMap<Variable, String>();
            w.append("[(");
            for (int i = 0; i < bindings.length; ++i)
            {
                if (i > 0) w.append(",");
                Variable v = bindings[i];
                w.append(v.name());
                used.put(v, v.name());
            }
            w.append(") => ");
            try
            {
                getBody().appendTo(w, used, Integer.MAX_VALUE, false, true, true, null, false);
            }
            catch (IOException e)
            {
                w.append("<subterm>");
            }
            w.append("]");
            return w.toString();
        }
    }

	/** Single substitute mapping. */
	protected class SubstituteCreatedSubstituteLink extends SubstituteLink implements Substitute
	{
		/** Bindings of substitute (variables that occur in matched term). */
		final private Variable[] bindings;
		/** Body of substitute (actually matched term). */
		private Term matched;
		/**
		 * Construct link with substitute.
		 * @param parent link
		 * @param from meta-variable
		 * @param bindings of substitute
		 * @param body of substitute
		 */
		private SubstituteCreatedSubstituteLink(SubstituteLink parent, String from, Variable[] bindings, Term body)
		{
			super(parent, from);
			this.bindings = bindings;
			this.matched = body;
			assert nonullvariable(bindings);
		}
		// SubstituteLink...
		Substitute getSubstitute()
		{
			return this;
		}
		// Substitute...
		public boolean rematch(Match match, Variable[] bs, Term term)
		{
			// Meta-variable previously matched to substitute.
			// Multiple occurrences of a pattern meta-application must have same variables in the list.
			if (!Arrays.equals(bs, bindings))
				return false;
			return getBody().equalsModulo(term, LinkedExtensibleMap.EMPTY_RENAMING);
		}
		public Copyable substitute(final Valuation valuation, final Term[] sub)
		{
			return new Copyable()
			{
				public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renamings)
				{
					if (crs instanceof GenericCRS) ++((GenericCRS) crs).substituteProper;
		            final int arity = sub.length;
		            if (arity != bindings.length)
		            	assert false : "rhs meta-application arity does not match pattern for "+valuation.name();
		            // There is actual substitution work to do so we must...
		            ExtensibleMap<Variable, Contractum> substitution = LinkedExtensibleMap.EMPTY_SUBSTITUTION;
		            for (int i = 0; i < arity; ++i)
		            {
		            	if (i  >= bindings.length || i >= sub.length)
		            		System.err.println("Error in copy of subterm ");
		            	else
		            		substitution = substitution.extend(bindings[i], (Contractum) sub[i]);
		            }
		            // NOTE: THIS IS THE ONLY ENTRY POINT TO CALLING Term.subsubstitute() FOR MATCHING (except for the properties one...)!
		            // (Unification also uses it in class UnificationSubstitute.)
		            return getBody().subsubstitute(sink, valuation, renamings, substitution, LinkedExtensibleMap.EMPTY_RENAMING, new HashSet<Variable>(substitution.keySet()));
				}
			};
		}
		public Variable[] getBindings()
        {
            return bindings;
        }
        public Term getBody()
        {
            return matched;
        }
		public void replaceBody(Term replacement)
		{
			matched = replacement;
		}
        // Object...
		public String toString()
		{
			StringBuilder w = new StringBuilder();
            Map<Variable,String> used = new HashMap<Variable, String>();
            w.append("[(");
            for (int i = 0; i < bindings.length; ++i)
            {
                if (i > 0) w.append(",");
                Variable v = bindings[i];
                w.append(v.name());
                used.put(v, v.name());
            }			
			w.append(") => ");
			try
			{
				getBody().appendTo(w, used, Integer.MAX_VALUE, false, true, true, null, false);
			}
			catch (IOException e)
			{
				w.append("<subterm>");
			}
			w.append("]");
			return w.toString();
		}
	}

	// Sic.
	
	public String toString()
	{
		StringBuilder w = new StringBuilder();
		w.append("[ ");
		for (SubstituteLink link = lastSubstitute; link != null; link = link.parent)
		{
			w.append(link.from);
			w.append(" => ");
			w.append(link.toString());
			if (link.parent != null)
				w.append(",\n");
		}
		w.append("\n]");
		if (matchedVariables != null)
			w.append("+"+matchedVariables.toString());
		return w.toString();
	}
}
