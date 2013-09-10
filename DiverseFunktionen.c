#include "DiverseFunktionen.h"

extern int iAnzahlMessungen;
extern double ** afMesswerte;

int SpeicherFreigeben()
{
    int i=0;

    #ifdef DEBUG
    printf("Der Speicher wird freigegeben!\n");
    #endif // DEBUG

    // Speicherplatz wieder freigeben.
    // Wichtig! In umgekehrter Reihenfolge

    // Spalten der i-ten afMesswerte freigeben */
    for(i = 0; i < iAnzahlMessungen; i++)
      free(afMesswerte[i]);

    // Jetzt können die leeren afMesswerte freigegeben werden
    free(afMesswerte);

    return 0;
}

