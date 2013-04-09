#include "import.h"

#define FILE_HEADER "IBZ_Programmiertechnik_Messdatei"

//#define DEBUG


int ImportDatei(char* acDateiNameEinlesen)
{
    int iImportStatus=0;
    FILE *datei;
    char acKopfzeile[100];

    #ifdef DEBUG
    printf("%s\n", acDateiNameEinlesen);
    #endif


    // Datei öffnen
    datei=fopen(acDateiNameEinlesen, "r");
    if (datei == NULL)
    {
        iImportStatus=1; // Datei kann nicht geöffnet werden
    }
    else
    {
        if (fgets(acKopfzeile, 100, datei) ==0)
            {
                iImportStatus=3; // Kopfzeile kann nicht gelesen werden
            }
        else
            {
                #ifdef DEBUG
                printf("%s", acKopfzeile);
                #endif
                iImportStatus=2; // Kopfzeile eingelesen
            }

    // Datei schliessen
    fclose(datei);
    }


    return(iImportStatus);
}
