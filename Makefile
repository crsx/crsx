# Makefile for CRSX pieces.

#VERSION := $(eval cat VERSION)
CRSXHOME = $(abspath .)

include Env.mk

.PHONY: all compile upload clean realclean

all: lib/javacc.jar lib/antlr-runtime-3.1.3.jar compile bin/crsxc crsx.jar

compile:
	$(ANT) compile

crsx.jar: 
	$(ANT) jar

lib/javacc.jar:
	$(error No javacc.jar found.  Get http://java.net/projects/javacc/downloads/download/oldversions%252Fjavacc-4.2.zip (or any later version), extract javacc-4.2/bin/lib/javacc.jar, and store it in lib/ as javacc.jar.)

lib/antlr-runtime-3.1.3.jar:
	$(error No lib/antlr-runtime-3.1.3.jar found.  Get http://www.antlr3.org/download/antlr-runtime-3.1.3.jar and store it in lib/ as antlr-runtime-3.1.3.jar.)

bin/crsxc:
	cd $(COMPILERSRC)/c && $(MAKE)
	cp $(COMPILERSRC)/c/build/crsxc bin/crsxc

clean:
	cd $(COMPILERSRC)/c && $(MAKE) clean
	rm -f bin/crsxc

realclean: clean
	rm -fr build $(COMPILERSRC)/c/build bin/crsxc crsx.jar
