// Copyright (c) 2014 IBM Corporation.
#include "prof.h"
#include "crsx.h"

#ifdef CRSX_ENABLE_PROFILING

#include <sys/time.h>
#include <sys/resource.h>

// Mac does not have clock_gettime
#ifdef __MACH__
#include <mach/mach_time.h>
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 0
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
#else
#include <time.h>
#endif

// Global profiler state.

char* profStepStack[16384];
unsigned profStepStackSize;
long profMemuseMetaSubstitutes; // in KB
long pMetaSubstituteCount; // Count total number of meta substitutions
long pCallCount; // Count total number of simple meta substitutions
long pFVCount; // Count total number of free variable sets
long pFVMaxSize; // Maximum free variable sets size
ProfMetaSubstitute profLargeMetaSubstitutes;
ProfBufferCopy profLargeBufferCopy;
ProfFunctionEntry profFunctions[16384]; // use array for sorting
unsigned profFunctionsCount = 0;
long pPeakTermSize, pNSPeakTermSize;
long pPeakTermMemuse, pNSPeakTermMemuse; // in Bytes
long pDuplicateMemuse;
size_t pMarker = 0;
long pStepCount;
time_t pTime; // Keep track of time
int pSampleRate; // Random term size sample rate
struct timespec pStartTime;
struct timespec pNanoTime;

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
        profStepStackSize = 0;
        profFunctionsCount = 0;
        profMemuseMetaSubstitutes = 0l;
        pPeakTermSize = pNSPeakTermSize = 0l;
        pPeakTermMemuse = pNSPeakTermMemuse = 0l;
        pDuplicateMemuse = 0l;
        pStepCount = 0l;
        pMetaSubstituteCount = 0l;
        pCallCount = 0l;
        pFVCount = 0l;
        pFVMaxSize = 0l;
        time(&pTime);
        clock_gettime(CLOCK_REALTIME, &pStartTime);
        pSampleRate = (rand() % 500) + 500;
        crsxpMetaCount = makeHS2(context, 8, NULL);
    }
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

        int i = 0;
        while (i < profFunctionsCount)
        {
            FREE(context, profFunctions[i]);
            profFunctions[i] = NULL;
            i++;
        }
    }
}

void crsxpBeforeStep(Context context, Term term)
{
    if (context->profiling)
    {
        profStepStack[profStepStackSize++] = SYMBOL(term);
        profAddStepFunction(context, SYMBOL(term));
        crsxpPrintStats(context, term);
        ++pStepCount;
    }
}

void crsxpAfterStep(Context context)
{
    if (context->profiling)
    {
        profStepStackSize--;
    }
}

void crsxpBeforeSubstitution(Context context, Term term)
{
    if (context->profiling)
    {
        getrusage(RUSAGE_SELF, &crsxpSubstitutionUse);

        clock_gettime(CLOCK_REALTIME, &pNanoTime);

    }
}

static struct timespec diff(struct timespec start, struct timespec end)
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

void crsxpAfterSubstitution(Context context)
{
    if (context->profiling)
    {
        pMetaSubstituteCount++;

        struct rusage uafter;
        getrusage(RUSAGE_SELF, &uafter);

        long memuse = uafter.ru_maxrss - crsxpSubstitutionUse.ru_maxrss;
        if (memuse > 50)
            PRINTF(context, "\n%-8ld# large meta substitution size: %ldKb",
                    pStepCount, memuse);

        struct timespec nanoTime;
        clock_gettime(CLOCK_REALTIME, &nanoTime);
        struct timespec d = diff(pNanoTime, nanoTime);
        long dl = d.tv_sec * 1000000000 + d.tv_nsec;

        //const char* symbol = (const char*)SYMBOL(term);
        const char* symbol = profStepStack[profStepStackSize - 1];
        if (symbol)
        {
            long* count = getValuePtrHS2(crsxpMetaCount, symbol);
            if (!count)
            {
                count = (long*) malloc(sizeof(long));
                (*count) = dl;
                addValueHS2(context, crsxpMetaCount, symbol, (void*) count);
            } else
                (*count) += dl;

            //PRINTF(context, "\n%-8ld# meta substitution for %s : %ld", pStepCount, symbol, (*count));
        }
    }
}

void crsxpBeforeCall(Context context)
{
    if (context->profiling)
    {
        pCallCount++;
    }
}

void crsxpAfterCall(Context context)
{
//    if (context->profiling)
//    {
//    }
}

void crsxpVSCreated(Context context)
{
    if (context->profiling)
    {
        pFVCount++;
    }
}
void crsxpVSAdded(Context context, Hashset set)
{
    if (context->profiling)
    {
        if (set->nitems > pFVMaxSize)
            pFVMaxSize = set->nitems;
    }
}

