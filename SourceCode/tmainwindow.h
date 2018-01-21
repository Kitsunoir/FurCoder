//------------------------------ tmainwindow.h  --------------------------------

/***************************************************************************
                            -  Description
                             -------------------
    Begin                : 5 December, 2006
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
 ***************************************************************************/

#ifndef TMAIN_H
#define TMAIN_H

#include <fox-1.6/fx.h>
#include "fcdefs.h"

/*
       Name: ENCODE

       Type: Macro Subroutine

       Parameters: aEntry (FXString) -- The current menu entry to be encrypted
*/

#define ENCODE(aEntry) \
{\
FXString CodeFrag=  FurCodeLE->getText();\
FXObject *NextMenu= OptMenuList[FRAMEINDEX][MenuIndex + 1];\
if (SectionStatus & UPGRADE_ENABLE)\
{\
CodeFrag.append(aEntry.erase(0));\
SectionStatus&= ~UPGRADE_ENABLE;\
}\
else CodeFrag.append(aEntry.prepend(' '));\
FurCodeLE->setText(CodeFrag);\
OptMenuList[FRAMEINDEX][MenuIndex]->handle(this, FXSEL(SEL_COMMAND, DISABLE), 0);\
if (NextMenu) NextMenu->handle(this, FXSEL(SEL_COMMAND, ENABLE), 0);\
}

//------------------------------------------------------------------------------

/*
       Name: CEIL

       Type: Macro Function

       Parameters: x (FXint) -- Length of string for which dynamic memory is
                   allocated.

       Returns: The next closest value that'll accomodate this string length.

       Note: Force carry by adding 15 to x. Next, bitwise AND with -16 to determine
             where the carry bit was set. This allows allocation of even amounts of
	     memory: 0x10, 0x20, 0x30 ... This helps keep memory boundries aligned
	     and insures that there will always be enough memory to accommodate the
	     string.
*/

#define CEIL(x) (((x) + 15) & -16)

//         Convenience Macros

#define FRAMEINDEX MenuFrameIndex-THEMES
#define DISABLE    FXWindow::ID_DISABLE
#define ENABLE     FXWindow::ID_ENABLE

/*
                              Text Macros

      Note: These macros are used by message boxes. Other macros used
            in the TMainWindow methods are located in the header file:
	    "furrinessratings.h". These are various text and numeric
	    macros related to the Fur Code itself. These may change with
	    revisions of the Fur Code.

	    The header "locations.h" contains macros that specify
	    system file paths. See these headers for definitions
	    not found here.
*/

#define SAVE_ADVISE \
"You haven't saved your current project yet!"\
"\nExit/start a new project anyway?"

//--------------------------------------

#define HELP_ERROR \
"Can't open a web browser on this system."\
"\nEither you don't have one (highly unlikely, but possible)"\
"\nOr it's on some non-standard path, or it's broken, or"\
"\nthe permissions are set incorrectly."\
"\n"\
"\nPossibly your browser path config file is corrupt, missing, or moved from"\
"\nits proper location. Make sure its still good and/or located properly"\
"\nManually open: \"/path/to/FurCoder-1.0.1/Documents/HelpMain.html\""\
"\nin order to view the help with whatever browser your system has installed."

//-------------------------------------

#define BUFFER_ERROR \
"\nMemory allocation for file buffer failed"\
"\nEither the file is badly corrupted, or more"\
"\nlikely it is not a Fur Coder file (Length= %d)"

//--------------------------------------

#define CONFIG_ERROR \
"Can't open the config file: %s"\
"\nThis is a FATAL ERROR... Aborting"

//--------------------------------------

#define FILE_READ_ERROR \
"Incomplete read of file: %s. Data may be lost."\
"\nCheck your config files for corruption/errors"

#define SAVE_QUERY \
"You haven't saved your current project yet!"\
"\nStart a new one anyway?"

#define EXIT_QUERY \
"You haven't saved your current project yet!"\
"\nExit Fur Coder anyway?"

/*
       Name: TMainWindow

       Type: Daughter Class

       Ancestor: FXMainWindow (FOX Class Library)

       Methods: See tmainwindow.cpp for details

       Variables: See below for details

       Note: "Main Window" object. Implements the app GUI, and the main
             application functionality.
*/

class TMainWindow : public FXMainWindow
{
    FXDECLARE(TMainWindow)

//------------------------ Functions 'n' Subroutines  --------------------------

    public:
               TMainWindow(FXApp *aAPP);
               virtual ~TMainWindow(void);

