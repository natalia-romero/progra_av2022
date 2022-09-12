/*Diseñe un programa en c++ que permita simular el sistema de venta de pasajes de aviones con capacidad de 300 pasajeros (Rut, Nombre).
El programa debe contar con dos funcionalidades para la venta de pasajes, 1 donde el cliente selecciona su asiento y otro donde el asiento es
seleccionado de manera automática por el sistema, ambos ocurren sólo si hay asientos disponibles en el avión.
Adicionalmente se debe programar lo siguiente :
1) BuscarPasajero (preguntando el Rut)
2) ImprimirLista
3) EliminarPasajero (preguntando el Rut)*/
#include <iostream>
using namespace std;
class Pasajero{
private:
    string rut, nombre;
public:
    Pasajero(){

    }
    Pasajero(string rut, string nombre){
        this->rut = rut;
        this->nombre = nombre;
    }
    string getNombre(){
        return nombre;
    }
    string getRut(){
        return rut;
    }
};
class Avion{
private:
    Pasajero *pasajeros[300];
public:
    Avion(){
        for (int i = 0; i < 300; ++i) {
            pasajeros[i] = NULL;
        }
    }
    void ventaSeleccion(Pasajero *pasajero, int asiento){
        if(pasajeros[asiento] == NULL){
            pasajeros[asiento] = pasajero;
            cout<<"Asiento asignado"<<endl;
        } else{
            cout<<"El asiento esta ocupado"<<endl;
        }
    }
    void ventaAutomatica(Pasajero *pasajero){
        bool estado = true;
        for (int i = 0; i < 300; ++i) {
            if(pasajeros[i] == NULL) {
                pasajeros[i] = pasajero;
                cout << "Se ha asignado el asiento " << i + 1 << endl;
                estado = false;
                break;
            }
        }
        if(estado){
            cout<<"No hay asientos disponibles."<<endl;
        }
    }
    void buscarPasajero(string rut){
        bool estado = true;
        for (int i = 0; i < 300; ++i) {
            if(pasajeros[i] != NULL && pasajeros[i]->getRut() == rut) {
                cout<<"Pasajero encontrado en el asiento "<<i+1<<endl;
                estado = false;
                break;
            }
        }
        if(estado){
            cout<<"No se encuentra al pasajero."<<endl;
        }
    }
    void imprimirAvion(){
        for (int i = 0; i < 300; ++i) {
            if(pasajeros[i] != NULL ) {
                cout<<"----------------------"<<endl;
                cout<<"Asiento: "<<i+1<<endl;
                cout<<" - rut: "<<pasajeros[i]->getRut()<<endl;
                cout<<" - nombre: "<<pasajeros[i]->getNombre()<<endl;
            }
        }
    }
    void eliminarPasajero(string rut){
        bool estado = true;
        for (int i = 0; i < 300; ++i) {
            if(pasajeros[i] != NULL && pasajeros[i]->getRut() == rut) {
                pasajeros[i] = NULL;
                cout<<"Pasajero eliminado del asiento "<<i+1<<endl;
                estado = false;
            }
        }
        if(estado){
            cout<<"No se encuentra al pasajero."<<endl;
        }
    }
};
int main() {
    Avion *elAvion = new Avion();
    Pasajero *pasajero1 = new Pasajero("12345", "persona1");
    Pasajero *pasajero2 = new Pasajero("111111", "persona2");
    elAvion->ventaAutomatica(pasajero1);
    elAvion->ventaAutomatica(pasajero1);
    elAvion->ventaSeleccion(pasajero2,7);
    elAvion->eliminarPasajero("111111");
    elAvion->imprimirAvion();
    return 0;
}

