# Makefile for CRSX rule compiler.

# Standard programs must be defined in a file located at $(MAKEFILE_GCC):
#    CC should be set to C compiler, such as gcc
#    CXX should be set to C++ compiler, such as g++
# Example file:
#    CC=gcc
#    CXX=g++

ifndef MAKEFILE_CC
CRSXHOME = $(abspath ../../../../../..)
MAKEFILE_CC=$(CRSXHOME)/Env.mk
endif

include $(MAKEFILE_CC)

ifndef CRSXCBUILD
CRSXCBUILD=build
endif

ICU4CLIB=-licui18n -licuuc -licudata -ldl
CCFLAGS+=-I. -DCRSX_ENABLE_PROFILING -DDEBUG -g
ifdef ICU4CDIR
LDFLAGS+=-L$(ICU4CDIR)
CCFLAGS+=-I$(ICU4CDIR)/../include
endif 

ifneq ($(UNAME_S),Darwin)
RTLIB=-lrt
endif

ifdef RTDIR
LDFLAGS+=-L$(RTDIR)
CCFLAGS+=-I$(RTDIR)/../include
endif

all: rules $(CRSXCBUILD)/crsxc

include Files.mk

CRSX_FILES=$(CRSXR_FILES) main.c

CRSX_O_FILES=$(CRSXCBUILD)/crsx.o $(CRSXCBUILD)/crsx_scan.o $(CRSXCBUILD)/main.o \
			 $(CRSXCBUILD)/linter.o $(CRSXCBUILD)/invariant.o $(CRSXCBUILD)/prof.o

#
$(CRSXCBUILD)/crsx.o: crsx.c crsx.h
$(CRSXCBUILD)/crsx_scan.o: crsx_scan.c crsx.h
$(CRSXCBUILD)/linter.o: linter.c linter.h crsx.h 
$(CRSXCBUILD)/main.o: main.c linter.h crsx.h
$(CRSXCBUILD)/invariant.o: invariant.c invariant.h crsx.h
$(CRSXCBUILD)/prof.o: prof.c prof.h crsx.h

#===================================================================================================
# C files

#
$(CRSXCBUILD)/%.o: %.c
	@mkdir -p $(CRSXCBUILD)
	$(CC) $(CCFLAGS) -c $< -o $@

$(CRSXCBUILD)/%.o: $(CRSXCBUILD)/%.c rules  
	@mkdir -p $(CRSXCBUILD)
	$(CC) $(CCFLAGS) -c $< -o $@
#
$(CRSXCBUILD)/crsx_scan.o: $(CRSXCBUILD)/crsx_scan.c crsx.h 
$(CRSXCBUILD)/crsx_scan.c: crsx_scan.l
	@mkdir -p $(CRSXCBUILD)
	$(FLEX) -v -s -o $(CRSXCBUILD)/crsx_scan.c crsx_scan.l


#===================================================================================================
# Generated Rules C files

# CRSX rule families
CRSXCFAMILIES=EVAL-E1 EVAL-E2 RULE SRULE TERM STERM HEADER SHEADER SYMBOLS SORTS D CD Reified Text
CRSXCO_FILES=$(CRSXCBUILD)/CRSXC_data.o $(CRSXCBUILD)/CRSXCsymbols.o

$(CRSXCBUILD)/CRSXCsymbols.c: rules
$(CRSXCBUILD)/CRSXCsymbols.o: $(CRSXCBUILD)/CRSXCsymbols.c  
	$(CC) $(CCFLAGS) -c $< -o $@ 

$(CRSXCBUILD)/CRSXC_data.c: rules
$(CRSXCBUILD)/CRSXC_data.o: $(CRSXCBUILD)/CRSXC_data.c   
	$(CC) $(CCFLAGS) -c $< -o $@

define TARGETS
CRSXCO_FILES+=$(CRSXCBUILD)/CRSXC_$(1)_fun.o
$(CRSXCBUILD)/CRSXC_$(1)_fun.c : rules
$(CRSXCBUILD)/CRSXC_$(1)_fun.o: $(CRSXCBUILD)/CRSXC_$(1)_fun.c 
	$(CC) $(CCFLAGS) -c $$< -o $$@  
endef
$(foreach family, $(CRSXCFAMILIES), $(eval $(call TARGETS,$(family))))


#===================================================================================================
# crsxc

rules: 
ifdef MAKEFILE_CC
	export MAKEFILE_CC=$(MAKEFILE_CC) && $(MAKE) -f Rules.mk
else
	$(MAKE) -f Rules.mk
endif

$(CRSXCBUILD)/crsxc: $(CRSXCO_FILES) $(CRSX_O_FILES)
	$(CXX) $^ $(ICU4CLIB) $(RTLIB) $(LDFLAGS) -o $@

clean::
	rm -f $(CRSXCBUILD)/crsxc $(CRSXCO_FILES) $(CRSX_O_FILES)
	$(MAKE) -f Rules.mk clean 
