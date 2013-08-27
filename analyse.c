#include "Analyse.h"

// Globale Variablen
extern int iAnzahlMessungen;
extern double ** afMesswerte;

// Funktion zum Berechnen der Werte
int Analyse(int SelectedRow, int SelectedValue)
{
    float fpuffer = afMesswerte[0][SelectedRow];
    int x=0;
    switch (SelectedValue)
    {
        case 1:     //Maximal-Wert

            for(x=0;x<iAnzahlMessungen;x++)
            {
                if (fpuffer<afMesswerte[x][SelectedRow])
                {
                    fpuffer=afMesswerte[x][SelectedRow];
                }
            }
            printf("\nDer Maximal-Wert ist %f\n", fpuffer);
            break;

        case 2:     //Minimal-Wert

            for(x=0;x<iAnzahlMessungen;x++)
            {
                if (fpuffer>afMesswerte[x][SelectedRow])
                {
                    fpuffer=afMesswerte[x][SelectedRow];
                }
            }
            printf("\nDer Minimal-Wert ist %f\n", fpuffer);
            break;

        case 3:     //Durchschnitts-Wert

            fpuffer = 0 ;

            for(x=0;x<iAnzahlMessungen;x++)
            {
                fpuffer +=afMesswerte[x][SelectedRow];
            }
            printf("\nDer Durchschnitts-Wert ist %f\n", fpuffer/iAnzahlMessungen);
            break;
    }
    #ifdef DEBUG
    printf("Sie haben folgende Spalte gew\x84hlt %d\n", SelectedRow);
    printf("Sie haben folgenden Wert gew\x84hlt %d\n", SelectedValue);
    #endif

    return 0;
}
