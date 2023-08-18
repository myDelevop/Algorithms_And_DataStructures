/*
 * nodoLista.h
 *
 *  Created on: 16/dic/2014
 *      Author: Rocco
 */

#ifndef NODOLISTA_H_
#define NODOLISTA_H_

typedef int tipoelem;
typedef class NodoLista* posizione;

class NodoLista {
public:
	tipoelem dato;
	NodoLista* prec;
	NodoLista* succ;
};

#endif /* NODOLISTA_H_ */
