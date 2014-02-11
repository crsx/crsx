package net.sf.crsx.util;

import java.util.Map;

import net.sf.crsx.Constructor;
import net.sf.crsx.Copyable;
import net.sf.crsx.Maker;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;

/**
 * Consume term that encodes Sink operations, decoding to create the actual term.
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: UnmetaSink.java,v 3.0 2012/12/17 18:04:59 krisrose Exp $
 */
public class UnmetaSink extends DelegateMaker implements Sink
{
	public final static String START= "$Start";
	public final static String CONSTRUCTOR= "$Constructor";
	public final static String REF = "$Ref";
	public final static String PROPERTY = "$Property";
	
	/** Real sink. */
	Sink sink;
	
	/** States. */
	enum State {NORMAL, STARTED, DID_VALUE, PROPERTY, DID_PROPERTY, IN_PROPERTY};
	/** Are we in the middle of constructing a constructor? */
	State state;
	/** Name of constructor while constructing. */
	String constructorName;
	/** Name of reference meta-variable while constructing. */
	String refName;
	/** Name of property we're constructing. */
	String propertyName; 
	/** Properties while constructing. */
	Map<String, Term> properties;
	
	Sink propertySink;
	
	// Constructor.
	
	/**
	 * Create meta-sink that delivers to the passed sink. 
	 */
	public UnmetaSink(Sink sink)
	{
		this.sink = sink;
		state = State.NORMAL;
	}
	
	/** Invoked when real constructor start needs to be shipped. */
	void open()
	{
		Constructor c = sink.makeConstructor(new Triple<String, String, Map<String, Term>>(constructorName, refName, properties));
		sink = sink.start(c);
		state = State.NORMAL;
		constructorName = null;
		refName = null;
		propertyName = null; 
		properties = null;
	}

	// DelegateMaker...
	
    @Override
    final public Maker maker()
    {
	    return sink;
    }

	// Sink...

	public Sink start(Constructor constructor)
	{
		switch (state)
		{
			case NORMAL : {
				String name = constructor.toString();
				if (name.equals(START))
				{
					state = State.STARTED;
				}
				else
				{
					sink = sink.start(constructor);
				}
				break;
			}
			case STARTED : {
				String c = constructor.toString();
				if (c.equals(PROPERTY))
				{
					state = State.PROPERTY;
				}
				else if (constructorName == null)
				{
					constructorName = c;
					state = State.DID_VALUE;
				}
				else if (refName == null)
				{
					refName = c;
					state = State.DID_VALUE;
				}
				else
				{
					assert false : "Bad meta-sink instruction.";
				}
				break;
			}
			case DID_VALUE :
				assert false : "Bad meta-sink instruction.";
				break;
				
			case PROPERTY : {
				String c = constructor.toString();
				if (propertyName == null)
				{
					propertyName = c;
					state = State.DID_PROPERTY;
				}
				else
				{
					propertySink = sink.makeBuffer(new CallBack(){
						@Override
						public void store(Variable[] binders, Term term, ContinuationSinkSetter continuationSetter)
						{
							assert binders.length == 0 : "Cannot have binders on property term.";
							properties.put(propertyName, term);
							state = State.DID_PROPERTY;
						}
					});
					state = State.IN_PROPERTY;
				}
				break;
			}

			case IN_PROPERTY :
				propertySink = propertySink.start(constructor);
				break;

			case DID_PROPERTY :
				break;
		}
		return this;
	}

	public Sink end()
	{
		switch (state)
		{
			case STARTED :
				// Done!
				open();
			case NORMAL :
				sink = sink.end();
				break;
				
			case IN_PROPERTY :
				propertySink = propertySink.end();
				break;
				
			case DID_VALUE :
				state = State.STARTED;
				break;
				
			case DID_PROPERTY :
				propertySink = null;
				state = State.DID_VALUE;
				break;
		}
		return this;
	}

	public Sink binds(Variable[] binders)
	{
		switch (state)
		{
			case STARTED :
				open();
			case NORMAL :
				sink = sink.binds(binders);
				break;
				
			case IN_PROPERTY :
				propertySink = propertySink.binds(binders);
				break;
				
			default :
				assert false : "Cannot bind variables here.";
		}
		return this;
	}

	public Sink use(Variable variable)
	{
		switch (state)
		{
			case STARTED :
				open();
			case NORMAL :
				sink = sink.use(variable);
				break;
				
			case IN_PROPERTY :
				propertySink = propertySink.use(variable);
				break;
				
			default :
				assert false : "Cannot use variable here.";
		}
		return this;
	}

	public Sink startMetaApplication(String name)
	{
		switch (state)
		{
			case STARTED :
				open();
			case NORMAL :
				sink = sink.startMetaApplication(name);
				break;
				
			case IN_PROPERTY :
				propertySink = propertySink.startMetaApplication(name);
				break;
				
			default :
				assert false : "Cannot start meta-application here.";
		}
		return this;
	}

	public Sink endMetaApplication()
	{
		switch (state)
		{
			case NORMAL :
				sink = sink.endMetaApplication();
				break;
				
			case IN_PROPERTY :
				propertySink = propertySink.endMetaApplication();
				break;
				
			default :
				assert false : "No meta-application to end.";
		}
		return this;
	}

	public Sink copy(Copyable source, boolean discard)
	{
		return source.copy(this, false, LinkedExtensibleMap.EMPTY_RENAMING);
	}
}
