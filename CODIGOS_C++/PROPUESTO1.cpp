#include <iostream> //Incluye la biblioteca de entrada y salida de datos
#include <string>   //Incluye la biblioteca de cadenas de texto
#include <vector>   //Incluye la biblioteca de vectores

using namespace std;

//Declaraciones adelantadas de las clases
class Autor;
class Libro;
class Usuario;

//Funciones para mostrar información
void mostrarAutor(Autor autor);
void mostrarLibro(Libro libro);
void mostrarUsuario(Usuario usuario);

//Definimos Clase Autor
class Autor {
public:
    string nombre;   //Atributo nombre de tipo string
    string nacionalidad; //Atributo nacionalidad de tipo string
    vector<string> librosEscritos; //Atributo librosEscritos de tipo vector de strings
    //Constructor de la clase Autor
    Autor(string nombre, string nacionalidad) 
        : nombre(nombre), nacionalidad(nacionalidad) {}
};

//Definimos Clase Libro
class Libro {
public:
    string ISBN;     //Atributo ISBN de tipo string
    string titulo;   //Atributo titulo de tipo string
    int anioPublicacion; //Atributo anioPublicacion de tipo entero
    int cantidadEjemplares; //Atributo cantidadEjemplares de tipo entero
    Autor* autor; //Atributo autor de tipo puntero a la clase Autor

    //Constructor de la clase Libro
    Libro(string ISBN, string titulo, int anioPublicacion, int cantidadEjemplares, Autor* autor) 
        : ISBN(ISBN), titulo(titulo), anioPublicacion(anioPublicacion), cantidadEjemplares(cantidadEjemplares), autor(autor) {}
};

//Definimos Clase Usuario
class Usuario {
public:
    string nombre;   //Atributo nombre de tipo string
    string direccion; //Atributo direccion de tipo string
    string telefono;  //Atributo telefono de tipo string
    vector<Libro*> librosPrestados; //Atributo librosPrestados de tipo vector de punteros a la clase Libro
    vector<string> fechasPrestamo; //Atributo fechasPrestamo de tipo vector de strings
    vector<string> fechasDevolucion; //Atributo fechasDevolucion de tipo vector de strings

    //Constructor de la clase Usuario
    Usuario(string nombre, string direccion, string telefono) 
        : nombre(nombre), direccion(direccion), telefono(telefono) {}
};

//Funcion para mostrar información de un autor
void mostrarAutor(Autor autor) {
    cout<<"Nombre: "<<autor.nombre<<endl;
    cout<<"Nacionalidad: "<<autor.nacionalidad<<endl;
    cout<<"Libros escritos:"<<endl;
    for (string libro : autor.librosEscritos) {
        cout<<"- "<<libro<<endl;
    }
}

//Funcion para mostrar información de un libro
void mostrarLibro(Libro libro) {
    cout<<"ISBN: "<<libro.ISBN<<endl;
    cout<<"Titulo: "<<libro.titulo<<endl;
    cout<<"Year de publicacion: "<<libro.anioPublicacion<<endl;
    cout<<"Cantidad de ejemplares: "<<libro.cantidadEjemplares<<endl;
    mostrarAutor(*libro.autor); //Muestra el libro y el autor de este
}

//Funcion para mostrar información de un usuario
void mostrarUsuario(Usuario usuario) {
    cout<<"Nombre: "<<usuario.nombre<<endl;
    cout<<"Direccion: "<<usuario.direccion<<endl;
    cout<<"Telefono: "<<usuario.telefono <<endl;
    cout<<"Libros prestados:"<<endl;
    //Recorre cada elemento del vector librosPrestados del objeto usuario, permitiendo acceder a cada libro prestado por el usuario durante la iteracion del bucle
    for (int i = 0; i < usuario.librosPrestados.size(); i++) { //Comentario de la linea "80"
    //Nota: ".size" es un metodo de la clase vector en C++, que devuelve el número de elementos actualmente almacenados en el vector
        Libro* libro = usuario.librosPrestados[i];
        //"*" es puntero al atributo de la clase
        cout<<"- ISBN: "<<libro->ISBN<<", Titulo: "<<libro->titulo;
        cout<<", Fecha de prestamo: "<<usuario.fechasPrestamo[i];
        cout<<", Fecha de devolucion: "<<usuario.fechasDevolucion[i]<<endl;
    }
}

int main() { //Funcion principal
    Autor autor1("Gabriel Garcia Marquez", "Colombiano"); //Crea un objeto de la clase Autor
    //"&" o "ampersand" se utiliza para obtener la direccion de memoria de objetos
    Libro libro1("9780060932759", "Cien years de soledad", 1967, 5, &autor1); //Crea un objeto de la clase Libro

    Usuario usuario1("Juan Perez", "Calle Principal 123", "555-1234"); //Crea un objeto de la clase Usuario

    //Nota: ".pushbck" envia un objeto al vector en orden como si de una lista se tratase
    usuario1.librosPrestados.push_back(&libro1); //Agrega el libro a la lista de libros prestados del usuario
    usuario1.fechasPrestamo.push_back("01/04/2024"); //Agrega la fecha de préstamo del libro
    usuario1.fechasDevolucion.push_back("15/04/2024"); //Agrega la fecha de devolución del libro

    //Mostrar informacion en la consola
    mostrarAutor(autor1);
    mostrarLibro(libro1);
    mostrarUsuario(usuario1);

    return 0;
}
