#include <iostream> //Incluye la biblioteca de entrada y salida de datos

using namespace std; //Utiliza el espacio de nombres estándar de C++

class Padre {  //Define la clase padre en la relacion de herencia
protected:
    int atributopadre;      //Atributo de la clase padre

public:
    Padre(int valor) : atributopadre(valor) {  //Constructor con un parametro
    }
    void metodopadre() {   
        cout << "Metodo de la clase padre: " << atributopadre << endl; //Metodo que imprime el atributo de la clase padre
    }
};


class Hijo : public Padre {  //Definicion de la clase derivada en la relacion de herencia
private:
    int atributohijo;

public:
    Hijo(int valorPadre, int valorPropio) : Padre(valorPadre), atributohijo(valorPropio) {  //Constructor con 2 parametros (Inicializa el atributo heredado y su propio atributo)
    }
    ~Hijo() {           //Destructor
    }
    void metodohijo() {
        cout << "Metodo de la clase hijo: " << atributohijo << endl;  //Metodo que imprime el atributo de la clase hijo
    }
};

int main() {
    Hijo objeto(10, 20);  //Crea un objeto de la clase derivada 
    objeto.metodopadre();   // Acceder a los atributos y metodos heredados de la clase base (Padre)
    objeto.metodohijo();  // Acceder a los atributos y metodos propios de la clase derivada (Hijo)

    return 0;
}

