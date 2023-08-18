//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <cstdlib>
#include "alberon.h"
#include "serviziAlberiNari.h"

using namespace std;

//Funzioni di visita

void previsita(NodoN n,AlberoN & T){
	
	if (!T.alberovuoto()){
		while (n != NULL){
			esaminaNodo(n, T);
			previsita(T.primofiglio(n), T);
			n = T.succfratello(n);
		}
	} 

}

void postvisita(NodoN n,AlberoN &T){
	if (!T.alberovuoto()){
		while (n != NULL){
			postvisita(T.primofiglio(n), T);
			esaminaNodo(n, T);
			n = T.succfratello(n);
		}
	}
}

void invisita(NodoN n, AlberoN &T){
	if(!T.alberovuoto()){
		if (!T.foglia(n)){
			invisita(T.primofiglio(n), T);
			esaminaNodo(n, T);
			n = T.primofiglio(n);
			while (!T.ultimofratello(n)){
				n = T.succfratello(n);
				invisita(n, T);
			}
		}else 
			esaminaNodo(n, T);
	}
}


//Funzioni di Supporto
void esaminaNodo(NodoN n, AlberoN &T){
	cout<<T.legginodo(n)<<", ";	
}

int confrontaTipo(tiponodon a, tiponodon b){
//Funzione che prende 2 tiponodon e li confronta
//restituendo -1 se a<b, 0 se a=b, 1 se a>b	
	int conf;
	
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	
	return conf;	
}

//Funzioni Ausiliarie
void insNaviga(AlberoN &T){
	
	tiponodon e;
	NodoN u;
	int scelta=0;
	
	if(T.alberovuoto()){
		cout<<"Inserisci Radice: ";
		cin>>e;
		T.insradice(e);
		cout<<endl;
	}
	
	u = T.radice();
	
	while(scelta<6){
		cout<<"Cosa vuoi fare?"<<endl;
		cout<<"1) Vai al Primo Figlio"<<endl;		
		cout<<"2) Vai al SuccFratello"<<endl;
		cout<<"3) Vai al Padre"<<endl;
		cout<<"4) Inserisci Primo Figlio"<<endl;
		cout<<"5) Inserisci SuccFratello"<<endl;
		cout<<"6) Esci dall'inserimento"<<endl;
		cin>>scelta;
				
		switch(scelta){
			case 1: 
				if(T.foglia(u)){
					cout<<"Impossibile accedere al Primo Figlio perche' e' foglia\n"<<endl;
				}else{
	    			u = T.primofiglio(u);
	    			cout<<"Primo Figlio: "<<T.legginodo(u)<<endl<<endl;
				}					
				break;
			case 2:
				if(T.ultimofratello(u)){
					cout<<"Impossibile accedere al SuccFratello perche' vuoto\n"<<endl;
				}else{
	    			u = T.succfratello(u);
	    			cout<<"SuccFratello: "<<T.legginodo(u)<<endl<<endl;
				}
				break;
			case 3:
				if(T.radice()==u){
					cout<<"Impossibile accedere al padre perche' sei alla Radice\n"<<endl;
				}else{
	    			u = T.padre(u);
	    			cout<<"Padre: "<<T.legginodo(u)<<endl<<endl;
				}
				break;
			case 4:
				cout<<"Inserisci il Tiponodo: ";
    			cin>>e;
    			T.insprimofiglio(e,u);
    			cout<<endl;
				break;
			case 5:
				cout<<"Inserisci il TipoNodo: ";
    			cin>>e;
    			cout<<endl;
    			T.inssuccfratello(e,u);
				break;
			default:
				scelta = 6;
		}
    }	
}

NodoN ricercaNodo(tiponodon t, NodoN n, AlberoN &T){
	
	NodoN NCercato = NULL;
	
	if (!T.alberovuoto()){
		while (n != NULL && NCercato == NULL){
			if(confrontaTipo(t, T.legginodo(n)) == 0)
				NCercato = n;
			else
				NCercato = ricercaNodo(t,T.primofiglio(n),T);
				
			n = T.succfratello(n);
		}
	}	
	return NCercato;	
}

int profonditaNodo(NodoN n, AlberoN &T){
	
	if (T.radice() == n) return 0;

	return 1 + profonditaNodo(T.padre(n), T);	
}

int contanodi(NodoN n, AlberoN &T){

	int conto = 0;
	if (!T.alberovuoto()){
		while (n != NULL){
			conto = contanodi(T.primofiglio(n), T) + 1 + conto;
			n = T.succfratello(n);
		}
	} 	
	
	return conto;
}
