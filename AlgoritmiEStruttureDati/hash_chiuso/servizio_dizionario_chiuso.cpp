//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

using namespace std;
#include <iostream>
#include "servizio_dizionario_chiuso.h"

void caricaDizionario(DizChiuso &D){
    cout<<"Inserimento di elementi: {4,5,6,8,8,9,16}"<<endl;
    D.inserisci(4);
    D.inserisci(5);
    D.inserisci(6);
    D.inserisci(8);
    D.inserisci(8);//duplicato
    D.inserisci(9);
    D.inserisci(16);
}


void verificaDizionario(DizChiuso &D){
    cout<<"Ecco gli elementi inseriti:"<<endl;
    cout<<"ora elimino il 4"<<endl;
    D.cancella(4);

    cout<<"vediamo se 26 appartiene al dizionario.."<<endl;
    if (D.appartiene(26)) cout<<"SI"<<endl;
    else cout<<"No"<<endl;

    cout<<"vediamo se inseriamo 26 al dizionario.."<<endl;
    D.inserisci(26);
    if (D.appartiene(26)) cout<<"26 appartiene al dizionario"<<endl;
    else cout<<"26 NON appartiene al dizionario"<<endl;

    cout<<"vediamo se togliamo 26 dal dizionario.."<<endl;
    D.cancella(26);
    if (D.appartiene(26)) cout<<"26 appartiene al dizionario"<<endl;
    else cout<<"26 NON appartiene al dizionario"<<endl;

    cout<<"vediamo se inserisco 4 al dizionario.."<<endl;
    D.inserisci(4);
    if (D.appartiene(4)) cout<<"4 appartiene al dizionario"<<endl;
    else cout<<"4 NON appartiene al dizionario"<<endl;

    cout<<"ora elimino 16.."<<endl;
    D.cancella(16);
    if (D.appartiene(16)) cout<<"16 appartiene al dizionario"<<endl;
    else cout<<"16 NON appartiene al dizionario"<<endl;
}



void stampaDizionario(DizChiuso D){
    for (int i=0;i<MAX;i++){
        if (D.appartiene(i)) cout<<i<<" ";
    }
    cout<<endl;
}