void profAddStepFunction(Context context, char* name)
{
    if (context->profiling)
    {
        if (profFunctionsCount >= 16384)
            return;

        char* stem = name;

        int i = 0;
        while (i < profFunctionsCount)
        {

            if (strcmp(profFunctions[i]->name, stem) == 0)
                break;
            i++;
        }

        if (i < profFunctionsCount)
        {
            profFunctions[i]->count++;
        } else
        {
            ProfFunctionEntry record = ALLOCATE(context,
                    sizeof(struct _ProfFunctionEntry));
            record->name = stem;
            record->count = 1;
            record->metaCount = 0;
            record->metaMemuse = 0;
            profFunctions[profFunctionsCount++] = record;
        }
    }
}

void pIncMetaCountFunction(Context context, char* name, long memuse)
{
    if (context->profiling)
    {
        // Search for existing entry
        // function name are of the form R4a-Form-let2$XX

        //    char* d = strchr(name, '$');
        //    char* stem = name;
        //    if (d)
        //    {
        //        int len = strlen(name) - strlen(d);
        //        stem = ALLOCATE(context, len + 1);
        //        memcpy(stem, name, len);
        //        stem[len] = '\0';
        //    }
        char * stem = name;

        int i = 0;
        while (i < profFunctionsCount)
        {

            if (strcmp(profFunctions[i]->name, stem) == 0)
            {
                break;
            }
            i++;
        }

        if (i < profFunctionsCount)
        {
            profFunctions[i]->metaCount++;
            profFunctions[i]->metaMemuse += memuse;
            //        if (d)
            //           FREE(context, stem);
        }
    }
}

static int profEntryCmp(const void* p1, const void* p2)
{

    ProfFunctionEntry e1 = *(ProfFunctionEntry*) p1;
    ProfFunctionEntry e2 = *(ProfFunctionEntry*) p2;

    if (e1->count == e2->count)
        return 0;
    if (e1->count > e2->count)
        return -1;
//        if (e1->metaCount == e2->metaCount)
//            return 0;
//        if (e1->metaCount > e2->metaCount)
//            return -1;
//        if (e1->metaMemuse == e2->metaMemuse)
//               return 0;
//           if (e1->metaMemuse > e2->metaMemuse)
//               return -1;

    return 1;
}

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

void printProfiling(Context context)
{
    if (context->profiling)
    {
        if (profLargeMetaSubstitutes || profLargeBufferCopy)
        {
            PRINTF(context, "Profiling information...");

            if (profLargeMetaSubstitutes)
            {
                PRINTF(context, "\n\nReport large meta substitutes...\n");

                ProfMetaSubstitute c = profLargeMetaSubstitutes;
                while (c)
                {
                    PRINTF(context, "\n===========================");
                    PRINTF(context, "\n  Large meta substitute");
                    printMetasubstituteRecord(context, c);
                    c = c->next;

                    PRINTF(context, "\n");
                }
            }

            if (profLargeBufferCopy)
            {
                PRINTF(context, "\n\nReport large environment copy...\n");

                ProfBufferCopy b = profLargeBufferCopy;
                while (b)
                {
                    PRINTF(context, "\n===========================");
                    PRINTF(context, "\n  Large environment copy");
                    PRINTF(context, "\n  size      : %u", b->size);
                    PRINTF(context, "\n  backtrace : ");

                    int i = b->backtraceSize - 1;
                    while (i >= 0)
                    {
                        PRINTF(context, "\n    %s", b->backtrace[i]);
                        i--;
                    }

                    b = b->next;

                    PRINTF(context, "\n");
                }
            }
        }

        PRINTF(context,
                "\n\nReport function count  (call count) (meta count) (memuse, M)...\n");

        qsort(profFunctions, profFunctionsCount, sizeof(ProfFunctionEntry),
                profEntryCmp);

        size_t i = 0;
        while (i < 50 && i < profFunctionsCount)
        {
            PRINTF(context, "\n%-50s : %10d %10d %5ld", profFunctions[i]->name,
                    profFunctions[i]->count, profFunctions[i]->metaCount,
                    profFunctions[i]->metaMemuse / 1024);
            i++;
        }

        PRINTF(context,
                "\n\nReport meta count  (step name) (time ns) (percent time) ...\n");

        Pair* counts = toArrayHS2(context, crsxpMetaCount);
        qsort(counts, crsxpMetaCount->size, sizeof(Pair), pairEntryCmp);

        struct timespec endTime;
        clock_gettime(CLOCK_REALTIME, &endTime);
        struct timespec d = diff(pStartTime, endTime);
        double dl = (double) (d.tv_sec * 1000000000 + d.tv_nsec);

        if (counts)
        {
            for (i = 0; i < crsxpMetaCount->size && i < 50; i++)
            {
                long time = *(long*) counts[i]->value;
                double percent = time / dl;
                PRINTF(context, "\n%-50s : %10ld %2.2f",
                        (const char* ) counts[i]->key, time, percent);
            }
        }

        PRINTF(context, "\nTotal memory used by meta substitution: %ldM",
                (profMemuseMetaSubstitutes / 1024));
//        PRINTF(context, "\nPeak term size (sample)          : %ld nodes",
//                pPeakTermSize);
        //PRINTF(context, "\nPeak term memory use (sample)    : %ldM\n",
        //       (pPeakTermMemuse / 1024 / 1024));
        //PRINTF(context, "\nMemory use due to Duplicate      : %ldM\n", (pDuplicateMemuse / 1024));
        PRINTF(context, "\n%-50s : %ld", "Full meta substitution count",
                pMetaSubstituteCount);
        PRINTF(context, "\n%-50s : %ld", "Shallow meta substitution count",
                pCallCount);
        PRINTF(context, "\n%-50s : %ld", "Free variable set count", pFVCount);
        PRINTF(context, "\n%-50s : %ld", "Free variable set maximum size",
                pFVMaxSize);

    }
}

