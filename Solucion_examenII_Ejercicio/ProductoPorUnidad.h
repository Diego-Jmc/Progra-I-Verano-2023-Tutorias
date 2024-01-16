//
// Created by Diego on 1/15/2024.
//

#ifndef SOLUCION_EXAMENII_EJERCICIO_PRODUCTOPORUNIDAD_H
#define SOLUCION_EXAMENII_EJERCICIO_PRODUCTOPORUNIDAD_H
#include "Producto.h"

class ProductoPorUnidad : public Producto {

private:
    float impuesto;

public:
    float calcularMontoPorPagar() override; // override es una guia visual
    ProductoPorUnidad(const string &nombre, const string &descripcion, const string &fecha, float precio, int cantidad,
                      float impuesto);

    string toString() override;
};


#endif //SOLUCION_EXAMENII_EJERCICIO_PRODUCTOPORUNIDAD_H
