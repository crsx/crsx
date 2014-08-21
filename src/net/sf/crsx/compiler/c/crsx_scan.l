/* Copyright (c) 2011,2012 IBM Corporation. */
%top{
// $Id: crsx_scan.l,v 3.13 2013/12/16 16:10:35 krisrose Exp $

///////////////////////////////////////////////////////////////////////////////////////////////////
// CRSX SCANNER
//
// Implements the load/read/scanTerm() functions based on the LOOKUP_DESCRIPTOR macro.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "crsx.h"
#include <string.h>
#include <stdio.h>
extern int fileno (FILE* file);

// State stack.

typedef struct _StateLink *StateLink;

// Push a state description of a particular kind and send any initialization events.
StateLink makeBase(Sink sink);
void pushConstruction(StateLink *statep, ConstructionDescriptor descriptor);
void pushNamedProperty(StateLink *statep, char *name);
void pushVariableProperty(StateLink *statep, char *variableName);
void pushString(StateLink *statep, char *string);
void pushFirstBinder(StateLink *statep, char *name);
void pushFollowingBinder(StateLink *statep, char *name);

// Pop a state of a particular kind including sending any pending events.
void popBase(StateLink *statep);
void popConstruction(StateLink *statep);
void popProperty(StateLink *statep); // either Named or Variable
void popString(StateLink *statep);
VariableNameMapLink popBinders(StateLink *statep); // close all following and one first binder and return link

// Retrieve the stored value in the top state.
char *topString(StateLink state);  // use before popString()
Sink topSink(StateLink state);
void setNames(StateLink state, VariableNameMapLink names);

// Find variable or allocate as fresh if previously not seen.
Variable lookupName(StateLink state, char *name);

// Helper to remove quotes.
static char *unquote(Context context, char *quoted)
{
	return makeRescaped(context, quoted);
}

// Helper for string allocation.
char* strdup_local (Context c, const char* s);
}

/* Generated names use crsx_yy. */
%option prefix="crsx_yy"

/* Scanner is reentrant with the initial state as extra argument. */
%option reentrant extra-type="StateLink"

/* Use CRSX memory management. */
%option noyyalloc noyyrealloc noyyfree

/* Several features omitted. */
%option nounput noinput noyywrap

/* DEFINITIONS. */

/* White space. */
SPACE_T   [[:space:]]


/* Constructor. */
CONSTRUCTOR_T   ([[:upper:]_$][[:alnum:]_$-]*|['']([^''\\]|\\[0-3]?[0-7]?[0-7]|\\[^0-7\n])*[''])

/* Literal. */
LITERAL_T   ([""]([^""\\]|\\[0-3]?[0-7]?[0-7]|\\[^0-7\n])*[""]|[0-9+-][0-9]*([.][0-9]+)?([Ee][+-]?[0-9]+)?)

/* Variable name, and quoted form. */
VARIABLE_T   ([[:lower:]]|"\302\271")([[:alnum:]_-]|"\302\271"|"\341\265\207"|"\313\242")*
VARIABLEQ_T   ("\302\271")?[v]([""]([^""\\]|\\[0-7][0-7]?[0-7]?|\\[^0-7\n])*[""]|['']([^''\\]|\\[0-7][0-7]?[0-7]?|\\[^0-7\n])*("\341\265\207")?[''])

/* STATES. */

%x Before BeforeWithBinders AfterSimple BeforeFirstKey BeforeKey AfterProperties AfterConstructor BeforeArgument AfterArguments AfterKey AfterFirstVariable AfterBinder
%{
#ifdef FLEX_DEBUG
  static char *stateNames[] = {"INITIAL", "Before", "BeforeWithBinders", "AfterSimple", "BeforeKey", "AfterProperties", "AfterConstructor", "BeforeArgument", "AfterArguments", "AfterKey", "AfterFirstVariable", "AfterBinder"};
# define B(STATE) ((yy_flex_debug ? (b_state(state, STATE), 0) : 0), BEGIN(STATE))
  void b_state(StateLink state, int STATE);
#else
# define B(STATE) BEGIN(STATE)
#endif
%}

/* RULES. */

