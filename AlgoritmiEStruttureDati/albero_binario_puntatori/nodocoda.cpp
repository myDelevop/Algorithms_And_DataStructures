//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "nodocoda.h"


/* Costruttore predefinito. */

NodoCoda::NodoCoda () 
{
	prec = NULL;
	succ = NULL;
}


/* Imposta a P il NodoCoda precedente. */

void
NodoCoda::scrivi_prec (NodoCoda *p)
{
	prec = p;
}


/* Restituisci il NodoCoda precedente. */

NodoCoda *
NodoCoda::leggi_prec ()
{
	return prec;
}


/* Imposta a S il NodoCoda successivo. */

void
NodoCoda::scrivi_succ (NodoCoda *s)
{
	succ = s;
}


/* Restituisci il NodoCoda successivo. */

NodoCoda *
NodoCoda::leggi_succ ()
{
	return succ;
}


/* Imposta a T l'elemento contenuto nel NodoCoda. */

void
NodoCoda::scrivi_valore (tipoelem t)
{
	valore = t;
}


/* Restituisci il valore dell'elemento contenuto nel NodoCoda. */

tipoelem
NodoCoda::leggi_valore ()
{
	return valore;
}
