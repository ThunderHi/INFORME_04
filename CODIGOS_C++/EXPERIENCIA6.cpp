#include <iostream> //Incluye la biblioteca de entrada y salida de datos

using namespace std; //Utiliza el espacio de nombres estándar de C++

class ObjetoCompuesto {  //Clase del objeto que se compone
private:
    int atributo;

public:
    ObjetoCompuesto(int valor) : atributo(valor) {} //Constructor con 1 parametro

    int getAtributo() {
        return atributo;
    }

    void setAtributo(int valor) {
        atributo = valor;
    }
};

class Base {    //Clase base que representa la entidad principal en la relacion de composicion
private:
    ObjetoCompuesto* objetoCompuesto;   //Atributo que representa el objeto compuesto

public:
    Base(ObjetoCompuesto* compuesto) : objetoCompuesto(compuesto) {}    // Constructor con un puntero a un objeto de la clase ObjetoCompuesto

    ObjetoCompuesto& getObjetoCompuesto() { // Método para acceder al objeto compuesto

        return *objetoCompuesto;    //Devuelve una referencia al objeto correspondiente
    }
    void modificaratributo(int valor) {    // Metodo para modificar el atributo del objeto compuesto
        objetoCompuesto->setAtributo(valor);
    }
    void eliminarobjeto() {                // Metodo para eliminar el objeto compuesto
        delete objetoCompuesto;
    }
    ~Base() {           //Destructor
        delete objetoCompuesto;
    }
};

int main() {
    ObjetoCompuesto* objeto = new ObjetoCompuesto(10); //Se declara un puntero: "objeto" de tipo ObjetoCompuesto y un objeto de la clase ObjetoCompuesto
    Base base(objeto);                         //Se crea un objeto de la clase Base que usa el puntero objeto como argumento al constructor de Base

    ObjetoCompuesto& compuesto = base.getObjetoCompuesto(); //Devuelve una referencia al objeto ObjetoCompuesto contenido en la clase Base
    compuesto.setAtributo(20);                 //Se establece el atributo 20
    cout << "Atributo del objeto: " << compuesto.getAtributo() << endl;

    base.modificaratributo(30);                 //Modificar el atributo del objeto
    cout << "Atributo del objeto modificado: " << compuesto.getAtributo() << endl;

    base.eliminarobjeto();                      //Eliminar el objeto
    return 0;
}

