#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>vac={3,6,4,8,2};
   for(int i:vac){
        cout<<i<<endl;
   }

// for reverse:   
    int size=5;
    for(int i=4; i>=0;i--){
        cout<<vac[i]<<endl;
    }

    vac.push_back(9); //capacity will 2x.
    cout<<"size of vac:"<<vac.size()<<endl;
    cout<<"capacity of vac:"<<vac.capacity();
    return 0;
}
// g++ -o kadane kadane.cpp ; .\kadane.exe