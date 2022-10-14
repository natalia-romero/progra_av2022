#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> edades;
    edades.push_back(40);
    edades.push_back(10);
    edades.push_back(406);
    for (int i = 0; i < edades.size(); ++i) {
        cout<<edades.at(i)<<endl;
    }
    cout<<"....."<<endl;
    edades.erase(edades.end()-3,edades.end()-1);
    for (int i = 0; i < edades.size(); ++i) {
        cout<<edades.at(i)<<endl;
    }

    return 0;
}