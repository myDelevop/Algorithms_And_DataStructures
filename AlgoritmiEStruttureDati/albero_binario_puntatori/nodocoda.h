//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef NODOCODA_H
#define NODOCODA_H

#include <string>
#include "nodo.h"

using namespace std;

typedef Nodo tipoelem;

class NodoCoda {
	tipoelem valore;
	NodoCoda *prec, *succ;
public:
	NodoCoda ();
	void scrivi_prec (NodoCoda *);
	NodoCoda * leggi_prec ();
	void scrivi_succ (NodoCoda *);
	NodoCoda * leggi_succ ();
	void scrivi_valore (tipoelem);
	tipoelem leggi_valore ();
};

#endif
