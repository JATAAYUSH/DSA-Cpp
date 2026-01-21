#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void merge(int arr[], int st, int mid, int end){
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else {
            temp.push_back(arr[j++]);
        }
    }
    for(int k=j;k<=end;k++){
        temp.push_back(arr[k]);
    }
   for(int k=i;k<=mid;k++){
        temp.push_back(arr[k]);
    }
   for(int idx=0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
}
void mergesort(int arr[],int st,int end){
    if(st<end) {
        int mid = st+(end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);

        merge(arr, st, mid, end);
    }
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]< arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int partition(int arr[],int st,int end){
    int idx = st-1,pivid= arr[end];
    for(int i=st;i<end;i++){
        if(arr[i]<=pivid){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}
void quicksort(int arr[],int st,int end){
    if(st<end){
        int pivIdx = partition(arr,st,end);
        quicksort(arr,st,pivIdx-1);
        quicksort(arr,pivIdx+1,end);
    }
}
int main(){
    int n = 5;
    int arr[n]={4,7,2,6,1};
    // selectionsort(arr,n);
    // insertionsort(arr,n);
    for(int val : arr){
        cout<< val<<",";
    }
    bubble(arr,n);
    // mergesort(arr,0,n-1);
    // quicksort(arr,0,n-1); //tC = acO(nlogn),vcO(n^2)
    for(int val : arr){
        cout<< val<<",";
    } 
}
