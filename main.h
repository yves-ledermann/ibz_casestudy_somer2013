#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "analyse.h"
#include "menus.h"
#include "export.h"
#include "import.h"


    //Test zum l�schen der Konsole
    #include <stdlib.h>
    #if WIN32
    #define CLEAR system( "cls" );
    #endif
    #if LINUX
    #define CLEAR system( "clear" );
    #endif

     //Bildschirm leeren
    //CLEAR

#endif // MAIN_H_INCLUDED
