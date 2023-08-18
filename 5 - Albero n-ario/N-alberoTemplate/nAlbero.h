/*
 * nAlbero.h
 *
 *  Created on: 29/gen/2015
 *      Author: rocco
 */

#ifndef NALBERO_H_
#define NALBERO_H_

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "nodoNalbero.h"

using namespace std;

typedef bool boolean;

template <class T>
class nAlbero {
public:
	void creaNalbero();
	boolean nAlberoVuoto();
	void insRadice(T);
	NodoNalbero<T>* radice();
	NodoNalbero<T>* padre(NodoNalbero<T>*);
	boolean foglia(NodoNalbero<T>*);
	NodoNalbero<T>* primoFiglio(NodoNalbero<T>*);
	boolean ultimoFratello(NodoNalbero<T>*);
	NodoNalbero<T>* succFratello(NodoNalbero<T>*);
	void insPrimoFiglio(T, NodoNalbero<T>*);
	void insFratelloSucc(T, NodoNalbero<T>*);
	void cancSottoNalbero(NodoNalbero<T>*);
	T leggiNodo(NodoNalbero<T>*);
	void scriviNodo(T, NodoNalbero<T>*);

	nAlbero();
	~nAlbero();
private:
	NodoNalbero<T>* albero;
};


template <class T>
void nAlbero<T>::creaNalbero() {
	albero = NULL;
}

template <class T>
boolean nAlbero<T>::nAlberoVuoto() {
	return (albero == NULL);
}

template <class T>
void nAlbero<T>::insRadice(T elem) {
	albero = new NodoNalbero<T>;
	scriviNodo(elem,albero);
	albero->setPrimoFiglio(NULL);
	albero->setSuccFratello(NULL);
	albero->setPadre(NULL);
}

template <class T>
NodoNalbero<T>* nAlbero<T>::radice() {
	return albero;
}

template <class T>
NodoNalbero<T>* nAlbero<T>::padre(NodoNalbero<T>* u) {
	assert(!nAlberoVuoto() && u != albero);
	return u->getPadre();
}

template <class T>
boolean nAlbero<T>::foglia(NodoNalbero<T>*u) {
	assert(!nAlberoVuoto());
	return (u->getPrimoFiglio() == NULL);
}

template <class T>
NodoNalbero<T>* nAlbero<T>::primoFiglio(NodoNalbero<T>* u) {
	assert(!nAlberoVuoto() && !foglia(u));
	return u->getPrimoFiglio();
}

template <class T>
boolean nAlbero<T>::ultimoFratello(NodoNalbero<T>* u) {
	assert(!nAlberoVuoto());
	return (u->getSuccFratello()==NULL);
}

template <class T>
NodoNalbero<T>* nAlbero<T>::succFratello(NodoNalbero<T>* u) {
	assert(!nAlberoVuoto() && !ultimoFratello(u));
	return u->getSuccFratello();
}

template <class T>
void nAlbero<T>::insPrimoFiglio(T elem, NodoNalbero<T>* u) {
	assert(!nAlberoVuoto() && foglia(u));
    if (!nAlberoVuoto() && foglia(u)) {
        NodoNalbero<T>* nuovo = new NodoNalbero<T>();
        scriviNodo(elem, nuovo);
        u->setPrimoFiglio(nuovo);
        nuovo->setPadre(u);
        nuovo->setPrimoFiglio(NULL);
        nuovo->setSuccFratello(NULL);
    }
}

template <class T>
void nAlbero<T>::insFratelloSucc(T elem, NodoNalbero<T>* u) {
	assert(!nAlberoVuoto() && ultimoFratello(u) && u!=albero);
    if (!nAlberoVuoto() && ultimoFratello(u) && u != albero) {
        NodoNalbero<T> *nuovo = new NodoNalbero<T>();
        scriviNodo(elem, nuovo);
        u->setSuccFratello(nuovo);
        nuovo->setPadre(u->getPadre());
        nuovo->setSuccFratello(NULL);
        nuovo->setPrimoFiglio(NULL);
    }
}

template <class T>
void nAlbero<T>::cancSottoNalbero(NodoNalbero<T>* n) {
	NodoNalbero<T> *temp;
	if(n != albero) {
        if ( (n->getPadre())->getPrimoFiglio() ==  n )
        	(n->getPadre())->setPrimoFiglio(n->getSuccFratello());
		else {
            temp = (n->getPadre())->getPrimoFiglio();
            while(temp->getSuccFratello() != n)
            	temp = temp->getSuccFratello();
            temp->setSuccFratello(n->getSuccFratello());
		}
    } else {
    	NodoNalbero<T>* u;
    	u = primoFiglio(albero);
    	while(!ultimoFratello(u)) {
    		cancSottoNalbero(u);
    		u = succFratello(u);
    	}
    	albero = NULL;
    	cout << "L'albero e' stato completamente rimosso ";
    	cout << "poichè il nodo inserito era la radice" << endl;
    }
    if(n->getPrimoFiglio() != NULL ){
        temp = n->getPrimoFiglio();
        if(temp->getSuccFratello() != NULL)
        	cancSottoNalbero(temp->getSuccFratello());
        cancSottoNalbero(temp);
    }
    delete n;
}

template <class T>
T nAlbero<T>::leggiNodo(NodoNalbero<T>* u) {
	return u->getDato();
}

template <class T>
void nAlbero<T>::scriviNodo(T elem, NodoNalbero<T>* u) {
	u->setDato(elem);
}

template <class T>
nAlbero<T>::nAlbero() {
	creaNalbero();
}

template <class T>
nAlbero<T>::~nAlbero() {}

#endif /* NALBERO_H_ */
