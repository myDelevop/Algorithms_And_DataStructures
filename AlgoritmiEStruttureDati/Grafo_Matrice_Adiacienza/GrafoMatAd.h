//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <cstdlib>
#include <string>
#include "lista.h"

#ifndef GRAFO_H
#define GRAFO_H
typedef int nodo;
typedef string tiponodo;
typedef int tipoarco;
typedef bool boolean;

// Classe Grafo Con Matrice Di Adiacenza, con nodi etichettati e archi pesati
class GrafoMatAd
{
    public:
        
        void creagrafo();
        bool grafovuoto();
        void insnodo(nodo, tiponodo);
        void insarco(nodo, nodo, tipoarco);
        void cancnodo(nodo);
        void cancarco(nodo,nodo);
        boolean esistenodo(nodo);
        boolean esistearco(nodo,nodo);
        Lista adiacenti(nodo);
        
        //Funzioni aggiuntive per gestire etichette e pesi
        void scrivinodo(nodo, tiponodo);
        void scriviarco(nodo, nodo, tipoarco);
        tiponodo legginodo(nodo);
        tipoarco leggiarco(nodo, nodo);
        
        //Funzioni aggiuntive per gestire le visite
		bool getVisitato(nodo);
		void setVisitato(bool, nodo);
		void azzeraVisita();
        
        //costruttore e distruttore
        GrafoMatAd();
        ~GrafoMatAd();
        
        //Funzione che stampa la matrice di adiacenza a scopo puramente di sviluppo
        void stampa();
    
    private:
      enum{MAX=100,INFINITO=-1}; //Poniamo il valore INFINITO=-1 essendo -1 un peso
                                 //non inseribile            
      tiponodo label[MAX];
      bool mark[MAX];
      bool visita[MAX];
      tipoarco matrice[MAX][MAX];
};
#endif


