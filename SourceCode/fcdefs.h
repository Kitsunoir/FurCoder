//---------------------------------- fcdefs.h ----------------------------------

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

     Note: This file contains preprocessor macros that are related to the
           The details of the Fur Code. Should there be a code revision,
           these values may be altered to accomodate the updates.

*/

#ifndef FCDEFS_H
#define FCDEFS_H

//        Numeric Macros

//  Number of Fur Code Key/Value pairs
//  Number of Fur Code option menus
//  Number of specific title keys
//  Number of specific theme keys
//  Number of specific relationship keys
//  Number of encode option menu panes

#define NO_FC_KEYS      177
#define NO_OPTIONS      26
#define NO_TITLE_CODES  23
#define NO_THEME_CODES  10
#define NO_RELATE_CODES 9
#define NO_OPTION_PANES 6

//        Application Status Bar Reports

#define PANE_0 "Encode: \"Themes\" Pane"
#define PANE_1 "Encode: \"Participation\" Pane"
#define PANE_2 "Encode: \"Realism\" Pane"
#define PANE_3 "Encode: \"Preferences\" Pane"
#define PANE_4 "Encode: \"Real Life\" Pane"
#define PANE_5 "Encode: \"Interests\" Pane"
#define PANE_6 "Encode: Project Complete. Finalize?"  //  Note: depricated

/*
          Regular expressions to parse the Codes. FXRex REs operate very much
	  like those used in Perl. (  ) forms capturing parenthesis, and (?:  ) make
	  non-capturing parenthesis. (Note: use "\\" escapes for the '\' character.
	  It's a C/C++ thing.)
*/

#define SPECIES_REGEX "(F[A-Z]{1}[a-z]{0,1}[A-Z]{0,1})([cfhmpstuw]*)([1-6]{0,1})([acdfmrsw]*)"
#define SPEC_PAT      "(!?F.* )(?:!A|A).+"
#define OS_REGEX      "c([abdlmnouvw]+)\\+{0,4}"
#define OS_REGEX_ALT  "c\\+{0,4}([abdlmnouvw]+)"

/*

          Letter code descriptor modifiers: Index items keyed
	  to option menu IDs.

*/

//  Theme codes (Species Modifier)
//  Relationship codes (Species Modifier)
//  Op-sys use mods (Tech Modifier)
//  Net useage mod (Internet: Admins Furry site)
//   "     "    "  (Internet: Admins non-Furry site)

#define THEME_CODE_ITEMS  "0cfhmpstuw"
#define RELATE_CODE_ITEMS "0acdfmrsw"
#define OS_CODE_ITEMS     "0abdlmnouvw"

#endif

//---------------------------------- fcdefs.h ----------------------------------
