#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Persona {
public:
    Persona() : nombre(""), edad(0) {}

    Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

private:
    std::string nombre;
    int edad;
};


// Guardar varias personas
void guardarPersonas(const std::vector<Persona>& personas, const std::string& filename) {
    std::ofstream archivoSalida(filename, std::ios::binary);

    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida: " << filename << std::endl;
        // c error
        return;
    }

    int numPersonas = personas.size(); // 3
    archivoSalida.write(reinterpret_cast<const char*>(&numPersonas), sizeof(int));

    for (const Persona& persona : personas) { // foreach

        int nombreLength = persona.getNombre().length(); // tomar el tamaño del nombre en int

        archivoSalida.write(reinterpret_cast<const char*>(&nombreLength), sizeof(int));
        archivoSalida.write(persona.getNombre().c_str(), nombreLength);

        int edad = persona.getEdad();
        archivoSalida.write(reinterpret_cast<const char*>(&edad), sizeof(int));
    }

    archivoSalida.close();
}

std::vector<Persona> cargarPersonas(const std::string& filename) {
    std::vector<Persona> personas;

    std::ifstream archivoEntrada(filename, std::ios::binary);
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada: " << filename << std::endl;
        return personas;
    }

    int numPersonas;
    archivoEntrada.read(reinterpret_cast<char*>(&numPersonas), sizeof(int));

    for (int i = 0; i < numPersonas; ++i) {
        int nombreLength;
        archivoEntrada.read(reinterpret_cast<char*>(&nombreLength), sizeof(int));
        std::string nombre;
        nombre.resize(nombreLength);
        archivoEntrada.read(&nombre[0], nombreLength);
        int edad;
        archivoEntrada.read(reinterpret_cast<char*>(&edad), sizeof(int));
        personas.push_back(Persona(nombre, edad));
    }

    archivoEntrada.close();
    return personas;
}

int main() {
    Persona persona1("Juan", 30);
    Persona persona2("Maria", 25);
    Persona persona3("Carlos", 35);

    std::vector<Persona> personas = {persona1, persona2, persona3};
    guardarPersonas(personas, "personas.dat");

    std::vector<Persona> personasCargadas = cargarPersonas("personas.dat");

    for (const auto& persona : personasCargadas) {
        std::cout << "Nombre: " << persona.getNombre() << ", Edad: " << persona.getEdad() << std::endl;
    }

    return 0;
}
