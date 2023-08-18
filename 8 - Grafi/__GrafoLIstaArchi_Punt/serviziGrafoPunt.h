/*
 * serviziGrafoListaArchiTemplate.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef SERVIZIGRAFOPUNT_H_
#define SERVIZIGRAFOPUNT_H_

#include "grafoListaArchi.h"
#include "codaTemplate.h"

//FUNZIONI DI ACQUISIZIONE
void acquisisciGrafo(GrafoListaArchi &);

//FUNZIONI DI VISITA
void DFS(cellaGrafo* n,GrafoListaArchi &G);
void visitaDFS(cellaGrafo *n, GrafoListaArchi &G);
void BFS(cellaGrafo* n,GrafoListaArchi &G);
void visitaBFS(cellaGrafo *n, GrafoListaArchi &G);

//FUNZIONI AUSILIARIE O DI SUPPORTO
boolean grafoConnesso(GrafoListaArchi &G);
void esaminaNodo(cellaGrafo* u,GrafoListaArchi &G);
void stampaNodi(GrafoListaArchi &);
void stampaArchi(GrafoListaArchi &);

#endif /* SERVIZIGRAFOPUNT_H_ */
