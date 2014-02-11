/* Copyright © 2009 IBM Corporation. */

package net.sf.crsx.generator;

import net.sf.crsx.CRSException;
import net.sf.crsx.generic.GenericRule;

/**
 * High-level code generator
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public interface Generator
{

    void end();

    void generateRule(GenericRule rule) throws CRSException;
}
