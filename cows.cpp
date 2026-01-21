#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> &stalls,int m,int n,int mid){
    int cow=1;
    int laststall = stalls[0]; 
    for(int i= 1;i<n;i++){
        if(stalls[i]-laststall>=mid){
            cow++;
            laststall = stalls[i];
        } 
        if(cow==m) return true;
    }
    return false;
}
int cowplace(vector<int> &stalls,int m,int n){
    if (m > n) {
    cout << "Error: More cows than stalls. Cannot place." << endl;
    return 1;
}

    sort(stalls.begin(),stalls.end());
    int min = 1;
    int max = stalls[n-1]-stalls[0];
    int ans = -1;
    while(min<=max){
        int mid = min + (max - min)/2;
        if(isPossible(stalls,m,n,mid)){
            min = mid + 1;
            ans = mid;
        } else {
            max = mid - 1;
        }
    }
    return ans;
}
int main (){
    int m;
    cout<<"Enter the Number of Cows: ";
    cin>> m;
    int n;
    cout<<"Enter the Number of stalls :";
    cin>> n;
    vector<int> stalls(n);
    cout<<"Enter the Pots: ";
    for(int i=0 ;i<n;i++){
        cin>> stalls[i];
    }
    cout << cowplace(stalls,m,n);
    return 0;
}