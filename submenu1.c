int SubMenu1()
{
/**< Sub-Menü Anzeigen */

int iSubMenu1Selection=0;
int iSubMenu1Exit=0;

do // SubMenu1
{
    printf("1 Sollwert\n");
    printf("2 Istwert\n");
    printf("3 Regeldifferenz\n");
    printf("4 Abbrechen\n");

    scanf("%d", &iSubMenu1Selection);

    switch (iSubMenu1Selection)
    {
    case 1: //Einlesen der Datei mit den Messwerte
        printf("1 Sollwert\n");
        break;

    case 2: //Ausgeben der Messwerte am Bildschirm
         printf("2 Istwert\n");
         break;

    case 3: //Auswertung der Messwerte
         printf("3 Regeldifferenz\n");
         break;

    case 4: //Zurück zum Hauptmenu
        printf("4 Zurück\n");
        iSubMenu1Exit=1;
        break;
    }



}
while (!iSubMenu1Exit);

    return 0;
}
