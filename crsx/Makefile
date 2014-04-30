# Makefile for CRSX pieces.

#VERSION := $(eval cat VERSION)

# Standard programs.
ANT = ant
RSYNC = rsync

CRSXBUILD = build 
JAVA = java
RUNCRSXRC = $(JAVA) -Dfile.encoding=UTF-8 -Xss20000K -Xmx2000m -cp $(CRSXBUILD) net.sf.crsx.run.Crsx allow-unnamed-rules allow-missing-cases
COMPILERSRC = src/net/sf/crsx/compiler
FLEX = flex
CC = gcc

INCLUDES = /usr/include

.PHONY: all upload clean

all: lib/javacc.jar lib/antlr-runtime-3.1.3.jar crsx.jar

crsx.jar:
	$(ANT) jar

upload:
	$(RSYNC) -au index.html "$$USER,crsx@web.sourceforge.net:/home/project-web/crsx/htdocs/index.html"

lib/javacc.jar:
	$(error No javacc.jar found.  Get http://java.net/projects/javacc/downloads/download/oldversions%252Fjavacc-4.2.zip (or any later version), extract javacc-4.2/bin/lib/javacc.jar, and store it in lib/ as javacc.jar.)

lib/antlr-runtime-3.1.3.jar:
	$(error No lib/antlr-runtime-3.1.3.jar found.  Get http://www.antlr.org/download/antlr-runtime-3.1.3.jar and store it in lib/ as antlr-runtime-3.1.3.jar.)

COMPILERSRC = src/net/sf/crsx/compiler
FLEX = flex

include RuleCompiler.mk
