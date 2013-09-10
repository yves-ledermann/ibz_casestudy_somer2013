#include "Analyse.h"

// Globale Variablen
extern int iAnzahlMessungen;
extern double ** afMesswerte;

/*Funktion zum Berechnen der Werte, = Definition / Der Parameter iSelectedRow wird von der Funktion (int MenuAuswahlSpalte) übernommen.
Der Parameter iSelectedValue wird von der Funktion (int MenuAuswahlBerechnung) übernommen*/
int Analyse(int iSelectedRow, int iSelectedValue)
{
    float fpuffer = afMesswerte[0][iSelectedRow]; // erster Wert auf den Puffer setzen. Wegen denn negativen Werten
    int x=0;
    switch (iSelectedValue) // gewählter Wert (Berechnungsart) aus den Hauptmenü
    {
        case 1:     //Maximal-Wert

            for(x=0;x<iAnzahlMessungen;x++) // Variable x wird nach oben gezählt solange sie klener als die Variable iAnzahlMessungen ist.
            {
                if (fpuffer<afMesswerte[x][iSelectedRow]) // Überprüfen ob Messwert kleiner als Puffer.
                {
                    fpuffer=afMesswerte[x][iSelectedRow]; // Wenn Messwert kleiner, wird er in Puffer übertragen.
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
