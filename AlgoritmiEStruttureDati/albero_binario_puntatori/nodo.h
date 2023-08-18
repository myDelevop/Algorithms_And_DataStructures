//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef NODO_H
#define NODO_H

typedef int tiponodo;


class nodo {
	tiponodo valore;
	nodo *figliodx, *figliosx, *padre;
	
public:
	nodo ();
	
	nodo * leggi_padre ();
	nodo * leggi_figliosx ();
	nodo * leggi_figliodx ();
	
	tiponodo leggitiponodo();
	void scrivitiponodo(tiponodo);
	
	void scrivifigliosx(nodo *);
	void scrivifigliodx(nodo *);
	void scrivipadre(nodo *);
	
};

typedef nodo * Nodo;

#endif
