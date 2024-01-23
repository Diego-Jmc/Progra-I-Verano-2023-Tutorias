//
// Created by Diego on 1/22/2024.
//

#include "Fecha.h"

int Fecha::getDia() const {
    return dia;
}

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

int Fecha::getMes() const {
    return mes;
}

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

int Fecha::getAnnio() const {
    return annio;
}

void Fecha::setAnnio(int annio) {
    Fecha::annio = annio;
}

Fecha::Fecha(int dia, int mes, int annio) : dia(dia), mes(mes), annio(annio) {}

Fecha::Fecha() {}

Fecha *Fecha::parsearFechaString(string fecha) {
    stringstream s;

        s<<fecha;

        string dia,mes,annio;

        getline(s,dia,'/');
        getline(s,mes,'/');
        getline(s,annio);

        return  new Fecha(stoi(dia),
                          stoi(mes),
                          stoi(annio));

}

string Fecha::toString() {
   stringstream s;

   s<< dia << "/" << mes << "/" << annio<< endl;

   return s.str();
}
