#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int st,int end){
    int idx=st-1;
    int pivot=arr[end];
    for(int i=st,i<end;i++){
        if(arr[i]<=pivot){
            idx++;
            int temp=arr[idx];
            arr[idx]=arr[i];
            arr[i]=temp;
        }
    }
    idx++;
    int temp =arr[idx];
    arr[idx]=arr[end]
    arr[end]=temp
    return idx;
}
void quick(vector<int> &arr, int st,int end){
    if(st<end){
        int pivot=partition(arr,st,end); 
        quick(arr,st,pivot-1);
        quick(arr,pivot+1,end);
    }
}
int main(){
    vector<int>  arr={5,2,6,4,1,3};
    quick(arr,0,arr.size()-1);

    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}