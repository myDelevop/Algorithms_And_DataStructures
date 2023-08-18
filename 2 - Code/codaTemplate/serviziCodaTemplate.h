/*
 * serviziCodaTemplate.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef SERVIZICODATEMPLATE_H_
#define SERVIZICODATEMPLATE_H_

#include <iostream>
#include <stdlib.h>
#include "codaTemplate.h"


template <class T>
void acquisisciCoda(Coda<T> &coda) {
	T i ;
	coda.creaCoda();
	for (i='a'; i<'f'; i++)
		coda.inCoda(i);

}


template <class T>
void stampaCoda(Coda<T> &coda) {

	Coda<T> temp;

	if (coda.codaVuota()) {
		cout<<"La coda e' Vuota.";
	} else {

		while(!coda.codaVuota()) {
	 		temp.inCoda(coda.leggiCoda());
			coda.fuoriCoda();
		}
		
		while(!temp.codaVuota()) {
			cout << temp.leggiCoda() << "   ";
			coda.inCoda(temp.leggiCoda());
			temp.fuoriCoda();
		}
	}
	cout<<endl<<endl;

	system("pause");
	system("cls");
}



template <class T>
void svuotaCoda(Coda<T> &coda) {
	while (!coda.codaVuota())
		coda.fuoriCoda();
}

template <class T>
boolean appartiene(T elem,Coda<T> &coda) {
	T x;
	boolean trovato = false;
	Coda<T> temp;

	if (!coda.codaVuota()) {
		while (!coda.codaVuota()) {
			x = coda.leggiCoda();
			coda.fuoriCoda();
			temp.inCoda(x);
			if (x==elem)
				trovato = true;
		}
	}
	while (!temp.codaVuota()) {
		coda.inCoda(temp.leggiCoda());
		temp.fuoriCoda();
	}
	return trovato;
}

template <class T>
void elimina(Coda<T> &coda) {
	Coda<T> aux;
	T info,temp;
	boolean trovato = false;

	cout << "Inserisci elemento da cancellare nella coda" << endl;
	cin>>info;

	while (!coda.codaVuota()) {
		temp = coda.leggiCoda();
		coda.fuoriCoda();
		if (temp == info)
			trovato = true;
		else
			aux.inCoda(temp);
	}
	while (!aux.codaVuota()) {
		temp = aux.leggiCoda();
		coda.inCoda(temp);
		aux.fuoriCoda();
	}
	if (trovato==false)
		cout << "elemento inserito non presente nella coda" << endl;
	else
		cout << "elemento cancellato con successo." << endl;
}

#endif /* SERVIZICODATEMPLATE_H_ */
