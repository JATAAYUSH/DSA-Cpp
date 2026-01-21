#include <iostream>
using namespace std;
// int noToBinary(int n){
//     int ans=0, pow=1;
//     while(n>0){
//         int rem = n%2;
//         n/=2;
//         ans+=(rem*pow);
//         pow*=10;
//     }
//     return ans;
// }
int binaryToDec(int a){
    int ans=0, pow=1;
    while(a>0){
        int rem = a%10;
        ans+=rem*pow;

        a/=10;
        pow*=2;
    }
    return ans;
}
int main(){
    // for(int i=1;i<=10;i++){
    //     cout << "Binary of "<< i <<" is "<<noToBinary(i) <<endl;
    // }    
    int a;
    cout<<"Binary Number: ";
    cin>>a;
    cout << "Number is "<<binaryToDec(a) <<endl;
    return 0;
}






