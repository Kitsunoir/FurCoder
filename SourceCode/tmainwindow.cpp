//---------------------------- tmainwindow.cpp  ------------------------------

/***************************************************************************
                            -  Description
                             -------------------
    Begin                : 6 December, 2006
    Copyright            : (C) 2006 by Simo
    E-Mail               : simo (at) furrydolphin (dot) net
    Version              : 1.0.0
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

#include "tmainwindow.h"
#include "tabout.h"
#include "tspecialmsgbox.h"
#include "furcodeexternals.h"
#include "icons.h"
#include "locations.h"
#include <fox-1.6/FXRex.h>
#include <string.h>
#include <ctype.h>

//                            Declare Message/Target Event Handler Map

FXDEFMAP(TMainWindow) MWFunctionMap[]=
{
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_NEW,                                           TMainWindow::MainMenuUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_FILEOPEN,                                      TMainWindow::MainMenuUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_FILESAVE,                                      TMainWindow::MainMenuUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_PRINT,                                         TMainWindow::MainMenuUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_DECODE_OK,                                     TMainWindow::CommandBtnUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_ENCODE_OK,                                     TMainWindow::CommandBtnUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_NEXT,                                          TMainWindow::CommandBtnUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_CANCEL,                                        TMainWindow::CommandBtnUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_UPGRADE,                                       TMainWindow::GenOptSelectUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_APPROX,                                        TMainWindow::GenOptSelectUD),
    FXMAPFUNC(SEL_UPDATE,   TMainWindow::ID_PRO,                                           TMainWindow::GenOptSelectUD),
    FXMAPFUNCS(SEL_UPDATE,  TMainWindow::ID_THEME_NONE,    TMainWindow::ID_RLSL_PRI,       TMainWindow::OptionMenuUD),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_ART_OC,        TMainWindow::ID_ART_PRI,        TMainWindow::ArtOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_CONS_ORG,      TMainWindow::ID_CONS_PRI,       TMainWindow::ConsOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_HUGS_TF,       TMainWindow::ID_HUGS_PRI,       TMainWindow::HugOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_MUCK_AW,       TMainWindow::ID_MUCK_PRI,       TMainWindow::MuckOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_DRESS_FON,     TMainWindow::ID_DRESS_OWN,      TMainWindow::FursuitingClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_OPSYS_NONE,    TMainWindow::ID_OPSYS_WINX,     TMainWindow::OSChoicesClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_NET_WSC,       TMainWindow::ID_NET_WMF,        TMainWindow::InternetClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_PLUSH_STP,     TMainWindow::ID_PLUSH_PRI,      TMainWindow::PlushieOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_REAL_PHOTO,    TMainWindow::ID_REAL_PRI,       TMainWindow::RealismOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_TRANS_WAW,     TMainWindow::ID_TRANS_PRI,      TMainWindow::XformOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_WRITE_BSL,     TMainWindow::ID_WRITE_PRI,      TMainWindow::FanficOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_ZINES_PUB,     TMainWindow::ID_ZINES_PRI,      TMainWindow::ZinesOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_FURSEX_M,      TMainWindow::ID_FURSEX_PRI,     TMainWindow::FurrysexOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_YIFFRATE_WE,   TMainWindow::ID_YIFFRATE_DEC,   TMainWindow::YiffinessOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_RLAGE_SIXTY,   TMainWindow::ID_RLAGE_PRI,      TMainWindow::AgeOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_TECH_TM,       TMainWindow::ID_TECH_PRI,       TMainWindow::TechOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_GAME_PM,       TMainWindow::ID_GAME_PRI,       TMainWindow::GamesOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_EDU_PHD,       TMainWindow::ID_EDU_PRI,        TMainWindow::EduOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_RLFURRY_LS,    TMainWindow::ID_RLFURRY_PRI,    TMainWindow::RLFurrinessOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_HOUSE_MWC,     TMainWindow::ID_HOUSE_PRI,      TMainWindow::HousingOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_ANIME_OTK,     TMainWindow::ID_ANIME_PRI,      TMainWindow::AnimeOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_PETS_MOM,      TMainWindow::ID_PETS_PRI,       TMainWindow::PetsOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_RLGEN_M,       TMainWindow::ID_RLGEN_PRI,      TMainWindow::RLSexOptClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_RLSL_HHO,      TMainWindow::ID_RLSL_PRI,       TMainWindow::RLYiffinessOptClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_NEW,                                           TMainWindow::FileNewClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_FILEOPEN,                                      TMainWindow::FileOpenClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_FILESAVE,                                      TMainWindow::FileSaveClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_PRINT,                                         TMainWindow::FilePrintClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_EXIT,                                          TMainWindow::AppExitClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_MODE_DECODE,                                   TMainWindow::ModeDecodeClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_MODE_ENCODE,                                   TMainWindow::ModeEncodeClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_MODE_TOGGLE,                                   TMainWindow::ToggleModeClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_DECODE_OK,                                     TMainWindow::OKDecodeClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_ENCODE_OK,                                     TMainWindow::OKEncodeClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_CNTS,                                          TMainWindow::SpecialMsgsClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_ABOUT,                                         TMainWindow::SpecialMsgsClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_DOLPHINS,                                      TMainWindow::SpecialMsgsClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_NEXT,                                          TMainWindow::NextMenuPaneClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_CANCEL,                                        TMainWindow::ProjectXnlClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_UPGRADE,                                       TMainWindow::GenOptSelectClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_UNCERTAIN,                                     TMainWindow::GenOptSelectClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_APPROX,                                        TMainWindow::GenOptSelectClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_PRO,                                           TMainWindow::GenOptSelectClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_FURRATE,                                       TMainWindow::FurRateClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_SPECIES,                                       TMainWindow::SpeciesSelect),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_RLOCCUPATION,                                  TMainWindow::RLJobsSelect),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_THEME_NONE,    TMainWindow::ID_THEME_WINGED,   TMainWindow::ThemesClick),
    FXMAPFUNCS(SEL_COMMAND, TMainWindow::ID_RELATION_NONE, TMainWindow::ID_RELATION_WRITE, TMainWindow::RelationshipClick),
    FXMAPFUNC(SEL_COMMAND,  TMainWindow::ID_EXIT,                                          TMainWindow::AppExitClick),
    FXMAPFUNC(SEL_CHANGED,  TMainWindow::ID_FURCODE_LE,                                    TMainWindow::FurCodeLECNG),
    FXMAPFUNC(SEL_CLOSE,    TMainWindow::ID_TITLE,                                         TMainWindow::AppExitClick),
    FXMAPFUNC(SEL_SIGNAL,   TMainWindow::ID_EXIT,                                          TMainWindow::AppExitClick)
};

FXIMPLEMENT(TMainWindow, FXMainWindow, MWFunctionMap, ARRAYNUMBER(MWFunctionMap))

TMainWindow::TMainWindow(FXApp *aApp) :
    FXMainWindow(aApp, "FurCoderCXX",  NULL, NULL, DECOR_ALL, 0, 0, 990, 600),
FileSaved(TRUE),
MainMode(DECODE_MODE),
ProjectStatus(NO_PROJECT),
SectionStatus(SECTION_START),
MenuFrameIndex(THEMES),
ThisApp(aApp)
{

//             Declare pointers to layouts

    FXMenuBar         *MainMenu;
    FXMenuPane        *FileMain, *EditMain, *ModeMain, *HelpMain;
    FXToolBarShell    *MenuSh, *TBSh;
    FXToolBar         *MWTb;
    FXVerticalFrame   *MainLO;
    FXSplitter        *SubLO;
    FXHorizontalFrame *CodeViewLO, *CmdBtnLO;
    FXGroupBox        *OptionsGB;
    FXMatrix          *Grid0,  *Grid1, *Grid2, *Grid3, *Grid4, *Grid5;

/*
            Note: Normally, don't declare widgets as local
                  subroutine variables. However, since the FOX
		  option menu buttons don't have a handle for
		  messageing, we need to store the pointers to
		  call ancestor methods to enable/disable these
		  menu buttons.

		  Declare as FXObject* since there are more than one
		  type of widget in the master list. Use common
		  ancestor type, call FXObject::handle on them to
		  perform the enabling/disabling.
*/

    FXObject *Themes,      *Relations,   *Art,            *Cons,        *Fursuiting, *Contact,
             *Mucking,     *Plushies,    *Realism,        *Transform,   *Fanfic,     *Fanzines,
	     *FurryGender, *YiffRating,  *RLAge,          *TechSavvy,   *OpSys,      *Games,
	     *Education,   *RLFurriness, *Housing,        *Internet,    *Anime,      *Pets,
	     *RLGender,    *RLSexlife,   *FurrySpeciesCB, *FurryJobsCB, *FurRateSB;

//         Initialize pointer matrix to NULL

    for (int i= 0; i < NO_OPTION_PANES; i++)
    {
	for(int j= 0; j < NO_OPTION_PANES; j++) OptMenuList[i][j]= 0;
    }

    FXMenuCommand *EditTextCut, *EditTextCopy, *EditTextPaste, *EditTextDelete;
    FXButton      *EditCutTBB, *EditCopyTBB, *EditPasteTBB, *EditDeleteTBB;

//        Initialize Main Window Icons from Resource

    FileOpenIco=    new FXXPMIcon(ThisApp, fileopen_xpm);
    FileSaveAsIco=  new FXXPMIcon(ThisApp, filesaveas_xpm);
    FilePrintIco=   new FXXPMIcon(ThisApp, fileprint_xpm);
    EditCutIco=     new FXXPMIcon(ThisApp, editcut_xpm);
    EditCopyIco=    new FXXPMIcon(ThisApp, editcopy_xpm);
    EditPasteIco=   new FXXPMIcon(ThisApp, editpaste_xpm);
    EditDeleteIco=  new FXXPMIcon(ThisApp, editdelete_xpm);
    DolphinLogoIco= new FXXPMIcon(ThisApp, smDolphin_xpm);
    AboutIco=       new FXXPMIcon(ThisApp, about_xpm);
    HelpIco=        new FXXPMIcon(ThisApp, help_xpm);
    NextArrowIco=   new FXXPMIcon(ThisApp, RtArrow_xpm);
    OKCheckIco=     new FXXPMIcon(ThisApp, OKCheck_xpm);
    CancelXIco=     new FXXPMIcon(ThisApp, CancelX_xpm);
    ExitIco=        new FXXPMIcon(ThisApp, Exit_xpm);
    ToggleIco=      new FXXPMIcon(ThisApp, toggle_xpm);
    NewIco=         new FXXPMIcon(ThisApp, New_xpm);

    setIcon(DolphinLogoIco);      //  Set Application Icons
    setMiniIcon(DolphinLogoIco);

//            Set targets and signals: Allow the application to be closed from the title bar

    setTarget(this);
    setSelector(ID_TITLE);

//                                           Create the Main Menu

    MenuSh=         new FXToolBarShell(this, FRAME_RAISED);
    MainMenu=       new FXMenuBar(this, MenuSh, LAYOUT_SIDE_TOP|LAYOUT_FILL_X|FRAME_RAISED);
                    new FXToolBarGrip(MainMenu, MainMenu, FXMenuBar::ID_TOOLBARGRIP, TOOLBARGRIP_DOUBLE);

    FileMain=       new FXMenuPane(this);
	            new FXMenuTitle(MainMenu, "&File", NULL, FileMain);
	            new FXMenuCommand(FileMain, "&New Project", NULL, this, ID_NEW);
	            new FXMenuSeparator(FileMain);
	            new FXMenuCommand(FileMain, "&Open...", NULL, this, ID_FILEOPEN);
	            new FXMenuCommand(FileMain, "&Save As...", NULL, this, ID_FILESAVE);
	            new FXMenuSeparator(FileMain);
	            new FXMenuCommand(FileMain, "&Exit...", NULL, this, ID_EXIT);

    EditMain=       new FXMenuPane(this);
                    new FXMenuTitle(MainMenu, "&Edit", NULL, EditMain);
    EditTextCut=    new FXMenuCommand(EditMain, "C&ut", NULL, NULL, 0);
    EditTextCopy=   new FXMenuCommand(EditMain, "C&opy", NULL, NULL, 0);
    EditTextPaste=  new FXMenuCommand(EditMain, "&Paste", NULL, NULL, 0);
    EditTextDelete= new FXMenuCommand(EditMain, "&Delete", NULL, NULL, 0);

    ModeMain=       new FXMenuPane(this);
                    new FXMenuTitle(MainMenu, "&Mode", NULL, ModeMain);
		    new FXMenuCommand(ModeMain, "&Encode", NULL, this, ID_MODE_ENCODE);
		    new FXMenuCommand(ModeMain, "&Decode", NULL, this, ID_MODE_DECODE);

    HelpMain=       new FXMenuPane(this);
                    new FXMenuTitle(MainMenu, "&Help", NULL, HelpMain, LAYOUT_RIGHT);
                    new FXMenuCommand(HelpMain, "&Contents...", NULL, this, ID_CNTS);
                    new FXMenuCommand(HelpMain, "&About...", NULL, this, ID_ABOUT);
                    new FXMenuSeparator(HelpMain);
                    new FXMenuCommand(HelpMain, "&Dolphins...", NULL, this, ID_DOLPHINS);

/*
                                          Main Window Status Bar

				   Note: Create now: needed for verbose tooltips.
				   *) Add special button
				   *) Add static text label
				   *) Add dynamic mode ident label
*/

    MWStatus=  new FXStatusBar(this, LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|STATUSBAR_WITH_DRAGCORNER|FRAME_RAISED);

               new FXButton(MWStatus,"\tClick Me!\tAn important message for you",
			    DolphinLogoIco, this, ID_DOLPHINS, LAYOUT_FILL_Y|LAYOUT_RIGHT);

    (void)     new FXLabel(MWStatus, "Application Mode", NULL, JUSTIFY_RIGHT|FRAME_NONE);
    ModeLbl=   new FXLabel(MWStatus, "Decode:No Fur Code Loaded", NULL, LABEL_NORMAL|FRAME_NORMAL);

