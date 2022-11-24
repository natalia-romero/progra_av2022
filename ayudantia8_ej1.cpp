#include "iostream"
#include "vector"
using namespace std;
class Empresa{
protected:
    string duenio, rut;
    int saldoT;
public:
    Empresa(string duenio,string rut){
        this->duenio = duenio;
        this->rut = rut;
        this->saldoT = 0;
    }
    void info(){
        cout<<"Nombre Duenio: "<<this->duenio<<endl<<"Rut Empresa: "<<this->rut<<endl<<"Saldo: "<< this->saldoT<<endl;
    }
    void acumularSaldo(int ingreso){
        this->saldoT += ingreso;
    }
};
class TiendaRopa:public Empresa{
protected:
    vector<float> fardos;
public:
    TiendaRopa(string duenio, string rut):Empresa(duenio,rut){
        for (int i = 0; i < 4; ++i) {
            fardos.push_back((i+1)*10); //agrego datos de prueba
        }
    }
    float exportarFardo(){
        float ultimo = fardos.back();
        fardos.pop_back();
        return ultimo;
    }
    bool verificarFardos(){
        return !fardos.empty();
        /*
         * if(fardos.empty()){
         *  return false
         *  } else{
         *  return true;
         *  }
         */
    }
    void ver(){
        int n = fardos.size();
        for (int i = 0; i < n; ++i) {
            cout<<"Fardo N° "<<i+1<<": "<<fardos.at(i)<<endl;
        }
    }

};
class Sucursal1: public TiendaRopa{
public:
    Sucursal1(string duenio, string rut): TiendaRopa(duenio, rut){}
    void venta(int cantidad){
        int kilos;
        while(this->verificarFardos() && cantidad > 0){
            cantidad--;
            cout<<"Fardo vendido!"<<endl;
            kilos = this->exportarFardo();
            this->acumularSaldo(kilos*1000);
        }

    }
};
int main(){
    Sucursal1 *s = new Sucursal1("Juan Duarte", "12345678-7");
    s->info();
    s->venta(4);
    s->info();
    return 0;
}