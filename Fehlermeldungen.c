
#include "Fehlermeldungen.h"

int AnzeigeFehlermeldung(int iFehlermeldung)
{

printf("\n\n\nFehler Nr\x2E%d\n",iFehlermeldung);

switch (iFehlermeldung)
    {
    case 0: //Fehlermeldung: Datei kann nicht geöffnet werden
        printf("\n\nDatei kann nicht ge%cffnet werden\x21 \n",148);

        break;

    case 10: // Fehlermeldung: Kopfzeile kann nicht eingelesen werden
        printf("\n\nDie Kopfzeile kann nicht eingelesen werden\x21\n");
        break;

    case 20: // Fehlermeldung: Kopfzeilen vergleich
        printf("\n\nDer Kopfzeilenvergleich stimmt nicht %cberein\x21\n",129);
        break;

    case 30: // Fehlermedlung: Die Anzahl Messwerte konnte nicht eingelesen werden
        printf("\n\nDie Anzahl der Messwerte konnte nicht eingelesen werden\x21\n");
        break;

    case 40: //Fehlermeldung: Die Anzahl Messwerte sind ausserhalb dem Bereich
        printf("\n\nDie Anzahl Messwerte sind ausserhalb dem g\x81ltigen Bereich\x21\n");
        break;

    case 51:
    case 52: // Fehlermeldung 51: Keine Virtuelle RAM mehr vorhanden. Fehlermeldung 52: Kein Speicher mehr für Messwerte
        printf("\n\nNicht gen\x81gend Arbeitsspeicher vorhanden\x21\n");
        break;

    case 99: // Fehlermeldung: Unbehandelter Fehler beim Import
        printf("\n\nEs ist ein unbekannter Fehler beim Import aufgetreten\x21\n");
        break;


    default:
        printf("\n\nEs ist ein unbekannter Fehler aufgetreten\x21\n");
    }

return 0;
}



