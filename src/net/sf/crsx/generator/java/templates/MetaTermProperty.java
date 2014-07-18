/* Copyright © 2009 IBM Corporation. */
package /*[PACKAGE[*/net.sf.crsx.generator.java.templates /*]]*/;


/**
 * Property of the form #Meta: (<pattern> || <contractum>)
 * 
 * @author  <a href="mailto:villard@us.ibm.com">Lionel Villard</a>
 */
public class MetaTermProperty extends PropertyConstraint
{
    // State

    /** #Meta position in {@link MatchingContext} */
    final protected int metaPosition;

    /** Pattern to match or contractum*/
    final protected Term patternOrContractum;

    // Constructors

    MetaTermProperty(int metaPosition, Term patternOrContractum)
    {
        this.metaPosition = metaPosition;
        this.patternOrContractum = patternOrContractum;
    }

    // Overrides

    /**
     * 
     */
    @Override
    public boolean match(Properties properties, MatchingContext context)
    {
//        final Term key = context.getSubstitute(metaPosition);
//        if (Utils.isConstant(key))
//        {
//            final Term term = GeneratedCRSX.namedProps.get(key.getSymbol());
//            return term != null && patternOrContractum.match(term, context);
//        }
//        return false;
    	throw new UnsupportedOperationException();
    }

    @Override
    public void contract(Properties properties, MatchingContext context)
    {
//        final Term key = context.getSubstitute(metaPosition);
//        if (Utils.isConstant(key))
//            GeneratedCRSX.namedProps.put(key.getSymbol(), patternOrContractum.contract(context));

    	throw new UnsupportedOperationException();
    }

}
