#include "main.h"

// Definition der Globalen Variablen die in vielen Funktionen benutzt werden.
int iAnzahlMessungen=0; // Anzahl Messungen in der eingelesenen Datei
double ** afMesswerte=NULL; // mehrfache Indirektion (zeiger auf Zeiger) zum Array mit den Messwerten

// Funktionen deklarieren
int ExportDatei(char* acDateiNameExport);
int Analyse(int iSelectedRow, int iSelectedValue);
int SpeicherFreigeben();
int ImportDatei(char* acDateiNameEinlesen);
int HauptMenu(int iDateiGeladen);
int MenuAuswahlSpalte();
int MenuAuswahlBerechnung();
int AnzeigeFehlermeldung(int iFehlermeldung);

// Main-Funktion - (Definition)
int main(int argc, char *argv[]) //argc= Anzahl kommandozeilen Argumente, argv Inhalt in einem String gespeichert.
{
    int iHauptMenuAuswahl=0;
    int iHauptMenuEnde=0;
    int iEinlesenStatus=0; // 98= Datei geladen
    int iSpalte=0;
    int iWert=0;
    int iExportStatus=0;
    int X=0;

    char acDateiNameEinlesen[FILENAME_MAX]; // Dateiname zum Einlesen// FILENAME_MAX ist in stdio.h maximale länge des Dateinamens.
    char acDateiNameExport[FILENAME_MAX];  // Dateiname zum Exportieren


    //Der erste Parameter (argc) beinhaltet, die Anzahl von Argumenten, die dem Programm beim Start übergeben wurden. Dabei handelt es sich um einen Integerwert.
    //Im zweiten Parameter(argv) stehen die einzelnen Argumente. Diese werden als Strings in einer Stringtabelle gespeichert.

    if (argc == 2) // Anzahl kommandozeilen Argumente
    {
                                #ifdef DEBUG  // War eine Hilfe für uns damit wir die zurückgegebenen Werte sehen.
                                printf("Datei von Kommandozeile\n");
                                printf("%s\n", argv[1]);
                                #endif // DEBUG

        //Übergabe des Dateinamens an readFile();
        iEinlesenStatus=ImportDatei(argv[1]);

                                #ifdef DEBUG
                                printf("%d", iEinlesenStatus);
                                #endif

        if (iEinlesenStatus != 98){ // Fehlermeldung,muss Wert 98 haben wenn Datei geladen.
        AnzeigeFehlermeldung(iEinlesenStatus);
        WARTE
        }
    }


    //Haupt-Menü
    do // MainMenu
    {

        // Menü-Auswahl Anzeigen und Auswahl einlesen
        iHauptMenuAuswahl=HauptMenu(iEinlesenStatus); // Funktion Hauptmenü

        //
        switch (iHauptMenuAuswahl) // Menü Auswahl 1,2,3,4,5,)
        {
        case 1: //Einlesen der Datei mit den Messwerte

            #ifdef DEBUG
            printf("1 Einlesen der Datei mit den Messwerten\n");
            #endif // DEBUG

            //Abfrage des Dateinamens
            printf("Bitte Dateiname eingeben\n\n");
            scanf("%s", acDateiNameEinlesen);

            //Übergabe des Dateinamens an Importdatei();

            // Wechsel zur Funktion Import (Yves)!!!


            iEinlesenStatus=ImportDatei(acDateiNameEinlesen);
            #ifdef DEBUG
            printf("%d", iEinlesenStatus);
            #endif
            //Rückgabewert auswerten
            // Wenn nicht geladen ist nicht 98
            if (iEinlesenStatus != 98)
            AnzeigeFehlermeldung(iEinlesenStatus);
            // Wenn geladen ist 98
            else
            printf("\nDatei wurde erfolgreich geladen\n");
            WARTE
            break;

        case 2: //Ausgeben der Messwerte am Bildschirm
            #ifdef DEBUG
            printf("2 Ausgeben der Messwerte am Bildschirm\n");
            printf("iAnzahlMessungen ist %d\n", iAnzahlMessungen);
            #endif // DEBUG
            // Wiedergeben am Bildschirm des Arrays afMesswerte()
            X=0;
            printf("\nMessung Nr \t Sollwert \t Istwert \tRegeldifferenz");
            for (X = 0; X < iAnzahlMessungen ; X++)
            {
                printf("\n%3i \t\t%8.3f \t%8.3f \t%8.3f", X+1, afMesswerte[X][0], afMesswerte[X][1], afMesswerte[X][2]);
            };

            WARTE

        break;

        case 3: //Auswertung der Messwerte
            printf("3 Auswertung der Messwerte\n");

            iSpalte=MenuAuswahlSpalte(); // Funktions Aufruf MenuAuswahlSpalte()

            // Wechsel zur Funktion MenuAuswahlSpalte!!

            if ((iSpalte<=3) && (iSpalte>=1))
                {
                  iWert=MenuAuswahlBerechnung();

                  // Wechsel zur Funktion MenuAuswahlBerechnung!!!!

                    if ((iWert>=1) && (iWert <=3))
                        {
                           Analyse(iSpalte-1, iWert);// Funktion Analyse, iWert gibt an was berechnet wird.

                           // Wechsel zur Funktion Analyse !!!!

                        }
                    else
                    printf("Falsche Eingabe oder Abbruch\n");

                }

            else
            printf("Falsche Eingabe oder Abbruch\n");

            WARTE
            break; // bei Tastendruck folgt break=wieder zurück zum Hauptmenu

        case 4: //Exportieren der Messwerte
        {
            #ifdef DEBUG
            printf("4 Exportieren der Messwerte\n");
            #endif // DEBUG

            //Abfrage des Dateinamens
            printf("Bitte Dateinamen f\x81r Export eingeben\n");
            scanf("%s", acDateiNameExport);

            //Übergabe des Dateinamens an Export();

            // Wechsel zur Funktion ExportDatei!!!!

            iExportStatus=ExportDatei(acDateiNameExport);

            //Meldung export
            if (iExportStatus)// Wert 1 von return1 der ExportDatei Funktion.
                printf("Daten wurden erfolgreich Exportiert\n");
            else
                printf("Die Daten konnten nicht exportiert werden\n");

           WARTE
            break;

        }
        case 5: //Beenden des Programms
             if (iEinlesenStatus == 98){

            SpeicherFreigeben(); // Funktion SpeicherFreigeben()

            // Wechsel zur Funktion SpeicherFreigeben!!!!

             }

            iHauptMenuEnde=1;
            break;

        default: //Fehlermeldung
            printf("\n Falsche Eingabe\n");
             WARTE
            break;
        }

    }
    while (!iHauptMenuEnde); //Solange kein 1 in iHauptMenuEnde wieder Hauptmenu Anzeige.

    return 0;
}
