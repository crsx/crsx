// Main program for generated cook.
// $Id: Cookmain.c,v 1.1 2014/01/21 18:38:35 krisrose Exp $

#include "Cook.h"

// Main 'cook' program: read parsed .hx file from stdin and normalize and print...
//
int main(const int argc, char *const argv[])
{
    // Create context.
    struct _Context _context;
    _context.stamp = 1u;
    _context.literalPool = makeHS2(&_context, 16);

    // Read wrapper from $1.
    ConstructionDescriptor wrapper = argc > 1 ? LOOKUP_DESCRIPTOR(&_context, argv[1]) : NULL;
    FILE *input = argc > 2 ? fopen(argv[2], "r") : stdin;
    if (!wrapper)
    {
        fprintf(stderr, "Usage: %s (PG|CRS) file\n", argv[0]);
        exit(2);
    }

    // Read and wrap term.
    Sink sink = MAKE_BUFFER(&_context);
    sink->start(sink, wrapper);
    readTerm(sink, input);
    sink->end(sink, wrapper);
    Term term = BUFFER_TERM(sink);
    FREE_BUFFER(sink);

    // Compute the result.
    normalize(&_context, &term);

    // Print the result.
    printTerm(&_context, term);
}
