#include "DiverseFunktionen.h"



extern int iAnzahlMessungen;
extern double ** afMesswerte;



int SpeicherFreigeben()
{
    int i=0;

    #ifdef DEBUG
    printf("Der Speicher wird freigegeben!\n");
    #endif // DEBUG
     /* Speicherplatz wieder freigeben.
    * Wichtig! In umgekehrter Reihenfolge. */

   /* Spalten der i-ten iAnzahlMesswerte freigeben */
   for(i = 0; i < iAnzahlMessungen; i++)
      free(afMesswerte[i]);
   /* Jetzt k�nnen die leeren iAnzahlMesswerten freigegeben werden. */
   free(afMesswerte);


    //Daten erfolgreich exportiert?
    return 1;
}
