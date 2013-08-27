#include "main.h"

// Globale Variablen die in vielen Funktionen Benutzt werden
int iAnzahlMessungen=0;
double ** afMesswerte=NULL;

// Funktionen
int ExportDatei(char* acDateiNameExport);
int Analyse(int SelectedRow, int SelectedValue);
int SpeicherFreigeben();
int ImportDatei(char* acDateiNameEinlesen);
int HauptMenu(int iDateiGeladen);
int MenuAuswahlSpalte();
int MenuAuswahlBerechnung();
int AnzeigeFehlermeldung(int iFehlermeldung);


int main(int argc, char *argv[])
{
    int iHauptMenuAuswahl=0;
    int iHauptMenuEnde=0;
    int iEinlesenStatus=0; // 98= Datei geladen
    int iSpalte=0;
    int iWert=0;
    int iExportStatus=0;

    char acDateiNameEinlesen[FILENAME_MAX]; // Dateiname zum Einlesen
    char acDateiNameExport[FILENAME_MAX];  // Dateiname zum Exportieren

    int X=0;

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

        if (iEinlesenStatus != 98){
        AnzeigeFehlermeldung(iEinlesenStatus);
        WARTE
        }
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
            printf("Bitte Dateiname eingeben\n\n");
            scanf("%s", acDateiNameEinlesen);

            //Übergabe des Dateinamens an readFile();
            iEinlesenStatus=ImportDatei(acDateiNameEinlesen);
            #ifdef DEBUG
            printf("%d", iEinlesenStatus);
            #endif
            //Rückgabewert auswerten
            if (iEinlesenStatus != 98){
            AnzeigeFehlermeldung(iEinlesenStatus);
            }
            WARTE
            break;

        case 2: //Ausgeben der Messwerte am Bildschirm
            #ifdef DEBUG
            printf("2 Ausgeben der Messwerte am Bildschirm\n");
            printf("iAnzahlMessungen ist %d\n", iAnzahlMessungen);
            #endif // DEBUG

            X=0;
            printf("\nMessung Nr \tSollwert \tIstwert \tRegeldifferenz");
            for (X = 0; X < iAnzahlMessungen ; X++)
            {
                printf("\n%3i \t\t%.3f \t\t%.3f \t\t%.3f", X+1, afMesswerte[X][0], afMesswerte[X][1], afMesswerte[X][2]);
            };

            WARTE

        break;

        case 3: //Auswertung der Messwerte
            printf("3 Auswertung der Messwerte\n");
            iSpalte=MenuAuswahlSpalte();
            if (iSpalte!=4)
            iWert=MenuAuswahlBerechnung();
            if ((iWert !=4) || (iSpalte !=4))
            Analyse(iSpalte, iWert);

           WARTE
            break;

        case 4: //Exportieren der Messwerte
        {
            #ifdef DEBUG
            printf("4 Exportieren der Messwerte\n");
            #endif // DEBUG

            //Abfrage des Dateinamens
            printf("Bitte Dateinamen f\x81r Export eingeben\n");
            scanf("%s", acDateiNameExport);

            //Übergabe des Dateinamens an Export();
            iExportStatus=ExportDatei(acDateiNameExport);

            //Meldung export
            if (iExportStatus)
                printf("Daten wurden erfolgreich Exportiert\n");
            else
                printf("Die Daten konnten nicht exportiert werden\n");

           WARTE
            break;

        }
        case 5: //Beenden des Programms
             if (iEinlesenStatus == 98){
            SpeicherFreigeben();
             }

            iHauptMenuEnde=1;
            break;

        default: //Fehlermeldung
            printf("\n Falsche Eingabe\n");
            break;
        }

    }
    while (!iHauptMenuEnde);

    return 0;
}
