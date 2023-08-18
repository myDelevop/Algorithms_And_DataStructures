/*
 * serviziPila.cpp
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <stdlib.h>
#include "serviziPilaVett.h"

using namespace std;

void acquisisciPila(Pila &pila)  {
	pila.creaPila();
	tipoelem i = 'a';
	pila.inPila(i);
	i = 'b';
	pila.inPila(i);
	i = 'c';
	pila.inPila(i);
	i = 'd';
	pila.inPila(i);
	i = 'e';
	pila.inPila(i);

}


void stampaPila(Pila pila) {
	Pila temp;
	if (pila.pilaVuota()) {
		cout << "La pila e' vuota. ";
	}else {

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

void svuotaPila(Pila &pila) {
	while (!pila.pilaVuota())
		pila.fuoriPila();
}


boolean appartiene(tipoelem elem,Pila &pila) {
	tipoelem x;
	boolean trovato = false;
	Pila temp;

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

void elimina(Pila &pila) {
	Pila aux;
	tipoelem info,temp;
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
