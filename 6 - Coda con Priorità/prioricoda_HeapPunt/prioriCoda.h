/*
 * prioriCoda.h
 *
 *  Created on: 30/gen/2015
 *      Author: rocco
 */

#ifndef PRIORICODA_H_
#define PRIORICODA_H_

#include "NodoPrioriCoda.h"

#define MAX_LENGTH 10
typedef bool boolean;

class PrioriCoda {
public:
    void inserisci(tipoelem, int);
    tipoelem min();
    void cancellaMin();
    boolean prioriCodaVuota();
    int getNumeroNodi();
    tipoelem leggiElemNodo(int);
    int leggiPrioriNodo(int);

    PrioriCoda();
	~PrioriCoda();
private:
	NodoPrioriCoda* heap[MAX_LENGTH];
	int numeroNodi;
};


#endif /* PRIORICODA_H_ */
