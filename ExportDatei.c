#include "ExportDatei.h"

extern int iAnzahlMessungen;
extern double ** afMesswerte;

#define dateiendung ".txt"
int ExportDatei(char* acDateiNameExport)
{
    FILE *filePtr;
    int X=0;
    int l = 0;
    int test = 0;
    char acDateiEndung [] = "\x2Etxt";

     printf("\nDie Daten werden Exportiert....\n\n");

    //auf .txt überprüfen
    l = strlen(acDateiNameExport);
    #ifdef DEBUG
                printf("strlen %d\n",l);

                #endif // DEBUG
    int j=0, i=0;
    j=0;
    i=0;
    for (i = l-4; i < l; i++){
        if (acDateiNameExport[i] != acDateiEndung[j])
        {
            test=1;
        }
        j++;
        #ifdef DEBUG
                printf("Vergleich %d %d %c %c\n",i,j,acDateiNameExport[i], acDateiEndung[j]);
                printf("Vergleich Status %i\n",test);
                #endif // DEBUG
    }



    if (test==1) {strcat(acDateiNameExport, acDateiEndung);}


    filePtr = fopen(acDateiNameExport,"w");


    for (X = 0; X < iAnzahlMessungen ; X++)
    {
        fprintf(filePtr, "\n%3i \t\t%.3f \t\t%.3f \t\t%.3f", X+1, afMesswerte[X][0], afMesswerte[X][1], afMesswerte[X][2]);
    };

    fclose(filePtr);



    //Daten erfolgreich exportiert?
    return 1;
}
