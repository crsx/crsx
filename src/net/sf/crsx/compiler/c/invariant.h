// Copyright (c) 2014 IBM Corporation.

/**
 * Various utiity functions checking for invariants.
 *
 * Only use for debugging purpose.
 */

#ifndef INVARIANT_H_
#define INVARIANT_H_

#include "crsx.h"

#ifdef CRSX_ENABLE_CHECK

// Whether or not to check for accurate reference count.
int gCheckRef = 0;

extern TermLink occurLink(TermLink link, void* p);
extern int addOccur(Context context, TermLink* linkp, void* p);
extern void freeOccur(Context context, TermLink link);

extern int checkTerm(Context context, Term term, int nf);
extern int checkTerm2(Context context, Term term, int nf, unsigned* envsize);
extern int checkTerm3(Context context, Term term, int nf, unsigned depth, unsigned* envsize, long* memuse);
extern int checkTerm4(Context context, Term parent, unsigned index, Term term, int nf, unsigned depth, unsigned* envsize, long* memuse, TermLink *usedp);

extern int checkPropsHS2(Context context, Hashset2 set, int nf, unsigned* envsize, long* memuse, TermLink* usedp);

#endif

#endif /* INVARIANT_H_ */
