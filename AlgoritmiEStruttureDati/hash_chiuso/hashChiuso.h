//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#ifndef HASH_CHIUSO_H
#define HASH_CHIUSO_H

typedef bool boolean;
typedef int tipoelem;
const int MAX=11;
		
class Cella{
public:
    void setlabel(tipoelem);
    tipoelem getlabel();
private:
    tipoelem label;
};

//definizione della classe Diz
class DizChiuso
{
	public:
		//Specifica delle interfacce
		void     crea();
		boolean  appartiene(tipoelem);
		void     inserisci(tipoelem);
		void     cancella(tipoelem);

		//costruttori e distruttori
		DizChiuso();
		~DizChiuso();
		
	private:
		
		Cella * diz[MAX];
        int stato[MAX]; 
        
		//funzione calcolo hash e funzione di ricerca hash
		int hash(tipoelem);
		void scan(tipoelem, int&, int&);
		void stampatutto();
		
};
#endif
