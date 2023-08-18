/*
 * NodoPila.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef NODOPILATEMPLATE_H_
#define NODOPILA_H_

#include <iostream>
#include <cstdlib>

using namespace std;

template <class tipoelem>
class NodoPila {
public:
	 void setElemento(tipoelem elemento);
	 tipoelem getElemento();
	 void setSuccessivo(NodoPila<tipoelem>*);
	 NodoPila<tipoelem>* getSuccessivo();
	 NodoPila();
	~NodoPila();

private:
	tipoelem dato;
	NodoPila<tipoelem>* successivo;
};


template <class tipoelem>
void NodoPila<tipoelem>::setElemento(tipoelem elem) {
	this->dato = elem;
}


template <class tipoelem>
tipoelem NodoPila<tipoelem>::getElemento() {
	return dato;
}


template <class tipoelem>
void NodoPila<tipoelem>::setSuccessivo(NodoPila<tipoelem>* next) {
	this->successivo = next;
}


template <class tipoelem>
NodoPila<tipoelem>* NodoPila<tipoelem>::getSuccessivo() {
	return successivo;
}


template <class tipoelem>
NodoPila<tipoelem>::NodoPila() {
	successivo = NULL;
}

template <class tipoelem>
NodoPila<tipoelem>::~NodoPila() {}


#endif /* NODOPILA_H_ */
