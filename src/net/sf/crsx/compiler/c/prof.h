// Copyright (c) 2014 IBM Corporation.

/**
 * Various profiling utilities
 */

#ifndef PROF_H_
#define PROF_H_

#include "crsx.h"
#include <sys/time.h>

#ifdef __MACH__

#define CLOCK_PROCESS_CPUTIME_ID 0
#define CLOCK_MONOTONIC 0
#define CLOCK_MONOTONIC_COARSE 0

extern int clock_gettime(int clk_id, struct timespec *t);
#else
#include <time.h>
#endif

extern struct timespec diff(struct timespec start, struct timespec end);


#ifdef CRSX_ENABLE_PROFILING


#ifndef CRSXLARGEMS
#define CRSXLARGEMS 160000
#endif

#ifndef CRSXLARGECOPY
#define CRSXLARGECOPY 10000
#endif

#endif

extern void crsxpInit(Context context);
extern void crsxpDestroy(Context context);

/** Called before executing a step function */
extern void crsxpBeforeStep(Context context, Term term);

/** Called after executing a step function */
extern void crsxpAfterStep(Context context);

/** Called before strictly evaluating a step in tail recursive position */
extern void crsxpNextStep(Context context, char* name);

/** Called before meta substitute */
extern void crsxpBeforeSubstitution(Context context, Term term);

/** Called after meta substitute */
extern void crsxpAfterSubstitution(Context context);

/** Called before call */
extern void crsxpBeforeCall(Context context);

/** Called after call */
extern void crsxpAfterCall(Context context);

extern void crsxpBeforePropagateFV(Context context);
extern void crsxpAfterPropagateFV(Context context);

/** Called when a variable set is created or copied */
extern void crsxpVSCreated(Context context);
extern void crsxpVSRehashed(Context context);

/** Called when a variable set is freed */
extern void crsxpVSFreed(Context context);

/** Called when a variable is added to a variable set */
extern void crsxpVSAdded(Context context, Hashset set);

extern void crsxpVSContains(Hashset set);

/** Called before allocating a new named properties */
extern void crsxpAllocateNamedProperty(Context context, NamedPropertyLink next);

/** Called before releasing pools */
extern void crsxpReleasePools(Context context);

extern void crsxpBeforeMergeProperties(Context context);
extern void crsxpAfterMergeProperties(Context context);
extern void crsxpNamedPropertiesMerged(Context context, int count);

extern void crsxpMakeVariable(Context context);
extern void crsxpFreeVariable(Context context);

extern void crsxpMakeConstruction(Context context);
extern void crsxpFreeConstruction(Context context);

extern void crsxpInstrumentEnter(Context context, Variable id, char* name);
extern void crsxpInstrumentExit(Context context, Variable id);

// Merge back-traces from raw profiling information
extern void crsxpMergeBacktrace(Context context, FILE* file);


extern void printProfiling(Context context);
extern void pIncMetaCountFunction(Context context, char* functionName, long memuse);



#endif /* PROF_H_ */
