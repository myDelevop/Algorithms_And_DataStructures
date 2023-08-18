#ifndef NODO_H
#define NODO_H

#include <string>

using namespace std;

typedef int tipoelem;

class Nodo {
	tipoelem valore;
	Nodo *prec, *succ;
public:
	Nodo ();
	void scrivi_prec (Nodo *);
	Nodo * leggi_prec ();
	void scrivi_succ (Nodo *);
	Nodo * leggi_succ ();
	void scrivi_valore (tipoelem);
	tipoelem leggi_valore ();
};

#endif
