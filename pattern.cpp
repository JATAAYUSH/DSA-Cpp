#include <iostream>
using namespace std;
int main (){
    // int n;
    // cout<< "Enter value of n: ";
    // cin>> n ;
    // for(int j=1;j<=n;j++){
    //     for (int i=1;i<=n;i++){
    //     cout<<"*";
    // }
    // cout<< endl;
    // }
       
    
    // char ch='A';
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<=i;j++){
    //     cout << ch;
    //     }
    //     cout << endl;
    //     ch=ch+1;
    // }

    // char ch='A';
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<=i;j++){
    //     cout << ch;
    //     ch++;
    //     }
    //     cout << endl;
    // }

    // int n;
    // char b=' ';
    // cout<< "Enter value of n: ";
    // cin>> n ;
    // for(int i=0;i<n;i++){
    //     for(int j=n;j>i;j--){
    //     cout << (i+1);
    //     }
    //     cout << endl;
    //     for(int k=0;k<(i+1);k++){
    //     cout << b;
    //     }
    // }

    int n;
    char b=' ';
    cout<< "Enter value of n: ";
    cin>> n ;
    for(int i=0;i<n;i++){
        for(int j=n;j>i+1;j--){
            cout <<" ";
            
        }
        cout<<"*";
        if(i!=0){
            for(int j=0;j<i;j++){
            cout <<" ";
        }
        }
        if(i!=0&&i!=1){
            for(int j=0;j<i-1;j++){
            cout <<" ";
        }
        }
        if(i!=0){
            for(int j=0;j<1;j++){
            cout<<"*";
        }
        }
        
        cout<< endl;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<i+1;j++){
            cout <<" ";
            
        }
        cout<<"*";
        for(int j=n-2;j>i;j--){
            cout<<" ";
        }
        for(int j=n-3;j>i;j--){
            cout<<" ";

        }
        if(i!=n-2){
            cout<<"*";
        }
        cout<< endl;
    }
    return 0;
}
// // 00
// // 11
// // 23
// // 35
// // 47