// time complexity = total no of calls * work done in each call.
// space complexity = depth of recursive tree * spcae in each call.
#include <iostream>
#include <vector>
using namespace std;
int sum(int n){
    if(n==0) return 0;
    return sum(n-1)+n;
}

void func(int n){
    if(n == 0){
        return ;
    }
    cout<< n <<" ";
    func(n-1);
}

int fact(int n){
    if(n == 1 || n == 0) return 1;
    return fact(n-1)*n;
}

int fibo(int n){
    if(n==1||n==0) return n;
    return fibo(n-1)+fibo(n-2);
}

bool sortornot(vector<int> arr,int n){
    if(n ==0 || n==1) return true;
    return arr[n-1] >= arr[n-2] && sortornot(arr,n-1) ;
}

int  binary(vector<int> &arr,int tar,int st,int end){
    int mid = st + (end-st)/2;
    if(arr[mid] == tar) return mid;
    if(arr[mid] <= tar){
        return binary(arr,tar,mid+1,end);
    }else{
        return binary(arr,tar,st,mid-1);
    } 
}

int main(){
    // cout<<sum(5)<<endl;
    // func(5);
    // cout<<endl;
    cout <<fact(0)<<endl;
    // cout <<fibo(5)<<endl;

    // vector<int> arr={1,2,3,4,5,6,7,8};
    // cout<<sortornot(arr,arr.size())<<endl;
    // cout <<binary(arr,6,0,arr.size());

}