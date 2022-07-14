#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, vector<int> &candidates, int n, int target, vector<vector<int>> &vec, vector<int> &dp){
        if(target==0){
            vec.push_back(dp);
            return;
        }
        if(i==n){
            return;
        }
        if(target>=candidates[i]){
            dp.push_back(candidates[i]);
            helper(i, candidates, n, target-candidates[i], vec, dp);
            dp.pop_back();
        }
        helper(i+1, candidates, n, target, vec, dp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        vector<int> dp;
        int n= candidates.size();
        helper(0, candidates, n, target, vec, dp);
        return vec;
    }
};

int main(){
    vector<int> arr= {2, 3, 6, 7};
    int t= 7;
    Solution obj;
    vector<vector<int>> vec= obj.combinationSum(arr, t);
    for(auto x: vec){
        cout<<"[";
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}