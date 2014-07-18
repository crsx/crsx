package net.sf.crsx.generic;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

import net.sf.crsx.CRSException;
import net.sf.crsx.Kind;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.util.Pair;

/**
 * This class is used to check whether the system is "full" (or "complete").
 * That is to say, if a rule is reduced to normal form, then the normal form
 * may only contain data symbols.  This is guaranteed if:
 * <ul>
 * <li> the system is left-linear
 * <li> the system is fully extended
 * <li> for all function constructors, there are rules for all data-combinations
 *   of patterns; for example a rule Add taking two natural numbers has cases
 *   for Add[O,O], Add[S[n],O], Add[O,S[m]], Add[S[n],S[m]] -- of course, some
 *   of those cases may overlap, and the n/m themselves may be split along
 *   several cases; if the sort has syntactical variables there should also be
 *   a case for these, and there should always be a case for all bound
 *   variables.
 * <li> there are no data constructors with binders which are semantic variables
 *   as this might lead to a case F[x.G[x]], where G cannot match on the x.
 * </ul>
 */

public class FullnessChecker
{
	/** The factory is used for obtaining sort information */
	private GenericFactory factory;
	
	/**
	 * Give a warning to the user (but don't abort).
	 * @param txt the warning to be given
	 */
	private void warning(String txt)
	{
		factory.warning(txt, "Fullness checker warning: ");
	}
	
	/**
	 * Give an error message to the user, which is collected and not shown
	 * until some functionality calls errorCheck
	 * @param txt the error to be displayed
	 * @throws CRSException if the error handler (the calling CRS) is set
	 * 	 to be strict about errors 
	 */
	private void error(String txt) throws CRSException
	{
		factory.warning(txt, "Fullness checker error: ");
	}
	
	/**
	 * Initialize the fullness checker
	 * @param factory the factory it must use for sort information
	 */
	public FullnessChecker(GenericFactory fac)
	{
		factory = fac;
	}
	
	/**
	 * Check fullness of a given set of rules
	 * @param rules a set of rules, given by name, and with complete sort information
	 * @throws CRSException if there were previous errors, or an error is given
	 * 	 because the system is not full, and the CRS responsible for error-handling
	 *   has strict checking enabled
	 */
	/*
	public void run(Map<String,GenericRule> rules) throws CRSException
	{
		factory.errorCheck("errors prevent checking fullness of rules");
		
		Set<String> constructors = factory.getKnownConstructors();

		// make an overview of all declarations of function constructors
		Map<String,Set<String>> ruleByConstructor = new HashMap<String,Set<String>>();
		for (String F : constructors)
		{
			if (!factory.isFunction(F)) continue;
			Set<Pair<Term,Term>> forms = factory.formsOf(F);
			for (Pair<Term,Term> pair : forms)
			{
				Map<Variable,String> varmap = new HashMap<Variable,String>();
				ruleByConstructor.put(printSortFormModuloVariables(pair.tail(), varmap) + " :: " +
									  printSortFormModuloVariables(pair.head(), varmap), new HashSet<String>());
			}
		}
		
		// assign to all function constructors the set of rules (by name) they come with
		for (Entry<String,GenericRule> e : rules.entrySet())
		{
			String rulename = e.getKey();
			GenericRule rule = e.getValue();
			Pair<Term,Term> declaration = rule.getConstructorDeclaration(rule.getPattern());
			Map<Variable,String> varmap = new HashMap<Variable,String>();
			String str = printSortFormModuloVariables(declaration.tail(), varmap);
			str += " :: " + printSortFormModuloVariables(declaration.head(), varmap);
			if (!ruleByConstructor.containsKey(str))
			{
				error("constructor in rule " + e.getKey() + " has declaration " + str +
					  " which is less general than the symbol's declaration.");
				continue;
			}
			ruleByConstructor.get(str).add(rulename);
		}
		
		// and finally, check completeness of all the relevant function constructors!
		for (Entry<String,Set<String>> e : ruleByConstructor.entrySet())
			checkCompleteness(e.getValue(), rules);
	}
	*/
	
