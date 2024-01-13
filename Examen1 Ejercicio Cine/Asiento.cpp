//
// Created by Diego on 1/12/2024.
//

#include "Asiento.h"

char Asiento::getFila() const {
    return fila;
}

void Asiento::setFila(char fila) {
   this->fila = fila;
}

int Asiento::getNumero() const {
    return numero;
}

void Asiento::setNumero(int numero) {
    this->numero = numero;
}

bool Asiento::isEstado() const {
    return estado;
}

void Asiento::setEstado(bool estado) {
    Asiento::estado = estado;
}

Asiento::Asiento() {}

Asiento::Asiento(char fila, int numero) : fila(fila), numero(numero), estado(true) {

}

Asiento::~Asiento() {

    this->fila=' ';
    this->numero= -1;

}

string Asiento::toString() {
    stringstream s;

    s<<"("<<numero<<","<<fila<<","<<estado<<")";

    return s.str();
}