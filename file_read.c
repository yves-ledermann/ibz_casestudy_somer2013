#include "file_read.h"

#define FILE_HEADER "IBZ_Programmiertechnik_Messdatei"

int read_file(char* acdatein)
{
    int file_status=0;
    FILE *datei;
    char headerbuffer[100];

    #ifdef DEBUG
    printf("%s\n", acdatein);
    #endif

    datei=fopen(acdatein, "r");
    if (datei != NULL)
    {
    do
        {
        fgets(headerbuffer, 100, datei);
            if (headerbuffer != 0)
            {
                #ifdef DEBUG
                printf("%s", headerbuffer);
                #endif
                file_status=2; // Kopfzeile eingelesen
            }
        }
        while (headerbuffer != 0);
        fclose(datei);
    }
    else
    {
        file_status=1;
    }


    return(file_status);
}
