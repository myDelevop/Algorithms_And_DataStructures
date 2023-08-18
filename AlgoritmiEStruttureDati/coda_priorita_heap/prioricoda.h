//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef PRIORICODA_H_
#define PRIORICODA_H_

typedef bool booleano;

typedef struct elem {
	int priori;
	char elem;
}* tipoelem;

const int MAXLUNG = 100;

class prioricoda {

private:
	
	tipoelem elementi[MAXLUNG];
	int ultimo;

public:
       
	prioricoda();
	
	void creaprioricoda();
	void inserisci (tipoelem);
	tipoelem min();
	void cancellamin();
	
};

#endif /*PRIORICODA_H_*/