	/**
	 * See whether all rules of the form F[l1,...,ln] -> r together are complete
	 * @param group a set of rule names having the same constructor (with the same sort/form)
	 * @param rules a set of rules, given by name, and with complete sort information
	 * @throws CRSExceotion error is called if the check fails
	 */
	private void checkCompleteness(Set<String> group, Map<String,GenericRule> rules) throws CRSException
	{
		// check 1: do we have left-linearity and fully extendedness? If not, don't even bother.
		for (String rulename : group)
		{
			Term term = rules.get(rulename).getPattern();
			if (!linear(term, new HashSet<Variable>(), new HashSet<Variable>(), new HashSet<String>()))
				error("rule " + rulename + " has a non-linear pattern.");
			if (!fullyExtended(term, new HashSet<Variable>()))
				error("rule " + rulename + " is not fully extended.");
		}
		
		// check 2: the real check: are the present patterns complete?
		// TODO
	}

	/**
	 * Test for linearity of the given meta-term.
	 * @param term a term to test
	 * @param bound the bound variables encountered in superterms (should be empty initially)
	 * @param varEncountered the free variables encountered before (should be empty initially)
	 * @param metavarEncountered the meta-variables encountered before (should be empty initially)
	 * @return
	 */
	private boolean linear(Term term, Set<Variable> bound, Set<Variable> varEncountered, Set<String> metavarEncountered)
	{
		if (term.kind() == Kind.VARIABLE_USE)
		{
			if (bound.contains(term.variable())) return true;
			if (varEncountered.contains(term.variable())) return false;
			varEncountered.add(term.variable());
			return true;
		}
		
		if (term.kind() == Kind.META_APPLICATION)
		{
			if (metavarEncountered.contains(term.metaVariable())) return false;
			metavarEncountered.add(term.metaVariable());
		}
		
		// term is a constructor or variable; we are interested in its subterms
		for (int i = 0; i < term.arity(); i++)
		{
			Variable[] binds = term.binders(i);
			for (int j = 0; j < binds.length; j++) bound.add(binds[j]);
			if (!linear(term.sub(i), bound, varEncountered, metavarEncountered)) return false;
			for (int j = 0; j < binds.length; j++) bound.remove(binds[j]);
		}
		
		return true;
	}

	/**
	 * Check whether the given term is fully extended, knowing that the binders
	 * in its context are all given in bound
	 * @param term a term to check
	 * @param bound the variables which are bound in the context of term;
	 * 	 initially, this should be an empty set
	 * @return
	 */
	private boolean fullyExtended(Term term, Set<Variable> bound)
	{
		for (int i = 0; i < term.arity(); i++)
		{
			for (int j = 0; j < term.binders(i).length; j++)
				bound.add(term.binders(i)[j]);
			if (!fullyExtended(term.sub(i), bound)) return false;
			for (int j = 0; j < term.binders(i).length; j++)
				bound.remove(term.binders(i)[j]);
		}
		if (term.kind() != Kind.META_APPLICATION) return true;
		Set<Variable> vars = new HashSet<Variable>();
		for (int i = 0; i < term.arity(); i++)
		{
			if (term.sub(i).kind() != Kind.VARIABLE_USE) return false;
			Variable x = term.sub(i).variable();
			if (!bound.contains(x)) return false;
			if (vars.contains(x)) return false;
			vars.add(x);
		}
		return vars.size() == bound.size();
	}
	
	/**
	 * This function takes care of the main testing whether a number of
	 * patterns together are complete.  "expectedSortSets" is a list of sort
	 * sets and expectedArgSorts a list of sorts.  Then "infos" is a set 
	 * containing a number of "info" triples, where an "info" consists of:
	 *   - a list of property sets of the same length as expectedSortSets,
	 *     such that each property set has the corresponding sort set
	 *   - a list of terms, of the same length as expectedArgSorts, such
	 *     that each term has the corresponding sort
	 *   - a list of variables which might occur as patterns anywhere (these
	 *     are originally bound variables); all info triples have a list of
	 *     the same length here
	 * @throws CRSException error() is used to indicate failure of completeness
	 */
	private void testFullness(Set<Pair<LinkedList<PropertiesHolder>,Pair<LinkedList<Term>,LinkedList<Variable[]>>>> infos,
							  LinkedList<PropertiesHolder> expectedSortSets,
							  LinkedList<Term> expectedArgSorts) throws CRSException
	{
		// TODO
	}
}
