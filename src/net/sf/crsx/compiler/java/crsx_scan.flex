/* Copyright (c) 2012 IBM Corporation. */
// $Id: crsx_scan.flex,v 3.1 2013/06/19 19:46:46 villardl Exp $
package net.sf.crsx.compiler.java;
 
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;

import static net.sf.crsx.compiler.java.Crsx.*;

///////////////////////////////////////////////////////////////////////////////////////////////////
// CRSX JAVA SCANNER 
///////////////////////////////////////////////////////////////////////////////////////////////////
 

%%

%class CrsxLexer
%unicode
%line
%column 
%final
%int

%{

    enum Tag {LINK_UNDEFINED_TAG, LINK_BASE_TAG, LINK_CONSTRUCTION_TAG, LINK_NAMED_PROPERTY_TAG, LINK_VARIABLE_PROPERTY_TAG, LINK_STRING_TAG, LINK_FIRST_BINDER_TAG, LINK_FOLLOWING_BINDER_TAG} ;

	/** Sink stack */
	private ArrayList<Sink> sinkStack = new ArrayList<Sink>(64);

    /** Tag stack */
	private ArrayList<Tag> tagStack = new ArrayList<Tag>(64);

    /** 
     * Data stack 
     * ConstructionDescriptor for LINK_CONSTRUCTION_TAG 
     * String for LINK_NAMED_PROPERTY_TAG and LINK_STRING_TAG 
     * Variable for LINK_VARIABLE_PROPERTY_TAG and LINK_*_BINDER_TAG 
     */
	private ArrayList<Object> dataStack = new ArrayList<Object>(64);
 
    /** Variables in scope for this constructor */
    private ArrayList<VariableNameMapLink> variableStack  = new ArrayList<VariableNameMapLink>(64);
 

// Push a state description of a particular kind and send any initialization events.
final private void makeBase(Sink sink)
{
    pushStack(sinkStack, sink);
    pushStack(tagStack, Tag.LINK_BASE_TAG);
  	pushStack(dataStack, null);
  	pushStack(variableStack, null);   
}

final private void pushConstruction(ConstructionDescriptor descriptor)
{
	assert descriptor != null;

	pushStack(sinkStack, topSink());
	pushStack(tagStack, Tag.LINK_CONSTRUCTION_TAG);
    pushStack(dataStack, descriptor);
    pushStack(variableStack, null);
    
    //
    topSink().start(descriptor);
    //
}

final private void pushNamedProperty(String name)
{
	pushStack(sinkStack, new BufferSink());
	pushStack(tagStack, Tag.LINK_NAMED_PROPERTY_TAG);
    pushStack(dataStack, name);
    pushStack(variableStack, null);
}

final private void pushVariableProperty(String variableName)
{
	pushStack(sinkStack, new BufferSink());
	pushStack(tagStack, Tag.LINK_VARIABLE_PROPERTY_TAG);
    pushStack(dataStack, lookupName(variableName));
    pushStack(variableStack, null);
}

final private void pushString(String string)
{
	pushStack(sinkStack, topSink());
	pushStack(tagStack, Tag.LINK_STRING_TAG);
    pushStack(dataStack, string);
    pushStack(variableStack, null);
}

final private void pushFirstBinder(String name)
{
    pushStack(sinkStack, topSink());
    pushStack(tagStack, Tag.LINK_FIRST_BINDER_TAG);
    
    // TODO: Double check that
    final boolean linear = name.indexOf("¹") != -1;
    final Variable variable = Variable.MAKE_VARIABLE(name, true, linear);
    pushStack(dataStack, variable);
    
    pushStack(variableStack, addNameMapLink(topStack(variableStack), name, variable)); 
}

final private void pushFollowingBinder(String name)
{
    pushStack(sinkStack, topSink());
    pushStack(tagStack, Tag.LINK_FOLLOWING_BINDER_TAG); 
    
    // TODO: Double check that
    final boolean linear = name.indexOf("¹") != -1;
    final Variable variable = Variable.MAKE_VARIABLE(name, true, linear);
    pushStack(dataStack, variable);
    
    pushStack(variableStack, addNameMapLink(topStack(variableStack), name, variable));  
}

// Pop a state of a particular kind including sending any pending events.
final private void popBase()
{
}

final private void popConstruction()
{
	assert topStack(tagStack) == Tag.LINK_CONSTRUCTION_TAG;
    assert topStack(dataStack) instanceof ConstructionDescriptor;
    
    //
    topStack(sinkStack).end((ConstructionDescriptor) topStack(dataStack));
    //
    
 	popStack(sinkStack);
    popStack(tagStack);
  	popStack(dataStack);
  	popStack(variableStack);
}

final private void popProperty() // either Named or Variable
{
	// Pop
    final Sink sink = popStack(sinkStack);
    final Tag tag = popStack(tagStack);
  	final Object data = popStack(dataStack);
  	popStack(variableStack); 

    //
    switch (tag)
    {
    case LINK_NAMED_PROPERTY_TAG :
	{
	    String name = (String) data;
	    Term term = sink.term(); 
	    topSink().propertyNamed(name, term);
	    break;
	}
    case LINK_VARIABLE_PROPERTY_TAG :
	{
        Variable variable = (Variable) data;
	    Term term = sink.term(); 
	    //FREE_BUFFER(topSink(state));
	    topSink().propertyVariable(variable, term);
	    break;
    }
    default :
        assert false : "state->tag != LINK_*_PROPERTY_TAG";
    }
}

final private void popString()
{
  	assert Tag.LINK_STRING_TAG ==  topStack(tagStack);

	// Pop
    popStack(sinkStack);
    popStack(tagStack);
  	popStack(dataStack);
  	popStack(variableStack);
}

//  close all following and one first binder and return array
final private VariableNameMapLink popBinders() 
{
    /* First count the number of binders. */
    int size = 1; /* the first */
    int index = tagStack.size() - 1;
    while (tagStack.get(index --) == Tag.LINK_FOLLOWING_BINDER_TAG)
    	size ++;
        
    /* Extract binder variables and pop the stack */
    final VariableNameMapLink scope = topStack(variableStack);
    
    Variable[] binders = new Variable[size];
    for (int i = size-1; i >= 0; --i)
    {
        assert ((i>0 && topStack(tagStack) == Tag.LINK_FOLLOWING_BINDER_TAG) || (i==0 && topStack(tagStack) == Tag.LINK_FIRST_BINDER_TAG));
        binders[i] = (Variable) topStack(dataStack);
        
        // Pop
    	popStack(sinkStack);
    	popStack(tagStack);
  		popStack(dataStack);
  		popStack(variableStack);
    }
    
    //
    topSink().binds(binders);
    //
    return scope;
}

// Retrieve the stored value in the top state.
final private String topString()  // use before popString()
{
   return (String) topStack(dataStack);
}

final private Sink topSink()
{
  return topStack(sinkStack);
}

final private void setNames(VariableNameMapLink names)
{
    popStack(variableStack);
    pushStack(variableStack, names);
}

// Find variable or allocate as fresh if previously not seen.
final private Variable lookupName(String name)
{
    // First search for bound variable.
    for (int i = tagStack.size() - 1; tagStack.get(i) != Tag.LINK_BASE_TAG; i--)
    { 
        for (VariableNameMapLink link = variableStack.get(i); link != null; link = link.link)
            if (link.key.equals(name))
                return link.value;
    }
     
    // Allocate as fresh variable.
     // TODO: Double check that
    final boolean linear = name.indexOf("¹") != -1;
    final Variable variable = Variable.MAKE_VARIABLE(name, true, linear);
    
    setNames(addNameMapLink(topStack(variableStack), name, variable));
    
    return variable;
}
 
final private ConstructionDescriptor lookupDescriptor(String name)
{
	return null; // TODO
}
 
// Helper to remove quotes.
	final private String unquote(String quoted)
	{
		char q = quoted.charAt(0);
		if (q != '"' && q != '\'')
			return quoted;

		char[] unquoted = new char[quoted.length()];
		char c;
		int j = 0;
		for (int i = 1; i < quoted.length() - 1; i++)
		{
			c = quoted.charAt(i);
			if (c == q) // shouldn't be needed (unless occurring in middle of quoted)
			{
				// ignore...
			}
			else if (c == '\\')
			{
				i ++;
				c = quoted.charAt(i);
				switch (c)
				{
					case '0' :
					case '1' :
					case '2' :
					case '3' :
					case '4' :
					case '5' :
					case '6' :
					case '7' : {
						int n = 0, m = 0;
						do
						{
							n = (n << 3) + (c - '0');
							i++;
							c = quoted.charAt(i);
							++m;
						}
						while (m < 3 && '0' <= c && c <= '7');
						unquoted[j++] = (char) n;
					}
						break;
					//  case 'a': unquoted[j++] = '\a'; break; Bell not supported
					case 'b' :
						unquoted[j++] = '\b';
						break;
					case 'f' :
						unquoted[j++] = '\f';
						break;
					case 'n' :
						unquoted[j++] = '\n';
						break;
					case 'r' :
						unquoted[j++] = '\r';
						break;
					default :
						unquoted[j++] = c;
				}
			}
			else
			{
				unquoted[j++] = c;
			}
		}

		return new String(unquoted);
	}

/* Main entry points. */

	final public int scanTerm(Sink sink, Reader input) throws IOException
	{
		yyreset(input);
		makeBase(sink);
		yybegin(Before);
		int result = yylex();
		popBase();

		return result;
	}

	final public int loadTerm(Sink sink, String name) throws IOException
	{
		FileReader reader = new FileReader(name);
		scanTerm(sink, reader);

		return 1;
	}


// Inner classes


static class VariableNameMapLink
{
   	VariableNameMapLink link;
    String key;
    Variable value;
    
    VariableNameMapLink(VariableNameMapLink link, String key, Variable value)
    {
     	this.link = link;
     	this.key = key;
     	this.value = value;
    }
};


final private VariableNameMapLink addNameMapLink(VariableNameMapLink parent, String name, Variable variable)
{
	// TODO: DIFFERENT FROM C VERSION
    return new VariableNameMapLink(parent, name, variable);
}

%}


