#include "ExportDatei.h"


// Anmelden der Globalen Variable
extern int iAnzahlMessungen;
extern double ** afMesswerte;

int ExportDatei(char* acDateiNameExport)
{
    FILE *filePtr;
    int X=0;
    int l = 0;
    int test = 0;
    char acDateiEndung [] = "\x2Etxt";

     printf("\nDie Daten werden Exportiert....\n\n");

    //auf .txt (Endung) überprüfen
    l = strlen(acDateiNameExport);

                #ifdef DEBUG
                printf("strlen %d\n",l);
                #endif // DEBUG

    int j=0, i=0;


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

    // wenn kein .txt hinzufügen
    if (test==1) {strcat(acDateiNameExport, acDateiEndung);}

    // datei öffnen
    filePtr = fopen(acDateiNameExport,"w");


    //Ueberschriften
    fprintf(filePtr,"Sollwert \tIstwert \tRegeldifferenz");

    // Messwerte in txt Datei schreiben
    for (X = 0; X < iAnzahlMessungen ; X++)
    {
        fprintf(filePtr, "\n%.3f \t%.3f \t%.3f", afMesswerte[X][0], afMesswerte[X][1], afMesswerte[X][2]);
    };

    fclose(filePtr);



    return 1;
}
