//
// Created by Diego on 1/15/2024.
//

#include "ProductoPorUnidad.h"


float ProductoPorUnidad::calcularMontoPorPagar() {
    return (precio+ precio*impuesto) * cantidad;
}

ProductoPorUnidad::ProductoPorUnidad(const string &nombre, const string &descripcion, const string &fecha, float precio,
                                     int cantidad, float impuesto) : Producto(nombre, descripcion, fecha, precio,
                                                                              cantidad), impuesto(impuesto) {}


string ProductoPorUnidad::toString() {
    stringstream s;

    s<< Producto::toString();
    s<<"Total a pagar: "  << calcularMontoPorPagar() <<endl;

    return s.str();
}