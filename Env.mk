# Common environment for makefile

# Standard programs.

SHELL = /bin/bash
ANT = ant
RSYNC = rsync
FLEX = flex
CC = gcc
CXX = g++

ifdef JAVA_HOME 
JAVA = $(JAVA_HOME)/jre/bin/java
else
JAVA = java
endif

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
CCFLAGS+=-Wno-gnu-variable-sized-type-not-at-end -Wbitwise-op-parentheses -std=c99
endif

# Compilation setup.

ifndef ICU4CDIR
ICU4CDIR=
ifeq ($(UNAME_S),Darwin)
ICU4CDIR=/usr/local/opt/icu4c/lib
endif
endif

CCFLAGS+=-g -Wall
INCLUDES = /usr/include

# CRSX setup.

BUILD = $(CRSXHOME)/build
RUNCRSXRC = $(JAVA) -Dfile.encoding=UTF-8 -Xss20000K -Xmx2000m -cp $(BUILD) net.sf.crsx.run.Crsx allow-unnamed-rules allow-missing-cases
COMPILERSRC = src/net/sf/crsx/compiler
