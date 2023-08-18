//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <cstdlib>
#include "alberobin.h"
#include "coda.h"
#include "serviziAlberoBin.h"

using namespace std;

void previsita(Nodo u, AlberoBin &T){

	if(!T.binalberovuoto()){
		
		esaminaNodo(u, T);
	
		if (!T.sxvuoto(u))
			previsita(T.figliosx(u),T);
		
		if (!T.dxvuoto(u))
			previsita(T.figliodx(u),T);
	}
}

void postvisita(Nodo u, AlberoBin &T){
	
	if(!T.binalberovuoto()){
		
		if (!T.sxvuoto(u))
			postvisita(T.figliosx(u),T);
		
		if (!T.dxvuoto(u))
			postvisita(T.figliodx(u),T);
			
		esaminaNodo(u, T);
	}	
}

void simmetrica(Nodo u, AlberoBin &T){

	if(!T.binalberovuoto()){
		
		if (!T.sxvuoto(u))
			simmetrica(T.figliosx(u),T);

		esaminaNodo(u, T);
		
		if (!T.dxvuoto(u))
			simmetrica(T.figliodx(u),T);
	}		    
}

void ampiezza(AlberoBin &T){

	Coda * c;
	c = new Coda;
	Nodo n;
	
	n = T.binradice();
	
	c->in(n);
	
	while(!c->vuota()){
		
		n = c->leggi();
		c->fuori();		
		esaminaNodo(n,T);
		
		if(!T.sxvuoto(n))
			c->in(T.figliosx(n));
		if(!T.dxvuoto(n))
			c->in(T.figliodx(n));
			
	}
	
}

void esaminaNodo(Nodo u, AlberoBin &T){
	cout<<T.legginodo(u)<<", ";
}

int confrontaTipi(tiponodo a, tiponodo b){
	
	int conf;
	
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	
	return conf;
}

void inserimentOrdinato(tiponodo e, Nodo u, AlberoBin &T){
	
	if (T.binalberovuoto()){
		T.insbinradice(e);
	}
	else{
		if (confrontaTipi(e,T.legginodo(u)) == -1){
			if (T.sxvuoto(u)){
				T.insfigliosx(e,u);
			}
			else 
				inserimentOrdinato(e,T.figliosx(u),T); //chiamata ricorsiva
		}
		if (confrontaTipi(e,T.legginodo(u)) == 1){
			if (T.dxvuoto(u)){
				T.insfigliodx(e,u);
			}
			else 
				inserimentOrdinato(e,T.figliodx(u),T);   // chiamata ricorsiva
		}
		if (confrontaTipi(e,T.legginodo(u)) == 0)
			cout<<"Elemento gia' presente!!!"<<endl;
	}
}

void insNaviga(AlberoBin &T){
	
	tiponodo e;
	Nodo u;
	int scelta=0;
	
	if(T.binalberovuoto()){
		cout<<"Inserisci Radice: ";
		cin>>e;
		T.insbinradice(e);
		cout<<endl;
	}
	
	u = T.binradice();
	
	while(scelta<6){
		cout<<"Cosa vuoi fare?"<<endl;
		cout<<"1) Vai al Figlio Sinistro"<<endl;		
		cout<<"2) Vai al Figlio Destro"<<endl;
		cout<<"3) Vai al Padre"<<endl;
		cout<<"4) Inserisci Figlio Sinistro"<<endl;
		cout<<"5) Inserisci Figlio Destro"<<endl;
		cout<<"6) Esci dall'inserimento"<<endl;
		cin>>scelta;
				
		switch(scelta){
			case 1: 
				if(T.sxvuoto(u)){
					cout<<"Impossibile accedere al Figlio Sinistro perche' vuoto\n"<<endl;
				}else{
	    			u = T.figliosx(u);
	    			cout<<"Figlio Sinistro: "<<T.legginodo(u)<<endl<<endl;
				}					
				break;
			case 2:
				if(T.dxvuoto(u)){
					cout<<"Impossibile accedere al Figlio Destro perche' vuoto\n"<<endl;
				}else{
	    			u = T.figliodx(u);
	    			cout<<"Figlio Destro: "<<T.legginodo(u)<<endl<<endl;
				}
				break;
			case 3:
				if(T.binradice()==u){
					cout<<"Impossibile accedere al padre perche' sei alla Radice\n"<<endl;
				}else{
	    			u = T.binpadre(u);
	    			cout<<"Padre: "<<T.legginodo(u)<<endl<<endl;
				}
				break;
			case 4:
				if(!T.sxvuoto(u)){
					cout<<"Figlio Sinistro esistente\n"<<endl;
				}else{
	    			cout<<"Inserisci il Tiponodo: ";
	    			cin>>e;
	    			T.insfigliosx(e,u);
	    			cout<<endl;
				}
				break;
			case 5:
				if(!T.dxvuoto(u)){
					cout<<"Figlio Destro esistente\n"<<endl;
				}else{
	    			cout<<"Inserisci il TipoNodo: ";
	    			cin>>e;
	    			cout<<endl;
	    			T.insfigliodx(e,u);
				}
				break;
			default:
				scelta = 6;
		}
    }
	
}

