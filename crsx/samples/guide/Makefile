# Makefile for examples in the HOACS Guide.

# =====
# SETUP
# =====

# Directories.
CRSXROOT = ../..
CRSXBUILD = $(CRSXROOT)/build
CRSXLIB = $(CRSXROOT)/lib
SOURCE = ../src

# How to run base commands.
JAVA = java
JAVAC = javac
JAVACC = javacc

# How to run the CRSX executable.
CRSX = $(JAVA) -cp "$(CRSXBUILD):" net.sf.crsx.run.Crsx
PG = $(JAVA) -cp "$(CRSXBUILD):$(CRSXLIB)/javacc.jar:" net.sf.crsx.pg.PG

# =============
# DEFAULT RULES
# =============

# The following three steps support dependencies of the form
#   mycompiler : mycompiler.hx

# (1) Generate PG grammar like 'deriv.pg' + check and compile the Java parser.
#
%.pg : %.hx
	@set -x \
	&& $(CRSX) \
		'grammar=("net.sf.crsx.hoacs.bootstrap.Raw";"net.sf.crsx.text.Text";)' \
		rules=net/sf/crsx/hoacs/bootstrap/CookPG.crs \
		input='$<' category=rawModule \
		output='$@.tmp' sink=net.sf.crsx.text.TextSink \
	&& class=$$(sed -n 's/class \(.*\)Parser :.*/\1/p' '$@.tmp') \
	&& base=$$(echo $$class | sed 's:\.:/:g') \
	&& $(PG) '$@.tmp' -source=$(SOURCE) \
	&& (cd $(SOURCE) \
	    && $(JAVACC) -OUTPUT_DIRECTORY=$$(dirname $$base) $${base}Parser.jj \
	    && $(JAVAC) -cp '$(CRSXLIB)/javacc.jar:$(CRSXBUILD)' -sourcepath $(SOURCE) -d $(CRSXBUILD) $${base}Parser.java ) \
	&& mv '$@.tmp' '$@'

# (2) Generate CRSX system (using generated parser) such as 'deriv.crs' + check CRSX system well formed.
#
%.crs : %.pg
	@set -x \
	&& $(CRSX) \
		'grammar=("net.sf.crsx.hoacs.bootstrap.Raw";"net.sf.crsx.text.Text";)' \
		rules=net/sf/crsx/hoacs/bootstrap/CookCRS.crs \
		input='$*.hx' category=rawModule \
		output='$@.tmp' sink=net.sf.crsx.text.TextSink \
	&& class=$$(sed -n 's/class \(.*\) :.*/\1/p' '$<') \
	&& $(CRSX) grammar='("'$${class}'";"net.sf.crsx.text.Text";)' rules='$@.tmp' \
	&& mv '$@.tmp' '$@'

%.crsE: %.crs %.pg
	@set -x \
	&& class=$$(sed -n 's/class \(.*\) :.*/\1/p' '$*.pg') \
	&& $(CRSX) 'grammar=("'$${class}'";"net.sf.crsx.text.Text";)' meta input='$*.crs' output='$@.tmp' \
	&& mv '$@.tmp' '$@'

## (3) Generate executable.
## [TODO: use proper compilation...]

%: %.crs %.pg
	@set -x \
	&& class=$$(sed -n 's/class \(.*\) :.*/\1/p' '$*.pg') \
	&& (echo '$(CRSX) "grammar=(\"'$${class}'\";\"net.sf.crsx.text.Text\";)" rules="$*.crs"' \
		 'term=" \$$Print-Fun[ %derivFun⟦ $$1 ⟧, 0] "' \
		 'sink="net.sf.crsx.text.TextSink"' > '$@.tmp') \
	&& mv '$@.tmp' '$@' \
	&& chmod +x $@

# DEPENDENCIES.

## Deriv example from Guide.

deriv.pg : deriv.hx
deriv.crs : deriv.hx
deriv : deriv.crs

clean::; rm -f deriv deriv.pg deriv.crs stamp* *.tmp
