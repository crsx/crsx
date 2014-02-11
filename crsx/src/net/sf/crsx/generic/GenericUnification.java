
package net.sf.crsx.generic;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Match;
import net.sf.crsx.Pattern;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleMap;

/**
 *	Unification implementation 
 * 
 * @author Jacob Johannsen (jjohann@us.ibm.com)
 *
 */
public class GenericUnification implements Unification
{

	private static class UnificationSubstitute implements Substitute{
	
		private Variable[] binders;
		
		private Pattern body;
		
		public UnificationSubstitute(Variable[] binders, Pattern body){
			this.binders = new Variable[binders.length];
			System.arraycopy(binders, 0, this.binders, 0, binders.length);
			this.body = body;
		}
		
		public Variable[] getBindings() {
			Variable[] res = new Variable[binders.length];
			System.arraycopy(this.binders, 0, res, 0, this.binders.length);
			return res;
		}
	
		public Pattern getBody() {
			Pattern res = (Pattern)this.body.copy(false, LinkedExtensibleMap.EMPTY_RENAMING);
			return res;
		}

		public void replaceBody(Term replacement)
		{
			body = (Pattern) replacement;
		}

		public boolean rematch(Match match, Variable[] binders, Term term) {
			throw new UnsupportedOperationException("rematch() not supported for UnificationSubstitute");
		}
	
		public Copyable substitute(final Valuation valuation, final Term[] replacement) {
			return new Copyable()
			{
				public Sink copy(Sink sink, boolean discard, ExtensibleMap<Variable, Variable> renamings)
				{
		            final int arity = replacement.length;
		            assert arity == binders.length: "Substitute applied to wrong number of arguments during unification";
		            ExtensibleMap<Variable, Contractum> substitution = LinkedExtensibleMap.EMPTY_SUBSTITUTION;
		            for (int i = 0; i < arity; ++i)
		                substitution = substitution.extend(binders[i], (Contractum) replacement[i]);
		            return body.subsubstitute(sink, valuation, renamings, substitution, LinkedExtensibleMap.EMPTY_RENAMING, new HashSet<Variable>());
				}
			};
		}
	}

	//Maps from metavariables (names) to substitutes.
	private HashMap<String, Substitute> sigma = new HashMap<String, Substitute>();

	//Maps from free variables to fresh variables.
	private HashMap<Variable, Variable> phi = new HashMap<Variable, Variable>();

	private GenericTerm t1;
	private GenericTerm t2;
	//private ExtensibleSet<Variable> contextVars;
	
	/**
	 * Construct a new Unification object. Does not perform unification on its own.
	 * @param t1 the first term to be unified
	 * @param t2 the second term to be unified
	 */
	public GenericUnification(GenericTerm t1, ExtensibleSet<Variable> contextVars, GenericTerm t2){
		this.t1 = t1;
		this.t2 = t2;
		//this.contextVars = contextVars;
	}
	
	
	/* (non-Javadoc)
	 * @see net.sf.crsx.Unification#getSubstitute(java.lang.String)
	 */
	public Substitute getSubstitute(String metavar)
	{
		return sigma.get(metavar);
	}

	/* (non-Javadoc)
	 * @see net.sf.crsx.Unification#getVariable(net.sf.crsx.Variable)
	 */
	public Variable getVariable(Variable var)
	{
		return phi.get(var);
	}


	/* (non-Javadoc)
	 * @see net.sf.crsx.Unification#putSubstitute(java.lang.String, net.sf.crsx.Substitute)
	 */
	public void putSubstitute(String metavar, Variable[] binders, Term body) {
		Substitute sub = new UnificationSubstitute(binders, (Pattern)body);
		sigma.put(metavar, sub);
	}

	/**
	 * Introduces new associations, and adds associations transitively.
	 * 
	 * @param var the source variable
	 * @param var2 the target variable
	 * @param map the map in which to introduce the new association
	 */
	private void put(Variable var, Variable var2, Map<Variable, Variable> map)
	{
		//Invariant: a variable v is always mapped directly to the transitively closed value of all
		//associations put in the map (provided there are no cycles in the transitive closure).

		//Find target of association
		Variable target = map.get(var2);
		if (target == null)
		{
			target = var2;
		}

		//Find sources induced by new association
		Set<Variable> sources = new TreeSet<Variable>();
		sources.add(var);
		for (Variable k : map.keySet())
		{
			if (var.equals(map.get(k)))
			{
				sources.add(k);
			}
		}

		//Add induced associations
		for (Variable s : sources)
		{
			map.put(s, target);
		}

	}

	/* (non-Javadoc)
	 * @see net.sf.crsx.Unification#putVariable(net.sf.crsx.Variable, net.sf.crsx.Variable)
	 */
	public void putVariable(Variable var, Variable var2)
	{
		this.put(var, var2, phi);
	}

	/** Helper to create unused meta-variable name. */
	public static String makeMetaVar(String unifiedMetaVariable, Set<String> existingmvars)
	{
	    String result = unifiedMetaVariable;
	    for (int i = 0; existingmvars.contains(result); ++i)
	        result = unifiedMetaVariable + "-" + i;
	    return result;
	}


	/**
	 * Returns the first pattern of this unification
	 * @return
	 */
	public GenericTerm getT1() {
		return t1;
	}

	/**
	 * Returns the second pattern of this unification
	 * @return
	 */
	public GenericTerm getT2() {
		return t2;
	}

	public GenericTerm getMGU(){
		ExtensibleMap<Variable, Variable> phix = new LinkedExtensibleMap<Variable, Variable>().extend(phi); 
		return (GenericTerm)t1.applySubstitutes(this).copy(false, phix);
	}
	
}
