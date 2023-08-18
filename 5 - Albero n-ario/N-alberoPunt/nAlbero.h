/*
 * nAlbero.h
 *
 *  Created on: 28/gen/2015
 *      Author: rocco
 */

#ifndef NALBERO_H_
#define NALBERO_H_

#include "nodoNalbero.h"

typedef bool boolean;

class nAlbero {
public:
	void creaNalbero();
	boolean nAlberoVuoto();
	void insRadice(tipoelem);
	NodoNalbero* radice();
	NodoNalbero* padre(NodoNalbero*);
	boolean foglia(NodoNalbero*);
	NodoNalbero* primoFiglio(NodoNalbero*);
	boolean ultimoFratello(NodoNalbero*);
	NodoNalbero* succFratello(NodoNalbero*);
	void insPrimoFiglio(tipoelem, NodoNalbero*);
	void insFratelloSucc(tipoelem, NodoNalbero*);
	void cancSottoNalbero(NodoNalbero*);
	tipoelem leggiNodo(NodoNalbero*);
	void scriviNodo(tipoelem, NodoNalbero*);

	nAlbero();
	~nAlbero();
private:
	NodoNalbero* albero;
};

#endif /* NALBERO_H_ */
