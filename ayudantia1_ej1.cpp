//Implemente un programa en c++ que permita crear un curso con una lista de 40 alumnos.
//Cada alumno se reconoce por su rut y su nombre. Además cada alumno cuenta con 3 notas.
//Implemente un método para que su programa la información de los alumnos con sus notas y promedio final.
#include <iostream>
using namespace std;
class Alumno{
private:
    string rut, nombre;
    float n1, n2, n3;
public:
    Alumno(string rut, string nombre, float n1, float n2, float n3){
        this->rut = rut;
        this->nombre = nombre;
        this->n1 = n1;
        this->n2 = n2;
        this->n3 = n3;
    }
    void mostrarAlumno(){
        float promedio = (n1+n2+n3)/3;
        cout<<"...................."<<endl;
        cout<<"Alumno "<<nombre<<" - Rut "<<rut<<endl;
        cout<<"Notas: "<<n1<<" - "<<n2<<" - "<<n3<<endl;
        cout<<"Promedio: "<<promedio<<endl;
    }
};
int main() {
    Alumno *alumnos[3];
    alumnos[0] = new Alumno("12345","Uwu", 3.4,6.8,5.5);
    alumnos[1] = new Alumno("49875","Owo", 7,6.2,4);
    alumnos[2] = new Alumno("12547","Ewe", 6.4,6.1,5.1);
    for (int i = 0; i < 3; ++i) {
        alumnos[i]->mostrarAlumno();
    }
    return 0;
}

