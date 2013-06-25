#include "ImportDatei.h"

extern int iAnzahlMessungen;
extern double ** afMesswerte;


int ImportDatei(char* acDateiNameEinlesen)
{
    int iImportStatus=0;
    FILE *datei;
    char acKopfzeile[100];
    char acAnzahlMessungen[20];
    int iStateImport=0;
    int i=0, x=0, y=0, z=0;
    /* afMesswerte ist Zeiger auf double-Zeiger. */

    char puffer[200];
    char acWert[20];

 // #include "globale-vars.h"

    #ifdef DEBUG
    printf("%s\n", acDateiNameEinlesen);
    #endif


    switch (iStateImport)
        {
        case 0: //Datei öffnen

            datei=fopen(acDateiNameEinlesen, "r");

            #ifdef DEBUG
            printf("%d", iStateImport);
            #endif

            if (datei == NULL){
                iImportStatus=0; // Datei kann nicht geöffnet werden
                break;
            }

         case 10: //Einlesen der Kopfzeile
            if (fgets(acKopfzeile, 100, datei) ==0) // ==0 Überprüfen
                {
                    iImportStatus=10; // Kopfzeile kann nicht gelesen werden
                    break;
                }

            #ifdef DEBUG
            printf("%s", acKopfzeile);
            #endif

        case 20: // Kopfzeile überprüfen

            #ifdef DEBUG
            printf("status Kopfzeilenvergelich %d\n", strncmp ( Kopfzeile ,acKopfzeile,32));
            #endif

            if ((strncmp ( Kopfzeile ,acKopfzeile,32))!=0)
                {
                    iImportStatus=20; // Kopfzeile falsch
                    break;
                }

        case 30: // Anzahl der Messresultate einlesen
            if (fgets(acAnzahlMessungen, 20, datei)!=0) // !=0 überprüfen
                {
                    #ifdef DEBUG
                    printf("Anzahl Messungen CArray %s\n", acAnzahlMessungen);
                    #endif

                    iAnzahlMessungen=atoi(acAnzahlMessungen);

                    #ifdef DEBUG
                    printf("Anzahl Messungen INT %d\n", iAnzahlMessungen);
                    #endif
                }
            else
                {
                   iImportStatus=30;// Anzahl Messungen können nicht eingelesen werden
                    break;
                }

        case 40: // Anzahl der Messresultate überprüfen
            if ((iAnzahlMessungen < MINWERT)||(iAnzahlMessungen > MAXWERT))
                {
                   iImportStatus=40;// Anzahl Messungen ausserhalb des Bereichs
                   break;
                }

        case 50: // Array grösse festlegen  & speicher zuweisen

            // Speicher reservieren für die float-Zeiger (=iAnzahlMessungen)
            afMesswerte = malloc(iAnzahlMessungen * sizeof(double *));

            if(NULL == afMesswerte)
                {
                iImportStatus=51; //Kein virtueller RAM mehr vorhanden ... !
                break;
                }

            // jetzt noch Speicher reservieren für die einzelnen Spalten
            // der i-ten iAnzahlMessungen
            for(i = 0; i < iAnzahlMessungen; i++)
            {
            afMesswerte[i] = malloc(SPALTE * sizeof(double));
            if(NULL == afMesswerte[i])
                {
                iImportStatus=52; //Kein Speicher mehr fuer iAnzahlMessungen!
                break;
                }
            }

        case 60: // Array einlesen

            i=0;
            y=0;
            x=0;

            do
            {
                fgets(puffer, 250, datei); //Zeilenweise einlesen

                    #ifdef DEBUG
                    printf("Zeilen-Puffer %s\n", puffer);
                    #endif


                do // Wert in array abspeichern
                    {
                        do // Chars in Werte-Puffer einlesen bis :
                            {
                                acWert[z]= puffer[i];

                                #ifdef DEBUG
                                printf("Char-puffer %d %s\n", i, acWert);
                                #endif
                                i++;
                                z++;
                            }
                         while (puffer[i]!= 58); // AbbruchZeichen ist :

                                #ifdef DEBUG
                                printf("while abbruch char  %d \n",puffer[i]);
                                #endif

                        i++;
                        acWert[z]='\0';
                        #ifdef DEBUG
                                printf("acWert zum speichern %d %d %s\n", x, y, acWert);
                                #endif

                        afMesswerte[x][y]=atof (acWert);
                        y++;
                        z=0;


                    }
                while (puffer[1+i]!= '\0');

                x++;
                i=0;
                y=0;
                z=0;

            }
            while (x < iAnzahlMessungen);

        case 70: // Datei erfolgreich eingelesen



        case 98:
            iImportStatus=98; //Datei eingelesen
            break;
        default:
            iImportStatus=99; //Unbehandelte Fehlermeldung
            break;


        }
    // Datei schliessen

        #ifdef DEBUG
        printf("iAnzahlMessungen zum speichern %d \n", iAnzahlMessungen);
        #endif
    fclose(datei);
    return(iImportStatus);
}