/*
Here is the grammar with the state established by each token:

<Before,BeforeWithBinders,BeforeArgument>
t  ::=
        V <AfterSimple,AfterFirstVariable>
     |
        L <AfterSimple>
     |
        ( '{' <BeforeFirstKey>
              ps? '}' <AfterProperties>
                      )? n

<Before,BeforeWithBinders,BeforeArgument,AfterProperties>
n  ::= C <AfterConstructor>
         ( '[' <BeforeArgument>
           as ']' <AfterArguments>
         )? <AfterConstructor,AfterArguments>
     |
       L <AfterSimple>


<BeforeKey,BeforeFirstKey>
ps  ::=  p ( ';' <BeforeKey>
                 p )* <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>

<BeforeKey,BeforeFirstKey>
p  ::=
        V <AfterKey>
          ':' <Before>
              t <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>
     |
        L <AfterKey>
          ':' <Before>
              t <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>
     |
        C <AfterKey>
          ':' <Before>
              t <AfterSimple,AfterFirstVariable,AfterConstructor,AfterArguments>

<BeforeArgument>
as  ::=  ( a <AfterSimple,AfterFirstVariable,AfterArgument>
             ( ',' <BeforeArgument>
                   a )* )? <AfterSimple,AfterFirstVariable,AfterArgument>

<BeforeArgument>
a  ::=
        ( V <AfterFirstVariable>
            ( V <AfterBinder>
                )* '.' <BeforeWithBinders>
                       )? t <AfterSimple,AfterFirstVariable,AfterArgument>
*/

%%

    // INITIALIZE.
    StateLink state = yyextra;
    B(Before);

    /* V as top level t or property value t. */
<Before>{VARIABLE_T}             { USEL(topSink(state), lookupName(state, yytext)); B(AfterSimple); }
<Before>{VARIABLEQ_T}             { USEL(topSink(state), lookupName(state, unquote(topSink(state)->context, yytext+1))); B(AfterSimple); }
    /* V as t in a without binders or as first binder in a. */
<BeforeArgument>{VARIABLE_T}     { pushString(&state, yytext); B(AfterFirstVariable); }
<BeforeArgument>{VARIABLEQ_T}     { pushString(&state, unquote(topSink(state)->context, yytext+1)); B(AfterFirstVariable); }
    /* V as t in a after binders. */
<BeforeWithBinders>{VARIABLE_T}  { Variable variable = lookupName(state, yytext); popBinders(&state); USEL(topSink(state), variable); B(AfterSimple); }
<BeforeWithBinders>{VARIABLEQ_T}  { Variable variable = lookupName(state, unquote(topSink(state)->context, yytext+1)); popBinders(&state); USEL(topSink(state), variable); B(AfterSimple); }
    /* V as key in p. */
<BeforeKey,BeforeFirstKey>{VARIABLE_T}  { pushVariableProperty(&state, yytext); B(AfterKey); }
<BeforeKey,BeforeFirstKey>{VARIABLEQ_T}  { pushVariableProperty(&state, unquote(topSink(state)->context, yytext+1)); B(AfterKey); }
    /* V as second binder in a. */
<AfterFirstVariable>{VARIABLE_T} { char *firstName = topString(state); popString(&state); pushFirstBinder(&state, firstName); pushFollowingBinder(&state, yytext); B(AfterBinder); }
<AfterFirstVariable>{VARIABLEQ_T} { char *firstName = topString(state); popString(&state); pushFirstBinder(&state, firstName); pushFollowingBinder(&state, unquote(topSink(state)->context, yytext+1)); B(AfterBinder); }
    /* V as third or subsequent binder in a. */
<AfterBinder>{VARIABLE_T}        { pushFollowingBinder(&state, yytext); }
<AfterBinder>{VARIABLEQ_T}        { pushFollowingBinder(&state, unquote(topSink(state)->context, yytext+1)); }

    /* L as top level t or property value t. */
<Before>{LITERAL_T}            { LITERALU(topSink(state), unquote(topSink(state)->context, yytext)); B(AfterSimple); }
    /* L as t in a without binders. */