/*
                                        Create the Main Window Toolbar

					*) New Project
					*) File Open
					*) File Save
					*) File Print
					*) On-line Help
					*) Invoke "About" Box
					*) Encode/Decode Toggle Button
					*) Connect the tooltip "balloons" to main
					   application object.
*/

    TBSh=          new FXToolBarShell(this, FRAME_RAISED);
    MWTb=          new FXToolBar(this, TBSh, LAYOUT_SIDE_TOP|LAYOUT_FILL_X|FRAME_RAISED);
                   new FXToolBarGrip(MWTb, MWTb, FXToolBar::ID_TOOLBARGRIP, TOOLBARGRIP_DOUBLE);

		   new FXButton(MWTb, "\tNew Project\tStart a new Fur Coder project", NewIco, this, ID_NEW,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

		   new FXButton(MWTb, "\tOpen...\tOpen a file for reading", FileOpenIco, this, ID_FILEOPEN,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

                   new FXButton(MWTb, "\tSave As...\tSave your Furry code to disk", FileSaveAsIco, this, ID_FILESAVE,
		             ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

		   new FXButton(MWTb, "\tPrint...\tPrint the current project", FilePrintIco, this, ID_PRINT,
				ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

                   new FXFrame(MWTb, FRAME_SUNKEN|LAYOUT_CENTER_Y|LAYOUT_FIX_HEIGHT|LAYOUT_FIX_WIDTH, 0, 0, 2, 22);

    EditCutTBB=    new FXButton(MWTb, "\tCut\tCut Fur Code to clipboard", EditCutIco, NULL, 0,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

    EditCopyTBB=   new FXButton(MWTb, "\tCopy\tCopy Fur Code to clipboard", EditCopyIco, NULL, 0,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

    EditPasteTBB=  new FXButton(MWTb, "\tPaste\tPaste to the Fur Code line edit from clipboard", EditPasteIco, NULL, 0,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

    EditDeleteTBB= new FXButton(MWTb, "\tDelete\tDelete the selection from Fur Code line edit", EditDeleteIco, NULL, 0,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

		   new FXFrame(MWTb, FRAME_SUNKEN|LAYOUT_CENTER_Y|LAYOUT_FIX_HEIGHT|LAYOUT_FIX_WIDTH, 0, 0, 2, 22);

		   new FXButton(MWTb, "\tToggle\tToggle the application mode", ToggleIco, this, ID_MODE_TOGGLE,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y|LAYOUT_SIDE_LEFT);

                   new FXFrame(MWTb, FRAME_SUNKEN|LAYOUT_CENTER_Y|LAYOUT_FIX_HEIGHT|LAYOUT_FIX_WIDTH, 0, 0, 2, 22);

                   new FXButton(MWTb, "\tOn-line help...\tInvoke the on-line help", HelpIco, this, ID_CNTS,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y);

                   new FXButton(MWTb, "\tAbout...\tInvoke the application \"About\" Box", AboutIco, this, ID_ABOUT,
			       ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_CENTER_Y);

                   new FXToolTip(aApp);

//                                                Main Window Layouts

    MainLO=      new FXVerticalFrame(this, LAYOUT_SIDE_TOP|LAYOUT_FILL|FRAME_NORMAL);
    FurCodeLE=   new FXTextField(MainLO, 128, this, ID_FURCODE_LE, TEXTFIELD_NORMAL);

    SubLO=       new FXSplitter(MainLO, SPLITTER_HORIZONTAL|SPLITTER_TRACKING|LAYOUT_FILL|FRAME_NONE);
    MenuFrame=   new FXSwitcher(SubLO, SWITCHER_VCOLLAPSE|LAYOUT_FILL|FRAME_NORMAL);
    OptionFrame= new FXSwitcher(SubLO, SWITCHER_VCOLLAPSE|LAYOUT_FILL|FRAME_NORMAL);

//                 Initialize the pop up menu panes and attach the menu commands

    for (int i= 0; i < NO_OPTIONS; i++) PopPanes[i]= new FXPopup(this);

    new FXOption(PopPanes[0], "None", NULL, this, ID_THEME_NONE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Cyborg", NULL, this,ID_THEME_CYBORG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "'Toon", NULL, this, ID_THEME_TOON, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Were-Animal", NULL, this, ID_THEME_WERE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Magical Powers", NULL, this, ID_THEME_MAGIC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Polymorphic", NULL, this, ID_THEME_POLY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Psychic Powers", NULL, this, ID_THEME_PSI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "'Taur", NULL, this, ID_THEME_TAUR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Unicorn", NULL, this, ID_THEME_UNICORN, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[0], "Winged", NULL, this, ID_THEME_WINGED, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[1], "None", NULL, this, ID_RELATION_NONE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Alter Ego", NULL, this, ID_RELATION_AE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Fursuit Character", NULL, this, ID_RELATION_FC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Someone to Draw", NULL, this, ID_RELATION_DRAW, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Imaginary Friend", NULL, this, ID_RELATION_IF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "On-Line Character", NULL, this, ID_RELATION_OLC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Role-Play Character", NULL, this, ID_RELATION_RPC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Totem/Spirit Animal", NULL, this, ID_RELATION_TSA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[1], "Someone to Write About", NULL, this, ID_RELATION_WRITE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[2], "Obsessive-Compulsive", NULL, this, ID_ART_OC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Have Art Published Regularly", NULL, this, ID_ART_PR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Have Art Published Occasionally", NULL, this, ID_ART_PO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "I Draw Regularly", NULL, this, ID_ART_DR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Draw for Others", NULL, this, ID_ART_FC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Draw for Myself", NULL, this, ID_ART_FM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Never Tried Furry Art", NULL, this, ID_ART_NTFA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Can't Draw a Straight Line", NULL, this, ID_ART_CDASL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Declined", NULL, this, ID_ART_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[2], "Private", NULL, this, ID_ART_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[3], "Been to Lots/Organizer", NULL, this, ID_CONS_ORG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Regular Atendee", NULL, this, ID_CONS_RA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Been to 2 or More", NULL, this, ID_CONS_MORE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Been to One", NULL, this, ID_CONS_ONE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Not Yet, But Soon", NULL, this, ID_CONS_NY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Not Interested", NULL, this, ID_CONS_NI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Absolutely Not!", NULL, this, ID_CONS_AN, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Sci-Fi Cons Only", NULL, this, ID_CONS_SFONLY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Sci-Fi Con Organizer", NULL, this, ID_CONS_SFORG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Declined", NULL, this, ID_CONS_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[3], "Private", NULL, this, ID_CONS_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[4], "Fursuit or Nudity", NULL, this, ID_DRESS_FON, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "Every Chance I Get", NULL, this, ID_DRESS_EC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "At Cons/Events where not Uncommon", NULL, this, ID_DRESS_ACNU, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "At Masquerades Where Expected", NULL, this, ID_DRESS_AM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "Thinking About It", NULL, this, ID_DRESS_TAI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "Only if My Life Depended on It...", NULL, this, ID_DRESS_REL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "...Not Even Then", NULL, this, ID_DRESS_NET, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "Declined", NULL, this, ID_DRESS_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "Private", NULL, this, ID_DRESS_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[4], "Option: Made Own Fursuit", NULL, this, ID_DRESS_OWN, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[5], "Extremely Touchy-Feely", NULL, this, ID_HUGS_TF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "Hug Close Friends", NULL, this, ID_HUGS_CF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "Accept Hugs; May Give", NULL, this, ID_HUGS_AMG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "If I Have To...", NULL, this, ID_HUGS_IIHT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "Not Till I Know You Better", NULL, this, ID_HUGS_NKYB, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "No Way!", NULL, this, ID_HUGS_NW, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "Stay Away!", NULL, this, ID_HUGS_SA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "Declined", NULL, this, ID_HUGS_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[5], "Private", NULL, this, ID_HUGS_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[6], "A Wizard!", NULL, this, ID_MUCK_AW, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "May Give Real Life a Go", NULL, this, ID_MUCK_MGRL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Several Chars on Different MU*'s", NULL, this, ID_MUCK_SC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Regular on One MU*", NULL, this, ID_MUCK_REG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Occasionally", NULL, this, ID_MUCK_OCC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Perhaps...", NULL, this, ID_MUCK_PER, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "I'm too Kewel for That", NULL, this, ID_MUCK_TKFT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Get a Life, Luser!", NULL, this, ID_MUCK_GAL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Declined", NULL, this, ID_MUCK_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[6], "Private", NULL, this, ID_MUCK_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[7], "Built a Shrine to Plushies", NULL, this, ID_PLUSH_STP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Species Specific Collector", NULL, this, ID_PLUSH_SSC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Have Some Favs", NULL, this, ID_PLUSH_HSF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Snuggle Some Occasionally", NULL, this, ID_PLUSH_SSO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Decorations Only", NULL, this, ID_PLUSH_DO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Useless Dust Collectors", NULL, this, ID_PLUSH_UDC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Act Your Age!", NULL, this, ID_PLUSH_AYA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Declined", NULL, this, ID_PLUSH_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[7], "Private", NULL, this, ID_PLUSH_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[8], "Photographic", NULL, this, ID_REAL_PHOTO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Anatomically Accurate", NULL, this, ID_REAL_AA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Prefer Realistic Furry", NULL, this, ID_REAL_PRF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "No Preference", NULL, this, ID_REAL_NP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Prefer 'Toons", NULL, this, ID_REAL_PT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Very 'Toonie", NULL, this, ID_REAL_VT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Totally Abstract", NULL, this, ID_REAL_TA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Declined", NULL, this, ID_REAL_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[8], "Private", NULL, this, ID_REAL_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[9], "Tell Me Where & When", NULL, this, ID_TRANS_WAW, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "If I Can Choose Species", NULL, this, ID_TRANS_CS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "Only If Reversable", NULL, this, ID_TRANS_IR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "A Definite Maybe", NULL, this, ID_TRANS_DM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "Better Think About It", NULL, this, ID_TRANS_TAI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "Being Human Ain't Half-bad", NULL, this, ID_TRANS_HUM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "A Really, Really Bad Idea", NULL, this, ID_TRANS_BI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "Declined", NULL, this, ID_TRANS_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[9], "Private", NULL, this, ID_TRANS_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[10], "Best Seller List", NULL, this, ID_WRITE_BSL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Sold a Book", NULL, this, ID_WRITE_SAB, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Sold to Major Magazine", NULL, this, ID_WRITE_SMM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Sold to Fan-zine", NULL, this, ID_WRITE_SFM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Write for Others", NULL, this, ID_WRITE_WFO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Write for Self", NULL, this, ID_WRITE_WFS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "No Creative Writing", NULL, this, ID_WRITE_NOW, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Functional Illiterate", NULL, this, ID_WRITE_FI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Best Seller List (Non-furry)", NULL, this, ID_WRITE_NFBSL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Sold a non-furry book", NULL, this, ID_WRITE_NFB, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Sold non-furry story", NULL, this, ID_WRITE_NFS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Sold to non-furry fan-zine", NULL, this, ID_WRITE_NFM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Declined", NULL, this, ID_WRITE_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[10], "Private", NULL, this, ID_WRITE_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[11], "Publisher", NULL, this, ID_ZINES_PUB, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Regular Contributor", NULL, this, ID_ZINES_RC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Been Published", NULL, this, ID_ZINES_BP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Buy Regularly", NULL, this, ID_ZINES_REG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Buy Occasionally", NULL, this, ID_ZINES_OCC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Not Interested", NULL, this, ID_ZINES_NOINT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Kids' Stuff!", NULL, this, ID_ZINES_KS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Declined", NULL, this, ID_ZINES_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[11], "Private", NULL, this, ID_ZINES_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[12], "Male", NULL, this, ID_FURSEX_M, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[12], "Female", NULL, this, ID_FURSEX_F, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[12], "Hermaphrodite", NULL, this, ID_FURSEX_H, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[12], "Polymorphic", NULL, this, ID_FURSEX_P, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[12], "Declined", NULL, this, ID_FURSEX_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[12], "Private", NULL, this, ID_FURSEX_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[13], "What Else?(!)", NULL, this, ID_YIFFRATE_WE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[13], "Ready, Willing & Able", NULL, this, ID_YIFFRATE_RWA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[13], "Cyber Sex Regularly", NULL, this, ID_YIFFRATE_CSR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[13], "May Try It", NULL, this, ID_YIFFRATE_MTE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[13], "Monk/Nun", NULL, this, ID_YIFFRATE_NOWE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[13], "WHUDDABUNCHA PERVS!", NULL, this, ID_YIFFRATE_WBP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[13], "Private", NULL, this, ID_YIFFRATE_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[14], "60+", NULL, this, ID_RLAGE_SIXTY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "50 - 59", NULL, this, ID_RLAGE_FIFTY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "40 - 49", NULL, this, ID_RLAGE_FORTY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "30 - 39", NULL, this, ID_RLAGE_THIRTY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "20 - 29", NULL, this, ID_RLAGE_TWENTY, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "10 - 19", NULL, this, ID_RLAGE_TEN, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "Under 10", NULL, this, ID_RLAGE_LESSTEN, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "Declined", NULL, this, ID_RLAGE_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[14], "Private", NULL, this, ID_RLAGE_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[15], "Master Hacker", NULL, this, ID_TECH_TM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "What's real life?", NULL, this, ID_TECH_RL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Programmer", NULL, this, ID_TECH_PRO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Easily Master Soft", NULL, this, ID_TECH_EMS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Just Another Tool", NULL, this, ID_TECH_JAT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Blinking 12:00 Person", NULL, this, ID_TECH_BTP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "How Do You Turn It On?", NULL, this, ID_TECH_HDYTIO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Luddite", NULL, this, ID_TECH_LUDD, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Declined", NULL, this, ID_TECH_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[15], "Private", NULL, this, ID_TECH_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[16], "No Preference/Next Menu", NULL, this, ID_OPSYS_NONE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "AmigaOS", NULL, this, ID_OPSYS_AMG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "*BSD", NULL, this, ID_OPSYS_BSD, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "DOS", NULL, this, ID_OPSYS_DOS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "Linux", NULL, this, ID_OPSYS_LIN, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "OS X", NULL, this, ID_OPSYS_OSX, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "Win 9x/NT/XP", NULL, this, ID_OPSYS_WINXP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "OS/2", NULL, this, ID_OPSYS_OST, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "UNIX", NULL, this, ID_OPSYS_UNI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "VMS", NULL, this, ID_OPSYS_VMS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[16], "Win 3.x", NULL, this, ID_OPSYS_WINX, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[17], "Phear ME!", NULL, this, ID_GAME_PM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "Master 'Nightmare Mode' Easily", NULL, this, ID_GAME_MNE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "Pretty Good", NULL, this, ID_GAME_PG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "OK", NULL, this, ID_GAME_OK, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "I've Tried It: NBD", NULL, this, ID_GAME_ITI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "Didn't Like It", NULL, this, ID_GAME_DLI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "I Miss Pac-Man", NULL, this, ID_GAME_MFM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "WHUDDA WASTEA TIME!", NULL, this, ID_GAME_WWT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "Declined", NULL, this, ID_GAME_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[17], "Private", NULL, this, ID_GAME_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[18], "PhD", NULL, this, ID_EDU_PHD, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "Master's", NULL, this, ID_EDU_MS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "Bachelor's", NULL, this, ID_EDU_BS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "Associate's", NULL, this, ID_EDU_AS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "H.S.Grad", NULL, this, ID_EDU_HS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "H.S. Incomplete", NULL, this, ID_EDU_HSI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "6th Grade+", NULL, this, ID_EDU_GS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "G.S. Incomplete", NULL, this, ID_EDU_GSI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "Completely Self-Taught", NULL, this, ID_EDU_CST, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "Declined", NULL, this, ID_EDU_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[18], "Private", NULL, this, ID_EDU_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[19], "Life Styler", NULL, this, ID_RLFURRY_LS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Bark/Yerf/Meow @ Everyone", NULL, this, ID_RLFURRY_BYM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Bark @ Friends Only", NULL, this, ID_RLFURRY_BFO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Own My Furriness", NULL, this, ID_RLFURRY_OMF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Don't Ask; Don't Tell", NULL, this, ID_RLFURRY_DADT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Tell Close Friends", NULL, this, ID_RLFURRY_TCF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Tell No One", NULL, this, ID_RLFURRY_TNO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Declined", NULL, this, ID_RLFURRY_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[19], "Private", NULL, this, ID_RLFURRY_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[20], "Married with Children", NULL, this, ID_HOUSE_MWC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Married: DINKs", NULL, this, ID_HOUSE_MDS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Furry Roommates", NULL, this, ID_HOUSE_FRM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Non-Furry Roommates", NULL, this, ID_HOUSE_NFRM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Living Alone: Social Life", NULL, this, ID_HOUSE_LASL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Living Alone: No Social Life", NULL, this, ID_HOUSE_LANSL, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Agoraphobic", NULL, this, ID_HOUSE_AGOR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Living with Parents", NULL, this, ID_HOUSE_LWP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Not Settled Anywhere", NULL, this, ID_HOUSE_NSA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Homeless", NULL, this, ID_HOUSE_LESS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Declined", NULL, this, ID_HOUSE_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[20], "Private", NULL, this, ID_HOUSE_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[21], "Web Master/Misress", NULL, this, ID_NET_WSC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Web Surf Regularly", NULL, this, ID_NET_WSR, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Web Surf Occasionally", NULL, this, ID_NET_WSO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "No ISP Connection", NULL, this, ID_NET_NCISP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Gates was Right: WWW Suxxors", NULL, this, ID_NET_SUX, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Silicon Snake Oil", NULL, this, ID_NET_SSO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Ban teh webs!", NULL, this, ID_NET_DSP, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Declined", NULL, this, ID_NET_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Private", NULL, this, ID_NET_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Option: Own Furry Site", NULL, this, ID_NET_WMFS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[21], "Option: Own Web Site", NULL, this, ID_NET_WMF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[22], "Otaku", NULL, this, ID_ANIME_OTK, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Record Every Episode", NULL, this, ID_ANIME_REE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Second only to Fur-dom", NULL, this, ID_ANIME_SOTF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Known Anime/Furry Fan", NULL, this, ID_ANIME_KAF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Seen It: NBD", NULL, this, ID_ANIME_NBD, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Not Seen It: Curious", NULL, this, ID_ANIME_NOTYET, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Huh????", NULL, this, ID_ANIME_HUH, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "YYYYEEEECCCCHHHH!!!!", NULL, this, ID_ANIME_YECH, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Only if Translated into English", NULL, this, ID_ANIME_INENG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Declined", NULL, this, ID_ANIME_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[22], "Private", NULL, this, ID_ANIME_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[23], "My Own Menagerie", NULL, this, ID_PETS_MOM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Several Exotics", NULL, this, ID_PETS_SE, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "2 - 3 Conventional or 1 Exotic", NULL, this, ID_PETS_OONUS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "One Conventional", NULL, this, ID_PETS_ONECON, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Had/Will Get", NULL, this, ID_PETS_HWG, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Can't Care for Pets Properly Now", NULL, this, ID_PETS_CANT, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "YECH! (Sure You're a Furry?)", NULL, this, ID_PETS_YECH, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Want One: Not Allowed", NULL, this, ID_PETS_WONA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Can't Have: Allergic", NULL, this, ID_PETS_CHA, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Declined", NULL, this, ID_PETS_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[23], "Private", NULL, this, ID_PETS_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[24], "Male", NULL, this, ID_RLGEN_M, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[24], "Female", NULL, this, ID_RLGEN_F, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[24], "Declined", NULL, this, ID_RLGEN_DEC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[24], "Private", NULL, this, ID_RLGEN_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    new FXOption(PopPanes[25], "Hornier 'n' a Hoot Owl", NULL, this, ID_RLSL_HHO, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "I Can Be Had", NULL, this, ID_RLSL_CBH, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "I've Done \"It\"", NULL, this, ID_RLSL_DI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "At Least not a Virgin", NULL, this, ID_RLSL_NAV, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "Saving Myself For...", NULL, this, ID_RLSL_SMF, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "Can't Get No Satisfaction", NULL, this, ID_RLSL_CONS, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "I Prefer Mytosis", NULL, this, ID_RLSL_IPM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "Faithfully Married", NULL, this, ID_RLSL_FM, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "Married with Children", NULL, this, ID_RLSL_FMWC, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    new FXOption(PopPanes[25], "Private", NULL, this, ID_RLSL_PRI, JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

/*

------------------------- Create the Option Menu Buttons ------------------------
 
          Create option menu buttons, connect event handlers, populate the
          Layouts and the "MenuFrame"  windows.
*/

//			Furry/Themes Select Sub-Window (THEMES)

    Grid0= new FXMatrix(MenuFrame, 4, MATRIX_BY_ROWS|PACK_UNIFORM_WIDTH);

    FurrySpeciesCB= new FXComboBox(Grid0, 30, this, ID_SPECIES, COMBOBOX_STATIC|FRAME_THICK|FRAME_SUNKEN);
    Themes=         new FXOptionMenu(Grid0, PopPanes[0], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    FurRateSB=      new FXSpinner(Grid0, 5, this, ID_FURRATE, SPIN_CYCLIC|FRAME_SUNKEN|FRAME_THICK);
    Relations=      new FXOptionMenu(Grid0, PopPanes[1], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    (void)          new FXLabel(Grid0, "Select Type of Furry");
    (void)          new FXLabel(Grid0, "Themes");
    FurrinessLbl=   new FXLabel(Grid0, "How Furry?");
    (void)          new FXLabel(Grid0, "Relationship");

    ((FXSpinner*)FurRateSB)->setRange(0, 6);
    ((FXComboBox*)FurrySpeciesCB)->setNumVisible(15);

//                      Furry Participation Window (PARTICIPATION)

    Grid1= new FXMatrix(MenuFrame, 5, MATRIX_BY_ROWS|PACK_UNIFORM_WIDTH);

    (void)      new FXLabel(Grid1, "Art");
    (void)      new FXLabel(Grid1, "Conventions");
    (void)      new FXLabel(Grid1, "Fursuiting");
    (void)      new FXLabel(Grid1, "Contact");
    (void)      new FXLabel(Grid1, "MUCKING");
    Art=        new FXOptionMenu(Grid1, PopPanes[2], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Cons=       new FXOptionMenu(Grid1, PopPanes[3], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Fursuiting= new FXOptionMenu(Grid1, PopPanes[4], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Contact=    new FXOptionMenu(Grid1, PopPanes[5], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Mucking=    new FXOptionMenu(Grid1, PopPanes[6], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

//                      Furry "Realism" Window (REALISM)

    Grid2= new FXMatrix(MenuFrame, 5, MATRIX_BY_ROWS|PACK_UNIFORM_WIDTH);

    (void)     new FXLabel(Grid2, "Plushies");
    (void)     new FXLabel(Grid2, "Realism");
    (void)     new FXLabel(Grid2, "Transformations");
    (void)     new FXLabel(Grid2, "Fan-Fic");
    (void)     new FXLabel(Grid2, "Fan-zines");
    Plushies=  new FXOptionMenu(Grid2, PopPanes[7], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Realism=   new FXOptionMenu(Grid2, PopPanes[8], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Transform= new FXOptionMenu(Grid2, PopPanes[9], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Fanfic=    new FXOptionMenu(Grid2, PopPanes[10], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Fanzines=  new FXOptionMenu(Grid2, PopPanes[11], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

//			You and Your Furry Window (PREFERENCES)

    Grid3= new FXMatrix(MenuFrame, 6, MATRIX_BY_ROWS|PACK_UNIFORM_WIDTH);

    (void)       new FXLabel(Grid3, "Furry's Gender");
    (void)       new FXLabel(Grid3, "Furry's Yiffiness");
    (void)       new FXLabel(Grid3, "Your Occupation");
    (void)       new FXLabel(Grid3, "Your Age");
    (void)       new FXLabel(Grid3, "Tech Savvy");
    (void)       new FXLabel(Grid3, "Op-Sys You Use");
    FurryGender= new FXOptionMenu(Grid3, PopPanes[12], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    YiffRating=  new FXOptionMenu(Grid3, PopPanes[13], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    FurryJobsCB= new FXComboBox(Grid3, 30, this, ID_RLOCCUPATION, COMBOBOX_STATIC|FRAME_SUNKEN|FRAME_THICK);
    RLAge=       new FXOptionMenu(Grid3, PopPanes[14], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    TechSavvy=   new FXOptionMenu(Grid3, PopPanes[15], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    OpSys=       new FXOptionMenu(Grid3, PopPanes[16], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

    ((FXComboBox*)FurryJobsCB)->setNumVisible(15);

//			Your Real Life Window (REALLIFE)

    Grid4= new FXMatrix(MenuFrame, 4, MATRIX_BY_ROWS|PACK_UNIFORM_WIDTH);

    (void)       new FXLabel(Grid4, "Games");
    (void)       new FXLabel(Grid4, "Education");
    (void)       new FXLabel(Grid4, "Real-life Furriness");
    (void)       new FXLabel(Grid4, "Housing");
    Games=       new FXOptionMenu(Grid4, PopPanes[17], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Education=   new FXOptionMenu(Grid4, PopPanes[18], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    RLFurriness= new FXOptionMenu(Grid4, PopPanes[19], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Housing=     new FXOptionMenu(Grid4, PopPanes[20], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

//			Your Outside Interests Window (INTERESTS)

    Grid5= new FXMatrix(MenuFrame, 5, MATRIX_BY_ROWS|PACK_UNIFORM_WIDTH);

    (void)     new FXLabel(Grid5, "Internet");
    (void)     new FXLabel(Grid5, "Anime");
    (void)     new FXLabel(Grid5, "Pets");
    (void)     new FXLabel(Grid5, "Your Gender");
    (void)     new FXLabel(Grid5, "Personal Yiffiness");
    Internet=  new FXOptionMenu(Grid5, PopPanes[21], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Anime=     new FXOptionMenu(Grid5, PopPanes[22], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    Pets=      new FXOptionMenu(Grid5, PopPanes[23], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    RLGender=  new FXOptionMenu(Grid5, PopPanes[24], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);
    RLSexlife= new FXOptionMenu(Grid5, PopPanes[25], FRAME_RAISED|FRAME_THICK|JUSTIFY_HZ_APART|ICON_AFTER_TEXT);

/*
       Initialize the Option Menu master list.

       Note: This becomes necessary as the option menu buttons themselves
             do not have a handle to receive messages. Must enable/disable
	     by calling the ancestor methods directly.

	     Store the pointers as FXObject*, and cast to type as needed.
*/

    FXuint Index= THEMES - THEMES;           //   THEMES Pane
    OptMenuList[Index][0]= FurrySpeciesCB;
    OptMenuList[Index][1]= Themes;
    OptMenuList[Index][2]= FurRateSB;
    OptMenuList[Index][3]= Relations;

    Index= PARTICIPATION - THEMES;           //   PARTICIPATION Pane
    OptMenuList[Index][0]= Art;
    OptMenuList[Index][1]= Cons;
    OptMenuList[Index][2]= Fursuiting;
    OptMenuList[Index][3]= Contact;
    OptMenuList[Index][4]= Mucking;

    Index= REALISM - THEMES;                 //   REALISM Pane
    OptMenuList[Index][0]= Plushies;
    OptMenuList[Index][1]= Realism;
    OptMenuList[Index][2]= Transform;
    OptMenuList[Index][3]= Fanfic;
    OptMenuList[Index][4]= Fanzines;

    Index= PREFERENCES - THEMES;             //   PREFERENCES Pane
    OptMenuList[Index][0]= FurryGender;
    OptMenuList[Index][1]= YiffRating;
    OptMenuList[Index][2]= FurryJobsCB;
    OptMenuList[Index][3]= RLAge;
    OptMenuList[Index][4]= TechSavvy;
    OptMenuList[Index][5]= OpSys;

    Index= REALLIFE - THEMES;                //   REALLIFE Pane
    OptMenuList[Index][0]= Games;
    OptMenuList[Index][1]= Education;
    OptMenuList[Index][2]= RLFurriness;
    OptMenuList[Index][3]= Housing;

    Index= INTERESTS - THEMES;               //   INTERESTS Pane
    OptMenuList[Index][0]= Internet;
    OptMenuList[Index][1]= Anime;
    OptMenuList[Index][2]= Pets;
    OptMenuList[Index][3]= RLGender;
    OptMenuList[Index][4]= RLSexlife;

//       Create layouts: populate the "OptionFrame" (First Window: Decode Mode)

    CodeViewLO=    new FXHorizontalFrame(OptionFrame, LAYOUT_FILL|FRAME_NORMAL);
    FurDecodeView= new FXText(CodeViewLO, NULL, 0, TEXT_WORDWRAP|TEXT_READONLY|LAYOUT_FILL);

//       Create layouts: populate the "OptionFrame" (Second Window: Encode Mode)

    OptionsGB=   new FXGroupBox(OptionFrame, "General Options", GROUPBOX_NORMAL|FRAME_GROOVE|PACK_UNIFORM_WIDTH);
	         new FXButton(OptionsGB, "Upgrade in Future", NULL, this, ID_UPGRADE);
		 new FXButton(OptionsGB, "Uncertain", NULL, this, ID_UNCERTAIN);
	         new FXButton(OptionsGB, "Approximate", NULL, this, ID_APPROX);
	         new FXButton(OptionsGB, "Professional", NULL, this, ID_PRO);

//                             Create Layouts: Command Button Group

    CmdBtnLO= new FXHorizontalFrame(MainLO, LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|FRAME_NORMAL);
              new FXButton(CmdBtnLO, "&Next", NextArrowIco, this, ID_NEXT, BUTTON_NORMAL|ICON_BEFORE_TEXT);
    OKCmdBtn= new FXButton(CmdBtnLO, "&OK", OKCheckIco, NULL, 0, BUTTON_NORMAL|ICON_BEFORE_TEXT);
              new FXButton(CmdBtnLO, "&Cancel", CancelXIco, this, ID_CANCEL, BUTTON_NORMAL|ICON_BEFORE_TEXT);
              new FXButton(CmdBtnLO, "&Exit", ExitIco, this, ID_EXIT, BUTTON_NORMAL|ICON_BEFORE_TEXT|LAYOUT_RIGHT);

/*
                     GUI Complete:

		     *) Connect the "edit" menu items and toolbar
		        buttons to targets and set the selectors
		     *) Disable option menu buttons
		     *) Initialize the mode check box
		     *) Read config files; add items to list boxes
		     *) Create a TheFurCode object (empty)
		     *) Create a Dictionary object (empty)
*/

    EditTextCut->setTarget(FurCodeLE);
    EditTextCut->setSelector(FXTextField::ID_CUT_SEL);

    EditTextCopy->setTarget(FurCodeLE);
    EditTextCopy->setSelector(FXTextField::ID_COPY_SEL);

    EditTextPaste->setTarget(FurCodeLE);
    EditTextPaste->setSelector(FXTextField::ID_PASTE_SEL);

    EditTextDelete->setTarget(FurCodeLE);
    EditTextDelete->setSelector(FXTextField::ID_DELETE_SEL);

    EditCutTBB->setTarget(FurCodeLE);
    EditCutTBB->setSelector(FXTextField::ID_CUT_SEL);

    EditCopyTBB->setTarget(FurCodeLE);
    EditCopyTBB->setSelector(FXTextField::ID_COPY_SEL);

    EditPasteTBB->setTarget(FurCodeLE);
    EditPasteTBB->setSelector(FXTextField::ID_PASTE_SEL);

    EditDeleteTBB->setTarget(FurCodeLE);
    EditDeleteTBB->setSelector(FXTextField::ID_DELETE_SEL);

    OKCmdBtn->setTarget(this);
    OKCmdBtn->setSelector(ID_DECODE_OK);

    for (int i= 0; i < NO_OPTION_PANES; i++)
    {
	for (int j= 0; j < NO_OPTION_PANES; j++)
	{
	    FXObject *Current= OptMenuList[i][j];
	    if (Current) Current->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	}
    }

    FurDecodeView->setMarginLeft(20);
    FurDecodeView->setMarginRight(20);
    FurDecodeView->setMarginTop(10);
    FurDecodeView->setMarginBottom(10);
    FurDecodeView->setTabColumns(7);

    ListBoxInitializer(FurrySpeciesCB, "FurrySpecies.config");
    ListBoxInitializer(FurryJobsCB, "FurryOccupations.config");

    TheFurCode=  new FXString();
    FurCodeDB=     new FXStringDict();
    TitleKeyDB=   new FXStringDict();
    ThemeKeyDB=   new FXStringDict();
    RelationsDB=     new FXStringDict();
}
//------------------------------------------------------------------------------
/*
       Name: ~TMainWindow

       Type: Subroutine (Destructor)

       Parameters: None

       Note: Clean up items that FOX doesn't clean up for us.
*/

TMainWindow::~TMainWindow(void)
{
    for (int i= 0; i < NO_OPTIONS; i++) delete PopPanes[i];
    delete TheFurCode;
    delete FurCodeDB;
    delete TitleKeyDB;
    delete ThemeKeyDB;
    delete RelationsDB;
    delete FileOpenIco;
    delete FileSaveAsIco;
    delete FilePrintIco;
    delete NewIco;
    delete EditCopyIco;
    delete EditCutIco;
    delete EditPasteIco;
    delete EditDeleteIco;
    delete ToggleIco;
    delete DolphinLogoIco;
    delete AboutIco;
    delete HelpIco;
    delete NextArrowIco;
    delete OKCheckIco;
    delete CancelXIco;
    delete ExitIco;
}

//------------------ Functions 'n' Subroutines: Application ---------------------

/*
     Name: create

     Type: Subroutine (void function)

     Parameters: none

     Note: Initialize FurCode dictionary. Data stored as type void* -- recast to
           FXString* pointers for use.
*/

void TMainWindow::create(void)
{
#ifdef FCINSTR
 printf("\nIn Function: TMainWindow::create\n");
#endif

    const FXchar **FurCodeKeys_pt=     FurCodeKeys;
    const FXchar **FurCodeMeanings_pt= FurCodeMeanings;
    const FXchar **TitleKeys_pt=       TitleKeys;
    const FXchar **PrimaryTitles_pt=   PrimaryTitles;
    const FXchar **ThemeKeys_pt=       ThemeKeys;
    const FXchar **ThemeMeanings_pt=   ThemeMeanings;
    const FXchar **RelKeys_pt=         RelKeys;
    const FXchar **RelMeanings_pt=     RelMeanings;

    while (*FurCodeKeys_pt) FurCodeDB->insert(*FurCodeKeys_pt++, *FurCodeMeanings_pt++);
    while (*TitleKeys_pt)   TitleKeyDB->insert(*TitleKeys_pt++, *PrimaryTitles_pt++);
    while (*ThemeKeys_pt)   ThemeKeyDB->insert(*ThemeKeys_pt++, *ThemeMeanings_pt++);
    while (*RelKeys_pt)     RelationsDB->insert(*RelKeys_pt++, *RelMeanings_pt++);

    FXMainWindow::create();
    show(PLACEMENT_SCREEN);
}
//------------------------------------------------------------------------------

/*
       Name: FindBrowser

       Type: Constant Function (Reference: FXString)

       Parameters: (none)

       Note: Search paths specified in the browserpaths.config file for an
             existing, working system web browser for the on-line help.

       Returns: System path to a working web browser.
*/

const FXString& TMainWindow::FindBrowser(void)
{
/*
    Length: Length of the text in the file
    Buffer: Pointer to character array of file contents
    Head, Tail: Pointers into the buffer for text parse
    RetVal: Either a file name or error advisory
*/
    FXint   Length;
    FXchar *Buffer= 0, *Head, *Tail, C;
    static  FXString RetVal= "None";

    FXString BrowserPaths= BROWSER_PATHS;
    FXFile   ReadConfig(BrowserPaths, FXFile::Reading);

    if (! ReadConfig.isOpen())
    {
	fprintf(stderr, CONFIG_ERROR, BROWSER_PATHS);
	ThisApp->exit(1);
    }

    Length= ReadConfig.size();
    FXchar Oneline[Length];
    FXMALLOC(&Buffer, FXchar, CEIL(Length + 1));

    ReadConfig.readBlock(Buffer, Length);

/*
    Parse the file contents to extract the list of possible paths to
    web browsers. If found a file that *is* a file, and is executable,
    we may have a possibility. Return it to the caller.

*/
    Head= Tail= Buffer;

    while (C= *Tail++)
    {
	if (C == '\n')
	{
	    memcpy(&Oneline[0], Head, Tail - Head); //  Fill the character array...
	    Oneline[Tail - Head - 1]= '\0';         //  ...Make it a C string; ditch new line

	    if ((Oneline[0] != '#') && (Oneline[0]))    //  Ditch comments; empty lines
	    {
	        if ((FXStat::isFile(Oneline)) && (FXStat::isExecutable(Oneline)))
		{
		  RetVal= Oneline;
		  FXFREE(&Buffer);
		  Buffer= 0;
		  break;
		}
	    }
	    Head= Tail;
	}
    }
    
    if (Buffer) FXFREE(&Buffer);

    return RetVal;
}
//------------------------------------------------------------------------------
/*
       Name: ListBoxInitializer

       Type: Subroutine

       Parameters:
                   aBox (Pointer: FXObject) -- Pointer to the list box to be
		   initialized.

		   FileName (Constant Reference: FXString) -- Name of config
		   file to read for initializing data

       Note: Reads the config files for strings to initialize the two list boxes
*/

void TMainWindow::ListBoxInitializer(FXObject *aBox, const FXString &aFileName)
{
/*
       FileSize:   Length of file in bytes (characters)
       Head, Tail: String Index Pointers
*/
    FXint   Length;
    FXchar  C;
    FXchar *Buffer= 0, *Head, *Tail;

    FXFile ReadConfig((CONFIG_PATH + aFileName), FXFile::Reading);

    if (! ReadConfig.isOpen())
    {
        fprintf(stderr, CONFIG_ERROR, aFileName.text());
	ThisApp->exit(1);
    }

    Length= ReadConfig.size();
    FXchar Oneline[Length];
    FXMALLOC(&Buffer, FXchar, CEIL(Length + 1));
    ReadConfig.readBlock(Buffer, Length);

/*
    Parse the file contents to extract the ComboBox list items from newlines
    and comment lines. Iterate over the string and break at newline characters.
    Copy memory containing characters, add a '\0' character to make official
    C string, and load into Combo Box if not a comment or empty line.

*/
    Head= Tail= Buffer;

    while (C= *Tail++)
    {
	if (C == '\n')
	{
	    memcpy(&Oneline[0], Head, Tail - Head);
	    Oneline[Tail - Head - 1]= '\0';
	    if ((Oneline[0] != '#') && (Oneline[0])) ((FXComboBox*)aBox)->appendItem(Oneline);
	    Head= Tail;
	}
    }
    
    FXFREE(&Buffer);
}

//------------------------------------------------------------------------------

const FXString& TMainWindow::GetMeaning(FXString &aCode, FXchar Mode, FXbool aHS)
{
#ifdef FCINSTR
  printf("\nIn Function: TMainWindow::GetMeaning\n");
  printf("\nGetMeaning Received:");
  printf("\naCode: %s", aCode.text());
  printf("\nMode: %c", Mode);
  printf("\naHS: %d", aHS);
#endif

    static FXString RetVal= "";

    if (! RetVal.empty()) RetVal.clear();

    if (Mode == 's')
    {

#ifdef FCINSTR
  printf("\nIn Species Block");
#endif

	FXString Species=  "";
	FXString Theme=    "";
	FXString Rating=   "";
	FXString Relation= "";
	FXint    Index, HowMany, Head[5], Tail[5], RateKey;
	FXchar   C, LastChar, *ThemeKeys, *RelKeys;

	FXComboBox *SpecCB= (FXComboBox*)OptMenuList[0][0];
	FXRex Pattern(SPECIES_REGEX, REX_CAPTURE);

        if (Pattern.match(aCode, Tail, Head, REX_FORWARD, 5))
	{
	    Species=  aCode.mid(Tail[1], Head[1] - Tail[1]);
	    Theme=    aCode.mid(Tail[2], Head[2] - Tail[2]);
	    Rating=   aCode.mid(Tail[3], Head[3] - Tail[3]);
	    Relation= aCode.mid(Tail[4], Head[4] - Tail[4]);
	    Index=    Species.length() - 1;
	    LastChar= Species[Index];

#if (FCINSTR == 2)
  printf("\nFXRex found:");
  printf("\nSpecies Code: %s", Species.text());
  printf("\nTheme Codes: %s", Theme.text());
  printf("\nRating: %s", Rating.text());
  printf("\nRelationship Codes: %s", Relation.text());
#endif
	    if (islower(LastChar))
	    {
		Species.erase(Index);
		Theme.prepend(LastChar);
	    }

	    if (Theme.empty())    Theme=    "0";
	    if (Relation.empty()) Relation= "0";
	}
	else
	{
	    RetVal.append(FXStringFormat(" Bad species code: %s.", aCode.text()));
	    return RetVal;
	}

	HowMany= SpecCB->getNumItems();

	for (int i= 0; i < HowMany; i++)
	{
	    FXString Current= SpecCB->getItem(i);

	    if (Current.find(Species) > -1)
	    {
		Species= Current.after(':');
		Species.trim();
		if (! aHS) RetVal.append(Species);
		break;
	    }
	}

#ifdef FCINSTR
 printf("Species Found: %s", Species.text());
#endif

        ThemeKeys= (FXchar*)Theme.text();
	RetVal.append("\n\tThemes of this Furry:");

	while (C= *ThemeKeys++)
	{
	    FXchar Key[2]=        {C, '\0'};
	    const FXchar *LookUp= ThemeKeyDB->find(Key);

#ifdef FCINSTR
  printf("\nPointer: LookUp= %p", LookUp);
#endif
	    (LookUp) ? RetVal.append(LookUp) :
	               RetVal.append(FXStringFormat(" Bad theme code: %s theme not understood", Key));
	}

	RateKey= FXIntVal(Rating, 10) - 1;
	RetVal.append("\n\tFurriness:");
	RetVal.append(Furriness[RateKey]);

#ifdef FCINSTR
 printf("\nKey= %d : Furriness= %s", RateKey, Furriness[RateKey]);
#endif

        RelKeys=  (FXchar*)Relation.text();
	RetVal.append("\n\tRelationship(s) with this Furry:");

	while (C= *RelKeys++)
	{
	    FXchar Key[2]=        {C, '\0'};
	    const FXchar *LookUp= RelationsDB->find(Key);

#ifdef FCINSTR
  printf("\nPointer: LookUp= %p", LookUp);
#endif
	    (LookUp) ? RetVal.append(LookUp) :
	               RetVal.append(FXStringFormat(" Bad relationship code: %s, relationship not understood", Key));

	}

    }
    else
    {

#ifdef FCINSTR
  printf("\nIn Jobs Block:");
#endif

	FXint       HowMany;
	FXString    Occu=   "";
	FXComboBox *JobsCB= (FXComboBox*)OptMenuList[3][2];

	HowMany= JobsCB->getNumItems();

	for (int i= 0; i < HowMany; i++)
	{
	    FXString Current= JobsCB->getItem(i);

	    if (Current.find(aCode) > -1)
	    {
		Occu= Current.after(':');

#ifdef FCINSTR
  printf("\nOccu= %s", Occu.text());
#endif

		break;
	    }
	}

	(Occu.empty()) ? RetVal.append(FXStringFormat(" Bad occupation code: %s not understood.", aCode.text())) :
	                 RetVal.append(Occu.trim());

    }

    return RetVal;
}

//------------------------------------------------------------------------------

const FXString& TMainWindow::DecodeSpecies(const FXString &aSpecCode)
{
#ifdef FCINSTR
  printf("\nIn Function: TMainWindow::DecodeSpecies\n");
  printf("\nReceived Code: %s", aSpecCode.text());
#endif

    static FXString RetVal= "";

    if (! RetVal.empty()) RetVal.clear();

    if (aSpecCode.find("!F") > -1)
    {
	RetVal.append("\nPrimary Fursona: Declines to participate in this category.");
	return RetVal;
    }
    if (aSpecCode.find("F#") > -1)
    {
	RetVal.append("\nPrimary Fursona: Prefers to keep this information private");
	return RetVal;
    }
    if (aSpecCode.find("F?") > -1)
    {
	RetVal.append("\nPrimary Fursona: Species undecided");
	return RetVal;
    }

    FXString UsrData=  aSpecCode + '/';
    FXString PriTitle= "Primary Fursona: ";
    FXString SecTitle= "";
    FXString Results;
    const FXchar *Head= 0, *Tail= 0;
    FXchar   C;
    FXString Species;
    FXint    HowMany, IndexSpl, ExactSpec[2], Length;
    FXbool   HaveSpecies, Primary;

    Length=  UsrData.length();
    HowMany= UsrData.contains('/');
    FXchar   OneLine[Length + 1];
    FXString SpecCodes[HowMany];
    FXint    i= 0;

    Head= Tail= UsrData.text();

    while (C= *Tail++)
    {
	if (C == '/')
	{
	    memcpy(&OneLine[0], Head, Tail - Head);
	    OneLine[Tail - Head - 1]= '\0';
	    SpecCodes[i++]= OneLine;
	    Head= Tail;
	}
    }

#ifdef FCINSTR
    for (int i= 0; i < HowMany; i++) printf("\nSpecCodes[%d]= %s", i, SpecCodes[i].text());
#endif

    for (int i= 0; i < HowMany; i++)
    {
	Primary= (SpecCodes[i][0] == 'F');

	if (! Primary)
	{
	    SecTitle.append("\n \nSecondary Fursona: ");
	    SpecCodes[i].prepend('F');
	}

	ExactSpec[0]= SpecCodes[i].find('[');
	ExactSpec[1]= SpecCodes[i].find(']');

	if ((ExactSpec[0] > -1) && (ExactSpec[1] > -1))
	{
	    Species= SpecCodes[i].mid(ExactSpec[0] + 1, ExactSpec[1] - ExactSpec[0] - 1);
	    SpecCodes[i].erase(ExactSpec[0], ExactSpec[1] - ExactSpec[0] + 1);
	    Primary ? PriTitle.append(Species) : SecTitle.append(Species);
	    HaveSpecies= TRUE;
	}
	else HaveSpecies= FALSE;

	IndexSpl= SpecCodes[i].find('~');

	if (IndexSpl > -1)
	{
	    SpecCodes[i].erase(IndexSpl);

	    if (IndexSpl == 1)
	    {
		Primary ? PriTitle.append("Furry's genera and/or species approximate: ") :
		          SecTitle.append("Furry's genera and/or species approximate: ");
	    }
	    else if (IndexSpl > 1)
	    {
		Primary ? PriTitle.append("Furry's genera certain; species approximate: ") :
		          SecTitle.append("Furry's genera certain; species approximate: ");
	    }
	}

	IndexSpl= SpecCodes[i].find('?');

	if (IndexSpl > -1)
	{
	    SpecCodes[i].erase(IndexSpl);
	    Primary ? PriTitle.append("Furry's species undecided: ") :
	              SecTitle.append("Furry's species undecided: ");
	}

	Results= GetMeaning(SpecCodes[i], 's', HaveSpecies);
	Primary ? PriTitle.append(Results) : SecTitle.append(Results);
    }

    RetVal.append(PriTitle);
    RetVal.append(SecTitle);

    return RetVal;
}

//------------------------------------------------------------------------------

const FXString& TMainWindow::DecodeJobs(FXString &aJobCode)
{
#ifdef FCINSTR
  printf("\nIn Function: TMainWindow::DecodeJobs\n");
  printf("\nJob code received: %s", aJobCode.text());
#endif

    static FXString RetVal= "";

    if (! RetVal.empty()) RetVal.clear();

    if (aJobCode.find("!RL") > -1)
    {
	RetVal.append("\n \nPrimary Occupation: Declines to participate in this category");
	return RetVal;
    }
    if (aJobCode.find("RL#") > -1)
    {
	RetVal.append("\n \nPrimary Occupation: Prefers to keep this information private.");
	return RetVal;
    }

    FXString UsrData=  aJobCode + '/';
    FXString PriTitle= "\n \nPrimary Occupation: ";
    FXString SecTitle= "";
    FXString Results;
    FXString SplMod= "";
    const FXchar *Head= 0, *Tail= 0;
    FXchar   C;
    FXint    HowMany, IndexSpl, Length;
    FXbool   Primary;

    Length=  UsrData.length();
    HowMany= UsrData.contains('/');

    FXchar   OneLine[Length + 1];
    FXString JobCodes[HowMany];
    FXint    i= 0;

    Head= Tail= UsrData.text();

    while (C= *Tail++)
    {
	if (C == '/')
	{
	    memcpy(&OneLine[0], Head, Tail - Head);
	    OneLine[Tail - Head - 1]= '\0';
	    JobCodes[i++]= OneLine;
	    Head= Tail;
	}
    }

#ifdef FCINSTR
  for (int i= 0; i < HowMany; i++) printf("\nJobCodes[%d]= %s", i, JobCodes[i].text());
#endif

    for (int i= 0; i < HowMany; i++)
    {
        Primary= ((JobCodes[i][0] == 'R') && (JobCodes[i][1] == 'L')) ? TRUE : FALSE;

	if (! Primary)
	{
	    SecTitle.append("\n \n\tSecondary Occupation(s): ");
	    JobCodes[i].prepend("RL");
	}

	IndexSpl= JobCodes[i].find('*');

	if (IndexSpl > -1)
	{
	    JobCodes[i].erase(IndexSpl);
	    SplMod.append("\t (Note: Qualified in this field, but no experience.)");
	}

	Results= GetMeaning(JobCodes[i], 'o');
	Primary ? PriTitle.append(Results + SplMod) : SecTitle.append(Results + SplMod);

#ifdef FCINSTR
  printf("\nPrimary= %d    JobCodes[%d]= %s     Results= %s", i, i, JobCodes[i].text(), Results.text());
  printf("\nPriTitle= %s     SecTitle= %s", PriTitle.text(), SecTitle.text());
#endif

    }

    RetVal.append(PriTitle);
    RetVal.append(SecTitle);

    return RetVal;
}

//------------------------------------------------------------------------------

const FXString& TMainWindow::DecodeSimple(const FXString &aCode, const FXchar aIndexChar)
{
#ifdef FCINSTR
  printf("\nIn Function TMainWindow::DecodeSimple\n");
  printf("\nRecieved Code: %s    aIndexChar= %c", aCode.text(), aIndexChar);
#endif

    FXString Primary= "";
    FXString Upgrade= "";
    FXString UGTitle= "";
    FXString PriMod=  "";
    FXString SecMod=  "";
    FXchar   Key[]= {aIndexChar, '\0'};
    static FXString RetVal= "";

    if (! RetVal.empty()) RetVal.clear();

    FXString Title= TitleKeyDB->find(Key);

    if (aCode.find('!') > -1)
    {
	RetVal.append(Title);
	RetVal.append("\n\t* Declines to participate in this category");
	return RetVal;
    }
    if (aCode.find('#') > -1)
    {
	RetVal.append(Title);
	RetVal.append("\n\t* Prefers to keep this information private.");
	return RetVal;
    }

    if (aCode.find('>') > -1)
    {
	Primary= aCode.before('>');
	Upgrade= (aCode.after('>')).prepend(aIndexChar);
	UGTitle= "\n \n\tFuture Plans for this Category:";
    }
    else Primary= aCode;

    if (Primary.find('$') > -1)
    {
        Title.append(" Professional");
	Primary.erase(Primary.find('$'));
    }

    if (Primary.find('?') > -1)
    {
	PriMod= " (Uncertain about this category or category rating.)";
	Primary.erase(Primary.find('?'));
    }

    const FXchar *LookUp= FurCodeDB->find(Primary.text());

#ifdef FCINSTR
    printf("\nPointer: LookUp= %p (Primary)", LookUp);
#endif

    (LookUp) ? Title.append(LookUp + PriMod) :
               Title.append(" Bad code, not understood.");

    if (Upgrade.find('$') > -1)
    {
	UGTitle.append(" Professional");
	Upgrade.erase(Upgrade.find('$'));
    }

    if (Upgrade.find('?') > -1)
    {
	SecMod= " (Uncertain about this category or category rating.)";
	Upgrade.erase(Upgrade.find('?'));
    }

    if (! Upgrade.empty())
    {
      const FXchar *LookUp= FurCodeDB->find(Upgrade.text());

#ifdef FCINSTR
  printf("\nPointer: LookUp= %p (Up grade)", LookUp);
#endif

      (LookUp) ? UGTitle.append(LookUp + SecMod) :
                 UGTitle.append(FXStringFormat(" Bad code %s not understood", Upgrade.text()));
    }

    RetVal.append(Title + UGTitle);

    return RetVal;
}

/*--------------------------- Event Handlers: Update ---------------------------

      Note: These functions are called in response to a SEL_UPDATE signal.
            These event handlers implement the settings of widget states
	    in conformity with the application status.

      Parameters: Common to all FOX event handlers:

                  FXObject* -- Pointer (FXObject) -- Pointer to calling
                               widget. Base class type

                  FXSelector -- FXuint: Simple hash of caller ID from
		                the message map and the command signal.

		  void* -- Pointer (void): Generic pointer to any extra
                           information the widget may have sent.

*/


long TMainWindow::MainMenuUD(FXObject *Sender, FXSelector Select, void*)
{
    switch (FXSELID(Select))
    {
        case ID_NEW:
                     (ProjectStatus >  NO_PROJECT) ? Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
		                                     Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
		     break;

        case ID_FILEOPEN:
	                  (TheFurCode->empty()) ? Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
	                                          Sender->handle(this,FXSEL(SEL_COMMAND, DISABLE), 0);
	                  break;

        case ID_FILESAVE:
	                  ((ProjectStatus == PROJECT_FINALIZE) && (! FileSaved)) ?
			        Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
			        Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
			  break;

        case ID_PRINT:
                       (TheFurCode->empty()) ? Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0) :
			                       Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
		        break;
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::OptionMenuUD(FXObject *Sender, FXSelector Select, void*)
{
    FXuint CallerID= FXSELID(Select);

    if (((MainMode == ENCODE_MODE) && (ProjectStatus == NO_PROJECT)) || (SectionStatus & UPGRADE_ENABLE))
    {
	Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
	return 1;
    }

    if (((CallerID >= ID_THEME_NONE) && (CallerID < ID_FURRATE)) || ((CallerID > ID_FURRATE)  && (CallerID <= ID_RELATION_WRITE)))
    {
	if (SectionStatus & SECTION_REVISIT) Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
	return 1;
    }

    if ((CallerID >= ID_DRESS_FON) && (CallerID <= ID_DRESS_OWN))
    {
	if (CallerID == ID_DRESS_OWN)
	{
	    (SectionStatus & DRESS_OPT_ENABLE) ? Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
	                                         Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	}
	else
	{
	    (SectionStatus & DRESS_OPT_ENABLE) ? Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0) :
	                                         Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
	}
    }

    if ((CallerID >= ID_NET_WSC) && (CallerID <= ID_NET_WMF))
    {
	if ((CallerID == ID_NET_WMFS) || (CallerID == ID_NET_WMF))
	{
	    (SectionStatus & WEB_OPT_ENABLE) ? Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
	                                       Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	}
	else
	{
	    (SectionStatus & WEB_OPT_ENABLE) ? Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0) :
	                                       Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
	}
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::CommandBtnUD(FXObject *Sender, FXSelector Select, void*)
{
    FXuint CallerID= FXSELID(Select);

    switch (CallerID)
    {
      case ID_NEXT:
	            !((SectionStatus & SECTION_START) || (MainMode == DECODE_MODE)) ?
	                  Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
	                  Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

	            if (ProjectStatus >= PROJECT_COMPLETE) Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	            break;

      case ID_ENCODE_OK:
	                 (ProjectStatus == PROJECT_COMPLETE) ?  Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
	                     Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
                         break;

      case ID_DECODE_OK:
	                 ((TheFurCode->empty()) || (ProjectStatus == PROJECT_FINALIZE)) ?
			     Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0) :
			     Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
			 break;

      case ID_CANCEL:
                      if (MainMode == DECODE_MODE) Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
                      else (ProjectStatus != PROJECT_PENDING) ?
			       Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0) :
                               Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);

                      break;
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::GenOptSelectUD(FXObject *Sender, FXSelector Select, void*)
{
    if (ProjectStatus == PROJECT_FINALIZE)
    {
        Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
        return 1;
    }

    switch (FXSELID(Select))
    {
      case ID_APPROX:
	              ((MenuFrameIndex == THEMES) && (! MenuIndex)) ?
			Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
	                Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
		      break;

      case ID_UPGRADE:
	               (MenuFrameIndex != THEMES) ?
			 Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0) :
			 Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
		       break;

      case ID_PRO:
	           ((MenuFrameIndex == THEMES) || ((MenuFrameIndex == PREFERENCES) && (MenuIndex == 2))) ?
		     Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0) :
		     Sender->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
		   break;
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::FurCodeLECNG(FXObject*, FXSelector Select, void*)
{
    if ((MainMode == ENCODE_MODE)  || (ProjectStatus == PROJECT_FINALIZE)) return 0;
    else
    {
	*TheFurCode= FurCodeLE->getText();
	ModeLbl->setText("Decode Fur Code");
    }

    return 1;
}

/*------------------------- Event Handlers: Command  ---------------------------

       Note: These functions are called in response to a FOX SEL_COMMAND
             signal. These event handlers implement functionality derived
	     from clicks on command buttons, toolbar buttons, and menu items.

       Parameters: Common parameters for all FOX event handlers:

                   FXObject* - Pointer (FXObject): Generic base class pointer to
                               any FOX widget.

                   FXSelector ( FXuint): The hash code of the message ID, and the
                                         target ID. Used to ident the caller and the
				         calling message. May extract both/either as
				         needed.

                   void* - Pointer (void): Generic pointer to extra data that the
                           caller may have sent.

       Returns: All FOX event handlers return:
                                               0 - Event wasn't handled successfully,
					           and/or nothing happened that
						   changed the program state. No GUI
						   updates needed.

                                               1 - Event was handled successfully, GUI
                                                   update possible.

------------------------------------------------------------------------------*/

/*
      Name: FileNewClick

      Type: Function

      Parameters: (unused)

      Note: Reset application to initial conditions for selected mode to start a new
            project. Prompt for confirm if current project unsaved.
*/

long TMainWindow::FileNewClick(FXObject*, FXSelector, void*)
{
    if ((! FileSaved) && (ProjectStatus == PROJECT_FINALIZE))
    {
	FXuint Code= FXMessageBox::question(this, MBOX_YES_NO, "Fur Coder Question", SAVE_QUERY);
	if (Code == MBOX_CLICKED_NO) return 0;
    }

    MainMode=       DECODE_MODE;
    FileSaved=      TRUE;
    ProjectStatus=  NO_PROJECT;
    SectionStatus=  SECTION_START;
    MenuFrameIndex= THEMES;
    MenuIndex=      0;

    OptionFrame->handle(this, FXSEL(SEL_COMMAND, DECODE_PANE), 0);

    for (int i= 0; i < NO_OPTION_PANES; i++)
    {
	for (int j= 0; j < NO_OPTION_PANES; j++)
	{
	    FXObject *Current= OptMenuList[i][j];
	    if (Current) Current->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	}
    }

    OKCmdBtn->setTarget(this);
    OKCmdBtn->setSelector(ID_DECODE_OK);
    FurCodeLE->setText("");
    FurDecodeView->setText("");
    TheFurCode->clear();

    return 1;
}
//------------------------------------------------------------------------------
/*
       Name: FileOpenClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Opens a Furry Code File for decryption. Copies the text to the
             TheFurCode object. Sets the ProjectStatus flag.
*/

long TMainWindow::FileOpenClick(FXObject *Sender, FXSelector, void*)
{
/*
       FileName: User supplied file name and path
       Length:   Length of file in bytes (characters)
       PFHandle: Pointer to the system file stream object
*/

    FXString FileName;
    FXchar  *Buffer= 0;
    FXint    BlksRead, Length;

/*
       *) Declare a FOX File Dialog and initialize

       *) SELECTFILE_EXISTING: Allow entries of names of files that
          are already on the system
.
       *) File Patterns:
                         *) *.fur -- Fur Coder project file
			 *) *.txt -- Any text file (*.fur files are also text files)
			 *) *.*   -- Any file type
       *) Initial pattern: *.fur
*/

    FXFileDialog OpenDlg(this, "Open Fur Code File");
    OpenDlg.setSelectMode(SELECTFILE_EXISTING);
    OpenDlg.setPatternList("Fur Code (*.fur)\nText (*.txt)\nAny (*.*)");
    OpenDlg.setCurrentPattern(0);

    if (! OpenDlg.execute(PLACEMENT_SCREEN))
    {
        FXMessageBox::information(this, MBOX_OK, "Furry Coder Advisory", "File Open Cancelled");
        return 0;
    }

    FileName= OpenDlg.getFilename();

    FXFile FCFile(FileName, FXFile::Reading);

    if (! FCFile.isOpen())
    {
	FXMessageBox::error(this, MBOX_OK, "Fur Coder Error", "Couldn't open file: %s", FileName.text());
	return 0;
    }

    Length= FCFile.size();
    FXMALLOC(&Buffer, FXchar, Length + 1);

    BlksRead= FCFile.readBlock(Buffer, Length);

    if (BlksRead < 0)
    {
	FXMessageBox::error(this, MBOX_OK, "Fur Coder Error", "Read of file: %s failed", FileName.text());
	FXFREE(&Buffer);
	return 0;
    }

    TheFurCode->clear();
    TheFurCode->insert(0, Buffer, Length);
    FurCodeLE->setText(TheFurCode->text());
    ModeLbl->setText("Decode Fur Code");
    if (Buffer) FXFREE(&Buffer);

    if (MainMode == ENCODE_MODE)
    {
	MainMode= DECODE_MODE;
	ModeDecodeClick(Sender, FXSEL(SEL_COMMAND, ID_MODE_DECODE), 0);
    }

    ProjectStatus= PROJECT_PENDING;

    return 1;
}

//------------------------------------------------------------------------------
/*
       Name: FileSaveClick

       Type: Function

       Parameters: (unused)

       Note: Initialize and execute a FOX File Dialog to get a file name/path for
             current project save. Perform write to file; update the "Saved" status
	     flag.
*/

long TMainWindow::FileSaveClick(FXObject*, FXSelector, void*)
{
/*
            FileName: The name of the file and path that the user
                      requests via the file dialog

            Buffer:   The text to be written to the user-created file.
                      can come from either the TheFurCode object (Encode Mode)
		      or from the Fur decode viewer (Decode Mode)

*/

    FXString FileName;
    FXuint   Code= 1000;

/*
       *) Declare a FOX File Dialog and initialize

       *) SELECTFILE_ANY: Remove restructions on file type to allow for
                          saving with the *.fur extension.
       *) File Patterns:
                         *) *.fur -- Fur Coder project file
			 *) *.txt -- Any text file (*.fur files are also text files)
			 *) *.*   -- Any file type

       *) Initial pattern: *.fur
*/

    FXFileDialog SaveDlg(this, "Open Furry Code File");
    SaveDlg.setSelectMode(SELECTFILE_ANY);
    SaveDlg.setPatternList("Furry Code (*.fur)\nText (*.txt)\nAny (*.*)");
    SaveDlg.setCurrentPattern(0);

    if (! SaveDlg.execute(PLACEMENT_OWNER))
    {
        FXMessageBox::information(this, MBOX_OK, "Furry Coder Advisory", "File Save Cancelled");
        return 0;
    }

    FileName= SaveDlg.getFilename();

    if (FXStat::exists(FileName))
      Code= FXMessageBox::question(this, MBOX_YES_NO, "Fur Coder Question", "Overwrite File: %s", FileName.text());

    if (Code == MBOX_CLICKED_NO) return 1;

    FXFile WriteFile(FileName, FXFile::Writing);
    WriteFile.writeBlock(TheFurCode->text(), TheFurCode->length());
    FileSaved= TRUE;
    ModeLbl->setText("Decode: Project Saved");

    return 1;
}
//------------------------------------------------------------------------------

long TMainWindow::FilePrintClick(FXObject*, FXSelector, void*)
{
    FXint Length, OLLength;                          //  Length of the text buffer, line to print
    const FXint X_Margin= 60;                        //  Page metrics: fix the left margin
    FXint Y_Margin=       60, LineHeight;            //  Page metrics: start of top margin and line spacing
    const FXchar *Buffer= 0, *Head= 0, *Tail= 0;
    FXchar C;
    FXint i= 1;
    FXdouble PageHeight;

    FXPrinter ThePrinter;  //  Declair a print job
/*
          Invoke print dialog box to get the system printer
	  and set it up for printing
*/
    FXPrintDialog PDlgBox(this, "Print Current Project");
    if (PDlgBox.execute(PLACEMENT_OWNER))  //  Start if #1
    {
      PDlgBox.getPrinter(ThePrinter);
      FXDCPrint Pdc(ThisApp);  
      if (! Pdc.beginPrint(ThePrinter))
      {
        FXMessageBox::error(this, MBOX_OK, "Fur Coder Error", "Print Fault");
        return 1;
      }

      Length=          TheFurCode->length();
      FXFont *SysFont= ThisApp->getNormalFont();
      LineHeight=      SysFont->getFontHeight();
      PageHeight=      ThePrinter.mediaheight;

      FXchar OneLine[Length];
      Pdc.setFont(SysFont);
      Pdc.beginPage(i);
      TheFurCode->append('\n');
      Buffer= TheFurCode->text();
      Head=   Tail= Buffer;
/*
          Note: Parse the text buffer into a new string at the newline
	        breaks. Otherwise, printer treats the buffer as one
		long string. FOX bug or ideosyncracy?

          1)  Parse the string to newline (character copy)
	  2)  Append C string terminator (ASCII Null)
	  3)  Draw text into image and print.
	  4)  Update the vertical margin, and reset to grab the next line.
*/
      while (C= *Tail++)
      {
	  if (C == '\n')
	  {
	      OLLength= Tail - Head;
	      memcpy(&OneLine[0], Head, OLLength);
	      OneLine[OLLength - 1]= '\0';
	      Pdc.drawText(X_Margin, Y_Margin, OneLine, OLLength);
	      Y_Margin+= LineHeight;
	      Head= Tail;

	      if (PageHeight - Y_Margin < 145)
	      {
		  Pdc.endPage();
		  Y_Margin= 60;
		  Pdc.beginPage(i++);
	      }
	  }
      }

      Pdc.endPage();
      Pdc.endPrint();
    }

    else FXMessageBox::information(this, MBOX_OK, "FXTransformer Designer Advisory", "Print job cancelled");

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::ModeDecodeClick(FXObject*, FXSelector, void*)
{
    ProjectStatus= NO_PROJECT;
    SectionStatus= SECTION_END;
    MainMode=      DECODE_MODE;

    OptionFrame->handle(this, FXSEL(SEL_COMMAND, DECODE_PANE), 0);
    OKCmdBtn->setTarget(this);
    OKCmdBtn->setSelector(ID_DECODE_OK);
    TheFurCode->empty() ?  ModeLbl->setText("Decode: No Fur Code Loaded") : ModeLbl->setText("Decode Fur Code");

    for (int i= 0; i < NO_OPTION_PANES; i++)
    {
	FXObject *Current= OptMenuList[0][i];
	if (Current) Current->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::ModeEncodeClick(FXObject*, FXSelector, void*)
{
    if ((ProjectStatus == PROJECT_COMPLETE) && (! TheFurCode->empty()))
    {
	FXint Code;
	Code= FXMessageBox::question(this, MBOX_YES_NO, "Fur Coder Question", SAVE_ADVISE);
	if (Code == MBOX_CLICKED_NO) return 0;
    }

    ProjectStatus=  NO_PROJECT;
    SectionStatus=  SECTION_START;
    MainMode=       ENCODE_MODE;
    MenuFrameIndex= THEMES;
    MenuIndex=      0;

    OptionFrame->handle(this, FXSEL(SEL_COMMAND, ENCODE_PANE), 0);
    MenuFrame->handle(this, FXSEL(SEL_COMMAND, THEMES), 0);
    OptMenuList[0][0]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
    OKCmdBtn->setTarget(this);
    OKCmdBtn->setSelector(ID_ENCODE_OK);
    FurCodeLE->setText("");
    TheFurCode->clear();
    ModeLbl->setText(PANE_0);

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::ToggleModeClick(FXObject *Sender, FXSelector, void*)
{
    (MainMode == DECODE_MODE) ? ModeEncodeClick(Sender, FXSEL(SEL_COMMAND, ID_MODE_ENCODE), 0) :
                                ModeDecodeClick(Sender, FXSEL(SEL_COMMAND, ID_MODE_DECODE), 0);
    return 1;
}

//------------------------------------------------------------------------------

/*
       Name: SpecialMsgsClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Invokes the special message dialogs: "About" box, Special Message
             Box, the On-Line Help.
*/

long TMainWindow::SpecialMsgsClick(FXObject*, FXSelector Select, void*)
{
/*
       Tab (Pointer: TAbout)         -- Pointer to the "About" Box object
       SMB (Pointer: TSpecialMsgBox) -- Pointer to the special message dialog.
       SysArg (FXString)             -- Command line options to the selected web browser.
       UseBrowser (FXString)         -- Path to detected web browser to display the
                                        on-line help.
*/

    FXDialogBox *MsgBox= 0;
    FXString     SysArg, UseBrowser;

    switch (FXSELID(Select))
    {
      case ID_ABOUT:
                        MsgBox= new TAbout(ThisApp);
                        MsgBox->execute(PLACEMENT_OWNER);
                        break;

      case ID_DOLPHINS:
                        MsgBox= new TSpecialMsgBox(ThisApp);
                        MsgBox->execute(PLACEMENT_OWNER);
                        break;

      case ID_CNTS:
                        UseBrowser= FindBrowser();

                        if (UseBrowser == "None")
                        {
	                  FXMessageBox::error(this, MBOX_OK, "Fur Coder Error",
					      HELP_ERROR);
	                  return 1;
                        }

                        SysArg= UseBrowser + DOC_PATH;
                        if (system(SysArg.text()))
	                  FXMessageBox::error(this, MBOX_OK, "Fur Coder Error",
					      HELP_ERROR);
    }

    if (MsgBox) delete MsgBox;
    return 1;
}

//------------------------------------------------------------------------------

/*
       NextMenuPaneClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Advances to the next option menu pane; sets up option menus for
             initial selection in current menu pane.

	     Resets:
	             *) SectionStatus
		     *) ProjectStatus
*/

long TMainWindow::NextMenuPaneClick(FXObject*, FXSelector, void*)
{
    const FXchar *PaneDesc[]=
                        {
			   PANE_0,
	                   PANE_1,
	                   PANE_2,
	                   PANE_3,
	                   PANE_4,
	                   PANE_5,
			   PANE_6
                        };

    if (MenuFrameIndex > INTERESTS) return 0;

    SectionStatus= SECTION_START;
    ++MenuFrameIndex;

    ModeLbl->setText(PaneDesc[FRAMEINDEX]);
    FXObject *Menu= OptMenuList[FRAMEINDEX][0];

    if (MenuFrameIndex <= INTERESTS)
    {
	MenuFrame->handle(this, FXSEL(SEL_COMMAND, MenuFrameIndex), 0);
	Menu->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);

	for (int i= 1; i < NO_OPTION_PANES; i++)
	{
	    FXObject *Current= OptMenuList[FRAMEINDEX][i];
	    if (Current) Current->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	    else break;
	}
    }

    else ProjectStatus= PROJECT_COMPLETE;

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::OKEncodeClick(FXObject*, FXSelector, void*)
{
    TheFurCode->clear();
    *TheFurCode=   FurCodeLE->getText();
    FileSaved=     FALSE;
    ProjectStatus= PROJECT_FINALIZE;
    ModeLbl->setText("Encode: Project Complete/Not Saved.");
    return 1;
}

//------------------------------------------------------------------------------

/*
       Name: AppExitClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Tests for project completion and save status. Invokes query dialog
             before exit if the current project isn't saved yet.
*/

long TMainWindow::AppExitClick(FXObject *Sender, FXSelector, void*)
{
    FXuint Code= 0;

    if (! FileSaved && (ProjectStatus == PROJECT_FINALIZE))
      Code= FXMessageBox::warning(this, MBOX_QUIT_SAVE_CANCEL, "Furry Coder Question", EXIT_QUERY);

    switch (Code)
    {
      case MBOX_CLICKED_QUIT:   ThisApp->exit(0); break;

      case MBOX_CLICKED_SAVE:   FileSaveClick(Sender, 0, 0); break;

      case MBOX_CLICKED_CANCEL: return 0;
    }

    ThisApp->exit(0);
    return 0;
}
//------------------------------------------------------------------------------
/*
       Name: ProjectXnlClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Resets the current application mode to initial start-up state for
             a new project.
	     Flags:
	              *) PriSelected
		      *) Saved
		      *) SectionStatus
	     Indices:
	              *) MenuFrameIndex
		      *) MenuIndex
*/

long TMainWindow::ProjectXnlClick(FXObject*, FXSelector, void*)
{
    FXString CodeFrag=  FurCodeLE->getText();
    FXObject *NextMenu= OptMenuList[FRAMEINDEX][MenuIndex + 1];

    if (MenuFrameIndex == THEMES)
    {
	FurCodeLE->setText("");
	MenuIndex= 0;

	for (int i= 1; i < NO_OPTION_PANES; i++)
        {
	  FXObject *Current= OptMenuList[0][i];
	  if (Current) Current->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	}

	OptMenuList[0][0]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
    }

    CodeFrag.trunc(CodeFrag.rfind(' '));
    FurCodeLE->setText(CodeFrag);

    SectionStatus&= 0x1;
    OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
    if (NextMenu) NextMenu->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

    return 1;
}

//----------------------- Encode Mode Event Handlers -------------------------

/*
       Name: SpeciesSelect

       Type: Function (Event Handler)

       Parameters: Sender (Pointer: FXObject) -- Pointer to caller.

       Note: Selects the Furry Species from the species list box. Parses off the
             description, and adds the code to the FurCode line edit.

	     Sets: ProjectStatus (initial menu item: starts current project)
	           SectionStatus for menu pane
*/

long TMainWindow::SpeciesSelect(FXObject *Sender, FXSelector, void*)
{
     FXString UsrData, CodeElement, SpeciesCode;
     FXint Key= 0;

     ProjectStatus= PROJECT_PENDING;
     MenuIndex=     0;

     UsrData=      ((FXComboBox*)Sender)->getText();
     CodeElement=  FurCodeLE->getText();

     if (UsrData == "F_Private")        Key= 1;
     else if (UsrData == "F_Declined")  Key= 2;
     else if (UsrData == "F_Uncertain") Key= 3;

     SpeciesCode= UsrData.before(':');

     if (!(SectionStatus & REVISIT_ENABLE))
     {
         switch (Key)
	 {
	     case 1:
	             SpeciesCode= "F#";
	             SectionStatus= SECTION_END;
	             break;

	     case 2:
	             SpeciesCode= "!F";
	             SectionStatus= SECTION_END;
	             break;

	     case 3:
	             SpeciesCode= "F?";
	             SectionStatus= SECTION_END;
	             break;
	}
     }
     else
     {
         if (Key)
	 {
	    FXMessageBox::error(this, MBOX_OK, "Fur Coder Error", "Bad selection; try again");
	    return 1;
	 }

	 SpeciesCode= SpeciesCode.after('F');
	 SpeciesCode.prepend('/');
     }

     FurCodeLE->setText(CodeElement + SpeciesCode);
     OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
     if (SectionStatus & REVISIT_ENABLE) SectionStatus|= SECTION_REVISIT;
     SectionStatus|= REVISIT_ENABLE;

     return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::RLJobsSelect(FXObject *Sender, FXSelector Select, void*)
{
    FXString UsrData, CodeFrag, JobCode;
    FXint Key= 0;
    MenuIndex= 2;

    UsrData=   ((FXComboBox*)Sender)->getText();
    CodeFrag=  FurCodeLE->getText();

    if (UsrData == "RL_Private")            Key= 1;
    else if (UsrData == "RL_Declined")      Key= 2;
    else if (UsrData == "RL_No_experience") Key= 3;
    else JobCode= UsrData.before(':');

    if (!(SectionStatus & REVISIT_ENABLE))
    {
	switch (Key)
	{
	  case 1:
	          JobCode= "RL#";
	          OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	          break;

	  case 2:
	          JobCode= "!RL";
	          OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
		  break;

	  case 3:
	          FXMessageBox::error(this, MBOX_OK, "Fur Coder Error", "Bad selection; try again");
	          return 1;
	          break;
	}

	JobCode.prepend(' ');
    }
    else
    {
        if ((Key > 0) && (Key < 3))
	{
	    FXMessageBox::error(this, MBOX_OK, "Fur Coder Error", "Bad selection; try again");
	    return 1;
	}

	if (Key == 3) JobCode.append('*');
	else
	{
	    JobCode= JobCode.after('L');
	    JobCode.prepend('/');
	}
    }

    FurCodeLE->setText(CodeFrag + JobCode);
    SectionStatus|= REVISIT_ENABLE;
    OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

/*
       Name: ThemesClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Makes Furry Theme selection, adds code to the Furry Species category.
*/

long TMainWindow::ThemesClick(FXObject *Sender, FXSelector Select, void*)
{
     FXchar   Theme;
     FXString CodeElement;

     MenuIndex=           1;
     SectionStatus&=     ~SECTION_REVISIT;
     FXchar ThemeCodes[]= THEME_CODE_ITEMS;
     CodeElement=         FurCodeLE->getText();
     Theme=               ThemeCodes[FXSELID(Select) - ID_THEME_NONE];

     if (Theme != '0')
     {
         CodeElement.append(Theme);
	 Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
     }

     FurCodeLE->setText(CodeElement);
     OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
     OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

/*
       Name: FurRateClick

       Type: Function (Event Handler)

       Parameters: Sender (Pointer: FXObject) -- Pointer to caller.

       Note: Registers the Furriness Rating modifier to the Species
             category. Updates the rating description label. Operates
	     cyclically, so that the final selection is the only one
	     that counts.
*/

long TMainWindow::FurRateClick(FXObject *Sender, FXSelector, void*)
{
    FXint    Key, StrIndex;
    FXchar   LastChar;
    FXString CodeElement;

    MenuIndex=   2;
    CodeElement= FurCodeLE->getText();
    Key=         ((FXSpinner*)Sender)->getValue();

    FurrinessLbl->setText(FRateDesc[Key]);

    StrIndex= CodeElement.length() - 1;
    LastChar= CodeElement[StrIndex];

    if (isdigit(LastChar)) CodeElement.erase(StrIndex);

    if (Key) CodeElement.append(FXStringVal(Key));

    FurCodeLE->setText(CodeElement);
    OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
    OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

/*
       Name: RelationshipClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Selects the "relationships" modifiers for the Furry Species
             category.
*/

long TMainWindow::RelationshipClick(FXObject *Sender, FXSelector Select, void*)
{
    FXchar   Relation;
    FXString CodeElement;

    MenuIndex=            3;
    SectionStatus&=      ~SECTION_START;
    FXchar RelateCodes[]= RELATE_CODE_ITEMS;
    CodeElement=          FurCodeLE->getText();
    Relation=             RelateCodes[FXSELID(Select) - ID_RELATION_NONE];

    if (Relation != '0')
    {
	CodeElement.append(Relation);
	Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
    }

    FurCodeLE->setText(CodeElement);
    OptMenuList[FRAMEINDEX][0]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
    OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::ArtOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=      0;
    SectionStatus=  (SectionStatus & UPGRADE_ENABLE) ? SECTION_START|UPGRADE_ENABLE : SECTION_START;
    FXString Entry= ArtCodes[FXSELID(Select) - ID_ART_OC];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::ConsOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        1;
    FXString Entry=   ConCodes[FXSELID(Select) - ID_CONS_ORG];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::FursuitingClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex= 2;
    FXuint StrIndex, Key;
    FXString Entry, FCCode;

    Key=   FXSELID(Select) - ID_DRESS_FON;
    Entry= DressCodes[Key];

    if (Key < 9) ENCODE(Entry)

    if ((SectionStatus & DRESS_OPT_ENABLE) && (Key == 9))
    {
        FXString CodeFrag;
        CodeFrag= FurCodeLE->getText();
	StrIndex= CodeFrag.rfind(' ');
	FCCode=   CodeFrag.right(CodeFrag.length() - StrIndex);
	CodeFrag.trunc(StrIndex);

	FXint i;
	if ((i= FCCode.rfind('>')) > -1) StrIndex= i + 1;
	else if ((i= FCCode.rfind('D')) > -1) StrIndex= i + 1;

	FCCode.insert(StrIndex, 'm');
	CodeFrag.append(FCCode);
	SectionStatus&= ~DRESS_OPT_ENABLE;
        FurCodeLE->setText(CodeFrag);
	OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
    }
    else
    {
	if (Key < 4)
	{
	    SectionStatus|= DRESS_OPT_ENABLE;
	    OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
	}
	else SectionStatus&= ~DRESS_OPT_ENABLE;
    }

    return 1;
}

//------------------------------------------------------------------------------


long TMainWindow::HugOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        3;
    FXString Entry=   HugCodes[FXSELID(Select) - ID_HUGS_TF];

    ENCODE(Entry)
    OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::MuckOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        4;
    FXString Entry=   MuckCodes[FXSELID(Select) - ID_MUCK_AW];

    ENCODE(Entry)
    SectionStatus&= ~SECTION_START;

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::PlushieOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        0;
    SectionStatus= (SectionStatus & UPGRADE_ENABLE) ? SECTION_START|UPGRADE_ENABLE : SECTION_START;
    FXString Entry=   PlushCodes[FXSELID(Select) - ID_PLUSH_STP];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::RealismOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        1;
    FXString Entry=   RealCodes[FXSELID(Select) - ID_REAL_PHOTO];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::XformOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        2;
    FXString Entry=   XformCodes[FXSELID(Select) - ID_TRANS_WAW];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::FanficOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        3;
    FXString Entry=   WriteCodes[FXSELID(Select) - ID_WRITE_BSL];

    ENCODE(Entry)
    
    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::ZinesOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        4;
    FXString Entry=   ZinesCodes[FXSELID(Select) - ID_ZINES_PUB];

    ENCODE(Entry)
    SectionStatus&= ~SECTION_START;

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::FurrysexOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=       0;
    SectionStatus= (SectionStatus & UPGRADE_ENABLE) ? SECTION_START|UPGRADE_ENABLE : SECTION_START;
    FXuint StrIndex= FXSELID(Select) - ID_FURSEX_M;
    FXString Entry=  FSexCodes[StrIndex];

    ENCODE(Entry)

    if (StrIndex > 3)
    {
	OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	OptMenuList[FRAMEINDEX][MenuIndex + 2]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::YiffinessOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=      1;
    FXString Entry= FYiffMods[FXSELID(Select) - ID_YIFFRATE_WE];
    SectionStatus|= UPGRADE_ENABLE;

    ENCODE(Entry)
    
    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::AgeOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex= 3;
    FXString Entry= AgeCodes[FXSELID(Select) - ID_RLAGE_SIXTY];

    ENCODE(Entry)
    SectionStatus&= ~REVISIT_ENABLE;
    OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::TechOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=          4;
    FXuint Key=         FXSELID(Select) - ID_TECH_TM;
    FXString Entry=     CompCodes[Key];
    ENCODE(Entry)

    if (Key < 5)
    {
	OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
	SectionStatus|= OS_OPT_ENABLE;
    }
    else
    {
	OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	SectionStatus= SECTION_END;
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::OSChoicesClick(FXObject *Sender, FXSelector Select, void*)
{
    MenuIndex= 5;
    FXchar Entry;
    FXchar OSCodes[]= OS_CODE_ITEMS;
    FXuint StrIndex;
    FXuint Key=       FXSELID(Select) - ID_OPSYS_NONE;
    FXuint ItemCount= SectionStatus & ~0xFF;
    ItemCount= ItemCount >> 9;

    if (! Key)
    {
	OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	SectionStatus= SECTION_END;
	return 1;
    }

    Entry=    OSCodes[Key];
    FXString  CodeFrag= FurCodeLE->getText();
    StrIndex= CodeFrag.rfind(' ');
    FXString TechCode= CodeFrag.right(CodeFrag.length() - StrIndex);
    CodeFrag.trunc(StrIndex);

    StrIndex= (TechCode.find('>') > -1) ? TechCode.find('>') : TechCode.find('c');
    
    TechCode.insert(++StrIndex + ItemCount++, Entry);
    CodeFrag.append(TechCode);
    ItemCount= ItemCount << 9;
    SectionStatus&= 0xFF;
    SectionStatus+= ItemCount;
    FurCodeLE->setText(CodeFrag);
    Sender->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
    SectionStatus&= ~SECTION_START;

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::GamesOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        0;
    SectionStatus= (SectionStatus & UPGRADE_ENABLE) ? SECTION_START|UPGRADE_ENABLE : SECTION_START;
    FXString Entry=   GameCodes[FXSELID(Select) - ID_GAME_PM];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::EduOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        1;
    FXString Entry=   EduCodes[FXSELID(Select) - ID_EDU_PHD];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::RLFurrinessOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        2;
    FXString Entry=   RLFurCodes[FXSELID(Select) - ID_RLFURRY_LS];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::HousingOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=        3;
    SectionStatus&=   ~SECTION_START;
    FXString Entry=   HomeCodes[FXSELID(Select) - ID_HOUSE_MWC];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::InternetClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=         0;
    SectionStatus&=   ~SECTION_START;
    FXuint Key=        FXSELID(Select) - ID_NET_WSC;
    FXString CodeFrag= FurCodeLE->getText();
    FXString Entry;

    (Key < 9) ? Entry= NetCodes[Key] : Entry= "";

    if (SectionStatus & UPGRADE_ENABLE)
    {
	CodeFrag.append(Entry.after('i'));
	SectionStatus&= ~UPGRADE_ENABLE;
    }
    else if (! (SectionStatus & WEB_OPT_ENABLE)) CodeFrag.append(Entry.prepend(' '));

    if (SectionStatus & WEB_OPT_ENABLE)
    {
	FXString WebOpt;
	FXuint   StrIndex;

	StrIndex= CodeFrag.rfind(' ');
	WebOpt=   CodeFrag.right(CodeFrag.length() - StrIndex);
	CodeFrag.trunc(StrIndex);

	if (WebOpt.find('>') > -1)
	{
	    StrIndex= WebOpt.find('>');
	    (Key == 9) ? WebOpt.insert(StrIndex + 1, "wf") : WebOpt.insert(StrIndex + 1, "w");
	}
	else
	{
	    (Key == 9) ? WebOpt.insert(2, "wf") : WebOpt.insert(2, "w");
	}

	CodeFrag.append(WebOpt);
	FurCodeLE->setText(CodeFrag);
	SectionStatus&= ~WEB_OPT_ENABLE;
    }

    FurCodeLE->setText(CodeFrag);

    if (Key < 3)
    {
	SectionStatus|= WEB_OPT_ENABLE;
	OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
    }
    else OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

    OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::AnimeOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex= 1;
    FXString Entry= AnimeCodes[FXSELID(Select) - ID_ANIME_OTK];

    ENCODE(Entry)
    OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::PetsOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex= 2;
    FXString Entry= PetCodes[FXSELID(Select) - ID_PETS_MOM];

    ENCODE(Entry)

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::RLSexOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=       3;
    FXuint StrIndex= FXSELID(Select) - ID_RLGEN_M;
    FXString Entry=  RLSexCodes[StrIndex];

    ENCODE(Entry)

    if (StrIndex > 1)
    {
	ProjectStatus= PROJECT_COMPLETE;
	SectionStatus= SECTION_END;
	OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
	OptMenuList[FRAMEINDEX][MenuIndex + 1]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
    }

    return 1;
}

//------------------------------------------------------------------------------

long TMainWindow::RLYiffinessOptClick(FXObject*, FXSelector Select, void*)
{
    MenuIndex=      4;

    FXString Entry= RLYiffMods[FXSELID(Select) - ID_RLSL_HHO];
    SectionStatus|= UPGRADE_ENABLE;
    ENCODE(Entry)
    SectionStatus= SECTION_END;
    ProjectStatus= PROJECT_COMPLETE;

    return 1;
}

//------------------------------------------------------------------------------

/*
       Name: GenOptSelectClick

       Type: Function (Event Handler)

       Parameters: (unused)

       Note: Activates the "general options" that apply to most fur code
             categories. Adds modification to the current code category;
	     resets the encode option menus.

	     Alerts user that a mode change is in progress, sets focus to
	     the Fur Code line edit for user input.
*/

long TMainWindow::GenOptSelectClick(FXObject*, FXSelector Select, void*)
{
    FXString CodeFrag=  FurCodeLE->getText();
    FXObject *NextMenu= OptMenuList[FRAMEINDEX][MenuIndex + 1];

    switch (FXSELID(Select))
    {
      case ID_UPGRADE:
                       SectionStatus|= UPGRADE_ENABLE;
		       SectionStatus&= 0xFF;
                       CodeFrag.append('>');
		       OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
		       if (NextMenu) NextMenu->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);

		       if ((MenuFrameIndex == PREFERENCES) && (MenuIndex == 5))
		       {
			   OptMenuList[FRAMEINDEX][MenuIndex - 1]->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);
			   OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);
		       }

                       break;

      case ID_PRO:       CodeFrag.append('$'); break;

      case ID_APPROX:    CodeFrag.insert(FurCodeLE->getCursorPos(), '~'); break;

      case ID_UNCERTAIN: CodeFrag.insert(FurCodeLE->getCursorPos(), '?'); break;
    }

    FurCodeLE->setText(CodeFrag);
    return 1;
}

//------------------------- Decode Mode Event Handlers -------------------------

long TMainWindow::OKDecodeClick(FXObject*, FXSelector, void*)
{
    FXchar  *Head, *Tail;
    FXString Current;
    FXString SpeciesCode=    "";
    FXString FurCodeMeaning= "                    FurCoderCXX Results\n \n";
    FXint    Length, NoItems, Start[2], End[2], i= 0;
    FXchar   C, IndexChar;
    FXRex    SpecPat(SPEC_PAT, REX_CAPTURE);

    if (SpecPat.match(*TheFurCode, Start, End, REX_FORWARD, 2))
    {
	SpeciesCode= TheFurCode->mid(Start[1], End[1] - Start[1]);
	SpeciesCode.trim();
	TheFurCode->erase(Start[1], End[1] - Start[1]);
    }
    else
    {
	FurCodeMeaning.append("* Fur Code defective");
	return 1;
    }

    TheFurCode->append(' ');

    Length=  TheFurCode->length();
    NoItems= TheFurCode->contains(' ');
    Head=    Tail= (FXchar*)TheFurCode->text();

    FXchar   OneLine[Length];
    FXString Elements[NoItems];

#ifdef FCINSTR
  printf("\nLength= %d     NoItems= %d", Length, NoItems);
#endif

    while ((C= *Tail++))
    {
	if (C == ' ')
	{
	    memcpy(&OneLine[0], Head, Tail - Head);
	    OneLine[Tail - Head - 1]= '\0';
            Elements[i++]= OneLine;
	    Head= Tail;

#if FCINSTR == 2
 printf("\nIn Function TMainWindow::OKDecodeClick");
 printf("\nElements[%d]= %s", i - 1, OneLine);
#endif
	}
    }

    FurCodeMeaning.append(DecodeSpecies(SpeciesCode));

    for (int i= 0; i < NoItems; i++)
    {
        FXchar ModChar= Elements[i][0];
        IndexChar=      (ModChar == '!') ? Elements[i][1] : ModChar;

	if (Elements[i].find("RL") > -1)
	{
	    FurCodeMeaning.append(DecodeJobs(Elements[i]));
	    continue;
	}

	Current= Elements[i];

	switch (IndexChar)
	{
	    case 'D':
	              if (Current.find('m') > -1)
		      {
			  FXint Index= Current.find('m');
		          Current.erase(Index);
		          FurCodeMeaning.append(DecodeSimple(Current, IndexChar));
		          FurCodeMeaning.append("\n\t  Note: Made own fursuit");
		      }
	              else FurCodeMeaning.append(DecodeSimple(Current, IndexChar));
	              break;

	    case 's':

	    case 'S':
	              {
	                  FXchar   ModChar;
	                  FXString TitleMod= "";
		          FXString Temp=     "";
			  FXString UMod=     "";
			  FXint    Index;

			  ModChar= Current[1];
			  Index=   Current.find('?');

			  if (Index  > 1)       UMod=    "\n\t(Note: Uncertain about yiffiness rating)";
			  else if (Index == 0)  ModChar= '?';
			  else if (Index == -1) Index= 1;

	                  switch (ModChar)
		          {
			      case 'm': TitleMod= ": Male"; Current.erase(1); break;

		              case 'f': TitleMod= ": Female"; Current.erase(1); break;

		              case 'h': TitleMod= ": Hermaphrodite"; Current.erase(1); break;

		              case 'p': TitleMod= ": Polymorph"; Current.erase(1); break;

			      case '?': TitleMod= ": Uncertain about gender"; Current.erase(Index); break;
		          }

#ifdef FCINSTR
 printf("\nIn Function TMainWindow::OKDecodeClick");
 printf("\n Current= %s\nIndexChar= %c", Current.text(), IndexChar);
#endif
		          Temp= DecodeSimple(Current, IndexChar);

			  Index= Temp.find(':');
			  Temp.insert(Index, TitleMod);
			  Temp.append(UMod);
			  FurCodeMeaning.append(Temp);
		      }
		      break;

	    case 'a':
	              {
		 	  FXString Age=  "";

			  if (isdigit(Current[1]))
			  {
			      Age=  Current.after('a');
			      FurCodeMeaning.append("\n \nExact RL age is: " + Age);
			  }
			  else FurCodeMeaning.append(DecodeSimple(Current, IndexChar));
		      }
		      break;

            case 'c':
	              {
		          FXString OSChoices= "";
			  FXString Primary, Upgrade= "";
		          FXString Key= "", Mod= "";
		          FXint    Index, Length, Head[2], Tail[2];
			  FXbool   Match;
		          FXRex    OSPats(OS_REGEX, REX_CAPTURE);
			  FXRex    OSPatsAlt(OS_REGEX_ALT, REX_CAPTURE);

			  Index= Current.find('>');

			  if (Index > -1)
			  {
			      Primary= Current.left(Index);
			      Upgrade= Current.right(Current.length() - Index - 1);
			      Upgrade.prepend('c');
			  }
			  else Primary= Current;

			  do
			  {
			        Index= Primary.find('?');
			        if (Index > -1) Primary.erase(Index);

			        if (OSPats.match(Primary, Tail, Head, REX_FORWARD, 2))         Match= TRUE;
			        else if (OSPatsAlt.match(Primary, Tail, Head, REX_FORWARD, 2)) Match= TRUE;
			        else Match= FALSE;

		                if (Match)
		                {
			           Mod=       "\n\t  Note: Prefers platforms/OSs:";
		                   OSChoices= Primary.mid(Tail[1], Head[1] - Tail[1]);
		                   Length=    OSChoices.length();
		                   Primary.erase(1, Length);
#ifdef FCINSTR
 printf("\nIn Function TMainWindow::OKDecodeClick");
 printf("\nFXRex Found: %s", OSChoices.text());
 printf("\nCurrent= %s", Primary.text());
#endif

		                  for (int i= 0; i < Length; i++)
		                  {
				      Key= "os_";
				      Key.append(OSChoices[i]);
				      const FXchar *LookUp= FurCodeDB->find(Key.text());
				      if (LookUp) Mod.append(LookUp);
				      else Mod.append(FXStringFormat("Bad OS code; not understood: %s", Key.text()));
#ifdef FCINSTR
 printf("\nIn Function TMainWindow::OKDecodeClick");
 printf("\nKey= %s; Dictionary Entry= %s", Key.text(), LookUp);
#endif
		                  }
		               }

			       if (Index > -1) Primary.insert(1, '?');
		               FurCodeMeaning.append(DecodeSimple(Primary, IndexChar));
		               FurCodeMeaning.append(Mod);
			       Primary= Upgrade;
			       Upgrade.clear();
			  } while (Primary != "");
	               }
	               break;

            case 'i':
	              {
		          FXString Choice= "", Mod= "";
			  FXint Index;

			  if (Current.find("wf") > -1)
			  {
			      Index= Current.find("wf");
			      Current.erase(Index, 2);
			      Mod= "\n\t* Note: Admins own Furry web site.";
			  }
			  else if (Current.find('w') > -1)
			  {
			      Index= Current.find('w');
			      Current.erase(Index);
			      Mod= "\n\t* Note: Admins own web site (non-Furry)";
			  }
			  else Mod= "";

		          FurCodeMeaning.append(DecodeSimple(Current, IndexChar));
		          FurCodeMeaning.append(Mod);
	              }
	              break;

	    default:  FurCodeMeaning.append(DecodeSimple(Elements[i], IndexChar)); break;
	}
    }

    FurDecodeView->appendText(FurCodeMeaning.text());
    TheFurCode->clear();
    *TheFurCode=   FurCodeMeaning;
    ProjectStatus= PROJECT_FINALIZE;
    FileSaved=     FALSE;
    ModeLbl->setText("Fur Code Decoded/Not Saved");

    return 1;
}

//---------------------------- tmainwindow.cpp  ------------------------------