void printMetasubstituteRecord(Context context, ProfMetaSubstitute c)
{
    PRINTF(context, "\n  size               : %u", c->size);
    PRINTF(context, "\n  term size          : %u", c->termSize);
    PRINTF(context, "\n  environment size   : %u", c->envSize);
    PRINTF(context, "\n  normal form        : %s", (c->nf ? "no" : "yes"));
    PRINTF(context, "\n  memory use         : %ldM", (c->memuse / 1024));
    PRINTF(context, "\n  backtrace          : ");

    int i = c->backtraceSize - 1;
    while (i >= 0)
    {
        PRINTF(context, "\n    %s", c->backtrace[i]);
        i--;
    }
}

static void termSize(Term term, long* size, long* memuse, int sharing);

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

static void termSize2(Term term, long* size, long* memuse, int sharing);

// size    : total number of nodes, excluding property links.
// memuse  : total memory use.
// sharing : when true, account for shared terms.
static void termSize(Term term, long* size, long* memuse, int sharing)
{
    pMarker++;
    termSize2(term, size, memuse, sharing);
}

static void termSize2(Term term, long* size, long* memuse, int sharing)
{
    if (!sharing && term->marker == pMarker)
        return;

    term->marker = pMarker;

    (*size)++;

    if (IS_VARIABLE_USE(term))
    {
        Variable v = VARIABLE(term);

        (*memuse) += sizeof(struct _Variable);
        (*memuse) += strlen(v->name) + 1;
    } else
    {
        (*memuse) += sizeof(struct _Construction);

        Construction construction = asConstruction(term);
        if (construction->fvs && construction->fvs != AllFreeVariables
                && (sharing || construction->fvs->marker != pMarker))
        {
            construction->fvs->marker = pMarker;

            (*memuse) += sizeof(struct _Hashset);
            (*memuse) += construction->fvs->capacity * sizeof(size_t);
        }
        if (construction->nfvs && construction->nfvs != AllFreeVariables
                && (sharing || construction->nfvs->marker != pMarker))
        {
            construction->nfvs->marker = pMarker;

            (*memuse) += sizeof(struct _Hashset);
            (*memuse) += construction->nfvs->capacity * sizeof(size_t);
        }
        if (construction->vfvs && construction->vfvs != AllFreeVariables
                && (sharing || construction->vfvs->marker != pMarker))
        {
            construction->vfvs->marker = pMarker;

            (*memuse) += sizeof(struct _Hashset);
            (*memuse) += construction->vfvs->capacity * sizeof(size_t);
        }

        if (construction->properties)
        {
            NamedPropertyLink link;

            for (link = construction->properties->namedProperties; link; link =
                    link->link)
            {
                if (!sharing && link->marker == pMarker)
                    break;

                link->marker = pMarker;

                if (link->name)
                {
                    termSize2(link->u.term, size, memuse, sharing);
                } else
                {
                    (*memuse) += memoryUsedHS2(link->u.propset);
                }

                (*memuse) += sizeof(struct _NamedPropertyLink);
            }
        }

        if (construction->properties)
        {
            VariablePropertyLink link;
            for (link = construction->properties->variableProperties; link;
                    link = link->link)
            {
                if (!sharing && link->marker == pMarker)
                    break;

                if (link->variable)
                {
                    termSize2(link->u.term, size, memuse, sharing);

                    (*memuse) += sizeof(struct _Variable);
                } else
                {
                    (*memuse) += memoryUsedHS2(link->u.propset);
                }

                (*memuse) += sizeof(struct _VariablePropertyLink);
            }
        }

        const int arity = ARITY(term);
        int i;
        for (i = 0; i < arity; ++i)
        {
            termSize2(SUB(term, i), size, memuse, sharing);
        }
    }
}

#else

void crsxpInit(Context context)
{}
void crsxpDestroy(Context context)
{}
void crsxpBeforeStep(Context context, Term term)
{}
void crsxpAfterStep(Context context)
{}
void crsxpBeforeSubstitution(Context context)
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
void printProfiling(Context context)
{}
void printMetasubstituteRecord(Context context, ProfMetaSubstitute c)
{}
void profAddStepFunction(Context context, char* functionName)
{}
void pIncMetaCountFunction(Context context, char* functionName, long memuse)
{}

#endif
