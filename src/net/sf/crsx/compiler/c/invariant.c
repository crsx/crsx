// Copyright (c) 2014 IBM Corporation.
#include "invariant.h"

// Checking terms.

#ifdef CRSX_ENABLE_CHECK

TermLink occurLink(TermLink link, void* p)
{
    while (link)
    {
        if (link->p == p)
            return link;
        link = link->link;
    }
    return NULL;
}

int addOccur(Context context, TermLink* linkp, void* p)
{
    TermLink ol = linkp ? occurLink(*linkp, p) : NULL;
    if (ol)
    {
        ol->count ++;
        return ol->count;
    }

    TermLink newLink = ALLOCATE(context, sizeof(struct _TermLink));
    newLink->p = p;
    newLink->count = 1;
    newLink->link = *linkp;
    *linkp = newLink;
    return 1;
}

void freeOccur(Context context, TermLink link)
{
    while (link)
    {
        TermLink next = link->link;
        FREE(context, link);
        link = next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
// Check that term is fully formed and return size.

int check(Context context, Term term)
{
    return checkTerm(context, term, 0);
}

int checkTerm(Context context, Term term, int nf)
{
    unsigned envsize = 0;
    return checkTerm2(context, term, 0, &envsize);
}

int checkTerm2(Context context, Term term, int nf, unsigned* envsize)
{
    long memuse = 0;
    return checkTerm3(context, term, 0, 0, envsize, &memuse);
}

int checkTerm3(Context context, Term term, int nf, unsigned depth, unsigned* envsize, long* memuse)
{
    TermLink used = (TermLink)0;
    int result = checkTerm4(context, NULL, 0, term, 0, depth, envsize, memuse, &used);
    freeOccur(context, used);
    return result;
}

int checkTerm4(Context context, Term parent, unsigned index, Term term, int nf, unsigned depth, unsigned* envsize, long* memuse, TermLink* usedp)
{
    if (term->nr <= 0)
    {
         DEBUGF(context, "//CRSX_CHECK: %s HAS NO REFERENCES!\n", SYMBOL(term));
         ASSERT(context, term->nr > 0);
    }

    unsigned oc;
    if (gCheckRef)
    {
        // This is quite expensive without a proper hash set

        // Check proper reference count
        oc = addOccur(context, usedp, (void*) term);
        if (oc > term->nr) {
            DEBUGF(context, "//CRSX_CHECK: %s HAS NOT ENOUGH REFERENCES!\n",
                    SYMBOL(term));
            ASSERT(context, oc <= term->nr);
        }
        if (oc > 1)
            return 0; // Don't traverse twice the same subterm
    }

    int size = 1;

    ASSERT(context, term);
    if (IS_VARIABLE_USE(term))
    {
        Variable v = VARIABLE(term);
        ASSERT(context, v);

        (*memuse) += sizeof(struct _Variable);
        (*memuse) += strlen(v->name) + 1;
    }
    else
    {
        ASSERT(context, IS_CONSTRUCTION(term));
        ASSERT(context, !nf || IS_NF(term));
        Construction construction = asConstruction(term);

        (*memuse) += sizeof(struct _Construction);

        // Check properties.
        int propertiesSize = 0;

#ifdef HSFREEVARS
        if (construction->fvs)
        {
            (*memuse) += sizeof(struct _Hashset);
            (*memuse) += construction->fvs->capacity * sizeof(size_t);
        }
        if (construction->nfvs)
        {
            (*memuse) += sizeof(struct _Hashset);
            (*memuse) += construction->nfvs->capacity * sizeof(size_t);
        }
        if (construction->vfvs)
        {
            (*memuse) += sizeof(struct _Hashset);
            (*memuse) += construction->vfvs->capacity * sizeof(size_t);
        }
#endif
        {
            //int c = 5; // Check only the first 10 properties (ref count won't be accurate)
            NamedPropertyLink link;
            for (link = construction->namedProperties; link; link = link->link)
            {
                ASSERT(context, link->nr > 0);

                if (gCheckRef)
                {
                    oc = addOccur(context, usedp, (void*)link);
                    if (oc > link->nr)
                    {
                        DEBUGF(context, "//CRSX_CHECK: NAMED PROPERTY %s HAS NOT ENOUGH REFERENCES!\n", link->name ? link->name : "MARKER");
                        ASSERT(context, oc <= link->nr);
                    }
                    if (oc > 1)
                        break;
                }

                if (link->name)
                {

                    propertiesSize += checkTerm4(context, NULL, 0, link->u.term, nf, 0, envsize, memuse, usedp);

                    //(*memuse) += strlen(link->name) + 1;
                }
                else
                {
                    propertiesSize += checkPropsHS2(context, link->u.propset, nf, envsize, memuse, usedp);
                }

                (*envsize) ++;
                (*memuse) += sizeof(struct _NamedPropertyLink);

                //if (c-- <= 0)
                //    break;
            }
        }

        {
            VariablePropertyLink link;
            for (link = construction->variableProperties; link; link = link->link)
            {
                ASSERT(context, link->nr > 0);

                if (gCheckRef)
                {
                    oc = addOccur(context, usedp, (void*) link);
                    if (oc > link->nr) {
                        DEBUGF(context,
                                "//CRSX_CHECK: VARIABLE PROPERTY %s HAS NOT ENOUGH REFERENCES!\n",
                                link->variable ? link->variable->name : "MARKER");
                        ASSERT(context, oc <= link->nr);
                    }
                    if (oc > 1)
                        break;
                }
                if (link->variable)
                {

                    propertiesSize += checkTerm4(context, NULL, 0, link->u.term, nf, 0, envsize, memuse, usedp);

                    (*memuse) += sizeof(struct _Variable);
                }
                else
                {
                    propertiesSize += checkPropsHS2(context, link->u.propset, nf, envsize, memuse, usedp);
                }

                (*envsize) ++;
                (*memuse) += sizeof(struct _VariablePropertyLink);
            }
        }
        size += propertiesSize;

        VARIABLESET subfvs = NULL;

        // Check binders and subterms.
      //  if (depth < 5)
        {
            const int arity = ARITY(term);
            int i;
            for (i = 0; i < arity; ++i)
            {
                const int rank = RANK(term,i);
                int j;
                for (j = 0; j < rank; ++j)
                {
                    ASSERT(context, BINDER(term,i,j));
                    ++size;
                }
                size += checkTerm4(context, term, i, SUB(term,i), IS_NF(term), depth + 1, envsize, memuse, usedp);


            }
        }

        //UNLINK_VARIABLESET(context, subfvs);
        if (0)
        {
            if (parent)
            {
                unsigned rank = RANK(parent, index);
                if (rank > 0)
                    subfvs = VARIABLESET_REMOVEALL(context, subfvs, BINDERS(parent, index), rank);

                // Ideally we want the sets to be equal. For now, make sure the term set includes the computed one
                subfvs = VARIABLESET_MINUS(context, subfvs, asConstruction(term)->fvs);
                if (!VARIABLESET_ISEMPTY(subfvs))
                {
                    FPRINTF(context, STDOUT, "ASSERTION FAIL ============\n");
                    VARIABLESET_PRINTF(context, STDOUT, subfvs);
                    FPRINTF(context, STDOUT, "\nTERM ============\n");
                    subfvs = VARIABLESET_MINUS(context, subfvs, asConstruction(term)->fvs);
                    ppt(context, 2, term);
                    ASSERT(context, !subfvs);
                }

            }

            // Quick check properties free vars wrt to term fvs
            VARIABLESET nps = LINK_VARIABLESET(context, asConstruction(term)->nfvs);
            if (!VARIABLESET_ISEMPTY(nps))
            {
                nps = VARIABLESET_MINUS(context, subfvs, asConstruction(term)->fvs);
                if (!VARIABLESET_ISEMPTY(nps))
                {
                    FPRINTF(context, STDOUT, "ASSERTION FAIL ============\n");
                    VARIABLESET_PRINTF(context, STDOUT, nps);
                    FPRINTF(context, STDOUT, "\nTERM ============\n");

                    ppt(context, 2, term);
                    ASSERT(context, !nps);
                }
            }

            nps = LINK_VARIABLESET(context, asConstruction(term)->variableFreeVars);
            if (!VARIABLESET_ISEMPTY(nps))
            {
                nps = VARIABLESET_MINUS(context, subfvs, asConstruction(term)->fvs);
                if (!VARIABLESET_ISEMPTY(nps))
                {
                    FPRINTF(context, STDOUT, "ASSERTION FAIL ============\n");
                    VARIABLESET_PRINTF(context, STDOUT, nps);
                    FPRINTF(context, STDOUT, "\nTERM ============\n");

                    ppt(context, 2, term);
                    ASSERT(context, !nps);
                }
            }
        }


    }
    return size;
}

#else

TermLink occurLink(TermLink link, void* p)
{ return 0; }
int addOccur(Context context, TermLink* linkp, void* p)
{ return 0; };
void freeOccur(Context context, TermLink link)
{};
int checkTerm(Context context, Term term, int nf)
{ return 0;};
int checkTerm2(Context context, Term term, int nf, unsigned* envsize)
{ return 0;};
int checkTerm3(Context context, Term term, int nf, unsigned depth, unsigned* envsize, long* memuse)
{ return 0;};
int checkTerm4(Context context, Term parent, unsigned index, Term term, int nf, unsigned depth, unsigned* envsize, long* memuse, TermLink *usedp)
{ return 0;};


#endif
