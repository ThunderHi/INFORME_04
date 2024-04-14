import java.util.ArrayList; // Importa la clase ArrayList para trabajar con colecciones dinámicas
import java.util.List;      // Importa la clase List para trabajar con interfaces de colecciones

class Objeto {              // Define la clase para los objetos que se agregarán a la colección
    private int identificador;
    private String atributo;

    public Objeto(int id, String attr) {  // Constructor con dos parámetros
        identificador = id;
        atributo = attr;
    }
    public int getIdentificador() {       // Método que devuelve el identificador de un objeto
        return identificador;
    }
    public String getAtributo() {         // Método que devuelve el atributo de un objeto
        return atributo;
    }
    public void setAtributo(String attr) {// Método para establecer el atributo del objeto en una variable
        atributo = attr;
    }
}
class EntidadPrincipal {                // Clase base: Entidad principal en la relación de agregación
    private List<Objeto> coleccion;     // Lista que representa la colección en la que se agregarán los objetos

    public EntidadPrincipal() {         // Constructor que inicializa la colección
        coleccion = new ArrayList<>();
    }
    public void agregarObjeto(Objeto objeto) {  // Método para agregar un objeto a la colección de objetos
        coleccion.add(objeto);
    }
    public void eliminarObjeto(Objeto objeto) { // Método que recibe un objeto y lo elimina de la colección
        coleccion.remove(objeto);
    }
    public Objeto obtenerObjeto(int identificador) {  // Método para obtener un objeto por su identificador
        for (Objeto obj : coleccion) {
            if (obj.getIdentificador() == identificador) {
                return obj;
            }
        }
        return null;
    }
    public List<Objeto> getColeccion() {  // Método que devuelve una referencia a la colección de objetos
        return coleccion;
    }
}

public class Act5 {
    public static void main(String[] args) {
        EntidadPrincipal entidadPrincipal = new EntidadPrincipal();

        // Crear varios objetos de la clase que se agregarán a la colección
        Objeto objeto1 = new Objeto(1, "Atributo 1");
        Objeto objeto2 = new Objeto(2, "Atributo 2");
        Objeto objeto3 = new Objeto(3, "Atributo 3");
        // Agregar los objetos a la colección
        entidadPrincipal.agregarObjeto(objeto1);
        entidadPrincipal.agregarObjeto(objeto2);
        entidadPrincipal.agregarObjeto(objeto3);
        // Obtener un objeto específico de la colección mediante su identificador
        Objeto objeto = entidadPrincipal.obtenerObjeto(2);
        if (objeto != null) {
            System.out.println("Identificador: " + objeto.getIdentificador() + ", Atributo: " + objeto.getAtributo());
        }
        // Eliminar un objeto de la colección
        entidadPrincipal.eliminarObjeto(objeto3);
        System.out.println("Objeto eliminado.");
        // Verificar los objetos en la colección después de eliminar uno
        System.out.println("Objetos en la colección después de eliminar:");
        for (Objeto obj : entidadPrincipal.getColeccion()) {
            System.out.println("Identificador: " + obj.getIdentificador() + ", Atributo: " + obj.getAtributo());
        }
    }
}
