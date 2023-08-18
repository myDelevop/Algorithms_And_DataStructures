//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>

#include "coda.h"


/* Costruttore. Crea una coda vuota. */

Coda::Coda ()
{
	coda_inizio = NULL;
	coda_fine = NULL;
}


/* Restituisce un valore diverso da zero se la coda e' vuota, altrimenti
 * restituisce zero. */

boolean
Coda::vuota ()
{
	return (coda_inizio == NULL);
}


/* Restituisce il valore dell'elemento all'inizio della coda. */

tipoelem
Coda::leggi ()
{
	if (coda_inizio == NULL)
		return 0;
	return coda_inizio->leggi_valore ();
}


/* Rimuove l'elemento all'inizio della coda. */

void
Coda::fuori ()
{
	NodoCoda *succ;
	
	if (coda_inizio == NULL)
		return;
	
	if (coda_inizio == coda_fine) {
		delete coda_inizio;
		coda_inizio = NULL;
		coda_fine = NULL;
		return;
	}

	succ = coda_inizio->leggi_succ ();
	delete coda_inizio;
	succ->scrivi_prec (NULL);
	coda_inizio = succ;
}


/* Inserisce il valore T alla fine della coda. */

void
Coda::in (tipoelem t)
{
	NodoCoda *nuovo;

	nuovo = new NodoCoda;
	nuovo->scrivi_valore (t);

	if (coda_inizio == NULL) {
		coda_inizio = nuovo;
		coda_fine = nuovo;
		nuovo->scrivi_succ (NULL);
		nuovo->scrivi_prec (NULL);
		return;
	}

	coda_fine->scrivi_succ (nuovo);
	nuovo->scrivi_prec (coda_fine);
	nuovo->scrivi_succ (NULL);
	coda_fine = nuovo;
}
