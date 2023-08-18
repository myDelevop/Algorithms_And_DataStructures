/*
 * Dizionario.h
 *
 *  Created on: 01/feb/2015
 *      Author: rocco
 */

#ifndef DIZIONARIO_H_
#define DIZIONARIO_H_

#include <iostream>
#include <string>
#include "datoDizionario.h"

using namespace std;

template <class T,class K>
class Dizionario {
public:
	virtual void inserisci(T,K)=0;
	virtual void cancella(K)=0;
	virtual T cerca(K)=0;
	Dizionario();
};

template <class T,class K>
Dizionario<T,K>::Dizionario() {}


#endif /* DIZIONARIO_H_ */
