//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

// Algoritmo di Morris Pratt - String Matching
// Tecnica algoritmica del backtracking
#define maxdim 100
#include <cstdlib>
#include <iostream>

using namespace std;

void calc_succ(int P[], int succ [], int m)
{
	int j=1;
	int h;
	h=0;
	succ[1]=0;
	while (j<=m+1){
		if ((h==0) || (P[j]==P[h])){
			j=j+1;
			h=h+1;
			succ[j]=h;
		}else
        	h=succ[h];
	}
}

int String(int P[],int T[], int n, int m)
{
	int i,j;
	int succ[100];
	i=0;
	j=0;
	calc_succ(P,succ,m);
	while ((i<=n) && (j<=m)){
		if ((j==0) || (T[i]==P[j])){
			i=i+1;
			j=j+1;
		}else
			j=succ[j];
	}
	if (j>m)
		return i-m;
	else
		return i;
}

main ()
{
	cout<<"* * * Algoritmo di Morris, Pratt, Knuth * * *";
	cout<<"\n\n";
	cout<<"Inserire la stringa principale (testo). "<<
	"\nLa stringa deve essere composta di 1 e di 0"<<
	"\nPer terminare inserire un valore negativo\n";
	int T[maxdim];
	int t,n,i=0;
	cin.clear();
	cin>>t;
	while (t>=0 && (i<maxdim)){
		i=i+1;
		T[i]=t;
		cin>>t;
	}
	n=i;
	cout<<"\n\n";
	cout<<"Inserire la stringa da ricercare (pattern)."<<
	"\nLa stringa deve essere composta di 1 e di 0"<<
	"\nPer terminare inserire un valore negativo\n";
	int P[maxdim];
	int m,p;
	i=0;
	cin.clear();
	cin>>p;
	while (p>=0 && (i<maxdim)){
		i=i+1;
		P[i]=p;
		cin>>p;
	}
	m=i;
	if (m<=n){
		int pos=String(P,T,n,m);
		if (pos>n)
			cout<<"\nLa stringa inserita non e' stata trovata nella stringa principale\n\n";
		else
			cout<<"\nLa stringa inserita e' stata trovata nella striga principale \n a partire dalla posizione "<<pos<<"\n\n";
	}else
		cout<<"\nIl pattern ha una dimensione maggiore del testo\n\n";
	system("PAUSE");
}
