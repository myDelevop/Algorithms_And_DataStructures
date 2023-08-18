/*
 * nAlbero.cpp
 *
 *  Created on: 28/gen/2015
 *      Author: rocco
 */

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "nAlbero.h"

using namespace std;

void nAlbero::creaNalbero() {
	albero = NULL;
}

boolean nAlbero::nAlberoVuoto() {
	return (albero == NULL);
}

void nAlbero::insRadice(tipoelem elem) {
	albero = new NodoNalbero;
	scriviNodo(elem,albero);
	albero->setPrimoFiglio(NULL);
	albero->setSuccFratello(NULL);
	albero->setPadre(NULL);
}

NodoNalbero* nAlbero::radice() {
	return albero;
}

NodoNalbero* nAlbero::padre(NodoNalbero* u) {
	assert(!nAlberoVuoto() && u != albero);
	return u->getPadre();
}

boolean nAlbero::foglia(NodoNalbero*u) {
	assert(!nAlberoVuoto());
	return (u->getPrimoFiglio() == NULL);
}

NodoNalbero* nAlbero::primoFiglio(NodoNalbero* u) {
	assert(!nAlberoVuoto() && !foglia(u));
	return u->getPrimoFiglio();
}

boolean nAlbero::ultimoFratello(NodoNalbero* u) {
	assert(!nAlberoVuoto());
	return (u->getSuccFratello()==NULL);
}

NodoNalbero* nAlbero::succFratello(NodoNalbero* u) {
	assert(!nAlberoVuoto() && !ultimoFratello(u));
	return u->getSuccFratello();
}

void nAlbero::insPrimoFiglio(tipoelem elem, NodoNalbero* u) {
	assert(!nAlberoVuoto() && foglia(u));
    if (!nAlberoVuoto() && foglia(u)) {
        NodoNalbero* nuovo = new NodoNalbero();
        scriviNodo(elem, nuovo);
        u->setPrimoFiglio(nuovo);
        nuovo->setPadre(u);
        nuovo->setPrimoFiglio(NULL);
        nuovo->setSuccFratello(NULL);
    }
}

void nAlbero::insFratelloSucc(tipoelem elem, NodoNalbero* u) {
	assert(!nAlberoVuoto() && ultimoFratello(u) && u!=albero);
    if (!nAlberoVuoto() && ultimoFratello(u) && u != albero) {
        NodoNalbero *nuovo = new NodoNalbero();
        scriviNodo(elem, nuovo);
        u->setSuccFratello(nuovo);
        nuovo->setPadre(u->getPadre());
        nuovo->setSuccFratello(NULL);
        nuovo->setPrimoFiglio(NULL);
    }
}

void nAlbero::cancSottoNalbero(NodoNalbero* n) {
	NodoNalbero *temp;
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
    	NodoNalbero* u;
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

tipoelem nAlbero::leggiNodo(NodoNalbero* u) {
	return u->getDato();
}

void nAlbero::scriviNodo(tipoelem elem, NodoNalbero* u) {
	u->setDato(elem);
}

nAlbero::nAlbero() {
	creaNalbero();
}

nAlbero::~nAlbero() {}
