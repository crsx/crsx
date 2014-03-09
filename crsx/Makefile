# Makefile for CRSX pieces.

#VERSION := $(eval cat VERSION)

# Standard programs.
ANT = ant
RSYNC = rsync
FLEX = flex
JAVA = java
CC = gcc

CRSXBUILD = build 
RUNCRSXRC = $(JAVA) -Dfile.encoding=UTF-8 -Xss20000K -Xmx2000m -cp $(CRSXBUILD) net.sf.crsx.run.Crsx allow-unnamed-rules allow-missing-cases
COMPILERSRC = src/net/sf/crsx/compiler

INCLUDES = /usr/include

.PHONY: all upload clean real

all: crsx.jar

crsx.jar: bin
	$(ANT) jar
realclean::; rm -f crsx.jar

#upload:
#	$(RSYNC) -au index.html "$$USER,crsx@web.sourceforge.net:/home/project-web/crsx/htdocs/index.html"

COMPILERSRC = src/net/sf/crsx/compiler

include RuleCompiler.mk

# HACS (including smoke test).

.PHONY: smoke hacs
smoke:: crsx.jar
	cp -f crsx.jar samples/gentle/hacs
	$(MAKE) -C samples/gentle first.run
	(cd samples/gentle && ./first.run --action=Compile --term="{initial := 1; rate := 1.0; position := initial + rate * 60;}")

clean::; $(MAKE) -C samples/gentle clean
realclean::; $(MAKE) -C samples/gentle realclean
