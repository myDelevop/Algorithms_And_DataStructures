#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef int posizione;
typedef bool boolean;

class Lista {
	Nodo *nodi;
	int numero_nodi;
	Nodo * trova_posizione (posizione);
public:
	//Costruttore e Distruttore
	Lista ();
	~Lista ();
	
	//Metodi
	void crealista();
	boolean listavuota ();
	tipoelem leggilista (posizione);
	void scrivilista (tipoelem, posizione);
	posizione primolista ();
	boolean finelista(posizione);
	posizione succlista (posizione);
	posizione predlista (posizione);
	void inslista (tipoelem, posizione);
	void canclista (posizione);
};

#endif
