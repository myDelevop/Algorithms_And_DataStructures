#include <stdlib.h>
#include <iostream>
#include "hashAperto.h"
#include "lista.h"

using namespace std;

void 
DizAperto::crea(){
    int i;
    for(i=0;i<MAX;i++){
        diz[i] = new Lista;
    }
}


DizAperto::DizAperto(){
    crea();
}

DizAperto::~DizAperto(){
}

//funzione calcolo hash
int 
DizAperto :: hash(tipoelem k)
{
	return k%MAX;
}

boolean 
DizAperto::appartiene(tipoelem a){
    int i;
    posizione j;
    i = hash(a);
    boolean trovato = false;
    
    if(!diz[i]->listavuota()){
        j = diz[i]->primolista();              
        do{
               if(diz[i]->leggilista(j) == a){
                       trovato = true;
               }   
               j++;  
        }while(!diz[i]->finelista(j) && !trovato);              
    }                   
    
    return trovato;
}

void 
DizAperto::inserisci(tipoelem a){
    int i;
    i = hash(a);
    
    if (!appartiene(a)){
    	posizione p = diz[i]->primolista();
           diz[i]->inslista(a,p);
    }
    cout<<"inserito"<<a<<endl;
}

void 
DizAperto::stampatutto(){
         posizione j;
         int i = 0 ;
         for(i=0;i<MAX;i++){ 
                 if(!diz[i]->listavuota()){
                        j = diz[i]->primolista();
                        cout<<"Valori in posizione "<<i<<" : ";              
                        do{
                               cout<<diz[i]->leggilista(j)<<" ";
                               j++;   
                        }while(!diz[i]->finelista(j));
                        cout<<endl;              
                 }                    
         }               
}


void 
DizAperto::cancella(tipoelem a){
    int i;
    posizione j;
    i = hash(a);
    boolean trovato = false;
    
    if (appartiene(a)){
        j = diz[i]->primolista();              
        do{
               if(diz[i]->leggilista(j) == a){
                       trovato = true;   
                       diz[i]->canclista(j);
               }     
               j++;
        }while(!diz[i]->finelista(j) && !trovato);
    }
    
    stampatutto();
}
