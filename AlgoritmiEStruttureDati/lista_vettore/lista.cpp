//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "lista.h"

/* Costruttore */

Lista::Lista ()
{
	dimensione = 0;
}


/* Restituisce un numero diverso da zero se la lista e' vuota, altrimenti
 * restituisce zero. */

boolean
Lista::listavuota ()
{
	return dimensione == 0;
}


/* Leggi il valore alla posizione POS. */

tipoelem
Lista::leggilista(posizione pos)
{
	if (pos < 1 || pos > dimensione)
		return 0;
	return lista[pos - 1];
}


/* Scrive il valore T alla posizione POS. */

void
Lista::scrivilista (tipoelem t, posizione pos)
{
	if (pos < 1 || pos > dimensione)
		return;
	lista[pos - 1] = t;
}


/* Restituisce la posizione del primo elemento. */

posizione
Lista::primolista ()
{
	return 1;
}


/* Restituisce un valore diverso da zero se POS e' l'ultima posizione della
 * lista, altrimenti restituisce zero. */

boolean
Lista::finelista(posizione pos)
{
	return pos > dimensione;
}


/* Restituisce la posizione successiva a POS. */

posizione
Lista::succlista (posizione pos)
{
	return pos + 1;
}


/* Restituisce la posizione precedente a POS. */

posizione
Lista::predlista (posizione pos)
{
	return pos - 1;
}


/* Inserisci T alla posizione POS. */

void
Lista::inslista(tipoelem t, posizione pos)
{
	if (dimensione >= max_lista)
		return;
	
	/* Inserimento prima del primo elemento. */
	
	if (pos == 0) {
		for (int i = dimensione; i > 0; i--)
			lista[i] = lista[i-1];
		lista[0] = t;
		dimensione++;
		return;
	}

	/* Inserimento dopo l'ultimo elemento. */

	if (pos == dimensione + 1) {
		lista[dimensione] = t;
		dimensione++;
		return;
	}

	/* Inserimento in posizione intermedia. */

	if (pos >= 1 && pos <= dimensione) {
		for (int i = dimensione; i > pos-1; i--)
			lista[i] = lista[i-1];
		lista[pos-1] = t;
		dimensione++;
	}
}


/* Cancella l'elemento alla posizione POS. POS deve essere una posizione valida
 * all'interno della lista, ovvero deve essereo compresa tra 1 e dimensione. */

void
Lista::canclista(posizione pos)
{
	if (pos < 1 || pos > dimensione)
		return;
	
	for (int i = pos-1; i < dimensione-1; i++)
		lista[i] = lista[i+1];
	dimensione--;
}
