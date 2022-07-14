#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, vector<int> &candidates, int n, int target, vector<vector<int>> &ans, vector<int> &dp){
        if(target==0){
            ans.push_back(dp);
            return;
        }
        for(int i= idx; i<n; i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            dp.push_back(candidates[i]);
            helper(i+1, candidates, n, target-candidates[i], ans, dp);
            dp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dp;
        int n= candidates.size();
        sort(candidates.begin(), candidates.end());
        helper(0,candidates, n, target, ans, dp);
        return ans;
    }
};

int main(){
    vector<int> arr= {10,1,2,7,6,1,5};
    int t= 8;
    Solution obj;
    vector<vector<int>> vec= obj.combinationSum2(arr, t);
    for(auto x: vec){
        cout<<"[";
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}