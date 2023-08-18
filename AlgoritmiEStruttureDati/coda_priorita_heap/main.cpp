//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "prioricoda.h"

using namespace std;

int main(int argc, char *argv[])
{


	prioricoda * p;
	p = new prioricoda;
	prioricoda P;
	P = *p;
	tipoelem t;

	cout<<"Inserimento della lettera A con priorità 9";
	t = new elem;t->priori = 9;t->elem = 'A';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	cout<<"Inserimento della lettera C con priorità 4";
	t = new elem;t->priori = 4;t->elem = 'C';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	cout<<"Inserimento della lettera S con priorità 7";
	t = new elem;t->priori = 7;t->elem = 'S';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	cout<<"Inserimento della lettera T con priorità 5";
	t = new elem;t->priori = 5;t->elem = 'T';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	cout<<"Inserimento della lettera G con priorità 2";
	t = new elem;t->priori = 2;t->elem = 'G';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	cout<<"Inserimento della lettera L con priorità 3";
	t = new elem;t->priori = 3;t->elem = 'L';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	cout<<"Inserimento della lettera F con priorità 8";
	t = new elem;t->priori = 8;t->elem = 'F';
	P.inserisci(t);
	cout<<"\n";
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;
	P.cancellamin();
	cout<<"Minimo eliminato"<<endl;
	t = P.min();
	cout<<"Minimo attuale\tPriorità: "<<t->priori<<"\tEtichetta: "<<t->elem<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
