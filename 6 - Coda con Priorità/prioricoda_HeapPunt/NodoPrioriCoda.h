/*
 * NodoPrioriCoda.h
 *
 *  Created on: 30/gen/2015
 *      Author: rocco
 */

#ifndef NODOPRIORICODA_H_
#define NODOPRIORICODA_H_

#include <iostream>
#include <cstdlib>

using namespace std;

typedef char tipoelem;

class NodoPrioriCoda {
public:
	void setElemento(tipoelem);
	void setPriorita(int);
	tipoelem getElemento();
	int getPriorita();

	NodoPrioriCoda();
    ~NodoPrioriCoda();
private:
    tipoelem elemento;
	int priorita;
};


#endif /* NODOPRIORICODA_H_ */
