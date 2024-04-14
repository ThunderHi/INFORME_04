class ObjetoCompuesto:
    def __init__(self, valor):
        self.atributo = valor

    def get_atributo(self):
        return self.atributo

    def set_atributo(self, valor):
        self.atributo = valor


class Base:
    def __init__(self, compuesto):
        self.objeto_compuesto = compuesto

    def get_objeto_compuesto(self):
        return self.objeto_compuesto

    def modificar_atributo(self, valor):
        self.objeto_compuesto.set_atributo(valor)

    def eliminar_objeto(self):
        del self.objeto_compuesto


if __name__ == "__main__":
    objeto = ObjetoCompuesto(10)
    base = Base(objeto)

    compuesto = base.get_objeto_compuesto()
    compuesto.set_atributo(20) #Valor del atributo establecido en 20
    print("Atributo del objeto:", compuesto.get_atributo())

    base.modificar_atributo(30) #Modificando el atributo del objeto
    print("Atributo del objeto modificado:", compuesto.get_atributo())

    base.eliminar_objeto() #Para eliminar el objeto
