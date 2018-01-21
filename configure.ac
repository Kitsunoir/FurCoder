#                      -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FurCoderCXX], [1.1.5], [simo@furrydolphin.net], [FurCoderCXX])
AC_CONFIG_SRCDIR([SourceCode/tmainwindow.cpp])

AM_INIT_AUTOMAKE

AC_MSG_NOTICE([Fur Coder Version:])
AC_MSG_RESULT([$VERSION])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

AC_ARG_ENABLE([optimum],
              [AS_HELP_STRING([--enable-optimum], [Enable optimum compile?])],
              [CXXFLAGS='-O3 -Wuninitialized -finline-functions -fomit-frame-pointer -fexpensive-optimizations'])

AC_ARG_ENABLE([debug],
	      [AS_HELP_STRING([--enable-debug], [Debug compile?])],
	      [CXXFLAGS='-ggdb -Wall'])

AC_ARG_ENABLE([instr],
              [AS_HELP_STRING([--enable-instr], [Enable Instrumentation? (no, verbose, quiet)])])

case $enable_instr in
quiet ) AC_DEFINE([FCINSTR], [1]);;

verbose ) AC_DEFINE([FCINSTR], [2]);;
esac

# Checks for libraries. Need FOX libs here. Try to compile and run a small FOX app.

AC_MSG_CHECKING([Looking for working FOX libs:])

SIMO_FOX_COMPILE

SIMO_FOX_RUN

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE

AC_CONFIG_FILES([Makefile
                 Documents/Images/Makefile
                 Documents/Makefile
                 SourceCode/Makefile
                 SourceCode/locations.h
                 etc/Makefile])
AC_OUTPUT

cat << EOF

>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Make FurCoderCXX <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>                                                                        <<
>>  Configure complete :-)                                                <<
>>                                                                        <<
>>  Next, enter: "make" (no quotes) to compile the program.               <<
>>  Note: You may have to su to root to complete the install.             <<
>>  Then enter "make install" to install the program on your system.      <<
>>                                                                        <<
>>  If you haven't done so already, be sure to see INSTALL   for          <<
>>  some important information on the running of the Furry Coder.         <<
>>                                                                        <<
>>  Thanks for choosing FurCoderCXX                                       <<
>>  Enjoy your new program :-)                                            <<
>>                                                                        <<
>>            IF SOFTWARE CAN BE FREE, WHY CAN'T DOLPHINS?                <<
>>                                                                        <<
>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Make FurCoderCXX <<<<<<<<<<<<<<<<<<<<<<<<<<<<<

EOF

