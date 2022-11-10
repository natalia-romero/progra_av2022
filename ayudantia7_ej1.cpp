#include <iostream>
#include <map>
using namespace std;
class Empresa{
private:
    map<string,map<char,int>> carrito; //carrito[nombre][tipo] stock
public:
    Empresa(){}
    void agregarCarrito(string nombre){
        //se inicializa carrito
        carrito[nombre]['Q'] = 0; //stock inicial empanadas de queso en 0
        carrito[nombre]['P'] = 0; //stock inicial empanadas de pino en 0
    }
    void agregarEmpanadasPino(string nombre, int cantidad){
        int cont = 0;
        while(carrito[nombre]['P'] != 20 && cantidad != 0){  //agrega empanadas hasta que se llegue al limite permitido
            carrito[nombre]['P']++;
            cont++;
            cantidad--;
        }
        if(carrito[nombre]['P'] == 20){ //si se supera la cantidad permitida
            cout<<"El stock de empanadas de pino ha sido superado. Se agregaron "<<cont<<" empanadas."<<endl;
        } else{ //no se supera la cantidad permitida, por lo tanto se alcanzo a agregar todo
            cout<<"Se agregaron todas las empanadas"<<endl;
        }
    }
    void agregarEmpanadasQueso(string nombre, int cantidad){
        int cont = 0;
        while(carrito[nombre]['Q'] != 20 && cantidad != 0){ //agrega empanadas hasta que se llegue al limite permitido
            carrito[nombre]['Q']++;
            cont++;
            cantidad--;
        }
        if(carrito[nombre]['Q'] == 20){ //si se supera la cantidad permitida
            cout<<"El stock de empanadas de queso ha sido superado. Se agregaron "<<cont<<" empanadas."<<endl;
        } else{ //no se supera la cantidad permitida, por lo tanto se alcanzo a agregar todo
            cout<<"Se agregaron todas las empanadas"<<endl;
        }
    }
    void vender(string nombre, int cantidad, char tipo){
        int cont = 0;
        while(carrito[nombre][tipo] != 0 && cantidad != 0){   //vende empanadas hasta que se acaben
            carrito[nombre][tipo]--;
            cont++;
            cantidad--;
        }
        if(carrito[nombre][tipo] == 0){  //si no quedan mas empanadas
            cout<<"Ya no quedan mas empanadas para vender. Se vendieron "<<cont<<" empanadas."<<endl;
        } else{ //quedan empanadas, por lo tanto se vendio todo
            cout<<"Se vendieron todas las empanadas"<<endl;
        }
    }
    void regalarMercaderia(string nombre){
        int contQ = 0, contP = 0;
        while(carrito[nombre]['Q'] != 0){   //dona empanadas de queso hasta que se acaben
            carrito[nombre]['Q']--;
            contQ++;
        }
        while(carrito[nombre]['P'] != 0){   //dona empanadas de pino hasta que se acaben
            carrito[nombre]['P']--;
            contP++;
        }
        cout<<"Se donaron "<<contP<<" empanadas de pino y "<<contQ<<" de queso."<<endl;
    }
    void listarStock(){
        for(auto i = carrito.begin(); i != carrito.end(); i++){
            cout<<"**********"<<endl;
            cout<<"STOCK CARRITO "<<i->first<<": "<<endl;
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                cout<<" - "<<j->first<<": "<<j->second<<endl;
            }
        }
    }
};
int main(){
    Empresa *pyme = new Empresa();
    pyme->agregarCarrito("El Bajon");
    pyme->agregarCarrito("MichiEmpanadas");

    pyme->agregarEmpanadasPino("El Bajon",5);
    pyme->agregarEmpanadasPino("El Bajon",2);
    pyme->agregarEmpanadasPino("El Bajon",15);
    pyme->listarStock();
    pyme->agregarEmpanadasPino("MichiEmpanadas",7);
    pyme->agregarEmpanadasPino("MichiEmpanadas",5);
    pyme->agregarEmpanadasPino("MichiEmpanadas",35);
    pyme->listarStock();
    pyme->agregarEmpanadasQueso("El Bajon",5);
    pyme->agregarEmpanadasQueso("El Bajon",2);
    pyme->listarStock();
    pyme->agregarEmpanadasQueso("El Bajon",7);
    pyme->agregarEmpanadasQueso("El Bajon",5);

    pyme->listarStock();


    pyme->vender("El Bajon",4,'P');
    pyme->vender("MichiEmpanadas",4,'P');

    pyme->listarStock();

    pyme->regalarMercaderia("El Bajon");
    pyme->listarStock();
    return 0;
}