	       //           Event Handlers: Command

	       //   Main Menu/Toolbar/Command Button Selections

	       long FileNewClick(FXObject*, FXSelector, void*);
	       long FileOpenClick(FXObject*, FXSelector, void*);
	       long FileSaveClick(FXObject*, FXSelector, void*);
	       long FilePrintClick(FXObject*, FXSelector, void*);
	       long AppExitClick(FXObject*, FXSelector, void*);
	       long ProjectXnlClick(FXObject*, FXSelector, void*);
	       long SpecialMsgsClick(FXObject*, FXSelector, void*);
	       long ModeDecodeClick(FXObject*, FXSelector, void*);
	       long ModeEncodeClick(FXObject*, FXSelector, void*);
	       long ToggleModeClick(FXObject*, FXSelector, void*);
	       long GenOptSelectClick(FXObject*, FXSelector, void*);
	       long SpeciesSelect(FXObject*, FXSelector, void*);
	       long RLJobsSelect(FXObject*, FXSelector, void*);
	       long FurRateClick(FXObject*, FXSelector, void*);
	       long OKDecodeClick(FXObject*, FXSelector, void*);
	       long OKEncodeClick(FXObject*, FXSelector, void*);
	       long NextMenuPaneClick(FXObject*, FXSelector, void*);
	       long FurCodeLECNG(FXObject*, FXSelector, void*);

	       //           Option Menu Selections:

	       long ThemesClick(FXObject*, FXSelector, void*);
	       long RelationshipClick(FXObject*, FXSelector, void*);
	       long ArtOptClick(FXObject*, FXSelector, void*);
	       long ConsOptClick(FXObject*, FXSelector, void*);
    	       long FursuitingClick(FXObject*, FXSelector, void*);
	       long HugOptClick(FXObject*, FXSelector, void*);
	       long MuckOptClick(FXObject*, FXSelector, void*);
	       long PlushieOptClick(FXObject*, FXSelector, void*);
	       long RealismOptClick(FXObject*, FXSelector, void*);
	       long XformOptClick(FXObject*, FXSelector, void*);
	       long FanficOptClick(FXObject*, FXSelector, void*);
	       long ZinesOptClick(FXObject*, FXSelector, void*);
	       long FurrysexOptClick(FXObject*, FXSelector, void*);
	       long YiffinessOptClick(FXObject*, FXSelector, void*);
	       long AgeOptClick(FXObject*, FXSelector, void*);
	       long TechOptClick(FXObject*, FXSelector, void*);
	       long OSChoicesClick(FXObject*, FXSelector, void*);
	       long GamesOptClick(FXObject*, FXSelector, void*);
	       long EduOptClick(FXObject*, FXSelector, void*);
	       long RLFurrinessOptClick(FXObject*, FXSelector, void*);
	       long HousingOptClick(FXObject*, FXSelector, void*);
	       long InternetClick(FXObject*, FXSelector, void*);
	       long AnimeOptClick(FXObject*, FXSelector, void*);
	       long PetsOptClick(FXObject*, FXSelector, void*);
	       long RLSexOptClick(FXObject*, FXSelector, void*);
	       long RLYiffinessOptClick(FXObject*, FXSelector, void*);

	       //           Event Handlers: Update

	       long CommandBtnUD(FXObject*, FXSelector, void*);
	       long GenOptSelectUD(FXObject*, FXSelector, void*);
	       long MainMenuUD(FXObject*, FXSelector, void*);
	       long OptionMenuUD(FXObject*, FXSelector, void*);

	       //           Application

	       virtual void create(void);

    protected:
               TMainWindow(void) {}  //  In-line default

    private:
	       //   FOX Maintenance: Copy Constructor, operator= Override

               TMainWindow(const TMainWindow&);
               TMainWindow& operator=(const TMainWindow&);

	       //           Application

	       const FXString& FindBrowser(void);
	       const FXString& DecodeSimple(const FXString&, const FXchar);
	       const FXString& DecodeJobs(FXString&);
	       const FXString& DecodeSpecies(const FXString&);
	       const FXString& GetMeaning(FXString&, FXchar, FXbool aHS=FALSE);
	       void  ListBoxInitializer(FXObject*, const FXString&);

//-------------------------------- Variables  ----------------------------------