<BeforeArgument>{LITERAL_T}    { LITERALU(topSink(state), unquote(topSink(state)->context, yytext)); B(AfterSimple); }
    /* L as t in a after binders. */
<BeforeWithBinders>{LITERAL_T} { popBinders(&state); LITERALU(topSink(state), unquote(topSink(state)->context, yytext)); B(AfterSimple); }
    /* L is t after a property set. */
<AfterProperties>{LITERAL_T}    { LITERALU(topSink(state), unquote(topSink(state)->context, yytext)); B(AfterSimple); }
    /* L as key in p. */
<BeforeKey,BeforeFirstKey>{LITERAL_T}       { pushNamedProperty(&state, unquote(topSink(state)->context, yytext)); B(AfterKey); }
    /* L in illegal places. */
<AfterFirstVariable,AfterBinder>{LITERAL_T} { ERRORF(topSink(state)->context, Scan, "Unexpected %s literal where binder expected!\n", yytext); }

    /* C starts or is top level t or property value t. */
<Before>{CONSTRUCTOR_T}             { pushConstruction(&state, LOOKUP_DESCRIPTOR(topSink(state)->context, unquote(topSink(state)->context, yytext))); B(AfterConstructor); }
    /* C starts or is t in a without binders. */
<BeforeArgument>{CONSTRUCTOR_T}     { pushConstruction(&state, LOOKUP_DESCRIPTOR(topSink(state)->context, unquote(topSink(state)->context, yytext))); B(AfterConstructor); }
    /* C starts or is t in a after binders. */
<BeforeWithBinders>{CONSTRUCTOR_T}  { VariableNameMapLink scope = popBinders(&state); pushConstruction(&state, LOOKUP_DESCRIPTOR(topSink(state)->context, unquote(topSink(state)->context, yytext))); B(AfterConstructor); setNames(state, scope); }
    /* C starts part of t after a property set. */
<AfterProperties>{CONSTRUCTOR_T}    { pushConstruction(&state, LOOKUP_DESCRIPTOR(topSink(state)->context, unquote(topSink(state)->context, yytext))); B(AfterConstructor); }
    /* C as key in p. */
<BeforeKey,BeforeFirstKey>{CONSTRUCTOR_T}       { pushNamedProperty(&state, unquote(topSink(state)->context, yytext)); B(AfterKey); }
    /* C in illegal places. */
<AfterFirstVariable,AfterBinder>{CONSTRUCTOR_T} { ERRORF(topSink(state)->context, Scan, "Unexpected constructor where binder expected!\n"); }

    /* "{" starts top level t or property value t. */
<Before>"{"            { B(BeforeFirstKey); }
    /* '{' starts t in a without binders. */
<BeforeArgument>"{"    { B(BeforeFirstKey); }
    /* '{' starts t in a after binders. */
<BeforeWithBinders>"{" { VariableNameMapLink scope = popBinders(&state); B(BeforeFirstKey); setNames(state, scope); }
    /* "{" in illegal places. */
<BeforeKey,BeforeFirstKey>"{" { ERRORF(topSink(state)->context, Scan, "Unexpected '{' where property key expected!\n"); }
<AfterFirstVariable,AfterBinder>"{" { ERRORF(topSink(state)->context, Scan, "Unexpected '{' where binder expected!\n"); }

    /* ":" */
<AfterKey>":" { B(Before); }
    /* ":" errors */
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder,AfterConstructor,AfterArguments>":" { ERRORF(topSink(state)->context, Scan, "Expected ':' after property key!\n"); }

    /* ";" */
<AfterSimple>";"		             { popProperty(&state); B(BeforeKey); }
    /* ";" */
<AfterConstructor,AfterArguments>";" { popConstruction(&state); popProperty(&state); B(BeforeKey); }
    /* ";" */
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder>";" { ERRORF(topSink(state)->context, Scan, "';' only allowed after finished property mapping!\n"); }

    /* "}" */
<BeforeFirstKey>"}"                  { B(AfterProperties); }
<AfterSimple>"}"                     { popProperty(&state); B(AfterProperties); }
<AfterConstructor,AfterArguments>"}" { popConstruction(&state); popProperty(&state); B(AfterProperties); }
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder>"}" { ERRORF(topSink(state)->context, Scan, "'}' only allowed after finished property mapping!\n"); }

    /* "[" */
