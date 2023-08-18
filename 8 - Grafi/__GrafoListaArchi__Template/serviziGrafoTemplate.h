/*
 * servizi.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef SERVIZIGRAFOTEMPLATE_H_
#define SERVIZIGRAFOTEMPLATE_H_

#include "grafoListaArchi.h"
#include "codaTemplate.h"

template <class tipoNodo,class tipoArco>
void acquisisciGrafo(GrafoListaArchi<tipoNodo,tipoArco> &G) { //supponendo int tipoNodo string tipoArco
	G.creaGrafo();
	cellaGrafo<tipoNodo>* nodo1 = new cellaGrafo<tipoNodo>();
	G.insNodo(nodo1, 3);
	cellaGrafo<tipoNodo>* nodo2 = new cellaGrafo<tipoNodo>();
	G.insNodo(nodo2, 4);
	cellaGrafo<tipoNodo>* nodo3 = new cellaGrafo<tipoNodo>();
	G.insNodo(nodo3, 1);
	cellaGrafo<tipoNodo>* nodo4 = new cellaGrafo<tipoNodo>();
	G.insNodo(nodo4, 2);
	cellaGrafo<tipoNodo>* nodo5 = new cellaGrafo<tipoNodo>();
	G.insNodo(nodo5, 7);

	arcoGrafoListaArchi<tipoArco,tipoNodo> *arco1 = new arcoGrafoListaArchi<tipoArco,tipoNodo>();
	G.insArco(nodo1,nodo2,arco1,"colleg1");
	arcoGrafoListaArchi<tipoArco,tipoNodo> *arco2 = new arcoGrafoListaArchi<tipoArco,tipoNodo>();
	G.insArco(nodo2,nodo3,arco2,"colleg2");
	arcoGrafoListaArchi<tipoArco,tipoNodo> *arco3 = new arcoGrafoListaArchi<tipoArco,tipoNodo>();
	G.insArco(nodo2,nodo5,arco3,"colleg3");


	//ecc..
}

template <class tipoNodo,class tipoArco>
void stampaNodi(GrafoListaArchi<tipoNodo,tipoArco> &G) {
    cellaGrafo<tipoNodo>* posizione;
    NodoLista<cellaGrafo<tipoNodo>*>* pos = G.listaNodi.primoLista();
    NodoLista<cellaGrafo<tipoNodo>*>* pos_adi;
    Lista<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> Adiacenti;
    while (pos != NULL) {
    	Adiacenti.creaLista();
    	posizione = pos->dato;
    	Adiacenti = G.adiacenti(posizione);
    	cout << endl;
    	cout << "Nodo# " << pos->dato->getInfo() << " ";
    	pos_adi = Adiacenti.primoLista();
    	while (pos_adi != NULL) {
    		cout << "adiacenti# " << pos_adi->dato->getInfo() << " ";
                     pos_adi = Adiacenti.succLista(pos_adi);
    	}
    	cout << "   " << endl;
    	pos = G.listaNodi.succLista(pos);
    }
    cout << endl << endl;
}

template <class tipoNodo,class tipoArco>
void stampaArchi(GrafoListaArchi<tipoNodo,tipoArco> &G) {
    typedef arcoGrafoListaArchi<tipoArco,tipoNodo> arcoGrafo;
    NodoLista<arcoGrafo*>* pos = G.listaArchi.primoLista();
    while (pos != NULL) {
    	cout << "Arco#" << pos->dato->getInfoArco() << " "
    			<< pos->dato->getNodoPartenza()->getInfo() << "->"
                << pos->dato->getNodoArrivo()->getInfo() << endl;
    	pos = G.listaArchi.succLista(pos);
    }
    cout << endl << endl;

}


template <class tipoNodo,class tipoArco>
void esaminaNodo(cellaGrafo<tipoNodo>* u,GrafoListaArchi<tipoNodo,tipoArco>&G) {
	cout << u->getInfo() << "   ";
}

template <class tipoNodo,class tipoArco>
void DFS(cellaGrafo<tipoNodo>* n,GrafoListaArchi<tipoNodo,tipoArco> &G) {
	NodoLista<cellaGrafo<tipoNodo>*> *pos;
	cellaGrafo<tipoNodo> *v;
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

template <class tipoNodo,class tipoArco>
void visitaDFS(cellaGrafo<tipoNodo> *n, GrafoListaArchi<tipoNodo,tipoArco> &G) {
	G.azzeraVisita();
	if (!G.listaNodi.listaVuota()) {
	cout<<"Visita in Profondita' (DFS = DEPTH-FIRST-SEARCH) :" << endl << endl;
	DFS(n,G);
	} else
		cout << "il Grafo e vuoto" << endl;
	G.azzeraVisita();
}

template <class tipoNodo,class tipoArco>
void BFS(cellaGrafo<tipoNodo>* n,GrafoListaArchi<tipoNodo,tipoArco> &G) {

	Coda<cellaGrafo<tipoNodo>*> coda;
	cellaGrafo<tipoNodo>* succ;
	NodoLista<cellaGrafo<tipoNodo>*> *pos;

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

template <class tipoNodo,class tipoArco>
void visitaBFS(cellaGrafo<tipoNodo> *n, GrafoListaArchi<tipoNodo,tipoArco> &G) {
	G.azzeraVisita();
	if (!G.listaNodi.listaVuota()) {
		cout<<"Visita in Ampiezza (BFS = BREADTH-FIRST-SEARCH) :"<<endl;
		BFS(n,G);
	} else
		cout << "Non ci Sono nodi " << endl;
	G.azzeraVisita();
}

template <class tipoNodo,class tipoArco>
boolean grafoConnesso(GrafoListaArchi<tipoNodo,tipoArco> &G) {
	cellaGrafo<tipoNodo>* u;
	NodoLista<cellaGrafo<tipoNodo>*> *pos;
	boolean connesso = true;
	if (!G.listaNodi.listaVuota()) {
		pos = G.listaNodi.primoLista();
		BFS(G.listaNodi.leggiLista(pos),G);
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



#endif /* SERVIZI_H_ */
