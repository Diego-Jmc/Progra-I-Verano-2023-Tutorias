//
// Created by Diego on 2/2/2024.
//

#ifndef INTERFACES_CLASESABSTRACTAS_FIGURA_H
#define INTERFACES_CLASESABSTRACTAS_FIGURA_H
#include <iostream>
using namespace std;

class Figura {
public:
    Figura();
    virtual float calcularArea() = 0; // esto convierte a esta clase en una clase abstracta
protected:
    float area;

};


#endif //INTERFACES_CLASESABSTRACTAS_FIGURA_H
