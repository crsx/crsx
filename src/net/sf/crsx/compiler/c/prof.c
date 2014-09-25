// Copyright (c) 2014 IBM Corporation.
#include "prof.h"
#include "crsx.h"

#include <sys/resource.h>

// Mac does not have clock_gettime
#ifdef __MACH__
#include <mach/mach_time.h>
int clock_gettime(int clk_id, struct timespec *t)
{
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);
    uint64_t time;
    time = mach_absolute_time();
    double nseconds = ((double) time * (double) timebase.numer)
            / ((double) timebase.denom);
    double seconds = ((double) time * (double) timebase.numer)
            / ((double) timebase.denom * 1e9);
    t->tv_sec = seconds;
    t->tv_nsec = nseconds;
    return 0;
}
#endif


struct timespec diff(struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ((end.tv_nsec - start.tv_nsec) < 0)
    {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else
    {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}

#ifdef CRSX_ENABLE_PROFILING


typedef struct _ProfFunctionEntry *ProfFunctionEntry;

struct _ProfFunctionEntry {
    long count; // number of time function has been called
    long time; // Accumulated time
};


// Global profiler state.

long profMemuseMetaSubstitutes; // in KB
long pMetaSubstituteCount; // Count total number of meta substitutions
long pAccuMetaTime; // Time spent doing meta application
long pAccuMergeTime; // Time spent doing meta application
long pAccuPropagateTime; // Time spent propagating free vars
long pMergeCount;
long pCallCount; // Count total number of simple meta substitutions
long pFVTotalCount; // Count total number of free variable sets
long pFVCount; // Current number of free variable sets
long pFVMaxSize; // Maximum free variable sets size
long pFVUsedCount; // Count total number of free variable set actually used
long pFVRehashCount; // Count total number of time FV set has been rehashed
long pVarCount; // Current number of live variables
long pPeakVarCount; // Peak number of live variables
long pTotalConsCount; // Total number of construction
long pConsCount; // Current number of construction
long pAccuStepTime;

long pPeakTermSize, pNSPeakTermSize;
long pPeakTermMemuse, pNSPeakTermMemuse; // in Bytes
long pDuplicateMemuse;
size_t pMarker = 0;
long pStepCount;
time_t pTime; // Keep track of time
int pSampleRate; // Random term size sample rate
struct timespec pStartTime;
struct timespec pNanoTime;
struct timespec pMergeClock;
struct timespec pPropagateClock;
struct timespec pStepClock;
size_t pKeyPoolSize;
char* pStepName; // Current step function
Hashset2 pSteps; // Track time/count in step


// Measure memory use after computation.
struct rusage crsxpComputeUse;

// Measure memory use during substitution.
struct rusage crsxpSubstitutionUse;

// Count number of meta-substitute per symbol
Hashset2 crsxpMetaCount;

static void crsxpPrintStats(Context context, Term term);

void crsxpInit(Context context)
{
    if (context->profiling)
    {
        getrusage(RUSAGE_SELF, &crsxpComputeUse);
        profMemuseMetaSubstitutes = 0l;
        pPeakTermSize = pNSPeakTermSize = 0l;
        pPeakTermMemuse = pNSPeakTermMemuse = 0l;
        pDuplicateMemuse = 0l;
        pStepCount = 0l;
        pMetaSubstituteCount = 0l;
        pCallCount = 0l;
        pFVTotalCount = 0l;
        pFVCount = 0l;
        pFVUsedCount = 0l;
        pFVRehashCount = 0l;
        pFVMaxSize = 0l;
        pVarCount = 0l;
        pPeakVarCount = 0l;
        pTotalConsCount = 0l;
        pConsCount = 0l;
        time(&pTime);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &pStartTime);
        pSampleRate = (rand() % 500) + 500;
        crsxpMetaCount = makeHS2(context, 8, NULL, equalsChars, hashChars);
        pSteps = makeHS2(context, 16, NULL, equalsChars, hashChars);
        pAccuMetaTime = 0l;
        pAccuMergeTime = 0l;
        pAccuPropagateTime = 0l;
        pMergeCount = 0;
        pAccuStepTime = 0;
    }
}


static long nano2ms(long nano)
{
    return nano / 1000000;
}

void crsxpDestroy(Context context)
{
    if (context->profiling)
    {
        printProfiling(context);

        struct rusage usageafter;
        getrusage(RUSAGE_SELF, &usageafter);
        long use = (usageafter.ru_maxrss - crsxpComputeUse.ru_maxrss) / 1024.0;
        PRINTF(context, "\nmemory use: %ldM\n", use);
    }
}

void crsxpBeforeStep(Context context, Term term)
{
    if (context->profiling)
    {
        pStepName = SYMBOL(term);
        crsxpPrintStats(context, term);
        ++pStepCount;

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &pStepClock);
    }
}

