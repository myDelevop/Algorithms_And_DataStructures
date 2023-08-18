/*
 * pilaPunt.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef PILAPUNT_H_
#define PILAPUNT_H_

#include "nodoPila.h"

class Pila {
public:
	void creaPila();
	boolean pilaVuota();
	tipoelem leggiPila();
	void inPila(tipoelem);
	void fuoriPila();
	 Pila();
	~Pila();

private:
	NodoPila* testa;
};



#endif /* PILAPUNT_H_ */
