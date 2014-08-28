// Copyright (c) 2014 IBM Corporation.

/**
 * Various profiling utilities
 */

#ifndef PROF_H_
#define PROF_H_

#include "crsx.h"

#ifdef CRSX_ENABLE_PROFILING


#ifndef CRSXLARGEMS
#define CRSXLARGEMS 160000
#endif

#ifndef CRSXLARGECOPY
#define CRSXLARGECOPY 10000
#endif

#endif

typedef struct _ProfMetaSubstitute *ProfMetaSubstitute;

struct _ProfMetaSubstitute {
  char** backtrace;
  unsigned backtraceSize;
  unsigned size;
  unsigned termSize;
  unsigned envSize;
  char* term;
  unsigned nf; // Whether the term is NF
  long memuse; // memory use for the substitution
  ProfMetaSubstitute next;
};


typedef struct _ProfBufferCopy *ProfBufferCopy;

struct _ProfBufferCopy {
  char** backtrace;
  unsigned backtraceSize;
  unsigned size;
  ProfBufferCopy next;
};

typedef struct _ProfFunctionEntry *ProfFunctionEntry;

struct _ProfFunctionEntry {
  char* name;
  // TODO: merge backtrace.
  //char** backtrace;
  //unsigned backtraceSize;
  unsigned metaCount; // Number of meta substitution
  long metaMemuse; // metasubstution memuse
  unsigned count; // number of time function has been called
};

extern void crsxpInit(Context context);
extern void crsxpDestroy(Context context);

/** Called before executing a step function */
extern void crsxpBeforeStep(Context context, Term term);

/** Called after executing a step function */
extern void crsxpAfterStep(Context context);

/** Called before meta substitute */
void crsxpBeforeSubstitution(Context context, Term term);

/** Called after meta substitute */
void crsxpAfterSubstitution(Context context);

/** Called before call */
void crsxpBeforeCall(Context context);

/** Called after call */
void crsxpAfterCall(Context context);

void crsxpBeforePropagateFV(Context context);
void crsxpAfterPropagateFV(Context context);

/** Called when a variable set is created or copied */
void crsxpVSCreated(Context context);
void crsxpVSRehashed(Context context);

/** Called when a variable set is freed */
void crsxpVSFreed(Context context);

/** Called when a variable is added to a variable set */
void crsxpVSAdded(Context context, Hashset set);

void crsxpVSContains(Hashset set);


/** Called before releasing pools */
void crsxpReleasePools(Context context);

void crsxpBeforeMergeProperties(Context context);
void crsxpAfterMergeProperties(Context context);
void crsxpNamedPropertiesMerged(Context context, int count);

void crsxpMakeVariable(Context context);
void crsxpFreeVariable(Context context);

void crsxpMakeConstruction(Context context);
void crsxpFreeConstruction(Context context);

extern void printProfiling(Context context);
extern void printMetasubstituteRecord(Context context, ProfMetaSubstitute c);
extern void profAddStepFunction(Context context, char* functionName);
extern void pIncMetaCountFunction(Context context, char* functionName, long memuse);



#endif /* PROF_H_ */
