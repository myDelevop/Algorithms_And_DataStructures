/*
 * binAlbero.h
 *
 *  Created on: 19/dic/2014
 *      Author: rocco
 */

#ifndef BINALBERO_H_
#define BINALBERO_H_

#include "nodoBinalbero.h"

class Binalbero {
public:
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

#endif /* BINALBERO_H_ */
