/*
 * nodoNalbero.h
 *
 *  Created on: 28/gen/2015
 *      Author: rocco
 */

#ifndef NODONALBERO_H_
#define NODONALBERO_H_

typedef int tipoelem;
typedef bool boolean;

class NodoNalbero {
public:
	tipoelem getDato();
	NodoNalbero* getPrimoFiglio();
	NodoNalbero* getSuccFratello();
	NodoNalbero* getPadre();
	void setDato(tipoelem);
	void setPrimoFiglio(NodoNalbero*);
	void setSuccFratello(NodoNalbero*);
	void setPadre(NodoNalbero*);
	NodoNalbero();
	~NodoNalbero();
private:
	tipoelem dato;
	NodoNalbero *primoFiglio;
	NodoNalbero *succFratello;
	NodoNalbero *padre;
};

#endif /* NODONALBERO_H_ */