<AfterConstructor>"[" { B(BeforeArgument); }
<Before,BeforeArgument,BeforeWithBinders,AfterFirstVariable,AfterBinder,AfterSimple,AfterArguments>"[" { ERRORF(topSink(state)->context, Scan, "'[' only allowed after constructor!\n"); }

    /* "," */
<AfterSimple>","                     { B(BeforeArgument); }
<AfterConstructor,AfterArguments>"," { popConstruction(&state); B(BeforeArgument); }
<AfterFirstVariable>","              { USEL(topSink(state), lookupName(state, topString(state))); popString(&state); B(BeforeArgument); }

    /* "]" */
<AfterSimple>"]"                     { B(AfterArguments); }
<AfterConstructor,AfterArguments>"]" { popConstruction(&state); B(AfterArguments); }
<AfterFirstVariable>"]"              { USEL(topSink(state), lookupName(state, topString(state))); popString(&state); B(AfterArguments); }

    /* "." */
<AfterFirstVariable>"." { char *firstName = topString(state); popString(&state); pushFirstBinder(&state, firstName); B(BeforeWithBinders); }
<AfterBinder>"."        { B(BeforeWithBinders); }

    /* EOF */
<AfterSimple><<EOF>>                     { yyterminate(); }
<AfterConstructor,AfterArguments><<EOF>> { popConstruction(&state); yyterminate(); }
<AfterFirstVariable><<EOF>>              { USEL(topSink(state), lookupName(state, topString(state))); popString(&state); yyterminate(); }

    /* Skip spaces. */
<*>{SPACE_T} {}
<*>"//".*"\n" {}

    /* Everything else is an error... */
<*>. { ERRORF(topSink(state)->context, Scan, "Unexpected symbol in term (%s)\n", yytext); }

%%

/* State stack. */

struct _StateLink
{
    StateLink parent; /* links form a stack */
    Sink sink; /* the term accumulator at this level */
    enum {LINK_UNDEFINED_TAG, LINK_BASE_TAG, LINK_CONSTRUCTION_TAG, LINK_NAMED_PROPERTY_TAG, LINK_VARIABLE_PROPERTY_TAG, LINK_STRING_TAG, LINK_FIRST_BINDER_TAG, LINK_FOLLOWING_BINDER_TAG} tag;
    union {
        ConstructionDescriptor descriptor; /* for LINK_CONSTRUCTION_TAG */
        char *string;                      /* for LINK_NAMED_PROPERTY_TAG and LINK_STRING_TAG */
        Variable variable;                 /* for LINK_VARIABLE_PROPERTY_TAG and LINK_*_BINDER_TAG */
    } stored;
    VariableNameMapLink variableNames; /* variables in scope for this constructor. */
};

char *topString(StateLink state)
{
    ASSERT(topSink(state)->context, state->tag == LINK_STRING_TAG);
    return state->stored.string;
}

Sink topSink(StateLink state)
{
    return state->sink;
}

void setNames(StateLink state, VariableNameMapLink names)
{
    //assert(!state->variableNames);
    state->variableNames = names;
}

Variable lookupName(StateLink state, char *name)
{
    StateLink s;
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "lookupName(%s) in", name);
    for (s = state; s; s = s->parent)
    {
        VariableNameMapLink link;
        for (link = s->variableNames; link; link = link->link)
            FPRINTF(sink->context, STDERR, " %s", link->key);
    }
    FPRINTF(sink->context, STDERR, "\n");
#endif
    // First search for bound variable.
    for (s = state; s; s = s->parent)
    {
        VariableNameMapLink link;
        for (link = s->variableNames; link; link = link->link)
            if (!strcmp(link->key, name))
                return link->value;
        if (s->tag == LINK_BASE_TAG) break;
    }
    // Allocate as fresh variable.
    assert (s->tag == LINK_BASE_TAG);
    Variable v = (strstr(name, "\302\271") ? MAKE_FRESH_LINEAR_VARIABLE(s->sink->context, name) : MAKE_FRESH_PROMISCUOUS_VARIABLE(s->sink->context, name));
    s->variableNames = addNameMapLink(s->sink->context, s->variableNames, strdup_local(topSink(state)->context, name), v);
    return v;
}

