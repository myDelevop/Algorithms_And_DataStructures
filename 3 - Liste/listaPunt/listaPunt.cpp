/*
 * listaPunt.cpp
 *
 *  Created on: 16/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <assert.h>
#include "listaPunt.h"

using namespace std;

void Lista::creaLista() {
	testa = NULL;
}

boolean Lista::listaVuota() {
	return (testa == NULL);
}

tipoelem Lista::leggiLista(posizione pos) {
	assert(!listaVuota());
	return pos->dato;
}

void Lista::scriviLista(tipoelem elem,posizione pos) {
	assert(!listaVuota());
	pos->dato = elem;
}

posizione Lista::primoLista() {
	return testa;
}

boolean Lista::fineLista(posizione pos) {
	return (pos == NULL);
}

posizione Lista::succLista(posizione pos) {
	assert (pos != NULL);
	return (pos->succ);
}

posizione Lista::precLista(posizione pos) {
	assert (pos != NULL);
	return (pos->prec);
}


void Lista::insLista(tipoelem a,posizione p) {

    NodoLista * nuovo = new NodoLista();
    nuovo->dato = a;
    if (p != NULL){
        nuovo->prec = p->prec;
        nuovo->succ = p;
        p->prec = nuovo;
        if(primoLista() == p){
            testa = nuovo; //p è testa
        }else{
            p->prec->succ = nuovo;
        }
    }else{
        if(listaVuota()){
            nuovo->prec = NULL;
            testa = nuovo;
        }else{
            //trovo ultimo elemento della lista
            p = primoLista();
            while ((p->succ != NULL) && !fineLista(p)) p = succLista(p);
            p->succ = nuovo;
            nuovo->prec = p;
        }
        nuovo->succ = NULL; //è ultimo della lista quindi succ è sempre NULL
    }
}

void Lista::cancLista(posizione p) {
    if (p != NULL){
        if (listaVuota()) {
        	cout << "Impossibile inserire elementi, la lista";
        	cout << "e' vuota" <<endl<<endl;
        }
        else if ((p->prec == NULL) && (p->succ == NULL))
        	testa = NULL;
        else if(p == testa) {
        	testa = p->succ;
        	testa->prec=0;
        } else if (p->succ == NULL) //cancellazione in coda
        	p->prec->succ = 0;
        else { //cancellazione posizione generica
        	p->succ->prec = p->prec;
        	(p->prec)->succ = p->succ;
        }
    } else cout <<"Posizione non corretta";
}

Lista::Lista() {
	creaLista();
}

Lista::~Lista() {}