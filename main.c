#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "analyse.h"
#include "functions.h"
#include "menu_main.h"


int main()
{
/**< Haupt-Menü Anzeigen */

int iMainMenuSelection=0;
int iMainMenuExit=0;
int iMainMenuFileLoaded=0;/**< Datei erfolgreich geladen */
int iRow=0;
int iValue=0;


do // MainMenu
{
   iMainMenuSelection=menu_main(iMainMenuFileLoaded);

    switch (iMainMenuSelection)
    {
    case 1: //Einlesen der Datei mit den Messwerte
        printf("1 Einlesen der Datei mit den Messwerten\n");

        //Abfrage des Dateinamens

        //Übergabe des Dateinamens an readFile();

        //Rückgabewert auswerten

        iMainMenuFileLoaded=1;
        break;

    case 2: //Ausgeben der Messwerte am Bildschirm
         printf("2 Ausgeben der Messwerte am Bildschirm\n");
         break;

    case 3: //Auswertung der Messwerte
         printf("3 Auswertung der Messwerte\n");
         iRow=SelectRow();
         iValue=SelectValue();
         Analyse(iRow, iValue);

         break;

    case 4: //Exportieren der Messwerte
        printf("4 Exportieren der Messwerte\n");
        break;
    case 5: //Beenden des Programms
        iMainMenuExit=1;
        break;
    }



}
while (!iMainMenuExit);

    return 0;
}
