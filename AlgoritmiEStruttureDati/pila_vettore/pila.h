//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef PILA_H
#define PILA_H
#include <string>

using namespace std;

typedef int tipoelem;
typedef bool boolean;

const int max_pila = 100;

class Pila {
	tipoelem pila[max_pila];
	int dimensione;
public:
	Pila ();
	boolean vuota ();
	tipoelem leggi ();
	void fuori ();
	void in (tipoelem);
};

#endif
