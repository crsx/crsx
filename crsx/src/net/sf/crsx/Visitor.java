/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx;

import java.util.Set;

/**
 * Base class for using {@link Term#visit(Visitor, net.sf.crsx.util.ExtensibleSet)}.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public abstract class Visitor
{
    /**
     * Visit meta-application (start and end).
     * @param metaApplication that is being visited
     * @param start true for invocation before subterms, false after
     * @param bound variables in the context of the meta-application (can be unmodifyable)
     * @throws CRSException to report errors
     */
    public void visitMetaApplication(Term metaApplication, boolean start, Set<Variable> bound) throws CRSException
    {}

    /**
     * Visit meta-application argument subterm (start and end).
     * @param metaApplication that is being visited
     * @param index of subterm
     * @param start true for invocation before the subterm, false after
     * @param bound variables in the context of the meta-application (can be unmodifyable)
     * @throws CRSException to report errors
     */
    public void visitMetaApplicationSub(Term metaApplication, int index, boolean start, Set<Variable> bound) throws CRSException
    {}

    /**
     * Visit construction.
     * @param construction that is being visited
     * @param start true for invocation before subterms, false after
     * @param bound variables in the context of the meta-application (can be unmodifyable)
     * @throws CRSException to report errors
     */
    public void visitConstruction(Term construction, boolean start, Set<Variable> bound) throws CRSException
    {}

    /**
     * Visit constructor.
     * @param constructor that is being visited
     * @param start true for invocation before the subterm, false after
     * @param bound variables in the context of the meta-application (can be unmodifyable)
     * @throws CRSException to report errors
     */
    public void visitConstructor(Constructor constructor, boolean start, Set<Variable> bound) throws CRSException
    {}

    /**
     * Visit construction.
     * @param construction that is being visited
     * @param index of subterm
     * @param start true for invocation before the subterm, false after
     * @param bound variables in the context of the meta-application (can be unmodifyable)
     * @throws CRSException to report errors
     */
    public void visitConstructionSub(Term construction, int index, boolean start, Set<Variable> bound) throws CRSException
    {}

    /**
     * Visit (variable) use.
     * @param use that is being visited
     * @param start true for invocation before variable visit, false after
     * @param bound variables in the context of the meta-application (can be unmodifyable)
     * @throws CRSException to report errors
     */
    public void visitUse(Term use, boolean start, Set<Variable> bound) throws CRSException
    {}
    
    /**
     * Visit free variable.
     * @param free variable that is visited
     * @param updater to replace the variable, if needed
     * @throws CRSException to report errors
     */
    public void visitFree(Variable free, VariableUpdater updater) throws CRSException
    {}
    
    /**
     * Visit bound variable.
     * @param bound variable that is visited
     * @param updater to replace the variable, if needed
     * @throws CRSException to report errors
     */
    public void visitBound(Variable bound, VariableUpdater updater) throws CRSException
    {}
    
    /**
     * Visit term properties. 
     * @param start true for invocation before the properties, false after
     * @throws CRSException to report errors
     */
    public void visitProperties(boolean start) throws CRSException
    {}
    
    /**
     * Visit named property. 
     * @param name property name
     * @param start true for invocation before the value of the named property, false after
     * @throws CRSException to report errors
     */
    public void visitNamedProperty(String name, boolean start) throws CRSException
    {}
    
    /**
     * Visit variable property.  
     * @param property TODO
     * @param start true for invocation before the variable and the value of the variable property, false after
     * @param hasMapping true when the variable should map to a value. The value (if any) is visited after this event.
     * @throws CRSException to report errors
     */
    public void visitVariableProperty(Variable property, boolean start, boolean hasMapping) throws CRSException
    {}
    
    /**
     * Visit meta property.  
     * @param name property metaVariable name
     * @param start true for invocation before the value of the meta property, false after
     * @param hasMapping true when the meta variable should map to a value. The value (if any) is visited after this event.
     * @throws CRSException to report errors
     */
    public void visitMetaProperty(String name, boolean start, boolean hasMapping) throws CRSException
    {}

    /**
     * Visit properties reference.  
     * @param name property reference (metaVariable) name
     * @param start true for invocation before the value of the meta property, false after
     * @throws CRSException to report errors
     */
    public void visitPropertiesRef(String name, boolean start) throws CRSException
    {}
    
    /**
     * Invoked before/after entering/leaving a primitive $[...] construct. 
     * @param start whether we are entering
     * @throws CRSException to report errors
     */
    public void visitPrimitive(Primitive primitive, boolean start) throws CRSException
    {}

    /**
     * Invoked before/after entering/leaving a subterm of a primitive that contains "normal" stuff.
     * @param start whether we are entering
     * @throws CRSException to report errors
     */
    public void visitPrimitiveNormal(Primitive primitive, boolean start) throws CRSException
    {}
    
    /**
     * Helper interface to permit updating the variable.
     * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
     */
    public interface VariableUpdater
    {
        /** Update variable. */
        void setVariable(Variable variable);
    }
}