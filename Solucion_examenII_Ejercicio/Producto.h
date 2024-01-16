//
// Created by Diego on 1/15/2024.
//

#ifndef SOLUCION_EXAMENII_EJERCICIO_PRODUCTO_H
#define SOLUCION_EXAMENII_EJERCICIO_PRODUCTO_H
#include <iostream>
#include <sstream>

using namespace  std;

class Producto {

protected:
    string nombre;
    string descripcion;
    string fecha; // utilizar algun objeto
    float precio;
    int cantidad;
public:

    Producto(const string &nombre, const string &descripcion, const string &fecha, float precio, int cantidad);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getDescripcion() const;

    void setDescripcion(const string &descripcion);

    const string &getFecha() const;

    void setFecha(const string &fecha);

    float getPrecio() const;

    void setPrecio(float precio);

    int getCantidad() const;

    void setCantidad(int cantidad);

    Producto();

    virtual string toString();

    virtual float calcularMontoPorPagar() = 0; // Metodo virtual

};


#endif //SOLUCION_EXAMENII_EJERCICIO_PRODUCTO_H
