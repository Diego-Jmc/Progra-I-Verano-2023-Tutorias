//
// Created by Diego on 1/12/2024.
//

#include "Cine.h"

int Cine::getNumFilas() const {
    return numFilas;
}

void Cine::setNumFilas(int numFilas) {
    Cine::numFilas = numFilas;
}

int Cine::getNumColumnas() const {
    return numColumnas;
}

void Cine::setNumColumnas(int numColumnas) {
    Cine::numColumnas = numColumnas;
}

Cine::Cine(int numFilas, int numColumnas){

    this->numFilas = numFilas;
    this->numColumnas = numColumnas;

    m = new Asiento ** [numFilas];

    for(int i=0;i<numFilas;i++){
        m[i] = new Asiento * [numColumnas];
    }

    char abecedario[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};

    int contador = 1;

    for(int i=0;i<numFilas;i++){
        for(int j = 0; j<numColumnas;j++){
            m[i][j] = new Asiento();
            m[i][j]->setFila(abecedario[i]);
            m[i][j]->setNumero(contador);
            m[i][j]->setEstado(true);
            contador++;
        }
    }

    asientosDisponibles = numFilas*numColumnas;
}

int Cine::cantAsientosDisponibles() {
    return asientosDisponibles;
}

string Cine::toString() {
    stringstream s;

    for(int i=0;i<numFilas;i++){
        for(int j=0;j<numColumnas;j++){
            s<<m[i][j]->toString()<<"  ";
        }

        s<<endl;
    }

    return s.str();
}


void Cine::reversar(char _fila, int _columna) {

    int fila = obtenerFila(_fila);

    if(fila != -1 && m[fila][_columna]){ // si la fila ingresada existe y si el asiento estaba libre
       m[fila][_columna]->setEstado(false);
       asientosDisponibles--;
    } // si la fila existe

}

int Cine::obtenerFila(char _fila) {
    char abecedario[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};

    int fila = -1;
    for(int i=0;i<26;i++){
        if(_fila == abecedario[i]){
            fila = i;
        }
    }

    return fila;
}


bool Cine::buscar(char _fila, int _cantAsientos) {

    int fila = obtenerFila(_fila);

    int cantAsientosDisponibles = 0;

    if(fila != -1){

        for(int i=0;i<numColumnas;i++){
            if(m[fila][i]->isEstado()){
                cantAsientosDisponibles++;
            }
        }

    }

    return cantAsientosDisponibles <= _cantAsientos;

}