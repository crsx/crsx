
package net.sf.crsx.compiler.java;

/**
 * Base class for referenceable object.
 * 
 * @author <a href="researcher.watson.ibm.com/researcher/view.php?person=us-villard">Lionel Villard</a>.
 */
public abstract class Referenceable
{
	// Static helpers
	
	final public static Referenceable LINK(Referenceable ref)
	{
		ref.link();		
		return ref;
	}

	final public static Term LINK(Term ref)
	{
		ref.link();		
		return ref;
	}
	
	final public static NamedPropertyLink LINK(NamedPropertyLink ref)
	{
		if (ref != null)
			ref.link();		
		return ref;
	}
	
	final public static VariablePropertyLink LINK(VariablePropertyLink ref)
	{
		if (ref != null)
			ref.link();	
		return ref;
	}

	final public static Referenceable LINK_LINK(Referenceable ref)
	{
		if (ref != null)
			ref.link();
		return ref;
	}

	final public static NamedPropertyLink LINK_LINK(NamedPropertyLink ref)
	{
		if (ref != null)
			ref.link();
		return ref;
	}

	final public static VariablePropertyLink LINK_LINK(VariablePropertyLink ref)
	{
		if (ref != null)
			ref.link();
		return ref;
	}
	
	final public static int LINK_COUNT(Referenceable ref)
	{
		assert ref.nr > 0;
		
		return ref.nr;
	}

	final public static void UNLINK(Referenceable ref)
	{
		if (ref != null)
			ref.unlink();		
	}
	
	final public static void UNLINK_LINK(Referenceable ref)
	{
		if (ref != null)
			ref.unlink();		
	}

	// State
	
	/** Reference count */
	public int nr;
	
	// Methods
	
	final public void link()
	{
		nr++;
	}
	
	protected abstract void unlink();

}