/* DEFINITIONS. */

/* White space. */
SPACE_T = [ \t\f]

/* Constructor. */
CONSTRUCTOR_T =  ([[:uppercase:]_][[:jletterdigit:]_$-]*|['']([^''\\]|\\[0-7][0-7]?[0-7]?|\\[^0-7\n])*[''])

/* Literal. */
LITERAL_T =  ([""]([^""\\]|\\[0-7][0-7]?[0-7]?|\\[^0-7\n])*[""]|[0-9+-][0-9]*([.][0-9]+)?([Ee][+-]?[0-9]+)?)

/* Variable name (includes Unicode for �). */
VARIABLE_T =  ([[:lowercase:]]([[:jletterdigit:]_-]|"\302\271")*)

/* STATES. */

%x Before BeforeWithBinders AfterSimple BeforeKey AfterProperties AfterConstructor BeforeArgument AfterArguments AfterKey AfterFirstVariable AfterBinder
 
/* RULES. */

/*
Here is the grammar with the state established by each token:

<Before,BeforeWithBinders,BeforeArgument>
t  ::=
        V <AfterSimple,AfterFirstVariable>
     |
        L <AfterSimple>
     |
        ( '{' <BeforeKey>
              ps? '}' <AfterProperties>
                      )? C <AfterConstructor>
                           ( '[' <BeforeArgument>
                                 as ']' <AfterArguments>
                                        )? <AfterConstructor,AfterArguments>

<BeforeKey>
ps  ::=  p ( ';' <BeforeKey>
                 p )* <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>

<BeforeKey>
p  ::=
        V <AfterKey>
          ':' <Before>
              t <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>
     |
        L <AfterKey>
          ':' <Before>
              t <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>

<BeforeArgument>
as  ::=  ( a <AfterSimple,AfterFirstVariable,AfterArgument,AfterFirstVariable>
             ( ',' <BeforeArgument>
                   a )* )? <AfterSimple,AfterFirstVariable,AfterArgument,AfterFirstVariable>

<BeforeArgument>
a  ::=
        ( V <AfterFirstVariable>
            ( V <AfterBinder>
                )* '.' <BeforeWithBinders>
                       )? t <AfterSimple,AfterFirstVariable,AfterArgument,AfterFirstVariable>
*/

