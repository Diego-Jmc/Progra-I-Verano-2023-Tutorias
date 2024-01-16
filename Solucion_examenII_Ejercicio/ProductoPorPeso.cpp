//
// Created by Diego on 1/15/2024.
//

#include "ProductoPorPeso.h"

float ProductoPorPeso::calcularMontoPorPagar() {

    float monto = (kilos * precio);

    if(kilos > 10){

        monto = (monto + monto*descuento);
        monto = (monto + monto*impuesto) * cantidad;
        return monto;
    }

   return (monto + monto*impuesto) * cantidad;


}



ProductoPorPeso::ProductoPorPeso(const string &nombre, const string &descripcion, const string &fecha, float precio,
                                 int cantidad, float impuesto, float descuento, int kilos) : Producto(nombre,
                                                                                                      descripcion,
                                                                                                      fecha, precio,
                                                                                                      cantidad),
                                                                                             impuesto(impuesto),
                                                                                             descuento(descuento),
                                                                                             kilos(kilos) {}

float ProductoPorPeso::getImpuesto() const {
    return impuesto;
}

void ProductoPorPeso::setImpuesto(float impuesto) {
    ProductoPorPeso::impuesto = impuesto;
}

float ProductoPorPeso::getDescuento() const {
    return descuento;
}

void ProductoPorPeso::setDescuento(float descuento) {
    ProductoPorPeso::descuento = descuento;
}

int ProductoPorPeso::getKilos() const {
    return kilos;
}

void ProductoPorPeso::setKilos(int kilos) {
    ProductoPorPeso::kilos = kilos;
}

string ProductoPorPeso::toString() {
    stringstream s;

    s<< Producto::toString(); // llamar al metodo toString del padre
    s<< "Precio a pagar: " << calcularMontoPorPagar();

    return s.str();
}
