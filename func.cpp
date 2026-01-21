// #include <iostream>
// using namespace std;
// int name(int a,int b){
//     cout<< "Aayush\n";
//     cout<< "Jattt\n";
//     a+=5;
//     return (a+b);
// }
// int main (){
//     int a=1;
//     int b=5;
//    cout<< name(a,b)<<endl;
//    cout << a;
// //    sum of n dijits:
//     return 0;
// }


//    sum of n dijits:
// #include <iostream>
// using namespace std;
// int sumOfNum(int num){
// int sum=0;
// while(num>0){
//     int newnum=num%10;
//     num=num/10;
//     sum+=newnum;
// }
// return sum;
// }
// int main(){
// cout<< sumOfNum(123)<<endl;
// cout<< sumOfNum(144);
//     return 0;
// }

// ncr formula:n!/[r!(n-r)!]
// g++ -o func func.cpp ; .\func.exe
#include <iostream>
using namespace std;
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
int ncr(int n,int r){
    int factr=factorial(r);
    int factnmr=factorial(n-r);
    int factn=factorial(n);
    return factn/(factr*factnmr);
}
int main(){
    int n=6,r=3;
    // cout<< "n=";
    // cin>> n;
    // cout<< "r=";
    // cin>> r;
    cout<<"nCR ="<< ncr(n,r);
    return 0;
}