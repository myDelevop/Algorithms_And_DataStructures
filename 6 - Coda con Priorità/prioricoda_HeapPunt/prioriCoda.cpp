/*
 * prioriCoda.cpp
 *
 *  Created on: 30/gen/2015
 *      Author: rocco
 */

#include "prioriCoda.h"

void PrioriCoda::inserisci(tipoelem elem, int pr) {
	int i = numeroNodi;
	int j = ((numeroNodi + 1) / 2) - 1;
	NodoPrioriCoda * temp = new NodoPrioriCoda();

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

tipoelem PrioriCoda::min() {
	NodoPrioriCoda* temp = new NodoPrioriCoda();
	if(!prioriCodaVuota())
		return heap[0]->getElemento();
	else
		cout << "Coda Vuota!" << endl;
	return temp->getElemento();
}

void PrioriCoda::cancellaMin() {
	NodoPrioriCoda* temp = new NodoPrioriCoda;

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

boolean PrioriCoda::prioriCodaVuota() {
	return (numeroNodi == 0);
}

int PrioriCoda::getNumeroNodi() {
	return numeroNodi;
}

tipoelem PrioriCoda::leggiElemNodo(int i) {
	NodoPrioriCoda* temp = new NodoPrioriCoda();
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

int PrioriCoda::leggiPrioriNodo(int i) {
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

PrioriCoda::PrioriCoda() {
	int i;
	for (i = 0; i <= MAX_LENGTH; i++)
		heap[i] = new NodoPrioriCoda();
	numeroNodi = 0;
}

PrioriCoda::~PrioriCoda() {}
