class ObjetoCompuesto {  // Clase del objeto que se compone
    private int atributo;
    public ObjetoCompuesto(int valor) {  // Constructor con un parámetro
        atributo = valor;
    }
    public int getAtributo() {  // Método para obtener el atributo
        return atributo;
    }
    public void setAtributo(int valor) {  // Método para establecer el atributo
        atributo = valor;
    }
}
class Base {  // Clase base que representa la entidad principal en la relación de composición
    private ObjetoCompuesto objetoCompuesto;  // Atributo que representa el objeto compuesto
    public Base(ObjetoCompuesto compuesto) {  // Constructor con un objeto de la clase ObjetoCompuesto
        objetoCompuesto = compuesto;
    }
    public ObjetoCompuesto getObjetoCompuesto() {  // Método para acceder al objeto compuesto
        return objetoCompuesto;
    }
    public void modificarAtributo(int valor) {  // Método para modificar el atributo del objeto compuesto
        objetoCompuesto.setAtributo(valor);
    }
    public void eliminarObjeto() {  // Método para eliminar el objeto compuesto
        objetoCompuesto = null;
    }
}
public class Act6 {
    public static void main(String[] args) {
        ObjetoCompuesto objeto = new ObjetoCompuesto(10);  // Se crea un objeto de la clase ObjetoCompuesto
        Base base = new Base(objeto);  // Se crea un objeto de la clase Base que usa el objeto como argumento al constructor
        ObjetoCompuesto compuesto = base.getObjetoCompuesto();  // Se obtiene una referencia al objeto ObjetoCompuesto contenido en la clase Base
        compuesto.setAtributo(20);  // Se establece el atributo en 20
        System.out.println("Atributo del objeto: " + compuesto.getAtributo());
        base.modificarAtributo(30);  // Se modifica el atributo del objeto
        System.out.println("Atributo del objeto modificado: " + compuesto.getAtributo());
        base.eliminarObjeto();  // Se elimina el objeto
    }
}
