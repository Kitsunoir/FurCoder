//---------------------------- furcodeexternals.cpp ----------------------------

#ifndef NULL
#define NULL (const char*)0
#endif

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

     Note: This file contains all the externals that the app needs for
           implementing encode/decode functions. Includes key/value pairs
           for decode mode look-up function.

*/

//                     Codes for encrypting the named categories

extern const char *ArtCodes[]=   {"A++++", "A+++", "A++", "A+", "A", "A-", "A--", "A---", "!A", "A#"};

extern const char *ConCodes[]=   {"C+++", "C++", "C+", "C", "C-", "C--", "C---", "C*", "C**", "!C", "C#"};

extern const char *DressCodes[]= {"D++++", "D+++", "D++", "D+", "D", "D-", "D--", "!D", "D#"};

extern const char *HugCodes[]=   {"H+++", "H++", "H+", "H", "H-", "H--", "H---", "!H", "H#"};

extern const char *MuckCodes[]=  {"M++++", "M+++", "M++", "M+", "M", "M-", "M--", "M---", "!M", "M#"};

extern const char *PlushCodes[]= {"P++++", "P+++", "P++", "P+", "P", "P-", "P--", "!P", "P#"};

extern const char *RealCodes[]=  {"R+++", "R++", "R+", "R", "R-", "R--", "R---", "!R", "R#"};

extern const char *XformCodes[]= {"T++++", "T+++", "T++", "T+", "T", "T-", "T--", "!T", "T#"};

extern const char *WriteCodes[]= {"W++++", "W+++", "W++", "W+", "W", "W-", "W--", "W---", "W****",
                                  "W***", "W**", "W*", "!W", "W#"};

extern const char *ZinesCodes[]= {"Z++++", "Z+++", "Z++", "Z+", "Z", "Z-", "Z--", "!Z", "Z#"};

extern const char *FSexCodes[]=  {"Sm", "Sf", "Sh", "Sp", "!S", "S#"};

extern const char *FYiffMods[]=  {"S+++", "S++", "S+", "S", "S-", "S--", "S#"};

extern const char *AgeCodes[]=   {"a++++", "a+++", "a++", "a+", "a", "a-", "a--", "!a", "a#"};

extern const char *CompCodes[]=  {"c++++", "c+++", "c++", "c+", "c", "c-", "c--", "c---", "!c", "c#"};

extern const char *GameCodes[]=  {"d++++", "d+++", "d++", "d+", "d", "d-", "d--", "d---", "!d", "d#"};

extern const char *EduCodes[]=   {"e++++", "e+++", "e++", "e+", "e", "e-", "e--", "e*", "e**", "!e", "e#"};

extern const char *RLFurCodes[]= {"f++++", "f+++", "f++", "f+", "f", "f-", "f--", "!f", "f#"};

extern const char *HomeCodes[]=  {"h++++", "h+++", "h++", "h+", "h", "h-", "h--", "h*", "h**", "h***", "!h", "h#"};

extern const char *NetCodes[]=   {"i+++", "i++", "i+", "i", "i-", "i--", "i---", "!i", "i#"};

extern const char *AnimeCodes[]= {"j++++", "j+++", "j++", "j+", "j", "j-", "j--", "j---", "j*", "!j", "j#"};

extern const char *PetCodes[]=   {"p+++", "p++", "p+", "p", "p-", "p--", "p---", "p*", "p**","!p", "p#"};

extern const char *RLSexCodes[]= {"sm", "sf", "!s", "s#"};

extern const char *RLYiffMods[]= {"s+++", "s++", "s+", "s", "s-", "s--", "s---", "s*", "s**", "s#"};

//           Furriness Rating Labels: keyed to index

extern const char *FRateDesc[]=
{
    "How Furry?",
    "Basically Human: Minor Furry Features",
    "Humanoid: Major Furry Features",
    "Anthropomorphic Animal",
    "Equally Comfy on 2 or More Legs",
    "Animal Shape: Sapient",
    "Normal Animal Form"
};
    

//            Decode mode furriness rating meanings: Keyed by index

extern const char *Furriness[]=
{
    "\n\t\t* Zoomorphic human: minor Furry features",
    "\n\t\t* Humanoid: major Furry features",
    "\n\t\t* Anthropomorphic animal",
    "\n\t\t* Two legs or four: makes no difference",
    "\n\t\t* Sapient animal, minor humanoid features",
    "\n\t\t* Normal animal form with sapience"
};

//------------- Key/Value pairs for initializing the dictionaries  -------------

