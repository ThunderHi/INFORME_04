class Padre {  // Clase padre en la relación de herencia
    protected int atributoPadre;  // Atributo de la clase padre

    public Padre(int valor) {  // Constructor con un parámetro
        atributoPadre = valor;
    }
    public void metodoPadre() {  // Método de la clase padre
        System.out.println("Método de la clase padre: " + atributoPadre);
    }
}
class Hijo extends Padre {  // Clase derivada en la relación de herencia
    private int atributoHijo;  // Atributo propio de la clase hijo

    public Hijo(int valorPadre, int valorPropio) {  // Constructor con dos parámetros
        super(valorPadre);  // Llama al constructor de la clase padre para inicializar el atributo heredado
        atributoHijo = valorPropio;  // Inicializa su propio atributo
    }
    public void metodoHijo() {  // Método propio de la clase hijo
        System.out.println("Método de la clase hijo: " + atributoHijo);
    }
}
public class Act7 {
    public static void main(String[] args) {
        Hijo objeto = new Hijo(10, 20);  // Crea un objeto de la clase derivada
        objeto.metodoPadre();  // Accede a los atributos y métodos heredados de la clase padre
        objeto.metodoHijo();   // Accede a los atributos y métodos propios de la clase derivada (hijo)
    }
}
