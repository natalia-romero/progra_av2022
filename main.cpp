#include <iostream>
using namespace std;
class Gato{
private:
    int edad;
    float peso;
    string nombre, color, raza, duenio;
public:
    Gato(){
        //nada
    }
    Gato(int edad, float peso, string nombre, string color, string raza, string duenio){
        this->edad = edad;
        this->peso = peso;
        this->nombre = nombre;
        this->color = color;
        this->raza = raza;
        this->duenio = duenio;
    }

    void maullar(){
        cout<<this->nombre<<": miau"<<endl;
    }

    int getEdad(){
        return this->edad;
    }
    void setEdad(int edad){
        this->edad = edad;
    }
};
int main() {
    Gato *gato1 = new Gato(3,4.5,"ElMiau","Blanco","Nose","Yooo");
    gato1->maullar();
    Gato *gatos[4];
    gatos[0] = new Gato();
    gatos[1] = new Gato();
    gatos[2] = new Gato();
    gatos[3] = new Gato();

    return 0;
}
