/* Copyright © 2009 IBM Corporation. */

package /* [PACKAGE[ */net.sf.crsx.generator.java.templates /*]]*/;

import java.util.HashMap;

/**
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class ToSink extends NativeSink
{

    private net.sf.crsx.Sink sink;

    HashMap<Variable, net.sf.crsx.Variable> vars = new HashMap<Variable, net.sf.crsx.Variable>();

    public ToSink(net.sf.crsx.Sink sink)
    {
        this.sink = sink;
    }

    @Override
    public void end(int id)
    {
        this.sink = this.sink.end();
    }

    @Override
    public void start(int id)
    {
        final String name = Dictionary.SINGLETON.getName(id);

        this.sink = sink.start(sink.makeConstructor(name));
    }

    @Override
    public void binds(Variable[] binders)
    {
        net.sf.crsx.Variable[] ext = new net.sf.crsx.Variable[binders.length];
        for (int i = 0; i < binders.length; i++)
        {
            net.sf.crsx.Variable v = vars.get(binders[i]);
            if (v == null)
            {
                v = sink.makeVariable(binders[i].name, true);
                vars.put(binders[i], v);
            }
            ext[i] = v; 
        }
        this.sink = this.sink.binds(ext);
    }

    @Override
    public void use(Variable var)
    {
        net.sf.crsx.Variable ext = vars.get(var);
        if (ext == null)
            sink = sink.use(sink.makeVariable(var.name, true));
        else
            sink = sink.use(ext);
    }

}
