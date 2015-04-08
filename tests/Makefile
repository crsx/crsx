# Makefile for smoketest
# params:
# TEST: test to execute when target is test.

CRSXHOME = $(abspath ..)
include $(CRSXHOME)/Env.mk

tests:=$(shell find . -name test*.crs | sort -n  )
	
abstest=$(abspath $(TEST))
absbasetest=$(basename $(abstest))
testname =$(notdir $(abstest))
basetest =$(notdir $(absbasetest))
outputdir =results/$(basetest)

exec = $(outputdir)/$(basetest)
got = $(outputdir)/$(basetest).out
ref = $(patsubst %.crs,%.ref,$(abstest))
log = tests.log

all:
	@rm -f $(log)
	@echo `date` >> $(log)
	@$(foreach t, $(tests), $(MAKE) --no-print-directory TEST="$t" test;)
	
test:
	@rm -f $(got)
	@printf $(TEST) 2>&1 | tee -a $(log)
	@echo >> $(log)
	@$(CRSX) compile --clean --strict -o $(outputdir) $(TEST) >> $(log) 2>&1
	@$(exec) wrapper=Test output=$(got) CANONICAL_VARIABLES=1
	@if diff -s $(got) $(ref) > /dev/null;  \
     then echo ..PASSED | tee -a $(log)  ; \
     else echo FAILED | tee -a $(log);  diff -s $(got) $(ref) | tee -a $(log);  \
     fi