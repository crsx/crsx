/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * Code Template instantiation
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class Code
{ 
    // State

    /** Original template */
    final protected CodeTemplate template;

    /** Parameter value */
    final protected Map<String, String> values;

    // Constructors

    Code(CodeTemplate template)
    {
        this.template = template;
        values = new HashMap<String, String>();
    }

    // Methods 
    
    /** Sets parameter value */
    public void setParameter(String name, String value)
    {
        values.put(name, value);
    }

    /** Write the code to the output */
    public void write(File dest)
    {
        try
        { 
            dest.createNewFile();
            FileWriter writer = new FileWriter(dest);
             
            writer.write(template.mergeParamValues(values).toString());
            writer.close();
        }
        catch (IOException e)
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
