# Common environment for makefile

# Standard programs.
ANT = ant
RSYNC = rsync
BUILD = $(CRSXHOME)/build
 
ifdef JAVA_HOME 
JAVA = $(JAVA_HOME)/jre/bin/java
else
JAVA = java
endif

RUNCRSXRC = $(JAVA) -Dfile.encoding=UTF-8 -Xss20000K -Xmx2000m -cp $(BUILD) net.sf.crsx.run.Crsx allow-unnamed-rules allow-missing-cases
COMPILERSRC = src/net/sf/crsx/compiler
FLEX = flex
CC = gcc
CXX = g++
CCFLAGS=-g -Wall
INCLUDES = /usr/include

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
CCFLAGS+=-Wno-gnu-variable-sized-type-not-at-end -std=c99
endif

ifndef ICU4CDIR
ICU4CDIR=
ifeq ($(UNAME_S),Darwin)
ICU4CDIR=/usr/local/opt/icu4c/lib
endif
endif
