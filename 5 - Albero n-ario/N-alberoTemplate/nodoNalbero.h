/*
 * nodoNalbero.h
 *
 *  Created on: 29/gen/2015
 *      Author: rocco
 */

#ifndef NODONALBERO_H_
#define NODONALBERO_H_

#include <cstdlib>
#include <iostream>

using namespace std;

typedef bool boolean;

template <class tipoelem>
class NodoNalbero {
public:
	tipoelem getDato();
	NodoNalbero* getPrimoFiglio();
	NodoNalbero* getSuccFratello();
	NodoNalbero* getPadre();
	void setDato(tipoelem);
	void setPrimoFiglio(NodoNalbero*);
	void setSuccFratello(NodoNalbero*);
	void setPadre(NodoNalbero*);
	NodoNalbero();
	~NodoNalbero();
private:
	tipoelem dato;
	NodoNalbero<tipoelem> *primoFiglio;
	NodoNalbero<tipoelem> *succFratello;
	NodoNalbero<tipoelem> *padre;
};

template <class T>
T NodoNalbero<T>::getDato() {
	return dato;
}

template <class T>
NodoNalbero<T>* NodoNalbero<T>::getPrimoFiglio() {
	return primoFiglio;
}

template <class T>
NodoNalbero<T>* NodoNalbero<T>::getSuccFratello() {
	return succFratello;
}

template <class T>
NodoNalbero<T>* NodoNalbero<T>::getPadre() {
	return padre;
}

template <class T>
void NodoNalbero<T>::setDato(T elem) {
	dato = elem;
}

template <class T>
void NodoNalbero<T>::setPrimoFiglio(NodoNalbero *u) {
	primoFiglio = u;
}

template <class T>
void NodoNalbero<T>::setSuccFratello(NodoNalbero* u) {
	succFratello = u;
}

template <class T>
void NodoNalbero<T>::setPadre(NodoNalbero* u) {
	padre = u;
}

template <class T>
NodoNalbero<T>::NodoNalbero() {
	if (false)
		dato = 0;//perde generalità non può essere settato
	primoFiglio = NULL;
	succFratello = NULL;
	padre = NULL;
}

template <class T>
NodoNalbero<T>::~NodoNalbero() {}

#endif /* NODONALBERO_H_ */
