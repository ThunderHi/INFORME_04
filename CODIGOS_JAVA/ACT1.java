// Importa las clases necesarias para la entrada/salida
import java.util.ArrayList; // Importa la clase ArrayList para manejar colecciones dinámicas

// Define la clase Hijo
class Hijo {
    private String nombre; // Atributo privado "nombre" de tipo String

    // Constructor que inicializa el nombre del hijo
    public Hijo(String nombre) {
        this.nombre = nombre;
    }

    // Método get para obtener el nombre del hijo
    public String getNombre() {
        return nombre;
    }

    // Método set para establecer el nombre del hijo
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

// Define la clase Padre
class Padre {
    private String nombre; // Atributo privado "nombre" de tipo String
    private ArrayList<Hijo> hijos; // Lista para almacenar objetos Hijo

    // Constructor que inicializa el nombre y la lista de hijos
    public Padre(String nombre) {
        this.nombre = nombre;
        this.hijos = new ArrayList<>();
    }

    // Método get para obtener el nombre del padre
    public String getNombre() {
        return nombre;
    }

    // Método set para establecer el nombre del padre
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    // Método para agregar un hijo al ArrayList de hijos
    public void agregarHijo(Hijo hijo) {
        if (hijos.size() < 5) { // Comprueba si hay menos de 5 hijos antes de agregar uno nuevo
            hijos.add(hijo);
        } else {
            System.out.println("No se pueden agregar más hijos.");
        }
    }

    // Método para imprimir información del padre y sus hijos
    public void imprimirInfo() {
        System.out.println("Nombre del Padre: " + nombre);
        System.out.println("Número de Hijos: " + hijos.size());
    }
}

// Clase principal para ejecutar el programa
public class Act1 {
    public static void main(String[] args) {
        Padre padre = new Padre("Alexander"); // Crea un objeto Padre

        Hijo hijo1 = new Hijo("Pedro"); // Crea un objeto Hijo
        Hijo hijo2 = new Hijo("Maria"); // Crea otro objeto Hijo

        padre.agregarHijo(hijo1); // Agrega hijo1 al Padre
        padre.agregarHijo(hijo2); // Agrega hijo2 al Padre

        padre.imprimirInfo(); // Imprime la información del Padre
    }
}
