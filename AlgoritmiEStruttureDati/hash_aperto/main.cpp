#include <cstdlib>
#include <iostream>
#include "hashAperto.h"
#include "servizio_dizionario_aperto.h"

using namespace std;

int main(int argc, char *argv[])
{
    DizAperto D;
    D.crea();
    caricaDizionario(D);
    verificaDizionario(D);
    system("PAUSE");	
    return 0;
}
