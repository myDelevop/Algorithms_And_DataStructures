//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef ALBEROBIN_H
#define ALBEROBIN_H
#include "nodoalbn.h"

typedef bool booleano;

class AlberoN {
	
    NodoN Rad;

public:
	//Costruttore e Distruttore
	AlberoN();
	~AlberoN();
	
	//Metodi Base	
	booleano alberovuoto();
	NodoN radice();
	NodoN padre(NodoN);
	booleano foglia(NodoN);
	NodoN primofiglio(NodoN);
	booleano ultimofratello(NodoN);
	NodoN succfratello(NodoN);
	void insprimosottoalbero(NodoN, AlberoN &);
	void inssottoalbero(NodoN, AlberoN &);
	void cancsottoalbero(NodoN);

	//Metodi aggiunti con Tiponodo	
	tiponodon legginodo(NodoN);
	void scrivinodo(tiponodon, NodoN);
		
	//Metodi aggiunti per scrivere i nodi in modo più dinamico		
	void insradice(tiponodon);
	void insprimofiglio(tiponodon, NodoN);
	void inssuccfratello(tiponodon, NodoN);
};

#endif
