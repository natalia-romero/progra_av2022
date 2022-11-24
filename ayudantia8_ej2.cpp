#include "iostream"
#include "map"
#include "vector"
using namespace std;
class Elecciones{
private:
    map<string,map<string,int>> votos; //votos[calle][opcion] (total votos)
public:
    Elecciones(){}
    void ingresarVoto1(string calle,string opcion, int cantidad){
        votos[calle][opcion] += cantidad;
    }
    void ingresarVoto2(string calle, vector<int>cantidad){
        votos[calle]["Juan Duarte"] += cantidad.at(0);
        votos[calle]["Pailita"] += cantidad.at(1);
        votos[calle]["Gato Duarte"] += cantidad.at(2);
        votos[calle]["Canela"] += cantidad.at(3);
        votos[calle]["Nulos"] += cantidad.at(4);
    }
    void mostrarGanador(){
        map<string,int> opcionVotos;
        for(auto i = votos.begin(); i != votos.end(); i++){
            bool verificar = true;
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                if(j->second < 30){
                    verificar = false;
                }
                opcionVotos[j->first] += j->second;
                cout<<j->first<<endl;
                cout<<opcionVotos[j->first]<<endl;
            }
            if(!verificar){
                cout<<"La "<<i->first<<" tiene un candidato con menos de 30 votos."<<endl;
                break;
            }
        }
        string ganador = opcionVotos.begin()->first;
        for(auto i = opcionVotos.begin(); i != opcionVotos.end();i++ ){
            if(opcionVotos[ganador] < i->second){
                ganador = i->first;
            }
        }
        cout<<"El ganador es: "<<ganador<<endl;

    }
};

int main(){
    Elecciones *juntavecinos = new Elecciones();
    juntavecinos->ingresarVoto1("Calle 1","Juan Duarte",33);
    juntavecinos->ingresarVoto1("Calle 1","Pailita",30);
    juntavecinos->ingresarVoto1("Calle 1","Gato Duarte",37);
    juntavecinos->ingresarVoto1("Calle 1","Canela",34);
    juntavecinos->mostrarGanador();
    return 0;
}