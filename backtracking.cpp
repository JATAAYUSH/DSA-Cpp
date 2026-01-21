#include <iostream>
#include <vector>
using namespace std;
//time comlexity : O(2^n *n)
void backTrack(vector<int> &arr,vector<int> &ans,int i){
    if(i==arr.size()){
        for(int val : ans){
            cout<< val<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    backTrack(arr,ans,i+1);

    ans.pop_back();
    backTrack(arr,ans,i+1);
}
void permutation(vector<int>& nums,int idx,vector<vector<int>>&anss){
    if(idx==nums.size()) {
        anss.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        permutation(nums,idx+1,anss);
        swap(nums[idx],nums[i]);
    } 
 }
int main(){
    // vector<int> arr = {1, 2, 3};
    // vector<int> ans;
    // backTrack(arr,ans,0);

    vector<int> nums={1, 2, 3, 4};
    vector<vector<int>> anss;
    permutation(nums,0,anss); 
    for (const auto &perm : anss) {
        for (int val : perm) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}