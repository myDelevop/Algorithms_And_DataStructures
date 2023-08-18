/*
 * dizionarioListaTemplate.h
 *
 *  Created on: 01/feb/2015
 *      Author: rocco
 */

#ifndef DIZIONARIOLISTATEMPLATE_H_
#define DIZIONARIOLISTATEMPLATE_H_

#include "Dizionario.h"
#include "datoDizionario.h"
#include "listaTemplate.h"

template <class elemento,class chiave>
class DizionarioLista:public Dizionario<elemento,chiave> {
public:
	void inserisci(elemento,chiave);
	void cancella(chiave);
	elemento cerca(chiave);
	DizionarioLista();
private:
	typedef Dato<elemento> DatoDiz;
	typedef NodoLista<DatoDiz>* posizione;
	Lista<DatoDiz,posizione> lista;
};

template <class elemento,class chiave>
void DizionarioLista<elemento,chiave>::inserisci(elemento elem,chiave k) {
	bool trovato = false;
	posizione pos = lista.primoLista();
	NodoLista<DatoDiz> nodo;
	DatoDiz dato;

	while (lista.fineLista(pos) && !trovato) {
		dato = lista.leggiLista(pos);
		if (k == dato.getChiave())
			trovato = true;
		else
			pos = lista.succLista(pos);
	}
	if (!trovato) {
		dato.setChiave(k);
		dato.setElemento(elem);
		pos = lista.primoLista();
		lista.insLista(dato,pos);
	}
}
template <class elemento,class chiave>
void DizionarioLista<elemento,chiave>::cancella(chiave k) {
	bool trovato;
	posizione pos = lista.primoLista();
	NodoLista<DatoDiz> nodo;
	DatoDiz dato;
	while (pos != NULL && trovato != true) {
		dato = lista.leggiLista(pos);
		if (k == dato.getChiave()) {
			lista.cancLista(pos);
			trovato = true;
			} else
				pos = lista.succLista(pos);
		}
}

template <class elemento,class chiave>
elemento DizionarioLista<elemento,chiave>::cerca(chiave k) {
	elemento risposta;//TODO: possibile errore di inizializzazione
	bool trovato;
	posizione pos = lista.primoLista();
	NodoLista<DatoDiz> nodo;
    DatoDiz dato;
    while (pos != NULL && trovato != true) {
    	dato = lista.leggiLista(pos);
    	if (k == dato.getChiave()) {
    		risposta = dato.getElemento();
    		trovato = true;
            } else
            	pos = lista.succLista(pos);
    }
    return risposta;
}

template <class elemento,class chiave>
DizionarioLista<elemento,chiave>::DizionarioLista() {
	lista.creaLista();
}

#endif /* DIZIONARIOLISTATEMPLATE_H_ */
