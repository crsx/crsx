# Makefile for CRSX rule compiler.

# Standard programs.

CC = gcc
CCFLAGS=-g -Wall 
#-O3

ICU4CDIR=
ICU4CLIB=-licui18n -licuuc -licudata
#INCLUDES = /usr/include

CACHE=rulecompiler

#Keep the intermediate files in cache.
.SECONDARY:

.PHONY: prereq bin 
bin: bin/crsx

clean::
	rm -f $(CACHE)/*.*
	rm -f bin/crsx

prereq:
	@mkdir -p bin
	@mkdir -p $(CACHE)

#===================================================================================================
# RULE COMPILER COMPILATION
# 

# CRSX.
#
CRSX_FILES=$(CACHE)/crsx.c $(CACHE)/crsx.h $(CACHE)/crsx_scan.l $(CACHE)/main.c $(CACHE)/linter.c $(CACHE)/linter.h

$(CACHE)/crsx.c $(CACHE)/crsx.h $(CACHE)/crsx_scan.l $(CACHE)/main.c $(CACHE)/linter.c $(CACHE)/linter.h: $(COMPILERSRC)/c/crsx.h $(COMPILERSRC)/c/crsx.c $(COMPILERSRC)/c/crsx_scan.l $(COMPILERSRC)/c/main.c $(COMPILERSRC)/c/linter.c  $(COMPILERSRC)/c/linter.h
	cp $(COMPILERSRC)/c/crsx.h $(CACHE)
	cp $(COMPILERSRC)/c/crsx.c $(CACHE)
	cp $(COMPILERSRC)/c/crsx_scan.l $(CACHE)
	cp $(COMPILERSRC)/c/main.c $(CACHE)
	cp $(COMPILERSRC)/c/linter.c $(CACHE)
	cp $(COMPILERSRC)/c/linter.h $(CACHE)

#
$(CACHE)/crsx.o: $(CACHE)/crsx.c $(CACHE)/crsx.h
	$(CC) $(CCFLAGS) -I$(CACHE) -c $(CACHE)/crsx.c -o $@
#
$(CACHE)/crsx_scan.o: $(CACHE)/crsx_scan.c $(CACHE)/crsx.h 
$(CACHE)/crsx_scan.c: $(CACHE)/crsx_scan.l
	$(FLEX) -v -s -o $(CACHE)/crsx_scan.c $(CACHE)/crsx_scan.l
#
$(CACHE)/linter.o: $(CACHE)/linter.c $(CACHE)/linter.h $(CACHE)/crsx.h
	$(CC) $(CCFLAGS) -I$(CACHE) -c $(CACHE)/linter.c -o $@
#
$(CACHE)/main.o: $(CACHE)/main.c $(CACHE)/crsx.h
	$(CC) $(CCFLAGS) -I$(CACHE) -c $(CACHE)/main.c -o $@

CRSXO_FILES=$(CACHE)/crsx.o $(CACHE)/crsx_scan.o $(CACHE)/main.o $(CACHE)/linter.o

TARGETS=CRSXC

# CRSX rule families
CRSXCFAMILIES =RULE TERM EVAL HEADER SORTS SYMBOLS D CD Reified Text

# Same as FAMILIES but as CRSX list format
CRSXCMODULES = ( $(patsubst %,'%';,$(CRSXCFAMILIES)) )

# The crsxc rules files.
CRSXCRULESFILES =  $(COMPILERSRC)/crsxc.crs $(COMPILERSRC)/c/rules.crs $(COMPILERSRC)/c/evaluators.crs $(COMPILERSRC)/c/term.crs $(COMPILERSRC)/c/header.crs $(COMPILERSRC)/c/sorts.crs $(COMPILERSRC)/c/symbols.crs $(COMPILERSRC)/defs.crs $(COMPILERSRC)/reify.crs $(COMPILERSRC)/c/cdefs.crs 

# We need a second expansion: the first expansion generates target rules and the second expansion processes automatic variables	    
.SECONDEXPANSION:
define TARGETDR
  $(CACHE)/$(1).dr: $($(1)RULESFILES)
	$(RUNCRSXRC) 'grammar=("net.sf.crsx.text.Text";)' "modules=$($(1)MODULES)" rules="$$<" simple-terms sortify dispatchify reify="$$@"
	@[ -s $$@ ] || rm -f $$@ || false

endef
$(foreach tgt, $(TARGETS), $(eval $(call TARGETDR,$(tgt))))

#===================================================================================================
# C SOURCE FILES GENERATION

define TARGETGEN

# - header fragment for TARGET.h with all declarations.
$(CACHE)/$(1)_%.h: $(CACHE)/$(1)_%_header.dr
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=$(COMPILERSRC)/c/header.crs wrapper="ComputeHeader" "MODULE=$$*" sink=net.sf.crsx.text.TextSink input="$$<" output="$$@.tmp"
	@mv $$@.tmp $$@

# - sort data structures and step function definitions.

$(CACHE)/$(1)_%_fun.c: $(CACHE)/$(1)_%.dr
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=$(COMPILERSRC)/c/rules.crs  wrapper="ComputeRules" "HEADERS=$(1).h" "MODULE=$$*" sink=net.sf.crsx.text.TextSink input="$$<" canonical-variables output="$$@.tmp"
	@mv $$@.tmp $$@
 
 # - symbol list for crsx_scan.
 $(CACHE)/$(1)_%.symlist: $(CACHE)/$(1)_%_header.dr
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=$(COMPILERSRC)/c/symbols.crs wrapper="ComputeSymbols" sink=net.sf.crsx.text.TextSink input="$$<" output="$$@.tmp"
	@sed -e 's/}, */},\n/g' -e 's/ //g' $$@.tmp | awk '/^$$$$/{next}{print}' | LC_ALL=C sort -bu > $$@
	@rm -f $$@.tmp

 # specific targets for data symbols.
 $(CACHE)/$(1)_data.dr: $(CACHE)/$(1).dr

 $(CACHE)/$(1)_data.h: $(CACHE)/$(1)_data.dr  
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=$(COMPILERSRC)/c/header.crs wrapper="ComputeHeader" MODULE=DATA sink=net.sf.crsx.text.TextSink input="$(CACHE)/$(1)_data.dr" output="$(CACHE)/$(1)_data.h.tmp"
	@mv $(CACHE)/$(1)_data.h.tmp $(CACHE)/$(1)_data.h

 $(CACHE)/$(1)_data.c: $(CACHE)/$(1)_data.dr 
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=$(COMPILERSRC)/c/sorts.crs wrapper="ComputeSorts" "HEADERS=$(1).h" sink=net.sf.crsx.text.TextSink input="$(CACHE)/$(1)_data.dr" output="$(CACHE)/$(1)_data.c.tmp"
	@mv $(CACHE)/$(1)_data.c.tmp $(CACHE)/$(1)_data.c

 $(CACHE)/$(1)_data.symlist: $(CACHE)/$(1)_data.dr  
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=$(COMPILERSRC)/c/symbols.crs wrapper="ComputeSymbols" sink=net.sf.crsx.text.TextSink input="$(CACHE)/$(1)_data.dr" output="$(CACHE)/$(1)_data.symlist.tmp"
	sed -e 's/}, */},\n/g' -e 's/ //g' $(CACHE)/$(1)_data.symlist.tmp | awk '/^$$$$/{next}{print}' | LC_ALL=C sort -bu > $(CACHE)/$(1)_data.symlist
	@rm $(CACHE)/$(1)_data.symlist.tmp

 $(1)DR_FILES += $(CACHE)/$(1)_data.dr
 $(1)H_FILES += $(CACHE)/$(1)_data.h 
 $(1)SYMLIST_FILES += $(CACHE)/$(1)_data.symlist
 
 $(CACHE)/%_fun.o : $(CACHE)/%_fun.c $(CACHE)/$(1).h 
	$(CC) $(CCFLAGS) -I$(CACHE) -I$(COMPILERSRC)/c -c $$< -o $$@
 
