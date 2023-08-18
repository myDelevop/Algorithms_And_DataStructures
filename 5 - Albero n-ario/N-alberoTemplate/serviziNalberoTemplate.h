/*
 * serviziNalberoTemplate.h
 *
 *  Created on: 29/gen/2015
 *      Author: rocco
 */

#ifndef SERVIZINALBEROTEMPLATE_H_
#define SERVIZINALBEROTEMPLATE_H_

#include <iostream>
#include "codaTemplate.h"
#include "nAlbero.h"

using namespace std;

//non viene usato template <class T> per non creare ambiguità

template <class S>
void preVisita(NodoNalbero<S>* u,nAlbero<S> &T) {
	NodoNalbero<S>* c;
	esaminaNodo(u, T);
	if (!T.foglia(u)) {
		c = T.primoFiglio(u);
		while (!T.ultimoFratello(c)) {
			preVisita(c,T);
			c = T.succFratello(c);
		}
		preVisita(c,T);
	}
}

template <class S>
void simmetrica(NodoNalbero<S>*u,nAlbero<S> &T) {//inVisita
	NodoNalbero<S>* c;
	if (T.foglia(u))
		esaminaNodo(u,T);
	else {
		c = T.primoFiglio(u);
		simmetrica(c,T);
		esaminaNodo(u,T);
		while(!T.ultimoFratello(c)) {
			c = T.succFratello(c);
			simmetrica(c,T);
		}
	}
}

template <class S>
void postVisita(NodoNalbero<S>* u,nAlbero<S> &T) {
	NodoNalbero<S>* c;
	if (!T.foglia(u)) {
		c = T.primoFiglio(u);
		while(!T.ultimoFratello(c)) {
			postVisita(c,T);
			c = T.succFratello(c);
		}
		postVisita(c,T);
	}
	esaminaNodo(u,T);
}

template <class S>
void ampiezza(NodoNalbero<S>* u,nAlbero<S> &T) {
    NodoNalbero<S>* temp;
    Coda<NodoNalbero<S>*> coda;
    coda.inCoda(u);
    while (!coda.codaVuota()) {
    	temp = coda.leggiCoda();
        esaminaNodo(temp,T);
        coda.fuoriCoda();
        if (!T.foglia(temp)) {
        	temp = T.primoFiglio(temp);
            while (!T.ultimoFratello(temp)) {
            	coda.inCoda(temp);
                temp = T.succFratello(temp);
            }
            coda.inCoda(temp);
        }
    }
}

template <class S>
void esaminaNodo(NodoNalbero<S>* u, nAlbero<S> &T) {
	if (u!=NULL)
		cout << T.leggiNodo(u) << "  ";
}

