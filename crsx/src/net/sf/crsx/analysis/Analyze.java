/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx.analysis;

import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.Builder;
import net.sf.crsx.CRSException;
import net.sf.crsx.Kind;
import net.sf.crsx.Path;
import net.sf.crsx.Term;
import net.sf.crsx.util.Util;

/**
 * Collection of analysis functions for CRS {@link Builder}.
 */
public class Analyze
{
    // Static.
    
    /** Possible roles for symbols. */
    public static enum SymbolRole {
        /** A function symbol only occurs at the outermost construction of patterns. */
        FUNCTION,
        /** A data symbol never occurs at the outermost construction of patterns. */
        DATA,
        /** Symbol known to occur in both outermost and inner locations of patterns. */
        IMPURE
    };

    // State.

    /** CRS under investigation.*/
    final Builder crs;

    /** Identify each symbol as function, data, neither, or unmatched (null). */
    private Map<String, SymbolRole> symbolRoles = new HashMap<String, SymbolRole>();

    // Constructor.

    /**
     * Create analysis.
     * @param crs to investigate.
     */
    public Analyze(Builder crs)
    {
        this.crs = crs;
    }
    
    // Methods.

    /**
     * Return the role of the constructor symbol in the CRS.
     * @param symbol to check
     * @return {@link SymbolRole#FUNCTION} if purely used as function, {@link SymbolRole#DATA} if used as data, 
     *      {@link SymbolRole#IMPURE} if used as both, and null if unused in 
     */
    public SymbolRole symbolRole(String symbol)
    {
        return symbolRoles().get(symbol);
    }

    /**
     * Return map from constructor symbols to all subterms of rule patterns that are constructions with that symbol.
     * Specifically, the returned map maps symbol names to lists of "rule pattern subterm" descriptions
     * in the form of a pair of a rule name and subterm path.
     */
    private Map<String, SymbolRole> symbolRoles()
    {
        if (symbolRoles == null)
        {
            symbolRoles = new HashMap<String, SymbolRole>();
            for (String name : crs.ruleNames())
                symbolRoleSubs(crs.rulePattern(name), Path.EMPTY);
        }
        return symbolRoles;
    }

    /** Helper for {@link #symbolRoles()}. */
    private void symbolRoleSubs(Term pattern, Path path)
    {
        Term term = path.of(pattern);
        if (term.kind() == Kind.CONSTRUCTION)
        {
            String symbol = Util.symbol(pattern);
            SymbolRole role = symbolRoles.get(symbol);
            if (role == null)
                // First encounter...symbol is candidate...
                symbolRoles.put(symbol, (path.isEmpty() ? SymbolRole.FUNCTION : SymbolRole.DATA));
            else
                switch (role)
                {
                    case FUNCTION :
                        if (!path.isEmpty())
                            symbolRoles.put(symbol, SymbolRole.IMPURE);
                        break;
                    case DATA :
                        if (path.isEmpty())
                            symbolRoles.put(symbol, SymbolRole.IMPURE);
                        break;
                    case IMPURE :
                        break;
                }
            // Recurse.
            for (Path subPath : term.paths(path))
                symbolRoleSubs(pattern, subPath);
        }
    }

    /**
     * Check that rule set constitutes a <em>derivor</em>:
     * symbols that can be implemented as compositional recursive equations.
     * @throws CRSException if the system is not a derivor
     */
    public void derivorCheck() throws CRSException
    {
        for (String rule : crs.ruleNames())
            derivorCheck(rule, crs.ruleContractum(rule));
    }
    /** Recursive helper for {@link #derivorCheck()}. */
    private void derivorCheck(String rule, Term term) throws CRSException
    {
        switch (term.kind())
        {
            case CONSTRUCTION : {
                // Construction...must be either a recursively checked data constructor or a derivor call.
                String symbol = Util.symbol(term);
                SymbolRole role = symbolRole(symbol);
                if (role != null)
                {
                    switch (role)
                    {
                        case DATA :
                            break; // continue to recursive check of arguments
                        case FUNCTION :
                            return;
                        case IMPURE :
                            throw new CRSException("DerivorCheck failed: rule "
                                    + rule + " contains non-function symbol in function position.");
                    }
                }
                break;
            }

            case META_APPLICATION : {
                // Meta-application...recurse.
                break;
            }

            case VARIABLE_USE : {
                // Variable occurrence...alright.
                break;
            }
        }
        // Symbol does not occur in pattern function position...so check recursively.
        for (Path p : term.paths(Path.EMPTY))
            derivorCheck(rule, p.of(term));
    }
    
}