StateLink makeBase(Sink sink)
{
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "makeBase\n");
#endif
    StateLink state = (StateLink) ALLOCATE(sink->context, sizeof(struct _StateLink));
    state->parent = NULL;
    state->sink = sink;
    state->tag = LINK_BASE_TAG;
    state->variableNames = NULL;
    return state;
}

void popBase(StateLink *statep)
{
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "popBase\n");
#endif
    StateLink state = *statep;
    *statep = state->parent; /* pop */
    //
    ASSERT(topSink(state)->context, state->tag == LINK_BASE_TAG);
    ASSERT(topSink(state)->context, !(*statep));
    //
    FREE(topSink(state)->context, state);
}

void pushConstruction(StateLink *statep, ConstructionDescriptor descriptor)
{
    ASSERT((*statep)->sink->context, descriptor);
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "pushConstruction(%s)\n", descriptor->sort->constructorNames[descriptor->sortoffset]);
#endif
    //
    StateLink state = (StateLink) ALLOCATE((*statep)->sink->context, sizeof(struct _StateLink));
    state->parent = *statep;
    state->sink = (*statep)->sink;
    state->tag = LINK_CONSTRUCTION_TAG;
    state->stored.descriptor = descriptor;
    state->variableNames = NULL;
    //
    topSink(state)->start(topSink(state), descriptor);
    //
    *statep = state; /* push */
}

void popConstruction(StateLink *statep)
{
    StateLink state = *statep;
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "popConstruction(%s)\n", state->stored.descriptor->sort->constructorNames[state->stored.descriptor->sortoffset]);
#endif
    *statep = state->parent; /* pop */
    //
    ASSERT(topSink(state)->context, state->tag == LINK_CONSTRUCTION_TAG);
    ASSERT(topSink(state)->context, *statep);
    ASSERT(topSink(state)->context, state->stored.descriptor);
    //
    (*statep)->sink->end((*statep)->sink, state->stored.descriptor);
    //
    FREE((*statep)->sink->context, state);
}

void pushNamedProperty(StateLink *statep, char *name)
{
    ASSERT((*statep)->sink->context, name);
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "pushNamedProperty(%s)\n", name);
#endif
    //
    StateLink state = (StateLink) ALLOCATE((*statep)->sink->context, sizeof(struct _StateLink));
    state->parent = *statep;
    state->sink = MAKE_BUFFER((*statep)->sink->context);
    state->tag = LINK_NAMED_PROPERTY_TAG;
    state->stored.string = GLOBAL(topSink(state)->context, name);
    state->variableNames = NULL;
    //
    *statep = state; /* push */
}

void pushVariableProperty(StateLink *statep, char *variableName)
{
    ASSERT((*statep)->sink->context, variableName);
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "pushVariableProperty(%s)\n", variableName);
#endif
    //
    StateLink state = (StateLink) ALLOCATE((*statep)->sink->context, sizeof(struct _StateLink));
    state->parent = *statep;
    state->sink = MAKE_BUFFER((*statep)->sink->context);
    state->tag = LINK_VARIABLE_PROPERTY_TAG;
    state->stored.variable = lookupName(state, variableName);
    state->variableNames = NULL;
    //
    *statep = state; /* push */
}

void popProperty(StateLink *statep)
{
    StateLink state = *statep;
    *statep = state->parent; /* pop */
    Context context = topSink(state)->context;
    //
    switch (state->tag)
    {
    case LINK_NAMED_PROPERTY_TAG :
	{
#ifdef FLEX_DEBUG
        FPRINTF(sink->context, STDERR, "popNamedProperty(%s)\n", state->stored.string);
#endif
        ASSERT(context, state->stored.string);
	    char *name = state->stored.string;
	    Term term = BUFFER_TERM(topSink(state));
	    FREE_BUFFER(topSink(state));
	    ADD_PROPERTY_NAMED((*statep)->sink, name, term);
	    break;
	}
    case LINK_VARIABLE_PROPERTY_TAG :
	{
#ifdef FLEX_DEBUG
        FPRINTF(sink->context, STDERR, "popVariableProperty(%s)\n", state->stored.variable->name);
#endif
        ASSERT(context, state->stored.variable);
	    Variable variable = state->stored.variable;
	    Term term = BUFFER_TERM(topSink(state));
	    FREE_BUFFER(topSink(state));
	    ADD_PROPERTY_VARIABLE((*statep)->sink, variable, term);
	    break;
    }
    default :
        ASSERT(context, !"state->tag != LINK_*_PROPERTY_TAG");
    }
    FREE(context, state);
}