template <class S>
int confrontaTipo(S a,S b) {
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

template <class S>
int calcolo(NodoNalbero<S>* u, nAlbero<S> &T, int temp, int max) {
    NodoNalbero<S>* c;
    if (T.foglia(u)) {
    	if (temp >= max)
    		max = temp;
     } else {
             temp++;
             {
            	 c = T.primoFiglio(u);
                 while (!T.ultimoFratello(c)) {
                	 max = calcolo(c,T,temp,max);
                     c = T.succFratello(c);
                 }
                     max = calcolo(c,T, temp, max);
             }
     }
     return max;
}

template <class S>
void autoacquisizione(nAlbero<S> &T) {

	NodoNalbero<S> *u = new NodoNalbero<S>();

	T.insRadice(4);
	u = T.radice();
	T.insPrimoFiglio(3,u);
	u = T.primoFiglio(u);
	T.insFratelloSucc(6,u);
	u = T.succFratello(u);
	T.insPrimoFiglio(18,u);
	T.insFratelloSucc(7,u);
	u = T.succFratello(u);
	T.insPrimoFiglio(16,u);
	u = T.primoFiglio(u);
	T.insFratelloSucc(14,u);
	u = T.primoFiglio(T.radice());
	T.insPrimoFiglio(5,u);
	u = T.primoFiglio(u);
	T.insFratelloSucc(24,u);
	u = T.succFratello(u);
	T.insFratelloSucc(9,u);
}

template <class S>
void acquisisciTastiera(nAlbero<S> &T) {
    Coda<NodoNalbero<S>*> tmp;
    bool finito;
    NodoNalbero<S>* aux;
    S info,infoPrimoFiglio;
	char risp;

	cout << "Inserisci l'elemento che devi mettere nella radice: " << endl;
	cin >> info;
    T.insRadice(info);
    aux = T.radice();
    tmp.inCoda(aux);
    while(!tmp.codaVuota()) {
       aux=tmp.leggiCoda();
       tmp.fuoriCoda();
       cout<<"Se vuoi inserire il primofiglio di "<<aux->getDato()<<" premi S altrimenti N:";
       do {
          cin>>risp;
       } while(toupper(risp)!='S' && toupper(risp)!='N');

       if (toupper(risp) == 'S') {
   		  cout<<"Inserisci il primofiglio di "<<aux->getDato()<<": ";
       	  cin>>info;
          cout<<endl;
          T.insPrimoFiglio(info,aux);
          aux=T.primoFiglio(aux);
          tmp.inCoda(aux);
          infoPrimoFiglio=info;
          do {
            finito=true;
           	cout<<"Per inserire un fratello di "<<infoPrimoFiglio<<" premi S altrimenti N: ";
	        do {
               cin>>risp;
            } while(toupper(risp)!='S'&& toupper(risp)!='N');
      		if (toupper(risp)=='S') {
               cout<<"Il fratello di "<<infoPrimoFiglio<<" e': ";
			   cin>>info;
               cout<<endl;
               T.insFratelloSucc(info,aux);
               aux=T.succFratello(aux);
               tmp.inCoda(aux);
				infoPrimoFiglio=info;
            finito=false;
            }
         } while(!finito);
      }
   }
}

template <class S>
int contaNodi(NodoNalbero<S>* u, nAlbero<S> &T,int cont) {
	 if (!T.nAlberoVuoto()) {
		 NodoNalbero<S>* c;
	     cont++;
	     if (!T.foglia(u)) {
	    	 c = T.primoFiglio(u);
	    	 while (!T.ultimoFratello(c)) {
	    		 cont = contaNodi(c, T,cont);
	             c = T.succFratello(c);
	    	 }
	    	 cont = contaNodi(c,T, cont);
	     }
	 }
	 return cont;
}

template <class S>
int contaFoglie(NodoNalbero<S>* u,nAlbero<S> &T, int cont) {
	if (!T.nAlberoVuoto() && u != NULL) {
		NodoNalbero<S>* c;
		if (T.foglia(u))
			cont++;
		else {
			c = T.primoFiglio(u);
			while (!T.ultimoFratello(c)) {
				cont = contaFoglie(c,T, cont);
				c = T.succFratello(c);
			}
			cont = contaFoglie(c,T, cont);
		}
	}
	return cont;
}

template <class S>
int altezza(NodoNalbero<S>* u, nAlbero<S> &T) {
	int max, temp;
    max = temp = 0;
    if (!T.nAlberoVuoto())
    	max = calcolo(u, T, temp, max);
    return max;
}

template <class S>
int profonditaNodo(NodoNalbero<S>* n, nAlbero<S> &T){
	if (T.radice() == n)
		return 0;
	return 1 + profonditaNodo(T.padre(n), T);
}

template <class S>
NodoNalbero<S>* ricercaNodo(S c,nAlbero<S> &a) {
	S s;
    NodoNalbero<S>* rad = new NodoNalbero<S>();
    NodoNalbero<S>* temp= new NodoNalbero<S>();
    boolean trovato = false;
    Coda<NodoNalbero<S>*> cod;

    rad = a.radice();
    if (rad->getDato() == c)
    	return rad;

    cod.inCoda(rad);
    while (!cod.codaVuota() && trovato == false) {
    	temp = cod.leggiCoda();
        s = temp->getDato();
        cod.fuoriCoda();
        if (s == c) {
        	trovato = true;
            	return temp;
        } else if (!a.foglia(temp)) {
        	temp = a.primoFiglio(temp);
            while (!a.ultimoFratello(temp)) {
            	cod.inCoda(temp);
                temp = a.succFratello(temp);
            }
            cod.inCoda(temp);
        }
    }
    if (cod.codaVuota())
    	cout << "elemento non prensente" << endl;
    return NULL;
}


#endif /* SERVIZINALBEROTEMPLATE_H_ */
