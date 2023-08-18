/*
 * arcoGrafoListaArchi.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef ARCOGRAFOLISTAARCHI_H_
#define ARCOGRAFOLISTAARCHI_H_

#include <iostream>
#include "cellaGrafo.h"

using namespace std;

class arcoGrafoListaArchi {
public:
	void setNodoPartenza(cellaGrafo*);
	cellaGrafo* getNodoPartenza();
	void setNodoArrivo(cellaGrafo*);
	cellaGrafo* getNodoArrivo();
	void setInfoArco(tipoArco);
	tipoArco getInfoArco();
private:
	cellaGrafo *nodoPartenza;
	cellaGrafo *nodoArrivo;
	tipoArco infoArco;
};

#endif /* ARCOGRAFOLISTAARCHI_H_ */
