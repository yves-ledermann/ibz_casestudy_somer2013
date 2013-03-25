#include "menu_main.h"

int menu_main(int iFileLoaded)
{
    int iMainMenuSelection=0;

    printf("MAINMENU:\n");
    printf("1 Einlesen der Datei mit den Messwerten\n");
    if (iFileLoaded) {
    printf("2 Ausgeben der Messwerte am Bildschirm\n");
    printf("3 Auswertung der Messwerte\n");
    printf("4 Exportieren der Messwerte\n");
    }
    printf("5 Beenden des Programms\n");

    scanf("%d", &iMainMenuSelection);

    return (iMainMenuSelection);
}
