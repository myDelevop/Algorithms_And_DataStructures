//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

//Algoritmo del Natural  - Merge - Sort
//Tecnica algoritmica del divide et impera
#define DIMMAX 100
#include <cstdlib>
#include <iostream>

using namespace std;

void merge(int A[], int primo, int ultimo, int mezzo){
	int i=primo;
	int j=mezzo+1;
	int k=primo;
	int B[DIMMAX];
	while ((i<=mezzo) && (j<=ultimo)){
		if (A[i]<=A[j]){
			B[k]=A[i];
			i++;
		}else{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	if (i<=mezzo){
		while (i<=mezzo){
			B[k] = A[i];
			i++;
			k++;
		}
	}else{
		while (j<=ultimo){
			B[k] = A[j];
			j++;
			k++;
		}
	}
	for (k=primo; k<=ultimo; k++)
		A[k] = B[k];
	return;
}

void mergesort (int A[], int primo, int ultimo){
	int mezzo;
	if (primo<ultimo){
		mezzo=(primo+ultimo)/2;
		mergesort(A,primo,mezzo);
		mergesort(A,mezzo+1,ultimo);
		merge(A,primo,ultimo,mezzo);
	}
}

main(){
	int A[DIMMAX];
	int a,n,i=0;
	cout<<" * * * Algoritmo del merge sort * * *";
	cout<<"\n\nInserimento del vettore di interi positivi da ordinare";
	cout<<"\n(Per terminare inserire un intero negativo)\n";
	cin>>a;

	while (a>0){
		i=i+1;
		A[i]=a;
		cin>>a;
	}

	n=i;
	cout<<"\n\nIl vettore inserito e'\n\n";
	for (int j=1;j<=n;j++)
		cout<<A[j]<<"\t";
	mergesort(A,1,n);

	cout <<"\n\nIl vettore ordinato e'\n\n";
	for (int j=1;j<=n;j++)
		cout<<A[j]<<"\t";
	cout<<"\n\n";
	system("PAUSE");
}
