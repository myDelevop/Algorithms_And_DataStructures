/*
 * pilaTemplate.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef PILATEMPLATE_H_
#define PILATEMPLATE_H_

#include <assert.h>
#include "nodoPilaTemplate.h"

typedef bool boolean;

template <class tipoelem>
class Pila {
public:
	void creaPila();
	boolean pilaVuota();
	tipoelem leggiPila();
	void fuoriPila();
	void inPila(tipoelem);
	 Pila();
	~Pila();

private:
	NodoPila<tipoelem>* testa;
};


template<class tipoelem>
void Pila<tipoelem>::creaPila() {
	testa = NULL;
}

template<class tipoelem>
boolean Pila<tipoelem>::pilaVuota() {
	return (testa == NULL);
}

template <class tipoelem>
tipoelem Pila<tipoelem>::leggiPila() {
	assert(!pilaVuota());
	return testa->getElemento();
}

template <class tipoelem>
void Pila<tipoelem>::fuoriPila() {
	assert(!pilaVuota());
	NodoPila<tipoelem>* temp = testa;
	testa = testa->getSuccessivo();
	delete temp;
}

template <class tipoelem>
void Pila<tipoelem>::inPila(tipoelem elem) {
	NodoPila<tipoelem>* nuovoNodo = new NodoPila<tipoelem>;
	nuovoNodo->setElemento(elem);
	nuovoNodo->setSuccessivo(testa);
	testa = nuovoNodo;
}

template <class tipoelem>
Pila<tipoelem>::Pila() {
	creaPila();
}

template <class tipoelem>
Pila<tipoelem>::~Pila(){}


#endif /* PILATEMPLATE_H_ */
