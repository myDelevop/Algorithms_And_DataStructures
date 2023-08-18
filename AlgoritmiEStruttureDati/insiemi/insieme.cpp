//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "insieme.h"

using namespace std;

Insieme::Insieme ()
{
     L = NULL;   
}


Insieme::~Insieme()
{
     L->~Lista();
     L = NULL;            
}



boolean
Insieme::insiemevuoto()
{
      boolean resp = false;
      if(L == NULL || L->listavuota())
      	resp = true;
      	
      return resp;   
}


boolean 
Insieme::appartiene(tipoelem t)
{
      bool app = false;
		if(!insiemevuoto()){
	      posizione i;
	      i = L->primolista();
	      do{
	            if(L->leggilista(i) == t)
	                 app = true;                                      
				i = L->succlista(i);
	      }while(!L->finelista(i) && !app);
		}
      return app;
}


void 
Insieme::inserisci(tipoelem t)
{
        
    if(L == NULL)
    {
         L = new Lista;
         L->inslista(t, L->primolista());
    }
    else if(!appartiene(t))
    {
         L->inslista(t, L->primolista());
    }
               
}


void 
Insieme::cancella(tipoelem t)
{
      posizione i, da_canc;
      i = L->primolista();
      bool app = false;     
      do{          
            if(L->leggilista(i) == t)
            {
                 app = true; 
                 da_canc = i;
            }            
			i = L->succlista(i);
      }while(!L->finelista(i) && !app);     
      
      if (app == true) 
		L->canclista(da_canc);   
}


void 
Insieme::unione(Insieme &A, Insieme &B)
{
      posizione i;
      i = A.L->primolista();
      
      do{
            inserisci(A.L->leggilista(i));
			i = A.L->succlista(i); 
      }while(!A.L->finelista(i));
      
      i = B.L->primolista();
       
      do{
            inserisci(B.L->leggilista(i));
			i = B.L->succlista(i); 
      }while(!B.L->finelista(i));
}


void
Insieme::intersezione(Insieme &A, Insieme &B)
{
      posizione i;
      i = A.L->primolista();
       tipoelem elem;
       
       do{
			elem = A.L->leggilista(i);             
			if ( B.appartiene(elem) ) 
                 inserisci(elem);
             
			i = A.L->succlista(i);      
       }while(!A.L->finelista(i));
                     
}


void 
Insieme::differenza(Insieme &A, Insieme &B)
{
      posizione i;
      i = A.L->primolista();
      
      do{
            inserisci(A.L->leggilista(i));
            i = A.L->succlista(i);
      }while(!A.L->finelista(i));
      
      i = B.L->primolista();

      do{
            cancella(B.L->leggilista(i));
            i = B.L->succlista(i);
      }while(!B.L->finelista(i));      
}

void
Insieme::stampa()
{
      posizione i;
      i = L->primolista();
      cout<<"{ ";
      
      do{
            cout<<L->leggilista(i)<<"; ";
            i = L->succlista(i);
      }while(!L->finelista(i));
      
      cout<<"}"<<endl;            
}
