#include <iostream>
using namespace std;

class Persona{
protected:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
    }
};

class Profesor : public Persona{
protected:
    int sueldo;
    string asignatura;
public:
    Profesor(string nombre, int edad, int sueldo, string asignatura) : Persona(nombre,edad){
        this->sueldo = sueldo;
        this->asignatura = asignatura;
    }
};

class Alumno : public Persona{
protected:
    int notas[6][4];
    string asignatura[6];
public:
    Alumno(string nombre, int edad, int notas[6][4], string asignaturas[6]) : Persona(nombre,edad){
        for (int i=0; i<6; i++){
            for (int j=0; j<4; j++){
                this->notas[i][j] = notas[i][j];
            }
            this->asignatura[i] = asignaturas[i];
        }
    }
};

int main(){
    int notas[6][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string asignaturas[6] = {"a", "b", "c", "d", "e", "f"};
    Alumno *al1 = new Alumno ("Juan", 17, notas, asignaturas);
    Profesor *pr1 = new Profesor("Pepe", 35, 1500000, "Web");
    return 0;
}
