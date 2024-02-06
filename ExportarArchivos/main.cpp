#include <iostream>
#include <fstream>
using namespace std;



// Tome en cuenta que este proyecto toma los archivos de texto de la carpeta "cmake-build-debug"
// que no se incluye en el repositorio de github , tener eso en cuenta cuando lo configure



string rutas_vector[] = {"C:/Users/Diego/Desktop/", // Cambiar por su nombre de usuario o agregar cualquier otra ruta
                         "C:/Users/Diego/"};

enum rutas{
    ESCRITORIO=0,
    MI_USUARIO = 1,
};

string crear_ruta(int route,string filename){
    return rutas_vector[route] + filename;
}


void mostrarMenu(){
    string nombre_archivo,contenido_archivo="",line;
    int ruta_seleccionada;

    while(true){

        cout<< "Digite el nombre del archivo que desea exportar" << endl;
        getline(cin,nombre_archivo);

        cout<<"A donde desea exportarlo?" <<endl;
        cout<<"(0) Escritorio" <<endl;
        cout<<"(1) Usuario" << endl;

        cin>> ruta_seleccionada;
        cin.ignore();

        ifstream copiar_contenido(nombre_archivo);

        if(copiar_contenido.is_open()){

            while(!copiar_contenido.eof()){
                getline(copiar_contenido,line);
                contenido_archivo+=line+"\n";
            }

            cout<<"Archivo exportado al escritorio" << endl;
        }else{
            cout<<"Error al abrir el archivo seleccionado"<<endl;
            break;
        }

        copiar_contenido.close();
        string destino = crear_ruta(ruta_seleccionada,"exported_file.txt");

        ofstream _export(destino);

        if(_export.is_open()){
            _export << contenido_archivo << endl;
        }else{
            cout<<"Error en la ruta de el archivo"<<endl;
            break;
        }
        _export.close();
    }
}

int main() {

    mostrarMenu();

    return 0;
}
