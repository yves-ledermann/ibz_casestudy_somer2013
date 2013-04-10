#include "main.h"

#define DEBUG

int main(int argc, char *argv[])
{
    int iHauptMenuAuswahl=0;
    int iHauptMenuEnde=0;
    int iEinlesenStatus=0; // 6= Datei geladen
    int iSpalte=0;
    int iWert=0;
    int iExportStatus=0;

    char acDateiNameEinlesen[FILENAME_MAX]; // Dateiname zum Einlesen
    char acDateiNameExport[FILENAME_MAX]; // Dateiname zum Exportieren


    // Auf Kommandozeilen Argumente prüfen
    if (argc == 2)
    {
         #ifdef DEBUG
        printf("Datei von Kommandozeile\n");
        printf("%s\n", argv[1]);
        #endif // DEBUG

        //Übergabe des Dateinamens an readFile();
        iEinlesenStatus=ImportDatei(argv[1]);
        #ifdef DEBUG
        printf("%d", iEinlesenStatus);
        #endif


    }


    //Haupt-Menü Anzeigen
    do // MainMenu
    {
        iHauptMenuAuswahl=HauptMenu(iEinlesenStatus);

        switch (iHauptMenuAuswahl)
        {
        case 1: //Einlesen der Datei mit den Messwerte

            #ifdef DEBUG
            printf("1 Einlesen der Datei mit den Messwerten\n");
            #endif // DEBUG

            //Abfrage des Dateinamens
            printf("Bitte Dateinamen eingeben\n");
            scanf("%s", acDateiNameEinlesen);

            //Übergabe des Dateinamens an readFile();
            iEinlesenStatus=ImportDatei(acDateiNameEinlesen);
            #ifdef DEBUG
            printf("%d", iEinlesenStatus);
            #endif
            //Rückgabewert auswerten

            iEinlesenStatus=6;
            break;

        case 2: //Ausgeben der Messwerte am Bildschirm
            #ifdef DEBUG
            printf("2 Ausgeben der Messwerte am Bildschirm\n");
            #endif // DEBUG
            break;

        case 3: //Auswertung der Messwerte
            printf("3 Auswertung der Messwerte\n");
            iSpalte=SelectRow();
            if (iSpalte!=4)
            iWert=SelectValue();
            if ((iWert !=4) || (iSpalte !=4))
            Analyse(iSpalte, iWert);
            break;

        case 4: //Exportieren der Messwerte
        {
            #ifdef DEBUG
            printf("4 Exportieren der Messwerte\n");
            #endif // DEBUG

            //Abfrage des Dateinamens
            printf("Bitte Dateinamen für Export eingeben\n");
            scanf("%s", acDateiNameExport);

            //Übergabe des Dateinamens an Export();
            iExportStatus=ExportDatei(acDateiNameExport);

            //Meldung export
            if (iExportStatus)
                printf("Daten erfolgreich Exportiert\n");
            else
                printf("Die Daten konnten nicht exportiert werden\n");
            break;

        }
        case 5: //Beenden des Programms
            iHauptMenuEnde=1;
            break;

        default: //Fehlermeldung
            printf("Falsche Eingabe\n");
            break;
        }
    }
    while (!iHauptMenuEnde);

    return 0;
}
