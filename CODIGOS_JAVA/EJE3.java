import java.util.ArrayList; // Importa la clase ArrayList para trabajar con listas dinámicas
import java.util.List; // Importa la interfaz List para trabajar con listas

class Asignatura { // Declaración de la clase Asignatura
    String codigo;
    String nombre;
    String descripcion;
    String profesor;
    // Constructor
    Asignatura(String codigo, String nombre, String descripcion, String profesor) {
        this.codigo = codigo;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.profesor = profesor;
    }
    // Función para mostrar la información de la asignatura
    void mostrarInformacion() {
        System.out.println("Asignatura: " + nombre + " (" + codigo + ")");
        System.out.println("Descripción: " + descripcion);
        System.out.println("Profesor: " + profesor);
        System.out.println();
    }
}
class Estudiante { // Declaración de la clase Estudiante
    String nombre;
    String direccion;
    String matricula;
    List<Asignatura> asignaturasMatriculadas; // Atributo asignaturasMatriculadas de tipo lista de Asignatura
    List<Integer> notas; // Atributo notas de tipo lista de enteros
    List<Integer> faltas; // Atributo faltas de tipo lista de enteros
    // Constructor
    Estudiante(String nombre, String direccion, String matricula) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.matricula = matricula;
        this.asignaturasMatriculadas = new ArrayList<>(); // Inicializa la lista de asignaturas matriculadas
        this.notas = new ArrayList<>(); // Inicializa la lista de notas
        this.faltas = new ArrayList<>(); // Inicializa la lista de faltas
    }
    // Función para matricular una asignatura a un estudiante
    void matricularAsignatura(Asignatura asignatura) {
        asignaturasMatriculadas.add(asignatura); // Añade una asignatura a la lista de asignaturas matriculadas
        notas.add(0); // Añade una nota de cero a la lista de notas
        faltas.add(0); // Añade un número de faltas de cero a la lista de faltas
    }
    // Función para registrar una nota en una asignatura
    void registrarNota(int nota, int asignaturaIndex) {
        notas.set(asignaturaIndex, nota); // Establece la nota en el índice correspondiente de la lista de notas
    }
    // Función para registrar una falta en una asignatura
    void registrarFalta(int falta, int asignaturaIndex) {
        faltas.set(asignaturaIndex, faltas.get(asignaturaIndex) + falta); // Incrementa el número de faltas en el índice correspondiente de la lista de faltas
    }
    // Función para mostrar la información del estudiante
    void mostrarInformacion() {
        System.out.println("Estudiante: " + nombre + " (" + matricula + ")");
        System.out.println("Dirección: " + direccion);
        System.out.println("Asignaturas Matriculadas:");
        for (Asignatura asignatura : asignaturasMatriculadas) {
            System.out.print("  - ");
            asignatura.mostrarInformacion(); // Muestra la información de cada asignatura matriculada por el estudiante
        }
        System.out.println();
    }
}
class Profesor { // Declaración de la clase Profesor
    String nombre;
    String direccion;
    String telefono;
    List<Asignatura> asignaturasImpartidas; // Atributo asignaturasImpartidas de tipo lista de Asignatura
    // Constructor
    Profesor(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.asignaturasImpartidas = new ArrayList<>(); // Inicializa la lista de asignaturas impartidas
    }
    // Función para mostrar la información del profesor
    void mostrarInformacion() {
        System.out.println("Profesor: " + nombre + " (" + telefono + ")");
        System.out.println("Dirección: " + direccion);
        System.out.println("Asignaturas Impartidas:");
        for (Asignatura asignatura : asignaturasImpartidas) {
            System.out.print("  - ");
            asignatura.mostrarInformacion(); // Muestra la información de cada asignatura impartida por el profesor
        }
        System.out.println();
    }
}
public class Eje3 {
    public static void main(String[] args) {
        // Crear asignaturas
        Asignatura asignatura1 = new Asignatura("A1", "Programación I", "Introducción a la programación", "Profesor Juan");
        Asignatura asignatura2 = new Asignatura("A2", "Matemáticas I", "Introducción a las matemáticas", "Profesora Maria");
        // Crear profesores
        Profesor profesor1 = new Profesor("Profesor Juan", "Dirección 1", "123456789");
        Profesor profesor2 = new Profesor("Profesora Maria", "Dirección 2", "987654321");
        // Asignar asignaturas a los profesores
        profesor1.asignaturasImpartidas.add(asignatura1);
        profesor2.asignaturasImpartidas.add(asignatura2);
        // Crear estudiantes
        Estudiante estudiante1 = new Estudiante("Estudiante Esdras", "Dirección A", "1A");
        Estudiante estudiante2 = new Estudiante("Estudiante Miguel", "Dirección B", "2B");
        // Matricular estudiantes en las asignaturas
        estudiante1.matricularAsignatura(asignatura1);
        estudiante1.matricularAsignatura(asignatura2);
        estudiante2.matricularAsignatura(asignatura1);
        estudiante2.matricularAsignatura(asignatura2);
        // Mostrar información por la terminal
        System.out.println("Información de Asignaturas:");
        asignatura1.mostrarInformacion();
        asignatura2.mostrarInformacion();
        System.out.println("Información de Profesores:");
        profesor1.mostrarInformacion();
        profesor2.mostrarInformacion();
        System.out.println("Información de Estudiantes:");
        estudiante1.mostrarInformacion();
        estudiante2.mostrarInformacion();
    }
}
