//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef CODA_H
#define CODA_H
#include <string>

using namespace std;

typedef int tipoelem;
typedef bool boolean;

const int max_coda = 100;

class Coda {
	tipoelem coda[max_coda];
	int dimensione;
public:
	Coda ();
	boolean vuota ();
	tipoelem leggi ();
	void fuori ();
	void in (tipoelem);
};

#endif
