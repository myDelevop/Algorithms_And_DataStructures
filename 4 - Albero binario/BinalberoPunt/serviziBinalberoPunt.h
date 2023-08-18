/*
 * serviziBinalberoPunt.h
 *
 *  Created on: 25/gen/2015
 *      Author: rocco
 */

#ifndef SERVIZIBINALBEROPUNT_H_
#define SERVIZIBINALBEROPUNT_H_

#include "binAlbero.h"

//FUNZIONE DI VISITA
void preVisita(NodoBinAlbero*, Binalbero&);
void simmetrica(NodoBinAlbero*, Binalbero&);
void postVisita(NodoBinAlbero*, Binalbero&);
void ampiezza(Binalbero&);

//FUNZIONI DI SUPPORTO
void esaminaNodo(NodoBinAlbero*, Binalbero&); //di supporto
int confrontaTipi(tipoelem a,tipoelem b);

//FUNZIONI AUSILIARIE
void acquisizione(Binalbero &);
void autoAcquisizione(Binalbero &); //acquisisce un albero casuale
void inserimentOrdinato(tipoelem , NodoBinAlbero* ,Binalbero &);
int maxProfondita(NodoBinAlbero*,Binalbero &);//numero di nodi fino alla foglia piu distante
int profNodo(NodoBinAlbero*,int,tipoelem,Binalbero&);
int contaNodi(NodoBinAlbero*, Binalbero &);
NodoBinAlbero* ricercaNodo(tipoelem,NodoBinAlbero*, Binalbero&);
NodoBinAlbero* ricercaOrdinataNodo(tipoelem,NodoBinAlbero*, Binalbero&);

#endif /* SERVIZIBINALBEROPUNT_H_ */
