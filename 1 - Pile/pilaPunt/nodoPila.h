/*
 * nodoPila.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef NODOPILA_H_
#define NODOPILA_H_

typedef bool boolean;
typedef char tipoelem;

class NodoPila {
public:
	tipoelem dato;
	NodoPila* successivo;
};

#endif /* NODOPILA_H_ */