void crsxpAfterStep(Context context)
{
    if (context->profiling)
    {
        struct timespec nanoTime;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &nanoTime);
        struct timespec d = diff(pStepClock, nanoTime);
        long dl = d.tv_sec * 1000000000 + d.tv_nsec;
        pAccuStepTime += dl;

        ProfFunctionEntry entry = getValueHS2(pSteps, (const void*) pStepName);
        if (!entry)
        {
            entry = ALLOCATE(context, sizeof(struct _ProfFunctionEntry));
            entry->count = 0;
            entry->time = 0;
            addValueHS2(context, pSteps, (const void*) pStepName, (void*) entry);
        }
        entry->count ++;
        entry->time += dl;
    }
}

void crsxpBeforeSubstitution(Context context, Term term)
{
    if (context->profiling)
    {
        getrusage(RUSAGE_SELF, &crsxpSubstitutionUse);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &pNanoTime);
    }
}
void crsxpAfterSubstitution(Context context)
{
    if (context->profiling)
    {
        pMetaSubstituteCount++;

        struct rusage uafter;
        getrusage(RUSAGE_SELF, &uafter);

        long memuse = uafter.ru_maxrss - crsxpSubstitutionUse.ru_maxrss;
        if (memuse > 300)
            PRINTF(context, "\n%-8ld# large meta substitution size: %ldKb",
                    pStepCount, memuse);

        struct timespec nanoTime;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &nanoTime);
        struct timespec d = diff(pNanoTime, nanoTime);
        long dl = d.tv_sec * 1000000000 + d.tv_nsec;

        const char* symbol = pStepName;
        if (symbol)
        {
            long* count = (long*) getValueHS2(crsxpMetaCount,
                    (const void*) symbol);
            if (!count)
            {
                count = (long*) malloc(sizeof(long));
                (*count) = dl;
                addValueHS2(context, crsxpMetaCount, (const void*) symbol,
                        (void*) count);
            } else
                (*count) += dl;
        }

        pAccuMetaTime += dl;
    }
}

void crsxpBeforePropagateFV(Context context)
{
    if (context->profiling)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &pPropagateClock);
    }
}

void crsxpAfterPropagateFV(Context context)
{
    if (context->profiling)
    {
        struct timespec nanoTime;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &nanoTime);
        struct timespec d = diff(pPropagateClock, nanoTime);
        long dl = d.tv_sec * 1000000000 + d.tv_nsec;

        pAccuPropagateTime += dl;
    }
}

void crsxpBeforeCall(Context context)
{
    pCallCount++;
}

void crsxpAfterCall(Context context)
{
//    if (context->profiling)
//    {
//    }
}

void crsxpVSCreated(Context context)
{
    pFVCount++;
    pFVTotalCount++;
}

void crsxpVSFreed(Context context)
{
    pFVCount--;
}

void crsxpVSAdded(Context context, Hashset set)
{
    if (context->profiling)
    {
        if (set->nitems > pFVMaxSize)
            pFVMaxSize = set->nitems;
    }
}

