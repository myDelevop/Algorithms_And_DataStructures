//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

// funzione che verifica se il vettore viola uno dei vincoli
bool verifica(int v[],int i){
	int j;
	for (j=1;j<i;j++)
		if (v[i]==v[j]||abs(v[i]-v[j])==abs(i-j))
			return true;
	return false;
}

bool nregine(int v[ ],int n){
	bool b,successo=false;
	int k=1;
	v[k]=1;
	do{
		if (verifica(v,k)){ //verifica che i vincoli del problema siano rispettati nelle righe fino alla riga k-esima
			do{
				if (v[k]<n){
					b=true;
					v[k]++;
				}else{ // backtrack
					b=false;
					k--;
				}
			}while(!b && k!=0);
		}else{
			if (k==n)
				successo=true;
			else{
				k++;
				v[k]=1;
			}
		}
	}while (!successo && k!=0);
	return successo;
}

int main(){
	int v[11];
	bool successo;
	int n;
	cout<<"Inserire il numero di regine da posizionare (n<10): ";
	cin>>n;
	successo=nregine(v,n);
	cout<<"\n";
	if (successo){
		for (int i=1;i<n+1;i++){
			for (int j=1;j<n+1;j++){
				if (v[i]!=j)
					cout<<" !! ";
				else
					cout<<" ## ";
			}
			cout<<"\n\n";
		}
	}else
	   cout<<"Non esiste soluzione al problema per n = "<<n<<"\n\n";
	system ("PAUSE");
}
