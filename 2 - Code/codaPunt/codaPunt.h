/*
 * codaPunt.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef CODAPUNT_H_
#define CODAPUNT_H_

#include "nodoCoda.h"

class Coda {
public:
	void creaCoda();
	boolean codaVuota();
	tipoelem leggiCoda();
	void inCoda(tipoelem);
	void fuoriCoda();
	 Coda();
	~Coda();

private:
	NodoCoda* testa;
	NodoCoda* fondo;
};



#endif /* CODAPUNT_H_ */
