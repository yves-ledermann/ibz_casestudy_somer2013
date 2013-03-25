int SubMenu2()
{
/**< Sub-Menü Anzeigen */

int iSubMenu2Selection=0;
int iSubMenu2Exit=0;

do // SubMenu2
{
    printf("1 Maximal-Wert\n");
    printf("2 Minimal-Wert\n");
    printf("3 Durchschnitt\n");
    printf("4 Abbrechen\n");

    scanf("%d", &iSubMenu2Selection);

    switch (iSubMenu2Selection)
    {
    case 1: //Einlesen der Datei mit den Messwerte
        printf("1 Maximal-Wert\n");
        break;

    case 2: //Ausgeben der Messwerte am Bildschirm
         printf("2 Minimal-Wert\n");
         break;

    case 3: //Auswertung der Messwerte
         printf("3 Durchschnitt\n");
         break;

    case 4: //Zurück zum Hauptmenu
        printf("4 Zurück\n");
        iSubMenu2Exit=1;
        break;
    }



}
while (!iSubMenu2Exit);

    return 0;
}
