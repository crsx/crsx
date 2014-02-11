/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates/*]]*/;

import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.Sink;

/**
 * Template for generated CRS.
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
@SuppressWarnings("unused")
public class GeneratedCRSX
{
    // Static

    /** Rewriting rules */
    final static private Rule[] rules;

    /** Dispatch rules */
    final static private Rule[][] dispatchRules;
  
    /** Global environment */
    final static public Map<String, String> env;

    // Static initializer

    static
    { 
        env = new HashMap<String, String>();

        rules = new Rule[/*[TERMCOUNT[*/0/*]]*/];
        dispatchRules = new Rule[/*[TERMCOUNT[*/0/*]]*/][];

        /*[STATICINIT[*//*]]*/
    }
     
    /*[RULES[*//*]]*/
    
    // Static methods

	private static void addRule(int id, Term pattern, Term contractum)
    {
        rules[id] = new Rule(pattern, contractum);
    }

	private static void addDispatchRules(int id, Rule[] rules)
    {
        dispatchRules[id] = rules;
    }
	
	private static Rule createRule(Term pattern, Term contractum)
    {
        return new Rule(pattern, contractum);
    }


    /** 
     * Dispatch the given term.  
     * @param contractum
     * @return
     */
    public static Term dispatch(Term term)
    {
        if (term instanceof FunctionConstruction)
        {
            final FunctionConstruction cons = (FunctionConstruction) term;
            if (cons.id != -1 && dispatchRules.length > cons.id && dispatchRules[cons.id] != null)
            {
                final Rule[] rule = dispatchRules[cons.id];

                for (int i = 0; i < rule.length; i++)
                {
                    MatchingContext context = new MatchingContext();
                    if (rule[i].getPattern().match(term, context))
                        return rule[i].getContractum().contract(context);
                }
            }
        }

        return term;
    }

    // Constructors

    public GeneratedCRSX()
    {}

    // Methods 

    /* [NORMALIZESINK[ */
    public void normalize(Sink sink, net.sf.crsx.Term term)
    {
        FromSink in = new FromSink(term.maker());
        in.copy(term, true);
        in.getTerm().normalize(rules, new ToSink(sink));
    }
    /*]]*/
    
    public void normalize(Term term, NativeSink sink)
    {
        term.normalize(rules, sink);
    }

}
