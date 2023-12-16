//
// Created by diego on 15/12/2023.
//

#ifndef POO_PUNTEROS_COLECCIONPERSONAS_H
#define POO_PUNTEROS_COLECCIONPERSONAS_H
#include "Persona.h"

class ColeccionPersonas {

private:
    int tam;
    int cant;
    Persona *coleccionPersonas;
public:
    ColeccionPersonas(int tam);
    ~ColeccionPersonas();
    void insertar(Persona p);
    string toString();
    Persona obtenerMasViejo();

};


#endif //POO_PUNTEROS_COLECCIONPERSONAS_H
