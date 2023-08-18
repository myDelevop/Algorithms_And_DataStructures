/*
 * pilaVett.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef PILAVETT_H_
#define PILAVETT_H_

#define MAX_LENGTH 200

typedef int tipoelem;
typedef bool boolean;


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
	tipoelem elementi[MAX_LENGTH];
	int testa;
};


#endif /* PILAVETT_H_ */
