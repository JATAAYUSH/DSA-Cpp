#include <iostream>
using namespace std;
void prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<< n <<" is not a Prime number:";
            return;
        }
    }
    cout<<n<<" is prime number";
}

int main(){
for(int i=2;i<=50;i++){
    prime(i);
    cout<<endl;
}
}