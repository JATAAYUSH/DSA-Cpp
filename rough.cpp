#include <iostream>
using namespace std;
int quick(int a[],int n){
    int left=0,right=a.size()-1,pivot=0;
    while(rigth>=left){
        if(a[pivot]<a[right]){
            right++;
        }
       else if(a[pivot]>a[right]){
        swep(a[pivot],a[right]);
        pivot=right;
        left++;
        }
    }
}
int main({
    int n=6;
    int a[]={3,7,5,1,4,2};

})