/*
 * binAlbero.cpp
 *
 *  Created on: 19/dic/2014
 *      Author: rocco
 */

#include "binAlbero.h"
#include <assert.h>

void Binalbero::creaBinalbero() {
	albero = NULL;
}

boolean Binalbero::binAlberoVuoto() {
	return (albero == NULL);
}

NodoBinAlbero* Binalbero::radice() {
	assert(!binAlberoVuoto());
	return albero;
}

NodoBinAlbero* Binalbero::padre(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && u != albero);
	return u->padre;
}

NodoBinAlbero* Binalbero::figlioSinistro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && !sinistroVuoto(u));
	return u->figlioSinistro;
}

NodoBinAlbero* Binalbero::figlioDestro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && !destroVuoto(u));
	return u->figlioDestro;
}

boolean Binalbero::sinistroVuoto(NodoBinAlbero* u) {
	return (u->figlioSinistro == NULL);
}

boolean Binalbero::destroVuoto(NodoBinAlbero* u) {
	return (u->figlioDestro == NULL);
}

tipoelem Binalbero::leggiNodo(NodoBinAlbero* u) {
	return u->dato;
}

void Binalbero::scriviNodo(tipoelem elem, NodoBinAlbero* u) {
	u->dato = elem;
}

void Binalbero::insRadice() {
	assert(binAlberoVuoto());
		albero = new NodoBinAlbero();
}

void Binalbero::insFiglioSinistro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && sinistroVuoto(u));
	NodoBinAlbero* temp = new NodoBinAlbero();
	u->figlioSinistro = temp;
	temp->padre = u;
}

void Binalbero::insFiglioDestro(NodoBinAlbero* u) {
	assert(!binAlberoVuoto() && destroVuoto(u));
	NodoBinAlbero* temp = new NodoBinAlbero();
	u->figlioDestro = temp;
	temp->padre = u;
}

void Binalbero::cancSottoBinAlbero(NodoBinAlbero* u) {

	if (!binAlberoVuoto()) {
		if (u == albero)
			delete albero;
		else {
			NodoBinAlbero* padre = u->padre;
			if (u == padre->figlioSinistro)
				padre->figlioSinistro = NULL;
			else
				padre->figlioDestro = NULL;

			delete u;
			}
	}
}

Binalbero::Binalbero() {
	creaBinalbero();
}

Binalbero::~Binalbero() {}
