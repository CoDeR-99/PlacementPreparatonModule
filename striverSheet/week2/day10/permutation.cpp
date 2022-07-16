#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &vec, vector<int> v){
        if(nums.size()==0){
            vec.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            int t= nums[i];
            vector<int> temp;
            for(int j=0; j<nums.size(); j++){
                if(j!=i){
                    temp.push_back(nums[j]);
                }
            }
            v.push_back(t);
            helper(temp, vec, v);
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        helper(nums, vec, v);
        return vec;
    }
};

int main(){
    vector<int> nums= {1, 2, 3};
    Solution obj;
    vector<vector<int>> vec= obj.permute(nums);
    for(auto x: vec){
        cout<<"[";
        for(auto i:x){
            cout<<i<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}