#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter the number of elements in array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array :";
    for (int val=0;val<n;val++) {
    cin >> arr[val];
    }  
    cout<<arr[2];
    return 0;
}
