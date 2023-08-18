//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "nodo.h"

nodo::nodo()
{
    figliodx=figliosx=padre=NULL;
}



Nodo 
nodo::leggi_padre()
{
     return padre;
}



Nodo 
nodo::leggi_figliosx()
{
     return figliosx;           
}



Nodo 
nodo::leggi_figliodx()
{
      return figliodx;
}



tiponodo 
nodo::leggitiponodo()
{
      return valore;         
}


void
nodo::scrivitiponodo(tiponodo t)
{
       valore = t;                
}


void
nodo::scrivifigliosx(Nodo n)
{
       figliosx = n;             
}


void
nodo::scrivifigliodx(Nodo n)
{
       figliodx = n;             
}


void
nodo::scrivipadre(Nodo n)
{
       padre = n;         
}
