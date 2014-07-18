/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Somewhat generic code template
 * For now support only parameters of the form /*[PARAMNAME[*'/' ... /*]]*'/'
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class CodeTemplate
{

    /** 
     * Load code template stored in the given file 
     * @return a code template or null if an error occurs
     */
    final public static CodeTemplate load(File file)
    {
        byte[] bytes = new byte[(int) file.length()];
        try
        {
            FileInputStream fis = new FileInputStream(file);
            fis.read(bytes);
            fis.close();
             
            return new CodeTemplate(file.getName(), new String(bytes));

        }
        catch (FileNotFoundException e)
        {
            // TODO: log
        }
        catch (IOException e)
        {

            e.printStackTrace();
            // TODO: log
        }
        return null;
    }

    /** Parameter match pattern */
    final private static Pattern PARAM_PATTERN = Pattern.compile("/\\*\\s*\\[([^\\[]*)\\[\\s*\\*/([^/]*)/\\*\\s*\\]\\]\\s*\\*/");

    // State

    /** Code text */
    final protected String text;

    /** Template name */
    final protected String name;

    /** Ordered list of replaceable substring. (start, end, parameter name)* */
    final protected Object[] parameters;

    // Constructor

    private CodeTemplate(String name, String text)
    {
        this.text = text;
        this.name = name;

        ArrayList<Object> paramList = new ArrayList<Object>();
        Matcher matcher = PARAM_PATTERN.matcher(text);
        while (matcher.find())
        {
            paramList.add(matcher.start(2));
            paramList.add(matcher.end(2));
            paramList.add(matcher.group(1));
        }
        this.parameters = paramList.toArray();
    }

    // Methods

    /** Name of the template */
    public String getName()
    {
        return name;
    }

    public Code instantiate()
    {
        return new Code(this);
    }

    public CharSequence mergeParamValues(Map<String, String> values)
    {
        StringBuilder builder = new StringBuilder(text);

        int offset = 0; // real position offset as text gets shifted around
        for (int i = 0; i < parameters.length; i += 3)
        {
            String value = values.get(parameters[i + 2]);
            if (value != null)
            {
                final int start = (Integer) parameters[i];
                final int end = (Integer) parameters[i + 1];
                builder.replace(start + offset, end + offset, value);
                offset += value.length() - (end - start);
            }
        }

        return builder;
    }
}
