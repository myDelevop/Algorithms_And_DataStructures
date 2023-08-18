//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "alberon.h"

AlberoN::AlberoN()
{
         Rad = NULL;         
}

AlberoN::~AlberoN()
{
     cancsottoalbero(Rad);
}


booleano 
AlberoN::alberovuoto()
{
         return (Rad==NULL);                 
}



NodoN 
AlberoN::radice()
{
        return Rad;
}



NodoN 
AlberoN::padre(NodoN n)
{
        return(n->leggipadre());  
}



booleano 
AlberoN::foglia(NodoN n)
{
     return (n->leggiprimofiglio() == NULL);        
}


NodoN 
AlberoN::primofiglio(NodoN n)
{
     return(n->leggiprimofiglio());             
}



booleano 
AlberoN::ultimofratello(NodoN n)
{
     return (n->leggisuccfratello() == NULL);        
}



NodoN 
AlberoN::succfratello(NodoN n)
{
     return (n->leggisuccfratello());              
}                 



void 
AlberoN::insprimosottoalbero(NodoN N, AlberoN &S){	
	NodoN s;
	s = S.radice();
	s->scrivisuccfratello(N->leggiprimofiglio());
	s->scrivipadre(N);
	N->scriviprimofiglio(s);
} 



void 
AlberoN::inssottoalbero(NodoN N, AlberoN &S){
	NodoN s;
	s = S.radice();
	s->scrivisuccfratello(N->leggisuccfratello());
	s->scrivipadre(N->leggipadre());
	N->scrivisuccfratello(s);    
} 



void 
AlberoN::cancsottoalbero(NodoN n){
	NodoN temp;	
	if(n != Rad){
        if ( (n->leggipadre())->leggiprimofiglio() ==  n  )
        	(n->leggipadre())->scriviprimofiglio(n->leggisuccfratello());
		else{
            temp = (n->leggipadre())->leggiprimofiglio();
            while(temp->leggisuccfratello() != n)
            	temp = temp->leggisuccfratello();
            temp->scrivisuccfratello(n->leggisuccfratello());	                
		}  
    }
    
    if(n->leggiprimofiglio() != NULL ){
        temp = n->leggiprimofiglio();
        if(temp->leggisuccfratello() != NULL)
        	cancsottoalbero(temp->leggisuccfratello());
        cancsottoalbero(temp);
    }
    delete n;
} 



void 
AlberoN::insradice(tiponodon t)
{
      NodoN nuovo;
      nuovo = new nodon;     
      
      nuovo->scrivitiponodon(t);
      Rad = nuovo;             
}


void 
AlberoN::insprimofiglio(tiponodon t, NodoN n)
{
      NodoN nuovo;
      nuovo = new nodon;     
      
      nuovo->scrivitiponodon(t);
      nuovo->scrivisuccfratello(n->leggiprimofiglio());
      
      n->scriviprimofiglio(nuovo);
      nuovo->scrivipadre(n);
                                  
}


void 
AlberoN::inssuccfratello(tiponodon t, NodoN n)
{
                          
      NodoN nuovo;
      nuovo = new nodon; 
      
      nuovo->scrivitiponodon(t);
      nuovo->scrivisuccfratello(n->leggisuccfratello());
      nuovo->scrivipadre(n->leggipadre());
      n->scrivisuccfratello(nuovo);       
                       
}



tiponodon 
AlberoN::legginodo(NodoN n)
{
       return (n->leggitiponodon());          
}



void 
AlberoN::scrivinodo(tiponodon t, NodoN n)
{
       n->scrivitiponodon(t);
}


