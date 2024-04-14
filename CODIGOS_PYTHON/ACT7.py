class Padre: #Define la clase padre en la relacion de herencia
    def __init__(self, valor):
        self.atributo_padre = valor

    def metodo_padre(self):
        print("Método de la clase Padre:", self.atributo_padre)


class Hijo(Padre): #Definicion de la clase derivada en la relacion de herencia
    def __init__(self, valor_padre, valor_propio):
        super().__init__(valor_padre)
        self.atributo_hijo = valor_propio

    def metodo_hijo(self):
        print("Método de la clase Hijo:", self.atributo_hijo)


if __name__ == "__main__":
    objeto = Hijo(10, 20) #Creando objeto de la clase derivada
    objeto.metodo_padre() #Acceder a los atributos y metodos heredados de la clase base (Padre)
    objeto.metodo_hijo() #Acceder a los atributos y metodos propios de la clase derivada (Hijo)
