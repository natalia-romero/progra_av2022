#include <iostream>
#include <map>
#include <stack>
using namespace std;
class Contenedor{
private:
    int id;
    float peso;
    float cargaTotal;
public:
    Contenedor(){}
    void crearContenedor(int id, float peso){ //inicializa contenedor
        this->id = id;
        this->peso = peso;
    }
    bool verificarCarga(float carga) { //verifica que la carga no sea mayor al peso del contenedor
        if (peso < carga) {
            return false;
        } else {
            cargaTotal = carga;
            return true;
        }
    }
    void info(){ //imprime los datos del contenedor
        cout<<"  - ID: "<<id<<endl<<"  - Peso: "<<peso<<endl<<"  - Carga Total: "<<cargaTotal<<endl;
    }
};
class Puerto{
private:
    map<string,stack<Contenedor*>> cargas;
public:
    Puerto(){}
    void embarque(string fruta, float carga, Contenedor *contenedor){
        if(contenedor->verificarCarga(carga)){ //verifica que la carga cumpla con el contenedor
            cargas[fruta].push(contenedor);
            cout<<"Contenedor agregado al embarque de "<<fruta<<endl;
        } else{
            cout<<"El contenedor no se ha agregado al embarque, la carga supera el peso permitido."<<endl;
        }
    }
    void listar(){
        for(auto i = cargas.begin(); i != cargas.end(); i++){
            stack<Contenedor*> aux = i->second; //crea una pila auxiliar para poder recorrer los contenedores
            cout<<"* * Fruta: "<<i->first<<endl;
            while(!aux.empty()) { //recorre todos los contenedores hasta que se acaben
                aux.top()->info();
                aux.pop();
            }
        }
    }
};
int main(){
    Puerto *puertito = new Puerto();
    Contenedor *a = new Contenedor();
    Contenedor *b = new Contenedor();
    Contenedor *c = new Contenedor();

    a->crearContenedor(123,234);
    b->crearContenedor(222,123);
    c->crearContenedor(777,678);
    puertito->embarque("frutilla",100,a);
    puertito->embarque("frutilla",50,b);
    puertito->embarque("naranja",300,c);
    puertito->listar();
    return 0;
}