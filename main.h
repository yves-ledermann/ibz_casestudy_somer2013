#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Debug switch

// #define DEBUG

//zum loeschen der Konsole
    #if WIN32
    #define CLEAR system( "cls" );
    #endif
    #if LINUX
    #define CLEAR system( "clear" );
    #endif

//zum warten auf Tasteneingabe
    #if WIN32
    #define WARTE printf("\n\n"); system("Pause");
    #endif

#endif // MAIN_H_INCLUDED
