#include <iostream>
#include <vector>
using namespace std;
class Alumno{
private:
    string rut, nombre;
    vector<float> notas;
public:
    Alumno(string rut, string nombre){
       this->rut = rut;
       this->nombre = nombre;
    }
    void ingresarNota(vector<float> notas_ing){
        int n = notas_ing.size();
        for (int i = 0; i < n; i++){
            notas.push_back(notas_ing.at(i));
        }
    }
    void ingresarNota(float nota){
        notas.push_back(nota);
    }
    float promedio(){
        int n = notas.size();
        float sum = 0;
        for (int i = 0; i < n; i++) {
            sum += notas.at(i);
        }
        return sum / n;
    }
    void lista(){
        int n = notas.size();
        for (int i = 0; i < n; ++i) {
            cout<<"Nota "<<i+1<<": "<<notas[i]<<endl;
        }
    }
};
int main(){
    Alumno *a =  new Alumno("123","uwu");
    vector<float> notas = {2,4.5,6};
    a->ingresarNota(7);

    a->ingresarNota(notas);
    a->lista();
    cout<<"Promedio: "<<a->promedio()<<endl;
    return 0;
}