extern const char *FurCodeMeanings[]=
{
    "\n\t* Obsessive/compulsive about Furry art",
    "\n\t* Art is regularly featured in mainstream 'zines; receives regular commissions",
    "\n\t* Art appears on-line and in reasonably well known 'zines",
    "\n\t* Draws frequently; receives good reviews",
    "\n\t* Draws for others",
    "\n\t* Draws strictly for self",
    "\n\t* Hasn't tried Furry art yet",
    "\n\t* Can't draw a straight line",

    "\n\t* Regular attendee at Fur-Cons; organized at least one",
    "\n\t* Regular attendee or staffed for at least one",
    "\n\t* Attended several cons; plan to attend more",
    "\n\t* Attended exactly one Fur-Con",
    "\n\t* Not yet, but plan to attend soon",
    "\n\t* No interest at this time",
    "\n\t* Have no plans to ever attend a Fur-Con",
    "\n\t* Attended Sci-Fi cons, but not a Fur-Con",
    "\n\t* Regular at Sci-Fi cons: oragnized/staffed at least one",

    "\n\t* I'd wear a fursuit to the \"Big Interview\"",
    "\n\t* Wear a fursuit, given any plausible excuse",
    "\n\t* At cons/events where costumes not uncommon",
    "\n\t* Halloween parties/masquerades where costumes expected/common",
    "\n\t* I've been considering it...",
    "\n\t* Only under extreme duress",
    "\n\t* Absolutely under no circumstances",

    "\n\t* Hug anyone, anywhere, anytime",
    "\n\t* Hug acquaintances, given any plausible excuse",
    "\n\t* Readily accept hugs, may give",
    "\n\t* Accept if it's not otherwise avoidable",
    "\n\t* Close friends/family only",
    "\n\t* Don't accept hugs; don't give them",
    "\n\t* Keep your distance, you perv!",

    "\n\t* MUCKS *are* my universe",
    "\n\t* May give \"real life\" a go someday",
    "\n\t* Have characters on several MU*s",
    "\n\t* Regular on one Furry MU*",
    "\n\t* Occasional participant",
    "\n\t* Have not tried it yet, but may do so",
    "\n\t* Haven't tried it; don't intend to do so",
    "\n\t* Get a life, lusers!",

    "\n\t* Have more plushies than any reasonable person should",
    "\n\t* Prolific species-specific collector",
    "\n\t* Have a collection of several favorites",
    "\n\t* Been known to cuddle a few",
    "\n\t* I like them as \"soft sculpture\" decorations",
    "\n\t* Useless dust collectors",
    "\n\t* You people need to act your age!",

    "\n\t* Photographic realism",
    "\n\t* Imaginary animals have anatomy too, and I want it accurate",
    "\n\t* Prefer realistic Furries",
    "\n\t* No preference",
    "\n\t* Prefers 'toonie Furries",
    "\n\t* Prefers definite 'tooniness",
    "\n\t* Prefers complete abstraction",

    "\n\t* What do you mean: there are other things to do?(!)",
    "\n\t* Ready, willing, and able",
    "\n\t* Have done cyber-sex",
    "\n\t* Never tried cyber-sex, but not ruling it out either",
    "\n\t* Not sexually active by choice",
    "\n\t* WHUDDA BUNCHA PERVS!",

    "\n\t* Where and when do I report for transformation?",
    "\n\t* Definitely, if I get to choose species",
    "\n\t* Only if the process is reversable",
    "\n\t* Perhaps, but only if it's a proven technology",
    "\n\t* Possibly might consider it",
    "\n\t* Being human ain't half-bad",
    "\n\t* Utterly whacko idea",

    "\n\t* Made Best Seller List",
    "\n\t* Sold a book",
    "\n\t* Sold a story/article to mainstream magazine",
    "\n\t* Sold a story/article to a Furry Fan-Zine",
    "\n\t* Write for others: get good reviews",
    "\n\t* Write strictly for self",
    "\n\t* No creative writing (resumes and tax returns excepted)",
    "\n\t* Functional illiterate",
    "\n\t* Made Best Seller List: non-Furry",
    "\n\t* Sold a non-Furry book",
    "\n\t* Sold non-Furry story/article to mainstream mag.",
    "\n\t* Sold story/article to some other fan-dom's fan-zines",

    "\n\t* Publish/edit/staff for professional Furry fan-zine",
    "\n\t* Published author/artist and/or staff for regularly published amatuer fan-zine",
    "\n\t* Been published once",
    "\n\t* Buy regularly; have a good collection of 'zines",
    "\n\t* Buy sporatically, have a few collected",
    "\n\t* No interest",
    "\n\t* Those 'zines are strictly kids' stuff",

    " 60+",
    " 50 - 59",
    " 40 - 49",
    " 30 - 39",
    " 20 - 29",
    " 10 - 19",
    " < 10(!)",

    "\n\t* Master Hacker: first name basis with Stallman, Raymond, Torvolds, etc.",
    "\n\t* Master Programmer",
    "\n\t* Some programming: work with computers frequently",
    "\n\t* Computers are fun; master most apps with little difficulty",
    "\n\t* Just another tool to be used if it suits the purpose",
    "\n\t* Blinking 12:00 person",
    "\n\t* How do you turn it on?",
    "\n\t* Luddite",

    "\n\t\t* Amiga",
    "\n\t\t* One of the *BSDs",
    "\n\t\t* DOS",
    "\n\t\t* Linux",
    "\n\t\t* OS X",
    "\n\t\t* Windows XP/2000/NT",
    "\n\t\t* OS/2",
    "\n\t\t* Commercial UNIX",
    "\n\t\t* VMS",
    "\n\t\t* Win 95/98/ME",

    "\n\t* Phear my abilities!",
    "\n\t* Master \"nightmare mode\" quite easily; frequently write WAD files",
    "\n\t* Pretty good: play other WADs frequently",
    "\n\t* Good way to kill a lazy afternoon",
    "\n\t* Tried it: not impressed",
    "\n\t* Tried it: didn't like it",
    "\n\t* Miss the old favs: Pac-Man, Xaxxon, Q-bert, etc.",
    "\n\t* WHUDDA WASTA TIME!",

    "\n\t* PhD",
    "\n\t* Master's",
    "\n\t* Bachelor's",
    "\n\t* Associate's",
    "\n\t* HS Grad",
    "\n\t* Haven't finished HS yet",
    "\n\t* Grade school grad",
    "\n\t* Not completed GS yet",
    "\n\t* Self-taught",

    "\n\t* I *am* a Furry",
    "\n\t* Bark/yarf at complete strangers",
    "\n\t* Bark/yarf at friends only",
    "\n\t* Readily make references to Furriness; show off art/'zine collections",
    "\n\t* Own my Furriness",
    "\n\t* Tell close friends/family only",
    "\n\t* It's my secret and it's gonna stay that way",

    "\n\t* Married with children",
    "\n\t* Married: DINKs (or other long-term relationship)",
    "\n\t* Furry room-mates",
    "\n\t* non-Furry room-mates",
    "\n\t* Living alone: social life",
    "\n\t* Living alone: no social life",
    "\n\t* Agoraphobic",
    "\n\t* A \"nester\", still living with parents",
    "\n\t* Not settled anywhere just yet",
    "\n\t* Homeless",

    "\n\t* Web Master/Mistress/Site Admin",
    "\n\t* Web surf constantly",
    "\n\t* Web surf regularly",
    "\n\t* Web surf occasionally",
    "\n\t* No ISP right at the moment",
    "\n\t* Bill Gates was right: WWW SUX",
    "\n\t* Internet Luddite",

    "\n\t* An Otaku",
    "\n\t* Record/own every episode I see, heard about",
    "\n\t* Devote all non-Furry time to Anime",
    "\n\t* Known within Furry as Anime fan",
    "\n\t* Seen it, may watch again",
    "\n\t* Not seen it yet, but curious",
    "\n\t* Haven't heard of it before",
    "\n\t* Seen it: didn't like it",
    "\n\t* Will watch, but only if in English (or other native language)",

    "\n\t* Has own menagerie",
    "\n\t* Several pets",
    "\n\t* Two or more \"conventional\" pets, or one exotic",
    "\n\t* One \"conventional\"",
    "\n\t* No pets at the moment, will get soon",
    "\n\t* No pets: can't properly care for them at present",
    "\n\t* No pets: don't like animals (*sure* you're a Furry?(!) )",
    "\n\t* No pets: not allowed (parents, land-lord, etc>)",
    "\n\t* No pets: allergic to animal dander",

    "\n\t* What do you mean: there are other things to do?(!)",
    "\n\t* Ready, willing, and able",
    "\n\t* Have done the \"real deal\"",
    "\n\t* Have \"done it\" exactly once",
    "\n\t* Not sexually active by choice",
    "\n\t* Can't get no satisfaction...",
    "\n\t* I prefer mytosis",
    "\n\t* Faithfully married/other long-term committment",
    "\n\t* Faithfully married with children",
    NULL
};

