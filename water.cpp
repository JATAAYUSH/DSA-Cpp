#include <iostream>
using namespace std;
// Brute force approch:
void max_waterB(int n,int arr[]){
    int maxArr=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int height=min(arr[i],arr[j]);
            int width=j-i;
            int currArr=height*width;
            maxArr=max(currArr,maxArr); 
        }
    }
    cout<<"Maximum Area by Brute is: "<<maxArr<<endl;
}

//Optimal approch:
void max_waterO(int n,int arr[]){
    int lp=0,rp=n-1;
    int maxArr=0;
    while(lp<rp){
        int ht = min(arr[lp],arr[rp]);
        int wth = rp-lp;
        int currArr=ht*wth;
        maxArr=max(currArr,maxArr);
        arr[lp]<arr[rp]?lp++:rp--;
    }
    cout<<"Maximum Area by Optimal is: "<<maxArr<<endl;
}

// Produt of array except self:
void mul_array(int arr[], int n){
    for(int i=0;i<n;i++){
        int mul=1;
        for(int j=0;j<n;j++){
            if(j!=i){
                mul*=arr[j];
            }
        }
        cout<<mul<<","; 
    }
}


int main(){
    int n=7;
    int arr[n]={8,4,6,3,9,4,2};
    // max_waterB(n,arr);
    // max_waterO(n,arr);
    mul_array(arr,n);
    return 0;
}