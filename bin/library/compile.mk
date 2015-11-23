# Makefile for compiling crsx files.
# Arguments are
# CRSXHOME  : crsx root directory
# CRSXFILE  : name of the file to compile
# OUTPUTDIR : where to put generated files
# MODE      : crsx compilation mode. STRICT or empty  
# OPTFLAG   : C compiler optimization flag  
# DEBUG     : debug flags

ifndef MAKEFILE_CC
MAKEFILE_CC=$(CRSXHOME)/Env.mk
endif

include $(MAKEFILE_CC)
include $(COMPILERSRC)/c/Files.mk

crsabs = $(abspath $(CRSFILE))   
crspath =$(dir $(crsabs))
crsname = $(notdir $(CRSFILE))
crsbasename = $(patsubst %.crs,%,$(crsname))

ifndef OUTPUTDIR
OUTPUTDIR=$(crspath)
endif

crsdrfile = $(OUTPUTDIR)/$(crsbasename).dr
crsliteralsdrfile = $(OUTPUTDIR)/$(crsbasename)_literals.dr
crsbinfile = $(OUTPUTDIR)/$(crsbasename)

objs=

header=$(OUTPUTDIR)/$(crsbasename).h

data=$(OUTPUTDIR)/$(crsbasename)_data.c
objs+=$(OUTPUTDIR)/$(crsbasename)_data.o

literals=$(OUTPUTDIR)/$(crsbasename)_literals.c
objs+=$(OUTPUTDIR)/$(crsbasename)_literals.o

header_literals=$(OUTPUTDIR)/$(crsbasename)_literals.h

symlist=$(OUTPUTDIR)/$(crsbasename)_data.symlist

function=$(OUTPUTDIR)/$(crsbasename)_fun.c
objs+=$(OUTPUTDIR)/$(crsbasename)_fun.o

symbols=$(OUTPUTDIR)/$(crsbasename)_symbols.c
objs+=$(OUTPUTDIR)/$(crsbasename)_symbols.o

CCFLAGS+=-I$(COMPILERSRC)/c $(OPTFLAG) -foptimize-sibling-calls  

all: $(crsbinfile)
clean::
	@rm -f $(crsdrfile) $(crsbinfile) $(header) $(data) $(function) $(symbols) $(symlist)

prereq: 
	@mkdir -p $(OUTPUTDIR)

# Generate C files

$(OUTPUTDIR)/$(crsbasename) : $(crsdrfile)

$(crsliteralsdrfile) : $(crsdrfile)

$(crsdrfile): $(CRSFILE) prereq
	@$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules="$<" simple-terms sortify dispatchify simplify inline reify="$@" 

$(literals): $(crsliteralsdrfile) prereq
	$(CRSXC) MODULE="$(crsbasename)" wrapper=ComputeLiterals input="$<" > "$@"

$(header_literals): $(crsliteralsdrfile) prereq
	$(CRSXC) MODULE="$(crsbasename)" wrapper=ComputeLiteralsHeader input="$<" > "$@"
	
$(data): $(crsdrfile) prereq
	$(CRSXC) HEADERS="$(crsbasename).h" $(MODE) wrapper=ComputeSorts input="$<" > "$@"

$(symlist): $(crsdrfile) 
	$(CRSXC) wrapper=ComputeSymbols input="$<" > "$@.tmp"
	@sed -e 's/ {/\'$$'\n{/g' -e 's/ //g' "$@.tmp" | awk '/^$$/{next}{print}' | LC_ALL=C sort -bu > "$@"
	@rm "$@.tmp"

$(header): $(crsdrfile) prereq
	$(CRSXC) HEADERS="crsx.h;$(header_literals)" $(MODE) wrapper=ComputeHeader input="$<" > "$@"

$(function): $(crsdrfile) prereq
	$(CRSXC) HEADERS="$(crsbasename).h" $(MODE) CANONICAL_VARIABLES=1 wrapper=ComputeRules input="$<" > "$@"

# All symbols list.
$(symbols): $(symlist)
	@LC_ALL=C sort -bu "$<" > "$@.tmp"
	@(echo '/* Generated table of all $(crsbasename) symbols. */'; \
	  echo '#include "$(crsbasename).h"'; \
	  echo "size_t symbolDescriptorCount = $$(wc -l < $@.tmp);"; \
	  echo 'struct _SymbolDescriptor symbolDescriptorTable[] = {';\
	  cat $@.tmp;\
	  echo '{NULL, NULL}};') > $@
	@rm "$@.tmp"

# Compile C files

CCFLAGS+=-I. -DCRSX_ENABLE_PROFILING -DGENERIC_LOADER $(DEBUG)  
 
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

ifeq ($(MODE),STRICT)
CCFLAGS+=-DSTRICT
endif

objs+=$(OUTPUTDIR)/crsx.o $(OUTPUTDIR)/crsx_scan.o $(OUTPUTDIR)/main.o \
			 $(OUTPUTDIR)/linter.o $(OUTPUTDIR)/invariant.o $(OUTPUTDIR)/prof.o
			 
clean::
	@rm -f $(objs)

$(OUTPUTDIR)/crsx.o: $(COMPILERSRC)/c/crsx.c $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/crsx_scan.o: $(COMPILERSRC)/c/crsx_scan.c $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/linter.o: $(COMPILERSRC)/c/linter.c $(COMPILERSRC)/c/linter.h $(COMPILERSRC)/c/crsx.h 
$(OUTPUTDIR)/main.o: $(COMPILERSRC)/c/main.c $(COMPILERSRC)/c/linter.h $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/invariant.o: $(COMPILERSRC)/c/invariant.c $(COMPILERSRC)/c/invariant.h $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/prof.o: $(COMPILERSRC)/c/prof.c $(COMPILERSRC)/c/prof.h $(COMPILERSRC)/c/crsx.h

$(OUTPUTDIR)/%.o: $(COMPILERSRC)/c/%.c prereq 
	$(CC) $(CCFLAGS) -c "$<" -o "$@" 

$(OUTPUTDIR)/%.o: $(OUTPUTDIR)/%.c $(header) $(header_literals)  prereq  
	$(CC) $(CCFLAGS) -c "$<" -o "$@"

$(OUTPUTDIR)/$(crsbasename): $(objs) 
	@$(CXX) $(objs) $(ICU4CLIB) $(RTLIB) $(LDFLAGS) -o "$@"