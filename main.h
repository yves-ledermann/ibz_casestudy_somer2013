#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define DEBUG

    //Test zum loeschen der Konsole
    #include <stdlib.h>
    #if WIN32
    #define CLEAR system( "cls" );
    #endif
    #if LINUX
    #define CLEAR system( "clear" );
    #endif

#endif // MAIN_H_INCLUDED
