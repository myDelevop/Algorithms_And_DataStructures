//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>

#include "alberobin.h"



AlberoBin::AlberoBin()
{
         radice = NULL;       
}

AlberoBin::~AlberoBin()
{
         cancsottobinalbero(radice);       
}


booleano 
AlberoBin::binalberovuoto()
{
         return (radice==NULL);
}



Nodo 
AlberoBin::binradice()
{
         return radice;           
}



Nodo 
AlberoBin::binpadre(Nodo n)
{
        return n->leggi_padre();      
}



Nodo 
AlberoBin::figliosx(Nodo n)
{
        return n->leggi_figliosx();      
}



Nodo 
AlberoBin::figliodx(Nodo n)
{
        return n->leggi_figliodx();      
}



booleano 
AlberoBin::sxvuoto(Nodo n)
{
        return (n->leggi_figliosx()==NULL);               
}



booleano 
AlberoBin::dxvuoto(Nodo n)
{
        return (n->leggi_figliodx()==NULL);               
}


void
AlberoBin::cancsottobinalbero(Nodo n)
{
            if(n != radice){
	            if ( (n->leggi_padre())->leggi_figliosx() ==  n  )
	                 (n->leggi_padre())->scrivifigliosx(NULL);
	                 
	            if ( (n->leggi_padre())->leggi_figliodx() ==  n  )
	                 (n->leggi_padre())->scrivifigliodx(NULL);     
            }
                 
            if(n->leggi_figliosx() != NULL)
            	cancsottobinalbero(n->leggi_figliosx());
            
            if(n->leggi_figliodx() != NULL)
            	cancsottobinalbero(n->leggi_figliodx());
            	
            delete n;
                    
}



tiponodo 
AlberoBin::legginodo(Nodo n)
{
          return (n->leggitiponodo());                
}


void
AlberoBin::scrivinodo(tiponodo t, Nodo n)
{
          n->scrivitiponodo(t);         
}


void
AlberoBin::insbinradice(tiponodo t)
{
      Nodo nuovo;
      nuovo = new nodo;     
      
      nuovo->scrivitiponodo(t);
      radice = nuovo;
              
}


void
AlberoBin::insfigliosx(tiponodo t, Nodo n)
{
       Nodo nuovo;
       nuovo = new nodo;
       
       nuovo->scrivitiponodo(t);
       nuovo->scrivipadre(n);
       n->scrivifigliosx(nuovo);
                      
}


void
AlberoBin::insfigliodx(tiponodo t, Nodo n)
{
       Nodo nuovo;
       nuovo = new nodo;
       
       nuovo->scrivitiponodo(t);
       nuovo->scrivipadre(n);
       n->scrivifigliodx(nuovo);
                      
}
