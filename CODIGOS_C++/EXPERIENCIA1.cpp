#include <iostream> //Incluye la biblioteca de entrada/salida de C++
#include <string>   //Incluye la biblioteca de cadenas de C++

using namespace std; 

//Declara la clase Hijo
class Hijo;

class Padre {
private:
    string nombre; //Atributo privado "nombre" de tipo string

    Hijo* hijos[5]; //Arreglo de objetos Hijo con tamaño máximo de 5
    //Significa que puede contener hasta 5 punteros a objetos Hijo

    int numHijos;   //Atributo privado "numHijos" de tipo entero

public:
    //Constructor con parámetro "nombre" de tipo string
    Padre(string nombre) : nombre(nombre), numHijos(0) {}

    //Metodo "get" para el atributo "nombre"
    string getNombre() {
        return nombre;
    }

    //Metodo "set" para el atributo "nombre"
    void setNombre(string nombre) {
        this->nombre = nombre;  //"this->" se usa para acceder a los miembros de un objeto dentro de un metodo de clase
    }

    //Metodo "agregarHijo" que toma un objeto "Hijo" y lo agrega al arreglo de "Hijo"
    void agregarHijo(Hijo* hijo) {
        if (numHijos < 5) {
            hijos[numHijos] = hijo;
            numHijos++;
        } else {
            cout<<"No se pueden agregar mas hijos."<<endl;
        }
    }

    //Metodo "imprimirInfo" que imprime el nombre del objeto "Padre" y la cantidad de objetos "Hijo" relacionados con él
    void imprimirInfo() {
        cout<<"Nombre del Padre: "<<nombre<<endl;
        cout<<"Numero de Hijos: "<<numHijos<<endl;
    }
};

class Hijo {
private:
    string nombre; //Atributo privado "nombre" de tipo string
public:
    //Constructor con parámetro "nombre" de tipo string
    Hijo(string nombre) : nombre(nombre) {}

    //Metodo "get" para el atributo "nombre"
    string getNombre() {
        return nombre;
    }

    //Metodo "set" para el atributo "nombre"
    void setNombre(string nombre) {
        this->nombre = nombre;  //"this->" para acceder a los miembros de un objeto dentro de un metodo de clase
    }
};

int main() {
    Padre padre("Alexander"); // Crea un objeto "Padre" con nombre "Juan"

    Hijo hijo1("Pedro"); //Crea un objeto "Hijo" con nombre "Pedro"
    Hijo hijo2("Maria"); //Crea un objeto "Hijo" con nombre "Maria"

    padre.agregarHijo(&hijo1); //Agrega el objeto "Hijo" "hijo1" al arreglo de "Hijo" del objeto "Padre" "padre"
    padre.agregarHijo(&hijo2); //Agrega el objeto "Hijo" "hijo2" al arreglo de "Hijo" del objeto "Padre" "padre"
    //"&" o "ampersand" se utiliza para obtener la direccion de memoria de objetos Hijo

    padre.imprimirInfo(); //Imprime la información del objeto "Padre" "padre"

    return 0;
}