//------------------------------------------------------------------------------

extern const char *FurCodeKeys[]=
{
    "A++++", "A+++", "A++",  "A+",   "A",    "A-",   "A--",  "A---",
    "C+++",  "C++",  "C+",   "C",    "C-",   "C--",  "C---", "C*",  "C**",
    "D++++", "D+++", "D++",  "D+",   "D",    "D-",   "D--",
    "H+++",  "H++",  "H+",   "H",    "H-",   "H--",  "H---",
    "M++++", "M+++", "M++",  "M+",   "M",    "M-",   "M--",  "M---",
    "P++++", "P+++", "P++",  "P+",   "P",    "P-",   "P--",
    "R+++",  "R++",  "R+",   "R",    "R-",   "R--",  "R---",
    "S+++",  "S++",  "S+",   "S",    "S-",   "S--",
    "T++++", "T+++", "T++",  "T+",   "T",    "T-",   "T--",
    "W++++", "W+++", "W++",  "W+",   "W",    "W-",   "W--",  "W---", "W****", "W***", "W**", "W*",
    "Z++++", "Z+++", "Z++",  "Z+",   "Z",    "Z-",   "Z--",
    "a++++", "a+++", "a++",  "a+",   "a",    "a-",   "a--",
    "c++++", "c+++", "c++",  "c+",   "c",    "c-",   "c--",  "c---",
    "os_a",  "os_b", "os_d", "os_l", "os_m", "os_n", "os_o", "os_u", "os_v", "os_w",
    "d++++", "d+++", "d++",  "d+",   "d",    "d-",   "d--",  "d---",
    "e++++", "e+++", "e++",  "e+",   "e",    "e-",   "e--",  "e*",   "e**",
    "f++++", "f+++", "f++",  "f+",   "f",    "f-",   "f--",
    "h++++", "h+++", "h++",  "h+",   "h",    "h-",   "h--",  "h*",    "h**", "h***",
    "i+++",  "i++",  "i+",   "i",    "i-",   "i--",  "i---",
    "j++++", "j+++", "j++",  "j+",   "j",    "j-",   "j--",  "j---",  "j*",
    "p+++",  "p++",  "p+",   "p",    "p-",   "p--",  "p---", "p*",    "p**",
    "s+++",  "s++",  "s+",   "s",    "s-",   "s--",  "s---", "s*",    "s**", NULL
};

