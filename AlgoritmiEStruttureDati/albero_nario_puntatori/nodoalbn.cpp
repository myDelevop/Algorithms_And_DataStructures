//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "nodoalbn.h"

nodon::nodon()
{
      primofiglio = succfratello = padre = NULL;
}

nodon * 
nodon::leggipadre()
{
      return padre;     
}



nodon * 
nodon::leggisuccfratello()
{
      return succfratello;            
}



nodon * 
nodon::leggiprimofiglio()
{
      return primofiglio;           
}



tiponodon 
nodon::leggitiponodon()
{
      return valore;          
}



void 
nodon::scrivitiponodon(tiponodon t)
{
       valore = t;                  
}



void 
nodon::scrivisuccfratello(nodon * n)
{
        succfratello = n;               
}



void
nodon::scriviprimofiglio(nodon * n)
{
       primofiglio = n;                 
}



void 
nodon::scrivipadre(nodon * n)
{
      padre = n;           
}



