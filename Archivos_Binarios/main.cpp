#include <iostream>
#include <fstream>
#include <vector>

// cout , string y end





struct Datos {
    int numero;
    float valor;
};

void mostrar(){
   std :: cout << "Hola mundo" << std:: endl;
}

int main() {

    std::vector<Datos> listaDatos = {{10, 3.14f}
    , {20, 6.28f},
    {30, 9.42f},
    {-2,9.5f}
    };

    std::ofstream archivoSalida("datos.bin", std::ios::binary);

    if (archivoSalida.is_open()) {
        int numElementos = listaDatos.size(); // 3
        archivoSalida.write(reinterpret_cast<char*>(&numElementos), sizeof(int));

        for (const Datos& datos : listaDatos) {
            archivoSalida.write(reinterpret_cast<const char*>(&datos), sizeof(Datos));
        }

        archivoSalida.close();
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::ifstream archivoEntrada("datos.bin", std::ios::binary);

    if (archivoEntrada.is_open()) {

        int numElementos;
        archivoEntrada.read(reinterpret_cast<char*>(&numElementos), sizeof(int));

        for (int i = 0; i < numElementos; ++i) {
            Datos datosLeidos;
            archivoEntrada.read(reinterpret_cast<char*>(&datosLeidos), sizeof(Datos));
            std::cout << "Numero: " << datosLeidos.numero << ", Valor: " << datosLeidos.valor << std::endl;
        }

        archivoEntrada.close();
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    return 0;
}
