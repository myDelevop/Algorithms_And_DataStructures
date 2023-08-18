//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include "lista.h"

/* Restituisce un nodo in base alla sua posizione POS. POS deve essere un numero
 * compreso tra 1 e il numero di nodi nella lista. Se POS va oltre questi
 * limiti, la funzione restituisce NULL. Bisogna notare che POS=0 e
 * POS=numero_nodi+1 sono delle posizioni particolari, in quanto possono essere
 * usate per denotare dei nodi fittizi rispettivamente prima del primo nodo e
 * dopo l'ultimo. Questi particolari valori di POS, tuttavia, devono essere
 * controllati caso per caso nelle varie funzioni, perche non sono presi in
 * considerazione da trova_posizione(). */

Nodo *
Lista::trova_posizione (posizione pos)
{
	Nodo *n;
	int i;
	
	if (pos <= 0 || pos > numero_nodi)
		return NULL;

	n = nodi;
	i = 1;
	while (i < pos) {
		n = n->leggi_succ ();
		i++;
	}

	return n;
}


/* Costruttore */

Lista::Lista ()
{
	nodi = NULL;
	numero_nodi = 0;
}


/* Distruttore. Libera la memoria di ogni nodo nella lista. */

Lista::~Lista ()
{
	Nodo *n, *p;

	n = nodi;
	while (n != NULL) {
		p = n->leggi_succ ();
		delete n;
		n = p;
	}
}


/* Restituisce un numero diverso da zero se la lista e' vuota, altrimenti
 * restituisce zero. */

boolean
Lista::listavuota ()
{
	return numero_nodi == 0;
}


/* Leggi il valore alla posizione POS. */

tipoelem
Lista::leggilista(posizione pos)
{
	Nodo *n;

	n = trova_posizione (pos);

	return ((n != NULL) ? n->leggi_valore () : 0);
}


/* Scrive il valore T alla posizione POS. */

void
Lista::scrivilista(tipoelem t, posizione pos)
{
	Nodo *n;

	n = trova_posizione (pos);
	if (n != NULL)
		n->scrivi_valore (t);
}


/* Restituisce la posizione del primo elemento. */

posizione
Lista::primolista()
{
	return 1;
}


/* Restituisce un valore diverso da zero se POS e' l'ultima posizione della
 * lista, altrimenti restituisce zero. */

boolean
Lista::finelista(posizione pos)
{
	return pos > numero_nodi;
}


/* Restituisce la posizione successiva a POS. */

posizione
Lista::succlista(posizione pos)
{
	return pos + 1;
}


/* Restituisce la posizione precedente a POS. */

posizione
Lista::predlista(posizione pos)
{
	return pos - 1;
}


/* Inserisci T alla posizione POS. */

void
Lista::inslista(tipoelem t, posizione pos)
{
	Nodo *nuovo, *prec, *succ;

	nuovo = new Nodo;
	nuovo->scrivi_valore (t);

	/* Inserimento in prima posizione */
	
	if (pos <= 1) {
		nuovo->scrivi_succ (nodi);
		nuovo->scrivi_prec (NULL);
		if (nodi != NULL)
			nodi->scrivi_prec (nuovo);
		nodi = nuovo;
		numero_nodi++;
		return;
	}

	/* Inserimento in ultima posizione */

	if (pos > numero_nodi) {
		prec = trova_posizione (numero_nodi);
		prec->scrivi_succ (nuovo);
		nuovo->scrivi_prec (prec);
		nuovo->scrivi_succ (NULL);
		numero_nodi++;
		return;
	}

	/* Inserimento in una posizione intermedia */

	succ = trova_posizione (pos);
	prec = succ->leggi_prec ();

	prec->scrivi_succ (nuovo);
	nuovo->scrivi_prec (prec);
	succ->scrivi_prec (nuovo);
	nuovo->scrivi_succ (succ);

	numero_nodi++;
}


/* Cancella l'elemento alla posizione POS. POS deve essere una posizione valida
 * all'interno della lista, ovvero deve essereo compresa tra 1 e numero_nodi. */

void
Lista::canclista(posizione pos)
{
	Nodo *trovato;

	if (numero_nodi == 0) return;

	/* Eliminazione del primo elemento (dobbiamo aggiornare il puntatore
	 * NODI). */

	if (pos == 1) {
		trovato = nodi;
		nodi = trovato->leggi_succ ();
		delete trovato;
		numero_nodi--;
		return;
	}

	/* Eliminazione di un elemento in un'altra posizione */

	trovato = trova_posizione (pos);
	if (trovato == NULL) return;

	Nodo *prec, *succ;
	prec = trovato->leggi_prec ();
	succ = trovato->leggi_succ ();
	if (succ != NULL)
		succ->scrivi_prec (prec);
	if (prec != NULL)
		prec->scrivi_succ (succ);
	delete trovato;
	numero_nodi--;
}
