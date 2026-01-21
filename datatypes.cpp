#include <iostream> 
// #include <string> optional.
using namespace std;
int povoftwo(int n){
    return (n>0) && ((n&(n-1))==0);
}
int main(){
    // cout<< sizeof(int)<<endl;
    // cout<< sizeof(double)<<endl;
    // cout<< sizeof(short int)<<endl;

    // for(int i=1;i<=50;i++){
    //     cout<<povoftwo(i);
    // }
    
    std::string a ="Aayush";
    std::cout<< a[2];
    for(int i=a.length()-1;i>=0;i--){
        cout<<a[i];
    }
}