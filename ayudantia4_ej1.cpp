#include <iostream>
using namespace std;
class Vehiculo{
protected:
    int cantidad, ruedas;
    string color;
public:
    Vehiculo(int ruedas, string color){
        this->cantidad=20;
        this->ruedas = ruedas;
        this->color = color;
    }
     void info(){
        cout<<"Stock disponible: "<<cantidad<<endl;
        cout<<"Ruedas: "<<ruedas<<endl;
        cout<<"Color: "<<color<<endl;
    }
    void setCantidad(){
        this->cantidad -= 1;
    }
    int getCantidad(){
        return this->cantidad;
    }
};
class Auto : public Vehiculo{
protected:
    int cantPasajeros;
    float velocidad;
public:
    Auto(int ruedas, string color, int cantPasajeros, float velocidad):Vehiculo(ruedas,color){
        this->cantPasajeros = cantPasajeros;
        this->velocidad = velocidad;
    }
    void info(){
        cout<<"Stock disponible: "<<cantidad<<endl;
        cout<<"Ruedas: "<<ruedas<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Cantidad de Pasajeros: "<<cantPasajeros<<endl;
        cout<<"Ruedas: "<<velocidad<<endl;
    }
};
class Camion : public Vehiculo{
protected:
    float carga;
public:
    Camion(int ruedas, string color, float carga):Vehiculo(ruedas,color){
        this->carga = carga;
    }
    void info(){
        cout<<"Stock disponible: "<<cantidad<<endl;
        cout<<"Ruedas: "<<ruedas<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Carga: "<<carga<<endl;
    }
};
int main(){
    Camion *c = new Camion(4,"Verde",400);
    Auto *a = new Auto(4,"Azul",5,899);
    Vehiculo *vehiculos[2] ={a,c};
    int op;
    while(true){
        cout<<"1) Ver stock. "<<endl;
        cout<<"2) Vender vehiculo. "<<endl;
        cout<<"3) Salir. "<<endl;
        cin>>op;
        if (op == 1){
            cout<<"   - 1) Stock Auto \n   - 2) Stock Camion\n";
            cin>>op;
            if(op == 1){
                cout<<"   -  STOCK: "<<vehiculos[0]->getCantidad()<<endl;
            } else if(op == 2){
                cout<<"   -  STOCK: "<<vehiculos[1]->getCantidad()<<endl;
            } else{
                cout<<"Opcion incorrecta"<<endl;
            }
        } else if(op == 2){
            cout<<"   - 1) Vender Auto \n   - 2) Vender Camion\n";
            cin>>op;
            if(op == 1){
                vehiculos[0]->setCantidad();
                vehiculos[0]->info();
            } else if(op == 2){
                vehiculos[1]->setCantidad();
                vehiculos[1]->info();
            } else{
                cout<<"Opcion incorrecta"<<endl;
            }
        } else if(op == 3){
            cout<<"chaochao"<<endl;
            break;
        } else {
            cout<<"Opcion incorrecta"<<endl;
        }
        cout<<"......................"<<endl;
    }
    return 0;
}