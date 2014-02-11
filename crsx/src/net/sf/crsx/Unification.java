package net.sf.crsx;

/**
 * Unification in progress. Maps metavariables to substitutes and free variables to fresh variables. 
 * Maintains a map from metavariables to substitutes (can be used for both patterns, since we assume 
 * uniqueness of metavariable names, and a map from free variables to variable names (again, we assume
 * uniqueness, and hence one map suffices).  
 * 
 * The variable associations work as the transitive closure of all added associations.
 * 
 * @author Jacob Johannsen (jjohann@us.ibm.com)
 *
 */
public interface Unification {

	/**
	 * Get the substitute associated to a metavariable from the first map
	 * @param metavar the metavariable
	 * @return the associated substitute
	 */
	Substitute getSubstitute(String metavar);
	
	/**
	 * Get the variable that is transitively associated to a variable in the first map, 
	 * i.e., getVariable(x) will return z if x is associated to y and y is associated to z.
	 * 
	 * @param var the variable to be looked up
	 * @return the associated variable
	 */
	Variable getVariable(Variable var);
	
	/**
	 * Add an association between a metavariable and a substitute in the first map.
	 * 
	 * If an association already exists for that metavariable, the old association is overwritten.
	 * 
	 * @param metavar the metavariable
	 * @param binders the binders of the substitute
	 * @param body the body of the substitute
	 */
	void putSubstitute(String metavar, Variable[] binders, Term body);
	
	/**
	 * Add an association between two variables in the first map. If an association from the first variable already
	 * exists, it is overwritten.
	 * 
	 *  As associations are transitive, any previous associations to var will now associate to var2 instead.
	 *  Similarly, any previous association from var2 to var3 will cause var to be associated to var3 instead.
	 *  
	 *  In case the added association causes an association loop, the subsequent behaviour of the Unification 
	 *  object is undefined.     
	 *  
	 * @param var
	 * @param var2
	 */
	void putVariable(Variable var, Variable var2);
	
	/**
	 * Generate the most general unifier corresponding to this unification
	 * @return the MGU
	 */
	Pattern getMGU();
	
}
