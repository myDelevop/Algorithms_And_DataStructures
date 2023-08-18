/*
 * cellaGrafo.cpp
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#include "cellaGrafo.h"

tipoNodo cellaGrafo::getInfoNodo() {
	return infoNodo;
}

void cellaGrafo::setInfoNodo(tipoNodo info) {
	infoNodo = info;
}

boolean cellaGrafo::getVisitato() {
	return visitato;
}

void cellaGrafo::setVisitato(boolean vis) {
	visitato = vis;
}

cellaGrafo::cellaGrafo() {
	visitato = false;
}


