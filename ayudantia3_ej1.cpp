#include <iostream>
using namespace std;

class Mascota {
protected:
    string nombre;
    int edad;
    bool chip;
public:
    Mascota (string nombre, int edad, bool chip){
        this->nombre = nombre;
        this->edad = edad;
        this->chip = chip;
    }
    void imprimir(){
        cout << "Nombre: " << this->nombre << " Edad: " << this->edad <<
             " Tiene chip?: " << this->chip;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setEdad(int edad){
        this->edad = edad;
    }
    void setChip(bool chip){
        this->chip = chip;
    }
};

class Gato : public Mascota {
protected:
    string color;
public:
    Gato(string nom, int ed, bool chp, string color) : Mascota(nom, ed, chp){
        this->color = color;
    }
    void setColor(string color){
        this->color = color;
    }
    void imprimirGato(){
        cout << " Color de Gato: " << this->color << endl;
    }
    void maullar(){
        cout << "Miau" << endl;
    }
};

class Perro : public Mascota {
protected:
    string raza;
public:
    Perro(string nom, int ed, bool chp, string raza) : Mascota(nom, ed, chp){
        this->raza = raza;
    }
    void setRaza(string raza){
        this->raza = raza;
    }
    void imprimirPerro(){
        cout << " Raza de Perro: " << this->raza << endl;
    }
    void ladrar(){
        cout << "Wau" << endl;
    }
};

int main(){
    int contadorGato = 0, contadorPerro = 0, opcion, numero;
    string nombre, color, raza;
    int edad;
    bool chip;
    Gato *gato[20];
    Perro *perro[20];
    while(true){
        cout << "[1] Ingresar gato" << endl;
        cout << "[2] Ingresar perro" << endl;
        cout << "[3] Modificar datos de gato" << endl;
        cout << "[4] Modificar datos de perro" << endl;
        cout << "[5] Ver datos de gato" << endl;
        cout << "[6] Ver datos de perro" << endl;
        cout << "[7] Hacer que un gato maulle" << endl;
        cout << "[8] Hacer que un perro ladre" << endl;
        cout << "[0] Terminar programa." << endl;
        cin >> opcion;
        if (opcion == 0){
            cout << "Se termino el programa" << endl;
            break;
        } else if (opcion == 1){
            if (contadorGato >= 20){
                cout << "No se pueden ingresar mas gatos, ya existen 20" << endl;
                continue;
            }
            cout << "Ingrese nombre, edad, si tiene chip o no, color" << endl;
            cin >> nombre >> edad >> chip >> color;
            gato[contadorGato] = new Gato(nombre, edad, chip, color);
            contadorGato++;
        } else if (opcion == 2){
            if (contadorPerro >= 20){
                cout << "No se pueden ingresar mas perros, ya existen 20" << endl;
                continue;
            }
            cout << "Ingrese nombre, edad, si tiene chip o no, raza" << endl;
            cin >> nombre >> edad >> chip >> raza;
            perro[contadorPerro] = new Perro(nombre, edad, chip, raza);
            contadorPerro++;
        } else if (opcion == 3){
            for (int i=0; i<contadorGato; i++){
                cout << i+1 << " ";
                gato[i]->imprimir();
                gato[i]->imprimirGato();
            }
            cout << "Ingrese numero del gato que quiera modificar" << endl;
            cin >> numero;
            cout << "Ingrese nuevo nombre, edad, chip, color" << endl;
            cin >> nombre >> edad >> chip >> color;
            gato[numero-1]->setNombre(nombre);
            gato[numero-1]->setEdad(edad);
            gato[numero-1]->setChip(chip);
            gato[numero-1]->setColor(color);
        } else if (opcion == 4){
            for (int i=0; i<contadorPerro; i++){
                cout << i+1 << " ";
                perro[i]->imprimir();
                perro[i]->imprimirPerro();
            }
            cout << "Ingrese numero del perro que quiera modificar" << endl;
            cin >> numero;
            cout << "Ingrese nuevo nombre, edad, chip, raza" << endl;
            cin >> nombre >> edad >> chip >> raza;
            perro[numero-1]->setNombre(nombre);
            perro[numero-1]->setEdad(edad);
            perro[numero-1]->setChip(chip);
            perro[numero-1]->setRaza(raza);
        } else if (opcion == 5){
            for (int i=0; i<contadorGato; i++){
                cout << i+1 << " ";
                gato[i]->imprimir();
                gato[i]->imprimirGato();
            }
        } else if (opcion == 6){
            for (int i=0; i<contadorPerro; i++){
                cout << i+1 << " ";
                perro[i]->imprimir();
                perro[i]->imprimirPerro();
            }
        } else if (opcion == 7){
            for (int i=0; i<contadorGato; i++){
                cout << i+1 << " ";
                gato[i]->imprimir();
                gato[i]->imprimirGato();
            }
            cout << "Ingrese numero del gato que quiera modificar" << endl;
            cin >> numero;
            gato[numero-1]->maullar();
        } else if (opcion == 8){
            for (int i=0; i<contadorPerro; i++){
                cout << i+1 << " ";
                perro[i]->imprimir();
                perro[i]->imprimirPerro();
            }
            cout << "Ingrese numero del perro que quiera modificar" << endl;
            cin >> numero;
            perro[numero-1]->ladrar();
        } else {
            cout << "Opcion equivocada" << endl;
        }
    }
    return 0;
}