endef
$(foreach tgt, $(TARGETS), $(eval $(call TARGETGEN,$(tgt))))

# Non-.c targets for all sort data structures, step functions, and function symbol lists.
define FAMILY_DEPENDENCIES
 $(CACHE)/$(1)_$(2).dr:		$(CACHE)/$(1).dr 
 $(CACHE)/$(1)_$(2)_header.dr:	$(CACHE)/$(1).dr 
 $(CACHE)/$(1)_$(2)_fun.c:		$(CACHE)/$(1)_$(2).dr 
 $(CACHE)/$(1)_$(2).h:		$(CACHE)/$(1)_$(2)_header.dr 
 $(CACHE)/$(1)_$(2).symlist:	$(CACHE)/$(1)_$(2)_header.dr 
 $(1)DR_FILES += $(CACHE)/$(1)_$(2).dr
 $(1)H_FILES += $(CACHE)/$(1)_$(2).h
 $(1)SYMLIST_FILES += $(CACHE)/$(1)_$(2).symlist
 $(1)C_FILES += $(CACHE)/$(1)_$(2)_fun.c

#
#all:: $(DR_FILES) $(H_FILES) $(C_FILES) $(CACHE)/$(1)symbols.c
#	touch all.stamp
#clean::
#	rm -f $(H_FILES)
#	rm -f $(C_FILES)
#	rm -f $(SYMLIST_FILES)
#	rm -f $(CACHE)/X2Bsymbols*
#	rm -f all.stamp
#realclean::
#	rm -f $(DR_FILES)

