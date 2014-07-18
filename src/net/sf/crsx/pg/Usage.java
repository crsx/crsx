/* Copyright (c) 2007,2008 IBM Corporation. */

package net.sf.crsx.pg;

/**
 * Helper structure to capture usage configuration.
 * @author <a href="mailto:krisrose@us.ibm.com">Kristoffer Rose</a>
 */
class Usage
{
    /** True when <em>any</em> usage markers were present. */
    boolean touched;

    boolean definition, buffer, use, construct, embedded, literal;
    
    boolean freeVar, freshVar, meta, wasConverted, needst, linear;
    String name, converted, category;
    Usage(String n, String c) {name = n; converted = c;}
}
