import java.util.ArrayList; // Importa la clase ArrayList para manejar colecciones dinámicas

// Definición de la clase Curso
class Curso {
    private String nombre;
    private String codigo;
    private String descripcion;
    private String fechaInicio;
    private String fechaFinalizacion;
    private ArrayList<Estudiante> estudiantes; // ArrayList para almacenar objetos Estudiante

    // Constructor de la clase Curso
    public Curso(String nombre, String codigo, String descripcion, String fechaInicio, String fechaFinalizacion) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.fechaInicio = fechaInicio;
        this.fechaFinalizacion = fechaFinalizacion;
        this.estudiantes = new ArrayList<>(); // Inicializa el ArrayList de estudiantes
    }

    // Método para agregar un estudiante al curso
    public void agregarEstudiante(Estudiante estudiante) {
        if (estudiantes.size() < 100) { // Verifica si hay menos de 100 estudiantes antes de agregar uno nuevo
            estudiantes.add(estudiante);
            estudiante.agregarCurso(this); // Agrega este curso al estudiante
        } else {
            System.out.println("No se pueden agregar más estudiantes al curso.");
        }
    }

    // Método para eliminar un estudiante del curso
    public void eliminarEstudiante(Estudiante estudiante) {
        if (estudiantes.remove(estudiante)) { // Elimina al estudiante del ArrayList
            estudiante.eliminarCurso(this); // Elimina este curso del estudiante
        }
    }

    // Método para imprimir los detalles del curso
    public void imprimirCurso() {
        System.out.println("Nombre: " + nombre + ", Código: " + codigo + ", Descripción: " + descripcion +
                ", Fecha de Inicio: " + fechaInicio + ", Fecha de Finalización: " + fechaFinalizacion);
        System.out.println("Estudiantes asociados:");
        for (Estudiante estudiante : estudiantes) { // Recorre el ArrayList de estudiantes
            estudiante.imprimirEstudiante(); // Imprime los detalles de cada estudiante asociado al curso
        }
    }

    // Métodos de acceso a los atributos
    public String getNombre() {
        return nombre;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public String getFechaInicio() {
        return fechaInicio;
    }

    public String getFechaFinalizacion() {
        return fechaFinalizacion;
    }
}

// Definición de la clase Estudiante
class Estudiante {
    private String nombre;
    private String apellido;
    private String numIdentificacion;
    private String correoElectronico;
    private ArrayList<Curso> cursos; // ArrayList para almacenar objetos Curso

    // Constructor de la clase Estudiante
    public Estudiante(String nombre, String apellido, String numIdentificacion, String correoElectronico) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.numIdentificacion = numIdentificacion;
        this.correoElectronico = correoElectronico;
        this.cursos = new ArrayList<>(); // Inicializa el ArrayList de cursos
    }

    // Método para agregar un curso al estudiante
    public void agregarCurso(Curso curso) {
        if (cursos.size() < 100) { // Verifica si hay menos de 100 cursos antes de agregar uno nuevo
            cursos.add(curso);
        } else {
            System.out.println("No se pueden agregar más cursos al estudiante.");
        }
    }

    // Método para eliminar un curso del estudiante
    public void eliminarCurso(Curso curso) {
        cursos.remove(curso); // Elimina el curso del ArrayList
    }

    // Método para imprimir los detalles del estudiante
    public void imprimirEstudiante() {
        System.out.println("Nombre: " + nombre + ", Apellido: " + apellido + ", Número de Identificación: " +
                numIdentificacion + ", Correo Electrónico: " + correoElectronico);
    }

    // Métodos de acceso a los atributos
    public String getNombre() {
        return nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public String getNumIdentificacion() {
        return numIdentificacion;
    }

    public String getCorreoElectronico() {
        return correoElectronico;
    }
}

public class Act2 {
    public static void main(String[] args) {
        Curso curso1 = new Curso("Curso 1", "001", "Descripción del Curso 1", "01/04/2024", "30/06/2024");
        Curso curso2 = new Curso("Curso 2", "002", "Descripción del Curso 2", "15/04/2024", "15/07/2024");

        Estudiante estudiante1 = new Estudiante("Juan", "Perez", "12345", "juan@gmail.com");
        Estudiante estudiante2 = new Estudiante("Maria", "Gomez", "67890", "maria@gmail.com");

        System.out.println("Cursos antes de asociar estudiantes:");
        curso1.imprimirCurso();
        curso2.imprimirCurso();

        System.out.println("\nEstudiantes antes de asociar cursos:");
        estudiante1.imprimirEstudiante();
        estudiante2.imprimirEstudiante();

        curso1.agregarEstudiante(estudiante1);
        curso2.agregarEstudiante(estudiante1);
        curso2.agregarEstudiante(estudiante2);

        estudiante1.agregarCurso(curso1);
        estudiante1.agregarCurso(curso2);
        estudiante2.agregarCurso(curso2);

        curso1.eliminarEstudiante(estudiante1);
        estudiante1.eliminarCurso(curso2);

        System.out.println("\nCursos después de asociar y desasociar estudiantes:");
        curso1.imprimirCurso();
        curso2.imprimirCurso();

        System.out.println("\nEstudiantes después de asociar y desasociar cursos:");
        estudiante1.imprimirEstudiante();
        estudiante2.imprimirEstudiante();
    }
}
