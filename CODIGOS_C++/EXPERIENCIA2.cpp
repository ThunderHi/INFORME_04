#include <iostream> // Incluye la biblioteca de entrada/salida estándar
#include <string> // Incluye la biblioteca de cadenas de caracteres

using namespace std;

class Estudiante; // Declaracion anticipada de la clase Estudiante

// Definicion de la clase Curso
class Curso {
private:
// Atributos de la clase Curso
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFinalizacion;
    Estudiante* estudiantes[100]; // Arreglo de punteros a objetos Estudiante
    int numEstudiantes;

public:
// Constructor de la clase Curso
    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFinalizacion) : nombre(nombre), codigo(codigo), descripcion(descripcion), fechaInicio(fechaInicio), fechaFinalizacion(fechaFinalizacion), numEstudiantes(0) {}

//Funcion para agregar un estudiante al curso
    void agregarEstudiante(Estudiante* estudiante);

//Funcion para eliminar un estudiante del curso
    void eliminarEstudiante(Estudiante* estudiante);

//Funcion para imprimir los detalles del curso
    void imprimirCurso();

//Funciones de acceso a los atributos
    string getNombre() const { return nombre; }
    string getCodigo() const { return codigo; }
    string getDescripcion() const { return descripcion; }
    string getFechaInicio() const { return fechaInicio; }
    string getFechaFinalizacion() const { return fechaFinalizacion; }
};

//Definicion de la clase Estudiante
class Estudiante {
private:
 //Atributos de la clase Estudiante
    string nombre;
    string apellido;
    string numIdentificacion;
    string correoElectronico;
    Curso* cursos[100]; // Arreglo de punteros a objetos Curso
    int numCursos;   //Numero de cursos en los que está inscrito el estudiante

public:

// Constructor de la clase Estudiante
    Estudiante(string nombre, string apellido, string numIdentificacion, string correoElectronico) : nombre(nombre), apellido(apellido), numIdentificacion(numIdentificacion), correoElectronico(correoElectronico), numCursos(0) {}

//Funcion para agregar un estudiante al curso
    void agregarCurso(Curso* curso);

 //Funcion para eliminar un estudiante del curso
    void eliminarCurso(Curso* curso);

//Funcion para imprimir los detalles del curso
    void imprimirEstudiante();

//Funciones de acceso a los atributos
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getNumIdentificacion() const { return numIdentificacion; }
    string getCorreoElectronico() const { return correoElectronico; }
};

//Funcion para imprimir los detalles de un curso
void imprimirDetalles(const Curso& curso) {
    cout<<"Nombre: "<<curso.getNombre()<<", Codigo: "<<curso.getCodigo()<<", Descripcion: "<<curso.getDescripcion()<<", Fecha de Inicio: "<<curso.getFechaInicio()<<", Fecha de Finalizacion: "<<curso.getFechaFinalizacion() << endl;
}

//Funcion para imprimir los detalles de un estudiante
void imprimirDetalles(const Estudiante& estudiante) {
    cout<<"Nombre: "<<estudiante.getNombre()<<", Apellido: "<<estudiante.getApellido()<<", Numero de Identificacion: "<<estudiante.getNumIdentificacion()<<", Correo Electronico: "<<estudiante.getCorreoElectronico() << endl;
}

//Implementación de la funcion agregarEstudiante
void Curso::agregarEstudiante(Estudiante* estudiante) {
    if (numEstudiantes < 100) {
        estudiantes[numEstudiantes] = estudiante;
        numEstudiantes++;
        estudiante->agregarCurso(this);
    } else {
        cout<<"No se pueden agregar mas estudiantes al curso."<<endl;
    }
}

