//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef PILA_H
#define PILA_H
#include "nodo.h"

typedef bool boolean;

class Pila {
	Nodo *pila;
public:
	Pila ();
	boolean vuota ();
	tipoelem leggi ();
	void fuori ();
	void in (tipoelem);
};

#endif
