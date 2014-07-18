// Copyright (c) 2010, 2014 IBM Corporation.
// $Id: linter.h,v 3.1 2014/02/07 20:18:10 villardl Exp $

#ifndef _LINTER_H
# define _LINTER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "crsx.h"

#define CHECK_CLOSED 0x0001          // Check term is closed (no free variables)
#define CHECK_NF     0x0002          // Check term is in normal form

#define ERROR_NO_REFERENCE 0         // Reference counting error
#define ERROR_NULL_VARIABLE 1        // Variable use does not point to a Variable
#define ERROR_NOT_CLOSED 2           // Term is not closed. subterm points to the invalid free variable.
#define ERROR_NOT_NF 3               // Term is not in normal form.

typedef struct _LinterReport* LinterReport;

/**
 * @Brief Various information created by linter.
 */
struct _LinterReport {
    int valid;                  // Whether term is valid w.r.t checked properties.
    int closed;                 // Whether term is closed.
    unsigned long long memuse;  // Accumulated memory use (in bytes)

    int error;                  // Error code. See ERROR_XXX
    Term term;                  // Parent of the invalid subterm. NULL is root.
    Term subterm;               // Invalid subterm.
};

/**
 * @Brief Check given term respects some properties
 *
 * Warning: Work in progress.
 */
LinterReport lint(Context context, Term term, int flags);

/**
 * @Brief Print report on the console
 */
void printReport(Context context, LinterReport report);

#ifdef __cplusplus
}
#endif

#endif

