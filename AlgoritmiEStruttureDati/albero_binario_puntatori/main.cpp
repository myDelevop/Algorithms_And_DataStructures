//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>

#include "serviziAlberoBin.h"
#include "alberobin.h"

using namespace std;

int main(int argc, char *argv[])
{

	AlberoBin * t;
	t = new AlberoBin;
	AlberoBin T;
	T = *t;
	Nodo u = 0;


	cout<<"Inserimento Radice: 2"<<endl;
	T.insbinradice(2);
	u = T.binradice();
	cout<<"Inserimento dei figli di 2 (FiglioSx:3 FiglioDx:5)"<<endl;
	T.insfigliosx(3, u);
	T.insfigliodx(5, u);
	cout<<"Inserimento dei figli di 3 (FiglioSx:7 FiglioDx:8)"<<endl;
	u = T.figliosx(u);
	T.insfigliosx(7, u);
	T.insfigliodx(8, u);
	cout<<"Inserimento dei figli di 5 (FiglioSx:9)"<<endl;
	u = T.binradice();
	u = T.figliodx(u);
	T.insfigliosx(9, u);
	cout<<"Inserimento dei figli di 9 (FiglioSx:4 FiglioDx:20)"<<endl;
	u = T.figliosx(u);
	T.insfigliosx(4, u);
	T.insfigliodx(20, u);
	cout<<"Inserimento dei figli di 4 (FiglioDx:1)"<<endl;
	u = T.figliosx(u);
	T.insfigliodx(1, u);
	cout<<"Previsita: [";
	previsita(T.binradice(), T);
	cout<<"]\n\n";
	cout<<"Postvisita: [";
	postvisita(T.binradice(), T);
	cout<<"]\n\n";
	cout<<"Invisita: [";
	simmetrica(T.binradice(), T);
	cout<<"]\n\n";
	cout<<"Visita in Ampiezza: [";
	ampiezza(T);
	cout<<"]\n\n";
	cout<<"Altezza dell'albero: "<<altezzaNodo(T.binradice(), T);
	cout<<"\n\n";
	cout<<"Numero nodi dell'albero: "<<contanodi(T.binradice(), T);
	cout<<"\n\n";
	cout<<"\nRicerca del tiponodo 4 nell'albero e memorizzazzione";
	u = ricercaNodo(4, T.binradice(), T);
	cout<<"\n";
	cout<<"Profondita del nodo memorizzato "<<T.legginodo(u)<<": "<<profonditaNodo(u, T.binradice(), 0, T)<<endl<<endl;
	cout<<"Altezza del nodo memorizzato "<<T.legginodo(u)<<": "<<altezzaNodo(u, T)<<endl<<endl;
    system("PAUSE");
    return 0;
}
