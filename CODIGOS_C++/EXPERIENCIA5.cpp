#include <iostream> //Incluye la biblioteca de entrada y salida de datos
#include <string>   //Incluye la biblioteca de cadenas de texto
#include <vector>   //Incluye la biblioteca de vectores

using namespace std;//Utiliza el espacio de nombres estándar de C++

class Objeto {      //Define la clase para los objetos que se agregaran a la coleccion
private:
    int identificador;
    string atributo;

public:
    Objeto(int id, string attr) : identificador(id), atributo(attr) {}  //Constructor con dos parametros

    int getIdentificador() const {     //Metodo que devuelve el identificador de un objeto
        return identificador;
    }

    string getAtributo() const {       //Metodo que devuelve el atributo de un objeto
        return atributo;
    }

    void setAtributo(string attr) {    //Metodo para establecer el atributo del objeto en una variable
        atributo = attr;
    }

};

class EntidadPrincipal {    //Clase base: Entidad principal en la relacion de agregacion 
private:
    vector<Objeto> coleccion;   //Vector que representa la coleccion en la que se agregaran los objetos

public:
    void agregarObjeto(const Objeto& objeto) {     //Metodo para agregar un objeto a la coleccion de objetos
        coleccion.push_back(objeto);
    }

    void eliminarObjeto(const Objeto& objeto) {     //Metodo que recibe un objeto y lo ubica en el arreglo mediante su identificador
    for (size_t i = 0; i < coleccion.size(); ++i) {
        if (coleccion[i].getIdentificador() == objeto.getIdentificador()) {
            coleccion.erase(coleccion.begin() + i);     //Luego de ubicar el objeto, este se elimina de la coleccion de objetos
            return;
        }
    }
        cout << "El objeto no está en la colección." << endl;   //Si no se encuentra el objeto en la coleccion de objetos
    }

    Objeto* obtenerObjeto(int identificador) {      //Metodo en el que se ingresa un identificador y devuelve el objeto correspondiente
        for (auto& obj : coleccion) {
            if (obj.getIdentificador() == identificador) {
                return &obj;
            }
        }
    }

    vector<Objeto>& getColeccion() {    //Metodo que devuelve una referencia a la coleccion de objetos
        return coleccion;
    }
};

int main() {
    EntidadPrincipal entidadPrincipal;

    // Crear varios objetos de la clase que se agregarán a la colección
    Objeto objeto1(1, "Atributo 1");
    Objeto objeto2(2, "Atributo 2");
    Objeto objeto3(3, "Atributo 3");

    // Agregar los objetos a la colección
    entidadPrincipal.agregarObjeto(objeto1);
    entidadPrincipal.agregarObjeto(objeto2);
    entidadPrincipal.agregarObjeto(objeto3);

    // Obtener un objeto específico de la colección mediante su identificador
    Objeto* objeto = entidadPrincipal.obtenerObjeto(2);
    if (objeto) {
        cout << "Identificador: " << objeto->getIdentificador() << ", Atributo: "<<objeto->getAtributo() << endl;
    }

    // Eliminar un objeto de la colección
    entidadPrincipal.eliminarObjeto(objeto3);
    cout << "Objeto eliminado." << endl;

    // Verificar los objetos en la colección después de eliminar uno
    cout << "Objetos en la coleccion despues de eliminar:" << endl;
    for (const auto& obj : entidadPrincipal.getColeccion()) {
        cout << "Identificador: " << obj.getIdentificador() << ", Atributo: " << obj.getAtributo() << endl;    }

    return 0;
}

