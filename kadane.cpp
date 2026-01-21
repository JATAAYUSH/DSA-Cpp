#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums){
    int currsum=0, maxsum=INT_MIN;
    for(int val: nums){
        currsum+=val;
        maxsum=max(currsum,maxsum);

        if(currsum<0){
            currsum=0;
        }
    }
    return maxsum;
}
int main(){
    int n=5;
    int array[n]={1,2,3,4,5};
    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
                cout<< array[i];
            }
            cout<<" ";
        }
        cout<< endl;
    }

    // int n=5;
    // int array[n]={1,2,3,4,5};
    // int maxsum=INT_MIN;
    // for(int st=0;st<n;st++){
    //     int currsum=0;
    //     for(int end=st;end<n;end++){
    //         currsum+=array[end];
    //         maxsum=max(currsum,maxsum);
    //     }
    // }
    // cout<< "Maximum sum of Sub Array = "<<maxsum;

    vector<int>nums={1,2,3,4,5};
    cout<< "Maximum sum of Sub Array = "<<maxSubArray(nums);
    return 0;
}