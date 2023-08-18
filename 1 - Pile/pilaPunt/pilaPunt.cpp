/*
 * pilaPunt.cpp
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <assert.h>
#include "pilaPunt.h"

void Pila::creaPila() {
	testa = NULL;
}

boolean Pila::pilaVuota() {
	return (testa == NULL);
}

tipoelem Pila::leggiPila() {
	assert(!pilaVuota());
	return testa->dato;
}

void Pila::inPila(tipoelem elem) {
	NodoPila* nuovoNodo = new NodoPila();
	nuovoNodo->dato = elem;
	nuovoNodo->successivo = testa;
	testa = nuovoNodo;
}

void Pila::fuoriPila() {
	assert(!pilaVuota());
	NodoPila* temp = testa;
	testa = testa->successivo;
	delete temp;
}
Pila::Pila() {
	creaPila();
}

Pila::~Pila() {}
