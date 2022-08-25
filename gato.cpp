#include <iostream>
using namespace std;
class Gato{
private:
    string nombre, color, raza;
    int edad;
    float peso;
public :
    Gato(){
        this->nombre = "Juan Duarte";
        //nada
    }
    Gato(string nombre, string color, string raza, int edad, float peso){
        this->nombre = nombre;
        this->color = color;
        this->raza = raza;
        this->edad = edad;
        this->peso = peso;
    }
    void maullar(){
        cout<<"miau"<<endl;
    }
    string getNombre(){
        return this->nombre;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
};


int main() {
    Gato *gato1 = new Gato();
    Gato *gatos[3];
    gatos[0] = new Gato("uwu","cafe","quiltro", 17,7.3);
    gatos[1] = new Gato();
    gatos[2] = new Gato();
    cout<<gatos[0]->getNombre()<<" dice: ";
    gato1->maullar();
    return 0;
}
