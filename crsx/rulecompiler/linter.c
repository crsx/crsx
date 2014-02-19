// Copyright (c) 2010, 2014 IBM Corporation.
// $Id: linter.c,v 3.1 2014/02/07 20:18:10 villardl Exp $

#include "linter.h"

// Intermediate data
typedef struct _LintContext* LintContext;

struct _LintContext {
    Context context;

    Hashset2 bound;     // Bound variables
};

const char* ERR_MSG[4] = {
        "Term has no reference.", "Variable term has no variable.", "Term is not closed.", "Term is not in normal form."
};

// Forward declarations
static int lintTerm(LintContext context, Term parent, unsigned index, Term term, int flags, LinterReport report);

LinterReport lint(Context context, Term term, int flags)
{
    LinterReport report = ALLOCATE(context, sizeof(struct _LinterReport));
    report->valid = 1;
    report->closed = 1;
    report->memuse = 0;

    LintContext lcontext = ALLOCATE(context, sizeof(struct _LintContext));
    lcontext->context = context;

    if (flags & CHECK_CLOSED)
        lcontext->bound = makeHS2(context, 9);

    lintTerm(lcontext, NULL, 0, term, flags, report);

    if (flags & CHECK_CLOSED)
        unlinkHS2(context, lcontext->bound);

    FREE(context, lcontext);

    return report;
}

static int error(Term parent, unsigned index, Term term, int code, LinterReport report)
{
    report->valid = 0;
    report->error = code;
    report->term = parent;
    report->subterm = term;

    return 0;
}

static int checkReferenceCounting(LintContext context, Term parent, unsigned index, Term term, int flags, LinterReport report)
{
    if (term->nr <= 0)
    {
       error(parent, index, term, ERROR_NO_REFERENCE, report);
       return 0;
    }

    return 1;
}

static int lintTerm(LintContext context, Term parent, unsigned index, Term term, int flags, LinterReport report)
{
    if (!checkReferenceCounting(context, parent, index, term, flags, report))
        return 0;

    if (IS_VARIABLE_USE(term))
    {
        Variable v = VARIABLE(term);

        if (!v)
        {
            error(parent, index, term, ERROR_NULL_VARIABLE, report);
            return 0;
        }

        if ((flags & CHECK_CLOSED) && !containsHS2(context->bound, v))
        {
            error(parent, index, term, ERROR_NOT_CLOSED, report);
            return 0;
        }

        report->memuse += sizeof(struct _Variable);
        report->memuse += strlen(v->name) + 1; // not pooled (yet).
    }
    else
    {
        ASSERT(context, IS_CONSTRUCTION(term));

        if ((flags & CHECK_NF) && !IS_NF(term))
            return error(parent, index, term, ERROR_NOT_NF, report);

        Construction construction = asConstruction(term);

        report->memuse += sizeof(struct _Construction);

        // Check properties
        {
            NamedPropertyLink link;
            for (link = construction->namedProperties; link; link = link->link)
            {
                if (link->nr <= 0)
                    return error(parent, index, term, ERROR_NO_REFERENCE, report); // TODO: improve


                if (link->name)
                {
                    if (!lintTerm(context, NULL, 0, link->u.term, flags, report))
                        return 0;
                }
                else
                {
                    report->memuse += sizeof(struct _Variable);
                }

                report->memuse += sizeof(struct _NamedPropertyLink);
            }
        }

        {
            VariablePropertyLink link;
            for (link = construction->variableProperties; link; link = link->link)
            {
                if (link->nr <= 0)
                    return error(parent, index, term, ERROR_NO_REFERENCE, report); // TODO: improve

                if (link->variable)
                {
                    if (!lintTerm(context, NULL, 0, link->u.term, flags, report))
                        return 0;

                    report->memuse += sizeof(struct _Variable);
                }

                report->memuse += sizeof(struct _VariablePropertyLink);
            }
        }

        // Check binders and subterms.
        const int arity = ARITY(term);
        int i;
        for (i = 0; i < arity; ++i)
        {
            const int rank = RANK(term,i);

            if (flags & CHECK_CLOSED)
            {
                // Record bound variables
                int j;
                for (j = 0; j < rank; ++j)
                    addHS2(context->context, context->bound, BINDER(term,i,j));
            }

            if (!lintTerm(context, term, i, SUB(term,i), flags, report))
                return 0;

            if (flags & CHECK_CLOSED)
            {
                // Unrecord bound variables
                int j;
                for (j = 0; j < rank; ++j)
                    removeHS2(context->context, context->bound, BINDER(term,i,j));
            }
        }
    }
    return 1;
}


void printReport(Context context, LinterReport report)
{
    if (!report->valid)
    {
        printf("Error: %s\n", ERR_MSG[report->error]);
        fprintTermWithIndent (context, STDOUT, report->term);
    }
}
