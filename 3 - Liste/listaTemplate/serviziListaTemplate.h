/*
 * serviziListaTemplate.h
 *
 *  Created on: 19/dic/2014
 *      Author: rocco
 */

#ifndef SERVIZILISTATEMPLATE_H_
#define SERVIZILISTATEMPLATE_H_

#include <iostream>
#include <stdlib.h>
#include "listaTemplate.h"

using namespace std;

template <class T, class posizione>
void acquisisciLista(Lista<T,posizione> &lista) {
	posizione pos = lista.primoLista();
	T dato;

	lista.creaLista();
	dato = 1;
	lista.insLista(dato,pos);
	dato = 2;
	lista.insLista(dato,pos);
	dato = 3;
	lista.insLista(dato,pos);
	dato = 4;
	lista.insLista(dato,pos);
	dato = 5;
	lista.insLista(dato,pos);
}

template <class T, class posizione>
void stampaLista(Lista<T,posizione> &lista) {
	posizione p = lista.primoLista();
	if(!lista.listaVuota()){
        while(!lista.fineLista(p)){
            cout << lista.leggiLista(p) << "   ";
            p = lista.succLista(p);
        }
    }else
        cout << "la lista e' vuota" << endl;
	cout <<endl<<endl;
}

template <class T,class posizione>
posizione cerca(Lista<T,posizione> &lista, T elem) {
	posizione pos = new NodoLista<T>; pos = NULL;
	boolean trovato = false;
	int i = 0;
	pos = lista.primoLista();
	if (!lista.listaVuota()) {
		while (!lista.fineLista(pos) && !trovato) {
			i++;
			if (lista.leggiLista(pos) == elem)
				trovato = true;
			else
				pos = lista.succLista(pos);
		}
	}
	cout << endl << "L'elemento ";
	if (trovato)
		cout << "e' ";
	else
		cout << "non e' ";
	cout << "presente nella lista" << endl;
	return pos;
}

template <class T,class posizione>
void svuotaLista(Lista<T,posizione> &lista) {
	if (!lista.listaVuota()) {
		while(!lista.listaVuota())
			lista.cancLista(lista.primoLista());
	} else
		cout << "La lista era gia' vuota." << endl;
}

template <class T,class posizione>
Lista<T,posizione> sdoppia(Lista<T,posizione> &lista) {
	Lista<T,posizione> temp;
	posizione pos1,pos2;
	T elem;
	pos2 = temp.primoLista();
	pos1 = lista.primoLista();

	 while(!lista.fineLista(pos1)) {
		elem = lista.leggiLista(pos1);
		pos1 = lista.succLista(pos1);
		temp.insLista(elem,pos2);
	}
	return temp;
}

#endif /* SERVIZILISTATEMPLATE_H_ */
