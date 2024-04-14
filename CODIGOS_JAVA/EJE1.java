import java.util.ArrayList; // Importa la clase ArrayList para trabajar con listas dinámicas
import java.util.List; // Importa la interfaz List para trabajar con listas

// Declaraciones adelantadas de las clases
class Autor {}
class Libro {}
class Usuario {}
// Definimos Clase Autor
class Autor {
    String nombre; // Atributo nombre de tipo string
    String nacionalidad; // Atributo nacionalidad de tipo string
    List<String> librosEscritos; // Atributo librosEscritos de tipo lista de strings

    // Constructor de la clase Autor
    Autor(String nombre, String nacionalidad) {
        this.nombre = nombre;
        this.nacionalidad = nacionalidad;
        this.librosEscritos = new ArrayList<>(); // Inicializa la lista de libros escritos
    }
}
// Definimos Clase Libro
class Libro {
    String ISBN; // Atributo ISBN de tipo string
    String titulo; // Atributo titulo de tipo string
    int anioPublicacion; // Atributo anioPublicacion de tipo entero
    int cantidadEjemplares; // Atributo cantidadEjemplares de tipo entero
    Autor autor; // Atributo autor de tipo Autor
    // Constructor de la clase Libro
    Libro(String ISBN, String titulo, int anioPublicacion, int cantidadEjemplares, Autor autor) {
        this.ISBN = ISBN;
        this.titulo = titulo;
        this.anioPublicacion = anioPublicacion;
        this.cantidadEjemplares = cantidadEjemplares;
        this.autor = autor;
    }
}
// Definimos Clase Usuario
class Usuario {
    String nombre; // Atributo nombre de tipo string
    String direccion; // Atributo direccion de tipo string
    String telefono; // Atributo telefono de tipo string
    List<Libro> librosPrestados; // Atributo librosPrestados de tipo lista de Libro
    List<String> fechasPrestamo; // Atributo fechasPrestamo de tipo lista de strings
    List<String> fechasDevolucion; // Atributo fechasDevolucion de tipo lista de strings
    // Constructor de la clase Usuario
    Usuario(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.librosPrestados = new ArrayList<>(); // Inicializa la lista de libros prestados
        this.fechasPrestamo = new ArrayList<>(); // Inicializa la lista de fechas de préstamo
        this.fechasDevolucion = new ArrayList<>(); // Inicializa la lista de fechas de devolución
    }
}
public class Eje1 {
    // Funciones para mostrar información (no es necesario definirlas en una clase separada en Java)
    static void mostrarAutor(Autor autor) {
        System.out.println("Nombre: " + autor.nombre);
        System.out.println("Nacionalidad: " + autor.nacionalidad);
        System.out.println("Libros escritos:");
        for (String libro : autor.librosEscritos) {
            System.out.println("- " + libro);
        }
    }
    static void mostrarLibro(Libro libro) {
        System.out.println("ISBN: " + libro.ISBN);
        System.out.println("Titulo: " + libro.titulo);
        System.out.println("Año de publicacion: " + libro.anioPublicacion);
        System.out.println("Cantidad de ejemplares: " + libro.cantidadEjemplares);
        mostrarAutor(libro.autor); // Muestra el libro y el autor de este
    }
    static void mostrarUsuario(Usuario usuario) {
        System.out.println("Nombre: " + usuario.nombre);
        System.out.println("Direccion: " + usuario.direccion);
        System.out.println("Telefono: " + usuario.telefono);
        System.out.println("Libros prestados:");
        for (int i = 0; i < usuario.librosPrestados.size(); i++) { // Itera sobre los libros prestados
            Libro libro = usuario.librosPrestados.get(i);
            System.out.print("- ISBN: " + libro.ISBN + ", Titulo: " + libro.titulo);
            System.out.println(", Fecha de prestamo: " + usuario.fechasPrestamo.get(i) +
                    ", Fecha de devolucion: " + usuario.fechasDevolucion.get(i));
        }
    }
    public static void main(String[] args) { // Funcion principal
        Autor autor1 = new Autor("Gabriel Garcia Marquez", "Colombiano"); // Crea un objeto de la clase Autor
        Libro libro1 = new Libro("9780060932759", "Cien años de soledad", 1967, 5, autor1); // Crea un objeto de la clase Libro
        Usuario usuario1 = new Usuario("Juan Perez", "Calle Principal 123", "555-1234"); // Crea un objeto de la clase Usuario
        usuario1.librosPrestados.add(libro1); // Agrega el libro a la lista de libros prestados del usuario
        usuario1.fechasPrestamo.add("01/04/2024"); // Agrega la fecha de préstamo del libro
        usuario1.fechasDevolucion.add("15/04/2024"); // Agrega la fecha de devolución del libro
        // Mostrar información en la consola
        mostrarAutor(autor1);
        mostrarLibro(libro1);
        mostrarUsuario(usuario1);
    }
}
