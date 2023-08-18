//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef LISTA_H
#define LISTA_H
#include <string>

using namespace std;

typedef int posizione;
typedef int tipoelem;
typedef bool boolean;

const int max_lista = 100;

class Lista {
	tipoelem lista[max_lista];
	int dimensione;
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
	boolean finelista (posizione);
	posizione succlista (posizione);
	posizione predlista (posizione);
	void inslista (tipoelem, posizione);
	void canclista (posizione);
};

#endif
