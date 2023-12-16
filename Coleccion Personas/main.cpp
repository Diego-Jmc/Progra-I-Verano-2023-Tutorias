#include "ColeccionPersonas.h"

using namespace std;

int main() {

    ColeccionPersonas *coleccion = new ColeccionPersonas(10);


    Persona persona1("Alice", 25);
    Persona persona2("Bob", 30);
    Persona persona3("Juan", 22);
    Persona persona4("Pedro", 25);
    Persona persona5("Marie", 30);
    Persona persona6("Bill", 20);
    Persona persona7("Julio", 49);
    Persona persona8("Mario", 100);
    Persona persona9("Paz", 56);
    Persona persona10("Luna", 16);

    coleccion->insertar(persona1);
    coleccion->insertar(persona2);
    coleccion->insertar(persona10);
    coleccion->insertar(persona3);
    coleccion->insertar(persona4);
    coleccion->insertar(persona5);
    coleccion->insertar(persona6);
    coleccion->insertar(persona7);
    coleccion->insertar(persona8);
    coleccion->insertar(persona9);

    cout<<coleccion->toString()<<endl;

    cout<<coleccion->obtenerMasViejo().toString()<<endl;

    return 0;
}
