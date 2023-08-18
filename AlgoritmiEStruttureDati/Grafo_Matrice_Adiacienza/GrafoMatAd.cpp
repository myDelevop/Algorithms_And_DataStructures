//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <cstdlib>
#include "GrafoMatAd.h"
#include "lista.h"

using namespace std;

void 
GrafoMatAd::creagrafo(){
    for(int i=0; i<MAX; i++){
            mark[i]=visita[i]=false;
    }        
	for(int i=0; i<MAX; i++)
	        for(int j=0; j<MAX; j++)
	                matrice[i][j]=INFINITO;
   
}

boolean 
GrafoMatAd::grafovuoto(){
       int i;         
       boolean vuoto=true;         
       for(i=0; i<MAX; i++){
            if(mark[i]!=false)
                vuoto = false;
       }
       return vuoto;
}

void 
GrafoMatAd::insnodo(nodo n, tiponodo t){
	if(mark[n] == 1)
		cout<<"Errore nodo esistente!!!";
	else{
        mark[n] = 1;
        label[n] = t;
	}
}

void 
GrafoMatAd::insarco(nodo n, nodo m, tipoarco ta){
//Verifica che sia possibile inserire l'arco e conseguente inserimento
        if( mark[n] == false || mark[m] == false) 
            cout<<"Errore un nodo inserito e' inesitente!!!"<<endl;
        else if(matrice[n][m] != INFINITO)
        	cout<<"Errore Arco già esistente!!!"<<endl;
        else
            matrice[n][m] = ta;                   
}

void 
GrafoMatAd::cancnodo(nodo n){
        mark[n] = false ; 
        int i;
        //Cancellazione tutti gli archi entranti e uscenti dal nodo eliminato
        for(i=0; i<MAX; i++){
            matrice[n][i] = INFINITO;     
        }
        for(i=0; i<MAX; i++){
            matrice[i][n] = INFINITO;     
        }            
}

void 
GrafoMatAd::cancarco(nodo n, nodo m){
        matrice[n][m] = INFINITO;                        
}

boolean 
GrafoMatAd::esistenodo(nodo n){
        return mark[n]==true;                     
}

boolean 
GrafoMatAd::esistearco(nodo n, nodo m){
         return matrice[n][m]!=INFINITO;                         
}

Lista 
GrafoMatAd::adiacenti(nodo n){
         Lista * l;
         l = new Lista;
         int i;
         posizione p;
         p = l->primolista();
         for(i=0; i<MAX; i++){
              if(matrice[n][i]!=INFINITO){
                     l->inslista(i,p);
                     p = l->succlista(p);         
              }
         }     
         return *l;                              
}

//costruttore e distruttore
GrafoMatAd::GrafoMatAd(){
        creagrafo();       
}

GrafoMatAd::~GrafoMatAd(){
}


void 
GrafoMatAd::scrivinodo(nodo n, tiponodo tn){

	if( mark[n] == false )
	    cout<<"Errore il nodo inserito e' inesitente!!!"<<endl;
	else
	   label[n] = tn;  
}

void 
GrafoMatAd::scriviarco(nodo n, nodo m, tipoarco ta){
        if( mark[n] == false || mark[m] == false || matrice[n][m] == INFINITO) 
            cout<<"Errore l'arco inserito e' inesitente!!!"<<endl;
        else
            matrice[n][m] = ta;  
}

tiponodo 
GrafoMatAd::legginodo(nodo n){

	if( mark[n] == false ){
	    cout<<"Errore il nodo inserito e' inesitente!!!"<<endl;
		return 0;
	}else
	   return label[n];  
}

tipoarco 
GrafoMatAd::leggiarco(nodo n, nodo m){
    tipoarco ta;
    
    if( mark[n] == false || mark[m] == false || matrice[n][m] == INFINITO){
        cout<<"Errore l'arco inserito e' inesitente!!!"<<endl;
        ta = INFINITO;
    }else
        ta = matrice[n][m]; 
    
    return ta;
}

bool 
GrafoMatAd::getVisitato(nodo n){
	return visita[n];
}

void 
GrafoMatAd::setVisitato(bool b, nodo n){
	visita[n] = b;
}

void 
GrafoMatAd::azzeraVisita(){
	for(int i=0; i<MAX; i++){
		visita[i]=false;
    } 
}

void 
GrafoMatAd::stampa(){
                     
    //Cerchiamo l'ultimo nodo utile
    int ultimo = 0;
    for(int i=0;i<=MAX;i++){
        if (mark[i]==true)
             ultimo=i;               
    }     
    
    cout<<"Lista Nodi:"<<endl;
    for(int i=0;i<=ultimo;i++){
      if (mark[i]==true){                  
          cout<<"Nodo: "<<i<<" \tEtichetta: "<<label[i]<<endl;
      }   
    }
    cout<<"\nLista Archi:"<<endl;    
    for(int i=0; i<MAX; i++)
            for(int j=0; j<MAX; j++)
                    if(matrice[i][j]!=INFINITO)
                            cout<<"Arco: "<<i<<"->"<<j<<"\tPeso: "<<matrice[i][j]<<endl;    
}