$(CACHE)/$(1)_$(2)_fun.o:	$(CACHE)/$(1)_$(2)_fun.c $(H_FILES) $(CACHE)/$(1).h
$(1)O_FILES += $(CACHE)/$(1)_$(2)_fun.o

$(CACHE)/$(1)symbols.o: $(CACHE)/$(1)symbols.c $(COMPILERSRC)/c/crsx.h $(CACHE)/$(1)_data.h $(CACHE)/$(1).h

endef

define TARGETED_FAMILY_DEPENDENCIES
# Top header file included from all components.
$(CACHE)/$(1).h: $$($(1)H_FILES)
	@(echo '/* C HEADER FOR CRSX $(1).h */'; \
	  echo '#ifndef CRSX__M_$(1)_H'; \
	  echo '#define CRSX__M_$(1)_H'; \
	  echo '#include "crsx.h"'; \
	  echo '#include "$(1)_data.h"'; \
	  for line in $($(1)FAMILIES); do \
	     echo "#include \"$(1)_$$$$line.h\""; \
	  done; \
	  echo '#endif') > $(CACHE)/$(1).h

$(1)H_FILES += $(CACHE)/$(1).h

# All symbols list.
$(CACHE)/$(1)symbols.c: $$($(1)SYMLIST_FILES)  
	LC_ALL=C sort -bu $$($(1)SYMLIST_FILES) > $$@.tmp
	@(echo '/* Generated table of all $(1) symbols. */'; \
	  echo '#include "$(1).h"'; \
	  echo "size_t symbolDescriptorCount = $$$$(wc -l <$$@.tmp);"; \
	  echo 'struct _SymbolDescriptor symbolDescriptorTable[] = {';\
	  cat $$@.tmp;\
	  echo '{NULL, NULL}};') > $$@


# OBJECT FILES.
$(CACHE)/$(1)_data.o: $(CACHE)/$(1)_data.c $($(1)H_FILES) $(CACHE)/$(1).h $(CRSX_FILES) 

$(1)O_FILES += $(CACHE)/$(1)_data.o
$(1)O_FILES += $(CACHE)/$(1)symbols.o

$(foreach family,$($(1)FAMILIES),$(eval $(call FAMILY_DEPENDENCIES,$(1),$(family))))
endef
$(foreach tgt, $(TARGETS), $(eval $(call TARGETED_FAMILY_DEPENDENCIES,$(tgt))))

#===================================================================================================
# bin

bin/crsx: $(CRSXCO_FILES) $(CRSXO_FILES)
	@mkdir -p bin
	$(CC) $^ $(ICU4CDIR) $(ICU4CLIB)  -o $@

# Default C compilation
%.o: %.c
	$(CC) $(CCFLAGS) -I$(CACHE) -c $< -o $@
