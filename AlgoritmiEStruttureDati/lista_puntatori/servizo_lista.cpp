//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <cstdlib>
#include "lista.h"
#include "servizio_lista.h"

using namespace std;

void stampa_lista(Lista &L) {
	posizione p;
	cout<<"[";
	p=L.primolista();
	if (!L.listavuota()) {
		while(!L.finelista(p)) {
	    	cout<<L.leggilista(p);
	        p=L.succlista(p);
	        if (!L.finelista(p)) 
				cout <<", ";
	    }
	    cout<<"]";
	}
	else
	cout<<"la lista e' vuota]"<<"\n";
	cout<<"\n";
}

void inserisce_utente(Lista &l){
	char risp;
	posizione indiceElemento=l.primolista();
	
	while(!l.finelista(indiceElemento))
		indiceElemento = l.succlista(indiceElemento);
		
	cout<<"Vuoi inserire un nuovo elemento? S/N: ";
	cin>>risp;
	
	while(toupper(risp)== 'S') {
		inserisci_nodo(l, indiceElemento);
		cout<<"Vuoi inserire un nuovo elemento? S/N: ";
		cin>>risp;
		indiceElemento=l.succlista(indiceElemento);
	}
}

void inserisci_nodo(Lista &l, posizione p){
		tipoelem elem;
		cout<<"Elemento: ";
		cin>>elem;
		l.inslista(elem,p);
}

void epurazione (Lista &l){
posizione p;
posizione q;

	p=l.primolista();
	while (!l.finelista(p)){
		q=l.succlista(p);
	   while (!l.finelista(q)){
      	if (l.leggilista(p)==l.leggilista(q)){
         	l.canclista(q);
         }else{
         	q=l.succlista(q);
         }
	   }
      p=l.succlista(p);
	}
}

