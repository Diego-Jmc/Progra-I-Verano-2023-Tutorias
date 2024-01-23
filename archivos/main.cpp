#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include "Fecha.h"

using namespace std;

class Persona{
private:
    string nombre;
    int edad;
    bool esta_Casado;
    Fecha *f;
public:

    Persona(const string &nombre, int edad, bool estaCasado, Fecha *f) : nombre(nombre), edad(edad),
                                                                         esta_Casado(estaCasado), f(f) {}

    Fecha *getF() const {
        return f;
    }

    void setF(Fecha *f) {
        Persona::f = f;
    }

    Persona() {}

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Persona::nombre = nombre;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int edad) {
        Persona::edad = edad;
    }

    bool isEstaCasado() const {
        return esta_Casado;
    }

    void setEstaCasado(bool estaCasado) {
        esta_Casado = estaCasado;
    }

    string toString (){
        stringstream s;
        s<< "Nombre: "<< nombre << endl;
        s<< "Edad: "<< edad << endl;
        s<< "Casdo: "<< esta_Casado << endl;
        s<< "Fecha de nacimiento: " << f->toString() << endl;

        return s.str();
    }

};


bool estaVacio(string filename){
    ifstream file(filename);

    string line;
    getline(file,line);

    return line.empty();

}

void guardarPersona(Persona *p,string filename){
    ofstream file(filename,ios::app);

    if(file.is_open()){

        if(!estaVacio(filename)){
            file<<endl;
        }

        file<<"Nombre:"<<p->getNombre()<<endl;
        file<<"Edad:"<<p->getEdad()<<endl;
        file<<"Casado:"<<p->isEstaCasado();

    }

    file.close();

}

list<Persona*> * getPersonasFromArchivo(string filename){

    auto listaPersonas = new list<Persona*>();

    ifstream file(filename); // abrimos el archivo de texto en modo lectura
    stringstream s;


    string nombre,edad,casado,line,aux,fecha;


    if(file.is_open()){

        while(!file.eof()){ // eof = hasta que llegue al final

            getline(file,line,':'); //
            getline(file,line);

            nombre = line;

            getline(file,line,':'); //
            getline(file,line);

            edad = line;

            getline(file,line,':'); //
            getline(file,line);

            casado = line;


            // en este punto ya tenemos los atributos del obejeto

            getline(file,fecha);


            Persona *p = new Persona(nombre, stoi(edad), stoi(casado), Fecha::parsearFechaString(fecha));

            listaPersonas->push_back(p);

        }

    }


    file.close();


   return listaPersonas;
}


int main() {

   auto listaPersonas = getPersonasFromArchivo("personas.txt");

    for ( auto &persona : *listaPersonas){
        cout<< persona->toString() <<endl;
    }

    return 0;
}
