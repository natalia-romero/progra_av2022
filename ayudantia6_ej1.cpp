#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Supermercado{
private:
    map<string, vector<int>> extra;
public:
    Supermercado(){}
    void ingresar(string rut){
        int dinero;
        for (int i = 0; i < 12; ++i) {
            cout<<"Ingrese dinero recibido en el mes "<<i+1<<endl;
            cin>>dinero;
            extra[rut].push_back(dinero);
        }
    }
    void imprimir(){
        for(auto i = extra.begin(); i != extra.end(); i++){
            cout<<"- Trabajador Rut "<<i->first;
            int size = i->second.size();
            int sum = 0;
            for (int j = 0; j < size; ++j) {
                sum += i->second.at(j);
            }
            cout<<" - Promedio: "<<sum/size<<endl;
        }
    }
    void bono(){
        for(auto i = extra.begin(); i != extra.end(); i++){
            int cont = 0;
            for (int j = 2; j < 8; ++j) {
                if(i->second.at(j) > 40000){
                    cont++;
                }
            }
            if(cont >= 3){
                cout<<"Bono para trabajador "<<i->first<<endl;
            }
        }
    }
};
int main(){
    Supermercado *super = new Supermercado();
    super->ingresar("12345");
    super->imprimir();
    super->bono();
    return 0;
}