    public:
	       enum  //  Target IDs
	       {
		   ID_NEW=          FXMainWindow::ID_LAST,  //  Last ID in base class
		   ID_FILEOPEN,
		   ID_FILESAVE,
		   ID_PRINT,
		   ID_EXIT,
		   ID_MODE_ENCODE,
		   ID_MODE_DECODE,
		   ID_MODE_TOGGLE,
		   ID_CNTS,
		   ID_ABOUT,
		   ID_TITLE,
		   ID_DOLPHINS,
		   ID_NEXT,
		   ID_DECODE_OK,
		   ID_ENCODE_OK,
		   ID_UPGRADE,
		   ID_UNCERTAIN,
		   ID_APPROX,
		   ID_PRO,
		   ID_RLOCCUPATION,
		   ID_CANCEL,
		   ID_FURCODE_LE,
		                                   //  Option Menu Command IDs
		   ID_SPECIES,
		   ID_THEME_NONE,
		   ID_THEME_CYBORG,
		   ID_THEME_TOON,
		   ID_THEME_WERE,
		   ID_THEME_MAGIC,
		   ID_THEME_POLY,
		   ID_THEME_PSI,
		   ID_THEME_TAUR,
		   ID_THEME_UNICORN,
		   ID_THEME_WINGED,
		   ID_FURRATE,
		   ID_RELATION_NONE,
		   ID_RELATION_AE,
		   ID_RELATION_FC,
		   ID_RELATION_DRAW,
		   ID_RELATION_IF,
		   ID_RELATION_OLC,
		   ID_RELATION_RPC,
		   ID_RELATION_TSA,
		   ID_RELATION_WRITE,
		   ID_ART_OC,
		   ID_ART_PR,
		   ID_ART_PO,
		   ID_ART_DR,
		   ID_ART_FC,
		   ID_ART_FM,
		   ID_ART_NTFA,
		   ID_ART_CDASL,
		   ID_ART_DEC,
		   ID_ART_PRI,
		   ID_CONS_ORG,
		   ID_CONS_RA,
		   ID_CONS_MORE,
		   ID_CONS_ONE,
		   ID_CONS_NY,
		   ID_CONS_NI,
		   ID_CONS_AN,
		   ID_CONS_SFONLY,
		   ID_CONS_SFORG,
		   ID_CONS_DEC,
		   ID_CONS_PRI,
		   ID_DRESS_FON,
		   ID_DRESS_EC,
		   ID_DRESS_ACNU,
		   ID_DRESS_AM,
		   ID_DRESS_TAI,
		   ID_DRESS_REL,
		   ID_DRESS_NET,
		   ID_DRESS_DEC,
		   ID_DRESS_PRI,
		   ID_DRESS_OWN,
		   ID_HUGS_TF,
		   ID_HUGS_CF,
		   ID_HUGS_AMG,
		   ID_HUGS_IIHT,
		   ID_HUGS_NKYB,
		   ID_HUGS_NW,
		   ID_HUGS_SA,
		   ID_HUGS_DEC,
		   ID_HUGS_PRI,
		   ID_MUCK_AW,
		   ID_MUCK_MGRL,
		   ID_MUCK_SC,
		   ID_MUCK_REG,
		   ID_MUCK_OCC,
		   ID_MUCK_PER,
		   ID_MUCK_TKFT,
		   ID_MUCK_GAL,
		   ID_MUCK_DEC,
		   ID_MUCK_PRI,
		   ID_PLUSH_STP,
		   ID_PLUSH_SSC,
		   ID_PLUSH_HSF,
		   ID_PLUSH_SSO,
		   ID_PLUSH_DO,
		   ID_PLUSH_UDC,
		   ID_PLUSH_AYA,
		   ID_PLUSH_DEC,
		   ID_PLUSH_PRI,
		   ID_REAL_PHOTO,
		   ID_REAL_AA,
		   ID_REAL_PRF,
		   ID_REAL_NP,
		   ID_REAL_PT,
		   ID_REAL_VT,
		   ID_REAL_TA,
		   ID_REAL_DEC,
		   ID_REAL_PRI,
		   ID_TRANS_WAW,
		   ID_TRANS_CS,
		   ID_TRANS_IR,
		   ID_TRANS_DM,
		   ID_TRANS_TAI,
		   ID_TRANS_HUM,
		   ID_TRANS_BI,
		   ID_TRANS_DEC,
		   ID_TRANS_PRI,
		   ID_WRITE_BSL,
		   ID_WRITE_SAB,
		   ID_WRITE_SMM,
		   ID_WRITE_SFM,
		   ID_WRITE_WFO,
		   ID_WRITE_WFS,
		   ID_WRITE_NOW,
		   ID_WRITE_FI,
		   ID_WRITE_NFBSL,
		   ID_WRITE_NFB,
		   ID_WRITE_NFS,
		   ID_WRITE_NFM,
		   ID_WRITE_DEC,
		   ID_WRITE_PRI,
		   ID_ZINES_PUB,
		   ID_ZINES_RC,
		   ID_ZINES_BP,
		   ID_ZINES_REG,
		   ID_ZINES_OCC,
		   ID_ZINES_NOINT,
		   ID_ZINES_KS,
		   ID_ZINES_DEC,
		   ID_ZINES_PRI,
		   ID_FURSEX_M,
		   ID_FURSEX_F,
		   ID_FURSEX_H,
		   ID_FURSEX_P,
		   ID_FURSEX_DEC,
		   ID_FURSEX_PRI,
		   ID_YIFFRATE_WE,
		   ID_YIFFRATE_RWA,
		   ID_YIFFRATE_CSR,
		   ID_YIFFRATE_MTE,
		   ID_YIFFRATE_NOWE,
		   ID_YIFFRATE_WBP,
		   ID_YIFFRATE_DEC,
		   ID_RLAGE_SIXTY,
		   ID_RLAGE_FIFTY,
		   ID_RLAGE_FORTY,
		   ID_RLAGE_THIRTY,
		   ID_RLAGE_TWENTY,
		   ID_RLAGE_TEN,
		   ID_RLAGE_LESSTEN,
		   ID_RLAGE_DEC,
		   ID_RLAGE_PRI,
		   ID_TECH_TM,
		   ID_TECH_RL,
		   ID_TECH_PRO,
		   ID_TECH_EMS,
		   ID_TECH_JAT,
		   ID_TECH_BTP,
		   ID_TECH_HDYTIO,
		   ID_TECH_LUDD,
		   ID_TECH_DEC,
		   ID_TECH_PRI,
		   ID_OPSYS_NONE,
		   ID_OPSYS_AMG,
		   ID_OPSYS_BSD,
		   ID_OPSYS_DOS,
		   ID_OPSYS_LIN,
		   ID_OPSYS_OSX,
		   ID_OPSYS_WINXP,
		   ID_OPSYS_OST,
		   ID_OPSYS_UNI,
		   ID_OPSYS_VMS,
		   ID_OPSYS_WINX,
		   ID_GAME_PM,
		   ID_GAME_MNE,
		   ID_GAME_PG,
		   ID_GAME_OK,
		   ID_GAME_ITI,
		   ID_GAME_DLI,
		   ID_GAME_MFM,
		   ID_GAME_WWT,
		   ID_GAME_DEC,
		   ID_GAME_PRI,
		   ID_EDU_PHD,
		   ID_EDU_MS,
		   ID_EDU_BS,
		   ID_EDU_AS,
		   ID_EDU_HS,
		   ID_EDU_HSI,
		   ID_EDU_GS,
		   ID_EDU_GSI,
		   ID_EDU_CST,
		   ID_EDU_DEC,
		   ID_EDU_PRI,
		   ID_RLFURRY_LS,
		   ID_RLFURRY_BYM,
		   ID_RLFURRY_BFO,
		   ID_RLFURRY_OMF,
		   ID_RLFURRY_DADT,
		   ID_RLFURRY_TCF,
		   ID_RLFURRY_TNO,
		   ID_RLFURRY_DEC,
		   ID_RLFURRY_PRI,
		   ID_HOUSE_MWC,
		   ID_HOUSE_MDS,
		   ID_HOUSE_FRM,
		   ID_HOUSE_NFRM,
		   ID_HOUSE_LASL,
		   ID_HOUSE_LANSL,
		   ID_HOUSE_AGOR,
		   ID_HOUSE_LWP,
		   ID_HOUSE_NSA,
		   ID_HOUSE_LESS,
		   ID_HOUSE_DEC,
		   ID_HOUSE_PRI,
		   ID_NET_WSC,
		   ID_NET_WSR,
		   ID_NET_WSO,
		   ID_NET_NCISP,
		   ID_NET_SUX,
		   ID_NET_SSO,
		   ID_NET_DSP,
		   ID_NET_DEC,
		   ID_NET_PRI,
		   ID_NET_WMFS,
		   ID_NET_WMF,
		   ID_ANIME_OTK,
		   ID_ANIME_REE,
		   ID_ANIME_SOTF,
		   ID_ANIME_KAF,
		   ID_ANIME_NBD,
		   ID_ANIME_NOTYET,
		   ID_ANIME_HUH,
		   ID_ANIME_YECH,
		   ID_ANIME_INENG,
		   ID_ANIME_DEC,
		   ID_ANIME_PRI,
		   ID_PETS_MOM,
		   ID_PETS_SE,
		   ID_PETS_OONUS,
		   ID_PETS_ONECON,
		   ID_PETS_HWG,
		   ID_PETS_CANT,
		   ID_PETS_YECH,
		   ID_PETS_WONA,
		   ID_PETS_CHA,
		   ID_PETS_DEC,
		   ID_PETS_PRI,
		   ID_RLGEN_M,
		   ID_RLGEN_F,
		   ID_RLGEN_DEC,
		   ID_RLGEN_PRI,
		   ID_RLSL_HHO,
		   ID_RLSL_CBH,
		   ID_RLSL_DI,
		   ID_RLSL_NAV,
		   ID_RLSL_SMF,
		   ID_RLSL_CONS,
		   ID_RLSL_IPM,
		   ID_RLSL_FM,
		   ID_RLSL_FMWC,
		   ID_RLSL_PRI,
		   ID_LAST
		};

