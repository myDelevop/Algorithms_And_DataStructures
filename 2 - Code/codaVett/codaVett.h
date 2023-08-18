/*
 * codaVett.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef CODAVETT_H_
#define CODAVETT_H_

#define MAX_LENGTH 200

typedef char tipoelem;
typedef bool boolean;

class Coda {
public:
	void creaCoda();
	boolean codaVuota();
	tipoelem leggiCoda();
	void inCoda(tipoelem);
	void fuoriCoda();
	Coda();
   ~Coda();

private:
	tipoelem elementi[MAX_LENGTH];
	int start;
	int len;
};

#endif /* CODAVETT_H_ */
