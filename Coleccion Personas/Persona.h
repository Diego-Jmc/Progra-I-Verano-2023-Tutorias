//
// Created by diego on 15/12/2023.
//

#ifndef POO_PUNTEROS_PERSONA_H
#define POO_PUNTEROS_PERSONA_H
#include <iostream>
#include <sstream>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(const string &nombre, int edad);

    Persona(){

    }

    virtual ~Persona();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getEdad() const;

    void setEdad(int edad);

    string toString();
};


#endif //POO_PUNTEROS_PERSONA_H
