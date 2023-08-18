/*
 * codaVett.cpp
 *
 *  Created on: 15/dic/2014
 *      Author: Rocco
 */

#include <iostream>
#include <assert.h>
#include "codaVett.h"

using namespace std;


void Coda::creaCoda() {
	start = 0;
	len = 0;
}


boolean Coda::codaVuota() {
	return (len <= 0);
}


tipoelem Coda::leggiCoda() {
	assert(!codaVuota());
	return elementi[start];
}


void Coda::inCoda(tipoelem elem) {
	assert(len < MAX_LENGTH);
	elementi[(start+len) % MAX_LENGTH] = elem;
	len++;
}

void Coda::fuoriCoda() {
	assert(!codaVuota());
	start = (start+1) % MAX_LENGTH;
	len--;
}

Coda::Coda() {
	creaCoda();
}

Coda::~Coda() {}
