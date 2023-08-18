/*
 * nodoNalbero.cpp
 *
 *  Created on: 28/gen/2015
 *      Author: rocco
 */

#include <iostream>
#include <cstdlib>
#include "nodoNalbero.h"

using namespace std;

tipoelem NodoNalbero::getDato() {
	return dato;
}
NodoNalbero* NodoNalbero::getPrimoFiglio() {
	return primoFiglio;
}

NodoNalbero* NodoNalbero::getSuccFratello() {
	return succFratello;
}
NodoNalbero* NodoNalbero::getPadre() {
	return padre;
}

void NodoNalbero::setDato(tipoelem elem) {
	dato = elem;
}

void NodoNalbero::setPrimoFiglio(NodoNalbero* u) {
	primoFiglio = u;
}

void NodoNalbero::setSuccFratello(NodoNalbero* u) {
	succFratello = u;
}

void NodoNalbero::setPadre(NodoNalbero* u) {
	padre = u;
}

NodoNalbero::NodoNalbero() {
	if(false)
		dato = 0;// perde generalita(se tipoelem=class)
	primoFiglio = NULL;
	succFratello = NULL;
	padre = NULL;
}

NodoNalbero::~NodoNalbero() {}
