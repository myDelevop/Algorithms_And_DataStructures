#ifndef HASH_Aperto_H
#define HASH_Aperto_H
#include "lista.h"

const int MAX=11;

//definizione della classe Diz
class DizAperto
{
	public:
		//Specifica delle interfacce
		void     crea();
		boolean  appartiene(tipoelem);
		void     inserisci(tipoelem);
		void     cancella(tipoelem);

		//costruttori e distruttori
		DizAperto();
		~DizAperto();
		
		
		void stampatutto();
	private:
		
		Lista * diz[MAX];
        
		//funzione calcolo hash e funzione di ricerca hash
		int hash(tipoelem);
		
};
#endif