void crsxpVSContains(Hashset set)
{
    if (!set->marker)
    {
        pFVUsedCount++;
        set->marker = 1;
    }
}

void crsxpVSRehashed(Context context)
{
    pFVRehashCount++;
}

void crsxpReleasePools(Context context)
{
    if (context->profiling)
    {
        pKeyPoolSize = 0;
        if (context->keyPool)
            pKeyPoolSize = context->keyPool->size;
    }
}

void crsxpBeforeMergeProperties(Context context)
{
    if (context->profiling)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &pMergeClock);
    }
}

void crsxpAfterMergeProperties(Context context)
{
    if (context->profiling)
    {
        struct timespec nanoTime;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &nanoTime);
        struct timespec d = diff(pMergeClock, nanoTime);
        long dl = d.tv_sec * 1000000000 + d.tv_nsec;

        pAccuMergeTime += dl;
    }
}
void crsxpNamedPropertiesMerged(Context context, int count)
{
    if (context->profiling)
    {
        pMergeCount += count;
    }
}

void crsxpMakeVariable(Context context)
{
    if (context->profiling)
    {
        pVarCount++;
        if (pVarCount > pPeakVarCount)
            pPeakVarCount = pVarCount;
    }
}
void crsxpFreeVariable(Context context)
{
    if (context->profiling)
    {
        pVarCount--;
    }
}

void crsxpMakeConstruction(Context context)
{
    if (context->profiling)
    {
        pConsCount++;
        pTotalConsCount++;
    }
}

void crsxpFreeConstruction(Context context)
{
    if (context->profiling)
    {
        pConsCount--;
    }

}

void profAddStepFunction(Context context, char* name)
{
    if (context->profiling)
    {
        pStepName = name;
//        if (profFunctionsCount >= 16384)
//            return;
//
//        char* stem = name;
//
//        int i = 0;
//        while (i < profFunctionsCount)
//        {
//
//            if (strcmp(profFunctions[i]->name, stem) == 0)
//                break;
//            i++;
//        }
//
//        if (i < profFunctionsCount)
//        {
//            profFunctions[i]->count++;
//        } else
//        {
//            ProfFunctionEntry record = ALLOCATE(context,
//                    sizeof(struct _ProfFunctionEntry));
//            record->name = stem;
//            record->count = 1;
//            record->metaCount = 0;
//            record->metaMemuse = 0;
//            profFunctions[profFunctionsCount++] = record;
//        }
    }
}
//
//void pIncMetaCountFunction(Context context, char* name, long memuse)
//{
//    if (context->profiling)
//    {
//        // Search for existing entry
//        // function name are of the form R4a-Form-let2$XX
//
//        //    char* d = strchr(name, '$');
//        //    char* stem = name;
//        //    if (d)
//        //    {
//        //        int len = strlen(name) - strlen(d);
//        //        stem = ALLOCATE(context, len + 1);
//        //        memcpy(stem, name, len);
//        //        stem[len] = '\0';
//        //    }
//        char * stem = name;
//
//        int i = 0;
//        while (i < profFunctionsCount)
//        {
//
//            if (strcmp(profFunctions[i]->name, stem) == 0)
//            {
//                break;
//            }
//            i++;
//        }
//
//        if (i < profFunctionsCount)
//        {
//            profFunctions[i]->metaCount++;
//            profFunctions[i]->metaMemuse += memuse;
//            //        if (d)
//            //           FREE(context, stem);
//        }
//    }
//}
//
//static int profEntryCmp(const void* p1, const void* p2)
//{
//
//    ProfFunctionEntry e1 = *(ProfFunctionEntry*) p1;
//    ProfFunctionEntry e2 = *(ProfFunctionEntry*) p2;
//
//    if (e1->count == e2->count)
//        return 0;
//    if (e1->count > e2->count)
//        return -1;
////        if (e1->metaCount == e2->metaCount)
////            return 0;
////        if (e1->metaCount > e2->metaCount)
////            return -1;
////        if (e1->metaMemuse == e2->metaMemuse)
////               return 0;
////           if (e1->metaMemuse > e2->metaMemuse)
////               return -1;
//
//    return 1;
//}

