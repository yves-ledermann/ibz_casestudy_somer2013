#include "Menus.h"


// Haupmenü anzeigen
int HauptMenu(int iDateiGeladen)
{
    int iMainMenuSelection=0;
    char buf=0;

                        #ifdef DEBUG
                        printf("MAINMENU:\n");
                        #endif // DEBUG

    //Bildschirm leeren wenn nicht DEBUG
    #ifndef DEBUG
    CLEAR
    #endif // DEBUG



printf("\n");
printf(" _    _                   _                        _   _ \n");
printf("| |  | |                 | |                      (_) (_)\n");
printf("| |__| | __ _ _   _ _ __ | |_ _ __ ___   ___ _ __  _   _ \n");
printf("|  __  |/ _` | | | | '_ \\| __| '_ ` _ \\ / _ \\ '_ \\| | | |\n");
printf("| |  | | (_| | |_| | |_) | |_| | | | | |  __/ | | | |_| |\n");
printf("|_|  |_|\\__,_|\\__,_| .__/ \\__|_| |_| |_|\\___|_| |_|\\__,_|\n");
printf("                    | |                                  \n");
printf("                    |_|                                   \n");
printf("\n");
printf("\n");

    printf("1 Einlesen der Datei mit den Messwerten\n");
    if (iDateiGeladen==98)
    {
        printf("2 Ausgeben der Messwerte am Bildschirm\n");
        printf("3 Auswertung der Messwerte\n");
        printf("4 Exportieren der Messwerte\n");
        printf("5 Beenden des Programms\n");
        printf("\nBitte eine Auswahl treffen\n");
    }
    else
    {
        printf("5 Beenden des Programms\n");
        printf("\nKeine Datei geladen\num alle Optionen zu sehen\x2C bitte zuerst eine Datei laden\x2E\n");
    }

    // Einlesen der Menü-Auswahl
    buf=getch();
    // Umwandeln in Int
    sscanf(&buf, "%d", &iMainMenuSelection );


                    #ifdef DEBUG
                    printf("\nselection:%d\n",iMainMenuSelection);
                    #endif // DEBUG

    return (iMainMenuSelection);
}



int MenuAuswahlSpalte()
{
    int iRowSelection=0;
    char buf=0;

    // Untermenü anzeigen
    printf("\n\n1 Sollwert\n");
    printf("2 Istwert\n");
    printf("3 Regeldifferenz\n");
    printf("4 Abbrechen\n");

    // Auswahl Zeichenweise einlesen
    buf=getch();
    // und nach INT umwandeln
    sscanf(&buf, "%d", &iRowSelection );

    #ifdef DEBUG
    printf("\nselection:%d\n",iRowSelection);
    #endif // DEBUG

    return (iRowSelection);
}

int MenuAuswahlBerechnung()
{
    int iValueSelection=0;
    char buf=0;

    // Anzeige des Untermenüs
    printf("\n\n1 Maximal-Wert\n");
    printf("2 Minimal-Wert\n");
    printf("3 Durchschnitt\n");
    printf("4 Abbrechen\n");

    buf=getch();
    sscanf(&buf, "%d", &iValueSelection );

    #ifdef DEBUG
    printf("\nselection:%d\n",iValueSelection);
    #endif // DEBUG

    return (iValueSelection);
}
