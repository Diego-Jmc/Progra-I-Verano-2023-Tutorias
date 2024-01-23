//
// Created by Diego on 1/22/2024.
//

#ifndef ARCHIVOS_FECHA_H
#define ARCHIVOS_FECHA_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fecha {

private:
    int dia;
    int mes;
    int annio;
public:


    Fecha(int dia, int mes, int annio);

    static Fecha * parsearFechaString(string fecha);

    Fecha();

    int getDia() const;

    void setDia(int dia);

    int getMes() const;

    void setMes(int mes);

    int getAnnio() const;

    void setAnnio(int annio);

    string toString();
};


#endif //ARCHIVOS_FECHA_H
