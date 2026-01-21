#include <iostream>
using namespace std;
int main(){
    int a = 1;
    string st = "harshit";
    char ch = 'h';
    // cout << "My first C++ code";
    // cout << a<<endl;
    // cout << st<<endl;
    // cout << ch;
    // cout << bool a = 1;
    // if(isalpha(ch)){
    // cout << "Yes it is Alphabet" << endl;
    //     char lower = tolower(ch);
    //     if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
    //         cout << "It is vowel" << endl;
    //     } else {
    //         cout << "It is not vowel" << endl;
    //     }
    // } else {
    //     cout << "It is not Alphabet" << endl;
    // }

    // int b = 34;
    // int n = 67;
    // int lastdig1 = b%10;
    // int lastdig2 = n%10;
    // if(lastdig1 == lastdig2){
    //     cout<<true;
    // }else cout<<false;

    int time = 10;
    if(time >0 && time < 12){
        cout<< time << "PM";
    }else{
        cout<< time << "AM";
    }
    
    return 0;
}