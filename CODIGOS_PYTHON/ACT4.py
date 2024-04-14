class Trabajador:
    def __init__(self, nombre, codigo):
        self.nombre = nombre
        self.codigo = codigo
        self.companeros = []  #Lista de compañeros
        self.numCompaneros = 0

    def agregarCompanero(self, trabajador):
        if self.numCompaneros < MAX_SIZE:
            self.companeros.append(trabajador)
            self.numCompaneros += 1
        else:
            print("No se puede agregar más compañeros. Se alcanzó el límite máximo.")

    def mostrarCompaneros(self):
        print("Compañeros de", self.nombre)
        for companero in self.companeros:
            print("- ", companero.nombre)


class Gerente(Trabajador): #Esta clase hereda de la clase Trabajador
    def __init__(self, nombre, codigo):
        super().__init__(nombre, codigo) #Llamar al constructor de la clase base
        self.trabajadores = []  #Lista de trabajadores
        self.numTrabajadores = 0

    def agregarTrabajador(self, trabajador):
        if self.numTrabajadores < MAX_SIZE:
            self.trabajadores.append(trabajador)
            self.numTrabajadores += 1
        else:
            print("No se puede agregar más trabajadores. Se alcanzó el límite máximo.")

    def mostrarTrabajadores(self):
        print("Trabajadores a cargo del gerente", self.nombre)
        for trabajador in self.trabajadores:
            print("- ", trabajador.nombre)


#Constante MAX_SIZE con valor 10
MAX_SIZE = 10

if __name__ == "__main__":
    trabajadores = [
        Trabajador("Thunder Huacallo", 1234),
        Trabajador("Angel Salas", 5678),
        Trabajador("Andree Aguilar", 9876)
    ]

    gerente1 = Gerente("Nylder Baca", 4321)
    gerente1.agregarTrabajador(trabajadores[0])
    gerente1.agregarTrabajador(trabajadores[1])
    gerente1.agregarTrabajador(trabajadores[2])

    trabajadores[0].agregarCompanero(trabajadores[1])
    trabajadores[0].agregarCompanero(trabajadores[2])
    trabajadores[1].agregarCompanero(trabajadores[0])
    trabajadores[1].agregarCompanero(trabajadores[2])
    trabajadores[2].agregarCompanero(trabajadores[0])
    trabajadores[2].agregarCompanero(trabajadores[1])

    print("Gerente:", gerente1.nombre)
    gerente1.mostrarTrabajadores()
    print()

    print("Trabajador:", trabajadores[0].nombre)
    trabajadores[0].mostrarCompaneros()
    print()
