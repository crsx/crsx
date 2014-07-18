# Makefile for CRSX rule compiler.

# Standard programs must be defined in a file located at $(MAKEFILE_GCC):
#    CC should be set to C compiler, such as gcc
#    CXX should be set to C++ compiler, such as g++
# Example file:
#    CC=gcc
#    CXX=g++
include $(MAKEFILE_CC)

UNAME_S=$(shell uname -s)
CCFLAGS=-g -Wall 
#-O3
ifeq ($(UNAME_S),Darwin)
CCFLAGS+=-Wno-gnu-variable-sized-type-not-at-end -std=c99
endif


ICU4CLIB=-licui18n -licuuc -licudata

CRSXCO_FILES=

.DEFAULT_GOAL := crsxc

#===================================================================================================
# CRSX.
#
CRSX_FILES=crsx.c crsx.h crsx_scan.c main.c linter.c linter.h
CRSXO_FILES= crsx.o main.o crsx_scan.o linter.o

#
crsx.o: crsx.c crsx.h
crsx_scan.o: crsx_scan.c crsx.h
linter.o: linter.c linter.h crsx.h 
main.o: main.c linter.h crsx.h

#===================================================================================================
# Rules

# CRSX rule families
CRSXCFAMILIES =RULE TERM EVAL HEADER SYMBOLS SORTS D CD Reified Text

# Same as FAMILIES but as CRSX list format
CRSXCMODULES = ( $(patsubst %,'%';,$(CRSXCFAMILIES)) )

CRSXCO_FILES=CRSXC_data.o CRSXCsymbols.o

define TARGETS
CRSXCO_FILES+=CRSXC_$(1)_fun.o
endef
$(foreach family, $(CRSXCFAMILIES), $(eval $(call TARGETS,$(family))))

#===================================================================================================
# bin

crsxc: $(CRSXCO_FILES) $(CRSXO_FILES)
	$(CXX) $^ $(ICU4CLIB) -L$(ICU4CDIR)/ -o $@

# Default C compilation
%.o: %.c
	$(CC) $(CCFLAGS) -I$(ICU4CDIR)/../include -c $< -o $@

clean:
	rm -f crsxc $(CRSXCO_FILES) $(CRSXO_FILES)