//Implementacion de la funcion agregarEstudiante
void Curso::eliminarEstudiante(Estudiante* estudiante) {
    for (int i = 0; i < numEstudiantes; i++) {  //Se realiza un bucle "for" para recorrer el arreglo de estudiantes del curso
//Se compara cada elemento del arreglo estudiantes con el puntero al estudiante que se desea eliminar (estudiante)

//Se inicia desde la posicion "i" hasta "numEstudiantes - 1"
        if (estudiantes[i] == estudiante) {
//Se mueve el estudiante en la posición "j + 1" hacia la posición "j", sobrescribiendo así el estudiante actual (estudiantes[j]) con el siguiente estudiante (estudiantes[j + 1])
            for (int j = i; j < numEstudiantes - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            numEstudiantes--;
            estudiante->eliminarCurso(this);    //se llama al método "eliminarCurso" del estudiante (estudiante->eliminarCurso(this)), pasando el puntero al curso actual (this)
            break;  //Se rompe el bucle externo
        }
    }
}

void Curso::imprimirCurso() {
    imprimirDetalles(*this);    //imprimirDetalles(*this);: Llama a la funcion "imprimirDetalles" pasando el objeto Curso actual (*this) 
    cout<<"Estudiantes asociados:"<<endl;
    for (int i = 0; i < numEstudiantes; i++) {  //Inicia un bucle "for" que recorre el arreglo de punteros a objetos Estudiante asociados al curso
        imprimirDetalles(*estudiantes[i]);  //Dentro del bucle, llama a la funcion 
//"*" en frente de una variable o adelante siginifica como un puntero que contiene la direccion de memoria de otra variable
    }
}

void Estudiante::agregarCurso(Curso* curso) {
//"*" en frente de una variable o adelante siginifica como un puntero que contiene la direccion de memoria de otra variable
    if (numCursos < 100) {  //Verifica si el numero de cursos que el estudiante ya esta tomando (numCursos) es menor que 100
        cursos[numCursos] = curso;  //La funcion utiliza el operador [] para acceder a la posición actual en la lista (numCursos) y asignarle el valor del puntero al curso (curso)
        numCursos++;    //Incrementa el valor de numCursos para reflejar que se ha agregado un nuevo curso a la lista
    } else {
        cout<<"No se pueden agregar mas cursos al estudiante."<<endl;   //Muestra mensaje por si no se puede agregar mas estudiantes al curso
    }
}

void Estudiante::eliminarCurso(Curso* curso) {
//"*" en frente de una variable o adelante siginifica como un puntero que contiene la direccion de memoria de otra variable
    //Un bucle "for" para recorrer la lista de cursos del estudiante (cursos)
    for (int i = 0; i < numCursos; i++) {
        if (cursos[i] == curso) {
            for (int j = i; j < numCursos - 1; j++) { //utiliza otro bucle "for" para mover todos los elementos de la lista que están despues del curso que se desea eliminar
                cursos[j] = cursos[j + 1];
            }
            numCursos--; //La funcion decrementa el valor de "numCursos" para reflejar que se ha eliminado un curso
            break;
        }
    }
}

void Estudiante::imprimirEstudiante() {
    imprimirDetalles(*this);
//"*" en frente de una variable o adelante siginifica como un puntero que contiene la direccion de memoria de otra variable
    cout<<"Cursos asociados:"<<endl;
    //Un bucle "for" para recorrer la lista de cursos del estudiante (cursos)
    for (int i = 0; i < numCursos; i++) {
        imprimirDetalles(*cursos[i]); //Imprime los detalles de los cursos
    }
}

int main() {
    Curso curso1("Curso 1", "001", "Descripcion del Curso 1", "01/04/2024", "30/06/2024");
    Curso curso2("Curso 2", "002", "Descripcion del Curso 2", "15/04/2024", "15/07/2024");

    Estudiante estudiante1("Juan", "Perez", "12345", "juan@gmail.com");
    Estudiante estudiante2("Maria", "Gomez", "67890", "maria@gmail.com");

    cout<<"Cursos antes de asociar estudiantes:"<<endl;
    curso1.imprimirCurso();
    curso2.imprimirCurso();

    cout<<"\nEstudiantes antes de asociar cursos:"<<endl;
    estudiante1.imprimirEstudiante();
    estudiante2.imprimirEstudiante();
//"&" o "ampersand" se utiliza para obtener la direccion de memoria de objetos
    curso1.agregarEstudiante(&estudiante1);
    curso2.agregarEstudiante(&estudiante1);
    curso2.agregarEstudiante(&estudiante2);

    estudiante1.agregarCurso(&curso1);
    estudiante1.agregarCurso(&curso2);
    estudiante2.agregarCurso(&curso2);

    curso1.eliminarEstudiante(&estudiante1);
    estudiante1.eliminarCurso(&curso2);
//"&" o "ampersand" se utiliza para obtener la direccion de memoria de objetos
    cout<<"\nCursos despues de asociar y desasociar estudiantes:"<<endl;
    curso1.imprimirCurso();
    curso2.imprimirCurso();

    cout<<"\nEstudiantes despues de asociar y desasociar cursos:"<<endl;
    estudiante1.imprimirEstudiante();
    estudiante2.imprimirEstudiante();

    return 0;
}
