//-------------------------------- tabout.cpp ----------------------------------

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

#include "tabout.h"
#include "icons.h"
#include <fox-1.6/FXJPGIcon.h>

//     Make the FOX Message/Target Callback Map

FXDEFMAP(TAbout) TAboutSM[]=
{
    FXMAPFUNC(SEL_CLOSE, TAbout::ID_TITLE, FXDialogBox::onCmdAccept)
};

FXIMPLEMENT(TAbout, FXDialogBox, TAboutSM, ARRAYNUMBER(TAboutSM))

/*
       Name: TAbout

       Type: Subroutine (Constructor)

       Parameters: aApp (Pointer: FXApp) -- Pointer to the main event loop

       Note: Create the "About" Box GUI. No other functionality to implement.
*/

TAbout::TAbout(FXApp *aApp) :
FXDialogBox(aApp, "About Fur Coder", DECOR_TITLE|DECOR_BORDER|DECOR_CLOSE),
ThisApp(aApp)

{
//        Declare Layout Managers

    FXVerticalFrame   *MainLO;
    FXHorizontalFrame *SubLO, *TabLO0, *TabLO1, *TabLO2, *CmdBtnGrp;
    FXTabBook         *Tabber;

//        Initialize Icons

    DolphinLogo= new FXXPMIcon(ThisApp, smDolphin_xpm);
    OKCheck=     new FXXPMIcon(ThisApp, OKCheck_xpm);
    FreeMe=      new FXJPGIcon(ThisApp, FreeMe_jpg);

    setMiniIcon(DolphinLogo);
    setTarget(this);
    setSelector(ID_TITLE);

    MainLO=    new FXVerticalFrame(this, LAYOUT_SIDE_TOP|LAYOUT_FILL|FRAME_NORMAL);
    SubLO=     new FXHorizontalFrame(MainLO, LAYOUT_FILL|FRAME_NONE|LAYOUT_SIDE_TOP);
    (void)     new FXLabel(SubLO, "", FreeMe, JUSTIFY_CENTER_X|JUSTIFY_CENTER_Y|ICON_BEFORE_TEXT|FRAME_GROOVE);
               new FXVerticalSeparator(SubLO);
    Tabber=    new FXTabBook(SubLO, NULL, 0, TABBOOK_BOTTOMTABS|LAYOUT_FILL|PACK_UNIFORM_WIDTH);
               new FXTabItem(Tabber, "&About", NULL, TAB_BOTTOM_NORMAL);
    TabLO0=    new FXHorizontalFrame(Tabber, LAYOUT_FILL_X|LAYOUT_FILL_Y|FRAME_GROOVE);
    (void)     new FXLabel(TabLO0, ABOUT_FC, NULL, JUSTIFY_LEFT|ICON_BEFORE_TEXT);
               new FXTabItem(Tabber, "A&uthor", NULL, TAB_BOTTOM_NORMAL);
    TabLO1=    new FXHorizontalFrame(Tabber, LAYOUT_FILL|FRAME_GROOVE);
    (void)     new FXLabel(TabLO1, AUTHOR_FC, NULL, JUSTIFY_LEFT|ICON_BEFORE_TEXT);
               new FXTabItem(Tabber, "&Credits", NULL, TAB_BOTTOM_NORMAL);
    TabLO2=    new FXHorizontalFrame(Tabber, LAYOUT_FILL_X|LAYOUT_FILL_Y|FRAME_GROOVE);
    (void)     new FXLabel(TabLO2, CREDITS_FC, NULL, JUSTIFY_CENTER_X|JUSTIFY_CENTER_Y|ICON_BEFORE_TEXT);
    CmdBtnGrp= new FXHorizontalFrame(MainLO, LAYOUT_FILL_X|FRAME_NORMAL|LAYOUT_SIDE_BOTTOM);
               new FXButton(CmdBtnGrp, "&OK", OKCheck, this, FXDialogBox::ID_ACCEPT, BUTTON_NORMAL|LAYOUT_RIGHT);
}
//------------------------------------------------------------------------------
/*
       Name: ~TAbout

       Type: Sunroutine (Destructor)

       Parameters: (none)

       Note: Clean up objects FOX doesn't clean up for us
*/

TAbout::~TAbout(void)
{
    delete DolphinLogo;
    delete OKCheck;
    delete FreeMe;
}

//-------------------------------- tabout.cpp ----------------------------------
