/*
 * grafoListaArchi.cpp
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */


#include "grafoListaArchi.h"

using namespace std;

void GrafoListaArchi::creaGrafo() {
	listaNodi.creaLista();
	listaArchi.creaLista();
}

boolean GrafoListaArchi::grafoVuoto() {
	boolean out;
	if (listaNodi.listaVuota())
		out = true;
	else
		out = false;
	return out;
}

void GrafoListaArchi::insNodo(nodoGrafo* u,tipoNodo dato) {
	NodoLista<nodoGrafo*>* pos;
	pos = listaNodi.primoLista();
	u->setInfoNodo(dato);
	listaNodi.insLista(u,pos);
}

void GrafoListaArchi::insArco(nodoGrafo* nodoA,nodoGrafo* nodoB,
		arcoGrafo* arco,tipoArco datoArco) {
	if (esisteNodo(nodoA) && esisteNodo(nodoB)) {
		arco->setInfoArco(datoArco);
		arco->setNodoPartenza(nodoA);
		arco->setNodoArrivo(nodoB);
		NodoLista<arcoGrafo*>* pos = listaArchi.primoLista();
		listaArchi.insLista(arco,pos);
	}
}

void GrafoListaArchi::cancNodo(nodoGrafo* nodoRead) {
	if (esisteNodo(nodoRead)) {
		boolean check = false;
		NodoLista<nodoGrafo*>* posNodo = listaNodi.primoLista();
		while (posNodo != NULL && check != true) {
			if (posNodo->dato == nodoRead) {
				listaNodi.cancLista(posNodo);
				check = true;
			} else
				posNodo = listaNodi.succLista(posNodo);
		}
		arcoGrafo* arco;
		NodoLista<arcoGrafo*>* pos;
		NodoLista<arcoGrafo*>* temp;
		pos = listaArchi.primoLista();
		while (pos != NULL) {
			arco = pos->dato;
			if (arco->getNodoArrivo() == nodoRead
					|| arco->getNodoPartenza() == nodoRead) {
				cout << "trovato arco x" << arco->getInfoArco() << endl;
				temp = listaArchi.succLista(pos);
				listaArchi.cancLista(pos);
				pos = listaArchi.primoLista();
			} else
				pos = listaArchi.succLista(pos);
		}
	}
}

void GrafoListaArchi::cancArco(nodoGrafo* nodoA,nodoGrafo* nodoB) {
	boolean check = false;
	arcoGrafo* arco;
	NodoLista<arcoGrafo*>* pos = listaArchi.primoLista();
	while (pos != NULL && check != true) {
		arco = pos->dato;
		if (arco->getNodoPartenza() == nodoA
				&& arco->getNodoArrivo() == nodoB) {
			check = true;
			listaArchi.cancLista(pos);
		} else
			pos = listaArchi.succLista(pos);
	}
}

Lista<cellaGrafo*,NodoLista<cellaGrafo*>*> GrafoListaArchi::
		adiacenti(nodoGrafo* nodo) {
	Lista<cellaGrafo*,NodoLista<cellaGrafo*>*> listaOut;
	listaOut.creaLista();
	if (esisteNodo(nodo)) {
		arcoGrafo* arco;
		NodoLista<arcoGrafo*>* pos;
		NodoLista<nodoGrafo*>* pos_ins;
		pos = listaArchi.primoLista();
		while (pos != NULL) {
			arco = pos->dato;
			if (arco->getNodoPartenza() == nodo) {
				pos_ins = listaOut.primoLista();
				listaOut.insLista(arco->getNodoArrivo(), pos_ins);
			}
			pos = listaArchi.succLista(pos);
		}
	}
	return listaOut;
}

boolean GrafoListaArchi::esisteNodo(nodoGrafo* nodo) {
	boolean check = false;
	NodoLista<nodoGrafo*>* pos = listaNodi.primoLista();
	while (pos != NULL && check != true) {
		if (pos->dato == nodo)
			check = true;
		else
			pos = listaNodi.succLista(pos);
	}
	return check;
}

boolean GrafoListaArchi::esisteArco(nodoGrafo* nodoA,
		nodoGrafo* nodoB) {
	boolean check = false;
	arcoGrafo* arco;
	NodoLista<arcoGrafo*>* pos = listaArchi.primoLista();
	while (pos != NULL && check != true) {
		arco = pos->dato;
		if (arco->getNodoPartenza() == nodoA
				&& arco->getNodoArrivo() == nodoB)
			check = true;
		else {
			check = false;
			pos = listaArchi.succLista(pos);
		}
	}
	return check;
}

void GrafoListaArchi::azzeraVisita() {
	NodoLista<nodoGrafo*>* pos;
	nodoGrafo* nodo;
	if (!listaNodi.listaVuota()) {
		pos = listaNodi.primoLista();
		while (!listaNodi.fineLista(pos)) {
			nodo = listaNodi.leggiLista(pos);
			nodo->setVisitato(false);
			pos = listaNodi.succLista(pos);
		}
	}
}

GrafoListaArchi::GrafoListaArchi() {}
