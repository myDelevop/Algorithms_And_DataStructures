/*
 * serviziPilaTemplate.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef SERVIZIPILATEMPLATE_H_
#define SERVIZIPILATEMPLATE_H_

#include <stdlib.h>
#include "pilaTemplate.h"

template <class T>
void acquisisciPila(Pila<T> &);

template <class T>
void stampaPila(Pila<T>);

template <class T>
void svuotaPila(Pila<T> &);


template <class T>
void acquisisciPila(Pila<T> &pila) {

	T dato;
	pila.creaPila();
	for (dato='a';dato<'f';dato++)
		pila.inPila(dato);
}


template <class T>
void stampaPila(Pila<T> pila) {

	Pila<T> temp;
	if (pila.pilaVuota())
		cout << "La pila e' Vuota.";
	else {
		while(!pila.pilaVuota()) {
			temp.inPila(pila.leggiPila());
			pila.fuoriPila();
		}
		while (!temp.pilaVuota()) {
			cout << temp.leggiPila() << "  ";
			pila.inPila(temp.leggiPila());
			temp.fuoriPila();
		}
	}
	cout<<endl<<endl;
	system("pause");
	system("CLS");
}


template <class T>
void svuotaPila(Pila<T> &pila) {

	while(!pila.pilaVuota())
		pila.fuoriPila();
}

template <class T>
boolean appartiene(T elem,Pila<T> &pila) {
	T x;
	boolean trovato = false;
	Pila<T> temp;
	if (!pila.pilaVuota()) {
		while (!pila.pilaVuota()) {
			x = pila.leggiPila();
			pila.fuoriPila();
			temp.inPila(x);
			if (x==elem)
				trovato = true;
		}
	}
	while (!temp.pilaVuota()) {
		pila.inPila(temp.leggiPila());
		temp.fuoriPila();
	}
	return trovato;
}

template <class T>
void elimina(Pila<T> &pila) {
	Pila<T> aux;
	T info,temp;
	boolean trovato = false;

	cout << "Inserisci elemento da cancellare nella pila" << endl;
	cin>>info;

	while (!pila.pilaVuota()) {
		temp = pila.leggiPila();
		pila.fuoriPila();
		if (temp == info)
			trovato = true;
		else
			aux.inPila(temp);
	}
	while (!aux.pilaVuota()) {
		temp = aux.leggiPila();
		pila.inPila(temp);
		aux.fuoriPila();
	}
	if (trovato==false)
		cout << "elemento inserito non presente nella pila" << endl;
	else
		cout << "elemento cancellato con successo." << endl;
}

#endif /* SERVIZIPILATEMPLATE_H_ */
