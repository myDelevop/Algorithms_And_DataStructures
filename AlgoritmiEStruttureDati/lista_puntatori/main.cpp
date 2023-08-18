//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "lista.h"

using namespace std;

void stampa(Lista *);

int main(int argc, char *argv[])
{
    Lista * l;
    l = new Lista;
    posizione p;
    
    cout<<"Lista Vuota? 1=Si 0=No :  "<<l->listavuota()<<endl;
    
    cout<<"Inserimento del 4 in posizione 1"<<endl;
    l->inslista(4,l->primolista());
    
    cout<<"Lista Vuota? 1=Si 0=No :  "<<l->listavuota()<<endl;
    
    p = l->primolista();
    p = l->succlista(p);
    cout<<"Inserimento del 2 in posizione successiva al 4"<<endl;
    l->inslista(2,p);
    
    p = l->primolista();
    p = l->succlista(p);
    p = l->succlista(p);
    cout<<"Inserimento del 20 in posizione successiva al 2"<<endl;
    l->inslista(20,p);
    
    p = l->primolista();
    p = l->succlista(p);
    p = l->succlista(p);
    cout<<"Inserimento del 12 tra il 2 e 20"<<endl;
    l->inslista(12,p);

    p = l->primolista();    
    cout<<"Inserimento del 7 in testa"<<endl;
    l->inslista(7,p);  
    
    cout<<"Stampa:"<<endl;    
    stampa(l);

    p = l->primolista();
    p = l->succlista(p);
    p = l->succlista(p);    
    cout<<"Sostituzione con l'8 in terza posizione"<<endl;
    l->scrivilista(8,p);
    
    cout<<"Stampa:"<<endl;    
    stampa(l);

    p = l->primolista();
    p = l->succlista(p);     
    cout<<"Cancellazione del numero in seconda posizione"<<endl;
    l->canclista(p);    
    
    cout<<"Stampa:"<<endl;    
    stampa(l);
        
    system("PAUSE");
    return EXIT_SUCCESS;
}

void stampa(Lista * l){
     posizione p = l->primolista();
     int i = 1;
     
     do{ 
        cout<<"Posizione: "<<i<<" Elemento: "<<l->leggilista(p)<<endl;
        p = l->succlista(p);   
        i++;             
     }while(!l->finelista(p));
} 
