#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>

int HauptMenu(int iMainMenuFileLoaded);

int SelectRow();
int SelectValue();


 //Test zum loeschen der Konsole
    #include <stdlib.h>
    #if WIN32
    #define CLEAR system( "cls" );
    #endif
    #if LINUX
    #define CLEAR system( "clear" );
    #endif


#endif // MENUS_H_INCLUDED
