/*
 * nodoCodaTemplate.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef NODOCODATEMPLATE_H_
#define NODOCODATEMPLATE_H_

#include <iostream>

using namespace std;

template <class tipoelem>
class NodoCoda {
public:
	void setDato(tipoelem);
	tipoelem getDato(void);
	void setSucc(NodoCoda<tipoelem>*);
	NodoCoda<tipoelem>* getSucc();
	 NodoCoda();
	~NodoCoda();

private:
	tipoelem dato;
	NodoCoda<tipoelem>* succ;
};


template <class tipoelem>
void NodoCoda<tipoelem>::setDato(tipoelem elem) {
	this->dato = elem;
}

template <class tipoelem>
tipoelem NodoCoda<tipoelem>::getDato() {
	return dato;
}


template <class tipoelem>
void NodoCoda<tipoelem>::setSucc(NodoCoda<tipoelem>* elem) {
	this->succ = elem;
}

template <class tipoelem>
NodoCoda<tipoelem>* NodoCoda<tipoelem>::getSucc() {
	return succ;
}


template <class tipoelem>
NodoCoda<tipoelem>::NodoCoda() {
	succ = NULL;
}

template <class tipoelem>
NodoCoda<tipoelem>::~NodoCoda() {}


#endif /* NODOCODATEMPLATE_H_ */