	       //            Class Member Widgets

	       FXSwitcher  *MenuFrame, *OptionFrame;
	       FXTextField *FurCodeLE;
	       FXText      *FurDecodeView;
	       FXLabel     *ModeLbl, *FurrinessLbl;
	       FXButton    *OKCmdBtn, *NextCmdBtn;
	       FXObject    *OptMenuList[NO_OPTION_PANES][NO_OPTION_PANES];

    protected:
	       //             Main Window Icons

	       FXIcon *FileOpenIco, *FileSaveAsIco, *FilePrintIco, *EditCopyIco, *EditCutIco,
		      *EditPasteIco, *EditDeleteIco, *DolphinLogoIco, *AboutIco, *HelpIco,
		      *NextArrowIco, *OKCheckIco, *CancelXIco, *ExitIco, *ToggleIco, *NewIco;

	       FXString    *TheFurCode;
	       FXPopup     *PopPanes[NO_OPTIONS];  //  List of option menu popup panes
               FXStatusBar *MWStatus;
    private:
	       enum  //  Menu Frame IDs  (MenuFrameIndex)
	       {
		   THEMES=        FXSwitcher::ID_OPEN_FIRST,
		   PARTICIPATION,
		   REALISM,
		   PREFERENCES,
		   REALLIFE,
		   INTERESTS
	       };

//------------------------- Application Control Flags  -------------------------

