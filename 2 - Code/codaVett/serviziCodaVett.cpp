/*
 * servizi.cpp
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <stdlib.h>
#include "serviziCodaVett.h"

using namespace std;

void acquisisciCoda(Coda &coda) {
	tipoelem i ;
	coda.creaCoda();
	for (i='a'; i<'f'; i++)
		coda.inCoda(i);
}

void stampaCoda(Coda &coda) {
	Coda temp;
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

void svuotaCoda(Coda &coda){
	while (!coda.codaVuota())
		coda.fuoriCoda();
}

boolean appartiene(tipoelem elem,Coda &coda) {
	tipoelem x;
	boolean trovato = false;
	Coda temp;

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

void elimina(Coda &coda) {
	Coda aux;
	tipoelem info,temp;
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
