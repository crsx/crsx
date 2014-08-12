/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

/**
 * Optional properties as held by {@link Constructor} and related players.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 * @version $Id: PropertiesHolder.java,v 3.0 2012/12/17 18:04:47 krisrose Exp $
 */
public interface PropertiesHolder
{
    /** The property names for which {@link #getProperty(String)} returns a term. */
    public Iterable<String> propertyNames();
    
    /** Extract a named property, or null if there is no such property. */
    public Term getProperty(String name);

    /** The property variables for which {@link #getProperty(Variable)} returns a term. */
    public Iterable<Variable> propertyVariables();
    
    /** Extract a variable property, or null if there is no such property. */
    public Term getProperty(Variable variable);
    
    /** Whether named property can be set. */
    public boolean canSetProperty(String name);
    
    /** Whether variable property can be set. */
    public boolean canSetProperty(Variable variable);
    
    /**
     * Set name property (only defined if {@link #canSetProperty(String)}).
     * @param name property to set
     * @param value of property or null to unset
     * @throws CRSException if property cannot be set or unset or the property format is not respected
     */
    public void setProperty(String name, Term value) throws CRSException;
    
    /**
     * Set variable property (only defined if {@link #canSetProperty(Variable)}.
     * @param variable property to set
     * @param value of property or null to unset
     * @throws CRSException if property cannot be set or unset or the property format is not respected
     */
    public void setProperty(Variable variable, Term value) throws CRSException;
    
    /**
     * Remove variable property
     * @param variable
     * @throws CRSException
     */
    public void removeProperty(Variable variable) throws CRSException;
    
        /**
     * Add all the properties at once.
     * @throws CRSException if a property cannot be set
     */
    public void setProperties(PropertiesHolder properties) throws CRSException;
    
    /** Whether this properties holder has negated or meta properties (not otherwise supported by the interface). */
    public boolean isMeta();
}
