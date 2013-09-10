#include "Analyse.h"

// Globale Variablen
extern int iAnzahlMessungen;
extern double ** afMesswerte;

int Analyse(int iSelectedRow, int iSelectedValue)
{
    float fpuffer = afMesswerte[0][iSelectedRow]; // erster Wert auf den Puffer setzen. Wegen denn negativen Werten
    int x=0;
    switch (iSelectedValue) // gew�hlter Wert (Berechnungsart) aus den Hauptmen�
    {
        case 1:     //Maximal-Wert

            for(x=0;x<iAnzahlMessungen;x++)
            {
                if (fpuffer<afMesswerte[x][iSelectedRow])
                {
                    fpuffer=afMesswerte[x][iSelectedRow];
                }
            }
            printf("\nDer Maximal-Wert ist %f\n", fpuffer);
            break;

        case 2:     //Minimal-Wert

            for(x=0;x<iAnzahlMessungen;x++)
            {
                if (fpuffer>afMesswerte[x][iSelectedRow])
                {
                    fpuffer=afMesswerte[x][iSelectedRow];
                }
            }
            printf("\nDer Minimal-Wert ist %f\n", fpuffer);
            break;

        case 3:     //Durchschnitts-Wert

            fpuffer = 0 ;

            for(x=0;x<iAnzahlMessungen;x++)
            {
                fpuffer +=afMesswerte[x][iSelectedRow];
            }
            printf("\nDer Durchschnitts-Wert ist %f\n", fpuffer/iAnzahlMessungen); //Puffer durch die Anzahl Messungen
            break;
    }
    #ifdef DEBUG
    printf("Sie haben folgende Spalte gew\x84hlt %d\n", iSelectedRow);
    printf("Sie haben folgenden Wert gew\x84hlt %d\n", iSelectedValue);
    #endif

    return 0;
}
