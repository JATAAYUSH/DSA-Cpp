// #include <iostream>
// #include <vector>
// using namespace std;
// class Stack{
//     vector<int> v;
// public:
//     void push(int val){
//         v.push_back(val);
//     }
//     void pop(){
//         v.pop_back();
//     }
//     int top(){
//         return v[v.size()-1];
//     }
//     bool empty(){
//         return v.size()==0;
//     }
// };
// int main(){
//     Stack s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;
// class Stack{
//     list<int> ll;
// public:
//     void push(int val){
//         ll.push_front(val);
//     }
//     void pop(){
//         ll.pop_front();
//     }
//     int top(){
//         return ll.front();
//     }
//     bool empty(){
//         return ll.size()==0;
//     }
// };
// int main(){
//     Stack s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;
//     return 0;
// }

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// int main(){
//     stack<int>s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;
//     return 0;
// }
//  int main(){
//     vector<int> val = {34,12,10,24,68,23,46};
//     vector<int> ans;
//     ans.push_back(1);
//     for(int i=1 ; i<val.size() ; i++){
//         int prv = i-1;
//         int count = 1;
//         while(val[i] >= val[prv] && prv >= 0){
//                 count++;
//                 prv--;
//         }
//         ans.push_back(count);
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" | ";
//     }
//  }

// next greatre element:
// int main(){
//     vector<int> arr = {6,8,0,1,3};
//     vector<int> ans;
//     stack<int> s;
//     s.push(arr[arr.size()-1]);
//     ans.push_back(-1);
//     for(int i = arr.size()-2;i>=0;i--){
//         while( s.size() != 0 && s.top() <= arr[i]){
//             s.pop();
//         }
//         if(s.empty()){
//             ans.push_back(-1);
//         } 
//         else {
//             ans.push_back(s.top());
//         }
//         s.push(arr[i]);
//     }
//     for(int i=ans.size()-1;i>=0;i--){
//         cout<<ans[i]<<" | ";
//     }
// }

// Previous Smaller Element:
int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans;
    stack<int> s;
    s.push(arr[0]);
    ans.push_back(-1);
    for(int i = 1;i<arr.size();i++){
        while( s.size() != 0 && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
        } 
        else {
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    for(int i=0 ;i<ans.size();i++){
        cout<<ans[i]<<" | ";
    }
}