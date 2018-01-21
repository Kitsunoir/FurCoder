##--------------------------- SourceCode Makefile.am ---------------------------

## *****************************************************************************
##                            -  Description
##                             -------------------
##    Begin                : 22 December, 2006
##    Copyright            : (C) 2006 by Simo
##    E-Mail               : simo@furrydolphin.net
##    Version              : 1.1.0
## **************************************************************************/

## ***************************************************************************
## *                                                                         *
## *   This program is free software; you can redistribute it and/or modify  *
## *   it under the terms of the GNU General Public License as published by  *
## *   the Free Software Foundation; either version 2 of the License, or     *
## *   (at your option) any later version.                                   *
## *                                                                         *
## *                                                                         *
## *   If software can be free, why can't dolphins?                          *
## *                                                                         *
## ***************************************************************************

##  Process with automake to create Makefile.in

INCLUDES= -I.
FoxLibs=  @FoxLibs@

bin_PROGRAMS= FurCoderCXX

FurCoderCXX_LDADD= $(FoxLibs)

FurCoderCXX_SOURCES= \
FurCoderCXX.cpp \
furcodeexternals.cpp furcodeexternals.h \
icons.cpp icons.h \
tabout.cpp tabout.h \
tspecialmsgbox.cpp tspecialmsgbox.h FreeDolphins.h \
tmainwindow.cpp tmainwindow.h fcdefs.h

##--------------------------- SourceCode Makefile.am ---------------------------
