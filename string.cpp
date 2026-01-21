#include <iostream>
using namespace std;
int main(){
    char str[12];
    cout <<"enter char array:";
    cin.getline(str,12);
    for (char val : str){
        cout<<val;
    }
    return 0;
}