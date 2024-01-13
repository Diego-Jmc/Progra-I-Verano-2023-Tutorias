//
// Created by Diego on 1/12/2024.
//

#ifndef EXA1_CINE_H
#define EXA1_CINE_H
#include "Asiento.h"

class Cine {

private:
    int numFilas;
    int numColumnas;
    Asiento *** m;
    int asientosDisponibles;
    int obtenerFila(char _fila);
public:
    Cine(int numFilas, int numColumnas);

    int getNumFilas() const;

    void setNumFilas(int numFilas);

    int getNumColumnas() const;

    void setNumColumnas(int numColumnas);

    int cantAsientosDisponibles();

    string toString();

    void reversar(char _fila, int _columna);

    bool buscar(char _fila, int _cantAsientos);

};


#endif //EXA1_CINE_H
