/*
 * datoDizionario.h
 *
 *  Created on: 01/feb/2015
 *      Author: rocco
 */

#ifndef DATODIZIONARIO_H_
#define DATODIZIONARIO_H_

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Dato {
public:
	T getElemento();
	void setElemento(T);
	int getChiave();
	void setChiave(int);
	Dato();
	Dato(int,T);
private:
	T elemento;
	int chiave;
};

template <class T>
T Dato<T>::getElemento() {
	return elemento;
}

template <class T>
void Dato<T>::setElemento(T elem) {
	elemento = elem;
}

template <class T>
int Dato<T>::getChiave() {
	return chiave;
}

template <class T>
void Dato<T>::setChiave(int k) {
	chiave = k;
}

template <class T>
Dato<T>::Dato() {
	chiave = 0;
}

template <class T>
Dato<T>::Dato(int elem,T k) {
	elemento = elem;
	chiave = k;
}


#endif /* DATODIZIONARIO_H_ */
