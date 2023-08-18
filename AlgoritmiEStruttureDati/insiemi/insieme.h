//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef INSIEME_H
#define INSIEME_H
#include "lista.h"

class Insieme {
	Lista * L;
	
public:
	          Insieme ();
	          ~Insieme();
      boolean insiemevuoto();
	  boolean appartiene(tipoelem);
         void inserisci(tipoelem);
         void cancella(tipoelem);
	     void unione(Insieme &, Insieme &);
	     void intersezione(Insieme &, Insieme &);
	     void differenza(Insieme &, Insieme &);
	     
     //Supporto
     tipoelem leggielem(posizione);
         void stampa();
};

#endif
