#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, vector<int> &nums, vector<vector<int>> &vec, vector<int> &dp){
        vec.push_back(dp);
        for(int i=ind; i<nums.size(); i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            dp.push_back(nums[i]);
            helper(i+1, nums, vec, dp);
            dp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        vector<int> dp;
        helper(0, nums, vec, dp);
        return vec;
    }
};

int main(){
    vector<int> arr= {1, 2, 2};
    Solution obj;
    vector<vector<int>> vec= obj.subsetsWithDup(arr);
    for(auto x: vec){
        cout<<"[";
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}