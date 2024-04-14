class Cliente:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.compras_realizadas = []  #Lista de compras realizadas por el cliente

class Producto:
    def __init__(self, codigo, descripcion, precio, proveedor):
        self.codigo = codigo
        self.descripcion = descripcion
        self.precio = precio
        self.proveedor = proveedor

class Venta:
    def __init__(self, numero_factura, fecha, cliente):
        self.numero_factura = numero_factura
        self.fecha = fecha
        self.cliente = cliente
        self.productos_vendidos = []  #Lista de productos vendidos en la venta

#Creacion de clientes con nombre, direccion y telefono
cliente1 = Cliente("Juan", "Av. Jesus 500", "123456789")
cliente2 = Cliente("Maria", "Av. Ejercito", "987654321")

#Creacion de productos con codigo, descripcion, precio y proveedor
producto1 = Producto(1, "Camisa", 25.99, "Proveedor1")
producto2 = Producto(2, "Pantalon", 39.99, "Proveedor2")

#Registro de una venta con datos de la factura y los productos vendidos
venta1 = Venta(1, "2024-04-13", cliente1)
venta1.productos_vendidos.append(producto1)
venta1.productos_vendidos.append(producto2)

#Mostrar la informacion de la venta
print("Venta realizada:")
print("Número de factura:", venta1.numero_factura)
print("Fecha:", venta1.fecha)
print("Cliente:", venta1.cliente.nombre)
print("Productos vendidos:")
for producto in venta1.productos_vendidos:
    print("- " + producto.descripcion + ": $" + str(producto.precio))
