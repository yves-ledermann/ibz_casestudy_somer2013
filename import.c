#include "import.h"

#define FILE_HEADER "IBZ_Programmiertechnik_Messdatei"

int ImportDatei(char* acDateiNameEinlesen)
{
    int file_status=0;
    FILE *datei;
    char acKopfzeile[100];

    #ifdef DEBUG
    printf("%s\n", acDateiNameEinlesen);
    #endif

    datei=fopen(acDateiNameEinlesen, "r");
    if (datei != NULL)
    {
    do
        {
        fgets(acKopfzeile, 100, datei);
            if (acKopfzeile != 0)
            {
                #ifdef DEBUG
                printf("%s", acKopfzeile);
                #endif
                file_status=2; // Kopfzeile eingelesen
            }
        }
        while (acKopfzeile != 0);
        fclose(datei);
    }
    else
    {
        file_status=1;
    }


    return(file_status);
}
