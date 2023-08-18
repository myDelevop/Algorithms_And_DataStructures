/*
 * arcoGrafoListaArchi.cpp
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#include "arcoGrafoListaArchi.h"

void arcoGrafoListaArchi::setNodoPartenza(cellaGrafo* u) {
	nodoPartenza = u;
}

cellaGrafo* arcoGrafoListaArchi::getNodoPartenza() {
	return nodoPartenza;
}

void arcoGrafoListaArchi::setNodoArrivo(cellaGrafo* u) {
	nodoArrivo = u;
}

cellaGrafo* arcoGrafoListaArchi::getNodoArrivo() {
	return nodoArrivo;
}

void arcoGrafoListaArchi::setInfoArco(tipoArco info) {
	infoArco = info;
}

tipoArco arcoGrafoListaArchi::getInfoArco() {
	return infoArco;
}
