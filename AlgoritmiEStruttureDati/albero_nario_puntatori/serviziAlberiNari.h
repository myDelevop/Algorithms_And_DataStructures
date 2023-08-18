//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef SERVIZIALBERINARI_H_
#define SERVIZIALBERINARI_H_
#include "alberon.h"

//Funzioni di visita
void previsita(NodoN,AlberoN &);
void postvisita(NodoN,AlberoN &);
void invisita(NodoN,AlberoN &);

//Funzioni di Supporto
void esaminaNodo(NodoN, AlberoN &);
int confrontaTipo(tiponodon, tiponodon);//Funzione che prende 2 tiponodon e li confronta
//restituendo -1 se a<b, 0 se a=b, 1 se a>b

//Funzioni Ausiliarie
void insNaviga(AlberoN &);//inserimento e navigazione di nodi
NodoN ricercaNodo(tiponodon, NodoN, AlberoN &);//restituisce il NodoN cercato
int profonditaNodo(NodoN, AlberoN&);//restutuisce la profondita del nodo dato il NodoN
int contanodi(NodoN, AlberoN &);


#endif /*SERVIZIALBERINARI_H_*/
