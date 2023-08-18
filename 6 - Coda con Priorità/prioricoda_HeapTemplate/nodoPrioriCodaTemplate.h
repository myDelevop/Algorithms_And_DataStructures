/*
 * nodoPrioriCodaTemplate.h
 *
 *  Created on: 30/gen/2015
 *      Author: rocco
 */

#ifndef NODOPRIORICODATEMPLATE_H_
#define NODOPRIORICODATEMPLATE_H_

#include <iostream>
#include <cstdlib>

using namespace std;

template <class tipoelem>
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

template <class T>
void NodoPrioriCoda<T>::setElemento(T elem) {
	elemento = elem;
}

template <class T>
void NodoPrioriCoda<T>::setPriorita(int pr) {
	priorita = pr;
}

template <class T>
T NodoPrioriCoda<T>::getElemento() {
	return elemento;
}

template <class T>
int NodoPrioriCoda<T>::getPriorita() {
	return priorita;
}

template <class T>
NodoPrioriCoda<T>::NodoPrioriCoda(){
	if (false)
		elemento = 0;
	priorita = -1;
}

template <class T>
NodoPrioriCoda<T>::~NodoPrioriCoda(){}


#endif /* NODOPRIORICODATEMPLATE_H_ */
