
Getting Started
***************

System requirements
===================

CRSX has been tested on OSX and Ubuntu.

``git`` must be installed on your system, as well as ``make``.

ICU is required to compile CRSX. You can install it as follows:

- on OS X: either use macport or homebrew.
- on Ubuntu:

  - type sudo apt-get install libicu52 (or older/newer version)
  - type sudo apt-get install libicu-dev

Download
========

CRSX is hosted on github.com. To download and enter the directory, type the following commands in a terminal:

.. code-block:: sh

    git clone https://github.com/crsx/crsx.git
    cd crsx

Installation
============

The code needs to be compile using this command :

.. code-block:: sh

    make -j1

.. note::

    The -j1 to turn off parallel make is because of a temporary bug in the makefile that would build in the wrong order and error.
    It tends to only matter the first time you make, subsequent incremental makes should be fine parallel.]

This might take a few minutes.

If you get this compilation error:

.. code-block:: sh

    gcc -g -Wall -I. -DCRSX_ENABLE_PROFILING -DDEBUG -g -c crsx.c -o build/crsx.o
    crsx.c:11:30: fatal error: unicode/umachine.h: No such file or directory
    #include <unicode/umachine.h>
                          ^
    compilation terminated.

it means ICU hasn't been installed on your system. See above for instructions.

Running a sample
================

Advanced: If you would like to understand this program as you compile and run it, see CRSX Sample Program: Hello World.

From the CRSX root directory, type the following commands in a terminal:

.. code-block:: sh

    cd samples/hello-world
    make -j1
    ./hello-world wrapper=Go

You should see "Hello-World"

Now you have CRSX running on your machine.

How to continue
===============

For a hands-on introduction to CRSX, see the `tutorials <https://github.com/crsx/crsx/wiki/Tutorials>`_.

For the reference manual, jump to the :doc:`intro` .
