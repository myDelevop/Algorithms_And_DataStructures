/*
 * grafoListaArchi.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef GRAFOLISTAARCHI_H_
#define GRAFOLISTAARCHI_H_

#include <iostream>
#include "cellaGrafo.h"
#include "arcoGrafoListaArchi.h"
#include "listaTemplate.h"

class GrafoListaArchi {
public:
	typedef cellaGrafo nodoGrafo;
	typedef arcoGrafoListaArchi arcoGrafo;
	Lista <arcoGrafo*,NodoLista<arcoGrafo*>*> listaArchi;
	Lista <nodoGrafo*,NodoLista<nodoGrafo*>*> listaNodi;

	void creaGrafo();
	boolean grafoVuoto();
	void insNodo(nodoGrafo*,tipoNodo);
	void insArco(nodoGrafo*,nodoGrafo*,arcoGrafo*,tipoArco);
	void cancNodo(nodoGrafo*);
	void cancArco(nodoGrafo*,nodoGrafo*);
	Lista<cellaGrafo*,NodoLista<cellaGrafo*>*> adiacenti(nodoGrafo*);
	boolean esisteNodo(nodoGrafo*);
	boolean esisteArco(nodoGrafo*,nodoGrafo*);
	void azzeraVisita();
	GrafoListaArchi();
};

#endif /* GRAFOLISTAARCHI_H_ */
