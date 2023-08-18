//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "pila.h"

/* Costruttore. Crea una pila vuota. */

Pila::Pila ()
{
	pila = NULL;
}

/* Restituisce un valore diverso da zero se la pila e' vuota, altrimenti
 * restituisce zero. */

boolean
Pila::vuota ()
{
	return (pila == NULL);
}


/* Restituisce il valore in cima alla pila. */

tipoelem
Pila::leggi ()
{
	if (pila == NULL)
		return 0;

	return pila->leggi_valore ();
}


/* Rimuove dalla pila l'elemento in cima. */

void
Pila::fuori ()
{
	Nodo *succ;
	
	if (pila == NULL)
		return;

	succ = pila->leggi_succ ();
	delete pila;
	if (succ != NULL)
		succ->scrivi_prec (NULL);
	pila = succ;
}


/* Inserisce in cima alla pila il valore T. */

void
Pila::in (tipoelem t)
{
	Nodo *nuovo;

	nuovo = new Nodo;
	nuovo->scrivi_valore (t);
	nuovo->scrivi_prec (NULL);
	nuovo->scrivi_succ (pila);
	if (pila != NULL)
		pila->scrivi_prec (nuovo);
	pila = nuovo;
}
