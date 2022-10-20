#include "iostream"
#include "stack"
using namespace std;
class Disco{
private:
    string nombre, tipo, cantante;
    int anio, precio;
public:
    Disco(string nombre, string tipo, string cantante, int anio, int precio){
        this->nombre = nombre;
        this->tipo = tipo;
        this->anio = anio;
        this->cantante = cantante;
        this->precio = precio;
    }
    string getTipo(){
        return tipo;
    }
    void info(){
        cout<<"Nombre: "<<nombre<<" - Tipo: "<<tipo<<" - Cantante: "<<cantante<<" - Anio: "<<anio<<" - Precio: "<<precio<<endl;
    }
};
class UDPyme{
private:
    stack<Disco*> cajaRandom;
    stack<Disco*> cajaRock;
    stack<Disco*> cajaPop;
    stack<Disco*> cajaReggaeton;
public:
    UDPyme(){
        cajaRandom.push(new Disco("Disco1","Pop","Uwu",2000,10200));
        cajaRandom.push(new Disco("Disco2","Reggaeton","OWO",2020,8900));
        cajaRandom.push(new Disco("Disco3","Rock","Uwu",2000,10900));
        cajaRandom.push(new Disco("Disco4","Rock","Uwu",2000,8900));
    }
    void ordenar(){
        while(!cajaRandom.empty()){
            string tipo = cajaRandom.top()->getTipo();
            if(tipo == "Reggaeton"){
                cajaReggaeton.push(cajaRandom.top());
                cout<<"Disco Agregado a Reggaeton."<<endl;
                cajaRandom.top()->info();
            } else if(tipo == "Pop"){
                cajaPop.push(cajaRandom.top());
                cout<<"Disco Agregado a Pop."<<endl;
                cajaRandom.top()->info();
            } else if (tipo == "Rock"){
                cajaRock.push(cajaRandom.top());
                cout<<"Disco Agregado a Rock."<<endl;
                cajaRandom.top()->info();
            } else{
                cout<<"Error al ordenar."<<endl;
            }
            cajaRandom.pop();
            cout<<" - -- - - -"<<endl;
        }
        cout<<"Caja ordenada!"<<endl;
    }

};
int main(){
    UDPyme *tiendita = new UDPyme();
    tiendita->ordenar();
    return 0;
}