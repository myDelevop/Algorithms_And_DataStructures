/*
 * servizi.h
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#ifndef SERVIZICODA_H_
#define SERVIZICODA_H_

#include "codaPunt.h"

void acquisisciCoda(Coda &);
void stampaCoda(Coda &);
void svuotaCoda(Coda &);
boolean appartiene(tipoelem,Coda&);
void elimina(Coda&);

#endif /* SERVIZICODA_H_ */
