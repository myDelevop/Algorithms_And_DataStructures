//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "pila.h"

using namespace std;

int main(int argc, char *argv[])
{
    Pila * c;
    c = new Pila;
    
    cout<<"Inserimento valore 1"<<endl;
    c->in(1);
    cout<<"Inserimento valore 3"<<endl;
    c->in(3);
    cout<<"Inserimento valore 6"<<endl;
    c->in(6);
    cout<<"Elemento in Testa: "<< c->leggi()<<endl;
    cout<<"FuoriPila"<<endl;
    c->fuori();
    cout<<"Elemento in Testa: "<< c->leggi()<<endl;
    cout<<"FuoriPila"<<endl;
    c->fuori();
    cout<<"Elemento in Testa: "<< c->leggi()<<endl;
    cout<<"FuoriPila"<<endl;
    c->fuori();
    
    cout<<"Pila Vuota 0=No 1=Si : "<<c->vuota()<<endl;
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
