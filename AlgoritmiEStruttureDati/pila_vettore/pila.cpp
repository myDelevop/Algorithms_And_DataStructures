//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "pila.h"

/* Costruttore. Crea una pila vuota. */

Pila::Pila ()
{
	dimensione = 0;
}

/* Restituisce un valore diverso da zero se la pila e' vuota, altrimenti
 * restituisce zero. */

boolean
Pila::vuota ()
{
	return (dimensione == 0);
}


/* Restituisce il valore in cima alla pila. */

tipoelem
Pila::leggi ()
{
	if (dimensione == 0)
		return 0;
	
	return pila[dimensione-1];
}


/* Rimuove dalla pila l'elemento in cima. */

void
Pila::fuori ()
{
	if (dimensione == 0)
		return;

	dimensione--;
}


/* Inserisce in cima alla pila il valore T. */

void
Pila::in (tipoelem t)
{
	if (dimensione >= max_pila)
		return;

	pila[dimensione] = t;
	dimensione++;
}
