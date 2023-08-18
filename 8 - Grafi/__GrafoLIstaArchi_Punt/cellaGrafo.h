/*
 * cellaGrafo.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef CELLAGRAFO_H_
#define CELLAGRAFO_H_

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef bool boolean;
typedef int tipoNodo;
typedef string tipoArco;

class cellaGrafo {
public:
	tipoNodo getInfoNodo();
	void setInfoNodo(tipoNodo);
	boolean getVisitato();
	void setVisitato(boolean);
	cellaGrafo();
private:
	tipoNodo infoNodo;
	boolean visitato; // utile per DFS/BFS
};

#endif /* CELLAGRAFO_H_ */
