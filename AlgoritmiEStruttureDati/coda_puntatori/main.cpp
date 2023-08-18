//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "coda.h"

using namespace std;

int main(int argc, char *argv[])
{
    
    Coda * c;
    c = new Coda;
    
    cout<<"Inserimento valore 1"<<endl;
    c->in(1);
    cout<<"Inserimento valore 3"<<endl;
    c->in(3);
    cout<<"Inserimento valore 6"<<endl;
    c->in(6);
    cout<<"Elemento in coda: "<< c->leggi()<<endl;
    cout<<"Fuoricoda"<<endl;
    c->fuori();
    cout<<"Elemento in coda: "<< c->leggi()<<endl;
    cout<<"Fuoricoda"<<endl;
    c->fuori();
    cout<<"Elemento in coda: "<< c->leggi()<<endl;
    cout<<"Fuoricoda"<<endl;
    c->fuori();
    
    cout<<"Coda Vuota 0=No 1=Si : "<<c->vuota()<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
