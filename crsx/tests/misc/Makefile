all: bool

bool: bool.o bool_sorts.o crsx.o
bool_fun.o: bool_fun.c bool.h crsx.h
bool_sorts.o: bool_sorts.c bool.h crsx.h

crsx.o: crsx.c crsx.h

crsx.h: ln -s ../../src/net/sf/crsx/compiler/