#include <iostream>
#include <queue>

using namespace std;
int main(){
    queue<int> edades;
    edades.push(78);
    edades.push(98);
    edades.push(77);
    edades.push(55);
    edades.push(22);
    int size = edades.size();
    queue<int> aux = edades;
    while(!edades.empty()){
        cout<<edades.front()<<endl;
        edades.pop();
    }


    return 0;
}