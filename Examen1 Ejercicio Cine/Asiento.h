//
// Created by Diego on 1/12/2024.
//

#ifndef EXA1_ASIENTO_H
#define EXA1_ASIENTO_H
#include <iostream>
#include <sstream>

using namespace std;

class Asiento {

private:
    char fila;
    int numero;
    bool estado;
public:

    Asiento();

    Asiento(char fila, int numero);

    virtual ~Asiento();

    char getFila() const;

    void setFila(char fila);

    int getNumero() const;

    void setNumero(int numero);

    bool isEstado() const;

    void setEstado(bool estado);

    string toString();
};


#endif //EXA1_ASIENTO_H
