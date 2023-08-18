//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef ALBEROBIN_H
#define ALBEROBIN_H

#include "nodo.h"

typedef bool booleano;

class AlberoBin {
	
    Nodo radice;

public:

	//Costruttore e Distruttore
	AlberoBin();
	~AlberoBin();
	
	//Metodi Base	
	booleano binalberovuoto();
	Nodo binradice();
	Nodo binpadre(Nodo);
	Nodo figliosx(Nodo);
	Nodo figliodx(Nodo);
	booleano sxvuoto(Nodo);
	booleano dxvuoto(Nodo);
	// void costrbinalbero(AlberoBin); Non implementato
	void cancsottobinalbero(Nodo);

	//Metodi aggiunti con Tiponodo		
	tiponodo legginodo(Nodo);
	void scrivinodo(tiponodo, Nodo);
	void insbinradice(tiponodo);
	void insfigliosx(tiponodo, Nodo);
	void insfigliodx(tiponodo, Nodo);
};

#endif
