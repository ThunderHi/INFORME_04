class Curso:
    def __init__(self, nombre, codigo, descripcion, fecha_inicio, fecha_finalizacion):
        self.nombre = nombre
        self.codigo = codigo
        self.descripcion = descripcion
        self.fecha_inicio = fecha_inicio
        self.fecha_finalizacion = fecha_finalizacion
        self.estudiantes = []
    
    def agregar_estudiante(self, estudiante):
        self.estudiantes.append(estudiante)
        estudiante.agregar_curso(self)
    
    def eliminar_estudiante(self, estudiante):
        if estudiante in self.estudiantes:
            self.estudiantes.remove(estudiante)
            estudiante.eliminar_curso(self)
    
    def imprimir_curso(self):
        print(f"Nombre: {self.nombre}, Codigo: {self.codigo}, Descripcion: {self.descripcion}, Fecha de Inicio: {self.fecha_inicio}, Fecha de Finalizacion: {self.fecha_finalizacion}")
        print("Estudiantes asociados:")
        for estudiante in self.estudiantes:
            estudiante.imprimir_estudiante()

class Estudiante:
    def __init__(self, nombre, apellido, num_identificacion, correo_electronico):
        self.nombre = nombre
        self.apellido = apellido
        self.num_identificacion = num_identificacion
        self.correo_electronico = correo_electronico
        self.cursos = []
    
    def agregar_curso(self, curso):
        self.cursos.append(curso)
    
    def eliminar_curso(self, curso):
        if curso in self.cursos:
            self.cursos.remove(curso)
    
    def imprimir_estudiante(self):
        print(f"Nombre: {self.nombre}, Apellido: {self.apellido}, Numero de Identificacion: {self.num_identificacion}, Correo Electronico: {self.correo_electronico}")
        print("Cursos asociados:")
        for curso in self.cursos:
            print(f"Nombre: {curso.nombre}, Codigo: {curso.codigo}, Descripcion: {curso.descripcion}, Fecha de Inicio: {curso.fecha_inicio}, Fecha de Finalizacion: {curso.fecha_finalizacion}")

if __name__ == "__main__":
    curso1 = Curso("Curso 1", "001", "Descripcion del Curso 1", "01/04/2024", "30/06/2024")
    curso2 = Curso("Curso 2", "002", "Descripcion del Curso 2", "15/04/2024", "15/07/2024")

    estudiante1 = Estudiante("Juan", "Perez", "12345", "juan@gmail.com")
    estudiante2 = Estudiante("Maria", "Gomez", "67890", "maria@gmail.com")

    print("Cursos antes de asociar estudiantes:")
    curso1.imprimir_curso()
    curso2.imprimir_curso()
    print("\nEstudiantes antes de asociar cursos:")
    estudiante1.imprimir_estudiante()
    estudiante2.imprimir_estudiante()

    curso1.agregar_estudiante(estudiante1)
    curso2.agregar_estudiante(estudiante1)
    curso2.agregar_estudiante(estudiante2)

    estudiante1.agregar_curso(curso1)
    estudiante1.agregar_curso(curso2)
    estudiante2.agregar_curso(curso2)

    curso1.eliminar_estudiante(estudiante1)
    estudiante1.eliminar_curso(curso2)

    print("\nCursos despues de asociar y desasociar estudiantes:")
    curso1.imprimir_curso()
    curso2.imprimir_curso()

    print("\nEstudiantes despues de asociar y desasociar cursos:")
    estudiante1.imprimir_estudiante()
    estudiante2.imprimir_estudiante()
