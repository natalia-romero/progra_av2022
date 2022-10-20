#include <iostream>
#include <queue>
using namespace std;
class Estudiante{
private:
    string rut;
    int saldo;
public:
    Estudiante(string rut){
        this->rut = rut;
        this->saldo = 30000;
    }
    string getRut(){
        return rut;
    }
    int getSaldo(){
        return saldo;
    }
    void setRut(){
        this->rut = rut;
    }
    void setSaldo(int descuento){
        this->saldo -= descuento;
    }
};
class Casino{
private:
    queue<Estudiante*> fila;
    int tickets;
public:
    Casino(){
        this->tickets = 500;
    }
    void imprimirFila(){
        queue<Estudiante*> aux = fila;
        int size = aux.size();
        for (int i = 0; i < size; ++i) {
            cout<<"N° "<<i+1<<": "<<aux.front()->getRut()<<endl;
            aux.pop();
        }
    }
    void ingreso(Estudiante *estudiante){
        fila.push(estudiante);
        cout<<"Estudiante "<<estudiante->getRut()<<" ingresado a la fila."<<endl;
    }
    bool stock(){
        return tickets > 0;
    }
    void venta(){
        if(stock()){
            if(fila.front()->getSaldo() - 1000 < 0){
                cout<<"Al estudiante "<<fila.front()->getRut()<<" no le queda saldo. "<<endl;
            } else {
                fila.front()->setSaldo(1000);
                tickets --;
                cout<<"Ticket vendido al estudiante "<<fila.front()->getRut()<<endl;
            }
            fila.pop();
        } else {
            cout<<"No quedan más tickets."<<endl;
        }

    }
};
int main(){
    Casino *casino = new Casino();
    casino->ingreso(new Estudiante("123456"));
    casino->ingreso(new Estudiante("84848"));
    casino->ingreso(new Estudiante("432532"));
    casino->ingreso(new Estudiante("677898"));
    casino->ingreso(new Estudiante("234555"));
    casino->imprimirFila();
    casino->venta();
    casino->venta();
    casino->imprimirFila();
    return 0;
}