/*
 * serviziLista.cpp
 *
 *  Created on: 16/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <stdlib.h>
#include "listaPunt.h"
#include "serviziListaPunt.h"

using namespace std;

void acquisisciLista(Lista &lista) {
	posizione pos = lista.primoLista();
	tipoelem dato;

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

void stampaLista(Lista &lista) {
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

posizione cerca(Lista lista,int elem) {
	posizione pos = new NodoLista(); pos = NULL;
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

void svuotaLista(Lista &lista) {
	if (!lista.listaVuota()) {
		while(!lista.listaVuota())
			lista.cancLista(lista.primoLista());
	} else
		cout << "La lista era gia' vuota" << endl;
}

Lista sdoppia(Lista &lista) {
	Lista temp;
	posizione pos1,pos2;
	tipoelem elem;
	pos2 = temp.primoLista();
	pos1 = lista.primoLista();

	 while(!lista.fineLista(pos1)) {
		elem = lista.leggiLista(pos1);
		pos1 = lista.succLista(pos1);
		temp.insLista(elem,pos2);
	}
	return temp;
}