Nodo ricercaOrdinataNodo(tiponodo e, Nodo u, AlberoBin &T){
	
	Nodo nodo = 0;
	int res;
	
	if(!T.binalberovuoto()){
		res = confrontaTipi(e, T.legginodo(u));
		if(res == 0)
			nodo = u;
		else if(res == -1){
			if(T.sxvuoto(u))
				nodo = 0;
			else
				nodo = ricercaOrdinataNodo(e, T.figliosx(u), T);
		}else if(res == 1){
			if(T.dxvuoto(u))
				nodo = 0;
			else
				nodo = ricercaOrdinataNodo(e, T.figliodx(u), T);
		}
	}
	return nodo;
}	

Nodo ricercaNodo(tiponodo e, Nodo u, AlberoBin &T){

	Nodo nodo = 0;
	if(!T.binalberovuoto()){
		if(confrontaTipi(e, T.legginodo(u)) == 0)
			nodo = u;
		else{
			if ((T.sxvuoto(u)) &&  (T.dxvuoto(u)))
				nodo = 0;
			else{
				if (!T.sxvuoto(u))
					nodo = ricercaNodo(e, T.figliosx(u), T);
				if(nodo == 0 && !T.dxvuoto(u))
					nodo = ricercaNodo(e, T.figliodx(u), T);
			}
		}
	}
    return nodo;
}

int altezzaNodo(Nodo u, AlberoBin &T){
	int max,corr;
	if((T.sxvuoto(u)==true) && (T.dxvuoto(u)==true))   //se u è foglia
		return 0;
	else{
		max=0;
		if (!T.sxvuoto(u)){
			corr = altezzaNodo(T.figliosx(u),T);
			if(max <= corr)
				max = corr;
		}
		if (!T.dxvuoto(u)){
			corr = altezzaNodo(T.figliodx(u),T);
			if(max <= corr)
				max = corr;
		}
		return(max+1);
	} 
}

int profonditaNodo(Nodo u, Nodo p, int livello, AlberoBin &T){
	int liv=-1;
	if(!T.binalberovuoto()){
		if(confrontaTipi(T.legginodo(u), T.legginodo(p)) == 0)
			liv = livello;
		else{
			if (!T.sxvuoto(p))
				liv = profonditaNodo(u, T.figliosx(p), livello+1, T);
			if (!T.dxvuoto(p) && (liv==-1))
				liv = profonditaNodo(u, T.figliodx(p), livello+1, T);
		}
	}
	return liv;	
}

int contanodi(Nodo u, AlberoBin &T){

	int num = 0;
	
	if(!T.binalberovuoto()){		
		if (!T.sxvuoto(u))
			num = num + contanodi(T.figliosx(u),T);		
		if (!T.dxvuoto(u))
			num = num + contanodi(T.figliodx(u),T);
		num++;
	}
	
	return num;	    
}


