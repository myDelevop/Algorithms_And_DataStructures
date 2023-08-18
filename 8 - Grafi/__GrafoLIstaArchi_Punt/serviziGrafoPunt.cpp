/*
 * serviziGrafoPunt.cpp
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#include "serviziGrafoPunt.h"

using namespace std;

void acquisisciGrafo(GrafoListaArchi &G) { //supponendo int tipoNodo string tipoArco
	G.creaGrafo();
	cellaGrafo* nodo1 = new cellaGrafo();
	G.insNodo(nodo1, 3);
	cellaGrafo* nodo2 = new cellaGrafo();
	G.insNodo(nodo2, 4);
	cellaGrafo* nodo3 = new cellaGrafo();
	G.insNodo(nodo3, 1);
	cellaGrafo* nodo4 = new cellaGrafo();
	G.insNodo(nodo4, 2);
	cellaGrafo* nodo5 = new cellaGrafo();
	G.insNodo(nodo5, 7);

	arcoGrafoListaArchi *arco1 = new arcoGrafoListaArchi();
	G.insArco(nodo1,nodo2,arco1,"colleg1");
	arcoGrafoListaArchi *arco2 = new arcoGrafoListaArchi();
	G.insArco(nodo2,nodo3,arco2,"colleg2");
	arcoGrafoListaArchi *arco3 = new arcoGrafoListaArchi();
	G.insArco(nodo2,nodo5,arco3,"colleg3");


	//ecc..
}

void stampaNodi(GrafoListaArchi &G) {
    cellaGrafo* posizione;
    NodoLista<cellaGrafo*>* pos = G.listaNodi.primoLista();
    NodoLista<cellaGrafo*>* pos_adi;
    Lista<cellaGrafo*, NodoLista<cellaGrafo*>*> Adiacenti;
    while (pos != NULL) {
    	Adiacenti.creaLista();
    	posizione = pos->dato;
    	Adiacenti = G.adiacenti(posizione);
    	cout << endl;
    	cout << "Nodo# " << pos->dato->getInfoNodo() << " ";
    	pos_adi = Adiacenti.primoLista();
    	while (pos_adi != NULL) {
    		cout << "adiacenti# " << pos_adi->dato->getInfoNodo() << " ";
                     pos_adi = Adiacenti.succLista(pos_adi);
    	}
    	cout << "   " << endl;
    	pos = G.listaNodi.succLista(pos);
    }
    cout << endl << endl;
}

void stampaArchi(GrafoListaArchi &G) {
    typedef arcoGrafoListaArchi arcoGrafo;
    NodoLista<arcoGrafo*>* pos = G.listaArchi.primoLista();
    while (pos != NULL) {
    	cout << "Arco#" << pos->dato->getInfoArco() << " "
                            << pos->dato->getNodoPartenza()->getInfoNodo() << "->"
                            << pos->dato->getNodoArrivo()->getInfoNodo() << endl;
    	pos = G.listaArchi.succLista(pos);
    }
    cout << endl << endl;

}

void esaminaNodo(cellaGrafo* u,GrafoListaArchi &G) {
	cout << u->getInfoNodo() << "   ";
}

void DFS(cellaGrafo* n,GrafoListaArchi &G) {
	NodoLista<cellaGrafo*> *pos;
	cellaGrafo *v;
	pos = G.adiacenti(n).primoLista();
	esaminaNodo(n,G);
	n->setVisitato(true);
	while (!G.adiacenti(n).fineLista(pos)) {
		v = G.adiacenti(n).leggiLista(pos);
		if (!v->getVisitato())
			DFS(v,G);
		pos = G.adiacenti(n).succLista(pos);
	}
}

void visitaDFS(cellaGrafo *n, GrafoListaArchi &G) {
	G.azzeraVisita();
	if (!G.listaNodi.listaVuota()) {
	cout<<"Visita in Profondita' (DFS = DEPTH-FIRST-SEARCH) :" << endl << endl;
	DFS(n,G);
	} else
		cout << "il Grafo e vuoto" << endl;
	G.azzeraVisita();
}

void BFS(cellaGrafo* n,GrafoListaArchi &G) {

	Coda<cellaGrafo*> coda;
	cellaGrafo* succ;
	NodoLista<cellaGrafo*> *pos;

	coda.inCoda(n);
	n->setVisitato(true);
	esaminaNodo(n,G);
	while (!coda.codaVuota()) {
		n = coda.leggiCoda();
		coda.fuoriCoda();
		pos = G.adiacenti(n).primoLista();
		while (!G.adiacenti(n).fineLista(pos)) {
			succ = G.adiacenti(n).leggiLista(pos);
			if (G.esisteArco(n,succ) && !succ->getVisitato()) {
				esaminaNodo(succ,G);
				coda.inCoda(succ);
				succ->setVisitato(true);
			}
			pos = G.adiacenti(n).succLista(pos);
		}
	}
}

void visitaBFS(cellaGrafo *n, GrafoListaArchi &G) {
	G.azzeraVisita();
	if (!G.listaNodi.listaVuota()) {
		cout<<"Visita in Ampiezza (BFS = BREADTH-FIRST-SEARCH) :"<<endl;
		BFS(n,G);
	} else
		cout << "Non ci Sono nodi " << endl;
	G.azzeraVisita();
}

boolean grafoConnesso(GrafoListaArchi &G) {
	cellaGrafo* u;
	NodoLista<cellaGrafo*> *pos;
	boolean connesso = true;

	if (!G.listaNodi.listaVuota()) {
		pos = G.listaNodi.primoLista();
		pos = G.listaNodi.succLista(pos);

		DFS(G.listaNodi.leggiLista(pos),G);
		while (!G.listaNodi.fineLista(pos)) {
			u = G.listaNodi.leggiLista(pos);
			if (!u->getVisitato())
				return false;
			pos = G.listaNodi.succLista(pos);
		}
	} else
		cout << "Non ci sono Nodi" << endl;
	return connesso;
}
