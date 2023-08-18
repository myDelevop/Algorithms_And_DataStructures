//	*********************************
//	**** Autore: Teodoro Santoro ****
//	****    Matricola: 477171    ****
//	*********************************

#include <iostream>
#include <stdlib.h>
#include "hashChiuso.h"
#include "servizio_dizionario_chiuso.h"
 
using namespace std;
 
int main(int argc, char *argv[]){
    DizChiuso D;
    D.crea();
    caricaDizionario(D);
    verificaDizionario(D);
    system("PAUSE");	
    return 0;
}
