#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int number[5];
    int size = sizeof(number) / sizeof(number[0]);
    for(int i=0;i<size;i++){
        cout<<"Enter values : ";
        cin>>number[i];
    }

    int smallest=INT_MAX;
    for(int i=0;i<size;i++){
        if(number[i]<smallest){
            smallest=number[i];
        }
    }
    cout<<"Smallest no: "<<smallest<<endl;
    
    // sort(number,number + size);
    // for(int i=0;i<size;i++){
    //     cout<< number[i]<<endl;
    // }
    // cout << "Smallest no.: "<<number[0]<<endl;
    // cout << "Largest no.: "<<number[size-1];



}