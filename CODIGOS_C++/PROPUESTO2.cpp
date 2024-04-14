#include <iostream>     //Incluye la biblioteca de entrada y salida de datos
#include <string>       //Incluye la biblioteca de cadenas de texto
#include <vector>       //Incluye la biblioteca de vectores

using namespace std;       //Utiliza el espacio de nombres estándar de C++

class Cliente {         //Declaracion de clase cliente
public:
    string nombre;
    string direccion;
    string telefono;
    vector<string> compras_realizadas;

    Cliente(string nombre, string direccion, string telefono)       //constructor con tres parametros
       : nombre(nombre),direccion(direccion),telefono (telefono){}
};

class Producto {       //Declaracion de clase producto
public:
    int codigo;
    string descripcion;
    float precio;
    string proveedor;

    // Constructor
    Producto(int codigo, string descripcion, float precio, string proveedor)        //constructor con tres parametros
        :codigo(codigo),descripcion(descripcion),precio(precio),proveedor(proveedor){}
};

class Venta {       //Declaracion de clase venta
public:
    int numero_factura;
    string fecha;
    Cliente cliente;
    vector<Producto> productos_vendidos;

    // Constructor
    Venta(int numero_factura, string fecha, Cliente cliente)            //constructor con tres parametros
        :numero_factura(numero_factura),fecha(fecha),cliente(cliente){}
};

int main() {

    // Se crean clientes con nombre, direccion y numero
    Cliente cliente1("Juan", "Av. Jesus 500", "123456789");
    Cliente cliente2("Maria", "Av. Ejercito", "987654321");

    // Se crean productos con codigo, descripcion, precio y proovedor
    Producto producto1(1, "Camisa", 25.99, "Proveedor1");
    Producto producto2(2, "Pantalon", 39.99, "Proveedor2");

    // Se registra una venta con datos de la factura y los productos vendidos se almacenan en el arreglo productos_vendidos
    Venta venta1(001, "2024-04-13", cliente1);
    venta1.productos_vendidos.push_back(producto1);
    venta1.productos_vendidos.push_back(producto2);

    // Mostrar la informacion de la venta
    cout << "Venta realizada:" << endl;
    cout << "Numero de factura: " << venta1.numero_factura << endl;
    cout << "Fecha: " << venta1.fecha << endl;
    cout << "Cliente: " << venta1.cliente.nombre << endl;
    cout << "Productos vendidos:" << endl;
    for (const auto& producto : venta1.productos_vendidos) {
        cout << "- " << producto.descripcion << ": $" << producto.precio << endl;
    }

    return 0;
}

