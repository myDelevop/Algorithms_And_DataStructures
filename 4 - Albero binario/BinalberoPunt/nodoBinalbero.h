/*
 * nodoBinalbero.h
 *
 *  Created on: 19/dic/2014
 *      Author: rocco
 */

#ifndef NODOBINALBERO_H_
#define NODOBINALBERO_H_

#include <iostream>

using namespace std;

typedef bool boolean;
typedef int tipoelem;

class NodoBinAlbero {
public:
	tipoelem dato;
	NodoBinAlbero* padre;
	NodoBinAlbero* figlioSinistro;
	NodoBinAlbero* figlioDestro;

	~NodoBinAlbero() {
		padre = NULL;
		delete figlioSinistro;
		delete figlioDestro;
	}
};



#endif /* NODOBINALBERO_H_ */