//------------------------------------------------------------------------------

extern const char *PrimaryTitles[]=
{
    "\n \nFurry Art:",
    "\n \nFur Cons:",
    "\n \nFursuiting:",
    "\n \nFursona(s):",
    "\n \nPersonal Contact:",
    "\n \nMUCK Participation:",
    "\n \nPlushies:",
    "\n \nRealism in Furry Art:",
    "\n \nRL Occupation(s):",
    "\n \nFurry Sex:",
    "\n \nTransformation:",
    "\n \nFanfic:",
    "\n \nFanzines:",
    "\n \nRL Age:",
    "\n \nTech Savvy:",
    "\n \nGaming (Doom, Quake, etc.):",
    "\n \nRL education:",
    "\n \nRL Furriness:",
    "\n \nLiving Arrangements:",
    "\n \nInternet Participation:",
    "\n \nAnime:",
    "\n \nPets:",
    "\n \nRL Sex:",
    NULL
};

extern const char *TitleKeys[]= {"A", "C", "D", "F", "H", "M", "P", "R", "RL", "S", "T", "W", "Z",
				 "a", "c", "d", "e", "f", "h", "i", "j", "p", "s", NULL};

//------------------------------------------------------------------------------

extern const char *ThemeMeanings[]=
{
    "\n\t\t* No themes specified for this Furry",
    "\n\t\t* Cyborg",
    "\n\t\t* 'Toon (funny animal)",
    "\n\t\t* Were",
    "\n\t\t* Magical powers",
    "\n\t\t* Polymorphic",
    "\n\t\t* Psychic powers",
    "\n\t\t* 'Taur",
    "\n\t\t* Unicorn",
    "\n\t\t* Winged",
    NULL
};

extern const char *ThemeKeys[]= {"0", "c", "f", "h", "m", "p", "s", "t", "u", "w", NULL};

//------------------------------------------------------------------------------

extern const char *RelMeanings[]=
{
    "\n\t\t* No relationship specified for this Furry",
    "\n\t\t* Alter ego",
    "\n\t\t* A fursuit character",
    "\n\t\t* Someone to draw",
    "\n\t\t* Imaginary friend",
    "\n\t\t* On-line role play character",
    "\n\t\t* A role play game character",
    "\n\t\t* Guardian spirit or totem",
    "\n\t\t* Someone to feature in fanfic",
    NULL
};

extern const char *RelKeys[]= {"0", "a", "c", "d", "f", "m", "r", "s", "w", NULL};

//---------------------------- furcodeexternals.cpp ----------------------------

