/*
 * nodoBinalberoTemplate.h
 *
 *  Created on: 19/dic/2014
 *      Author: rocco
 */

#ifndef NODOBINALBEROTEMPLATE_H_
#define NODOBINALBEROTEMPLATE_H_

#include <iostream>

using namespace std;

typedef bool boolean;

template <class tipoelem>
class CellaBin {
public:
	void setElem(tipoelem);
	void setPadre(CellaBin<tipoelem>*);
	void setFiglioSinistro(CellaBin<tipoelem>*);
	void setFiglioDestro(CellaBin<tipoelem>*);
	tipoelem getElem();
	CellaBin<tipoelem>* getPadre();
	CellaBin<tipoelem>* getFiglioSx();
	CellaBin<tipoelem>* getFiglioDx();

private:
	tipoelem dato;
	CellaBin* padre;
	CellaBin* figlioSinistro;
	CellaBin* figlioDestro;
};

template <class T>
void CellaBin<T>::setElem(T elem) {
	dato = elem;
}

template <class T>
void CellaBin<T>::setPadre(CellaBin<T>* u) {
	padre = u;
}

template <class T>
void CellaBin<T>::setFiglioSinistro(CellaBin<T>* u) {
	figlioSinistro = u;
}

template <class T>
void CellaBin<T>::setFiglioDestro(CellaBin<T>* u) {
	figlioDestro = u;
}

template <class T>
T CellaBin<T>::getElem() {
	return dato;
}

template <class T>
CellaBin<T>* CellaBin<T>::getPadre() {
	return padre;
}

template <class T>
CellaBin<T>* CellaBin<T>::getFiglioSx() {
	return figlioSinistro;
}


template <class T>
CellaBin<T>* CellaBin<T>::getFiglioDx() {
	return figlioDestro;
}


#endif /* NODOBINALBEROTEMPLATE_H_ */
