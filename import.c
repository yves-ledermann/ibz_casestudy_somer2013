#include "import.h"

#define Kopfzeile "IBZ_Programmiertechnik_Messdatei"

#define DEBUG

int ImportDatei(char* acDateiNameEinlesen)
{
    int iImportStatus=0;
    FILE *datei;
    char acKopfzeile[100];

    #ifdef DEBUG
    printf("%s\n", acDateiNameEinlesen);
    #endif

    //Datei �ffnen
        datei=fopen(acDateiNameEinlesen, "r");

        if (datei == NULL){ // Datei kann nicht ge�ffnet werden
            iImportStatus=1;
            }
        else {
    //Einlesen der Datei mit den Messwerte
                if (fgets(acKopfzeile, 100, datei) ==0)
                    {
                        iImportStatus=2; // Kopfzeile kann nicht gelesen werden
                    }
                else
                    {
                        #ifdef DEBUG
                        printf("%s", acKopfzeile);
                        #endif

    // Kopfzeile �berpr�fen

                        #ifdef DEBUG
                        printf("status Kopfzeilenvergelich %d\n", strncmp ( Kopfzeile ,acKopfzeile,32));
                        #endif

                    if ((strncmp ( Kopfzeile ,acKopfzeile,32))!=0)
                        {
                            iImportStatus=3; // Kopfzeile falsch
                        }
                    else
                        {
    // Anzahl der Messresultate einlesen

    // Array gr�sse festlegen

    // Array einlesen

    // Datei erfolgreich eingelesen

                                            iImportStatus=6;


    // Datei schliessen

                                            fclose(datei);




                        } //Kopfzeile Pr�fen
                    } //Einlesen der Datei mit den Messwerte
                }//Datei �ffnen


    return(iImportStatus);
}
