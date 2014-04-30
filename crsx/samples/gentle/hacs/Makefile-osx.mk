# Makefile for OSX with alternative ICU brew installation

all:
	export LDFLAGS=-L/usr/local/opt/icu4c/lib && export CFLAGS="-I/usr/local/opt/icu4c/include -Wno-gnu-variable-sized-type-not-at-end -Wno-tautological-constant-out-of-range-compare" && make 