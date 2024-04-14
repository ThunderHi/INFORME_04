class Objeto:  #Define la clase para los objetos que se agregaran a la coleccion
    def __init__(self, identificador, atributo):
        self.identificador = identificador
        self.atributo = atributo

    def get_identificador(self):
        return self.identificador

    def get_atributo(self):
        return self.atributo

    def set_atributo(self, atributo):
        self.atributo = atributo


class EntidadPrincipal:  #Clase base: Entidad principal en la relacion de agregacion
    def __init__(self):
        self.coleccion = []  #Lista que representa la coleccion en la que se agregaron los objetos

    def agregar_objeto(self, objeto):
        self.coleccion.append(objeto)

    def eliminar_objeto(self, objeto):
        for obj in self.coleccion:
            if obj.get_identificador() == objeto.get_identificador():
                self.coleccion.remove(obj)
                return
        print("El objeto no está en la colección.")

    def obtener_objeto(self, identificador):
        for obj in self.coleccion:
            if obj.get_identificador() == identificador:
                return obj

    def get_coleccion(self):
        return self.coleccion


if __name__ == "__main__":
    entidad_principal = EntidadPrincipal()

    #Crear varios objetos de la clase que se agregaron a la coleccion
    objeto1 = Objeto(1, "Atributo 1")
    objeto2 = Objeto(2, "Atributo 2")
    objeto3 = Objeto(3, "Atributo 3")

    #Agregar los objetos a la coleccion
    entidad_principal.agregar_objeto(objeto1)
    entidad_principal.agregar_objeto(objeto2)
    entidad_principal.agregar_objeto(objeto3)

    #Obtener un objeto especifico de la coleccion mediante su identificador
    objeto = entidad_principal.obtener_objeto(2)
    if objeto:
        print("Identificador:", objeto.get_identificador(), ", Atributo:", objeto.get_atributo())

    #Eliminar un objeto de la coleccion
    entidad_principal.eliminar_objeto(objeto3)
    print("Objeto eliminado.")

    #Verificar los objetos en la coleccion despues de eliminar uno
    print("Objetos en la colección después de eliminar:")
    for obj in entidad_principal.get_coleccion():
        print("Identificador:", obj.get_identificador(), ", Atributo:", obj.get_atributo())
