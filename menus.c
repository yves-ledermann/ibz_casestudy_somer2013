#include "menus.h"

/*
    //Test zum löschen der Konsole
    #include <stdlib.h>
    #if WIN32
    #define CLEAR system( "cls" );
    #endif
    #if LINUX
    #define CLEAR system( "clear" );
    #endif

     //Bildschirm leeren
    CLEAR
*/

// Haupmenü anzeigen
int HauptMenu(int iDateiGeladen)
{
    int iMainMenuSelection=0;
    #ifdef DEBUG
    printf("MAINMENU:\n");
    #endif // DEBUG


    printf("1 Einlesen der Datei mit den Messwerten\n");
    if (iDateiGeladen==6)
    {
        printf("2 Ausgeben der Messwerte am Bildschirm\n");
        printf("3 Auswertung der Messwerte\n");
        printf("4 Exportieren der Messwerte\n");
    }
    printf("5 Beenden des Programms\n");
    scanf("%d", &iMainMenuSelection);
    return (iMainMenuSelection);
}


int SelectRow()
{
    int iRowSelection=0;

    printf("1 Sollwert\n");
    printf("2 Istwert\n");
    printf("3 Regeldifferenz\n");
    printf("4 Abbrechen\n");

    scanf("%d", &iRowSelection);

    return (iRowSelection);
}

int SelectValue()
{
    int iValueSelection=0;

    printf("1 Maximal-Wert\n");
    printf("2 Minimal-Wert\n");
    printf("3 Durchschnitt\n");
    printf("4 Abbrechen\n");

    scanf("%d", &iValueSelection);

    return (iValueSelection);
}
