class Padre:    #Clase Padre
    def __init__(self, nombre):
        self.nombre = nombre  #Atributo "nombre"
        self.hijos = []       #Lista para almacenar objetos Hijo
        self.numHijos = 0     #Contador de hijos

    #Metodo para agregar un hijo a la lista
    def agregarHijo(self, hijo):
        if self.numHijos < 7:
            self.hijos.append(hijo)
            self.numHijos += 1
        else:
            print("No se pueden agregar más hijos.")
    
    #Metodo para imprimir informacion del Padre
    def imprimirInfo(self):
        print("Nombre del Padre:", self.nombre)
        print("Número de Hijos:", self.numHijos)

#Clase Hijo
class Hijo:
    def __init__(self, nombre):
        self.nombre = nombre  # Atributo "nombre"

#Función principal
def main():
    padre = Padre("Alejandro")  #Crea un objeto Padre
    hijo1 = Hijo("Diego")  #Crea un objeto Hijo
    hijo2 = Hijo("Carmen")
    hijo3 = Hijo("Joaquin")
    hijo4 = Hijo("Mariana")

    padre.agregarHijo(hijo1)  #Agrega hijo1 al Padre
    padre.agregarHijo(hijo2)  #Agrega hijo2 al Padre
    padre.agregarHijo(hijo3)  #Agrega hijo2 al Padre
    padre.agregarHijo(hijo4)  #Agrega hijo2 al Padre

    padre.imprimirInfo()  #Imprime la información del Padre

if __name__ == "__main__":
    main()
