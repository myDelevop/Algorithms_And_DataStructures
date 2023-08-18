//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "coda.h"

/* Costruttore. Crea una coda vuota. */

Coda::Coda ()
{
	dimensione = 0;
}


/* Restituisce un valore diverso da zero se la coda e' vuota, altrimenti
 * restituisce zero. */

boolean
Coda::vuota ()
{
	return (dimensione == 0);
}


/* Restituisce il valore dell'elemento all'inizio della coda. */

tipoelem
Coda::leggi ()
{
	if (dimensione == 0)
		return 0;

	return coda[0];
}


/* Rimuove l'elemento all'inizio della coda. */

void
Coda::fuori ()
{
	if (dimensione == 0)
		return;

	for (int i = 0; i < dimensione - 1; i++)
		coda[i] = coda[i + 1];
	dimensione--;
}


/* Inserisce il valore T alla fine della coda. */

void
Coda::in (tipoelem t)
{
	if (dimensione >= max_coda)
		return;

	coda[dimensione] = t;
	dimensione++;
}