static int pairEntryCmp(const void* p1, const void* p2)
{
    Pair pair1 = *(Pair*) p1;
    Pair pair2 = *(Pair*) p2;

    long value1 = *((long*) pair1->value);
    long value2 = *((long*) pair2->value);

    if (value1 == value2)
        return 0;
    if (value1 > value2)
        return -1;
    return 1;
}


static int stepPairEntryCmp(const void* p1, const void* p2)
{
    Pair pair1 = *(Pair*) p1;
    Pair pair2 = *(Pair*) p2;

    ProfFunctionEntry value1 = (ProfFunctionEntry) pair1->value;
    ProfFunctionEntry value2 = (ProfFunctionEntry) pair2->value;

    if (value1->time == value2->time)
        return 0;
    if (value1->time > value2->time)
        return -1;
    return 1;
}



void printProfiling(Context context)
{
    if (context->profiling)
    {
        struct timespec endTime;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endTime);
        struct timespec d = diff(pStartTime, endTime);
        long dl = d.tv_sec * 1000000000l + d.tv_nsec;


        PRINTF(context,
                "\n\nStep Function Report (step name) (call count) (time ms) (percent time)\n");
        PRINTF(context,
                "========================================================");

        Pair* steps = toArrayHS2(context, pSteps);
        if (steps)
        {
            qsort(steps, pSteps->size, sizeof(Pair), stepPairEntryCmp);

            size_t i;
            for (i = 0; i < pSteps->size && i < 50; i++)
            {
                long time = ((ProfFunctionEntry) steps[i]->value)->time;
                double percent = (time / (double) dl) * 100.0;
                PRINTF(context, "\n%-50s : %8ld %10ld %2.2f%%",
                        (const char* ) steps[i]->key,
                        ((ProfFunctionEntry) steps[i]->value)->count,
                        nano2ms(time), percent);
            }
        }

        PRINTF(context,
                "\n\nMeta Substitution Report  (step name) (time ms) (percent time) ...\n");
        PRINTF(context,
                "==================================================================");

        Pair* counts = toArrayHS2(context, crsxpMetaCount);
        if (counts)
        {
            qsort(counts, crsxpMetaCount->size, sizeof(Pair), pairEntryCmp);

            size_t i;
            for (i = 0; i < crsxpMetaCount->size && i < 50; i++)
            {
                long time = *(long*) counts[i]->value;
                double percent = (time / (double) dl) * 100.0;
                PRINTF(context, "\n%-50s : %10ld %2.2f%%",
                        (const char* ) counts[i]->key,
                        (long ) (time / 1000000.0), percent);
            }
        }

        PRINTF(context, "\n===\n\n%-50s : %ldM",
                "Total memory used by meta substitution",
                (profMemuseMetaSubstitutes / 1024));
        PRINTF(context, "\n%-50s : %ldms(%2.2f%%)",
                "Total time spent in meta substitution", nano2ms(pAccuMetaTime),
                (pAccuMetaTime / (double ) dl) * 100.0);

//        PRINTF(context, "\nPeak term size (sample)          : %ld nodes",
//                pPeakTermSize);
        //PRINTF(context, "\nPeak term memory use (sample)    : %ldM\n",
        //       (pPeakTermMemuse / 1024 / 1024));
        //PRINTF(context, "\nMemory use due to Duplicate      : %ldM\n", (pDuplicateMemuse / 1024));
        PRINTF(context, "\n%-50s : %ld", "Full meta substitution count",
                pMetaSubstituteCount);
        PRINTF(context, "\n%-50s : %ld", "Shallow meta substitution count",
                pCallCount);
        PRINTF(context, "\n%-50s : %ldms (%2.2f%%)",
                "Total time spent merging environments",
                nano2ms(pAccuMergeTime),
                (pAccuMergeTime / (double ) dl) * 100.0);
        PRINTF(context, "\n%-50s : %ld (%2.2f%%)",
                "Total time spent propagating free vars",
                nano2ms(pAccuPropagateTime),
                (pAccuPropagateTime / (double ) dl) * 100.0);
        PRINTF(context, "\n%-50s : %ld", "Total number of properties merged",
                pMergeCount);
        PRINTF(context, "\n%-50s : %ld", "Free variable sets total count",
                pFVTotalCount);
        PRINTF(context, "\n%-50s : %ld", "Free variable sets rehash count",
                pFVRehashCount);
        PRINTF(context, "\n%-50s : %ld", "Current free variable set count",
                pFVCount);
        PRINTF(context, "\n%-50s : %ld (%2.2f%%)",
                "Free variable set usage count", pFVUsedCount,
                (pFVUsedCount / (double ) pFVTotalCount) * 100.0);
        PRINTF(context, "\n%-50s : %ld", "Free variable set maximum size",
                        pFVMaxSize);
        PRINTF(context, "\n%-50s : %ldms (%2.2f%%)", "Time spent in step functions",
                nano2ms(pAccuStepTime), (pAccuStepTime / (double ) dl) * 100.0);
        PRINTF(context, "\n%-50s : %ld", "Current variable count", pVarCount);
        PRINTF(context, "\n%-50s : %ld", "Peak variable count", pPeakVarCount);
        PRINTF(context, "\n%-50s : %ld", "Current construction count",
                pConsCount);
        PRINTF(context, "\n%-50s : %ld", "Total construction count",
                pTotalConsCount);
        PRINTF(context, "\n%-50s : %ld", "String key pool size", pKeyPoolSize);
        PRINTF(context, "\n%-50s : %ldms", "Total time", nano2ms(dl));

    }
}

