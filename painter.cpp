#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <numeric> // for std::accumulate
using namespace std;
bool istrue(vector<int> &arr,int n,int m, int maxTime){
    int pntr = 1,time = 0;
    for(int i=0;i<n;i++){
        if(time + arr[i] <= maxTime){
            time += arr[i];
        }else{
            pntr++;
            time = arr[i];
        }
    }
    return (pntr <= m) ? true : false;
}
int allocatepainters(vector<int> &arr,int n, int m){
    int st = *max_element(arr.begin(),arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (st<=end){
        int mid = st + (end - st)/2;
        if(istrue(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }else st = mid + 1;
    }
    return ans;
}
int main(){
    int n=4,m=2;
    vector<int>arr={40,30,10,20};
    cout<< allocatepainters(arr,n,m)<<endl;
    return 0 ;
}