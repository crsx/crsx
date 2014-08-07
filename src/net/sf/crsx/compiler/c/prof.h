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
void crsxpBeforeSubstitution(Context context);

/** Called after meta substitute */
void crsxpAfterSubstitution(Context context);


extern void printProfiling(Context context);
extern void printMetasubstituteRecord(Context context, ProfMetaSubstitute c);
extern void profAddStepFunction(Context context, char* functionName);
extern void pIncMetaCountFunction(Context context, char* functionName, long memuse);



#endif /* PROF_H_ */
