/*
 * NodoPrioriCoda.cpp
 *
 *  Created on: 30/gen/2015
 *      Author: rocco
 */

#include "NodoPrioriCoda.h"

void NodoPrioriCoda::setElemento(tipoelem elem) {
	elemento = elem;
}

void NodoPrioriCoda::setPriorita(int pr) {
	priorita = pr;
}

tipoelem NodoPrioriCoda::getElemento() {
	return elemento;
}

int NodoPrioriCoda::getPriorita() {
	return priorita;
}

NodoPrioriCoda::NodoPrioriCoda(){
	if (false)
		elemento = 0;
	priorita = -1;
}

NodoPrioriCoda::~NodoPrioriCoda(){}


