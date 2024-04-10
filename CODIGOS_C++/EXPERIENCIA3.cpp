#include <iostream>

using namespace std;

//Se define la clase Estudiante con sus atributos y metodos
class Estudiante {
  private:
    string nombre;
    int codigo;

  public:
  //Constructor de la clase Estudiante
    Estudiante(string nombre, int codigo) {
    //Se inicializa los atributos
      this->nombre = nombre;
      this->codigo = codigo;
    }

    //Metodo para obtener el nombre del estudiante
    string getNombre() { return nombre; }
    //Se retorna el atributo nombre
    int getCodigo() { return codigo; }  //Se retorna el atributo codigo
};

//Se define la clase Docente con sus atributos y metodos
class Docente {
  private:
    string nombre;
    string especialidad;

  public:
  //Constructor de la clase Docente
    Docente(string nombre, string especialidad) {
    //Se inicializa los atributos
      this->nombre = nombre;
      this->especialidad = especialidad;
    }

    //Metodo para obtener el nombre del docente
    string getNombre() { return nombre; }   //Se retorna el atributo nombre
   //Metodo para obtener la especialidad
    string getEspecialidad() { return especialidad; }   //Se retorna el atributo especialidad
};

//Se define la clase Curso con sus atributos y metodos
class Curso {
  private:
    string nombre;
    int codigo;

  public:
    //Constructor de la clase Curso
    Curso(string nombre, int codigo) {
      this->nombre = nombre;
      this->codigo = codigo;
    }

    //Metodo para obtener el nombre del curso
    string getNombre() { return nombre; }   // Se retorna el atributo nombre
    //Metodo para obtener el codigo
    int getCodigo() { return codigo; }  //Se retorna el atributo codigo
};

//Se define la clase Asociacion que representa la relación entre un estudiante, un docente y un curso
class Asociacion {
  private:
  //Punteros para cada atributo
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;

  public:
  //Constructor de la clase Asociación
    Asociacion(Estudiante* estudiante, Docente* docente, Curso* curso) {
    //Se inicializa los atributos
      this->estudiante = estudiante;
      this->docente = docente;
      this->curso = curso;
    }

    //Metodos para obtener Estudiante, Docente y Curso
    Estudiante* getEstudiante() { return estudiante; }
    Docente* getDocente() { return docente; }
    Curso* getCurso() { return curso; }
    //Retorna los punteros a los atributos
};

int main() {
  Estudiante estudiante1("Juan Perez", 1234);
  Docente docente1("Ana Garcia", "Matematicas");
  Curso curso1("Calculo I", 101);

  Estudiante estudiante2("Maria Lopez", 5678);
  Docente docente2("Pedro Martinez", "Fisica");
  Curso curso2("Fisica I", 102);
  //"&" o "ampersand" se utiliza para obtener la direccion de memoria de objetos
  Asociacion asociacion1(&estudiante1, &docente1, &curso1);
  Asociacion asociacion2(&estudiante2, &docente2, &curso2);

  //Obtencion de informacion
  cout<<"Estudiante: "<<asociacion1.getEstudiante()->getNombre() << endl;
  cout<< "Docente: "<<asociacion1.getDocente()->getNombre() << endl;
  cout<<"Curso: "<<asociacion1.getCurso()->getNombre() << endl;

  cout<<"Estudiante: "<<asociacion2.getEstudiante()->getNombre() << endl;
  cout<<"Docente: "<<asociacion2.getDocente()->getNombre() << endl;
  cout<<"Curso: "<<asociacion2.getCurso()->getNombre() << endl;

  return 0;
}
