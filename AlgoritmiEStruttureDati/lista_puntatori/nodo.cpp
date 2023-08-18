//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "nodo.h"

/* Costruttore predefinito. */

Nodo::Nodo () 
{
	prec = NULL;
	succ = NULL;
}


/* Imposta a P il nodo precedente. */

void
Nodo::scrivi_prec (Nodo *p)
{
	prec = p;
}


/* Restituisci il nodo precedente. */

Nodo *
Nodo::leggi_prec ()
{
	return prec;
}


/* Imposta a S il nodo successivo. */

void
Nodo::scrivi_succ (Nodo *s)
{
	succ = s;
}


/* Restituisci il nodo successivo. */

Nodo *
Nodo::leggi_succ ()
{
	return succ;
}


/* Imposta a T l'elemento contenuto nel nodo. */

void
Nodo::scrivi_valore (tipoelem t)
{
	valore = t;
}


/* Restituisci il valore dell'elemento contenuto nel nodo. */

tipoelem
Nodo::leggi_valore ()
{
	return valore;
}