void pushString(StateLink *statep, char *string)
{
    ASSERT((*statep)->sink->context, string);
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "pushString(%s)\n", string);
#endif
    //
    StateLink state = (StateLink) ALLOCATE((*statep)->sink->context, sizeof(struct _StateLink));
    state->parent = *statep;
    state->sink = (*statep)->sink;
    state->tag = LINK_STRING_TAG;
    state->stored.string = GLOBAL(topSink(state)->context, string);
    state->variableNames = NULL;
    //
    *statep = state; /* push */
}

void popString(StateLink *statep)
{
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "popString\n");
#endif
    StateLink state = *statep;
    *statep = state->parent; /* pop */
    //
    ASSERT(topSink(state)->context, state->tag == LINK_STRING_TAG);
    FREE(topSink(state)->context, state);
}

char*
strdup_local (Context c, const char* s)
{
	return ALLOCATENF(c, strlen (s) + 1, "%s", s);
}

void pushFirstBinder(StateLink *statep, char *name)
{
    ASSERT((*statep)->sink->context, name);
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "pushFirstBinder(%s)\n", name);
#endif
    //
    StateLink state = (StateLink) ALLOCATE((*statep)->sink->context, sizeof(struct _StateLink));
    state->parent = *statep;
    state->sink = (*statep)->sink;
    state->tag = LINK_FIRST_BINDER_TAG;
    Variable variable = (strstr(name, "\302\271") ? MAKE_BOUND_LINEAR_VARIABLE(topSink(state)->context, name) : MAKE_BOUND_PROMISCUOUS_VARIABLE(topSink(state)->context, name));
    state->stored.variable = variable;
    state->variableNames = addNameMapLink(topSink(state)->context, (*statep)->variableNames, strdup_local(state->sink->context, name), variable);
    //
    *statep = state; /* push */
}

void pushFollowingBinder(StateLink *statep, char *name)
{
    ASSERT((*statep)->sink->context, name);
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "pushFollowingBinder(%s)\n", name);
#endif
    //
    StateLink state = (StateLink) ALLOCATE((*statep)->sink->context, sizeof(struct _StateLink));
    state->parent = *statep;
    state->sink = (*statep)->sink;
    state->tag = LINK_FOLLOWING_BINDER_TAG;
    Variable variable = (strstr(name, "\302\271") ? MAKE_BOUND_LINEAR_VARIABLE(topSink(state)->context, name) : MAKE_BOUND_PROMISCUOUS_VARIABLE(topSink(state)->context, name));
    state->stored.variable = variable;
    state->variableNames = addNameMapLink(topSink(state)->context, (*statep)->variableNames, strdup_local(state->sink->context, name), variable);
    //
    *statep = state; /* push */
}

VariableNameMapLink popBinders(StateLink *statep)
{
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "popBinders:");
#endif
    /* First count the number of binders. */
    int size = 1; /* the first */
    {
        StateLink s = *statep;
        for (; s && s->tag == LINK_FOLLOWING_BINDER_TAG; s = s->parent) ++size;
    }
    /* Extract binder variables and pop the stack */
    StateLink state = *statep;
    Variable *binders = (Variable*) ALLOCATE(topSink(state)->context, size*sizeof(Variable));
    VariableNameMapLink scope = state->variableNames;
    int i;
    for (i = size-1; i >= 0; --i)
    {
        ASSERT(topSink(state)->context, ((i>0 && state->tag==LINK_FOLLOWING_BINDER_TAG) || (i==0 && state->tag==LINK_FIRST_BINDER_TAG)));
        binders[i] = state->stored.variable;
#ifdef FLEX_DEBUG
        FPRINTF(sink->context, STDERR, " %s", binders[i]->name);
#endif

        StateLink old = state;
        state = state->parent;
        FREE(old->sink->context, old);
    }
    *statep = state; /* pops */
