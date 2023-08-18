/*
 * serviziNalbero.h
 *
 *  Created on: 28/gen/2015
 *      Author: rocco
 */

#ifndef SERVIZINALBEROPUNT_H_
#define SERVIZINALBEROPUNT_H_

#include "nAlbero.h"

//FUNZIONI DI VISITA
void preVisita(NodoNalbero*, nAlbero&);
void simmetrica(NodoNalbero*, nAlbero&); //inVisita
void postVisita(NodoNalbero*, nAlbero&);
void ampiezza(NodoNalbero*, nAlbero&);

//FUNZIONI DI SUPPORTO
void esaminaNodo(NodoNalbero*, nAlbero&);
int confrontaTipo(tipoelem, tipoelem);
int calcolo(NodoNalbero*, nAlbero &, int, int);

//FUNZIONI AUSILIARIE
void autoacquisizione(nAlbero &);
void acquisisciTastiera(nAlbero &);
int contaNodi(NodoNalbero*, nAlbero&, int a); //a=0 alla prima chiamata
int contaFoglie(NodoNalbero*,nAlbero&,int a); // """.....
int altezza(NodoNalbero* u, nAlbero &T);
int profonditaNodo(NodoNalbero*, nAlbero&);
NodoNalbero* ricercaNodo(tipoelem c,nAlbero &a);


#endif /* SERVIZINALBEROPUNT_H_ */
