/* Copyright (c) 2008 IBM Corporation. */

package net.sf.crsx.pg;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

import net.sf.crsx.util.Pair;
import net.sf.crsx.util.Util;

/**
 * Helper to construct "reverser" rewrite system that converts term to 
 * an expression that constructs the string that parsed to it. 
 * 
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
class Reverser
{
    // Static.
    
    /** Derivor function used by serializer...should not clash with constructor! */
    final private static String SERIALIZE = "$S$"; 

    /** Quote string. */
    static String q(String s)
    {
        return Util.quoteJava(s);
    }

    // State.

    /**
     * List of rule fragments.
     * Each rule fragment is a pair of
     * <ul>
     * <li>a list of subterms (strings) and
     * <li>a result text construction term (string).
     * </ul>
     */
    private List<Pair<List<String>, String>> rules;

    /** Counter for meta-variables. */
    private int metaCount;

    // Constructor.

    /**
     * Construct empty reverser.
     * Initially the reverser contains a single rule mapping the empty term sequence to the empty text.
     */
    public Reverser()
    {
        this(new LinkedList<String>(), "");
    }

    /**
     * Construct reverser with one rule fragment.
     * @param terms fragment to rewrite
     * @param text fragment to generate
     */
    public Reverser(List<String> terms, String text)
    {
        rules = new LinkedList<Pair<List<String>, String>>();
        rules.add(new Pair<List<String>, String>(terms, text));
    }

    /**
     * Construct reverser with fresh rules.
     * @param rules to use (not cloned or copied)
     */
    public Reverser(List<Pair<List<String>, String>> rules, int metaCount)
    {
        this.rules = rules;
        this.metaCount = metaCount;
    }

    // Helpers.

    public String toString()
    {
        StringBuffer b = new StringBuffer();
        for (Pair<List<String>, String> rule : rules)
            b.append("\t" + rule.head() + " &rarr; " + rule.tail() + " ;\n");
        return b.toString();
    }

    // Methods.

    /** Return safe meta-variable count for this reverser. */
    int metacount()
    {
        return ++metaCount;
    }

    // Constructing new reversers.

    /** Create new reverser with all possible concatenations of this and that reverser (in order). */
    Reverser concatenate(Reverser that)
    {
        List<Pair<List<String>, String>> combinedRules = new LinkedList<Pair<List<String>, String>>();
        for (Pair<List<String>, String> rule1 : rules)
            for (Pair<List<String>, String> rule2 : that.rules)
            {
                List<String> combinedTerms = new LinkedList<String>();
                combinedTerms.addAll(rule1.head());
                combinedTerms.addAll(rule2.head());
                combinedRules.add(new Pair<List<String>, String>(combinedTerms, rule1.tail() + rule2.tail()));
            }
        return new Reverser(combinedRules, (metaCount > that.metaCount ? metaCount : that.metaCount));
    }

    /** Create new reverser with the union of this and that reverser. */
    Reverser union(Reverser that)
    {
        List<Pair<List<String>, String>> combinedRules = new LinkedList<Pair<List<String>, String>>();
        combinedRules.addAll(rules);
        combinedRules.addAll(that.rules);
        return new Reverser(combinedRules, (metaCount > that.metaCount ? metaCount : that.metaCount));
    }

    /**
     * Create new reverser where all rules prepend a prefix to the matched terms and result term.
     * @param termPrefix to add as new first parameter, or null if none
     * @param resultPrefix expression to prepend to result of all rules, or null if none
     */
    Reverser prepend(String termPrefix, String resultPrefix)
    {
        List<Pair<List<String>, String>> newRules = new LinkedList<Pair<List<String>, String>>();
        for (Pair<List<String>, String> rule : rules)
        {
            List<String> newTerms;
            if (termPrefix == null)
                newTerms = rule.head();
            else
            {
                newTerms = new LinkedList<String>();
                newTerms.add(termPrefix);
                newTerms.addAll(rule.head());
            }

            newRules.add(new Pair<List<String>, String>(newTerms, resultPrefix + rule.tail()));
        }
        return new Reverser(newRules, metaCount);
    }

    /**
     * Create new reverser where all rules have a singleton matching construction with the old fragments as parameters.
     * @param wrapperStart text (as used in term), including the constructor/meta-variable and leading "["
     * @param wrapperComma text to separate subterms, usually just ","
     * @param wrapperEnd text (as used in term), usually just "]"
     * @param resultPrefix expression to prepend to result of all rules, or null if none
     */
    Reverser prependWrap(String wrapperStart, String wrapperSeparator, String wrapperEnd, String resultPrefix)
    {
        List<Pair<List<String>, String>> newRules = new LinkedList<Pair<List<String>, String>>();
        for (Pair<List<String>, String> rule : rules)
        {
            // W[ t1 , ... , tn ]
            StringBuffer b = new StringBuffer();
            b.append(wrapperStart); // W[
            boolean following = false;
            for (String term : rule.head())
            {
                if (following)
                    b.append(wrapperSeparator); // ,
                else
                    following = true;
                b.append(term); // ti
            }
            b.append(wrapperEnd); // ]

            List<String> newTerms = new LinkedList<String>();
            newTerms.add(b.toString());

            newRules.add(new Pair<List<String>, String>(newTerms, resultPrefix + rule.tail()));
        }
        return new Reverser(newRules, metaCount);
    }

    /**
     * Used to generate 
     * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
     */
    abstract static class Builder
    {
        /**
         * Create frsh reverser that extends the passed reverser to include the effect of this leading component.
         * @param following reverser for following components
         */
        abstract Reverser prependTo(Reverser following);

        /** Return a fresh reverser builder that has the effect of the union of this and that. */
        Builder choice(final Builder that)
        {
            final Builder self = this;
            return new Builder()
                {
                    @Override
                    Reverser prependTo(Reverser following)
                    {
                        return self.prependTo(following).union(that.prependTo(following));
                    }
                };
        }
        
        /** Return a fresh reverser builder that has the effect of the concatenation of this and that. */
        Builder concatenate(final Builder that)
        {
            final Builder self = this;
            return new Builder()
                {
                    @Override
                    Reverser prependTo(Reverser following)
                    {
                        return self.prependTo(that.prependTo(following));
                    }
                };
        }
        
        void appendRulesTo(Appendable w, String name) throws IOException
        {
            int count = 0;
            Reverser rev = prependTo(new Reverser());
            for (Pair<List<String>, String> rule : rev.rules)
            {
                String lhs = SERIALIZE + rule.head();
                if (! (lhs + "; ").equals(rule.tail()))
                {
                    String rhs = "( " + rule.tail() + ")";
                    w.append("\t" + name + "-" + (++count) + " : " + lhs + " &rarr; " + rhs + " ;\n");
                }
            }
        }
    }

    /** Dummy. */
    static Builder dummy()
    {
        return new Builder()
            {
                @Override
                Reverser prependTo(Reverser following)
                {
                    return following;
                }
            };
    }
    
    // Handlers for JJCRS concatenation prefixes.

    /**
     * Handle prefix literal.
     * @param literal text (assumed quoted)
     * @param use of the text in the term
     */
    static Builder literal(final String literal, final Usage use)
    {
        return new Builder()
            {
                @Override
                Reverser prependTo(Reverser following)
                {
                    if (!use.touched)
                    {
                        // "literal" ...
                        return following.prepend(null, "Q[" + literal + "]; ");
                    }
                    else if (use.wasConverted)
                    {
                        // "literal":... ...
                        throw new UnsupportedOperationException("Cannot reverse converted literal form (" + literal + ").");
                    }
                    else if (use.construct)
                    {
                        // "literal"$ ...
                        return following.prependWrap(literal + "[", ",", "]", "Q[" + literal + "]; ");
                    }
                    else
                    {
                        throw new UnsupportedOperationException("Cannot reverse used literal form (" + literal + ").");
                    }
                }
            };
    }

    /**
     * Handle inline prefix.
     * @param inline text (assumed quoted)
     * @param use of the prefix
     */
    static Builder inline(final String inline, final Usage use)
    {
        return new Builder()
            {
                @Override
                Reverser prependTo(Reverser following)
                {
                    if (!use.touched)
                    {
                        // {inline} ...
                        return following.prependWrap(inline + "[", ",", "]", "");
                    }
                    else if (use.wasConverted)
                    {
                        throw new UnsupportedOperationException("Cannot reverse converted inline form ({" + inline + "}).");
                    }
                    else if (use.construct)
                    {
                        // {inline}$ ...
                        return following.prependWrap(inline + "[", ",", "]", "");
                    }
                    else
                    {
                        throw new UnsupportedOperationException("Cannot reverse used inline form ({" + inline + "}).");
                    }
                }
            };
    }

    /**
     * Handle terminal.
     * @param terminal name
     * @param use of the terminal
     */
    static Builder terminal(final String terminal, final Usage use)
    {
        return new Builder()
            {
                @Override
                Reverser prependTo(Reverser following)
                {
                    if (!use.touched)
                    {
                        // <terminal> ...
                        return following.prepend(null, "T[" + q(terminal) + "]; "); // T[t] should rewrite to terminal text
                    }
                    else if (use.construct)
                    {
                        if (use.buffer)
                        {
                            // <terminal>#... ...
                            return following.prepend(null, use.name + "; "); // just reuse the meta-variable?
                        }
                        else
                        {
                            // <terminal>$ ...
                            String metavar = "#" + following.metacount() + "-" + terminal; 
                            return following.prependWrap("$[C," + metavar + ", (", ";", ";)]", "Q[" + metavar + "]; ");
                        }
                    }
                    else if (use.definition)
                    {
                        // <terminal>^x Rest
                        return following.prepend(null, use.name + "; "); // x in result
                    }
                    else if (use.use)
                    {
                        // <terminal>! Rest
                        String var = "v-" + terminal + "-" + following.metacount();
                        return following.prepend(var, var + "; ");
                    }
                    else if (use.meta)
                    {
                        if (use.wasConverted)
                        {
                            // <terminal>#@ ...
                            return following.prepend(null, use.name + "; "); // just reuse the meta-variable?
                        }
                        else
                        {
                            // <terminal>@ ...
                            String metavar = "#" + following.metacount() + "-" + terminal; 
                            return following.prependWrap("$[M," + metavar + ", (", ";", ";)]", "Q[" + metavar + "]; ");
                        }
                    }
                    else
                    {
                        throw new UnsupportedOperationException("Cannot reverse used terminal form (" + terminal + ").");
                    }
                }
            };
    }

    /** Handle nonterminal. */
    static Builder nonterminal(final String nonterminal, final List<String> vs, final Usage use)
    {
        return new Builder()
            {
                @Override
                Reverser prependTo(Reverser following)
                {
                    String binderPrefix, term;
                    if (vs == null || vs.size() == 0)
                    {
                        binderPrefix = "";
                        term = use.name;
                    }
                    else
                    {
                        binderPrefix = vs.get(0);
                        for (int i = 1; i < vs.size(); ++i) binderPrefix = binderPrefix + " " + vs.get(i);
                        binderPrefix = binderPrefix + ".b";
                        term = use.name + vs;
                    }
                    if (use.buffer)
                    {
                        // Nonterminal ...
                        return following.prepend(null, SERIALIZE+"["+term+"]; ");
                    }
                    else
                    {
                        // Nonterminal ...
                        String metaapplication = "#"+following.metacount()+"-"+term;
                        return following.prepend(binderPrefix+metaapplication, SERIALIZE+"["+metaapplication+"]; ");
                    }
                }
            };
    }

    /** Handle generated term. */
    static Builder generation(final String term)
    {
        return new Builder()
            {
                @Override
                Reverser prependTo(Reverser following)
                {
                    // {{ t }} ...
                    return following.prepend(term, "");
                }
            };
    }
}