#ifdef FLEX_DEBUG
    FPRINTF(sink->context, STDERR, "\n");
#endif
    //
    BINDS(topSink(state), size, binders);
    //
    return scope;
}

#ifdef FLEX_DEBUG
void b_state(StateLink state, int STATE)
{
    Context context = topSink(state)->context;
    FPRINTF(context, STDERR,"--<%s> [", stateNames[STATE]);
    StateLink s;
    for (s = state; s; s = s->parent)
    {
        switch (s->tag)
        {
        case LINK_UNDEFINED_TAG:          FPRINTF(context, STDERR, "? "); break;
        case LINK_BASE_TAG:               FPRINTF(context, STDERR, "base"); break;
        case LINK_CONSTRUCTION_TAG:       FPRINTF(context, STDERR, "construction(%s) ", s->stored.descriptor->sort->constructorNames[s->stored.descriptor->sortoffset]); break;
        case LINK_NAMED_PROPERTY_TAG:     FPRINTF(context, STDERR, "named(%s) ", s->stored.string); break;
        case LINK_VARIABLE_PROPERTY_TAG:  FPRINTF(context, STDERR, "variable(%s) ", s->stored.variable->name); break;
        case LINK_STRING_TAG:             FPRINTF(context, STDERR, "string(%s) ", s->stored.string); break;
        case LINK_FIRST_BINDER_TAG:       FPRINTF(context, STDERR, "binders(%s) ", s->stored.variable->name); break;
        case LINK_FOLLOWING_BINDER_TAG:   FPRINTF(context, STDERR, "(%s) ", s->stored.variable->name); break;
        }
    }
    FPRINTF(context, STDERR,"]\n");
}
#endif

/* Main entry points. */

int loadTerm(Sink sink, char *name)
{
    FILE *fp = FOPEN_IN(sink->context, name);
    if (!fp)
    {
        ERRORF(sink->context, Scan, "Cannot read file %s (%s)\n", name, strerror(errno));
        return 0;
    }
    readTerm(sink, fp);
    return 1;
}

int readTerm(Sink sink, FILE *input)
{
    yyscan_t scanner;
    crsx_yylex_init(&scanner);
    crsx_yyset_in(input, scanner);
    StateLink state = makeBase(sink);
    crsx_yyset_extra(state, scanner);
#ifdef FLEX_DEBUG
    crsx_yyset_debug(1, scanner);
#endif
    int result = crsx_yylex(scanner);
    crsx_yylex_destroy(scanner);
    popBase(&state);
    return result;
}

int scanTerm(Sink sink, const char* text)
{
    yyscan_t scanner;
    crsx_yylex_init(&scanner);
    // crsx_yy_scan_string(text, scanner);
    StateLink state = makeBase(sink);
    crsx_yyset_extra(state, scanner);
    crsx_yy_scan_string(text, scanner);
#ifdef FLEX_DEBUG
    crsx_yyset_debug(1, scanner);
#endif
    int result = crsx_yylex(scanner);
    crsx_yylex_destroy(scanner);
    popBase(&state);
    return result;
}

/* Memory management. */

void *crsx_yyalloc(yy_size_t bytes, yyscan_t scanner)
{
    if (!scanner)
        return malloc(bytes); /* no context yet */
    else
        return ALLOCATE(crsx_yyget_extra(scanner)->sink->context, bytes);
}

void *crsx_yyrealloc(void *ptr, yy_size_t bytes, yyscan_t scanner)
{
    return REALLOCATE(crsx_yyget_extra(scanner)->sink->context, ptr, bytes);
}

void crsx_yyfree(void *ptr, yyscan_t scanner)
{
    if (ptr == scanner)
        free(ptr); /* malloc'd */
    else
        FREE(crsx_yyget_extra(scanner)->sink->context, ptr);
}