%%

    // INITIALIZE.
//    StateLink state = yyextra;
//    yybegin(Before);

    /* V as top level t or property value t. */
<Before>{VARIABLE_T}             { topSink().use(lookupName(yytext())); yybegin(AfterSimple); }
    /* V as t in a without binders or as first binder in a. */
<BeforeArgument>{VARIABLE_T}     { pushString(yytext()); yybegin(AfterFirstVariable); }
    /* V as t in a after binders. */
<BeforeWithBinders>{VARIABLE_T}  { Variable variable = lookupName(yytext()); popBinders(); topSink().use(variable); yybegin(AfterSimple); }
    /* V as key in p. */
<BeforeKey>{VARIABLE_T}          { pushVariableProperty(yytext()); yybegin(AfterKey); }
    /* V as second binder in a. */
<AfterFirstVariable>{VARIABLE_T} { String firstName = topString(); popString(); pushFirstBinder(firstName); pushFollowingBinder(yytext()); yybegin(AfterBinder); }
    /* V as third or subsequent binder in a. */
<AfterBinder>{VARIABLE_T}        { pushFollowingBinder(yytext()); }

    /* L as top level t or property value t. */
<Before>{LITERAL_T}            { topSink().literal(unquote(yytext())); yybegin(AfterSimple); }
    /* L as t in a without binders. */
