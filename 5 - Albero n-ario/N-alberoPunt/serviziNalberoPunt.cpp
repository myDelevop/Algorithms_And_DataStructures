/*
 * serviziNalbero.cpp
 *
 *  Created on: 28/gen/2015
 *      Author: rocco
 */


#include <iostream>
#include "codaTemplate.h"
#include "nAlbero.h"
#include "serviziNalberoPunt.h"

using namespace std;

void preVisita(NodoNalbero* u,nAlbero &T) {
	NodoNalbero* c;
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

void simmetrica(NodoNalbero* u,nAlbero &T) {//inVisita
	NodoNalbero* c;
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

void postVisita(NodoNalbero* u,nAlbero &T) {
	NodoNalbero* c;
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

void ampiezza(NodoNalbero* u,nAlbero &T) {
    NodoNalbero* temp;
    Coda<NodoNalbero*> coda;
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

void esaminaNodo(NodoNalbero* u, nAlbero &T) {
	if (u!=NULL)
		cout << T.leggiNodo(u) << "  ";
}

int confrontaTipo(tipoelem a, tipoelem b) {
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

int calcolo(NodoNalbero* u, nAlbero &T, int temp, int max) {
    NodoNalbero* c;
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

void autoacquisizione(nAlbero &T) {

	NodoNalbero *u = new NodoNalbero();

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

void acquisisciTastiera(nAlbero &T) {
    Coda<NodoNalbero*> tmp;
    bool finito;
    NodoNalbero* aux;
    tipoelem info,infoPrimoFiglio;
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

int contaNodi(NodoNalbero* u, nAlbero &T,int cont) {
	 if (!T.nAlberoVuoto()) {
		 NodoNalbero* c;
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

int contaFoglie(NodoNalbero* u,nAlbero &T, int cont) {
	if (!T.nAlberoVuoto() && u != NULL) {
		NodoNalbero* c;
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

int altezza(NodoNalbero* u, nAlbero &T) {
	int max, temp;
    max = temp = 0;
    if (!T.nAlberoVuoto())
    	max = calcolo(u, T, temp, max);
    return max;
}

int profonditaNodo(NodoNalbero* n, nAlbero &T){
	if (T.radice() == n)
		return 0;
	return 1 + profonditaNodo(T.padre(n), T);
}

NodoNalbero* ricercaNodo(tipoelem c,nAlbero &a) {
	tipoelem s;
    NodoNalbero* rad = new NodoNalbero();
    NodoNalbero* temp= new NodoNalbero();
    boolean trovato = false;
    Coda<NodoNalbero*> cod;

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
