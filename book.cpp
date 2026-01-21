#include <iostream>
#include <vector>
using namespace std ;
bool isValid(vector<int>&arr,int n,int m,int allowed_Pages){
    int stu = 1, pages = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > allowed_Pages) return false;
        if(pages + arr[i] <= allowed_Pages){
            pages+=arr[i];
        }else {
            stu++;
            pages = arr[i];
        }
    }
    return (stu <= m) ? true : false;
}
int allocateBooks(vector<int>&arr, int n ,int m ){
    if(m>n) return -1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int ans = -1, st = 0, end = sum;
    while (st <= end){
        int mid = st + (end - st)/2;
        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        } else{
            st = mid + 1;
        }
    }
    return ans;
}
int main (){
    int n=4,m=2;
    vector<int>arr={2,1,3,4};
    cout<< allocateBooks(arr,n,m)<<endl;
    return 0 ;
}