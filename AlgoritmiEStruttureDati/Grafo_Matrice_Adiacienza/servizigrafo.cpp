//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <cstdlib>
#include "servizigrafo.h"
#include "lista.h"
#include "coda.h"

void esaminaNodo(nodo n, GrafoMatAd &G){
	cout<<"Nodo: "<<n<<"  Etichetta: "<<G.legginodo(n)<<endl;
}

void DFS(nodo n, GrafoMatAd &G){
	posizione p;
	nodo v;
	p = G.adiacenti(n).primolista();
	
	esaminaNodo(n,G);
	G.setVisitato(true,n);
	
	while(!G.adiacenti(n).finelista(p)){
		v = G.adiacenti(n).leggilista(p);
		if(!G.getVisitato(v))
			DFS(v,G);
		p = G.adiacenti(n).succlista(p);
	}	
}

void visitaDFS(nodo n, GrafoMatAd &G){
	G.azzeraVisita();
	cout<<"Visita in Profondita' (DFS = DEPTH-FIRST-SEARCH) :"<<endl;
	DFS(n,G);
}

void BFS(nodo n, GrafoMatAd &G){

	Coda C;
	nodo succ;

	C.in(n);
	G.setVisitato(true,n);
	esaminaNodo(n,G);
	while(!C.vuota()){
		n = C.leggi();
		C.fuori();
		posizione p = G.adiacenti(n).primolista();		
		while(!G.adiacenti(n).finelista(p)){
			succ = G.adiacenti(n).leggilista(p);
			if(G.esistearco(n,succ) && !G.getVisitato(succ)){
				esaminaNodo(succ,G);
				C.in(succ);
				G.setVisitato(true,succ);
    		}
 			p = G.adiacenti(n).succlista(p);
		}
	}
}

void visitaBFS(nodo n, GrafoMatAd &G){
	G.azzeraVisita();
	cout<<"Visita in Ampiezza (BFS = BREADTH-FIRST-SEARCH) :"<<endl;
	BFS(n,G);
}
