/*
 * nodoCoda.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef NODOCODA_H_
#define NODOCODA_H_

typedef char tipoelem;
typedef bool boolean;

class NodoCoda {
public:
	tipoelem dato;
	NodoCoda* successivo;
};

#endif /* NODOCODA_H_ */
