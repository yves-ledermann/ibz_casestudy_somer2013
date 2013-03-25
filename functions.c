#include "functions.h"

int SelectRow()
/** \brief Spalte/Wert zum Analysieren ausw�hlen
 *
 * \return gew�hlte Spalte
 *
 */
/**< Spalte/Wert ausw�hlen */
{
    int iRowSelection=0;

    printf("1 Sollwert\n");
    printf("2 Istwert\n");
    printf("3 Regeldifferenz\n");
    printf("4 Abbrechen\n");

    scanf("%d", &iRowSelection);

    return (iRowSelection);
}

int SelectValue()

/**< Berechnungsart ausw�hlen */

{
    int iValueSelection=0;

    printf("1 Maximal-Wert\n");
    printf("2 Minimal-Wert\n");
    printf("3 Durchschnitt\n");
    printf("4 Abbrechen\n");

    scanf("%d", &iValueSelection);

    return (iValueSelection);
}