//
//static void termSize(Term term, long* size, long* memuse, int sharing);

void crsxpPrintStats(Context context, Term term)
{
    if (context->profiling)
    {
        if ((pStepCount % pSampleRate) == 0)
        {
            pSampleRate = (rand() % 500) + 500;
//
//            // Update peak sizes
//            long size = 0;
//            long memuse = 0;
//            termSize(term, &size, &memuse, 0);
//
//            int p = size > pPeakTermSize;
//
//            pPeakTermSize = p ? size : pPeakTermSize;
//            pPeakTermMemuse =
//                    (memuse > pPeakTermMemuse) ? memuse : pPeakTermMemuse;
//
//            long nssize = 0;
//            long nsmemuse = 0;
//            termSize(term, &nssize, &nsmemuse, 1);
//            pNSPeakTermSize =
//                    (nssize > pNSPeakTermSize) ? nssize : pNSPeakTermSize;
//            pNSPeakTermMemuse =
//                    (nsmemuse > pNSPeakTermMemuse) ?
//                            nsmemuse : pNSPeakTermMemuse;

            time_t now;
            time(&now);
            if (difftime(now, pTime) > 1)
            {
                pTime = now;

                printf("\n%-8ld# stats: substitution count: %ld", pStepCount,
                        pMetaSubstituteCount);

                fflush(stdout);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////
// Compute term size without check overhead

//static void termSize2(Term term, long* size, long* memuse, int sharing);
//
//// size    : total number of nodes, excluding property links.
//// memuse  : total memory use.
//// sharing : when true, account for shared terms.
//static void termSize(Term term, long* size, long* memuse, int sharing)
//{
//    pMarker++;
//    termSize2(term, size, memuse, sharing);
//}
//
//static void termSize2(Term term, long* size, long* memuse, int sharing)
//{
//    if (!sharing && term->marker == pMarker)
//        return;
//
//    term->marker = pMarker;
//
//    (*size)++;
//
//    if (IS_VARIABLE_USE(term))
//    {
//        Variable v = VARIABLE(term);
//
//        (*memuse) += sizeof(struct _Variable);
//        (*memuse) += strlen(v->name) + 1;
//    } else
//    {
//        (*memuse) += sizeof(struct _Construction);
//
//        Construction construction = asConstruction(term);
//        if (construction->fvs && construction->fvs != AllFreeVariables
//                && (sharing || construction->fvs->marker != pMarker))
//        {
//            construction->fvs->marker = pMarker;
//
//            (*memuse) += sizeof(struct _Hashset);
//            (*memuse) += construction->fvs->capacity * sizeof(size_t);
//        }
//        if (construction->nfvs && construction->nfvs != AllFreeVariables
//                && (sharing || construction->nfvs->marker != pMarker))
//        {
//            construction->nfvs->marker = pMarker;
//
//            (*memuse) += sizeof(struct _Hashset);
//            (*memuse) += construction->nfvs->capacity * sizeof(size_t);
//        }
//        if (construction->vfvs && construction->vfvs != AllFreeVariables
//                && (sharing || construction->vfvs->marker != pMarker))
//        {
//            construction->vfvs->marker = pMarker;
//
//            (*memuse) += sizeof(struct _Hashset);
//            (*memuse) += construction->vfvs->capacity * sizeof(size_t);
//        }
//
//        if (construction->properties)
//        {
//            NamedPropertyLink link;
//
//            for (link = construction->properties->namedProperties; link; link =
//                    link->link)
//            {
//                if (!sharing && link->marker == pMarker)
//                    break;
//
//                link->marker = pMarker;
//
//                if (link->name)
//                {
//                    termSize2(link->u.term, size, memuse, sharing);
//                } else
//                {
//                    (*memuse) += memoryUsedHS2(link->u.propset);
//                }
//
//                (*memuse) += sizeof(struct _NamedPropertyLink);
//            }
//        }
//
//        if (construction->properties)
//        {
//            VariablePropertyLink link;
//            for (link = construction->properties->variableProperties; link;
//                    link = link->link)
//            {
//                if (!sharing && link->marker == pMarker)
//                    break;
//
//                if (link->variable)
//                {
//                    termSize2(link->u.term, size, memuse, sharing);
//
//                    (*memuse) += sizeof(struct _Variable);
//                } else
//                {
//                    (*memuse) += memoryUsedHS2(link->u.propset);
//                }
//
//                (*memuse) += sizeof(struct _VariablePropertyLink);
//            }
//        }
//
//        const int arity = ARITY(term);
//        int i;
//        for (i = 0; i < arity; ++i)
//        {
//            termSize2(SUB(term, i), size, memuse, sharing);
//        }
//    }
//}

#else

void crsxpInit(Context context)
{}
void crsxpDestroy(Context context)
{}
void crsxpBeforeStep(Context context, Term term)
{}
void crsxpAfterStep(Context context)
{}
void crsxpBeforeSubstitution(Context context, Term term)
{}
void crsxpAfterSubstitution(Context context)
{}
void crsxpBeforeCall(Context context)
{}
void crsxpAfterCall(Context context)
{}
void crsxpVSCreated(Context context)
{}
void crsxpVSAdded(Context context, Hashset set)
{}
void crsxpVSContains(Hashset set)
{}
void crsxpVSFreed(Context context)
{}
void crsxpVSRehashed(Context context)
{}
void crsxpBeforeMergeProperties(Context context)
{}
void crsxpAfterMergeProperties(Context context)
{}
void crsxpNamedPropertiesMerged(Context context, int count)
{}
void printProfiling(Context context)
{}
void profAddStepFunction(Context context, char* functionName)
{}
void pIncMetaCountFunction(Context context, char* functionName, long memuse)
{}
void crsxpReleasePools(Context context)
{}
void crsxpMakeVariable(Context context)
{}
void crsxpFreeVariable(Context context)
{}
void crsxpMakeConstruction(Context context)
{}
void crsxpFreeConstruction(Context context)
{}
void crsxpBeforePropagateFV(Context context)
{}
void crsxpAfterPropagateFV(Context context)
{}

#endif
