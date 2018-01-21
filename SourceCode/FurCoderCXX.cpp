//----------------------------- furrycoder.cpp -------------------------------

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
 *       ----> If software can be free, why can't dolphins? <----          *
 *                                                                         *
 ***************************************************************************

*/
/*
 *        Author: Simo
 */

#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tmainwindow.h"

/*
     Name: main

     Type: Function (int)

     Parameters:
                 argc (int) - Number of command line options
		 argv (Dbl Pointer: char) - Array of command line options
		 Note: FOX parses argv for FOX specific options, passes these
		       along to the FOX application object, leaves user
		       defined options for processing.

     Returns:
              0 --  Indicates success to shell
	      1 --      "     failure  "   "

     Note:
           1) See if user gave the "version" command line option.
	      If yes, print version to stdout and exit

	   2) Create an FXApp object and initialize: use app and vendor
	      names to create a hidden directory in each user's /home dir
	      for application specific settings.

	   3) Create the TMainWindow object and intialize, add signal
	      detect so that <CNTL> C will gracefully terminate the app

	   4) Request X-Server services and enter main event loop.

*/

int main(int argc, char *argv[])
{
//     See if "version" option given on command line

    for (int i= 1; i < argc; i++)
    {
        if (! (strcmp(argv[i], "-v") && strcmp(argv[i], "--version")))
	{
	    printf("FurCoderCXX Version: %s\n", VERSION);
	    return 0;
	}
    }

    FXApp  MyApp("FurCoderCXX", "Simo");
    MyApp.init(argc, argv);
    TMainWindow *Mw=  new TMainWindow(&MyApp);
    MyApp.addSignal(SIGINT, Mw, TMainWindow::ID_EXIT);
    MyApp.create();
    return MyApp.run();
}

//----------------------------- furrycoder.cpp -------------------------------
