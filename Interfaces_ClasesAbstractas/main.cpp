#include "Figura.h"
#include <math.h>
#include <list>

/*
  La idea de tener interfaces es lograr polimorfismo
  osea tener una interfaz común va a permitir a las
  instancias de varios objetos ser tratados de igual manera
  sin necesidad de conocer su implementación

 */

// hacemos que circulo implemente figura

class Circulo: public Figura{

private:
    float radio;

public:

    virtual float calcularArea() override {
        return M_PI * pow(radio,2);
    }

    Circulo(float _radio){
        this->radio = _radio;

    }

};

class Triangulo : public  Figura{

private:
    float base;
    float altura;

public:
    Triangulo(float _base,float _altura){
        this->base = _base;
        this->altura = _altura;
    }

    virtual float calcularArea() override {
        return (base*altura) / 2;
    }

};

int main() {

    auto  listaFiguras = new list<Figura*>();

    listaFiguras->push_back(new Circulo(3.1));
    listaFiguras->push_back(new Triangulo(10,22));
    listaFiguras->push_back(new Circulo(8.12));


    for(auto &figura : * listaFiguras){
        cout << figura -> calcularArea() << endl;
    }



    return 0;
}
