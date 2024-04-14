#Definicion de las clases Estudiante, Docente y Curso junto con sus inicializaciones y metodos
class Estudiante:
    def __init__(self, nombre, codigo):
        self.nombre = nombre
        self.codigo = codigo

    def get_nombre(self):
        return self.nombre

    def get_codigo(self):
        return self.codigo

class Docente:
    def __init__(self, nombre, especialidad):
        self.nombre = nombre
        self.especialidad = especialidad

    def get_nombre(self):
        return self.nombre

    def get_especialidad(self):
        return self.especialidad

class Curso:
    def __init__(self, nombre, codigo):
        self.nombre = nombre
        self.codigo = codigo

    def get_nombre(self):
        return self.nombre

    def get_codigo(self):
        return self.codigo

class Asociacion: #Definimos la clase Asociacion para relacionar las 3 clases anteriores
    def __init__(self, estudiante, docente, curso):
        self.estudiante = estudiante
        self.docente = docente
        self.curso = curso
    #Tres métodos de la clase
    def get_estudiante(self):  #Puntero al estudiante
        return self.estudiante

    def get_docente(self): #Puntero al docente
        return self.docente

    def get_curso(self): #Puntero al curso
        return self.curso
#Programa main
if __name__ == "__main__":
    estudiante1 = Estudiante("Angel Salas", 1234)
    docente1 = Docente("Oscar Flores", "Lenguajes de Programacion")
    curso1 = Curso("LP2", 101)
    #Creacion de instancias de las clases Estudiante, Docente y Curso
    estudiante2 = Estudiante("Romina Torres", 5678)
    docente2 = Docente("Francisco Rodriguez", "Fisica")
    curso2 = Curso("Fisica I", 102)
    #Creacion de instancias de la clase Asociacion
    asociacion1 = Asociacion(estudiante1, docente1, curso1)
    asociacion2 = Asociacion(estudiante2, docente2, curso2)

    print("Estudiante:", asociacion1.get_estudiante().get_nombre())
    print("Docente:", asociacion1.get_docente().get_nombre())
    print("Curso:", asociacion1.get_curso().get_nombre())

    print("Estudiante:", asociacion2.get_estudiante().get_nombre())
    print("Docente:", asociacion2.get_docente().get_nombre())
    print("Curso:", asociacion2.get_curso().get_nombre())
