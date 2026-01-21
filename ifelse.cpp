// conditional statments 
#include <iostream>
using namespace std;
int main (){
    int n;
    for (int i=0;i<=5;i++){
        cout<< "Enter the no:";
        cin>> n;
        if(n%2==0){
            cout<< "Even Number"<<"\n";
        }
        else cout<< "Odd Number"<<"\n";
    }
    
    return 0;
}