	       enum                   //  Major Mode
	       {
		   DECODE_MODE= 0,
		   ENCODE_MODE
	       };

	       enum                   //  Menu Pane IDs
	       {
		   DECODE_PANE=    FXSwitcher::ID_OPEN_FIRST,
		   ENCODE_PANE
	       };

	       enum                        //  Encode Mode Status Flags
	       {
		   SECTION_START=    0x1,
		   DRESS_OPT_ENABLE= 0x2,
		   WEB_OPT_ENABLE=   0x4,
		   OS_OPT_ENABLE=    0x8,
		   UPGRADE_ENABLE=   0x10,
		   REVISIT_ENABLE=   0x20,
		   LE_HAS_FURCODE=   0x40,
		   SECTION_REVISIT=  0x80,
		   SECTION_END=      0x0
	       };

	       enum                       //  Application State Flags
	       {
		   NO_PROJECT= 0,         //  Application in start-up state
		   PROJECT_PENDING,       //  Project begun
		   PROJECT_COMPLETE,      //  Encode mode: all menu entries made
		   PROJECT_FINALIZE       //  Ready to file save project
	       };

/*
        	             Program Control Flags

                       Decode:        Decode mode enabled?
		       FileSaved:     Save current project?
		       ProjectStatus: The application status
		       SectionStatus: Progress marker: ready to change panes?
*/

	       FXbool FileSaved;
	       FXuint MainMode, ProjectStatus, SectionStatus;

	       //          Class Variables: Internal

	       FXuint        MenuIndex;        //  Menu index within the current menu pane
	       FXuint        MenuFrameIndex;
	       FXStringDict *FurCodeDB;
	       FXStringDict *TitleKeyDB;
	       FXStringDict *ThemeKeyDB;
	       FXStringDict *RelationsDB;
	       FXApp        *ThisApp;         //  Pointer to the FOX main application object (event loop)
};

#endif

//------------------------------ tmainwindow.h  --------------------------------
