//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef NODO_H
#define NODO_H

typedef int tiponodon;


class nodon {
	tiponodon valore;
	nodon *primofiglio, *succfratello, *padre;
	
public:
	
    nodon();
	
	nodon * leggipadre();
	nodon * leggisuccfratello();
	nodon * leggiprimofiglio();
	
	tiponodon leggitiponodon();
	void scrivitiponodon(tiponodon);
	
	void scrivisuccfratello(nodon *);
	void scriviprimofiglio(nodon *);
	void scrivipadre(nodon *);
	
};

typedef nodon * NodoN;

#endif
