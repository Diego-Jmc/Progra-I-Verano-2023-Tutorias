//
// Created by diego on 15/12/2023.
//

#include "Persona.h"

const string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const string &nombre) {
    Persona::nombre = nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    Persona::edad = edad;
}

Persona::Persona(const string &nombre, int edad) : nombre(nombre), edad(edad) {}

Persona::~Persona() {

}

string Persona::toString() {
    stringstream s;

    s<<"Nombre: "<< this->nombre<<endl;
    s<<"Edad: "<< this->edad<<endl;

    return s.str();
}