<BeforeArgument>{LITERAL_T}    { topSink().literal(unquote(yytext())); yybegin(AfterSimple); }
    /* L as t in a after binders. */
<BeforeWithBinders>{LITERAL_T} { popBinders(); topSink().literal(unquote(yytext())); yybegin(AfterSimple); }
    /* L as key in p. */
<BeforeKey>{LITERAL_T}         { pushNamedProperty(unquote(yytext())); yybegin(AfterKey); }
    /* L in illegal places. */
<AfterFirstVariable,AfterBinder>{LITERAL_T} { throw new Error("Unexpected " + yytext() + " literal where binder expected!\n"); }

    /* C starts or is top level t or property value t. */
<Before>{CONSTRUCTOR_T}             { pushConstruction(lookupDescriptor(unquote(yytext()))); yybegin(AfterConstructor); }
    /* C starts or is t in a without binders. */
<BeforeArgument>{CONSTRUCTOR_T}     { pushConstruction(lookupDescriptor(unquote(yytext()))); yybegin(AfterConstructor); }
    /* C starts or is t in a after binders. */
<BeforeWithBinders>{CONSTRUCTOR_T}  { VariableNameMapLink scope = popBinders(); pushConstruction(lookupDescriptor(unquote(yytext()))); yybegin(AfterConstructor); setNames(scope); }
    /* C starts part of t after a property set. */
<AfterProperties>{CONSTRUCTOR_T}    { pushConstruction(lookupDescriptor(unquote(yytext()))); yybegin(AfterConstructor); }
    /* C in illegal places. */
<AfterFirstVariable,AfterBinder>{CONSTRUCTOR_T} { throw new Error("Unexpected constructor where binder expected!\n"); }

    /* "{" starts top level t or property value t. */
<Before>"{"            { yybegin(BeforeKey); }
    /* '{' starts t in a without binders. */
<BeforeArgument>"{"    { yybegin(BeforeKey); }
    /* '{' starts t in a after binders. */
<BeforeWithBinders>"{" { popBinders(); yybegin(BeforeKey); }
    /* "{" in illegal places. */
<BeforeKey>"{" { throw new Error("Unexpected '{' where property key expected!\n"); }
<AfterFirstVariable,AfterBinder>"{" { throw new Error("Unexpected '{' where binder expected!\n"); }

    /* ":" */
<AfterKey>":" { yybegin(Before); }
    /* ":" errors */
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder,AfterConstructor,AfterArguments>":" { throw new Error("Expected ':' after property key!\n"); }

    /* ";" */
<AfterSimple>";"		             { popProperty(); yybegin(BeforeKey); }
    /* ";" */
<AfterConstructor,AfterArguments>";" { popConstruction(); popProperty(); yybegin(BeforeKey); }
    /* ";" */
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder>";" { throw new Error("';' only allowed after finished property mapping!\n"); }

    /* "}" */
<AfterSimple>"}"                     { popProperty(); yybegin(AfterProperties); }
<AfterConstructor,AfterArguments>"}" { popConstruction(); popProperty(); yybegin(AfterProperties); }
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder>"}" { throw new Error("'}' only allowed after finished property mapping!\n"); }

    /* "[" */
<AfterConstructor>"[" { yybegin(BeforeArgument); }
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder,AfterSimple,AfterArguments>"[" { throw new Error("'[' only allowed after constructor!\n"); }

    /* "," */
<AfterSimple>","                     { yybegin(BeforeArgument); }
<AfterConstructor,AfterArguments>"," { popConstruction(); yybegin(BeforeArgument); }
<AfterFirstVariable>","              { topSink().use(lookupName(topString())); popString(); yybegin(BeforeArgument); }

    /* "]" */
<AfterSimple>"]"                     { yybegin(AfterArguments); }
<AfterConstructor,AfterArguments>"]" { popConstruction(); yybegin(AfterArguments); }
<AfterFirstVariable>"]"              { topSink().use(lookupName(topString())); popString(); yybegin(AfterArguments); }

    /* "." */
<AfterFirstVariable>"." { String firstName = topString(); popString(); pushFirstBinder(firstName); yybegin(BeforeWithBinders); }
<AfterBinder>"."        { yybegin(BeforeWithBinders); }

    /* EOF */
<AfterSimple><<EOF>>                     { yyclose(); }
<AfterConstructor,AfterArguments><<EOF>> { popConstruction(); yyclose(); }
<AfterFirstVariable><<EOF>>              { topSink().use(lookupName(topString())); popString(); yyclose(); }

    /* Skip spaces. */
{SPACE_T} {}
"//".*"\n" {}

    /* Everything else is an error... */
. { throw new Error("Illegal character <"+ yytext()+ ">"); }

