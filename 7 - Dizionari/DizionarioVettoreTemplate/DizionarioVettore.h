/*
 * DizionarioVett.h
 *
 *  Created on: 01/feb/2015
 *      Author: rocco
 */

#ifndef DIZIONARIOVETT_H_
#define DIZIONARIOVETT_H_

#include <iostream>
#include "datoDizionario.h"
#include "Dizionario.h"

using namespace std;

#define MAX_LENGTH 100

template <class elemento,class chiave>
class DizionarioVettore: public Dizionario<elemento,chiave> {
public:
	void inserisci(elemento,chiave);
	void cancella(chiave);
	elemento cerca(chiave);
	DizionarioVettore();
private:
	Dato<elemento> elementi[MAX_LENGTH];
	int dimensione;
};

template <class elemento,class chiave>
void DizionarioVettore<elemento,chiave>::inserisci(elemento elem,chiave k) {
	int i;
	bool trovato = false;
	for (i = 0; i < dimensione; i++) {
		if (k == elementi[i].getChiave())
			trovato = true;
	}
	if (!trovato && dimensione < MAX_LENGTH) {
		elementi[dimensione].setChiave(k);
		elementi[dimensione].setElemento(elem);
		dimensione++;
	}
}

template <class elemento,class chiave>
void DizionarioVettore<elemento,chiave>::cancella(chiave k) {
	int i;
	bool trovato = false;

	for (i = 0; i < dimensione; i++) {
		if (k == elementi[i].getChiave())
			trovato = true;
		if (trovato) {
			elementi[i].setChiave(elementi[i+1].getChiave());
			elementi[i].setElemento(elementi[i+1].getElemento());
		}
	}
}

template <class elemento,class chiave>
elemento DizionarioVettore<elemento,chiave>::cerca(chiave k) {
	elemento risposta;
	int i;
	bool trovato = false;
	for (i = 0; (i < dimensione) && (!trovato); i++) {
		if (k == elementi[i].getChiave())
			risposta = elementi[i].getElemento();
	}
	return risposta;
}


template <class elemento,class chiave>
DizionarioVettore<elemento,chiave>::DizionarioVettore() {
	dimensione = 0;
}

#endif /* DIZIONARIOVETT_H_ */
