import java.util.ArrayList; // Importa la clase ArrayList para trabajar con listas dinámicas
import java.util.List; // Importa la interfaz List para trabajar con listas

class Cliente { // Declaración de la clase Cliente
    String nombre;
    String direccion;
    String telefono;
    List<String> comprasRealizadas; // Se utiliza una lista para almacenar las compras realizadas
    // Constructor
    Cliente(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.comprasRealizadas = new ArrayList<>(); // Inicializa la lista de compras realizadas
    }
}
class Producto { // Declaración de la clase Producto
    int codigo;
    String descripcion;
    float precio;
    String proveedor;
    // Constructor
    Producto(int codigo, String descripcion, float precio, String proveedor) {
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.precio = precio;
        this.proveedor = proveedor;
    }
}
class Venta { // Declaración de la clase Venta
    int numeroFactura;
    String fecha;
    Cliente cliente;
    List<Producto> productosVendidos; // Se utiliza una lista para almacenar los productos vendidos
    // Constructor
    Venta(int numeroFactura, String fecha, Cliente cliente) {
        this.numeroFactura = numeroFactura;
        this.fecha = fecha;
        this.cliente = cliente;
        this.productosVendidos = new ArrayList<>(); // Inicializa la lista de productos vendidos
    }
}
public class Eje2 {
    public static void main(String[] args) {
        // Se crean clientes con nombre, dirección y número
        Cliente cliente1 = new Cliente("Juan", "Av. Jesus 500", "123456789");
        Cliente cliente2 = new Cliente("Maria", "Av. Ejercito", "987654321");
        // Se crean productos con código, descripción, precio y proveedor
        Producto producto1 = new Producto(1, "Camisa", 25.99f, "Proveedor1");
        Producto producto2 = new Producto(2, "Pantalon", 39.99f, "Proveedor2");
        // Se registra una venta con datos de la factura y los productos vendidos
        Venta venta1 = new Venta(001, "2024-04-13", cliente1);
        venta1.productosVendidos.add(producto1);
        venta1.productosVendidos.add(producto2);
        // Mostrar la información de la venta
        System.out.println("Venta realizada:");
        System.out.println("Numero de factura: " + venta1.numeroFactura);
        System.out.println("Fecha: " + venta1.fecha);
        System.out.println("Cliente: " + venta1.cliente.nombre);
        System.out.println("Productos vendidos:");
        for (Producto producto : venta1.productosVendidos) {
            System.out.println("- " + producto.descripcion + ": $" + producto.precio);
        }
    }
}
