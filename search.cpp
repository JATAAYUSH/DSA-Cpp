#include<iostream>
using namespace std;
int func(int arr[],int n,int target,int st,int end){
    if(st<=end){
        int mid=st+(end-st)/2;
        if(target > arr[mid]){
            st=mid+1;
            return func(arr,n,target,st,end);
        }else if(target < arr[mid]){
            end=mid-1;
            return func(arr,n,target,st,end);
        }else 
            return mid;
    }
    return -1;
}
   
int main(){
    
    int n = 7, target = 6;
    int st=0,end=n-1;
    int arr[7] = {3,5,6,8,9,12,16};
    cout<< func(arr,n,target,st,end);


    return 0;
}