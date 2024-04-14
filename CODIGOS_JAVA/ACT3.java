// Se importa la clase Scanner para la entrada de datos desde la consola
import java.util.Scanner;

// Se define la clase Estudiante con sus atributos y métodos
class Estudiante {
    private String nombre;
    private int codigo;

    // Constructor de la clase Estudiante
    public Estudiante(String nombre, int codigo) {
        this.nombre = nombre;
        this.codigo = codigo;
    }

    // Método para obtener el nombre del estudiante
    public String getNombre() {
        return nombre;
    }

    // Método para obtener el código del estudiante
    public int getCodigo() {
        return codigo;
    }
}

// Se define la clase Docente con sus atributos y métodos
class Docente {
    private String nombre;
    private String especialidad;

    // Constructor de la clase Docente
    public Docente(String nombre, String especialidad) {
        this.nombre = nombre;
        this.especialidad = especialidad;
    }

    // Método para obtener el nombre del docente
    public String getNombre() {
        return nombre;
    }

    // Método para obtener la especialidad del docente
    public String getEspecialidad() {
        return especialidad;
    }
}
// Se define la clase Curso con sus atributos y métodos
class Curso {
    private String nombre;
    private int codigo;
    // Constructor de la clase Curso
    public Curso(String nombre, int codigo) {
        this.nombre = nombre;
        this.codigo = codigo;
    }
    // Método para obtener el nombre del curso
    public String getNombre() {
        return nombre;
    }
    // Método para obtener el código del curso
    public int getCodigo() {
        return codigo;
    }
}
// Se define la clase Asociacion que representa la relación entre un estudiante, un docente y un curso
class Asociacion {
    private Estudiante estudiante;
    private Docente docente;
    private Curso curso;
    // Constructor de la clase Asociación
    public Asociacion(Estudiante estudiante, Docente docente, Curso curso) {
        this.estudiante = estudiante;
        this.docente = docente;
        this.curso = curso;
    }
    // Métodos para obtener el estudiante, el docente y el curso
    public Estudiante getEstudiante() {
        return estudiante;
    }

    public Docente getDocente() {
        return docente;
    }

    public Curso getCurso() {
        return curso;
    }
}

public class Act3 {
    public static void main(String[] args) {
        // Creación de objetos Estudiante, Docente y Curso
        Estudiante estudiante1 = new Estudiante("Juan Perez", 1234);
        Docente docente1 = new Docente("Ana Garcia", "Matematicas");
        Curso curso1 = new Curso("Calculo I", 101);

        Estudiante estudiante2 = new Estudiante("Maria Lopez", 5678);
        Docente docente2 = new Docente("Pedro Martinez", "Fisica");
        Curso curso2 = new Curso("Fisica I", 102);

        // Creación de objetos Asociacion
        Asociacion asociacion1 = new Asociacion(estudiante1, docente1, curso1);
        Asociacion asociacion2 = new Asociacion(estudiante2, docente2, curso2);

        // Impresión de información
        System.out.println("Estudiante: " + asociacion1.getEstudiante().getNombre());
        System.out.println("Docente: " + asociacion1.getDocente().getNombre());
        System.out.println("Curso: " + asociacion1.getCurso().getNombre());

        System.out.println("Estudiante: " + asociacion2.getEstudiante().getNombre());
        System.out.println("Docente: " + asociacion2.getDocente().getNombre());
        System.out.println("Curso: " + asociacion2.getCurso().getNombre());
    }
}
