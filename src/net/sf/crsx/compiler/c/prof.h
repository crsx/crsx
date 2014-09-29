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

void crsxpInstrumentEnter(Context context, Variable id, char* name);
void crsxpInstrumentExit(Context context, Variable id);

// Merge back-traces from raw profiling information
void crsxpMergeBacktrace(Context context, FILE* file);


extern void printProfiling(Context context);
extern void pIncMetaCountFunction(Context context, char* functionName, long memuse);



#endif /* PROF_H_ */
