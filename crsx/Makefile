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

all: crsx.jar

crsx.jar:
	$(ANT) jar

upload:
	$(RSYNC) -au index.html "$$USER,crsx@web.sourceforge.net:/home/project-web/crsx/htdocs/index.html"


COMPILERSRC = src/net/sf/crsx/compiler
FLEX = flex

include RuleCompiler.mk