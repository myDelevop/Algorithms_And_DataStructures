//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "GrafoMatAd.h"
#include "servizigrafo.h"

using namespace std;

int main(int argc, char *argv[])
{
    
    GrafoMatAd * g, G;
    g = new GrafoMatAd;
    G = * g;

	cout<<"Inserimento del nodo 1 con etichetta A"<<endl;	
	G.insnodo(1,"A");
	cout<<"Inserimento del nodo 2 con etichetta B"<<endl;
	G.insnodo(2,"B");
	cout<<"Inserimento del nodo 3 con etichetta C"<<endl;
	G.insnodo(3,"C");
	cout<<"Inserimento del nodo 4 con etichetta D"<<endl;
	G.insnodo(4,"D");
	cout<<"Inserimento del nodo 5 con etichetta E"<<endl;
	G.insnodo(5,"E");
	cout<<"Inserimento del nodo 6 con etichetta F"<<endl;
	G.insnodo(6,"F");
	cout<<"Inserimento del nodo 7 con etichetta G"<<endl;
	G.insnodo(7,"G");
	cout<<"Inserimento del nodo 8 con etichetta H"<<endl;
	G.insnodo(8,"H");
	
	cout<<"Inserimento dell'arco 1->2"<<endl;
	G.insarco(1,2,1);
	cout<<"Inserimento dell'arco 1->3"<<endl;
	G.insarco(1,3,1);
	cout<<"Inserimento dell'arco 2->6"<<endl;
	G.insarco(2,6,1);
	cout<<"Inserimento dell'arco 2->4"<<endl;
	G.insarco(2,4,1);
	cout<<"Inserimento dell'arco 4->3"<<endl;
	G.insarco(4,3,1);
	cout<<"Inserimento dell'arco 3->8"<<endl;
	G.insarco(3,8,1);
	cout<<"Inserimento dell'arco 3->5"<<endl;
	G.insarco(3,5,1);
	cout<<"Inserimento dell'arco 5->4"<<endl;
	G.insarco(5,4,1);
	cout<<"Inserimento dell'arco 5->7"<<endl;
	G.insarco(5,7,1);
	cout<<"Inserimento dell'arco 6->7"<<endl;
	G.insarco(6,7,1);	

	cout<<"Visita in Profondita' (DFS = DEPTH-FIRST-SEARCH): Partenza nodo 1"<<endl;
	visitaDFS(1,G);
	cout<<"Visita in Ampiezza (BFS = BREADTH-FIRST-SEARCH): Partenza nodo 1"<<endl;
	visitaBFS(1,G);
	
	cout<<"Eliminiamo il nodo 6 con relativa cancellazione degli archi"<<endl;
	G.cancnodo(6);
	cout<<"Eliminiamo l'arco 2->4"<<endl;
	G.cancarco(2,4);
	cout<<"Modifichiamo l'etichetta del nodo 8 in Z"<<endl;
	G.scrivinodo(8,"Z");
	
	G.stampa();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
