/*
 * listaPunt.h
 *
 *  Created on: 16/dic/2014
 *      Author: Rocco
 */

#ifndef LISTAPUNT_H_
#define LISTAPUNT_H_

#include "nodoLista.h"

typedef bool boolean;

class Lista {
public:
	void creaLista();
	boolean listaVuota();
	tipoelem leggiLista(posizione);
	void scriviLista(tipoelem,posizione);
	posizione primoLista();
	boolean fineLista(posizione);
	posizione succLista(posizione);
	posizione precLista(posizione);
	void insLista(tipoelem,posizione);
	void cancLista(posizione);
	 Lista();
	~Lista();

private:
	NodoLista *testa;
};

#endif /* LISTAPUNT_H_ */
