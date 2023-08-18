//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef SERVIZIALBEROBIN_H_
#define SERVIZIALBEROBIN_H_

#include "alberobin.h"

//Funzioni di visita
void previsita(Nodo,AlberoBin &);
void postvisita(Nodo,AlberoBin &);
void simmetrica(Nodo,AlberoBin &);
void ampiezza(AlberoBin &);

//Funzioni di Supporto
void esaminaNodo(Nodo, AlberoBin &);
int confrontaTipi(tiponodo, tiponodo);//Funzione che prende 2 tiponodo e li confronta
//restituendo -1 se a<b, 0 se a=b, 1 se a>b

//Funzioni Ausiliarie
void inserimentOrdinato(tiponodo, Nodo, AlberoBin &);  // inserimento ordinato  con rimozione dei duplicati
Nodo ricercaOrdinataNodo(tiponodo, Nodo, AlberoBin &); // restituisce il nodo contenente l'etichetta cercata
void insNaviga(AlberoBin &);//inserimento e navigazione di nodi
Nodo ricercaNodo(tiponodo, Nodo, AlberoBin &);//restituisce il nodo cercato
int altezzaNodo(Nodo, AlberoBin &);
int profonditaNodo(Nodo, Nodo, int, AlberoBin &);//restutuisce l'altezza dato il nodo da cercare e il nodo di partenza
int contanodi(Nodo, AlberoBin &);

#endif /*SERVIZIALBEROBIN_H_*/
