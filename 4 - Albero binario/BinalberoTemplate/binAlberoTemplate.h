/*
 * binAlberoTemplate.h
 *
 *  Created on: 19/dic/2014
 *      Author: rocco
 */

#ifndef BINALBEROTEMPLATE_H_
#define BINALBEROTEMPLATE_H_

#include <iostream>
#include <assert.h>
#include "nodoBinalberoTemplate.h"

using namespace std;

template <class tipoelem>
class Binalbero {
public:
	typedef CellaBin<tipoelem> NodoBinAlbero; //anche typedef con puntatore

	void creaBinalbero();
	boolean binAlberoVuoto();
	NodoBinAlbero* radice();
	NodoBinAlbero* padre(NodoBinAlbero*);
	NodoBinAlbero* figlioSinistro(NodoBinAlbero*);
	NodoBinAlbero* figlioDestro(NodoBinAlbero*);
	boolean sinistroVuoto(NodoBinAlbero*);
	boolean destroVuoto(NodoBinAlbero*);
	tipoelem leggiNodo(NodoBinAlbero*);
	void scriviNodo(tipoelem, NodoBinAlbero*);
	void insRadice();
	void insFiglioSinistro(NodoBinAlbero*);
	void insFiglioDestro(NodoBinAlbero*);
	void cancSottoBinAlbero(NodoBinAlbero*);
	Binalbero();
	~Binalbero();
private:
	NodoBinAlbero* albero;
};

template <class T>
void Binalbero<T>::creaBinalbero() {
	albero = NULL;
}

template <class T>
boolean Binalbero<T>::binAlberoVuoto() {
	return (albero == NULL);
}

template <class T>
CellaBin<T>* Binalbero<T>::radice() {
	assert(!binAlberoVuoto());
	return albero;
}

template <class T>
CellaBin<T>* Binalbero<T>::padre(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && u != albero);
	return u->getPadre();
}

template <class T>
CellaBin<T>* Binalbero<T>::figlioSinistro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && !sinistroVuoto(u));
	return u->getFiglioSx();
}

template <class T>
CellaBin<T>* Binalbero<T>::figlioDestro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && ! destroVuoto(u));
	return u->getFiglioDx();
}

template <class T>
boolean Binalbero<T>::sinistroVuoto(NodoBinAlbero* u) {
	return (u->getFiglioSx() == NULL);
}

template <class T>
boolean Binalbero<T>::destroVuoto(NodoBinAlbero* u) {
	return (u->getFiglioDx() == NULL);
}

template <class T>
T Binalbero<T>::leggiNodo(NodoBinAlbero* u) {
	return u->getElem();
}

template <class T>
void Binalbero<T>::scriviNodo(T elem, NodoBinAlbero* u) {
	u->setElem(elem);
}

template <class T>
void Binalbero<T>::insRadice() {
	assert(binAlberoVuoto());
	albero = new CellaBin<T>();
}

template <class T>
void Binalbero<T>::insFiglioSinistro(NodoBinAlbero* u) {
	assert (!binAlberoVuoto() && sinistroVuoto(u));
	NodoBinAlbero* temp = new NodoBinAlbero();
	u->setFiglioSinistro(temp);
	temp->setPadre(u);
}

template <class T>
void Binalbero<T>::insFiglioDestro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && destroVuoto(u));
	NodoBinAlbero* temp = new NodoBinAlbero();
	u->setFiglioDestro(temp);
	temp->setPadre(u);
}

template <class T>
void Binalbero<T>::cancSottoBinAlbero(NodoBinAlbero* u) {
	if (!binAlberoVuoto()) {
		if (u == albero)
			delete albero;
		else {
			NodoBinAlbero* padre = u->getPadre();
			if (u==padre->getFiglioSx())
				padre->setFiglioSinistro(NULL);
			else
				padre->setFiglioDestro(NULL);
			delete u;
			}
	}
}

template <class T>
Binalbero<T>::Binalbero() {
	creaBinalbero();
}

template <class T>
Binalbero<T>::~Binalbero() {}

#endif /* BINALBEROTEMPLATE_H_ */
