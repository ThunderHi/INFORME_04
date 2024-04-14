#Definicion de la clase Autor
class Autor:
    def __init__(self, nombre, nacionalidad):
        self.nombre = nombre
        self.nacionalidad = nacionalidad
        self.libros_escritos = []  #Lista de libros escritos por el autor

#Definicion de la clase Libro
class Libro:
    def __init__(self, isbn, titulo, anio_publicacion, cantidad_ejemplares, autor):
        self.isbn = isbn
        self.titulo = titulo
        self.anio_publicacion = anio_publicacion
        self.cantidad_ejemplares = cantidad_ejemplares
        self.autor = autor

#Definicion de la clase Usuario
class Usuario:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.libros_prestados = []  #Lista de libros prestados al usuario
        self.fechas_prestamo = []   #Lista de fechas de prestamo de libros
        self.fechas_devolucion = []  #Lista de fechas de devolucion de libros

#Funcion para mostrar informacion de un autor
def mostrar_autor(autor):
    print("Nombre:", autor.nombre)
    print("Nacionalidad:", autor.nacionalidad)
    print("Libros escritos:")
    for libro in autor.libros_escritos:
        print("- " + libro)

#Funcion para mostrar informacion de un libro
def mostrar_libro(libro):
    print("ISBN:", libro.isbn)
    print("Título:", libro.titulo)
    print("Año de publicación:", libro.anio_publicacion)
    print("Cantidad de ejemplares:", libro.cantidad_ejemplares)
    mostrar_autor(libro.autor)

#Funcion para mostrar informacion de un usuario
def mostrar_usuario(usuario):
    print("Nombre:", usuario.nombre)
    print("Dirección:", usuario.direccion)
    print("Teléfono:", usuario.telefono)
    print("Libros prestados:")
    for i in range(len(usuario.libros_prestados)):
        libro = usuario.libros_prestados[i]
        print("- ISBN:", libro.isbn + ", Título:", libro.titulo, end="")
        print(", Fecha de préstamo:", usuario.fechas_prestamo[i], end="")
        print(", Fecha de devolución:", usuario.fechas_devolucion[i])

if __name__ == "__main__":
    #Creacion de objetos Autor, Libro y Usuario
    autor1 = Autor("Gabriel García Márquez", "Colombiano")
    libro1 = Libro("9780060932759", "Cien años de soledad", 1967, 5, autor1)
    usuario1 = Usuario("Juan Pérez", "Calle Principal 123", "555-1234")

    #Añadir el libro prestado al usuario con sus fechas correspondientes
    usuario1.libros_prestados.append(libro1)
    usuario1.fechas_prestamo.append("01/04/2024")
    usuario1.fechas_devolucion.append("15/04/2024")

    #Mostrar informacion en la consola
    mostrar_autor(autor1)
    mostrar_libro(libro1)
    mostrar_usuario(usuario1)
