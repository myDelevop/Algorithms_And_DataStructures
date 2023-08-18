/*
 * codaTemplate.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef CODATEMPLATE_H_
#define CODATEMPLATE_H_

#include "nodoCodaTemplate.h"
#include <assert.h>

typedef bool boolean;


template <class tipoelem>
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
	NodoCoda<tipoelem>* testa;
	NodoCoda<tipoelem>* fondo;
};

template <class tipoelem>
void Coda<tipoelem>::creaCoda(){
	testa = NULL;
	fondo = NULL;
}

template <class tipoelem>
boolean Coda<tipoelem>::codaVuota() {
	return (testa == NULL);
}

template <class tipoelem>
tipoelem Coda<tipoelem>::leggiCoda() {
	assert(!codaVuota());
	return testa->getDato();
}

template <class tipoelem>
void Coda<tipoelem>::inCoda(tipoelem elem) {
	NodoCoda<tipoelem>* nuovoNodo = new NodoCoda<tipoelem>();
	nuovoNodo->setDato(elem);
	nuovoNodo->setSucc(NULL);

	if (codaVuota()) {
		testa = nuovoNodo;
		fondo = testa;
	}else{
		fondo->setSucc(nuovoNodo);
		fondo = nuovoNodo;
	}
}

template <class tipoelem>
void Coda<tipoelem>::fuoriCoda() {
	assert(!codaVuota());
	NodoCoda<tipoelem>* temp = testa;
	testa = testa->getSucc();
	delete temp;
}

template <class tipoelem>
Coda<tipoelem>::Coda() {
	creaCoda();
}


template <class tipoelem>
Coda<tipoelem>::~Coda() {}
#endif /* CODATEMPLATE_H_ */
