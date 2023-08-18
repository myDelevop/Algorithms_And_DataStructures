//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef CODA_H
#define CODA_H

#include "nodocoda.h"

typedef bool boolean;

class Coda {
	NodoCoda *coda_inizio;
	NodoCoda *coda_fine;
public:
	Coda ();
	boolean vuota ();
	tipoelem leggi ();
	void fuori ();
	void in (tipoelem);
};

#endif
