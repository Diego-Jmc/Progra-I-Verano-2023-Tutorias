//
// Created by Diego on 1/15/2024.
//

#include "Producto.h"

Producto::Producto(const string &nombre, const string &descripcion, const string &fecha, float precio, int cantidad)
        : nombre(nombre), descripcion(descripcion), fecha(fecha), precio(precio), cantidad(cantidad) {}

const string &Producto::getNombre() const {
    return nombre;
}

void Producto::setNombre(const string &nombre) {
    Producto::nombre = nombre;
}

const string &Producto::getDescripcion() const {
    return descripcion;
}

void Producto::setDescripcion(const string &descripcion) {
    Producto::descripcion = descripcion;
}

const string &Producto::getFecha() const {
    return fecha;
}

void Producto::setFecha(const string &fecha) {
    Producto::fecha = fecha;
}

float Producto::getPrecio() const {
    return precio;
}

void Producto::setPrecio(float precio) {
    Producto::precio = precio;
}

int Producto::getCantidad() const {
    return cantidad;
}

void Producto::setCantidad(int cantidad) {
    Producto::cantidad = cantidad;
}

Producto::Producto() {}


string Producto::toString() {
    stringstream s;

    s<<"Nombre: "<< getNombre() <<endl;
    s<<"Descripcion: " << getDescripcion() <<endl;
    s<<"Precio: " << getPrecio() << endl;


    return s.str();
}


