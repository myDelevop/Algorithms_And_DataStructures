/*
 * serviziBinalberoPunt.cpp
 *
 *  Created on: 25/gen/2015
 *      Author: rocco
 */

#include "serviziBinalberoPunt.h"
#include "codaTemplate.h"

void preVisita(NodoBinAlbero* u, Binalbero &T) {
	if (!T.binAlberoVuoto()) {
		esaminaNodo(u, T);
		if (!T.sinistroVuoto(u))
			preVisita(T.figlioSinistro(u), T);
		if (!T.destroVuoto(u))
			preVisita(T.figlioDestro(u), T);
	}
}

void simmetrica(NodoBinAlbero* u, Binalbero& T) {
	if (!T.binAlberoVuoto()) {
		if(!T.sinistroVuoto(u))
			simmetrica(T.figlioSinistro(u), T);
		esaminaNodo(u, T);
		if(!T.destroVuoto(u))
			simmetrica(T.figlioDestro(u), T);
	}
}

void postVisita(NodoBinAlbero* u, Binalbero& T) {
	if (!T.binAlberoVuoto()) {
		if(!T.sinistroVuoto(u))
			postVisita(T.figlioSinistro(u), T);
		if(!T.destroVuoto(u))
			postVisita(T.figlioDestro(u), T);
		esaminaNodo(u, T);
	}
}

void ampiezza(Binalbero& T) {
	Coda<NodoBinAlbero*> coda;
	NodoBinAlbero* x;

	if (!T.binAlberoVuoto()) {
		esaminaNodo(T.radice(), T);
		coda.inCoda(T.radice());
		while (!coda.codaVuota()) {
			x = coda.leggiCoda();
			coda.fuoriCoda();
			if (!T.sinistroVuoto(x)) {
				esaminaNodo(T.figlioSinistro(x),T);
				coda.inCoda(T.figlioSinistro(x));
			}
			if (!T.destroVuoto(x)) {
				esaminaNodo(T.figlioDestro(x), T);
				coda.inCoda(T.figlioDestro(x));
			}
		}
	}
}

void esaminaNodo(NodoBinAlbero* u, Binalbero& T) {
	cout << T.leggiNodo(u) << "  ";
}

int confrontaTipi(tipoelem a,tipoelem b){
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

void acquisizione(Binalbero& T) {
	tipoelem elem;
	T.creaBinalbero();
	cout<<"inserisci elemento (-1 per terminare): ";
	cin>>elem;
	while (elem != -1) {
		if (!T.binAlberoVuoto()) {
			inserimentOrdinato(elem,T.radice(),T);
		} else {
			T.insRadice();
			T.scriviNodo(elem,T.radice());
		}
		cout<<"inserisci elemento (-1 per terminare): ";
		cin>>elem;
	}
}

void autoAcquisizione(Binalbero &T) {
	T.insRadice();
	T.scriviNodo(5,T.radice());
	T.insFiglioSinistro(T.radice());
	T.scriviNodo(7,T.figlioSinistro(T.radice()));
	T.insFiglioDestro(T.radice());
	T.scriviNodo(2,T.figlioDestro(T.radice()));
	T.insFiglioDestro(T.figlioSinistro(T.radice()));
	T.scriviNodo(1,T.figlioDestro(T.figlioSinistro(T.radice())));
}

void inserimentOrdinato(tipoelem e, NodoBinAlbero* u,Binalbero &T) {
	if (T.binAlberoVuoto()) {
		T.insRadice();
		T.scriviNodo(e,T.radice());
	} else {
		if (confrontaTipi(e,T.leggiNodo(u)) == -1) {
			if (T.sinistroVuoto(u)) {
				T.insFiglioSinistro(u);
				T.scriviNodo(e,T.figlioSinistro(u));
			} else
				inserimentOrdinato(e,T.figlioSinistro(u),T);
		}
		if (confrontaTipi(e,T.leggiNodo(u)) == 1) {
			if (T.destroVuoto(u)) {
				T.insFiglioDestro(u);
				T.scriviNodo(e,T.figlioDestro(u));
			} else
				inserimentOrdinato(e,T.figlioDestro(u),T);   // chiamata ricorsiva
		}
		if (confrontaTipi(e,T.leggiNodo(u)) == 0)
			cout<<"Elemento gia' presente!!!"<<endl;
	}
}

int maxProfondita(NodoBinAlbero*u,Binalbero &T) {
	int max,corr;
	if (T.sinistroVuoto(u) && T.destroVuoto(u))
		return 0;
	else {
		max = 0;
		if (!T.sinistroVuoto(u)) {
			corr = maxProfondita(T.figlioSinistro(u),T);
			if (max <= corr)
				max = corr;
		}
		if (!T.destroVuoto(u)) {
			corr = maxProfondita(T.figlioDestro(u),T);
			if (max <= corr)
				max = corr;
		}
		return (max+1);
	}
}

int profNodo(NodoBinAlbero* u,int livello,
		tipoelem elem,Binalbero& T) {
	int liv = -1;
	if (!T.binAlberoVuoto()) {
		if (T.leggiNodo(u) == elem)
			return livello;
		if (!T.sinistroVuoto(u))
			liv = profNodo(T.figlioSinistro(u),livello+1,elem,T);
		if (!T.destroVuoto(u) && liv == -1)
			liv = profNodo(T.figlioDestro(u),livello+1, elem,T);
		}
	return liv;
}

int contaNodi(NodoBinAlbero* u, Binalbero &T){
	int num = 0;
	if(!T.binAlberoVuoto()){
		if (!T.sinistroVuoto(u))
			num = num + contaNodi(T.figlioSinistro(u),T);
		if (!T.destroVuoto(u))
			num = num + contaNodi(T.figlioDestro(u),T);
		num++;
	}
	return num;
}

NodoBinAlbero* ricercaNodo(tipoelem elem,NodoBinAlbero* u, Binalbero& T) {
	NodoBinAlbero* nodo = NULL;
	if (!T.binAlberoVuoto()) {
		if (confrontaTipi(elem,T.leggiNodo(u)) == 0)
			nodo = u;
		else {
			if (T.sinistroVuoto(u) && T.destroVuoto(u))
				nodo = NULL;
			else {
				if (!T.sinistroVuoto(u))
					nodo = ricercaNodo(elem,T.figlioSinistro(u),T);
				if (nodo == NULL && !T.destroVuoto(u))
					nodo = ricercaNodo(elem,T.figlioDestro(u),T);
			}

		}
	}
	return nodo;
}

NodoBinAlbero* ricercaOrdinataNodo(tipoelem elem,NodoBinAlbero* u, Binalbero& T) {
	NodoBinAlbero* nodo = NULL;
	int res;
	if(!T.binAlberoVuoto()){
		res = confrontaTipi(elem, T.leggiNodo(u));
		if(res == 0)
			nodo = u;
		else if(res == -1){
			if(T.sinistroVuoto(u))
				nodo = 0;
			else
				nodo = ricercaOrdinataNodo(elem, T.figlioSinistro(u), T);
		}else if(res == 1){
			if(T.destroVuoto(u))
				nodo = 0;
			else
				nodo = ricercaOrdinataNodo(elem, T.figlioDestro(u), T);
		}
	}
	return nodo;
}
