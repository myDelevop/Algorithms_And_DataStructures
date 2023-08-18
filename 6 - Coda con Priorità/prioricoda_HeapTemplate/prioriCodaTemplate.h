/*
 * prioriCoda.h
 *
 *  Created on: 30/gen/2015
 *      Author: rocco
 */

#ifndef PRIORICODATEMPLATE_H_
#define PRIORICODATEMPLATE_H_

#include "nodoPrioriCodaTemplate.h"

#define MAX_LENGTH 10
typedef bool boolean;

template <class tipoelem>
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
	NodoPrioriCoda<tipoelem>* heap[MAX_LENGTH];
	int numeroNodi;
};

template <class T>
void PrioriCoda<T>::inserisci(T elem, int pr) {
	int i = numeroNodi;
	int j = ((numeroNodi + 1) / 2) - 1;
	NodoPrioriCoda<T> * temp = new NodoPrioriCoda<T>();

	if (numeroNodi != MAX_LENGTH) {
		heap[i]->setElemento(elem);
		heap[i]->setPriorita(pr);
		if (i > 0)
			while (heap[i]->getPriorita() < heap[j]->getPriorita()) {
				temp = heap[j];
				heap[j] = heap[i];
                heap[i] = temp;
                i = j;
                j = i / 2;
			}
		numeroNodi++;
	} else cout << "Coda piena!" << endl;
}

template <class T>
T PrioriCoda<T>::min() {
	NodoPrioriCoda<T>* temp = new NodoPrioriCoda<T>();
	if(!prioriCodaVuota())
		return heap[0]->getElemento();
	else
		cout << "Coda Vuota!" << endl;
	return temp->getElemento();
}

template <class T>
void PrioriCoda<T>::cancellaMin() {
	NodoPrioriCoda<T>* temp = new NodoPrioriCoda<T>();
	if(!prioriCodaVuota()) {
		int i = 0, j;
		temp = heap[0];
		heap[0] = heap[numeroNodi - 1];
        heap[numeroNodi - 1] = NULL;
        numeroNodi--;
        delete temp;
        j = (i + 1) * 2;
        if (j <= numeroNodi)
        	while (j <= numeroNodi
        			&& heap[i]->getPriorita() > heap[j - 1]->getPriorita()) {
        		temp = heap[i];
        		heap[i] = heap[j-1];
        		heap[j-1] = temp;
        		i = j-1;
        		j = (i + 1) * 2;
        	}
	} else cout << "Coda vuota!" << endl;
}

template <class T>
boolean PrioriCoda<T>::prioriCodaVuota() {
	return (numeroNodi == 0);
}

template <class T>
int PrioriCoda<T>::getNumeroNodi() {
	return numeroNodi;
}

template <class T>
T PrioriCoda<T>::leggiElemNodo(int i) {
	NodoPrioriCoda<T>* temp = new NodoPrioriCoda<T>();
	if (!prioriCodaVuota())
		if (i <= numeroNodi)
			if (heap[i]->getPriorita() != -1)
				return heap[i]->getElemento();
			else
				cout << "Nodo Insesistente" << endl;
		else
			cout << "Superata la massima lunghezza" << endl;
	else
		cout << "PrioriCoda Vuota" << endl;
	return temp->getElemento();
}

template <class T>
int PrioriCoda<T>::leggiPrioriNodo(int i) {
	if (!prioriCodaVuota())
		if (i <= numeroNodi)
			if (heap[i]->getPriorita() != -1)
				return heap[i]->getPriorita();
			else
				cout << "nodo inesistente" << endl;
		else
			cout << "superate la lunghezza massima" << endl;
	else
		cout <<"PrioriCoda Vuota" << endl;
	return -1;
}

template <class T>
PrioriCoda<T>::PrioriCoda() {
	int i;
	for (i = 0; i <= MAX_LENGTH; i++)
		heap[i] = new NodoPrioriCoda();
	numeroNodi = 0;
}

template <class T>
PrioriCoda<T>::~PrioriCoda() {}

#endif /* PRIORICODATEMPLATE_H_ */
