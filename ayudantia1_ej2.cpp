//Utilizando el Programa del ejercicio anterior, implemente en la función main lo siguiente:
// a. Imprimir por pantalla la información del alumno con mejor promedio.
// b. Imprimir a el listado de alumnos con promedio inferior a 4,0 que reprueban el ramo.
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
    float getPromedio(){
        float promedio = (n1+n2+n3)/3;
        return promedio;
    }
    void mostrarDatosPersonales(){
        cout<<"Alumno "<<nombre<<" - Rut "<<rut<<endl;
    }
    void mostrarAlumno(){
        this->mostrarDatosPersonales();
        cout<<"Notas: "<<n1<<" - "<<n2<<" - "<<n3<<endl;
        cout<<"Promedio: "<< this->getPromedio()<<endl;
        cout<<"...................."<<endl;
    }
};
int main() {
    Alumno *alumnos[3];
    alumnos[0] = new Alumno("12345","Uwu", 1,2,5.5);
    alumnos[1] = new Alumno("49875","Owo", 7,6.2,4);
    alumnos[2] = new Alumno("12547","Ewe", 6.4,6.1,5.1);
    float promedio = 0;
    int indice = 0;
    for (int i = 0; i < 3; ++i) {
        alumnos[i]->mostrarAlumno();
        float promAlumno = alumnos[i]->getPromedio();

        if(promedio <= promAlumno){ //se busca alumno con mejor promedio
            promedio = promAlumno;
            indice = i;
        }
    }
    for (int i = 0; i < 3; ++i) { //Alumnos que reprueban el ramo
        float promAlumno = alumnos[i]->getPromedio();
        if(promAlumno < 4){
            cout<<"Reprueba el ramo: ";
            alumnos[i]->mostrarDatosPersonales();
            cout<<endl;
        }
    }
    cout<<"El alumno con mejor promedio es: "; //se muestra alumno con mejor promedio
    alumnos[indice]->mostrarAlumno();
    return 0;
}
