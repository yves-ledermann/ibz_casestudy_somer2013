#include "menus.h"



// Haupmenü anzeigen
int HauptMenu(int iDateiGeladen)
{
    int iMainMenuSelection=0;
    #ifdef DEBUG
    printf("MAINMENU:\n");
    #endif // DEBUG

//Bildschirm leeren
    CLEAR


 printf(" _    _                   _                        _   _ \n");
 printf("| |  | |                 | |                      (_) (_)\n");
 printf("| |__| | __ _ _   _ _ __ | |_ _ __ ___   ___ _ __  _   _ \n");
 printf("|  __  |/ _` | | | | '_ \\| __| '_ ` _ \\ / _ \\ '_ \\| | | |\n");
 printf("| |  | | (_| | |_| | |_) | |_| | | | | |  __/ | | | |_| |\n");
 printf("|_|  |_|\\__,_|\\__,_| .__/ \\__|_| |_| |_|\\___|_| |_|\\__,_|\n");
 printf("                    | |                                  \n");
 printf("                    |_|                                   \n");
 printf("\n");


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
