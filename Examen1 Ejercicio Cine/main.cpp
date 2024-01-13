#include "Cine.h"
using namespace std;

int main() {


    Cine *c = new Cine(3,3);

    c->reversar('a',0);
    c->reversar('a',1); // Listo

    cout<< c->toString()<<endl;

    cout<< "Asientos disponibles: "<< c->cantAsientosDisponibles() <<endl;


    delete c;


    return 0;
}
