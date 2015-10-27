/**
 * 
 */

package net.sf.crsx.generic;

import java.util.Set;

import net.sf.crsx.Contractum;
import net.sf.crsx.Sink;
import net.sf.crsx.Substitute;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.util.ExtensibleMap;

/**
 * Dummy Valuation for use during unification. Only use is to return null from getVariable.
 * 
 * @author jjohann
 *
 */
public class DummyValuation implements Valuation
{

	/* 
	 * Never used 	
	 */
	public Sink contract(Sink sink)
	{
		//Never used
		return null;
	}

	/* 
	 * Never used
	 */
	public Substitute getSubstitute(String metaVariable)
	{
		return null;
	}

	/* 
	 * Always returns null
	 */
	public Variable getVariable(Variable variable)
	{
		return null;
	}

	/* 
	 * Never used
	 */
	public boolean leave()
	{
		return false;
	}

	/* 
	 * Never used
	 */
	public String name()
	{
		return "";
	}

	public boolean spent(ExtensibleMap<Variable, Variable> renamings, ExtensibleMap<Variable, Contractum> substitution, ExtensibleMap<Variable, Variable> bound, Set<Variable> possible)
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public Sink staticContract(Sink sink)
	{
		// TODO Auto-generated method stub
		return null;
	}
}
