//
// Created by Diego on 1/15/2024.
//

#ifndef SOLUCION_EXAMENII_EJERCICIO_PRODUCTOPORPESO_H
#define SOLUCION_EXAMENII_EJERCICIO_PRODUCTOPORPESO_H
#include "Producto.h"



class ProductoPorPeso : public Producto {

private:
    float impuesto;
    float descuento;
    int kilos;
public:
    float calcularMontoPorPagar() override;
    ProductoPorPeso(const string &nombre, const string &descripcion, const string &fecha, float precio, int cantidad,
                    float impuesto, float descuento, int kilos);

    string toString() override;


    float getImpuesto() const;

    void setImpuesto(float impuesto);

    float getDescuento() const;

    void setDescuento(float descuento);

    int getKilos() const;

    void setKilos(int kilos);
};


#endif //SOLUCION_EXAMENII_EJERCICIO_PRODUCTOPORPESO_H
