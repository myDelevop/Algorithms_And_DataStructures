//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <cstdlib>
#include <iostream>
#include "insieme.h"

using namespace std;

int main(int argc, char *argv[])
{

    Insieme A, B, U, I, D;

    if (A.insiemevuoto())
       cout<<"A insieme vuoto"<<endl;
    else
       cout<<"A insieme con elementi"<<endl;
       
    A.inserisci(1);
    A.inserisci(7);
    A.inserisci(12);
    A.inserisci(13);
    A.inserisci(3);
    A.inserisci(5);
    A.inserisci(14);
    A.inserisci(11);
    A.inserisci(10);
    A.inserisci(4);
    A.inserisci(8);
    A.inserisci(9);
    A.inserisci(2);
    A.inserisci(6);
    cout<<"A:";
    A.stampa();    
        
    if (A.appartiene(5))
       cout<<"il 5 appartiene ad A"<<endl;
    else
       cout<<"il 5 non appartiene ad A"<<endl;
       
    A.cancella(5);
    
    cout<<"5 cancellato  ad A"<<endl;
    cout<<"A:";
    A.stampa();     
    if (A.appartiene(5))
       cout<<"il 5 appartiene  ad A"<<endl;
    else
       cout<<"il 5 non appartiene  ad A"<<endl;
    if (A.appartiene(9))
       cout<<"il 9 appartiene  ad A"<<endl;
    else
       cout<<"il 9 non appartiene  ad A"<<endl;
    if (A.appartiene(1))
       cout<<"il 1 appartiene  ad A"<<endl;
    else
       cout<<"il 1 non appartiene  ad A"<<endl;
       
    if (A.insiemevuoto())
       cout<<"A insieme vuoto"<<endl;
    else
       cout<<"A insieme con elementi"<<endl; 
       
              
    B.inserisci(11);
    B.inserisci(12);
    B.inserisci(13);
    B.inserisci(14);
    B.inserisci(15);
    B.inserisci(16);
    B.inserisci(17);
    B.inserisci(18);
    B.inserisci(19);
    cout<<"B:";
    B.stampa();    

       

    if (U.insiemevuoto())
       cout<<"U insieme vuoto"<<endl;
    else
       cout<<"U insieme con elementi"<<endl;     
         
    U.unione(A, B);
    cout<<"U = A Unione B"<<endl;
    
    if (U.insiemevuoto())
       cout<<"U insieme vuoto"<<endl;
    else
       cout<<"U insieme con elementi"<<endl;   
    
    cout<<"U:";
    U.stampa();    
    
    
    cout<<"I = A interzezione B"<<endl;
    I.intersezione(A, B);
    cout<<"I:";
    I.stampa();    
   
   
    cout<<"I = A - B"<<endl;
    D.differenza(A, B);
    cout<<"D:";
    D.stampa(); 
    
       
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
