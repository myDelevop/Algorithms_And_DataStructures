//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <stdlib.h>
#include <iostream>
#include "hashChiuso.h"

using namespace std;

void Cella::setlabel(tipoelem etichetta){
    label=etichetta;
}

tipoelem Cella::getlabel(){
    return label;
}

DizChiuso::DizChiuso(){
    crea();
}

DizChiuso::~DizChiuso(){
}

void 
DizChiuso::crea(){
    int i;
    for(i=0;i<MAX;i++){
        diz[i]=(NULL);
        stato[i]=0;
    }
}



//funzione calcolo hash
int 
DizChiuso :: hash(tipoelem k)
{
	return k%MAX;
}



/***
Gestione collisione con scansione lineare  
j: cursore cella con elemento a (se esiste)
c cursore prima cella vuota incontrata nella scansione
stato[j]=0 cella libera
stato[j]=1 cella cancellata
*/
void 
DizChiuso::scan(tipoelem a,int &j,int &c){
    int i;
    boolean libero,trovato,esaurito;
    i=hash(a);// calcolo mediante funzione hash del punto inizio scansione
    j=c=i;
    libero=esaurito=trovato=false;//inizializzazione valori; 
    if (diz[j]!=NULL && diz[j]->getlabel()==0 && stato[j]==1){
       trovato==true;//ho trovato un elemento cancellato nella posizione della funzione hash
    }
    while ((!((libero)||(trovato)||(esaurito) ))){
        if (diz[j]!=NULL && diz[j]->getlabel()!=0){ 
/*getlabel restituisce il valore puntato dal puntatore se non si cancella con delete*/
            if(diz[j]->getlabel()==a) trovato=true;
            else{            
                j=(j+1) % MAX; // avanza nella scansione (se arriva alla fine riprende dall'inizio)
                if (i==j) esaurito=true;// se ho terminato la scansione
                }
        }else{
            c=j;
            libero=true;
        }
    }
}


boolean 
DizChiuso::appartiene(tipoelem a){
    int j,c;
    scan(a,j,c);
    if ((diz[j]!=NULL) && (diz[j]->getlabel()==a)) return true;
    return false;        
}

void 
DizChiuso::inserisci(tipoelem a){
    int j,c;
    scan(a,j,c);
    if (!appartiene(a)){
           if (diz[c]==NULL) diz[c]=new Cella;
           diz[c]->setlabel(a);
           stato[c]=0;
    }
    stampatutto();
}

void 
DizChiuso::stampatutto(){
    cout<<"dizionario["<<MAX<<"]: {";
    for(int p=0;p<MAX;p++){
            if (p>0)cout<<"|";
            if (diz[p]!=NULL) cout<<diz[p]->getlabel();
            else cout<<diz[p];
    }
    cout<<"}"<<endl;
    cout<<"     stato["<<MAX<<"]: {";
    for(int p=0;p<MAX;p++){
            if (p>0)cout<<"|";
            cout<<stato[p];
    }
    cout<<"}"<<endl;
}

void 
DizChiuso::cancella(tipoelem a){
    int j,c;
    scan(a,j,c);
    if (diz[j]!=NULL){
        if (diz[j]->getlabel()==a){ 
            stato[j]=1;
            diz[j]->setlabel(0);
        }
    }
    stampatutto();
}
