/* Copyright © 2008 IBM Corporation. */

package net.sf.crsx.util;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Variable;

/**
 * Dummy sink that ignores all operations.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
public class DummySink extends DelegateMaker implements Sink
{
    // State.
    
    /** Maker for term fragment construction. */
    final private Maker maker;
    
    // Constructor.
    
    /** Create dummy sink. */
    public DummySink(Maker maker)
    {
        this.maker = maker;
    }

    // DelegateMaker...
    
    @Override
    final public Maker maker()
    {
	    return maker;
    }

    // Sink...
    
    public Sink binds(Variable[] binders)
    {
        return this;
    }

    public Sink copy(Copyable source, boolean discard)
    {
        return this;
    }

    public Sink end()
    {
        return this;
    }

    public Sink endMetaApplication()
    {
        return this;
    }

    public Sink start(Constructor constructor)
    {
        return this;
    }

    public Sink startMetaApplication(String name)
    {
        return this;
    }

    public Sink use(Variable variable)
    {
        return this;
    }
}
