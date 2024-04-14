class Asignatura:
    def __init__(self, codigo, nombre, descripcion, profesor):
        self.codigo = codigo
        self.nombre = nombre
        self.descripcion = descripcion
        self.profesor = profesor

    def mostrar_informacion(self): #Funcion para mostrar la informacion de la asignatura
        print("Asignatura:", self.nombre, "(", self.codigo, ")")
        print("Descripcion:", self.descripcion)
        print("Profesor:", self.profesor)
        print()

class Estudiante:
    def __init__(self, nombre, direccion, matricula):
        self.nombre = nombre
        self.direccion = direccion
        self.matricula = matricula
        self.asignaturas_matriculadas = []
        self.notas = []
        self.faltas = []
    #Funcion para matricular una asignatura a un estudiante
    def matricular_asignatura(self, asignatura):
        self.asignaturas_matriculadas.append(asignatura)
        self.notas.append(0)
        self.faltas.append(0)

    def registrar_nota(self, nota, asignatura_index):
        self.notas[asignatura_index] = nota

    def registrar_falta(self, falta, asignatura_index):
        self.faltas[asignatura_index] += 1

    def mostrar_informacion(self):
        print("Estudiante:", self.nombre, "(", self.matricula, ")")
        print("Direccion:", self.direccion)
        print("Asignaturas Matriculadas:")
        for asignatura in self.asignaturas_matriculadas:
            print("  - ", end="")
            asignatura.mostrar_informacion()
        print()

class Profesor:
    def __init__(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.asignaturas_impartidas = []
    #Funcion para mostrar la informacion del profesor
    def mostrar_informacion(self):
        print("Profesor:", self.nombre, "(", self.telefono, ")")
        print("Direccion:", self.direccion)
        print("Asignaturas Impartidas:")
        for asignatura in self.asignaturas_impartidas:
            print("  - ", end="")
            asignatura.mostrar_informacion()
        print()

#Crear asignaturas
asignatura1 = Asignatura("A1", "Programacion I", "Introduccion a la programacion", "Profesor Juan")
asignatura2 = Asignatura("A2", "Matematicas I", "Introduccion a las matematicas", "Profesora Maria")

#Crear profesores
profesor1 = Profesor("Profesor Juan", "Direccion 1", "123456789")
profesor2 = Profesor("Profesora Maria", "Direccion 2", "987654321")

#Asignar asignaturas a los profesores
profesor1.asignaturas_impartidas.append(asignatura1)
profesor2.asignaturas_impartidas.append(asignatura2)

#Crear estudiantes
estudiante1 = Estudiante("Estudiante Esdras", "Dirección A", "1A")
estudiante2 = Estudiante("Estudiante Miguel", "Dirección B", "2B")

#Matricular estudiantes en las asignaturas
estudiante1.matricular_asignatura(asignatura1)
estudiante1.matricular_asignatura(asignatura2)
estudiante2.matricular_asignatura(asignatura1)
estudiante2.matricular_asignatura(asignatura2)

#Mostrar informacion
print("Informacion de Asignaturas:")
asignatura1.mostrar_informacion()
asignatura2.mostrar_informacion()

print("Informacion de Profesores:")
profesor1.mostrar_informacion()
profesor2.mostrar_informacion()

print("Informacion de Estudiantes:")
estudiante1.mostrar_informacion()
estudiante2.mostrar_informacion()
