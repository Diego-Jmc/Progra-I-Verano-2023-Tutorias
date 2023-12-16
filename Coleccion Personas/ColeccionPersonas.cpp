//
// Created by diego on 15/12/2023.
//

#include "ColeccionPersonas.h"

ColeccionPersonas::ColeccionPersonas(int tam) {
    this->tam = tam;
    this->cant = 0;
    coleccionPersonas = new Persona[tam];
}

void ColeccionPersonas::insertar(Persona p) {
    if( tam > cant) {
        coleccionPersonas[cant++] = p;
    }else{
        cout<<"Espacio insuficiente"<<endl;
    }
}

string ColeccionPersonas::toString() {
    stringstream s;

    for(int i=0;i<cant;i++){
        s<<coleccionPersonas[i].toString()<<endl;
    }

    return s.str();

}

Persona ColeccionPersonas::obtenerMasViejo() {

    Persona p("Aux",0);

    for(int i=0;i<cant;i++){
        if(coleccionPersonas[i].getEdad() > p.getEdad() ){
            p = coleccionPersonas[i];
        }
    }

    return p;
}

ColeccionPersonas::~ColeccionPersonas(){
        delete coleccionPersonas;
}
