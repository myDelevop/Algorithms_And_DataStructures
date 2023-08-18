//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "serviziAlberiNari.h"
#include "alberon.h"

using namespace std;

int main(int argc, char *argv[])
{

	AlberoN * t;
	t = new AlberoN;
	AlberoN T;
	T = *t;
	NodoN u = 0;

	cout<<"Caricamento dell'albero Nario ..."<<endl;
	T.insradice(3);
	u = T.radice();
	T.insprimofiglio(8, u);
	T.insprimofiglio(6, u);
	T.insprimofiglio(4, u);
	u = T.primofiglio(u);
	T.insprimofiglio(2, u);
	u = T.succfratello(u);
	T.insprimofiglio(9, u);
	T.insprimofiglio(7, u);
	T.insprimofiglio(5, u);
	u = T.primofiglio(u);
	u = T.succfratello(u);
	T.insprimofiglio(1, u);
	u = T.padre(u);
	u = T.succfratello(u);
	T.insprimofiglio(12, u);
	T.insprimofiglio(11, u);
	u = T.primofiglio(u);
	T.insprimofiglio(13, u);
	T.insprimofiglio(15, u);
	u = T.primofiglio(u);
	T.insprimofiglio(14, u);
	cout<<"Previsita: [";
	previsita(T.radice(), T);
	cout<<"]\n";
	cout<<"Postvisita: [";
	postvisita(T.radice(), T);
	cout<<"]\n";
	cout<<"Invisita: [";
	invisita(T.radice(), T);
	cout<<"]\n";
	cout<<"Numero nodi dell'albero: "<<contanodi(T.radice(), T);
	cout<<"\nRicerca e memorizzazione del nodo 9";
	u = ricercaNodo(9, T.radice(), T);
	cout<<"\nProfondita del nodo memorizzato "<<T.legginodo(u)<<": "<<profonditaNodo(u,T);

    system("PAUSE");
    return 0;
}
