/*
 * codaPunt.cpp
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <assert.h>
#include "codaPunt.h"

void Coda::creaCoda() {
	testa = NULL;
	fondo = NULL;
}

boolean Coda::codaVuota() {
	return (testa == NULL);
}

tipoelem Coda::leggiCoda() {
	assert(!codaVuota());
	return testa->dato;
}

void Coda::inCoda(tipoelem elem) {
	NodoCoda* nuovoNodo = new NodoCoda();
	nuovoNodo->dato = elem;
	nuovoNodo->successivo = NULL;

	if (codaVuota()) {
		testa = nuovoNodo;
		fondo = testa;
	}else{
		fondo->successivo = nuovoNodo;
		fondo = nuovoNodo;
	}
}

void Coda::fuoriCoda() {
	assert(!codaVuota());
	testa = testa->successivo;
}

Coda:: Coda() {
	creaCoda();
}

Coda::~Coda() {}
