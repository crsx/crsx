# Local Makefile for artifacts *in* HACS directory.

# HACS configuration.
HACS = $(abspath .)
include Makefile-hx

all:: Cookmain

# HACS Cook utility dependencies.
Cookmain.o: Cookmain.c Cook.h crsx.h
Cookmain: Cookmain.o Cook_sorts.o Cook_rules.o Cook_symbols.o crsx.o crsx_scan.o
#	$(CC) -o Cookmain Cookmain.o Cook_sorts.o Cook_rules.o Cook_symbols.o crsx.o crsx_scan.o -licuuc -licudata -licui18n -licuio
clean::; rm -f Cook_* Cook.*
realclean::; rm -fr Cookmain tmp
