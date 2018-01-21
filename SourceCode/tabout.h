//-------------------------------- tabout.h ----------------------------------

/***************************************************************************
                            -  Description
                             -------------------
    Begin                : 6 December, 2006
    Copyright            : (C) 2006 by Simo
    E-Mail               : simo (at) furrydolphin (dot) net
    Version              : 1.1.0
 **************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *                                                                         *
 *   If software can be free, why can't dolphins?                          *
 *                                                                         *
 ***************************************************************************

*/

#ifndef TABOUT_H
#define TABOUT_H

#include <fox-1.6/fx.h>

//------------------------------- Text Macros --------------------------------

#define ABOUT_FC \
"\nFurCoderCXX:"\
"\n*  Create a Furry Code"\
"\n*  Decrypt a Furry Code"\
"\n" \
"\nVersion: "VERSION\
"\nSee the on-line help for further details on using"\
"\nFurCoderCXX."\
"\n" \
"\nIF SOFTWARE CAN BE FREE, WHY CAN'T DOLPHINS?"
//--------------------------------------

#define AUTHOR_FC \
"\nFur Coder written by: Simo,"\
"\nwith FOX and XEMACS"\
"\n"\
"\nWritten on a Slackware 10.1 System"\
"\n"\
"\nCopyright(C) 2006 by Simo"
//--------------------------------------

#define CREDITS_FC \
"\nThe Furry Code by: Ross Smith"\
"\nOriginated: 23 June, 1996"\
"\nVersion: 1.3 ( 7 Feburary, 1998)"\
"\nCopyright(C) 1998 by Ross Smith"
//--------------------------------------

class TAbout : public FXDialogBox
{
    FXDECLARE(TAbout)
    public:
                 TAbout(FXApp *aApp);
                 virtual ~TAbout(void);

    protected:
                 TAbout(void) {}                   //  Bury default constructor

    private:
                 TAbout(const TAbout&);            //  Hide default copy and assignment constructors
                 TAbout& operator=(const TAbout&);

    public:
                 enum
	         {
	             ID_TITLE= FXDialogBox::ID_LAST,
	             ID_LAST
	         };

    protected:
        	 FXIcon *DolphinLogo, *OKCheck, *FreeMe;

    private:
		 FXApp *ThisApp;
};

#endif

//-------------------------------- tabout.h ----------------------------------
