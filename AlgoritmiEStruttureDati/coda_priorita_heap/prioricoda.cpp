//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "prioricoda.h"

using namespace std;

prioricoda::prioricoda(){
	int i;
	ultimo = 0;
	for( i = 0; i < MAXLUNG; i++)
		elementi[i] = 0;
}

void 
prioricoda::creaprioricoda(){
	prioricoda();
}

void 
prioricoda::inserisci (tipoelem t){
	int i, k;
	tipoelem temp;
	
	if(ultimo == MAXLUNG-1)
		cout<<"Errore Coda con Priorita' piena"<<endl;
	else{
		ultimo++;
		elementi[ultimo] = t;
		i = ultimo;
		if(i > 1)
			k = i / 2;
		while(i > 1 && elementi[i]->priori < elementi[k]->priori){
			temp = elementi[i];
			elementi[i] = elementi[k];
			elementi[k] = temp;
			i = k;
			if(i > 1)
				k = i / 2;
		}
	}
}

tipoelem 
prioricoda::min(){
	
	tipoelem t = 0;
	
	if(ultimo == 0)
		cout<<"Errore Coda con Priorita' vuota"<<endl;
	else
		t = elementi[1];
		
	return t;
}

void 
prioricoda::cancellamin(){

	if(ultimo == 0)
		cout<<"Errore Coda con Priorita' vuota"<<endl;
	else{
		int i, k;
		bool scambio;
		tipoelem temp;
		
		elementi[1] = elementi[ultimo];
		ultimo--;
		i = 1;
		scambio = true;
		
		while(i <= (ultimo/ 2) && scambio){
			k = 2 * i;
			if(k < ultimo)
				if(elementi[k]->priori > elementi[k+1]->priori)
					k++;
			if(elementi[k]->priori < elementi[i]->priori){
				temp = elementi[i];
				elementi[i] = elementi[k];
				elementi[k] = temp;
				i = k;
			}else
				scambio = false;
		}
	}
}
