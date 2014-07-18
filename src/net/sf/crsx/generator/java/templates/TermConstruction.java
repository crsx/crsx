/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;


/**
 * Construction that occurs only in terms
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public abstract class TermConstruction extends Construction
{
    // State

    /** Variable bindings for each arguments. */
    final protected Variable[][] subbinders;
    
    /** Construction unique ID */
    final protected int id;
    
    /** Term properties */
    protected Properties properties;

    // Constructors

    protected TermConstruction(int id, Properties properties, Variable[][] subbinders, Term... args)
    {
        super(args);

        this.subbinders = subbinders;
        this.id = id;
        this.properties = properties;
    }

    // Overrides

    @Override
    final public Variable[][] getBinders()
    {
        return subbinders;
    }
    
    /** Gets contruction unique ID */
    final protected int getID()
    {
        return id;
    }
    
    @Override
    final public String getSymbol()
    {
        return Dictionary.SINGLETON.getName(id);
    }


    @Override
	public Properties getProperties()
	{
		return properties;
	}

	@Override
	public void setProperties(Properties properties)
	{
		this.properties = properties;
	}

	@Override
    public boolean match(Term term, MatchingContext context)
    {
        throw new AssertionError("Not a pattern");
    }
    
    @Override
    public Term contract(MatchingContext context)
    {
        throw new AssertionError("Not a contractum");
    }


}
