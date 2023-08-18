//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef CODA_H
#define CODA_H
#include "nodo.h"

typedef bool boolean;

class Coda {
	Nodo *coda_inizio;
	Nodo *coda_fine;
public:
	Coda ();
	boolean vuota ();
	tipoelem leggi ();
	void fuori ();
	void in (tipoelem);
};

#endif
