#include <iostream> //Incluye la biblioteca de entrada y salida de datos
#include <string>   //Incluye la biblioteca de cadenas de texto

using namespace std; //Utiliza el espacio de nombres estándar de C++

const int MAX_SIZE = 10; //Define la constante MAX_SIZE con un valor de 10

class Trabajador { //Define la clase Trabajador
protected:
    string nombre;   
    int codigo;      
    Trabajador* companeros[MAX_SIZE]; //Arreglo de punteros a objetos de la clase Trabajador
    int numCompaneros; //Atributo numCompaneros de tipo entero

public:
    Trabajador(string nombre, int codigo) : nombre(nombre), codigo(codigo), numCompaneros(0) {} //Constructor con dos parámetros

    Trabajador() : nombre(""), codigo(0), numCompaneros(0) {} //Constructor sin parámetros

    void agregarCompanero(Trabajador* trabajador) { //Metodo para agregar un compañero
        if (numCompaneros < MAX_SIZE) {
            companeros[numCompaneros++] = trabajador; //Asigna el puntero trabajador al elemento del arreglo compañeros en la posicion numCompaneros
        } else {
            cout<<"No se puede agregar mas compañeros. Se alcanza el limite maximo."<<endl;
        }
    }

    void mostrarCompaneros() { //Metodo para mostrar los compañeros
        cout<<"Companeros de "<<nombre<<":"<<endl;
        for (int i = 0; i < numCompaneros; i++) {   //Bucle "for" que itera desde 0 hasta numCompaneros (numero de compañeros)
            cout<<"- "<<companeros[i]->nombre<<endl; //Dentro del bucle, se imprime un guion "-", seguido del nombre del compañero en la posicion "i" de la lista companeros
        }
    }

    string getNombre() { return nombre; } //Metodo para obtener el nombre
};

class Gerente : public Trabajador { //Define la clase Gerente que hereda de la clase Trabajador
private:
    Trabajador trabajadores[MAX_SIZE]; //Arreglo de objetos de la clase Trabajador
    int numTrabajadores; //Atributo numTrabajadores de tipo entero

public:
    Gerente(string nombre, int codigo) : Trabajador(nombre, codigo), numTrabajadores(0) {} //Constructor con dos parametros

    void agregarTrabajador(Trabajador* trabajador) { //Metodo para agregar un trabajador
        if (numTrabajadores < MAX_SIZE) { //Condicion que verifica si el numero de trabajadores actual (numTrabajadores) es menor que el tamaño maximo permitido (MAX_SIZE)
        //El operador de desreferenciación (*) para acceder al objeto Trabajador al que apunta el puntero trabajador
            trabajadores[numTrabajadores++] = *trabajador; //Si la condicion se cumple, se agrega el nuevo trabajador a la lista trabajadores en la posicióon numTrabajadores
        } else {
            cout<<"No se puede agregar mas trabajadores. Se alcanzo el limite maximo."<<endl;
        }
    }

    void mostrarTrabajadores() { //Metodo para mostrar los trabajadores
        cout<<"Trabajadores a cargo del gerente "<<nombre<<":"<<endl;
        for (int i = 0; i < numTrabajadores; i++) { //Bucle "for" que itera desde 0 hasta numCompaneros (numero de compañeros)
            cout<<"- "<<trabajadores[i].getNombre() << endl; //Usa getNombre() en lugar de nombre
        }
    }
};

int main() { // Función principal
    Trabajador trabajadores[MAX_SIZE] = { //Inicializa el arreglo de objetos de la clase Trabajador
        Trabajador("Juan Perez", 1234),
        Trabajador("Maria Lopez", 5678),
        Trabajador("Pedro Martinez", 9876)
    };

    Gerente gerente1("Ana Garcia", 4321); //Crea un objeto de la clase Gerente
     //"&" o "ampersand" se utiliza para obtener la direccion de memoria de objetos
    gerente1.agregarTrabajador(&trabajadores[0]); //Agrega un trabajador al gerente
    gerente1.agregarTrabajador(&trabajadores[1]); //Agrega un trabajador al gerente
    gerente1.agregarTrabajador(&trabajadores[2]); //Agrega un trabajador al gerente
   
    trabajadores[0].agregarCompanero(&trabajadores[1]); //Agrega un compañero a un trabajador
    trabajadores[0].agregarCompanero(&trabajadores[2]); //Agrega un compañero a un trabajador
    trabajadores[1].agregarCompanero(&trabajadores[0]); //Agrega un compañero a un trabajador
    trabajadores[1].agregarCompanero(&trabajadores[2]); //Agrega un compañero a un trabajador
    trabajadores[2].agregarCompanero(&trabajadores[0]); //Agrega un compañero a un trabajador
    trabajadores[2].agregarCompanero(&trabajadores[1]); //Agrega un compañero a un trabajador

    cout<<"Gerente: "<<gerente1.getNombre()<<endl; //Muestra el nombre del gerente
    gerente1.mostrarTrabajadores(); //Muestra los trabajadores del gerente
    cout<<endl;

    cout<<"Trabajador: "<<trabajadores[0].getNombre()<<endl; //Muestra el nombre del trabajador
    trabajadores[0].mostrarCompaneros(); //Muestra los compañeros del trabajador
    cout << endl;

    return 0; //Finaliza la funcion principal
}
