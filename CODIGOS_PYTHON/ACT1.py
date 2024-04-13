#Clase Padre
class Padre:
    def __init__(self, nombre):
        self.nombre = nombre  #Atributo "nombre"
        self.hijos = []       #Lista para almacenar objetos Hijo
        self.numHijos = 0     #Contador de hijos
    
    #Metodo para agregar un hijo a la lista
    def agregarHijo(self, hijo):
        if self.numHijos < 5:
            self.hijos.append(hijo)
            self.numHijos += 1
        else:
            print("No se pueden agregar más hijos.")

    #Metodo para imprimir información del Padre
    def imprimirInfo(self):
        print("Nombre del Padre:", self.nombre)
        print("Número de Hijos:", self.numHijos)

#Clase Hijo
class Hijo:
    def __init__(self, nombre):
        self.nombre = nombre  # Atributo "nombre"

#Función principal
def main():
    padre = Padre("Alexander")  #Crea un objeto Padre con nombre "Alexander"

    hijo1 = Hijo("Pedro")  #Crea un objeto Hijo con nombre "Pedro"
    hijo2 = Hijo("Maria")  #Crea un objeto Hijo con nombre "Maria"

    padre.agregarHijo(hijo1)  #Agrega hijo1 al Padre
    padre.agregarHijo(hijo2)  #Agrega hijo2 al Padre

    padre.imprimirInfo()  #Imprime la información del Padre

if __name__ == "__main__":
    main()
