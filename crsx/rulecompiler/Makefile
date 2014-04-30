# Makefile for CRSX rule compiler.

# Standard programs.

CC = gcc
CCPLUS = g++ $(CFLAGS)
CCFLAGS=-g -Wall $(CFLAGS) 
#-O3

ICU4CLIB=-licui18n -licuuc -licudata

CRSXCO_FILES=

.DEFAULT_GOAL := crsx

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

crsx: $(CRSXCO_FILES) $(CRSXO_FILES)
	$(CCPLUS) $^ $(ICU4CLIB) $(LDFLAGS) $(ICU4CDIR) -o $@

# Default C compilation
%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@
