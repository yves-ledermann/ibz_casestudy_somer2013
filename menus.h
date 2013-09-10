#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>      //getch-Funktion

//zum loeschen der Konsole
    #if WIN32
    #define CLEAR system( "cls" );
    #endif
    #if LINUX
    #define CLEAR system( "clear" );
    #endif

#endif // MENUS_H_INCLUDED
