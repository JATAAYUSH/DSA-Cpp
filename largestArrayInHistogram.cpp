#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        int newans = arr[0];
        for(int i=0;i<arr.size();i++){
            int w = 0;
            int ans = 0;
            int h = arr[i];
            for(int j=i;j<arr.size();j++){
                h = min(h,arr[j]);
                w++;
                ans = max(ans,h*w);
            }
            newans = max(newans,ans);
        }
        return newans;
    }
};
int main(){
    vector<int> arr = {2,1,5,6,2,3};
    Solution sol;
    cout<< sol.largestRectangleArea(arr);
    return 0;
}